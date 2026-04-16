from __future__ import annotations

import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2

from .multimodal_semantic_context import (
    NormalizedSubtitleRegion,
    build_multimodal_prompt_header,
    compact_text_evidence,
    encode_vlm_frame_variants,
    format_multimodal_evidence_block,
    format_vlm_frame_lines,
    select_asr_text_for_window,
)
from .asr_transcription import transcribe_video_to_segments
from .ocr_text_extraction import extract_ocr_entries
from .text_evidence_resolution import resolve_text_evidence
from .vlm_openai_client import call_openai_compatible_vision

LOG_START = "[Start] VLM shot analysis started"
LOG_GROUP = "[Process] VLM group"
LOG_COMPLETE = "[Done] VLM shot analysis completed"
ALLOWED_PEAK_ROLES = {
    "setup",
    "buildup",
    "conflict",
    "payoff",
    "transition",
    "ending",
    "character-focus",
    "unknown",
}


@dataclass(frozen=True)
class VlmShotAnalysisConfig:
    group_size: int = 3
    keyframes_per_shot: int = 3
    highlight_threshold: float = 0.7
    enable_ocr: bool = True
    enable_auto_asr: bool = True
    auto_asr_model: str = "turbo"
    enable_subtitle_region: bool = False
    subtitle_region: NormalizedSubtitleRegion | None = None
    prompt_profile: str = "short-video"


def analyze_shot_sequence(
    video_path: Path,
    shots: list[dict[str, Any]],
    vlm_config: dict[str, str],
    config: VlmShotAnalysisConfig | None = None,
    asr_text: str | None = None,
    asr_segments: list[dict[str, Any]] | None = None,
    character_references: list[dict[str, Any]] | None = None,
) -> dict[str, Any]:
    active_config = config or VlmShotAnalysisConfig()
    print(LOG_START)
    normalized_asr_segments = list(asr_segments or [])
    if active_config.enable_auto_asr and not normalized_asr_segments:
        normalized_asr_segments = transcribe_video_to_segments(
            video_path=video_path,
            model_name=active_config.auto_asr_model,
        )
    prepared_character_references = _prepare_character_reference_images(character_references or [])

    groups = []
    for group_index, shot_group in enumerate(_chunk_shots(shots, active_config.group_size), start=1):
        images: list[dict[str, Any]] = []
        for shot in shot_group:
            images.extend(
                _extract_keyframes_for_shot(
                    video_path=video_path,
                    shot=shot,
                    keyframes_per_shot=active_config.keyframes_per_shot,
                    subtitle_region=active_config.subtitle_region
                    if active_config.enable_subtitle_region
                    else None,
                )
            )

        ocr_entries = (
            extract_ocr_entries(images)
            if active_config.enable_ocr and active_config.enable_subtitle_region
            else []
        )
        asr_lines = select_asr_text_for_window(
            normalized_asr_segments,
            start_sec=float(shot_group[0]["startSec"]),
            end_sec=float(shot_group[-1]["endSec"]),
        )
        if asr_text:
            asr_lines = compact_text_evidence([*asr_lines, asr_text])
        text_evidence = resolve_text_evidence(
            ocr_entries=ocr_entries,
            asr_lines=asr_lines,
        )

        response = call_openai_compatible_vision(
            vlm_config=vlm_config,
            prompt=_build_prompt(
                shot_group,
                images,
                include_subtitle_region=active_config.enable_subtitle_region,
                prompt_profile=active_config.prompt_profile,
                text_evidence_lines=text_evidence.primary_lines,
                text_evidence_source=text_evidence.source,
                text_evidence_conflict=text_evidence.conflict_detected,
                text_evidence_note=text_evidence.conservative_note,
                character_references=character_references or [],
            ),
            images=[*prepared_character_references, *images],
        )
        normalized = _normalize_group_result(
            group_index=group_index,
            shot_group=shot_group,
            raw=response,
            text_evidence_source=text_evidence.source,
            text_evidence_conflict=text_evidence.conflict_detected,
        )
        groups.append(normalized)
        print(
            f"{LOG_GROUP}: index={group_index}, shots={normalized['shotIndexes']}, "
            f"highlight={normalized['highlightScore']:.3f}, peaks={normalized['peakTimesSec']}"
        )

    summary = {
        "groupCount": len(groups),
        "highlightGroupCount": sum(
            1 for group in groups if float(group["highlightScore"]) >= active_config.highlight_threshold
        ),
    }
    print(LOG_COMPLETE)
    return {
        "groups": groups,
        "summary": summary,
        "config": {
            "group_size": active_config.group_size,
            "keyframes_per_shot": active_config.keyframes_per_shot,
            "highlight_threshold": active_config.highlight_threshold,
            "enable_ocr": active_config.enable_ocr,
            "enable_auto_asr": active_config.enable_auto_asr,
            "enable_subtitle_region": active_config.enable_subtitle_region,
            "prompt_profile": active_config.prompt_profile,
            "character_reference_count": len(prepared_character_references),
        },
    }


def _chunk_shots(shots: list[dict[str, Any]], group_size: int) -> list[list[dict[str, Any]]]:
    return [shots[index : index + group_size] for index in range(0, len(shots), group_size)]


def _build_prompt(
    shot_group: list[dict[str, Any]],
    images: list[dict[str, Any]],
    *,
    include_subtitle_region: bool,
    prompt_profile: str,
    text_evidence_lines: list[str] | None = None,
    text_evidence_source: str = "none",
    text_evidence_conflict: bool = False,
    text_evidence_note: str = "",
    character_references: list[dict[str, Any]] | None = None,
) -> str:
    shot_lines = "\n".join(
        f"- shot {int(shot['index'])}: {float(shot['startSec']):.3f}s to {float(shot['endSec']):.3f}s"
        for shot in shot_group
    )
    return _build_prompt_with_frames(
        shot_lines,
        images,
        include_subtitle_region=include_subtitle_region,
        prompt_profile=prompt_profile,
        text_evidence_lines=text_evidence_lines,
        text_evidence_source=text_evidence_source,
        text_evidence_conflict=text_evidence_conflict,
        text_evidence_note=text_evidence_note,
        character_references=character_references,
    )


def _build_prompt_with_frames(
    shot_lines: str,
    images: list[dict[str, Any]],
    *,
    include_subtitle_region: bool,
    prompt_profile: str,
    text_evidence_lines: list[str] | None = None,
    text_evidence_source: str = "none",
    text_evidence_conflict: bool = False,
    text_evidence_note: str = "",
    character_references: list[dict[str, Any]] | None = None,
) -> str:
    frame_lines = format_vlm_frame_lines(images)
    return "".join(
        [
            build_multimodal_prompt_header(
                prompt_profile=prompt_profile,
                include_subtitle_region=include_subtitle_region,
            ),
            "peak_role MUST be one of: setup, buildup, conflict, payoff, transition, ending, "
            "character-focus, unknown.\n",
            "Never output a person name, IP name, character name, or object name as peak_role.\n",
            "peak_times MUST use real timestamps from the frame list when possible, and each value must stay inside "
            "the group start/end range.\n",
            "Use highlight_score on a 0-1 scale.\n",
            "Required JSON keys: is_continuous_story, highlight_score, peak_times, peak_role, reason, "
            "speaker_hint, speaker_confidence.\n",
            format_multimodal_evidence_block(
                text_evidence_lines=text_evidence_lines,
                text_evidence_source=text_evidence_source,
                text_evidence_conflict=text_evidence_conflict,
                text_evidence_note=text_evidence_note,
                character_references=character_references,
            ),
            f"Shots:\n{shot_lines}\n",
            f"Frames in order:\n{frame_lines}",
        ]
    )


def _normalize_group_result(
    group_index: int,
    shot_group: list[dict[str, Any]],
    raw: dict[str, Any],
    *,
    text_evidence_source: str = "none",
    text_evidence_conflict: bool = False,
) -> dict[str, Any]:
    start_sec = float(shot_group[0]["startSec"])
    end_sec = float(shot_group[-1]["endSec"])
    peak_times = [
        round(parsed_value, 3)
        for value in raw.get("peak_times", [])
        for parsed_value in [_parse_peak_time(value)]
        if parsed_value is not None and start_sec <= parsed_value <= end_sec
    ]
    return {
        "index": group_index,
        "startSec": round(start_sec, 3),
        "endSec": round(end_sec, 3),
        "shotIndexes": [int(shot["index"]) for shot in shot_group],
        "isContinuousStory": bool(raw.get("is_continuous_story", False)),
        "mergeWithPrev": False,
        "mergeWithNext": False,
        "highlightScore": round(float(raw.get("highlight_score", 0.0)), 3),
        "peakTimesSec": peak_times,
        "peakRole": _normalize_peak_role(
            raw_role=str(raw.get("peak_role", "unknown")),
            reason=str(raw.get("reason", "")).strip(),
        ),
        "speakerHint": str(raw.get("speaker_hint", "")).strip(),
        "speakerConfidence": round(_clamp_score(raw.get("speaker_confidence", 0.0)), 3),
        "evidenceSource": str(raw.get("evidence_source", text_evidence_source)).strip() or text_evidence_source,
        "textConflict": bool(raw.get("text_conflict", text_evidence_conflict)),
        "reason": str(raw.get("reason", "")).strip(),
    }


def _normalize_peak_role(raw_role: str, reason: str) -> str:
    normalized_role = raw_role.strip().lower()
    if normalized_role in ALLOWED_PEAK_ROLES:
        return normalized_role

    evidence = f"{normalized_role} {reason.strip().lower()}"
    if any(keyword in evidence for keyword in ("fight", "conflict", "attack", "clash", "escalation", "impact")):
        return "conflict"
    if any(keyword in evidence for keyword in ("payoff", "result", "reveal", "resolution", "win", "loss")):
        return "payoff"
    if any(keyword in evidence for keyword in ("ending", "final", "closing", "finish", "conclusion")):
        return "ending"
    if any(keyword in evidence for keyword in ("transition", "exits", "exit", "leave", "walk", "move", "travel")):
        return "transition"
    if any(keyword in evidence for keyword in ("build", "buildup", "rising", "prepare", "preparing")):
        return "buildup"
    if any(keyword in evidence for keyword in ("setup", "introduce", "introducing", "establish", "opening")):
        return "setup"
    if any(keyword in evidence for keyword in ("character", "protagonist", "hero", "main character")):
        return "character-focus"
    return "unknown"


def _parse_peak_time(value: Any) -> float | None:
    if isinstance(value, (int, float)):
        return float(value)

    text = str(value).strip()
    if not text:
        return None

    match = re.search(r"-?\d+(?:\.\d+)?", text)
    if not match:
        return None

    try:
        return float(match.group(0))
    except ValueError:
        return None


def _clamp_score(value: Any) -> float:
    try:
        parsed = float(value)
    except (TypeError, ValueError):
        return 0.0
    return min(max(parsed, 0.0), 1.0)


def _prepare_character_reference_images(
    character_references: list[dict[str, Any]],
) -> list[dict[str, Any]]:
    prepared: list[dict[str, Any]] = []
    for reference in character_references:
        name = str(reference.get("name", "")).strip()
        image_base64 = str(reference.get("imageBase64", "")).strip()
        if not name or not image_base64:
            continue
        prepared.append(
            {
                "timeSec": 0.0,
                "jpegBase64": image_base64,
                "kind": "character-reference",
                "label": name,
            }
        )
    return prepared


def _extract_keyframes_for_shot(
    video_path: Path,
    shot: dict[str, Any],
    keyframes_per_shot: int,
    subtitle_region: NormalizedSubtitleRegion | None = None,
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

    encoded_frames: list[dict[str, Any]] = []
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError("Unable to open video file for VLM keyframes.")

    try:
        for time_sec in sample_times:
            capture.set(cv2.CAP_PROP_POS_MSEC, max(0.0, time_sec) * 1000.0)
            success, frame = capture.read()
            if not success or frame is None:
                continue
            encoded_frames.extend(
                encode_vlm_frame_variants(
                    frame=frame,
                    time_sec=time_sec,
                    subtitle_region=subtitle_region,
                )
            )
    finally:
        capture.release()

    return encoded_frames
