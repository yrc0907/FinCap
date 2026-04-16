# 当前项目实际流程（2026-04-16）

本文档不是理想设计稿，而是**按照当前代码已经实现出来的真实流程**整理的现状文档。

目标只有一个：

- 让后面讨论时，不再把“旧设计文档里的流程”和“当前项目真实流程”混在一起。

---

## 1. 当前主链路

当前项目真正的主链路是：

1. `Layer 07: Full Timeline Multi-Scale Detection`
2. `Layer 08: Dual-Signal Boundary Detection`
3. `Strict Shots`
4. `VLM Shot Analysis`
5. `Adjacent Story Reassignment`
6. `Corrected Event Timeline`
7. `Narration Spans`
8. `Selected Clips`

也就是：

`完整时间轴检测 -> 真实边界 -> 干净镜头段 -> VLM理解 -> 相邻段修正 -> 修正后的事件段 -> 段内保留/桥接/丢弃 -> 最终可剪片段`

---

## 2. 每一层现在在做什么

### 2.1 Layer 07

作用：

- 在完整时间轴上找“可疑变化区间”
- 给后面边界精修提供候选区域

输入：

- 原视频

输出：

- `suspiciousRegions`
- `sceneDetectorCandidates`

当前特点：

- 已经接了 `TransNetV2 CUDA/CPU fallback`
- 当前结果更像“先粗找变化区”

---

### 2.2 Layer 08

作用：

- 在可疑区间里继续判断真实边界到底在哪里
- 把主体变化、场景变化、检测器候选融合成最终边界点

输入：

- `suspiciousRegions`
- `sceneDetectorCandidates`

输出：

- `boundaryCandidates`

当前特点：

- 这是当前真正的“边界层”
- 但这层出来的边界仍然可能存在“上一段尾巴混入下一段”的问题

---

### 2.3 Strict Shots

作用：

- 把边界点变成严格连续的镜头片段
- 去掉重复边界、极短脏边界

输入：

- `boundaryCandidates`

输出：

- `shots`

当前特点：

- 这一步只做“边界清洗”
- 不做剧情合并

---

### 2.4 VLM Shot Analysis

作用：

- 把若干个 `shots` 按组送给 VLM 看
- 让 VLM判断当前组里大概发生了什么

输入：

- `shots`
- 抽出来的关键帧

输出：

- `groups`
- 每组的：
  - `highlightScore`
  - `peakTimesSec`
  - `peakRole`
  - `reason`

当前特点：

- **现在的 VLM 只看当前组**
- **不再负责相邻组合并**
- 也就是说，它只回答“这组是什么”，不回答“该不该并到下一组”

---

### 2.5 Adjacent Story Reassignment

作用：

- 只看**相邻两组**
- 判断前一组尾巴是不是其实已经属于后一组剧情

输入：

- `groups`

输出：

- `pairs`
- 每对相邻组的：
  - `shouldReassignTail`
  - `reassignFromSec`
  - `confidence`
  - `reason`

当前特点：

- 只做相邻组，不做跨段
- 它解决的是“尾部污染”问题

短例子：

- 原来：
  - Group A = `38.353 - 44.987`
  - Group B = `44.987 - 56.187`
- 如果返回：
  - `reassignFromSec = 44.342`
- 那含义就是：
  - `44.342` 之后其实已经属于 Group B

---

### 2.6 Corrected Event Timeline

作用：

- 把 `Adjacent` 的修正点真正落成新时间轴

输入：

- `groups`
- `pairs`
- `shots`

输出：

- `events`

每个事件包含：

- 原始范围 `originalStartSec / originalEndSec`
- 修正后范围 `startSec / endSec`
- `sourceGroupIndexes`
- `changed`
- `reasons`

当前特点：

- 这一步是当前真正的“防串段护栏”
- 后面文案和配音都应该建立在这层上，而不是建立在旧的 `groups` 上

---

### 2.7 Narration Spans

作用：

- 在每个 `Corrected Event` 内部继续细分
- 标出哪些小段值得保留，哪些只是桥接，哪些应该丢掉

输入：

- `Corrected Event`
- `shots`
- 当前事件对应的组信息

输出：

- `narrationSpans`

标签有三种：

- `keep`
- `bridge`
- `drop`

当前规则是第一版启发式：

- 命中 `peakTimesSec` -> `keep`
- 事件首尾 -> `bridge`
- 中间低分 `transition` -> `drop`
- 一些中高价值支持段 -> `bridge`

当前特点：

- 这一步已经能把“整段都讲”拆成“小段挑着讲”
- 但规则还偏保守

---

### 2.8 Selected Clips

作用：

- 从 `narrationSpans` 里导出最终可剪片段

当前规则：

- 保留 `keep`
- 保留 `bridge`
- 丢弃 `drop`

输出：

- `selectedClips`

当前特点：

- 这一步已经能导出“最终可剪片段清单”
- 但当前样片里仍然偏保守，删减力度不够狠

---

## 3. 当前项目里“还存在但不是主链路”的流程

当前代码里还有两条旧分支仍然存在：

1. `Dynamic Segment Generation`
2. `Event Merge`

它们仍然能跑，但**已经不是当前最重要的主链路**。

原因很简单：

- 它们更多是“按边界做段，再合并段”
- 但当前项目最关键的问题已经变成：
  - 边界污染
  - 相邻剧情误归属
  - 配音串到下一段画面

所以现在更重要的是：

- `Strict Shots -> VLM -> Adjacent -> Corrected Events`

而不是旧的：

- `Dynamic Segments -> Event Merge`

结论：

- 旧分支暂时保留
- 但当前讨论和继续开发时，应以**新主链路**为准

---

## 4. 当前项目最核心的问题

### 4.1 已经解决到什么程度

已经做到：

- 能从完整时间轴找到边界候选
- 能生成严格镜头段
- 能做 VLM 分组理解
- 能做相邻尾部重归属
- 能生成修正后的事件段
- 能在事件内部打 `keep / bridge / drop`
- 能导出最终可剪片段清单

### 4.2 还没有真正解决好的问题

最核心还没彻底解决的是：

- **边界仍然不够干净**
- 有时上一段里还会出现下一段场景
- 导致后面即使做了 `selectedClips`，意义也会下降

所以当前真正的第一优先级不是“再做更复杂的选段”，而是：

- 继续提高边界修正质量
- 让 `Corrected Events` 更可信

---

## 5. 当前系统应该怎么理解

不要再把当前系统理解成：

- “先切段，再整段都讲”

当前系统更准确的理解是：

1. 先切出**尽量干净的剧情边界**
2. 再把边界修成**不串段的事件段**
3. 再在事件段内部挑：
   - 哪些必须讲
   - 哪些只做桥接
   - 哪些直接不要

所以：

- `Corrected Event` 是剧情单位
- `Narration Span` 是讲解单位
- `Selected Clip` 是最终剪辑单位

这三层不能混为一谈。

---

## 6. 当前最推荐的后续开发顺序

如果继续按当前项目真实流程推进，顺序应该是：

1. **继续提高边界修正质量**
   - 目标：上一段不要再混入下一段场景

2. **收紧 `keep / bridge / drop` 规则**
   - 目标：不要所有段都落成 `keep`

3. **把 `Selected Clips` 真正变成最终解说时间轴**
   - 控制原片保留比例
   - 保证文案不跨事件边界

4. **最后才考虑复杂段九宫格**
   - 九宫格不是当前主问题
   - 现在先别把它当核心

---

## 7. 一句话总结

当前项目的真实主链路已经不是旧文档里的“动态片段 -> 事件合并”为主，
而是：

**完整时间轴检测 -> 真实边界 -> 严格镜头段 -> VLM分组 -> 相邻重归属 -> 修正事件段 -> 段内保留/桥接/丢弃 -> 最终可剪片段**

后面所有讨论，建议都以这条链路为准。
