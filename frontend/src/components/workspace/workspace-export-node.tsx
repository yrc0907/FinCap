import type { CorrectedEventTimelineResult } from "../../types/workspace";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceExportNodeProps = {
  result: CorrectedEventTimelineResult | null;
  isExporting: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onExport: () => void;
};

export function WorkspaceExportNode({
  result,
  isExporting,
  tone,
  message,
  onExport,
}: WorkspaceExportNodeProps) {
  const clips = result?.functionalClips ?? [];

  return (
    <WorkflowNodeCard
      eyebrow="07"
      title="Export"
      status={clips.length > 0 ? "Ready" : "Idle"}
      description="Output"
      active={clips.length > 0}
      tone={tone}
      message={message}
      actions={[
        {
          label: "Export",
          onClick: onExport,
          disabled: clips.length === 0,
          busy: isExporting,
          variant: "default",
        },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-3">
        <WorkflowNodeMetric label="Clips" value={String(clips.length)} />
        <WorkflowNodeMetric
          label="Peak"
          value={String(clips.filter((clip) => clip.type === "peak").length)}
        />
        <WorkflowNodeMetric
          label="Build"
          value={String(clips.filter((clip) => clip.type === "build").length)}
        />
      </div>
    </WorkflowNodeCard>
  );
}
