from __future__ import annotations

import unittest
from unittest.mock import patch

import numpy as np

from services import torch_scoring


class WeightedTransitionBackendSelectionTests(unittest.TestCase):
    def setUp(self) -> None:
        self.frames = [
            np.zeros((4, 4), dtype=np.uint8),
            np.full((4, 4), 255, dtype=np.uint8),
        ]

    def test_auto_mode_prefers_torch_cuda_when_available(self) -> None:
        histogram_scores = np.asarray([0.2], dtype=np.float32)
        frame_diff_scores = np.asarray([0.6], dtype=np.float32)

        with (
            patch.dict("os.environ", {}, clear=False),
            patch.object(torch_scoring, "is_opencv_cuda_available", return_value=True),
            patch.object(
                torch_scoring,
                "_compute_torch_components",
                return_value=(histogram_scores, frame_diff_scores),
            ) as torch_compute,
            patch.object(torch_scoring, "is_torch_cuda_available", return_value=True),
        ):
            scores, backend = torch_scoring.compute_weighted_transition_scores(
                self.frames,
                histogram_weight=0.25,
                frame_diff_weight=0.75,
            )

        self.assertEqual(backend, "torch-cuda")
        torch_compute.assert_called_once_with(self.frames)
        np.testing.assert_allclose(scores, np.asarray([0.5], dtype=np.float32))

    def test_ignores_opencv_cuda_preference_and_keeps_torch_cuda(self) -> None:
        histogram_scores = np.asarray([0.2], dtype=np.float32)
        frame_diff_scores = np.asarray([0.6], dtype=np.float32)

        with (
            patch.dict("os.environ", {"FINCAP_WEIGHTED_SCORE_BACKEND": "opencv-cuda"}, clear=False),
            patch.object(torch_scoring, "is_opencv_cuda_available", return_value=True),
            patch.object(torch_scoring, "is_torch_cuda_available", return_value=True),
            patch.object(
                torch_scoring,
                "_compute_torch_components",
                return_value=(histogram_scores, frame_diff_scores),
            ) as torch_compute,
            patch.object(torch_scoring, "_compute_opencv_cuda_components") as opencv_compute,
        ):
            scores, backend = torch_scoring.compute_weighted_transition_scores(
                self.frames,
                histogram_weight=0.25,
                frame_diff_weight=0.75,
            )

        self.assertEqual(backend, "torch-cuda")
        torch_compute.assert_called_once_with(self.frames)
        opencv_compute.assert_not_called()
        np.testing.assert_allclose(scores, np.asarray([0.5], dtype=np.float32))

    def test_falls_back_to_torch_cuda_when_opencv_cuda_is_unavailable(self) -> None:
        histogram_scores = np.asarray([0.1], dtype=np.float32)
        frame_diff_scores = np.asarray([0.3], dtype=np.float32)

        with (
            patch.object(torch_scoring, "is_opencv_cuda_available", return_value=False),
            patch.object(torch_scoring, "is_torch_cuda_available", return_value=True),
            patch.object(
                torch_scoring,
                "_compute_torch_components",
                return_value=(histogram_scores, frame_diff_scores),
            ) as torch_compute,
        ):
            scores, backend = torch_scoring.compute_weighted_transition_scores(
                self.frames,
                histogram_weight=0.5,
                frame_diff_weight=0.5,
            )

        self.assertEqual(backend, "torch-cuda")
        torch_compute.assert_called_once_with(self.frames)
        np.testing.assert_allclose(scores, np.asarray([0.2], dtype=np.float32))

    def test_scene_transition_scores_fall_back_when_farneback_is_unavailable(self) -> None:
        frames = [
            np.zeros((8, 8), dtype=np.uint8),
            np.full((8, 8), 32, dtype=np.uint8),
            np.full((8, 8), 224, dtype=np.uint8),
        ]

        with (
            patch.object(torch_scoring, "is_torch_cuda_available", return_value=False),
            patch.object(
                torch_scoring.cv2,
                "calcOpticalFlowFarneback",
                side_effect=AttributeError("Farneback missing"),
                create=True,
            ),
        ):
            scores, backend = torch_scoring.compute_scene_transition_scores(
                frames,
                histogram_weight=0.3,
                frame_diff_weight=0.3,
                optical_flow_weight=0.4,
            )

        self.assertEqual(backend, "opencv-cpu+motion-proxy")
        self.assertEqual(scores.shape, (2,))


if __name__ == "__main__":
    unittest.main()
