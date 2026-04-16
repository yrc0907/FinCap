from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.lighthouse_segments import LighthouseSegmentConfig, extract_lighthouse_segments


class LighthouseSegmentsTests(unittest.TestCase):
    @patch("services.lighthouse_segments.run_lighthouse_inference")
    @patch("services.lighthouse_segments.inspect_lighthouse_runtime")
    def test_keeps_query_results_separate_and_merges_overlapping_peak_clips(
        self,
        inspect_runtime_mock,
        run_inference_mock,
    ) -> None:
        inspect_runtime_mock.return_value = {
            "available": True,
            "python": "C:\\FinCap\\.venv-lighthouse\\Scripts\\python.exe",
            "runner": "C:\\FinCap\\backend\\lighthouse_inference_runner.py",
            "repo": "C:\\FinCap\\_tmp_lighthouse",
        }
        run_inference_mock.return_value = {
            "status": "ok",
            "device": "cpu",
            "featureName": "clip",
            "modelName": "cg_detr",
            "queryResults": [
                {
                    "queryName": "peak",
                    "queryText": "highest impact moment",
                    "predRelevantWindows": [[2.1, 5.7, 0.91]],
                    "predSaliencyScores": [0.1, 0.4, 0.9],
                },
                {
                    "queryName": "conflict",
                    "queryText": "conflict escalation",
                    "predRelevantWindows": [[2.2, 5.8, 0.86], [6.1, 7.8, 0.44]],
                    "predSaliencyScores": [0.2, 0.5, 0.7],
                },
            ],
        }

        result = extract_lighthouse_segments(
            video_path=Path("demo.mp4"),
            shots=[
                {"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0},
                {"index": 2, "startSec": 2.0, "endSec": 4.0, "durationSec": 2.0},
                {"index": 3, "startSec": 4.0, "endSec": 6.0, "durationSec": 2.0},
                {"index": 4, "startSec": 6.0, "endSec": 8.0, "durationSec": 2.0},
            ],
            config=LighthouseSegmentConfig(
                min_window_score=0.5,
                max_peak_clips=3,
            ),
        )

        self.assertEqual(result["status"], "ok")
        self.assertEqual(
            [(item["queryName"], len(item["windows"])) for item in result["queryResults"]],
            [("peak", 1), ("conflict", 1)],
        )
        self.assertEqual(
            [
                (item["queryName"], item["windows"][0]["snappedStartSec"], item["windows"][0]["snappedEndSec"])
                for item in result["queryResults"]
            ],
            [("peak", 2.0, 6.0), ("conflict", 2.0, 6.0)],
        )
        self.assertEqual(
            [
                (
                    item["label"],
                    item["startSec"],
                    item["endSec"],
                    item["score"],
                    item["sourceQueries"],
                )
                for item in result["peakClips"]
            ],
            [("lighthouse_peak", 2.0, 6.0, 0.91, ["conflict", "peak"])],
        )

    @patch("services.lighthouse_segments.run_lighthouse_inference")
    @patch("services.lighthouse_segments.inspect_lighthouse_runtime")
    def test_returns_unavailable_when_runtime_is_missing(
        self,
        inspect_runtime_mock,
        run_inference_mock,
    ) -> None:
        inspect_runtime_mock.return_value = {
            "available": False,
            "python": None,
            "runner": None,
            "repo": "C:\\FinCap\\_tmp_lighthouse",
            "issues": ["Missing Python runtime."],
        }

        result = extract_lighthouse_segments(
            video_path=Path("demo.mp4"),
            shots=[{"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0}],
        )

        self.assertEqual(result["status"], "unavailable")
        self.assertEqual(result["queryResults"], [])
        self.assertEqual(result["peakClips"], [])
        self.assertEqual(result["summary"]["peakClipCount"], 0)
        run_inference_mock.assert_not_called()


if __name__ == "__main__":
    unittest.main()
