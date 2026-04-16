# Layer8 Boundary Cleanliness Refinement Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Refine each Layer8 boundary inside a small local frame window so the chosen cut lands on the cleanest nearby frame transition instead of a slightly dirty late/early frame.

**Architecture:** Keep Layer7 and the existing Layer8 fusion flow unchanged up to `boundaryCandidates`. Add one new post-fusion refinement module that scores nearby frame transitions using local left-stability, right-stability, and cross-boundary separation, then replaces the fused timestamp with the best nearby timestamp. Downstream strict shots and semantic layers continue to use those refined boundaries, and semantic layers still snap back to strict shot boundaries.

**Tech Stack:** Python, OpenCV, existing frame sampling utilities, unittest

---

### Task 1: Lock the refinement scoring behavior in tests

**Files:**
- Create: `backend/tests/test_boundary_cleanliness_refinement.py`
- Test: `backend/tests/test_boundary_cleanliness_refinement.py`

- [ ] **Step 1: Write the failing “choose cleaner nearby frame” test**

```python
def test_refines_boundary_to_cleaner_nearby_timestamp():
    result = refine_boundary_candidates(
        ...,
        frame_metric_provider=provider,
    )
    assert result[0]["timeSec"] == 10.733
```

- [ ] **Step 2: Write the failing “keep original when no better candidate exists” test**

```python
def test_keeps_original_boundary_when_current_frame_is_best():
    ...
```

- [ ] **Step 3: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_boundary_cleanliness_refinement.py" -v`
Expected: FAIL because the refinement module does not exist yet.

### Task 2: Implement the boundary cleanliness refinement module

**Files:**
- Create: `backend/services/boundary_cleanliness_refinement.py`
- Test: `backend/tests/test_boundary_cleanliness_refinement.py`

- [ ] **Step 1: Implement the local scoring helper**

Rules:
- inspect a narrow symmetric window around the current boundary
- evaluate multiple nearby candidate timestamps
- prefer strong cross-boundary difference
- penalize unstable left/right interiors
- keep original timestamp when scores tie

- [ ] **Step 2: Re-run focused tests**

Run: `python -m unittest discover -s tests -p "test_boundary_cleanliness_refinement.py" -v`
Expected: PASS

### Task 3: Integrate refinement into Layer8

**Files:**
- Modify: `backend/services/dual_signal_boundary_detection.py`
- Modify: `backend/tests/test_scene_route_integration.py`
- Test: `backend/tests/test_scene_route_integration.py`

- [ ] **Step 1: Write the failing integration test**

```python
def test_boundary_detection_refines_fused_boundary_timestamp():
    ...
    assert result["boundaryCandidates"][0]["timeSec"] == 10.733
```

- [ ] **Step 2: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_scene_route_integration.py" -v`
Expected: FAIL because Layer8 does not call the refinement module yet.

- [ ] **Step 3: Call refinement after fusion and before returning**

Requirements:
- preserve existing fields
- add refinement reason/source marker only when timestamp changes
- keep file size under 500 lines

- [ ] **Step 4: Re-run focused tests**

Run: `python -m unittest discover -s tests -p "test_scene_route_integration.py" -v`
Expected: PASS

### Task 4: Verify the drift case and full backend suite

**Files:**
- Verify only

- [ ] **Step 1: Re-run corrected timeline tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: PASS

- [ ] **Step 2: Re-run full backend tests**

Run: `python -m unittest discover -s tests -p "test_*.py" -v`
Expected: PASS

- [ ] **Step 3: Re-run the sample Layer7/Layer8 pipeline**

Run a local script against `C:\FinCap\text_video.mp4`.
Expected: the refined Layer8 boundary should stay at or move toward the cleanest nearby strict-shot anchor instead of drifting later.
