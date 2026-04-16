from __future__ import annotations

import unittest

from services.event_merging import EventMergeConfig, merge_dynamic_segments_into_events


class EventMergingTests(unittest.TestCase):
    def test_merges_short_adjacent_fragments_under_weak_boundaries(self) -> None:
        result = merge_dynamic_segments_into_events(
            dynamic_segments=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.2, "durationSec": 2.2},
                {"index": 3, "startSec": 4.2, "endSec": 6.1, "durationSec": 1.9},
                {"index": 4, "startSec": 6.1, "endSec": 10.0, "durationSec": 3.9},
            ],
            boundary_candidates=[
                {"timeSec": 2.0, "score": 0.77, "origin": "scene-detector"},
                {"timeSec": 4.2, "score": 0.76, "origin": "scene-detector"},
                {"timeSec": 6.1, "score": 0.88, "origin": "scene-detector+subject"},
            ],
            config=EventMergeConfig(),
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 6.1), (6.1, 10.0)],
        )
        self.assertEqual(result["mergedBoundaryPointsSec"], [2.0, 4.2])
        self.assertEqual(result["keptBoundaryPointsSec"], [6.1])

    def test_preserves_strong_boundaries_for_substantial_segments(self) -> None:
        result = merge_dynamic_segments_into_events(
            dynamic_segments=[
                {"index": 1, "startSec": 0.0, "endSec": 4.0, "durationSec": 4.0},
                {"index": 2, "startSec": 4.0, "endSec": 8.5, "durationSec": 4.5},
                {"index": 3, "startSec": 8.5, "endSec": 12.5, "durationSec": 4.0},
            ],
            boundary_candidates=[
                {"timeSec": 4.0, "score": 0.88, "origin": "scene-detector+subject"},
                {"timeSec": 8.5, "score": 0.84, "origin": "scene-detector"},
            ],
            config=EventMergeConfig(),
        )

        self.assertEqual(result["summary"]["eventCount"], 3)
        self.assertEqual(result["keptBoundaryPointsSec"], [4.0, 8.5])
        self.assertEqual(result["mergedBoundaryPointsSec"], [])

    def test_max_event_guardrail_prevents_infinite_merge(self) -> None:
        result = merge_dynamic_segments_into_events(
            dynamic_segments=[
                {"index": 1, "startSec": 0.0, "endSec": 3.0, "durationSec": 3.0},
                {"index": 2, "startSec": 3.0, "endSec": 6.0, "durationSec": 3.0},
                {"index": 3, "startSec": 6.0, "endSec": 9.0, "durationSec": 3.0},
                {"index": 4, "startSec": 9.0, "endSec": 12.0, "durationSec": 3.0},
            ],
            boundary_candidates=[
                {"timeSec": 3.0, "score": 0.74, "origin": "scene-detector"},
                {"timeSec": 6.0, "score": 0.75, "origin": "scene-detector"},
                {"timeSec": 9.0, "score": 0.73, "origin": "scene-detector"},
            ],
            config=EventMergeConfig(max_event_sec=8.0),
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["events"]],
            [(0.0, 9.0), (9.0, 12.0)],
        )
        self.assertEqual(result["mergedBoundaryPointsSec"], [3.0, 6.0])
        self.assertEqual(result["keptBoundaryPointsSec"], [9.0])


if __name__ == "__main__":
    unittest.main()
