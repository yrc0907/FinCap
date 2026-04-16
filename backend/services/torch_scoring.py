from __future__ import annotations

import os
from typing import Sequence

import cv2
import numpy as np

try:
    import torch
except Exception:  # pragma: no cover
    torch = None


def is_opencv_cuda_available() -> bool:
    if not hasattr(cv2, "cuda"):
        return False

    if not hasattr(cv2.cuda, "absdiff") or not hasattr(cv2.cuda, "calcHist"):
        return False

    try:
        return cv2.cuda.getCudaEnabledDeviceCount() > 0
    except Exception:
        return False


def is_torch_cuda_available() -> bool:
    return bool(torch is not None and torch.cuda.is_available())


def get_weighted_score_backend_preference() -> str:
    return os.getenv("FINCAP_WEIGHTED_SCORE_BACKEND", "auto").strip().lower() or "auto"


def _compute_cpu_histogram_diff_scores(frames: Sequence[np.ndarray]) -> np.ndarray:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32)

    histograms: list[np.ndarray] = []
    for frame in frames:
        histogram = cv2.calcHist([frame], [0], None, [32], [0, 256])
        histogram = cv2.normalize(histogram, histogram).flatten()
        histograms.append(histogram.astype(np.float32))

    scores = [
        float(
            max(
                0.0,
                min(
                    1.0,
                    1.0
                    - cv2.compareHist(
                        histograms[index - 1],
                        histograms[index],
                        cv2.HISTCMP_CORREL,
                    ),
                ),
            )
        )
        for index in range(1, len(histograms))
    ]
    return np.asarray(scores, dtype=np.float32)


def _compute_cpu_frame_diff_scores(frames: Sequence[np.ndarray]) -> np.ndarray:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32)

    scores = [
        float(np.mean(cv2.absdiff(frames[index - 1], frames[index])) / 255.0)
        for index in range(1, len(frames))
    ]
    return np.asarray(scores, dtype=np.float32)


def _compute_cpu_motion_proxy_scores(frames: Sequence[np.ndarray]) -> np.ndarray:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32)

    scores = []
    previous_edges = cv2.Canny(frames[0], 40, 120)
    for index in range(1, len(frames)):
        current_frame = frames[index]
        frame_difference = cv2.absdiff(frames[index - 1], current_frame)
        current_edges = cv2.Canny(current_frame, 40, 120)
        changed_pixels = float(np.mean((frame_difference >= 18).astype(np.float32)))
        edge_density_shift = abs(
            float(np.mean(previous_edges > 0)) - float(np.mean(current_edges > 0))
        )
        scores.append(float(np.clip(changed_pixels * 0.72 + edge_density_shift * 0.28, 0.0, 1.0)))
        previous_edges = current_edges

    return np.asarray(scores, dtype=np.float32)


def _compress_histogram_to_32_bins(histogram_256: np.ndarray) -> np.ndarray:
    flattened = histogram_256.reshape(-1).astype(np.float32)
    histogram_32 = flattened.reshape(32, 8).sum(axis=1)
    norm = float(np.linalg.norm(histogram_32))
    if norm > 0.0:
        histogram_32 = histogram_32 / norm
    return histogram_32.astype(np.float32)


def _compute_opencv_cuda_components(frames: Sequence[np.ndarray]) -> tuple[np.ndarray, np.ndarray]:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32), np.empty((0,), dtype=np.float32)

    gpu_frames: list[cv2.cuda.GpuMat] = []
    histograms: list[np.ndarray] = []

    for frame in frames:
        gpu_frame = cv2.cuda_GpuMat()
        gpu_frame.upload(frame)
        gpu_frames.append(gpu_frame)
        histogram = cv2.cuda.calcHist(gpu_frame).download()
        histograms.append(_compress_histogram_to_32_bins(histogram))

    histogram_scores = [
        float(
            max(
                0.0,
                min(
                    1.0,
                    1.0
                    - cv2.compareHist(
                        histograms[index - 1],
                        histograms[index],
                        cv2.HISTCMP_CORREL,
                    ),
                ),
            )
        )
        for index in range(1, len(histograms))
    ]
    frame_diff_scores = [
        float(np.mean(cv2.cuda.absdiff(gpu_frames[index - 1], gpu_frames[index]).download()) / 255.0)
        for index in range(1, len(gpu_frames))
    ]
    return (
        np.asarray(histogram_scores, dtype=np.float32),
        np.asarray(frame_diff_scores, dtype=np.float32),
    )


def _compute_torch_components(frames: Sequence[np.ndarray]) -> tuple[np.ndarray, np.ndarray]:
    stacked_frames = np.stack(frames, axis=0)

    with torch.no_grad():
        frame_tensor = torch.from_numpy(stacked_frames).to(device="cuda", dtype=torch.uint8)
        float_frames = frame_tensor.to(dtype=torch.float32)
        frame_diff_scores = (
            (float_frames[1:] - float_frames[:-1]).abs().mean(dim=(1, 2)) / 255.0
        )

        flattened = frame_tensor.reshape(frame_tensor.shape[0], -1).to(dtype=torch.int64)
        bin_indices = torch.div(flattened, 8, rounding_mode="floor")
        histograms = torch.zeros(
            (frame_tensor.shape[0], 32),
            device="cuda",
            dtype=torch.float32,
        )
        ones = torch.ones_like(bin_indices, dtype=torch.float32)
        histograms.scatter_add_(1, bin_indices, ones)
        histograms = histograms / histograms.norm(dim=1, keepdim=True).clamp_min(1e-6)
        previous_histograms = histograms[:-1]
        current_histograms = histograms[1:]
        previous_means = previous_histograms.mean(dim=1, keepdim=True)
        current_means = current_histograms.mean(dim=1, keepdim=True)
        centered_previous = previous_histograms - previous_means
        centered_current = current_histograms - current_means
        numerator = (centered_previous * centered_current).sum(dim=1)
        denominator = (
            centered_previous.square().sum(dim=1).sqrt()
            * centered_current.square().sum(dim=1).sqrt()
        ).clamp_min(1e-6)
        correlations = numerator / denominator
        histogram_diff_scores = (1.0 - correlations).clamp(0.0, 1.0)

        return (
            histogram_diff_scores.detach().cpu().numpy().astype(np.float32),
            frame_diff_scores.detach().cpu().numpy().astype(np.float32),
        )


def _compute_torch_scene_components(
    frames: Sequence[np.ndarray],
) -> tuple[np.ndarray, np.ndarray, np.ndarray]:
    stacked_frames = np.stack(frames, axis=0)

    with torch.no_grad():
        frame_tensor = torch.from_numpy(stacked_frames).to(device="cuda", dtype=torch.uint8)
        float_frames = frame_tensor.to(dtype=torch.float32) / 255.0

        frame_diff_scores = (float_frames[1:] - float_frames[:-1]).abs().mean(dim=(1, 2))

        flattened = frame_tensor.reshape(frame_tensor.shape[0], -1).to(dtype=torch.int64)
        bin_indices = torch.div(flattened, 8, rounding_mode="floor")
        histograms = torch.zeros(
            (frame_tensor.shape[0], 32),
            device="cuda",
            dtype=torch.float32,
        )
        ones = torch.ones_like(bin_indices, dtype=torch.float32)
        histograms.scatter_add_(1, bin_indices, ones)
        histograms = histograms / histograms.norm(dim=1, keepdim=True).clamp_min(1e-6)
        previous_histograms = histograms[:-1]
        current_histograms = histograms[1:]
        previous_means = previous_histograms.mean(dim=1, keepdim=True)
        current_means = current_histograms.mean(dim=1, keepdim=True)
        centered_previous = previous_histograms - previous_means
        centered_current = current_histograms - current_means
        numerator = (centered_previous * centered_current).sum(dim=1)
        denominator = (
            centered_previous.square().sum(dim=1).sqrt()
            * centered_current.square().sum(dim=1).sqrt()
        ).clamp_min(1e-6)
        correlations = numerator / denominator
        histogram_diff_scores = (1.0 - correlations).clamp(0.0, 1.0)

        kernel_x = torch.tensor(
            [[-1.0, 0.0, 1.0], [-2.0, 0.0, 2.0], [-1.0, 0.0, 1.0]],
            device="cuda",
            dtype=torch.float32,
        ).view(1, 1, 3, 3)
        kernel_y = torch.tensor(
            [[-1.0, -2.0, -1.0], [0.0, 0.0, 0.0], [1.0, 2.0, 1.0]],
            device="cuda",
            dtype=torch.float32,
        ).view(1, 1, 3, 3)
        image_batch = float_frames.unsqueeze(1)
        grad_x = torch.nn.functional.conv2d(image_batch, kernel_x, padding=1)
        grad_y = torch.nn.functional.conv2d(image_batch, kernel_y, padding=1)
        gradient_magnitude = torch.sqrt(grad_x.square() + grad_y.square() + 1e-6)
        motion_scores = (
            (gradient_magnitude[1:] - gradient_magnitude[:-1]).abs().mean(dim=(1, 2, 3)) * 3.5
        ).clamp(0.0, 1.0)

        return (
            histogram_diff_scores.detach().cpu().numpy().astype(np.float32),
            frame_diff_scores.detach().cpu().numpy().astype(np.float32),
            motion_scores.detach().cpu().numpy().astype(np.float32),
        )


def compute_weighted_transition_scores(
    frames: Sequence[np.ndarray],
    histogram_weight: float,
    frame_diff_weight: float,
) -> tuple[np.ndarray, str]:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32), "empty"

    _ = get_weighted_score_backend_preference()

    if is_torch_cuda_available():
        histogram_scores, frame_diff_scores = _compute_torch_components(frames)
        weighted_scores = histogram_weight * histogram_scores + frame_diff_weight * frame_diff_scores
        return np.clip(weighted_scores, 0.0, 1.0), "torch-cuda"

    histogram_scores = _compute_cpu_histogram_diff_scores(frames)
    frame_diff_scores = _compute_cpu_frame_diff_scores(frames)
    weighted_scores = histogram_weight * histogram_scores + frame_diff_weight * frame_diff_scores
    return np.clip(weighted_scores, 0.0, 1.0), "opencv-cpu"


def compute_scene_transition_scores(
    frames: Sequence[np.ndarray],
    histogram_weight: float,
    frame_diff_weight: float,
    optical_flow_weight: float,
) -> tuple[np.ndarray, str]:
    if len(frames) < 2:
        return np.empty((0,), dtype=np.float32), "empty"

    if is_torch_cuda_available():
        histogram_scores, frame_diff_scores, motion_scores = _compute_torch_scene_components(frames)
        weighted_scores = (
            histogram_weight * histogram_scores
            + frame_diff_weight * frame_diff_scores
            + optical_flow_weight * motion_scores
        )
        return np.clip(weighted_scores, 0.0, 1.0), "torch-cuda"

    histogram_scores = _compute_cpu_histogram_diff_scores(frames)
    frame_diff_scores = _compute_cpu_frame_diff_scores(frames)

    try:
        optical_flow_scores = []
        for index in range(1, len(frames)):
            flow = cv2.calcOpticalFlowFarneback(
                frames[index - 1],
                frames[index],
                None,
                pyr_scale=0.5,
                levels=3,
                winsize=15,
                iterations=3,
                poly_n=5,
                poly_sigma=1.2,
                flags=0,
            )
            magnitude, _ = cv2.cartToPolar(flow[..., 0], flow[..., 1])
            optical_flow_scores.append(float(max(0.0, min(1.0, np.mean(magnitude) / 8.0))))
        optical_flow_scores_array = np.asarray(optical_flow_scores, dtype=np.float32)
        backend = "opencv-cpu+opencv-flow"
    except Exception:
        optical_flow_scores_array = _compute_cpu_motion_proxy_scores(frames)
        backend = "opencv-cpu+motion-proxy"

    weighted_scores = (
        histogram_weight * histogram_scores
        + frame_diff_weight * frame_diff_scores
        + optical_flow_weight * optical_flow_scores_array
    )
    return np.clip(weighted_scores, 0.0, 1.0), backend
