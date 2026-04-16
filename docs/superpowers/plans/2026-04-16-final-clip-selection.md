# Final Clip Selection Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Export a final cut-ready clip list from corrected event narration spans and verify it by batch-cutting the sample video.

**Architecture:** Reuse the existing corrected event timeline response, derive top-level `selectedClips` by keeping `keep` and `bridge` spans while dropping `drop` spans, and expose summary counts for the UI. Do not add a new route or state machine; keep the selection inside the corrected timeline payload.

**Tech Stack:** Python backend service + unittest + TypeScript React + pnpm build + ffmpeg verification

---

### Task 1: Lock selected clip behavior in tests

**Files:**
- Modify: `backend/tests/test_corrected_event_timeline.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Write a failing selection test**

```python
def test_exports_keep_and_bridge_spans_as_selected_clips():
    result = generate_corrected_event_timeline(...)
    assert [item["label"] for item in result["selectedClips"]] == ["bridge", "keep", "bridge"]
```

- [ ] **Step 2: Write a failing drop-filter test**

```python
def test_excludes_drop_spans_from_selected_clips():
    ...
```

- [ ] **Step 3: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: FAIL because `selectedClips` does not exist yet.

### Task 2: Extend corrected timeline output

**Files:**
- Modify: `backend/services/corrected_event_timeline.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Build top-level selected clip list from narration spans**

Rules:
- include `keep`
- include `bridge`
- exclude `drop`
- never merge across event boundaries

- [ ] **Step 2: Add summary counts**

Add:
- `selectedClipCount`
- `selectedKeepClipCount`
- `selectedBridgeClipCount`

- [ ] **Step 3: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: PASS

### Task 3: Show final clips in the frontend

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/components/workspace/workspace-semantic-results.tsx`

- [ ] **Step 1: Extend corrected timeline types**

Add `selectedClips` and selection summary fields.

- [ ] **Step 2: Render final clips**

Show:
- selected clip count
- clip label
- start/end
- source event

### Task 4: Verify and batch-cut sample clips

**Files:**
- Verify only

- [ ] **Step 1: Run backend tests**

Run: `python -m unittest discover -s tests -p "test_*.py" -v`
Expected: all tests pass

- [ ] **Step 2: Run frontend build**

Run: `pnpm --dir frontend build`
Expected: build succeeds

- [ ] **Step 3: Batch-cut sample selected clips**

Run a local ffmpeg-based validation script against `text_video.mp4`.
Expected: produce preview files for all selected clips.
