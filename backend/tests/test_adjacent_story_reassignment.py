from __future__ import annotations

import unittest
from unittest.mock import patch

from services.adjacent_story_reassignment import analyze_adjacent_story_reassignment


class AdjacentStoryReassignmentTests(unittest.TestCase):
    @patch("services.adjacent_story_reassignment.call_openai_compatible_json")
    def test_detects_tail_reassignment_between_adjacent_groups(self, call_model_mock) -> None:
        call_model_mock.return_value = {
            "should_reassign_tail": True,
            "reassign_from_sec": 8.1,
            "source_group_index": 1,
            "target_group_index": 2,
            "confidence": 0.84,
            "reason": "The first group's last beat introduces the next chase.",
        }

        result = analyze_adjacent_story_reassignment(
            groups=[
                {
                    "index": 1,
                    "startSec": 4.033,
                    "endSec": 10.733,
                    "shotIndexes": [1, 2],
                    "highlightScore": 0.5,
                    "peakTimesSec": [8.1],
                    "peakRole": "buildup",
                    "reason": "A calm setup shifts into a chase.",
                },
                {
                    "index": 2,
                    "startSec": 10.733,
                    "endSec": 16.133,
                    "shotIndexes": [3, 4],
                    "highlightScore": 0.8,
                    "peakTimesSec": [12.5],
                    "peakRole": "conflict",
                    "reason": "The chase continues and escalates.",
                },
            ],
            llm_config={
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "test-key",
                "model": "gpt-4.1",
            },
        )

        self.assertEqual(result["summary"]["pairCount"], 1)
        self.assertEqual(result["summary"]["reassignmentCount"], 1)
        self.assertEqual(result["pairs"][0]["leftGroupIndex"], 1)
        self.assertEqual(result["pairs"][0]["rightGroupIndex"], 2)
        self.assertTrue(result["pairs"][0]["shouldReassignTail"])
        self.assertEqual(result["pairs"][0]["reassignFromSec"], 8.1)

    @patch("services.adjacent_story_reassignment.call_openai_compatible_json")
    def test_only_compares_adjacent_pairs(self, call_model_mock) -> None:
        call_model_mock.return_value = {
            "should_reassign_tail": False,
            "reassign_from_sec": None,
            "source_group_index": None,
            "target_group_index": None,
            "confidence": 0.2,
            "reason": "No story handoff.",
        }

        result = analyze_adjacent_story_reassignment(
            groups=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "shotIndexes": [1], "reason": "A"},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "shotIndexes": [2], "reason": "B"},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "shotIndexes": [3], "reason": "C"},
            ],
            llm_config={
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "test-key",
                "model": "gpt-4.1",
            },
        )

        self.assertEqual(call_model_mock.call_count, 2)
        self.assertEqual([pair["leftGroupIndex"] for pair in result["pairs"]], [1, 2])
        self.assertEqual([pair["rightGroupIndex"] for pair in result["pairs"]], [2, 3])


if __name__ == "__main__":
    unittest.main()
