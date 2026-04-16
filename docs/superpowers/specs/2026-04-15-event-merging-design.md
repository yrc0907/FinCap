# Event Merging Design

## Goal

Add Chapter 9 event merging after dynamic segment generation so obviously fragmented adjacent segments can be merged into more usable event ranges.

## Scope

This design covers a generic rule-based event merging stage.

It does not attempt true semantic understanding and does not use a VLM.

## Input

The stage consumes:

- Chapter 8 dynamic segments
- Layer08 boundary candidates

Dynamic segments define the legal timeline pieces.
Boundary candidates provide the split-strength signal between neighboring segments.

## Output

The stage outputs:

- merged event ranges
- kept and merged boundary timestamps
- merge reasons
- event count and duration stats

## Generic Rule Model

Because V1 does not use a VLM, it infers “same event” from continuity proxies:

- weak or medium boundary strength
- short neighboring segments
- current event still too short
- maximum event length guardrail

## Merge Strategy

### Keep a Boundary

Prefer keeping a boundary when:

- boundary score is strong enough
- current accumulated event is already long enough
- next segment is also substantial

### Merge Across a Boundary

Prefer merging when:

- the next segment is short
- the current accumulated event is still short
- the boundary is weak or medium

### Maximum Event Guardrail

Force a split when the current event becomes too long, even if the next boundary is weak.

This avoids endlessly merging everything into one giant event.

## Why This Works Without a VLM

This stage does not “understand story meaning.”

Instead, it reduces obvious fragmentation by using timeline structure and boundary confidence. It is a continuity-based merge layer, not a semantic understanding layer.

## Default Config

V1 uses generic thresholds:

- target event duration
- max event duration
- short segment threshold
- keep-boundary score
- strong-boundary score

## Logging

Use Chinese console logs:

- `【开始】事件合并开始`
- `【过程】合并前动态片段数量`
- `【过程】合并后事件段数量`
- `【完成】事件合并完成`
- `【警告】存在可疑碎片化事件段`
- `【错误】事件合并失败`
- `【回退】保留动态片段直接继续`

## Testing

Add tests for:

- weak-boundary short-fragment merging
- strong-boundary preservation
- maximum-event guardrail

Run the sample video and report:

- event count
- event ranges
- shortest and longest event durations
