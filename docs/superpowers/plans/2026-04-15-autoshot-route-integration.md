# AutoShot Route Integration Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add AutoShot as a new selectable Layer07 scene detector route while preserving the existing TransNetV2 route and keeping backend/frontend contracts aligned.

**Architecture:** Build a dedicated AutoShot runtime wrapper around the official model code in `third_party/AutoShot`, expose it through the shared scene candidate provider, and thread a new `autoshot-cuda` mode through the API and workspace selector. Extract FastAPI request models from `backend/app.py` so the main backend entrypoint stays under the 500-line file limit.

**Tech Stack:** Python, Torch CUDA, ffmpeg-python, FastAPI, React, TypeScript, unittest

---

### Task 1: Add failing tests for the new route

**Files:**
- Modify: `backend/tests/test_scene_candidate_detection.py`
- Modify: `backend/tests/test_scene_route_integration.py`

- [ ] Add a failing provider test proving `autoshot-cuda` returns the same unified candidate structure as other detector routes.
- [ ] Add a failing integration test proving Layer07 and Layer08 accept `autoshot-cuda` as a valid mode.
- [ ] Run the focused backend tests and confirm they fail for missing AutoShot support.

### Task 2: Build the AutoShot runtime wrapper

**Files:**
- Create: `backend/services/autoshot_runtime.py`
- Modify: `backend/services/scene_candidate_detection.py`
- Modify: `backend/requirements.txt`

- [ ] Implement lazy loading of the AutoShot model code from `third_party/AutoShot`.
- [ ] Add checkpoint discovery, CUDA device selection, frame batching, and prediction-to-cut conversion.
- [ ] Expose `autoshot-cuda` from the shared scene detector provider with unified metadata.

### Task 3: Thread the new mode through the app and workspace

**Files:**
- Create: `backend/api_models.py`
- Modify: `backend/app.py`
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/components/workspace/workspace-config.ts`

- [ ] Extract request models from `backend/app.py` into `backend/api_models.py`.
- [ ] Add `autoshot-cuda` to backend validation and frontend type/selector definitions.
- [ ] Keep all user-facing labels and code strings in English.

### Task 4: Verify and document runtime readiness

**Files:**
- No new files required

- [ ] Run the backend test suite.
- [ ] Run the frontend build.
- [ ] Report whether AutoShot is immediately runnable or still awaiting a local checkpoint file.
