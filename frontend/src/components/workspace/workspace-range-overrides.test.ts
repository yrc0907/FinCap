import { describe, expect, it } from "vitest";

import { applyTimedRangeOverrides } from "./workspace-range-overrides";

describe("applyTimedRangeOverrides", () => {
  it("replaces matching item ranges and recalculates duration", () => {
    const result = applyTimedRangeOverrides(
      [
        { index: 1, startSec: 1, endSec: 3, durationSec: 2 },
        { index: 2, startSec: 4, endSec: 6, durationSec: 2 },
      ],
      [{ key: "shot:2", startSec: 4.5, endSec: 7 }],
      (item) => `shot:${item.index}`,
    );

    expect(result).toEqual([
      { index: 1, startSec: 1, endSec: 3, durationSec: 2 },
      { index: 2, startSec: 4.5, endSec: 7, durationSec: 2.5 },
    ]);
  });
});
