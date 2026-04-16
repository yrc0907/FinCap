# Layer09 Narrative Boundary Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add Layer09 as a narrative-boundary refinement stage that uses Layer08 visual boundaries plus lightweight audio-change features to output narrative boundaries and narrative segments.

**Architecture:** Extract mono audio from the source video, compute lightweight audio features (energy, silence proxy, spectral flux), score each Layer08 boundary with visual plus audio evidence, then merge nearby accepted boundaries into coarser narrative segments. Expose the new stage through a backend service, FastAPI endpoint, and workspace UI section.

**Tech Stack:** Python, ffmpeg-python, NumPy, FastAPI, React, TypeScript, unittest

---

### Task 1: Write failing narrative-boundary tests

**Files:**
- Create: `backend/tests/test_narrative_boundary_detection.py`

- [ ] Add a failing test proving Layer09 keeps audio-supported boundaries and merges overly dense nearby cuts.
- [ ] Add a failing test proving Layer09 falls back to a visual-only narrative reduction path when audio extraction fails.
- [ ] Run the new test file and confirm failure for missing Layer09 implementation.

### Task 2: Implement lightweight audio feature extraction and Layer09 scoring

**Files:**
- Create: `backend/services/audio_change_detection.py`
- Create: `backend/services/narrative_boundary_detection.py`

- [ ] Extract mono audio frames and compute normalized energy, silence proxy, and spectral flux.
- [ ] Score Layer08 boundaries with visual plus audio evidence, merge close narrative boundaries, and build final narrative segments.
- [ ] Keep both new service files below 500 lines.

### Task 3: Expose Layer09 through the backend and workspace

**Files:**
- Modify: `backend/api_models.py`
- Modify: `backend/app.py`
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-control-panel.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`

- [ ] Add the Layer09 request/response models and FastAPI endpoint.
- [ ] Add a Layer09 run button in the workspace after Layer08.
- [ ] Show narrative boundary and segment output in the results panel.

### Task 4: Verify Layer09 end to end

**Files:**
- No new files required

- [ ] Run the new Layer09 tests.
- [ ] Run the full backend test suite.
- [ ] Run the frontend build.
- [ ] Run the sample video through Layer07, Layer08, and Layer09 to inspect logs and final narrative boundaries.
