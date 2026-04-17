import type { ReactNode } from "react";

import { Button } from "../ui/button";

export type WorkflowNodeTone = "idle" | "running" | "success" | "error";

type WorkflowNodeAction = {
  label: string;
  onClick: () => void;
  disabled?: boolean;
  busy?: boolean;
  variant?: "default" | "secondary" | "ghost";
};

type WorkflowNodeCardProps = {
  eyebrow: string;
  title: string;
  status: string;
  description?: string;
  children?: ReactNode;
  actions?: WorkflowNodeAction[];
  active?: boolean;
  tone?: WorkflowNodeTone;
  message?: string;
};

export function WorkflowNodeCard({
  eyebrow,
  title,
  status,
  description,
  children,
  actions = [],
  active = false,
  tone = "idle",
  message,
}: WorkflowNodeCardProps) {
  const toneFrameClassName =
    tone === "running"
      ? "border-cyan-400/65 opacity-100 shadow-[0_0_34px_rgba(34,211,238,0.24)] animate-pulse"
      : tone === "success"
        ? "border-emerald-400/70 opacity-100 shadow-[0_0_34px_rgba(16,185,129,0.28)]"
        : tone === "error"
          ? "border-rose-400/70 opacity-100 shadow-[0_0_34px_rgba(251,113,133,0.28)]"
          : "border-transparent opacity-0";
  const toneBadgeClassName =
    tone === "running"
      ? "border-cyan-400/25 bg-cyan-400/10 text-cyan-200"
      : tone === "success"
        ? "border-emerald-400/25 bg-emerald-400/10 text-emerald-200"
        : tone === "error"
          ? "border-rose-400/25 bg-rose-400/10 text-rose-200"
          : "border-white/10 bg-white/[0.04] text-white/58";
  const toneMessageClassName =
    tone === "running"
      ? "border-cyan-400/15 bg-cyan-400/10 text-cyan-100"
      : tone === "success"
        ? "border-emerald-400/15 bg-emerald-400/10 text-emerald-100"
        : tone === "error"
          ? "border-rose-400/15 bg-rose-400/10 text-rose-100"
          : "border-white/8 bg-white/[0.03] text-white/55";

  return (
    <section
      data-tone={tone}
      className={[
        "relative min-w-0 overflow-hidden rounded-[30px] border p-5 backdrop-blur-xl transition-all",
        "bg-[linear-gradient(180deg,rgba(255,255,255,0.05),rgba(255,255,255,0.015))]",
        active
          ? "border-white/18 shadow-[0_0_50px_rgba(255,255,255,0.08)]"
          : "border-white/8 shadow-[0_0_40px_rgba(0,0,0,0.35)]",
      ].join(" ")}
    >
      <div
        aria-hidden
        className={[
          "pointer-events-none absolute inset-0 rounded-[30px] border-2 transition-all duration-300",
          toneFrameClassName,
        ].join(" ")}
      />
      <div className="absolute inset-x-5 top-0 h-px bg-gradient-to-r from-transparent via-white/40 to-transparent" />
      <div className="absolute inset-0 bg-[radial-gradient(circle_at_top_left,rgba(255,255,255,0.08),transparent_42%)]" />

      <div className="relative z-10 space-y-5">
        <div className="flex items-start justify-between gap-4">
          <div className="min-w-0 space-y-3">
            <div className="inline-flex items-center gap-2 rounded-full border border-white/10 bg-black/35 px-3 py-1">
              <span className="text-[10px] font-black uppercase tracking-[0.24em] text-white/72">
                {eyebrow}
              </span>
              {description ? (
                <span className="text-[9px] font-mono uppercase tracking-[0.2em] text-white/28">
                  {description}
                </span>
              ) : null}
            </div>
            <h3 className="min-w-0 break-words text-[16px] leading-tight font-black tracking-[0.04em] text-white/92">
              {title}
            </h3>
          </div>

          <div
            className={[
              "shrink-0 rounded-full border px-3 py-1.5 text-[9px] font-black uppercase tracking-[0.22em]",
              toneBadgeClassName,
            ].join(" ")}
          >
            {status}
          </div>
        </div>

        {message ? (
          <div
            className={[
              "rounded-2xl border px-3 py-2 text-[11px] font-black tracking-[0.04em]",
              toneMessageClassName,
            ].join(" ")}
          >
            {message}
          </div>
        ) : null}

        {children ? <div>{children}</div> : null}

        {actions.length > 0 ? (
          <div className="flex flex-wrap gap-2 border-t border-white/6 pt-4">
            {actions.map((action) => (
              <Button
                key={action.label}
                type="button"
                size="sm"
                variant={action.variant ?? "secondary"}
                disabled={action.disabled || action.busy}
                className={[
                  "h-9 rounded-2xl border px-4 text-[10px] font-black uppercase tracking-[0.18em]",
                  action.variant === "default"
                    ? "border-white/0 bg-white text-black hover:bg-white/90"
                    : action.variant === "ghost"
                      ? "border-white/10 bg-transparent text-white/70 hover:bg-white/[0.08]"
                      : "border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]",
                ].join(" ")}
                onClick={action.onClick}
              >
                {action.busy ? `${action.label}...` : action.label}
              </Button>
            ))}
          </div>
        ) : null}
      </div>
    </section>
  );
}
