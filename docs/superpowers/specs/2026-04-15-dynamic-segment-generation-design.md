# Dynamic Segment Generation Design

## Goal

Add Chapter 8 dynamic segment generation after Layer08 so boundary candidates become usable non-uniform timeline segments.

## Scope

This design covers:

- boundary cleanup rules
- dynamic segment generation
- legality validation
- tail-first correction
- backend and workspace integration

This design does not include Chapter 9 event merging.

## Current Inputs

Layer08 already returns:

- ordered boundary candidates
- per-boundary confidence
- per-boundary source metadata
- video duration metadata

These become the only required input for dynamic segment generation V1.

## Output

The new stage outputs:

- ordered dynamic segments
- normalized segment start/end pairs
- segment duration statistics
- abnormal short segment warnings
- preserved source boundaries used to create each segment

## Rules

### Boundary Cleanup

Before generating segments, normalize Layer08 boundaries by:

- sorting by `timeSec`
- removing duplicate timestamps inside a tiny epsilon
- dropping boundaries at or outside the legal video range

### Dynamic Segment Generation

Generate segments by splitting:

- `0.0 -> boundary[0]`
- `boundary[i] -> boundary[i + 1]`
- `boundary[last] -> video_duration`

### Tail-First Correction

If a generated segment is too short:

- prefer merging it into the following segment when possible
- otherwise merge it into the previous segment
- keep earlier segment starts fixed whenever possible

This preserves the “do not randomly move the front half” rule from the advanced design doc while keeping the implementation lightweight.

### Legality Validation

The validator must guarantee:

- no overlaps
- no gaps
- continuous start/end chain
- first segment starts at `0.0`
- last segment ends at video duration
- all durations are positive

### Warnings

Warn when:

- any segment is below the abnormal-short threshold
- cleanup removed invalid boundaries

## Default Strategy

V1 uses a rules-only strategy:

- minimum segment length threshold
- abnormal-short threshold
- maximum segment length reporting
- tail-first merge for short fragments

This keeps runtime cheap and deterministic.

## API and UI

Add a new backend endpoint and workspace stage after Layer08.

The workspace should show:

- input boundary count
- output segment count
- shortest segment
- longest segment
- each segment start/end/duration

## Logging

Keep console logs in Chinese for this stage:

- `【开始】动态片段生成开始`
- `【过程】候选边界数量`
- `【过程】最终动态片段数量`
- `【过程】最短片段、最长片段`
- `【完成】动态片段生成完成`
- `【警告】存在异常短片段`
- `【错误】片段生成失败`
- `【回退】退回最近可用边界版本`

## Testing

Add tests for:

- direct boundary-to-segment conversion
- short tail merge behavior
- legality validation
- API contract

Run the sample video and report:

- segment count
- segment ranges
- shortest/longest durations
