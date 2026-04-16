from __future__ import annotations

import asyncio
import json
import subprocess
from io import BytesIO
from pathlib import Path
from typing import Any

import edge_tts

LOG_START = "[Start] MVP video export started"
LOG_SEGMENT = "[Process] MVP segment"
LOG_COMPLETE = "[Done] MVP video export completed"


def export_mvp_video(
    selected_clip_manifest: dict[str, Any],
    narrations: dict[str, Any],
    tts_voice: str,
    output_dir: Path,
) -> dict[str, Any]:
    if not tts_voice.strip():
        raise RuntimeError("TTS voice is required for MVP export.")

    output_dir.mkdir(parents=True, exist_ok=True)
    raw_audio_dir = output_dir / "audio-raw"
    fitted_audio_dir = output_dir / "audio-fit"
    segments_dir = output_dir / "segments"
    raw_audio_dir.mkdir(parents=True, exist_ok=True)
    fitted_audio_dir.mkdir(parents=True, exist_ok=True)
    segments_dir.mkdir(parents=True, exist_ok=True)

    narration_by_clip = {
        int(item["clipIndex"]): item for item in narrations.get("clips", [])
    }
    selected_clips = sorted(
        selected_clip_manifest.get("selectedClips", []),
        key=lambda item: int(item.get("index", 0)),
    )
    segment_records: list[dict[str, Any]] = []
    print(LOG_START)

    for clip in selected_clips:
        clip_index = int(clip.get("index", 0))
        narration = narration_by_clip.get(clip_index)
        if narration is None:
            raise RuntimeError(f"Missing narration for clip {clip_index}.")
        clip_path = Path(str(clip.get("file", "")))
        if not clip_path.exists():
            raise RuntimeError(f"Clip file is missing for clip {clip_index}: {clip_path}")

        raw_audio_path = raw_audio_dir / f"clip_{clip_index:02d}.mp3"
        fitted_audio_path = fitted_audio_dir / f"clip_{clip_index:02d}.m4a"
        segment_path = segments_dir / f"segment_{clip_index:02d}.mp4"
        audio_bytes = asyncio.run(_synthesize_audio_bytes(narration["narration"], tts_voice))
        raw_audio_path.write_bytes(audio_bytes)
        source_duration_sec = probe_media_duration(raw_audio_path)
        target_duration_sec = max(0.001, float(clip.get("durationSec", 0.0)))

        _run_command(
            build_audio_fit_command(
                input_audio_path=raw_audio_path,
                output_audio_path=fitted_audio_path,
                source_duration_sec=source_duration_sec,
                target_duration_sec=target_duration_sec,
            )
        )
        _run_command(
            build_mux_command(
                clip_path=clip_path,
                audio_path=fitted_audio_path,
                output_path=segment_path,
            )
        )
        segment_records.append(
            {
                "clipIndex": clip_index,
                "clipFile": str(clip_path.resolve()),
                "rawAudioFile": str(raw_audio_path.resolve()),
                "fittedAudioFile": str(fitted_audio_path.resolve()),
                "segmentFile": str(segment_path.resolve()),
                "narration": narration["narration"],
                "sourceDurationSec": round(source_duration_sec, 3),
                "targetDurationSec": round(target_duration_sec, 3),
            }
        )
        print(
            f"{LOG_SEGMENT}: clip={clip_index}, audio={source_duration_sec:.3f}s, target={target_duration_sec:.3f}s"
        )

    concat_list_path = output_dir / "segments.txt"
    concat_list_path.write_text(
        "\n".join(_build_concat_list_line(record["segmentFile"]) for record in segment_records),
        encoding="utf-8",
    )
    final_video_path = output_dir / "mvp_final_video.mp4"
    _run_command(build_concat_command(concat_list_path, final_video_path))

    result = {
        "video": selected_clip_manifest.get("video"),
        "selectedClipCount": len(selected_clips),
        "narrationSummary": narrations.get("summary", {}),
        "segments": segment_records,
        "finalVideo": str(final_video_path.resolve()),
    }
    manifest_path = output_dir / "mvp_manifest.json"
    manifest_path.write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    print(LOG_COMPLETE)
    return result


def build_audio_fit_command(
    input_audio_path: Path,
    output_audio_path: Path,
    source_duration_sec: float,
    target_duration_sec: float,
) -> list[str]:
    filter_parts: list[str] = []
    if source_duration_sec > target_duration_sec and target_duration_sec > 0.0:
        filter_parts.extend(_build_atempo_chain(source_duration_sec / target_duration_sec))
    filter_parts.append(f"apad=pad_dur={target_duration_sec:.3f}")
    filter_parts.append(f"atrim=0:{target_duration_sec:.3f}")
    return [
        "ffmpeg",
        "-y",
        "-i",
        str(input_audio_path),
        "-filter:a",
        ",".join(filter_parts),
        "-c:a",
        "aac",
        str(output_audio_path),
    ]


def build_mux_command(
    clip_path: Path,
    audio_path: Path,
    output_path: Path,
) -> list[str]:
    return [
        "ffmpeg",
        "-y",
        "-i",
        str(clip_path),
        "-i",
        str(audio_path),
        "-map",
        "0:v:0",
        "-map",
        "1:a:0",
        "-c:v",
        "copy",
        "-c:a",
        "aac",
        "-shortest",
        str(output_path),
    ]


def build_concat_command(
    list_path: Path,
    output_path: Path,
) -> list[str]:
    return [
        "ffmpeg",
        "-y",
        "-f",
        "concat",
        "-safe",
        "0",
        "-i",
        str(list_path),
        "-c",
        "copy",
        str(output_path),
    ]


def probe_media_duration(media_path: Path) -> float:
    command = [
        "ffprobe",
        "-v",
        "error",
        "-show_entries",
        "format=duration",
        "-of",
        "default=noprint_wrappers=1:nokey=1",
        str(media_path),
    ]
    result = subprocess.run(command, capture_output=True, text=True, check=True)
    return float(result.stdout.strip())


async def _synthesize_audio_bytes(text: str, voice: str) -> bytes:
    communicator = edge_tts.Communicate(text=text, voice=voice)
    buffer = BytesIO()
    async for chunk in communicator.stream():
        if chunk["type"] == "audio":
            buffer.write(chunk["data"])
    audio = buffer.getvalue()
    if not audio:
        raise RuntimeError("No audio returned from Edge TTS.")
    return audio


def _build_atempo_chain(speed: float) -> list[str]:
    if speed <= 1.0:
        return []

    parts: list[str] = []
    remaining = float(speed)
    while remaining > 2.0:
        parts.append("atempo=2.0")
        remaining /= 2.0
    if abs(remaining - round(remaining)) < 1e-9:
        parts.append(f"atempo={remaining:.1f}")
    else:
        parts.append(f"atempo={remaining:.3f}".rstrip("0").rstrip("."))
    return parts


def _run_command(command: list[str]) -> None:
    try:
        subprocess.run(command, check=True, capture_output=True, text=True)
    except subprocess.CalledProcessError as exc:  # pragma: no cover
        message = exc.stderr.strip() or exc.stdout.strip() or str(exc)
        raise RuntimeError(message) from exc


def _build_concat_list_line(segment_file: str) -> str:
    escaped = segment_file.replace("'", "''")
    return "file '" + escaped + "'"
