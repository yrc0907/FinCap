import { useEffect, useState } from "react";
import { Toaster, toast } from "sonner";

import { DashboardShell } from "./components/dashboard-shell";
import { ProjectWorkspace } from "./components/project-workspace";
import { SettingsModal } from "./components/settings-modal";
import {
  deleteProjectForeverRequest,
  fetchProjects,
  moveProjectToTrashRequest,
  renameProjectRequest,
  restoreProjectRequest,
  uploadProjectVideo,
} from "./lib/projects";
import { loadStoredSettings, persistSettings, withIdleStatus } from "./lib/settings";
import type { ProjectItem } from "./types/project";
import type { SystemConfig } from "./types/settings";
import "./index.css";

const cloneSettings = (settings: SystemConfig): SystemConfig =>
  JSON.parse(JSON.stringify(settings)) as SystemConfig;

function App() {
  const [showSettings, setShowSettings] = useState(false);
  const [settings, setSettings] = useState<SystemConfig>(() => loadStoredSettings());
  const [settingsSnapshot, setSettingsSnapshot] = useState<SystemConfig | null>(null);
  const [projects, setProjects] = useState<ProjectItem[]>([]);
  const [projectsReady, setProjectsReady] = useState(false);
  const [currentView, setCurrentView] = useState<"home" | "workspace">("home");
  const [activeProjectId, setActiveProjectId] = useState<string | null>(null);

  useEffect(() => {
    persistSettings(settings);
  }, [settings]);

  useEffect(() => {
    let active = true;

    const loadProjects = async () => {
      try {
        const nextProjects = await fetchProjects();

        if (!active) {
          return;
        }

        setProjects(nextProjects);
      } catch (error) {
        if (!active) {
          return;
        }

        const message = error instanceof Error ? error.message : "Unable to load projects.";
        toast.error(`Project load failed: ${message}`);
      } finally {
        if (active) {
          setProjectsReady(true);
        }
      }
    };

    void loadProjects();

    return () => {
      active = false;
    };
  }, []);

  const openSettings = () => {
    setSettingsSnapshot(cloneSettings(withIdleStatus(settings)));
    setShowSettings(true);
  };

  const closeSettings = () => {
    setShowSettings(false);
  };

  const applyConfiguration = () => {
    const sanitized = withIdleStatus(settings);
    setSettings(sanitized);
    persistSettings(sanitized);
    setSettingsSnapshot(cloneSettings(sanitized));
    toast.success("Settings saved.");
    closeSettings();
  };

  const discardChanges = () => {
    if (settingsSnapshot) {
      setSettings(settingsSnapshot);
      persistSettings(settingsSnapshot);
      toast.info("Changes discarded.");
    }

    closeSettings();
  };

  const uploadVideo = async (file: File) => {
    try {
      const nextProject = await uploadProjectVideo(file);
      setProjects((prev) => [nextProject, ...prev]);
      setActiveProjectId(nextProject.id);
      setCurrentView("workspace");
      toast.success("Project created.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unable to upload video.";
      toast.error(`Upload failed: ${message}`);
    }
  };

  const renameProject = async (projectId: string, nextName: string) => {
    try {
      const updatedProject = await renameProjectRequest(projectId, nextName.trim());
      setProjects((prev) =>
        prev.map((project) => (project.id === projectId ? updatedProject : project)),
      );
      toast.success("Project renamed.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unable to rename project.";
      toast.error(`Rename failed: ${message}`);
    }
  };

  const moveProjectsToTrash = async (projectIds: string[]) => {
    if (projectIds.length === 0) {
      return;
    }

    try {
      const updatedProjects = await Promise.all(
        projectIds.map((projectId) => moveProjectToTrashRequest(projectId)),
      );
      const updatedById = new Map(updatedProjects.map((project) => [project.id, project]));
      setProjects((prev) =>
        prev.map((project) => updatedById.get(project.id) ?? project),
      );
      toast.success(projectIds.length === 1 ? "Project moved to trash." : `${projectIds.length} projects moved to trash.`);
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unable to move project to trash.";
      toast.error(`Delete failed: ${message}`);
    }
  };

  const restoreProjects = async (projectIds: string[]) => {
    if (projectIds.length === 0) {
      return;
    }

    try {
      const updatedProjects = await Promise.all(projectIds.map((projectId) => restoreProjectRequest(projectId)));
      const updatedById = new Map(updatedProjects.map((project) => [project.id, project]));
      setProjects((prev) =>
        prev.map((project) => updatedById.get(project.id) ?? project),
      );
      toast.success(projectIds.length === 1 ? "Project restored." : `${projectIds.length} projects restored.`);
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unable to restore project.";
      toast.error(`Restore failed: ${message}`);
    }
  };

  const permanentlyDeleteProjects = async (projectIds: string[]) => {
    if (projectIds.length === 0) {
      return;
    }

    try {
      await Promise.all(projectIds.map((projectId) => deleteProjectForeverRequest(projectId)));
      const deletedIds = new Set(projectIds);
      setProjects((prev) => prev.filter((project) => !deletedIds.has(project.id)));
      toast.success(projectIds.length === 1 ? "Project deleted." : `${projectIds.length} projects deleted.`);
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unable to delete project.";
      toast.error(`Delete failed: ${message}`);
    }
  };

  const returnHome = () => {
    setCurrentView("home");
  };

  const openProject = (projectId: string) => {
    setActiveProjectId(projectId);
    setCurrentView("workspace");
  };

  const activeProject =
    activeProjectId === null ? null : projects.find((project) => project.id === activeProjectId) ?? null;

  return (
    <>
      <Toaster
        closeButton
        position="top-right"
        richColors
        theme="dark"
        toastOptions={{
          classNames: {
            toast: "border border-white/10 bg-[#090909] text-white",
            title: "text-sm font-semibold",
            description: "text-xs text-white/60",
          },
        }}
      />

      {currentView === "home" ? (
        <DashboardShell
          onOpenSettings={openSettings}
          projects={projects}
          projectsReady={projectsReady}
          onUploadVideo={uploadVideo}
          onOpenProject={openProject}
          onRenameProject={renameProject}
          onMoveProjectsToTrash={moveProjectsToTrash}
          onRestoreProjects={restoreProjects}
          onDeleteProjectsForever={permanentlyDeleteProjects}
        />
      ) : (
        <ProjectWorkspace project={activeProject} onBack={returnHome} settings={settings} />
      )}

      <SettingsModal
        open={showSettings}
        settings={settings}
        setSettings={setSettings}
        onApply={applyConfiguration}
        onClose={closeSettings}
        onDiscard={discardChanges}
      />
    </>
  );
}

export default App;
