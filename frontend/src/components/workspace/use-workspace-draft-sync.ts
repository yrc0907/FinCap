import { useCallback, useEffect, useRef, useState } from "react";
import { toast } from "sonner";

import {
  fetchWorkspaceClipOverrides,
  fetchWorkspaceFrameOverrides,
  fetchWorkspaceRuntimeState,
  fetchWorkspaceSemanticDraft,
  saveWorkspaceSemanticDraft,
  saveWorkspaceRuntimeState,
} from "../../lib/workspace-node-api";
import type { WorkspaceRuntimeState } from "./workspace-runtime-state";
import type {
  ClipRangeOverride,
  FrameOverride,
  VlmDraftPayload,
} from "../../types/workspace-drafts";
import {
  isWorkspaceRouteMissingError,
  WORKSPACE_ROUTE_MISSING_MESSAGE,
} from "./workspace-route-error";

type UseWorkspaceDraftSyncProps = {
  projectId: string | null;
  vlmPayload: VlmDraftPayload;
  runtimeState: WorkspaceRuntimeState;
  setVlmPayload: React.Dispatch<React.SetStateAction<VlmDraftPayload>>;
  setShotOverrides: React.Dispatch<React.SetStateAction<ClipRangeOverride[]>>;
  setFunctionalClipOverrides: React.Dispatch<React.SetStateAction<ClipRangeOverride[]>>;
  setFrameOverrides: React.Dispatch<React.SetStateAction<FrameOverride[]>>;
  applyRuntimeState: (runtimeState: WorkspaceRuntimeState | null) => void;
};

export function useWorkspaceDraftSync({
  projectId,
  vlmPayload,
  runtimeState,
  setVlmPayload,
  setShotOverrides,
  setFunctionalClipOverrides,
  setFrameOverrides,
  applyRuntimeState,
}: UseWorkspaceDraftSyncProps) {
  const [isWorkspaceDraftLoaded, setIsWorkspaceDraftLoaded] = useState(false);
  const [isWorkspaceApiAvailable, setIsWorkspaceApiAvailable] = useState(true);
  const semanticDraftSaveTimerRef = useRef<number | null>(null);
  const runtimeStateSaveTimerRef = useRef<number | null>(null);

  const handleWorkspaceApiError = useCallback((error: unknown, showToast = false) => {
    if (!isWorkspaceRouteMissingError(error)) {
      return false;
    }
    setIsWorkspaceApiAvailable(false);
    if (showToast) {
      toast.error(WORKSPACE_ROUTE_MISSING_MESSAGE);
    }
    return true;
  }, []);

  const ensureWorkspaceApiAvailable = useCallback(() => {
    if (isWorkspaceApiAvailable) {
      return true;
    }
    toast.error(WORKSPACE_ROUTE_MISSING_MESSAGE);
    return false;
  }, [isWorkspaceApiAvailable]);

  useEffect(() => {
    setIsWorkspaceDraftLoaded(false);
    setIsWorkspaceApiAvailable(true);
  }, [projectId]);

  useEffect(() => {
    if (!projectId) {
      return;
    }
    let active = true;
    void Promise.all([
      fetchWorkspaceSemanticDraft(projectId),
      fetchWorkspaceClipOverrides(projectId, "shots"),
      fetchWorkspaceClipOverrides(projectId, "functional-clips"),
      fetchWorkspaceFrameOverrides(projectId),
      fetchWorkspaceRuntimeState(projectId),
    ])
      .then(
        ([
          semanticDraft,
          savedShotOverrides,
          savedFunctionalOverrides,
          savedFrameOverrides,
          savedRuntimeState,
        ]) => {
        if (!active) {
          return;
        }
        if (semanticDraft.vlmPayload) {
          setVlmPayload((current) => ({ ...current, ...semanticDraft.vlmPayload }));
        }
        setShotOverrides(savedShotOverrides.items);
        setFunctionalClipOverrides(savedFunctionalOverrides.items);
        setFrameOverrides(savedFrameOverrides.items);
        applyRuntimeState(savedRuntimeState.runtimeState);
        setIsWorkspaceDraftLoaded(true);
        },
      )
      .catch((error) => {
        if (!active) {
          return;
        }
        if (handleWorkspaceApiError(error)) {
          setIsWorkspaceDraftLoaded(true);
          return;
        }
        const message = error instanceof Error ? error.message : "Unknown error.";
        toast.error(`Workspace draft load failed: ${message}`);
        setIsWorkspaceDraftLoaded(true);
      });

    return () => {
      active = false;
    };
  }, [
    handleWorkspaceApiError,
    projectId,
    setFrameOverrides,
    setFunctionalClipOverrides,
    setShotOverrides,
    setVlmPayload,
    applyRuntimeState,
  ]);

  useEffect(() => {
    if (!projectId || !isWorkspaceDraftLoaded || !isWorkspaceApiAvailable) {
      return;
    }
    if (semanticDraftSaveTimerRef.current !== null) {
      window.clearTimeout(semanticDraftSaveTimerRef.current);
    }
    semanticDraftSaveTimerRef.current = window.setTimeout(() => {
      void saveWorkspaceSemanticDraft(projectId, vlmPayload).catch((error) => {
        if (handleWorkspaceApiError(error)) {
          return;
        }
        const message = error instanceof Error ? error.message : "Unknown error.";
        toast.error(`Workspace draft save failed: ${message}`);
      });
    }, 400);
    return () => {
      if (semanticDraftSaveTimerRef.current !== null) {
        window.clearTimeout(semanticDraftSaveTimerRef.current);
        semanticDraftSaveTimerRef.current = null;
      }
    };
  }, [
    handleWorkspaceApiError,
    isWorkspaceApiAvailable,
    isWorkspaceDraftLoaded,
    projectId,
    vlmPayload,
  ]);

  useEffect(() => {
    if (!projectId || !isWorkspaceDraftLoaded || !isWorkspaceApiAvailable) {
      return;
    }
    if (runtimeStateSaveTimerRef.current !== null) {
      window.clearTimeout(runtimeStateSaveTimerRef.current);
    }
    runtimeStateSaveTimerRef.current = window.setTimeout(() => {
      void saveWorkspaceRuntimeState(projectId, runtimeState).catch((error) => {
        if (handleWorkspaceApiError(error)) {
          return;
        }
        const message = error instanceof Error ? error.message : "Unknown error.";
        toast.error(`Workspace state save failed: ${message}`);
      });
    }, 400);
    return () => {
      if (runtimeStateSaveTimerRef.current !== null) {
        window.clearTimeout(runtimeStateSaveTimerRef.current);
        runtimeStateSaveTimerRef.current = null;
      }
    };
  }, [
    handleWorkspaceApiError,
    isWorkspaceApiAvailable,
    isWorkspaceDraftLoaded,
    projectId,
    runtimeState,
  ]);

  return {
    isWorkspaceDraftLoaded,
    isWorkspaceApiAvailable,
    ensureWorkspaceApiAvailable,
    handleWorkspaceApiError,
  };
}
