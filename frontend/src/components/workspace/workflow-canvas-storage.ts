import type { WorkflowCanvasGraphNode } from "./workflow-canvas-graph";

type StoredWorkflowCanvasNode = {
  id: string;
  position: WorkflowCanvasGraphNode["position"];
};

const buildStorageKey = (projectId: string) => `fincap.workflow-layout:${projectId}`;

export function loadWorkflowCanvasNodes(
  projectId: string | null | undefined,
  defaultNodes: WorkflowCanvasGraphNode[],
): WorkflowCanvasGraphNode[] {
  if (!projectId || typeof window === "undefined") {
    return defaultNodes;
  }

  const rawValue = window.localStorage.getItem(buildStorageKey(projectId));
  if (!rawValue) {
    return defaultNodes;
  }

  try {
    const storedNodes = JSON.parse(rawValue) as StoredWorkflowCanvasNode[];
    const positionById = new Map(storedNodes.map((node) => [node.id, node.position]));
    return defaultNodes.map((node) => ({
      ...node,
      position: positionById.get(node.id) ?? node.position,
    }));
  } catch {
    return defaultNodes;
  }
}

export function saveWorkflowCanvasNodes(
  projectId: string | null | undefined,
  nodes: WorkflowCanvasGraphNode[],
) {
  if (!projectId || typeof window === "undefined") {
    return;
  }

  const payload: StoredWorkflowCanvasNode[] = nodes.map((node) => ({
    id: node.id,
    position: node.position,
  }));

  window.localStorage.setItem(buildStorageKey(projectId), JSON.stringify(payload));
}
