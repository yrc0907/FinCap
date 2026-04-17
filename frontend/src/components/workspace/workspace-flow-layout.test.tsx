import { describe, expect, it } from "vitest";

import type { ProjectWorkspaceFlowState } from "./use-project-workspace-state";
import { toAsrDraftEntries } from "./workspace-flow-layout";
import { defaultVlmPayload } from "./workspace-config";

describe("toAsrDraftEntries", () => {
  it("prefers structured ASR segments over plain ASR text", () => {
    const state = {
      vlmPayload: {
        ...defaultVlmPayload,
        asrText: "fallback",
        asrSegments: [
          {
            startSec: 1.2,
            endSec: 2.8,
            text: "first line",
          },
        ],
      },
      strictShotResult: null,
    } as unknown as ProjectWorkspaceFlowState;

    expect(toAsrDraftEntries(state)).toEqual([
      {
        id: "segment-0",
        startSec: 1.2,
        endSec: 2.8,
        text: "first line",
        format: "asr",
      },
    ]);
  });

  it("falls back to plain ASR text when no segments exist", () => {
    const state = {
      vlmPayload: {
        ...defaultVlmPayload,
        asrText: "fallback text",
        asrSegments: [],
      },
      strictShotResult: {
        videoDurationSec: 12.5,
      },
    } as unknown as ProjectWorkspaceFlowState;

    expect(toAsrDraftEntries(state)).toEqual([
      {
        id: "asr-text",
        startSec: 0,
        endSec: 12.5,
        text: "fallback text",
        format: "asr",
      },
    ]);
  });
});
