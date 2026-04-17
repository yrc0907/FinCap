from __future__ import annotations

import time
from pathlib import Path
from typing import Any

from services.functional_clip_export import export_functional_clips


def export_project_functional_clips(
    project_id: str,
    video_path: Path,
    clips: list[dict[str, Any]],
    output_root: Path,
) -> dict[str, Any]:
    timestamp = time.strftime("%Y%m%d-%H%M%S")
    output_dir = output_root / project_id / f"functional-clips-{timestamp}"
    manifest = export_functional_clips(
        video_path=video_path,
        clips=clips,
        output_dir=output_dir,
    )
    return {
        "projectId": project_id,
        "clipCount": len(manifest.get("clips", [])),
        "outputDir": str(output_dir.resolve()),
        "manifest": manifest,
    }
