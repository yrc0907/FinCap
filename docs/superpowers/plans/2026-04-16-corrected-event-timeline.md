# Corrected Event Timeline Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build a corrected event timeline that applies adjacent tail reassignment results to VLM groups so later narration never crosses into the wrong event.

**Architecture:** Keep VLM group analysis and adjacent reassignment separate, then add a deterministic corrected-event pass that trims a left group and extends the next group at the returned reassignment timestamp. Expose the corrected events through the timeline API and show them in the existing semantic results UI.

**Tech Stack:** Python backend services + FastAPI routes + TypeScript React frontend + unittest + pnpm build

---

### Task 1: Define corrected event behavior in tests

**Files:**
- Create: `backend/tests/test_corrected_event_timeline.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Write the failing test**

```python
def test_trims_left_event_and_extends_right_event():
    result = generate_corrected_event_timeline(
        groups=[
            {"index": 1, "startSec": 0.0, "endSec": 10.0},
            {"index": 2, "startSec": 10.0, "endSec": 20.0},
        ],
        adjacent_pairs=[
            {
                "leftGroupIndex": 1,
                "rightGroupIndex": 2,
                "shouldReassignTail": True,
                "reassignFromSec": 8.5,
            }
        ],
    )
    assert [(item["startSec"], item["endSec"]) for item in result["events"]] == [
        (0.0, 8.5),
        (8.5, 20.0),
    ]
```

- [ ] **Step 2: Run test to verify it fails**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: FAIL with `ModuleNotFoundError` or missing function errors because corrected event service does not exist yet.

- [ ] **Step 3: Write boundary-aligned and chained-adjustment tests**

```python
def test_boundary_aligned_reassignment_keeps_same_ranges():
    ...

def test_middle_event_can_receive_prev_tail_and_trim_to_next():
    ...
```

- [ ] **Step 4: Run test to verify it still fails for the right reason**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: FAIL from missing implementation, not syntax or import errors.

### Task 2: Implement corrected event generation service

**Files:**
- Create: `backend/services/corrected_event_timeline.py`
- Modify: `backend/api_models.py`
- Modify: `backend/timeline_routes.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Write minimal service implementation**

```python
def generate_corrected_event_timeline(groups, adjacent_pairs):
    ...
```

Return:
- `events`
- `summary`
- `inputGroupCount`
- `inputPairCount`

Each event should include:
- `index`
- `originalStartSec`
- `originalEndSec`
- `startSec`
- `endSec`
- `durationSec`
- `sourceGroupIndexes`
- `changed`
- `reasons`

- [ ] **Step 2: Add request models and route**

```python
@router.post("/corrected-event-timeline")
async def run_corrected_event_timeline(...):
    ...
```

- [ ] **Step 3: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: PASS

### Task 3: Expose corrected events in the frontend

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-semantic-results.tsx`
- Modify: `frontend/src/components/workspace/workspace-results-panel.tsx`

- [ ] **Step 1: Add frontend types and API helper**

```ts
export type CorrectedEventTimelineResult = { ... }
export const runCorrectedEventTimeline = async (...) => { ... }
```

- [ ] **Step 2: Auto-run corrected events after adjacent pass**

```ts
const adjacentResult = await runAdjacentStoryReassignment(...);
const correctedResult = await runCorrectedEventTimeline(...);
```

- [ ] **Step 3: Print and render corrected events**

Console:
- `[Workspace] Corrected event timeline`

UI:
- show corrected event count
- show original range vs corrected range
- show reasons when changed

- [ ] **Step 4: Keep touched files under 500 lines**

Split or compress only where needed to stay within the project rule.

### Task 4: Verify end-to-end behavior

**Files:**
- Verify only

- [ ] **Step 1: Run backend tests**

Run: `python -m unittest discover -s tests -p "test_*.py" -v`
Expected: all tests pass

- [ ] **Step 2: Run frontend build**

Run: `pnpm --dir frontend build`
Expected: build succeeds

- [ ] **Step 3: Check changed file line counts**

Run:

```powershell
@( 
  'backend/services/corrected_event_timeline.py',
  'backend/tests/test_corrected_event_timeline.py',
  'backend/api_models.py',
  'backend/timeline_routes.py',
  'frontend/src/components/project-workspace.tsx',
  'frontend/src/components/workspace/workspace-semantic-results.tsx',
  'frontend/src/components/workspace/workspace-results-panel.tsx',
  'frontend/src/lib/workspace.ts',
  'frontend/src/types/workspace.ts'
) | ForEach-Object { "$(($_))`t$((Get-Content $_).Count)" }
```

Expected: every touched file is `<= 500` lines.
