import { describe, expect, it } from "vitest";

import { buildWorkflowCanvasGraph } from "./workflow-canvas-graph";

describe("buildWorkflowCanvasGraph", () => {
  it("returns one fixed main-chain graph with draggable nodes", () => {
    const graph = buildWorkflowCanvasGraph();

    expect(graph.nodes.map((node) => node.id)).toEqual([
      "upload",
      "boundary",
      "shots",
      "semantic",
      "story",
      "scene-logic",
      "export",
    ]);
    expect(graph.edges.map((edge) => edge.id)).toEqual([
      "upload-boundary",
      "boundary-shots",
      "shots-semantic",
      "semantic-story",
      "story-scene-logic",
      "scene-logic-export",
    ]);
    expect(graph.nodes.every((node) => node.draggable !== false)).toBe(true);
    expect(Math.max(...graph.nodes.map((node) => node.position.x))).toBeLessThanOrEqual(1400);
    expect(new Set(graph.nodes.map((node) => node.position.y)).size).toBeGreaterThan(1);
  });
});
