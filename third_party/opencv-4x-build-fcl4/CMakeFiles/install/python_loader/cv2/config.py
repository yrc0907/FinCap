import os

BINARIES_PATHS = [
    os.path.join('C:/FinCap/third_party/opencv-4x-install', 'x64/vc17/bin'),
    os.path.join(os.getenv('CUDA_PATH', 'C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.2'), 'bin/x64')
] + BINARIES_PATHS
