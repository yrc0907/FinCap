import { useState } from "react";

import type { CorrectedEventTimelineResult } from "../../types/workspace";
import { WorkspaceClipEditorShell } from "./workspace-clip-editor-shell";

type WorkspaceStoryPreviewProps = {
  videoSrc: string | undefined;
  result: CorrectedEventTimelineResult | null;
};

export function WorkspaceStoryPreview({
  videoSrc,
  result,
}: WorkspaceStoryPreviewProps) {
  const [selectedIndex, setSelectedIndex] = useState(0);
  const selectedEvent = result?.events[selectedIndex] ?? null;
  const maxSec = result?.videoIndex.durationSec ?? 1;

  return (
    <div className="grid h-[min(78vh,760px)] gap-5 xl:grid-cols-[320px_minmax(0,1fr)]">
      <div className="flex min-h-0 flex-col rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
          Story Fix
        </div>
        <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
          {result?.summary.eventCount ?? 0} events
        </div>
        <div className="mt-4 min-h-0 flex-1 space-y-2 overflow-y-auto pr-1">
          {result?.events.length ? (
            result.events.map((event, index) => (
              <button
                key={event.index}
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
                    Event {event.index}
                  </div>
                  <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/35">
                    {event.changed ? "changed" : "same"}
                  </div>
                </div>
                <div className="mt-2 break-words text-[11px] text-white/65">
                  {event.startSec.toFixed(3)}s - {event.endSec.toFixed(3)}s
                </div>
                <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
                  Groups {event.sourceGroupIndexes.join(", ")}
                </div>
              </button>
            ))
          ) : (
            <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35">
              Run story fix first.
            </div>
          )}
        </div>
      </div>

      {selectedEvent ? (
        <WorkspaceClipEditorShell
          videoSrc={videoSrc}
          label={`Event ${selectedEvent.index}`}
          startSec={selectedEvent.startSec}
          endSec={selectedEvent.endSec}
          maxSec={maxSec}
        />
      ) : null}
    </div>
  );
}
