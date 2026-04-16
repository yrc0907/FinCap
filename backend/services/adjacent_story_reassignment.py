from __future__ import annotations

from typing import Any

from .vlm_openai_client import call_openai_compatible_json

LOG_START = "[Start] Adjacent story reassignment started"
LOG_PAIR = "[Process] Adjacent pair"
LOG_COMPLETE = "[Done] Adjacent story reassignment completed"


def analyze_adjacent_story_reassignment(
    groups: list[dict[str, Any]],
    llm_config: dict[str, str],
) -> dict[str, Any]:
    print(LOG_START)
    pairs = []
    for left_group, right_group in zip(groups, groups[1:]):
        response = call_openai_compatible_json(
            llm_config=llm_config,
            prompt=_build_prompt(left_group, right_group),
            max_tokens=320,
        )
        normalized = _normalize_pair(left_group, right_group, response)
        pairs.append(normalized)
        print(
            f"{LOG_PAIR}: left={normalized['leftGroupIndex']}, right={normalized['rightGroupIndex']}, "
            f"reassign={normalized['shouldReassignTail']}, from={normalized['reassignFromSec']}"
        )

    summary = {
        "pairCount": len(pairs),
        "reassignmentCount": sum(1 for pair in pairs if pair["shouldReassignTail"]),
    }
    print(LOG_COMPLETE)
    return {"pairs": pairs, "summary": summary}


def _build_prompt(left_group: dict[str, Any], right_group: dict[str, Any]) -> str:
    return (
        "You are judging only two adjacent story groups from one video.\n"
        "Use the VLM group results below. Do not request images. Do not compare non-adjacent groups.\n"
        "Decide whether the tail of the left group actually belongs to the right group.\n"
        "If yes, return the earliest timestamp in the left group where the right group's story begins.\n"
        "Return JSON only. Do not add markdown. Do not add extra keys.\n"
        "Required JSON keys: should_reassign_tail, reassign_from_sec, source_group_index, "
        "target_group_index, confidence, reason.\n"
        "If there is no reassignment, set should_reassign_tail=false, reassign_from_sec=null, "
        "source_group_index=null, target_group_index=null.\n"
        "Confidence must be 0-1.\n"
        f"Left group:\n{_format_group(left_group)}\n"
        f"Right group:\n{_format_group(right_group)}"
    )


def _format_group(group: dict[str, Any]) -> str:
    return (
        f"- index: {int(group['index'])}\n"
        f"- range: {float(group['startSec']):.3f}s to {float(group['endSec']):.3f}s\n"
        f"- shots: {', '.join(str(value) for value in group.get('shotIndexes', []))}\n"
        f"- continuous: {bool(group.get('isContinuousStory', False))}\n"
        f"- highlight_score: {float(group.get('highlightScore', 0.0)):.3f}\n"
        f"- peak_times: {', '.join(str(value) for value in group.get('peakTimesSec', [])) or 'none'}\n"
        f"- peak_role: {str(group.get('peakRole', 'unknown'))}\n"
        f"- reason: {str(group.get('reason', '')).strip()}"
    )


def _normalize_pair(
    left_group: dict[str, Any],
    right_group: dict[str, Any],
    raw: dict[str, Any],
) -> dict[str, Any]:
    left_start = float(left_group["startSec"])
    left_end = float(left_group["endSec"])
    should_reassign = bool(raw.get("should_reassign_tail", False))
    reassign_from = _safe_optional_float(raw.get("reassign_from_sec"))
    if reassign_from is None or reassign_from < left_start or reassign_from > left_end:
        should_reassign = False
        reassign_from = None

    confidence = max(0.0, min(1.0, float(raw.get("confidence", 0.0))))
    return {
        "leftGroupIndex": int(left_group["index"]),
        "rightGroupIndex": int(right_group["index"]),
        "shouldReassignTail": should_reassign,
        "reassignFromSec": None if reassign_from is None else round(reassign_from, 3),
        "sourceGroupIndex": int(left_group["index"]) if should_reassign else None,
        "targetGroupIndex": int(right_group["index"]) if should_reassign else None,
        "confidence": round(confidence, 3),
        "reason": str(raw.get("reason", "")).strip(),
    }


def _safe_optional_float(value: Any) -> float | None:
    if value is None:
        return None
    try:
        return float(value)
    except (TypeError, ValueError):
        return None
