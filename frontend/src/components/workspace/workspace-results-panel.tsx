import { Radar, SplitSquareVertical } from "lucide-react";

import type {
  AdjacentStoryReassignmentResult,
  CorrectedEventTimelineResult,
  DynamicSegmentGenerationResult,
  DualSignalBoundaryDetectionResult,
  EventMergingResult,
  MultiscaleDetectionResult,
  StrictShotGenerationResult,
  VlmShotAnalysisResult,
} from "../../types/workspace";
import { formatScore, formatSeconds } from "./workspace-config";
import { WorkspaceSemanticResults } from "./workspace-semantic-results";

type WorkspaceResultsPanelProps = {
  multiscaleResult: MultiscaleDetectionResult | null;
  boundaryResult: DualSignalBoundaryDetectionResult | null;
  dynamicSegmentResult: DynamicSegmentGenerationResult | null;
  eventMergingResult: EventMergingResult | null;
  strictShotResult: StrictShotGenerationResult | null;
  vlmShotAnalysisResult: VlmShotAnalysisResult | null;
  adjacentStoryReassignmentResult: AdjacentStoryReassignmentResult | null;
  correctedEventTimelineResult: CorrectedEventTimelineResult | null;
};

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

export function WorkspaceResultsPanel({
  multiscaleResult,
  boundaryResult,
  dynamicSegmentResult,
  eventMergingResult,
  strictShotResult,
  vlmShotAnalysisResult,
  adjacentStoryReassignmentResult,
  correctedEventTimelineResult,
}: WorkspaceResultsPanelProps) {
  return (
    <>
      <section className="flex min-h-0 flex-1 flex-col overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
        <div className="border-b border-white/6 p-5">
          <div className="flex items-center gap-3">
            <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
              <Radar size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Layer 07 Output
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Suspicious Change Regions
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {multiscaleResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard
                  label="Duration"
                  value={formatSeconds(multiscaleResult.videoIndex.durationSec)}
                />
                <SummaryCard label="FPS" value={multiscaleResult.videoIndex.fps} />
                <SummaryCard label="Regions" value={multiscaleResult.suspiciousRegions.length} />
                <SummaryCard label="Scene Route" value={multiscaleResult.sceneDetector.backend} />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {multiscaleResult.suspiciousRegions.map((region, index) => (
                  <div
                    key={`${region.startSec}-${region.peakSec}-${index}`}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Region {index + 1}
                      </div>
                      <div
                        className={`rounded-full px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] ${
                          region.confidence === "high"
                            ? "bg-emerald-500/10 text-emerald-300"
                            : "bg-amber-500/10 text-amber-200"
                        }`}
                      >
                        {region.confidence}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Start {formatSeconds(region.startSec)}</span>
                      <span>End {formatSeconds(region.endSec)}</span>
                      <span>Peak {formatSeconds(region.peakSec)}</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>Coarse {formatSeconds(region.coarsePeakSec)}</span>
                      <span>Score {region.score.toFixed(4)}</span>
                      <span>{region.sources.join(" + ")}</span>
                    </div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[260px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Layer 07 Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run Layer 07 to scan the full timeline.
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
              <SplitSquareVertical size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Layer 08 Output
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Real Boundary Candidates
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {boundaryResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Input Regions" value={boundaryResult.inputRegionCount} />
                <SummaryCard label="Subject Signals" value={boundaryResult.subjectCandidates.length} />
                <SummaryCard label="Boundaries" value={boundaryResult.boundaryCandidates.length} />
                <SummaryCard label="Scene Route" value={boundaryResult.sceneDetector.backend} />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {boundaryResult.boundaryCandidates.map((boundary, index) => (
                  <div
                    key={`${boundary.timeSec}-${index}`}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Boundary {index + 1}
                      </div>
                      <div
                        className={`rounded-full px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] ${
                          boundary.confidence === "high"
                            ? "bg-emerald-500/10 text-emerald-300"
                            : "bg-amber-500/10 text-amber-200"
                        }`}
                      >
                        {boundary.confidence}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Time {formatSeconds(boundary.timeSec)}</span>
                      <span>Window {formatSeconds(boundary.windowStartSec)}</span>
                      <span>To {formatSeconds(boundary.windowEndSec)}</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>Score {boundary.score.toFixed(4)}</span>
                      <span>Subject {formatScore(boundary.subjectScore)}</span>
                      <span>Scene {formatScore(boundary.sceneScore)}</span>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                      <span>{boundary.sources.join(" + ")}</span>
                    </div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[260px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Layer 08 Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run Layer 08 after Layer 07.
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
              <Radar size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Dynamic Segments
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Chapter 08 Output
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {dynamicSegmentResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Segments" value={dynamicSegmentResult.summary.segmentCount} />
                <SummaryCard label="Used Cuts" value={dynamicSegmentResult.usedBoundaryCount} />
                <SummaryCard
                  label="Shortest"
                  value={formatSeconds(dynamicSegmentResult.summary.shortestSegmentSec)}
                />
                <SummaryCard
                  label="Longest"
                  value={formatSeconds(dynamicSegmentResult.summary.longestSegmentSec)}
                />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {dynamicSegmentResult.segments.map((segment) => (
                  <div
                    key={segment.index}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Segment {segment.index}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {formatSeconds(segment.durationSec)}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Start {formatSeconds(segment.startSec)}</span>
                      <span>End {formatSeconds(segment.endSec)}</span>
                    </div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Segments Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run segments after Layer 08.
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
              <SplitSquareVertical size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Event Merge
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Chapter 09 Output
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {eventMergingResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Events" value={eventMergingResult.summary.eventCount} />
                <SummaryCard
                  label="Merged Cuts"
                  value={eventMergingResult.mergedBoundaryPointsSec.length}
                />
                <SummaryCard
                  label="Shortest"
                  value={formatSeconds(eventMergingResult.summary.shortestEventSec)}
                />
                <SummaryCard
                  label="Longest"
                  value={formatSeconds(eventMergingResult.summary.longestEventSec)}
                />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {eventMergingResult.events.map((event) => (
                  <div
                    key={event.index}
                    className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4"
                  >
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Event {event.index}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {formatSeconds(event.durationSec)}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Start {formatSeconds(event.startSec)}</span>
                      <span>End {formatSeconds(event.endSec)}</span>
                      <span>Segments {event.segmentCount}</span>
                    </div>

                    {event.mergeReasons.length > 0 ? (
                      <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/22">
                        <span>{event.mergeReasons.join(" + ")}</span>
                      </div>
                    ) : null}
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Events Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run event merge after Chapter 08.
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
              <Radar size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">
                Strict Shots
              </div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                Boundary Clean Pass
              </div>
            </div>
          </div>
        </div>

        <div className="flex min-h-0 flex-1 flex-col p-5">
          {strictShotResult ? (
            <>
              <div className="grid gap-3 md:grid-cols-4">
                <SummaryCard label="Shots" value={strictShotResult.summary.shotCount} />
                <SummaryCard label="Cuts" value={strictShotResult.usedBoundaryPointsSec.length} />
                <SummaryCard label="Shortest" value={formatSeconds(strictShotResult.summary.shortestShotSec)} />
                <SummaryCard label="Longest" value={formatSeconds(strictShotResult.summary.longestShotSec)} />
              </div>

              <div className="mt-5 flex-1 space-y-3 overflow-y-auto pr-1 scrollbar-none">
                {strictShotResult.shots.map((shot) => (
                  <div key={shot.index} className="rounded-[24px] border border-white/8 bg-white/[0.025] p-4">
                    <div className="flex items-center justify-between gap-3">
                      <div className="text-sm font-black uppercase tracking-[0.06em] text-white/85">
                        Shot {shot.index}
                      </div>
                      <div className="rounded-full bg-white/5 px-3 py-1 text-[9px] font-black uppercase tracking-[0.22em] text-white/45">
                        {formatSeconds(shot.durationSec)}
                      </div>
                    </div>

                    <div className="mt-3 flex flex-wrap items-center gap-x-4 gap-y-2 text-[10px] font-mono uppercase tracking-[0.18em] text-white/28">
                      <span>Start {formatSeconds(shot.startSec)}</span>
                      <span>End {formatSeconds(shot.endSec)}</span>
                    </div>
                  </div>
                ))}
              </div>
            </>
          ) : (
            <div className="flex h-full min-h-[220px] items-center justify-center text-center">
              <div>
                <div className="text-[10px] font-black uppercase tracking-[0.32em] text-white/20">
                  Strict Shots Idle
                </div>
                <div className="mt-4 text-base font-bold text-white/70">
                  Run strict shots after Layer 08.
                </div>
              </div>
            </div>
          )}
        </div>
      </section>

      <WorkspaceSemanticResults
        vlmShotAnalysisResult={vlmShotAnalysisResult}
        adjacentStoryReassignmentResult={adjacentStoryReassignmentResult}
        correctedEventTimelineResult={correctedEventTimelineResult}
      />
    </>
  );
}
