import { ArrowLeft, Command } from "lucide-react";
import { motion } from "framer-motion";
import type { ProjectItem } from "../types/project";

type ProjectWorkspaceProps = {
  project: ProjectItem | null;
  onBack: () => void;
};

export function ProjectWorkspace({ project, onBack }: ProjectWorkspaceProps) {
  return (
    <div className="h-screen w-screen bg-black text-white flex flex-col p-6 md:p-10 font-sans relative overflow-hidden select-none">
      <div className="absolute inset-0 fincap-gradient pointer-events-none" />

      <nav className="flex items-center justify-between mb-8 md:mb-16 relative z-20 shrink-0">
        <div className="flex items-center gap-3 md:gap-5">
          <div className="w-9 h-9 md:w-11 md:h-11 bg-white flex items-center justify-center rounded-xl md:rounded-2xl shadow-[0_0_30px_rgba(255,255,255,0.1)]">
            <Command size={18} className="text-black md:hidden" />
            <Command size={22} className="text-black hidden md:block" />
          </div>
          <span className="text-2xl md:text-3xl font-black tracking-[-0.05em] uppercase">FinCap</span>
        </div>

        <button
          onClick={onBack}
          className="inline-flex items-center gap-2 rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.3em] text-white/70 transition-all hover:border-white/30 hover:text-white"
        >
          <ArrowLeft size={14} />
          Back
        </button>
      </nav>

      <main className="relative z-10 flex-1 min-h-0">
        <motion.div
          initial={{ opacity: 0, scale: 0.98 }}
          animate={{ opacity: 1, scale: 1 }}
          transition={{ duration: 0.5, ease: [0.16, 1, 0.3, 1] }}
          className="glass video-glow flex h-full flex-col items-center justify-center rounded-3xl border border-white/[0.04] md:rounded-[48px]"
        >
          <div className="text-center text-2xl font-black tracking-[-0.04em] uppercase md:text-4xl">
            Editor Placeholder
          </div>
          <div className="mt-5 text-center">
            <div className="text-base font-bold tracking-tight text-white/80 md:text-xl">
              {project?.name ?? "Untitled Project"}
            </div>
            <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
              {project?.meta ?? "No Project Selected"}
            </div>
          </div>
        </motion.div>
      </main>
    </div>
  );
}
