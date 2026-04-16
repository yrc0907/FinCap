from __future__ import annotations

import argparse
import json
from pathlib import Path

from services.frame_aligned_clip_export import export_selected_clips_from_manifest
from services.mvp_narration import generate_clip_narrations
from services.mvp_video_export import export_mvp_video


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate narration, TTS, and a final MVP video.")
    parser.add_argument("--video", required=True, help="Source video path.")
    parser.add_argument("--manifest", required=True, help="Selected clips manifest path.")
    parser.add_argument("--output", required=True, help="Output directory.")
    parser.add_argument("--vlm-endpoint", required=True, help="OpenAI-compatible vision endpoint.")
    parser.add_argument("--vlm-key", required=True, help="OpenAI-compatible API key.")
    parser.add_argument("--vlm-model", required=True, help="Vision-capable model name.")
    parser.add_argument("--tts-voice", required=True, help="Edge TTS voice short name.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    video_path = Path(args.video).resolve()
    manifest_path = Path(args.manifest).resolve()
    output_dir = Path(args.output).resolve()

    clip_manifest = _load_or_export_clip_manifest(
        video_path=video_path,
        manifest_path=manifest_path,
        output_dir=output_dir,
    )
    narrations = generate_clip_narrations(
        video_path=video_path,
        selected_clips=clip_manifest.get("selectedClips", []),
        vlm_config={
            "endpoint": args.vlm_endpoint,
            "key": args.vlm_key,
            "model": args.vlm_model,
        },
    )
    narration_manifest_path = output_dir / "narration_manifest.json"
    narration_manifest_path.parent.mkdir(parents=True, exist_ok=True)
    narration_manifest_path.write_text(
        json.dumps(narrations, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )
    result = export_mvp_video(
        selected_clip_manifest=clip_manifest,
        narrations=narrations,
        tts_voice=args.tts_voice,
        output_dir=output_dir,
    )
    print(f"[Done] Narration manifest: {narration_manifest_path}")
    print(f"[Done] Final video: {result['finalVideo']}")


def _load_or_export_clip_manifest(
    video_path: Path,
    manifest_path: Path,
    output_dir: Path,
) -> dict[str, object]:
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    selected_clips = manifest.get("selectedClips", [])
    if selected_clips and all(str(item.get("file", "")).strip() for item in selected_clips):
        return manifest

    export_dir = output_dir / "selected-clips"
    return export_selected_clips_from_manifest(
        video_path=video_path,
        manifest_path=manifest_path,
        output_dir=export_dir,
    )


if __name__ == "__main__":
    main()
