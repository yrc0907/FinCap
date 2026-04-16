from __future__ import annotations

import base64
from typing import Any

import cv2
import numpy as np


_OCR_ENGINE: Any | None = None


def extract_ocr_lines(images: list[dict[str, Any]]) -> list[str]:
    lines: list[str] = []
    for image in images:
        if str(image.get("kind", "")).strip() != "subtitle":
            continue
        frame = _decode_jpeg_base64(str(image.get("jpegBase64", "")))
        if frame is None:
            continue
        lines.extend(_extract_text_from_frame(frame))
    return lines


def _extract_text_from_frame(frame: Any) -> list[str]:
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

    lines: list[str] = []
    for item in result:
        if isinstance(item, (list, tuple)) and len(item) >= 2:
            text = str(item[1]).strip()
            if text:
                lines.append(text)
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
