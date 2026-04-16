import type {
  RunDynamicSegmentGenerationPayload,
  RunDualSignalBoundaryDetectionPayload,
  RunEventMergingPayload,
  RunMultiscaleDetectionPayload,
  RunStrictShotGenerationPayload,
  RunVlmShotAnalysisPayload,
} from "../../lib/workspace";
import type { SceneDetectorMode } from "../../types/workspace";

export type ProcessingMode = "fast" | "standard" | "high";
export type MultiscaleControlsPayload = Omit<RunMultiscaleDetectionPayload, "scene_detector_mode">;
export type BoundaryControlsPayload = Omit<
  RunDualSignalBoundaryDetectionPayload,
  "scene_detector_mode" | "suspiciousRegions"
>;
export type DynamicSegmentControlsPayload = Omit<
  RunDynamicSegmentGenerationPayload,
  "boundaryCandidates"
>;
export type EventMergingControlsPayload = Omit<
  RunEventMergingPayload,
  "dynamicSegments" | "boundaryCandidates"
>;
export type StrictShotControlsPayload = Omit<
  RunStrictShotGenerationPayload,
  "boundaryCandidates"
>;
export type VlmControlsPayload = Omit<RunVlmShotAnalysisPayload, "shots" | "vlmConfig">;

export const defaultMultiscalePayload: MultiscaleControlsPayload = {
  coarse_window_sec: 2.0,
  coarse_stride_sec: 0.5,
  coarse_score_threshold: 0.58,
  coarse_merge_gap_sec: 1.2,
  fine_search_radius_sec: 1.0,
  fine_sample_step_sec: 0.08,
  fine_score_threshold: 0.5,
};

export const defaultBoundaryPayload: BoundaryControlsPayload = {
  subject_sample_step_sec: 0.12,
  subject_core_ratio: 0.58,
  subject_score_threshold: 0.46,
  scene_sample_step_sec: 0.12,
  scene_score_threshold: 0.48,
  fusion_gap_sec: 0.35,
  fusion_high_confidence_score: 0.62,
};

export const defaultDynamicSegmentPayload: DynamicSegmentControlsPayload = {
  min_segment_sec: 1.6,
  abnormal_short_sec: 1.0,
  dedupe_epsilon_sec: 0.05,
};

export const defaultEventMergingPayload: EventMergingControlsPayload = {
  target_event_sec: 6.0,
  max_event_sec: 9.0,
  short_segment_sec: 2.8,
  substantial_segment_sec: 3.5,
  keep_boundary_score: 0.82,
  strong_boundary_score: 0.86,
};

export const defaultStrictShotPayload: StrictShotControlsPayload = {
  dedupe_epsilon_sec: 0.05,
  min_shot_sec: 0.15,
  abnormal_short_sec: 0.3,
};

export const defaultVlmPayload: VlmControlsPayload = {
  group_size: 3,
  keyframes_per_shot: 3,
  highlight_threshold: 0.7,
  enableSubtitleRegion: false,
  subtitleRegion: {
    x: 0.05,
    y: 0.78,
    width: 0.9,
    height: 0.18,
  },
  enableOcr: true,
  enableAutoAsr: true,
  asrText: "",
  asrSegments: [],
  characterReferences: [],
  promptProfile: "short-video",
};

export const processingModeProfiles: Record<
  ProcessingMode,
  {
    label: string;
    multiscale: MultiscaleControlsPayload;
    boundary: BoundaryControlsPayload;
    dynamicSegments: DynamicSegmentControlsPayload;
    eventMerging: EventMergingControlsPayload;
    strictShots: StrictShotControlsPayload;
    vlm: VlmControlsPayload;
  }
> = {
  fast: {
    label: "Fast",
    multiscale: {
      coarse_window_sec: 2.8,
      coarse_stride_sec: 1.8,
      coarse_score_threshold: 0.62,
      coarse_merge_gap_sec: 1.6,
      fine_search_radius_sec: 0.6,
      fine_sample_step_sec: 0.24,
      fine_score_threshold: 0.54,
    },
    boundary: {
      subject_sample_step_sec: 0.24,
      subject_core_ratio: 0.58,
      subject_score_threshold: 0.47,
      scene_sample_step_sec: 0.24,
      scene_score_threshold: 0.5,
      fusion_gap_sec: 0.45,
      fusion_high_confidence_score: 0.64,
    },
    dynamicSegments: {
      min_segment_sec: 1.8,
      abnormal_short_sec: 1.2,
      dedupe_epsilon_sec: 0.05,
    },
    eventMerging: {
      target_event_sec: 5.5,
      max_event_sec: 8.5,
      short_segment_sec: 2.6,
      substantial_segment_sec: 3.2,
      keep_boundary_score: 0.8,
      strong_boundary_score: 0.85,
    },
    strictShots: {
      dedupe_epsilon_sec: 0.05,
      min_shot_sec: 0.2,
      abnormal_short_sec: 0.35,
    },
    vlm: {
      group_size: 2,
      keyframes_per_shot: 2,
      highlight_threshold: 0.72,
      enableSubtitleRegion: false,
      subtitleRegion: {
        x: 0.05,
        y: 0.78,
        width: 0.9,
        height: 0.18,
      },
      enableOcr: true,
      enableAutoAsr: true,
      asrText: "",
      asrSegments: [],
      characterReferences: [],
      promptProfile: "short-video",
    },
  },
  standard: {
    label: "Standard",
    multiscale: defaultMultiscalePayload,
    boundary: defaultBoundaryPayload,
    dynamicSegments: defaultDynamicSegmentPayload,
    eventMerging: defaultEventMergingPayload,
    strictShots: defaultStrictShotPayload,
    vlm: defaultVlmPayload,
  },
  high: {
    label: "High",
    multiscale: {
      coarse_window_sec: 1.8,
      coarse_stride_sec: 0.4,
      coarse_score_threshold: 0.56,
      coarse_merge_gap_sec: 1.0,
      fine_search_radius_sec: 1.2,
      fine_sample_step_sec: 0.06,
      fine_score_threshold: 0.48,
    },
    boundary: {
      subject_sample_step_sec: 0.08,
      subject_core_ratio: 0.58,
      subject_score_threshold: 0.44,
      scene_sample_step_sec: 0.08,
      scene_score_threshold: 0.46,
      fusion_gap_sec: 0.3,
      fusion_high_confidence_score: 0.6,
    },
    dynamicSegments: {
      min_segment_sec: 1.4,
      abnormal_short_sec: 0.9,
      dedupe_epsilon_sec: 0.04,
    },
    eventMerging: {
      target_event_sec: 6.5,
      max_event_sec: 10.0,
      short_segment_sec: 3.0,
      substantial_segment_sec: 3.6,
      keep_boundary_score: 0.84,
      strong_boundary_score: 0.88,
    },
    strictShots: {
      dedupe_epsilon_sec: 0.04,
      min_shot_sec: 0.12,
      abnormal_short_sec: 0.25,
    },
    vlm: {
      group_size: 3,
      keyframes_per_shot: 4,
      highlight_threshold: 0.68,
      enableSubtitleRegion: false,
      subtitleRegion: {
        x: 0.05,
        y: 0.78,
        width: 0.9,
        height: 0.18,
      },
      enableOcr: true,
      enableAutoAsr: true,
      asrText: "",
      asrSegments: [],
      characterReferences: [],
      promptProfile: "short-video",
    },
  },
};

export const sceneDetectorModeOptions: Array<{
  value: SceneDetectorMode;
  label: string;
}> = [
  { value: "pyscenedetect", label: "PySceneDetect" },
  { value: "transnetv2-cuda", label: "TransNetV2 CUDA" },
];

export const formatSeconds = (value: number) => `${value.toFixed(2)}s`;
export const formatScore = (value: number | null) => (value === null ? "--" : value.toFixed(4));
