# VLM Shot Semantic Pass Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add a strict-shot semantic analysis pass that keeps boundary-derived shots intact, runs VLM vision understanding on shot groups, returns continuity/highlight judgments, and prints the results in both backend logs and the frontend workspace.

**Architecture:** Keep the existing boundary detector untouched, replace the current pre-merge assumption with a stricter shot normalization step, and add a new VLM analysis route that consumes normalized shots plus an OpenAI-compatible VLM config. The frontend will pass the active VLM config from global settings into the workspace, trigger the new route, and render the returned semantic results while also logging them in the browser console.

**Tech Stack:** FastAPI, Pydantic, Python unittest, OpenCV/FFmpeg frame extraction, OpenAI-compatible chat completions API, React, TypeScript, shadcn/ui, pnpm.

---

## File Map

- Create: `backend/services/strict_shot_generation.py`
- Create: `backend/services/vlm_openai_client.py`
- Create: `backend/services/vlm_shot_analysis.py`
- Create: `backend/tests/test_strict_shot_generation.py`
- Create: `backend/tests/test_vlm_shot_analysis.py`
- Create: `frontend/src/components/workspace/workspace-vlm-panel.tsx`
- Modify: `backend/api_models.py`
- Modify: `backend/app.py`
- Modify: `frontend/src/App.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-control-panel.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/types/workspace.ts`

### Task 1: Add failing tests for strict shot normalization

**Files:**
- Create: `backend/tests/test_strict_shot_generation.py`
- Create: `backend/services/strict_shot_generation.py`

- [ ] **Step 1: Write the failing test**

```python
from __future__ import annotations

import unittest

from services.strict_shot_generation import StrictShotConfig, generate_strict_shots


class StrictShotGenerationTests(unittest.TestCase):
    def test_keeps_boundary_split_points_while_cleaning_duplicates(self) -> None:
        result = generate_strict_shots(
            video_duration_sec=13.167,
            boundary_candidates=[
                {"timeSec": 4.033, "score": 0.91},
                {"timeSec": 6.2, "score": 0.83},
                {"timeSec": 6.201, "score": 0.82},
                {"timeSec": 8.1, "score": 0.87},
                {"timeSec": 10.733, "score": 0.9},
            ],
            config=StrictShotConfig(dedupe_epsilon_sec=0.01, min_shot_sec=0.15),
        )

        self.assertEqual(
            [(item["startSec"], item["endSec"]) for item in result["shots"]],
            [(0.0, 4.033), (4.033, 6.2), (6.2, 8.1), (8.1, 10.733), (10.733, 13.167)],
        )
        self.assertEqual(result["removedBoundaries"], [{"timeSec": 6.201, "reason": "duplicate"}])


if __name__ == "__main__":
    unittest.main()
```

- [ ] **Step 2: Run test to verify it fails**

Run: `python -m unittest backend.tests.test_strict_shot_generation -v`
Expected: FAIL with `ModuleNotFoundError` or missing `generate_strict_shots`

- [ ] **Step 3: Write minimal implementation**

```python
@dataclass(frozen=True)
class StrictShotConfig:
    dedupe_epsilon_sec: float = 0.05
    min_shot_sec: float = 0.15


def generate_strict_shots(video_duration_sec: float, boundary_candidates: list[dict[str, Any]], config: StrictShotConfig | None = None) -> dict[str, Any]:
    ...
```

- [ ] **Step 4: Run test to verify it passes**

Run: `python -m unittest backend.tests.test_strict_shot_generation -v`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/tests/test_strict_shot_generation.py backend/services/strict_shot_generation.py
git commit -m "feat: add strict shot normalization"
```

### Task 2: Add failing tests for VLM shot semantic analysis

**Files:**
- Create: `backend/tests/test_vlm_shot_analysis.py`
- Create: `backend/services/vlm_openai_client.py`
- Create: `backend/services/vlm_shot_analysis.py`

- [ ] **Step 1: Write the failing test**

```python
from __future__ import annotations

import unittest
from pathlib import Path
from unittest.mock import patch

from services.vlm_shot_analysis import VlmShotAnalysisConfig, analyze_shot_sequence


class VlmShotAnalysisTests(unittest.TestCase):
    @patch("services.vlm_shot_analysis._extract_keyframes_for_shot")
    @patch("services.vlm_shot_analysis.call_openai_compatible_vision")
    def test_returns_semantic_scores_and_peak_times(
        self,
        call_openai_mock,
        extract_frames_mock,
    ) -> None:
        extract_frames_mock.return_value = [
            {"timeSec": 4.5, "jpegBase64": "aaa"},
            {"timeSec": 5.4, "jpegBase64": "bbb"},
        ]
        call_openai_mock.return_value = {
            "is_continuous_story": True,
            "merge_with_next": True,
            "highlight_score": 0.88,
            "peak_times": [5.4],
            "peak_role": "conflict",
            "reason": "Action escalation continues into the next shot.",
        }

        result = analyze_shot_sequence(
            video_path=Path("text_video.mp4"),
            shots=[
                {"index": 1, "startSec": 4.033, "endSec": 6.2, "durationSec": 2.167},
                {"index": 2, "startSec": 6.2, "endSec": 8.1, "durationSec": 1.9},
            ],
            vlm_config={"endpoint": "https://example.com/v1/chat/completions", "key": "k", "model": "gpt-4.1-mini"},
            config=VlmShotAnalysisConfig(group_size=2),
        )

        self.assertEqual(result["groups"][0]["highlightScore"], 0.88)
        self.assertEqual(result["groups"][0]["peakTimesSec"], [5.4])
        self.assertTrue(result["groups"][0]["mergeWithNext"])


if __name__ == "__main__":
    unittest.main()
```

- [ ] **Step 2: Run test to verify it fails**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis -v`
Expected: FAIL with missing module or missing `analyze_shot_sequence`

- [ ] **Step 3: Write minimal implementation**

```python
@dataclass(frozen=True)
class VlmShotAnalysisConfig:
    group_size: int = 3
    keyframes_per_shot: int = 3


def analyze_shot_sequence(...):
    ...
```

- [ ] **Step 4: Run test to verify it passes**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis -v`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/tests/test_vlm_shot_analysis.py backend/services/vlm_openai_client.py backend/services/vlm_shot_analysis.py
git commit -m "feat: add vlm shot semantic analysis"
```

### Task 3: Wire backend API models and route

**Files:**
- Modify: `backend/api_models.py`
- Modify: `backend/app.py`

- [ ] **Step 1: Add request/response-facing models**

Add models for:
- `VlmRuntimeConfigRequest`
- `StrictShotGenerationRequest`
- `ShotRequest`
- `VlmShotAnalysisRequest`

- [ ] **Step 2: Add backend endpoint**

Add:
- `POST /api/projects/{project_id}/timeline/strict-shot-generate`
- `POST /api/projects/{project_id}/timeline/vlm-shot-analyze`

- [ ] **Step 3: Print backend logs**

Print:
- shot count
- grouped shot count
- highlight scores
- peak times
- merge decisions

- [ ] **Step 4: Run targeted tests**

Run: `python -m unittest backend.tests.test_strict_shot_generation backend.tests.test_vlm_shot_analysis -v`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/api_models.py backend/app.py
git commit -m "feat: expose strict shot and vlm analysis routes"
```

### Task 4: Wire frontend settings, API client, and workspace actions

**Files:**
- Modify: `frontend/src/App.tsx`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`

- [ ] **Step 1: Add failing frontend type/build changes**

Introduce:
- `StrictShotResult`
- `VlmShotAnalysisResult`
- workspace payload types for the new endpoints

- [ ] **Step 2: Pass settings into workspace**

Update:
- `App.tsx` to pass `settings`
- `ProjectWorkspace` to select the first usable VLM config

- [ ] **Step 3: Add workspace actions**

Add handlers for:
- run strict shots
- run VLM semantic pass
- `console.log(...)` for returned results

- [ ] **Step 4: Run build**

Run: `pnpm --dir frontend build`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add frontend/src/App.tsx frontend/src/lib/workspace.ts frontend/src/types/workspace.ts frontend/src/components/project-workspace.tsx
git commit -m "feat: wire workspace strict shot and vlm actions"
```

### Task 5: Add visible workspace result panels

**Files:**
- Modify: `frontend/src/components/workspace/workspace-control-panel.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`
- Create: `frontend/src/components/workspace/workspace-vlm-panel.tsx`

- [ ] **Step 1: Add controls**

Add buttons for:
- `Run Strict Shots`
- `Run VLM`

- [ ] **Step 2: Add results rendering**

Show:
- shot list
- grouped semantic ranges
- highlight score
- peak times
- merge with prev / next
- reason

- [ ] **Step 3: Keep files under 500 lines**

If the results panel grows too large, move the VLM section into `workspace-vlm-panel.tsx`.

- [ ] **Step 4: Run build**

Run: `pnpm --dir frontend build`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add frontend/src/components/workspace/workspace-control-panel.tsx frontend/src/components/workspace/workspace-results-panel.tsx frontend/src/components/workspace/workspace-vlm-panel.tsx
git commit -m "feat: render strict shot and vlm results"
```

### Task 6: End-to-end verification

**Files:**
- Modify: none unless fixes are required

- [ ] **Step 1: Run backend test suite**

Run: `python -m unittest discover -s backend/tests -p 'test_*.py' -v`
Expected: PASS

- [ ] **Step 2: Run frontend build**

Run: `pnpm --dir frontend build`
Expected: PASS

- [ ] **Step 3: Manual runtime check**

Use the app to run:
1. Layer 07
2. Layer 08
3. Strict Shots
4. VLM

Confirm:
- backend console prints shot/VLM summaries
- browser console prints the semantic result object
- workspace panel shows highlight scores and peak times

- [ ] **Step 4: Commit**

```bash
git add -A
git commit -m "feat: add vlm shot semantic pass"
```
