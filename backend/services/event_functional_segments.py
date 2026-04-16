from __future__ import annotations

from dataclasses import dataclass
from typing import Any


@dataclass(frozen=True)
class FunctionalSegmentConfig:
    epsilon_sec: float = 0.001
    max_build_shots: int = 2
    max_result_shots: int = 1
    min_peak_score: float = 0.55
    min_context_score: float = 0.28
    weak_transition_score: float = 0.4


def extract_event_functional_segments(
    events: list[dict[str, Any]],
    groups: list[dict[str, Any]],
    shots: list[dict[str, Any]],
    config: FunctionalSegmentConfig | None = None,
) -> dict[str, Any]:
    active_config = config or FunctionalSegmentConfig()
    ordered_groups = sorted(groups, key=lambda item: int(item["index"]))
    ordered_shots = sorted(shots, key=lambda item: float(item["startSec"]))
    groups_by_index = {int(group["index"]): group for group in ordered_groups}

    enriched_events: list[dict[str, Any]] = []
    functional_clips: list[dict[str, Any]] = []
    for event in events:
        segments = _build_event_functional_segments(
            event=event,
            groups_by_index=groups_by_index,
            ordered_shots=ordered_shots,
            config=active_config,
        )
        enriched_event = dict(event)
        enriched_event["functionalSegments"] = segments
        enriched_events.append(enriched_event)
        for segment in segments:
            if not bool(segment["selected"]):
                continue
            functional_clips.append(
                {
                    "index": len(functional_clips) + 1,
                    "eventIndex": int(event["index"]),
                    "type": segment["type"],
                    "startSec": segment["startSec"],
                    "endSec": segment["endSec"],
                    "durationSec": segment["durationSec"],
                    "score": segment["score"],
                    "reason": segment["reason"],
                    "sourceShotIndexes": segment["sourceShotIndexes"],
                    "sourceGroupIndexes": segment["sourceGroupIndexes"],
                }
            )

    return {
        "events": enriched_events,
        "functionalClips": functional_clips,
        "summary": _build_summary(enriched_events, functional_clips),
    }


def _build_event_functional_segments(
    event: dict[str, Any],
    groups_by_index: dict[int, dict[str, Any]],
    ordered_shots: list[dict[str, Any]],
    config: FunctionalSegmentConfig,
) -> list[dict[str, Any]]:
    event_shots = _decorate_event_shots(event, groups_by_index, ordered_shots, config.epsilon_sec)
    if not event_shots:
        return []

    peak_anchor_index = _resolve_peak_anchor_index(event_shots)
    if _should_emit_transition_only(event_shots, peak_anchor_index, config):
        transition_segments: list[dict[str, Any]] = []
        _append_segment(
            segments=transition_segments,
            event_index=int(event["index"]),
            segment_type="transition",
            reason="low-value-event",
            event_shots=event_shots,
            start_index=0,
            end_index=len(event_shots) - 1,
            selected=False,
        )
        return transition_segments

    peak_start_index, peak_end_index = _expand_peak_cluster(event_shots, peak_anchor_index, config)
    peak_group_indexes = list(event_shots[peak_anchor_index]["sourceGroupIndexes"])
    build_start_index = _expand_context_start(
        event_shots=event_shots,
        context_start_index=peak_start_index,
        context_limit=config.max_build_shots,
        peak_group_indexes=peak_group_indexes,
        config=config,
    )
    result_end_index = _expand_context_end(
        event_shots=event_shots,
        context_end_index=peak_end_index,
        context_limit=config.max_result_shots,
        peak_group_indexes=peak_group_indexes,
        config=config,
    )

    segments: list[dict[str, Any]] = []
    _append_segment(
        segments=segments,
        event_index=int(event["index"]),
        segment_type="transition",
        reason="leading-transition",
        event_shots=event_shots,
        start_index=0,
        end_index=build_start_index - 1,
        selected=False,
    )
    _append_segment(
        segments=segments,
        event_index=int(event["index"]),
        segment_type="build",
        reason="pre-peak-context",
        event_shots=event_shots,
        start_index=build_start_index,
        end_index=peak_start_index - 1,
        selected=True,
    )
    _append_segment(
        segments=segments,
        event_index=int(event["index"]),
        segment_type="peak",
        reason="peak-core",
        event_shots=event_shots,
        start_index=peak_start_index,
        end_index=peak_end_index,
        selected=True,
    )
    _append_segment(
        segments=segments,
        event_index=int(event["index"]),
        segment_type="result",
        reason="post-peak-result",
        event_shots=event_shots,
        start_index=peak_end_index + 1,
        end_index=result_end_index,
        selected=True,
    )
    _append_segment(
        segments=segments,
        event_index=int(event["index"]),
        segment_type="transition",
        reason="trailing-transition",
        event_shots=event_shots,
        start_index=result_end_index + 1,
        end_index=len(event_shots) - 1,
        selected=False,
    )
    return segments


def _decorate_event_shots(
    event: dict[str, Any],
    groups_by_index: dict[int, dict[str, Any]],
    ordered_shots: list[dict[str, Any]],
    epsilon_sec: float,
) -> list[dict[str, Any]]:
    event_start_sec = float(event["startSec"])
    event_end_sec = float(event["endSec"])
    source_group_indexes = [int(value) for value in event.get("sourceGroupIndexes", [])]
    decorated: list[dict[str, Any]] = []

    for shot in ordered_shots:
        overlap_start_sec = max(float(shot["startSec"]), event_start_sec)
        overlap_end_sec = min(float(shot["endSec"]), event_end_sec)
        if overlap_end_sec - overlap_start_sec <= epsilon_sec:
            continue

        overlapping_group_indexes = [
            group_index
            for group_index in source_group_indexes
            if _ranges_overlap(
                overlap_start_sec,
                overlap_end_sec,
                float(groups_by_index[group_index]["startSec"]),
                float(groups_by_index[group_index]["endSec"]),
                epsilon_sec,
            )
        ]
        if not overlapping_group_indexes:
            overlapping_group_indexes = list(source_group_indexes)

        roles = sorted(
            {
                str(groups_by_index[group_index].get("peakRole", "unknown"))
                for group_index in overlapping_group_indexes
            }
        )
        highlight_score = max(
            float(groups_by_index[group_index].get("highlightScore", 0.0))
            for group_index in overlapping_group_indexes
        )
        peak_times_sec = sorted(
            {
                round(float(peak_time), 3)
                for group_index in overlapping_group_indexes
                for peak_time in groups_by_index[group_index].get("peakTimesSec", [])
                if overlap_start_sec <= float(peak_time) <= overlap_end_sec
            }
        )
        decorated.append(
            {
                "index": int(shot["index"]),
                "startSec": round(overlap_start_sec, 3),
                "endSec": round(overlap_end_sec, 3),
                "durationSec": round(overlap_end_sec - overlap_start_sec, 3),
                "sourceGroupIndexes": overlapping_group_indexes,
                "sourceShotIndexes": [int(shot["index"])],
                "roles": roles,
                "highlightScore": round(highlight_score, 3),
                "peakTimesSec": peak_times_sec,
                "hasPeak": bool(peak_times_sec),
            }
        )

    return decorated


def _resolve_peak_anchor_index(event_shots: list[dict[str, Any]]) -> int:
    scored_candidates = [
        (
            _score_peak_candidate(shot),
            index,
        )
        for index, shot in enumerate(event_shots)
    ]
    scored_candidates.sort(key=lambda item: (item[0], -item[1]), reverse=True)
    return int(scored_candidates[0][1])


def _score_peak_candidate(shot: dict[str, Any]) -> float:
    score = float(shot["highlightScore"])
    if bool(shot["hasPeak"]):
        score += 1.0
    roles = set(shot["roles"])
    if roles.intersection({"conflict", "payoff"}):
        score += 0.2
    if "transition" in roles:
        score -= 0.15
    return round(score, 4)


def _expand_peak_cluster(
    event_shots: list[dict[str, Any]],
    anchor_index: int,
    config: FunctionalSegmentConfig,
) -> tuple[int, int]:
    start_index = anchor_index
    end_index = anchor_index

    while start_index > 0 and bool(event_shots[start_index - 1]["hasPeak"]):
        if not _shares_any_group_indexes(
            event_shots[start_index - 1]["sourceGroupIndexes"],
            event_shots[start_index]["sourceGroupIndexes"],
        ):
            break
        start_index -= 1

    while end_index < len(event_shots) - 1 and bool(event_shots[end_index + 1]["hasPeak"]):
        if not _shares_any_group_indexes(
            event_shots[end_index + 1]["sourceGroupIndexes"],
            event_shots[end_index]["sourceGroupIndexes"],
        ):
            break
        end_index += 1

    return start_index, end_index


def _expand_context_start(
    event_shots: list[dict[str, Any]],
    context_start_index: int,
    context_limit: int,
    peak_group_indexes: list[int],
    config: FunctionalSegmentConfig,
) -> int:
    build_start_index = context_start_index
    used_context = 0
    while build_start_index > 0 and used_context < context_limit:
        candidate = event_shots[build_start_index - 1]
        neighbor = event_shots[build_start_index]
        if not _can_extend_context(candidate, neighbor, peak_group_indexes, config):
            break
        build_start_index -= 1
        used_context += 1
    return build_start_index


def _expand_context_end(
    event_shots: list[dict[str, Any]],
    context_end_index: int,
    context_limit: int,
    peak_group_indexes: list[int],
    config: FunctionalSegmentConfig,
) -> int:
    result_end_index = context_end_index
    used_context = 0
    while result_end_index < len(event_shots) - 1 and used_context < context_limit:
        candidate = event_shots[result_end_index + 1]
        neighbor = event_shots[result_end_index]
        if not _can_extend_context(candidate, neighbor, peak_group_indexes, config):
            break
        result_end_index += 1
        used_context += 1
    return result_end_index


def _can_extend_context(
    candidate: dict[str, Any],
    neighbor: dict[str, Any],
    peak_group_indexes: list[int],
    config: FunctionalSegmentConfig,
) -> bool:
    if _is_weak_transition(candidate, config):
        return False
    if float(candidate["highlightScore"]) < config.min_context_score and not bool(candidate["hasPeak"]):
        return False
    if _shares_any_group_indexes(candidate["sourceGroupIndexes"], neighbor["sourceGroupIndexes"]):
        return True
    return _shares_any_group_indexes(candidate["sourceGroupIndexes"], peak_group_indexes)


def _is_peak_like(
    shot: dict[str, Any],
    config: FunctionalSegmentConfig,
) -> bool:
    if bool(shot["hasPeak"]):
        return True
    roles = set(shot["roles"])
    return (
        float(shot["highlightScore"]) >= config.min_peak_score
        and bool(roles.intersection({"conflict", "payoff"}))
    )


def _should_emit_transition_only(
    event_shots: list[dict[str, Any]],
    anchor_index: int,
    config: FunctionalSegmentConfig,
) -> bool:
    if any(bool(shot["hasPeak"]) for shot in event_shots):
        return False

    anchor_shot = event_shots[anchor_index]
    if _is_weak_transition(anchor_shot, config):
        return True

    return float(anchor_shot["highlightScore"]) < config.min_peak_score


def _is_weak_transition(
    shot: dict[str, Any],
    config: FunctionalSegmentConfig,
) -> bool:
    roles = set(shot["roles"])
    return "transition" in roles and float(shot["highlightScore"]) < config.weak_transition_score


def _append_segment(
    segments: list[dict[str, Any]],
    event_index: int,
    segment_type: str,
    reason: str,
    event_shots: list[dict[str, Any]],
    start_index: int,
    end_index: int,
    selected: bool,
) -> None:
    if start_index < 0 or end_index < start_index or end_index >= len(event_shots):
        return

    segment_shots = event_shots[start_index : end_index + 1]
    segments.append(
        {
            "index": len(segments) + 1,
            "eventIndex": event_index,
            "type": segment_type,
            "startSec": round(float(segment_shots[0]["startSec"]), 3),
            "endSec": round(float(segment_shots[-1]["endSec"]), 3),
            "durationSec": round(
                float(segment_shots[-1]["endSec"]) - float(segment_shots[0]["startSec"]),
                3,
            ),
            "score": round(max(float(item["highlightScore"]) for item in segment_shots), 3),
            "reason": reason,
            "selected": selected,
            "sourceShotIndexes": [int(item["index"]) for item in segment_shots],
            "sourceGroupIndexes": sorted(
                {
                    int(group_index)
                    for item in segment_shots
                    for group_index in item["sourceGroupIndexes"]
                }
            ),
        }
    )


def _build_summary(
    enriched_events: list[dict[str, Any]],
    functional_clips: list[dict[str, Any]],
) -> dict[str, Any]:
    type_counts = {"build": 0, "peak": 0, "result": 0, "transition": 0}
    for event in enriched_events:
        for segment in event.get("functionalSegments", []):
            segment_type = str(segment.get("type", ""))
            if segment_type in type_counts:
                type_counts[segment_type] += 1

    return {
        "functionalEventCount": len(enriched_events),
        "functionalClipCount": len(functional_clips),
        "buildSegmentCount": type_counts["build"],
        "peakSegmentCount": type_counts["peak"],
        "resultSegmentCount": type_counts["result"],
        "transitionSegmentCount": type_counts["transition"],
    }


def _shares_any_group_indexes(left_group_indexes: list[int], right_group_indexes: list[int]) -> bool:
    return bool(set(left_group_indexes).intersection(right_group_indexes))


def _ranges_overlap(
    start_a: float,
    end_a: float,
    start_b: float,
    end_b: float,
    epsilon_sec: float,
) -> bool:
    return min(end_a, end_b) - max(start_a, start_b) > epsilon_sec
