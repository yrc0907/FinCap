import { describe, expect, it } from "vitest";

import { buildSourceRangeTimelineModel } from "./workspace-source-range-model";

describe("buildSourceRangeTimelineModel", () => {
  it("builds the original-video dual-handle timeline model", () => {
    expect(buildSourceRangeTimelineModel(4.033, 10.733, 60.633, 6.2)).toEqual({
      maxSec: 60.633,
      startSec: 4.033,
      endSec: 10.733,
      currentTimeSec: 6.2,
      startPercent: 6.651,
      endPercent: 17.702,
      currentPercent: 10.225,
      selectedWidthPercent: 11.05,
    });
  });
});
