# Layer08 Scene-First Fusion Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Rework Layer08 so strong Layer07 scene detector cuts remain the primary signal while subject and motion heuristics only refine or supplement final boundaries.

**Architecture:** Extract boundary fusion logic into a focused module, add tests that lock in scene-first behavior, and update Layer08 to preserve high-confidence scene detector candidates while still allowing subject-assisted additions inside suspicious windows.

**Tech Stack:** Python, FastAPI backend services, unittest, NumPy

---

### Task 1: Lock scene-first behavior with failing tests

**Files:**
- Modify: `backend/tests/test_scene_route_integration.py`

- [ ] Add a failing test proving a reused high-confidence scene detector candidate is kept even when the local scene score is weak.
- [ ] Add a failing test proving subject-only candidates can still survive when no strong scene detector candidate exists nearby.
- [ ] Run the targeted test file and verify the new assertions fail for the expected reason.

### Task 2: Extract fusion logic into a focused module

**Files:**
- Create: `backend/services/boundary_fusion.py`
- Modify: `backend/services/dual_signal_boundary_detection.py`

- [ ] Move boundary candidate normalization and fusion helpers into a dedicated module so the Layer08 service file stays below the 500-line limit.
- [ ] Introduce scene-first fusion rules that preserve high-confidence detector candidates and mark boundary origin metadata.
- [ ] Run the targeted test file again and verify the new fusion logic satisfies the scene-first behavior.

### Task 3: Verify integration and sample-video behavior

**Files:**
- No new files required

- [ ] Run `python -m unittest backend.tests.test_scene_route_integration backend.tests.test_scene_candidate_detection`.
- [ ] Run the backend test suite.
- [ ] Run the sample video through the selected route and inspect runtime plus boundary output for regressions.
