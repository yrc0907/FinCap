from pathlib import Path

PYTHON_EXTENSIONS_PATHS = [
    str(Path(__file__).resolve().parent / "python-3.12")
] + PYTHON_EXTENSIONS_PATHS
