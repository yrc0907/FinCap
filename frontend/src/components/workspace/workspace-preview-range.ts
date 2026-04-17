export function buildPreviewRangeKey(
  src: string | undefined,
  startSec: number,
  endSec: number,
) {
  return `${src ?? "no-src"}:${startSec.toFixed(3)}:${endSec.toFixed(3)}`;
}
