from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2
import numpy as np
from scenedetect import ContentDetector, SceneManager, open_video

from .transnet_refinement import detect_transnetv2_candidate_windows
from .torch_scoring import is_opencv_cuda_available

SceneDetectorMode = str


@dataclass(frozen=True)
class SceneCandidateConfig:
    sample_step_sec: float = 0.12
    width: int = 256
    height: int = 144
    window_radius_sec: float = 0.5
    min_scene_len_sec: float = 0.45
    merge_gap_sec: float = 0.2
    adaptive_window_size: int = 5
    threshold_floor: float = 0.45
    threshold_std_factor: float = 0.75
    histogram_weight: float = 0.28
    frame_diff_weight: float = 0.32
    edge_diff_weight: float = 0.22
    motion_proxy_weight: float = 0.18
    pyscenedetect_threshold: float = 24.0
    pyscenedetect_min_scene_len: int = 12
    transnet_refine_enabled: bool = True
    transnet_refine_step_sec: float = 0.04
    transnet_refine_radius_sec: float = 0.55
    transnet_refine_distance_penalty: float = 0.12
    transnet_hard_score: float = 0.85
    transnet_hard_span_steps: float = 2.0


def normalize_scene_detector_mode(mode: str | None) -> SceneDetectorMode:
    normalized = (mode or "pyscenedetect").strip().lower()
    if normalized not in {"pyscenedetect", "transnetv2-cuda"}:
        raise ValueError(f"Unsupported scene detector mode: {mode}")
    return normalized


def run_pyscenedetect_cut_points(
    video_path: Path,
    config: SceneCandidateConfig,
) -> list[float]:
    video = open_video(str(video_path))
    scene_manager = SceneManager()
    scene_manager.add_detector(
        ContentDetector(
            threshold=config.pyscenedetect_threshold,
            min_scene_len=config.pyscenedetect_min_scene_len,
        )
    )
    scene_manager.detect_scenes(video=video)
    return [start_time.get_seconds() for start_time, _ in scene_manager.get_scene_list()[1:]]


def merge_candidate_windows(
    candidate_windows: list[dict[str, Any]],
    merge_gap_sec: float,
) -> list[dict[str, Any]]:
    if not candidate_windows:
        return []

    sorted_windows = sorted(candidate_windows, key=lambda item: item["startSec"])
    merged: list[dict[str, Any]] = [dict(sorted_windows[0])]

    for window in sorted_windows[1:]:
        current = merged[-1]
        if float(window["startSec"]) - float(current["endSec"]) > merge_gap_sec:
            merged.append(dict(window))
            continue

        current["endSec"] = round(max(float(current["endSec"]), float(window["endSec"])), 3)
        if float(window["score"]) > float(current["score"]):
            current["score"] = round(float(window["score"]), 4)
            current["peakSec"] = round(float(window["peakSec"]), 3)
        current["cutClass"] = (
            "hard-cut"
            if "hard-cut" in {current["cutClass"], window["cutClass"]}
            else "soft-cut"
        )
        current["sources"] = sorted(set(current["sources"] + window["sources"]))

    return merged


def compute_scene_signal_series(
    frames: list[np.ndarray],
    config: SceneCandidateConfig,
) -> tuple[np.ndarray, np.ndarray, str]:
    if len(frames) < 2:
        empty = np.empty((0,), dtype=np.float32)
        return empty, empty, "empty"

    if is_opencv_cuda_available():
        try:
            histogram_scores, frame_diff_scores, edge_diff_scores, motion_scores = (
                _compute_cuda_signal_components(frames)
            )
            backend = "opencv-cuda"
        except Exception:
            histogram_scores, frame_diff_scores, edge_diff_scores, motion_scores = (
                _compute_cpu_signal_components(frames)
            )
            backend = "opencv-cpu"
    else:
        histogram_scores, frame_diff_scores, edge_diff_scores, motion_scores = (
            _compute_cpu_signal_components(frames)
        )
        backend = "opencv-cpu"

    weighted_scores = (
        config.histogram_weight * histogram_scores
        + config.frame_diff_weight * frame_diff_scores
        + config.edge_diff_weight * edge_diff_scores
        + config.motion_proxy_weight * motion_scores
    )
    weighted_scores = np.clip(weighted_scores, 0.0, 1.0).astype(np.float32)
    thresholds = compute_adaptive_thresholds(weighted_scores, config)
    return weighted_scores, thresholds, backend


def compute_adaptive_thresholds(
    scores: np.ndarray,
    config: SceneCandidateConfig,
) -> np.ndarray:
    if scores.size == 0:
        return np.empty((0,), dtype=np.float32)

    radius = max(1, config.adaptive_window_size)
    thresholds = np.empty_like(scores, dtype=np.float32)

    for index in range(scores.size):
        left = max(0, index - radius)
        right = min(scores.size, index + radius + 1)
        local_scores = scores[left:right]
        local_mean = float(np.mean(local_scores))
        local_std = float(np.std(local_scores))
        thresholds[index] = max(
            config.threshold_floor,
            local_mean + local_std * config.threshold_std_factor,
        )

    return thresholds


def build_candidate_windows(
    times_sec: list[float],
    scores: np.ndarray,
    thresholds: np.ndarray,
    config: SceneCandidateConfig,
    source_label: str,
) -> list[dict[str, Any]]:
    if not times_sec or scores.size == 0 or thresholds.size == 0:
        return []

    groups: list[list[int]] = []
    current_group: list[int] = []

    for index, (score, threshold) in enumerate(zip(scores, thresholds)):
        if float(score) >= float(threshold):
            current_group.append(index)
            continue

        if current_group:
            groups.append(current_group)
            current_group = []

    if current_group:
        groups.append(current_group)

    windows: list[dict[str, Any]] = []
    last_peak_sec: float | None = None

    for group in groups:
        peak_index = max(group, key=lambda item: float(scores[item]))
        peak_sec = float(times_sec[peak_index])
        peak_score = float(scores[peak_index])

        if last_peak_sec is not None and peak_sec - last_peak_sec < config.min_scene_len_sec:
            if peak_score > float(windows[-1]["score"]):
                windows[-1] = _build_candidate_window(
                    group,
                    times_sec,
                    scores,
                    config,
                    source_label,
                )
                last_peak_sec = peak_sec
            continue

        windows.append(
            _build_candidate_window(
                group,
                times_sec,
                scores,
                config,
                source_label,
            )
        )
        last_peak_sec = peak_sec

    return merge_candidate_windows(windows, config.merge_gap_sec)


def detect_scene_candidates(
    video_path: Path,
    mode: str,
    config: SceneCandidateConfig | None = None,
) -> dict[str, Any]:
    active_config = config or SceneCandidateConfig()
    detector_mode = normalize_scene_detector_mode(mode)

    if detector_mode == "pyscenedetect":
        cut_points = run_pyscenedetect_cut_points(video_path, active_config)
        candidate_windows = [
            {
                "startSec": round(max(0.0, cut_point - active_config.window_radius_sec), 3),
                "endSec": round(cut_point + active_config.window_radius_sec, 3),
                "peakSec": round(cut_point, 3),
                "score": 1.0,
                "cutClass": "hard-cut",
                "sources": ["scene-pyscenedetect"],
            }
            for cut_point in cut_points
        ]
        return build_scene_result(detector_mode, "pyscenedetect", candidate_windows, active_config)

    if detector_mode == "transnetv2-cuda":
        candidate_windows, backend, extra_meta = detect_transnetv2_candidate_windows(
            video_path,
            active_config,
        )
        result = build_scene_result(detector_mode, backend, candidate_windows, active_config)
        result["meta"] = extra_meta
        return result

    raise ValueError(f"Unsupported scene detector mode: {mode}")


def build_scene_result(
    mode: str,
    backend: str,
    candidate_windows: list[dict[str, Any]],
    config: SceneCandidateConfig,
) -> dict[str, Any]:
    cut_points = [round(float(item["peakSec"]), 3) for item in candidate_windows]
    hard_cut_count = sum(1 for item in candidate_windows if item["cutClass"] == "hard-cut")
    soft_cut_count = sum(1 for item in candidate_windows if item["cutClass"] == "soft-cut")
    return {
        "mode": mode,
        "backend": backend,
        "thresholdMode": "detector",
        "cutPointsSec": cut_points,
        "candidateCount": len(candidate_windows),
        "hardCutCount": hard_cut_count,
        "softCutCount": soft_cut_count,
        "candidateWindows": candidate_windows,
        "config": {
            "sample_step_sec": active_round(config.sample_step_sec),
            "window_radius_sec": active_round(config.window_radius_sec),
            "min_scene_len_sec": active_round(config.min_scene_len_sec),
            "merge_gap_sec": active_round(config.merge_gap_sec),
            "threshold_floor": active_round(config.threshold_floor),
        },
    }


def active_round(value: float) -> float:
    return round(float(value), 4)


def _build_candidate_window(
    group: list[int],
    times_sec: list[float],
    scores: np.ndarray,
    config: SceneCandidateConfig,
    source_label: str,
) -> dict[str, Any]:
    start_index = group[0]
    end_index = group[-1]
    peak_index = max(group, key=lambda item: float(scores[item]))
    start_sec = max(0.0, float(times_sec[start_index]) - config.window_radius_sec)
    end_sec = float(times_sec[end_index]) + config.window_radius_sec
    span_sec = max(config.sample_step_sec, float(times_sec[end_index]) - float(times_sec[start_index]))
    peak_score = float(scores[peak_index])
    is_compact_peak = len(group) == 1 and span_sec <= config.sample_step_sec * 1.2
    cut_class = "hard-cut" if peak_score >= 0.8 and is_compact_peak else "soft-cut"
    return {
        "startSec": round(start_sec, 3),
        "endSec": round(end_sec, 3),
        "peakSec": round(float(times_sec[peak_index]), 3),
        "score": round(peak_score, 4),
        "cutClass": cut_class,
        "sources": [source_label],
    }


def _compute_cpu_signal_components(
    frames: list[np.ndarray],
) -> tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    histogram_scores: list[float] = []
    frame_diff_scores: list[float] = []
    edge_diff_scores: list[float] = []
    motion_scores: list[float] = []

    previous_edges = cv2.Canny(frames[0], 40, 120)

    for index in range(1, len(frames)):
        previous_frame = frames[index - 1]
        current_frame = frames[index]
        histogram_scores.append(_histogram_diff(previous_frame, current_frame))
        frame_difference = cv2.absdiff(previous_frame, current_frame)
        frame_diff = float(np.mean(frame_difference) / 255.0)
        frame_diff_scores.append(frame_diff)
        current_edges = cv2.Canny(current_frame, 40, 120)
        edge_diff = float(np.mean(cv2.absdiff(previous_edges, current_edges)) / 255.0)
        edge_diff_scores.append(edge_diff)
        motion_scores.append(_motion_proxy_score(frame_difference, previous_edges, current_edges))
        previous_edges = current_edges

    return (
        np.asarray(histogram_scores, dtype=np.float32),
        np.asarray(frame_diff_scores, dtype=np.float32),
        np.asarray(edge_diff_scores, dtype=np.float32),
        np.asarray(motion_scores, dtype=np.float32),
    )


def _compute_cuda_signal_components(
    frames: list[np.ndarray],
) -> tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    histogram_scores: list[float] = []
    frame_diff_scores: list[float] = []
    edge_diff_scores: list[float] = []
    motion_scores: list[float] = []
    gpu_frames: list[cv2.cuda.GpuMat] = []
    edge_detector = cv2.cuda.createCannyEdgeDetector(40, 120)
    histograms: list[np.ndarray] = []
    edges: list[np.ndarray] = []

    for frame in frames:
        gpu_frame = cv2.cuda_GpuMat()
        gpu_frame.upload(frame)
        gpu_frames.append(gpu_frame)
        histograms.append(_compress_histogram_32(cv2.cuda.calcHist(gpu_frame).download()))
        edges.append(edge_detector.detect(gpu_frame).download())

    for index in range(1, len(gpu_frames)):
        histogram_scores.append(_compare_histograms(histograms[index - 1], histograms[index]))
        frame_difference = cv2.cuda.absdiff(gpu_frames[index - 1], gpu_frames[index]).download()
        frame_diff = float(np.mean(frame_difference) / 255.0)
        frame_diff_scores.append(frame_diff)
        edge_diff = float(np.mean(cv2.absdiff(edges[index - 1], edges[index])) / 255.0)
        edge_diff_scores.append(edge_diff)
        motion_scores.append(_motion_proxy_score(frame_difference, edges[index - 1], edges[index]))

    return (
        np.asarray(histogram_scores, dtype=np.float32),
        np.asarray(frame_diff_scores, dtype=np.float32),
        np.asarray(edge_diff_scores, dtype=np.float32),
        np.asarray(motion_scores, dtype=np.float32),
    )


def _histogram_diff(previous_frame: np.ndarray, current_frame: np.ndarray) -> float:
    previous_hist = cv2.calcHist([previous_frame], [0], None, [32], [0, 256])
    current_hist = cv2.calcHist([current_frame], [0], None, [32], [0, 256])
    previous_hist = cv2.normalize(previous_hist, previous_hist).flatten()
    current_hist = cv2.normalize(current_hist, current_hist).flatten()
    return _compare_histograms(previous_hist, current_hist)


def _compare_histograms(previous_hist: np.ndarray, current_hist: np.ndarray) -> float:
    return float(
        max(
            0.0,
            min(
                1.0,
                1.0 - cv2.compareHist(previous_hist, current_hist, cv2.HISTCMP_CORREL),
            ),
        )
    )


def _compress_histogram_32(histogram_256: np.ndarray) -> np.ndarray:
    flattened = histogram_256.reshape(-1).astype(np.float32)
    histogram_32 = flattened.reshape(32, 8).sum(axis=1)
    norm = float(np.linalg.norm(histogram_32))
    if norm > 0.0:
        histogram_32 = histogram_32 / norm
    return histogram_32.astype(np.float32)


def _motion_proxy_score(
    frame_difference: np.ndarray,
    previous_edges: np.ndarray,
    current_edges: np.ndarray,
) -> float:
    changed_pixels = float(np.mean((frame_difference >= 18).astype(np.float32)))
    edge_density_shift = abs(
        float(np.mean(previous_edges > 0)) - float(np.mean(current_edges > 0))
    )
    return float(np.clip(changed_pixels * 0.72 + edge_density_shift * 0.28, 0.0, 1.0))


def _read_video_duration_sec(video_path: Path) -> float:
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError("Unable to open video file.")

    try:
        fps = float(capture.get(cv2.CAP_PROP_FPS) or 0.0)
        frame_count = int(capture.get(cv2.CAP_PROP_FRAME_COUNT) or 0)
    finally:
        capture.release()

    if fps <= 0.0:
        fps = 25.0

    return frame_count / fps if frame_count > 0 else 0.0
