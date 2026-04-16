from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Any

from services.adjacent_story_reassignment import analyze_adjacent_story_reassignment
from services.corrected_event_timeline import generate_corrected_event_timeline
from services.functional_clip_export import export_functional_clips
from services.lighthouse_segments import LighthouseSegmentConfig, extract_lighthouse_segments
from services.shot_level_vlm_segments import extract_shot_level_vlm_segments
from services.vlm_shot_analysis import VlmShotAnalysisConfig, analyze_shot_sequence


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compare shot-level VLM clips against Lighthouse clips.")
    parser.add_argument("--manifest", required=True, help="Strict-shot manifest path.")
    parser.add_argument("--output", required=True, help="Output directory.")
    parser.add_argument("--video", help="Optional source video path override.")
    parser.add_argument("--vlm-endpoint", required=True, help="OpenAI-compatible endpoint.")
    parser.add_argument("--vlm-key", required=True, help="OpenAI-compatible API key.")
    parser.add_argument("--vlm-model", required=True, help="Vision-capable model name.")
    parser.add_argument("--group-size", type=int, default=3, help="Strict shots per VLM group.")
    parser.add_argument("--keyframes-per-shot", type=int, default=3, help="Sampled keyframes per shot.")
    parser.add_argument("--highlight-threshold", type=float, default=0.7, help="Highlight score threshold.")
    parser.add_argument("--lighthouse-python", help="Optional Lighthouse runtime Python path.")
    parser.add_argument("--lighthouse-runner", help="Optional Lighthouse runner script path.")
    parser.add_argument("--lighthouse-repo", help="Optional Lighthouse repo path.")
    parser.add_argument("--lighthouse-weight-dir", help="Optional Lighthouse checkpoint directory.")
    parser.add_argument("--lighthouse-max-clips", type=int, default=5, help="Exported Lighthouse peak clips.")
    return parser.parse_args()


def run_comparison(
    manifest_path: Path,
    output_dir: Path,
    vlm_config: dict[str, str],
    video_path: Path | None = None,
    shot_analysis_config: VlmShotAnalysisConfig | None = None,
    lighthouse_config: LighthouseSegmentConfig | None = None,
) -> dict[str, Any]:
    manifest = json.loads(Path(manifest_path).read_text(encoding="utf-8"))
    resolved_video_path = _resolve_video_path(manifest, video_path)
    shots = _extract_shots(manifest)
    output_dir.mkdir(parents=True, exist_ok=True)

    active_shot_config = shot_analysis_config or VlmShotAnalysisConfig()
    groups_result = analyze_shot_sequence(
        video_path=resolved_video_path,
        shots=shots,
        vlm_config=vlm_config,
        config=active_shot_config,
    )
    adjacent_result = analyze_adjacent_story_reassignment(
        groups=groups_result["groups"],
        llm_config=vlm_config,
    )
    corrected_result = generate_corrected_event_timeline(
        groups=groups_result["groups"],
        adjacent_pairs=adjacent_result["pairs"],
        shots=shots,
    )
    pipeline_context = {
        "video": str(resolved_video_path.resolve()),
        "shots": shots,
        "groups": groups_result["groups"],
        "adjacentPairs": adjacent_result["pairs"],
        "events": corrected_result["events"],
    }
    _write_json(output_dir / "pipeline_context.json", pipeline_context)

    shot_level_result = extract_shot_level_vlm_segments(
        video_path=resolved_video_path,
        events=corrected_result["events"],
        groups=groups_result["groups"],
        shots=shots,
        vlm_config=vlm_config,
    )
    shot_level_dir = output_dir / "shot-level-vlm"
    shot_level_export = _export_route_clips(
        video_path=resolved_video_path,
        clips=shot_level_result.get("peakClips", []),
        output_dir=shot_level_dir / "peak-clips",
    )
    _write_json(
        shot_level_dir / "result.json",
        {
            "analysis": shot_level_result,
            "export": shot_level_export,
        },
    )

    active_lighthouse_config = lighthouse_config or LighthouseSegmentConfig()
    lighthouse_result = extract_lighthouse_segments(
        video_path=resolved_video_path,
        shots=shots,
        config=active_lighthouse_config,
    )
    lighthouse_dir = output_dir / "lighthouse"
    lighthouse_export = _export_route_clips(
        video_path=resolved_video_path,
        clips=lighthouse_result.get("peakClips", []),
        output_dir=lighthouse_dir / "peak-clips",
    )
    _write_json(
        lighthouse_dir / "result.json",
        {
            "analysis": lighthouse_result,
            "export": lighthouse_export,
        },
    )

    summary = {
        "video": str(resolved_video_path.resolve()),
        "shotCount": len(shots),
        "groupCount": len(groups_result["groups"]),
        "eventCount": len(corrected_result["events"]),
        "routes": {
            "shotLevelVlm": {
                "status": "ok",
                "peakClipCount": len(shot_level_result.get("peakClips", [])),
                "ranges": _collect_ranges(shot_level_result.get("peakClips", [])),
                "outputDir": str(shot_level_dir.resolve()),
            },
            "lighthouse": {
                "status": lighthouse_result.get("status", "unknown"),
                "peakClipCount": len(lighthouse_result.get("peakClips", [])),
                "ranges": _collect_ranges(lighthouse_result.get("peakClips", [])),
                "outputDir": str(lighthouse_dir.resolve()),
            },
        },
    }
    _write_json(output_dir / "comparison_summary.json", summary)
    _print_summary(summary)
    return summary


def _resolve_video_path(manifest: dict[str, Any], video_path: Path | None) -> Path:
    candidate = video_path or manifest.get("video")
    if not candidate:
        raise ValueError("The strict-shot manifest does not include a video path.")
    return Path(candidate).resolve()


def _extract_shots(manifest: dict[str, Any]) -> list[dict[str, Any]]:
    strict_shots = manifest.get("strictShots", {})
    shots = strict_shots.get("shots") or manifest.get("shots")
    if not isinstance(shots, list) or not shots:
        raise ValueError("The strict-shot manifest does not include any shots.")
    return shots


def _export_route_clips(
    video_path: Path,
    clips: list[dict[str, Any]],
    output_dir: Path,
) -> dict[str, Any]:
    if not clips:
        return {"clips": []}
    return export_functional_clips(video_path=video_path, clips=clips, output_dir=output_dir)


def _write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")


def _collect_ranges(clips: list[dict[str, Any]]) -> list[str]:
    return [
        f"{float(clip['startSec']):.3f}-{float(clip['endSec']):.3f}"
        for clip in clips
    ]


def _print_summary(summary: dict[str, Any]) -> None:
    shot_route = summary["routes"]["shotLevelVlm"]
    lighthouse_route = summary["routes"]["lighthouse"]
    print(
        f"[ShotLevelVLM] peaks={shot_route['peakClipCount']} "
        f"ranges={', '.join(shot_route['ranges']) or 'none'}"
    )
    print(
        f"[Lighthouse] status={lighthouse_route['status']} "
        f"peaks={lighthouse_route['peakClipCount']} "
        f"ranges={', '.join(lighthouse_route['ranges']) or 'none'}"
    )
    print(f"[Done] Summary: {Path(summary['routes']['shotLevelVlm']['outputDir']).parent / 'comparison_summary.json'}")


def main() -> None:
    args = parse_args()
    lighthouse_config = LighthouseSegmentConfig(
        max_peak_clips=args.lighthouse_max_clips,
        runner_python=Path(args.lighthouse_python).resolve()
        if args.lighthouse_python
        else LighthouseSegmentConfig().runner_python,
        runner_script=Path(args.lighthouse_runner).resolve()
        if args.lighthouse_runner
        else LighthouseSegmentConfig().runner_script,
        repo_path=Path(args.lighthouse_repo).resolve()
        if args.lighthouse_repo
        else LighthouseSegmentConfig().repo_path,
        weight_dir=Path(args.lighthouse_weight_dir).resolve()
        if args.lighthouse_weight_dir
        else LighthouseSegmentConfig().weight_dir,
    )
    run_comparison(
        manifest_path=Path(args.manifest).resolve(),
        output_dir=Path(args.output).resolve(),
        video_path=Path(args.video).resolve() if args.video else None,
        vlm_config={
            "endpoint": args.vlm_endpoint,
            "key": args.vlm_key,
            "model": args.vlm_model,
        },
        shot_analysis_config=VlmShotAnalysisConfig(
            group_size=args.group_size,
            keyframes_per_shot=args.keyframes_per_shot,
            highlight_threshold=args.highlight_threshold,
        ),
        lighthouse_config=lighthouse_config,
    )


if __name__ == "__main__":
    main()
