import { ArrowLeft, Command } from "lucide-react";

import type { ProjectItem } from "../../types/project";
import { Button } from "../ui/button";

type ProjectWorkspaceHeaderProps = {
  project: ProjectItem | null;
  onBack: () => void;
};

export function ProjectWorkspaceHeader({
  project,
  onBack,
}: ProjectWorkspaceHeaderProps) {
  return (
    <nav className="relative z-20 mb-4 flex shrink-0 items-center justify-between md:mb-6">
      <div className="flex items-center gap-3 md:gap-5">
        <div className="flex h-9 w-9 items-center justify-center rounded-xl bg-white shadow-[0_0_30px_rgba(255,255,255,0.1)] md:h-11 md:w-11 md:rounded-2xl">
          <Command size={18} className="text-black md:hidden" />
          <Command size={22} className="hidden text-black md:block" />
        </div>
        <div>
          <div className="text-2xl font-black uppercase tracking-[-0.05em] md:text-3xl">
            FinCap
          </div>
          <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/20">
            Workflow Console
          </div>
          <div className="mt-3 text-[11px] font-mono uppercase tracking-[0.24em] text-white/25">
            {project?.name ?? "No Project"}
          </div>
        </div>
      </div>

      <Button
        onClick={onBack}
        variant="ghost"
        size="lg"
        className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.3em] text-white/70 hover:border-white/30 hover:bg-white/[0.05] hover:text-white"
      >
        <ArrowLeft size={14} />
        Back
      </Button>
    </nav>
  );
}
