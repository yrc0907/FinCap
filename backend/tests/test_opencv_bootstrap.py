from __future__ import annotations

import os
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

from opencv_bootstrap import activate_local_opencv_cuda


class OpenCvBootstrapTests(unittest.TestCase):
    def test_activate_local_opencv_cuda_registers_package_and_binary_paths(self) -> None:
        original_sys_path = list(sys.path)
        original_path = os.environ.get("PATH", "")
        original_cv2 = sys.modules.pop("cv2", None)

        with tempfile.TemporaryDirectory() as temp_dir:
            temp_path = Path(temp_dir)
            package_root = temp_path / "site-packages"
            cv2_package = package_root / "cv2"
            bin_dir = temp_path / "bin"

            cv2_package.mkdir(parents=True)
            bin_dir.mkdir(parents=True)
            (cv2_package / "__init__.py").write_text("# test package\n", encoding="utf-8")

            try:
                result = activate_local_opencv_cuda(
                    package_roots=[package_root],
                    binary_dirs=[bin_dir],
                )
            finally:
                sys.path[:] = original_sys_path
                os.environ["PATH"] = original_path
                if original_cv2 is not None:
                    sys.modules["cv2"] = original_cv2

        self.assertTrue(result.activated)
        self.assertEqual(result.package_root, str(package_root))
        self.assertEqual(result.binary_dir, str(bin_dir))
        self.assertEqual(sys.path, original_sys_path)
        self.assertEqual(os.environ.get("PATH", ""), original_path)

    def test_activate_local_opencv_cuda_returns_inactive_when_paths_are_missing(self) -> None:
        result = activate_local_opencv_cuda(
            package_roots=[Path("C:/missing-opencv-package-root")],
            binary_dirs=[Path("C:/missing-opencv-bin-root")],
        )

        self.assertFalse(result.activated)
        self.assertIsNone(result.package_root)
        self.assertIsNone(result.binary_dir)

    def test_importing_services_auto_activates_local_opencv_cuda_paths(self) -> None:
        with tempfile.TemporaryDirectory() as temp_dir:
            temp_path = Path(temp_dir)
            package_root = temp_path / "site-packages"
            cv2_package = package_root / "cv2"
            bin_dir = temp_path / "bin"

            cv2_package.mkdir(parents=True)
            bin_dir.mkdir(parents=True)
            (cv2_package / "__init__.py").write_text("# startup test package\n", encoding="utf-8")

            env = os.environ.copy()
            env["FINCAP_OPENCV_PYTHON_ROOT"] = str(package_root)
            env["FINCAP_OPENCV_BIN_DIR"] = str(bin_dir)

            command = [
                sys.executable,
                "-c",
                (
                    "import json, os, sys; "
                    "import services; "
                    "print(json.dumps({'sys_path': sys.path, 'path': os.environ.get('PATH', '')}))"
                ),
            ]
            result = subprocess.run(
                command,
                cwd=str(Path(__file__).resolve().parents[1]),
                env=env,
                capture_output=True,
                text=True,
                check=True,
            )
            payload = json.loads(result.stdout.strip())

        self.assertIn(str(package_root), payload["sys_path"])
        self.assertTrue(
            payload["path"] == str(bin_dir)
            or payload["path"].startswith(str(bin_dir) + os.pathsep)
        )


if __name__ == "__main__":
    unittest.main()
