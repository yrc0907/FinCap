import { useMemo, useState } from "react";

import type { DualSignalBoundaryDetectionResult } from "../../types/workspace";
import { buildBoundaryPreviewItems } from "./workspace-boundary-preview-model";
import { WorkspaceClipEditorShell } from "./workspace-clip-editor-shell";

type WorkspaceBoundaryPreviewProps = {
  videoSrc: string | undefined;
  result: DualSignalBoundaryDetectionResult | null;
};

export function WorkspaceBoundaryPreview({
  videoSrc,
  result,
}: WorkspaceBoundaryPreviewProps) {
  const maxSec = result?.videoIndex.durationSec ?? 1;
  const boundaryWindows = useMemo(() => {
    if (!result) {
      return [];
    }
    return buildBoundaryPreviewItems(result.boundaryCandidates, maxSec);
  }, [maxSec, result]);

  const [selectedIndex, setSelectedIndex] = useState(0);
  const selectedBoundary = boundaryWindows[selectedIndex] ?? null;

  return (
    <div className="grid h-[min(78vh,760px)] gap-5 xl:grid-cols-[320px_minmax(0,1fr)]">
      <div className="min-h-0 space-y-3">
        <div className="flex h-full min-h-0 flex-col rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
          <div className="rounded-[22px] border border-white/8 bg-black/25 px-4 py-4">
            <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/72">
              Boundary Preview
            </div>
            <div className="mt-2 text-[11px] font-black text-white/90">
              {boundaryWindows.length} cuts
            </div>
            <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/28">
              Select one item to re-cut on the source video
            </div>
          </div>
          <div className="mt-4 min-h-0 flex-1 space-y-2 overflow-y-auto pr-1">
            {boundaryWindows.length > 0 ? (
              boundaryWindows.map((boundary, index) => (
                <button
                  key={`${boundary.timeSec}-${boundary.index}`}
                  type="button"
                  onClick={() => setSelectedIndex(index)}
                  className={[
                    "group w-full rounded-[24px] border px-4 py-4 text-left transition-all",
                    index === selectedIndex
                      ? "border-emerald-300/30 bg-emerald-300/10 shadow-[0_0_24px_rgba(110,231,183,0.14)]"
                      : "border-white/8 bg-black/20 hover:border-white/15 hover:bg-white/[0.04]",
                  ].join(" ")}
                >
                  <div className="flex items-start gap-3">
                    <div
                      className={[
                        "flex h-10 w-10 shrink-0 items-center justify-center rounded-2xl border text-sm font-black transition-colors",
                        index === selectedIndex
                          ? "border-emerald-200/35 bg-emerald-200/18 text-white"
                          : "border-white/10 bg-white/[0.04] text-white/78",
                      ].join(" ")}
                    >
                      {boundary.index}
                    </div>
                    <div className="min-w-0 flex-1">
                      <div className="flex items-center justify-between gap-3">
                        <div className="truncate text-sm font-black tracking-[0.04em] text-white/90">
                          {boundary.startSec.toFixed(3)}s - {boundary.endSec.toFixed(3)}s
                        </div>
                        <div className="shrink-0 rounded-full border border-white/10 bg-white/[0.04] px-2.5 py-1 text-[10px] font-mono uppercase tracking-[0.16em] text-white/40">
                          {boundary.confidence}
                        </div>
                      </div>
                      <div className="mt-2 flex flex-wrap gap-2">
                        <div className="rounded-full border border-white/10 bg-black/30 px-2.5 py-1 text-[10px] font-black uppercase tracking-[0.14em] text-white/58">
                          {boundary.durationSec.toFixed(3)}s
                        </div>
                        <div className="rounded-full border border-white/10 bg-black/30 px-2.5 py-1 text-[10px] font-black uppercase tracking-[0.14em] text-white/58">
                          Score {boundary.score.toFixed(3)}
                        </div>
                      </div>
                      <div className="mt-3 rounded-2xl border border-white/8 bg-black/35 px-3 py-3">
                        <div className="relative h-6 overflow-hidden rounded-full bg-white/[0.05]">
                          <div
                            className="absolute inset-y-1 rounded-full bg-white/[0.12]"
                            style={{
                              left: `${boundary.laneLeftPercent}%`,
                              width: `${Math.max(boundary.laneWidthPercent, 1.4)}%`,
                            }}
                          />
                          <div
                            className="absolute inset-y-0 w-[2px] bg-emerald-300"
                            style={{
                              left: `${(boundary.timeSec / Math.max(maxSec, 0.001)) * 100}%`,
                            }}
                          />
                        </div>
                        <div className="mt-2 flex items-center justify-between gap-3 text-[10px] font-mono uppercase tracking-[0.16em] text-white/32">
                          <span>Cut {boundary.timeSec.toFixed(3)}s</span>
                          <span>{maxSec.toFixed(3)}s</span>
                        </div>
                      </div>
                    </div>
                  </div>
                </button>
              ))
            ) : (
              <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35">
                Run boundary detection first.
              </div>
            )}
          </div>
        </div>
      </div>

      {selectedBoundary ? (
        <WorkspaceClipEditorShell
          videoSrc={videoSrc}
          label={`Boundary ${selectedBoundary.index}`}
          startSec={selectedBoundary.startSec}
          endSec={selectedBoundary.endSec}
          maxSec={maxSec}
        />
      ) : null}
    </div>
  );
}
