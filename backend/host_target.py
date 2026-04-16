from __future__ import annotations

import platform


WINDOWS_TARGETS = {
    "amd64": "x86_64-pc-windows-msvc",
    "x86_64": "x86_64-pc-windows-msvc",
    "arm64": "aarch64-pc-windows-msvc",
    "aarch64": "aarch64-pc-windows-msvc",
}

LINUX_TARGETS = {
    "amd64": "x86_64-unknown-linux-gnu",
    "x86_64": "x86_64-unknown-linux-gnu",
    "arm64": "aarch64-unknown-linux-gnu",
    "aarch64": "aarch64-unknown-linux-gnu",
}

DARWIN_TARGETS = {
    "x86_64": "x86_64-apple-darwin",
    "arm64": "aarch64-apple-darwin",
    "aarch64": "aarch64-apple-darwin",
}


def detect_host_target(
    system_name: str | None = None,
    machine_name: str | None = None,
) -> str:
    resolved_system = (system_name or platform.system()).strip().lower()
    resolved_machine = (machine_name or platform.machine()).strip().lower()

    if resolved_system == "windows":
        target = WINDOWS_TARGETS.get(resolved_machine)
    elif resolved_system == "linux":
        target = LINUX_TARGETS.get(resolved_machine)
    elif resolved_system == "darwin":
        target = DARWIN_TARGETS.get(resolved_machine)
    else:
        target = None

    if target is None:
        raise RuntimeError(
            f"Unsupported host platform: system={resolved_system}, machine={resolved_machine}"
        )
    return target


def main() -> None:
    print(detect_host_target())


if __name__ == "__main__":
    main()
