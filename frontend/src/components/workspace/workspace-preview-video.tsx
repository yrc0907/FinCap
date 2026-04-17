import { useEffect, useRef } from "react";

type WorkspacePreviewVideoProps = {
  src: string | undefined;
  title: string;
  startSec?: number;
  endSec?: number;
};

export function WorkspacePreviewVideo({
  src,
  title,
  startSec = 0,
  endSec,
}: WorkspacePreviewVideoProps) {
  const videoRef = useRef<HTMLVideoElement | null>(null);

  useEffect(() => {
    const video = videoRef.current;
    if (!video || !Number.isFinite(startSec)) {
      return;
    }

    const seekToStart = () => {
      try {
        video.currentTime = Math.max(0, startSec);
      } catch {
        return;
      }
    };

    seekToStart();
    video.addEventListener("loadedmetadata", seekToStart);

    return () => {
      video.removeEventListener("loadedmetadata", seekToStart);
    };
  }, [startSec]);

  useEffect(() => {
    const video = videoRef.current;
    if (!video || !Number.isFinite(endSec ?? Number.NaN)) {
      return;
    }

    const handleTimeUpdate = () => {
      if ((endSec ?? 0) <= 0) {
        return;
      }
      if (video.currentTime <= (endSec ?? 0)) {
        return;
      }
      video.currentTime = endSec ?? video.currentTime;
      video.pause();
    };

    video.addEventListener("timeupdate", handleTimeUpdate);

    return () => {
      video.removeEventListener("timeupdate", handleTimeUpdate);
    };
  }, [endSec]);

  if (!src) {
    return (
      <div className="flex min-h-[220px] items-center justify-center rounded-[28px] border border-dashed border-white/10 bg-black/30 text-[11px] font-mono uppercase tracking-[0.22em] text-white/25">
        No Video
      </div>
    );
  }

  return (
    <div className="overflow-hidden rounded-[28px] border border-white/8 bg-black/40">
      <div className="flex items-center justify-between gap-3 border-b border-white/6 px-4 py-3">
        <div className="text-[10px] font-mono uppercase tracking-[0.24em] text-white/25">{title}</div>
        <div className="text-[10px] font-black uppercase tracking-[0.18em] text-white/45">
          {startSec.toFixed(3)}s{typeof endSec === "number" ? ` - ${endSec.toFixed(3)}s` : ""}
        </div>
      </div>
      <video
        ref={videoRef}
        src={src}
        controls
        playsInline
        preload="metadata"
        className="aspect-video w-full bg-black object-contain"
      />
    </div>
  );
}
