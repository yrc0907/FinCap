import type {
  CharacterReferenceInput,
  StrictShot,
  SubtitleRegion,
  VlmPromptProfile,
} from "./workspace";

export type OcrEntryInput = {
  id: string;
  startSec: number;
  endSec: number;
  text: string;
  confidence?: number;
};

export type AsrDraftSegmentInput = {
  id?: string;
  startSec: number;
  endSec: number;
  text: string;
  format?: "asr" | "srt";
};

export type VlmDraftPayload = {
  group_size: number;
  keyframes_per_shot: number;
  highlight_threshold: number;
  enableSubtitleRegion: boolean;
  subtitleRegion: SubtitleRegion;
  enableOcr: boolean;
  enableAutoAsr: boolean;
  ocrEntries: OcrEntryInput[];
  asrText: string;
  asrSegments: AsrDraftSegmentInput[];
  characterReferences: CharacterReferenceInput[];
  promptProfile: VlmPromptProfile;
};

export type ClipRangeOverride = {
  key: string;
  startSec: number;
  endSec: number;
};

export type FrameOverride = {
  shotIndex: number;
  frameIndex: number;
  groupIndex: number;
  timeSec: number;
  sourceTimeSec: number;
};

export type SemanticDraftResponse = {
  vlmPayload: VlmDraftPayload | null;
};

export type ClipRangeOverrideResponse = {
  scope: "shots" | "functional-clips";
  items: ClipRangeOverride[];
  updatedAt?: number;
};

export type FrameOverrideResponse = {
  items: FrameOverride[];
  updatedAt?: number;
};

export type FunctionalClipExportRequestItem = {
  index: number;
  eventIndex?: number;
  type: "build" | "peak" | "result" | "transition";
  startSec: number;
  endSec: number;
  durationSec: number;
  score?: number;
  reason: string;
  sourceShotIndexes: number[];
  sourceGroupIndexes: number[];
  exportStartFrame?: number;
  exportEndFrame?: number;
  exportStartSec?: number;
  exportEndSec?: number;
  exportDurationSec?: number;
};

export type FunctionalClipExportResult = {
  projectId: string;
  clipCount: number;
  outputDir: string;
  manifest: {
    video: string;
    videoIndex?: {
      fps: number;
      frameCount: number;
      durationSec: number;
    };
    clips: FunctionalClipExportRequestItem[];
  };
};

export type TimedRangeItem = Pick<StrictShot, "startSec" | "endSec" | "durationSec">;
