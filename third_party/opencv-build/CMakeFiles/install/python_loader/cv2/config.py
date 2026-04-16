import os

BINARIES_PATHS = [
    os.path.join('C:/FinCap/backend/.opencv-cuda-install', 'x64/vc17/bin'),
    os.path.join(os.getenv('CUDA_PATH', 'C:/PROGRA~1/NVIDIA~2/CUDA/v13.2'), 'bin')
] + BINARIES_PATHS
