import { describe, expect, it } from "vitest";

import { buildPlannedFrameSlots } from "./workspace-frame-slots";

describe("buildPlannedFrameSlots", () => {
  it("builds editable frame slots with group and shot ranges", () => {
    const slots = buildPlannedFrameSlots(
      [
        {
          index: 1,
          startSec: 2,
          endSec: 6,
          durationSec: 4,
        },
        {
          index: 2,
          startSec: 6,
          endSec: 10,
          durationSec: 4,
        },
      ],
      1,
      2,
    );

    expect(slots).toEqual([
      {
        id: "1-1-0",
        groupIndex: 1,
        shotIndex: 1,
        frameIndex: 0,
        shotStartSec: 2,
        shotEndSec: 6,
        timeSec: 3.333,
        sourceTimeSec: 3.333,
      },
      {
        id: "1-1-1",
        groupIndex: 1,
        shotIndex: 1,
        frameIndex: 1,
        shotStartSec: 2,
        shotEndSec: 6,
        timeSec: 4.667,
        sourceTimeSec: 4.667,
      },
      {
        id: "2-2-0",
        groupIndex: 2,
        shotIndex: 2,
        frameIndex: 0,
        shotStartSec: 6,
        shotEndSec: 10,
        timeSec: 7.333,
        sourceTimeSec: 7.333,
      },
      {
        id: "2-2-1",
        groupIndex: 2,
        shotIndex: 2,
        frameIndex: 1,
        shotStartSec: 6,
        shotEndSec: 10,
        timeSec: 8.667,
        sourceTimeSec: 8.667,
      },
    ]);
  });
});
