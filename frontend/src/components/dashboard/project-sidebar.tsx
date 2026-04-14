import { type KeyboardEvent, type RefObject } from "react";
import { AnimatePresence, motion } from "framer-motion";
import { ArrowDownUp, FolderOpen, Pencil, Search, Trash2, X } from "lucide-react";

import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuLabel,
  DropdownMenuRadioGroup,
  DropdownMenuRadioItem,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from "../ui/dropdown-menu";
import type { ProjectItem } from "../../types/project";
import type { BrowserModalMode, SortMode } from "./types";
import { formatRelativeTime, iconButtonClass } from "./utils";

type ProjectSidebarProps = {
  explorerWidth: number;
  isMobileLayout: boolean;
  searchOpen: boolean;
  searchDraft: string;
  searchQuery: string;
  sortMode: SortMode;
  visibleProjects: ProjectItem[];
  activeProjectCount: number;
  trashedProjectsCount: number;
  projectsReady: boolean;
  editingProjectId: string | null;
  renameDraft: string;
  renameInputRef: RefObject<HTMLInputElement | null>;
  onSearchToggle: () => void;
  onSearchDraftChange: (value: string) => void;
  onSearchClose: () => void;
  onSortModeChange: (value: SortMode) => void;
  onOpenBrowserModal: (mode: Exclude<BrowserModalMode, null>) => void;
  onOpenProject: (projectId: string) => void;
  onStartRename: (project: ProjectItem) => void;
  onRenameDraftChange: (value: string) => void;
  onCommitRename: (projectId: string) => void;
  onHandleRenameKeyDown: (event: KeyboardEvent<HTMLInputElement>, projectId: string) => void;
  onRequestMoveToTrash: (projectIds: string[]) => void;
};

export function ProjectSidebar({
  explorerWidth,
  isMobileLayout,
  searchOpen,
  searchDraft,
  searchQuery,
  sortMode,
  visibleProjects,
  activeProjectCount,
  trashedProjectsCount,
  projectsReady,
  editingProjectId,
  renameDraft,
  renameInputRef,
  onSearchToggle,
  onSearchDraftChange,
  onSearchClose,
  onSortModeChange,
  onOpenBrowserModal,
  onOpenProject,
  onStartRename,
  onRenameDraftChange,
  onCommitRename,
  onHandleRenameKeyDown,
  onRequestMoveToTrash,
}: ProjectSidebarProps) {
  return (
    <div
      className="flex flex-col gap-6 md:gap-8 min-h-0 shrink-0 md:pl-8 w-full md:w-auto overflow-hidden"
      style={{ width: isMobileLayout ? "100%" : explorerWidth }}
    >
      <div className="space-y-4 px-2">
        <div className="flex items-center justify-between gap-3">
          <div className="min-w-0">
            <h3 className="text-[10px] md:text-[11px] font-black tracking-[0.4em] uppercase text-white/30 truncate">
              Assets
            </h3>
            {searchQuery ? (
              <p className="mt-2 text-[9px] font-mono uppercase tracking-[0.25em] text-white/20">
                Filtered Results
              </p>
            ) : null}
          </div>

          <div className="flex items-center gap-2 shrink-0">
            <button className={iconButtonClass} title="All Projects" onClick={() => onOpenBrowserModal("projects")}>
              <FolderOpen size={16} />
            </button>

            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <button className={iconButtonClass} title="Sort">
                  <ArrowDownUp size={16} />
                </button>
              </DropdownMenuTrigger>
              <DropdownMenuContent>
                <DropdownMenuLabel>Sort</DropdownMenuLabel>
                <DropdownMenuSeparator />
                <DropdownMenuRadioGroup value={sortMode} onValueChange={(value) => onSortModeChange(value as SortMode)}>
                  <DropdownMenuRadioItem value="newest">Time Desc</DropdownMenuRadioItem>
                  <DropdownMenuRadioItem value="oldest">Time Asc</DropdownMenuRadioItem>
                  <DropdownMenuRadioItem value="name-asc">Name Asc</DropdownMenuRadioItem>
                  <DropdownMenuRadioItem value="name-desc">Name Desc</DropdownMenuRadioItem>
                </DropdownMenuRadioGroup>
              </DropdownMenuContent>
            </DropdownMenu>

            <button
              className={`${iconButtonClass} ${searchOpen || searchDraft ? "border-white/25 text-white" : ""}`}
              title="Search"
              onClick={onSearchToggle}
            >
              <Search size={16} />
            </button>

            <button
              className={`${iconButtonClass} ${trashedProjectsCount > 0 ? "text-white/70" : ""}`}
              title="Trash"
              onClick={() => onOpenBrowserModal("trash")}
            >
              <Trash2 size={16} />
            </button>
          </div>
        </div>

        <AnimatePresence initial={false}>
          {searchOpen ? (
            <motion.div
              initial={{ opacity: 0, height: 0 }}
              animate={{ opacity: 1, height: "auto" }}
              exit={{ opacity: 0, height: 0 }}
              className="overflow-hidden"
            >
              <div className="relative">
                <Search
                  size={16}
                  className="pointer-events-none absolute top-1/2 left-5 -translate-y-1/2 text-white/25"
                />
                <input
                  type="text"
                  value={searchDraft}
                  onChange={(event) => onSearchDraftChange(event.target.value)}
                  placeholder="Search projects"
                  className="w-full rounded-2xl border border-white/10 bg-white/[0.03] py-3 pr-12 pl-12 text-sm text-white outline-none transition-colors placeholder:text-white/20 focus:border-white/30"
                />
                <button
                  onClick={onSearchClose}
                  className="absolute top-1/2 right-4 -translate-y-1/2 text-white/20 transition-colors hover:text-white"
                >
                  <X size={14} />
                </button>
              </div>
            </motion.div>
          ) : null}
        </AnimatePresence>
      </div>

      <div className="flex-1 overflow-visible space-y-4 md:space-y-5 pr-2 scrollbar-none relative">
        {visibleProjects.map((project) => (
          <motion.div
            key={project.id}
            initial={false}
            onClick={() => onOpenProject(project.id)}
            whileHover={{
              scale: 1.05,
              x: -8,
              zIndex: 50,
            }}
            transition={{ duration: 0.1, ease: "linear" }}
            className="group relative flex gap-4 md:gap-5 p-3 md:p-4 rounded-2xl md:rounded-3xl cursor-pointer bg-white/[0.01] hover:bg-black hover:shadow-[0_15px_40px_rgba(0,0,0,0.8)] border border-white/[0.03] hover:border-white/20 transition-all duration-200"
          >
            <div className="relative w-20 h-14 md:w-28 md:h-20 rounded-xl md:rounded-2xl overflow-hidden bg-white/5 border border-white/5 shrink-0">
              {project.isVideo && project.thumb ? (
                <video
                  src={project.thumb}
                  muted
                  playsInline
                  preload="metadata"
                  className="w-full h-full object-cover transition-all duration-300 opacity-80 group-hover:opacity-100"
                />
              ) : (
                <img
                  src={project.thumb}
                  alt=""
                  className="w-full h-full object-cover transition-all duration-300 opacity-80 group-hover:opacity-100"
                />
              )}
            </div>

            <div className="flex flex-1 items-start justify-between gap-3 min-w-0">
              <div className="flex flex-col justify-center flex-1 min-w-0">
                {editingProjectId === project.id ? (
                  <input
                    ref={renameInputRef}
                    type="text"
                    value={renameDraft}
                    onClick={(event) => event.stopPropagation()}
                    onChange={(event) => onRenameDraftChange(event.target.value)}
                    onBlur={() => onCommitRename(project.id)}
                    onKeyDown={(event) => onHandleRenameKeyDown(event, project.id)}
                    className="w-full rounded-xl border border-white/10 bg-white/[0.04] px-3 py-2 text-sm font-bold text-white outline-none transition-colors focus:border-white/30"
                  />
                ) : (
                  <span className="text-[11px] md:text-sm font-bold text-white/80 group-hover:text-white truncate tracking-tight">
                    {project.name}
                  </span>
                )}

                <div className="mt-2 flex flex-col gap-0.5 md:gap-1">
                  <span className="text-[8px] md:text-[10px] font-mono text-white/20 tracking-tighter truncate">
                    {project.meta}
                  </span>
                  <div className="text-[8px] md:text-[9px] text-white/40 font-bold uppercase tracking-widest">
                    {formatRelativeTime(project.createdAt)}
                  </div>
                </div>
              </div>

              <div className="flex items-center gap-2 opacity-0 transition-opacity group-hover:opacity-100">
                <button
                  onClick={(event) => {
                    event.stopPropagation();
                    onStartRename(project);
                  }}
                  className="flex size-9 items-center justify-center rounded-2xl border border-white/10 bg-white/[0.03] text-white/40 transition-all hover:border-white/25 hover:text-white"
                  title="Rename"
                >
                  <Pencil size={14} />
                </button>
                <button
                  onClick={(event) => {
                    event.stopPropagation();
                    onRequestMoveToTrash([project.id]);
                  }}
                  className="flex size-9 items-center justify-center rounded-2xl border border-red-500/10 bg-red-500/5 text-red-400/70 transition-all hover:border-red-500/30 hover:bg-red-500/10 hover:text-red-300"
                  title="Delete"
                >
                  <Trash2 size={14} />
                </button>
              </div>
            </div>
          </motion.div>
        ))}

        {visibleProjects.length === 0 ? (
          <div className="rounded-[32px] border border-white/8 bg-white/[0.02] p-8 text-center">
            <div className="text-[10px] font-black uppercase tracking-[0.35em] text-white/20">
              Empty State
            </div>
            <div className="mt-4 text-sm font-bold text-white/70">
              {!projectsReady
                ? "Loading Projects"
                : activeProjectCount === 0
                  ? "No Projects Yet"
                  : "No Matching Projects"}
            </div>
          </div>
        ) : null}
      </div>

      <div className="p-6 rounded-3xl border border-white/5 bg-white/[0.01] shrink-0 mt-auto">
        <div className="flex justify-between items-end mb-4">
          <p className="text-[10px] font-black tracking-widest text-white/20 uppercase">Core Storage</p>
          <p className="text-[10px] font-mono text-white/40">42%</p>
        </div>
        <div className="h-1 w-full bg-white/5 rounded-full overflow-hidden">
          <div className="h-full w-[42%] bg-white/60" />
        </div>
      </div>
    </div>
  );
}
