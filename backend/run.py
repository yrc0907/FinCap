import os

import uvicorn
from app import app
from services.gpu_runtime import get_gpu_runtime_summary


if __name__ == "__main__":
    runtime = get_gpu_runtime_summary()
    print(f"[Startup] FFmpeg CUDA: {runtime['ffmpeg']['reason']}")
    print(f"[Startup] Torch CUDA: {runtime['torch']['reason']}")
    print(f"[Startup] OpenCV CUDA: {runtime['opencv']['reason']}")
    uvicorn.run(
        app,
        host=os.getenv("FINCAP_BACKEND_HOST", "127.0.0.1"),
        port=int(os.getenv("FINCAP_BACKEND_PORT", "8765")),
        reload=False,
    )
