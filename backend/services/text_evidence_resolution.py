from __future__ import annotations

from dataclasses import dataclass
from difflib import SequenceMatcher
from typing import Any

from .multimodal_semantic_context import compact_text_evidence


@dataclass(frozen=True)
class TextEvidenceDecision:
    source: str
    primary_lines: list[str]
    conflict_detected: bool
    conservative_note: str
    ocr_confidence: float


def resolve_text_evidence(
    ocr_entries: list[dict[str, Any]] | None,
    asr_lines: list[str] | None,
    *,
    ocr_confidence_threshold: float = 0.75,
    conflict_similarity_threshold: float = 0.72,
) -> TextEvidenceDecision:
    normalized_ocr_entries = _normalize_ocr_entries(ocr_entries or [])
    ocr_lines = compact_text_evidence([entry["text"] for entry in normalized_ocr_entries])
    asr_lines_normalized = compact_text_evidence(list(asr_lines or []))
    ocr_confidence = _average_confidence(normalized_ocr_entries)
    strong_ocr = bool(ocr_lines) and ocr_confidence >= ocr_confidence_threshold

    if strong_ocr and asr_lines_normalized:
        similarity = _text_similarity(ocr_lines, asr_lines_normalized)
        if similarity < conflict_similarity_threshold:
            return TextEvidenceDecision(
                source="conflict",
                primary_lines=ocr_lines,
                conflict_detected=True,
                conservative_note=(
                    "OCR and ASR conflict. Be conservative with dialogue-driven claims and rely more on visuals."
                ),
                ocr_confidence=ocr_confidence,
            )

    if strong_ocr:
        return TextEvidenceDecision(
            source="ocr",
            primary_lines=ocr_lines,
            conflict_detected=False,
            conservative_note="",
            ocr_confidence=ocr_confidence,
        )

    if asr_lines_normalized:
        return TextEvidenceDecision(
            source="asr",
            primary_lines=asr_lines_normalized,
            conflict_detected=False,
            conservative_note="",
            ocr_confidence=ocr_confidence,
        )

    if ocr_lines:
        return TextEvidenceDecision(
            source="ocr",
            primary_lines=ocr_lines,
            conflict_detected=False,
            conservative_note="",
            ocr_confidence=ocr_confidence,
        )

    return TextEvidenceDecision(
        source="none",
        primary_lines=[],
        conflict_detected=False,
        conservative_note="",
        ocr_confidence=0.0,
    )


def _normalize_ocr_entries(entries: list[dict[str, Any]]) -> list[dict[str, Any]]:
    normalized: list[dict[str, Any]] = []
    for entry in entries:
        text = " ".join(str(entry.get("text", "")).split()).strip()
        if not text:
            continue
        confidence = _clamp_score(entry.get("confidence", 0.0))
        normalized.append({"text": text, "confidence": confidence})
    return normalized


def _average_confidence(entries: list[dict[str, Any]]) -> float:
    if not entries:
        return 0.0
    return sum(float(entry["confidence"]) for entry in entries) / float(len(entries))


def _text_similarity(left_lines: list[str], right_lines: list[str]) -> float:
    left_text = " ".join(left_lines).casefold().strip()
    right_text = " ".join(right_lines).casefold().strip()
    if not left_text or not right_text:
        return 0.0
    return SequenceMatcher(None, left_text, right_text).ratio()


def _clamp_score(value: Any) -> float:
    try:
        parsed = float(value)
    except (TypeError, ValueError):
        return 0.0
    return min(max(parsed, 0.0), 1.0)
