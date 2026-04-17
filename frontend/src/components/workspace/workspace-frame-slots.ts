import type { StrictShotGenerationResult } from "../../types/workspace";
import type { FrameOverride } from "../../types/workspace-drafts";

export type PlannedFrameSlot = {
  id: string;
  groupIndex: number;
  shotIndex: number;
  frameIndex: number;
  shotStartSec: number;
  shotEndSec: number;
  timeSec: number;
  sourceTimeSec: number;
};

export function buildPlannedFrameSlots(
  shots: StrictShotGenerationResult["shots"],
  groupSize: number,
  framesPerShot: number,
): PlannedFrameSlot[] {
  const safeGroupSize = Math.max(1, groupSize);
  const safeFramesPerShot = Math.max(1, framesPerShot);
  const slots: PlannedFrameSlot[] = [];

  shots.forEach((shot, shotPosition) => {
    const groupIndex = Math.floor(shotPosition / safeGroupSize) + 1;

    for (let frameIndex = 0; frameIndex < safeFramesPerShot; frameIndex += 1) {
      const ratio = (frameIndex + 1) / (safeFramesPerShot + 1);
      const timeSec = Number((shot.startSec + shot.durationSec * ratio).toFixed(3));

      slots.push({
        id: `${groupIndex}-${shot.index}-${frameIndex}`,
        groupIndex,
        shotIndex: shot.index,
        frameIndex,
        shotStartSec: shot.startSec,
        shotEndSec: shot.endSec,
        timeSec,
        sourceTimeSec: timeSec,
      });
    }
  });

  return slots;
}

export function applyFrameOverrides(
  slots: PlannedFrameSlot[],
  overrides: FrameOverride[],
): PlannedFrameSlot[] {
  if (slots.length === 0 || overrides.length === 0) {
    return slots;
  }

  const overrideMap = new Map(
    overrides.map((item) => [`${item.shotIndex}:${item.frameIndex}`, item]),
  );

  return slots.map((slot) => {
    const override = overrideMap.get(`${slot.shotIndex}:${slot.frameIndex}`);
    if (!override) {
      return slot;
    }

    return {
      ...slot,
      groupIndex: override.groupIndex,
      timeSec: Number(override.timeSec.toFixed(3)),
      sourceTimeSec: Number(override.sourceTimeSec.toFixed(3)),
    };
  });
}
