import type { FunctionalClipExportResult } from "../../types/workspace-drafts";
import type {
  AdjacentStoryReassignmentResult,
  CorrectedEventTimelineResult,
  DualSignalBoundaryDetectionResult,
  MultiscaleDetectionResult,
  SceneDetectorMode,
  StrictShotGenerationResult,
  VlmShotAnalysisResult,
} from "../../types/workspace";
import type {
  BoundaryControlsPayload,
  MultiscaleControlsPayload,
  ProcessingMode,
  StrictShotControlsPayload,
} from "./workspace-config";
import type {
  WorkflowNodeFeedback,
  WorkflowNodeKey,
} from "./workspace-node-feedback";

export type WorkspaceRuntimeState = {
  processingMode: ProcessingMode;
  sceneDetectorMode: SceneDetectorMode;
  multiscalePayload: MultiscaleControlsPayload;
  boundaryPayload: BoundaryControlsPayload;
  strictShotPayload: StrictShotControlsPayload;
  multiscaleResult: MultiscaleDetectionResult | null;
  boundaryResult: DualSignalBoundaryDetectionResult | null;
  rawStrictShotResult: StrictShotGenerationResult | null;
  vlmShotAnalysisResult: VlmShotAnalysisResult | null;
  adjacentStoryReassignmentResult: AdjacentStoryReassignmentResult | null;
  rawCorrectedEventTimelineResult: CorrectedEventTimelineResult | null;
  exportResult: FunctionalClipExportResult | null;
  nodeFeedback: Record<WorkflowNodeKey, WorkflowNodeFeedback> | null;
};

export type WorkspaceRuntimeStateResponse = {
  runtimeState: WorkspaceRuntimeState | null;
  updatedAt?: number;
};
