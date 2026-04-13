import { useCallback, useEffect, useRef, useState } from "react";
import { motion } from "framer-motion";
import {
  Activity,
  Command,
  Maximize2,
  Play,
  Search,
  Settings,
  Upload,
} from "lucide-react";

const projects = [
  {
    id: 1,
    name: "Cinematic_Sequence_01",
    date: "2m ago",
    meta: "4K | 24fps | 12.4GB",
    thumb: "https://images.unsplash.com/photo-1492691527719-9d1e07e534b4?w=400&q=80",
  },
  {
    id: 2,
    name: "FinCap_Social_Promo",
    date: "1h ago",
    meta: "1080p | 60fps | 2.1GB",
    thumb: "https://images.unsplash.com/photo-1536240478700-b869070f9279?w=400&q=80",
  },
  {
    id: 3,
    name: "Draft_B_Roll_Nature",
    date: "Yesterday",
    meta: "4K | 30fps | 45.8GB",
    thumb: "https://images.unsplash.com/photo-1441974231531-c6227db76b6e?w=400&q=80",
  },
];

type DashboardShellProps = {
  onOpenSettings: () => void;
};

export function DashboardShell({ onOpenSettings }: DashboardShellProps) {
  const [explorerWidth, setExplorerWidth] = useState(400);
  const [isResizing, setIsResizing] = useState(false);
  const containerRef = useRef<HTMLDivElement>(null);

  const startResizing = useCallback(() => {
    setIsResizing(true);
  }, []);

  const stopResizing = useCallback(() => {
    setIsResizing(false);
  }, []);

  const resize = useCallback(
    (e: MouseEvent) => {
      if (isResizing && containerRef.current) {
        const containerWidth = containerRef.current.offsetWidth;
        const newWidth = containerWidth - (e.clientX - containerRef.current.offsetLeft);
        const maxWidth = Math.max(320, containerWidth - 400);

        if (newWidth >= 320 && newWidth <= maxWidth) {
          setExplorerWidth(newWidth);
        } else if (newWidth < 320) {
          setExplorerWidth(320);
        } else if (newWidth > maxWidth) {
          setExplorerWidth(maxWidth);
        }
      }
    },
    [isResizing],
  );

  useEffect(() => {
    window.addEventListener("mousemove", resize);
    window.addEventListener("mouseup", stopResizing);

    return () => {
      window.removeEventListener("mousemove", resize);
      window.removeEventListener("mouseup", stopResizing);
    };
  }, [resize, stopResizing]);

  const isMobileLayout = typeof window !== "undefined" && window.innerWidth < 768;

  return (
    <div
      className="h-screen w-screen bg-black text-white flex flex-col p-6 md:p-10 font-sans relative overflow-hidden select-none"
      ref={containerRef}
    >
      <div className="absolute inset-0 fincap-gradient pointer-events-none" />

      <nav className="flex items-center justify-between mb-8 md:mb-16 relative z-20 shrink-0">
        <div className="flex items-center gap-3 md:gap-5">
          <div className="w-9 h-9 md:w-11 md:h-11 bg-white flex items-center justify-center rounded-xl md:rounded-2xl shadow-[0_0_30px_rgba(255,255,255,0.1)]">
            <Command size={18} className="text-black md:hidden" />
            <Command size={22} className="text-black hidden md:block" />
          </div>
          <span className="text-2xl md:text-3xl font-black tracking-[-0.05em] uppercase">FinCap</span>
        </div>

        <div className="flex items-center gap-3">
          <div className="hidden sm:flex items-center gap-2 px-4 py-2 rounded-xl bg-white/[0.03] border border-white/10 text-[10px] font-mono text-white/40">
            <Activity size={12} />
            STABLE
          </div>
          <button
            onClick={onOpenSettings}
            className="w-9 h-9 md:w-11 md:h-11 flex items-center justify-center hover:bg-white/10 rounded-xl md:rounded-2xl transition-all border border-white/5"
          >
            <Settings size={18} className="text-white/40 hover:text-white md:hidden" />
            <Settings size={22} className="text-white/40 hover:text-white hidden md:block" />
          </button>
        </div>
      </nav>

      <main className="flex-1 flex flex-col md:flex-row gap-0 relative z-10 min-h-0">
        <div className="flex-1 flex flex-col min-h-0 md:pr-12 mb-8 md:mb-0">
          <motion.div
            className="flex-1 glass rounded-3xl md:rounded-[48px] relative group overflow-hidden video-glow border-white/[0.03]"
            initial={{ opacity: 0, scale: 0.98 }}
            animate={{ opacity: 1, scale: 1 }}
            transition={{ duration: 0.8, ease: [0.16, 1, 0.3, 1] }}
          >
            <div className="scan-line pointer-events-none" />

            <div className="absolute inset-0 flex flex-col items-center justify-center p-4">
              <motion.button
                whileHover={{ scale: 1.05 }}
                whileTap={{ scale: 0.95 }}
                className="flex flex-col items-center gap-6 md:gap-8 group/btn relative"
              >
                <div className="absolute -inset-10 bg-white/5 rounded-full blur-3xl opacity-0 group-hover/btn:opacity-100 transition-opacity duration-700" />

                <div className="w-16 h-16 md:w-24 md:h-24 rounded-2xl md:rounded-[36px] bg-white text-black flex items-center justify-center shadow-[0_0_40px_rgba(255,255,255,0.2)] group-hover/btn:shadow-[0_0_100px_rgba(255,255,255,0.5)] group-hover/btn:rotate-12 transition-all duration-1000 ease-[0.16,1,0.3,1] relative z-10">
                  <Upload size={24} strokeWidth={2.5} className="md:hidden" />
                  <Upload
                    size={32}
                    strokeWidth={2.5}
                    className="hidden md:block group-hover/btn:scale-125 transition-transform duration-500"
                  />
                </div>
                <div className="text-center space-y-2 md:space-y-3 relative z-10">
                  <h2 className="text-lg md:text-xl font-black tracking-[-0.02em] uppercase group-hover/btn:tracking-[0.1em] transition-all duration-700">
                    Initialize Project
                  </h2>
                  <p className="text-[8px] md:text-[10px] font-mono text-white/20 tracking-[0.3em] uppercase">
                    Drop RAW Footage
                  </p>
                </div>
              </motion.button>
            </div>

            <div className="absolute top-6 left-6 md:top-10 md:left-10 flex flex-col gap-3 md:gap-4">
              <div className="flex gap-2 md:gap-3">
                <div className="px-3 py-1.5 md:px-4 md:py-2 bg-white text-black rounded-lg md:rounded-xl text-[8px] md:text-[10px] font-black tracking-widest uppercase">
                  Idle
                </div>
                <div className="px-3 py-1.5 md:px-4 md:py-2 bg-white/5 backdrop-blur-md border border-white/10 rounded-lg md:rounded-xl text-[8px] md:text-[10px] font-mono text-white/30 tracking-tight">
                  00:00:00:00
                </div>
              </div>
            </div>

            <div className="absolute bottom-8 left-8 right-8 flex items-center justify-between">
              <div className="hidden sm:flex gap-4">
                <div className="flex flex-col">
                  <span className="text-[8px] md:text-[9px] font-black text-white/10 uppercase tracking-widest">
                    Resolution
                  </span>
                  <span className="text-[10px] md:text-xs font-bold text-white/40">----</span>
                </div>
              </div>

              <div className="flex items-center gap-3 md:gap-5">
                <button className="w-10 h-10 md:w-14 md:h-14 rounded-xl md:rounded-2xl bg-white/5 hover:bg-white/10 flex items-center justify-center backdrop-blur-md border border-white/10 transition-all group/play">
                  <Play size={20} className="text-white/20 group-hover/play:text-white fill-current transition-colors" />
                </button>
                <button className="w-10 h-10 md:w-14 md:h-14 rounded-xl md:rounded-2xl bg-white/5 hover:bg-white/10 flex items-center justify-center backdrop-blur-md border border-white/10 transition-all group/max">
                  <Maximize2 size={18} className="text-white/20 group-hover/max:text-white transition-colors" />
                </button>
              </div>
            </div>
          </motion.div>
        </div>

        <div
          className="hidden md:flex relative w-12 group/handle cursor-col-resize z-30 items-center justify-center -mx-6 transition-all"
          onMouseDown={startResizing}
        >
          <div
            className={`w-[1px] h-[60%] transition-all duration-300 ${
              isResizing
                ? "bg-white h-full shadow-[0_0_20px_rgba(255,255,255,0.8)]"
                : "bg-white/10 group-hover/handle:bg-white/40 group-hover/handle:h-[80%]"
            }`}
          />
          <div
            className={`absolute w-1.5 h-12 bg-white rounded-full transition-all duration-500 opacity-0 group-hover/handle:opacity-100 ${
              isResizing ? "scale-y-150 h-24" : "scale-y-100"
            }`}
          />
          <div className="absolute -top-6 text-[8px] font-black tracking-widest text-white/0 group-hover/handle:text-white/20 transition-all uppercase whitespace-nowrap">
            Resize_Engine
          </div>
        </div>

        <div
          className="flex flex-col gap-6 md:gap-8 min-h-0 shrink-0 md:pl-8 w-full md:w-auto overflow-hidden"
          style={{ width: isMobileLayout ? "100%" : explorerWidth }}
        >
          <div className="flex items-center justify-between px-2">
            <h3 className="text-[10px] md:text-[11px] font-black tracking-[0.4em] uppercase text-white/30 truncate">
              Assets
            </h3>
            <button className="text-white/20 hover:text-white transition-colors shrink-0">
              <Search size={16} />
            </button>
          </div>

          <div className="flex-1 overflow-visible space-y-4 md:space-y-5 pr-2 scrollbar-none relative">
            {projects.map((project) => (
              <motion.div
                key={project.id}
                initial={false}
                whileHover={{
                  scale: 1.05,
                  x: -8,
                  zIndex: 50,
                }}
                transition={{ duration: 0.1, ease: "linear" }}
                className="group relative flex gap-4 md:gap-5 p-3 md:p-4 rounded-2xl md:rounded-3xl cursor-pointer bg-white/[0.01] hover:bg-black hover:shadow-[0_15px_40px_rgba(0,0,0,0.8)] border border-white/[0.03] hover:border-white/20 transition-all duration-200"
              >
                <div className="relative w-20 h-14 md:w-28 md:h-20 rounded-xl md:rounded-2xl overflow-hidden bg-white/5 border border-white/5 shrink-0">
                  <img
                    src={project.thumb}
                    alt=""
                    className="w-full h-full object-cover grayscale group-hover:grayscale-0 transition-all duration-300 opacity-60 group-hover:opacity-100"
                  />
                </div>

                <div className="flex flex-col justify-center flex-1 min-w-0">
                  <div className="flex items-center justify-between mb-1">
                    <span className="text-[11px] md:text-sm font-bold text-white/80 group-hover:text-white truncate tracking-tight">
                      {project.name}
                    </span>
                  </div>
                  <div className="flex flex-col gap-0.5 md:gap-1">
                    <span className="text-[8px] md:text-[10px] font-mono text-white/20 tracking-tighter truncate">
                      {project.meta}
                    </span>
                    <div className="text-[8px] md:text-[9px] text-white/40 font-bold uppercase tracking-widest">
                      {project.date}
                    </div>
                  </div>
                </div>
              </motion.div>
            ))}
          </div>

          <div className="p-6 rounded-3xl border border-white/5 bg-white/[0.01] shrink-0 mt-auto">
            <div className="flex justify-between items-end mb-4">
              <p className="text-[10px] font-black tracking-widest text-white/20 uppercase">Core Storage</p>
              <p className="text-[10px] font-mono text-white/40">42%</p>
            </div>
            <div className="h-1 w-full bg-white/5 rounded-full overflow-hidden">
              <div className="h-full w-[42%] bg-white/60" />
            </div>
          </div>
        </div>
      </main>

      <footer className="mt-12 flex items-center justify-between px-2 shrink-0">
        <div className="flex items-center gap-8 text-[10px] text-white/20 tracking-[0.3em] uppercase font-black">
          <div className="flex items-center gap-2.5">
            <div className="w-2 h-2 rounded-full bg-white" />
            Core_Online
          </div>
          <div className="flex items-center gap-2.5">
            <div className="w-2 h-2 rounded-full border border-white/20" />
            Neural_Engine_Wait
          </div>
        </div>

        <div className="text-[10px] font-mono text-white/10 tracking-widest uppercase">
          FinCap_OS // Build_2026.04.13
        </div>
      </footer>
    </div>
  );
}
