export type SourceRangeTimelineModel = {
  maxSec: number;
  startSec: number;
  endSec: number;
  currentTimeSec: number;
  startPercent: number;
  endPercent: number;
  currentPercent: number;
  selectedWidthPercent: number;
};

function clampTime(value: number, min: number, max: number) {
  return Math.min(Math.max(value, min), max);
}

function roundToThousandths(value: number) {
  return Math.round(value * 1000) / 1000;
}

export function buildSourceRangeTimelineModel(
  startSec: number,
  endSec: number,
  maxSec: number,
  currentTimeSec: number,
): SourceRangeTimelineModel {
  const safeMaxSec = Math.max(maxSec, 0.001);
  const safeStartSec = clampTime(startSec, 0, safeMaxSec);
  const safeEndSec = clampTime(endSec, safeStartSec, safeMaxSec);
  const safeCurrentTimeSec = clampTime(currentTimeSec, 0, safeMaxSec);
  const startPercent = (safeStartSec / safeMaxSec) * 100;
  const endPercent = (safeEndSec / safeMaxSec) * 100;
  const currentPercent = (safeCurrentTimeSec / safeMaxSec) * 100;

  return {
    maxSec: safeMaxSec,
    startSec: safeStartSec,
    endSec: safeEndSec,
    currentTimeSec: safeCurrentTimeSec,
    startPercent: roundToThousandths(startPercent),
    endPercent: roundToThousandths(endPercent),
    currentPercent: roundToThousandths(currentPercent),
    selectedWidthPercent: roundToThousandths(endPercent - startPercent),
  };
}
