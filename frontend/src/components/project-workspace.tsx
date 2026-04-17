import { motion } from "framer-motion";

import type { ProjectItem } from "../types/project";
import type { SystemConfig } from "../types/settings";
import { ProjectWorkspaceHeader } from "./workspace/project-workspace-header";
import { WorkspaceFlowLayout } from "./workspace/workspace-flow-layout";
import { useProjectWorkspaceState } from "./workspace/use-project-workspace-state";

type ProjectWorkspaceProps = {
  project: ProjectItem | null;
  onBack: () => void;
  onUploadVideo: (file: File) => Promise<ProjectItem | null> | void;
  settings: SystemConfig;
};

export function ProjectWorkspace({
  project,
  onBack,
  onUploadVideo,
  settings,
}: ProjectWorkspaceProps) {
  const state = useProjectWorkspaceState({
    project,
    settings,
    onUploadVideo,
  });

  return (
    <div className="relative flex h-screen w-screen select-none flex-col overflow-hidden bg-black px-5 pt-5 pb-4 font-sans text-white md:px-8 md:pt-7 md:pb-6">
      <div className="fincap-gradient pointer-events-none absolute inset-0" />
      <ProjectWorkspaceHeader project={project} onBack={onBack} />

      <main className="relative z-10 min-h-0 flex-1 overflow-hidden">
        <motion.section
          initial={{ opacity: 0, scale: 0.985 }}
          animate={{ opacity: 1, scale: 1 }}
          transition={{ duration: 0.45, ease: [0.16, 1, 0.3, 1] }}
          className="h-full min-h-0"
        >
          <WorkspaceFlowLayout state={state} />
        </motion.section>
      </main>
    </div>
  );
}
