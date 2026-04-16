import { GitCompareArrows, Sparkles } from "lucide-react";

import type {
  AdjacentStoryReassignmentResult,
  CorrectedEventTimelineResult,
  VlmShotAnalysisResult,
} from "../../types/workspace";
import { formatSeconds } from "./workspace-config";

function SummaryCard({ label, value }: { label: string; value: string | number }) {
  return (
    <div className="rounded-2xl border border-white/8 bg-white/[0.025] px-4 py-4">
      <div className="text-[9px] font-mono uppercase tracking-[0.22em] text-white/20">{label}</div>
      <div className="mt-2 text-sm font-black uppercase tracking-[0.08em] text-white/80">
        {value}
      </div>
    </div>
  );
}

type WorkspaceSemanticResultsProps = {
  vlmShotAnalysisResult: VlmShotAnalysisResult | null;
  adjacentStoryReassignmentResult: AdjacentStoryReassignmentResult | null;
  correctedEventTimelineResult: CorrectedEventTimelineResult | null;
};

export function WorkspaceSemanticResults({
  vlmShotAnalysisResult,
  adjacentStoryReassignmentResult,
  correctedEventTimelineResult,
}: WorkspaceSemanticResultsProps) {
  return (
    <>
      <section className="flex min-h-0 flex-1 flex-col overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
        <div className="border-b border-white/6 p-5">
          <div className="flex items-center gap-3">
            <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
              <Sparkles size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">VLM</div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Semantic Shot Pass
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {vlmShotAnalysisResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Input Shots" value={vlmShotAnalysisResult.inputShotCount} />
                <SummaryCard label="Groups" value={vlmShotAnalysisResult.summary.groupCount} />
                <SummaryCard label="Highlights" value={vlmShotAnalysisResult.summary.highlightGroupCount} />
                <SummaryCard label="Gate" value={vlmShotAnalysisResult.config.highlight_threshold.toFixed(2)} />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {vlmShotAnalysisResult.groups.map((group) => (
                  <div key={group.index} className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4">
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Group {group.index}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {group.highlightScore.toFixed(3)}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Start {formatSeconds(group.startSec)}</span>
                      <span>End {formatSeconds(group.endSec)}</span>
                      <span>Shots {group.shotIndexes.join(", ")}</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>Continuous {group.isContinuousStory ? "yes" : "no"}</span>
                      <span>Role {group.peakRole}</span>
                      <span>
                        Speaker {group.speakerHint ? group.speakerHint : "--"}
                      </span>
                      <span>Voice {(group.speakerConfidence * 100).toFixed(0)}%</span>
                      <span>Prev hold</span>
                      <span>Next hold</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>
                        Peaks{" "}
                        {group.peakTimesSec.length > 0
                          ? group.peakTimesSec.map(formatSeconds).join(", ")
                          : "--"}
                      </span>
                    </div>

                    <div className="mt-3 text-xs text-white/60">{group.reason || "No reason returned."}</div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  VLM Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run VLM after strict shots.
                </div>
              </div>
            </div>
          )}
        </div>
      </section>

      <section className="flex min-h-0 flex-1 flex-col overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
        <div className="border-b border-white/6 p-5">
          <div className="flex items-center gap-3">
            <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
              <GitCompareArrows size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Adjacent
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Pair Reassignment
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {adjacentStoryReassignmentResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-3">
                <SummaryCard label="Input Groups" value={adjacentStoryReassignmentResult.inputGroupCount} />
                <SummaryCard label="Pairs" value={adjacentStoryReassignmentResult.summary.pairCount} />
                <SummaryCard
                  label="Reassignments"
                  value={adjacentStoryReassignmentResult.summary.reassignmentCount}
                />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {adjacentStoryReassignmentResult.pairs.map((pair) => (
                  <div
                    key={`${pair.leftGroupIndex}-${pair.rightGroupIndex}`}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Pair {pair.leftGroupIndex}-{pair.rightGroupIndex}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {pair.confidence.toFixed(3)}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>Tail {pair.shouldReassignTail ? "move" : "hold"}</span>
                      <span>
                        From {pair.reassignFromSec === null ? "--" : formatSeconds(pair.reassignFromSec)}
                      </span>
                    </div>

                    <div className="mt-3 text-xs text-white/60">{pair.reason || "No reason returned."}</div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Adjacent Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run adjacent after VLM.
                </div>
              </div>
            </div>
          )}
        </div>
      </section>

      <section className="flex min-h-0 flex-1 flex-col overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
        <div className="border-b border-white/6 p-5">
          <div className="flex items-center gap-3">
            <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
              <Sparkles size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Corrected
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Event Timeline
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {correctedEventTimelineResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Input Groups" value={correctedEventTimelineResult.inputGroupCount} />
                <SummaryCard label="Events" value={correctedEventTimelineResult.summary.eventCount} />
                <SummaryCard
                  label="Changed"
                  value={correctedEventTimelineResult.summary.changedEventCount}
                />
                <SummaryCard
                  label="Selected"
                  value={correctedEventTimelineResult.summary.selectedClipCount}
                />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {correctedEventTimelineResult.events.map((event) => (
                  <div
                    key={event.index}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Event {event.index}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {event.changed ? "changed" : "same"}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Original {formatSeconds(event.originalStartSec)}</span>
                      <span>To {formatSeconds(event.originalEndSec)}</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>Corrected {formatSeconds(event.startSec)}</span>
                      <span>To {formatSeconds(event.endSec)}</span>
                      <span>Groups {event.sourceGroupIndexes.join(", ")}</span>
                    </div>

                    {event.reasons.length > 0 ? (
                      <div className="mt-3 text-xs text-white/60">{event.reasons.join(" + ")}</div>
                    ) : null}

                    {event.narrationSpans.length > 0 ? (
                      <div className="mt-4 space-y-2 border-t border-white/6 pt-4">
                        {event.narrationSpans.map((span) => (
                          <div
                            key={`${event.index}-${span.index}`}
                            className="rounded-2xl border border-white/6 bg-black/20 px-3 py-3"
                          >
                            <div className="flex items-center justify-between gap-3">
                              <div className="text-[10px] font-black uppercase tracking-[0.18em] text-white/70">
                                {span.label}
                              </div>
                              <div className="text-[10px] font-mono uppercase tracking-[0.18em] text-white/35">
                                {span.score.toFixed(3)}
                              </div>
                            </div>

                            <div className="mt-2 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                              <span>{formatSeconds(span.startSec)}</span>
                              <span>To {formatSeconds(span.endSec)}</span>
                              <span>Shots {span.sourceShotIndexes.join(", ")}</span>
                            </div>

                            <div className="mt-2 text-xs text-white/50">{span.reason}</div>
                          </div>
                        ))}
                      </div>
                    ) : null}
                  </div>
                ))}
              </div>

              {correctedEventTimelineResult.selectedClips.length > 0 ? (
                <div className="mt-5 space-y-3 border-t border-white/6 pt-5">
                  <div className="grid gap-3 md:grid-cols-3">
                    <SummaryCard
                      label="Keep Clips"
                      value={correctedEventTimelineResult.summary.selectedKeepClipCount}
                    />
                    <SummaryCard
                      label="Bridge Clips"
                      value={correctedEventTimelineResult.summary.selectedBridgeClipCount}
                    />
                    <SummaryCard
                      label="Dropped"
                      value={correctedEventTimelineResult.summary.dropSpanCount}
                    />
                  </div>

                  <div className="space-y-3">
                    {correctedEventTimelineResult.selectedClips.map((clip) => (
                      <div
                        key={`selected-${clip.index}`}
                        className="rounded-[24px] border border-white/8 bg-black/20 p-4"
                      >
                        <div className="flex items-center justify-between gap-3">
                          <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                            Clip {clip.index}
                          </div>
                          <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                            {clip.label}
                          </div>
                        </div>

                        <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                          <span>{formatSeconds(clip.startSec)}</span>
                          <span>To {formatSeconds(clip.endSec)}</span>
                          <span>Event {clip.eventIndex}</span>
                          <span>Shots {clip.sourceShotIndexes.join(", ")}</span>
                        </div>

                        <div className="mt-2 text-xs text-white/50">{clip.reason}</div>
                      </div>
                    ))}
                  </div>
                </div>
              ) : null}
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Corrected Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run adjacent to build corrected events.
                </div>
              </div>
            </div>
          )}
        </div>
      </section>
    </>
  );
}
