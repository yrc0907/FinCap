import { Button } from "../ui/button";

export type AsrDraftEntry = {
  id: string;
  startSec: number;
  endSec: number;
  text: string;
  format: "asr" | "srt";
};

type WorkspaceAsrShellProps = {
  entries: AsrDraftEntry[];
  onChangeEntries: (entries: AsrDraftEntry[]) => void;
};

export function WorkspaceAsrShell({
  entries,
  onChangeEntries,
}: WorkspaceAsrShellProps) {
  const updateEntry = (id: string, key: keyof AsrDraftEntry, value: string) => {
    onChangeEntries(
      entries.map((entry) =>
        entry.id === id
          ? {
              ...entry,
              [key]:
                key === "text" || key === "format"
                  ? value
                  : Number.isFinite(Number(value))
                    ? Number(value)
                    : entry[key],
            }
          : entry,
      ) as AsrDraftEntry[],
    );
  };

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between gap-3">
        <div>
          <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">ASR</div>
          <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
            Editable shell
          </div>
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
                format: "asr",
              },
            ])
          }
        >
          Add
        </Button>
      </div>
      <div className="max-h-[520px] space-y-3 overflow-y-auto pr-1">
        {entries.length > 0 ? (
          entries.map((entry, index) => (
            <div key={entry.id} className="rounded-2xl border border-white/8 bg-black/20 p-4">
              <div className="flex items-center justify-between gap-3">
                <div className="text-[10px] font-black uppercase tracking-[0.2em] text-white/60">
                  Segment {index + 1}
                </div>
                <select
                  value={entry.format}
                  onChange={(event) => updateEntry(entry.id, "format", event.target.value)}
                  className="rounded-2xl border border-white/10 bg-black/30 px-3 py-2 text-[11px] text-white"
                >
                  <option value="asr">ASR</option>
                  <option value="srt">SRT</option>
                </select>
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
            ASR preview shell is ready.
          </div>
        )}
      </div>
    </div>
  );
}
