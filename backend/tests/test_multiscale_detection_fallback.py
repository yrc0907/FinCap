from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

import numpy as np

from services.multiscale_detection import CoarseDetectionConfig, detect_full_timeline_multiscale
from services.scene_candidate_detection import SceneCandidateConfig


class MultiscaleDetectionFallbackTests(unittest.TestCase):
    def test_transnet_route_uses_detector_merge_gap_not_coarse_merge_gap(self) -> None:
        coarse_batch = type(
            "FrameBatchStub",
            (),
            {
                "backend": "ffmpeg-cuda",
                "times_sec": [0.0, 1.0, 2.0],
                "frames": [np.zeros((8, 8), dtype=np.uint8) for _ in range(3)],
            },
        )()
        fine_batch = type(
            "FrameBatchStub",
            (),
            {
                "backend": "ffmpeg-cuda",
                "times_sec": [0.0, 1.0, 2.0],
                "frames": [np.zeros((8, 8), dtype=np.uint8) for _ in range(3)],
            },
        )()
        captured_config: dict[str, float] = {}

        def capture_scene_candidates(*args, **kwargs):
            config = kwargs["config"]
            captured_config["merge_gap_sec"] = float(config.merge_gap_sec)
            return {
                "mode": "transnetv2-cuda",
                "backend": "transnetv2-cuda",
                "candidateCount": 0,
                "hardCutCount": 0,
                "softCutCount": 0,
                "candidateWindows": [],
            }

        with (
            patch(
                "services.multiscale_detection.build_video_index",
                return_value=type(
                    "VideoIndexStub",
                    (),
                    {
                        "fps": 25.0,
                        "frame_count": 50,
                        "duration_sec": 2.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.multiscale_detection.sample_grayscale_frames",
                side_effect=[coarse_batch, fine_batch],
            ),
            patch(
                "services.multiscale_detection.compute_weighted_transition_scores",
                side_effect=[
                    (np.asarray([0.1, 0.1], dtype=np.float32), "torch-cuda"),
                    (np.asarray([0.1, 0.1], dtype=np.float32), "torch-cuda"),
                ],
            ),
            patch(
                "services.multiscale_detection.detect_scene_candidates",
                side_effect=capture_scene_candidates,
            ),
        ):
            detect_full_timeline_multiscale(
                Path("demo.mp4"),
                coarse_config=CoarseDetectionConfig(merge_gap_sec=1.2),
                scene_detector_mode="transnetv2-cuda",
            )

        self.assertEqual(
            captured_config["merge_gap_sec"],
            SceneCandidateConfig().merge_gap_sec,
        )

    def test_transnetv2_failure_keeps_empty_candidate_list(self) -> None:
        coarse_batch = type(
            "FrameBatchStub",
            (),
            {
                "backend": "ffmpeg-cuda",
                "times_sec": [0.0, 1.0, 2.0],
                "frames": [np.zeros((8, 8), dtype=np.uint8) for _ in range(3)],
            },
        )()
        fine_batch = type(
            "FrameBatchStub",
            (),
            {
                "backend": "ffmpeg-cuda",
                "times_sec": [0.0, 1.0, 2.0],
                "frames": [np.zeros((8, 8), dtype=np.uint8) for _ in range(3)],
            },
        )()

        with (
            patch(
                "services.multiscale_detection.build_video_index",
                return_value=type(
                    "VideoIndexStub",
                    (),
                    {
                        "fps": 25.0,
                        "frame_count": 50,
                        "duration_sec": 2.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.multiscale_detection.sample_grayscale_frames",
                side_effect=[coarse_batch, fine_batch],
            ),
            patch(
                "services.multiscale_detection.compute_weighted_transition_scores",
                side_effect=[
                    (np.asarray([0.7, 0.1], dtype=np.float32), "torch-cuda"),
                    (np.asarray([0.8, 0.2], dtype=np.float32), "torch-cuda"),
                ],
            ),
            patch(
                "services.multiscale_detection.detect_scene_candidates",
                side_effect=RuntimeError("model unavailable"),
            ),
        ):
            result = detect_full_timeline_multiscale(
                Path("demo.mp4"),
                scene_detector_mode="transnetv2-cuda",
            )

        self.assertEqual(result["sceneDetector"]["backend"], "unavailable")
        self.assertEqual(result["sceneDetectorCandidates"], [])
        self.assertEqual(len(result["suspiciousRegions"]), 1)
        self.assertEqual(result["suspiciousRegions"][0]["peakSec"], 1.0)


if __name__ == "__main__":
    unittest.main()
