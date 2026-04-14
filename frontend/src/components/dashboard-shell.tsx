import { type ChangeEvent, type KeyboardEvent, useEffect, useRef, useState } from "react";
import { motion } from "framer-motion";
import { Activity, Command, Maximize2, Play, Settings, Upload } from "lucide-react";

import {
  AlertDialog,
  AlertDialogAction,
  AlertDialogCancel,
  AlertDialogContent,
  AlertDialogDescription,
  AlertDialogFooter,
  AlertDialogHeader,
  AlertDialogTitle,
} from "./ui/alert-dialog";
import { ProjectBrowserModal } from "./dashboard/project-browser-modal";
import { ProjectSidebar } from "./dashboard/project-sidebar";
import type {
  BrowserDensityMode,
  BrowserModalMode,
  DashboardShellProps,
  PendingProjectAction,
  SortMode,
  ThumbnailRatioMode,
} from "./dashboard/types";
import { sortProjects } from "./dashboard/utils";
import type { ProjectItem } from "../types/project";

export function DashboardShell({
  onOpenSettings,
  projects,
  projectsReady,
  onUploadVideo,
  onOpenProject,
  onRenameProject,
  onMoveProjectsToTrash,
  onRestoreProjects,
  onDeleteProjectsForever,
}: DashboardShellProps) {
  const [explorerWidth, setExplorerWidth] = useState(400);
  const [isResizing, setIsResizing] = useState(false);
  const [sortMode, setSortMode] = useState<SortMode>("newest");
  const [searchOpen, setSearchOpen] = useState(false);
  const [searchDraft, setSearchDraft] = useState("");
  const [searchQuery, setSearchQuery] = useState("");
  const [browserModalMode, setBrowserModalMode] = useState<BrowserModalMode>(null);
  const [modalSearchDraft, setModalSearchDraft] = useState("");
  const [trashSearchDraft, setTrashSearchDraft] = useState("");
  const [thumbnailRatioMode, setThumbnailRatioMode] = useState<ThumbnailRatioMode>("auto");
  const [customThumbnailRatio, setCustomThumbnailRatio] = useState("16:9");
  const [browserDensityMode, setBrowserDensityMode] = useState<BrowserDensityMode>("comfortable");
  const [editingProjectId, setEditingProjectId] = useState<string | null>(null);
  const [renameDraft, setRenameDraft] = useState("");
  const [pendingProjectAction, setPendingProjectAction] = useState<PendingProjectAction>(null);
  const containerRef = useRef<HTMLDivElement>(null);
  const fileInputRef = useRef<HTMLInputElement>(null);
  const renameInputRef = useRef<HTMLInputElement>(null);

  useEffect(() => {
    const timer = window.setTimeout(() => {
      setSearchQuery(searchDraft.trim().toLowerCase());
    }, 320);

    return () => {
      window.clearTimeout(timer);
    };
  }, [searchDraft]);

  useEffect(() => {
    if (editingProjectId) {
      renameInputRef.current?.focus();
      renameInputRef.current?.select();
    }
  }, [editingProjectId]);

  useEffect(() => {
    const resize = (event: MouseEvent) => {
      if (isResizing && containerRef.current) {
        const containerWidth = containerRef.current.offsetWidth;
        const newWidth = containerWidth - (event.clientX - containerRef.current.offsetLeft);
        const maxWidth = Math.max(320, containerWidth - 400);

        if (newWidth >= 320 && newWidth <= maxWidth) {
          setExplorerWidth(newWidth);
        } else if (newWidth < 320) {
          setExplorerWidth(320);
        } else if (newWidth > maxWidth) {
          setExplorerWidth(maxWidth);
        }
      }
    };

    const stopResizing = () => {
      setIsResizing(false);
    };

    window.addEventListener("mousemove", resize);
    window.addEventListener("mouseup", stopResizing);

    return () => {
      window.removeEventListener("mousemove", resize);
      window.removeEventListener("mouseup", stopResizing);
    };
  }, [isResizing]);

  const isMobileLayout = typeof window !== "undefined" && window.innerWidth < 768;
  const activeProjects = projects.filter((project) => project.deletedAt === null);
  const trashedProjects = projects
    .filter((project) => project.deletedAt !== null)
    .sort((a, b) => (b.deletedAt ?? 0) - (a.deletedAt ?? 0));
  const sortedProjects = sortProjects(activeProjects, sortMode);
  const visibleProjects = searchQuery
    ? sortedProjects.filter((project) => `${project.name} ${project.meta}`.toLowerCase().includes(searchQuery))
    : sortedProjects;

  const startRename = (project: ProjectItem) => {
    setEditingProjectId(project.id);
    setRenameDraft(project.name);
  };

  const commitRename = (projectId: string) => {
    if (!renameDraft.trim()) {
      setEditingProjectId(null);
      setRenameDraft("");
      return;
    }

    onRenameProject(projectId, renameDraft);
    setEditingProjectId(null);
    setRenameDraft("");
  };

  const cancelRename = () => {
    setEditingProjectId(null);
    setRenameDraft("");
  };

  const handleRenameKeyDown = (event: KeyboardEvent<HTMLInputElement>, projectId: string) => {
    if (event.key === "Enter") {
      event.preventDefault();
      commitRename(projectId);
    }

    if (event.key === "Escape") {
      event.preventDefault();
      cancelRename();
    }
  };

  const openFilePicker = () => {
    fileInputRef.current?.click();
  };

  const handleFileChange = (event: ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];

    if (!file) {
      return;
    }

    void onUploadVideo(file);
    event.target.value = "";
  };

  const openBrowserModal = (mode: Exclude<BrowserModalMode, null>) => {
    setBrowserModalMode(mode);

    if (mode === "projects") {
      setModalSearchDraft("");
    } else {
      setTrashSearchDraft("");
    }
  };

  const toggleSearch = () => {
    setSearchOpen((prev) => !prev);

    if (searchOpen) {
      setSearchDraft("");
    }
  };

  const closeSearch = () => {
    setSearchOpen(false);
    setSearchDraft("");
  };

  const requestMoveToTrash = (projectIds: string[]) => {
    if (projectIds.length === 0) {
      return;
    }

    setPendingProjectAction({
      kind: "trash",
      projectIds,
      title: projectIds.length === 1 ? "Move To Trash" : "Move Selected To Trash",
      description:
        projectIds.length === 1
          ? "Are you sure you want to move this project to the trash?"
          : `Are you sure you want to move ${projectIds.length} projects to the trash?`,
      confirmLabel: "Confirm",
    });
  };

  const requestDeleteForever = (projectIds: string[]) => {
    if (projectIds.length === 0) {
      return;
    }

    setPendingProjectAction({
      kind: "delete-forever",
      projectIds,
      title: projectIds.length === 1 ? "Delete Forever" : "Delete Selected Forever",
      description:
        projectIds.length === 1
          ? "This project will be permanently deleted."
          : `${projectIds.length} projects will be permanently deleted.`,
      confirmLabel: "Delete",
    });
  };

  const confirmPendingProjectAction = async () => {
    if (!pendingProjectAction) {
      return;
    }

    const nextAction = pendingProjectAction;
    setPendingProjectAction(null);

    if (nextAction.kind === "trash") {
      await onMoveProjectsToTrash(nextAction.projectIds);
      return;
    }

    await onDeleteProjectsForever(nextAction.projectIds);
  };

  return (
    <div
      className="h-screen w-screen bg-black text-white flex flex-col p-6 md:p-10 font-sans relative overflow-hidden select-none"
      ref={containerRef}
    >
      <div className="absolute inset-0 fincap-gradient pointer-events-none" />

      <nav className="flex items-center justify-between mb-8 md:mb-16 relative z-20 shrink-0">
        <div className="flex items-center gap-3 md:gap-5">
          <div className="w-9 h-9 md:w-11 md:h-11 bg-white flex items-center justify-center rounded-xl md:rounded-2xl shadow-[0_0_30px_rgba(255,255,255,0.1)]">
            <Command size={18} className="text-black md:hidden" />
            <Command size={22} className="text-black hidden md:block" />
          </div>
          <span className="text-2xl md:text-3xl font-black tracking-[-0.05em] uppercase">FinCap</span>
        </div>

        <div className="flex items-center gap-3">
          <div className="hidden sm:flex items-center gap-2 px-4 py-2 rounded-xl bg-white/[0.03] border border-white/10 text-[10px] font-mono text-white/40">
            <Activity size={12} />
            STABLE
          </div>
          <button
            onClick={onOpenSettings}
            className="w-9 h-9 md:w-11 md:h-11 flex items-center justify-center hover:bg-white/10 rounded-xl md:rounded-2xl transition-all border border-white/5"
          >
            <Settings size={18} className="text-white/40 hover:text-white md:hidden" />
            <Settings size={22} className="text-white/40 hover:text-white hidden md:block" />
          </button>
        </div>
      </nav>

      <main className="flex-1 flex flex-col md:flex-row gap-0 relative z-10 min-h-0">
        <div className="flex-1 flex flex-col min-h-0 md:pr-12 mb-8 md:mb-0">
          <motion.div
            className="flex-1 glass rounded-3xl md:rounded-[48px] relative group overflow-hidden video-glow border-white/[0.03]"
            initial={{ opacity: 0, scale: 0.98 }}
            animate={{ opacity: 1, scale: 1 }}
            transition={{ duration: 0.8, ease: [0.16, 1, 0.3, 1] }}
          >
            <div className="scan-line pointer-events-none" />

            <div className="absolute inset-0 flex flex-col items-center justify-center p-4">
              <motion.button
                onClick={openFilePicker}
                whileHover={{ scale: 1.05 }}
                whileTap={{ scale: 0.95 }}
                className="flex flex-col items-center gap-6 md:gap-8 group/btn relative"
              >
                <div className="absolute -inset-10 bg-white/5 rounded-full blur-3xl opacity-0 group-hover/btn:opacity-100 transition-opacity duration-700" />

                <div className="w-16 h-16 md:w-24 md:h-24 rounded-2xl md:rounded-[36px] bg-white text-black flex items-center justify-center shadow-[0_0_40px_rgba(255,255,255,0.2)] group-hover/btn:shadow-[0_0_100px_rgba(255,255,255,0.5)] group-hover/btn:rotate-12 transition-all duration-1000 ease-[0.16,1,0.3,1] relative z-10">
                  <Upload size={24} strokeWidth={2.5} className="md:hidden" />
                  <Upload
                    size={32}
                    strokeWidth={2.5}
                    className="hidden md:block group-hover/btn:scale-125 transition-transform duration-500"
                  />
                </div>
                <div className="text-center space-y-2 md:space-y-3 relative z-10">
                  <h2 className="text-lg md:text-xl font-black tracking-[-0.02em] uppercase group-hover/btn:tracking-[0.1em] transition-all duration-700">
                    Initialize Project
                  </h2>
                  <p className="text-[8px] md:text-[10px] font-mono text-white/20 tracking-[0.3em] uppercase">
                    Drop RAW Footage
                  </p>
                </div>
              </motion.button>
            </div>

            <div className="absolute top-6 left-6 md:top-10 md:left-10 flex flex-col gap-3 md:gap-4">
              <div className="flex gap-2 md:gap-3">
                <div className="px-3 py-1.5 md:px-4 md:py-2 bg-white text-black rounded-lg md:rounded-xl text-[8px] md:text-[10px] font-black tracking-widest uppercase">
                  Idle
                </div>
                <div className="px-3 py-1.5 md:px-4 md:py-2 bg-white/5 backdrop-blur-md border border-white/10 rounded-lg md:rounded-xl text-[8px] md:text-[10px] font-mono text-white/30 tracking-tight">
                  00:00:00:00
                </div>
              </div>
            </div>

            <div className="absolute bottom-8 left-8 right-8 flex items-center justify-between">
              <div className="hidden sm:flex gap-4">
                <div className="flex flex-col">
                  <span className="text-[8px] md:text-[9px] font-black text-white/10 uppercase tracking-widest">
                    Resolution
                  </span>
                  <span className="text-[10px] md:text-xs font-bold text-white/40">----</span>
                </div>
              </div>

              <div className="flex items-center gap-3 md:gap-5">
                <button className="w-10 h-10 md:w-14 md:h-14 rounded-xl md:rounded-2xl bg-white/5 hover:bg-white/10 flex items-center justify-center backdrop-blur-md border border-white/10 transition-all group/play">
                  <Play size={20} className="text-white/20 group-hover/play:text-white fill-current transition-colors" />
                </button>
                <button className="w-10 h-10 md:w-14 md:h-14 rounded-xl md:rounded-2xl bg-white/5 hover:bg-white/10 flex items-center justify-center backdrop-blur-md border border-white/10 transition-all group/max">
                  <Maximize2 size={18} className="text-white/20 group-hover/max:text-white transition-colors" />
                </button>
              </div>
            </div>
          </motion.div>
        </div>

        <div
          className="hidden md:flex relative w-12 group/handle cursor-col-resize z-30 items-center justify-center -mx-6 transition-all"
          onMouseDown={() => setIsResizing(true)}
        >
          <div
            className={`w-[1px] h-[60%] transition-all duration-300 ${
              isResizing
                ? "bg-white h-full shadow-[0_0_20px_rgba(255,255,255,0.8)]"
                : "bg-white/10 group-hover/handle:bg-white/40 group-hover/handle:h-[80%]"
            }`}
          />
          <div
            className={`absolute w-1.5 h-12 bg-white rounded-full transition-all duration-500 opacity-0 group-hover/handle:opacity-100 ${
              isResizing ? "scale-y-150 h-24" : "scale-y-100"
            }`}
          />
          <div className="absolute -top-6 text-[8px] font-black tracking-widest text-white/0 group-hover/handle:text-white/20 transition-all uppercase whitespace-nowrap">
            Resize_Engine
          </div>
        </div>

        <ProjectSidebar
          explorerWidth={explorerWidth}
          isMobileLayout={isMobileLayout}
          searchOpen={searchOpen}
          searchDraft={searchDraft}
          searchQuery={searchQuery}
          sortMode={sortMode}
          visibleProjects={visibleProjects}
          activeProjectCount={activeProjects.length}
          trashedProjectsCount={trashedProjects.length}
          projectsReady={projectsReady}
          editingProjectId={editingProjectId}
          renameDraft={renameDraft}
          renameInputRef={renameInputRef}
          onSearchToggle={toggleSearch}
          onSearchDraftChange={setSearchDraft}
          onSearchClose={closeSearch}
          onSortModeChange={setSortMode}
          onOpenBrowserModal={openBrowserModal}
          onOpenProject={onOpenProject}
          onStartRename={startRename}
          onRenameDraftChange={setRenameDraft}
          onCommitRename={commitRename}
          onHandleRenameKeyDown={handleRenameKeyDown}
          onRequestMoveToTrash={requestMoveToTrash}
        />
      </main>

      <footer className="mt-12 flex items-center justify-between px-2 shrink-0">
        <div className="flex items-center gap-8 text-[10px] text-white/20 tracking-[0.3em] uppercase font-black">
          <div className="flex items-center gap-2.5">
            <div className="w-2 h-2 rounded-full bg-white" />
            Core_Online
          </div>
          <div className="flex items-center gap-2.5">
            <div className="w-2 h-2 rounded-full border border-white/20" />
            Neural_Engine_Wait
          </div>
        </div>

        <div className="text-[10px] font-mono text-white/10 tracking-widest uppercase">
          FinCap_OS // Build_2026.04.13
        </div>
      </footer>

      <input
        ref={fileInputRef}
        type="file"
        accept="video/*"
        className="hidden"
        onChange={handleFileChange}
      />

      <ProjectBrowserModal
        open={browserModalMode === "projects"}
        mode="projects"
        title="Projects"
        description="All active projects"
        projects={sortedProjects}
        searchDraft={modalSearchDraft}
        setSearchDraft={setModalSearchDraft}
        onClose={() => setBrowserModalMode(null)}
        emptyLabel="No Projects"
        ratioMode={thumbnailRatioMode}
        setRatioMode={setThumbnailRatioMode}
        customRatio={customThumbnailRatio}
        setCustomRatio={setCustomThumbnailRatio}
        densityMode={browserDensityMode}
        setDensityMode={setBrowserDensityMode}
        onOpenProject={onOpenProject}
        onStartRename={startRename}
        onRequestMoveToTrash={requestMoveToTrash}
      />

      <ProjectBrowserModal
        open={browserModalMode === "trash"}
        mode="trash"
        title="Trash"
        description="Deleted projects"
        projects={trashedProjects}
        searchDraft={trashSearchDraft}
        setSearchDraft={setTrashSearchDraft}
        onClose={() => setBrowserModalMode(null)}
        emptyLabel="Trash Is Empty"
        ratioMode={thumbnailRatioMode}
        setRatioMode={setThumbnailRatioMode}
        customRatio={customThumbnailRatio}
        setCustomRatio={setCustomThumbnailRatio}
        densityMode={browserDensityMode}
        setDensityMode={setBrowserDensityMode}
        onRestoreProjects={onRestoreProjects}
        onRequestDeleteForever={requestDeleteForever}
      />

      <AlertDialog
        open={pendingProjectAction !== null}
        onOpenChange={(open) => {
          if (!open) {
            setPendingProjectAction(null);
          }
        }}
      >
        <AlertDialogContent>
          <AlertDialogHeader>
            <AlertDialogTitle>{pendingProjectAction?.title ?? "Confirm Action"}</AlertDialogTitle>
            <AlertDialogDescription>{pendingProjectAction?.description ?? ""}</AlertDialogDescription>
          </AlertDialogHeader>
          <AlertDialogFooter>
            <AlertDialogCancel>Cancel</AlertDialogCancel>
            <AlertDialogAction onClick={() => void confirmPendingProjectAction()}>
              {pendingProjectAction?.confirmLabel ?? "Confirm"}
            </AlertDialogAction>
          </AlertDialogFooter>
        </AlertDialogContent>
      </AlertDialog>
    </div>
  );
}
