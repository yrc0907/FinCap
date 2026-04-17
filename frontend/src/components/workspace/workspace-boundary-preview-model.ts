type BoundaryCandidateLike = {
  timeSec: number;
  windowStartSec: number;
  windowEndSec: number;
  score: number;
  confidence: string;
};

export type BoundaryPreviewItem = {
  index: number;
  timeSec: number;
  startSec: number;
  endSec: number;
  durationSec: number;
  score: number;
  confidence: string;
  laneLeftPercent: number;
  laneWidthPercent: number;
};

function roundToThousandths(value: number) {
  return Math.round(value * 1000) / 1000;
}

export function buildBoundaryPreviewItems(
  candidates: BoundaryCandidateLike[],
  videoDurationSec: number,
): BoundaryPreviewItem[] {
  const safeDurationSec = Math.max(videoDurationSec, 0.001);

  return candidates.map((candidate, index) => {
    const startSec = Math.max(0, candidate.windowStartSec);
    const endSec = Math.max(startSec, candidate.windowEndSec);
    const durationSec = endSec - startSec;

    return {
      index: index + 1,
      timeSec: candidate.timeSec,
      startSec,
      endSec,
      durationSec: roundToThousandths(durationSec),
      score: candidate.score,
      confidence: candidate.confidence,
      laneLeftPercent: roundToThousandths((startSec / safeDurationSec) * 100),
      laneWidthPercent: roundToThousandths((durationSec / safeDurationSec) * 100),
    };
  });
}
