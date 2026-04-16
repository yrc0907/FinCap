from __future__ import annotations

import base64
from typing import Any

import cv2
import numpy as np


_OCR_ENGINE: Any | None = None


def extract_ocr_entries(images: list[dict[str, Any]]) -> list[dict[str, Any]]:
    entries: list[dict[str, Any]] = []
    for image in images:
        if str(image.get("kind", "")).strip() != "subtitle":
            continue
        frame = _decode_jpeg_base64(str(image.get("jpegBase64", "")))
        if frame is None:
            continue
        entries.extend(_extract_entries_from_frame(frame))
    return entries


def extract_ocr_lines(images: list[dict[str, Any]]) -> list[str]:
    return [entry["text"] for entry in extract_ocr_entries(images)]


def _extract_entries_from_frame(frame: Any) -> list[dict[str, Any]]:
    engine = _get_ocr_engine()
    if engine is None:
        return []

    try:
        result, _ = engine(frame)
    except Exception as exc:  # pragma: no cover
        print(f"[Warn] OCR extraction failed: {exc}")
        return []

    if not result:
        return []

    lines: list[dict[str, Any]] = []
    for item in result:
        text, confidence = _parse_ocr_result_item(item)
        if text:
            lines.append({"text": text, "confidence": confidence})
    return lines


def _get_ocr_engine() -> Any | None:
    global _OCR_ENGINE
    if _OCR_ENGINE is not None:
        return _OCR_ENGINE

    try:
        from rapidocr_onnxruntime import RapidOCR
    except ImportError:  # pragma: no cover
        return None

    _OCR_ENGINE = RapidOCR()
    return _OCR_ENGINE


def _parse_ocr_result_item(item: Any) -> tuple[str, float]:
    if isinstance(item, dict):
        text = str(item.get("text", "")).strip()
        confidence = _normalize_confidence(item.get("score", item.get("confidence", 0.0)))
        return text, confidence

    if isinstance(item, (list, tuple)):
        if len(item) >= 3:
            text = str(item[1]).strip()
            confidence = _normalize_confidence(item[2])
            return text, confidence
        if len(item) >= 2:
            text = str(item[1]).strip()
            return text, 0.9 if text else 0.0

    return "", 0.0


def _decode_jpeg_base64(jpeg_base64: str) -> Any | None:
    if not jpeg_base64.strip():
        return None
    try:
        buffer = base64.b64decode(jpeg_base64)
    except Exception:
        return None
    array = np.frombuffer(buffer, dtype=np.uint8)
    if array.size == 0:
        return None
    return cv2.imdecode(array, cv2.IMREAD_COLOR)


def _normalize_confidence(value: Any) -> float:
    try:
        parsed = float(value)
    except (TypeError, ValueError):
        return 0.0
    return min(max(parsed, 0.0), 1.0)
