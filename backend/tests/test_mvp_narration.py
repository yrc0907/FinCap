from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.mvp_narration import (
    NarrationGenerationConfig,
    generate_clip_narrations,
    normalize_narration_response,
)


class MvpNarrationTests(unittest.TestCase):
    def test_normalize_narration_response_enforces_bounds(self) -> None:
        result = normalize_narration_response(
            clip={"index": 2, "startSec": 10.0, "endSec": 15.0, "durationSec": 5.0},
            raw={"summary": "A conflict grows.", "narration": "  主角终于开始反击，局势一下子紧张起来了。  "},
            max_characters=12,
        )

        self.assertEqual(result["clipIndex"], 2)
        self.assertEqual(result["summary"], "A conflict grows.")
        self.assertEqual(result["narration"], "主角终于开始反击，局势一")
        self.assertEqual(result["startSec"], 10.0)
        self.assertEqual(result["endSec"], 15.0)

    @patch("services.mvp_narration.call_openai_compatible_vision")
    @patch("services.mvp_narration.extract_clip_keyframes")
    def test_generate_clip_narrations_returns_ordered_items(
        self,
        extract_keyframes_mock,
        vision_mock,
    ) -> None:
        extract_keyframes_mock.side_effect = [
            [{"timeSec": 1.0, "jpegBase64": "abc"}],
            [{"timeSec": 6.0, "jpegBase64": "def"}],
        ]
        vision_mock.side_effect = [
            {"summary": "Opening setup.", "narration": "故事开场，角色登场。"},
            {"summary": "Conflict grows.", "narration": "冲突升级，气氛突然绷紧。"},
        ]

        result = generate_clip_narrations(
            video_path=Path("demo.mp4"),
            selected_clips=[
                {"index": 1, "startSec": 0.0, "endSec": 4.0, "durationSec": 4.0},
                {"index": 2, "startSec": 4.0, "endSec": 8.0, "durationSec": 4.0},
            ],
            vlm_config={
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "demo",
                "model": "gpt-4.1",
            },
            config=NarrationGenerationConfig(keyframes_per_clip=1, chars_per_second=3.0),
        )

        self.assertEqual(len(result["clips"]), 2)
        self.assertEqual(result["clips"][0]["clipIndex"], 1)
        self.assertEqual(result["clips"][0]["narration"], "故事开场，角色登场。")
        self.assertEqual(result["clips"][1]["clipIndex"], 2)
        self.assertEqual(result["clips"][1]["summary"], "Conflict grows.")
        self.assertEqual(result["summary"]["clipCount"], 2)
        self.assertEqual(result["summary"]["totalNarrationCharacters"], 22)


if __name__ == "__main__":
    unittest.main()
