# Dual Functional Segmentation Design

## Goal

Build two separate high-value clip extraction routes on top of the current Layer07/08 -> Strict Shots -> VLM -> Adjacent -> Corrected Event Timeline pipeline:

1. A primary `shot-level single-peak rerank + adjacent continuity recheck` route.
2. A secondary `Lighthouse query-based highlight refinement` route.

Both routes must:

- stay separate in code and artifacts
- print their results clearly
- export peak clips as standalone video files

## Why This Change

The current functional segment extraction is still too coarse because it projects group-level VLM peaks down to shots after the fact. That makes too many shots look like peaks, so highlight clips remain too wide and still feel like narration blocks instead of TikTok-style high-value moments.

The new design keeps the current clean boundary pipeline, but adds a more precise second-stage selector.

## Option Comparison

### Option 1: Shot-Level Single-Peak Only

- Ask the VLM to pick one main peak shot inside each corrected event.
- Expand around that peak using local heuristics only.

Pros:

- Lowest implementation cost
- Better than current projected-peak logic

Cons:

- Still weak when adjacent shots look similar but actually belong to a different narrative function

### Option 2: Shot-Level Single-Peak + Adjacent Continuity Recheck

- Ask the VLM to choose one `main_peak_shot_index` per event.
- Recheck left/right adjacent shots one-by-one with a second VLM continuity prompt.
- Stop expansion once continuity breaks.

Pros:

- Best fit for the current project
- Handles build / peak / result / transition better than a pure score-based expansion
- Keeps strict-shot boundaries clean

Cons:

- More VLM calls
- Still depends on prompt quality

### Option 3: Lighthouse as the Primary System

- Replace the current business logic with Lighthouse-style query retrieval.

Pros:

- Strong for query-based highlight retrieval

Cons:

- Poor fit for the full build / transition / result taxonomy
- Higher setup cost
- Not a clean replacement for the current pipeline

## Chosen Design

Use Option 2 as the primary production path and add a separate Lighthouse route as an experimental comparison path.

## Architecture

### Route A: Shot-Level VLM Functional Segments

Input:

- `video_path`
- `groups`
- `shots`
- `corrected events`
- VLM config

Steps:

1. Project each corrected event onto strict shots.
2. Extract shot-level keyframes for every shot inside the event.
3. Ask the VLM for one structured result per event:
   - `main_peak_shot_index`
   - shot-level role hints
   - optional confidence / reason
4. Start from the chosen peak shot.
5. Walk left and right one adjacent shot at a time.
6. For each adjacent candidate, ask a second VLM continuity question:
   - does this shot still belong to the same high-value sequence?
   - if yes, is it `build`, `peak`, or `result`?
7. Stop when continuity breaks.
8. Mark remaining shots as `transition`.

Output:

- `vlmFunctionalEvents`
- `vlmFunctionalClips`
- exported peak clips under their own artifact folder

### Route B: Lighthouse Query-Based Highlights

Input:

- `video_path`
- strict shots or corrected events
- a fixed query set such as:
  - `action climax`
  - `conflict escalation`
  - `resolution result`

Steps:

1. Run Lighthouse as a separate experimental route.
2. Convert returned windows into shot-aligned clips.
3. Export only high-score peak-like windows.

Output:

- `lighthouseFunctionalClips`
- exported Lighthouse clips under a separate artifact folder

## Boundaries and Safety

- Do not replace the existing `selectedClips` route yet.
- Keep both new routes additive and isolated.
- Always snap exported clips back to strict-shot boundaries.
- Keep each code file under 500 lines.

## Testing Strategy

- Test that the primary VLM route chooses exactly one main peak shot.
- Test that continuity expansion stops before unrelated trailing shots.
- Test that Lighthouse route normalization stays separate from the VLM route.
- Run the full backend suite after integration.

## Expected Outcome

After this change, the primary route should produce tighter `build / peak / result / transition` clips, and the Lighthouse route should provide a separate query-style highlight comparison baseline.
