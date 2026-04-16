# Dual Route Scene Detection Design

## Goal

Add two switchable scene-detection routes to Layer 07 and Layer 08:

- `pyscenedetect`
- `opencv-cuda`

The new design must improve end-to-end speed, preserve or improve cut quality, keep logs deterministic, and expose the same route choice from the workspace UI through the backend APIs.

## Current Constraints

- User-facing chat stays in Chinese.
- All source code, comments, logs, and UI copy stay in English.
- Backend remains Python.
- Frontend uses the existing React + shadcn/ui stack.
- Individual code files must stay under 500 lines.
- The current custom OpenCV build exposes CUDA image primitives but does not expose CUDA optical flow.

## Architecture

### Unified Scene Candidate Provider

Introduce a shared scene candidate provider abstraction used by both Layer 07 and Layer 08.

The provider accepts:

- `video_path`
- `detector_mode`
- sampling and threshold config

The provider returns:

- unified cut-point timestamps
- candidate windows
- detector metadata

This removes duplicated direct `PySceneDetect` calls and guarantees that Layer 07 and Layer 08 consume the same scene route.

### Detector Modes

#### `pyscenedetect`

Keep the current `PySceneDetect` path as a supported route for quality comparison and fallback.

#### `opencv-cuda`

Add a new OpenCV-driven route that replaces `PySceneDetect` scene detection responsibilities with:

- frame difference scoring
- histogram difference scoring
- edge difference scoring
- rolling adaptive thresholding
- minimum scene-length filtering
- neighboring candidate merge
- hard-cut vs soft-cut tagging
- unified cut-point output

The route should use CUDA-enabled OpenCV operators where available and fall back cleanly when a specific CUDA primitive is unavailable.

## OpenCV CUDA Route

### Input

Use the existing grayscale frame sampling pipeline, which already prefers `ffmpeg-cuda`.

### Signals

For adjacent sampled frames, compute:

- histogram difference
- frame difference
- edge difference
- motion proxy score

The motion proxy is a lightweight scene-motion heuristic built from cheap frame-change signals. It is intentionally used instead of optical flow in V1 because the current OpenCV build does not expose CUDA optical flow.

### Adaptive Thresholding

Compute a rolling mean and rolling standard deviation over the aggregated scene score series.

Build a dynamic threshold from:

- local rolling mean
- local rolling standard deviation
- configurable sensitivity multiplier
- configurable hard floor

This avoids a brittle global threshold and improves stability across different pacing styles.

### Candidate Windows

Convert threshold crossings into candidate windows. Then apply:

- minimum scene-length filtering
- suppression of overly dense nearby hits
- merge of overlapping or near-adjacent windows

Each candidate window stores:

- start time
- end time
- peak time
- peak score
- cut class
- signal sources

### Hard vs Soft Classification

Each candidate window is tagged as:

- `hard-cut`
- `soft-cut`

The first version uses shape-based heuristics derived from peak width, peak height, and local slope. This is metadata only and does not alter the response schema consumed by existing downstream code.

### CUDA Optical Flow Extension

Reserve an extension point for future `cudaoptflow` support. V1 does not require recompiling OpenCV again.

## Layer Integration

### Layer 07

Layer 07 keeps its current multi-scale role:

- coarse pass finds suspicious regions
- fine pass refines timing

The change is that scene-route injection now comes from the unified provider instead of a direct `PySceneDetect` call.

### Layer 08

Layer 08 keeps its current dual-signal role:

- subject signal from center-region weighted scoring
- scene signal from scene-transition scoring plus provider cuts
- fused boundary candidates

The change is that scene-route injection now comes from the same unified provider and therefore stays aligned with Layer 07.

## API Changes

Add a `scene_detector_mode` request field to:

- `MultiscaleDetectionRequest`
- `DualSignalBoundaryDetectionRequest`

Accepted values:

- `pyscenedetect`
- `opencv-cuda`

The response should include route metadata so console and UI results clearly show which detector ran.

## Workspace UI

Add a route selector to the workspace control surface so the user can switch between:

- `PySceneDetect`
- `OpenCV CUDA`

The selector should feed both Layer 07 and Layer 08 requests. The UI must stay visually consistent with the existing workspace style and use shadcn/ui primitives.

Because `project-workspace.tsx` is already oversized, split the workspace into smaller focused modules before or during the UI change.

## Logging

Keep console logs English-only and add route visibility:

- active scene detector mode
- detector backend
- candidate count
- hard-cut count
- soft-cut count

This must appear in both Layer 07 and Layer 08 flows.

## Testing

Add test coverage for:

- scene detector mode selection
- OpenCV route candidate generation
- minimum scene-length filtering and merge behavior
- request parsing for the new mode field

Then run the sample video through both routes and verify:

- both routes complete successfully
- console logs clearly identify the route
- the OpenCV route produces a valid candidate list

