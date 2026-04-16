# Dual Functional Segmentation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add two separate functional clip extraction routes: a production `shot-level peak + continuity recheck` route and a comparison `Lighthouse` route, then print and export their peak clips.

**Architecture:** Build the VLM route first on top of corrected events and strict shots, then add an isolated Lighthouse route that consumes the same inputs but produces its own outputs and artifacts. Both routes export frame-aligned peak clips without changing the legacy selected-clip path.

**Tech Stack:** Python, unittest, ffmpeg, existing OpenAI-compatible VLM client, optional Lighthouse repo/runtime

---

### Task 1: Shot-Level VLM Route

**Files:**
- Create: `backend/services/shot_level_vlm_segments.py`
- Create: `backend/tests/test_shot_level_vlm_segments.py`

- [ ] Write failing tests for one-main-peak selection and continuity stop behavior.
- [ ] Run the tests and confirm failure.
- [ ] Implement event-level shot rerank and adjacent continuity recheck.
- [ ] Re-run the tests and confirm pass.

### Task 2: Clip Export Helpers

**Files:**
- Create: `backend/services/functional_clip_export.py`
- Create: `backend/tests/test_functional_clip_export.py`

- [ ] Write failing tests for generic functional clip export and naming.
- [ ] Run the tests and confirm failure.
- [ ] Implement reusable export helpers for VLM and Lighthouse clips.
- [ ] Re-run the tests and confirm pass.

### Task 3: Lighthouse Route

**Files:**
- Create: `backend/services/lighthouse_segments.py`
- Create: `backend/tests/test_lighthouse_segments.py`

- [ ] Write failing tests for normalized Lighthouse output handling.
- [ ] Run the tests and confirm failure.
- [ ] Implement an isolated Lighthouse route with graceful environment/runtime checks.
- [ ] Re-run the tests and confirm pass.

### Task 4: Comparison Runner

**Files:**
- Create: `backend/run_dual_functional_comparison.py`

- [ ] Add a CLI that runs the VLM route, then the Lighthouse route, then exports both result sets.
- [ ] Print concise summaries for both routes.
- [ ] Save separate JSON manifests and clip folders.

### Task 5: Verification

**Files:**
- Use: `artifacts/`

- [ ] Run the new targeted tests.
- [ ] Run the full backend suite.
- [ ] Run the comparison CLI on the sample video.
- [ ] Confirm that both routes print outputs and export peak clips separately.
