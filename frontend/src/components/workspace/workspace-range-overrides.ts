import type { ClipRangeOverride, TimedRangeItem } from "../../types/workspace-drafts";

export function applyTimedRangeOverrides<T extends TimedRangeItem>(
  items: T[],
  overrides: ClipRangeOverride[],
  getKey: (item: T) => string,
): T[] {
  if (items.length === 0 || overrides.length === 0) {
    return items;
  }

  const overrideMap = new Map(overrides.map((item) => [item.key, item]));

  return items.map((item) => {
    const override = overrideMap.get(getKey(item));
    if (!override) {
      return item;
    }

    const startSec = Number(override.startSec.toFixed(3));
    const endSec = Number(Math.max(override.endSec, startSec).toFixed(3));
    return {
      ...item,
      startSec,
      endSec,
      durationSec: Number((endSec - startSec).toFixed(3)),
    };
  });
}
