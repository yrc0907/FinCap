# Multimodal Semantic Foundation Design

## Goal

Upgrade the current strict-shot VLM pipeline from pure visual understanding into a subtitle-aware short-video semantic layer that can score visually intense and text-driven drama more reliably.

## Problem

The current pipeline mainly sees frames. It works for clear visual peaks such as fights, chases, and strong motion, but it misses emotionally important clips where the visual intensity is low and the meaning lives in subtitles or dialogue, such as pressure from a boss, humiliation, threats, or a truth reveal.

## Phase Scope

This change is intentionally split into phases.

### Phase 1: Build Now

- Add a reusable subtitle region definition to the VLM shot-analysis request.
- Crop subtitle-region images from every sampled keyframe.
- Send both full-frame keyframes and subtitle-region keyframes to the VLM.
- Rewrite the VLM prompt into a short-video scoring rubric.
- Let the VLM judge clips using:
  - visual intensity
  - visible subtitle text from subtitle crops
  - narrative function labels such as buildup, climax, result, transition
- Keep the current strict-shot, adjacent reassignment, and corrected-event pipeline unchanged.

### Phase 2: Build Later

- Real OCR engine output aggregation
- ASR fallback
- Audio semantic features
- Unified multimodal scoring fusion
- Drag-to-select subtitle box UI instead of numeric region inputs

## Why Phase 1 First

Phase 1 gives the largest immediate accuracy gain with the smallest engineering cost:

- no new heavy OCR dependency is required
- no ASR model setup is required
- no audio model calibration is required
- it already lets the VLM read subtitle content from the cropped subtitle band

## User Flow

1. The user defines one global subtitle box for the current project flow.
2. The backend samples shot keyframes as before.
3. For each keyframe, the backend also crops the subtitle region.
4. The VLM receives:
   - full-frame images
   - subtitle-crop images
   - a short-video semantic scoring rubric
5. The VLM returns:
   - highlight score
   - peak role
   - peak times
   - reason
6. The downstream event and clip pipeline reuses those stronger semantic outputs.

## Prompt Direction

The prompt must explicitly tell the VLM to score these high:

- conflict escalation
- fights and action clashes
- chase and pursuit
- emotional collapse
- strong threats, pressure, scolding, humiliation
- sudden reversal or truth reveal
- result and payoff after the peak

The prompt must explicitly tell the VLM to score these low:

- calm transition
- ordinary walking
- plain exposition
- visually flat dialogue with no strong pressure or plot movement

## Data Model Changes

Add a subtitle region object with normalized coordinates:

- `x`
- `y`
- `width`
- `height`

Add an optional semantic mode block to VLM requests:

- `enableSubtitleRegion`
- `subtitleRegion`
- `promptProfile`

## Backend Design

Create one new helper module for shared multimodal VLM context:

- build the short-video semantic rubric
- crop subtitle-region frames
- format prompt sections for subtitle crops

Keep the actual VLM services small by calling the shared helper from:

- `vlm_shot_analysis.py`
- `shot_level_vlm_segments.py`

## Frontend Design

For Phase 1, expose numeric subtitle-region controls in the existing VLM panel:

- `Subtitle X`
- `Subtitle Y`
- `Subtitle W`
- `Subtitle H`

This is enough to test the pipeline without building a drag-box UI yet.

## Lighthouse Decision

The Lighthouse comparison route is not part of the production semantic path anymore. It can remain on disk temporarily, but it should not be extended or used as the primary highlight route.

## Testing Strategy

Phase 1 tests must prove:

- request models accept subtitle-region input
- subtitle crops are sampled when region support is enabled
- the VLM prompt contains the short-video scoring rubric
- existing visual-only behavior still works when subtitle-region input is absent

## Expected Outcome

After Phase 1, the VLM pipeline should detect not only visual peaks, but also subtitle-heavy emotional pressure and plot-driving dialogue more reliably, especially in anime and dialogue-heavy scenes.
