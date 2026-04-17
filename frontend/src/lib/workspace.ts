import { ensureBackendReady, resolveBackendUrl } from "./backend-runtime";
import type {
  AdjacentStoryReassignmentResult,
  AsrSegmentInput,
  CharacterReferenceInput,
  CorrectedEventTimelineResult,
  DynamicSegmentGenerationResult,
  DualSignalBoundaryDetectionResult,
  EventMergingResult,
  FrameOverrideInput,
  MultiscaleDetectionResult,
  OcrEntryInput,
  SceneDetectorMode,
  StrictShotGenerationResult,
  SubtitleRegion,
  VlmPromptProfile,
  VlmShotAnalysisResult,
} from "../types/workspace";

const buildApiUrl = (path: string) => `${resolveBackendUrl()}${path}`;

const extractBackendError = async (response: Response) => {
  const fallback = `HTTP ${response.status}`;
  const text = await response.text();

  if (!text) {
    return fallback;
  }

  try {
    const parsed = JSON.parse(text) as { detail?: string; message?: string };
    return parsed.detail || parsed.message || fallback;
  } catch {
    return text.length > 160 ? `${text.slice(0, 157)}...` : text;
  }
};

export type RunMultiscaleDetectionPayload = {
  coarse_window_sec: number;
  coarse_stride_sec: number;
  coarse_score_threshold: number;
  coarse_merge_gap_sec: number;
  fine_search_radius_sec: number;
  fine_sample_step_sec: number;
  fine_score_threshold: number;
  scene_detector_mode: SceneDetectorMode;
};

export type RunDualSignalBoundaryDetectionPayload = {
  suspiciousRegions: MultiscaleDetectionResult["suspiciousRegions"];
  subject_sample_step_sec: number;
  subject_core_ratio: number;
  subject_score_threshold: number;
  scene_sample_step_sec: number;
  scene_score_threshold: number;
  fusion_gap_sec: number;
  fusion_high_confidence_score: number;
  scene_detector_mode: SceneDetectorMode;
  sceneDetectorCandidates?: MultiscaleDetectionResult["sceneDetectorCandidates"];
  sceneDetectorBackend?: string;
};

export type RunDynamicSegmentGenerationPayload = {
  boundaryCandidates: DualSignalBoundaryDetectionResult["boundaryCandidates"];
  min_segment_sec: number;
  abnormal_short_sec: number;
  dedupe_epsilon_sec: number;
};

export type RunEventMergingPayload = {
  dynamicSegments: DynamicSegmentGenerationResult["segments"];
  boundaryCandidates: DualSignalBoundaryDetectionResult["boundaryCandidates"];
  target_event_sec: number;
  max_event_sec: number;
  short_segment_sec: number;
  substantial_segment_sec: number;
  keep_boundary_score: number;
  strong_boundary_score: number;
};

export type RunStrictShotGenerationPayload = {
  boundaryCandidates: DualSignalBoundaryDetectionResult["boundaryCandidates"];
  dedupe_epsilon_sec: number;
  min_shot_sec: number;
  abnormal_short_sec: number;
};

export type RunVlmShotAnalysisPayload = {
  shots: StrictShotGenerationResult["shots"];
  vlmConfig: {
    endpoint: string;
    key: string;
    model: string;
  };
  group_size: number;
  keyframes_per_shot: number;
  highlight_threshold: number;
  enableSubtitleRegion: boolean;
  subtitleRegion: SubtitleRegion;
  enableOcr: boolean;
  enableAutoAsr: boolean;
  ocrEntries: OcrEntryInput[];
  asrText: string;
  asrSegments: AsrSegmentInput[];
  characterReferences: CharacterReferenceInput[];
  frameOverrides?: FrameOverrideInput[];
  promptProfile: VlmPromptProfile;
};

export type RunAdjacentStoryReassignmentPayload = {
  groups: VlmShotAnalysisResult["groups"];
  llmConfig: {
    endpoint: string;
    key: string;
    model: string;
  };
};

export type RunCorrectedEventTimelinePayload = {
  groups: VlmShotAnalysisResult["groups"];
  adjacentPairs: AdjacentStoryReassignmentResult["pairs"];
  shots: StrictShotGenerationResult["shots"];
};

export const runMultiscaleDetection = async (
  projectId: string,
  payload: RunMultiscaleDetectionPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}/timeline/multiscale-detect`), {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(payload),
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as MultiscaleDetectionResult;
};

export const runDualSignalBoundaryDetection = async (
  projectId: string,
  payload: RunDualSignalBoundaryDetectionPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/dual-signal-boundary-detect`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as DualSignalBoundaryDetectionResult;
};

export const runDynamicSegmentGeneration = async (
  projectId: string,
  payload: RunDynamicSegmentGenerationPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/dynamic-segment-generate`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as DynamicSegmentGenerationResult;
};

export const runEventMerging = async (
  projectId: string,
  payload: RunEventMergingPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}/timeline/event-merge`), {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(payload),
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as EventMergingResult;
};

export const runStrictShotGeneration = async (
  projectId: string,
  payload: RunStrictShotGenerationPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/strict-shot-generate`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as StrictShotGenerationResult;
};

export const runVlmShotAnalysis = async (
  projectId: string,
  payload: RunVlmShotAnalysisPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/vlm-shot-analyze`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as VlmShotAnalysisResult;
};

export const runAdjacentStoryReassignment = async (
  projectId: string,
  payload: RunAdjacentStoryReassignmentPayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/adjacent-story-reassign`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as AdjacentStoryReassignmentResult;
};

export const runCorrectedEventTimeline = async (
  projectId: string,
  payload: RunCorrectedEventTimelinePayload,
) => {
  await ensureBackendReady();
  const response = await fetch(
    buildApiUrl(`/api/projects/${projectId}/timeline/corrected-event-timeline`),
    {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(payload),
    },
  );

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as CorrectedEventTimelineResult;
};
