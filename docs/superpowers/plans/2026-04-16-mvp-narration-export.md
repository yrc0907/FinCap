# MVP Narration Export Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a minimal end-to-end MVP that turns an existing `selectedClips` manifest into narration text, TTS audio, and one exported final video.

**Architecture:** Reuse the current selected-clip manifest as the timeline source. Add one narration service to extract clip keyframes and ask a VLM for short Chinese narration, then add one export service that synthesizes Edge TTS per clip, time-fits each audio track to the clip duration, muxes segment videos, and concatenates them into a single final MP4.

**Tech Stack:** Python, OpenCV, existing OpenAI-compatible VLM client, Edge TTS, ffmpeg/ffprobe, unittest

---

### Task 1: Narration Service

**Files:**
- Create: `backend/services/mvp_narration.py`
- Test: `backend/tests/test_mvp_narration.py`

- [ ] Write failing tests for narration normalization and clip narration generation.
- [ ] Run `python -m unittest backend.tests.test_mvp_narration -v` and confirm failure.
- [ ] Implement a small narration service that extracts clip keyframes, builds a strict JSON prompt, and normalizes the returned narration payload.
- [ ] Re-run `python -m unittest backend.tests.test_mvp_narration -v` and confirm pass.

### Task 2: Final Export Service

**Files:**
- Create: `backend/services/mvp_video_export.py`
- Test: `backend/tests/test_mvp_video_export.py`

- [ ] Write failing tests for audio-fit, mux, and concat ffmpeg command generation.
- [ ] Run `python -m unittest backend.tests.test_mvp_video_export -v` and confirm failure.
- [ ] Implement the export service that saves raw TTS audio, fits each narration track to exact clip duration, muxes per-clip videos, and concatenates the final output.
- [ ] Re-run `python -m unittest backend.tests.test_mvp_video_export -v` and confirm pass.

### Task 3: Executable Entry

**Files:**
- Create: `backend/run_mvp_pipeline.py`

- [ ] Add a CLI entry that accepts `video`, `manifest`, `output`, VLM config, and TTS voice.
- [ ] Make the CLI write a `mvp_manifest.json` with narration, audio, segment, and final video paths.
- [ ] Smoke-run the CLI on the current local sample after implementation.

### Task 4: End-to-End Verification

**Files:**
- Use existing artifacts under `artifacts/`

- [ ] Run the new unittest files and the existing relevant suite.
- [ ] Run the CLI on a real local video and selected-clips manifest.
- [ ] Verify that narration JSON, audio files, segment files, and the final MP4 are produced.
