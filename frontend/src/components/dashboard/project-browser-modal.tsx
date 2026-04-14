import { useEffect, useState } from "react";
import { motion } from "framer-motion";
import { Check, FolderOpen, Pencil, RotateCcw, Search, Trash2, X } from "lucide-react";

import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "../ui/select";
import type { ProjectItem } from "../../types/project";
import type { BrowserDensityMode, BrowserModalMode, ThumbnailRatioMode } from "./types";
import { formatRelativeTime, resolveMinCardWidth, resolveRatioValue } from "./utils";

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

export function ProjectBrowserModal({
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
      current.includes(projectId) ? current.filter((id) => id !== projectId) : [...current, projectId],
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
