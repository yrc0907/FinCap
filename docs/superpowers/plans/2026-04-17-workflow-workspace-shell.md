# Workflow Workspace Shell Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace the current layer-oriented workspace UI with a workflow-node shell that preserves the existing backend execution hooks and adds preview modal scaffolding for each visible stage.

**Architecture:** Keep all backend orchestration inside `ProjectWorkspace`, but move visual structure into a workflow canvas made of small node components plus shared preview dialog shells. Reuse existing result data for preview lists and keep unsupported editing interactions as local draft-only shells.

**Tech Stack:** React 19, TypeScript, existing shadcn/ui primitives, Tailwind CSS, pnpm, existing workspace backend APIs

---

### Task 1: Documented Workflow Model

**Files:**
- Create: `docs/superpowers/specs/2026-04-17-workflow-workspace-shell-design.md`
- Create: `docs/superpowers/plans/2026-04-17-workflow-workspace-shell.md`

- [ ] Capture the approved workflow-shell design and node definitions in a spec document.
- [ ] Save the implementation plan alongside the spec so later edits can follow the same workflow structure.

### Task 2: Workspace Orchestration Split

**Files:**
- Modify: `frontend/src/components/project-workspace.tsx`
- Create: `frontend/src/components/workspace/workspace-flow-layout.tsx`
- Create: `frontend/src/components/workspace/workspace-preview-state.ts`

- [ ] Move display composition out of `ProjectWorkspace` so it owns only backend execution state and node event handlers.
- [ ] Add shared preview-state helpers so node cards and dialogs use one consistent modal state model.
- [ ] Keep all current backend execution functions working without changing payload contracts.

### Task 3: Workspace Upload Node

**Files:**
- Modify: `frontend/src/App.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`
- Create: `frontend/src/components/workspace/workspace-upload-node.tsx`

- [ ] Pass the existing upload handler from `App` into the workspace.
- [ ] Add a workflow upload node that can upload a new video while already inside the workspace.
- [ ] Switch the active project to the newly uploaded project after success so the home page and workspace remain in sync.

### Task 4: Workflow Node Shell Components

**Files:**
- Create: `frontend/src/components/workspace/workflow-node-card.tsx`
- Create: `frontend/src/components/workspace/workflow-node-connector.tsx`
- Create: `frontend/src/components/workspace/workspace-boundary-node.tsx`
- Create: `frontend/src/components/workspace/workspace-shot-node.tsx`
- Create: `frontend/src/components/workspace/workspace-semantic-node.tsx`
- Create: `frontend/src/components/workspace/workspace-story-node.tsx`
- Create: `frontend/src/components/workspace/workspace-scene-logic-node.tsx`
- Create: `frontend/src/components/workspace/workspace-export-node.tsx`

- [ ] Add a reusable workflow node shell component with title, status, actions, and content slots.
- [ ] Render the approved workflow order as visible node blocks on a single canvas.
- [ ] Hide internal backend terminology from node labels and action copy.

### Task 5: Shared Preview Dialog Scaffolding

**Files:**
- Create: `frontend/src/components/ui/dialog.tsx`
- Create: `frontend/src/components/workspace/workspace-preview-dialog.tsx`
- Create: `frontend/src/components/workspace/workspace-clip-editor-shell.tsx`
- Create: `frontend/src/components/workspace/workspace-preview-video.tsx`

- [ ] Add a shadcn-style dialog primitive for workspace previews.
- [ ] Build one reusable preview dialog wrapper used by all workflow nodes.
- [ ] Add a shared clip editor shell with local-only start/end draft controls for boundary and shot editing previews.

### Task 6: Boundary And Shot Preview Shells

**Files:**
- Create: `frontend/src/components/workspace/workspace-boundary-preview.tsx`
- Create: `frontend/src/components/workspace/workspace-shot-preview.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`

- [ ] Derive boundary preview rows from the current boundary result and show timestamps plus nearby ranges.
- [ ] Derive shot preview rows from strict-shot results and show playable ranges.
- [ ] Wire preview dialogs from the boundary node and shot node.

### Task 7: OCR / ASR / Reference / VLM Shells

**Files:**
- Create: `frontend/src/components/workspace/workspace-ocr-shell.tsx`
- Create: `frontend/src/components/workspace/workspace-asr-shell.tsx`
- Create: `frontend/src/components/workspace/workspace-character-reference-shell.tsx`
- Create: `frontend/src/components/workspace/workspace-vlm-grid-shell.tsx`
- Modify: `frontend/src/components/workspace/workspace-character-reference-list.tsx`

- [ ] Add OCR region-shell UI with current subtitle region controls and a visual overlay shell.
- [ ] Add ASR draft segment editor shell.
- [ ] Reuse existing character reference upload behavior inside a dedicated modal shell.
- [ ] Add a VLM grid preview shell that shows planned frame slots and replacement placeholders before real frame editing is wired.

### Task 8: Story Fix And Scene Logic Preview Shells

**Files:**
- Create: `frontend/src/components/workspace/workspace-story-preview.tsx`
- Create: `frontend/src/components/workspace/workspace-scene-logic-preview.tsx`
- Modify: `frontend/src/types/workspace.ts`

- [ ] Show corrected event timeline data in a story-fix preview dialog.
- [ ] Extend frontend result typing so `functionalClips` returned by the backend can be rendered safely.
- [ ] Group functional clips into user-facing categories for the scene-logic preview shell.

### Task 9: Header And Layout Polish

**Files:**
- Modify: `frontend/src/components/workspace/project-workspace-header.tsx`
- Modify: `frontend/src/index.css`

- [ ] Update the workspace header copy to match the workflow-console concept instead of layer names.
- [ ] Add subtle grid and connector styling to support the industrial workflow look.

### Task 10: Verification

**Files:**
- Use existing frontend project files only

- [ ] Run `pnpm -C frontend exec tsc --noEmit` and fix any type issues.
- [ ] Run `pnpm -C frontend build:web` and fix any production build issues.
- [ ] Manually inspect the new workspace node flow in the browser and confirm that existing backend actions still trigger from the new shell.
