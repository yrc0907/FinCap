import { useCallback, useMemo } from "react";

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
import {
  defaultBoundaryPayload,
  defaultMultiscalePayload,
  defaultStrictShotPayload,
  type BoundaryControlsPayload,
  type MultiscaleControlsPayload,
  type ProcessingMode,
  type StrictShotControlsPayload,
} from "./workspace-config";
import {
  buildInitialNodeFeedback,
  type WorkflowNodeFeedback,
  type WorkflowNodeKey,
} from "./workspace-node-feedback";
import type { WorkspaceRuntimeState } from "./workspace-runtime-state";

type UseWorkspaceRuntimeStateProps = {
  hasProject: boolean;
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
  nodeFeedback: Record<WorkflowNodeKey, WorkflowNodeFeedback>;
  setProcessingMode: React.Dispatch<React.SetStateAction<ProcessingMode>>;
  setSceneDetectorMode: React.Dispatch<React.SetStateAction<SceneDetectorMode>>;
  setMultiscalePayload: React.Dispatch<React.SetStateAction<MultiscaleControlsPayload>>;
  setBoundaryPayload: React.Dispatch<React.SetStateAction<BoundaryControlsPayload>>;
  setStrictShotPayload: React.Dispatch<React.SetStateAction<StrictShotControlsPayload>>;
  setMultiscaleResult: React.Dispatch<React.SetStateAction<MultiscaleDetectionResult | null>>;
  setBoundaryResult: React.Dispatch<
    React.SetStateAction<DualSignalBoundaryDetectionResult | null>
  >;
  setRawStrictShotResult: React.Dispatch<
    React.SetStateAction<StrictShotGenerationResult | null>
  >;
  setVlmShotAnalysisResult: React.Dispatch<React.SetStateAction<VlmShotAnalysisResult | null>>;
  setAdjacentStoryReassignmentResult: React.Dispatch<
    React.SetStateAction<AdjacentStoryReassignmentResult | null>
  >;
  setRawCorrectedEventTimelineResult: React.Dispatch<
    React.SetStateAction<CorrectedEventTimelineResult | null>
  >;
  setExportResult: React.Dispatch<React.SetStateAction<FunctionalClipExportResult | null>>;
  setNodeFeedback: React.Dispatch<
    React.SetStateAction<Record<WorkflowNodeKey, WorkflowNodeFeedback>>
  >;
};

export function useWorkspaceRuntimeState({
  hasProject,
  processingMode,
  sceneDetectorMode,
  multiscalePayload,
  boundaryPayload,
  strictShotPayload,
  multiscaleResult,
  boundaryResult,
  rawStrictShotResult,
  vlmShotAnalysisResult,
  adjacentStoryReassignmentResult,
  rawCorrectedEventTimelineResult,
  exportResult,
  nodeFeedback,
  setProcessingMode,
  setSceneDetectorMode,
  setMultiscalePayload,
  setBoundaryPayload,
  setStrictShotPayload,
  setMultiscaleResult,
  setBoundaryResult,
  setRawStrictShotResult,
  setVlmShotAnalysisResult,
  setAdjacentStoryReassignmentResult,
  setRawCorrectedEventTimelineResult,
  setExportResult,
  setNodeFeedback,
}: UseWorkspaceRuntimeStateProps) {
  const runtimeState = useMemo<WorkspaceRuntimeState>(
    () => ({
      processingMode,
      sceneDetectorMode,
      multiscalePayload,
      boundaryPayload,
      strictShotPayload,
      multiscaleResult,
      boundaryResult,
      rawStrictShotResult,
      vlmShotAnalysisResult,
      adjacentStoryReassignmentResult,
      rawCorrectedEventTimelineResult,
      exportResult,
      nodeFeedback,
    }),
    [
      processingMode,
      sceneDetectorMode,
      multiscalePayload,
      boundaryPayload,
      strictShotPayload,
      multiscaleResult,
      boundaryResult,
      rawStrictShotResult,
      vlmShotAnalysisResult,
      adjacentStoryReassignmentResult,
      rawCorrectedEventTimelineResult,
      exportResult,
      nodeFeedback,
    ],
  );

  const applyRuntimeState = useCallback(
    (savedRuntimeState: WorkspaceRuntimeState | null) => {
      if (!savedRuntimeState) {
        return;
      }
      setProcessingMode(savedRuntimeState.processingMode ?? "standard");
      setSceneDetectorMode(savedRuntimeState.sceneDetectorMode ?? "transnetv2-cuda");
      setMultiscalePayload(savedRuntimeState.multiscalePayload ?? defaultMultiscalePayload);
      setBoundaryPayload(savedRuntimeState.boundaryPayload ?? defaultBoundaryPayload);
      setStrictShotPayload(savedRuntimeState.strictShotPayload ?? defaultStrictShotPayload);
      setMultiscaleResult(savedRuntimeState.multiscaleResult ?? null);
      setBoundaryResult(savedRuntimeState.boundaryResult ?? null);
      setRawStrictShotResult(savedRuntimeState.rawStrictShotResult ?? null);
      setVlmShotAnalysisResult(savedRuntimeState.vlmShotAnalysisResult ?? null);
      setAdjacentStoryReassignmentResult(
        savedRuntimeState.adjacentStoryReassignmentResult ?? null,
      );
      setRawCorrectedEventTimelineResult(
        savedRuntimeState.rawCorrectedEventTimelineResult ?? null,
      );
      setExportResult(savedRuntimeState.exportResult ?? null);
      setNodeFeedback(savedRuntimeState.nodeFeedback ?? buildInitialNodeFeedback(hasProject));
    },
    [
      hasProject,
      setAdjacentStoryReassignmentResult,
      setBoundaryPayload,
      setBoundaryResult,
      setExportResult,
      setMultiscalePayload,
      setMultiscaleResult,
      setNodeFeedback,
      setProcessingMode,
      setRawCorrectedEventTimelineResult,
      setRawStrictShotResult,
      setSceneDetectorMode,
      setStrictShotPayload,
      setVlmShotAnalysisResult,
    ],
  );

  return {
    runtimeState,
    applyRuntimeState,
  };
}
