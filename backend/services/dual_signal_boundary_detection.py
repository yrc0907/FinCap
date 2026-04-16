from __future__ import annotations

from bisect import bisect_left, bisect_right
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import numpy as np

from .boundary_fusion import (
    BoundaryFusionConfig,
    collect_scene_detector_candidates,
    fuse_boundary_candidates,
    summarize_reused_scene_detector,
)
from .boundary_cleanliness_refinement import refine_boundary_candidates
from .boundary_cleanliness_refinement import BoundaryCleanlinessConfig
from .frame_sampling import sample_grayscale_frames
from .multiscale_detection import build_video_index
from .scene_candidate_detection import SceneCandidateConfig, detect_scene_candidates
from .torch_scoring import (
    compute_scene_transition_scores,
    compute_weighted_transition_scores,
)

LOG_START = "[Start] Boundary detection started"
LOG_SCENE_DETECTOR = "[Process] Scene detector"
LOG_BACKEND = "[Process] Decode backend"
LOG_COMPUTE = "[Process] Compute backend"
LOG_SUBJECT = "[Process] Subject change candidate count"
LOG_SCENE = "[Process] Shot/scene change candidate count"
LOG_FUSION = "[Process] Fused boundary candidate count"
LOG_POINTS = "[Result] Boundary points"
LOG_COMPLETE = "[Done] Boundary detection finished"
LOG_WARNING = "[Warning] Low-confidence boundaries detected"
LOG_ERROR = "[Error] Boundary detection failed"
LOG_FALLBACK = "[Fallback] Keep current boundaries and continue"


@dataclass(frozen=True)
class SubjectBoundaryConfig:
    sample_step_sec: float = 0.12
    core_ratio: float = 0.58
    histogram_weight: float = 0.42
    frame_diff_weight: float = 0.58
    score_threshold: float = 0.46


@dataclass(frozen=True)
class SceneBoundaryConfig:
    sample_step_sec: float = 0.12
    histogram_weight: float = 0.28
    optical_flow_weight: float = 0.42
    frame_diff_weight: float = 0.30
    score_threshold: float = 0.48
    pyscenedetect_score: float = 0.8


def _extract_core_region(frame: np.ndarray, core_ratio: float) -> np.ndarray:
    height, width = frame.shape[:2]
    core_width = max(1, int(width * core_ratio))
    core_height = max(1, int(height * core_ratio))
    start_x = max(0, (width - core_width) // 2)
    start_y = max(0, (height - core_height) // 2)
    return frame[start_y : start_y + core_height, start_x : start_x + core_width]


def _slice_score_series(
    times_sec: list[float],
    scores: np.ndarray,
    start_sec: float,
    end_sec: float,
) -> tuple[list[float], np.ndarray]:
    left_index = bisect_left(times_sec, start_sec)
    right_index = bisect_right(times_sec, end_sec)
    return times_sec[left_index:right_index], scores[left_index:right_index]


def _scan_subject_candidate(
    region: dict[str, Any],
    score_times_sec: list[float],
    scores: np.ndarray,
    config: SubjectBoundaryConfig,
) -> dict[str, Any] | None:
    start_sec = float(region["startSec"])
    end_sec = float(region["endSec"])
    best_score = 0.0
    best_time_sec = float(region["peakSec"])
    region_times_sec, region_scores = _slice_score_series(
        times_sec=score_times_sec,
        scores=scores,
        start_sec=start_sec,
        end_sec=end_sec,
    )

    for sample_time_sec, score in zip(region_times_sec, region_scores):
        if float(score) > best_score:
            best_score = float(score)
            best_time_sec = sample_time_sec

    if best_score < config.score_threshold:
        return None

    return {
        "timeSec": round(best_time_sec, 3),
        "score": round(best_score, 4),
        "signal": "subject",
        "candidateType": "subject",
        "source": "subject-core",
        "windowStartSec": round(start_sec, 3),
        "windowEndSec": round(end_sec, 3),
    }


def _scan_scene_candidate(
    region: dict[str, Any],
    score_times_sec: list[float],
    scores: np.ndarray,
    config: SceneBoundaryConfig,
) -> dict[str, Any] | None:
    start_sec = float(region["startSec"])
    end_sec = float(region["endSec"])
    best_score = 0.0
    best_time_sec = float(region["peakSec"])
    region_times_sec, region_scores = _slice_score_series(
        times_sec=score_times_sec,
        scores=scores,
        start_sec=start_sec,
        end_sec=end_sec,
    )

    for sample_time_sec, score in zip(region_times_sec, region_scores):
        if float(score) > best_score:
            best_score = float(score)
            best_time_sec = sample_time_sec

    if best_score < config.score_threshold:
        return None

    return {
        "timeSec": round(best_time_sec, 3),
        "score": round(best_score, 4),
        "signal": "scene",
        "candidateType": "scene-motion",
        "source": "scene-motion",
        "windowStartSec": round(start_sec, 3),
        "windowEndSec": round(end_sec, 3),
    }


def detect_dual_signal_boundaries(
    video_path: Path,
    suspicious_regions: list[dict[str, Any]],
    subject_config: SubjectBoundaryConfig | None = None,
    scene_config: SceneBoundaryConfig | None = None,
    fusion_config: BoundaryFusionConfig | None = None,
    scene_detector_mode: str = "pyscenedetect",
    scene_detector_candidates: list[dict[str, Any]] | None = None,
    scene_detector_backend: str | None = None,
) -> dict[str, Any]:
    subject = subject_config or SubjectBoundaryConfig()
    scene = scene_config or SceneBoundaryConfig()
    fusion = fusion_config or BoundaryFusionConfig()

    try:
        index = build_video_index(video_path)
        normalized_regions = sorted(
            suspicious_regions,
            key=lambda item: (float(item["startSec"]), float(item["peakSec"])),
        )
        reused_scene_detector_result = None
        if scene_detector_candidates is not None:
            reused_scene_detector_result = summarize_reused_scene_detector(
                mode=scene_detector_mode,
                backend=scene_detector_backend,
                candidate_windows=scene_detector_candidates,
            )

        print(LOG_START)
        print(f"{LOG_SCENE_DETECTOR}: mode={scene_detector_mode}")

        if not normalized_regions and scene_detector_candidates is None:
            print(f"{LOG_SUBJECT}: 0")
            print(f"{LOG_SCENE}: 0")
            print(f"{LOG_FUSION}: 0")
            print(LOG_FALLBACK)
            print(LOG_COMPLETE)
            return {
                "videoIndex": {
                    "fps": round(index.fps, 3),
                    "frameCount": index.frame_count,
                    "durationSec": round(index.duration_sec, 3),
                    "width": index.width,
                    "height": index.height,
                },
                "inputRegionCount": 0,
                "subjectConfig": subject.__dict__,
                "sceneConfig": scene.__dict__,
                "fusionConfig": fusion.__dict__,
                "sceneDetector": {
                    "mode": scene_detector_mode,
                    "backend": "empty",
                    "candidateCount": 0,
                    "hardCutCount": 0,
                    "softCutCount": 0,
                },
                "subjectCandidates": [],
                "sceneCandidates": [],
                "boundaryCandidates": [],
            }
        if not normalized_regions and scene_detector_candidates is not None:
            scene_candidates = collect_scene_detector_candidates([], scene_detector_candidates)
            fused_candidates = fuse_boundary_candidates([], scene_candidates, fusion)

            print(f"{LOG_SUBJECT}: 0")
            print(f"{LOG_SCENE}: {len(scene_candidates)}")
            print(f"{LOG_FUSION}: {len(fused_candidates)}")
            print(
                f"{LOG_POINTS}: "
                + (
                    ", ".join(f"{item['timeSec']:.3f}s" for item in fused_candidates)
                    if fused_candidates
                    else "none"
                )
            )
            print(LOG_COMPLETE)
            return {
                "videoIndex": {
                    "fps": round(index.fps, 3),
                    "frameCount": index.frame_count,
                    "durationSec": round(index.duration_sec, 3),
                    "width": index.width,
                    "height": index.height,
                },
                "inputRegionCount": 0,
                "subjectConfig": subject.__dict__,
                "sceneConfig": scene.__dict__,
                "fusionConfig": fusion.__dict__,
                "sceneDetector": {
                    "mode": reused_scene_detector_result["mode"],
                    "backend": reused_scene_detector_result["backend"],
                    "candidateCount": reused_scene_detector_result["candidateCount"],
                    "hardCutCount": reused_scene_detector_result["hardCutCount"],
                    "softCutCount": reused_scene_detector_result["softCutCount"],
                },
                "subjectCandidates": [],
                "sceneCandidates": scene_candidates,
                "boundaryCandidates": fused_candidates,
            }

        subject_candidates: list[dict[str, Any]] = []
        scene_candidates: list[dict[str, Any]] = []
        decode_backends: set[str] = set()
        compute_backends: set[str] = set()
        scene_detector_result = {
            "mode": scene_detector_mode,
            "backend": "unavailable",
            "candidateCount": 0,
            "hardCutCount": 0,
            "softCutCount": 0,
        }

        subject_batch = sample_grayscale_frames(
            video_path=video_path,
            start_sec=0.0,
            end_sec=index.duration_sec,
            step_sec=subject.sample_step_sec,
            width=320,
            height=180,
        )
        decode_backends.add(subject_batch.backend)
        subject_core_frames = [
            _extract_core_region(frame, subject.core_ratio) for frame in subject_batch.frames
        ]
        subject_scores, subject_compute_backend = compute_weighted_transition_scores(
            subject_core_frames,
            subject.histogram_weight,
            subject.frame_diff_weight,
        )
        compute_backends.add(subject_compute_backend)

        for region in normalized_regions:
            candidate = _scan_subject_candidate(
                region,
                subject_batch.times_sec[1:],
                subject_scores,
                subject,
            )
            if candidate is not None:
                subject_candidates.append(candidate)

        if scene_detector_candidates is None:
            scene_batch = sample_grayscale_frames(
                video_path=video_path,
                start_sec=0.0,
                end_sec=index.duration_sec,
                step_sec=scene.sample_step_sec,
                width=256,
                height=144,
            )
            decode_backends.add(scene_batch.backend)
            scene_scores, scene_compute_backend = compute_scene_transition_scores(
                scene_batch.frames,
                scene.histogram_weight,
                scene.frame_diff_weight,
                scene.optical_flow_weight,
            )
            compute_backends.add(scene_compute_backend)

            for region in normalized_regions:
                candidate = _scan_scene_candidate(
                    region,
                    scene_batch.times_sec[1:],
                    scene_scores,
                    scene,
                )
                if candidate is not None:
                    scene_candidates.append(candidate)

        try:
            if scene_detector_candidates is not None:
                scene_detector_result = reused_scene_detector_result
                scene_windows = scene_detector_candidates
            else:
                scene_detector_result = detect_scene_candidates(
                    video_path=video_path,
                    mode=scene_detector_mode,
                    config=SceneCandidateConfig(
                        sample_step_sec=scene.sample_step_sec,
                        width=256,
                        height=144,
                        window_radius_sec=max(scene.sample_step_sec * 2.0, 0.3),
                        min_scene_len_sec=max(scene.sample_step_sec * 3.0, 0.4),
                        merge_gap_sec=max(fusion.gap_sec, scene.sample_step_sec),
                        threshold_floor=min(max(scene.score_threshold - 0.08, 0.25), 0.8),
                    ),
                )
                scene_windows = scene_detector_result["candidateWindows"]
            scene_candidates.extend(
                collect_scene_detector_candidates(
                    normalized_regions,
                    scene_windows,
                )
            )
        except Exception as exc:
            print(f"[Warning] Scene detector boundary pass failed and was skipped: {exc}")

        fused_candidates = fuse_boundary_candidates(subject_candidates, scene_candidates, fusion)
        try:
            refined_candidates = refine_boundary_candidates(
                video_path=video_path,
                boundary_candidates=fused_candidates,
                fps=index.fps,
                frame_count=index.frame_count,
                config=BoundaryCleanlinessConfig(require_gpu=True),
            )
        except Exception as exc:
            print(f"[Warning] Boundary cleanliness refinement failed and was skipped: {exc}")
            refined_candidates = fused_candidates
        low_confidence_count = sum(
            1 for item in refined_candidates if item["confidence"] == "low"
        )

        print(f"{LOG_COMPUTE}: {', '.join(sorted(compute_backends))}")
        print(f"{LOG_BACKEND}: {', '.join(sorted(decode_backends))}")
        print(
            f"{LOG_SCENE_DETECTOR}: mode={scene_detector_result['mode']}, "
            f"backend={scene_detector_result['backend']}, "
            f"candidates={scene_detector_result['candidateCount']}, "
            f"hardCuts={scene_detector_result['hardCutCount']}, "
            f"softCuts={scene_detector_result['softCutCount']}"
        )
        print(f"{LOG_SUBJECT}: {len(subject_candidates)}")
        print(f"{LOG_SCENE}: {len(scene_candidates)}")
        print(f"{LOG_FUSION}: {len(refined_candidates)}")
        print(
            f"{LOG_POINTS}: "
            + (
                ", ".join(f"{item['timeSec']:.3f}s" for item in refined_candidates)
                if refined_candidates
                else "none"
            )
        )

        if low_confidence_count > 0:
            print(f"{LOG_WARNING}: {low_confidence_count}")

        if not refined_candidates:
            print(LOG_FALLBACK)

        print(LOG_COMPLETE)

        return {
            "videoIndex": {
                "fps": round(index.fps, 3),
                "frameCount": index.frame_count,
                "durationSec": round(index.duration_sec, 3),
                "width": index.width,
                "height": index.height,
            },
            "inputRegionCount": len(normalized_regions),
            "subjectConfig": subject.__dict__,
            "sceneConfig": scene.__dict__,
            "fusionConfig": fusion.__dict__,
            "sceneDetector": {
                "mode": scene_detector_result["mode"],
                "backend": scene_detector_result["backend"],
                "candidateCount": scene_detector_result["candidateCount"],
                "hardCutCount": scene_detector_result["hardCutCount"],
                "softCutCount": scene_detector_result["softCutCount"],
            },
            "subjectCandidates": subject_candidates,
            "sceneCandidates": scene_candidates,
            "boundaryCandidates": refined_candidates,
        }
    except Exception as exc:
        print(f"{LOG_ERROR}: {exc}")
        print(LOG_FALLBACK)
        raise
