from __future__ import annotations

import unittest
from pathlib import Path

from services.frame_aligned_clip_export import (
    attach_frame_alignment_to_selected_clips,
    build_ffmpeg_frame_export_command,
)


class FrameAlignedClipExportTests(unittest.TestCase):
    def test_aligns_adjacent_clip_ranges_without_shared_frames(self) -> None:
        clips = attach_frame_alignment_to_selected_clips(
            selected_clips=[
                {"index": 1, "startSec": 0.0, "endSec": 10.753},
                {"index": 2, "startSec": 10.753, "endSec": 16.153},
            ],
            fps=30.0,
            video_duration_sec=60.967,
        )

        self.assertEqual(clips[0]["exportStartFrame"], 0)
        self.assertEqual(clips[0]["exportEndFrame"], 323)
        self.assertEqual(clips[1]["exportStartFrame"], 323)
        self.assertEqual(clips[1]["exportEndFrame"], 485)
        self.assertEqual(clips[0]["exportEndFrame"], clips[1]["exportStartFrame"])

    def test_clamps_export_frames_inside_video_bounds(self) -> None:
        clips = attach_frame_alignment_to_selected_clips(
            selected_clips=[{"index": 1, "startSec": -0.2, "endSec": 99.0}],
            fps=24.0,
            video_duration_sec=3.0,
        )

        self.assertEqual(clips[0]["exportStartFrame"], 0)
        self.assertEqual(clips[0]["exportEndFrame"], 72)

    def test_builds_trim_filters_from_frame_range(self) -> None:
        command = build_ffmpeg_frame_export_command(
            video_path=Path("input.mp4"),
            output_path=Path("output.mp4"),
            export_start_frame=323,
            export_end_frame=485,
            export_start_sec=10.767,
            export_end_sec=16.167,
        )

        command_text = " ".join(command)
        self.assertIn("trim=start_frame=323:end_frame=485", command_text)
        self.assertIn("atrim=start=10.767:end=16.167", command_text)


if __name__ == "__main__":
    unittest.main()
