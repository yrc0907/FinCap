import type {
  DualSignalBoundaryDetectionResult,
  MultiscaleDetectionResult,
  SceneDetectorMode,
} from "../../types/workspace";
import type { ProcessingMode } from "./workspace-config";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceBoundaryNodeProps = {
  processingMode: ProcessingMode;
  sceneDetectorMode: SceneDetectorMode;
  multiscaleResult: MultiscaleDetectionResult | null;
  boundaryResult: DualSignalBoundaryDetectionResult | null;
  isRunning: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onRun: () => void;
  onPreview: () => void;
  onAdvanced: () => void;
};

export function WorkspaceBoundaryNode({
  processingMode,
  sceneDetectorMode,
  multiscaleResult,
  boundaryResult,
  isRunning,
  tone,
  message,
  onRun,
  onPreview,
  onAdvanced,
}: WorkspaceBoundaryNodeProps) {
  return (
    <WorkflowNodeCard
      eyebrow="02"
      title="Boundary Detection"
      status={boundaryResult ? "Done" : isRunning ? "Running" : "Idle"}
      description="Boundary"
      active={Boolean(boundaryResult)}
      tone={tone}
      message={message}
      actions={[
        { label: "Run", onClick: onRun, busy: isRunning, variant: "default" },
        { label: "Preview", onClick: onPreview, disabled: !boundaryResult },
        { label: "Advanced", onClick: onAdvanced, variant: "ghost" },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-2">
        <WorkflowNodeMetric label="Mode" value={processingMode} />
        <WorkflowNodeMetric label="Route" value={sceneDetectorMode} />
        <WorkflowNodeMetric
          label="Regions"
          value={String(multiscaleResult?.suspiciousRegions.length ?? 0)}
        />
        <WorkflowNodeMetric
          label="Cuts"
          value={String(boundaryResult?.boundaryCandidates.length ?? 0)}
        />
      </div>
    </WorkflowNodeCard>
  );
}
