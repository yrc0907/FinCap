import { useMemo, useState } from "react";

import type { CorrectedEventTimelineResult } from "../../types/workspace";
import { WorkspaceClipEditorShell } from "./workspace-clip-editor-shell";

type WorkspaceSceneLogicPreviewProps = {
  videoSrc: string | undefined;
  result: CorrectedEventTimelineResult | null;
  onSaveRange?: (
    clipIndex: number,
    clipType: "build" | "peak" | "result" | "transition",
    startSec: number,
    endSec: number,
  ) => void;
};

const typeLabels = {
  build: "推进",
  peak: "高爆",
  transition: "过渡",
  result: "结果",
} as const;

export function WorkspaceSceneLogicPreview({
  videoSrc,
  result,
  onSaveRange,
}: WorkspaceSceneLogicPreviewProps) {
  const clips = result?.functionalClips ?? [];
  const [selectedIndex, setSelectedIndex] = useState(0);
  const selectedClip = clips[selectedIndex] ?? null;
  const maxSec = result?.videoIndex.durationSec ?? 1;
  const summary = useMemo(
    () =>
      Object.entries(typeLabels).map(([key, label]) => ({
        key,
        label,
        count: clips.filter((clip) => clip.type === key).length,
      })),
    [clips],
  );

  return (
    <div className="space-y-5">
      <div className="grid gap-3 md:grid-cols-4">
        {summary.map((item) => (
          <div key={item.key} className="rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
              {item.label}
            </div>
            <div className="mt-2 text-sm font-black text-white/85">{item.count}</div>
          </div>
        ))}
      </div>

      <div className="grid h-[min(78vh,760px)] gap-5 xl:grid-cols-[320px_minmax(0,1fr)]">
        <div className="flex min-h-0 flex-col rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
          <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
            Functional Clips
          </div>
          <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
            {clips.length} clips
          </div>
          <div className="mt-4 min-h-0 flex-1 space-y-2 overflow-y-auto pr-1">
            {clips.length > 0 ? (
              clips.map((clip, index) => (
                <button
                  key={`${clip.index}-${clip.type}-${clip.startSec}`}
                  type="button"
                  onClick={() => setSelectedIndex(index)}
                  className={[
                    "w-full rounded-2xl border px-4 py-3 text-left transition-colors",
                    index === selectedIndex
                      ? "border-white/25 bg-white/[0.06]"
                      : "border-white/8 bg-black/20 hover:bg-white/[0.04]",
                  ].join(" ")}
                >
                  <div className="flex items-center justify-between gap-3">
                    <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                      {typeLabels[clip.type]}
                    </div>
                    <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/35">
                      {clip.score.toFixed(3)}
                    </div>
                  </div>
                  <div className="mt-2 break-words text-[11px] text-white/65">
                    {clip.startSec.toFixed(3)}s - {clip.endSec.toFixed(3)}s
                  </div>
                  <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
                    Event {clip.eventIndex}
                  </div>
                </button>
              ))
            ) : (
              <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35">
                Scene logic is empty.
              </div>
            )}
          </div>
        </div>

        {selectedClip ? (
          <WorkspaceClipEditorShell
            videoSrc={videoSrc}
            label={typeLabels[selectedClip.type]}
            startSec={selectedClip.exportStartSec ?? selectedClip.startSec}
            endSec={selectedClip.exportEndSec ?? selectedClip.endSec}
            maxSec={maxSec}
            onSave={
              onSaveRange
                ? (startSec, endSec) =>
                    onSaveRange(selectedClip.index, selectedClip.type, startSec, endSec)
                : undefined
            }
          />
        ) : null}
      </div>
    </div>
  );
}
