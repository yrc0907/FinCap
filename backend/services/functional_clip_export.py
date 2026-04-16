from __future__ import annotations

import json
import subprocess
from pathlib import Path
from typing import Any

from .frame_aligned_clip_export import (
    attach_frame_alignment_to_selected_clips,
    build_ffmpeg_frame_export_command,
    inspect_video_timeline,
)


def build_functional_clip_manifest(
    video_path: Path,
    clips: list[dict[str, Any]],
    fps: float,
    video_duration_sec: float,
    frame_count: int | None = None,
) -> dict[str, Any]:
    aligned_clips = attach_frame_alignment_to_selected_clips(
        selected_clips=[dict(clip) for clip in clips],
        fps=fps,
        video_duration_sec=video_duration_sec,
        frame_count=frame_count,
    )
    return {
        "video": str(video_path.resolve()),
        "clips": aligned_clips,
    }


def export_functional_clips(
    video_path: Path,
    clips: list[dict[str, Any]],
    output_dir: Path,
) -> dict[str, Any]:
    output_dir.mkdir(parents=True, exist_ok=True)
    video_meta = inspect_video_timeline(video_path)
    manifest = build_functional_clip_manifest(
        video_path=video_path,
        clips=clips,
        fps=float(video_meta["fps"]),
        video_duration_sec=float(video_meta["durationSec"]),
        frame_count=int(video_meta["frameCount"]),
    )
    exported_clips: list[dict[str, Any]] = []
    for clip in manifest["clips"]:
        output_path = output_dir / build_functional_clip_file_name(clip)
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

    export_manifest = {
        "video": manifest["video"],
        "videoIndex": video_meta,
        "clips": exported_clips,
    }
    manifest_path = output_dir / "functional_clips_manifest.json"
    manifest_path.write_text(json.dumps(export_manifest, ensure_ascii=False, indent=2), encoding="utf-8")
    return export_manifest


def build_functional_clip_file_name(clip: dict[str, Any]) -> str:
    index = int(clip.get("index", 0))
    label = str(clip.get("label") or clip.get("type") or "clip").strip() or "clip"
    start_sec = float(clip.get("exportStartSec", clip.get("startSec", 0.0)))
    end_sec = float(clip.get("exportEndSec", clip.get("endSec", 0.0)))
    return f"clip_{index:02d}_{label}_{start_sec:06.3f}_{end_sec:06.3f}.mp4"
