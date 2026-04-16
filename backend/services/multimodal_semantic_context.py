from __future__ import annotations

import base64
from dataclasses import dataclass
from typing import Any

import cv2


@dataclass(frozen=True)
class NormalizedSubtitleRegion:
    x: float
    y: float
    width: float
    height: float


def normalize_subtitle_region(
    region: NormalizedSubtitleRegion | dict[str, Any] | None,
) -> NormalizedSubtitleRegion | None:
    if region is None:
        return None
    if isinstance(region, NormalizedSubtitleRegion):
        x = float(region.x)
        y = float(region.y)
        width = float(region.width)
        height = float(region.height)
    else:
        try:
            x = float(region.get("x", 0.0))
            y = float(region.get("y", 0.0))
            width = float(region.get("width", 0.0))
            height = float(region.get("height", 0.0))
        except (AttributeError, TypeError, ValueError):
            return None

    x = min(max(x, 0.0), 1.0)
    y = min(max(y, 0.0), 1.0)
    width = min(max(width, 0.0), 1.0 - x)
    height = min(max(height, 0.0), 1.0 - y)
    if width <= 0.0 or height <= 0.0:
        return None
    return NormalizedSubtitleRegion(x=x, y=y, width=width, height=height)


def encode_vlm_frame_variants(
    frame: Any,
    time_sec: float,
    subtitle_region: NormalizedSubtitleRegion | None = None,
) -> list[dict[str, Any]]:
    images = [_encode_frame(frame=frame, time_sec=time_sec, kind="scene")]
    normalized_region = normalize_subtitle_region(subtitle_region)
    if normalized_region is None:
        return images

    subtitle_crop = crop_subtitle_region(frame, normalized_region)
    if subtitle_crop is None:
        return images
    images.append(_encode_frame(frame=subtitle_crop, time_sec=time_sec, kind="subtitle"))
    return images


def crop_subtitle_region(
    frame: Any,
    region: NormalizedSubtitleRegion,
) -> Any | None:
    height, width = frame.shape[:2]
    left = int(round(width * region.x))
    top = int(round(height * region.y))
    right = int(round(width * (region.x + region.width)))
    bottom = int(round(height * (region.y + region.height)))
    if right <= left or bottom <= top:
        return None
    crop = frame[top:bottom, left:right]
    if crop.size == 0:
        return None
    return crop


def build_short_video_semantic_rubric() -> str:
    return (
        "Short-video semantic scoring rubric:\n"
        "- Score HIGH for conflict escalation, fights, chase, emotional collapse, sudden reversal, truth reveal, "
        "result/payoff, and strong dialogue-driven pressure.\n"
        "- Score HIGH for threats, pressure, scolding, humiliation, command pressure, blame, and decisive key lines "
        "visible in subtitles.\n"
        "- Score HIGH for boss pressure, accusation, humiliation, deadline pressure, threat, and emotional breaking "
        "points revealed by OCR or ASR text.\n"
        "- Score LOW for ordinary walking, calm transition, plain exposition, visually flat dialogue, and filler "
        "movement without pressure or plot movement.\n"
        "- Use scene images, subtitle-region crops, OCR text, ASR text, and character references when available.\n"
    )


def build_multimodal_prompt_header(
    *,
    prompt_profile: str,
    include_subtitle_region: bool,
) -> str:
    base = (
        "You are analyzing adjacent shots from one video.\n"
        "Only describe this current shot group. Do not infer neighboring groups and do not decide adjacent merges.\n"
        "Return JSON only. Do not add markdown. Do not add any extra keys.\n"
    )
    if prompt_profile == "short-video":
        base += build_short_video_semantic_rubric()
    if include_subtitle_region:
        base += (
            "Some images are subtitle-region crops. Read visible subtitle text from subtitle-region crops when present "
            "and treat subtitle pressure or reveal lines as semantic evidence.\n"
        )
    base += (
        "If OCR text, ASR text, or character reference evidence is provided, use it as supporting evidence.\n"
        "Return speaker_hint as the most likely speaking role or character name from the provided evidence. "
        "If uncertain, return unknown.\n"
    )
    return base


def format_vlm_frame_lines(images: list[dict[str, Any]]) -> str:
    lines: list[str] = []
    for index, image in enumerate(images, start=1):
        kind = str(image.get("kind", "scene")).strip() or "scene"
        label = str(image.get("label", "")).strip()
        if label:
            lines.append(f"- frame {index} [{kind} | {label}]")
            continue
        lines.append(f"- frame {index} [{kind}]: {float(image['timeSec']):.3f}s")
    return "\n".join(lines) or "- no frame timestamps available"


def compact_text_evidence(lines: list[str]) -> list[str]:
    normalized: list[str] = []
    seen: set[str] = set()
    for raw in lines:
        text = " ".join(str(raw).split()).strip()
        if not text:
            continue
        key = text.casefold()
        if key in seen:
            continue
        seen.add(key)
        normalized.append(text)
    return normalized


def select_asr_text_for_window(
    segments: list[dict[str, Any]],
    start_sec: float,
    end_sec: float,
) -> list[str]:
    selected: list[str] = []
    for segment in segments:
        segment_start = float(segment.get("startSec", 0.0))
        segment_end = float(segment.get("endSec", 0.0))
        if segment_end <= start_sec or segment_start >= end_sec:
            continue
        selected.append(str(segment.get("text", "")))
    return compact_text_evidence(selected)


def format_multimodal_evidence_block(
    *,
    text_evidence_lines: list[str] | None = None,
    text_evidence_source: str = "none",
    text_evidence_conflict: bool = False,
    text_evidence_note: str = "",
    character_references: list[dict[str, Any]] | None = None,
) -> str:
    sections: list[str] = []
    normalized_text_evidence = compact_text_evidence(list(text_evidence_lines or []))[:8]
    normalized_characters = [
        str(reference.get("name", "")).strip()
        for reference in (character_references or [])
        if str(reference.get("name", "")).strip()
    ][:8]

    if normalized_text_evidence:
        sections.append(
            "Text evidence source: "
            f"{text_evidence_source}\n"
            + "\n".join(f"- {line}" for line in normalized_text_evidence)
        )
    if text_evidence_conflict and text_evidence_note.strip():
        sections.append("Text evidence note:\n" + text_evidence_note.strip())
    if normalized_characters:
        sections.append(
            "Character references:\n" + "\n".join(f"- {name}" for name in normalized_characters)
        )

    if not sections:
        return ""
    return "\n".join(sections) + "\n"


def resize_for_vlm(frame: Any) -> Any:
    height, width = frame.shape[:2]
    longest_edge = max(height, width)
    if longest_edge <= 960:
        return frame
    scale = 960.0 / float(longest_edge)
    target_size = (max(1, int(round(width * scale))), max(1, int(round(height * scale))))
    return cv2.resize(frame, target_size, interpolation=cv2.INTER_AREA)


def _encode_frame(
    frame: Any,
    time_sec: float,
    kind: str,
) -> dict[str, Any]:
    resized_frame = resize_for_vlm(frame)
    success, buffer = cv2.imencode(".jpg", resized_frame)
    if not success:
        raise RuntimeError("Unable to encode VLM frame.")
    return {
        "timeSec": round(float(time_sec), 3),
        "jpegBase64": base64.b64encode(buffer.tobytes()).decode("utf-8"),
        "kind": kind,
    }
