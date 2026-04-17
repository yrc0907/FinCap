import { Button } from "../ui/button";

type WorkflowCanvasControlsProps = {
  onZoomIn: () => void;
  onZoomOut: () => void;
  onResetView: () => void;
};

export function WorkflowCanvasControls({
  onZoomIn,
  onZoomOut,
  onResetView,
}: WorkflowCanvasControlsProps) {
  return (
    <div className="absolute top-4 right-4 z-20 flex items-center gap-2 rounded-2xl border border-white/10 bg-black/70 p-2 backdrop-blur-xl">
      <Button
        type="button"
        size="icon"
        variant="secondary"
        aria-label="Zoom Out"
        onClick={onZoomOut}
        className="h-8 w-8 rounded-xl border border-white/10 bg-white/[0.03] text-white/75 hover:bg-white/[0.08] hover:text-white"
      >
        -
      </Button>
      <Button
        type="button"
        size="icon"
        variant="secondary"
        aria-label="Zoom In"
        onClick={onZoomIn}
        className="h-8 w-8 rounded-xl border border-white/10 bg-white/[0.03] text-white/75 hover:bg-white/[0.08] hover:text-white"
      >
        +
      </Button>
      <Button
        type="button"
        size="sm"
        variant="secondary"
        aria-label="Reset View"
        onClick={onResetView}
        className="h-8 rounded-xl border border-white/10 bg-white/[0.03] px-3 text-[10px] font-black uppercase tracking-[0.18em] text-white/75 hover:bg-white/[0.08] hover:text-white"
      >
        Fit
      </Button>
    </div>
  );
}
