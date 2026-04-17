from __future__ import annotations

from pydantic import BaseModel, Field

SCENE_DETECTOR_MODE_PATTERN = "^(pyscenedetect|transnetv2-cuda)$"


class TtsRequest(BaseModel):
    text: str = Field(default="This is a test from FinCap.", min_length=1, max_length=1000)
    voice: str = Field(min_length=1)


class RenameProjectRequest(BaseModel):
    name: str = Field(min_length=1, max_length=200)


class MultiscaleDetectionRequest(BaseModel):
    coarse_window_sec: float = Field(default=2.0, ge=0.4, le=12.0)
    coarse_stride_sec: float = Field(default=0.5, ge=0.04, le=4.0)
    coarse_score_threshold: float = Field(default=0.58, ge=0.0, le=1.0)
    coarse_merge_gap_sec: float = Field(default=1.2, ge=0.0, le=8.0)
    fine_search_radius_sec: float = Field(default=1.0, ge=0.2, le=4.0)
    fine_sample_step_sec: float = Field(default=0.08, ge=0.01, le=0.5)
    fine_score_threshold: float = Field(default=0.5, ge=0.0, le=1.0)
    scene_detector_mode: str = Field(default="pyscenedetect", pattern=SCENE_DETECTOR_MODE_PATTERN)


class SuspiciousRegionRequest(BaseModel):
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    peakSec: float = Field(ge=0.0)
    coarsePeakSec: float | None = Field(default=None, ge=0.0)
    score: float = Field(default=0.0, ge=0.0, le=1.0)
    confidence: str | None = None
    sources: list[str] = Field(default_factory=list)


class SceneDetectorCandidateRequest(BaseModel):
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    peakSec: float = Field(ge=0.0)
    score: float = Field(default=0.0, ge=0.0, le=1.0)
    cutClass: str = Field(pattern="^(hard-cut|soft-cut)$")
    sources: list[str] = Field(default_factory=list)


class DualSignalBoundaryDetectionRequest(BaseModel):
    suspiciousRegions: list[SuspiciousRegionRequest] = Field(default_factory=list)
    subject_sample_step_sec: float = Field(default=0.12, ge=0.02, le=1.0)
    subject_core_ratio: float = Field(default=0.58, ge=0.2, le=0.95)
    subject_score_threshold: float = Field(default=0.46, ge=0.0, le=1.0)
    scene_sample_step_sec: float = Field(default=0.12, ge=0.02, le=1.0)
    scene_score_threshold: float = Field(default=0.48, ge=0.0, le=1.0)
    fusion_gap_sec: float = Field(default=0.35, ge=0.0, le=2.0)
    fusion_high_confidence_score: float = Field(default=0.62, ge=0.0, le=1.0)
    scene_detector_mode: str = Field(default="pyscenedetect", pattern=SCENE_DETECTOR_MODE_PATTERN)
    sceneDetectorCandidates: list[SceneDetectorCandidateRequest] | None = None
    sceneDetectorBackend: str | None = None


class BoundaryCandidateRequest(BaseModel):
    timeSec: float = Field(ge=0.0)
    score: float = Field(default=0.0, ge=0.0, le=1.0)
    subjectScore: float | None = Field(default=None, ge=0.0, le=1.0)
    sceneScore: float | None = Field(default=None, ge=0.0, le=1.0)
    windowStartSec: float = Field(ge=0.0)
    windowEndSec: float = Field(ge=0.0)
    confidence: str | None = None
    sources: list[str] = Field(default_factory=list)
    origin: str | None = None


class BoundaryCleanlinessRefineRequest(BaseModel):
    boundaryCandidates: list[BoundaryCandidateRequest] = Field(default_factory=list)
    search_radius_frames: int = Field(default=2, ge=1, le=6)
    resize_width: int = Field(default=320, ge=64, le=1280)
    resize_height: int = Field(default=180, ge=64, le=720)
    stability_penalty: float = Field(default=0.5, ge=0.0, le=2.0)
    min_improvement: float = Field(default=0.02, ge=0.0, le=1.0)
    require_gpu: bool = True


class DynamicSegmentGenerationRequest(BaseModel):
    boundaryCandidates: list[BoundaryCandidateRequest] = Field(default_factory=list)
    min_segment_sec: float = Field(default=1.6, ge=0.2, le=12.0)
    abnormal_short_sec: float = Field(default=1.0, ge=0.1, le=12.0)
    dedupe_epsilon_sec: float = Field(default=0.05, ge=0.001, le=1.0)


class DynamicSegmentRequest(BaseModel):
    index: int = Field(ge=1)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    durationSec: float = Field(ge=0.0)
    startBoundarySec: float | None = Field(default=None, ge=0.0)
    endBoundarySec: float | None = Field(default=None, ge=0.0)


class StrictShotGenerationRequest(BaseModel):
    boundaryCandidates: list[BoundaryCandidateRequest] = Field(default_factory=list)
    dedupe_epsilon_sec: float = Field(default=0.05, ge=0.001, le=1.0)
    min_shot_sec: float = Field(default=0.15, ge=0.01, le=4.0)
    abnormal_short_sec: float = Field(default=0.3, ge=0.05, le=12.0)


class ShotRequest(BaseModel):
    index: int = Field(ge=1)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    durationSec: float = Field(ge=0.0)


class SubtitleRegionRequest(BaseModel):
    x: float = Field(ge=0.0, le=1.0)
    y: float = Field(ge=0.0, le=1.0)
    width: float = Field(gt=0.0, le=1.0)
    height: float = Field(gt=0.0, le=1.0)


class VlmRuntimeConfigRequest(BaseModel):
    endpoint: str = Field(min_length=1)
    key: str = Field(min_length=1)
    model: str = Field(min_length=1)


class AsrSegmentRequest(BaseModel):
    id: str | None = Field(default=None, max_length=120)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    text: str = Field(default="", max_length=4000)
    format: str | None = Field(default=None, pattern="^(asr|srt)$")


class OcrEntryRequest(BaseModel):
    id: str | None = Field(default=None, max_length=120)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    text: str = Field(default="", max_length=4000)
    confidence: float | None = Field(default=None, ge=0.0, le=1.0)


class CharacterReferenceRequest(BaseModel):
    id: str | None = Field(default=None, max_length=120)
    name: str = Field(min_length=1, max_length=80)
    imageBase64: str = Field(min_length=1)


class FrameOverrideRequest(BaseModel):
    shotIndex: int = Field(ge=1)
    frameIndex: int = Field(ge=0)
    groupIndex: int = Field(ge=1)
    timeSec: float = Field(ge=0.0)
    sourceTimeSec: float = Field(ge=0.0)


class ClipRangeOverrideRequest(BaseModel):
    key: str = Field(min_length=1, max_length=200)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)


class VlmDraftPayloadRequest(BaseModel):
    group_size: int = Field(default=3, ge=1, le=8)
    keyframes_per_shot: int = Field(default=3, ge=1, le=6)
    highlight_threshold: float = Field(default=0.7, ge=0.0, le=1.0)
    enableSubtitleRegion: bool = False
    subtitleRegion: SubtitleRegionRequest | None = None
    enableOcr: bool = True
    enableAutoAsr: bool = True
    ocrEntries: list[OcrEntryRequest] = Field(default_factory=list)
    asrText: str | None = Field(default=None, max_length=12000)
    asrSegments: list[AsrSegmentRequest] = Field(default_factory=list)
    characterReferences: list[CharacterReferenceRequest] = Field(default_factory=list)
    promptProfile: str = Field(default="short-video", pattern="^(standard|short-video)$")


class VlmShotAnalysisRequest(BaseModel):
    shots: list[ShotRequest] = Field(default_factory=list)
    vlmConfig: VlmRuntimeConfigRequest
    group_size: int = Field(default=3, ge=1, le=8)
    keyframes_per_shot: int = Field(default=3, ge=1, le=6)
    highlight_threshold: float = Field(default=0.7, ge=0.0, le=1.0)
    enableSubtitleRegion: bool = False
    subtitleRegion: SubtitleRegionRequest | None = None
    enableOcr: bool = True
    enableAutoAsr: bool = True
    ocrEntries: list[OcrEntryRequest] = Field(default_factory=list)
    asrText: str | None = Field(default=None, max_length=12000)
    asrSegments: list[AsrSegmentRequest] = Field(default_factory=list)
    characterReferences: list[CharacterReferenceRequest] = Field(default_factory=list)
    frameOverrides: list[FrameOverrideRequest] = Field(default_factory=list)
    promptProfile: str = Field(default="short-video", pattern="^(standard|short-video)$")


class VlmShotGroupRequest(BaseModel):
    index: int = Field(ge=1)
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    shotIndexes: list[int] = Field(default_factory=list)
    isContinuousStory: bool = False
    mergeWithPrev: bool = False
    mergeWithNext: bool = False
    highlightScore: float = Field(default=0.0, ge=0.0, le=1.0)
    peakTimesSec: list[float] = Field(default_factory=list)
    peakRole: str = Field(default="unknown")
    speakerHint: str = Field(default="")
    speakerConfidence: float = Field(default=0.0, ge=0.0, le=1.0)
    reason: str = Field(default="")


class AdjacentStoryReassignmentRequest(BaseModel):
    groups: list[VlmShotGroupRequest] = Field(default_factory=list)
    llmConfig: VlmRuntimeConfigRequest


class AdjacentStoryPairRequest(BaseModel):
    leftGroupIndex: int = Field(ge=1)
    rightGroupIndex: int = Field(ge=1)
    shouldReassignTail: bool = False
    reassignFromSec: float | None = Field(default=None, ge=0.0)
    sourceGroupIndex: int | None = Field(default=None, ge=1)
    targetGroupIndex: int | None = Field(default=None, ge=1)
    confidence: float = Field(default=0.0, ge=0.0, le=1.0)
    reason: str = Field(default="")


class CorrectedEventTimelineRequest(BaseModel):
    groups: list[VlmShotGroupRequest] = Field(default_factory=list)
    adjacentPairs: list[AdjacentStoryPairRequest] = Field(default_factory=list)
    shots: list[ShotRequest] = Field(default_factory=list)


class EventMergingRequest(BaseModel):
    dynamicSegments: list[DynamicSegmentRequest] = Field(default_factory=list)
    boundaryCandidates: list[BoundaryCandidateRequest] = Field(default_factory=list)
    target_event_sec: float = Field(default=6.0, ge=1.0, le=60.0)
    max_event_sec: float = Field(default=9.0, ge=2.0, le=120.0)
    short_segment_sec: float = Field(default=2.8, ge=0.2, le=30.0)
    substantial_segment_sec: float = Field(default=3.5, ge=0.2, le=30.0)
    keep_boundary_score: float = Field(default=0.82, ge=0.0, le=1.0)
    strong_boundary_score: float = Field(default=0.86, ge=0.0, le=1.0)


class FunctionalClipExportClipRequest(BaseModel):
    index: int = Field(ge=1)
    eventIndex: int | None = Field(default=None, ge=0)
    type: str = Field(pattern="^(build|peak|result|transition)$")
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    durationSec: float = Field(ge=0.0)
    score: float | None = Field(default=None, ge=0.0, le=1.0)
    reason: str = Field(default="", max_length=4000)
    sourceShotIndexes: list[int] = Field(default_factory=list)
    sourceGroupIndexes: list[int] = Field(default_factory=list)
    exportStartFrame: int | None = Field(default=None, ge=0)
    exportEndFrame: int | None = Field(default=None, ge=0)
    exportStartSec: float | None = Field(default=None, ge=0.0)
    exportEndSec: float | None = Field(default=None, ge=0.0)
    exportDurationSec: float | None = Field(default=None, ge=0.0)


class FunctionalClipExportRequest(BaseModel):
    clips: list[FunctionalClipExportClipRequest] = Field(default_factory=list)
