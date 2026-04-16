from __future__ import annotations

import shutil
import subprocess
from functools import lru_cache
from typing import Any

import cv2

try:
    import torch
except Exception:  # pragma: no cover
    torch = None


@lru_cache(maxsize=1)
def get_ffmpeg_cuda_runtime() -> dict[str, Any]:
    ffmpeg_path = shutil.which("ffmpeg")
    if ffmpeg_path is None:
        return {
            "available": False,
            "backend": "ffmpeg-cuda",
            "reason": "ffmpeg is not installed",
        }

    try:
        result = subprocess.run(
            ["ffmpeg", "-hide_banner", "-decoders"],
            capture_output=True,
            text=True,
            check=True,
        )
    except Exception as exc:
        return {
            "available": False,
            "backend": "ffmpeg-cuda",
            "reason": f"ffmpeg decoder inspection failed: {exc}",
        }

    has_cuda_decoder = "h264_cuvid" in result.stdout or "hevc_cuvid" in result.stdout
    return {
        "available": has_cuda_decoder,
        "backend": "ffmpeg-cuda",
        "reason": "available" if has_cuda_decoder else "cuda decoders were not found in ffmpeg",
    }


@lru_cache(maxsize=1)
def get_torch_cuda_runtime() -> dict[str, Any]:
    if torch is None:
        return {
            "available": False,
            "backend": "torch-cuda",
            "reason": "torch is not installed",
        }

    if not torch.cuda.is_available():
        return {
            "available": False,
            "backend": "torch-cuda",
            "reason": "torch cuda is not available",
        }

    return {
        "available": True,
        "backend": "torch-cuda",
        "reason": "available",
        "deviceName": torch.cuda.get_device_name(0),
        "deviceCount": torch.cuda.device_count(),
    }


@lru_cache(maxsize=1)
def get_opencv_cuda_runtime() -> dict[str, Any]:
    if not hasattr(cv2, "cuda"):
        return {
            "available": False,
            "backend": "opencv-cuda",
            "reason": "cv2.cuda module is missing",
        }

    try:
        device_count = cv2.cuda.getCudaEnabledDeviceCount()
    except Exception as exc:
        return {
            "available": False,
            "backend": "opencv-cuda",
            "reason": f"cuda device query failed: {exc}",
        }

    required_ops = ["cvtColor", "resize", "absdiff", "calcHist"]
    missing_ops = [name for name in required_ops if not hasattr(cv2.cuda, name)]

    if device_count <= 0:
        return {
            "available": False,
            "backend": "opencv-cuda",
            "reason": "no cuda-enabled devices are exposed by the current OpenCV build",
            "deviceCount": device_count,
            "missingOps": missing_ops,
        }

    if missing_ops:
        return {
            "available": False,
            "backend": "opencv-cuda",
            "reason": "the current OpenCV build is missing required CUDA image ops",
            "deviceCount": device_count,
            "missingOps": missing_ops,
        }

    return {
        "available": True,
        "backend": "opencv-cuda",
        "reason": "available",
        "deviceCount": device_count,
    }


@lru_cache(maxsize=1)
def get_gpu_runtime_summary() -> dict[str, Any]:
    return {
        "ffmpeg": get_ffmpeg_cuda_runtime(),
        "torch": get_torch_cuda_runtime(),
        "opencv": get_opencv_cuda_runtime(),
    }
