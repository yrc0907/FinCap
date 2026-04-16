import os
from pathlib import Path

THIRD_PARTY_DIR = Path(__file__).resolve().parents[2]

BINARIES_PATHS = [
    str(THIRD_PARTY_DIR / "opencv-4x-install" / "x64" / "vc17" / "bin"),
    os.path.join(
        os.getenv("CUDA_PATH", "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.2"),
        "bin/x64",
    ),
] + BINARIES_PATHS
