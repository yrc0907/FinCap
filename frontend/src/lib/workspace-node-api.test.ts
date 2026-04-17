import { afterEach, beforeEach, describe, expect, it, vi } from "vitest";

import {
  exportFunctionalClips,
  fetchWorkspaceSemanticDraft,
  fetchWorkspaceRuntimeState,
  saveWorkspaceClipOverrides,
  saveWorkspaceRuntimeState,
} from "./workspace-node-api";
import { buildInitialNodeFeedback } from "../components/workspace/workspace-node-feedback";

vi.mock("./backend-runtime", () => ({
  ensureBackendReady: vi.fn().mockResolvedValue(undefined),
  resolveBackendUrl: vi.fn().mockReturnValue("http://localhost:8000"),
}));

describe("workspace node api", () => {
  const fetchMock = vi.fn();

  beforeEach(() => {
    vi.stubGlobal("fetch", fetchMock);
  });

  afterEach(() => {
    vi.unstubAllGlobals();
    fetchMock.mockReset();
  });

  it("requests semantic draft from the workspace endpoint", async () => {
    fetchMock.mockResolvedValueOnce(
      new Response(JSON.stringify({ vlmPayload: null }), { status: 200 }),
    );

    await fetchWorkspaceSemanticDraft("project-1");

    expect(fetchMock).toHaveBeenCalledWith(
      "http://localhost:8000/api/projects/project-1/workspace/semantic-draft",
      undefined,
    );
  });

  it("saves scoped clip overrides", async () => {
    fetchMock.mockResolvedValueOnce(
      new Response(JSON.stringify({ scope: "shots", items: [] }), { status: 200 }),
    );

    await saveWorkspaceClipOverrides("project-1", "shots", [
      { key: "shot:1", startSec: 1.2, endSec: 2.4 },
    ]);

    expect(fetchMock).toHaveBeenCalledWith(
      "http://localhost:8000/api/projects/project-1/workspace/clip-overrides/shots",
      expect.objectContaining({
        method: "PUT",
        headers: { "Content-Type": "application/json" },
      }),
    );
  });

  it("requests runtime state from the workspace endpoint", async () => {
    fetchMock.mockResolvedValueOnce(
      new Response(JSON.stringify({ runtimeState: null }), { status: 200 }),
    );

    await fetchWorkspaceRuntimeState("project-1");

    expect(fetchMock).toHaveBeenCalledWith(
      "http://localhost:8000/api/projects/project-1/workspace/runtime-state",
      undefined,
    );
  });

  it("saves runtime state to the workspace endpoint", async () => {
    fetchMock.mockResolvedValueOnce(
      new Response(JSON.stringify({ runtimeState: { boundaryResult: null } }), {
        status: 200,
      }),
    );

    await saveWorkspaceRuntimeState("project-1", {
      processingMode: "standard",
      sceneDetectorMode: "transnetv2-cuda",
      multiscalePayload: {
        coarse_window_sec: 2,
        coarse_stride_sec: 0.5,
        coarse_score_threshold: 0.58,
        coarse_merge_gap_sec: 1.2,
        fine_search_radius_sec: 1,
        fine_sample_step_sec: 0.08,
        fine_score_threshold: 0.5,
      },
      boundaryPayload: {
        subject_sample_step_sec: 0.12,
        subject_core_ratio: 0.58,
        subject_score_threshold: 0.46,
        scene_sample_step_sec: 0.12,
        scene_score_threshold: 0.48,
        fusion_gap_sec: 0.35,
        fusion_high_confidence_score: 0.62,
      },
      strictShotPayload: {
        dedupe_epsilon_sec: 0.05,
        min_shot_sec: 0.15,
        abnormal_short_sec: 0.3,
      },
      multiscaleResult: null,
      boundaryResult: null,
      rawStrictShotResult: null,
      vlmShotAnalysisResult: null,
      adjacentStoryReassignmentResult: null,
      rawCorrectedEventTimelineResult: null,
      exportResult: null,
      nodeFeedback: buildInitialNodeFeedback(true),
    });

    expect(fetchMock).toHaveBeenCalledWith(
      "http://localhost:8000/api/projects/project-1/workspace/runtime-state",
      expect.objectContaining({
        method: "PUT",
        headers: { "Content-Type": "application/json" },
      }),
    );
  });

  it("posts functional clips to the export endpoint", async () => {
    fetchMock.mockResolvedValueOnce(
      new Response(
        JSON.stringify({
          projectId: "project-1",
          clipCount: 1,
          outputDir: "C:/exports",
          manifest: { video: "demo.mp4", clips: [] },
        }),
        { status: 200 },
      ),
    );

    await exportFunctionalClips("project-1", [
      {
        index: 1,
        type: "peak",
        startSec: 1,
        endSec: 2,
        durationSec: 1,
        reason: "demo",
        sourceShotIndexes: [1],
        sourceGroupIndexes: [1],
      },
    ]);

    expect(fetchMock).toHaveBeenCalledWith(
      "http://localhost:8000/api/projects/project-1/workspace/export-functional-clips",
      expect.objectContaining({
        method: "POST",
        headers: { "Content-Type": "application/json" },
      }),
    );
  });
});
