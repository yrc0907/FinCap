# Dynamic Segment Generation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add Chapter 8 dynamic segment generation after Layer08 so fused boundary candidates become usable dynamic segments.

**Architecture:** Build a small backend service that converts ordered Layer08 boundaries into non-uniform segments, applies lightweight tail-first correction rules, validates legality, and exposes the result through FastAPI and the workspace UI. Keep the implementation rule-based and deterministic for speed.

**Tech Stack:** Python, FastAPI, unittest, React, TypeScript

---

### Task 1: Add failing dynamic-segment tests

**Files:**
- Create: `backend/tests/test_dynamic_segment_generation.py`

- [ ] Add a failing test for direct boundary-to-segment conversion.
- [ ] Add a failing test for short-tail merge behavior.
- [ ] Add a failing test for legality validation and summary stats.

### Task 2: Implement backend dynamic segment generation

**Files:**
- Create: `backend/services/dynamic_segment_generation.py`

- [ ] Implement boundary cleanup.
- [ ] Implement dynamic segment building.
- [ ] Implement tail-first short-segment correction.
- [ ] Implement legality validation and summary stats.
- [ ] Add required Chinese console logs.

### Task 3: Expose the stage through the backend

**Files:**
- Modify: `backend/api_models.py`
- Modify: `backend/app.py`

- [ ] Add request and response models for dynamic segment generation.
- [ ] Add the FastAPI endpoint after Layer08.

### Task 4: Integrate the workspace

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-config.ts`
- Modify: `frontend/src/components/workspace/workspace-control-panel.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`

- [ ] Add Layer08-derived request payload support.
- [ ] Add a Layer08+ stage run button.
- [ ] Show dynamic segment stats and segment rows.

### Task 5: Verify end to end

**Files:**
- No new files required

- [ ] Run the new backend test file.
- [ ] Run the full backend test suite.
- [ ] Run the sample video through Layer07, Layer08, and dynamic segment generation.
- [ ] Report segment count, time ranges, and shortest/longest durations.
