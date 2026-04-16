from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.shot_level_vlm_segments import (
    ShotLevelVlmSegmentConfig,
    extract_shot_level_vlm_segments,
)


class ShotLevelVlmSegmentsTests(unittest.TestCase):
    @patch("services.shot_level_vlm_segments.extract_shot_keyframes")
    @patch("services.shot_level_vlm_segments.call_openai_compatible_vision")
    def test_selects_single_main_peak_and_expands_by_continuity(
        self,
        vision_mock,
        keyframes_mock,
    ) -> None:
        keyframes_mock.return_value = [{"timeSec": 1.0, "jpegBase64": "abc"}]
        vision_mock.side_effect = [
            {
                "main_peak_shot_index": 3,
                "peak_confidence": 0.92,
                "peak_reason": "Shot 3 is the decisive impact.",
                "shot_roles": [
                    {"shot_index": 1, "role": "build", "score": 0.45},
                    {"shot_index": 2, "role": "build", "score": 0.58},
                    {"shot_index": 3, "role": "peak", "score": 0.95},
                    {"shot_index": 4, "role": "result", "score": 0.67},
                    {"shot_index": 5, "role": "transition", "score": 0.22},
                ],
            },
            {"same_sequence": True, "role": "build", "confidence": 0.88, "reason": "Same buildup."},
            {"same_sequence": True, "role": "build", "confidence": 0.72, "reason": "Still buildup."},
            {"same_sequence": True, "role": "result", "confidence": 0.84, "reason": "Immediate aftermath."},
            {"same_sequence": False, "role": "transition", "confidence": 0.8, "reason": "Next story."},
        ]

        result = extract_shot_level_vlm_segments(
            video_path=Path("demo.mp4"),
            events=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "durationSec": 10.0,
                    "sourceGroupIndexes": [1],
                }
            ],
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 10.0,
                    "peakTimesSec": [5.0],
                    "peakRole": "conflict",
                    "highlightScore": 0.8,
                }
            ],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0, "durationSec": 2.0},
                {"index": 5, "startSec": 8.0, "endSec": 10.0, "durationSec": 2.0},
            ],
            vlm_config={"endpoint": "https://example.com", "key": "demo", "model": "gpt-4.1"},
            config=ShotLevelVlmSegmentConfig(keyframes_per_shot=1),
        )

        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["functionalClips"]],
            [("build", 0.0, 4.0), ("peak", 4.0, 6.0), ("result", 6.0, 8.0)],
        )
        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["peakClips"]],
            [(4.0, 6.0)],
        )
        self.assertEqual(result["events"][0]["mainPeakShotIndex"], 3)

    @patch("services.shot_level_vlm_segments.extract_shot_keyframes")
    @patch("services.shot_level_vlm_segments.call_openai_compatible_vision")
    def test_stops_when_adjacent_shot_fails_second_judgment(
        self,
        vision_mock,
        keyframes_mock,
    ) -> None:
        keyframes_mock.return_value = [{"timeSec": 1.0, "jpegBase64": "abc"}]
        vision_mock.side_effect = [
            {
                "main_peak_shot_index": 2,
                "peak_confidence": 0.9,
                "peak_reason": "Shot 2 is the main climax.",
                "shot_roles": [
                    {"shot_index": 1, "role": "build", "score": 0.5},
                    {"shot_index": 2, "role": "peak", "score": 0.95},
                    {"shot_index": 3, "role": "result", "score": 0.5},
                    {"shot_index": 4, "role": "result", "score": 0.45},
                ],
            },
            {"same_sequence": False, "role": "transition", "confidence": 0.85, "reason": "Different scene."},
            {"same_sequence": True, "role": "result", "confidence": 0.82, "reason": "Immediate result."},
            {"same_sequence": False, "role": "transition", "confidence": 0.9, "reason": "Next sequence."},
        ]

        result = extract_shot_level_vlm_segments(
            video_path=Path("demo.mp4"),
            events=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 8.0,
                    "durationSec": 8.0,
                    "sourceGroupIndexes": [1],
                }
            ],
            groups=[
                {
                    "index": 1,
                    "startSec": 0.0,
                    "endSec": 8.0,
                    "peakTimesSec": [3.1],
                    "peakRole": "conflict",
                    "highlightScore": 0.84,
                }
            ],
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0, "durationSec": 2.0},
            ],
            vlm_config={"endpoint": "https://example.com", "key": "demo", "model": "gpt-4.1"},
            config=ShotLevelVlmSegmentConfig(keyframes_per_shot=1),
        )

        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["functionalClips"]],
            [("peak", 2.0, 4.0), ("result", 4.0, 6.0)],
        )
        self.assertEqual(
            [(item["type"], item["startSec"], item["endSec"]) for item in result["events"][0]["functionalSegments"]],
            [("transition", 0.0, 2.0), ("peak", 2.0, 4.0), ("result", 4.0, 6.0), ("transition", 6.0, 8.0)],
        )


if __name__ == "__main__":
    unittest.main()
