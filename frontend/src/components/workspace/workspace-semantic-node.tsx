import type { VlmShotAnalysisResult } from "../../types/workspace";
import type { VlmControlsPayload } from "./workspace-config";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceSemanticNodeProps = {
  result: VlmShotAnalysisResult | null;
  vlmPayload: VlmControlsPayload;
  activeModel: string | null;
  isRunning: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onOpenOcr: () => void;
  onOpenAsr: () => void;
  onOpenReferences: () => void;
  onOpenVlmGrid: () => void;
  onRun: () => void;
};

export function WorkspaceSemanticNode({
  result,
  vlmPayload,
  activeModel,
  isRunning,
  tone,
  message,
  onOpenOcr,
  onOpenAsr,
  onOpenReferences,
  onOpenVlmGrid,
  onRun,
}: WorkspaceSemanticNodeProps) {
  return (
    <WorkflowNodeCard
      eyebrow="04"
      title="OCR / ASR / Ref / VLM"
      status={result ? "Done" : isRunning ? "Running" : "Idle"}
      description="Semantic"
      active={Boolean(result)}
      tone={tone}
      message={message}
      actions={[
        { label: "OCR", onClick: onOpenOcr },
        { label: "ASR", onClick: onOpenAsr },
        { label: "Ref", onClick: onOpenReferences },
        { label: "Grid", onClick: onOpenVlmGrid },
        { label: "Run", onClick: onRun, busy: isRunning, variant: "default" },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-2">
        <WorkflowNodeMetric label="Model" value={activeModel ?? "--"} />
        <WorkflowNodeMetric label="OCR" value={vlmPayload.enableOcr ? "On" : "Off"} />
        <WorkflowNodeMetric
          label="ASR"
          value={
            vlmPayload.enableAutoAsr
              ? "Auto"
              : vlmPayload.asrSegments.length > 0
                ? "Manual"
                : "Off"
          }
        />
        <WorkflowNodeMetric label="Groups" value={String(result?.summary.groupCount ?? 0)} />
      </div>
    </WorkflowNodeCard>
  );
}
