import type {
  AdjacentStoryReassignmentResult,
  CorrectedEventTimelineResult,
} from "../../types/workspace";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceStoryNodeProps = {
  adjacentResult: AdjacentStoryReassignmentResult | null;
  correctedResult: CorrectedEventTimelineResult | null;
  isRunning: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onRun: () => void;
  onPreview: () => void;
};

export function WorkspaceStoryNode({
  adjacentResult,
  correctedResult,
  isRunning,
  tone,
  message,
  onRun,
  onPreview,
}: WorkspaceStoryNodeProps) {
  return (
    <WorkflowNodeCard
      eyebrow="05"
      title="Story Fix"
      status={correctedResult ? "Done" : isRunning ? "Running" : "Idle"}
      description="Story"
      active={Boolean(correctedResult)}
      tone={tone}
      message={message}
      actions={[
        { label: "Run", onClick: onRun, busy: isRunning, variant: "default" },
        { label: "Preview", onClick: onPreview, disabled: !correctedResult },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-3">
        <WorkflowNodeMetric label="Pairs" value={String(adjacentResult?.summary.pairCount ?? 0)} />
        <WorkflowNodeMetric label="Events" value={String(correctedResult?.summary.eventCount ?? 0)} />
        <WorkflowNodeMetric
          label="Selected"
          value={String(correctedResult?.summary.selectedClipCount ?? 0)}
        />
      </div>
    </WorkflowNodeCard>
  );
}
