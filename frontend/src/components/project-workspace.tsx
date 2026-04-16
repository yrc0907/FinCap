import { useState } from "react";
import { motion } from "framer-motion";
import { toast } from "sonner";

import {
  runAdjacentStoryReassignment,
  runCorrectedEventTimeline,
  runDualSignalBoundaryDetection,
  runDynamicSegmentGeneration,
  runEventMerging,
  runMultiscaleDetection,
  runStrictShotGeneration,
  runVlmShotAnalysis,
  type RunDualSignalBoundaryDetectionPayload,
  type RunDynamicSegmentGenerationPayload,
  type RunEventMergingPayload,
  type RunAdjacentStoryReassignmentPayload,
  type RunCorrectedEventTimelinePayload,
  type RunMultiscaleDetectionPayload,
  type RunStrictShotGenerationPayload,
  type RunVlmShotAnalysisPayload,
} from "../lib/workspace";
import type { ProjectItem } from "../types/project";
import type {
  AdjacentStoryReassignmentResult,
  CorrectedEventTimelineResult,
  DynamicSegmentGenerationResult,
  DualSignalBoundaryDetectionResult,
  EventMergingResult,
  MultiscaleDetectionResult,
  SceneDetectorMode,
  StrictShotGenerationResult,
  VlmShotAnalysisResult,
} from "../types/workspace";
import type { SystemConfig } from "../types/settings";
import { ProjectWorkspaceHeader } from "./workspace/project-workspace-header";
import { WorkspaceControlPanel } from "./workspace/workspace-control-panel";
import { WorkspaceResultsPanel } from "./workspace/workspace-results-panel";
import {
  defaultBoundaryPayload,
  defaultDynamicSegmentPayload,
  defaultEventMergingPayload,
  defaultMultiscalePayload,
  defaultStrictShotPayload,
  defaultVlmPayload,
  processingModeProfiles,
  type BoundaryControlsPayload,
  type DynamicSegmentControlsPayload,
  type EventMergingControlsPayload,
  type MultiscaleControlsPayload,
  type ProcessingMode,
  type StrictShotControlsPayload,
} from "./workspace/workspace-config";
import { useVlmControls } from "./workspace/use-vlm-controls";

type ProjectWorkspaceProps = {
  project: ProjectItem | null;
  onBack: () => void;
  settings: SystemConfig;
};
export function ProjectWorkspace({ project, onBack, settings }: ProjectWorkspaceProps) {
  const [processingMode, setProcessingMode] = useState<ProcessingMode>("standard");
  const [sceneDetectorMode, setSceneDetectorMode] =
    useState<SceneDetectorMode>("transnetv2-cuda");
  const [multiscalePayload, setMultiscalePayload] =
    useState<MultiscaleControlsPayload>(defaultMultiscalePayload);
  const [boundaryPayload, setBoundaryPayload] =
    useState<BoundaryControlsPayload>(defaultBoundaryPayload);
  const [dynamicSegmentPayload, setDynamicSegmentPayload] =
    useState<DynamicSegmentControlsPayload>(defaultDynamicSegmentPayload);
  const [eventMergingPayload, setEventMergingPayload] =
    useState<EventMergingControlsPayload>(defaultEventMergingPayload);
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
  } = useVlmControls(defaultVlmPayload);
  const [multiscaleResult, setMultiscaleResult] = useState<MultiscaleDetectionResult | null>(null);
  const [boundaryResult, setBoundaryResult] = useState<DualSignalBoundaryDetectionResult | null>(
    null,
  );
  const [dynamicSegmentResult, setDynamicSegmentResult] =
    useState<DynamicSegmentGenerationResult | null>(null);
  const [eventMergingResult, setEventMergingResult] = useState<EventMergingResult | null>(null);
  const [strictShotResult, setStrictShotResult] = useState<StrictShotGenerationResult | null>(null);
  const [vlmShotAnalysisResult, setVlmShotAnalysisResult] =
    useState<VlmShotAnalysisResult | null>(null);
  const [adjacentStoryReassignmentResult, setAdjacentStoryReassignmentResult] =
    useState<AdjacentStoryReassignmentResult | null>(null);
  const [correctedEventTimelineResult, setCorrectedEventTimelineResult] =
    useState<CorrectedEventTimelineResult | null>(null);
  const [isRunningMultiscale, setIsRunningMultiscale] = useState(false);
  const [isRunningBoundary, setIsRunningBoundary] = useState(false);
  const [isRunningDynamicSegments, setIsRunningDynamicSegments] = useState(false);
  const [isRunningEventMerging, setIsRunningEventMerging] = useState(false);
  const [isRunningStrictShots, setIsRunningStrictShots] = useState(false);
  const [isRunningVlm, setIsRunningVlm] = useState(false);
  const [isRunningAdjacent, setIsRunningAdjacent] = useState(false);

  const activeVlmConfig =
    settings.vlmConfigs.find(
      (config) => config.endpoint.trim() && config.key.trim() && config.model.trim(),
    ) ?? null;
  const applyProcessingMode = (mode: ProcessingMode) => {
    const profile = processingModeProfiles[mode];
    setProcessingMode(mode);
    setMultiscalePayload(profile.multiscale);
    setBoundaryPayload(profile.boundary);
    setDynamicSegmentPayload(profile.dynamicSegments);
    setEventMergingPayload(profile.eventMerging);
    setStrictShotPayload(profile.strictShots);
    setVlmPayload(profile.vlm);
    setMultiscaleResult(null);
    setBoundaryResult(null);
    setDynamicSegmentResult(null);
    setEventMergingResult(null);
    setStrictShotResult(null);
    setVlmShotAnalysisResult(null);
    setAdjacentStoryReassignmentResult(null);
    setCorrectedEventTimelineResult(null);
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

  const updateDynamicSegmentField = <K extends keyof DynamicSegmentControlsPayload,>(
    key: K,
    value: string,
  ) => {
    const parsed = Number(value);
    setDynamicSegmentPayload((current) => ({
      ...current,
      [key]: Number.isFinite(parsed) ? parsed : current[key],
    }));
  };

  const updateEventMergingField = <K extends keyof EventMergingControlsPayload,>(
    key: K,
    value: string,
  ) => {
    const parsed = Number(value);
    setEventMergingPayload((current) => ({
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

  const handleRunMultiscale = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }

    try {
      setIsRunningMultiscale(true);
      setBoundaryResult(null);
      setDynamicSegmentResult(null);
      setEventMergingResult(null);
      setStrictShotResult(null);
      setVlmShotAnalysisResult(null);
      setAdjacentStoryReassignmentResult(null);
      setCorrectedEventTimelineResult(null);
      const nextPayload: RunMultiscaleDetectionPayload = {
        ...multiscalePayload,
        scene_detector_mode: sceneDetectorMode,
      };
      const nextResult = await runMultiscaleDetection(project.id, nextPayload);
      setMultiscaleResult(nextResult);
      toast.success("Layer 07 finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Layer 07 failed: ${message}`);
    } finally {
      setIsRunningMultiscale(false);
    }
  };

  const handleRunBoundary = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }

    if (!multiscaleResult) {
      toast.error("Run Layer 07 first.");
      return;
    }

    try {
      setIsRunningBoundary(true);
      setDynamicSegmentResult(null);
      setEventMergingResult(null);
      setStrictShotResult(null);
      setVlmShotAnalysisResult(null);
      setAdjacentStoryReassignmentResult(null);
      setCorrectedEventTimelineResult(null);
      const nextPayload: RunDualSignalBoundaryDetectionPayload = {
        ...boundaryPayload,
        scene_detector_mode: sceneDetectorMode,
        suspiciousRegions: multiscaleResult.suspiciousRegions,
        sceneDetectorCandidates: multiscaleResult.sceneDetectorCandidates,
        sceneDetectorBackend: multiscaleResult.sceneDetector.backend,
      };
      const nextResult = await runDualSignalBoundaryDetection(project.id, nextPayload);
      setBoundaryResult(nextResult);
      toast.success("Layer 08 finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Layer 08 failed: ${message}`);
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
      toast.error("Run Layer 08 first.");
      return;
    }

    try {
      setIsRunningStrictShots(true);
      setVlmShotAnalysisResult(null);
      setAdjacentStoryReassignmentResult(null);
      setCorrectedEventTimelineResult(null);
      const nextPayload: RunStrictShotGenerationPayload = {
        ...strictShotPayload,
        boundaryCandidates: boundaryResult.boundaryCandidates,
      };
      const nextResult = await runStrictShotGeneration(project.id, nextPayload);
      console.log("[Workspace] Strict shots", nextResult);
      setStrictShotResult(nextResult);
      toast.success("Strict shots finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Strict shots failed: ${message}`);
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
      toast.error("Run strict shots first.");
      return;
    }

    if (!activeVlmConfig) {
      toast.error("Set a VLM endpoint, key, and model in Settings first.");
      return;
    }

    try {
      setIsRunningVlm(true);
      setAdjacentStoryReassignmentResult(null);
      setCorrectedEventTimelineResult(null);
      const nextPayload: RunVlmShotAnalysisPayload = {
        ...vlmPayload,
        shots: strictShotResult.shots,
        vlmConfig: {
          endpoint: activeVlmConfig.endpoint.trim(),
          key: activeVlmConfig.key.trim(),
          model: activeVlmConfig.model.trim(),
        },
      };
      const nextResult = await runVlmShotAnalysis(project.id, nextPayload);
      console.log("[Workspace] VLM shot analysis", nextResult);
      setVlmShotAnalysisResult(nextResult);
      toast.success("VLM pass finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`VLM pass failed: ${message}`);
    } finally {
      setIsRunningVlm(false);
    }
  };

  const handleRunAdjacent = async () => {
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
      setIsRunningAdjacent(true);
      const nextPayload: RunAdjacentStoryReassignmentPayload = {
        groups: vlmShotAnalysisResult.groups,
        llmConfig: {
          endpoint: activeVlmConfig.endpoint.trim(),
          key: activeVlmConfig.key.trim(),
          model: activeVlmConfig.model.trim(),
        },
      };
      const nextResult = await runAdjacentStoryReassignment(project.id, nextPayload);
      const correctedPayload: RunCorrectedEventTimelinePayload = {
        groups: vlmShotAnalysisResult.groups,
        adjacentPairs: nextResult.pairs,
        shots: strictShotResult?.shots ?? [],
      };
      const correctedResult = await runCorrectedEventTimeline(project.id, correctedPayload);
      console.log("[Workspace] Adjacent story reassignment", nextResult);
      console.log("[Workspace] Corrected event timeline", correctedResult);
      setAdjacentStoryReassignmentResult(nextResult);
      setCorrectedEventTimelineResult(correctedResult);
      toast.success("Adjacent pass finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Adjacent pass failed: ${message}`);
    } finally {
      setIsRunningAdjacent(false);
    }
  };

  const handleRunDynamicSegments = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }

    if (!boundaryResult) {
      toast.error("Run Layer 08 first.");
      return;
    }

    try {
      setIsRunningDynamicSegments(true);
      setEventMergingResult(null);
      const nextPayload: RunDynamicSegmentGenerationPayload = {
        ...dynamicSegmentPayload,
        boundaryCandidates: boundaryResult.boundaryCandidates,
      };
      const nextResult = await runDynamicSegmentGeneration(project.id, nextPayload);
      setDynamicSegmentResult(nextResult);
      toast.success("Dynamic segments finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Dynamic segments failed: ${message}`);
    } finally {
      setIsRunningDynamicSegments(false);
    }
  };

  const handleRunEventMerging = async () => {
    if (!project) {
      toast.error("Project is unavailable.");
      return;
    }

    if (!dynamicSegmentResult || !boundaryResult) {
      toast.error("Run dynamic segments first.");
      return;
    }

    try {
      setIsRunningEventMerging(true);
      const nextPayload: RunEventMergingPayload = {
        ...eventMergingPayload,
        dynamicSegments: dynamicSegmentResult.segments,
        boundaryCandidates: boundaryResult.boundaryCandidates,
      };
      const nextResult = await runEventMerging(project.id, nextPayload);
      setEventMergingResult(nextResult);
      toast.success("Event merge finished.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      toast.error(`Event merge failed: ${message}`);
    } finally {
      setIsRunningEventMerging(false);
    }
  };
  return (
    <div className="relative flex h-screen w-screen select-none flex-col overflow-hidden bg-black p-6 font-sans text-white md:p-10">
      <div className="fincap-gradient pointer-events-none absolute inset-0" />
      <ProjectWorkspaceHeader project={project} onBack={onBack} />

      <main className="relative z-10 flex min-h-0 flex-1 flex-col gap-6 xl:grid xl:grid-cols-[1.1fr_0.9fr]">
        <motion.section
          initial={{ opacity: 0, scale: 0.98 }}
          animate={{ opacity: 1, scale: 1 }}
          transition={{ duration: 0.45, ease: [0.16, 1, 0.3, 1] }}
          className="glass video-glow flex min-h-0 flex-col overflow-hidden rounded-3xl border border-white/[0.04] md:rounded-[48px]"
        >
          <WorkspaceControlPanel
            project={project}
            processingMode={processingMode}
            sceneDetectorMode={sceneDetectorMode}
            multiscalePayload={multiscalePayload}
            boundaryPayload={boundaryPayload}
            dynamicSegmentPayload={dynamicSegmentPayload}
            eventMergingPayload={eventMergingPayload}
            strictShotPayload={strictShotPayload}
            vlmPayload={vlmPayload}
            isRunningMultiscale={isRunningMultiscale}
            isRunningBoundary={isRunningBoundary}
            isRunningDynamicSegments={isRunningDynamicSegments}
            isRunningEventMerging={isRunningEventMerging}
            isRunningStrictShots={isRunningStrictShots}
            isRunningVlm={isRunningVlm}
            isRunningAdjacent={isRunningAdjacent}
            hasMultiscaleResult={Boolean(multiscaleResult)}
            hasBoundaryResult={Boolean(boundaryResult)}
            hasDynamicSegmentResult={Boolean(dynamicSegmentResult)}
            hasStrictShotResult={Boolean(strictShotResult)}
            hasVlmShotAnalysisResult={Boolean(vlmShotAnalysisResult)}
            activeVlmModel={activeVlmConfig?.model ?? null}
            onApplyProcessingMode={applyProcessingMode}
            onSceneDetectorModeChange={setSceneDetectorMode}
            onUpdateMultiscaleField={updateMultiscaleField}
            onUpdateBoundaryField={updateBoundaryField}
            onUpdateDynamicSegmentField={updateDynamicSegmentField}
            onUpdateEventMergingField={updateEventMergingField}
            onUpdateStrictShotField={updateStrictShotField}
            onUpdateVlmField={updateVlmField}
            onUpdateVlmSubtitleRegionField={updateVlmSubtitleRegionField}
            onAddCharacterReference={addCharacterReference}
            onUpdateCharacterReference={updateCharacterReference}
            onRemoveCharacterReference={removeCharacterReference}
            onRunMultiscale={() => void handleRunMultiscale()}
            onRunBoundary={() => void handleRunBoundary()}
            onRunDynamicSegments={() => void handleRunDynamicSegments()}
            onRunEventMerging={() => void handleRunEventMerging()}
            onRunStrictShots={() => void handleRunStrictShots()}
            onRunVlm={() => void handleRunVlm()}
            onRunAdjacent={() => void handleRunAdjacent()}
          />
        </motion.section>

        <motion.section
          initial={{ opacity: 0, scale: 0.98 }}
          animate={{ opacity: 1, scale: 1 }}
          transition={{ duration: 0.45, delay: 0.05, ease: [0.16, 1, 0.3, 1] }}
          className="glass video-glow flex min-h-0 flex-col gap-5 overflow-hidden rounded-3xl border border-white/[0.04] p-6 md:rounded-[48px] md:p-8"
        >
          <WorkspaceResultsPanel
            multiscaleResult={multiscaleResult}
            boundaryResult={boundaryResult}
            dynamicSegmentResult={dynamicSegmentResult}
            eventMergingResult={eventMergingResult}
            strictShotResult={strictShotResult}
            vlmShotAnalysisResult={vlmShotAnalysisResult}
            adjacentStoryReassignmentResult={adjacentStoryReassignmentResult}
            correctedEventTimelineResult={correctedEventTimelineResult}
          />
        </motion.section>
      </main>
    </div>
  );
}
