import { useEffect, useMemo, useState } from "react";

import type { StrictShotGenerationResult } from "../../types/workspace";
import type { FrameOverride } from "../../types/workspace-drafts";
import { Button } from "../ui/button";
import type { VlmControlsPayload } from "./workspace-config";
import {
  applyFrameOverrides,
  buildPlannedFrameSlots,
  type PlannedFrameSlot,
} from "./workspace-frame-slots";
import { WorkspaceFrameEditorShell } from "./workspace-frame-editor-shell";

type WorkspaceVlmGridShellProps = {
  videoSrc: string | undefined;
  shots: StrictShotGenerationResult["shots"];
  vlmPayload: VlmControlsPayload;
  activeModel: string | null;
  isRunning: boolean;
  frameOverrides: FrameOverride[];
  onSaveOverrides: (items: FrameOverride[]) => void;
};

export function WorkspaceVlmGridShell({
  videoSrc,
  shots,
  vlmPayload,
  activeModel,
  isRunning,
  frameOverrides,
  onSaveOverrides,
}: WorkspaceVlmGridShellProps) {
  const plannedSlots = useMemo(
    () => buildPlannedFrameSlots(shots, vlmPayload.group_size, vlmPayload.keyframes_per_shot),
    [shots, vlmPayload.group_size, vlmPayload.keyframes_per_shot],
  );
  const hydratedSlots = useMemo(
    () => applyFrameOverrides(plannedSlots, frameOverrides),
    [frameOverrides, plannedSlots],
  );
  const [draftSlots, setDraftSlots] = useState<PlannedFrameSlot[]>(hydratedSlots);
  const [selectedSlotId, setSelectedSlotId] = useState<string | null>(hydratedSlots[0]?.id ?? null);

  useEffect(() => {
    setDraftSlots(hydratedSlots);
    setSelectedSlotId(hydratedSlots[0]?.id ?? null);
  }, [hydratedSlots]);

  const selectedSlot = draftSlots.find((slot) => slot.id === selectedSlotId) ?? null;
  const editedCount = draftSlots.filter(
    (slot) => Math.abs(slot.timeSec - slot.sourceTimeSec) > 0.0005,
  ).length;

  const handleChangeSlotTime = (slotId: string, timeSec: number) => {
    setDraftSlots((current) =>
      current.map((slot) =>
        slot.id === slotId ? { ...slot, timeSec: Number(timeSec.toFixed(3)) } : slot,
      ),
    );
  };

  const handleResetSlot = (slotId: string) => {
    setDraftSlots((current) =>
      current.map((slot) =>
        slot.id === slotId ? { ...slot, timeSec: slot.sourceTimeSec } : slot,
      ),
    );
  };

  const handleSave = () => {
    onSaveOverrides(
      draftSlots
        .filter((slot) => Math.abs(slot.timeSec - slot.sourceTimeSec) > 0.0005)
        .map((slot) => ({
          shotIndex: slot.shotIndex,
          frameIndex: slot.frameIndex,
          groupIndex: slot.groupIndex,
          timeSec: slot.timeSec,
          sourceTimeSec: slot.sourceTimeSec,
        })),
    );
  };

  return (
    <div className="space-y-5">
      <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="flex flex-wrap items-center justify-between gap-3">
          <div>
            <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
              VLM Grid
            </div>
            <div className="mt-2 break-all text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
              {activeModel ?? "No Model"}
            </div>
          </div>
          <div className="rounded-full border border-white/10 bg-white/[0.03] px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/55">
            {isRunning ? "Running" : "Ready"}
          </div>
        </div>

        <div className="mt-4 grid gap-3 md:grid-cols-2 xl:grid-cols-4">
          <MetricCard label="Group" value={String(vlmPayload.group_size)} />
          <MetricCard label="Frames" value={String(vlmPayload.keyframes_per_shot)} />
          <MetricCard label="Planned" value={String(draftSlots.length)} />
          <MetricCard label="Edited" value={String(editedCount)} />
        </div>
      </div>

      <div className="grid gap-5 xl:grid-cols-[0.95fr_1.05fr]">
        <div className="grid gap-3 md:grid-cols-3 xl:grid-cols-2">
          {draftSlots.length > 0 ? (
            draftSlots.map((slot) => {
              const isSelected = slot.id === selectedSlotId;
              const isEdited = Math.abs(slot.timeSec - slot.sourceTimeSec) > 0.0005;

              return (
                <button
                  key={slot.id}
                  type="button"
                  onClick={() => setSelectedSlotId(slot.id)}
                  className={[
                    "rounded-[24px] border p-3 text-left transition-colors",
                    isSelected
                      ? "border-white/25 bg-white/[0.06]"
                      : "border-white/8 bg-white/[0.02] hover:bg-white/[0.04]",
                  ].join(" ")}
                >
                  <div className="aspect-square rounded-2xl border border-dashed border-white/10 bg-black/30" />
                  <div className="mt-3 flex items-center justify-between gap-3">
                    <div className="text-[10px] font-black uppercase tracking-[0.18em] text-white/70">
                      Group {slot.groupIndex}
                    </div>
                    <div className="text-[9px] font-black uppercase tracking-[0.18em] text-white/40">
                      {isEdited ? "Edited" : "Original"}
                    </div>
                  </div>
                  <div className="mt-2 text-[11px] text-white/55">Shot {slot.shotIndex}</div>
                  <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
                    {slot.timeSec.toFixed(3)}s
                  </div>
                </button>
              );
            })
          ) : (
            <div className="rounded-2xl border border-dashed border-white/10 px-4 py-8 text-center text-[11px] text-white/35 md:col-span-3 xl:col-span-2">
              Run shot generation first.
            </div>
          )}
        </div>

        {selectedSlot ? (
          <WorkspaceFrameEditorShell
            videoSrc={videoSrc}
            slot={selectedSlot}
            onChangeTime={(timeSec) => handleChangeSlotTime(selectedSlot.id, timeSec)}
            onReset={() => handleResetSlot(selectedSlot.id)}
          />
        ) : null}
      </div>

      <div className="flex justify-end">
        <Button type="button" size="sm" className="rounded-2xl" onClick={handleSave}>
          Save
        </Button>
      </div>

      {isRunning ? (
        <div className="space-y-2">
          <div className="h-2 overflow-hidden rounded-full bg-white/10">
            <div className="h-full w-1/2 animate-pulse rounded-full bg-white" />
          </div>
          <div className="text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
            VLM progress shell
          </div>
        </div>
      ) : null}
    </div>
  );
}

function MetricCard({ label, value }: { label: string; value: string }) {
  return (
    <div className="rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
      <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">{label}</div>
      <div className="mt-2 break-all text-lg font-black text-white/85">{value}</div>
    </div>
  );
}
