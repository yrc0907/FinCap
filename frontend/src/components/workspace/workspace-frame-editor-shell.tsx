import { Button } from "../ui/button";
import { WorkspacePreviewVideo } from "./workspace-preview-video";
import type { PlannedFrameSlot } from "./workspace-frame-slots";

type WorkspaceFrameEditorShellProps = {
  videoSrc: string | undefined;
  slot: PlannedFrameSlot;
  onChangeTime: (timeSec: number) => void;
  onReset: () => void;
};

function clampTime(value: number, min: number, max: number) {
  return Math.min(Math.max(value, min), max);
}

export function WorkspaceFrameEditorShell({
  videoSrc,
  slot,
  onChangeTime,
  onReset,
}: WorkspaceFrameEditorShellProps) {
  const nudge = (delta: number) => {
    onChangeTime(clampTime(slot.timeSec + delta, slot.shotStartSec, slot.shotEndSec));
  };

  const changed = Math.abs(slot.timeSec - slot.sourceTimeSec) > 0.0005;

  return (
    <div className="grid gap-4 xl:grid-cols-[1.1fr_0.9fr]">
      <WorkspacePreviewVideo
        src={videoSrc}
        title={`Group ${slot.groupIndex} / Shot ${slot.shotIndex}`}
        startSec={slot.timeSec}
      />

      <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="flex items-center justify-between gap-3">
          <div>
            <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
              Replace Frame
            </div>
            <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
              Group {slot.groupIndex} / Shot {slot.shotIndex}
            </div>
          </div>
          <div className="rounded-full border border-white/10 bg-white/[0.03] px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/55">
            {changed ? "Edited" : "Original"}
          </div>
        </div>

        <div className="mt-5 grid gap-3 sm:grid-cols-3">
          <div className="rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">Current</div>
            <div className="mt-2 text-sm font-black text-white/85">{slot.timeSec.toFixed(3)}s</div>
          </div>
          <div className="rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">Original</div>
            <div className="mt-2 text-sm font-black text-white/85">{slot.sourceTimeSec.toFixed(3)}s</div>
          </div>
          <div className="rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">Shot</div>
            <div className="mt-2 text-sm font-black text-white/85">
              {slot.shotStartSec.toFixed(3)}s - {slot.shotEndSec.toFixed(3)}s
            </div>
          </div>
        </div>

        <div className="mt-5 rounded-[24px] border border-white/8 bg-black/25 p-4">
          <div className="text-[10px] font-mono uppercase tracking-[0.2em] text-white/25">Frame Time</div>
          <input
            type="range"
            min={slot.shotStartSec}
            max={slot.shotEndSec}
            step={0.033}
            value={slot.timeSec}
            onChange={(event) => onChangeTime(Number(event.target.value))}
            className="mt-3 w-full accent-white"
          />
          <div className="mt-3 flex flex-wrap gap-2">
            {[-0.5, -0.1, 0.1, 0.5].map((delta) => (
              <Button
                key={delta}
                type="button"
                size="sm"
                variant="secondary"
                className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
                onClick={() => nudge(delta)}
              >
                {delta > 0 ? `+${delta}` : delta}s
              </Button>
            ))}
          </div>
        </div>

        <div className="mt-5 flex flex-wrap gap-3">
          <Button
            type="button"
            size="sm"
            variant="secondary"
            className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
            onClick={onReset}
          >
            Reset
          </Button>
        </div>
      </div>
    </div>
  );
}
