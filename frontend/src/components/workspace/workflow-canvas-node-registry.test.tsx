import { render, screen } from "@testing-library/react";
import { describe, expect, it, vi } from "vitest";

import type { ProjectWorkspaceFlowState } from "./use-project-workspace-state";
import { WorkflowCanvasNodeRenderer } from "./workflow-canvas-node-registry";

describe("WorkflowCanvasNodeRenderer", () => {
  it("renders the visible workflow node label for boundary detection", async () => {
    const state = {
      processingMode: "standard",
      sceneDetectorMode: "transnetv2-cuda",
      multiscaleResult: null,
      boundaryResult: null,
      isRunningBoundary: false,
      nodeFeedback: {
        boundary: { tone: "idle", message: "Run boundary detection" },
      },
      handleRunBoundaryFlow: vi.fn(),
    } as unknown as ProjectWorkspaceFlowState;

    render(
      <WorkflowCanvasNodeRenderer
        kind="boundary"
        state={state}
        openPreview={vi.fn()}
      />,
    );

    expect(await screen.findByText("Boundary Detection")).toBeInTheDocument();
  });
});
