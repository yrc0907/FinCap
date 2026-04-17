import type { NodeProps, NodeTypes } from "@xyflow/react";

import { WorkspaceBoundaryNode } from "./workspace-boundary-node";
import { WorkspaceExportNode } from "./workspace-export-node";
import { WorkspaceSceneLogicNode } from "./workspace-scene-logic-node";
import { WorkspaceSemanticNode } from "./workspace-semantic-node";
import { WorkspaceShotNode } from "./workspace-shot-node";
import { WorkspaceStoryNode } from "./workspace-story-node";
import { WorkspaceUploadNode } from "./workspace-upload-node";
import type { ProjectWorkspaceFlowState } from "./use-project-workspace-state";
import type {
  WorkflowCanvasGraphNode,
  WorkflowCanvasNodeKind,
} from "./workflow-canvas-graph";
import { WorkflowCanvasNodeFrame } from "./workflow-canvas-node";
import type { WorkspacePreviewKind } from "./workspace-preview-state";

type OpenPreview = (kind: Exclude<WorkspacePreviewKind, null>) => void;

type WorkflowCanvasNodeRendererProps = {
  kind: WorkflowCanvasNodeKind;
  state: ProjectWorkspaceFlowState;
  openPreview: OpenPreview;
};

export function WorkflowCanvasNodeRenderer({
  kind,
  state,
  openPreview,
}: WorkflowCanvasNodeRendererProps) {
  switch (kind) {
    case "upload":
      return (
        <WorkspaceUploadNode
          project={state.project}
          isUploading={state.isUploadingVideo}
          tone={state.nodeFeedback.upload.tone}
          message={state.nodeFeedback.upload.message}
          onUpload={(file) => void state.handleUploadVideo(file)}
        />
      );
    case "boundary":
      return (
        <WorkspaceBoundaryNode
          processingMode={state.processingMode}
          sceneDetectorMode={state.sceneDetectorMode}
          multiscaleResult={state.multiscaleResult}
          boundaryResult={state.boundaryResult}
          isRunning={state.isRunningBoundary}
          tone={state.nodeFeedback.boundary.tone}
          message={state.nodeFeedback.boundary.message}
          onRun={() => void state.handleRunBoundaryFlow()}
          onPreview={() => openPreview("boundary")}
          onAdvanced={() => openPreview("boundary-advanced")}
        />
      );
    case "shots":
      return (
        <WorkspaceShotNode
          result={state.strictShotResult}
          isRunning={state.isRunningStrictShots}
          tone={state.nodeFeedback.shots.tone}
          message={state.nodeFeedback.shots.message}
          onRun={() => void state.handleRunStrictShots()}
          onPreview={() => openPreview("shots")}
        />
      );
    case "semantic":
      return (
        <WorkspaceSemanticNode
          result={state.vlmShotAnalysisResult}
          vlmPayload={state.vlmPayload}
          activeModel={state.activeVlmConfig?.model ?? null}
          isRunning={state.isRunningVlm}
          tone={state.nodeFeedback.semantic.tone}
          message={state.nodeFeedback.semantic.message}
          onOpenOcr={() => openPreview("ocr")}
          onOpenAsr={() => openPreview("asr")}
          onOpenReferences={() => openPreview("references")}
          onOpenVlmGrid={() => openPreview("vlm")}
          onRun={() => void state.handleRunVlm()}
        />
      );
    case "story":
      return (
        <WorkspaceStoryNode
          adjacentResult={state.adjacentStoryReassignmentResult}
          correctedResult={state.correctedEventTimelineResult}
          isRunning={state.isRunningStoryFix}
          tone={state.nodeFeedback.story.tone}
          message={state.nodeFeedback.story.message}
          onRun={() => void state.handleRunStoryFix()}
          onPreview={() => openPreview("story")}
        />
      );
    case "scene-logic":
      return (
        <WorkspaceSceneLogicNode
          result={state.correctedEventTimelineResult}
          tone={state.nodeFeedback.sceneLogic.tone}
          message={state.nodeFeedback.sceneLogic.message}
          onPreview={() => openPreview("scene-logic")}
        />
      );
    case "export":
      return (
        <WorkspaceExportNode
          result={state.correctedEventTimelineResult}
          isExporting={state.isExporting}
          tone={state.nodeFeedback.export.tone}
          message={state.nodeFeedback.export.message}
          onExport={() => void state.handleExportFunctionalClips()}
        />
      );
    default:
      return null;
  }
}

function createWorkflowRuntimeNode(
  state: ProjectWorkspaceFlowState,
  openPreview: OpenPreview,
) {
  return function WorkflowRuntimeNode({
    data,
  }: NodeProps<WorkflowCanvasGraphNode>) {
    return (
      <WorkflowCanvasNodeFrame>
        <WorkflowCanvasNodeRenderer kind={data.kind} state={state} openPreview={openPreview} />
      </WorkflowCanvasNodeFrame>
    );
  };
}

export function buildWorkflowCanvasNodeTypes(
  state: ProjectWorkspaceFlowState,
  openPreview: OpenPreview,
): NodeTypes {
  return {
    workflow: createWorkflowRuntimeNode(state, openPreview),
  };
}
