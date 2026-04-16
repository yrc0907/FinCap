export type SceneDetectorMode =
  | "pyscenedetect"
  | "transnetv2-cuda";

export type SceneDetectorSummary = {
  mode: SceneDetectorMode;
  backend: string;
  candidateCount: number;
  hardCutCount: number;
  softCutCount: number;
};

export type SceneDetectorCandidate = {
  startSec: number;
  endSec: number;
  peakSec: number;
  score: number;
  cutClass: "hard-cut" | "soft-cut";
  sources: string[];
};

export type MultiscaleDetectionRegion = {
  startSec: number;
  endSec: number;
  peakSec: number;
  coarsePeakSec: number;
  score: number;
  confidence: "high" | "low";
  sources: string[];
};

export type MultiscaleDetectionResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  coarseConfig: {
    window_sec: number;
    stride_sec: number;
    histogram_weight: number;
    frame_diff_weight: number;
    score_threshold: number;
    merge_gap_sec: number;
  };
  fineConfig: {
    search_radius_sec: number;
    sample_step_sec: number;
    histogram_weight: number;
    frame_diff_weight: number;
    score_threshold: number;
  };
  sceneDetector: SceneDetectorSummary;
  sceneDetectorCandidates: SceneDetectorCandidate[];
  suspiciousRegions: MultiscaleDetectionRegion[];
};

export type BoundarySignalCandidate = {
  timeSec: number;
  score: number;
  signal: "subject" | "scene";
  source: string;
  windowStartSec: number;
  windowEndSec: number;
};

export type BoundaryCandidate = {
  timeSec: number;
  score: number;
  subjectScore: number | null;
  sceneScore: number | null;
  windowStartSec: number;
  windowEndSec: number;
  confidence: "high" | "low";
  sources: string[];
  origin?: "scene-detector" | "scene-detector+subject" | "scene+subject" | "scene" | "subject-only";
};

export type DualSignalBoundaryDetectionResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputRegionCount: number;
  subjectConfig: {
    sample_step_sec: number;
    core_ratio: number;
    histogram_weight: number;
    frame_diff_weight: number;
    score_threshold: number;
  };
  sceneConfig: {
    sample_step_sec: number;
    histogram_weight: number;
    optical_flow_weight: number;
    frame_diff_weight: number;
    score_threshold: number;
    pyscenedetect_score: number;
  };
  fusionConfig: {
    gap_sec: number;
    high_confidence_score: number;
  };
  sceneDetector: SceneDetectorSummary;
  subjectCandidates: BoundarySignalCandidate[];
  sceneCandidates: BoundarySignalCandidate[];
  boundaryCandidates: BoundaryCandidate[];
};

export type DynamicSegment = {
  index: number;
  startSec: number;
  endSec: number;
  durationSec: number;
  startBoundarySec: number | null;
  endBoundarySec: number | null;
};

export type DynamicSegmentGenerationResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputBoundaryCount: number;
  usedBoundaryCount: number;
  removedBoundaryCount: number;
  usedBoundaryPointsSec: number[];
  removedBoundaries: Array<{
    timeSec: number;
    reason: string;
  }>;
  segments: DynamicSegment[];
  summary: {
    segmentCount: number;
    shortestSegmentSec: number;
    longestSegmentSec: number;
    abnormalShortSegmentCount: number;
    isLegal: boolean;
  };
  config: {
    min_segment_sec: number;
    abnormal_short_sec: number;
    dedupe_epsilon_sec: number;
  };
};

export type EventRange = {
  index: number;
  startSec: number;
  endSec: number;
  durationSec: number;
  segmentCount: number;
  startSegmentIndex: number;
  endSegmentIndex: number;
  mergeReasons: string[];
};

export type EventMergingResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputSegmentCount: number;
  eventCount: number;
  keptBoundaryPointsSec: number[];
  mergedBoundaryPointsSec: number[];
  mergedBoundaries: Array<{
    timeSec: number;
    reason: string;
  }>;
  events: EventRange[];
  summary: {
    eventCount: number;
    shortestEventSec: number;
    longestEventSec: number;
    suspiciousFragmentCount: number;
  };
  config: {
    target_event_sec: number;
    max_event_sec: number;
    short_segment_sec: number;
    substantial_segment_sec: number;
    keep_boundary_score: number;
    strong_boundary_score: number;
  };
};

export type StrictShot = {
  index: number;
  startSec: number;
  endSec: number;
  durationSec: number;
};

export type SubtitleRegion = {
  x: number;
  y: number;
  width: number;
  height: number;
};

export type VlmPromptProfile = "standard" | "short-video";

export type AsrSegmentInput = {
  startSec: number;
  endSec: number;
  text: string;
};

export type CharacterReferenceInput = {
  id: string;
  name: string;
  imageBase64: string;
};

export type StrictShotGenerationResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  videoDurationSec: number;
  usedBoundaryPointsSec: number[];
  removedBoundaries: Array<{
    timeSec: number;
    reason: string;
  }>;
  shots: StrictShot[];
  summary: {
    shotCount: number;
    shortestShotSec: number;
    longestShotSec: number;
    abnormalShortShotCount: number;
    isLegal: boolean;
  };
  config: {
    dedupe_epsilon_sec: number;
    min_shot_sec: number;
    abnormal_short_sec: number;
  };
};

export type VlmShotGroup = {
  index: number;
  startSec: number;
  endSec: number;
  shotIndexes: number[];
  isContinuousStory: boolean;
  mergeWithPrev: boolean;
  mergeWithNext: boolean;
  highlightScore: number;
  peakTimesSec: number[];
  peakRole: string;
  speakerHint: string;
  speakerConfidence: number;
  evidenceSource: "ocr" | "asr" | "conflict" | "none";
  textConflict: boolean;
  reason: string;
};

export type VlmShotAnalysisResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputShotCount: number;
  groups: VlmShotGroup[];
  summary: {
    groupCount: number;
    highlightGroupCount: number;
  };
  config: {
    group_size: number;
    keyframes_per_shot: number;
    highlight_threshold: number;
    enable_ocr?: boolean;
    enable_auto_asr?: boolean;
    enable_subtitle_region?: boolean;
    prompt_profile?: VlmPromptProfile;
    character_reference_count?: number;
  };
};

export type AdjacentStoryPair = {
  leftGroupIndex: number;
  rightGroupIndex: number;
  shouldReassignTail: boolean;
  reassignFromSec: number | null;
  sourceGroupIndex: number | null;
  targetGroupIndex: number | null;
  confidence: number;
  reason: string;
};

export type AdjacentStoryReassignmentResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputGroupCount: number;
  pairs: AdjacentStoryPair[];
  summary: {
    pairCount: number;
    reassignmentCount: number;
  };
};

export type CorrectedEvent = {
  index: number;
  originalStartSec: number;
  originalEndSec: number;
  startSec: number;
  endSec: number;
  durationSec: number;
  sourceGroupIndexes: number[];
  changed: boolean;
  reasons: string[];
  narrationSpans: Array<{
    index: number;
    startSec: number;
    endSec: number;
    durationSec: number;
    label: "keep" | "bridge" | "drop";
    reason: string;
    score: number;
    sourceShotIndexes: number[];
    sourceGroupIndexes: number[];
  }>;
};

export type CorrectedEventTimelineResult = {
  videoIndex: {
    fps: number;
    frameCount: number;
    durationSec: number;
    width: number;
    height: number;
  };
  inputGroupCount: number;
  inputPairCount: number;
  events: CorrectedEvent[];
  selectedClips: Array<{
    index: number;
    eventIndex: number;
    label: "keep" | "bridge";
    startSec: number;
    endSec: number;
    durationSec: number;
    score: number;
    reason: string;
    sourceShotIndexes: number[];
    sourceGroupIndexes: number[];
  }>;
  summary: {
    eventCount: number;
    changedEventCount: number;
    appliedPairCount: number;
    droppedEventCount: number;
    keepSpanCount: number;
    bridgeSpanCount: number;
    dropSpanCount: number;
    selectedClipCount: number;
    selectedKeepClipCount: number;
    selectedBridgeClipCount: number;
  };
};
