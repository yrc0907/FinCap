# Event Functional Segments Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add shot-aligned functional segment extraction inside corrected events so peak moments can be exported as clean subclips instead of whole story blocks.

**Architecture:** Keep the current Layer07/08 and corrected-event pipeline unchanged as the source of clean strict shots and repaired events. Add one conservative post-processing service that finds the peak shot inside each event, expands only across continuous neighboring strict shots, labels `build`, `peak`, `result`, and `transition`, and exposes top-level `functionalClips` without replacing the existing `selectedClips` yet.

**Tech Stack:** Python, unittest, existing corrected-event timeline structures

---

### Task 1: Functional Segment Service

**Files:**
- Create: `backend/services/event_functional_segments.py`
- Test: `backend/tests/test_event_functional_segments.py`

- [ ] Write failing unit tests for peak extraction and contamination-stop behavior.
- [ ] Run the new tests to confirm failure.
- [ ] Implement shot-aligned peak/build/result/transition extraction.
- [ ] Re-run the tests to confirm pass.

### Task 2: Corrected Timeline Integration

**Files:**
- Modify: `backend/services/corrected_event_timeline.py`
- Modify: `backend/tests/test_corrected_event_timeline.py`

- [ ] Add `functionalSegments` per event and top-level `functionalClips`.
- [ ] Keep legacy `narrationSpans` and `selectedClips` intact for compatibility.
- [ ] Add one integration test proving functional clips stop before unrelated trailing shots.

### Task 3: Verification

**Files:**
- Use: `backend/tests/`

- [ ] Run the new targeted tests.
- [ ] Run the full backend test suite.
