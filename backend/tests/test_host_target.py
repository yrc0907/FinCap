from __future__ import annotations

import unittest

from host_target import detect_host_target


class HostTargetTests(unittest.TestCase):
    def test_detects_windows_x64_target_without_rustc(self) -> None:
        self.assertEqual(
            detect_host_target(system_name="Windows", machine_name="AMD64"),
            "x86_64-pc-windows-msvc",
        )

    def test_detects_windows_arm64_target_without_rustc(self) -> None:
        self.assertEqual(
            detect_host_target(system_name="Windows", machine_name="ARM64"),
            "aarch64-pc-windows-msvc",
        )

    def test_raises_for_unsupported_platform(self) -> None:
        with self.assertRaises(RuntimeError):
            detect_host_target(system_name="Plan9", machine_name="mips")


if __name__ == "__main__":
    unittest.main()
