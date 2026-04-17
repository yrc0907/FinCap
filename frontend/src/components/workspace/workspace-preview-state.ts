import { useState } from "react";

export type WorkspacePreviewKind =
  | "boundary-advanced"
  | "boundary"
  | "shots"
  | "ocr"
  | "asr"
  | "references"
  | "vlm"
  | "story"
  | "scene-logic"
  | "export"
  | null;

export type WorkspacePreviewState = {
  kind: WorkspacePreviewKind;
  selectedIndex: number | null;
};

export function useWorkspacePreviewState() {
  const [state, setState] = useState<WorkspacePreviewState>({
    kind: null,
    selectedIndex: null,
  });

  const openPreview = (kind: Exclude<WorkspacePreviewKind, null>, selectedIndex: number | null = null) => {
    setState({ kind, selectedIndex });
  };

  const closePreview = () => {
    setState({ kind: null, selectedIndex: null });
  };

  return {
    previewState: state,
    openPreview,
    closePreview,
  };
}
