import { describe, expect, it } from "vitest";

import { buildBoundaryPreviewItems } from "./workspace-boundary-preview-model";

describe("buildBoundaryPreviewItems", () => {
  it("builds boundary cards with duration and normalized lane positions", () => {
    const items = buildBoundaryPreviewItems(
      [
        {
          timeSec: 4.033,
          windowStartSec: 3.033,
          windowEndSec: 5.033,
          score: 0.91,
          confidence: "high",
        },
      ],
      60.633,
    );

    expect(items).toEqual([
      {
        index: 1,
        timeSec: 4.033,
        startSec: 3.033,
        endSec: 5.033,
        durationSec: 2,
        score: 0.91,
        confidence: "high",
        laneLeftPercent: 5.002,
        laneWidthPercent: 3.299,
      },
    ]);
  });
});
