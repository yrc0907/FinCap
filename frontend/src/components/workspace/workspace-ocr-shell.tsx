import type { SubtitleRegion } from "../../types/workspace";
import { Button } from "../ui/button";
import { WorkspacePreviewVideo } from "./workspace-preview-video";

export type OcrDraftEntry = {
  id: string;
  startSec: number;
  endSec: number;
  text: string;
};

type WorkspaceOcrShellProps = {
  videoSrc: string | undefined;
  enabled: boolean;
  subtitleRegion: SubtitleRegion;
  entries: OcrDraftEntry[];
  onToggleEnabled: (next: boolean) => void;
  onUpdateSubtitleRegion: (key: keyof SubtitleRegion, value: number) => void;
  onChangeEntries: (entries: OcrDraftEntry[]) => void;
};

export function WorkspaceOcrShell({
  videoSrc,
  enabled,
  subtitleRegion,
  entries,
  onToggleEnabled,
  onUpdateSubtitleRegion,
  onChangeEntries,
}: WorkspaceOcrShellProps) {
  const updateEntry = (id: string, key: keyof OcrDraftEntry, value: string) => {
    onChangeEntries(
      entries.map((entry) =>
        entry.id === id
          ? {
              ...entry,
              [key]:
                key === "text" ? value : Number.isFinite(Number(value)) ? Number(value) : entry[key],
            }
          : entry,
      ),
    );
  };

  return (
    <div className="space-y-5">
      <div className="grid gap-5 xl:grid-cols-[1.1fr_0.9fr]">
        <div className="space-y-4">
          <WorkspacePreviewVideo src={videoSrc} title="OCR Region" />
          <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
            <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
              Subtitle Region
            </div>
            <div className="mt-4 grid gap-3 md:grid-cols-2">
              {(["x", "y", "width", "height"] as Array<keyof SubtitleRegion>).map((key) => (
                <label key={key} className="space-y-2">
                  <span className="text-[10px] font-mono uppercase tracking-[0.2em] text-white/25">
                    {key}
                  </span>
                  <input
                    type="number"
                    min={0}
                    max={1}
                    step={0.01}
                    value={subtitleRegion[key]}
                    onChange={(event) => onUpdateSubtitleRegion(key, Number(event.target.value))}
                    className="w-full rounded-2xl border border-white/10 bg-black/20 px-4 py-3 text-sm text-white"
                  />
                </label>
              ))}
            </div>
            <div className="mt-4 flex gap-3">
              <Button
                type="button"
                size="sm"
                variant="secondary"
                className="rounded-2xl border border-white/10 bg-white/[0.03] text-white"
                onClick={() => onToggleEnabled(!enabled)}
              >
                {enabled ? "OCR On" : "OCR Off"}
              </Button>
            </div>
          </div>
        </div>

        <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
          <div className="flex items-center justify-between gap-3">
            <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
              OCR Preview
            </div>
            <Button
              type="button"
              size="sm"
              variant="secondary"
              className="rounded-2xl border border-white/10 bg-white/[0.03] text-white"
              onClick={() =>
                onChangeEntries([
                  ...entries,
                  {
                    id: crypto.randomUUID(),
                    startSec: 0,
                    endSec: 0,
                    text: "",
                  },
                ])
              }
            >
              Add
            </Button>
          </div>
          <div className="mt-4 max-h-[480px] space-y-3 overflow-y-auto pr-1">
            {entries.length > 0 ? (
              entries.map((entry, index) => (
                <div key={entry.id} className="rounded-2xl border border-white/8 bg-black/20 p-4">
                  <div className="text-[10px] font-black uppercase tracking-[0.2em] text-white/60">
                    Line {index + 1}
                  </div>
                  <div className="mt-3 grid gap-3 md:grid-cols-2">
                    <input
                      type="number"
                      step={0.1}
                      value={entry.startSec}
                      onChange={(event) => updateEntry(entry.id, "startSec", event.target.value)}
                      className="rounded-2xl border border-white/10 bg-black/20 px-4 py-3 text-sm text-white"
                    />
                    <input
                      type="number"
                      step={0.1}
                      value={entry.endSec}
                      onChange={(event) => updateEntry(entry.id, "endSec", event.target.value)}
                      className="rounded-2xl border border-white/10 bg-black/20 px-4 py-3 text-sm text-white"
                    />
                    <textarea
                      value={entry.text}
                      onChange={(event) => updateEntry(entry.id, "text", event.target.value)}
                      rows={3}
                      className="rounded-2xl border border-white/10 bg-black/20 px-4 py-3 text-sm text-white md:col-span-2"
                    />
                  </div>
                </div>
              ))
            ) : (
              <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35">
                OCR preview shell is ready.
              </div>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
