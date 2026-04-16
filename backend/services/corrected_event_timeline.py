from __future__ import annotations

from dataclasses import dataclass
from typing import Any

from .event_functional_segments import extract_event_functional_segments
from .frame_aligned_clip_export import attach_frame_alignment_to_selected_clips

LOG_START = "[Start] Corrected event timeline started"
LOG_APPLIED = "[Process] Applied corrected boundaries"
LOG_COMPLETE = "[Done] Corrected event timeline completed"


@dataclass(frozen=True)
class CorrectedEventConfig:
    epsilon_sec: float = 0.001


def generate_corrected_event_timeline(
    groups: list[dict[str, Any]],
    adjacent_pairs: list[dict[str, Any]],
    shots: list[dict[str, Any]] | None = None,
    fps: float | None = None,
    video_duration_sec: float | None = None,
    frame_count: int | None = None,
    config: CorrectedEventConfig | None = None,
) -> dict[str, Any]:
    active_config = config or CorrectedEventConfig()
    print(LOG_START)

    ordered_groups = sorted(groups, key=lambda item: int(item["index"]))
    ordered_shots = sorted((shots or []), key=lambda item: float(item["startSec"]))
    shot_boundaries_sec = _collect_shot_boundaries(ordered_shots)
    corrected_ranges = {
        int(group["index"]): {
            "originalStartSec": float(group["startSec"]),
            "originalEndSec": float(group["endSec"]),
            "startSec": float(group["startSec"]),
            "endSec": float(group["endSec"]),
            "sourceGroupIndexes": [int(group["index"])],
            "reasons": [],
        }
        for group in ordered_groups
    }

    applied_pair_count = 0
    for pair in sorted(adjacent_pairs, key=lambda item: int(item["leftGroupIndex"])):
        applied = _apply_adjacent_pair(
            corrected_ranges=corrected_ranges,
            pair=pair,
            epsilon_sec=active_config.epsilon_sec,
        )
        if applied:
            applied_pair_count += 1

    print(f"{LOG_APPLIED}: {applied_pair_count}")
    events, dropped_event_count = _build_events(
        corrected_ranges,
        ordered_groups,
        ordered_shots,
        shot_boundaries_sec,
        active_config.epsilon_sec,
    )
    span_counts = _count_span_labels(events)
    selected_clips = _build_selected_clips(events)
    functional_result = extract_event_functional_segments(
        events=events,
        groups=ordered_groups,
        shots=ordered_shots,
    )
    events = functional_result["events"]
    functional_clips = functional_result["functionalClips"]
    if fps is not None and video_duration_sec is not None:
        selected_clips = attach_frame_alignment_to_selected_clips(
            selected_clips=selected_clips,
            fps=float(fps),
            video_duration_sec=float(video_duration_sec),
            frame_count=frame_count,
        )
        functional_clips = attach_frame_alignment_to_selected_clips(
            selected_clips=functional_clips,
            fps=float(fps),
            video_duration_sec=float(video_duration_sec),
            frame_count=frame_count,
        )
    summary = {
        "eventCount": len(events),
        "changedEventCount": sum(1 for event in events if event["changed"]),
        "appliedPairCount": applied_pair_count,
        "droppedEventCount": dropped_event_count,
        "keepSpanCount": span_counts["keep"],
        "bridgeSpanCount": span_counts["bridge"],
        "dropSpanCount": span_counts["drop"],
        "selectedClipCount": len(selected_clips),
        "selectedKeepClipCount": sum(1 for clip in selected_clips if clip["label"] == "keep"),
        "selectedBridgeClipCount": sum(1 for clip in selected_clips if clip["label"] == "bridge"),
        "functionalClipCount": len(functional_clips),
        "functionalBuildClipCount": sum(1 for clip in functional_clips if clip["type"] == "build"),
        "functionalPeakClipCount": sum(1 for clip in functional_clips if clip["type"] == "peak"),
        "functionalResultClipCount": sum(1 for clip in functional_clips if clip["type"] == "result"),
    }
    print(LOG_COMPLETE)
    return {
        "inputGroupCount": len(ordered_groups),
        "inputPairCount": len(adjacent_pairs),
        "events": events,
        "selectedClips": selected_clips,
        "functionalClips": functional_clips,
        "summary": summary,
    }


def _apply_adjacent_pair(
    corrected_ranges: dict[int, dict[str, Any]],
    pair: dict[str, Any],
    epsilon_sec: float,
) -> bool:
    if not bool(pair.get("shouldReassignTail", False)):
        return False

    left_index = int(pair["leftGroupIndex"])
    right_index = int(pair["rightGroupIndex"])
    reassign_from = _safe_float(pair.get("reassignFromSec"))
    if reassign_from is None or left_index not in corrected_ranges or right_index not in corrected_ranges:
        return False

    left_range = corrected_ranges[left_index]
    right_range = corrected_ranges[right_index]
    changed = False

    if not (left_range["startSec"] + epsilon_sec < reassign_from <= left_range["endSec"] + epsilon_sec):
        return False

    if reassign_from < left_range["endSec"] - epsilon_sec:
        left_range["endSec"] = reassign_from
        left_range["reasons"].append(f"tail-moved-to-{right_index}")
        changed = True

    if reassign_from < right_range["startSec"] - epsilon_sec:
        right_range["startSec"] = reassign_from
        right_range["sourceGroupIndexes"] = sorted(
            set(right_range["sourceGroupIndexes"] + [left_index])
        )
        right_range["reasons"].append(f"tail-absorbed-from-{left_index}")
        changed = True

    return changed


def _build_events(
    corrected_ranges: dict[int, dict[str, Any]],
    ordered_groups: list[dict[str, Any]],
    ordered_shots: list[dict[str, Any]],
    shot_boundaries_sec: list[float],
    epsilon_sec: float,
) -> tuple[list[dict[str, Any]], int]:
    events: list[dict[str, Any]] = []
    dropped_event_count = 0
    groups_by_index = {int(group["index"]): group for group in ordered_groups}

    for group in ordered_groups:
        index = int(group["index"])
        corrected_range = corrected_ranges[index]
        snapped_start_sec = _snap_to_nearest_shot_boundary(
            float(corrected_range["startSec"]),
            shot_boundaries_sec,
        )
        snapped_end_sec = _snap_to_nearest_shot_boundary(
            float(corrected_range["endSec"]),
            shot_boundaries_sec,
        )
        start_sec = round(snapped_start_sec, 3)
        end_sec = round(max(snapped_end_sec, snapped_start_sec), 3)
        duration_sec = round(end_sec - start_sec, 3)
        if duration_sec <= epsilon_sec:
            dropped_event_count += 1
            continue

        original_start_sec = round(float(corrected_range["originalStartSec"]), 3)
        original_end_sec = round(float(corrected_range["originalEndSec"]), 3)
        changed = (
            abs(start_sec - original_start_sec) > epsilon_sec
            or abs(end_sec - original_end_sec) > epsilon_sec
        )
        events.append(
            {
                "index": index,
                "originalStartSec": original_start_sec,
                "originalEndSec": original_end_sec,
                "startSec": start_sec,
                "endSec": end_sec,
                "durationSec": duration_sec,
                "sourceGroupIndexes": corrected_range["sourceGroupIndexes"],
                "changed": changed,
                "reasons": corrected_range["reasons"],
                "narrationSpans": _build_narration_spans(
                    event_start_sec=start_sec,
                    event_end_sec=end_sec,
                    source_group_indexes=corrected_range["sourceGroupIndexes"],
                    ordered_shots=ordered_shots,
                    groups_by_index=groups_by_index,
                    epsilon_sec=epsilon_sec,
                ),
            }
        )

    return events, dropped_event_count


def _build_narration_spans(
    event_start_sec: float,
    event_end_sec: float,
    source_group_indexes: list[int],
    ordered_shots: list[dict[str, Any]],
    groups_by_index: dict[int, dict[str, Any]],
    epsilon_sec: float,
) -> list[dict[str, Any]]:
    raw_spans: list[dict[str, Any]] = []
    for shot in ordered_shots:
        overlap_start = max(float(shot["startSec"]), event_start_sec)
        overlap_end = min(float(shot["endSec"]), event_end_sec)
        if overlap_end - overlap_start <= epsilon_sec:
            continue

        overlapping_groups = [
            group_index
            for group_index in source_group_indexes
            if _ranges_overlap(
                overlap_start,
                overlap_end,
                float(groups_by_index[group_index]["startSec"]),
                float(groups_by_index[group_index]["endSec"]),
                epsilon_sec,
            )
        ]
        if not overlapping_groups:
            overlapping_groups = list(source_group_indexes)

        roles = {
            str(groups_by_index[group_index].get("peakRole", "unknown"))
            for group_index in overlapping_groups
        }
        highlight_score = max(
            float(groups_by_index[group_index].get("highlightScore", 0.0))
            for group_index in overlapping_groups
        )
        has_peak = any(
            overlap_start <= float(peak_time) <= overlap_end
            for group_index in overlapping_groups
            for peak_time in groups_by_index[group_index].get("peakTimesSec", [])
        )
        raw_spans.append(
            {
                "startSec": round(overlap_start, 3),
                "endSec": round(overlap_end, 3),
                "durationSec": round(overlap_end - overlap_start, 3),
                "sourceShotIndexes": [int(shot["index"])],
                "sourceGroupIndexes": sorted(set(overlapping_groups)),
                "roles": sorted(roles),
                "highlightScore": round(highlight_score, 3),
                "hasPeak": has_peak,
            }
        )

    labeled_spans = [
        _label_span(
            span=span,
            is_first=index == 0,
            is_last=index == len(raw_spans) - 1,
        )
        for index, span in enumerate(raw_spans)
    ]
    return _merge_adjacent_spans(labeled_spans, epsilon_sec)


def _label_span(
    span: dict[str, Any],
    is_first: bool,
    is_last: bool,
) -> dict[str, Any]:
    roles = set(span["roles"])
    highlight_score = float(span["highlightScore"])
    if bool(span["hasPeak"]):
        label = "keep"
        reason = "peak-overlap"
    elif is_first or is_last:
        label = "bridge"
        reason = "event-edge"
    elif roles.intersection({"conflict", "payoff"}) and highlight_score >= 0.6:
        label = "keep"
        reason = "high-value-role"
    elif roles.intersection({"setup", "buildup", "ending", "character-focus"}):
        label = "bridge"
        reason = "support-role"
    elif "transition" in roles and highlight_score < 0.4:
        label = "drop"
        reason = "low-transition"
    elif highlight_score >= 0.45:
        label = "bridge"
        reason = "mid-value-support"
    else:
        label = "drop"
        reason = "low-value-span"

    return {
        "startSec": span["startSec"],
        "endSec": span["endSec"],
        "durationSec": span["durationSec"],
        "label": label,
        "reason": reason,
        "score": round(highlight_score, 3),
        "sourceShotIndexes": span["sourceShotIndexes"],
        "sourceGroupIndexes": span["sourceGroupIndexes"],
    }


def _merge_adjacent_spans(
    spans: list[dict[str, Any]],
    epsilon_sec: float,
) -> list[dict[str, Any]]:
    if not spans:
        return []

    merged: list[dict[str, Any]] = [dict(spans[0])]
    for span in spans[1:]:
        current = merged[-1]
        if (
            span["label"] == current["label"]
            and span["startSec"] <= current["endSec"] + epsilon_sec
        ):
            current["endSec"] = span["endSec"]
            current["durationSec"] = round(float(current["endSec"]) - float(current["startSec"]), 3)
            current["score"] = round(max(float(current["score"]), float(span["score"])), 3)
            current["sourceShotIndexes"] = sorted(
                set(current["sourceShotIndexes"] + span["sourceShotIndexes"])
            )
            current["sourceGroupIndexes"] = sorted(
                set(current["sourceGroupIndexes"] + span["sourceGroupIndexes"])
            )
            current["reason"] = current["reason"] if current["reason"] == span["reason"] else "merged-same-label"
            continue

        merged.append(dict(span))

    for index, span in enumerate(merged, start=1):
        span["index"] = index
    return merged


def _count_span_labels(events: list[dict[str, Any]]) -> dict[str, int]:
    counts = {"keep": 0, "bridge": 0, "drop": 0}
    for event in events:
        for span in event.get("narrationSpans", []):
            label = str(span.get("label", ""))
            if label in counts:
                counts[label] += 1
    return counts


def _build_selected_clips(events: list[dict[str, Any]]) -> list[dict[str, Any]]:
    selected_clips: list[dict[str, Any]] = []
    for event in events:
        for span in event.get("narrationSpans", []):
            if span["label"] == "drop":
                continue
            selected_clips.append(
                {
                    "index": len(selected_clips) + 1,
                    "eventIndex": int(event["index"]),
                    "label": span["label"],
                    "startSec": span["startSec"],
                    "endSec": span["endSec"],
                    "durationSec": span["durationSec"],
                    "score": span["score"],
                    "reason": span["reason"],
                    "sourceShotIndexes": span["sourceShotIndexes"],
                    "sourceGroupIndexes": span["sourceGroupIndexes"],
                }
            )
    return selected_clips


def _ranges_overlap(
    start_a: float,
    end_a: float,
    start_b: float,
    end_b: float,
    epsilon_sec: float,
) -> bool:
    return min(end_a, end_b) - max(start_a, start_b) > epsilon_sec


def _safe_float(value: Any) -> float | None:
    if value is None:
        return None
    try:
        return float(value)
    except (TypeError, ValueError):
        return None


def _collect_shot_boundaries(ordered_shots: list[dict[str, Any]]) -> list[float]:
    if not ordered_shots:
        return []

    boundaries = {
        round(float(shot["startSec"]), 3)
        for shot in ordered_shots
    }
    boundaries.update(
        round(float(shot["endSec"]), 3)
        for shot in ordered_shots
    )
    return sorted(boundaries)


def _snap_to_nearest_shot_boundary(
    value_sec: float,
    shot_boundaries_sec: list[float],
) -> float:
    if not shot_boundaries_sec:
        return value_sec

    return min(
        shot_boundaries_sec,
        key=lambda boundary_sec: (abs(boundary_sec - value_sec), boundary_sec),
    )
