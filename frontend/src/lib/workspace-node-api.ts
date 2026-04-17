import type {
  WorkspaceRuntimeState,
  WorkspaceRuntimeStateResponse,
} from "../components/workspace/workspace-runtime-state";
import type {
  ClipRangeOverride,
  ClipRangeOverrideResponse,
  FrameOverride,
  FrameOverrideResponse,
  FunctionalClipExportRequestItem,
  FunctionalClipExportResult,
  SemanticDraftResponse,
  VlmDraftPayload,
} from "../types/workspace-drafts";
import { ensureBackendReady, resolveBackendUrl } from "./backend-runtime";

const buildApiUrl = (path: string) => `${resolveBackendUrl()}${path}`;

async function extractBackendError(response: Response) {
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
}

async function requestJson<T>(path: string, init?: RequestInit): Promise<T> {
  await ensureBackendReady();
  const response = await fetch(buildApiUrl(path), init);
  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }
  return (await response.json()) as T;
}

export const fetchWorkspaceSemanticDraft = (projectId: string) =>
  requestJson<SemanticDraftResponse>(`/api/projects/${projectId}/workspace/semantic-draft`);

export const saveWorkspaceSemanticDraft = (projectId: string, vlmPayload: VlmDraftPayload) =>
  requestJson<SemanticDraftResponse>(`/api/projects/${projectId}/workspace/semantic-draft`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(vlmPayload),
  });

export const fetchWorkspaceClipOverrides = (
  projectId: string,
  scope: "shots" | "functional-clips",
) =>
  requestJson<ClipRangeOverrideResponse>(
    `/api/projects/${projectId}/workspace/clip-overrides/${scope}`,
  );

export const saveWorkspaceClipOverrides = (
  projectId: string,
  scope: "shots" | "functional-clips",
  items: ClipRangeOverride[],
) =>
  requestJson<ClipRangeOverrideResponse>(
    `/api/projects/${projectId}/workspace/clip-overrides/${scope}`,
    {
      method: "PUT",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(items),
    },
  );

export const fetchWorkspaceFrameOverrides = (projectId: string) =>
  requestJson<FrameOverrideResponse>(`/api/projects/${projectId}/workspace/frame-overrides`);

export const saveWorkspaceFrameOverrides = (projectId: string, items: FrameOverride[]) =>
  requestJson<FrameOverrideResponse>(`/api/projects/${projectId}/workspace/frame-overrides`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(items),
  });

export const fetchWorkspaceRuntimeState = (projectId: string) =>
  requestJson<WorkspaceRuntimeStateResponse>(`/api/projects/${projectId}/workspace/runtime-state`);

export const saveWorkspaceRuntimeState = (
  projectId: string,
  runtimeState: WorkspaceRuntimeState,
) =>
  requestJson<WorkspaceRuntimeStateResponse>(`/api/projects/${projectId}/workspace/runtime-state`, {
    method: "PUT",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(runtimeState),
  });

export const exportFunctionalClips = (
  projectId: string,
  clips: FunctionalClipExportRequestItem[],
) =>
  requestJson<FunctionalClipExportResult>(
    `/api/projects/${projectId}/workspace/export-functional-clips`,
    {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ clips }),
    },
  );
