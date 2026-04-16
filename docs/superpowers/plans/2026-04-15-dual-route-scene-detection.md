# Dual Route Scene Detection Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add switchable `pyscenedetect` and `opencv-cuda` scene-detection routes to Layer 07 and Layer 08, expose the selector in the workspace UI, and keep logs/tests aligned.

**Architecture:** Create a shared scene candidate provider module used by both backend layers. Preserve `PySceneDetect` as one route, add an OpenCV CUDA replacement route as the second route, and thread a single `scene_detector_mode` value from the workspace UI through both API calls.

**Tech Stack:** Python, FastAPI, OpenCV CUDA, PySceneDetect, React, TypeScript, shadcn/ui, unittest

---

### Task 1: Add detector mode tests and a shared backend provider skeleton

**Files:**
- Create: `backend/tests/test_scene_candidate_detection.py`
- Create: `backend/services/scene_candidate_detection.py`

- [ ] Write failing backend tests for route selection, candidate filtering, and merge behavior.
- [ ] Run the new test file and verify failure due to missing shared provider behavior.
- [ ] Implement the shared provider skeleton with `pyscenedetect` and `opencv-cuda` route dispatch.
- [ ] Re-run the new test file until it passes.

### Task 2: Integrate the shared provider into Layer 07 and Layer 08

**Files:**
- Modify: `backend/services/multiscale_detection.py`
- Modify: `backend/services/dual_signal_boundary_detection.py`

- [ ] Add failing tests or extend existing backend tests to assert route metadata is used by both layers.
- [ ] Run focused backend tests and verify failure.
- [ ] Replace direct `PySceneDetect` calls with the shared provider in both layers.
- [ ] Add English-only logs for detector mode and candidate summary.
- [ ] Re-run the focused backend tests until they pass.

### Task 3: Thread the route through FastAPI request models

**Files:**
- Modify: `backend/app.py`

- [ ] Add failing tests for request parsing or handler defaults if needed.
- [ ] Add `scene_detector_mode` to both request models and pass it into Layer 07 and Layer 08 calls.
- [ ] Run backend tests to verify the new request field works.

### Task 4: Split workspace code and add the selector UI

**Files:**
- Modify: `frontend/src/components/project-workspace.tsx`
- Create: `frontend/src/components/workspace/project-workspace-header.tsx`
- Create: `frontend/src/components/workspace/workspace-processing-panel.tsx`
- Create: `frontend/src/components/workspace/workspace-results-panel.tsx`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/types/workspace.ts`

- [ ] Split the oversized workspace component into focused subcomponents before adding more behavior.
- [ ] Add a shadcn/ui selector for the scene detector route.
- [ ] Thread the selected route into both Layer 07 and Layer 08 requests.
- [ ] Keep copy short and styling consistent with the existing workspace.

### Task 5: Verify with tests and the sample video

**Files:**
- No new files required

- [ ] Run backend unit tests covering the new provider and API flow.
- [ ] Run frontend checks if available.
- [ ] Run the sample video through both routes and inspect console logs.
- [ ] Confirm the OpenCV route completes, logs its detector mode, and returns candidate output.

