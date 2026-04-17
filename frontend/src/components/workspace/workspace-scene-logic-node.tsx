import type { CorrectedEventTimelineResult } from "../../types/workspace";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceSceneLogicNodeProps = {
  result: CorrectedEventTimelineResult | null;
  tone: WorkflowNodeTone;
  message: string;
  onPreview: () => void;
};

export function WorkspaceSceneLogicNode({
  result,
  tone,
  message,
  onPreview,
}: WorkspaceSceneLogicNodeProps) {
  const clips = result?.functionalClips ?? [];
  const buildCount = clips.filter((clip) => clip.type === "build").length;
  const peakCount = clips.filter((clip) => clip.type === "peak").length;
  const transitionCount = clips.filter((clip) => clip.type === "transition").length;
  const resultCount = clips.filter((clip) => clip.type === "result").length;

  return (
    <WorkflowNodeCard
      eyebrow="06"
      title="Scene Logic"
      status={clips.length > 0 ? "Done" : "Idle"}
      description="Clips"
      active={clips.length > 0}
      tone={tone}
      message={message}
      actions={[{ label: "Preview", onClick: onPreview, disabled: clips.length === 0 }]}
    >
      <div className="grid gap-3 md:grid-cols-2">
        <WorkflowNodeMetric label="Build" value={String(buildCount)} />
        <WorkflowNodeMetric label="Peak" value={String(peakCount)} />
        <WorkflowNodeMetric label="Transition" value={String(transitionCount)} />
        <WorkflowNodeMetric label="Result" value={String(resultCount)} />
      </div>
    </WorkflowNodeCard>
  );
}
