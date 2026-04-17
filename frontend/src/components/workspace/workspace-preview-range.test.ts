import { describe, expect, it } from "vitest";

import { buildPreviewRangeKey } from "./workspace-preview-range";

describe("workspace preview range", () => {
  it("builds a stable key from video source and time range", () => {
    expect(buildPreviewRangeKey("demo.mp4", 4.0331, 10.7332)).toBe(
      "demo.mp4:4.033:10.733",
    );
  });

  it("changes when the selected clip range changes", () => {
    expect(buildPreviewRangeKey("demo.mp4", 4.033, 10.733)).not.toBe(
      buildPreviewRangeKey("demo.mp4", 10.733, 13.167),
    );
  });
});
