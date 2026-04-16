from __future__ import annotations

import os
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


@dataclass(frozen=True)
class OpenCvBootstrapState:
    activated: bool
    reason: str
    package_root: str | None = None
    binary_dir: str | None = None


def _repo_root() -> Path:
    return Path(__file__).resolve().parent.parent


def _iter_env_paths(variable_name: str) -> list[Path]:
    raw_value = os.getenv(variable_name, "").strip()
    if not raw_value:
        return []

    return [Path(part) for part in raw_value.split(os.pathsep) if part.strip()]


def _default_package_roots() -> list[Path]:
    return [
        *_iter_env_paths("FINCAP_OPENCV_PYTHON_ROOT"),
        _repo_root() / "third_party" / "opencv-4x-python",
        Path("C:/registry/Lib/site-packages"),
    ]


def _default_binary_dirs() -> list[Path]:
    return [
        *_iter_env_paths("FINCAP_OPENCV_BIN_DIR"),
        _repo_root() / "third_party" / "opencv-4x-install" / "x64" / "vc17" / "bin",
    ]


def _resolve_package_root(candidates: Iterable[Path]) -> Path | None:
    for candidate in candidates:
        if (candidate / "cv2" / "__init__.py").exists():
            return candidate.resolve()
    return None


def _resolve_binary_dir(candidates: Iterable[Path]) -> Path | None:
    for candidate in candidates:
        if candidate.exists() and candidate.is_dir():
            return candidate.resolve()
    return None


def _prepend_unique_path(existing_path: str, value: str) -> str:
    current_parts = [part for part in existing_path.split(os.pathsep) if part]
    normalized_value = os.path.normcase(os.path.normpath(value))

    if any(os.path.normcase(os.path.normpath(part)) == normalized_value for part in current_parts):
        return existing_path

    return value if not existing_path else value + os.pathsep + existing_path


def activate_local_opencv_cuda(
    package_roots: Iterable[Path] | None = None,
    binary_dirs: Iterable[Path] | None = None,
) -> OpenCvBootstrapState:
    if "cv2" in sys.modules:
        return OpenCvBootstrapState(activated=False, reason="cv2 is already imported")

    package_root = _resolve_package_root(package_roots or _default_package_roots())
    binary_dir = _resolve_binary_dir(binary_dirs or _default_binary_dirs())

    if package_root is None:
        return OpenCvBootstrapState(activated=False, reason="opencv package root was not found")

    if binary_dir is None:
        return OpenCvBootstrapState(activated=False, reason="opencv binary directory was not found")

    package_root_str = str(package_root)
    binary_dir_str = str(binary_dir)

    if package_root_str not in sys.path:
        sys.path.insert(0, package_root_str)

    if os.name == "nt" and hasattr(os, "add_dll_directory"):
        os.add_dll_directory(binary_dir_str)

    os.environ["PATH"] = _prepend_unique_path(os.environ.get("PATH", ""), binary_dir_str)

    return OpenCvBootstrapState(
        activated=True,
        reason="opencv cuda paths were activated",
        package_root=package_root_str,
        binary_dir=binary_dir_str,
    )
