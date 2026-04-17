import { afterEach, beforeEach, describe, expect, it } from "vitest";

import {
  loadWorkflowCanvasNodes,
  saveWorkflowCanvasNodes,
} from "./workflow-canvas-storage";

const DEFAULT_NODES = [
  {
    id: "upload",
    type: "workflow" as const,
    position: { x: 120, y: 110 },
    data: { kind: "upload" as const },
  },
  {
    id: "boundary",
    type: "workflow" as const,
    position: { x: 470, y: 110 },
    data: { kind: "boundary" as const },
  },
];

describe("workflow canvas storage", () => {
  beforeEach(() => {
    window.localStorage.clear();
  });

  afterEach(() => {
    window.localStorage.clear();
  });

  it("restores saved node positions for the same project", () => {
    saveWorkflowCanvasNodes("project-1", [
      {
        ...DEFAULT_NODES[0],
        position: { x: 300, y: 220 },
      },
      DEFAULT_NODES[1],
    ]);

    expect(loadWorkflowCanvasNodes("project-1", DEFAULT_NODES)[0]?.position).toEqual({
      x: 300,
      y: 220,
    });
  });

  it("keeps default positions when nothing is saved", () => {
    expect(loadWorkflowCanvasNodes("project-1", DEFAULT_NODES)).toEqual(DEFAULT_NODES);
  });
});
