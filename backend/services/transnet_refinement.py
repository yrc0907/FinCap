from __future__ import annotations

from functools import lru_cache
from pathlib import Path
from typing import Any

import numpy as np

from .frame_sampling import sample_grayscale_frames
from .torch_scoring import compute_scene_transition_scores, is_torch_cuda_available


@lru_cache(maxsize=1)
def load_transnetv2_model() -> Any:
    from transnetv2_pytorch import TransNetV2

    return TransNetV2(device=_resolve_transnet_device())


def _resolve_transnet_device() -> str:
    if not is_torch_cuda_available():
        raise RuntimeError("transnetv2-cuda requires torch cuda.")
    return "cuda"


def detect_transnetv2_candidate_windows(
    video_path: Path,
    config: Any,
    model: Any | None = None,
) -> tuple[list[dict[str, Any]], str, dict[str, Any]]:
    active_model = model or load_transnetv2_model()
    backend = f"transnetv2-{active_model.device.type}"

    if not getattr(config, "transnet_refine_enabled", True):
        return _detect_basic_windows(video_path, config, active_model, backend)

    fps = float(active_model.get_video_fps(str(video_path)) or 25.0)
    _, single_frame_predictions, _ = active_model.predict_video(str(video_path), quiet=True)
    predictions = _to_numpy(single_frame_predictions)
    threshold = _adaptive_transnet_threshold(predictions, float(config.threshold_floor))
    scenes = active_model.predictions_to_scenes_with_data(
        predictions,
        fps=fps,
        threshold=threshold,
    )

    candidate_windows = []
    for scene in scenes[1:]:
        raw_cut_sec = _scene_start_sec(scene, fps)
        boundary_probability = _boundary_probability(predictions, int(scene["start_frame"]))
        candidate_windows.append(
            _refine_candidate_window(
                video_path=video_path,
                config=config,
                raw_cut_sec=raw_cut_sec,
                boundary_probability=boundary_probability,
                source=backend,
            )
        )

    return (
        _merge_refined_windows(candidate_windows, float(config.merge_gap_sec)),
        backend,
        {
            "threshold": round(float(threshold), 4),
            "sceneCount": len(scenes),
            "rawCutCount": max(0, len(scenes) - 1),
            "refinementEnabled": True,
            "probabilityP95": _safe_percentile(predictions, 95),
        },
    )


def _detect_basic_windows(
    video_path: Path,
    config: Any,
    model: Any,
    backend: str,
) -> tuple[list[dict[str, Any]], str, dict[str, Any]]:
    scenes = model.detect_scenes(str(video_path), threshold=float(config.threshold_floor))
    candidate_windows = [
        _build_basic_window(
            cut_sec=_scene_start_sec(scene, float(model.get_video_fps(str(video_path)) or 25.0)),
            score=float(scene.get("probability", 1.0)),
            config=config,
            source=backend,
        )
        for scene in scenes[1:]
    ]
    return (
        candidate_windows,
        backend,
        {
            "threshold": round(float(config.threshold_floor), 4),
            "sceneCount": len(scenes),
            "rawCutCount": max(0, len(scenes) - 1),
            "refinementEnabled": False,
        },
    )


def _refine_candidate_window(
    video_path: Path,
    config: Any,
    raw_cut_sec: float,
    boundary_probability: float,
    source: str,
) -> dict[str, Any]:
    radius_sec = max(float(config.window_radius_sec), float(config.transnet_refine_radius_sec))
    step_sec = max(0.02, float(config.transnet_refine_step_sec))
    start_sec = max(0.0, raw_cut_sec - radius_sec)
    end_sec = raw_cut_sec + radius_sec
    sample_batch = sample_grayscale_frames(
        video_path=video_path,
        start_sec=start_sec,
        end_sec=end_sec,
        step_sec=step_sec,
        width=int(config.width),
        height=int(config.height),
    )
    if len(sample_batch.frames) < 2:
        return _build_basic_window(raw_cut_sec, boundary_probability, config, source)

    scores, _ = compute_scene_transition_scores(
        sample_batch.frames,
        float(config.histogram_weight),
        float(config.frame_diff_weight),
        float(config.edge_diff_weight + config.motion_proxy_weight),
    )
    score_times = sample_batch.times_sec[1:]
    if scores.size == 0 or not score_times:
        return _build_basic_window(raw_cut_sec, boundary_probability, config, source)

    thresholds = _local_adaptive_thresholds(scores, config)
    peak_index = _select_peak_index(score_times, scores, thresholds, raw_cut_sec, config)
    group = _expand_peak_group(scores, thresholds, peak_index)
    peak_sec = float(score_times[peak_index])
    local_score = float(scores[peak_index])
    score = float(np.clip(boundary_probability * 0.55 + local_score * 0.45, 0.0, 1.0))
    group_span_sec = float(score_times[group[-1]]) - float(score_times[group[0]])
    cut_class = _classify_cut(score, group_span_sec, step_sec, config)

    return {
        "startSec": round(max(0.0, float(score_times[group[0]]) - step_sec), 3),
        "endSec": round(float(score_times[group[-1]]) + step_sec, 3),
        "peakSec": round(peak_sec, 3),
        "score": round(score, 4),
        "cutClass": cut_class,
        "sources": [source],
    }


def _adaptive_transnet_threshold(predictions: np.ndarray, floor: float) -> float:
    if predictions.size == 0:
        return floor

    active = predictions[predictions > 0.05]
    if active.size < 3:
        return floor

    adaptive = float(np.percentile(active, 70))
    return float(np.clip(max(floor, adaptive), 0.25, 0.85))


def _local_adaptive_thresholds(scores: np.ndarray, config: Any) -> np.ndarray:
    radius = max(1, int(config.adaptive_window_size))
    thresholds = np.empty_like(scores, dtype=np.float32)

    for index in range(scores.size):
        left = max(0, index - radius)
        right = min(scores.size, index + radius + 1)
        local_scores = scores[left:right]
        thresholds[index] = max(
            float(config.threshold_floor) * 0.8,
            float(np.mean(local_scores)) + float(np.std(local_scores)) * float(config.threshold_std_factor),
        )

    return thresholds


def _select_peak_index(
    times_sec: list[float],
    scores: np.ndarray,
    thresholds: np.ndarray,
    raw_cut_sec: float,
    config: Any,
) -> int:
    candidate_indices = [
        index for index, score in enumerate(scores) if float(score) >= float(thresholds[index])
    ]
    if not candidate_indices:
        candidate_indices = list(range(scores.size))

    distance_penalty = float(config.transnet_refine_distance_penalty)
    return max(
        candidate_indices,
        key=lambda index: float(scores[index]) - abs(float(times_sec[index]) - raw_cut_sec) * distance_penalty,
    )


def _expand_peak_group(scores: np.ndarray, thresholds: np.ndarray, peak_index: int) -> list[int]:
    peak_score = float(scores[peak_index])
    group_floor = max(float(thresholds[peak_index]), peak_score * 0.65)
    left = peak_index
    right = peak_index

    while left > 0 and float(scores[left - 1]) >= group_floor:
        left -= 1

    while right + 1 < scores.size and float(scores[right + 1]) >= group_floor:
        right += 1

    return list(range(left, right + 1))


def _classify_cut(score: float, group_span_sec: float, step_sec: float, config: Any) -> str:
    hard_span_sec = max(0.08, step_sec * float(config.transnet_hard_span_steps))
    if score >= float(config.transnet_hard_score) and group_span_sec <= hard_span_sec:
        return "hard-cut"
    return "soft-cut"


def _merge_refined_windows(
    candidate_windows: list[dict[str, Any]],
    merge_gap_sec: float,
) -> list[dict[str, Any]]:
    if not candidate_windows:
        return []

    sorted_windows = sorted(candidate_windows, key=lambda item: item["startSec"])
    merged = [dict(sorted_windows[0])]
    for window in sorted_windows[1:]:
        current = merged[-1]
        if float(window["startSec"]) - float(current["endSec"]) > merge_gap_sec:
            merged.append(dict(window))
            continue

        current["endSec"] = round(max(float(current["endSec"]), float(window["endSec"])), 3)
        if float(window["score"]) > float(current["score"]):
            current["score"] = window["score"]
            current["peakSec"] = window["peakSec"]
            current["cutClass"] = window["cutClass"]
        current["sources"] = sorted(set(current["sources"] + window["sources"]))

    return merged


def _build_basic_window(
    cut_sec: float,
    score: float,
    config: Any,
    source: str,
) -> dict[str, Any]:
    return {
        "startSec": round(max(0.0, cut_sec - float(config.window_radius_sec)), 3),
        "endSec": round(cut_sec + float(config.window_radius_sec), 3),
        "peakSec": round(cut_sec, 3),
        "score": round(float(np.clip(score, 0.0, 1.0)), 4),
        "cutClass": "hard-cut",
        "sources": [source],
    }


def _to_numpy(predictions: Any) -> np.ndarray:
    if hasattr(predictions, "cpu"):
        predictions = predictions.cpu()
    if hasattr(predictions, "detach"):
        predictions = predictions.detach()
    if hasattr(predictions, "numpy"):
        predictions = predictions.numpy()
    return np.asarray(predictions, dtype=np.float32).reshape(-1)


def _scene_start_sec(scene: dict[str, Any], fps: float) -> float:
    if "start_time" in scene:
        return float(scene["start_time"])
    return float(scene["start_frame"]) / max(fps, 1e-6)


def _boundary_probability(predictions: np.ndarray, frame_index: int) -> float:
    if predictions.size == 0:
        return 1.0
    left = max(0, frame_index - 2)
    right = min(predictions.size, frame_index + 3)
    return float(np.max(predictions[left:right]))


def _safe_percentile(values: np.ndarray, percentile: float) -> float:
    if values.size == 0:
        return 0.0
    return round(float(np.percentile(values, percentile)), 4)
