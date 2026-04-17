import { describe, expect, it } from "vitest";

import {
  WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME,
  WORKSPACE_CLIP_EDITOR_LEFT_COLUMN_CLASS_NAME,
} from "./workspace-clip-editor-shell";
import { WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME } from "./workspace-clip-preview-player";

describe("workspace clip editor layout", () => {
  it("keeps the editor constrained to the preview viewport height", () => {
    expect(WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME).toContain("h-full");
    expect(WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME).toContain("min-h-0");
    expect(WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME).not.toContain("grid-rows-[minmax(0,1fr)_auto]");
  });

  it("removes the source-range micro-adjust layout", () => {
    expect(WORKSPACE_CLIP_EDITOR_LEFT_COLUMN_CLASS_NAME).toContain("min-h-0");
    expect(WORKSPACE_CLIP_EDITOR_LEFT_COLUMN_CLASS_NAME).not.toContain("grid");
  });

  it("does not force the preview player to occupy the whole column height by itself", () => {
    expect(WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME).toContain("min-h-0");
    expect(WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME).not.toContain("h-full");
    expect(WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME).not.toContain("min-h-[540px]");
  });
});
