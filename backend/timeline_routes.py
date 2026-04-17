from __future__ import annotations

from pathlib import Path

from fastapi import APIRouter, HTTPException

from api_models import (
    AdjacentStoryReassignmentRequest,
    BoundaryCleanlinessRefineRequest,
    CorrectedEventTimelineRequest,
    DynamicSegmentGenerationRequest,
    DualSignalBoundaryDetectionRequest,
    EventMergingRequest,
    MultiscaleDetectionRequest,
    StrictShotGenerationRequest,
    VlmShotAnalysisRequest,
)
from services.boundary_cleanliness_refinement import (
    BoundaryCleanlinessConfig,
    refine_boundary_candidates,
)
from project_store import fetch_project_or_404, get_db_connection, resolve_project_video_path
from services.dual_signal_boundary_detection import (
    BoundaryFusionConfig,
    SceneBoundaryConfig,
    SubjectBoundaryConfig,
    detect_dual_signal_boundaries,
)
from services.dynamic_segment_generation import DynamicSegmentConfig, generate_dynamic_segments
from services.event_merging import EventMergeConfig, merge_dynamic_segments_into_events
from services.adjacent_story_reassignment import analyze_adjacent_story_reassignment
from services.corrected_event_timeline import generate_corrected_event_timeline
from services.multiscale_detection import (
    CoarseDetectionConfig,
    FineDetectionConfig,
    build_video_index,
    detect_full_timeline_multiscale,
)
from services.multimodal_semantic_context import NormalizedSubtitleRegion, normalize_subtitle_region
from services.strict_shot_generation import StrictShotConfig, generate_strict_shots
from services.vlm_shot_analysis import VlmShotAnalysisConfig, analyze_shot_sequence

router = APIRouter(prefix="/api/projects/{project_id}/timeline")


def _load_project_video_index(project_id: str) -> tuple[Path, dict[str, object]]:
    connection = get_db_connection()
    try:
        row = fetch_project_or_404(connection, project_id)
        video_path = resolve_project_video_path(row)
    finally:
        connection.close()

    index = build_video_index(video_path)
    return video_path, {
        "fps": round(index.fps, 3),
        "frameCount": index.frame_count,
        "durationSec": round(index.duration_sec, 3),
        "width": index.width,
        "height": index.height,
    }


@router.post("/multiscale-detect")
async def run_multiscale_detection(
    project_id: str, payload: MultiscaleDetectionRequest
) -> dict[str, object]:
    video_path, _ = _load_project_video_index(project_id)
    try:
        return detect_full_timeline_multiscale(
            video_path=video_path,
            coarse_config=CoarseDetectionConfig(
                window_sec=payload.coarse_window_sec,
                stride_sec=payload.coarse_stride_sec,
                score_threshold=payload.coarse_score_threshold,
                merge_gap_sec=payload.coarse_merge_gap_sec,
            ),
            fine_config=FineDetectionConfig(
                search_radius_sec=payload.fine_search_radius_sec,
                sample_step_sec=payload.fine_sample_step_sec,
                score_threshold=payload.fine_score_threshold,
            ),
            scene_detector_mode=payload.scene_detector_mode,
        )
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Full timeline multi-scale detection failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/dual-signal-boundary-detect")
async def run_dual_signal_boundary_detection(
    project_id: str, payload: DualSignalBoundaryDetectionRequest
) -> dict[str, object]:
    video_path, _ = _load_project_video_index(project_id)
    try:
        return detect_dual_signal_boundaries(
            video_path=video_path,
            suspicious_regions=[region.model_dump() for region in payload.suspiciousRegions],
            subject_config=SubjectBoundaryConfig(
                sample_step_sec=payload.subject_sample_step_sec,
                core_ratio=payload.subject_core_ratio,
                score_threshold=payload.subject_score_threshold,
            ),
            scene_config=SceneBoundaryConfig(
                sample_step_sec=payload.scene_sample_step_sec,
                score_threshold=payload.scene_score_threshold,
            ),
            fusion_config=BoundaryFusionConfig(
                gap_sec=payload.fusion_gap_sec,
                high_confidence_score=payload.fusion_high_confidence_score,
            ),
            scene_detector_mode=payload.scene_detector_mode,
            scene_detector_candidates=(
                None
                if payload.sceneDetectorCandidates is None
                else [candidate.model_dump() for candidate in payload.sceneDetectorCandidates]
            ),
            scene_detector_backend=payload.sceneDetectorBackend,
        )
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Dual-signal boundary detection failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/boundary-cleanliness-refine")
async def run_boundary_cleanliness_refine(
    project_id: str, payload: BoundaryCleanlinessRefineRequest
) -> dict[str, object]:
    video_path, video_index = _load_project_video_index(project_id)
    try:
        result = refine_boundary_candidates(
            video_path=video_path,
            boundary_candidates=[candidate.model_dump() for candidate in payload.boundaryCandidates],
            fps=float(video_index["fps"]),
            frame_count=int(video_index["frameCount"]),
            config=BoundaryCleanlinessConfig(
                search_radius_frames=payload.search_radius_frames,
                resize_width=payload.resize_width,
                resize_height=payload.resize_height,
                stability_penalty=payload.stability_penalty,
                min_improvement=payload.min_improvement,
                require_gpu=payload.require_gpu,
            ),
        )
        return {
            "videoIndex": video_index,
            "inputBoundaryCount": len(payload.boundaryCandidates),
            "boundaryCandidates": result,
        }
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Boundary cleanliness refinement failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/dynamic-segment-generate")
async def run_dynamic_segment_generation(
    project_id: str, payload: DynamicSegmentGenerationRequest
) -> dict[str, object]:
    video_path, video_index = _load_project_video_index(project_id)
    try:
        result = generate_dynamic_segments(
            video_duration_sec=float(video_index["durationSec"]),
            boundary_candidates=[candidate.model_dump() for candidate in payload.boundaryCandidates],
            config=DynamicSegmentConfig(
                min_segment_sec=payload.min_segment_sec,
                abnormal_short_sec=payload.abnormal_short_sec,
                dedupe_epsilon_sec=payload.dedupe_epsilon_sec,
            ),
        )
        result["videoIndex"] = video_index
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Dynamic segment generation failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/strict-shot-generate")
async def run_strict_shot_generation(
    project_id: str, payload: StrictShotGenerationRequest
) -> dict[str, object]:
    _, video_index = _load_project_video_index(project_id)
    try:
        result = generate_strict_shots(
            video_duration_sec=float(video_index["durationSec"]),
            boundary_candidates=[candidate.model_dump() for candidate in payload.boundaryCandidates],
            config=StrictShotConfig(
                dedupe_epsilon_sec=payload.dedupe_epsilon_sec,
                min_shot_sec=payload.min_shot_sec,
                abnormal_short_sec=payload.abnormal_short_sec,
            ),
        )
        result["videoIndex"] = video_index
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Strict shot generation failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/event-merge")
async def run_event_merging(
    project_id: str, payload: EventMergingRequest
) -> dict[str, object]:
    _, video_index = _load_project_video_index(project_id)
    try:
        result = merge_dynamic_segments_into_events(
            dynamic_segments=[segment.model_dump() for segment in payload.dynamicSegments],
            boundary_candidates=[candidate.model_dump() for candidate in payload.boundaryCandidates],
            config=EventMergeConfig(
                target_event_sec=payload.target_event_sec,
                max_event_sec=payload.max_event_sec,
                short_segment_sec=payload.short_segment_sec,
                substantial_segment_sec=payload.substantial_segment_sec,
                keep_boundary_score=payload.keep_boundary_score,
                strong_boundary_score=payload.strong_boundary_score,
            ),
        )
        result["videoIndex"] = video_index
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Event merging failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/vlm-shot-analyze")
async def run_vlm_shot_analysis(
    project_id: str, payload: VlmShotAnalysisRequest
) -> dict[str, object]:
    video_path, video_index = _load_project_video_index(project_id)
    try:
        subtitle_region = normalize_subtitle_region(
            None
            if not payload.enableSubtitleRegion or payload.subtitleRegion is None
            else NormalizedSubtitleRegion(
                x=payload.subtitleRegion.x,
                y=payload.subtitleRegion.y,
                width=payload.subtitleRegion.width,
                height=payload.subtitleRegion.height,
            )
        )
        result = analyze_shot_sequence(
            video_path=video_path,
            shots=[shot.model_dump() for shot in payload.shots],
            vlm_config=payload.vlmConfig.model_dump(),
            config=VlmShotAnalysisConfig(
                group_size=payload.group_size,
                keyframes_per_shot=payload.keyframes_per_shot,
                highlight_threshold=payload.highlight_threshold,
                enable_ocr=payload.enableOcr,
                enable_auto_asr=payload.enableAutoAsr,
                enable_subtitle_region=payload.enableSubtitleRegion,
                subtitle_region=subtitle_region,
                prompt_profile=payload.promptProfile,
            ),
            ocr_entries=[entry.model_dump() for entry in payload.ocrEntries],
            asr_text=payload.asrText,
            asr_segments=[segment.model_dump() for segment in payload.asrSegments],
            character_references=[reference.model_dump() for reference in payload.characterReferences],
            frame_overrides=[override.model_dump() for override in payload.frameOverrides],
        )
        result["videoIndex"] = video_index
        result["inputShotCount"] = len(payload.shots)
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] VLM shot analysis failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/adjacent-story-reassign")
async def run_adjacent_story_reassignment(
    project_id: str, payload: AdjacentStoryReassignmentRequest
) -> dict[str, object]:
    _, video_index = _load_project_video_index(project_id)
    try:
        result = analyze_adjacent_story_reassignment(
            groups=[group.model_dump() for group in payload.groups],
            llm_config=payload.llmConfig.model_dump(),
        )
        result["videoIndex"] = video_index
        result["inputGroupCount"] = len(payload.groups)
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Adjacent story reassignment failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc


@router.post("/corrected-event-timeline")
async def run_corrected_event_timeline(
    project_id: str, payload: CorrectedEventTimelineRequest
) -> dict[str, object]:
    _, video_index = _load_project_video_index(project_id)
    try:
        result = generate_corrected_event_timeline(
            groups=[group.model_dump() for group in payload.groups],
            adjacent_pairs=[pair.model_dump() for pair in payload.adjacentPairs],
            shots=[shot.model_dump() for shot in payload.shots],
            fps=float(video_index["fps"]),
            video_duration_sec=float(video_index["durationSec"]),
            frame_count=int(video_index["frameCount"]),
        )
        result["videoIndex"] = video_index
        return result
    except HTTPException:
        raise
    except Exception as exc:
        print(f"[Error] Corrected event timeline failed: {exc}")
        raise HTTPException(status_code=500, detail=str(exc)) from exc
