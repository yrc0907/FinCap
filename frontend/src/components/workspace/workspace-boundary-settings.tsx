import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "../ui/select";
import {
  sceneDetectorModeOptions,
  type BoundaryControlsPayload,
  type MultiscaleControlsPayload,
  type ProcessingMode,
  type StrictShotControlsPayload,
} from "./workspace-config";
import type { SceneDetectorMode } from "../../types/workspace";

type WorkspaceBoundarySettingsProps = {
  processingMode: ProcessingMode;
  sceneDetectorMode: SceneDetectorMode;
  multiscalePayload: MultiscaleControlsPayload;
  boundaryPayload: BoundaryControlsPayload;
  strictShotPayload: StrictShotControlsPayload;
  onApplyProcessingMode: (mode: ProcessingMode) => void;
  onSceneDetectorModeChange: (mode: SceneDetectorMode) => void;
  onUpdateMultiscaleField: <K extends keyof MultiscaleControlsPayload>(key: K, value: string) => void;
  onUpdateBoundaryField: <K extends keyof BoundaryControlsPayload>(key: K, value: string) => void;
  onUpdateStrictShotField: <K extends keyof StrictShotControlsPayload>(key: K, value: string) => void;
};

function NumberField({
  label,
  value,
  onChange,
}: {
  label: string;
  value: number;
  onChange: (value: string) => void;
}) {
  return (
    <label className="space-y-2">
      <span className="text-[10px] font-mono uppercase tracking-[0.2em] text-white/25">
        {label}
      </span>
      <input
        type="number"
        step={0.01}
        value={value}
        onChange={(event) => onChange(event.target.value)}
        className="w-full rounded-2xl border border-white/10 bg-black/20 px-4 py-3 text-sm text-white"
      />
    </label>
  );
}

export function WorkspaceBoundarySettings({
  processingMode,
  sceneDetectorMode,
  multiscalePayload,
  boundaryPayload,
  strictShotPayload,
  onApplyProcessingMode,
  onSceneDetectorModeChange,
  onUpdateMultiscaleField,
  onUpdateBoundaryField,
  onUpdateStrictShotField,
}: WorkspaceBoundarySettingsProps) {
  return (
    <div className="space-y-6">
      <div className="grid gap-4 md:grid-cols-2">
        <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
          <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
            Profile
          </div>
          <div className="mt-4 grid gap-3">
            <Select value={processingMode} onValueChange={(value) => onApplyProcessingMode(value as ProcessingMode)}>
              <SelectTrigger className="rounded-2xl border-white/10 bg-black/20 text-white">
                <SelectValue placeholder="Profile" />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="fast">Fast</SelectItem>
                <SelectItem value="standard">Standard</SelectItem>
                <SelectItem value="high">High</SelectItem>
              </SelectContent>
            </Select>

            <Select value={sceneDetectorMode} onValueChange={(value) => onSceneDetectorModeChange(value as SceneDetectorMode)}>
              <SelectTrigger className="rounded-2xl border-white/10 bg-black/20 text-white">
                <SelectValue placeholder="Route" />
              </SelectTrigger>
              <SelectContent>
                {sceneDetectorModeOptions.map((option) => (
                  <SelectItem key={option.value} value={option.value}>
                    {option.label}
                  </SelectItem>
                ))}
              </SelectContent>
            </Select>
          </div>
        </div>

        <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
          <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
            Strict Shot
          </div>
          <div className="mt-4 grid gap-3 md:grid-cols-2">
            <NumberField
              label="min_shot_sec"
              value={strictShotPayload.min_shot_sec}
              onChange={(value) => onUpdateStrictShotField("min_shot_sec", value)}
            />
            <NumberField
              label="abnormal_short_sec"
              value={strictShotPayload.abnormal_short_sec}
              onChange={(value) => onUpdateStrictShotField("abnormal_short_sec", value)}
            />
          </div>
        </div>
      </div>

      <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
          Multiscale
        </div>
        <div className="mt-4 grid gap-3 md:grid-cols-3">
          <NumberField
            label="coarse_window_sec"
            value={multiscalePayload.coarse_window_sec}
            onChange={(value) => onUpdateMultiscaleField("coarse_window_sec", value)}
          />
          <NumberField
            label="coarse_stride_sec"
            value={multiscalePayload.coarse_stride_sec}
            onChange={(value) => onUpdateMultiscaleField("coarse_stride_sec", value)}
          />
          <NumberField
            label="coarse_score_threshold"
            value={multiscalePayload.coarse_score_threshold}
            onChange={(value) => onUpdateMultiscaleField("coarse_score_threshold", value)}
          />
          <NumberField
            label="coarse_merge_gap_sec"
            value={multiscalePayload.coarse_merge_gap_sec}
            onChange={(value) => onUpdateMultiscaleField("coarse_merge_gap_sec", value)}
          />
          <NumberField
            label="fine_search_radius_sec"
            value={multiscalePayload.fine_search_radius_sec}
            onChange={(value) => onUpdateMultiscaleField("fine_search_radius_sec", value)}
          />
          <NumberField
            label="fine_sample_step_sec"
            value={multiscalePayload.fine_sample_step_sec}
            onChange={(value) => onUpdateMultiscaleField("fine_sample_step_sec", value)}
          />
        </div>
      </div>

      <div className="rounded-[28px] border border-white/8 bg-white/[0.02] p-4">
        <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
          Boundary
        </div>
        <div className="mt-4 grid gap-3 md:grid-cols-3">
          <NumberField
            label="subject_sample_step_sec"
            value={boundaryPayload.subject_sample_step_sec}
            onChange={(value) => onUpdateBoundaryField("subject_sample_step_sec", value)}
          />
          <NumberField
            label="subject_core_ratio"
            value={boundaryPayload.subject_core_ratio}
            onChange={(value) => onUpdateBoundaryField("subject_core_ratio", value)}
          />
          <NumberField
            label="subject_score_threshold"
            value={boundaryPayload.subject_score_threshold}
            onChange={(value) => onUpdateBoundaryField("subject_score_threshold", value)}
          />
          <NumberField
            label="scene_sample_step_sec"
            value={boundaryPayload.scene_sample_step_sec}
            onChange={(value) => onUpdateBoundaryField("scene_sample_step_sec", value)}
          />
          <NumberField
            label="scene_score_threshold"
            value={boundaryPayload.scene_score_threshold}
            onChange={(value) => onUpdateBoundaryField("scene_score_threshold", value)}
          />
          <NumberField
            label="fusion_gap_sec"
            value={boundaryPayload.fusion_gap_sec}
            onChange={(value) => onUpdateBoundaryField("fusion_gap_sec", value)}
          />
          <NumberField
            label="fusion_high_confidence_score"
            value={boundaryPayload.fusion_high_confidence_score}
            onChange={(value) => onUpdateBoundaryField("fusion_high_confidence_score", value)}
          />
        </div>
      </div>
    </div>
  );
}

