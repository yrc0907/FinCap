import { describe, expect, it } from "vitest";

import { WORKFLOW_CANVAS_SURFACE_CLASS_NAME } from "./workflow-canvas";

describe("WORKFLOW_CANVAS_SURFACE_CLASS_NAME", () => {
  it("keeps the workflow canvas on a full-height surface", () => {
    expect(WORKFLOW_CANVAS_SURFACE_CLASS_NAME).toContain("h-full");
    expect(WORKFLOW_CANVAS_SURFACE_CLASS_NAME).toContain("min-h-0");
    expect(WORKFLOW_CANVAS_SURFACE_CLASS_NAME).not.toContain("min-h-[620px]");
  });
});
