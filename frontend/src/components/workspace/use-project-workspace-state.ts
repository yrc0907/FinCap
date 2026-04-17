import { useCallback, useEffect, useMemo, useState } from "react";
import { toast } from "sonner";

import {
  runAdjacentStoryReassignment,
  runCorrectedEventTimeline,
  runDualSignalBoundaryDetection,
  runMultiscaleDetection,
  runStrictShotGeneration,
  runVlmShotAnalysis,
  type RunDualSignalBoundaryDetectionPayload,
  type RunMultiscaleDetectionPayload,
  type RunStrictShotGenerationPayload,
  type RunVlmShotAnalysisPayload,
} from "../../lib/workspace";
import {
  exportFunctionalClips,
  saveWorkspaceClipOverrides,
  saveWorkspaceFrameOverrides,
} from "../../lib/workspace-node-api";
import type { ProjectItem } from "../../types/project";
import type { SystemConfig } from "../../types/settings";
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
  ClipRangeOverride,
  FrameOverride,
  FunctionalClipExportResult,
} from "../../types/workspace-drafts";
import {
  defaultBoundaryPayload,
  defaultMultiscalePayload,
  defaultStrictShotPayload,
  processingModeProfiles,
  type BoundaryControlsPayload,
  type MultiscaleControlsPayload,
  type ProcessingMode,
  type StrictShotControlsPayload,
} from "./workspace-config";
import {
  applyFunctionalClipOverrides,
  applyStrictShotOverrides,
  buildFunctionalClipOverrideKey,
  buildShotOverrideKey,
  upsertRangeOverride,
} from "./workspace-state-overrides";
import {
  buildInitialNodeFeedback,
  type WorkflowNodeFeedback,
  type WorkflowNodeKey,
} from "./workspace-node-feedback";
import { useWorkspaceRuntimeState } from "./use-workspace-runtime-state";
import { useWorkspaceDraftSync } from "./use-workspace-draft-sync";
import { useVlmControls } from "./use-vlm-controls";

type UseProjectWorkspaceStateProps = {
  project: ProjectItem | null;
  settings: SystemConfig;
  onUploadVideo: (file: File) => Promise<ProjectItem | null> | void;
}; type FunctionalClipType = "build" | "peak" | "result" | "transition";

export function useProjectWorkspaceState({
  project,
  settings,
  onUploadVideo,
}: UseProjectWorkspaceStateProps) {
  const [processingMode, setProcessingMode] = useState<ProcessingMode>("standard");
  const [sceneDetectorMode, setSceneDetectorMode] =
    useState<SceneDetectorMode>("transnetv2-cuda");
  const [multiscalePayload, setMultiscalePayload] =
    useState<MultiscaleControlsPayload>(defaultMultiscalePayload);
  const [boundaryPayload, setBoundaryPayload] =
    useState<BoundaryControlsPayload>(defaultBoundaryPayload);
  const [strictShotPayload, setStrictShotPayload] =
    useState<StrictShotControlsPayload>(defaultStrictShotPayload);
  const {
    vlmPayload,
    setVlmPayload,
    updateVlmField,
    updateVlmSubtitleRegionField,
    addCharacterReference,
    updateCharacterReference,
    removeCharacterReference,
  } = useVlmControls(processingModeProfiles.standard.vlm);
  const [multiscaleResult, setMultiscaleResult] = useState<MultiscaleDetectionResult | null>(null);
  const [boundaryResult, setBoundaryResult] = useState<DualSignalBoundaryDetectionResult | null>(
    null,
  );
  const [rawStrictShotResult, setRawStrictShotResult] =
    useState<StrictShotGenerationResult | null>(null);
  const [vlmShotAnalysisResult, setVlmShotAnalysisResult] =
    useState<VlmShotAnalysisResult | null>(null);
  const [adjacentStoryReassignmentResult, setAdjacentStoryReassignmentResult] =
    useState<AdjacentStoryReassignmentResult | null>(null);
  const [rawCorrectedEventTimelineResult, setRawCorrectedEventTimelineResult] =
    useState<CorrectedEventTimelineResult | null>(null);
  const [shotOverrides, setShotOverrides] = useState<ClipRangeOverride[]>([]);
  const [functionalClipOverrides, setFunctionalClipOverrides] = useState<ClipRangeOverride[]>([]);
  const [frameOverrides, setFrameOverrides] = useState<FrameOverride[]>([]);
  const [isRunningBoundary, setIsRunningBoundary] = useState(false);
  const [isRunningStrictShots, setIsRunningStrictShots] = useState(false);
  const [isRunningVlm, setIsRunningVlm] = useState(false);
  const [isRunningStoryFix, setIsRunningStoryFix] = useState(false);
  const [isExporting, setIsExporting] = useState(false);
  const [isUploadingVideo, setIsUploadingVideo] = useState(false);
  const [exportResult, setExportResult] = useState<FunctionalClipExportResult | null>(null);
  const [nodeFeedback, setNodeFeedback] = useState(() => buildInitialNodeFeedback(Boolean(project)));
  const activeVlmConfig =
    settings.vlmConfigs.find(
      (config) => config.endpoint.trim() && config.key.trim() && config.model.trim(),
    ) ?? null;
  const videoSrc = project?.thumb;
  const strictShotResult = useMemo(
    () => applyStrictShotOverrides(rawStrictShotResult, shotOverrides),
    [rawStrictShotResult, shotOverrides],
  );
  const correctedEventTimelineResult = useMemo(
    () => applyFunctionalClipOverrides(rawCorrectedEventTimelineResult, functionalClipOverrides),
    [rawCorrectedEventTimelineResult, functionalClipOverrides],
  );
  const { runtimeState, applyRuntimeState } = useWorkspaceRuntimeState({
    hasProject: Boolean(project),
    processingMode, sceneDetectorMode, multiscalePayload, boundaryPayload, strictShotPayload,
    multiscaleResult, boundaryResult, rawStrictShotResult, vlmShotAnalysisResult,
    adjacentStoryReassignmentResult, rawCorrectedEventTimelineResult, exportResult, nodeFeedback,
    setProcessingMode, setSceneDetectorMode, setMultiscalePayload, setBoundaryPayload,
    setStrictShotPayload, setMultiscaleResult, setBoundaryResult, setRawStrictShotResult,
    setVlmShotAnalysisResult, setAdjacentStoryReassignmentResult,
    setRawCorrectedEventTimelineResult, setExportResult, setNodeFeedback,
  });
  const {
    ensureWorkspaceApiAvailable,
    handleWorkspaceApiError,
  } = useWorkspaceDraftSync({
    projectId: project?.id ?? null,
    vlmPayload,
    runtimeState,
    setVlmPayload,
    setShotOverrides,
    setFunctionalClipOverrides,
    setFrameOverrides,
    applyRuntimeState,
  });

  const resetPipelineResults = useCallback(() => {
    setMultiscaleResult(null);
    setBoundaryResult(null);
    setRawStrictShotResult(null);
    setVlmShotAnalysisResult(null);
    setAdjacentStoryReassignmentResult(null);
    setRawCorrectedEventTimelineResult(null);
    setExportResult(null);
  }, []);
  const updateNodeFeedback = useCallback(
    (key: WorkflowNodeKey, tone: WorkflowNodeFeedback["tone"], message: string) => {
      setNodeFeedback((current) => ({
        ...current,
        [key]: { tone, message },
      }));
    },
    [],
  );

  useEffect(() => {
    resetPipelineResults();
    setShotOverrides([]);
    setFunctionalClipOverrides([]);
    setFrameOverrides([]);
    setNodeFeedback(buildInitialNodeFeedback(Boolean(project)));
  }, [project?.id, resetPipelineResults]);

  const applyProcessingMode = (mode: ProcessingMode) => {
    const profile = processingModeProfiles[mode];
    setProcessingMode(mode);
    setMultiscalePayload(profile.multiscale);
    setBoundaryPayload(profile.boundary);
    setStrictShotPayload(profile.strictShots);
    setVlmPayload(profile.vlm);
    resetPipelineResults();
    setNodeFeedback(buildInitialNodeFeedback(Boolean(project)));
    toast.success(`${profile.label} mode applied.`);
  };

  const updateMultiscaleField = <K extends keyof MultiscaleControlsPayload,>(
    key: K,
    value: string,
  ) => {
    const parsed = Number(value);
    setMultiscalePayload((current) => ({
      ...current,
      [key]: Number.isFinite(parsed) ? parsed : current[key],
    }));
  };

  const updateBoundaryField = <K extends keyof BoundaryControlsPayload,>(
    key: K,
    value: string,
  ) => {
    const parsed = Number(value);
    setBoundaryPayload((current) => ({
      ...current,
      [key]: Number.isFinite(parsed) ? parsed : current[key],
    }));
  };

  const updateStrictShotField = <K extends keyof StrictShotControlsPayload,>(
    key: K,
    value: string,
  ) => {
    const parsed = Number(value);
    setStrictShotPayload((current) => ({
      ...current,
      [key]: Number.isFinite(parsed) ? parsed : current[key],
    }));
  };

  const handleUploadVideo = async (file: File) => {
    try {
      setIsUploadingVideo(true);
      updateNodeFeedback("upload", "running", "Uploading video");
      await onUploadVideo(file);
      updateNodeFeedback("upload", "success", "Video uploaded");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("upload", "error", "Upload failed");
      toast.error(`Upload failed: ${message}`);
    } finally {
      setIsUploadingVideo(false);
    }
  };

  const handleRunBoundaryFlow = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }
    try {
      setIsRunningBoundary(true);
      updateNodeFeedback("boundary", "running", "Boundary detection running");
      setRawStrictShotResult(null);
      setVlmShotAnalysisResult(null);
      setAdjacentStoryReassignmentResult(null);
      setRawCorrectedEventTimelineResult(null);

      const nextMultiscalePayload: RunMultiscaleDetectionPayload = {
        ...multiscalePayload,
        scene_detector_mode: sceneDetectorMode,
      };
      const nextMultiscaleResult = await runMultiscaleDetection(project.id, nextMultiscalePayload);
      setMultiscaleResult(nextMultiscaleResult);

      const nextBoundaryPayload: RunDualSignalBoundaryDetectionPayload = {
        ...boundaryPayload,
        scene_detector_mode: sceneDetectorMode,
        suspiciousRegions: nextMultiscaleResult.suspiciousRegions,
        sceneDetectorCandidates: nextMultiscaleResult.sceneDetectorCandidates,
        sceneDetectorBackend: nextMultiscaleResult.sceneDetector.backend,
      };
      const nextBoundaryResult = await runDualSignalBoundaryDetection(
        project.id,
        nextBoundaryPayload,
      );
      setBoundaryResult(nextBoundaryResult);
      updateNodeFeedback("boundary", "success", "Boundary detection done");
      toast.success("Boundary detection finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("boundary", "error", "Boundary detection failed");
      toast.error(`Boundary detection failed: ${message}`);
    } finally {
      setIsRunningBoundary(false);
    }
  };

  const handleRunStrictShots = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }
    if (!boundaryResult) {
      toast.error("Run boundary detection first.");
      return;
    }
    try {
      setIsRunningStrictShots(true);
      updateNodeFeedback("shots", "running", "Shot generation running");
      setVlmShotAnalysisResult(null);
      setAdjacentStoryReassignmentResult(null);
      setRawCorrectedEventTimelineResult(null);

      const nextPayload: RunStrictShotGenerationPayload = {
        ...strictShotPayload,
        boundaryCandidates: boundaryResult.boundaryCandidates,
      };
      const nextResult = await runStrictShotGeneration(project.id, nextPayload);
      console.log("[Workspace] Strict shots", nextResult);
      setRawStrictShotResult(nextResult);
      updateNodeFeedback("shots", "success", "Shot generation done");
      toast.success("Shot segments finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("shots", "error", "Shot generation failed");
      toast.error(`Shot segments failed: ${message}`);
    } finally {
      setIsRunningStrictShots(false);
    }
  };

  const handleRunVlm = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }
    if (!strictShotResult) {
      toast.error("Run shot segments first.");
      return;
    }
    if (!activeVlmConfig) {
      toast.error("Set a VLM endpoint, key, and model in Settings first.");
      return;
    }
    try {
      setIsRunningVlm(true);
      updateNodeFeedback("semantic", "running", "Semantic analysis running");
      setAdjacentStoryReassignmentResult(null);
      setRawCorrectedEventTimelineResult(null);

      const nextPayload: RunVlmShotAnalysisPayload = {
        ...vlmPayload,
        shots: strictShotResult.shots,
        frameOverrides,
        vlmConfig: {
          endpoint: activeVlmConfig.endpoint.trim(),
          key: activeVlmConfig.key.trim(),
          model: activeVlmConfig.model.trim(),
        },
      };
      const nextResult = await runVlmShotAnalysis(project.id, nextPayload);
      console.log("[Workspace] VLM shot analysis", nextResult);
      setVlmShotAnalysisResult(nextResult);
      updateNodeFeedback("semantic", "success", "Semantic analysis done");
      toast.success("VLM pass finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("semantic", "error", "Semantic analysis failed");
      toast.error(`VLM pass failed: ${message}`);
    } finally {
      setIsRunningVlm(false);
    }
  };

  const handleRunStoryFix = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }
    if (!vlmShotAnalysisResult) {
      toast.error("Run VLM first.");
      return;
    }
    if (!activeVlmConfig) {
      toast.error("Set a VLM endpoint, key, and model in Settings first.");
      return;
    }
    try {
      setIsRunningStoryFix(true);
      updateNodeFeedback("story", "running", "Story correction running");
      const adjacentResult = await runAdjacentStoryReassignment(project.id, {
        groups: vlmShotAnalysisResult.groups,
        llmConfig: {
          endpoint: activeVlmConfig.endpoint.trim(),
          key: activeVlmConfig.key.trim(),
          model: activeVlmConfig.model.trim(),
        },
      });
      const correctedResult = await runCorrectedEventTimeline(project.id, {
        groups: vlmShotAnalysisResult.groups,
        adjacentPairs: adjacentResult.pairs,
        shots: strictShotResult?.shots ?? [],
      });
      console.log("[Workspace] Adjacent story reassignment", adjacentResult);
      console.log("[Workspace] Corrected event timeline", correctedResult);
      setAdjacentStoryReassignmentResult(adjacentResult);
      setRawCorrectedEventTimelineResult(correctedResult);
      updateNodeFeedback("story", "success", "Story correction done");
      updateNodeFeedback(
        "sceneLogic",
        correctedResult.functionalClips.length > 0 ? "success" : "idle",
        correctedResult.functionalClips.length > 0 ? "Functional clips ready" : "Review functional clips",
      );
      updateNodeFeedback("export", "idle", "Export the final result");
      toast.success("Story fix finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("story", "error", "Story correction failed");
      toast.error(`Story fix failed: ${message}`);
    } finally {
      setIsRunningStoryFix(false);
    }
  };

  const handleSaveShotRange = async (shotIndex: number, startSec: number, endSec: number) => {
    if (!project || !ensureWorkspaceApiAvailable()) {
      return;
    }
    const nextOverrides = upsertRangeOverride(shotOverrides, {
      key: buildShotOverrideKey(shotIndex),
      startSec,
      endSec,
    });
    setShotOverrides(nextOverrides);
    try {
      await saveWorkspaceClipOverrides(project.id, "shots", nextOverrides);
      toast.success("Shot saved.");
    } catch (error) {
      if (handleWorkspaceApiError(error, true)) {
        return;
      }
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Shot save failed: ${message}`);
    }
  };

  const handleSaveFunctionalClipRange = async (
    clipIndex: number,
    clipType: FunctionalClipType,
    startSec: number,
    endSec: number,
  ) => {
    if (!project || !ensureWorkspaceApiAvailable()) {
      return;
    }
    const nextOverrides = upsertRangeOverride(functionalClipOverrides, {
      key: buildFunctionalClipOverrideKey(clipIndex, clipType),
      startSec,
      endSec,
    });
    setFunctionalClipOverrides(nextOverrides);
    try {
      await saveWorkspaceClipOverrides(project.id, "functional-clips", nextOverrides);
      toast.success("Clip saved.");
    } catch (error) {
      if (handleWorkspaceApiError(error, true)) {
        return;
      }
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Clip save failed: ${message}`);
    }
  };

  const handleSaveFrameOverrides = async (nextOverrides: FrameOverride[]) => {
    if (!project || !ensureWorkspaceApiAvailable()) {
      return;
    }
    setFrameOverrides(nextOverrides);
    try {
      await saveWorkspaceFrameOverrides(project.id, nextOverrides);
      toast.success("Frames saved.");
    } catch (error) {
      if (handleWorkspaceApiError(error, true)) {
        return;
      }
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Frame save failed: ${message}`);
    }
  };

  const handleExportFunctionalClips = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }
    if (!correctedEventTimelineResult?.functionalClips.length) {
      toast.error("Run story fix first.");
      return;
    }
    if (!ensureWorkspaceApiAvailable()) {
      return;
    }
    try {
      setIsExporting(true);
      updateNodeFeedback("export", "running", "Export running");
      const nextResult = await exportFunctionalClips(
        project.id,
        correctedEventTimelineResult.functionalClips,
      );
      setExportResult(nextResult);
      updateNodeFeedback("export", "success", "Export done");
      toast.success(`Exported to ${nextResult.outputDir}`);
    } catch (error) {
      if (handleWorkspaceApiError(error, true)) {
        return;
      }
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateNodeFeedback("export", "error", "Export failed");
      toast.error(`Export failed: ${message}`);
    } finally {
      setIsExporting(false);
    }
  };

  return {
    project, videoSrc, processingMode, sceneDetectorMode, nodeFeedback,
    multiscalePayload, boundaryPayload, strictShotPayload, vlmPayload, frameOverrides, activeVlmConfig,
    multiscaleResult, boundaryResult, strictShotResult, vlmShotAnalysisResult,
    adjacentStoryReassignmentResult, correctedEventTimelineResult, exportResult,
    isRunningBoundary, isRunningStrictShots, isRunningVlm, isRunningStoryFix, isExporting, isUploadingVideo,
    setSceneDetectorMode, setVlmPayload, applyProcessingMode,
    updateMultiscaleField, updateBoundaryField, updateStrictShotField,
    updateVlmField, updateVlmSubtitleRegionField,
    addCharacterReference, updateCharacterReference, removeCharacterReference,
    handleUploadVideo, handleRunBoundaryFlow, handleRunStrictShots, handleRunVlm, handleRunStoryFix,
    handleSaveShotRange, handleSaveFunctionalClipRange, handleSaveFrameOverrides, handleExportFunctionalClips,
  };
}

export type ProjectWorkspaceFlowState = ReturnType<typeof useProjectWorkspaceState>;
