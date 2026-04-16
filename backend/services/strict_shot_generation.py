from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Any

LOG_START = "[Start] Strict shot generation started"
LOG_INPUT = "[Process] Input boundary count"
LOG_OUTPUT = "[Process] Strict shot count"
LOG_REMOVED = "[Process] Removed boundary count"
LOG_COMPLETE = "[Done] Strict shot generation completed"


@dataclass(frozen=True)
class StrictShotConfig:
    dedupe_epsilon_sec: float = 0.05
    min_shot_sec: float = 0.15
    abnormal_short_sec: float = 0.3


def generate_strict_shots(
    video_duration_sec: float,
    boundary_candidates: list[dict[str, Any]],
    config: StrictShotConfig | None = None,
) -> dict[str, Any]:
    active_config = config or StrictShotConfig()
    print(LOG_START)
    print(f"{LOG_INPUT}: {len(boundary_candidates)}")

    cleaned_boundaries, removed_boundaries = _cleanup_boundaries(
        video_duration_sec=video_duration_sec,
        boundary_candidates=boundary_candidates,
        config=active_config,
    )
    shots = _build_shots(video_duration_sec=video_duration_sec, boundaries=cleaned_boundaries)
    summary = _build_summary(shots=shots, config=active_config)

    print(f"{LOG_OUTPUT}: {summary['shotCount']}")
    print(f"{LOG_REMOVED}: {len(removed_boundaries)}")
    print(LOG_COMPLETE)

    return {
        "videoDurationSec": round(float(video_duration_sec), 3),
        "usedBoundaryPointsSec": [round(item["timeSec"], 3) for item in cleaned_boundaries],
        "removedBoundaries": [
            {
                "timeSec": round(float(item["timeSec"]), 3),
                "reason": item["reason"],
            }
            for item in removed_boundaries
        ],
        "shots": shots,
        "summary": summary,
        "config": {
            "dedupe_epsilon_sec": round(float(active_config.dedupe_epsilon_sec), 3),
            "min_shot_sec": round(float(active_config.min_shot_sec), 3),
            "abnormal_short_sec": round(float(active_config.abnormal_short_sec), 3),
        },
    }


def _cleanup_boundaries(
    video_duration_sec: float,
    boundary_candidates: list[dict[str, Any]],
    config: StrictShotConfig,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
    sorted_candidates = sorted(boundary_candidates, key=lambda item: float(item.get("timeSec", 0.0)))
    kept_boundaries: list[dict[str, Any]] = []
    removed_boundaries: list[dict[str, Any]] = []

    for candidate in sorted_candidates:
        time_sec = float(candidate.get("timeSec", 0.0))

        if not math.isfinite(time_sec):
            removed_boundaries.append({"timeSec": 0.0, "reason": "invalid-time"})
            continue

        if time_sec <= config.dedupe_epsilon_sec or time_sec >= video_duration_sec - config.dedupe_epsilon_sec:
            removed_boundaries.append({"timeSec": time_sec, "reason": "out-of-range"})
            continue

        if kept_boundaries and time_sec - float(kept_boundaries[-1]["timeSec"]) <= config.dedupe_epsilon_sec:
            removed_boundaries.append({"timeSec": time_sec, "reason": "duplicate"})
            continue

        if kept_boundaries and time_sec - float(kept_boundaries[-1]["timeSec"]) < config.min_shot_sec:
            removed_boundaries.append({"timeSec": time_sec, "reason": "micro-shot"})
            continue

        kept_boundaries.append({"timeSec": time_sec, "score": candidate.get("score")})

    if kept_boundaries and video_duration_sec - float(kept_boundaries[-1]["timeSec"]) < config.min_shot_sec:
        removed_boundary = kept_boundaries.pop()
        removed_boundaries.append({"timeSec": float(removed_boundary["timeSec"]), "reason": "micro-tail"})

    return kept_boundaries, removed_boundaries


def _build_shots(video_duration_sec: float, boundaries: list[dict[str, Any]]) -> list[dict[str, Any]]:
    timeline_points = [0.0]
    timeline_points.extend(float(item["timeSec"]) for item in boundaries)
    timeline_points.append(float(video_duration_sec))

    shots: list[dict[str, Any]] = []
    for index in range(1, len(timeline_points)):
        start_sec = float(timeline_points[index - 1])
        end_sec = float(timeline_points[index])
        shots.append(
            {
                "index": index,
                "startSec": round(start_sec, 3),
                "endSec": round(end_sec, 3),
                "durationSec": round(end_sec - start_sec, 3),
            }
        )
    return shots


def _build_summary(shots: list[dict[str, Any]], config: StrictShotConfig) -> dict[str, Any]:
    durations = [float(item["durationSec"]) for item in shots]
    return {
        "shotCount": len(shots),
        "shortestShotSec": round(min(durations), 3) if durations else 0.0,
        "longestShotSec": round(max(durations), 3) if durations else 0.0,
        "abnormalShortShotCount": sum(1 for value in durations if value < config.abnormal_short_sec),
        "isLegal": all(float(item["durationSec"]) > 0.0 for item in shots),
    }
