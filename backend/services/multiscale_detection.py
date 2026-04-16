from __future__ import annotations

from bisect import bisect_left, bisect_right
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2
import numpy as np

from .frame_sampling import sample_grayscale_frames
from .scene_candidate_detection import SceneCandidateConfig, detect_scene_candidates
from .torch_scoring import compute_weighted_transition_scores

LOG_START = "[Start] Full timeline multi-scale detection started"
LOG_COARSE = "[Process] Coarse window params"
LOG_FINE = "[Process] Fine window params"
LOG_SCENE_DETECTOR = "[Process] Scene detector"
LOG_BACKEND = "[Process] Decode backend"
LOG_COMPUTE = "[Process] Compute backend"
LOG_COUNT = "[Process] Suspicious change region count"
LOG_COMPLETE = "[Done] Full timeline multi-scale detection finished"
LOG_WARNING = "[Warning]"


@dataclass(frozen=True)
class CoarseDetectionConfig:
    window_sec: float = 2.0
    stride_sec: float = 0.5
    histogram_weight: float = 0.55
    frame_diff_weight: float = 0.45
    score_threshold: float = 0.58
    merge_gap_sec: float = 1.2


@dataclass(frozen=True)
class FineDetectionConfig:
    search_radius_sec: float = 1.0
    sample_step_sec: float = 0.08
    histogram_weight: float = 0.45
    frame_diff_weight: float = 0.55
    score_threshold: float = 0.5


@dataclass(frozen=True)
class VideoIndex:
    fps: float
    frame_count: int
    duration_sec: float
    width: int
    height: int


def _open_capture(video_path: Path) -> cv2.VideoCapture:
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError("Unable to open video file.")
    return capture


def build_video_index(video_path: Path) -> VideoIndex:
    capture = _open_capture(video_path)

    try:
        fps = float(capture.get(cv2.CAP_PROP_FPS) or 0.0)
        frame_count = int(capture.get(cv2.CAP_PROP_FRAME_COUNT) or 0)
        width = int(capture.get(cv2.CAP_PROP_FRAME_WIDTH) or 0)
        height = int(capture.get(cv2.CAP_PROP_FRAME_HEIGHT) or 0)
    finally:
        capture.release()

    if fps <= 0:
        fps = 25.0

    duration_sec = frame_count / fps if frame_count > 0 else 0.0
    return VideoIndex(
        fps=fps,
        frame_count=frame_count,
        duration_sec=duration_sec,
        width=width,
        height=height,
    )


def _read_frame(capture: cv2.VideoCapture, frame_index: int) -> np.ndarray | None:
    capture.set(cv2.CAP_PROP_POS_FRAMES, frame_index)
    success, frame = capture.read()
    if not success or frame is None:
        return None
    return frame


def _prepare_frame(frame: np.ndarray) -> np.ndarray:
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    return cv2.resize(gray, (320, 180), interpolation=cv2.INTER_AREA)


def _normalized_histogram(frame: np.ndarray) -> np.ndarray:
    histogram = cv2.calcHist([frame], [0], None, [32], [0, 256])
    histogram = cv2.normalize(histogram, histogram).flatten()
    return histogram


def _frame_score(
    previous_frame: np.ndarray,
    current_frame: np.ndarray,
    histogram_weight: float,
    frame_diff_weight: float,
) -> float:
    previous_histogram = _normalized_histogram(previous_frame)
    current_histogram = _normalized_histogram(current_frame)
    histogram_diff = 1.0 - cv2.compareHist(previous_histogram, current_histogram, cv2.HISTCMP_CORREL)
    frame_difference = cv2.absdiff(previous_frame, current_frame)
    diff_score = float(np.mean(frame_difference) / 255.0)
    weighted_score = histogram_weight * histogram_diff + frame_diff_weight * diff_score
    return max(0.0, min(1.0, weighted_score))


def _merge_regions(regions: list[dict[str, Any]], merge_gap_sec: float) -> list[dict[str, Any]]:
    if not regions:
        return []

    sorted_regions = sorted(regions, key=lambda item: item["start_sec"])
    merged: list[dict[str, Any]] = [dict(sorted_regions[0])]

    for region in sorted_regions[1:]:
        current = merged[-1]
        if region["start_sec"] - current["end_sec"] <= merge_gap_sec:
            current["end_sec"] = max(current["end_sec"], region["end_sec"])
            if region["score"] > current["score"]:
                current["score"] = region["score"]
                current["peak_sec"] = region["peak_sec"]
            current["sources"] = sorted(set(current["sources"] + region["sources"]))
            continue

        merged.append(dict(region))

    return merged


def _slice_timeline_batch(
    times_sec: list[float],
    frames: list[np.ndarray],
    start_sec: float,
    end_sec: float,
) -> tuple[list[float], list[np.ndarray]]:
    left_index = bisect_left(times_sec, start_sec)
    right_index = bisect_right(times_sec, end_sec)
    return times_sec[left_index:right_index], frames[left_index:right_index]


def _slice_score_series(
    times_sec: list[float],
    scores: np.ndarray,
    start_sec: float,
    end_sec: float,
) -> tuple[list[float], np.ndarray]:
    left_index = bisect_left(times_sec, start_sec)
    right_index = bisect_right(times_sec, end_sec)
    return times_sec[left_index:right_index], scores[left_index:right_index]


def _resolve_scene_detector_merge_gap_sec(
    scene_detector_mode: str,
    coarse: CoarseDetectionConfig,
) -> float:
    normalized_mode = scene_detector_mode.strip().lower()
    if normalized_mode == "transnetv2-cuda":
        return min(float(coarse.merge_gap_sec), float(SceneCandidateConfig().merge_gap_sec))

    return float(coarse.merge_gap_sec)


def detect_full_timeline_multiscale(
    video_path: Path,
    coarse_config: CoarseDetectionConfig | None = None,
    fine_config: FineDetectionConfig | None = None,
    scene_detector_mode: str = "pyscenedetect",
) -> dict[str, Any]:
    coarse = coarse_config or CoarseDetectionConfig()
    fine = fine_config or FineDetectionConfig()
    index = build_video_index(video_path)

    print(LOG_START)
    print(
        f"{LOG_COARSE}: window_sec={coarse.window_sec}, stride_sec={coarse.stride_sec}, "
        f"threshold={coarse.score_threshold}"
    )
    print(
        f"{LOG_FINE}: search_radius_sec={fine.search_radius_sec}, sample_step_sec={fine.sample_step_sec}, "
        f"threshold={fine.score_threshold}"
    )
    print(f"{LOG_SCENE_DETECTOR}: mode={scene_detector_mode}")

    if index.frame_count <= 1:
        print(f"{LOG_COUNT}: 0")
        print(LOG_COMPLETE)
        return {
            "videoIndex": index.__dict__,
            "coarseConfig": coarse.__dict__,
            "fineConfig": fine.__dict__,
            "sceneDetector": {
                "mode": scene_detector_mode,
                "backend": "empty",
                "candidateCount": 0,
                "hardCutCount": 0,
                "softCutCount": 0,
            },
            "sceneDetectorCandidates": [],
            "suspiciousRegions": [],
        }

    coarse_regions: list[dict[str, Any]] = []
    decode_backends: set[str] = set()
    compute_backends: set[str] = set()

    coarse_batch = sample_grayscale_frames(
        video_path=video_path,
        start_sec=0.0,
        end_sec=index.duration_sec,
        step_sec=coarse.stride_sec,
        width=320,
        height=180,
    )
    decode_backends.add(coarse_batch.backend)
    coarse_scores, coarse_compute_backend = compute_weighted_transition_scores(
        coarse_batch.frames,
        coarse.histogram_weight,
        coarse.frame_diff_weight,
    )
    compute_backends.add(coarse_compute_backend)
    window_sec = max(coarse.window_sec, coarse.stride_sec)

    for current_time_sec, score in zip(coarse_batch.times_sec[1:], coarse_scores):
        if float(score) >= coarse.score_threshold:
            peak_sec = current_time_sec
            coarse_regions.append(
                {
                    "start_sec": max(0.0, peak_sec - window_sec / 2),
                    "end_sec": min(index.duration_sec, peak_sec + window_sec / 2),
                    "peak_sec": peak_sec,
                    "score": round(float(score), 4),
                    "sources": ["opencv-coarse"],
                }
            )

    scene_detector_result = {
        "mode": scene_detector_mode,
        "backend": "unavailable",
        "candidateCount": 0,
        "hardCutCount": 0,
        "softCutCount": 0,
        "candidateWindows": [],
    }

    try:
        scene_detector_result = detect_scene_candidates(
            video_path=video_path,
            mode=scene_detector_mode,
            config=SceneCandidateConfig(
                sample_step_sec=max(coarse.stride_sec, 0.08),
                width=256,
                height=144,
                window_radius_sec=max(coarse.window_sec / 2, coarse.stride_sec / 2),
                min_scene_len_sec=max(coarse.window_sec * 0.45, coarse.stride_sec),
                merge_gap_sec=_resolve_scene_detector_merge_gap_sec(
                    scene_detector_mode,
                    coarse,
                ),
                threshold_floor=min(max(coarse.score_threshold - 0.08, 0.25), 0.8),
            ),
        )
        for candidate_window in scene_detector_result["candidateWindows"]:
            coarse_regions.append(
                {
                    "start_sec": max(0.0, float(candidate_window["startSec"])),
                    "end_sec": min(index.duration_sec, float(candidate_window["endSec"])),
                    "peak_sec": float(candidate_window["peakSec"]),
                    "score": round(float(candidate_window["score"]), 4),
                    "sources": list(candidate_window["sources"]),
                }
            )
    except Exception as exc:
        print(f"{LOG_WARNING} Scene detector failed and was skipped: {exc}")

    merged_regions = _merge_regions(coarse_regions, coarse.merge_gap_sec)
    suspicious_regions: list[dict[str, Any]] = []

    fine_batch = sample_grayscale_frames(
        video_path=video_path,
        start_sec=0.0,
        end_sec=index.duration_sec,
        step_sec=fine.sample_step_sec,
        width=320,
        height=180,
    )
    decode_backends.add(fine_batch.backend)
    fine_scores, fine_compute_backend = compute_weighted_transition_scores(
        fine_batch.frames,
        fine.histogram_weight,
        fine.frame_diff_weight,
    )
    compute_backends.add(fine_compute_backend)

    for region in merged_regions:
        start_sec = max(0.0, region["peak_sec"] - fine.search_radius_sec)
        end_sec = min(index.duration_sec, region["peak_sec"] + fine.search_radius_sec)
        best_score = 0.0
        best_time_sec = region["peak_sec"]

        region_times_sec, region_scores = _slice_score_series(
            times_sec=fine_batch.times_sec[1:],
            scores=fine_scores,
            start_sec=start_sec,
            end_sec=end_sec,
        )

        for sample_time_sec, score in zip(region_times_sec, region_scores):
            if float(score) > best_score:
                best_score = float(score)
                best_time_sec = sample_time_sec

        suspicious_regions.append(
            {
                "startSec": round(start_sec, 3),
                "endSec": round(end_sec, 3),
                "peakSec": round(best_time_sec, 3),
                "coarsePeakSec": round(region["peak_sec"], 3),
                "score": round(max(region["score"], best_score), 4),
                "confidence": "high" if max(region["score"], best_score) >= fine.score_threshold else "low",
                "sources": region["sources"],
            }
        )

    low_confidence_count = sum(1 for item in suspicious_regions if item["confidence"] == "low")
    print(f"{LOG_COMPUTE}: {', '.join(sorted(compute_backends))}")
    print(f"{LOG_BACKEND}: {', '.join(sorted(decode_backends))}")
    print(
        f"{LOG_SCENE_DETECTOR}: mode={scene_detector_result['mode']}, "
        f"backend={scene_detector_result['backend']}, "
        f"candidates={scene_detector_result['candidateCount']}, "
        f"hardCuts={scene_detector_result['hardCutCount']}, "
        f"softCuts={scene_detector_result['softCutCount']}"
    )
    print(f"{LOG_COUNT}: {len(suspicious_regions)}")
    if low_confidence_count > 0:
        print(f"{LOG_WARNING} Low-confidence suspicious regions detected: {low_confidence_count}")
    print(LOG_COMPLETE)

    return {
        "videoIndex": {
            "fps": round(index.fps, 3),
            "frameCount": index.frame_count,
            "durationSec": round(index.duration_sec, 3),
            "width": index.width,
            "height": index.height,
        },
        "coarseConfig": coarse.__dict__,
        "fineConfig": fine.__dict__,
        "sceneDetector": {
            "mode": scene_detector_result["mode"],
            "backend": scene_detector_result["backend"],
            "candidateCount": scene_detector_result["candidateCount"],
            "hardCutCount": scene_detector_result["hardCutCount"],
            "softCutCount": scene_detector_result["softCutCount"],
        },
        "sceneDetectorCandidates": scene_detector_result["candidateWindows"],
        "suspiciousRegions": suspicious_regions,
    }
