# Multimodal Semantic Foundation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add subtitle-region-aware VLM analysis and a short-video high-peak prompt rubric to improve semantic clip scoring without introducing a full OCR/ASR/audio stack yet.

**Architecture:** Add a shared multimodal helper module that crops subtitle-region frames and builds the short-video scoring rubric. Reuse that helper from the existing VLM shot-group analysis and shot-level peak-selection services while exposing numeric subtitle-region controls through the current workspace UI.

**Tech Stack:** Python, FastAPI, Pydantic, unittest, React, TypeScript, existing OpenAI-compatible VLM client, OpenCV

---

### Task 1: Shared Multimodal Context Helpers

**Files:**
- Create: `backend/services/multimodal_semantic_context.py`
- Create: `backend/tests/test_multimodal_semantic_context.py`

- [ ] Write a failing test for normalized subtitle-region cropping metadata.
- [ ] Run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_multimodal_semantic_context -v` and confirm failure.
- [ ] Implement subtitle-region dataclasses, frame-crop helpers, and the shared short-video semantic rubric builder.
- [ ] Re-run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_multimodal_semantic_context -v` and confirm pass.

### Task 2: VLM Shot Analysis Prompt Upgrade

**Files:**
- Modify: `backend/services/vlm_shot_analysis.py`
- Modify: `backend/api_models.py`
- Create: `backend/tests/test_vlm_shot_analysis_multimodal.py`

- [ ] Write a failing test proving VLM shot analysis includes subtitle crops and the short-video rubric when subtitle-region input is provided.
- [ ] Run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_vlm_shot_analysis_multimodal -v` and confirm failure.
- [ ] Add subtitle-region request models and wire the new helper into `analyze_shot_sequence`.
- [ ] Re-run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_vlm_shot_analysis_multimodal -v` and confirm pass.

### Task 3: Shot-Level Peak Selection Prompt Upgrade

**Files:**
- Modify: `backend/services/shot_level_vlm_segments.py`
- Create: `backend/tests/test_shot_level_vlm_multimodal.py`

- [ ] Write a failing test proving peak-selection prompts mention conflict, threats, pressure, reversal, and subtitle evidence.
- [ ] Run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_shot_level_vlm_multimodal -v` and confirm failure.
- [ ] Reuse the shared rubric helper in peak selection and continuity prompts without growing the file materially.
- [ ] Re-run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest tests.test_shot_level_vlm_multimodal -v` and confirm pass.

### Task 4: Workspace Controls

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/workspace/workspace-config.ts`
- Modify: `frontend/src/components/workspace/workspace-semantic-controls.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`

- [ ] Add subtitle-region fields to the workspace payload types and local VLM control state.
- [ ] Add numeric inputs for `Subtitle X/Y/W/H` in the existing semantic controls panel.
- [ ] Pass the new fields into the VLM shot-analysis request.

### Task 5: Verification

**Files:**
- Use: `artifacts/`

- [ ] Run the new targeted tests.
- [ ] Run `C:\FinCap\backend\.venv\Scripts\python.exe -m unittest discover -s tests -p "test_*.py" -v`.
- [ ] Run one real VLM pass on `C:\FinCap\text_video.mp4` with a subtitle-region payload.
- [ ] Confirm the returned VLM reasons reflect subtitle-aware high-peak criteria.
