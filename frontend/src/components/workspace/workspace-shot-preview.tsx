import { useState } from "react";

import type { StrictShotGenerationResult } from "../../types/workspace";
import { WorkspaceClipEditorShell } from "./workspace-clip-editor-shell";

type WorkspaceShotPreviewProps = {
  videoSrc: string | undefined;
  result: StrictShotGenerationResult | null;
  onSaveRange?: (shotIndex: number, startSec: number, endSec: number) => void;
};

export function WorkspaceShotPreview({
  videoSrc,
  result,
  onSaveRange,
}: WorkspaceShotPreviewProps) {
  const [selectedIndex, setSelectedIndex] = useState(0);
  const selectedShot = result?.shots[selectedIndex] ?? null;
  const maxSec = result?.videoIndex.durationSec ?? 1;

  return (
    <div className="grid h-[min(78vh,760px)] gap-5 xl:grid-cols-[320px_minmax(0,1fr)]">
      <div className="flex min-h-0 flex-col rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
          Shot Segments
        </div>
        <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
          {result?.summary.shotCount ?? 0} generated
        </div>
        <div className="mt-4 min-h-0 flex-1 space-y-2 overflow-y-auto pr-1">
          {result?.shots.length ? (
            result.shots.map((shot, index) => (
              <button
                key={`${shot.index}-${shot.startSec}`}
                type="button"
                onClick={() => setSelectedIndex(index)}
                className={[
                  "w-full rounded-2xl border px-4 py-3 text-left transition-colors",
                  index === selectedIndex
                    ? "border-white/25 bg-white/[0.06]"
                    : "border-white/8 bg-black/20 hover:bg-white/[0.04]",
                ].join(" ")}
              >
                <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                  Shot {shot.index}
                </div>
                <div className="mt-2 break-words text-[11px] text-white/65">
                  {shot.startSec.toFixed(3)}s - {shot.endSec.toFixed(3)}s
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
                  Duration {shot.durationSec.toFixed(3)}s
                </div>
              </button>
            ))
          ) : (
            <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35">
              Run shot generation first.
            </div>
          )}
        </div>
      </div>

      {selectedShot ? (
        <WorkspaceClipEditorShell
          videoSrc={videoSrc}
          label={`Shot ${selectedShot.index}`}
          startSec={selectedShot.startSec}
          endSec={selectedShot.endSec}
          maxSec={maxSec}
          onSave={
            onSaveRange
              ? (startSec, endSec) => onSaveRange(selectedShot.index, startSec, endSec)
              : undefined
          }
        />
      ) : null}
    </div>
  );
}
