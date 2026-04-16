from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.scene_candidate_detection import (
    SceneCandidateConfig,
    detect_scene_candidates,
    merge_candidate_windows,
    normalize_scene_detector_mode,
)


class SceneCandidateDetectionTests(unittest.TestCase):
    def test_pyscenedetect_route_returns_unified_result(self) -> None:
        config = SceneCandidateConfig(window_radius_sec=0.6)

        with patch(
            "services.scene_candidate_detection.run_pyscenedetect_cut_points",
            return_value=[1.2, 3.4],
        ):
            result = detect_scene_candidates(
                Path("demo.mp4"),
                mode="pyscenedetect",
                config=config,
            )

        self.assertEqual(result["mode"], "pyscenedetect")
        self.assertEqual(result["backend"], "pyscenedetect")
        self.assertEqual(result["cutPointsSec"], [1.2, 3.4])
        self.assertEqual(result["hardCutCount"], 2)
        self.assertEqual(result["softCutCount"], 0)
        self.assertEqual(result["candidateWindows"][0]["startSec"], 0.6)
        self.assertEqual(result["candidateWindows"][0]["endSec"], 1.8)

    def test_merge_candidate_windows_combines_nearby_candidates(self) -> None:
        merged = merge_candidate_windows(
            [
                {
                    "startSec": 1.0,
                    "endSec": 1.2,
                    "peakSec": 1.1,
                    "score": 0.71,
                    "cutClass": "hard-cut",
                    "sources": ["scene-detector"],
                },
                {
                    "startSec": 1.32,
                    "endSec": 1.5,
                    "peakSec": 1.4,
                    "score": 0.66,
                    "cutClass": "soft-cut",
                    "sources": ["scene-detector"],
                },
            ],
            merge_gap_sec=0.2,
        )

        self.assertEqual(len(merged), 1)
        self.assertEqual(merged[0]["startSec"], 1.0)
        self.assertEqual(merged[0]["endSec"], 1.5)
        self.assertEqual(merged[0]["peakSec"], 1.1)
        self.assertEqual(merged[0]["cutClass"], "hard-cut")

    def test_transnet_route_returns_unified_result(self) -> None:
        config = SceneCandidateConfig(window_radius_sec=0.5)

        with patch(
            "services.scene_candidate_detection.detect_transnetv2_candidate_windows",
            return_value=(
                [
                    {
                        "startSec": 1.7,
                        "endSec": 2.3,
                        "peakSec": 2.0,
                        "score": 0.9321,
                        "cutClass": "hard-cut",
                        "sources": ["transnetv2-cuda"],
                    },
                    {
                        "startSec": 5.1,
                        "endSec": 5.9,
                        "peakSec": 5.5,
                        "score": 0.7812,
                        "cutClass": "soft-cut",
                        "sources": ["transnetv2-cuda"],
                    },
                ],
                "transnetv2-cuda",
                {"threshold": 0.52, "refinementEnabled": True},
            ),
        ):
            result = detect_scene_candidates(
                Path("demo.mp4"),
                mode="transnetv2-cuda",
                config=config,
            )

        self.assertEqual(result["mode"], "transnetv2-cuda")
        self.assertEqual(result["backend"], "transnetv2-cuda")
        self.assertEqual(result["cutPointsSec"], [2.0, 5.5])
        self.assertEqual(result["candidateCount"], 2)
        self.assertEqual(result["hardCutCount"], 1)
        self.assertEqual(result["softCutCount"], 1)
        self.assertEqual(result["candidateWindows"][0]["startSec"], 1.7)
        self.assertEqual(result["candidateWindows"][1]["peakSec"], 5.5)
        self.assertTrue(result["meta"]["refinementEnabled"])

    def test_removed_scene_routes_are_rejected(self) -> None:
        for mode in ["opencv-cuda", "autoshot-cuda"]:
            with self.subTest(mode=mode):
                with self.assertRaises(ValueError):
                    normalize_scene_detector_mode(mode)


if __name__ == "__main__":
    unittest.main()
