from __future__ import annotations

import unittest
from pathlib import Path

from services.functional_clip_export import (
    build_functional_clip_file_name,
    build_functional_clip_manifest,
)


class FunctionalClipExportTests(unittest.TestCase):
    def test_build_functional_clip_file_name_uses_type_when_label_missing(self) -> None:
        name = build_functional_clip_file_name(
            {
                "index": 3,
                "type": "peak",
                "exportStartSec": 24.033,
                "exportEndSec": 25.333,
            }
        )

        self.assertEqual(name, "clip_03_peak_24.033_25.333.mp4")

    def test_build_functional_clip_manifest_aligns_export_fields(self) -> None:
        manifest = build_functional_clip_manifest(
            video_path=Path("demo.mp4"),
            clips=[
                {"index": 1, "type": "peak", "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
            ],
            fps=30.0,
            video_duration_sec=10.0,
            frame_count=300,
        )

        self.assertEqual(manifest["video"], str(Path("demo.mp4").resolve()))
        self.assertEqual(manifest["clips"][0]["exportStartFrame"], 120)
        self.assertEqual(manifest["clips"][0]["exportEndFrame"], 180)


if __name__ == "__main__":
    unittest.main()
