import type { ProjectItem } from "../../types/project";

export type DashboardShellProps = {
  onOpenSettings: () => void;
  projects: ProjectItem[];
  projectsReady: boolean;
  onUploadVideo: (file: File) => void | Promise<ProjectItem | null>;
  onOpenProject: (projectId: string) => void;
  onRenameProject: (projectId: string, nextName: string) => void | Promise<void>;
  onMoveProjectsToTrash: (projectIds: string[]) => void | Promise<void>;
  onRestoreProjects: (projectIds: string[]) => void | Promise<void>;
  onDeleteProjectsForever: (projectIds: string[]) => void | Promise<void>;
};

export type SortMode = "newest" | "oldest" | "name-asc" | "name-desc";
export type BrowserModalMode = "projects" | "trash" | null;
export type ThumbnailRatioMode = "auto" | "21:9" | "16:9" | "4:3" | "1:1" | "9:16" | "custom";
export type BrowserDensityMode = "comfortable" | "compact";
export type PendingProjectAction =
  | {
      kind: "trash" | "delete-forever";
      projectIds: string[];
      title: string;
      description: string;
      confirmLabel: string;
    }
  | null;
