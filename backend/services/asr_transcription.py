from __future__ import annotations

from pathlib import Path
from typing import Any

import torch


_ASR_MODEL_CACHE: dict[tuple[str, str], Any] = {}
_ASR_SEGMENT_CACHE: dict[tuple[str, int, str], list[dict[str, Any]]] = {}


def transcribe_video_to_segments(
    video_path: Path,
    model_name: str = "turbo",
) -> list[dict[str, Any]]:
    resolved_path = video_path.resolve()
    if not resolved_path.exists():
        return []
    if not torch.cuda.is_available():
        print("[Warn] CUDA is unavailable. Automatic ASR was skipped.")
        return []
    stat = resolved_path.stat()
    cache_key = (str(resolved_path), stat.st_mtime_ns, model_name)
    cached = _ASR_SEGMENT_CACHE.get(cache_key)
    if cached is not None:
        return [dict(item) for item in cached]

    whisper = _import_whisper()
    if whisper is None:
        return []

    device = "cuda"
    model = _get_model(whisper, model_name=model_name, device=device)
    if model is None:
        return []

    try:
        result = model.transcribe(
            str(resolved_path),
            verbose=False,
            word_timestamps=False,
            condition_on_previous_text=True,
            fp16=device == "cuda",
        )
    except Exception as exc:  # pragma: no cover
        print(f"[Warn] ASR transcription failed: {exc}")
        return []

    segments: list[dict[str, Any]] = []
    for segment in result.get("segments", []):
        text = str(segment.get("text", "")).strip()
        if not text:
            continue
        segments.append(
            {
                "startSec": round(float(segment.get("start", 0.0)), 3),
                "endSec": round(float(segment.get("end", 0.0)), 3),
                "text": text,
            }
        )

    _ASR_SEGMENT_CACHE[cache_key] = [dict(item) for item in segments]
    return segments


def _import_whisper() -> Any | None:
    try:
        import whisper
    except ImportError:  # pragma: no cover
        return None
    return whisper


def _get_model(whisper: Any, *, model_name: str, device: str) -> Any | None:
    cache_key = (model_name, device)
    cached = _ASR_MODEL_CACHE.get(cache_key)
    if cached is not None:
        return cached

    try:
        model = whisper.load_model(model_name, device=device)
    except Exception as exc:  # pragma: no cover
        print(f"[Warn] Unable to load ASR model '{model_name}' on {device}: {exc}")
        return None

    _ASR_MODEL_CACHE[cache_key] = model
    return model
