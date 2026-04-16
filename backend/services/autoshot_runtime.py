from __future__ import annotations

import importlib
import os
import sys
from functools import lru_cache
from pathlib import Path
from typing import Any

import cv2
import numpy as np

try:
    import ffmpeg
except Exception:  # pragma: no cover
    ffmpeg = None

try:
    import torch
except Exception:  # pragma: no cover
    torch = None

AUTOSHOT_INPUT_WIDTH = 48
AUTOSHOT_INPUT_HEIGHT = 27
AUTOSHOT_WINDOW_SIZE = 100
AUTOSHOT_VALID_SLICE_START = 25
AUTOSHOT_VALID_SLICE_END = 75
AUTOSHOT_DEFAULT_THRESHOLD = 0.296
AUTOSHOT_CHECKPOINT_ENV = "FINCAP_AUTOSHOT_CHECKPOINT_PATH"
AUTOSHOT_THRESHOLD_ENV = "FINCAP_AUTOSHOT_THRESHOLD"


def get_autoshot_repo_path() -> Path:
    return Path(__file__).resolve().parents[2] / "third_party" / "AutoShot"


def get_autoshot_checkpoint_path() -> Path:
    configured_path = os.getenv(AUTOSHOT_CHECKPOINT_ENV, "").strip()
    if configured_path:
        return Path(configured_path).expanduser().resolve()
    return get_autoshot_repo_path() / "ckpt_0_200_0.pth"


def get_autoshot_threshold() -> float:
    raw_threshold = os.getenv(AUTOSHOT_THRESHOLD_ENV, "").strip()
    if not raw_threshold:
        return AUTOSHOT_DEFAULT_THRESHOLD
    try:
        return float(raw_threshold)
    except ValueError as exc:  # pragma: no cover
        raise RuntimeError(f"Invalid AutoShot threshold: {raw_threshold}") from exc


def is_autoshot_ready() -> bool:
    return (
        torch is not None
        and ffmpeg is not None
        and get_autoshot_repo_path().exists()
        and get_autoshot_checkpoint_path().exists()
    )


def run_autoshot_cut_points(video_path: Path) -> tuple[list[float], str, dict[str, Any]]:
    model, device = _load_autoshot_model()
    frames = _extract_video_frames(video_path)
    predictions = _predict_boundaries(model, frames, device)
    threshold = get_autoshot_threshold()
    scenes = _predictions_to_scenes((predictions > threshold).astype(np.uint8))
    fps = _read_video_fps(video_path)
    cut_points = [round(float(scene[0] / fps), 3) for scene in scenes[1:]]
    backend = f"autoshot-{device}"
    meta = {
        "threshold": round(float(threshold), 4),
        "sceneCount": int(len(scenes)),
        "checkpoint": str(get_autoshot_checkpoint_path()),
    }
    return cut_points, backend, meta


@lru_cache(maxsize=1)
def _load_autoshot_model() -> tuple[Any, str]:
    if torch is None:
        raise RuntimeError("Torch is required for AutoShot inference.")
    if ffmpeg is None:
        raise RuntimeError("ffmpeg-python is required for AutoShot inference.")

    repo_path = get_autoshot_repo_path()
    if not repo_path.exists():
        raise FileNotFoundError(f"AutoShot repository not found at {repo_path}.")

    checkpoint_path = get_autoshot_checkpoint_path()
    if not checkpoint_path.exists():
        raise FileNotFoundError(
            f"AutoShot checkpoint not found at {checkpoint_path}. "
            f"Set {AUTOSHOT_CHECKPOINT_ENV} to a valid checkpoint file."
        )

    device = "cuda" if torch.cuda.is_available() else "cpu"
    model_class = _load_autoshot_model_class(repo_path)
    model = model_class().eval()

    model_state = model.state_dict()
    checkpoint = torch.load(checkpoint_path, map_location=device)
    state_dict = checkpoint["net"] if isinstance(checkpoint, dict) and "net" in checkpoint else checkpoint
    filtered_state_dict = {key: value for key, value in state_dict.items() if key in model_state}
    model_state.update(filtered_state_dict)
    model.load_state_dict(model_state)
    model = model.to(device)
    model.eval()
    return model, device


def _load_autoshot_model_class(repo_path: Path) -> Any:
    repo_path_str = str(repo_path)
    if repo_path_str not in sys.path:
        sys.path.insert(0, repo_path_str)
    module = importlib.import_module("supernet_flattransf_3_8_8_8_13_12_0_16_60")
    return getattr(module, "TransNetV2Supernet")


def _extract_video_frames(video_path: Path) -> np.ndarray:
    stream, _ = (
        ffmpeg.input(str(video_path))
        .output(
            "pipe:",
            format="rawvideo",
            pix_fmt="rgb24",
            s=f"{AUTOSHOT_INPUT_WIDTH}x{AUTOSHOT_INPUT_HEIGHT}",
        )
        .run(capture_stdout=True, capture_stderr=True)
    )
    return np.frombuffer(stream, np.uint8).reshape([-1, AUTOSHOT_INPUT_HEIGHT, AUTOSHOT_INPUT_WIDTH, 3])


def _predict_boundaries(model: Any, frames: np.ndarray, device: str) -> np.ndarray:
    predictions: list[np.ndarray] = []

    for batch in _iter_autoshot_batches(frames):
        batch_tensor = torch.from_numpy(batch.transpose((3, 0, 1, 2))[np.newaxis, ...]).float().to(device)
        with torch.no_grad():
            logits = model(batch_tensor)
            if isinstance(logits, tuple):
                logits = logits[0]
            one_hot = torch.sigmoid(logits[0]).detach().cpu().numpy()
        predictions.append(one_hot[AUTOSHOT_VALID_SLICE_START:AUTOSHOT_VALID_SLICE_END])

    if not predictions:
        return np.empty((0,), dtype=np.float32)

    return np.concatenate(predictions, axis=0)[: len(frames)]


def _iter_autoshot_batches(frames: np.ndarray):
    remainder = 50 - len(frames) % 50
    if remainder == 50:
        remainder = 0
    padded_frames = np.concatenate(
        [frames[:1]] * AUTOSHOT_VALID_SLICE_START
        + [frames]
        + [frames[-1:]] * (remainder + AUTOSHOT_VALID_SLICE_START),
        axis=0,
    )

    for index in range(0, len(padded_frames) - 50, 50):
        yield padded_frames[index : index + AUTOSHOT_WINDOW_SIZE]


def _predictions_to_scenes(predictions: np.ndarray) -> np.ndarray:
    scenes = []
    current_value = -1
    previous_value = 0
    start_index = 0

    for index, current_value in enumerate(predictions):
        if previous_value == 1 and current_value == 0:
            start_index = index
        if previous_value == 0 and current_value == 1 and index != 0:
            scenes.append([start_index, index])
        previous_value = current_value

    if current_value == 0:
        scenes.append([start_index, index])

    if not scenes:
        return np.array([[0, len(predictions) - 1]], dtype=np.int32)

    return np.asarray(scenes, dtype=np.int32)


def _read_video_fps(video_path: Path) -> float:
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError("Unable to open video file for AutoShot inference.")
    try:
        fps = float(capture.get(cv2.CAP_PROP_FPS) or 0.0)
    finally:
        capture.release()
    return fps if fps > 0.0 else 25.0
