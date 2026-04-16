# Frame-Aligned Clip Export Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Prevent adjacent selected clips from sharing the same video frame by aligning clip exports to real frame boundaries and using one reusable export path.

**Architecture:** Keep semantic ranges unchanged for analysis, but derive frame-aligned export metadata from the project video FPS and duration. Use half-open frame ranges `[start_frame, end_frame)` so adjacent clips touch without overlap. Add one reusable Python exporter for local preview generation so validation artifacts use the same logic as future production exports.

**Tech Stack:** Python, FastAPI route post-processing, unittest, ffmpeg

---

### Task 1: Lock frame-aligned range behavior in tests

**Files:**
- Create: `backend/tests/test_frame_aligned_clip_export.py`
- Test: `backend/tests/test_frame_aligned_clip_export.py`

- [ ] **Step 1: Write the failing frame-range test**

```python
def test_aligns_adjacent_clip_ranges_without_shared_frames():
    clips = attach_frame_alignment_to_selected_clips(
        selected_clips=[
            {"index": 1, "startSec": 0.0, "endSec": 10.753},
            {"index": 2, "startSec": 10.753, "endSec": 16.153},
        ],
        fps=30.0,
        video_duration_sec=60.967,
    )
    assert clips[0]["exportStartFrame"] == 0
    assert clips[0]["exportEndFrame"] == 323
    assert clips[1]["exportStartFrame"] == 323
    assert clips[1]["exportEndFrame"] == 485
```

- [ ] **Step 2: Write the failing clamp test**

```python
def test_clamps_export_frames_inside_video_bounds():
    clips = attach_frame_alignment_to_selected_clips(
        selected_clips=[{"index": 1, "startSec": -0.2, "endSec": 99.0}],
        fps=24.0,
        video_duration_sec=3.0,
    )
    assert clips[0]["exportStartFrame"] == 0
    assert clips[0]["exportEndFrame"] == 72
```

- [ ] **Step 3: Run focused tests**

Run: `python -m unittest discover -s backend/tests -p "test_frame_aligned_clip_export.py" -v`
Expected: FAIL because the alignment helper does not exist yet.

### Task 2: Add reusable frame-alignment helpers

**Files:**
- Create: `backend/services/frame_aligned_clip_export.py`
- Test: `backend/tests/test_frame_aligned_clip_export.py`

- [ ] **Step 1: Implement minimal frame-alignment helpers**

```python
def attach_frame_alignment_to_selected_clips(...):
    ...
```

Rules:
- use half-open frame ranges
- use `ceil(second * fps)` for both boundaries
- clamp inside `[0, total_frames]`
- never let `exportEndFrame < exportStartFrame`

- [ ] **Step 2: Re-run focused tests**

Run: `python -m unittest discover -s backend/tests -p "test_frame_aligned_clip_export.py" -v`
Expected: PASS

### Task 3: Attach export metadata to corrected timeline results

**Files:**
- Modify: `backend/services/corrected_event_timeline.py`
- Modify: `backend/timeline_routes.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Write the failing integration test**

```python
def test_selected_clips_include_frame_aligned_export_metadata():
    result = generate_corrected_event_timeline(...)
    assert result["selectedClips"][0]["exportStartFrame"] == 0
```

- [ ] **Step 2: Run focused tests to verify failure**

Run: `python -m unittest discover -s backend/tests -p "test_corrected_event_timeline.py" -v`
Expected: FAIL because selected clips do not expose export metadata yet.

- [ ] **Step 3: Add optional alignment post-processing**

Approach:
- keep `generate_corrected_event_timeline()` backward compatible
- add optional `fps` and `video_duration_sec`
- enrich only `selectedClips`
- from the route, pass project `fps` and `durationSec`

- [ ] **Step 4: Re-run corrected timeline tests**

Run: `python -m unittest discover -s backend/tests -p "test_corrected_event_timeline.py" -v`
Expected: PASS

### Task 4: Add one reusable preview exporter

**Files:**
- Modify: `backend/services/frame_aligned_clip_export.py`
- Create: `backend/export_selected_clips.py`
- Test: `backend/tests/test_frame_aligned_clip_export.py`

- [ ] **Step 1: Write the failing ffmpeg command test**

```python
def test_builds_trim_filters_from_frame_range():
    command = build_ffmpeg_frame_export_command(...)
    assert "trim=start_frame=323:end_frame=485" in " ".join(command)
```

- [ ] **Step 2: Run focused tests to verify failure**

Run: `python -m unittest discover -s backend/tests -p "test_frame_aligned_clip_export.py" -v`
Expected: FAIL because the export command helper does not exist yet.

- [ ] **Step 3: Implement reusable export command + CLI**

CLI behavior:
- read selected clip manifest JSON
- export clips into an output folder
- use frame-aligned video trim filters
- reset timestamps for each clip

- [ ] **Step 4: Re-run focused tests**

Run: `python -m unittest discover -s backend/tests -p "test_frame_aligned_clip_export.py" -v`
Expected: PASS

### Task 5: Verify with tests and a regenerated sample

**Files:**
- Verify only

- [ ] **Step 1: Run backend tests**

Run: `python -m unittest discover -s backend/tests -p "test_*.py" -v`
Expected: PASS

- [ ] **Step 2: Regenerate sample selected clips through the new exporter**

Run:

```bash
python backend/export_selected_clips.py --video C:\FinCap\text_video.mp4 --manifest C:\FinCap\artifacts\final-selected-clips\selected_clips_manifest.json --output C:\FinCap\artifacts\final-selected-clips\frame-aligned
```

Expected: output clips are created successfully.

- [ ] **Step 3: Verify no overlap between clip 1 tail frame and clip 2 head frame**

Run a local verification script against the regenerated clips.
Expected: the previous duplicated boundary frame no longer appears in both clips.
