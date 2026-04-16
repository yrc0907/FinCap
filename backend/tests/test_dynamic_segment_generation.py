from __future__ import annotations

import unittest

from services.dynamic_segment_generation import (
    DynamicSegmentConfig,
    generate_dynamic_segments,
)


class DynamicSegmentGenerationTests(unittest.TestCase):
    def test_generates_continuous_segments_from_boundaries(self) -> None:
        result = generate_dynamic_segments(
            video_duration_sec=10.0,
            boundary_candidates=[
                {"timeSec": 2.0, "confidence": "high"},
                {"timeSec": 5.0, "confidence": "high"},
                {"timeSec": 8.0, "confidence": "high"},
            ],
            config=DynamicSegmentConfig(min_segment_sec=1.6),
        )

        self.assertTrue(result["summary"]["isLegal"])
        self.assertEqual(result["usedBoundaryPointsSec"], [2.0, 5.0, 8.0])
        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["segments"]],
            [(0.0, 2.0), (2.0, 5.0), (5.0, 8.0), (8.0, 10.0)],
        )

    def test_merges_short_fragments_without_moving_earlier_starts(self) -> None:
        result = generate_dynamic_segments(
            video_duration_sec=12.0,
            boundary_candidates=[
                {"timeSec": 3.0, "confidence": "high"},
                {"timeSec": 4.0, "confidence": "high"},
                {"timeSec": 7.0, "confidence": "high"},
                {"timeSec": 11.4, "confidence": "high"},
            ],
            config=DynamicSegmentConfig(min_segment_sec=1.6),
        )

        self.assertEqual(result["usedBoundaryPointsSec"], [3.0, 7.0])
        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["segments"]],
            [(0.0, 3.0), (3.0, 7.0), (7.0, 12.0)],
        )
        self.assertEqual(
            [(item["timeSec"], item["reason"]) for item in result["removedBoundaries"]],
            [(4.0, "short-segment"), (11.4, "short-tail")],
        )

    def test_cleans_invalid_duplicates_and_reports_legal_summary(self) -> None:
        result = generate_dynamic_segments(
            video_duration_sec=6.0,
            boundary_candidates=[
                {"timeSec": -1.0, "confidence": "high"},
                {"timeSec": 0.02, "confidence": "high"},
                {"timeSec": 2.0, "confidence": "high"},
                {"timeSec": 2.01, "confidence": "high"},
                {"timeSec": 5.0, "confidence": "high"},
                {"timeSec": 12.0, "confidence": "high"},
            ],
            config=DynamicSegmentConfig(
                min_segment_sec=0.5,
                abnormal_short_sec=0.8,
                dedupe_epsilon_sec=0.05,
            ),
        )

        self.assertEqual(result["usedBoundaryPointsSec"], [2.0, 5.0])
        self.assertEqual(result["summary"]["segmentCount"], 3)
        self.assertEqual(result["summary"]["shortestSegmentSec"], 1.0)
        self.assertEqual(result["summary"]["longestSegmentSec"], 3.0)
        self.assertEqual(result["summary"]["abnormalShortSegmentCount"], 0)
        self.assertTrue(result["summary"]["isLegal"])
        self.assertEqual(result["removedBoundaryCount"], 4)


if __name__ == "__main__":
    unittest.main()
