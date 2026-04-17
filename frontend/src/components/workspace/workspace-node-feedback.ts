import type { WorkflowNodeTone } from "./workflow-node-card";

export type WorkflowNodeKey =
  | "upload"
  | "boundary"
  | "shots"
  | "semantic"
  | "story"
  | "sceneLogic"
  | "export";

export type WorkflowNodeFeedback = {
  tone: WorkflowNodeTone;
  message: string;
};

export function buildInitialNodeFeedback(
  hasProject: boolean,
): Record<WorkflowNodeKey, WorkflowNodeFeedback> {
  return {
    upload: {
      tone: hasProject ? "success" : "idle",
      message: hasProject ? "Video ready" : "Upload a source video",
    },
    boundary: { tone: "idle", message: "Run boundary detection" },
    shots: { tone: "idle", message: "Generate clean shot segments" },
    semantic: { tone: "idle", message: "Run OCR / ASR / VLM" },
    story: { tone: "idle", message: "Run story correction" },
    sceneLogic: { tone: "idle", message: "Review functional clips" },
    export: { tone: "idle", message: "Export the final result" },
  };
}
