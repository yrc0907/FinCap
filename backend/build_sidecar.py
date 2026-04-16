import shutil
import subprocess
import sys
import time
from pathlib import Path

from host_target import detect_host_target


def main() -> None:
    backend_dir = Path(__file__).resolve().parent
    repo_root = backend_dir.parent
    frontend_dir = repo_root / "frontend"
    binaries_dir = frontend_dir / "src-tauri" / "binaries"
    build_dir = backend_dir / ".pyinstaller"
    dist_dir = build_dir / "dist"
    spec_dir = build_dir / "spec"
    work_dir = build_dir / "build"

    binaries_dir.mkdir(parents=True, exist_ok=True)
    dist_dir.mkdir(parents=True, exist_ok=True)
    spec_dir.mkdir(parents=True, exist_ok=True)
    work_dir.mkdir(parents=True, exist_ok=True)

    host_target = detect_host_target()
    binary_name = "fincap-backend"
    command = [
        sys.executable,
        "-m",
        "PyInstaller",
        "--noconfirm",
        "--clean",
        "--onefile",
        "--name",
        binary_name,
        "--distpath",
        str(dist_dir),
        "--workpath",
        str(work_dir),
        "--specpath",
        str(spec_dir),
        str(backend_dir / "run.py"),
    ]

    subprocess.run(command, check=True)

    source_binary = dist_dir / f"{binary_name}.exe"
    target_binary = binaries_dir / f"{binary_name}-{host_target}.exe"
    for attempt in range(10):
        try:
            shutil.copy2(source_binary, target_binary)
            break
        except PermissionError:
            if attempt == 9:
                raise
            time.sleep(1)
    print(f"Built sidecar: {target_binary}")


if __name__ == "__main__":
    main()
