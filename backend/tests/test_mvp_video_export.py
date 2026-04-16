from __future__ import annotations

import unittest
from pathlib import Path

from services.mvp_video_export import (
    build_audio_fit_command,
    build_concat_command,
    build_mux_command,
)


class MvpVideoExportTests(unittest.TestCase):
    def test_build_audio_fit_command_adds_atempo_when_needed(self) -> None:
        command = build_audio_fit_command(
            input_audio_path=Path("voice.mp3"),
            output_audio_path=Path("voice_fit.m4a"),
            source_duration_sec=8.0,
            target_duration_sec=4.0,
        )

        self.assertEqual(command[0], "ffmpeg")
        filter_value = command[command.index("-filter:a") + 1]
        self.assertIn("atempo=2.0", filter_value)
        self.assertIn("atrim=0:4.000", filter_value)

    def test_build_mux_command_maps_video_and_fitted_audio(self) -> None:
        command = build_mux_command(
            clip_path=Path("clip.mp4"),
            audio_path=Path("voice_fit.m4a"),
            output_path=Path("segment.mp4"),
        )

        self.assertEqual(
            command,
            [
                "ffmpeg",
                "-y",
                "-i",
                "clip.mp4",
                "-i",
                "voice_fit.m4a",
                "-map",
                "0:v:0",
                "-map",
                "1:a:0",
                "-c:v",
                "copy",
                "-c:a",
                "aac",
                "-shortest",
                "segment.mp4",
            ],
        )

    def test_build_concat_command_uses_concat_demuxer(self) -> None:
        command = build_concat_command(
            list_path=Path("segments.txt"),
            output_path=Path("final.mp4"),
        )

        self.assertEqual(
            command,
            [
                "ffmpeg",
                "-y",
                "-f",
                "concat",
                "-safe",
                "0",
                "-i",
                "segments.txt",
                "-c",
                "copy",
                "final.mp4",
            ],
        )


if __name__ == "__main__":
    unittest.main()
