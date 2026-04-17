type WorkflowNodeMetricProps = {
  label: string;
  value: string;
};

export function WorkflowNodeMetric({
  label,
  value,
}: WorkflowNodeMetricProps) {
  return (
    <div className="min-w-0 rounded-2xl border border-white/8 bg-black/20 px-4 py-3">
      <div className="truncate text-[10px] font-mono uppercase tracking-[0.18em] text-white/25">
        {label}
      </div>
      <div
        title={value}
        className="mt-2 min-w-0 break-words text-sm leading-snug font-black text-white/85"
      >
        {value}
      </div>
    </div>
  );
}
