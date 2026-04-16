from __future__ import annotations

import unittest

from services.strict_shot_generation import StrictShotConfig, generate_strict_shots


class StrictShotGenerationTests(unittest.TestCase):
    def test_keeps_boundary_splits_while_removing_duplicates(self) -> None:
        result = generate_strict_shots(
            video_duration_sec=13.167,
            boundary_candidates=[
                {"timeSec": 4.033, "score": 0.91},
                {"timeSec": 6.2, "score": 0.83},
                {"timeSec": 6.201, "score": 0.82},
                {"timeSec": 8.1, "score": 0.87},
                {"timeSec": 10.733, "score": 0.9},
            ],
            config=StrictShotConfig(dedupe_epsilon_sec=0.01, min_shot_sec=0.15),
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["shots"]],
            [(0.0, 4.033), (4.033, 6.2), (6.2, 8.1), (8.1, 10.733), (10.733, 13.167)],
        )
        self.assertEqual(result["usedBoundaryPointsSec"], [4.033, 6.2, 8.1, 10.733])
        self.assertEqual(result["removedBoundaries"], [{"timeSec": 6.201, "reason": "duplicate"}])
        self.assertTrue(result["summary"]["isLegal"])

    def test_removes_micro_shot_without_pre_merging_story(self) -> None:
        result = generate_strict_shots(
            video_duration_sec=12.0,
            boundary_candidates=[
                {"timeSec": 3.0, "score": 0.9},
                {"timeSec": 3.08, "score": 0.71},
                {"timeSec": 7.0, "score": 0.88},
            ],
            config=StrictShotConfig(dedupe_epsilon_sec=0.01, min_shot_sec=0.15),
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["shots"]],
            [(0.0, 3.0), (3.0, 7.0), (7.0, 12.0)],
        )
        self.assertEqual(
            result["removedBoundaries"],
            [{"timeSec": 3.08, "reason": "micro-shot"}],
        )


if __name__ == "__main__":
    unittest.main()
