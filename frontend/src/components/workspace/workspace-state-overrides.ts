import type {
  CorrectedEventTimelineResult,
  StrictShot,
  StrictShotGenerationResult,
} from "../../types/workspace";
import type { ClipRangeOverride } from "../../types/workspace-drafts";
import { applyTimedRangeOverrides } from "./workspace-range-overrides";

type FunctionalClipType = "build" | "peak" | "result" | "transition";

export function applyStrictShotOverrides(
  result: StrictShotGenerationResult | null,
  overrides: ClipRangeOverride[],
): StrictShotGenerationResult | null {
  if (!result) {
    return null;
  }
  const shots = applyTimedRangeOverrides(result.shots, overrides, (shot) =>
    buildShotOverrideKey(shot.index),
  );
  return {
    ...result,
    shots,
    summary: recalculateShotSummary(result.shots, shots, result.summary.abnormalShortShotCount),
  };
}

export function applyFunctionalClipOverrides(
  result: CorrectedEventTimelineResult | null,
  overrides: ClipRangeOverride[],
): CorrectedEventTimelineResult | null {
  if (!result) {
    return null;
  }
  return {
    ...result,
    functionalClips: applyTimedRangeOverrides(result.functionalClips, overrides, (clip) =>
      buildFunctionalClipOverrideKey(clip.index, clip.type),
    ),
  };
}

export function upsertRangeOverride(
  current: ClipRangeOverride[],
  nextItem: ClipRangeOverride,
): ClipRangeOverride[] {
  const nextMap = new Map(current.map((item) => [item.key, item]));
  nextMap.set(nextItem.key, {
    ...nextItem,
    startSec: Number(nextItem.startSec.toFixed(3)),
    endSec: Number(Math.max(nextItem.endSec, nextItem.startSec).toFixed(3)),
  });
  return Array.from(nextMap.values());
}

export function buildShotOverrideKey(index: number) {
  return `shot:${index}`;
}

export function buildFunctionalClipOverrideKey(index: number, type: FunctionalClipType) {
  return `functional:${type}:${index}`;
}

function recalculateShotSummary(
  originalShots: StrictShot[],
  nextShots: StrictShot[],
  fallbackAbnormalCount: number,
) {
  if (nextShots.length === 0) {
    return {
      shotCount: 0,
      shortestShotSec: 0,
      longestShotSec: 0,
      abnormalShortShotCount: 0,
      isLegal: true,
    };
  }
  const durations = nextShots.map((shot) => shot.durationSec);
  const minShotSec =
    originalShots.length > 0
      ? Math.min(...originalShots.map((shot) => shot.durationSec))
      : Number.POSITIVE_INFINITY;
  return {
    shotCount: nextShots.length,
    shortestShotSec: Number(Math.min(...durations).toFixed(3)),
    longestShotSec: Number(Math.max(...durations).toFixed(3)),
    abnormalShortShotCount:
      Number.isFinite(minShotSec) && minShotSec > 0
        ? nextShots.filter((shot) => shot.durationSec < minShotSec).length
        : fallbackAbnormalCount,
    isLegal: nextShots.every((shot) => shot.durationSec >= 0),
  };
}
