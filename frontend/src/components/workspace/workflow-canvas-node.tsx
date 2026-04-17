import { memo, type ReactNode } from "react";
import { Handle, Position, type NodeProps } from "@xyflow/react";

import type { WorkflowCanvasGraphNode } from "./workflow-canvas-graph";

type WorkflowCanvasNodeFrameProps = {
  children?: ReactNode;
};

export function WorkflowCanvasNodeFrame({
  children,
}: WorkflowCanvasNodeFrameProps) {
  return (
    <div className="group relative min-w-[360px] max-w-[430px] px-2 py-2">
      <Handle
        type="target"
        position={Position.Left}
        className="!h-3 !w-3 !border-0 !bg-white/50 !opacity-0 transition-opacity group-hover:!opacity-100"
      />
      <div className="rounded-[34px] border border-white/7 bg-black/35 p-1 shadow-[0_0_50px_rgba(0,0,0,0.35)]">
        {children}
      </div>
      <Handle
        type="source"
        position={Position.Right}
        className="!h-3 !w-3 !border-0 !bg-white/50 !opacity-0 transition-opacity group-hover:!opacity-100"
      />
    </div>
  );
}

export const WorkflowCanvasNode = memo(function WorkflowCanvasNode({
  data,
}: NodeProps<WorkflowCanvasGraphNode>) {
  return (
    <WorkflowCanvasNodeFrame>
      <div className="rounded-[28px] border border-white/12 bg-[#080808]/95 p-4 shadow-[0_0_30px_rgba(255,255,255,0.06)]">
        <div className="text-[10px] font-mono uppercase tracking-[0.2em] text-white/25">Workflow</div>
        <div className="mt-3 text-sm font-black uppercase tracking-[0.08em] text-white/90">
          {data.kind}
        </div>
      </div>
    </WorkflowCanvasNodeFrame>
  );
});
