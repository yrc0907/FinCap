from __future__ import annotations

import shutil
import subprocess
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path

import cv2
import numpy as np


@dataclass(frozen=True)
class FrameSampleBatch:
    frames: list[np.ndarray]
    times_sec: list[float]
    backend: str


@lru_cache(maxsize=1)
def _has_ffmpeg() -> bool:
    return shutil.which("ffmpeg") is not None


@lru_cache(maxsize=1)
def _ffmpeg_supports_cuda() -> bool:
    if not _has_ffmpeg():
        return False

    try:
        result = subprocess.run(
            ["ffmpeg", "-hide_banner", "-decoders"],
            capture_output=True,
            text=True,
            check=True,
        )
    except Exception:
        return False

    return "h264_cuvid" in result.stdout or "hevc_cuvid" in result.stdout


def _build_ffmpeg_command(
    video_path: Path,
    start_sec: float,
    duration_sec: float,
    step_sec: float,
    width: int,
    height: int,
    use_cuda: bool,
) -> list[str]:
    fps_filter = f"fps=1/{step_sec:.8f}"
    if use_cuda:
        vf = ",".join(
            [
                fps_filter,
                f"scale_cuda={width}:{height}",
                "hwdownload",
                "format=nv12",
                "format=gray",
            ]
        )
        return [
            "ffmpeg",
            "-hide_banner",
            "-loglevel",
            "error",
            "-hwaccel",
            "cuda",
            "-hwaccel_output_format",
            "cuda",
            "-ss",
            f"{start_sec:.6f}",
            "-i",
            str(video_path),
            "-t",
            f"{duration_sec:.6f}",
            "-vf",
            vf,
            "-an",
            "-sn",
            "-dn",
            "-f",
            "rawvideo",
            "pipe:1",
        ]

    vf = ",".join(
        [
            fps_filter,
            f"scale={width}:{height}:flags=area",
            "format=gray",
        ]
    )
    return [
        "ffmpeg",
        "-hide_banner",
        "-loglevel",
        "error",
        "-ss",
        f"{start_sec:.6f}",
        "-i",
        str(video_path),
        "-t",
        f"{duration_sec:.6f}",
        "-vf",
        vf,
        "-an",
        "-sn",
        "-dn",
        "-f",
        "rawvideo",
        "pipe:1",
    ]


def _decode_ffmpeg_frames(
    video_path: Path,
    start_sec: float,
    end_sec: float,
    step_sec: float,
    width: int,
    height: int,
    use_cuda: bool,
) -> FrameSampleBatch:
    duration_sec = max(0.0, end_sec - start_sec)
    if duration_sec <= 0.0:
        return FrameSampleBatch(frames=[], times_sec=[], backend="ffmpeg-cuda" if use_cuda else "ffmpeg-cpu")

    command = _build_ffmpeg_command(
        video_path=video_path,
        start_sec=start_sec,
        duration_sec=duration_sec,
        step_sec=step_sec,
        width=width,
        height=height,
        use_cuda=use_cuda,
    )
    result = subprocess.run(command, capture_output=True, check=True)

    frame_size = width * height
    if frame_size <= 0:
        raise RuntimeError("Invalid frame size.")

    frame_count = len(result.stdout) // frame_size
    if frame_count == 0:
        return FrameSampleBatch(frames=[], times_sec=[], backend="ffmpeg-cuda" if use_cuda else "ffmpeg-cpu")

    frames: list[np.ndarray] = []
    times_sec: list[float] = []

    for index in range(frame_count):
        offset = index * frame_size
        frame_bytes = result.stdout[offset : offset + frame_size]
        if len(frame_bytes) < frame_size:
            break

        frame = np.frombuffer(frame_bytes, dtype=np.uint8).reshape((height, width)).copy()
        sample_time_sec = min(end_sec, start_sec + index * step_sec)
        frames.append(frame)
        times_sec.append(round(sample_time_sec, 6))

    return FrameSampleBatch(
        frames=frames,
        times_sec=times_sec,
        backend="ffmpeg-cuda" if use_cuda else "ffmpeg-cpu",
    )


def _decode_opencv_frames(
    video_path: Path,
    start_sec: float,
    end_sec: float,
    step_sec: float,
    width: int,
    height: int,
) -> FrameSampleBatch:
    capture = cv2.VideoCapture(str(video_path))
    if not capture.isOpened():
        raise RuntimeError("Unable to open video file.")

    try:
        fps = float(capture.get(cv2.CAP_PROP_FPS) or 0.0)
        if fps <= 0:
            fps = 25.0

        step_frames = max(1, int(round(fps * step_sec)))
        start_frame = max(0, int(round(start_sec * fps)))
        end_frame = max(start_frame, int(round(end_sec * fps)))

        frames: list[np.ndarray] = []
        times_sec: list[float] = []

        for frame_index in range(start_frame, end_frame + 1, step_frames):
            capture.set(cv2.CAP_PROP_POS_FRAMES, frame_index)
            success, frame = capture.read()
            if not success or frame is None:
                continue

            gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            resized_frame = cv2.resize(gray_frame, (width, height), interpolation=cv2.INTER_AREA)
            frames.append(resized_frame)
            times_sec.append(round(frame_index / fps, 6))

        return FrameSampleBatch(frames=frames, times_sec=times_sec, backend="opencv-cpu")
    finally:
        capture.release()


def sample_grayscale_frames(
    video_path: Path,
    start_sec: float,
    end_sec: float,
    step_sec: float,
    width: int,
    height: int,
) -> FrameSampleBatch:
    normalized_start_sec = max(0.0, start_sec)
    normalized_end_sec = max(normalized_start_sec, end_sec)

    if _ffmpeg_supports_cuda():
        try:
            return _decode_ffmpeg_frames(
                video_path=video_path,
                start_sec=normalized_start_sec,
                end_sec=normalized_end_sec,
                step_sec=step_sec,
                width=width,
                height=height,
                use_cuda=True,
            )
        except Exception:
            pass

    if _has_ffmpeg():
        try:
            return _decode_ffmpeg_frames(
                video_path=video_path,
                start_sec=normalized_start_sec,
                end_sec=normalized_end_sec,
                step_sec=step_sec,
                width=width,
                height=height,
                use_cuda=False,
            )
        except Exception:
            pass

    return _decode_opencv_frames(
        video_path=video_path,
        start_sec=normalized_start_sec,
        end_sec=normalized_end_sec,
        step_sec=step_sec,
        width=width,
        height=height,
    )
