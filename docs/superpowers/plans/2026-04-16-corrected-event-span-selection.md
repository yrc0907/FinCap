# Corrected Event Span Selection Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add keep / bridge / drop span tagging inside corrected events so narration can stay within clean event boundaries while still skipping low-value transitions.

**Architecture:** Extend the corrected event timeline service so each corrected event is intersected with strict shots, then assign deterministic labels per child span from group highlight, peak times, and role signals. Merge adjacent child spans with the same label inside one corrected event and return them in the existing corrected timeline response.

**Tech Stack:** Python backend services + FastAPI + TypeScript React + unittest + pnpm build

---

### Task 1: Lock span-label behavior in tests

**Files:**
- Modify: `backend/tests/test_corrected_event_timeline.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Write a failing keep-span test**

```python
def test_marks_peak_overlap_span_as_keep():
    result = generate_corrected_event_timeline(
        groups=[...],
        adjacent_pairs=[...],
        shots=[...],
    )
    assert result["events"][1]["narrationSpans"][1]["label"] == "keep"
```

- [ ] **Step 2: Write a failing drop-span test**

```python
def test_marks_low_transition_middle_span_as_drop():
    ...
```

- [ ] **Step 3: Write a failing merge test**

```python
def test_merges_adjacent_bridge_spans_within_same_event():
    ...
```

- [ ] **Step 4: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: FAIL because narration span fields are not implemented yet.

### Task 2: Extend corrected event service

**Files:**
- Modify: `backend/services/corrected_event_timeline.py`
- Modify: `backend/api_models.py`
- Modify: `backend/timeline_routes.py`
- Test: `backend/tests/test_corrected_event_timeline.py`

- [ ] **Step 1: Add shots input to corrected event generation**

```python
def generate_corrected_event_timeline(groups, adjacent_pairs, shots, config=None):
    ...
```

- [ ] **Step 2: Build child spans from corrected-event/shot intersections**

Each child span must keep:
- `startSec`
- `endSec`
- `sourceShotIndexes`
- `sourceGroupIndexes`

- [ ] **Step 3: Assign labels**

Rules for first version:
- peak overlap -> `keep`
- conflict/payoff with solid highlight -> `keep`
- first/last support span or setup/buildup/character-focus -> `bridge`
- low-score transition in the middle -> `drop`

- [ ] **Step 4: Merge adjacent spans with same label inside one event**

- [ ] **Step 5: Run focused tests**

Run: `python -m unittest discover -s tests -p "test_corrected_event_timeline.py" -v`
Expected: PASS

### Task 3: Expose spans in the frontend

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/project-workspace.tsx`
- Modify: `frontend/src/components/workspace/workspace-semantic-results.tsx`

- [ ] **Step 1: Extend corrected timeline request/response types**

Add:
- `shots` in corrected timeline request
- `narrationSpans` in corrected events
- span summary counts

- [ ] **Step 2: Pass strict shots into corrected timeline API call**

```ts
const correctedPayload = {
  groups: vlmShotAnalysisResult.groups,
  adjacentPairs: nextResult.pairs,
  shots: strictShotResult.shots,
}
```

- [ ] **Step 3: Render span labels**

For each corrected event, show:
- corrected range
- narration spans
- `keep / bridge / drop`

### Task 4: Verify end-to-end

**Files:**
- Verify only

- [ ] **Step 1: Run backend tests**

Run: `python -m unittest discover -s tests -p "test_*.py" -v`
Expected: all tests pass

- [ ] **Step 2: Run frontend build**

Run: `pnpm --dir frontend build`
Expected: build succeeds

- [ ] **Step 3: Check line counts**

Run:

```powershell
@( 
  'backend/services/corrected_event_timeline.py',
  'backend/tests/test_corrected_event_timeline.py',
  'frontend/src/components/project-workspace.tsx',
  'frontend/src/components/workspace/workspace-semantic-results.tsx',
  'frontend/src/lib/workspace.ts',
  'frontend/src/types/workspace.ts'
) | ForEach-Object { "$(($_))`t$((Get-Content $_).Count)" }
```

Expected: every touched file is `<= 500` lines.
