type WorkspaceNumericFieldProps = {
  label: string;
  value: number;
  step: string;
  onChange: (value: string) => void;
  fullWidth?: boolean;
};

export function WorkspaceNumericField({
  label,
  value,
  step,
  onChange,
  fullWidth = false,
}: WorkspaceNumericFieldProps) {
  return (
    <label className={`space-y-2 ${fullWidth ? "md:col-span-2" : ""}`}>
      <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
        {label}
      </span>
      <input
        type="number"
        step={step}
        value={value}
        onChange={(event) => onChange(event.target.value)}
        className="w-full rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-sm text-white outline-none transition-colors focus:border-white/30"
      />
    </label>
  );
}
