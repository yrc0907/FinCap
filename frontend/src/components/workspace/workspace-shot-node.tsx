import type { StrictShotGenerationResult } from "../../types/workspace";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceShotNodeProps = {
  result: StrictShotGenerationResult | null;
  isRunning: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onRun: () => void;
  onPreview: () => void;
};

export function WorkspaceShotNode({
  result,
  isRunning,
  tone,
  message,
  onRun,
  onPreview,
}: WorkspaceShotNodeProps) {
  return (
    <WorkflowNodeCard
      eyebrow="03"
      title="Strict Shots"
      status={result ? "Done" : isRunning ? "Running" : "Idle"}
      description="Strict"
      active={Boolean(result)}
      tone={tone}
      message={message}
      actions={[
        { label: "Run", onClick: onRun, busy: isRunning, variant: "default" },
        { label: "Preview", onClick: onPreview, disabled: !result },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-3">
        <WorkflowNodeMetric label="Shots" value={String(result?.summary.shotCount ?? 0)} />
        <WorkflowNodeMetric
          label="Shortest"
          value={result ? `${result.summary.shortestShotSec.toFixed(3)}s` : "--"}
        />
        <WorkflowNodeMetric
          label="Longest"
          value={result ? `${result.summary.longestShotSec.toFixed(3)}s` : "--"}
        />
      </div>
    </WorkflowNodeCard>
  );
}
