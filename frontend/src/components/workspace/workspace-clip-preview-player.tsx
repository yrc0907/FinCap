import { useEffect, useMemo, useRef, useState } from "react";
import { Pause, Play, RotateCcw, SkipBack, SkipForward } from "lucide-react";

import { Button } from "../ui/button";

type WorkspaceClipPreviewPlayerProps = {
  src: string | undefined;
  title: string;
  startSec: number;
  endSec: number;
  seekTimeSec: number;
  onCurrentTimeChange?: (timeSec: number) => void;
};

export const WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME =
  "flex min-h-0 flex-col overflow-hidden rounded-[32px] border border-white/8 bg-black/45";

function clampTime(value: number, min: number, max: number) {
  return Math.min(Math.max(value, min), max);
}

export function WorkspaceClipPreviewPlayer({
  src,
  title,
  startSec,
  endSec,
  seekTimeSec,
  onCurrentTimeChange,
}: WorkspaceClipPreviewPlayerProps) {
  const videoRef = useRef<HTMLVideoElement | null>(null);
  const animationFrameRef = useRef<number | null>(null);
  const [currentTimeSec, setCurrentTimeSec] = useState(startSec);
  const [isPlaying, setIsPlaying] = useState(false);
  const clipDurationSec = useMemo(
    () => Math.max(0.001, endSec - startSec),
    [endSec, startSec],
  );

  useEffect(() => {
    const video = videoRef.current;
    if (!video) {
      return;
    }

    const nextTimeSec = clampTime(seekTimeSec, startSec, endSec);
    const applySeek = () => {
      try {
        if (Math.abs(video.currentTime - nextTimeSec) < 0.01) {
          return;
        }
        video.currentTime = nextTimeSec;
        setCurrentTimeSec(nextTimeSec);
        onCurrentTimeChange?.(nextTimeSec);
      } catch {
        return;
      }
    };

    applySeek();
    video.addEventListener("loadedmetadata", applySeek);

    return () => {
      video.removeEventListener("loadedmetadata", applySeek);
    };
  }, [endSec, onCurrentTimeChange, seekTimeSec, startSec]);

  useEffect(() => {
    const video = videoRef.current;
    if (!video) {
      return;
    }

    const handleTimeUpdate = () => {
      const nextTimeSec = clampTime(video.currentTime, startSec, endSec);
      if (video.currentTime > endSec) {
        video.currentTime = startSec;
        video.pause();
        setIsPlaying(false);
        setCurrentTimeSec(startSec);
        onCurrentTimeChange?.(startSec);
        return;
      }
      setCurrentTimeSec(nextTimeSec);
      onCurrentTimeChange?.(nextTimeSec);
    };

    const handlePause = () => setIsPlaying(false);
    const handlePlay = () => setIsPlaying(true);

    video.addEventListener("timeupdate", handleTimeUpdate);
    video.addEventListener("pause", handlePause);
    video.addEventListener("play", handlePlay);

    return () => {
      video.removeEventListener("timeupdate", handleTimeUpdate);
      video.removeEventListener("pause", handlePause);
      video.removeEventListener("play", handlePlay);
    };
  }, [endSec, onCurrentTimeChange, startSec]);

  useEffect(() => {
    if (!isPlaying) {
      if (animationFrameRef.current !== null) {
        window.cancelAnimationFrame(animationFrameRef.current);
        animationFrameRef.current = null;
      }
      return;
    }

    const video = videoRef.current;
    if (!video) {
      return;
    }

    const syncCurrentTime = () => {
      const nextTimeSec = clampTime(video.currentTime, startSec, endSec);
      setCurrentTimeSec(nextTimeSec);
      onCurrentTimeChange?.(nextTimeSec);

      if (!video.paused && !video.ended) {
        animationFrameRef.current = window.requestAnimationFrame(syncCurrentTime);
      }
    };

    animationFrameRef.current = window.requestAnimationFrame(syncCurrentTime);

    return () => {
      if (animationFrameRef.current !== null) {
        window.cancelAnimationFrame(animationFrameRef.current);
        animationFrameRef.current = null;
      }
    };
  }, [endSec, isPlaying, onCurrentTimeChange, startSec]);

  const handleTogglePlay = async () => {
    const video = videoRef.current;
    if (!video) {
      return;
    }
    if (isPlaying) {
      video.pause();
      return;
    }
    if (video.currentTime < startSec || video.currentTime > endSec) {
      video.currentTime = startSec;
    }
    try {
      await video.play();
    } catch {
      setIsPlaying(false);
    }
  };

  const handleSeekWithinClip = (nextTimeSec: number) => {
    const video = videoRef.current;
    if (!video) {
      return;
    }
    const clampedTimeSec = clampTime(nextTimeSec, startSec, endSec);
    video.currentTime = clampedTimeSec;
    setCurrentTimeSec(clampedTimeSec);
    onCurrentTimeChange?.(clampedTimeSec);
  };

  if (!src) {
    return (
      <div className="flex h-full min-h-0 items-center justify-center rounded-[32px] border border-dashed border-white/10 bg-black/30 text-[11px] font-mono uppercase tracking-[0.22em] text-white/25">
        No Video
      </div>
    );
  }

  return (
    <div className={WORKSPACE_CLIP_PREVIEW_PLAYER_CLASS_NAME}>
      <div className="flex flex-wrap items-center justify-between gap-3 border-b border-white/6 px-5 py-4">
        <div className="min-w-0">
          <div className="truncate text-[10px] font-mono uppercase tracking-[0.22em] text-white/30">
            {title}
          </div>
          <div className="mt-1 text-sm font-black text-white/90">
            {startSec.toFixed(3)}s - {endSec.toFixed(3)}s
          </div>
        </div>
        <div className="rounded-full border border-white/10 bg-white/[0.04] px-3 py-1 text-[10px] font-black uppercase tracking-[0.18em] text-white/65">
          {clipDurationSec.toFixed(3)}s
        </div>
      </div>

      <div className="relative flex flex-1 items-center justify-center overflow-hidden bg-black">
        <video
          ref={videoRef}
          src={src}
          playsInline
          preload="metadata"
          controls={false}
          className="block max-h-full max-w-full bg-black object-contain object-center"
        />
      </div>

      <div className="space-y-4 border-t border-white/6 px-5 py-4">
        <div className="flex flex-wrap items-center gap-2">
          <Button
            type="button"
            size="sm"
            variant="secondary"
            className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
            onClick={() => handleSeekWithinClip(startSec)}
          >
            <SkipBack />
            Start
          </Button>
          <Button
            type="button"
            size="sm"
            className="rounded-2xl"
            onClick={() => void handleTogglePlay()}
          >
            {isPlaying ? <Pause /> : <Play />}
            {isPlaying ? "Pause" : "Play"}
          </Button>
          <Button
            type="button"
            size="sm"
            variant="secondary"
            className="rounded-2xl border border-white/10 bg-white/[0.03] text-white hover:bg-white/[0.08]"
            onClick={() => handleSeekWithinClip(endSec)}
          >
            <SkipForward />
            End
          </Button>
          <Button
            type="button"
            size="sm"
            variant="ghost"
            className="rounded-2xl border border-white/10 bg-transparent text-white/70 hover:bg-white/[0.08]"
            onClick={() => handleSeekWithinClip(seekTimeSec)}
          >
            <RotateCcw />
            Refresh
          </Button>
        </div>

        <div className="rounded-[24px] border border-white/8 bg-black/25 px-4 py-4">
          <div className="flex items-center justify-between gap-3 text-[10px] font-mono uppercase tracking-[0.18em] text-white/30">
            <span>Clip Preview</span>
            <span>{currentTimeSec.toFixed(3)}s</span>
          </div>
          <input
            aria-label="Clip preview timeline"
            type="range"
            min={startSec}
            max={endSec}
            step={0.001}
            value={currentTimeSec}
            onChange={(event) => handleSeekWithinClip(Number(event.target.value))}
            className="mt-3 w-full accent-white"
          />
        </div>
      </div>
    </div>
  );
}
