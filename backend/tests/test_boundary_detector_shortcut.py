from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

import numpy as np

from services.dual_signal_boundary_detection import detect_dual_signal_boundaries
from services.frame_sampling import FrameSampleBatch


class BoundaryDetectorShortcutTests(unittest.TestCase):
    def test_boundary_detection_skips_scene_motion_pass_when_detector_candidates_are_reused(self) -> None:
        suspicious_regions = [
            {
                "startSec": 0.5,
                "endSec": 1.3,
                "peakSec": 1.0,
                "score": 0.81,
                "confidence": "high",
                "sources": ["transnetv2-cuda"],
            }
        ]
        scene_detector_candidates = [
            {
                "startSec": 0.6,
                "endSec": 1.2,
                "peakSec": 1.0,
                "score": 1.0,
                "cutClass": "hard-cut",
                "sources": ["transnetv2-cuda"],
            }
        ]

        with (
            patch(
                "services.dual_signal_boundary_detection.build_video_index",
                return_value=type(
                    "VideoIndexStub",
                    (),
                    {
                        "fps": 25.0,
                        "frame_count": 20,
                        "duration_sec": 2.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.dual_signal_boundary_detection.sample_grayscale_frames",
                return_value=FrameSampleBatch(
                    frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                    times_sec=[0.0, 0.3, 0.6, 0.9, 1.2],
                    backend="ffmpeg-cuda",
                ),
            ) as sample_frames_mock,
            patch(
                "services.dual_signal_boundary_detection.compute_weighted_transition_scores",
                return_value=(np.asarray([0.2, 0.8, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_scene_transition_scores",
            ) as compute_scene_scores_mock,
        ):
            detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=suspicious_regions,
                scene_detector_mode="transnetv2-cuda",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="transnetv2-cuda",
            )

        sample_frames_mock.assert_called_once()
        compute_scene_scores_mock.assert_not_called()


if __name__ == "__main__":
    unittest.main()
