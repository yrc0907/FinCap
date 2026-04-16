from __future__ import annotations

import json
import math
import subprocess
from pathlib import Path
from typing import Any

import cv2


def attach_frame_alignment_to_selected_clips(
    selected_clips: list[dict[str, Any]],
    fps: float,
    video_duration_sec: float,
    frame_count: int | None = None,
) -> list[dict[str, Any]]:
    if fps <= 0.0:
        return [dict(clip) for clip in selected_clips]

    total_frames = _resolve_total_frames(
        fps=fps,
        video_duration_sec=video_duration_sec,
        frame_count=frame_count,
    )
    aligned_clips: list[dict[str, Any]] = []
    for clip in selected_clips:
        start_sec = float(clip.get("startSec", 0.0))
        end_sec = float(clip.get("endSec", start_sec))
        export_start_frame = _align_second_to_frame(start_sec, fps=fps, total_frames=total_frames)
        export_end_frame = _align_second_to_frame(end_sec, fps=fps, total_frames=total_frames)
        if export_end_frame < export_start_frame:
            export_end_frame = export_start_frame

        aligned = dict(clip)
        aligned["exportStartFrame"] = export_start_frame
        aligned["exportEndFrame"] = export_end_frame
        aligned["exportStartSec"] = round(export_start_frame / fps, 3)
        aligned["exportEndSec"] = round(export_end_frame / fps, 3)
        aligned["exportDurationSec"] = round((export_end_frame - export_start_frame) / fps, 3)
        aligned_clips.append(aligned)

    return aligned_clips


def build_ffmpeg_frame_export_command(
    video_path: Path,
    output_path: Path,
    export_start_frame: int,
    export_end_frame: int,
    export_start_sec: float,
    export_end_sec: float,
) -> list[str]:
    trim_filter = f"trim=start_frame={int(export_start_frame)}:end_frame={int(export_end_frame)},setpts=PTS-STARTPTS"
    audio_filter = f"atrim=start={float(export_start_sec):.3f}:end={float(export_end_sec):.3f},asetpts=PTS-STARTPTS"
    return [
        "ffmpeg",
        "-y",
        "-i",
        str(video_path),
        "-map",
        "0:v:0",
        "-map",
        "0:a:0?",
        "-vf",
        trim_filter,
        "-af",
        audio_filter,
        "-c:v",
        "libx264",
        "-c:a",
        "aac",
        str(output_path),
    ]


def enrich_selected_clip_manifest(
    manifest: dict[str, Any],
    fps: float,
    video_duration_sec: float,
    frame_count: int | None = None,
) -> dict[str, Any]:
    selected_clips = manifest.get("selectedClips", [])
    enriched_manifest = dict(manifest)
    enriched_manifest["selectedClips"] = attach_frame_alignment_to_selected_clips(
        selected_clips=[dict(clip) for clip in selected_clips],
        fps=fps,
        video_duration_sec=video_duration_sec,
        frame_count=frame_count,
    )
    return enriched_manifest


def export_selected_clips_from_manifest(
    video_path: Path,
    manifest_path: Path,
    output_dir: Path,
) -> dict[str, Any]:
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    video_meta = inspect_video_timeline(video_path)
    enriched_manifest = enrich_selected_clip_manifest(
        manifest=manifest,
        fps=video_meta["fps"],
        video_duration_sec=video_meta["durationSec"],
        frame_count=video_meta["frameCount"],
    )

    clips_dir = output_dir / "clips"
    clips_dir.mkdir(parents=True, exist_ok=True)

    exported_clips: list[dict[str, Any]] = []
    for clip in enriched_manifest.get("selectedClips", []):
        output_path = clips_dir / _build_output_file_name(clip)
        command = build_ffmpeg_frame_export_command(
            video_path=video_path,
            output_path=output_path,
            export_start_frame=int(clip["exportStartFrame"]),
            export_end_frame=int(clip["exportEndFrame"]),
            export_start_sec=float(clip["exportStartSec"]),
            export_end_sec=float(clip["exportEndSec"]),
        )
        subprocess.run(command, check=True, capture_output=True, text=True)
        exported_clip = dict(clip)
        exported_clip["file"] = str(output_path.resolve())
        exported_clips.append(exported_clip)

    export_manifest = dict(enriched_manifest)
    export_manifest["video"] = str(video_path.resolve())
    export_manifest["videoIndex"] = video_meta
    export_manifest["selectedClips"] = exported_clips
    manifest_output_path = output_dir / "selected_clips_manifest.json"
    manifest_output_path.write_text(
        json.dumps(export_manifest, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )
    return export_manifest


def inspect_video_timeline(video_path: Path) -> dict[str, Any]:
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError(f"Unable to open video file: {video_path}")

    try:
        fps = float(capture.get(cv2.CAP_PROP_FPS) or 0.0)
        frame_count = int(capture.get(cv2.CAP_PROP_FRAME_COUNT) or 0)
    finally:
        capture.release()

    if fps <= 0.0:
        raise RuntimeError(f"Unable to inspect FPS for video: {video_path}")

    duration_sec = frame_count / fps if frame_count > 0 else 0.0
    return {
        "fps": round(fps, 3),
        "frameCount": frame_count,
        "durationSec": round(duration_sec, 3),
    }


def _resolve_total_frames(
    fps: float,
    video_duration_sec: float,
    frame_count: int | None,
) -> int:
    if frame_count is not None and frame_count >= 0:
        return int(frame_count)
    return max(0, int(math.ceil(max(0.0, float(video_duration_sec)) * fps - 1e-9)))


def _align_second_to_frame(
    second: float,
    fps: float,
    total_frames: int,
) -> int:
    safe_second = max(0.0, float(second))
    frame_index = int(math.ceil(safe_second * fps - 1e-9))
    return min(max(0, frame_index), total_frames)


def _build_output_file_name(clip: dict[str, Any]) -> str:
    index = int(clip.get("index", 0))
    label = str(clip.get("label", "clip")).strip() or "clip"
    start_sec = float(clip.get("exportStartSec", clip.get("startSec", 0.0)))
    end_sec = float(clip.get("exportEndSec", clip.get("endSec", 0.0)))
    return f"clip_{index:02d}_{label}_{start_sec:06.3f}_{end_sec:06.3f}.mp4"
