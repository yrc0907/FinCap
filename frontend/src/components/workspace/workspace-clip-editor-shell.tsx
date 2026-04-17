import { WorkspacePreviewVideo } from "./workspace-preview-video";
import { buildPreviewRangeKey } from "./workspace-preview-range";

type WorkspaceClipEditorShellProps = {
  videoSrc: string | undefined;
  label: string;
  startSec: number;
  endSec: number;
  maxSec: number;
  onSave?: (startSec: number, endSec: number) => void;
};

export const WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME = "h-full min-h-0";
export const WORKSPACE_CLIP_EDITOR_LEFT_COLUMN_CLASS_NAME =
  WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME;

export function WorkspaceClipEditorShell({
  videoSrc,
  label,
  startSec,
  endSec,
}: WorkspaceClipEditorShellProps) {
  const previewKey = buildPreviewRangeKey(videoSrc, startSec, endSec);

  return (
    <div className={WORKSPACE_CLIP_EDITOR_LAYOUT_CLASS_NAME}>
      <WorkspacePreviewVideo
        key={previewKey}
        src={videoSrc}
        title={label}
        startSec={startSec}
        endSec={endSec}
      />
    </div>
  );
}
