import type { ProjectItem } from "../types/project";
import { ensureBackendReady, resolveBackendUrl } from "./backend-runtime";

const buildApiUrl = (path: string) => `${resolveBackendUrl()}${path}`;

const extractBackendError = async (response: Response) => {
  const fallback = `HTTP ${response.status}`;
  const text = await response.text();

  if (!text) {
    return fallback;
  }

  try {
    const parsed = JSON.parse(text) as { detail?: string; message?: string };
    return parsed.detail || parsed.message || fallback;
  } catch {
    return text.length > 160 ? `${text.slice(0, 157)}...` : text;
  }
};

export const fetchProjects = async () => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl("/api/projects"));

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  const data = (await response.json()) as { projects?: ProjectItem[] };
  return Array.isArray(data.projects) ? data.projects : [];
};

export const uploadProjectVideo = async (file: File) => {
  await ensureBackendReady();
  const formData = new FormData();
  formData.append("file", file);

  const response = await fetch(buildApiUrl("/api/projects/upload"), {
    method: "POST",
    body: formData,
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as ProjectItem;
};

export const renameProjectRequest = async (projectId: string, name: string) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}/rename`), {
    method: "PATCH",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({ name }),
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as ProjectItem;
};

export const moveProjectToTrashRequest = async (projectId: string) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}/trash`), {
    method: "POST",
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as ProjectItem;
};

export const restoreProjectRequest = async (projectId: string) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}/restore`), {
    method: "POST",
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return (await response.json()) as ProjectItem;
};

export const deleteProjectForeverRequest = async (projectId: string) => {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(`/api/projects/${projectId}`), {
    method: "DELETE",
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }
};
