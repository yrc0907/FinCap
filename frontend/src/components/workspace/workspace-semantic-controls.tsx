import { GitCompareArrows, Radar, ScanSearch } from "lucide-react";

import { Button } from "../ui/button";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "../ui/select";
import type { StrictShotControlsPayload, VlmControlsPayload } from "./workspace-config";
import { WorkspaceCharacterReferenceList } from "./workspace-character-reference-list";
import { WorkspaceNumericField } from "./workspace-numeric-field";

type WorkspaceSemanticControlsProps = {
  projectReady: boolean;
  hasBoundaryResult: boolean;
  hasStrictShotResult: boolean;
  hasVlmShotAnalysisResult: boolean;
  isRunningStrictShots: boolean;
  isRunningVlm: boolean;
  isRunningAdjacent: boolean;
  strictShotPayload: StrictShotControlsPayload;
  vlmPayload: VlmControlsPayload;
  activeVlmModel: string | null;
  onUpdateStrictShotField: <K extends keyof StrictShotControlsPayload>(key: K, value: string) => void;
  onUpdateVlmField: <K extends keyof VlmControlsPayload>(key: K, value: string | boolean) => void;
  onUpdateVlmSubtitleRegionField: (
    key: keyof VlmControlsPayload["subtitleRegion"],
    value: string,
  ) => void;
  onAddCharacterReference: () => void;
  onUpdateCharacterReference: (
    id: string,
    key: "name" | "imageBase64",
    value: string,
  ) => void;
  onRemoveCharacterReference: (id: string) => void;
  onRunStrictShots: () => void;
  onRunVlm: () => void;
  onRunAdjacent: () => void;
};

export function WorkspaceSemanticControls({
  projectReady,
  hasBoundaryResult,
  hasStrictShotResult,
  hasVlmShotAnalysisResult,
  isRunningStrictShots,
  isRunningVlm,
  isRunningAdjacent,
  strictShotPayload,
  vlmPayload,
  activeVlmModel,
  onUpdateStrictShotField,
  onUpdateVlmField,
  onUpdateVlmSubtitleRegionField,
  onAddCharacterReference,
  onUpdateCharacterReference,
  onRemoveCharacterReference,
  onRunStrictShots,
  onRunVlm,
  onRunAdjacent,
}: WorkspaceSemanticControlsProps) {
  return (
    <>
      <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
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

        <div className="grid gap-4 p-5 md:grid-cols-2">
          <WorkspaceNumericField
            label="Dedupe Gap"
            value={strictShotPayload.dedupe_epsilon_sec}
            step="0.01"
            onChange={(value) => onUpdateStrictShotField("dedupe_epsilon_sec", value)}
          />
          <WorkspaceNumericField
            label="Min Shot"
            value={strictShotPayload.min_shot_sec}
            step="0.01"
            onChange={(value) => onUpdateStrictShotField("min_shot_sec", value)}
          />
          <WorkspaceNumericField
            label="Short Warning"
            value={strictShotPayload.abnormal_short_sec}
            step="0.01"
            fullWidth
            onChange={(value) => onUpdateStrictShotField("abnormal_short_sec", value)}
          />
        </div>

        <div className="border-t border-white/6 p-5">
          <Button
            onClick={onRunStrictShots}
            disabled={isRunningStrictShots || !projectReady || !hasBoundaryResult}
            size="lg"
            className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
          >
            <Radar size={14} />
            {isRunningStrictShots ? "Running Strict Shots" : "Run Strict Shots"}
          </Button>
        </div>
      </section>

      <section className="overflow-hidden rounded-[28px] border border-white/8 bg-white/[0.02]">
        <div className="border-b border-white/6 p-5">
          <div className="flex items-center gap-3">
            <div className="flex h-11 w-11 items-center justify-center rounded-2xl bg-white/5">
              <ScanSearch size={18} className="text-white/50" />
            </div>
            <div>
              <div className="text-sm font-black uppercase tracking-[0.08em] text-white/85">VLM</div>
              <div className="mt-1 text-[10px] font-mono uppercase tracking-[0.28em] text-white/25">
                {activeVlmModel ?? "No Model"}
              </div>
            </div>
          </div>
        </div>

        <div className="grid gap-4 p-5 md:grid-cols-2">
          <WorkspaceNumericField
            label="Group Size"
            value={vlmPayload.group_size}
            step="1"
            onChange={(value) => onUpdateVlmField("group_size", value)}
          />
          <WorkspaceNumericField
            label="Frames / Shot"
            value={vlmPayload.keyframes_per_shot}
            step="1"
            onChange={(value) => onUpdateVlmField("keyframes_per_shot", value)}
          />
          <WorkspaceNumericField
            label="Highlight Gate"
            value={vlmPayload.highlight_threshold}
            step="0.01"
            fullWidth
            onChange={(value) => onUpdateVlmField("highlight_threshold", value)}
          />
          <label className="space-y-2">
            <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
              Prompt
            </span>
            <Select
              value={vlmPayload.promptProfile}
              onValueChange={(value) => onUpdateVlmField("promptProfile", value)}
            >
              <SelectTrigger className="h-[50px] rounded-2xl border-white/10 bg-white/[0.03] text-[11px] font-black uppercase tracking-[0.18em] text-white">
                <SelectValue placeholder="Prompt" />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="short-video">Short Video</SelectItem>
                <SelectItem value="standard">Standard</SelectItem>
              </SelectContent>
            </Select>
          </label>
          <label className="space-y-2">
            <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
              OCR
            </span>
            <Select
              value={vlmPayload.enableOcr ? "on" : "off"}
              onValueChange={(value) => onUpdateVlmField("enableOcr", value === "on")}
            >
              <SelectTrigger className="h-[50px] rounded-2xl border-white/10 bg-white/[0.03] text-[11px] font-black uppercase tracking-[0.18em] text-white">
                <SelectValue placeholder="OCR" />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="on">On</SelectItem>
                <SelectItem value="off">Off</SelectItem>
              </SelectContent>
            </Select>
          </label>
          <label className="space-y-2">
            <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
              Auto ASR
            </span>
            <Select
              value={vlmPayload.enableAutoAsr ? "on" : "off"}
              onValueChange={(value) => onUpdateVlmField("enableAutoAsr", value === "on")}
            >
              <SelectTrigger className="h-[50px] rounded-2xl border-white/10 bg-white/[0.03] text-[11px] font-black uppercase tracking-[0.18em] text-white">
                <SelectValue placeholder="Auto ASR" />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="on">On</SelectItem>
                <SelectItem value="off">Off</SelectItem>
              </SelectContent>
            </Select>
          </label>
          <label className="space-y-2">
            <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
              Subtitle Region
            </span>
            <Select
              value={vlmPayload.enableSubtitleRegion ? "on" : "off"}
              onValueChange={(value) => onUpdateVlmField("enableSubtitleRegion", value === "on")}
            >
              <SelectTrigger className="h-[50px] rounded-2xl border-white/10 bg-white/[0.03] text-[11px] font-black uppercase tracking-[0.18em] text-white">
                <SelectValue placeholder="Subtitle Region" />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="off">Off</SelectItem>
                <SelectItem value="on">On</SelectItem>
              </SelectContent>
            </Select>
          </label>
        </div>

        {vlmPayload.enableSubtitleRegion ? (
          <div className="grid gap-4 border-t border-white/6 p-5 md:grid-cols-2">
            <WorkspaceNumericField
              label="Subtitle X"
              value={vlmPayload.subtitleRegion.x}
              step="0.01"
              onChange={(value) => onUpdateVlmSubtitleRegionField("x", value)}
            />
            <WorkspaceNumericField
              label="Subtitle Y"
              value={vlmPayload.subtitleRegion.y}
              step="0.01"
              onChange={(value) => onUpdateVlmSubtitleRegionField("y", value)}
            />
            <WorkspaceNumericField
              label="Subtitle Width"
              value={vlmPayload.subtitleRegion.width}
              step="0.01"
              onChange={(value) => onUpdateVlmSubtitleRegionField("width", value)}
            />
            <WorkspaceNumericField
              label="Subtitle Height"
              value={vlmPayload.subtitleRegion.height}
              step="0.01"
              onChange={(value) => onUpdateVlmSubtitleRegionField("height", value)}
            />
          </div>
        ) : null}

        <div className="space-y-4 border-t border-white/6 p-5">
          <label className="space-y-2">
            <span className="text-[9px] font-mono uppercase tracking-[0.24em] text-white/25">
              Manual ASR
            </span>
            <textarea
              value={vlmPayload.asrText}
              onChange={(event) => onUpdateVlmField("asrText", event.target.value)}
              rows={4}
              placeholder="Optional"
              className="w-full rounded-2xl border border-white/10 bg-white/[0.03] px-4 py-3 text-sm text-white outline-none transition-colors focus:border-white/30"
            />
          </label>

          <WorkspaceCharacterReferenceList
            references={vlmPayload.characterReferences}
            onAdd={onAddCharacterReference}
            onUpdate={onUpdateCharacterReference}
            onRemove={onRemoveCharacterReference}
          />
        </div>

        <div className="border-t border-white/6 p-5">
          <div className="flex flex-wrap gap-3">
            <Button
              onClick={onRunVlm}
              disabled={isRunningVlm || !projectReady || !hasStrictShotResult}
              size="lg"
              className="rounded-2xl bg-white px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-black hover:bg-white/90"
            >
              <ScanSearch size={14} />
              {isRunningVlm ? "Running VLM" : "Run VLM"}
            </Button>
            <Button
              onClick={onRunAdjacent}
              disabled={isRunningAdjacent || !projectReady || !hasVlmShotAnalysisResult}
              size="lg"
              variant="secondary"
              className="rounded-2xl border border-white/10 bg-white/[0.03] px-6 py-4 text-[10px] font-black uppercase tracking-[0.28em] text-white hover:bg-white/[0.08]"
            >
              <GitCompareArrows size={14} />
              {isRunningAdjacent ? "Running Adjacent" : "Run Adjacent"}
            </Button>
          </div>
        </div>
      </section>
    </>
  );
}
