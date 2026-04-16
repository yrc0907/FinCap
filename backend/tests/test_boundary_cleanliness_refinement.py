from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

import numpy as np

from services.boundary_cleanliness_refinement import (
    BoundaryCleanlinessConfig,
    refine_boundary_candidates,
)
from services.frame_sampling import FrameSampleBatch


class BoundaryCleanlinessRefinementTests(unittest.TestCase):
    def test_prefers_candidate_closer_to_detector_anchor_when_cleanliness_is_similar(self) -> None:
        scores = {
            321: {
                "boundaryDiff": 0.92,
                "leftStabilityDiff": 0.0,
                "rightStabilityDiff": 0.0,
            },
            322: {
                "boundaryDiff": 0.88,
                "leftStabilityDiff": 0.0,
                "rightStabilityDiff": 0.0,
            },
            323: {
                "boundaryDiff": 0.12,
                "leftStabilityDiff": 0.0,
                "rightStabilityDiff": 0.0,
            },
            324: {
                "boundaryDiff": 0.09,
                "leftStabilityDiff": 0.0,
                "rightStabilityDiff": 0.0,
            },
        }

        result = refine_boundary_candidates(
            video_path=Path("demo.mp4"),
            boundary_candidates=[
                {
                    "timeSec": 10.753,
                    "score": 0.93,
                    "windowStartSec": 10.5,
                    "windowEndSec": 11.0,
                    "sources": ["transnetv2-cuda"],
                    "origin": "scene-detector",
                    "sceneDetectorAnchorSec": 10.753,
                    "sceneDetectorAnchorScore": 0.93,
                }
            ],
            fps=30.0,
            frame_count=2000,
            config=BoundaryCleanlinessConfig(
                search_radius_frames=2,
                min_improvement=0.01,
                detector_anchor_penalty=0.1,
            ),
            frame_metric_provider=lambda frame_index: scores.get(
                frame_index,
                {
                    "boundaryDiff": 0.0,
                    "leftStabilityDiff": 0.0,
                    "rightStabilityDiff": 0.0,
                },
            ),
        )

        self.assertEqual(result[0]["timeSec"], 10.733)

    def test_refines_boundary_with_gpu_sampling_and_torch_scores(self) -> None:
        sample_batch = FrameSampleBatch(
            frames=[np.zeros((8, 8), dtype=np.uint8) for _ in range(8)],
            times_sec=[10.633, 10.667, 10.7, 10.733, 10.767, 10.8, 10.833, 10.867],
            backend="ffmpeg-cuda",
        )

        with (
            patch(
                "services.boundary_cleanliness_refinement.sample_grayscale_frames",
                return_value=sample_batch,
            ),
            patch(
                "services.boundary_cleanliness_refinement.compute_weighted_transition_scores",
                return_value=(
                    np.asarray([0.05, 0.12, 0.96, 0.1, 0.08, 0.05, 0.04], dtype=np.float32),
                    "torch-cuda",
                ),
            ),
        ):
            result = refine_boundary_candidates(
                video_path=Path("demo.mp4"),
                boundary_candidates=[
                    {
                        "timeSec": 10.753,
                        "score": 0.93,
                        "windowStartSec": 10.5,
                        "windowEndSec": 11.0,
                        "sources": ["scene-detector"],
                        "origin": "scene-detector",
                    }
                ],
                fps=30.0,
                frame_count=2000,
                config=BoundaryCleanlinessConfig(
                    search_radius_frames=2,
                    min_improvement=0.02,
                    require_gpu=True,
                ),
            )

        self.assertEqual(result[0]["timeSec"], 10.733)
        self.assertEqual(result[0]["refinedFromSec"], 10.753)
        self.assertIn("cleanliness-refinement", result[0]["sources"])

    def test_raises_when_gpu_refinement_falls_back_to_cpu(self) -> None:
        sample_batch = FrameSampleBatch(
            frames=[np.zeros((8, 8), dtype=np.uint8) for _ in range(8)],
            times_sec=[10.633, 10.667, 10.7, 10.733, 10.767, 10.8, 10.833, 10.867],
            backend="ffmpeg-cpu",
        )

        with (
            patch(
                "services.boundary_cleanliness_refinement.sample_grayscale_frames",
                return_value=sample_batch,
            ),
            patch(
                "services.boundary_cleanliness_refinement.compute_weighted_transition_scores",
                return_value=(
                    np.asarray([0.05, 0.12, 0.96, 0.1, 0.08, 0.05, 0.04], dtype=np.float32),
                    "opencv-cpu",
                ),
            ),
        ):
            with self.assertRaises(RuntimeError):
                refine_boundary_candidates(
                    video_path=Path("demo.mp4"),
                    boundary_candidates=[
                        {
                            "timeSec": 10.753,
                            "score": 0.93,
                            "windowStartSec": 10.5,
                            "windowEndSec": 11.0,
                            "sources": ["scene-detector"],
                            "origin": "scene-detector",
                        }
                    ],
                    fps=30.0,
                    frame_count=2000,
                    config=BoundaryCleanlinessConfig(
                        search_radius_frames=2,
                        min_improvement=0.02,
                        require_gpu=True,
                    ),
                )

    def test_refines_boundary_to_cleaner_nearby_timestamp(self) -> None:
        scores = {
            321: {
                "boundaryDiff": 12.0,
                "leftStabilityDiff": 8.0,
                "rightStabilityDiff": 9.0,
            },
            322: {
                "boundaryDiff": 5800.0,
                "leftStabilityDiff": 15.0,
                "rightStabilityDiff": 2.0,
            },
            323: {
                "boundaryDiff": 0.4,
                "leftStabilityDiff": 5700.0,
                "rightStabilityDiff": 0.3,
            },
            324: {
                "boundaryDiff": 0.2,
                "leftStabilityDiff": 0.4,
                "rightStabilityDiff": 0.2,
            },
        }

        result = refine_boundary_candidates(
            video_path=Path("demo.mp4"),
            boundary_candidates=[
                {
                    "timeSec": 10.753,
                    "score": 0.93,
                    "windowStartSec": 10.5,
                    "windowEndSec": 11.0,
                    "sources": ["scene-detector"],
                    "origin": "scene-detector",
                }
            ],
            fps=30.0,
            frame_count=2000,
            config=BoundaryCleanlinessConfig(search_radius_frames=2, min_improvement=1.0),
            frame_metric_provider=lambda frame_index: scores.get(
                frame_index,
                {
                    "boundaryDiff": 0.0,
                    "leftStabilityDiff": 0.0,
                    "rightStabilityDiff": 0.0,
                },
            ),
        )

        self.assertEqual(result[0]["timeSec"], 10.733)
        self.assertEqual(result[0]["refinedFromSec"], 10.753)
        self.assertIn("cleanliness-refinement", result[0]["sources"])

    def test_keeps_original_boundary_when_current_frame_is_best(self) -> None:
        scores = {
            322: {
                "boundaryDiff": 1200.0,
                "leftStabilityDiff": 3.0,
                "rightStabilityDiff": 2.0,
            },
            323: {
                "boundaryDiff": 10.0,
                "leftStabilityDiff": 1000.0,
                "rightStabilityDiff": 10.0,
            },
            324: {
                "boundaryDiff": 15.0,
                "leftStabilityDiff": 14.0,
                "rightStabilityDiff": 12.0,
            },
        }

        result = refine_boundary_candidates(
            video_path=Path("demo.mp4"),
            boundary_candidates=[
                {
                    "timeSec": 10.733,
                    "score": 0.91,
                    "windowStartSec": 10.5,
                    "windowEndSec": 11.0,
                    "sources": ["scene-detector"],
                    "origin": "scene-detector",
                }
            ],
            fps=30.0,
            frame_count=2000,
            config=BoundaryCleanlinessConfig(search_radius_frames=2, min_improvement=1.0),
            frame_metric_provider=lambda frame_index: scores.get(
                frame_index,
                {
                    "boundaryDiff": 0.0,
                    "leftStabilityDiff": 0.0,
                    "rightStabilityDiff": 0.0,
                },
            ),
        )

        self.assertEqual(result[0]["timeSec"], 10.733)
        self.assertNotIn("refinedFromSec", result[0])
        self.assertEqual(result[0]["sources"], ["scene-detector"])


if __name__ == "__main__":
    unittest.main()
