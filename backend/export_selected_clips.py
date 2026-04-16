from __future__ import annotations

import argparse
from pathlib import Path

from services.frame_aligned_clip_export import export_selected_clips_from_manifest


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Export selected clips with frame-aligned boundaries.")
    parser.add_argument("--video", required=True, help="Source video path.")
    parser.add_argument("--manifest", required=True, help="Selected clip manifest path.")
    parser.add_argument("--output", required=True, help="Output directory.")
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    result = export_selected_clips_from_manifest(
        video_path=Path(args.video).resolve(),
        manifest_path=Path(args.manifest).resolve(),
        output_dir=Path(args.output).resolve(),
    )
    print(f"[Done] Exported clips: {len(result.get('selectedClips', []))}")
    print(f"[Done] Manifest: {Path(args.output).resolve() / 'selected_clips_manifest.json'}")


if __name__ == "__main__":
    main()
