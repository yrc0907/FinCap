# Workflow Workspace Shell Design

## Goal

Replace the current layer-centric workspace with a node-based workflow shell that matches the user's industrial storyboard sketch while preserving the existing backend pipeline.

## Primary User Flow

The new workspace should present one visible production flow:

1. Upload Video
2. Boundary Detection
3. Shot Segments
4. OCR / ASR / Character References / VLM Grid
5. Story Fix
6. Scene Logic
7. Voice + Export

Users should not see internal engineering names such as Layer 07, Layer 08, or Strict Shots.

## Scope For This Phase

This phase is workflow-shell first.

### Build Now

- Replace the current split control/results layout with a workflow canvas.
- Render each workflow stage as a node card with:
  - title
  - short status
  - primary action
  - preview action when applicable
- Keep the current backend execution hooks working under the new UI shell.
- Add reusable preview modal scaffolding for:
  - boundary preview
  - shot preview
  - OCR preview
  - ASR preview
  - character references
  - VLM grid preview
  - story fix preview
  - scene logic preview
- Add a workspace upload node that can upload a different video and switch the active project immediately.
- Keep the industrial dark style consistent with the existing app.

### Scaffold Now, Connect Later

- manual boundary re-selection save logic
- manual shot re-selection save logic
- OCR edit persistence
- ASR edit persistence
- frame replacement persistence
- final export orchestration from the workspace

These interactions should still have visible UI shells, local draft state, and action buttons so the user can continue editing later.

## Architecture

The current `ProjectWorkspace` mixes orchestration, controls, and results in one large screen. The redesign should split this into:

- one orchestration container that still owns backend execution state
- one workflow canvas component that renders visible nodes
- one reusable modal/panel layer for preview and editing shells
- small focused node sections that map user-facing stages to existing backend results

This keeps the backend pipeline intact while changing only the user-facing structure.

## Node Definitions

### Upload Video

- shows current project name and media metadata
- allows uploading another video from inside the workspace
- on successful upload:
  - backend project is created
  - home project list stays in sync
  - active workspace project switches to the new project

### Boundary Detection

- visible action runs the internal boundary chain
- internal chain remains:
  - multiscale detect
  - dual-signal boundary detect
- advanced modal exposes processing mode, route, and internal boundary parameters
- preview modal shows:
  - boundary times
  - derived clips around boundaries
  - current editable local trim shell

### Shot Segments

- visible action runs strict-shot generation
- preview modal shows generated shot segments
- each shot can open the shared local trim editor shell

### OCR / ASR / Character References / VLM Grid

- one node card with four sub-entry points
- OCR modal:
  - video preview shell
  - subtitle region overlay shell
  - preview list shell for subtitle entries
- ASR modal:
  - editable segment list shell
- Character References modal:
  - image upload
  - naming
- VLM Grid modal:
  - planned sampled frame grid
  - replace-frame shell
  - run button and progress shell

### Story Fix

- visible action runs adjacent-story reassignment and corrected-event timeline
- preview modal shows corrected events, selected clips, and editable local ranges

### Scene Logic

- preview modal groups current functional clips by user-facing types:
  - peak
  - build
  - transition
  - result
- labels should be user-facing Chinese, while underlying data can still reuse current backend functional clip types

### Voice + Export

- visible shell only for now
- can expose current ready-state based on available selected clips / functional clips
- action buttons may be placeholders until export is fully wired into workspace APIs

## Styling Direction

- preserve the existing dark glass industrial look
- add a blueprint/grid canvas background
- node cards should read like a production console rather than generic dashboard cards
- arrows or flow connectors should reinforce left-to-right progression
- modals should feel like operator panels, not form dialogs

## Data Reuse Rules

- preserve existing result shapes from:
  - multiscale detection
  - dual boundary detection
  - strict shots
  - VLM shot analysis
  - adjacent reassignment
  - corrected event timeline
- derive user-facing preview data from existing results rather than inventing duplicate state
- local edit shells may keep draft-only state in the frontend during this phase

## Implementation Constraints

- keep source code and comments in English
- keep user-facing chat in Chinese
- use `pnpm`
- keep modified files under the 500-line project rule by splitting components early
- prefer existing shadcn/ui primitives and add only missing primitives when needed

## Expected Outcome

After this phase, the workspace should look and behave like a visible production workflow console instead of an engineering control surface, while still running the current backend pipeline under the hood.
