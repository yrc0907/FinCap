import { Radar, ScanSearch, SplitSquareVertical } from "lucide-react";

import type { ProjectItem } from "../../types/project";
import type { SceneDetectorMode } from "../../types/workspace";
import { Button } from "../ui/button";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "../ui/select";
import {
  processingModeProfiles,
  sceneDetectorModeOptions,
  type BoundaryControlsPayload,
  type DynamicSegmentControlsPayload,
  type EventMergingControlsPayload,
  type MultiscaleControlsPayload,
  type ProcessingMode,
  type StrictShotControlsPayload,
  type VlmControlsPayload,
} from "./workspace-config";
import { WorkspaceNumericField } from "./workspace-numeric-field";
import { WorkspaceSemanticControls } from "./workspace-semantic-controls";

type WorkspaceControlPanelProps = {
  project: ProjectItem | null;
  processingMode: ProcessingMode;
  sceneDetectorMode: SceneDetectorMode;
  multiscalePayload: MultiscaleControlsPayload;
  boundaryPayload: BoundaryControlsPayload;
  dynamicSegmentPayload: DynamicSegmentControlsPayload;
  eventMergingPayload: EventMergingControlsPayload;
  strictShotPayload: StrictShotControlsPayload;
  vlmPayload: VlmControlsPayload;
  isRunningMultiscale: boolean;
  isRunningBoundary: boolean;
  isRunningDynamicSegments: boolean;
  isRunningEventMerging: boolean;
  isRunningStrictShots: boolean;
  isRunningVlm: boolean;
  isRunningAdjacent: boolean;
  hasMultiscaleResult: boolean;
  hasBoundaryResult: boolean;
  hasDynamicSegmentResult: boolean;
  hasStrictShotResult: boolean;
  hasVlmShotAnalysisResult: boolean;
  activeVlmModel: string | null;
  onApplyProcessingMode: (mode: ProcessingMode) => void;
  onSceneDetectorModeChange: (mode: SceneDetectorMode) => void;
  onUpdateMultiscaleField: <K extends keyof MultiscaleControlsPayload>(key: K, value: string) => void;
  onUpdateBoundaryField: <K extends keyof BoundaryControlsPayload>(key: K, value: string) => void;
  onUpdateDynamicSegmentField: <K extends keyof DynamicSegmentControlsPayload>(
    key: K,
    value: string,
  ) => void;
  onUpdateEventMergingField: <K extends keyof EventMergingControlsPayload>(
    key: K,
    value: string,
  ) => void;
  onUpdateStrictShotField: <K extends keyof StrictShotControlsPayload>(key: K, value: string) => void;
  onUpdateVlmField: <K extends keyof VlmControlsPayload>(key: K, value: string | boolean) => void;
  onUpdateVlmSubtitleRegionField: (
    key: keyof VlmControlsPayload["subtitleRegion"],
    value: string,
  ) => void;
  onAddCharacterReference: () => void;
  onUpdateCharacterReference: (
    id: string,
    key: "name" | "imageBase64",
    value: string,
  ) => void;
  onRemoveCharacterReference: (id: string) => void;
  onRunMultiscale: () => void;
  onRunBoundary: () => void;
  onRunDynamicSegments: () => void;
  onRunEventMerging: () => void;
  onRunStrictShots: () => void;
  onRunVlm: () => void;
  onRunAdjacent: () => void;
};

export function WorkspaceControlPanel({
  project,
  processingMode,
  sceneDetectorMode,
  multiscalePayload,
  boundaryPayload,
  dynamicSegmentPayload,
  eventMergingPayload,
  strictShotPayload,
  vlmPayload,
  isRunningMultiscale,
  isRunningBoundary,
  isRunningDynamicSegments,
  isRunningEventMerging,
  isRunningStrictShots,
  isRunningVlm,
  isRunningAdjacent,
  hasMultiscaleResult,
  hasBoundaryResult,
  hasDynamicSegmentResult,
  hasStrictShotResult,
  hasVlmShotAnalysisResult,
  activeVlmModel,
  onApplyProcessingMode,
  onSceneDetectorModeChange,
  onUpdateMultiscaleField,
  onUpdateBoundaryField,
  onUpdateDynamicSegmentField,
  onUpdateEventMergingField,
  onUpdateStrictShotField,
  onUpdateVlmField,
  onUpdateVlmSubtitleRegionField,
  onAddCharacterReference,
  onUpdateCharacterReference,
  onRemoveCharacterReference,
  onRunMultiscale,
  onRunBoundary,
  onRunDynamicSegments,
  onRunEventMerging,
  onRunStrictShots,
  onRunVlm,
  onRunAdjacent,
}: WorkspaceControlPanelProps) {
  return (
    <>
      <div className="border-b border-white/5 p-6 md:p-8">
        <div className="flex items-start justify-between gap-4">
          <div>
            <div className="text-[10px] font-mono uppercase tracking-[0.32em] text-white/25">
              Active Project
            </div>
            <h1 className="mt-3 text-2xl font-black uppercase tracking-tight md:text-3xl">
              {project?.name ?? "No Project"}
            </h1>
            <div className="mt-3 text-[11px] font-mono uppercase tracking-[0.24em] text-white/25">
              {project?.meta ?? "No Source"}
            </div>
          </div>
          <div className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.28em] text-white/60">
            Full Timeline
          </div>
        </div>
      </div>
      <div className="flex-1 space-y-5 overflow-y-auto p-6 md:p-8">
        <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
          <div className="border-b border-white/6 p-5">
            <div className="grid gap-4 md:grid-cols-2">
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Processing Mode
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Active {processingModeProfiles[processingMode].label}
                </div>
              </div>
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Scene Route
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Shared Across Layers
                </div>
              </div>
              <Select
                value={processingMode}
                onValueChange={(value) => onApplyProcessingMode(value as ProcessingMode)}
              >
                <SelectTrigger className="h-12 rounded-2xl text-[11px] font-black uppercase tracking-[0.2em]">
                  <SelectValue placeholder="Select Mode" />
                </SelectTrigger>
                <SelectContent>
                  <SelectItem value="fast">Fast</SelectItem>
                  <SelectItem value="standard">Standard</SelectItem>
                  <SelectItem value="high">High</SelectItem>
                </SelectContent>
              </Select>
              <Select
                value={sceneDetectorMode}
                onValueChange={(value) => onSceneDetectorModeChange(value as SceneDetectorMode)}
              >
                <SelectTrigger className="h-12 rounded-2xl text-[11px] font-black uppercase tracking-[0.2em]">
                  <SelectValue placeholder="Select Route" />
                </SelectTrigger>
                <SelectContent>
                  {sceneDetectorModeOptions.map((option) => (
                    <SelectItem key={option.value} value={option.value}>
                      {option.label}
                    </SelectItem>
                  ))}
                </SelectContent>
              </Select>
            </div>
          </div>
        </section>

        <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
          <div className="border-b border-white/6 p-5">
            <div className="flex items-center gap-3">
              <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
                <ScanSearch size={18} className="text-white/50" />
              </div>
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Layer 07
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Full Timeline Multi-Scale Detection
                </div>
              </div>
            </div>
          </div>

          <div className="grid gap-4 p-5 md:grid-cols-2">
            <WorkspaceNumericField
              label="Coarse Window"
              value={multiscalePayload.coarse_window_sec}
              step="0.1"
              onChange={(value) => onUpdateMultiscaleField("coarse_window_sec", value)}
            />
            <WorkspaceNumericField
              label="Coarse Stride"
              value={multiscalePayload.coarse_stride_sec}
              step="0.1"
              onChange={(value) => onUpdateMultiscaleField("coarse_stride_sec", value)}
            />
            <WorkspaceNumericField
              label="Coarse Threshold"
              value={multiscalePayload.coarse_score_threshold}
              step="0.01"
              onChange={(value) => onUpdateMultiscaleField("coarse_score_threshold", value)}
            />
            <WorkspaceNumericField
              label="Merge Gap"
              value={multiscalePayload.coarse_merge_gap_sec}
              step="0.1"
              onChange={(value) => onUpdateMultiscaleField("coarse_merge_gap_sec", value)}
            />
            <WorkspaceNumericField
              label="Fine Radius"
              value={multiscalePayload.fine_search_radius_sec}
              step="0.1"
              onChange={(value) => onUpdateMultiscaleField("fine_search_radius_sec", value)}
            />
            <WorkspaceNumericField
              label="Fine Step"
              value={multiscalePayload.fine_sample_step_sec}
              step="0.01"
              onChange={(value) => onUpdateMultiscaleField("fine_sample_step_sec", value)}
            />
            <WorkspaceNumericField
              label="Fine Threshold"
              value={multiscalePayload.fine_score_threshold}
              step="0.01"
              fullWidth
              onChange={(value) => onUpdateMultiscaleField("fine_score_threshold", value)}
            />
          </div>

          <div className="border-t border-white/6 p-5">
            <Button
              onClick={onRunMultiscale}
              disabled={isRunningMultiscale || !project}
              size="lg"
              className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
            >
              <Radar size={14} />
              {isRunningMultiscale ? "Running Layer 07" : "Run Layer 07"}
            </Button>
          </div>
        </section>

        <WorkspaceSemanticControls
          projectReady={Boolean(project)}
          hasBoundaryResult={hasBoundaryResult}
          hasStrictShotResult={hasStrictShotResult}
          hasVlmShotAnalysisResult={hasVlmShotAnalysisResult}
          isRunningStrictShots={isRunningStrictShots}
          isRunningVlm={isRunningVlm}
          isRunningAdjacent={isRunningAdjacent}
          strictShotPayload={strictShotPayload}
          vlmPayload={vlmPayload}
          activeVlmModel={activeVlmModel}
          onUpdateStrictShotField={onUpdateStrictShotField}
          onUpdateVlmField={onUpdateVlmField}
          onUpdateVlmSubtitleRegionField={onUpdateVlmSubtitleRegionField}
          onAddCharacterReference={onAddCharacterReference}
          onUpdateCharacterReference={onUpdateCharacterReference}
          onRemoveCharacterReference={onRemoveCharacterReference}
          onRunStrictShots={onRunStrictShots}
          onRunVlm={onRunVlm}
          onRunAdjacent={onRunAdjacent}
        />

        <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
          <div className="border-b border-white/6 p-5">
            <div className="flex items-center gap-3">
              <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
                <SplitSquareVertical size={18} className="text-white/50" />
              </div>
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Layer 08
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Dual-Signal Boundary Detection
                </div>
              </div>
            </div>
          </div>

          <div className="grid gap-4 p-5 md:grid-cols-2">
            <WorkspaceNumericField
              label="Subject Step"
              value={boundaryPayload.subject_sample_step_sec}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("subject_sample_step_sec", value)}
            />
            <WorkspaceNumericField
              label="Subject Core Ratio"
              value={boundaryPayload.subject_core_ratio}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("subject_core_ratio", value)}
            />
            <WorkspaceNumericField
              label="Subject Threshold"
              value={boundaryPayload.subject_score_threshold}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("subject_score_threshold", value)}
            />
            <WorkspaceNumericField
              label="Scene Step"
              value={boundaryPayload.scene_sample_step_sec}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("scene_sample_step_sec", value)}
            />
            <WorkspaceNumericField
              label="Scene Threshold"
              value={boundaryPayload.scene_score_threshold}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("scene_score_threshold", value)}
            />
            <WorkspaceNumericField
              label="Fusion Gap"
              value={boundaryPayload.fusion_gap_sec}
              step="0.01"
              onChange={(value) => onUpdateBoundaryField("fusion_gap_sec", value)}
            />
            <WorkspaceNumericField
              label="High Confidence Score"
              value={boundaryPayload.fusion_high_confidence_score}
              step="0.01"
              fullWidth
              onChange={(value) => onUpdateBoundaryField("fusion_high_confidence_score", value)}
            />
          </div>

          <div className="border-t border-white/6 p-5">
            <Button
              onClick={onRunBoundary}
              disabled={isRunningBoundary || !project || !hasMultiscaleResult}
              size="lg"
              className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
            >
              <SplitSquareVertical size={14} />
              {isRunningBoundary ? "Running Layer 08" : "Run Layer 08"}
            </Button>
          </div>
        </section>
        <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
          <div className="border-b border-white/6 p-5">
            <div className="flex items-center gap-3">
              <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
                <Radar size={18} className="text-white/50" />
              </div>
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Dynamic Segments
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Chapter 08
                </div>
              </div>
            </div>
          </div>

          <div className="grid gap-4 p-5 md:grid-cols-2">
            <WorkspaceNumericField
              label="Min Segment"
              value={dynamicSegmentPayload.min_segment_sec}
              step="0.1"
              onChange={(value) => onUpdateDynamicSegmentField("min_segment_sec", value)}
            />
            <WorkspaceNumericField
              label="Short Warning"
              value={dynamicSegmentPayload.abnormal_short_sec}
              step="0.1"
              onChange={(value) => onUpdateDynamicSegmentField("abnormal_short_sec", value)}
            />
            <WorkspaceNumericField
              label="Dedupe Gap"
              value={dynamicSegmentPayload.dedupe_epsilon_sec}
              step="0.01"
              fullWidth
              onChange={(value) => onUpdateDynamicSegmentField("dedupe_epsilon_sec", value)}
            />
          </div>

          <div className="border-t border-white/6 p-5">
            <Button
              onClick={onRunDynamicSegments}
              disabled={isRunningDynamicSegments || !project || !hasBoundaryResult}
              size="lg"
              className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
            >
              <Radar size={14} />
              {isRunningDynamicSegments ? "Running Segments" : "Run Segments"}
            </Button>
          </div>
        </section>
        <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
          <div className="border-b border-white/6 p-5">
            <div className="flex items-center gap-3">
              <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
                <SplitSquareVertical size={18} className="text-white/50" />
              </div>
              <div>
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Event Merge
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                  Chapter 09
                </div>
              </div>
            </div>
          </div>

          <div className="grid gap-4 p-5 md:grid-cols-2">
            <WorkspaceNumericField
              label="Target Event"
              value={eventMergingPayload.target_event_sec}
              step="0.1"
              onChange={(value) => onUpdateEventMergingField("target_event_sec", value)}
            />
            <WorkspaceNumericField
              label="Max Event"
              value={eventMergingPayload.max_event_sec}
              step="0.1"
              onChange={(value) => onUpdateEventMergingField("max_event_sec", value)}
            />
            <WorkspaceNumericField
              label="Short Segment"
              value={eventMergingPayload.short_segment_sec}
              step="0.1"
              onChange={(value) => onUpdateEventMergingField("short_segment_sec", value)}
            />
            <WorkspaceNumericField
              label="Substantial"
              value={eventMergingPayload.substantial_segment_sec}
              step="0.1"
              onChange={(value) => onUpdateEventMergingField("substantial_segment_sec", value)}
            />
            <WorkspaceNumericField
              label="Keep Score"
              value={eventMergingPayload.keep_boundary_score}
              step="0.01"
              onChange={(value) => onUpdateEventMergingField("keep_boundary_score", value)}
            />
            <WorkspaceNumericField
              label="Strong Score"
              value={eventMergingPayload.strong_boundary_score}
              step="0.01"
              onChange={(value) => onUpdateEventMergingField("strong_boundary_score", value)}
            />
          </div>

          <div className="border-t border-white/6 p-5">
            <Button
              onClick={onRunEventMerging}
              disabled={isRunningEventMerging || !project || !hasDynamicSegmentResult}
              size="lg"
              className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
            >
              <SplitSquareVertical size={14} />
              {isRunningEventMerging ? "Running Events" : "Run Events"}
            </Button>
          </div>
        </section>
      </div>
    </>
  );
}
