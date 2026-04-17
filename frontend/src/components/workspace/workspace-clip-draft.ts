type ClipDraftField = "start" | "end";

function clampTime(value: number, min: number, max: number) {
  return Math.min(Math.max(value, min), max);
}

export function clampClipDraft(
  startSec: number,
  endSec: number,
  maxSec: number,
) {
  const clampedMaxSec = Math.max(startSec, endSec, maxSec, 0);
  const draftStartSec = clampTime(startSec, 0, clampedMaxSec);
  const draftEndSec = clampTime(endSec, draftStartSec, clampedMaxSec);

  return {
    draftStartSec,
    draftEndSec,
    clampedMaxSec,
  };
}

export function updateClipDraftField(
  field: ClipDraftField,
  value: number,
  draftStartSec: number,
  draftEndSec: number,
  maxSec: number,
) {
  const { clampedMaxSec } = clampClipDraft(draftStartSec, draftEndSec, maxSec);

  if (field === "start") {
    const nextStartSec = clampTime(value, 0, draftEndSec);
    return {
      draftStartSec: nextStartSec,
      draftEndSec,
      previewTimeSec: nextStartSec,
    };
  }

  const nextEndSec = clampTime(value, draftStartSec, clampedMaxSec);
  return {
    draftStartSec,
    draftEndSec: nextEndSec,
    previewTimeSec: nextEndSec,
  };
}
