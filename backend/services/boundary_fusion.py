from __future__ import annotations

from dataclasses import dataclass
from typing import Any


@dataclass(frozen=True)
class BoundaryFusionConfig:
    gap_sec: float = 0.35
    high_confidence_score: float = 0.62
    detector_keep_score: float = 0.95
    scene_priority_margin: float = 0.08


def summarize_reused_scene_detector(
    mode: str,
    backend: str | None,
    candidate_windows: list[dict[str, Any]],
) -> dict[str, Any]:
    return {
        "mode": mode,
        "backend": backend or "reused",
        "candidateCount": len(candidate_windows),
        "hardCutCount": sum(1 for item in candidate_windows if item["cutClass"] == "hard-cut"),
        "softCutCount": sum(1 for item in candidate_windows if item["cutClass"] == "soft-cut"),
    }


def collect_scene_detector_candidates(
    suspicious_regions: list[dict[str, Any]],
    candidate_windows: list[dict[str, Any]],
) -> list[dict[str, Any]]:
    candidates: list[dict[str, Any]] = []

    for candidate_window in candidate_windows:
        resolved_window = _resolve_candidate_window_bounds(
            suspicious_regions=suspicious_regions,
            candidate_window=candidate_window,
        )
        if resolved_window is None:
            continue
        window_start_sec, window_end_sec = resolved_window
        candidates.append(
            {
                "timeSec": round(float(candidate_window["peakSec"]), 3),
                "score": round(float(candidate_window["score"]), 4),
                "signal": "scene",
                "candidateType": "scene-detector",
                "source": "+".join(candidate_window["sources"]),
                "windowStartSec": window_start_sec,
                "windowEndSec": window_end_sec,
                "cutClass": candidate_window.get("cutClass"),
            }
        )

    return candidates


def fuse_boundary_candidates(
    subject_candidates: list[dict[str, Any]],
    scene_candidates: list[dict[str, Any]],
    config: BoundaryFusionConfig,
) -> list[dict[str, Any]]:
    all_candidates = sorted(subject_candidates + scene_candidates, key=lambda item: item["timeSec"])
    if not all_candidates:
        return []

    clusters = _cluster_candidates(all_candidates, config.gap_sec)
    fused_candidates: list[dict[str, Any]] = []

    for cluster in clusters:
        primary_candidate = _select_primary_candidate(cluster, config)
        subject_score = _max_score(cluster, signal="subject")
        scene_score = _max_score(cluster, signal="scene")
        sources = sorted({item["source"] for item in cluster})
        detector_anchor = _best_candidate(
            cluster,
            predicate=lambda item: item.get("candidateType") == "scene-detector",
        )

        fused_candidate = {
            "timeSec": round(float(primary_candidate["timeSec"]), 3),
            "score": round(float(primary_candidate["score"]), 4),
            "subjectScore": _round_optional(subject_score),
            "sceneScore": _round_optional(scene_score),
            "windowStartSec": round(
                min(float(item["windowStartSec"]) for item in cluster),
                3,
            ),
            "windowEndSec": round(
                max(float(item["windowEndSec"]) for item in cluster),
                3,
            ),
            "confidence": _resolve_confidence(
                primary_candidate=primary_candidate,
                cluster=cluster,
                config=config,
            ),
            "sources": sources,
            "origin": _resolve_origin(primary_candidate, subject_score),
        }
        if detector_anchor is not None:
            fused_candidate["sceneDetectorAnchorSec"] = round(float(detector_anchor["timeSec"]), 3)
            fused_candidate["sceneDetectorAnchorScore"] = round(float(detector_anchor["score"]), 4)
            if detector_anchor.get("cutClass") is not None:
                fused_candidate["sceneDetectorCutClass"] = str(detector_anchor["cutClass"])
        fused_candidates.append(fused_candidate)

    return fused_candidates


def _resolve_candidate_window_bounds(
    suspicious_regions: list[dict[str, Any]],
    candidate_window: dict[str, Any],
) -> tuple[float, float] | None:
    if not suspicious_regions:
        return (
            round(float(candidate_window["startSec"]), 3),
            round(float(candidate_window["endSec"]), 3),
        )

    peak_sec = float(candidate_window["peakSec"])

    for region in suspicious_regions:
        if float(region["startSec"]) <= peak_sec <= float(region["endSec"]):
            return round(float(region["startSec"]), 3), round(float(region["endSec"]), 3)

    return (
        round(float(candidate_window["startSec"]), 3),
        round(float(candidate_window["endSec"]), 3),
    )


def _cluster_candidates(
    candidates: list[dict[str, Any]],
    gap_sec: float,
) -> list[list[dict[str, Any]]]:
    clusters: list[list[dict[str, Any]]] = [[candidates[0]]]

    for candidate in candidates[1:]:
        current_cluster = clusters[-1]
        if float(candidate["timeSec"]) - float(current_cluster[-1]["timeSec"]) <= gap_sec:
            current_cluster.append(candidate)
            continue

        clusters.append([candidate])

    return clusters


def _select_primary_candidate(
    cluster: list[dict[str, Any]],
    config: BoundaryFusionConfig,
) -> dict[str, Any]:
    strong_detector = _best_candidate(
        cluster,
        predicate=lambda item: item.get("candidateType") == "scene-detector"
        and float(item["score"]) >= config.detector_keep_score,
    )
    if strong_detector is not None:
        return strong_detector

    best_scene = _best_candidate(cluster, predicate=lambda item: item["signal"] == "scene")
    best_subject = _best_candidate(cluster, predicate=lambda item: item["signal"] == "subject")

    if best_scene is None:
        return best_subject  # type: ignore[return-value]

    if best_subject is None:
        return best_scene

    if float(best_scene["score"]) + config.scene_priority_margin >= float(best_subject["score"]):
        return best_scene

    return best_subject


def _best_candidate(
    cluster: list[dict[str, Any]],
    predicate: Any,
) -> dict[str, Any] | None:
    matches = [item for item in cluster if predicate(item)]
    if not matches:
        return None
    return max(matches, key=lambda item: float(item["score"]))


def _max_score(cluster: list[dict[str, Any]], signal: str) -> float | None:
    scores = [float(item["score"]) for item in cluster if item["signal"] == signal]
    return max(scores) if scores else None


def _round_optional(value: float | None) -> float | None:
    if value is None:
        return None
    return round(float(value), 4)


def _resolve_confidence(
    primary_candidate: dict[str, Any],
    cluster: list[dict[str, Any]],
    config: BoundaryFusionConfig,
) -> str:
    if (
        primary_candidate.get("candidateType") == "scene-detector"
        and float(primary_candidate["score"]) >= config.detector_keep_score
    ):
        return "high"

    signals = {item["signal"] for item in cluster}
    if len(signals) > 1 or float(primary_candidate["score"]) >= config.high_confidence_score:
        return "high"

    return "low"


def _resolve_origin(
    primary_candidate: dict[str, Any],
    subject_score: float | None,
) -> str:
    if primary_candidate.get("candidateType") == "scene-detector":
        return "scene-detector+subject" if subject_score is not None else "scene-detector"

    if primary_candidate["signal"] == "scene":
        return "scene+subject" if subject_score is not None else "scene"

    return "subject-only"
