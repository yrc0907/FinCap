# React Flow Workspace Canvas Design

## Status

This design supersedes the earlier workflow-shell direction in `2026-04-17-workflow-workspace-shell-design.md`.

The approved direction is:

- React Flow canvas
- fixed workflow chain
- draggable nodes
- pannable and zoomable canvas
- pure modal interactions
- no right-side configuration panel

## Goal

Replace the current card-based workspace with a real workflow editor that feels closer to Dify or Coze while preserving the existing backend pipeline and modal-based editing flow.

The user does **not** want a normal page layout that merely looks like a workflow. The workspace must behave like a canvas editor.

## Approved Decisions

### Canvas Behavior

- The workspace uses a real node canvas instead of stacked cards.
- Users can drag nodes to rearrange visual positions.
- Users can pan the full canvas.
- Users can zoom in and out.
- The workflow graph is fixed. Users cannot create new edges or reconnect nodes.

### Layout Direction

- The chosen visual direction is the single main-chain canvas.
- The graph should read left-to-right as one production line.
- The graph can wrap vertically on smaller screens, but desktop should prioritize one visible chain.

### Interaction Model

- Use pure dialogs for detail work.
- Do not add a persistent right-side inspector.
- Node surfaces stay compact.
- Detailed parameter editing, preview, re-trim, OCR editing, ASR editing, reference upload, and VLM grid inspection all happen in dialogs.

### Technical Direction

- Use React Flow for the editor surface.
- Keep shadcn/ui dialogs and existing modal shells.
- Reuse existing backend execution hooks from the current workspace state container.
- Keep internal engineering labels hidden from the main canvas.

## Visible Workflow

The visible nodes remain:

1. Upload Video
2. Boundary Detection
3. Shot Segments
4. OCR / ASR / Character References / VLM
5. Story Fix
6. Scene Logic
7. Voice + Export

Internal terms such as Layer 07, Layer 08, and Strict Shots remain backend-only concepts.

## Product Intent

The user wants the workspace to feel like an operator canvas:

- node-first
- spatial
- draggable
- navigable by canvas movement
- visually close to workflow tooling rather than dashboard tooling

This means the canvas itself is a primary interaction surface, not just a decorative container.

## Architecture

The redesign should split responsibilities into four layers:

### 1. Workspace State Container

The orchestration layer continues to own:

- active project
- upload switching
- boundary run flow
- shot generation
- VLM run flow
- story-fix flow
- current results and run states

This layer should remain separate from React Flow presentation logic.

### 2. React Flow Canvas Layer

The canvas layer owns:

- node definitions
- edge definitions
- initial node positions
- drag persistence in local state
- zoom and pan controls
- fit-view behavior
- minimap and background grid if enabled

This layer should not duplicate backend result state. It only consumes current workspace state and renders nodes.

### 3. Node UI Layer

Each visible workflow stage becomes a custom React Flow node component.

Each node should expose:

- title
- short status
- compact summary
- primary run button when relevant
- preview or settings buttons when relevant

The node should be compact enough to stay readable even when zoomed out.

### 4. Modal Layer

All heavy interactions remain in dialogs:

- boundary advanced settings
- boundary preview
- shot preview
- OCR shell
- ASR shell
- character references
- VLM grid preview
- story preview
- scene logic preview
- export shell

The canvas opens modals; it does not embed large editors inside nodes.

## React Flow Requirements

### Required

- draggable nodes
- pannable viewport
- zoom with wheel
- zoom controls
- fit-view or reset-view action
- fixed edges
- custom dark industrial styling

### Optional In Phase 1

- minimap
- snap grid
- subtle node entrance animation
- selected-node glow

### Not In Scope For This Phase

- free edge editing
- node creation
- node deletion
- custom branching
- user-authored graph topology

## Node Definitions

### Upload Video Node

- shows current project name and meta
- opens file picker
- successful upload switches active workspace project immediately
- should visually anchor the graph start

### Boundary Detection Node

- primary action runs the current multiscale plus dual-signal boundary chain
- settings action opens advanced modal
- preview action opens boundary preview modal
- summary can include route, mode, region count, and boundary count

### Shot Segments Node

- primary action runs strict-shot generation
- preview action opens shot preview modal
- summary can include shot count and shortest/longest shot

### OCR / ASR / Character References / VLM Node

- one combined node
- actions open separate dialogs for OCR, ASR, references, and VLM grid
- primary action runs VLM analysis
- summary can include active model, OCR on/off, ASR mode, and group count

### Story Fix Node

- primary action runs adjacent story reassignment and corrected event timeline
- preview action opens corrected event timeline preview
- summary can include pair count, event count, and selected clip count

### Scene Logic Node

- preview-only in this phase
- shows grouped functional clips:
  - build
  - peak
  - transition
  - result
- preview opens functional-clip modal

### Voice + Export Node

- shell-only for now
- can show whether export inputs are ready
- export action can remain placeholder until fully wired

## Visual Direction

The canvas should feel closer to Dify/Coze than to a settings dashboard.

### Desired Characteristics

- strong spatial composition
- visible connection flow
- dark industrial surface
- compact but high-contrast node cards
- clearer hierarchy between canvas and modal content

### Styling Rules

- preserve the current dark palette family
- reduce the feeling of large glass panels
- make the canvas itself the dominant visual object
- use a grid or blueprint background
- edges should be subtle but clearly readable
- selected or active nodes should have a brighter edge glow

### Toolbar

Phase 1 should include a small canvas toolbar for:

- zoom in
- zoom out
- reset view

The toolbar should stay minimal and not compete with node actions.

## Data And Execution Rules

- React Flow nodes must consume current state from the workspace orchestration layer.
- Existing API contracts stay unchanged in this phase.
- Existing modal preview components should be reused where possible.
- Existing local-only draft editing shells remain acceptable for now.
- The canvas must not introduce a parallel source of truth for result data.

## Phase 1 Scope

Build now:

- React Flow canvas
- fixed main-chain graph
- custom workflow nodes
- node dragging
- canvas pan and zoom
- minimal canvas toolbar
- pure dialog interactions
- existing backend actions wired through the new nodes

Do later:

- persisted node positions
- richer minimap behavior
- polished selection states
- better mobile graph ergonomics
- export execution from the node
- save-back support for re-trim and text editing shells

## Risks

### Risk 1: Canvas Becomes Visually Busy

Mitigation:

- keep node content compact
- move heavy detail into dialogs
- avoid descriptive helper copy inside nodes

### Risk 2: React Flow State Drifts From Workspace State

Mitigation:

- React Flow holds layout and selection only
- backend and result state stay in the workspace container

### Risk 3: Large Files During Migration

Mitigation:

- split canvas, node registry, node components, and modal registry into separate files
- keep each file below the project 500-line limit

## Testing Strategy

The implementation should verify:

- TypeScript passes
- production build passes
- canvas renders with fixed nodes and edges
- nodes can be dragged
- viewport can pan and zoom
- each node still triggers the same backend action chain as before
- each modal still opens correctly from the new node surface

## Expected Outcome

After this change, the workspace should no longer feel like a styled dashboard. It should feel like a true workflow editor with fixed production stages, draggable nodes, and canvas-based navigation, while keeping the existing backend pipeline and modal editing flow intact.
