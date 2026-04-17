type ViewportState = {
  x: number;
  y: number;
  zoom: number;
};

type SurfaceSize = {
  width: number;
  height: number;
};

type NodeBounds = {
  x: number;
  y: number;
  width: number;
  height: number;
};

export type ViewportFlowBounds = {
  minX: number;
  minY: number;
  maxX: number;
  maxY: number;
};

export function buildViewportFlowBounds(
  viewport: ViewportState,
  surfaceSize: SurfaceSize,
): ViewportFlowBounds {
  const zoom = viewport.zoom || 1;

  return {
    minX: -viewport.x / zoom,
    minY: -viewport.y / zoom,
    maxX: (surfaceSize.width - viewport.x) / zoom,
    maxY: (surfaceSize.height - viewport.y) / zoom,
  };
}

export function shouldAutoZoomOutForDraggedNode(
  nodeBounds: NodeBounds,
  viewportBounds: ViewportFlowBounds,
): boolean {
  return (
    nodeBounds.x < viewportBounds.minX ||
    nodeBounds.y < viewportBounds.minY ||
    nodeBounds.x + nodeBounds.width > viewportBounds.maxX ||
    nodeBounds.y + nodeBounds.height > viewportBounds.maxY
  );
}

export function getNextAutoZoomLevel(currentZoom: number, minZoom: number): number {
  return Math.max(minZoom, Number((currentZoom * 0.94).toFixed(3)));
}
