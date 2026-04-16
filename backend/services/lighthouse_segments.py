from __future__ import annotations

import json
import subprocess
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any


def _default_queries() -> tuple[tuple[str, str], ...]:
    return (
        ("peak", "the highest impact, climactic, high-energy moment"),
        ("conflict", "the strongest conflict escalation or action confrontation"),
        ("result", "the immediate aftermath, payoff, or result moment"),
    )


def _default_runner_python() -> Path:
    return Path("C:/FinCap/.venv-lighthouse/Scripts/python.exe")


def _default_runner_script() -> Path:
    return Path(__file__).resolve().parents[1] / "lighthouse_inference_runner.py"


def _default_repo_path() -> Path:
    return Path("C:/FinCap/_tmp_lighthouse")


def _default_weight_dir() -> Path:
    return _default_repo_path() / "gradio_demo" / "weights"


@dataclass(frozen=True)
class LighthouseSegmentConfig:
    queries: tuple[tuple[str, str], ...] = field(default_factory=_default_queries)
    min_window_score: float = 0.5
    max_windows_per_query: int = 3
    max_peak_clips: int = 5
    runner_python: Path = field(default_factory=_default_runner_python)
    runner_script: Path = field(default_factory=_default_runner_script)
    repo_path: Path = field(default_factory=_default_repo_path)
    weight_dir: Path = field(default_factory=_default_weight_dir)
    model_name: str = "cg_detr"
    feature_name: str = "clip"
    prefer_gpu: bool = True


def extract_lighthouse_segments(
    video_path: Path,
    shots: list[dict[str, Any]],
    config: LighthouseSegmentConfig | None = None,
) -> dict[str, Any]:
    active_config = config or LighthouseSegmentConfig()
    runtime = inspect_lighthouse_runtime(active_config)
    if not runtime["available"]:
        return {
            "status": "unavailable",
            "runtime": runtime,
            "queryResults": [],
            "functionalClips": [],
            "peakClips": [],
            "summary": {
                "queryCount": len(active_config.queries),
                "queryResultCount": 0,
                "peakClipCount": 0,
            },
        }

    query_defs = [{"name": name, "text": text} for name, text in active_config.queries]
    raw_result = run_lighthouse_inference(
        video_path=video_path,
        query_defs=query_defs,
        config=active_config,
        runtime=runtime,
    )
    query_results = _normalize_query_results(
        raw_query_results=raw_result.get("queryResults", []),
        shots=shots,
        config=active_config,
    )
    peak_clips = _merge_peak_clips(query_results, active_config.max_peak_clips)
    return {
        "status": str(raw_result.get("status", "ok")),
        "runtime": {
            **runtime,
            "device": raw_result.get("device"),
            "featureName": raw_result.get("featureName", active_config.feature_name),
            "modelName": raw_result.get("modelName", active_config.model_name),
        },
        "queryResults": query_results,
        "functionalClips": peak_clips,
        "peakClips": peak_clips,
        "summary": {
            "queryCount": len(query_defs),
            "queryResultCount": len(query_results),
            "peakClipCount": len(peak_clips),
        },
    }


def inspect_lighthouse_runtime(config: LighthouseSegmentConfig) -> dict[str, Any]:
    runner_python = Path(config.runner_python)
    runner_script = Path(config.runner_script)
    repo_path = Path(config.repo_path)
    issues: list[str] = []

    if not runner_python.exists():
        issues.append(f"Missing Lighthouse Python runtime: {runner_python}")
    if not runner_script.exists():
        issues.append(f"Missing Lighthouse runner script: {runner_script}")
    if not repo_path.exists():
        issues.append(f"Missing Lighthouse repo path: {repo_path}")

    return {
        "available": len(issues) == 0,
        "python": str(runner_python) if runner_python.exists() else None,
        "runner": str(runner_script) if runner_script.exists() else None,
        "repo": str(repo_path),
        "issues": issues,
    }


def run_lighthouse_inference(
    video_path: Path,
    query_defs: list[dict[str, str]],
    config: LighthouseSegmentConfig,
    runtime: dict[str, Any],
) -> dict[str, Any]:
    request_payload = {
        "videoPath": str(video_path.resolve()),
        "queries": query_defs,
        "repoPath": str(Path(config.repo_path).resolve()),
        "weightDir": str(Path(config.weight_dir).resolve()),
        "modelName": config.model_name,
        "featureName": config.feature_name,
        "preferGpu": bool(config.prefer_gpu),
    }
    with tempfile.TemporaryDirectory(prefix="lighthouse-run-") as temp_dir:
        input_path = Path(temp_dir) / "request.json"
        output_path = Path(temp_dir) / "result.json"
        input_path.write_text(json.dumps(request_payload, ensure_ascii=False, indent=2), encoding="utf-8")
        command = [
            str(runtime["python"]),
            str(runtime["runner"]),
            "--input",
            str(input_path),
            "--output",
            str(output_path),
        ]
        completed = subprocess.run(
            command,
            check=False,
            capture_output=True,
            text=True,
        )
        if completed.returncode != 0:
            detail = completed.stderr.strip() or completed.stdout.strip() or "Lighthouse runner failed."
            raise RuntimeError(detail)
        if not output_path.exists():
            raise RuntimeError("Lighthouse runner did not write a result file.")
        return json.loads(output_path.read_text(encoding="utf-8"))


def _normalize_query_results(
    raw_query_results: list[dict[str, Any]],
    shots: list[dict[str, Any]],
    config: LighthouseSegmentConfig,
) -> list[dict[str, Any]]:
    ordered_shots = sorted(shots, key=lambda item: float(item["startSec"]))
    normalized: list[dict[str, Any]] = []
    for raw_query in raw_query_results:
        windows: list[dict[str, Any]] = []
        for rank, window in enumerate(raw_query.get("predRelevantWindows", []), start=1):
            start_sec, end_sec, score = _parse_window(window)
            if start_sec is None or end_sec is None or score is None:
                continue
            if score < config.min_window_score:
                continue
            snapped = _snap_window_to_shots(start_sec, end_sec, ordered_shots)
            if snapped is None:
                continue
            windows.append(
                {
                    "rank": len(windows) + 1,
                    "rawStartSec": round(start_sec, 3),
                    "rawEndSec": round(end_sec, 3),
                    "rawDurationSec": round(max(0.0, end_sec - start_sec), 3),
                    "score": round(score, 4),
                    "snappedStartSec": snapped["startSec"],
                    "snappedEndSec": snapped["endSec"],
                    "snappedDurationSec": snapped["durationSec"],
                    "sourceShotIndexes": snapped["sourceShotIndexes"],
                }
            )
            if len(windows) >= config.max_windows_per_query:
                break

        normalized.append(
            {
                "queryName": str(raw_query.get("queryName", "")).strip() or "query",
                "queryText": str(raw_query.get("queryText", "")).strip(),
                "windows": windows,
                "saliencyCount": len(raw_query.get("predSaliencyScores", [])),
            }
        )
    return normalized


def _parse_window(window: Any) -> tuple[float | None, float | None, float | None]:
    if not isinstance(window, (list, tuple)) or len(window) < 3:
        return None, None, None
    try:
        start_sec = float(window[0])
        end_sec = float(window[1])
        score = float(window[2])
    except (TypeError, ValueError):
        return None, None, None
    if end_sec <= start_sec:
        return None, None, None
    return start_sec, end_sec, score


def _snap_window_to_shots(
    start_sec: float,
    end_sec: float,
    shots: list[dict[str, Any]],
) -> dict[str, Any] | None:
    overlapping_shots = [
        shot
        for shot in shots
        if float(shot["endSec"]) > start_sec and float(shot["startSec"]) < end_sec
    ]
    if not overlapping_shots:
        return None
    snapped_start = round(float(overlapping_shots[0]["startSec"]), 3)
    snapped_end = round(float(overlapping_shots[-1]["endSec"]), 3)
    return {
        "startSec": snapped_start,
        "endSec": snapped_end,
        "durationSec": round(snapped_end - snapped_start, 3),
        "sourceShotIndexes": [int(shot["index"]) for shot in overlapping_shots],
    }


def _merge_peak_clips(
    query_results: list[dict[str, Any]],
    max_peak_clips: int,
) -> list[dict[str, Any]]:
    merged: dict[tuple[int, ...], dict[str, Any]] = {}
    for query in query_results:
        query_name = str(query["queryName"])
        for window in query["windows"]:
            key = tuple(int(index) for index in window["sourceShotIndexes"])
            if key not in merged:
                merged[key] = {
                    "type": "peak",
                    "label": f"lighthouse_{query_name}",
                    "startSec": window["snappedStartSec"],
                    "endSec": window["snappedEndSec"],
                    "durationSec": window["snappedDurationSec"],
                    "score": window["score"],
                    "reason": f"Lighthouse query match: {query_name}",
                    "sourceShotIndexes": list(window["sourceShotIndexes"]),
                    "sourceQueries": [query_name],
                }
                continue
            merged_clip = merged[key]
            if float(window["score"]) > float(merged_clip["score"]):
                merged_clip["label"] = f"lighthouse_{query_name}"
                merged_clip["score"] = window["score"]
                merged_clip["reason"] = f"Lighthouse query match: {query_name}"
            merged_clip["sourceQueries"] = sorted(set(merged_clip["sourceQueries"] + [query_name]))

    ordered = sorted(
        merged.values(),
        key=lambda item: (-float(item["score"]), float(item["startSec"]), float(item["endSec"])),
    )[:max_peak_clips]
    for index, clip in enumerate(ordered, start=1):
        clip["index"] = index
    return ordered
