# Event Merging Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add Chapter 9 generic event merging after dynamic segment generation using boundary strength and segment continuity rules.

**Architecture:** Build a lightweight backend service that groups neighboring dynamic segments into event ranges based on boundary score, short-fragment detection, target event duration, and maximum event guardrails. Expose the result through FastAPI and the workspace UI.

**Tech Stack:** Python, FastAPI, unittest, React, TypeScript

---

### Task 1: Add failing event-merging tests

**Files:**
- Create: `backend/tests/test_event_merging.py`

- [ ] Add a failing test for merging short adjacent fragments under weak boundaries.
- [ ] Add a failing test for preserving strong boundaries when both sides are substantial.
- [ ] Add a failing test for maximum-event guardrails.

### Task 2: Implement backend event merging

**Files:**
- Create: `backend/services/event_merging.py`

- [ ] Implement boundary lookup from Layer08 output.
- [ ] Implement generic keep-vs-merge rules.
- [ ] Implement event summary stats and warnings.
- [ ] Add required Chinese logs.

### Task 3: Expose event merging through the backend

**Files:**
- Modify: `backend/api_models.py`
- Modify: `backend/app.py`

- [ ] Add request and response models for event merging.
- [ ] Add the FastAPI endpoint after Chapter 8 dynamic segments.

### Task 4: Integrate the workspace

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-config.ts`
- Modify: `frontend/src/components/workspace/workspace-control-panel.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`

- [ ] Add event-merging payload support.
- [ ] Add a Chapter 9 run button after dynamic segments.
- [ ] Show event ranges and summary stats.

### Task 5: Verify end to end

**Files:**
- No new files required

- [ ] Run the new backend event-merging test file.
- [ ] Run the full backend test suite.
- [ ] Run `pnpm build` for the frontend.
- [ ] Run the sample video through Layer07, Layer08, Chapter 8, and Chapter 9, then report event outputs.
