# React Flow Workspace Canvas Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace the current stacked workspace layout with a real React Flow editor that supports draggable nodes, pannable and zoomable canvas navigation, fixed workflow edges, and pure modal interactions.

**Architecture:** Keep `ProjectWorkspace` as the orchestration container and move visual composition into a React Flow canvas layer. Store only graph layout and selection state inside the canvas; keep backend execution state, results, and modal data in the existing workspace state container. Reuse the current modal shells and node action handlers, but render them from custom React Flow nodes instead of grid cards.

**Tech Stack:** React 19, TypeScript, React Flow (`@xyflow/react`), shadcn/ui dialogs, Tailwind CSS, Vitest, React Testing Library, pnpm

---

### Task 1: Add React Flow and Frontend Test Harness

**Files:**
- Modify: `frontend/package.json`
- Modify: `frontend/pnpm-lock.yaml`
- Create: `frontend/vitest.config.ts`
- Create: `frontend/src/test/setup.ts`
- Create: `frontend/src/components/workspace/workflow-canvas-graph.test.ts`

- [ ] **Step 1: Write the failing test for fixed workflow graph shape**

```ts
import { describe, expect, it } from "vitest";

import { buildWorkflowCanvasGraph } from "./workflow-canvas-graph";

describe("buildWorkflowCanvasGraph", () => {
  it("returns one fixed main-chain graph with draggable nodes", () => {
    const graph = buildWorkflowCanvasGraph();

    expect(graph.nodes.map((node) => node.id)).toEqual([
      "upload",
      "boundary",
      "shots",
      "semantic",
      "story",
      "scene-logic",
      "export",
    ]);
    expect(graph.edges.map((edge) => edge.id)).toEqual([
      "upload-boundary",
      "boundary-shots",
      "shots-semantic",
      "semantic-story",
      "story-scene-logic",
      "scene-logic-export",
    ]);
    expect(graph.nodes.every((node) => node.draggable !== false)).toBe(true);
  });
});
```

- [ ] **Step 2: Run the test and verify it fails because graph builder does not exist**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas-graph.test.ts`

Expected: FAIL with module-not-found or symbol-not-found error for `buildWorkflowCanvasGraph`

- [ ] **Step 3: Install the required runtime and test packages**

Run:

```bash
pnpm --dir frontend add @xyflow/react
pnpm --dir frontend add -D vitest jsdom @testing-library/react @testing-library/jest-dom
```

- [ ] **Step 4: Add minimal Vitest config and setup**

`frontend/vitest.config.ts`

```ts
import path from "path";
import { defineConfig } from "vitest/config";
import react from "@vitejs/plugin-react";
import tailwindcss from "@tailwindcss/vite";

export default defineConfig({
  plugins: [react(), tailwindcss()],
  resolve: {
    alias: {
      "@": path.resolve(__dirname, "./src"),
    },
  },
  test: {
    environment: "jsdom",
    globals: true,
    setupFiles: ["./src/test/setup.ts"],
  },
});
```

`frontend/src/test/setup.ts`

```ts
import "@testing-library/jest-dom/vitest";
```

- [ ] **Step 5: Create the minimal graph builder implementation**

`frontend/src/components/workspace/workflow-canvas-graph.ts`

```ts
import type { Edge, Node } from "@xyflow/react";

export type WorkflowCanvasNodeData = {
  kind:
    | "upload"
    | "boundary"
    | "shots"
    | "semantic"
    | "story"
    | "scene-logic"
    | "export";
};

export function buildWorkflowCanvasGraph(): {
  nodes: Array<Node<WorkflowCanvasNodeData>>;
  edges: Edge[];
} {
  return {
    nodes: [
      { id: "upload", type: "workflow", position: { x: 40, y: 80 }, data: { kind: "upload" } },
      { id: "boundary", type: "workflow", position: { x: 340, y: 80 }, data: { kind: "boundary" } },
      { id: "shots", type: "workflow", position: { x: 640, y: 80 }, data: { kind: "shots" } },
      { id: "semantic", type: "workflow", position: { x: 980, y: 80 }, data: { kind: "semantic" } },
      { id: "story", type: "workflow", position: { x: 1320, y: 80 }, data: { kind: "story" } },
      { id: "scene-logic", type: "workflow", position: { x: 1660, y: 80 }, data: { kind: "scene-logic" } },
      { id: "export", type: "workflow", position: { x: 1980, y: 80 }, data: { kind: "export" } },
    ],
    edges: [
      { id: "upload-boundary", source: "upload", target: "boundary", animated: false },
      { id: "boundary-shots", source: "boundary", target: "shots", animated: false },
      { id: "shots-semantic", source: "shots", target: "semantic", animated: false },
      { id: "semantic-story", source: "semantic", target: "story", animated: false },
      { id: "story-scene-logic", source: "story", target: "scene-logic", animated: false },
      { id: "scene-logic-export", source: "scene-logic", target: "export", animated: false },
    ],
  };
}
```

- [ ] **Step 6: Run the test to verify it passes**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas-graph.test.ts`

Expected: PASS

- [ ] **Step 7: Commit**

```bash
git add frontend/package.json frontend/pnpm-lock.yaml frontend/vitest.config.ts frontend/src/test/setup.ts frontend/src/components/workspace/workflow-canvas-graph.ts frontend/src/components/workspace/workflow-canvas-graph.test.ts
git commit -m "test: add react flow workspace graph coverage"
```

### Task 2: Build the React Flow Canvas Shell

**Files:**
- Create: `frontend/src/components/workspace/workflow-canvas-node.tsx`
- Create: `frontend/src/components/workspace/workflow-canvas.tsx`
- Create: `frontend/src/components/workspace/workflow-canvas-controls.tsx`
- Modify: `frontend/src/index.css`
- Test: `frontend/src/components/workspace/workflow-canvas.test.tsx`

- [ ] **Step 1: Write the failing render test for the canvas shell**

```tsx
import { render, screen } from "@testing-library/react";
import { describe, expect, it, vi } from "vitest";

import { WorkflowCanvas } from "./workflow-canvas";

describe("WorkflowCanvas", () => {
  it("renders fixed workflow labels and toolbar buttons", () => {
    render(
      <WorkflowCanvas
        nodes={[]}
        edges={[]}
        nodeTypes={{}}
        onNodesChange={vi.fn()}
      />,
    );

    expect(screen.getByRole("button", { name: /zoom in/i })).toBeInTheDocument();
    expect(screen.getByRole("button", { name: /zoom out/i })).toBeInTheDocument();
    expect(screen.getByRole("button", { name: /reset view/i })).toBeInTheDocument();
  });
});
```

- [ ] **Step 2: Run the test and verify it fails because `WorkflowCanvas` does not exist**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas.test.tsx`

Expected: FAIL with module-not-found or symbol-not-found error for `WorkflowCanvas`

- [ ] **Step 3: Implement the minimal canvas wrapper and toolbar**

`frontend/src/components/workspace/workflow-canvas-controls.tsx`

```tsx
import { Minus, Plus, ScanSearch } from "lucide-react";

import { Button } from "../ui/button";

type WorkflowCanvasControlsProps = {
  onZoomIn: () => void;
  onZoomOut: () => void;
  onResetView: () => void;
};

export function WorkflowCanvasControls({
  onZoomIn,
  onZoomOut,
  onResetView,
}: WorkflowCanvasControlsProps) {
  return (
    <div className="absolute top-4 right-4 z-20 flex items-center gap-2 rounded-2xl border border-white/10 bg-black/70 p-2">
      <Button aria-label="Zoom Out" size="icon" variant="ghost" onClick={onZoomOut}><Minus /></Button>
      <Button aria-label="Zoom In" size="icon" variant="ghost" onClick={onZoomIn}><Plus /></Button>
      <Button aria-label="Reset View" size="icon" variant="ghost" onClick={onResetView}><ScanSearch /></Button>
    </div>
  );
}
```

`frontend/src/components/workspace/workflow-canvas.tsx`

```tsx
import {
  Background,
  ControlsProps,
  MiniMap,
  ReactFlow,
  ReactFlowProvider,
  useReactFlow,
  type Edge,
  type Node,
  type NodeChange,
  type NodeTypes,
} from "@xyflow/react";

import "@xyflow/react/dist/style.css";

import { WorkflowCanvasControls } from "./workflow-canvas-controls";

type WorkflowCanvasProps<TNodeData> = {
  nodes: Array<Node<TNodeData>>;
  edges: Edge[];
  nodeTypes: NodeTypes;
  onNodesChange: (changes: NodeChange[]) => void;
};
```

Add an inner component that uses `useReactFlow()` and renders:

- `<ReactFlow fitView nodesDraggable panOnDrag zoomOnScroll />`
- `<Background />`
- `<MiniMap />`
- `<WorkflowCanvasControls />`

- [ ] **Step 4: Add minimal custom node chrome**

`frontend/src/components/workspace/workflow-canvas-node.tsx`

```tsx
import { memo } from "react";
import { Handle, Position, type NodeProps } from "@xyflow/react";

import type { WorkflowCanvasNodeData } from "./workflow-canvas-graph";

export const WorkflowCanvasNode = memo(function WorkflowCanvasNode({
  data,
}: NodeProps<WorkflowCanvasNodeData>) {
  return (
    <div className="min-w-[220px] rounded-[28px] border border-white/12 bg-[#080808]/95 p-4 shadow-[0_0_30px_rgba(255,255,255,0.06)]">
      <Handle type="target" position={Position.Left} className="!border-0 !bg-white/40" />
      <div className="text-[10px] font-mono uppercase tracking-[0.2em] text-white/30">{data.kind}</div>
      <Handle type="source" position={Position.Right} className="!border-0 !bg-white/40" />
    </div>
  );
});
```

- [ ] **Step 5: Add canvas surface styling**

Append to `frontend/src/index.css`:

```css
.workflow-editor {
  background-image:
    linear-gradient(rgba(255, 255, 255, 0.04) 1px, transparent 1px),
    linear-gradient(90deg, rgba(255, 255, 255, 0.04) 1px, transparent 1px),
    radial-gradient(circle at top left, rgba(255, 255, 255, 0.05), transparent 35%);
  background-size: 28px 28px, 28px 28px, auto;
}
```

- [ ] **Step 6: Run the test to verify it passes**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas.test.tsx`

Expected: PASS

- [ ] **Step 7: Commit**

```bash
git add frontend/src/components/workspace/workflow-canvas-node.tsx frontend/src/components/workspace/workflow-canvas.tsx frontend/src/components/workspace/workflow-canvas-controls.tsx frontend/src/components/workspace/workflow-canvas.test.tsx frontend/src/index.css
git commit -m "feat: add react flow canvas shell"
```

### Task 3: Map Existing Workflow Stages Into Custom React Flow Nodes

**Files:**
- Modify: `frontend/src/components/workspace/workspace-upload-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-boundary-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-shot-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-semantic-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-story-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-scene-logic-node.tsx`
- Modify: `frontend/src/components/workspace/workspace-export-node.tsx`
- Modify: `frontend/src/components/workspace/workflow-canvas-graph.ts`
- Create: `frontend/src/components/workspace/workflow-canvas-node-registry.tsx`
- Test: `frontend/src/components/workspace/workflow-canvas-node-registry.test.tsx`

- [ ] **Step 1: Write the failing test for node registry labels**

```tsx
import { render, screen } from "@testing-library/react";
import { describe, expect, it, vi } from "vitest";

import { WorkflowCanvasNodeRenderer } from "./workflow-canvas-node-registry";

describe("WorkflowCanvasNodeRenderer", () => {
  it("renders the visible workflow node labels", () => {
    render(
      <WorkflowCanvasNodeRenderer
        kind="boundary"
        state={{} as never}
        openPreview={vi.fn()}
      />,
    );

    expect(screen.getByText("边界检测")).toBeInTheDocument();
  });
});
```

- [ ] **Step 2: Run the test and verify it fails because registry component does not exist**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas-node-registry.test.tsx`

Expected: FAIL with module-not-found or symbol-not-found error

- [ ] **Step 3: Refactor each existing node component into body content that can render inside React Flow**

Keep the current concise node content model, but remove outer page layout assumptions. Each file should keep:

- title
- status
- compact metric chips
- primary button
- preview/settings buttons

The outer wrapper should become suitable for embedding inside `WorkflowCanvasNode`.

- [ ] **Step 4: Create the node registry and wire node kinds to actual components**

`frontend/src/components/workspace/workflow-canvas-node-registry.tsx`

```tsx
import type { ProjectWorkspaceFlowState } from "./use-project-workspace-state";
import type { WorkspacePreviewKind } from "./workspace-preview-state";

type WorkflowCanvasNodeRendererProps = {
  kind: "upload" | "boundary" | "shots" | "semantic" | "story" | "scene-logic" | "export";
  state: ProjectWorkspaceFlowState;
  openPreview: (kind: Exclude<WorkspacePreviewKind, null>) => void;
};
```

Implement a `switch (kind)` that returns the corresponding existing node component with current handlers.

- [ ] **Step 5: Update graph node data so each React Flow node carries the workflow kind only**

Keep node data narrow:

```ts
data: { kind: "boundary" }
```

Pass the full `state` object through the custom node component factory, not through per-node graph duplication.

- [ ] **Step 6: Run the test to verify it passes**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas-node-registry.test.tsx`

Expected: PASS

- [ ] **Step 7: Commit**

```bash
git add frontend/src/components/workspace/workspace-upload-node.tsx frontend/src/components/workspace/workspace-boundary-node.tsx frontend/src/components/workspace/workspace-shot-node.tsx frontend/src/components/workspace/workspace-semantic-node.tsx frontend/src/components/workspace/workspace-story-node.tsx frontend/src/components/workspace/workspace-scene-logic-node.tsx frontend/src/components/workspace/workspace-export-node.tsx frontend/src/components/workspace/workflow-canvas-graph.ts frontend/src/components/workspace/workflow-canvas-node-registry.tsx frontend/src/components/workspace/workflow-canvas-node-registry.test.tsx
git commit -m "feat: map workspace stages into react flow nodes"
```

### Task 4: Replace the Old Grid Layout With React Flow Canvas

**Files:**
- Modify: `frontend/src/components/workspace/workspace-flow-layout.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-preview-state.ts`
- Test: `frontend/src/components/workspace/workspace-flow-layout.test.tsx`

- [ ] **Step 1: Write the failing integration test for modal triggers from the canvas**

```tsx
import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import { describe, expect, it, vi } from "vitest";

import { WorkspaceFlowLayout } from "./workspace-flow-layout";

describe("WorkspaceFlowLayout", () => {
  it("opens the boundary preview dialog from the boundary node", async () => {
    const user = userEvent.setup();
    render(<WorkspaceFlowLayout state={{} as never} />);

    await user.click(screen.getByRole("button", { name: /preview/i }));

    expect(screen.getByText("Preview")).toBeInTheDocument();
  });
});
```

- [ ] **Step 2: Run the test and verify it fails because the old layout does not render through React Flow**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workspace-flow-layout.test.tsx`

Expected: FAIL for missing predictable React Flow integration or mismatched controls

- [ ] **Step 3: Replace the current grid canvas with React Flow composition**

Inside `frontend/src/components/workspace/workspace-flow-layout.tsx`:

- keep the current modal state hooks
- keep OCR and ASR draft state
- create nodes and edges from `buildWorkflowCanvasGraph()`
- keep node positions in local state with `useNodesState`
- render `<WorkflowCanvas />`
- keep all existing `WorkspacePreviewDialog` instances below the canvas

Do **not** duplicate modal logic. Move only the visible node rendering into React Flow.

- [ ] **Step 4: Keep `ProjectWorkspace` thin**

`frontend/src/components/project-workspace.tsx` should continue to:

- create workspace state
- render header
- render the new flow layout

Do not move orchestration out of `useProjectWorkspaceState`.

- [ ] **Step 5: Run the integration test to verify it passes**

Run: `pnpm --dir frontend exec vitest run frontend/src/components/workspace/workspace-flow-layout.test.tsx`

Expected: PASS

- [ ] **Step 6: Commit**

```bash
git add frontend/src/components/workspace/workspace-flow-layout.tsx frontend/src/components/project-workspace.tsx frontend/src/components/workspace/workspace-preview-state.ts frontend/src/components/workspace/workspace-flow-layout.test.tsx
git commit -m "feat: replace workspace grid with react flow editor"
```

### Task 5: Verify Production Build and Workspace Behavior

**Files:**
- Use existing frontend project files only

- [ ] **Step 1: Run targeted Vitest coverage for new React Flow workspace files**

Run:

```bash
pnpm --dir frontend exec vitest run frontend/src/components/workspace/workflow-canvas-graph.test.ts frontend/src/components/workspace/workflow-canvas.test.tsx frontend/src/components/workspace/workflow-canvas-node-registry.test.tsx frontend/src/components/workspace/workspace-flow-layout.test.tsx
```

Expected: PASS

- [ ] **Step 2: Run TypeScript validation**

Run: `pnpm --dir frontend exec tsc --noEmit`

Expected: PASS

- [ ] **Step 3: Run production build**

Run: `pnpm --dir frontend run build:web`

Expected: PASS

- [ ] **Step 4: Manual browser verification**

Open the workspace and verify:

- nodes are draggable
- canvas pans by drag
- mouse wheel zooms
- zoom toolbar works
- reset view works
- fixed edges remain intact
- each node still opens the same modal shells as before
- run buttons still trigger the existing backend actions

- [ ] **Step 5: Commit**

```bash
git add frontend
git commit -m "feat: finalize react flow workspace canvas"
```
