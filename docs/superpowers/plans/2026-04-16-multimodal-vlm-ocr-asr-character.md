# Multimodal VLM OCR ASR Character Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Upgrade the strict-shot semantic pipeline so VLM decisions can use OCR text, automatic ASR text, character reference images, and speaker hints end to end.

**Architecture:** Keep the current strict-shot pipeline unchanged, then enrich the VLM analysis stage with optional multimodal evidence. Add small backend services for OCR extraction and automatic ASR transcription, extend the VLM prompt builder and normalization layer, then wire new request/response fields into the workspace UI.

**Tech Stack:** FastAPI, Pydantic, OpenCV, optional OCR/ASR Python providers, React 19, TypeScript, pnpm

---

### Task 1: Backend request and result model expansion

**Files:**
- Modify: `backend/api_models.py`
- Modify: `backend/tests/test_vlm_shot_analysis_multimodal.py`

- [ ] **Step 1: Write the failing test**

```python
def test_request_model_accepts_asr_and_character_references(self) -> None:
    payload = VlmShotAnalysisRequest.model_validate(
        {
            "shots": [{"index": 1, "startSec": 0.0, "endSec": 2.0, "durationSec": 2.0}],
            "vlmConfig": {
                "endpoint": "https://example.com/v1/chat/completions",
                "key": "demo",
                "model": "gpt-4.1",
            },
            "enableSubtitleRegion": True,
            "subtitleRegion": {"x": 0.05, "y": 0.78, "width": 0.9, "height": 0.18},
            "promptProfile": "short-video",
            "asrText": "Boss is scolding Nobita's father.",
            "asrSegments": [{"startSec": 0.5, "endSec": 1.6, "text": "You must finish it today."}],
            "characterReferences": [
                {"name": "大雄", "imageBase64": "demo-image"}
            ],
        }
    )

    assert payload.asrText == "Boss is scolding Nobita's father."
    assert len(payload.asrSegments) == 1
    assert payload.characterReferences[0].name == "大雄"
```

- [ ] **Step 2: Run test to verify it fails**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis_multimodal.VlmShotAnalysisMultimodalTests.test_request_model_accepts_asr_and_character_references`

Expected: FAIL because the request model does not accept the new fields yet.

- [ ] **Step 3: Write minimal implementation**

```python
class AsrSegmentRequest(BaseModel):
    startSec: float = Field(ge=0.0)
    endSec: float = Field(ge=0.0)
    text: str = Field(default="", max_length=4000)


class CharacterReferenceRequest(BaseModel):
    name: str = Field(min_length=1, max_length=80)
    imageBase64: str = Field(min_length=1)


class VlmShotAnalysisRequest(BaseModel):
    ...
    asrText: str | None = None
    asrSegments: list[AsrSegmentRequest] = Field(default_factory=list)
    characterReferences: list[CharacterReferenceRequest] = Field(default_factory=list)
```

- [ ] **Step 4: Run test to verify it passes**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis_multimodal.VlmShotAnalysisMultimodalTests.test_request_model_accepts_asr_and_character_references`

Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/api_models.py backend/tests/test_vlm_shot_analysis_multimodal.py
git commit -m "feat: extend vlm request models for multimodal inputs"
```

### Task 2: OCR and automatic ASR evidence services

**Files:**
- Create: `backend/services/ocr_text_extraction.py`
- Create: `backend/services/asr_transcription.py`
- Modify: `backend/requirements.txt`
- Test: `backend/tests/test_multimodal_semantic_context.py`

- [ ] **Step 1: Write the failing tests**

```python
def test_group_ocr_lines_are_compacted_in_order(self) -> None:
    evidence = compact_text_evidence([" boss ", "", "boss", "Finish it today"])
    self.assertEqual(evidence, ["boss", "Finish it today"])


def test_asr_segment_selection_returns_overlapping_lines(self) -> None:
    segments = [
        {"startSec": 0.0, "endSec": 1.0, "text": "hello"},
        {"startSec": 1.2, "endSec": 2.0, "text": "finish it today"},
    ]
    selected = select_asr_text_for_window(segments, 1.0, 2.2)
    self.assertEqual(selected, ["finish it today"])
```

- [ ] **Step 2: Run tests to verify they fail**

Run: `python -m unittest backend.tests.test_multimodal_semantic_context`

Expected: FAIL because helper functions do not exist yet.

- [ ] **Step 3: Write minimal implementation**

```python
def compact_text_evidence(lines: list[str]) -> list[str]:
    normalized: list[str] = []
    seen: set[str] = set()
    for raw in lines:
        text = " ".join(str(raw).split()).strip()
        if not text:
            continue
        key = text.casefold()
        if key in seen:
            continue
        seen.add(key)
        normalized.append(text)
    return normalized


def select_asr_text_for_window(
    segments: list[dict[str, Any]],
    start_sec: float,
    end_sec: float,
) -> list[str]:
    selected = []
    for segment in segments:
        if float(segment["endSec"]) < start_sec or float(segment["startSec"]) > end_sec:
            continue
        selected.append(str(segment.get("text", "")))
    return compact_text_evidence(selected)
```

- [ ] **Step 4: Run tests to verify they pass**

Run: `python -m unittest backend.tests.test_multimodal_semantic_context`

Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/services/ocr_text_extraction.py backend/services/asr_transcription.py backend/requirements.txt backend/tests/test_multimodal_semantic_context.py
git commit -m "feat: add optional ocr and asr evidence services"
```

### Task 3: VLM multimodal prompt and normalization

**Files:**
- Modify: `backend/services/multimodal_semantic_context.py`
- Modify: `backend/services/vlm_shot_analysis.py`
- Modify: `backend/timeline_routes.py`
- Test: `backend/tests/test_vlm_shot_analysis_multimodal.py`
- Test: `backend/tests/test_vlm_shot_analysis.py`

- [ ] **Step 1: Write the failing tests**

```python
def test_prompt_includes_ocr_asr_character_and_speaker_keys(self) -> None:
    prompt = _build_prompt_with_frames(
        shot_lines="- shot 1: 0.000s to 2.000s",
        images=[{"timeSec": 1.0, "jpegBase64": "demo", "kind": "scene"}],
        include_subtitle_region=True,
        prompt_profile="short-video",
        ocr_lines=["You must finish it today."],
        asr_lines=["Boss: finish it today."],
        character_references=[{"name": "大雄"}],
    )
    self.assertIn("speaker_hint", prompt)
    self.assertIn("You must finish it today.", prompt)
    self.assertIn("Boss: finish it today.", prompt)
    self.assertIn("大雄", prompt)


def test_normalized_group_result_returns_speaker_hint(self) -> None:
    result = _normalize_group_result(
        group_index=1,
        shot_group=[{"index": 1, "startSec": 0.0, "endSec": 2.0}],
        raw={
            "is_continuous_story": True,
            "highlight_score": 0.82,
            "peak_times": [1.0],
            "peak_role": "conflict",
            "reason": "Boss pressures the father.",
            "speaker_hint": "boss",
            "speaker_confidence": 0.76,
        },
    )
    self.assertEqual(result["speakerHint"], "boss")
    self.assertEqual(result["speakerConfidence"], 0.76)
```

- [ ] **Step 2: Run tests to verify they fail**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis_multimodal backend.tests.test_vlm_shot_analysis`

Expected: FAIL because prompt builder and normalized result do not expose the new fields.

- [ ] **Step 3: Write minimal implementation**

```python
return (
    build_multimodal_prompt_header(...)
    + "Required JSON keys: is_continuous_story, highlight_score, peak_times, peak_role, reason, speaker_hint, speaker_confidence.\n"
    + format_multimodal_evidence_block(
        ocr_lines=ocr_lines,
        asr_lines=asr_lines,
        character_references=character_references,
    )
    + f"Shots:\n{shot_lines}\n"
    + f"Frames in order:\n{frame_lines}"
)
```

- [ ] **Step 4: Run tests to verify they pass**

Run: `python -m unittest backend.tests.test_vlm_shot_analysis_multimodal backend.tests.test_vlm_shot_analysis`

Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add backend/services/multimodal_semantic_context.py backend/services/vlm_shot_analysis.py backend/timeline_routes.py backend/tests/test_vlm_shot_analysis_multimodal.py backend/tests/test_vlm_shot_analysis.py
git commit -m "feat: enrich vlm shot analysis with multimodal evidence"
```

### Task 4: Frontend VLM controls and result display

**Files:**
- Modify: `frontend/src/types/workspace.ts`
- Modify: `frontend/src/lib/workspace.ts`
- Modify: `frontend/src/components/workspace/workspace-config.ts`
- Modify: `frontend/src/components/workspace/workspace-semantic-controls.tsx`
- Modify: `frontend/src/components/workspace/workspace-semantic-results.tsx`
- Modify: `frontend/src/components/project-workspace.tsx`
- Create: `frontend/src/components/workspace/workspace-character-reference-list.tsx`

- [ ] **Step 1: Write the failing compile target**

```ts
type VlmShotGroup = {
  speakerHint: string;
  speakerConfidence: number;
};
```

- [ ] **Step 2: Run build to verify it fails**

Run: `pnpm -C frontend exec tsc --noEmit`

Expected: FAIL because the new types and props are missing.

- [ ] **Step 3: Write minimal implementation**

```ts
export type CharacterReferenceInput = {
  id: string;
  name: string;
  imageBase64: string;
};

export type RunVlmShotAnalysisPayload = {
  ...
  asrText: string;
  asrSegments: Array<{ startSec: number; endSec: number; text: string }>;
  characterReferences: CharacterReferenceInput[];
};
```

- [ ] **Step 4: Run build to verify it passes**

Run: `pnpm -C frontend exec tsc --noEmit`

Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add frontend/src/types/workspace.ts frontend/src/lib/workspace.ts frontend/src/components/workspace/workspace-config.ts frontend/src/components/workspace/workspace-semantic-controls.tsx frontend/src/components/workspace/workspace-semantic-results.tsx frontend/src/components/project-workspace.tsx frontend/src/components/workspace/workspace-character-reference-list.tsx
git commit -m "feat: wire multimodal vlm controls and results in workspace"
```

### Task 5: Git ignore cleanup for repo submission

**Files:**
- Create: `.gitignore`
- Modify: `backend/.gitignore`
- Modify: `frontend/.gitignore`

- [ ] **Step 1: Write the failing check**

```bash
git status --short
```

- [ ] **Step 2: Run check to verify noisy untracked files exist**

Run: `git status --short`

Expected: output includes transient folders such as `.venv-lighthouse`, `artifacts`, `.vscode`, and local test environments.

- [ ] **Step 3: Write minimal implementation**

```gitignore
.vscode/
artifacts/
_tmp_*/
text_video.mp4
backend/.venv*/
backend/.opencv-cuda-wheel-test/
.venv-lighthouse/
```

- [ ] **Step 4: Run check to verify noise is reduced**

Run: `git status --short`

Expected: transient local-only files are no longer listed unless already tracked.

- [ ] **Step 5: Commit**

```bash
git add .gitignore backend/.gitignore frontend/.gitignore
git commit -m "chore: ignore local artifacts and environments"
```
