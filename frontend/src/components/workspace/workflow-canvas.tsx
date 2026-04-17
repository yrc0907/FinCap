import { useCallback, useEffect, useMemo, useRef } from "react";
import {
  Background,
  MiniMap,
  type OnNodeDrag,
  ReactFlow,
  ReactFlowProvider,
  useReactFlow,
  type Edge,
  type NodeChange,
  type NodeTypes,
} from "@xyflow/react";

import "@xyflow/react/dist/style.css";

import type { WorkflowCanvasGraphNode } from "./workflow-canvas-graph";
import {
  buildViewportFlowBounds,
  getNextAutoZoomLevel,
  shouldAutoZoomOutForDraggedNode,
} from "./workflow-canvas-autofit";
import { WorkflowCanvasControls } from "./workflow-canvas-controls";

export const WORKFLOW_CANVAS_SURFACE_CLASS_NAME =
  "workflow-editor relative h-full min-h-0 overflow-hidden rounded-[36px] border border-white/8 bg-black/70 shadow-[0_0_80px_rgba(255,255,255,0.04)]";
const AUTO_ZOOM_MIN = 0.48;
const AUTO_ZOOM_INTERVAL_MS = 120;

type WorkflowCanvasProps = {
  nodes: WorkflowCanvasGraphNode[];
  edges: Edge[];
  nodeTypes: NodeTypes;
  onNodesChange: (changes: NodeChange<WorkflowCanvasGraphNode>[]) => void;
};

function WorkflowCanvasInner({
  nodes,
  edges,
  nodeTypes,
  onNodesChange,
}: WorkflowCanvasProps) {
  const reactFlow = useReactFlow<WorkflowCanvasGraphNode>();
  const surfaceRef = useRef<HTMLDivElement | null>(null);
  const lastAutoZoomAtRef = useRef(0);
  const nodeIdsKey = useMemo(() => nodes.map((node) => node.id).join("|"), [nodes]);

  useEffect(() => {
    const frameId = window.requestAnimationFrame(() => {
      void reactFlow.fitView({
        duration: 250,
        padding: 0.18,
        minZoom: AUTO_ZOOM_MIN,
      });
    });

    return () => {
      window.cancelAnimationFrame(frameId);
    };
  }, [nodeIdsKey, reactFlow]);

  const handleNodeDrag: OnNodeDrag<WorkflowCanvasGraphNode> = useCallback(
    (_event, node) => {
      const surface = surfaceRef.current;
      if (!surface) {
        return;
      }

      const now = performance.now();
      if (now - lastAutoZoomAtRef.current < AUTO_ZOOM_INTERVAL_MS) {
        return;
      }

      const viewport = reactFlow.getViewport();
      const viewportBounds = buildViewportFlowBounds(viewport, {
        width: surface.clientWidth,
        height: surface.clientHeight,
      });
      const nodeBounds = reactFlow.getNodesBounds([node]);

      if (!shouldAutoZoomOutForDraggedNode(nodeBounds, viewportBounds)) {
        return;
      }

      const nextZoom = getNextAutoZoomLevel(viewport.zoom, AUTO_ZOOM_MIN);
      if (nextZoom >= viewport.zoom) {
        return;
      }

      lastAutoZoomAtRef.current = now;
      void reactFlow.zoomTo(nextZoom, { duration: 120 });
    },
    [reactFlow],
  );

  const handleNodeDragStop: OnNodeDrag<WorkflowCanvasGraphNode> = useCallback(() => {
    lastAutoZoomAtRef.current = 0;
  }, []);

  return (
    <div ref={surfaceRef} className={WORKFLOW_CANVAS_SURFACE_CLASS_NAME}>
      <WorkflowCanvasControls
        onZoomIn={() => reactFlow.zoomIn()}
        onZoomOut={() => reactFlow.zoomOut()}
        onResetView={() => reactFlow.fitView({ duration: 250, padding: 0.18, minZoom: AUTO_ZOOM_MIN })}
      />
      <ReactFlow<WorkflowCanvasGraphNode>
        className="h-full"
        nodes={nodes}
        edges={edges}
        nodeTypes={nodeTypes}
        onNodesChange={onNodesChange}
        onNodeDrag={handleNodeDrag}
        onNodeDragStop={handleNodeDragStop}
        fitView
        fitViewOptions={{ padding: 0.18, minZoom: AUTO_ZOOM_MIN }}
        nodesDraggable
        nodesConnectable={false}
        elementsSelectable
        panOnDrag
        zoomOnScroll
        zoomOnPinch
        zoomOnDoubleClick={false}
        proOptions={{ hideAttribution: true }}
      >
        <MiniMap
          pannable
          zoomable
          className="!bottom-5 !left-5 !rounded-2xl !border !border-white/10 !bg-black/75"
          maskColor="rgba(0, 0, 0, 0.34)"
        />
        <Background gap={28} size={1} color="rgba(255,255,255,0.10)" />
      </ReactFlow>
    </div>
  );
}

export function WorkflowCanvas(props: WorkflowCanvasProps) {
  return (
    <ReactFlowProvider>
      <WorkflowCanvasInner {...props} />
    </ReactFlowProvider>
  );
}
