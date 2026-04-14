import type { ProjectItem } from "../../types/project";
import type { BrowserDensityMode, SortMode, ThumbnailRatioMode } from "./types";

export const iconButtonClass =
  "flex size-10 items-center justify-center rounded-2xl border border-white/10 bg-white/[0.03] text-white/30 transition-all hover:border-white/25 hover:text-white";

export const formatRelativeTime = (timestamp: number) => {
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

export const sortProjects = (projects: ProjectItem[], sortMode: SortMode) => {
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

export const resolveRatioValue = (ratioMode: ThumbnailRatioMode, customRatio: string) => {
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

export const resolveMinCardWidth = (ratio: number, densityMode: BrowserDensityMode) => {
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
