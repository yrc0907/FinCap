from __future__ import annotations

from dataclasses import dataclass
from typing import Any

LOG_START = "【开始】事件合并开始"
LOG_INPUT = "【过程】合并前动态片段数量"
LOG_OUTPUT = "【过程】合并后事件段数量"
LOG_COMPLETE = "【完成】事件合并完成"
LOG_WARNING = "【警告】存在可疑碎片化事件段"
LOG_ERROR = "【错误】事件合并失败"
LOG_FALLBACK = "【回退】保留动态片段直接继续"


@dataclass(frozen=True)
class EventMergeConfig:
    target_event_sec: float = 6.0
    max_event_sec: float = 9.0
    short_segment_sec: float = 2.8
    substantial_segment_sec: float = 3.5
    keep_boundary_score: float = 0.82
    strong_boundary_score: float = 0.86
    weak_boundary_score: float = 0.78
    suspicious_fragment_sec: float = 3.0
    boundary_epsilon_sec: float = 0.05


def merge_dynamic_segments_into_events(
    dynamic_segments: list[dict[str, Any]],
    boundary_candidates: list[dict[str, Any]],
    config: EventMergeConfig | None = None,
) -> dict[str, Any]:
    active_config = config or EventMergeConfig()
    print(LOG_START)
    print(f"{LOG_INPUT}：{len(dynamic_segments)}")

    try:
        _validate_dynamic_segments(dynamic_segments)
        events: list[dict[str, Any]] = []
        kept_boundary_points: list[float] = []
        merged_boundary_points: list[float] = []
        merged_boundaries: list[dict[str, Any]] = []
        boundary_lookup = _build_boundary_lookup(
            boundary_candidates=boundary_candidates,
            epsilon_sec=active_config.boundary_epsilon_sec,
        )

        current_group = [dynamic_segments[0]]
        current_merge_reasons: list[str] = []

        for next_segment in dynamic_segments[1:]:
            boundary_time_sec = float(current_group[-1]["endSec"])
            boundary = _find_boundary(boundary_lookup, boundary_time_sec, active_config)
            decision = _decide_boundary(
                current_group=current_group,
                next_segment=next_segment,
                boundary=boundary,
                config=active_config,
            )

            if decision["merge"]:
                current_group.append(next_segment)
                current_merge_reasons.append(decision["reason"])
                merged_boundary_points.append(round(boundary_time_sec, 3))
                merged_boundaries.append(
                    {
                        "timeSec": round(boundary_time_sec, 3),
                        "reason": decision["reason"],
                    }
                )
                continue

            kept_boundary_points.append(round(boundary_time_sec, 3))
            events.append(_build_event(current_group, current_merge_reasons, len(events) + 1))
            current_group = [next_segment]
            current_merge_reasons = []

        events.append(_build_event(current_group, current_merge_reasons, len(events) + 1))
        summary = _build_summary(events, active_config)

        print(f"{LOG_OUTPUT}：{summary['eventCount']}")
        if summary["suspiciousFragmentCount"] > 0:
            print(f"{LOG_WARNING}：{summary['suspiciousFragmentCount']}")
        print(LOG_COMPLETE)

        return {
            "inputSegmentCount": len(dynamic_segments),
            "eventCount": len(events),
            "keptBoundaryPointsSec": kept_boundary_points,
            "mergedBoundaryPointsSec": merged_boundary_points,
            "mergedBoundaries": merged_boundaries,
            "events": events,
            "summary": summary,
            "config": {
                "target_event_sec": round(float(active_config.target_event_sec), 3),
                "max_event_sec": round(float(active_config.max_event_sec), 3),
                "short_segment_sec": round(float(active_config.short_segment_sec), 3),
                "substantial_segment_sec": round(float(active_config.substantial_segment_sec), 3),
                "keep_boundary_score": round(float(active_config.keep_boundary_score), 3),
                "strong_boundary_score": round(float(active_config.strong_boundary_score), 3),
            },
        }
    except Exception as exc:
        print(f"{LOG_ERROR}：{exc}")
        print(LOG_FALLBACK)
        raise


def _validate_dynamic_segments(dynamic_segments: list[dict[str, Any]]) -> None:
    if not dynamic_segments:
        raise ValueError("Dynamic segments are required.")

    previous_end_sec: float | None = None
    for segment in dynamic_segments:
        start_sec = float(segment["startSec"])
        end_sec = float(segment["endSec"])
        if end_sec <= start_sec:
            raise ValueError("Dynamic segments must have positive duration.")
        if previous_end_sec is not None and abs(start_sec - previous_end_sec) > 0.001:
            raise ValueError("Dynamic segments must be continuous.")
        previous_end_sec = end_sec


def _build_boundary_lookup(
    boundary_candidates: list[dict[str, Any]],
    epsilon_sec: float,
) -> list[dict[str, Any]]:
    lookup = sorted(boundary_candidates, key=lambda item: float(item.get("timeSec", 0.0)))
    deduped: list[dict[str, Any]] = []
    for candidate in lookup:
        time_sec = float(candidate.get("timeSec", 0.0))
        if deduped and abs(time_sec - float(deduped[-1].get("timeSec", 0.0))) <= epsilon_sec:
            if float(candidate.get("score", 0.0)) > float(deduped[-1].get("score", 0.0)):
                deduped[-1] = dict(candidate)
            continue
        deduped.append(dict(candidate))
    return deduped


def _find_boundary(
    boundary_lookup: list[dict[str, Any]],
    boundary_time_sec: float,
    config: EventMergeConfig,
) -> dict[str, Any] | None:
    for candidate in boundary_lookup:
        if abs(float(candidate.get("timeSec", 0.0)) - boundary_time_sec) <= config.boundary_epsilon_sec:
            return candidate
    return None


def _decide_boundary(
    current_group: list[dict[str, Any]],
    next_segment: dict[str, Any],
    boundary: dict[str, Any] | None,
    config: EventMergeConfig,
) -> dict[str, Any]:
    current_event_duration = float(current_group[-1]["endSec"]) - float(current_group[0]["startSec"])
    next_duration = float(next_segment["durationSec"])
    boundary_score = float(boundary.get("score", 0.0)) if boundary is not None else 0.0
    boundary_origin = str(boundary.get("origin", "")) if boundary is not None else ""
    is_subject_supported = "subject" in boundary_origin
    current_is_substantial = current_event_duration >= config.substantial_segment_sec
    next_is_substantial = next_duration >= config.substantial_segment_sec
    both_substantial = current_is_substantial and next_is_substantial
    boundary_is_strong = boundary_score >= config.strong_boundary_score or (
        is_subject_supported and boundary_score >= config.keep_boundary_score
    )
    boundary_is_keepable = boundary_score >= config.keep_boundary_score

    if current_event_duration >= config.max_event_sec:
        return {"merge": False, "reason": "max-event-guardrail"}

    if boundary_is_strong and both_substantial:
        return {"merge": False, "reason": "strong-boundary"}

    if boundary_is_keepable and both_substantial and (
        current_event_duration + next_duration >= config.target_event_sec
    ):
        return {"merge": False, "reason": "substantial-neighbors"}

    if next_duration <= config.short_segment_sec:
        return {"merge": True, "reason": "short-next-segment"}

    if current_event_duration < config.target_event_sec:
        return {"merge": True, "reason": "short-current-event"}

    if boundary_score < config.weak_boundary_score:
        return {"merge": True, "reason": "weak-boundary"}

    return {"merge": False, "reason": "default-keep"}


def _build_event(
    segments: list[dict[str, Any]],
    merge_reasons: list[str],
    event_index: int,
) -> dict[str, Any]:
    start_sec = float(segments[0]["startSec"])
    end_sec = float(segments[-1]["endSec"])
    return {
        "index": event_index,
        "startSec": round(start_sec, 3),
        "endSec": round(end_sec, 3),
        "durationSec": round(end_sec - start_sec, 3),
        "segmentCount": len(segments),
        "startSegmentIndex": int(segments[0]["index"]),
        "endSegmentIndex": int(segments[-1]["index"]),
        "mergeReasons": list(merge_reasons),
    }


def _build_summary(
    events: list[dict[str, Any]],
    config: EventMergeConfig,
) -> dict[str, Any]:
    durations = [float(item["durationSec"]) for item in events]
    return {
        "eventCount": len(events),
        "shortestEventSec": round(min(durations), 3),
        "longestEventSec": round(max(durations), 3),
        "suspiciousFragmentCount": sum(
            1 for duration in durations if duration < config.suspicious_fragment_sec
        ),
    }
