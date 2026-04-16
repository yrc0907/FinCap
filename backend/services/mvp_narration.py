from __future__ import annotations

import base64
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import cv2

from .vlm_openai_client import call_openai_compatible_vision

LOG_START = "[Start] MVP narration generation started"
LOG_CLIP = "[Process] MVP narration clip"
LOG_COMPLETE = "[Done] MVP narration generation completed"


@dataclass(frozen=True)
class NarrationGenerationConfig:
    keyframes_per_clip: int = 4
    chars_per_second: float = 3.0
    min_characters: int = 10
    max_characters: int = 42


def generate_clip_narrations(
    video_path: Path,
    selected_clips: list[dict[str, Any]],
    vlm_config: dict[str, str],
    config: NarrationGenerationConfig | None = None,
) -> dict[str, Any]:
    active_config = config or NarrationGenerationConfig()
    ordered_clips = sorted(selected_clips, key=lambda item: int(item.get("index", 0)))
    results: list[dict[str, Any]] = []
    print(LOG_START)

    for clip in ordered_clips:
        max_characters = _resolve_character_budget(clip, active_config)
        images = extract_clip_keyframes(
            video_path=video_path,
            clip=clip,
            keyframes_per_clip=active_config.keyframes_per_clip,
        )
        response = call_openai_compatible_vision(
            vlm_config=vlm_config,
            prompt=build_narration_prompt(clip=clip, images=images, max_characters=max_characters),
            images=images,
        )
        normalized = normalize_narration_response(
            clip=clip,
            raw=response,
            max_characters=max_characters,
        )
        normalized["frameCount"] = len(images)
        results.append(normalized)
        print(
            f"{LOG_CLIP}: index={normalized['clipIndex']}, range={normalized['startSec']:.3f}-{normalized['endSec']:.3f}, "
            f"chars={normalized['charCount']}"
        )

    summary = {
        "clipCount": len(results),
        "totalNarrationCharacters": sum(int(item["charCount"]) for item in results),
        "avgNarrationCharacters": round(
            sum(int(item["charCount"]) for item in results) / len(results), 2
        )
        if results
        else 0.0,
    }
    print(LOG_COMPLETE)
    return {"clips": results, "summary": summary}


def build_narration_prompt(
    clip: dict[str, Any],
    images: list[dict[str, Any]],
    max_characters: int,
) -> str:
    frame_lines = "\n".join(
        f"- frame {index + 1}: {float(image['timeSec']):.3f}s"
        for index, image in enumerate(images)
    )
    if not frame_lines:
        frame_lines = "- no sampled frames"

    return (
        "You are generating short Chinese narration for one video clip.\n"
        "Only describe the current clip. Do not mention later clips. Do not write markdown.\n"
        "Return JSON only with keys: summary, narration.\n"
        "summary must be English and short.\n"
        "narration must be Simplified Chinese, one sentence, natural, easy to dub, and visually grounded.\n"
        "Do not invent names, episode numbers, or plot facts that are not visible.\n"
        f"Keep narration within {max_characters} Chinese characters if possible.\n"
        f"Clip range: {float(clip['startSec']):.3f}s to {float(clip['endSec']):.3f}s.\n"
        f"Clip duration: {float(clip.get('durationSec', 0.0)):.3f}s.\n"
        f"Frames:\n{frame_lines}"
    )


def normalize_narration_response(
    clip: dict[str, Any],
    raw: dict[str, Any],
    max_characters: int,
) -> dict[str, Any]:
    summary = _normalize_whitespace(str(raw.get("summary", "")).strip())
    narration = _normalize_whitespace(str(raw.get("narration", "")).strip())
    if not narration:
        narration = "这一段画面继续推进。"

    narration = _truncate_text(narration, max_characters)
    return {
        "clipIndex": int(clip.get("index", 0)),
        "startSec": round(float(clip.get("startSec", 0.0)), 3),
        "endSec": round(float(clip.get("endSec", 0.0)), 3),
        "durationSec": round(float(clip.get("durationSec", 0.0)), 3),
        "summary": summary,
        "narration": narration,
        "charCount": len(narration),
    }


def extract_clip_keyframes(
    video_path: Path,
    clip: dict[str, Any],
    keyframes_per_clip: int,
) -> list[dict[str, Any]]:
    start_sec = float(clip.get("startSec", 0.0))
    end_sec = float(clip.get("endSec", start_sec))
    duration_sec = max(0.0, end_sec - start_sec)
    if duration_sec <= 0.0:
        return []

    if keyframes_per_clip <= 1:
        sample_times = [start_sec + duration_sec * 0.5]
    else:
        sample_times = [
            start_sec + duration_sec * ((index + 1) / (keyframes_per_clip + 1))
            for index in range(keyframes_per_clip)
        ]

    encoded_frames: list[dict[str, Any]] = []
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError(f"Unable to open video file for clip narration: {video_path}")

    try:
        for time_sec in sample_times:
            capture.set(cv2.CAP_PROP_POS_MSEC, max(0.0, time_sec) * 1000.0)
            success, frame = capture.read()
            if not success or frame is None:
                continue
            resized_frame = _resize_for_vlm(frame)
            encoded = cv2.imencode(".jpg", resized_frame)
            if not encoded[0]:
                continue
            encoded_frames.append(
                {
                    "timeSec": round(float(time_sec), 3),
                    "jpegBase64": base64.b64encode(encoded[1].tobytes()).decode("utf-8"),
                }
            )
    finally:
        capture.release()

    return encoded_frames


def _resolve_character_budget(
    clip: dict[str, Any],
    config: NarrationGenerationConfig,
) -> int:
    duration_sec = max(0.0, float(clip.get("durationSec", 0.0)))
    dynamic_budget = int(round(duration_sec * config.chars_per_second))
    return max(config.min_characters, min(config.max_characters, dynamic_budget))


def _truncate_text(text: str, max_characters: int) -> str:
    stripped = text.strip()
    if len(stripped) <= max_characters:
        return stripped
    return stripped[:max_characters].rstrip("，。！？；：、 ")


def _normalize_whitespace(text: str) -> str:
    return " ".join(text.split())


def _resize_for_vlm(frame: Any) -> Any:
    height, width = frame.shape[:2]
    longest_edge = max(height, width)
    if longest_edge <= 960:
        return frame

    scale = 960.0 / float(longest_edge)
    target_size = (max(1, int(round(width * scale))), max(1, int(round(height * scale))))
    return cv2.resize(frame, target_size, interpolation=cv2.INTER_AREA)
