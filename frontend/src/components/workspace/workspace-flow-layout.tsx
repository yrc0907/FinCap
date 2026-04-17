import { useCallback, useEffect, useMemo, useState } from "react";
import { useNodesState } from "@xyflow/react";

import { WorkflowCanvas } from "./workflow-canvas";
import { buildWorkflowCanvasGraph } from "./workflow-canvas-graph";
import { buildWorkflowCanvasNodeTypes } from "./workflow-canvas-node-registry";
import type { ProjectWorkspaceFlowState } from "./use-project-workspace-state";
import { WorkspaceAsrShell, type AsrDraftEntry } from "./workspace-asr-shell";
import { WorkspaceBoundaryPreview } from "./workspace-boundary-preview";
import { WorkspaceBoundarySettings } from "./workspace-boundary-settings";
import { WorkspaceCharacterReferenceShell } from "./workspace-character-reference-shell";
import { WorkspaceOcrShell, type OcrDraftEntry } from "./workspace-ocr-shell";
import { WorkspacePreviewDialog } from "./workspace-preview-dialog";
import type { WorkspacePreviewKind, WorkspacePreviewState } from "./workspace-preview-state";
import { WorkspaceSceneLogicPreview } from "./workspace-scene-logic-preview";
import { WorkspaceShotPreview } from "./workspace-shot-preview";
import { WorkspaceStoryPreview } from "./workspace-story-preview";
import { WorkspaceVlmGridShell } from "./workspace-vlm-grid-shell";
import {
  loadWorkflowCanvasNodes,
  saveWorkflowCanvasNodes,
} from "./workflow-canvas-storage";

type WorkspaceFlowLayoutProps = {
  state: ProjectWorkspaceFlowState;
};

export function toAsrDraftEntries(state: ProjectWorkspaceFlowState): AsrDraftEntry[] {
  if (state.vlmPayload.asrSegments.length > 0) {
    return state.vlmPayload.asrSegments.map((segment, index) => ({
      id: segment.id ?? `segment-${index}`,
      startSec: segment.startSec,
      endSec: segment.endSec,
      text: segment.text,
      format: segment.format ?? "asr",
    }));
  }

  if (state.vlmPayload.asrText.trim()) {
    return [
      {
        id: "asr-text",
        startSec: 0,
        endSec: state.strictShotResult?.videoDurationSec ?? 0,
        text: state.vlmPayload.asrText,
        format: "asr",
      },
    ];
  }

  return [];
}

export function WorkspaceFlowLayout({ state }: WorkspaceFlowLayoutProps) {
  const [previewState, setPreviewState] = useState<WorkspacePreviewState>({
    kind: null,
    selectedIndex: null,
  });
  const [asrEntries, setAsrEntries] = useState<AsrDraftEntry[]>(() => toAsrDraftEntries(state));
  const graph = useMemo(() => buildWorkflowCanvasGraph(), []);
  const initialNodes = useMemo(
    () => loadWorkflowCanvasNodes(state.project?.id, graph.nodes),
    [graph.nodes, state.project?.id],
  );
  const [nodes, setNodes, onNodesChange] = useNodesState(initialNodes);

  const openPreview = useCallback(
    (kind: Exclude<WorkspacePreviewKind, null>, selectedIndex: number | null = null) => {
      setPreviewState({ kind, selectedIndex });
    },
    [],
  );

  const closePreview = useCallback(() => {
    setPreviewState({ kind: null, selectedIndex: null });
  }, []);

  useEffect(() => {
    setNodes(loadWorkflowCanvasNodes(state.project?.id, graph.nodes));
  }, [graph.nodes, setNodes, state.project?.id]);

  useEffect(() => {
    saveWorkflowCanvasNodes(state.project?.id, nodes);
  }, [nodes, state.project?.id]);

  useEffect(() => {
    setAsrEntries(toAsrDraftEntries(state));
  }, [state.strictShotResult?.videoDurationSec, state.vlmPayload.asrSegments, state.vlmPayload.asrText]);

  const nodeTypes = useMemo(
    () => buildWorkflowCanvasNodeTypes(state, openPreview),
    [openPreview, state],
  );

  const handleChangeAsrEntries = (entries: AsrDraftEntry[]) => {
    setAsrEntries(entries);
    state.setVlmPayload((current) => ({
      ...current,
      asrSegments: entries.map((entry) => ({
        id: entry.id,
        startSec: entry.startSec,
        endSec: entry.endSec,
        text: entry.text,
        format: entry.format,
      })),
      asrText: entries.map((entry) => entry.text.trim()).filter(Boolean).join("\n"),
    }));
  };

  return (
    <>
      <section className="h-full min-h-0 rounded-[42px] border border-white/[0.05] bg-white/[0.015] p-3 md:p-4">
        <WorkflowCanvas
          nodes={nodes}
          edges={graph.edges}
          nodeTypes={nodeTypes}
          onNodesChange={onNodesChange}
        />
      </section>

      <WorkspacePreviewDialog
        open={previewState.kind === "boundary-advanced"}
        title="边界检测"
        description="Advanced"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceBoundarySettings
          processingMode={state.processingMode}
          sceneDetectorMode={state.sceneDetectorMode}
          multiscalePayload={state.multiscalePayload}
          boundaryPayload={state.boundaryPayload}
          strictShotPayload={state.strictShotPayload}
          onApplyProcessingMode={state.applyProcessingMode}
          onSceneDetectorModeChange={state.setSceneDetectorMode}
          onUpdateMultiscaleField={state.updateMultiscaleField}
          onUpdateBoundaryField={state.updateBoundaryField}
          onUpdateStrictShotField={state.updateStrictShotField}
        />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "boundary"}
        title="边界检测"
        description="Preview"
        contentClassName="max-w-[min(96vw,1680px)]"
        bodyClassName="overflow-hidden px-6 py-6"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceBoundaryPreview videoSrc={state.videoSrc} result={state.boundaryResult} />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "shots"}
        title="镜头段"
        description="Preview"
        contentClassName="max-w-[min(96vw,1680px)]"
        bodyClassName="overflow-hidden px-6 py-6"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceShotPreview
          videoSrc={state.videoSrc}
          result={state.strictShotResult}
          onSaveRange={state.handleSaveShotRange}
        />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "ocr"}
        title="OCR"
        description="Preview"
        contentClassName="max-w-[min(96vw,1680px)]"
        bodyClassName="overflow-hidden px-6 py-6"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceOcrShell
          videoSrc={state.videoSrc}
          enabled={state.vlmPayload.enableSubtitleRegion}
          subtitleRegion={state.vlmPayload.subtitleRegion}
          entries={state.vlmPayload.ocrEntries as OcrDraftEntry[]}
          onToggleEnabled={(next) => state.updateVlmField("enableSubtitleRegion", next)}
          onUpdateSubtitleRegion={(key, value) =>
            state.updateVlmSubtitleRegionField(key, String(value))
          }
          onChangeEntries={(entries) =>
            state.setVlmPayload((current) => ({
              ...current,
              ocrEntries: entries,
            }))
          }
        />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "asr"}
        title="ASR"
        description="Preview"
        contentClassName="max-w-[min(96vw,1680px)]"
        bodyClassName="overflow-hidden px-6 py-6"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceAsrShell entries={asrEntries} onChangeEntries={handleChangeAsrEntries} />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "references"}
        title="参考图"
        description="Preview"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceCharacterReferenceShell
          references={state.vlmPayload.characterReferences}
          onAdd={state.addCharacterReference}
          onUpdate={state.updateCharacterReference}
          onRemove={state.removeCharacterReference}
        />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "vlm"}
        title="VLM 九宫格"
        description="Preview"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceVlmGridShell
          videoSrc={state.videoSrc}
          shots={state.strictShotResult?.shots ?? []}
          vlmPayload={state.vlmPayload}
          activeModel={state.activeVlmConfig?.model ?? null}
          isRunning={state.isRunningVlm}
          frameOverrides={state.frameOverrides}
          onSaveOverrides={state.handleSaveFrameOverrides}
        />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "story"}
        title="修正剧情"
        description="Preview"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceStoryPreview videoSrc={state.videoSrc} result={state.correctedEventTimelineResult} />
      </WorkspacePreviewDialog>

      <WorkspacePreviewDialog
        open={previewState.kind === "scene-logic"}
        title="高爆 / 推进 / 过渡 / 结果"
        description="Preview"
        onOpenChange={(open) => {
          if (!open) {
            closePreview();
          }
        }}
      >
        <WorkspaceSceneLogicPreview
          videoSrc={state.videoSrc}
          result={state.correctedEventTimelineResult}
          onSaveRange={state.handleSaveFunctionalClipRange}
        />
      </WorkspacePreviewDialog>
    </>
  );
}
