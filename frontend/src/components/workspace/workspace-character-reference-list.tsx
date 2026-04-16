import type { ChangeEvent } from "react";

import { Button } from "../ui/button";
import type { VlmControlsPayload } from "./workspace-config";

type WorkspaceCharacterReferenceListProps = {
  references: VlmControlsPayload["characterReferences"];
  onAdd: () => void;
  onUpdate: (id: string, key: "name" | "imageBase64", value: string) => void;
  onRemove: (id: string) => void;
};

async function readImageAsBase64(file: File): Promise<string> {
  const dataUrl = await new Promise<string>((resolve, reject) => {
    const reader = new FileReader();
    reader.onload = () => resolve(String(reader.result || ""));
    reader.onerror = () => reject(reader.error || new Error("Unable to read image."));
    reader.readAsDataURL(file);
  });
  const [, base64 = ""] = dataUrl.split(",", 2);
  return base64;
}

export function WorkspaceCharacterReferenceList({
  references,
  onAdd,
  onUpdate,
  onRemove,
}: WorkspaceCharacterReferenceListProps) {
  const handleFileChange = async (id: string, event: ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) {
      return;
    }
    const base64 = await readImageAsBase64(file);
    onUpdate(id, "imageBase64", base64);
    event.target.value = "";
  };

  return (
    <div className="space-y-3">
      <div className="flex items-center justify-between gap-3">
        <div className="text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
          Character References
        </div>
        <Button
          type="button"
          size="sm"
          variant="secondary"
          className="rounded-2xl border border-white/10 bg-white/[0.03] text-[10px] font-black uppercase tracking-[0.22em] text-white hover:bg-white/[0.08]"
          onClick={onAdd}
        >
          Add
        </Button>
      </div>

      {references.length === 0 ? (
        <div className="rounded-2xl border border-dashed border-white/10 px-4 py-4 text-[11px] text-white/35">
          No reference
        </div>
      ) : null}

      {references.map((reference) => (
        <div key={reference.id} className="grid gap-3 rounded-2xl border border-white/8 bg-black/20 p-3">
          <input
            type="text"
            value={reference.name}
            onChange={(event) => onUpdate(reference.id, "name", event.target.value)}
            placeholder="Name"
            className="w-full rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-sm text-white outline-none transition-colors focus:border-white/30"
          />

          <div className="flex flex-wrap items-center gap-3">
            <input
              type="file"
              accept="image/*"
              onChange={(event) => void handleFileChange(reference.id, event)}
              className="block w-full min-w-0 text-[11px] text-white/65 file:mr-3 file:rounded-2xl file:border-0 file:bg-white file:px-4 file:py-2 file:text-[10px] file:font-black file:uppercase file:tracking-[0.22em] file:text-black"
            />
            <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/30">
              {reference.imageBase64 ? "Ready" : "Empty"}
            </div>
            <Button
              type="button"
              size="sm"
              variant="secondary"
              className="rounded-2xl border border-white/10 bg-transparent text-[10px] font-black uppercase tracking-[0.22em] text-white/70 hover:bg-white/[0.08]"
              onClick={() => onRemove(reference.id)}
            >
              Remove
            </Button>
          </div>
        </div>
      ))}
    </div>
  );
}
