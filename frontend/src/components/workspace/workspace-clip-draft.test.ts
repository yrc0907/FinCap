import { describe, expect, it } from "vitest";

import { clampClipDraft, updateClipDraftField } from "./workspace-clip-draft";

describe("workspace clip draft helpers", () => {
  it("keeps the clip range inside the allowed duration", () => {
    expect(clampClipDraft(4.033, 10.733, 60.633)).toEqual({
      draftStartSec: 4.033,
      draftEndSec: 10.733,
      clampedMaxSec: 60.633,
    });
  });

  it("supports manual start and end edits", () => {
    const nextStart = updateClipDraftField("start", 5.25, 4.033, 10.733, 60.633);
    const nextEnd = updateClipDraftField("end", 11.5, nextStart.draftStartSec, nextStart.draftEndSec, 60.633);

    expect(nextStart).toEqual({
      draftStartSec: 5.25,
      draftEndSec: 10.733,
      previewTimeSec: 5.25,
    });
    expect(nextEnd).toEqual({
      draftStartSec: 5.25,
      draftEndSec: 11.5,
      previewTimeSec: 11.5,
    });
  });
});
