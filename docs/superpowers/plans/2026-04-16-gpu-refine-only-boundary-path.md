# GPU Refine-Only Boundary Path Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Reuse existing Layer7/Layer8 cut points, run GPU-only boundary cleanliness refinement without rerunning full Layer7, and keep `transnetv2-cuda` from silently falling back to CPU.

**Architecture:** Add one refine-only API path that accepts cached `boundaryCandidates` and refines them locally with `ffmpeg-cuda + torch-cuda`. Keep full Layer7 detection unchanged for callers that still need it, but enforce CUDA when `transnetv2-cuda` is selected so the detector either runs on GPU or fails loudly. The refinement service remains narrow: it never adds or removes cuts, and only nudges each cut by a tiny local frame window.

**Tech Stack:** Python, FastAPI, ffmpeg-cuda, torch-cuda, unittest

---

### Task 1: Lock GPU-only refine behavior in tests

**Files:**
- Modify: `backend/tests/test_boundary_cleanliness_refinement.py`
- Create: `backend/tests/test_transnet_cuda_requirement.py`
- Test: `backend/tests/test_boundary_cleanliness_refinement.py`
- Test: `backend/tests/test_transnet_cuda_requirement.py`

- [ ] **Step 1: Write the failing "refine-only path uses ffmpeg-cuda + torch-cuda" test**

```python
def test_refines_boundary_with_gpu_sampling_and_torch_scores(self) -> None:
    with (
        patch("services.boundary_cleanliness_refinement.sample_grayscale_frames", ...),
        patch("services.boundary_cleanliness_refinement.compute_weighted_transition_scores", ...),
    ):
        result = refine_boundary_candidates(...)
    self.assertEqual(result[0]["timeSec"], 10.733)
```

- [ ] **Step 2: Write the failing "raise when GPU is required but unavailable" test**

```python
def test_raises_when_gpu_refinement_falls_back_to_cpu(self) -> None:
    with self.assertRaises(RuntimeError):
        refine_boundary_candidates(..., config=BoundaryCleanlinessConfig(require_gpu=True))
```

- [ ] **Step 3: Write the failing "transnetv2-cuda rejects CPU fallback" test**

```python
def test_load_transnetv2_model_requires_torch_cuda(self) -> None:
    with patch("services.transnet_refinement.is_torch_cuda_available", return_value=False):
        with self.assertRaises(RuntimeError):
            load_transnetv2_model.cache_clear()
            load_transnetv2_model()
```

- [ ] **Step 4: Run focused tests to verify RED**

Run: `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest backend.tests.test_boundary_cleanliness_refinement backend.tests.test_transnet_cuda_requirement -v`
Expected: FAIL because the GPU-only refine path and hard CUDA requirement are not implemented yet.

### Task 2: Implement GPU-only refine-only service behavior

**Files:**
- Modify: `backend/services/boundary_cleanliness_refinement.py`
- Modify: `backend/api_models.py`
- Modify: `backend/timeline_routes.py`
- Test: `backend/tests/test_boundary_cleanliness_refinement.py`

- [ ] **Step 1: Implement local GPU frame sampling and local boundary scoring**

```python
sample_batch = sample_grayscale_frames(
    video_path=video_path,
    start_sec=window_start_sec,
    end_sec=window_end_sec,
    step_sec=1.0 / fps,
    width=config.resize_width,
    height=config.resize_height,
)
scores, backend = compute_weighted_transition_scores(...)
```

- [ ] **Step 2: Enforce GPU-only mode when requested**

```python
if config.require_gpu and sample_batch.backend != "ffmpeg-cuda":
    raise RuntimeError(...)
if config.require_gpu and backend != "torch-cuda":
    raise RuntimeError(...)
```

- [ ] **Step 3: Add refine-only request/route that accepts cached boundaries**

```python
@router.post("/boundary-cleanliness-refine")
async def run_boundary_cleanliness_refine(...):
    return refine_boundary_candidates(...)
```

- [ ] **Step 4: Run focused tests to verify GREEN**

Run: `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest backend.tests.test_boundary_cleanliness_refinement -v`
Expected: PASS

### Task 3: Enforce CUDA in the TransNet detector path

**Files:**
- Modify: `backend/services/transnet_refinement.py`
- Test: `backend/tests/test_transnet_cuda_requirement.py`

- [ ] **Step 1: Resolve detector device explicitly from torch CUDA availability**

```python
def _resolve_transnet_device() -> str:
    if not is_torch_cuda_available():
        raise RuntimeError("transnetv2-cuda requires torch cuda")
    return "cuda"
```

- [ ] **Step 2: Instantiate `TransNetV2` with explicit CUDA**

```python
return TransNetV2(device=_resolve_transnet_device())
```

- [ ] **Step 3: Run focused tests to verify GREEN**

Run: `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest backend.tests.test_transnet_cuda_requirement -v`
Expected: PASS

### Task 4: Verify cached refine-only flow end to end

**Files:**
- Verify only

- [ ] **Step 1: Run the targeted backend test set**

Run: `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest discover -s backend/tests -p "test_*.py" -v`
Expected: PASS

- [ ] **Step 2: Run a local refine-only script against cached Layer7/8 boundaries**

Run a local Python one-off that loads `C:\FinCap\artifacts\layer7-layer8-only\layer7_layer8_raw_manifest.json` and refines only `layer8.boundaryCandidates`.
Expected: finish quickly, avoid full Layer7 rerun, and print only the refined boundary list.

- [ ] **Step 3: Compare before/after boundary points**

Expected:
- same boundary count
- only tiny local shifts (`±1~2` frames)
- no new cut points
- no removed cut points
