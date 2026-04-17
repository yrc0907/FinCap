import type { Edge, Node } from "@xyflow/react";

export type WorkflowCanvasNodeKind =
  | "upload"
  | "boundary"
  | "shots"
  | "semantic"
  | "story"
  | "scene-logic"
  | "export";

export type WorkflowCanvasNodeData = {
  kind: WorkflowCanvasNodeKind;
};

export type WorkflowCanvasGraphNode = Node<WorkflowCanvasNodeData, "workflow">;

export function buildWorkflowCanvasGraph(): {
  nodes: WorkflowCanvasGraphNode[];
  edges: Edge[];
} {
  return {
    nodes: [
      {
        id: "upload",
        type: "workflow",
        position: { x: 120, y: 110 },
        data: { kind: "upload" },
      },
      {
        id: "boundary",
        type: "workflow",
        position: { x: 470, y: 110 },
        data: { kind: "boundary" },
      },
      {
        id: "shots",
        type: "workflow",
        position: { x: 820, y: 110 },
        data: { kind: "shots" },
      },
      {
        id: "semantic",
        type: "workflow",
        position: { x: 1170, y: 110 },
        data: { kind: "semantic" },
      },
      {
        id: "story",
        type: "workflow",
        position: { x: 1170, y: 430 },
        data: { kind: "story" },
      },
      {
        id: "scene-logic",
        type: "workflow",
        position: { x: 820, y: 430 },
        data: { kind: "scene-logic" },
      },
      {
        id: "export",
        type: "workflow",
        position: { x: 470, y: 430 },
        data: { kind: "export" },
      },
    ],
    edges: [
      {
        id: "upload-boundary",
        source: "upload",
        target: "boundary",
      },
      {
        id: "boundary-shots",
        source: "boundary",
        target: "shots",
      },
      {
        id: "shots-semantic",
        source: "shots",
        target: "semantic",
      },
      {
        id: "semantic-story",
        source: "semantic",
        target: "story",
      },
      {
        id: "story-scene-logic",
        source: "story",
        target: "scene-logic",
      },
      {
        id: "scene-logic-export",
        source: "scene-logic",
        target: "export",
      },
    ],
  };
}
