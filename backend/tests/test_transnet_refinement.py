from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

import numpy as np

from services.frame_sampling import FrameSampleBatch
from services.scene_candidate_detection import SceneCandidateConfig
from services.transnet_refinement import detect_transnetv2_candidate_windows


class _PredictionStub:
    def __init__(self, values: list[float]) -> None:
        self._values = np.asarray(values, dtype=np.float32)

    def cpu(self) -> "_PredictionStub":
        return self

    def detach(self) -> "_PredictionStub":
        return self

    def numpy(self) -> np.ndarray:
        return self._values


class _TransNetModelStub:
    def __init__(self) -> None:
        self.device = type("Device", (), {"type": "cuda"})()

    def get_video_fps(self, video_path: str) -> float:
        return 10.0

    def predict_video(self, video_path: str, quiet: bool = False) -> tuple[None, _PredictionStub, None]:
        return None, _PredictionStub([0.01, 0.02, 0.08, 0.78, 0.91, 0.12, 0.01]), None

    def predictions_to_scenes_with_data(
        self,
        predictions: np.ndarray,
        fps: float,
        threshold: float,
    ) -> list[dict[str, object]]:
        return [
            {
                "shot_id": 1,
                "start_frame": 0,
                "end_frame": 3,
                "start_time": "0.0",
                "end_time": "0.3",
                "probability": 0.78,
            },
            {
                "shot_id": 2,
                "start_frame": 4,
                "end_frame": 6,
                "start_time": "0.4",
                "end_time": "0.6",
                "probability": 0.91,
            },
        ]

    def detect_scenes(self, video_path: str, threshold: float = 0.5) -> list[dict[str, object]]:
        return [
            {
                "shot_id": 1,
                "start_frame": 0,
                "end_frame": 3,
                "start_time": "0.0",
                "end_time": "0.3",
                "probability": 0.78,
            },
            {
                "shot_id": 2,
                "start_frame": 4,
                "end_frame": 6,
                "start_time": "0.4",
                "end_time": "0.6",
                "probability": 0.91,
            },
        ]


class TransNetRefinementTests(unittest.TestCase):
    def test_refinement_moves_peak_and_marks_soft_cut(self) -> None:
        config = SceneCandidateConfig(
            sample_step_sec=0.1,
            window_radius_sec=0.5,
            threshold_floor=0.45,
        )
        model = _TransNetModelStub()

        with (
            patch(
                "services.transnet_refinement.sample_grayscale_frames",
                return_value=FrameSampleBatch(
                    frames=[np.zeros((8, 8), dtype=np.uint8)] * 6,
                    times_sec=[0.0, 0.1, 0.2, 0.3, 0.4, 0.5],
                    backend="ffmpeg-cuda",
                ),
            ),
            patch(
                "services.transnet_refinement.compute_scene_transition_scores",
                return_value=(np.asarray([0.18, 0.84, 0.79, 0.22, 0.09], dtype=np.float32), "torch-cuda"),
            ),
        ):
            candidate_windows, backend, meta = detect_transnetv2_candidate_windows(
                Path("demo.mp4"),
                config,
                model=model,
            )

        self.assertEqual(backend, "transnetv2-cuda")
        self.assertEqual(len(candidate_windows), 1)
        self.assertEqual(candidate_windows[0]["peakSec"], 0.2)
        self.assertEqual(candidate_windows[0]["cutClass"], "soft-cut")
        self.assertGreater(candidate_windows[0]["score"], 0.7)
        self.assertTrue(meta["refinementEnabled"])

    def test_can_disable_refinement_and_keep_basic_transnet_windows(self) -> None:
        config = SceneCandidateConfig(
            sample_step_sec=0.1,
            window_radius_sec=0.5,
            threshold_floor=0.45,
            transnet_refine_enabled=False,
        )
        model = _TransNetModelStub()

        with patch("services.transnet_refinement.sample_grayscale_frames") as sample_frames_mock:
            candidate_windows, backend, meta = detect_transnetv2_candidate_windows(
                Path("demo.mp4"),
                config,
                model=model,
            )

        sample_frames_mock.assert_not_called()
        self.assertEqual(backend, "transnetv2-cuda")
        self.assertEqual(candidate_windows[0]["peakSec"], 0.4)
        self.assertEqual(candidate_windows[0]["cutClass"], "hard-cut")
        self.assertFalse(meta["refinementEnabled"])


if __name__ == "__main__":
    unittest.main()
