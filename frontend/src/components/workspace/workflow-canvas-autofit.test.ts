import { describe, expect, it } from "vitest";

import {
  buildViewportFlowBounds,
  shouldAutoZoomOutForDraggedNode,
} from "./workflow-canvas-autofit";

describe("buildViewportFlowBounds", () => {
  it("converts the current viewport into visible flow bounds", () => {
    expect(
      buildViewportFlowBounds(
        {
          x: -200,
          y: -120,
          zoom: 2,
        },
        {
          width: 800,
          height: 600,
        },
      ),
    ).toEqual({
      minX: 100,
      minY: 60,
      maxX: 500,
      maxY: 360,
    });
  });
});

describe("shouldAutoZoomOutForDraggedNode", () => {
  const viewportBounds = {
    minX: 0,
    minY: 0,
    maxX: 600,
    maxY: 400,
  };

  it("returns false when the dragged node is still inside the current viewport", () => {
    expect(
      shouldAutoZoomOutForDraggedNode(
        {
          x: 120,
          y: 80,
          width: 180,
          height: 120,
        },
        viewportBounds,
      ),
    ).toBe(false);
  });

  it("returns true when the dragged node exceeds the current viewport on any side", () => {
    expect(
      shouldAutoZoomOutForDraggedNode(
        {
          x: 520,
          y: 80,
          width: 120,
          height: 120,
        },
        viewportBounds,
      ),
    ).toBe(true);
  });
});
