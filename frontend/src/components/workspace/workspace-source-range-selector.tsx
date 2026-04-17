import { ScissorsLineDashed } from "lucide-react";

import { Button } from "../ui/button";
import { buildSourceRangeTimelineModel } from "./workspace-source-range-model";

type WorkspaceSourceRangeSelectorProps = {
  startSec: number;
  endSec: number;
  maxSec: number;
  currentTimeSec: number;
  onStartChange: (value: number) => void;
  onEndChange: (value: number) => void;
  onSeek: (value: number) => void;
  onSave?: () => void;
  onReset?: () => void;
};

const BASE_SLIDER_CLASS_NAME =
  "pointer-events-none absolute inset-x-0 top-1/2 z-20 h-7 w-full -translate-y-1/2 appearance-none bg-transparent [&::-webkit-slider-runnable-track]:h-0 [&::-webkit-slider-thumb]:pointer-events-auto [&::-webkit-slider-thumb]:appearance-none [&::-webkit-slider-thumb]:rounded-full [&::-moz-range-track]:h-0 [&::-moz-range-track]:bg-transparent [&::-moz-range-thumb]:pointer-events-auto [&::-moz-range-thumb]:appearance-none [&::-moz-range-thumb]:rounded-full";

export function WorkspaceSourceRangeSelector({
  startSec,
  endSec,
  maxSec,
  currentTimeSec,
  onStartChange,
  onEndChange,
  onSeek,
  onSave,
  onReset,
}: WorkspaceSourceRangeSelectorProps) {
  const timeline = buildSourceRangeTimelineModel(startSec, endSec, maxSec, currentTimeSec);

  return (
    <div className="rounded-[30px] border border-white/8 bg-black/45 px-5 py-5">
      <div className="flex flex-wrap items-start justify-between gap-3">
        <div>
          <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/72">
            Source Range
          </div>
          <div className="mt-2 text-sm font-black text-white/92">Original Video</div>
        </div>
        <div className="rounded-full border border-white/10 bg-white/[0.04] px-3 py-1 text-[10px] font-black uppercase tracking-[0.18em] text-white/60">
          {timeline.maxSec.toFixed(3)}s
        </div>
      </div>

      <div className="mt-5 rounded-[26px] border border-white/8 bg-[#090909] px-4 py-4">
        <div className="relative overflow-hidden rounded-[22px] border border-white/8 bg-black px-4 py-4">
          <div className="pointer-events-none absolute inset-0 bg-[linear-gradient(90deg,rgba(255,255,255,0.07)_0%,rgba(255,255,255,0.03)_20%,rgba(255,255,255,0.08)_40%,rgba(255,255,255,0.03)_60%,rgba(255,255,255,0.08)_80%,rgba(255,255,255,0.04)_100%)] opacity-90" />
          <div className="pointer-events-none absolute inset-y-4 left-4 right-4">
            <div className="absolute inset-0 rounded-[14px] border border-white/8 bg-white/[0.03]" />
            <div
              className="absolute inset-y-0 rounded-[14px] border border-emerald-300/40 bg-emerald-300/16 shadow-[0_0_18px_rgba(110,231,183,0.18)]"
              style={{
                left: `${timeline.startPercent}%`,
                width: `${Math.max(timeline.selectedWidthPercent, 0.6)}%`,
              }}
            />
            <div
              className="absolute inset-y-[-4px] z-10 w-[2px] bg-rose-300/90 shadow-[0_0_10px_rgba(253,164,175,0.55)]"
              style={{
                left: `${timeline.currentPercent}%`,
              }}
            />
          </div>

          <div className="relative z-20 h-20">
            <button
              type="button"
              className="absolute inset-0"
              onClick={(event) => {
                const rect = event.currentTarget.getBoundingClientRect();
                const ratio = rect.width <= 0 ? 0 : (event.clientX - rect.left) / rect.width;
                onSeek(ratio * timeline.maxSec);
              }}
            />

            <input
              aria-label="Source range start"
              type="range"
              min={0}
              max={timeline.maxSec}
              step={0.001}
              value={timeline.startSec}
              onChange={(event) => onStartChange(Number(event.target.value))}
              className={[
                BASE_SLIDER_CLASS_NAME,
                "[&::-webkit-slider-thumb]:mt-0 [&::-webkit-slider-thumb]:h-5 [&::-webkit-slider-thumb]:w-5 [&::-webkit-slider-thumb]:border-2 [&::-webkit-slider-thumb]:border-black [&::-webkit-slider-thumb]:bg-white [&::-webkit-slider-thumb]:shadow-[0_0_16px_rgba(255,255,255,0.35)] [&::-moz-range-thumb]:h-5 [&::-moz-range-thumb]:w-5 [&::-moz-range-thumb]:border-2 [&::-moz-range-thumb]:border-black [&::-moz-range-thumb]:bg-white",
              ].join(" ")}
            />
            <input
              aria-label="Source range end"
              type="range"
              min={0}
              max={timeline.maxSec}
              step={0.001}
              value={timeline.endSec}
              onChange={(event) => onEndChange(Number(event.target.value))}
              className={[
                BASE_SLIDER_CLASS_NAME,
                "[&::-webkit-slider-thumb]:mt-0 [&::-webkit-slider-thumb]:h-5 [&::-webkit-slider-thumb]:w-5 [&::-webkit-slider-thumb]:border-2 [&::-webkit-slider-thumb]:border-black [&::-webkit-slider-thumb]:bg-emerald-300 [&::-webkit-slider-thumb]:shadow-[0_0_16px_rgba(110,231,183,0.45)] [&::-moz-range-thumb]:h-5 [&::-moz-range-thumb]:w-5 [&::-moz-range-thumb]:border-2 [&::-moz-range-thumb]:border-black [&::-moz-range-thumb]:bg-[#6ee7b7]",
              ].join(" ")}
            />
          </div>

          <div className="relative z-20 mt-2 flex items-center justify-between gap-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/42">
            <span>0.000s</span>
            <span>{timeline.maxSec.toFixed(3)}s</span>
          </div>
        </div>

        <div className="mt-4 grid gap-3 md:grid-cols-3">
          <div className="rounded-2xl border border-white/8 bg-white/[0.03] px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">Start</div>
            <div className="mt-2 text-sm font-black text-white/88">{timeline.startSec.toFixed(3)}s</div>
          </div>
          <div className="rounded-2xl border border-white/8 bg-white/[0.03] px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">Playhead</div>
            <div className="mt-2 text-sm font-black text-white/88">{timeline.currentTimeSec.toFixed(3)}s</div>
          </div>
          <div className="rounded-2xl border border-white/8 bg-white/[0.03] px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">End</div>
            <div className="mt-2 text-sm font-black text-white/88">{timeline.endSec.toFixed(3)}s</div>
          </div>
        </div>

        <div className="mt-4 grid gap-3 md:grid-cols-2">
          <label className="rounded-2xl border border-white/8 bg-white/[0.03] px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">Start</div>
            <input
              aria-label="Start input"
              type="number"
              min={0}
              max={timeline.endSec}
              step={0.001}
              value={Number(timeline.startSec.toFixed(3))}
              onChange={(event) => onStartChange(Number(event.target.value))}
              className="mt-3 h-11 w-full rounded-2xl border border-white/10 bg-black/35 px-4 text-sm font-black text-white outline-none transition focus:border-white/30"
            />
          </label>
          <label className="rounded-2xl border border-white/8 bg-white/[0.03] px-4 py-3">
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">End</div>
            <input
              aria-label="End input"
              type="number"
              min={timeline.startSec}
              max={timeline.maxSec}
              step={0.001}
              value={Number(timeline.endSec.toFixed(3))}
              onChange={(event) => onEndChange(Number(event.target.value))}
              className="mt-3 h-11 w-full rounded-2xl border border-white/10 bg-black/35 px-4 text-sm font-black text-white outline-none transition focus:border-white/30"
            />
          </label>
        </div>

        <div className="mt-4 flex flex-wrap gap-2">
          <Button
            type="button"
            size="sm"
            variant="secondary"
            className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
            onClick={() => onStartChange(timeline.currentTimeSec)}
          >
            <ScissorsLineDashed />
            Set Start
          </Button>
          <Button
            type="button"
            size="sm"
            variant="secondary"
            className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
            onClick={() => onEndChange(timeline.currentTimeSec)}
          >
            <ScissorsLineDashed />
            Set End
          </Button>
          {onReset ? (
            <Button
              type="button"
              size="sm"
              variant="secondary"
              className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
              onClick={onReset}
            >
              Reset
            </Button>
          ) : null}
          {onSave ? (
            <Button type="button" size="sm" className="rounded-2xl" onClick={onSave}>
              Save
            </Button>
          ) : null}
        </div>
      </div>
    </div>
  );
}
