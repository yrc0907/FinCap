from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Any

LOG_START = "【开始】动态片段生成开始"
LOG_COUNT = "【过程】候选边界数量"
LOG_SEGMENTS = "【过程】最终动态片段数量"
LOG_RANGE = "【过程】最短片段、最长片段"
LOG_WARNING = "【警告】存在异常短片段"
LOG_COMPLETE = "【完成】动态片段生成完成"
LOG_ERROR = "【错误】片段生成失败"
LOG_FALLBACK = "【回退】退回最近可用边界版本"


@dataclass(frozen=True)
class DynamicSegmentConfig:
    min_segment_sec: float = 1.6
    abnormal_short_sec: float = 1.0
    dedupe_epsilon_sec: float = 0.05


def generate_dynamic_segments(
    video_duration_sec: float,
    boundary_candidates: list[dict[str, Any]],
    config: DynamicSegmentConfig | None = None,
) -> dict[str, Any]:
    active_config = config or DynamicSegmentConfig()
    print(LOG_START)
    print(f"{LOG_COUNT}：{len(boundary_candidates)}")

    try:
        if video_duration_sec <= 0.0:
            raise ValueError("Video duration must be positive.")

        cleaned_boundaries, removed_boundaries = _cleanup_boundaries(
            video_duration_sec=video_duration_sec,
            boundary_candidates=boundary_candidates,
            config=active_config,
        )
        used_boundaries, short_removed_boundaries = _apply_tail_first_correction(
            video_duration_sec=video_duration_sec,
            cleaned_boundaries=cleaned_boundaries,
            config=active_config,
        )
        removed_boundaries.extend(short_removed_boundaries)
        segments = _build_segments(
            video_duration_sec=video_duration_sec,
            used_boundaries=used_boundaries,
        )
        summary = _build_summary(segments, active_config)
        is_legal, legality_errors = _validate_segments(
            video_duration_sec=video_duration_sec,
            segments=segments,
        )
        summary["isLegal"] = is_legal

        if not is_legal:
            print(f"{LOG_FALLBACK}：{' | '.join(legality_errors)}")
            raise ValueError("; ".join(legality_errors))

        print(f"{LOG_SEGMENTS}：{summary['segmentCount']}")
        print(
            f"{LOG_RANGE}：{summary['shortestSegmentSec']:.3f}s / "
            f"{summary['longestSegmentSec']:.3f}s"
        )
        if summary["abnormalShortSegmentCount"] > 0:
            print(f"{LOG_WARNING}：{summary['abnormalShortSegmentCount']}")
        print(LOG_COMPLETE)

        return {
            "videoDurationSec": round(float(video_duration_sec), 3),
            "inputBoundaryCount": len(boundary_candidates),
            "usedBoundaryCount": len(used_boundaries),
            "removedBoundaryCount": len(removed_boundaries),
            "usedBoundaryPointsSec": [round(item["timeSec"], 3) for item in used_boundaries],
            "removedBoundaries": [
                {
                    "timeSec": round(float(item["timeSec"]), 3),
                    "reason": item["reason"],
                }
                for item in removed_boundaries
            ],
            "segments": segments,
            "summary": summary,
            "config": {
                "min_segment_sec": round(float(active_config.min_segment_sec), 3),
                "abnormal_short_sec": round(float(active_config.abnormal_short_sec), 3),
                "dedupe_epsilon_sec": round(float(active_config.dedupe_epsilon_sec), 3),
            },
        }
    except Exception as exc:
        print(f"{LOG_ERROR}：{exc}")
        raise


def _cleanup_boundaries(
    video_duration_sec: float,
    boundary_candidates: list[dict[str, Any]],
    config: DynamicSegmentConfig,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
    cleaned_boundaries: list[dict[str, Any]] = []
    removed_boundaries: list[dict[str, Any]] = []
    sorted_candidates = sorted(boundary_candidates, key=_extract_time_sec)

    for candidate in sorted_candidates:
        time_sec = _extract_time_sec(candidate)
        if not math.isfinite(time_sec):
            removed_boundaries.append({"timeSec": 0.0, "reason": "invalid-time"})
            continue

        if time_sec <= config.dedupe_epsilon_sec or time_sec >= (
            video_duration_sec - config.dedupe_epsilon_sec
        ):
            removed_boundaries.append({"timeSec": time_sec, "reason": "out-of-range"})
            continue

        if cleaned_boundaries and (
            time_sec - float(cleaned_boundaries[-1]["timeSec"]) <= config.dedupe_epsilon_sec
        ):
            removed_boundaries.append({"timeSec": time_sec, "reason": "duplicate"})
            continue

        cleaned_boundaries.append(
            {
                "timeSec": time_sec,
                "confidence": candidate.get("confidence"),
                "sources": list(candidate.get("sources", [])),
            }
        )

    return cleaned_boundaries, removed_boundaries


def _apply_tail_first_correction(
    video_duration_sec: float,
    cleaned_boundaries: list[dict[str, Any]],
    config: DynamicSegmentConfig,
) -> tuple[list[dict[str, Any]], list[dict[str, Any]]]:
    used_boundaries: list[dict[str, Any]] = []
    removed_boundaries: list[dict[str, Any]] = []
    current_start_sec = 0.0

    for boundary in cleaned_boundaries:
        candidate_duration = float(boundary["timeSec"]) - current_start_sec
        if candidate_duration < config.min_segment_sec:
            removed_boundaries.append(
                {
                    "timeSec": float(boundary["timeSec"]),
                    "reason": "short-segment",
                }
            )
            continue

        used_boundaries.append(boundary)
        current_start_sec = float(boundary["timeSec"])

    if used_boundaries and (video_duration_sec - float(used_boundaries[-1]["timeSec"])) < config.min_segment_sec:
        removed_boundaries.append(
            {
                "timeSec": float(used_boundaries[-1]["timeSec"]),
                "reason": "short-tail",
            }
        )
        used_boundaries.pop()

    return used_boundaries, removed_boundaries


def _build_segments(
    video_duration_sec: float,
    used_boundaries: list[dict[str, Any]],
) -> list[dict[str, Any]]:
    timeline_points = [0.0]
    timeline_points.extend(float(item["timeSec"]) for item in used_boundaries)
    timeline_points.append(float(video_duration_sec))

    segments: list[dict[str, Any]] = []
    for index in range(1, len(timeline_points)):
        start_sec = float(timeline_points[index - 1])
        end_sec = float(timeline_points[index])
        segments.append(
            {
                "index": index,
                "startSec": round(start_sec, 3),
                "endSec": round(end_sec, 3),
                "durationSec": round(end_sec - start_sec, 3),
                "startBoundarySec": round(start_sec, 3) if index > 1 else None,
                "endBoundarySec": round(end_sec, 3) if index < len(timeline_points) - 1 else None,
            }
        )

    return segments


def _build_summary(
    segments: list[dict[str, Any]],
    config: DynamicSegmentConfig,
) -> dict[str, Any]:
    if not segments:
        return {
            "segmentCount": 0,
            "shortestSegmentSec": 0.0,
            "longestSegmentSec": 0.0,
            "abnormalShortSegmentCount": 0,
            "isLegal": True,
        }

    durations = [float(item["durationSec"]) for item in segments]
    return {
        "segmentCount": len(segments),
        "shortestSegmentSec": round(min(durations), 3),
        "longestSegmentSec": round(max(durations), 3),
        "abnormalShortSegmentCount": sum(
            1 for duration in durations if duration < config.abnormal_short_sec
        ),
        "isLegal": True,
    }


def _validate_segments(
    video_duration_sec: float,
    segments: list[dict[str, Any]],
) -> tuple[bool, list[str]]:
    if not segments:
        return False, ["No segments generated."]

    errors: list[str] = []
    first_start_sec = float(segments[0]["startSec"])
    if abs(first_start_sec - 0.0) > 0.001:
        errors.append("First segment must start at zero.")

    last_end_sec = float(segments[-1]["endSec"])
    if abs(last_end_sec - float(video_duration_sec)) > 0.001:
        errors.append("Last segment must end at video duration.")

    previous_end_sec = None
    for segment in segments:
        start_sec = float(segment["startSec"])
        end_sec = float(segment["endSec"])
        if end_sec <= start_sec:
            errors.append("Segment duration must be positive.")
        if previous_end_sec is not None and abs(start_sec - previous_end_sec) > 0.001:
            errors.append("Segments must be continuous with no gaps or overlaps.")
        previous_end_sec = end_sec

    return len(errors) == 0, errors


def _extract_time_sec(candidate: dict[str, Any]) -> float:
    return float(candidate.get("timeSec", 0.0))
