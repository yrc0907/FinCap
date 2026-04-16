from __future__ import annotations

import base64
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2

from .vlm_openai_client import call_openai_compatible_vision

ALLOWED_ROLES = {"build", "peak", "result", "transition", "neutral"}


@dataclass(frozen=True)
class ShotLevelVlmSegmentConfig:
    keyframes_per_shot: int = 2
    max_build_shots: int = 2
    max_result_shots: int = 2
    min_continuity_confidence: float = 0.55
    epsilon_sec: float = 0.001


def extract_shot_level_vlm_segments(
    video_path: Path,
    events: list[dict[str, Any]],
    groups: list[dict[str, Any]],
    shots: list[dict[str, Any]],
    vlm_config: dict[str, str],
    config: ShotLevelVlmSegmentConfig | None = None,
) -> dict[str, Any]:
    active_config = config or ShotLevelVlmSegmentConfig()
    ordered_events = sorted(events, key=lambda item: int(item["index"]))
    ordered_groups = sorted(groups, key=lambda item: int(item["index"]))
    ordered_shots = sorted(shots, key=lambda item: float(item["startSec"]))
    groups_by_index = {int(group["index"]): group for group in ordered_groups}

    enriched_events: list[dict[str, Any]] = []
    functional_clips: list[dict[str, Any]] = []
    peak_clips: list[dict[str, Any]] = []
    for event in ordered_events:
        event_shots = _project_event_shots(
            event=event,
            groups_by_index=groups_by_index,
            ordered_shots=ordered_shots,
            epsilon_sec=active_config.epsilon_sec,
        )
        analyzed_event = _analyze_event(
            video_path=video_path,
            event=event,
            event_shots=event_shots,
            vlm_config=vlm_config,
            config=active_config,
        )
        enriched_events.append(analyzed_event)
        for clip in analyzed_event["functionalClips"]:
            clip_record = dict(clip)
            clip_record["index"] = len(functional_clips) + 1
            functional_clips.append(clip_record)
            if clip_record["type"] == "peak":
                peak_record = dict(clip_record)
                peak_record["index"] = len(peak_clips) + 1
                peak_clips.append(peak_record)

    return {
        "events": enriched_events,
        "functionalClips": functional_clips,
        "peakClips": peak_clips,
        "summary": {
            "eventCount": len(enriched_events),
            "functionalClipCount": len(functional_clips),
            "peakClipCount": len(peak_clips),
            "buildClipCount": sum(1 for clip in functional_clips if clip["type"] == "build"),
            "resultClipCount": sum(1 for clip in functional_clips if clip["type"] == "result"),
        },
    }


def extract_shot_keyframes(
    video_path: Path,
    shot: dict[str, Any],
    keyframes_per_shot: int,
) -> list[dict[str, Any]]:
    start_sec = float(shot["startSec"])
    end_sec = float(shot["endSec"])
    duration_sec = max(0.0, end_sec - start_sec)
    if duration_sec <= 0.0:
        return []

    if keyframes_per_shot <= 1:
        sample_times = [start_sec + duration_sec * 0.5]
    else:
        sample_times = [
            start_sec + duration_sec * ((index + 1) / (keyframes_per_shot + 1))
            for index in range(keyframes_per_shot)
        ]

    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError(f"Unable to open video file for shot keyframes: {video_path}")

    frames: list[dict[str, Any]] = []
    try:
        for time_sec in sample_times:
            capture.set(cv2.CAP_PROP_POS_MSEC, max(0.0, time_sec) * 1000.0)
            success, frame = capture.read()
            if not success or frame is None:
                continue
            resized_frame = _resize_frame(frame)
            encoded = cv2.imencode(".jpg", resized_frame)
            if not encoded[0]:
                continue
            frames.append(
                {
                    "timeSec": round(float(time_sec), 3),
                    "jpegBase64": base64.b64encode(encoded[1].tobytes()).decode("utf-8"),
                }
            )
    finally:
        capture.release()

    return frames


def _analyze_event(
    video_path: Path,
    event: dict[str, Any],
    event_shots: list[dict[str, Any]],
    vlm_config: dict[str, str],
    config: ShotLevelVlmSegmentConfig,
) -> dict[str, Any]:
    if not event_shots:
        enriched = dict(event)
        enriched["mainPeakShotIndex"] = None
        enriched["functionalSegments"] = []
        enriched["functionalClips"] = []
        return enriched

    peak_analysis = _run_peak_selection(
        video_path=video_path,
        event=event,
        event_shots=event_shots,
        vlm_config=vlm_config,
        config=config,
    )
    main_peak_shot_index = peak_analysis["mainPeakShotIndex"]
    if main_peak_shot_index is None:
        segments = _build_transition_only_segments(event, event_shots)
        enriched = dict(event)
        enriched["mainPeakShotIndex"] = None
        enriched["peakAnalysis"] = peak_analysis
        enriched["functionalSegments"] = segments
        enriched["functionalClips"] = []
        return enriched

    peak_position = _find_shot_position(event_shots, main_peak_shot_index)
    left_position = peak_position
    right_position = peak_position
    used_build = 0
    used_result = 0

    while left_position > 0 and used_build < config.max_build_shots:
        candidate_position = left_position - 1
        continuity = _run_continuity_check(
            video_path=video_path,
            anchor_shot=event_shots[left_position],
            candidate_shot=event_shots[candidate_position],
            direction="left",
            vlm_config=vlm_config,
            config=config,
        )
        if not continuity["sameSequence"]:
            break
        if continuity["role"] not in {"build", "peak"}:
            break
        if continuity["confidence"] < config.min_continuity_confidence:
            break
        left_position = candidate_position
        used_build += 1

    while right_position < len(event_shots) - 1 and used_result < config.max_result_shots:
        candidate_position = right_position + 1
        continuity = _run_continuity_check(
            video_path=video_path,
            anchor_shot=event_shots[right_position],
            candidate_shot=event_shots[candidate_position],
            direction="right",
            vlm_config=vlm_config,
            config=config,
        )
        if not continuity["sameSequence"]:
            break
        if continuity["role"] not in {"result", "peak"}:
            break
        if continuity["confidence"] < config.min_continuity_confidence:
            break
        right_position = candidate_position
        used_result += 1

    segments = _build_segments(
        event=event,
        event_shots=event_shots,
        left_position=left_position,
        peak_position=peak_position,
        right_position=right_position,
    )
    functional_clips = [
        {
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
        for segment in segments
        if segment["selected"]
    ]
    enriched = dict(event)
    enriched["mainPeakShotIndex"] = main_peak_shot_index
    enriched["peakAnalysis"] = peak_analysis
    enriched["functionalSegments"] = segments
    enriched["functionalClips"] = functional_clips
    return enriched


def _run_peak_selection(
    video_path: Path,
    event: dict[str, Any],
    event_shots: list[dict[str, Any]],
    vlm_config: dict[str, str],
    config: ShotLevelVlmSegmentConfig,
) -> dict[str, Any]:
    images: list[dict[str, Any]] = []
    shot_lines: list[str] = []
    for shot in event_shots:
        keyframes = extract_shot_keyframes(video_path, shot, config.keyframes_per_shot)
        shot["previewFrames"] = keyframes
        images.extend(keyframes)
        shot_lines.append(
            f"- shot {int(shot['index'])}: {float(shot['startSec']):.3f}s to {float(shot['endSec']):.3f}s"
        )
    response = call_openai_compatible_vision(
        vlm_config=vlm_config,
        prompt=_build_peak_selection_prompt(event, shot_lines, images),
        images=images,
    )
    return _normalize_peak_selection(response, event_shots)


def _run_continuity_check(
    video_path: Path,
    anchor_shot: dict[str, Any],
    candidate_shot: dict[str, Any],
    direction: str,
    vlm_config: dict[str, str],
    config: ShotLevelVlmSegmentConfig,
) -> dict[str, Any]:
    anchor_frames = anchor_shot.get("previewFrames") or extract_shot_keyframes(
        video_path, anchor_shot, config.keyframes_per_shot
    )
    candidate_frames = candidate_shot.get("previewFrames") or extract_shot_keyframes(
        video_path, candidate_shot, config.keyframes_per_shot
    )
    images = [*anchor_frames, *candidate_frames]
    response = call_openai_compatible_vision(
        vlm_config=vlm_config,
        prompt=_build_continuity_prompt(anchor_shot, candidate_shot, direction, anchor_frames, candidate_frames),
        images=images,
    )
    return _normalize_continuity_response(response)


def _build_peak_selection_prompt(
    event: dict[str, Any],
    shot_lines: list[str],
    images: list[dict[str, Any]],
) -> str:
    frame_lines = "\n".join(
        f"- frame {index + 1}: {float(image['timeSec']):.3f}s"
        for index, image in enumerate(images)
    ) or "- no frames"
    shot_block = "\n".join(shot_lines)
    return (
        "You are analyzing strict shots inside one corrected story event.\n"
        "Pick exactly one main peak shot if this event contains a clear climax.\n"
        "Return JSON only. Do not add markdown.\n"
        "Required keys: main_peak_shot_index, peak_confidence, peak_reason, shot_roles.\n"
        "shot_roles must be a list of objects with keys: shot_index, role, score.\n"
        "role must be one of: build, peak, result, transition, neutral.\n"
        "main_peak_shot_index must be one of the listed shot indexes or null.\n"
        f"Event range: {float(event['startSec']):.3f}s to {float(event['endSec']):.3f}s.\n"
        f"Shots:\n{shot_block}\n"
        f"Frames in order:\n{frame_lines}"
    )


def _build_continuity_prompt(
    anchor_shot: dict[str, Any],
    candidate_shot: dict[str, Any],
    direction: str,
    anchor_frames: list[dict[str, Any]],
    candidate_frames: list[dict[str, Any]],
) -> str:
    anchor_range = f"{float(anchor_shot['startSec']):.3f}s to {float(anchor_shot['endSec']):.3f}s"
    candidate_range = f"{float(candidate_shot['startSec']):.3f}s to {float(candidate_shot['endSec']):.3f}s"
    frame_lines = []
    for index, frame in enumerate(anchor_frames, start=1):
        frame_lines.append(f"- anchor frame {index}: {float(frame['timeSec']):.3f}s")
    for index, frame in enumerate(candidate_frames, start=1):
        frame_lines.append(f"- candidate frame {index}: {float(frame['timeSec']):.3f}s")
    return (
        "You are checking whether two adjacent strict shots belong to the same climax sequence.\n"
        "Return JSON only. Do not add markdown.\n"
        "Required keys: same_sequence, role, confidence, reason.\n"
        "role must be one of: build, peak, result, transition, neutral.\n"
        f"Direction: {direction}.\n"
        f"Anchor shot {int(anchor_shot['index'])}: {anchor_range}.\n"
        f"Candidate shot {int(candidate_shot['index'])}: {candidate_range}.\n"
        f"Frames:\n{chr(10).join(frame_lines)}"
    )


def _normalize_peak_selection(
    raw: dict[str, Any],
    event_shots: list[dict[str, Any]],
) -> dict[str, Any]:
    valid_indexes = {int(shot["index"]) for shot in event_shots}
    main_peak_value = raw.get("main_peak_shot_index")
    try:
        main_peak_shot_index = int(main_peak_value) if main_peak_value is not None else None
    except (TypeError, ValueError):
        main_peak_shot_index = None
    if main_peak_shot_index not in valid_indexes:
        main_peak_shot_index = None

    normalized_roles = []
    for item in raw.get("shot_roles", []):
        try:
            shot_index = int(item.get("shot_index"))
        except (TypeError, ValueError):
            continue
        if shot_index not in valid_indexes:
            continue
        role = str(item.get("role", "neutral")).strip().lower()
        if role not in ALLOWED_ROLES:
            role = "neutral"
        try:
            score = float(item.get("score", 0.0))
        except (TypeError, ValueError):
            score = 0.0
        normalized_roles.append({"shotIndex": shot_index, "role": role, "score": round(score, 3)})

    if main_peak_shot_index is None and normalized_roles:
        best_role = max(
            normalized_roles,
            key=lambda item: (item["role"] == "peak", item["score"], -item["shotIndex"]),
        )
        if best_role["role"] == "peak":
            main_peak_shot_index = int(best_role["shotIndex"])

    try:
        peak_confidence = float(raw.get("peak_confidence", 0.0))
    except (TypeError, ValueError):
        peak_confidence = 0.0
    return {
        "mainPeakShotIndex": main_peak_shot_index,
        "peakConfidence": round(peak_confidence, 3),
        "peakReason": str(raw.get("peak_reason", "")).strip(),
        "shotRoles": normalized_roles,
    }


def _normalize_continuity_response(raw: dict[str, Any]) -> dict[str, Any]:
    role = str(raw.get("role", "neutral")).strip().lower()
    if role not in ALLOWED_ROLES:
        role = "neutral"
    try:
        confidence = float(raw.get("confidence", 0.0))
    except (TypeError, ValueError):
        confidence = 0.0
    return {
        "sameSequence": bool(raw.get("same_sequence", False)),
        "role": role,
        "confidence": round(confidence, 3),
        "reason": str(raw.get("reason", "")).strip(),
    }


def _build_segments(
    event: dict[str, Any],
    event_shots: list[dict[str, Any]],
    left_position: int,
    peak_position: int,
    right_position: int,
) -> list[dict[str, Any]]:
    segments: list[dict[str, Any]] = []
    _append_segment(segments, event, event_shots, 0, left_position - 1, "transition", False)
    _append_segment(segments, event, event_shots, left_position, peak_position - 1, "build", True)
    _append_segment(segments, event, event_shots, peak_position, peak_position, "peak", True)
    _append_segment(segments, event, event_shots, peak_position + 1, right_position, "result", True)
    _append_segment(segments, event, event_shots, right_position + 1, len(event_shots) - 1, "transition", False)
    return segments


def _build_transition_only_segments(
    event: dict[str, Any],
    event_shots: list[dict[str, Any]],
) -> list[dict[str, Any]]:
    segments: list[dict[str, Any]] = []
    _append_segment(segments, event, event_shots, 0, len(event_shots) - 1, "transition", False)
    return segments


def _append_segment(
    segments: list[dict[str, Any]],
    event: dict[str, Any],
    event_shots: list[dict[str, Any]],
    start_position: int,
    end_position: int,
    segment_type: str,
    selected: bool,
) -> None:
    if start_position < 0 or end_position < start_position or end_position >= len(event_shots):
        return
    segment_shots = event_shots[start_position : end_position + 1]
    segments.append(
        {
            "index": len(segments) + 1,
            "eventIndex": int(event["index"]),
            "type": segment_type,
            "startSec": round(float(segment_shots[0]["startSec"]), 3),
            "endSec": round(float(segment_shots[-1]["endSec"]), 3),
            "durationSec": round(float(segment_shots[-1]["endSec"]) - float(segment_shots[0]["startSec"]), 3),
            "score": round(max(float(shot["highlightScore"]) for shot in segment_shots), 3),
            "reason": segment_type,
            "selected": selected,
            "sourceShotIndexes": [int(shot["index"]) for shot in segment_shots],
            "sourceGroupIndexes": sorted(
                {
                    int(group_index)
                    for shot in segment_shots
                    for group_index in shot["sourceGroupIndexes"]
                }
            ),
        }
    )


def _project_event_shots(
    event: dict[str, Any],
    groups_by_index: dict[int, dict[str, Any]],
    ordered_shots: list[dict[str, Any]],
    epsilon_sec: float,
) -> list[dict[str, Any]]:
    event_start_sec = float(event["startSec"])
    event_end_sec = float(event["endSec"])
    source_group_indexes = [int(value) for value in event.get("sourceGroupIndexes", [])]
    projected: list[dict[str, Any]] = []
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
        peak_times_sec = sorted(
            {
                round(float(peak_time), 3)
                for group_index in overlapping_group_indexes
                for peak_time in groups_by_index[group_index].get("peakTimesSec", [])
                if overlap_start_sec <= float(peak_time) <= overlap_end_sec
            }
        )
        projected.append(
            {
                "index": int(shot["index"]),
                "startSec": round(overlap_start_sec, 3),
                "endSec": round(overlap_end_sec, 3),
                "durationSec": round(overlap_end_sec - overlap_start_sec, 3),
                "sourceGroupIndexes": overlapping_group_indexes,
                "highlightScore": round(
                    max(float(groups_by_index[group_index].get("highlightScore", 0.0)) for group_index in overlapping_group_indexes),
                    3,
                ),
                "peakTimesSec": peak_times_sec,
                "previewFrames": [],
            }
        )
    return projected


def _find_shot_position(event_shots: list[dict[str, Any]], shot_index: int) -> int:
    for position, shot in enumerate(event_shots):
        if int(shot["index"]) == int(shot_index):
            return position
    raise RuntimeError(f"Shot index {shot_index} was not found in event shots.")


def _resize_frame(frame: Any) -> Any:
    height, width = frame.shape[:2]
    longest_edge = max(height, width)
    if longest_edge <= 960:
        return frame
    scale = 960.0 / float(longest_edge)
    target_size = (max(1, int(round(width * scale))), max(1, int(round(height * scale))))
    return cv2.resize(frame, target_size, interpolation=cv2.INTER_AREA)


def _ranges_overlap(
    start_a: float,
    end_a: float,
    start_b: float,
    end_b: float,
    epsilon_sec: float,
) -> bool:
    return min(end_a, end_b) - max(start_a, start_b) > epsilon_sec
