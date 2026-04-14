import { type ChangeEvent, type KeyboardEvent, useEffect, useRef, useState } from "react";
import { AnimatePresence, motion } from "framer-motion";
import {
  Activity,
  ArrowDownUp,
  Check,
  Command,
  FolderOpen,
  Maximize2,
  Pencil,
  Play,
  RotateCcw,
  Search,
  Settings,
  Trash2,
  Upload,
  X,
} from "lucide-react";

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
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuLabel,
  DropdownMenuRadioGroup,
  DropdownMenuRadioItem,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from "./ui/dropdown-menu";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "./ui/select";
import type { ProjectItem } from "../types/project";

type DashboardShellProps = {
  onOpenSettings: () => void;
  projects: ProjectItem[];
  projectsReady: boolean;
  onUploadVideo: (file: File) => void | Promise<void>;
  onOpenProject: (projectId: string) => void;
  onRenameProject: (projectId: string, nextName: string) => void | Promise<void>;
  onMoveProjectsToTrash: (projectIds: string[]) => void | Promise<void>;
  onRestoreProjects: (projectIds: string[]) => void | Promise<void>;
  onDeleteProjectsForever: (projectIds: string[]) => void | Promise<void>;
};

type SortMode = "newest" | "oldest" | "name-asc" | "name-desc";
type BrowserModalMode = "projects" | "trash" | null;
type ThumbnailRatioMode = "auto" | "21:9" | "16:9" | "4:3" | "1:1" | "9:16" | "custom";
type BrowserDensityMode = "comfortable" | "compact";
type PendingProjectAction =
  | {
      kind: "trash" | "delete-forever";
      projectIds: string[];
      title: string;
      description: string;
      confirmLabel: string;
    }
  | null;

const iconButtonClass =
  "flex size-10 items-center justify-center rounded-2xl border border-white/10 bg-white/[0.03] text-white/30 transition-all hover:border-white/25 hover:text-white";

const formatRelativeTime = (timestamp: number) => {
  const diff = Date.now() - timestamp;
  const minute = 60 * 1000;
  const hour = 60 * minute;
  const day = 24 * hour;

  if (diff < minute) {
    return "Now";
  }

  if (diff < hour) {
    return `${Math.max(1, Math.round(diff / minute))}m ago`;
  }

  if (diff < day) {
    return `${Math.max(1, Math.round(diff / hour))}h ago`;
  }

  if (diff < day * 2) {
    return "Yesterday";
  }

  return `${Math.max(2, Math.round(diff / day))}d ago`;
};

const sortProjects = (projects: ProjectItem[], sortMode: SortMode) => {
  const nextProjects = [...projects];

  nextProjects.sort((a, b) => {
    switch (sortMode) {
      case "oldest":
        return a.createdAt - b.createdAt;
      case "name-asc":
        return a.name.localeCompare(b.name);
      case "name-desc":
        return b.name.localeCompare(a.name);
      case "newest":
      default:
        return b.createdAt - a.createdAt;
    }
  });

  return nextProjects;
};

const resolveRatioValue = (ratioMode: ThumbnailRatioMode, customRatio: string) => {
  if (ratioMode === "custom") {
    const match = customRatio.trim().match(/^(\d+(?:\.\d+)?)\s*[:/]\s*(\d+(?:\.\d+)?)$/);

    if (!match) {
      return 16 / 9;
    }

    const width = Number(match[1]);
    const height = Number(match[2]);

    if (!Number.isFinite(width) || !Number.isFinite(height) || width <= 0 || height <= 0) {
      return 16 / 9;
    }

    return width / height;
  }

  if (ratioMode === "auto") {
    return 16 / 9;
  }

  const [width, height] = ratioMode.split(":").map(Number);
  return width / height;
};

const resolveMinCardWidth = (ratio: number, densityMode: BrowserDensityMode) => {
  let baseWidth = 320;

  if (ratio >= 2.1) {
    baseWidth = 170;
  } else if (ratio >= 1.7) {
    baseWidth = 205;
  } else if (ratio >= 1.3) {
    baseWidth = 235;
  } else if (ratio >= 0.95) {
    baseWidth = 265;
  }

  return densityMode === "compact" ? Math.max(150, baseWidth - 36) : baseWidth;
};

type ProjectBrowserModalProps = {
  open: boolean;
  mode: Exclude<BrowserModalMode, null>;
  title: string;
  description: string;
  projects: ProjectItem[];
  searchDraft: string;
  setSearchDraft: (value: string) => void;
  onClose: () => void;
  emptyLabel: string;
  ratioMode: ThumbnailRatioMode;
  setRatioMode: (value: ThumbnailRatioMode) => void;
  customRatio: string;
  setCustomRatio: (value: string) => void;
  densityMode: BrowserDensityMode;
  setDensityMode: (value: BrowserDensityMode) => void;
  onOpenProject?: (projectId: string) => void;
  onStartRename?: (project: ProjectItem) => void;
  onRequestMoveToTrash?: (projectIds: string[]) => void;
  onRestoreProjects?: (projectIds: string[]) => void | Promise<void>;
  onRequestDeleteForever?: (projectIds: string[]) => void;
};

function ProjectBrowserModal({
  open,
  mode,
  title,
  description,
  projects,
  searchDraft,
  setSearchDraft,
  onClose,
  emptyLabel,
  ratioMode,
  setRatioMode,
  customRatio,
  setCustomRatio,
  densityMode,
  setDensityMode,
  onOpenProject,
  onStartRename,
  onRequestMoveToTrash,
  onRestoreProjects,
  onRequestDeleteForever,
}: ProjectBrowserModalProps) {
  const [selectedProjectIds, setSelectedProjectIds] = useState<string[]>([]);
  const normalizedQuery = searchDraft.trim().toLowerCase();
  const visibleProjects = normalizedQuery
    ? projects.filter((project) => `${project.name} ${project.meta}`.toLowerCase().includes(normalizedQuery))
    : projects;
  const ratio = resolveRatioValue(ratioMode, customRatio);
  const minCardWidth = resolveMinCardWidth(ratio, densityMode);
  const visibleProjectIds = visibleProjects.map((project) => project.id);
  const selectedVisibleIds = visibleProjectIds.filter((projectId) => selectedProjectIds.includes(projectId));
  const allVisibleSelected = visibleProjectIds.length > 0 && selectedVisibleIds.length === visibleProjectIds.length;
  const ModalIcon = mode === "trash" ? Trash2 : FolderOpen;

  useEffect(() => {
    if (!open) {
      setSelectedProjectIds([]);
    }
  }, [open, mode]);

  useEffect(() => {
    setSelectedProjectIds((current) =>
      current.filter((projectId) => projects.some((project) => project.id === projectId)),
    );
  }, [projects]);

  if (!open) {
    return null;
  }

  const toggleProjectSelection = (projectId: string) => {
    setSelectedProjectIds((current) =>
      current.includes(projectId)
        ? current.filter((id) => id !== projectId)
        : [...current, projectId],
    );
  };

  const toggleSelectAllVisible = () => {
    if (allVisibleSelected) {
      setSelectedProjectIds((current) => current.filter((projectId) => !visibleProjectIds.includes(projectId)));
      return;
    }

    setSelectedProjectIds((current) => Array.from(new Set([...current, ...visibleProjectIds])));
  };

  return (
    <motion.div
      initial={{ opacity: 0, backdropFilter: "blur(0px)" }}
      animate={{ opacity: 1, backdropFilter: "blur(20px)" }}
      className="fixed inset-0 z-[110] flex items-center justify-center bg-black/60 p-4 md:p-10"
      onClick={(event) => {
        if (event.target === event.currentTarget) {
          onClose();
        }
      }}
    >
      <motion.div
        initial={{ scale: 0.92, opacity: 0, y: 20 }}
        animate={{ scale: 1, opacity: 1, y: 0 }}
        className="flex max-h-[90vh] w-full max-w-6xl flex-col overflow-hidden rounded-[32px] border border-white/10 bg-[#0a0a0a] shadow-[0_0_100px_rgba(0,0,0,1)] md:rounded-[48px]"
      >
        <div className="flex items-center justify-between border-b border-white/5 p-8 md:p-12">
          <div className="flex items-center gap-4">
            <div className="flex h-12 w-12 items-center justify-center rounded-2xl bg-white/5">
              <ModalIcon size={24} className="text-white/40" />
            </div>
            <div>
              <h2 className="text-2xl font-black uppercase tracking-tight">{title}</h2>
              <p className="mt-2 text-[10px] font-mono uppercase tracking-[0.32em] text-white/25">
                {description}
              </p>
            </div>
          </div>
          <button
            onClick={onClose}
            className="group flex h-12 w-12 items-center justify-center rounded-2xl bg-white/5 transition-all hover:bg-white/10"
          >
            <X size={22} className="text-white/25 transition-colors group-hover:text-white" />
          </button>
        </div>

        <div className="flex-1 overflow-y-auto p-8 md:p-12">
          <div className="mb-8 flex flex-col gap-4 xl:flex-row xl:items-center">
            <div className="relative flex-1">
              <Search
                size={16}
                className="pointer-events-none absolute top-1/2 left-5 -translate-y-1/2 text-white/25"
              />
              <input
                type="text"
                value={searchDraft}
                onChange={(event) => setSearchDraft(event.target.value)}
                placeholder="Search projects"
                className="w-full rounded-2xl border border-white/10 bg-white/[0.03] py-4 pr-5 pl-12 text-sm text-white outline-none transition-colors placeholder:text-white/20 focus:border-white/30"
              />
            </div>

            <div className="flex flex-col gap-4 md:flex-row xl:items-center">
              <div className="min-w-[180px]">
                <Select value={ratioMode} onValueChange={(value) => setRatioMode(value as ThumbnailRatioMode)}>
                  <SelectTrigger>
                    <SelectValue placeholder="Thumb Ratio" />
                  </SelectTrigger>
                  <SelectContent>
                    <SelectItem value="auto">Auto Ratio</SelectItem>
                    <SelectItem value="21:9">21:9</SelectItem>
                    <SelectItem value="16:9">16:9</SelectItem>
                    <SelectItem value="4:3">4:3</SelectItem>
                    <SelectItem value="1:1">1:1</SelectItem>
                    <SelectItem value="9:16">9:16</SelectItem>
                    <SelectItem value="custom">Custom</SelectItem>
                  </SelectContent>
                </Select>
              </div>

              {ratioMode === "custom" ? (
                <input
                  type="text"
                  value={customRatio}
                  onChange={(event) => setCustomRatio(event.target.value)}
                  placeholder="16:9"
                  className="w-full rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-sm text-white outline-none transition-colors placeholder:text-white/20 focus:border-white/30 md:w-32"
                />
              ) : null}

              <div className="min-w-[180px]">
                <Select value={densityMode} onValueChange={(value) => setDensityMode(value as BrowserDensityMode)}>
                  <SelectTrigger>
                    <SelectValue placeholder="View Density" />
                  </SelectTrigger>
                  <SelectContent>
                    <SelectItem value="comfortable">Comfortable</SelectItem>
                    <SelectItem value="compact">Compact</SelectItem>
                  </SelectContent>
                </Select>
              </div>

              <div className="rounded-2xl border border-white/10 bg-white/[0.03] px-5 py-4 text-[10px] font-mono uppercase tracking-[0.26em] text-white/30">
                {visibleProjects.length} Items
              </div>
            </div>
          </div>

          <div className="mb-8 flex flex-col gap-4 rounded-[28px] border border-white/8 bg-white/[0.025] p-5 md:flex-row md:items-center md:justify-between">
            <div className="flex flex-wrap items-center gap-3">
              <div className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.24em] text-white/65">
                {selectedProjectIds.length} Selected
              </div>
              <div className="rounded-2xl border border-white/8 bg-white/[0.02] px-4 py-3 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
                Ratio {ratioMode === "custom" ? customRatio || "16:9" : ratioMode}
              </div>
            </div>

            <div className="flex flex-wrap items-center gap-3">
              <button
                onClick={toggleSelectAllVisible}
                className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.22em] text-white/70 transition-all hover:border-white/25 hover:text-white"
              >
                {allVisibleSelected ? "Clear Visible" : "Select Visible"}
              </button>

              <button
                onClick={() => setSelectedProjectIds([])}
                disabled={selectedProjectIds.length === 0}
                className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.22em] text-white/70 transition-all hover:border-white/25 hover:text-white disabled:cursor-not-allowed disabled:border-white/5 disabled:text-white/20"
              >
                Clear
              </button>

              {mode === "projects" ? (
                <button
                  onClick={() => onRequestMoveToTrash?.(selectedProjectIds)}
                  disabled={selectedProjectIds.length === 0}
                  className="rounded-2xl border border-red-500/20 bg-red-500/10 px-4 py-3 text-[10px] font-black uppercase tracking-[0.22em] text-red-300 transition-all hover:bg-red-500/20 disabled:cursor-not-allowed disabled:border-red-500/10 disabled:bg-red-500/5 disabled:text-red-300/30"
                >
                  Move To Trash
                </button>
              ) : (
                <>
                  <button
                    onClick={() => void onRestoreProjects?.(selectedProjectIds)}
                    disabled={selectedProjectIds.length === 0}
                    className="rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-[10px] font-black uppercase tracking-[0.22em] text-white/70 transition-all hover:border-white/25 hover:text-white disabled:cursor-not-allowed disabled:border-white/5 disabled:text-white/20"
                  >
                    Restore
                  </button>
                  <button
                    onClick={() => onRequestDeleteForever?.(selectedProjectIds)}
                    disabled={selectedProjectIds.length === 0}
                    className="rounded-2xl border border-red-500/20 bg-red-500/10 px-4 py-3 text-[10px] font-black uppercase tracking-[0.22em] text-red-300 transition-all hover:bg-red-500/20 disabled:cursor-not-allowed disabled:border-red-500/10 disabled:bg-red-500/5 disabled:text-red-300/30"
                  >
                    Delete Forever
                  </button>
                </>
              )}
            </div>
          </div>

          {visibleProjects.length === 0 ? (
            <div className="flex min-h-[320px] items-center justify-center rounded-[32px] border border-white/6 bg-white/[0.02] text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.35em] text-white/20">
                  Empty State
                </div>
                <div className="mt-4 text-base font-bold text-white/70">{emptyLabel}</div>
              </div>
            </div>
          ) : (
            <div
              className="grid gap-4"
              style={{
                gridTemplateColumns: `repeat(auto-fill, minmax(${minCardWidth}px, 1fr))`,
              }}
            >
              {visibleProjects.map((project) => {
                const isSelected = selectedProjectIds.includes(project.id);

                return (
                  <div
                    key={project.id}
                    role={mode === "projects" ? "link" : "button"}
                    tabIndex={0}
                    onClick={() => {
                      if (mode === "projects") {
                        onOpenProject?.(project.id);
                        onClose();
                        return;
                      }

                      toggleProjectSelection(project.id);
                    }}
                    onKeyDown={(event) => {
                      if (event.key === "Enter" || event.key === " ") {
                        event.preventDefault();

                        if (mode === "projects") {
                          onOpenProject?.(project.id);
                          onClose();
                          return;
                        }

                        toggleProjectSelection(project.id);
                      }
                    }}
                    className={`group overflow-hidden rounded-[28px] border text-left transition-all ${
                      isSelected
                        ? "border-white/30 bg-white/[0.06] shadow-[0_0_0_1px_rgba(255,255,255,0.08)]"
                        : "border-white/8 bg-white/[0.025] hover:border-white/18 hover:bg-white/[0.04]"
                    }`}
                  >
                    <div className="relative overflow-hidden bg-white/5" style={{ aspectRatio: `${ratio}` }}>
                      {project.isVideo && project.thumb ? (
                        <video
                          src={project.thumb}
                          muted
                          playsInline
                          preload="metadata"
                          className="h-full w-full object-cover opacity-90 transition-transform duration-500 group-hover:scale-[1.03]"
                        />
                      ) : (
                        <img
                          src={project.thumb}
                          alt=""
                          className="h-full w-full object-cover opacity-90 transition-transform duration-500 group-hover:scale-[1.03] group-hover:opacity-100"
                        />
                      )}
                      <div className="pointer-events-none absolute inset-0 bg-gradient-to-t from-black/70 via-black/10 to-transparent" />

                      <div className="absolute inset-x-0 top-0 flex items-start justify-between p-4">
                        <button
                          type="button"
                          onClick={(event) => {
                            event.stopPropagation();
                            toggleProjectSelection(project.id);
                          }}
                          className={`flex h-9 w-9 items-center justify-center rounded-2xl border backdrop-blur-md transition-all ${
                            isSelected
                              ? "border-white/30 bg-white text-black"
                              : "border-white/10 bg-black/40 text-white/40 group-hover:border-white/20 group-hover:text-white"
                          }`}
                        >
                          <Check size={14} />
                        </button>

                        <div className="flex items-center gap-2 opacity-0 transition-opacity duration-200 group-hover:opacity-100">
                          {mode === "projects" ? (
                            <>
                              <button
                                type="button"
                                onClick={(event) => {
                                  event.stopPropagation();
                                  onStartRename?.(project);
                                  onClose();
                                }}
                                className="flex h-9 items-center justify-center rounded-2xl border border-white/10 bg-black/40 px-3 text-white/70 backdrop-blur-md transition-all hover:border-white/25 hover:text-white"
                              >
                                <Pencil size={12} />
                              </button>
                              <button
                                type="button"
                                onClick={(event) => {
                                  event.stopPropagation();
                                  onRequestMoveToTrash?.([project.id]);
                                }}
                                className="flex h-9 items-center justify-center rounded-2xl border border-red-500/20 bg-red-500/15 px-3 text-red-200 backdrop-blur-md transition-all hover:bg-red-500/25"
                              >
                                <Trash2 size={12} />
                              </button>
                            </>
                          ) : (
                            <>
                              <button
                                type="button"
                                onClick={(event) => {
                                  event.stopPropagation();
                                  void onRestoreProjects?.([project.id]);
                                }}
                                className="flex h-9 items-center justify-center rounded-2xl border border-white/10 bg-black/40 px-3 text-white/70 backdrop-blur-md transition-all hover:border-white/25 hover:text-white"
                              >
                                <RotateCcw size={12} />
                              </button>
                              <button
                                type="button"
                                onClick={(event) => {
                                  event.stopPropagation();
                                  onRequestDeleteForever?.([project.id]);
                                }}
                                className="flex h-9 items-center justify-center rounded-2xl border border-red-500/20 bg-red-500/15 px-3 text-red-200 backdrop-blur-md transition-all hover:bg-red-500/25"
                              >
                                <Trash2 size={12} />
                              </button>
                            </>
                          )}
                        </div>
                      </div>
                    </div>

                    <div className="space-y-2 p-4 md:p-5">
                      <div>
                        <div className="truncate text-sm font-black tracking-tight text-white/85">{project.name}</div>
                        <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
                          {project.meta}
                        </div>
                      </div>

                      <div className="flex items-center gap-2 overflow-hidden text-[9px] font-mono uppercase tracking-[0.16em] text-white/24">
                        <span className="truncate">Created {formatRelativeTime(project.createdAt)}</span>
                        <span className="h-1 w-1 shrink-0 rounded-full bg-white/12" />
                        <span className="truncate">Updated {formatRelativeTime(project.updatedAt)}</span>
                      </div>
                    </div>
                  </div>
                );
              })}
            </div>
          )}
        </div>
      </motion.div>
    </motion.div>
  );
}

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
    ? sortedProjects.filter((project) => {
        const searchable = `${project.name} ${project.meta}`.toLowerCase();
        return searchable.includes(searchQuery);
      })
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
                <button className={iconButtonClass} title="All Projects" onClick={() => openBrowserModal("projects")}>
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
                    <DropdownMenuRadioGroup value={sortMode} onValueChange={(value) => setSortMode(value as SortMode)}>
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
                  onClick={() => {
                    setSearchOpen((prev) => !prev);
                    if (searchOpen) {
                      setSearchDraft("");
                    }
                  }}
                >
                  <Search size={16} />
                </button>

                <button
                  className={`${iconButtonClass} ${trashedProjects.length > 0 ? "text-white/70" : ""}`}
                  title="Trash"
                  onClick={() => openBrowserModal("trash")}
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
                      onChange={(event) => setSearchDraft(event.target.value)}
                      placeholder="Search projects"
                      className="w-full rounded-2xl border border-white/10 bg-white/[0.03] py-3 pr-12 pl-12 text-sm text-white outline-none transition-colors placeholder:text-white/20 focus:border-white/30"
                    />
                    <button
                      onClick={() => {
                        setSearchOpen(false);
                        setSearchDraft("");
                      }}
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
                        onChange={(event) => setRenameDraft(event.target.value)}
                        onBlur={() => commitRename(project.id)}
                        onKeyDown={(event) => handleRenameKeyDown(event, project.id)}
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
                        startRename(project);
                      }}
                      className="flex size-9 items-center justify-center rounded-2xl border border-white/10 bg-white/[0.03] text-white/40 transition-all hover:border-white/25 hover:text-white"
                      title="Rename"
                    >
                      <Pencil size={14} />
                    </button>
                    <button
                      onClick={(event) => {
                        event.stopPropagation();
                        requestMoveToTrash([project.id]);
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
                    : activeProjects.length === 0
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
