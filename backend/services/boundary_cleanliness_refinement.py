from __future__ import annotations

import math
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Callable

import cv2
import numpy as np

from .frame_sampling import sample_grayscale_frames
from .torch_scoring import compute_weighted_transition_scores


FrameMetricProvider = Callable[[int], dict[str, float]]


@dataclass(frozen=True)
class BoundaryCleanlinessConfig:
    search_radius_frames: int = 2
    resize_width: int = 320
    resize_height: int = 180
    stability_penalty: float = 0.5
    min_improvement: float = 0.02
    score_epsilon: float = 1e-6
    require_gpu: bool = False
    detector_anchor_penalty: float = 0.1


def refine_boundary_candidates(
    video_path: Path,
    boundary_candidates: list[dict[str, Any]],
    fps: float,
    frame_count: int,
    config: BoundaryCleanlinessConfig | None = None,
    frame_metric_provider: FrameMetricProvider | None = None,
) -> list[dict[str, Any]]:
    active_config = config or BoundaryCleanlinessConfig()
    if fps <= 0.0 or frame_count <= 3 or not boundary_candidates:
        return [dict(candidate) for candidate in boundary_candidates]

    if frame_metric_provider is not None:
        return _refine_with_metric_provider(
            boundary_candidates=boundary_candidates,
            fps=fps,
            frame_count=frame_count,
            config=active_config,
            frame_metric_provider=frame_metric_provider,
        )

    return [
        _refine_boundary_candidate_with_local_gpu_window(
            video_path=video_path,
            candidate=candidate,
            fps=fps,
            frame_count=frame_count,
            config=active_config,
        )
        for candidate in boundary_candidates
    ]


def _refine_with_metric_provider(
    boundary_candidates: list[dict[str, Any]],
    fps: float,
    frame_count: int,
    config: BoundaryCleanlinessConfig,
    frame_metric_provider: FrameMetricProvider,
) -> list[dict[str, Any]]:
    refined_candidates: list[dict[str, Any]] = []

    for candidate in boundary_candidates:
        original_time_sec = float(candidate.get("timeSec", 0.0))
        detector_anchor_frame = _resolve_detector_anchor_frame(candidate, fps, frame_count)
        original_frame = _second_to_boundary_frame(
            second=original_time_sec,
            fps=fps,
            frame_count=frame_count,
        )
        min_frame = max(2, original_frame - config.search_radius_frames)
        max_frame = min(frame_count - 2, original_frame + config.search_radius_frames)
        if min_frame > max_frame:
            refined_candidates.append(dict(candidate))
            continue

        original_metric = frame_metric_provider(original_frame)
        original_score = _compute_total_score(
            metric=original_metric,
            candidate_frame=original_frame,
            detector_anchor_frame=detector_anchor_frame,
            config=config,
        )
        best_frame = original_frame
        best_score = original_score

        for candidate_frame in range(min_frame, max_frame + 1):
            metric = frame_metric_provider(candidate_frame)
            score = _compute_total_score(
                metric=metric,
                candidate_frame=candidate_frame,
                detector_anchor_frame=detector_anchor_frame,
                config=config,
            )
            if score > best_score + config.score_epsilon:
                best_frame = candidate_frame
                best_score = score

        refined_candidates.append(
            _build_refined_candidate(
                candidate=candidate,
                fps=fps,
                original_time_sec=original_time_sec,
                original_frame=original_frame,
                best_frame=best_frame,
                original_score=original_score,
                best_score=best_score,
                config=config,
            )
        )

    return refined_candidates


def _refine_boundary_candidate_with_local_gpu_window(
    video_path: Path,
    candidate: dict[str, Any],
    fps: float,
    frame_count: int,
    config: BoundaryCleanlinessConfig,
) -> dict[str, Any]:
    original_time_sec = float(candidate.get("timeSec", 0.0))
    detector_anchor_frame = _resolve_detector_anchor_frame(candidate, fps, frame_count)
    original_frame = _second_to_boundary_frame(
        second=original_time_sec,
        fps=fps,
        frame_count=frame_count,
    )
    min_frame = max(2, original_frame - config.search_radius_frames)
    max_frame = min(frame_count - 2, original_frame + config.search_radius_frames)
    if min_frame > max_frame:
        return dict(candidate)

    sample_start_frame = max(0, min_frame - 2)
    sample_end_frame = min(frame_count - 1, max_frame + 1)
    sample_batch = sample_grayscale_frames(
        video_path=video_path,
        start_sec=sample_start_frame / fps,
        end_sec=(sample_end_frame + 1) / fps,
        step_sec=1.0 / fps,
        width=config.resize_width,
        height=config.resize_height,
    )
    if config.require_gpu and sample_batch.backend != "ffmpeg-cuda":
        raise RuntimeError(
            f"Boundary cleanliness refinement requires ffmpeg-cuda, got {sample_batch.backend}."
        )
    if len(sample_batch.frames) < 4:
        return dict(candidate)

    transition_scores, score_backend = compute_weighted_transition_scores(
        sample_batch.frames,
        histogram_weight=0.45,
        frame_diff_weight=0.55,
    )
    if config.require_gpu and score_backend != "torch-cuda":
        raise RuntimeError(
            f"Boundary cleanliness refinement requires torch-cuda, got {score_backend}."
        )
    if transition_scores.size < 3:
        return dict(candidate)

    original_metric = _metric_from_local_scores(
        transition_scores=transition_scores,
        sample_start_frame=sample_start_frame,
        boundary_frame=original_frame,
    )
    if original_metric is None:
        return dict(candidate)

    original_score = _compute_total_score(
        metric=original_metric,
        candidate_frame=original_frame,
        detector_anchor_frame=detector_anchor_frame,
        config=config,
    )
    best_frame = original_frame
    best_score = original_score

    for candidate_frame in range(min_frame, max_frame + 1):
        metric = _metric_from_local_scores(
            transition_scores=transition_scores,
            sample_start_frame=sample_start_frame,
            boundary_frame=candidate_frame,
        )
        if metric is None:
            continue
        score = _compute_total_score(
            metric=metric,
            candidate_frame=candidate_frame,
            detector_anchor_frame=detector_anchor_frame,
            config=config,
        )
        if score > best_score + config.score_epsilon:
            best_frame = candidate_frame
            best_score = score

    return _build_refined_candidate(
        candidate=candidate,
        fps=fps,
        original_time_sec=original_time_sec,
        original_frame=original_frame,
        best_frame=best_frame,
        original_score=original_score,
        best_score=best_score,
        config=config,
    )


def _metric_from_local_scores(
    transition_scores: np.ndarray,
    sample_start_frame: int,
    boundary_frame: int,
) -> dict[str, float] | None:
    local_boundary_index = boundary_frame - sample_start_frame
    if local_boundary_index < 2 or local_boundary_index >= transition_scores.size:
        return None

    return {
        "boundaryDiff": float(transition_scores[local_boundary_index - 1]),
        "leftStabilityDiff": float(transition_scores[local_boundary_index - 2]),
        "rightStabilityDiff": float(transition_scores[local_boundary_index]),
    }


def _build_refined_candidate(
    candidate: dict[str, Any],
    fps: float,
    original_time_sec: float,
    original_frame: int,
    best_frame: int,
    original_score: float,
    best_score: float,
    config: BoundaryCleanlinessConfig,
) -> dict[str, Any]:
    if best_frame == original_frame or best_score - original_score < config.min_improvement:
        return dict(candidate)

    updated_candidate = dict(candidate)
    updated_candidate["refinedFromSec"] = round(original_time_sec, 3)
    updated_candidate["timeSec"] = round(best_frame / fps, 3)
    updated_candidate["sources"] = _append_source(
        candidate.get("sources", []),
        "cleanliness-refinement",
    )
    return updated_candidate


def _compute_cleanliness_score(
    metric: dict[str, float],
    config: BoundaryCleanlinessConfig,
) -> float:
    boundary_diff = float(metric.get("boundaryDiff", 0.0))
    left_stability_diff = float(metric.get("leftStabilityDiff", 0.0))
    right_stability_diff = float(metric.get("rightStabilityDiff", 0.0))
    stability_cost = max(left_stability_diff, right_stability_diff)
    return boundary_diff - config.stability_penalty * stability_cost


def _compute_total_score(
    metric: dict[str, float],
    candidate_frame: int,
    detector_anchor_frame: int | None,
    config: BoundaryCleanlinessConfig,
) -> float:
    score = _compute_cleanliness_score(metric, config)
    if detector_anchor_frame is None:
        return score

    distance_frames = abs(candidate_frame - detector_anchor_frame)
    radius = max(1, config.search_radius_frames)
    return score - config.detector_anchor_penalty * (distance_frames / radius)


def _second_to_boundary_frame(
    second: float,
    fps: float,
    frame_count: int,
) -> int:
    frame_index = int(math.ceil(max(0.0, second) * fps - 1e-9))
    return min(max(1, frame_index), frame_count - 1)


def _append_source(existing_sources: Any, new_source: str) -> list[str]:
    sources = [str(item) for item in existing_sources] if isinstance(existing_sources, list) else []
    if new_source not in sources:
        sources.append(new_source)
    return sources


def _resolve_detector_anchor_frame(
    candidate: dict[str, Any],
    fps: float,
    frame_count: int,
) -> int | None:
    anchor_sec = candidate.get("sceneDetectorAnchorSec")
    if anchor_sec is None:
        return None
    return _second_to_boundary_frame(
        second=float(anchor_sec),
        fps=fps,
        frame_count=frame_count,
    )


class _OpenCvFrameMetricProvider:
    def __init__(
        self,
        video_path: Path,
        resize_width: int,
        resize_height: int,
    ) -> None:
        self._capture = cv2.VideoCapture(str(video_path))
        if not self._capture.isOpened():
            raise RuntimeError(f"Unable to open video file for boundary refinement: {video_path}")
        self._resize_width = resize_width
        self._resize_height = resize_height
        self._frame_cache: dict[int, np.ndarray] = {}

    def __call__(self, boundary_frame: int) -> dict[str, float]:
        previous_inner = self._read_gray(boundary_frame - 2)
        previous_edge = self._read_gray(boundary_frame - 1)
        next_edge = self._read_gray(boundary_frame)
        next_inner = self._read_gray(boundary_frame + 1)
        return {
            "boundaryDiff": _mean_squared_error(previous_edge, next_edge),
            "leftStabilityDiff": _mean_squared_error(previous_inner, previous_edge),
            "rightStabilityDiff": _mean_squared_error(next_edge, next_inner),
        }

    def _read_gray(self, frame_index: int) -> np.ndarray:
        if frame_index in self._frame_cache:
            return self._frame_cache[frame_index]

        self._capture.set(cv2.CAP_PROP_POS_FRAMES, frame_index)
        success, frame = self._capture.read()
        if not success or frame is None:
            raise RuntimeError(f"Unable to read frame {frame_index} during boundary refinement.")
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        resized = cv2.resize(
            gray,
            (self._resize_width, self._resize_height),
            interpolation=cv2.INTER_AREA,
        )
        self._frame_cache[frame_index] = resized
        return resized


def _mean_squared_error(left: np.ndarray, right: np.ndarray) -> float:
    difference = left.astype(np.float32) - right.astype(np.float32)
    return float(np.mean(difference * difference))
