from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.vlm_shot_analysis import (
    VlmShotAnalysisConfig,
    _normalize_group_result,
    analyze_shot_sequence,
)


class VlmShotAnalysisTests(unittest.TestCase):
    @patch("services.vlm_shot_analysis._extract_keyframes_for_shot")
    @patch("services.vlm_shot_analysis.call_openai_compatible_vision")
    def test_returns_group_scores_and_peak_times(
        self,
        call_openai_mock,
        extract_keyframes_mock,
    ) -> None:
        extract_keyframes_mock.side_effect = [
            [
                {"timeSec": 4.5, "jpegBase64": "aaa"},
                {"timeSec": 5.4, "jpegBase64": "bbb"},
            ],
            [
                {"timeSec": 6.6, "jpegBase64": "ccc"},
                {"timeSec": 7.4, "jpegBase64": "ddd"},
            ],
        ]
        call_openai_mock.return_value = {
            "is_continuous_story": True,
            "merge_with_prev": False,
            "merge_with_next": True,
            "highlight_score": 0.88,
            "peak_times": [5.4, 7.4],
            "peak_role": "conflict",
            "reason": "Action escalation continues across both shots.",
        }

        result = analyze_shot_sequence(
            video_path=Path("text_video.mp4"),
            shots=[
                {"index": 1, "startSec": 4.033, "endSec": 6.2, "durationSec": 2.167},
                {"index": 2, "startSec": 6.2, "endSec": 8.1, "durationSec": 1.9},
            ],
            vlm_config={
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "test-key",
                "model": "gpt-4.1-mini",
            },
            config=VlmShotAnalysisConfig(group_size=2, keyframes_per_shot=2),
        )

        self.assertEqual(result["summary"]["groupCount"], 1)
        self.assertEqual(result["summary"]["highlightGroupCount"], 1)
        self.assertEqual(result["groups"][0]["highlightScore"], 0.88)
        self.assertEqual(result["groups"][0]["peakTimesSec"], [5.4, 7.4])
        self.assertEqual(result["groups"][0]["peakRole"], "conflict")
        self.assertTrue(result["groups"][0]["isContinuousStory"])
        self.assertFalse(result["groups"][0]["mergeWithNext"])
        self.assertEqual(result["groups"][0]["reason"], "Action escalation continues across both shots.")

    def test_groups_adjacent_shots_by_configured_window(self) -> None:
        with (
            patch("services.vlm_shot_analysis._extract_keyframes_for_shot", return_value=[]),
            patch(
                "services.vlm_shot_analysis.call_openai_compatible_vision",
                return_value={
                    "is_continuous_story": False,
                    "merge_with_prev": False,
                    "merge_with_next": False,
                    "highlight_score": 0.31,
                    "peak_times": [],
                    "peak_role": "setup",
                    "reason": "Calm transition.",
                },
            ),
        ):
            result = analyze_shot_sequence(
                video_path=Path("text_video.mp4"),
                shots=[
                    {"index": 1, "startSec": 0.0, "endSec": 1.0, "durationSec": 1.0},
                    {"index": 2, "startSec": 1.0, "endSec": 2.0, "durationSec": 1.0},
                    {"index": 3, "startSec": 2.0, "endSec": 3.0, "durationSec": 1.0},
                ],
                vlm_config={
                    "endpoint": "https://example.com/v1/chat/completions",
                    "key": "test-key",
                    "model": "gpt-4.1-mini",
                },
                config=VlmShotAnalysisConfig(group_size=2, keyframes_per_shot=2),
            )

        self.assertEqual(len(result["groups"]), 2)
        self.assertEqual(result["groups"][0]["shotIndexes"], [1, 2])
        self.assertEqual(result["groups"][1]["shotIndexes"], [3])

    def test_normalizes_invalid_peak_role_from_reason_keywords(self) -> None:
        with (
            patch("services.vlm_shot_analysis._extract_keyframes_for_shot", return_value=[]),
            patch(
                "services.vlm_shot_analysis.call_openai_compatible_vision",
                return_value={
                    "is_continuous_story": True,
                    "merge_with_prev": False,
                    "merge_with_next": False,
                    "highlight_score": 0.66,
                    "peak_times": [1.4],
                    "peak_role": "Doraemon",
                    "reason": "The same character exits the building, indicating a continuous transition.",
                },
            ),
        ):
            result = analyze_shot_sequence(
                video_path=Path("text_video.mp4"),
                shots=[
                    {"index": 1, "startSec": 1.0, "endSec": 2.0, "durationSec": 1.0},
                ],
                vlm_config={
                    "endpoint": "https://example.com/v1/chat/completions",
                    "key": "test-key",
                    "model": "gpt-4.1",
                },
                config=VlmShotAnalysisConfig(group_size=2, keyframes_per_shot=2),
            )

        self.assertEqual(result["groups"][0]["peakRole"], "transition")

    def test_accepts_peak_times_with_seconds_suffix(self) -> None:
        with (
            patch("services.vlm_shot_analysis._extract_keyframes_for_shot", return_value=[]),
            patch(
                "services.vlm_shot_analysis.call_openai_compatible_vision",
                return_value={
                    "is_continuous_story": True,
                    "highlight_score": 0.73,
                    "peak_times": ["1.400s", "1.700 sec", "bad"],
                    "peak_role": "payoff",
                    "reason": "The reveal lands at the end of the shot.",
                },
            ),
        ):
            result = analyze_shot_sequence(
                video_path=Path("text_video.mp4"),
                shots=[
                    {"index": 1, "startSec": 1.0, "endSec": 2.0, "durationSec": 1.0},
                ],
                vlm_config={
                    "endpoint": "https://example.com/v1/chat/completions",
                    "key": "test-key",
                    "model": "gpt-4.1",
                },
                config=VlmShotAnalysisConfig(group_size=2, keyframes_per_shot=2),
            )

        self.assertEqual(result["groups"][0]["peakTimesSec"], [1.4, 1.7])

    def test_normalized_group_result_returns_speaker_hint(self) -> None:
        result = _normalize_group_result(
            group_index=1,
            shot_group=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
            ],
            raw={
                "is_continuous_story": True,
                "highlight_score": 0.82,
                "peak_times": [1.0],
                "peak_role": "conflict",
                "reason": "Boss pressures the father.",
                "speaker_hint": "boss",
                "speaker_confidence": 0.76,
                "evidence_source": "ocr",
                "text_conflict": False,
            },
        )

        self.assertEqual(result["speakerHint"], "boss")
        self.assertEqual(result["speakerConfidence"], 0.76)
        self.assertEqual(result["evidenceSource"], "ocr")
        self.assertFalse(result["textConflict"])


if __name__ == "__main__":
    unittest.main()
