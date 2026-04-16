from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

import numpy as np

from services.dual_signal_boundary_detection import detect_dual_signal_boundaries
from services.frame_sampling import FrameSampleBatch
from services.multiscale_detection import detect_full_timeline_multiscale


class SceneRouteIntegrationTests(unittest.TestCase):
    def test_boundary_detection_keeps_detector_candidates_outside_region_windows(self) -> None:
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
                "score": 0.9,
                "cutClass": "hard-cut",
                "sources": ["transnetv2-cuda"],
            },
            {
                "startSec": 2.4,
                "endSec": 2.7,
                "peakSec": 2.55,
                "score": 0.88,
                "cutClass": "soft-cut",
                "sources": ["transnetv2-cuda"],
            },
        ]

        with (
            patch(
                "services.dual_signal_boundary_detection.build_video_index",
                return_value=type(
                    "VideoIndexStub",
                    (),
                    {
                        "fps": 25.0,
                        "frame_count": 100,
                        "duration_sec": 4.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.dual_signal_boundary_detection.sample_grayscale_frames",
                return_value=FrameSampleBatch(
                    frames=[np.zeros((4, 4), dtype=np.uint8)] * 4,
                    times_sec=[0.0, 0.5, 1.0, 1.5],
                    backend="ffmpeg-cuda",
                ),
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_weighted_transition_scores",
                return_value=(np.asarray([0.1, 0.1, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.detect_scene_candidates",
            ) as detect_scene_candidates_mock,
        ):
            result = detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=suspicious_regions,
                scene_detector_mode="transnetv2-cuda",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="transnetv2-cuda",
            )

        detect_scene_candidates_mock.assert_not_called()
        self.assertEqual(
            [item["timeSec"] for item in result["boundaryCandidates"]],
            [1.0, 2.55],
        )
        self.assertEqual(result["boundaryCandidates"][1]["windowStartSec"], 2.4)
        self.assertEqual(result["boundaryCandidates"][1]["windowEndSec"], 2.7)

    def test_boundary_detection_reuses_scene_detector_candidates_when_provided(self) -> None:
        suspicious_regions = [
            {
                "startSec": 0.5,
                "endSec": 1.3,
                "peakSec": 1.0,
                "score": 0.81,
                "confidence": "high",
                "sources": ["opencv-coarse"],
            }
        ]
        scene_detector_candidates = [
            {
                "startSec": 0.6,
                "endSec": 1.2,
                "peakSec": 1.0,
                "score": 0.74,
                "cutClass": "soft-cut",
                "sources": ["scene-pyscenedetect"],
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
                side_effect=[
                    FrameSampleBatch(
                        frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                        times_sec=[0.0, 0.3, 0.6, 0.9, 1.2],
                        backend="ffmpeg-cuda",
                    ),
                    FrameSampleBatch(
                        frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                        times_sec=[0.0, 0.3, 0.6, 0.9, 1.2],
                        backend="ffmpeg-cuda",
                    ),
                ],
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_weighted_transition_scores",
                return_value=(np.asarray([0.2, 0.8, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_scene_transition_scores",
                return_value=(np.asarray([0.2, 0.75, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.detect_scene_candidates",
            ) as detect_scene_candidates_mock,
        ):
            result = detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=suspicious_regions,
                scene_detector_mode="pyscenedetect",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="pyscenedetect",
            )

        detect_scene_candidates_mock.assert_not_called()
        self.assertEqual(result["sceneDetector"]["backend"], "pyscenedetect")
        self.assertEqual(result["sceneDetector"]["candidateCount"], 1)

    def test_boundary_detection_preserves_detector_candidates_without_regions(self) -> None:
        scene_detector_candidates = [
            {
                "startSec": 3.5,
                "endSec": 4.5,
                "peakSec": 4.0,
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
                        "frame_count": 250,
                        "duration_sec": 10.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.dual_signal_boundary_detection.sample_grayscale_frames",
            ) as sample_frames_mock,
            patch(
                "services.dual_signal_boundary_detection.detect_scene_candidates",
            ) as detect_scene_candidates_mock,
        ):
            result = detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=[],
                scene_detector_mode="transnetv2-cuda",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="transnetv2-cuda",
            )

        sample_frames_mock.assert_not_called()
        detect_scene_candidates_mock.assert_not_called()
        self.assertEqual(result["sceneDetector"]["backend"], "transnetv2-cuda")
        self.assertEqual(
            result["boundaryCandidates"],
            [
                {
                    "timeSec": 4.0,
                    "score": 1.0,
                    "subjectScore": None,
                    "sceneScore": 1.0,
                    "windowStartSec": 3.5,
                    "windowEndSec": 4.5,
                    "confidence": "high",
                    "sources": ["transnetv2-cuda"],
                    "origin": "scene-detector",
                    "sceneDetectorAnchorSec": 4.0,
                    "sceneDetectorAnchorScore": 1.0,
                    "sceneDetectorCutClass": "hard-cut",
                }
            ],
        )

    def test_boundary_detection_marks_detector_primary_origin(self) -> None:
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
                side_effect=[
                    FrameSampleBatch(
                        frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                        times_sec=[0.0, 0.3, 0.6, 0.9, 1.2],
                        backend="ffmpeg-cuda",
                    ),
                    FrameSampleBatch(
                        frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                        times_sec=[0.0, 0.3, 0.6, 0.9, 1.2],
                        backend="ffmpeg-cuda",
                    ),
                ],
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_weighted_transition_scores",
                return_value=(np.asarray([0.2, 0.3, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_scene_transition_scores",
                return_value=(np.asarray([0.2, 0.2, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.detect_scene_candidates",
            ) as detect_scene_candidates_mock,
        ):
            result = detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=suspicious_regions,
                scene_detector_mode="transnetv2-cuda",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="transnetv2-cuda",
            )

        detect_scene_candidates_mock.assert_not_called()
        self.assertEqual(len(result["boundaryCandidates"]), 1)
        self.assertEqual(result["boundaryCandidates"][0]["timeSec"], 1.0)
        self.assertEqual(result["boundaryCandidates"][0]["origin"], "scene-detector")
        self.assertEqual(result["boundaryCandidates"][0]["sources"], ["transnetv2-cuda"])

    def test_boundary_detection_refines_fused_boundary_timestamp(self) -> None:
        suspicious_regions = [
            {
                "startSec": 10.5,
                "endSec": 11.0,
                "peakSec": 10.753,
                "score": 0.84,
                "confidence": "high",
                "sources": ["transnetv2-cuda"],
            }
        ]
        scene_detector_candidates = [
            {
                "startSec": 10.6,
                "endSec": 10.9,
                "peakSec": 10.753,
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
                        "fps": 30.0,
                        "frame_count": 2000,
                        "duration_sec": 61.0,
                        "width": 320,
                        "height": 180,
                    },
                )(),
            ),
            patch(
                "services.dual_signal_boundary_detection.sample_grayscale_frames",
                return_value=FrameSampleBatch(
                    frames=[np.zeros((4, 4), dtype=np.uint8)] * 5,
                    times_sec=[10.4, 10.55, 10.7, 10.85, 11.0],
                    backend="ffmpeg-cuda",
                ),
            ),
            patch(
                "services.dual_signal_boundary_detection.compute_weighted_transition_scores",
                return_value=(np.asarray([0.2, 0.3, 0.2, 0.1], dtype=np.float32), "torch-cuda"),
            ),
            patch(
                "services.dual_signal_boundary_detection.refine_boundary_candidates",
                return_value=[
                    {
                        "timeSec": 10.733,
                        "score": 1.0,
                        "subjectScore": 0.3,
                        "sceneScore": 1.0,
                        "windowStartSec": 10.5,
                        "windowEndSec": 11.0,
                        "confidence": "high",
                        "sources": ["transnetv2-cuda", "cleanliness-refinement"],
                        "origin": "scene-detector",
                        "refinedFromSec": 10.753,
                    }
                ],
            ) as refine_boundaries_mock,
            patch(
                "services.dual_signal_boundary_detection.detect_scene_candidates",
            ) as detect_scene_candidates_mock,
        ):
            result = detect_dual_signal_boundaries(
                Path("demo.mp4"),
                suspicious_regions=suspicious_regions,
                scene_detector_mode="transnetv2-cuda",
                scene_detector_candidates=scene_detector_candidates,
                scene_detector_backend="transnetv2-cuda",
            )

        detect_scene_candidates_mock.assert_not_called()
        refine_boundaries_mock.assert_called_once()
        refined_input = refine_boundaries_mock.call_args.kwargs["boundary_candidates"][0]
        self.assertEqual(refined_input["sceneDetectorAnchorSec"], 10.753)
        self.assertEqual(refined_input["sceneDetectorAnchorScore"], 1.0)
        self.assertEqual(result["boundaryCandidates"][0]["timeSec"], 10.733)
        self.assertEqual(result["boundaryCandidates"][0]["refinedFromSec"], 10.753)


if __name__ == "__main__":
    unittest.main()
