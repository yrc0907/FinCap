import { AnimatePresence, motion } from "framer-motion";
import { Database, Mic, Play, Plus, Settings, Trash2, Type, Wifi, X } from "lucide-react";
import { type Dispatch, type SetStateAction, useEffect, useRef, useState } from "react";
import { toast } from "sonner";

import {
  createModelConfig,
  createTestPayload,
  DEFAULT_MODEL,
  DEFAULT_TTS_TEXT,
  extractErrorMessage,
  OPENAI_COMPATIBLE_PLACEHOLDER,
  resolveChatCompletionsUrl,
} from "../lib/settings";
import { fetchTtsVoices, synthesizeTtsAudio, testTtsBackendConnection, type EdgeTtsVoice } from "../lib/tts";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "./ui/select";
import type { ConnectionStatus, ModelConfig, SystemConfig, TtsConfig } from "../types/settings";

type SettingsModalProps = {
  open: boolean;
  settings: SystemConfig;
  setSettings: Dispatch<SetStateAction<SystemConfig>>;
  onApply: () => void;
  onClose: () => void;
  onDiscard: () => void;
};

export function SettingsModal({
  open,
  settings,
  setSettings,
  onApply,
  onClose,
  onDiscard,
}: SettingsModalProps) {
  const [ttsVoices, setTtsVoices] = useState<EdgeTtsVoice[]>([]);
  const [isLoadingVoices, setIsLoadingVoices] = useState(false);
  const [ttsVoiceError, setTtsVoiceError] = useState<string | null>(null);
  const audioRef = useRef<HTMLAudioElement | null>(null);
  const audioUrlRef = useRef<string | null>(null);

  useEffect(() => {
    if (!open) {
      return;
    }

    let active = true;

    const loadVoices = async () => {
      try {
        setIsLoadingVoices(true);
        setTtsVoiceError(null);
        const voices = await fetchTtsVoices();

        if (!active) {
          return;
        }

        setTtsVoices(voices);

        if (!settings.ttsConfig.voice && voices.length > 0) {
          setSettings((prev) => ({
            ...prev,
            ttsConfig: {
              ...prev.ttsConfig,
              voice: voices[0].ShortName,
            },
          }));
        }
      } catch (error) {
        if (!active) {
          return;
        }

        setTtsVoices([]);
        const message = error instanceof Error ? error.message : "Unable to load voices.";
        setTtsVoiceError(message);
        updateTtsConfig({ status: "error" });
        toast.error(`TTS voice list failed: ${message}`);
      } finally {
        if (active) {
          setIsLoadingVoices(false);
        }
      }
    };

    void loadVoices();

    return () => {
      active = false;
    };
  }, [open]);

  useEffect(() => {
    return () => {
      audioRef.current?.pause();
      if (audioUrlRef.current) {
        URL.revokeObjectURL(audioUrlRef.current);
      }
    };
  }, []);

  const updateConfigs = (
    type: "vlmConfigs" | "llmConfigs",
    id: number,
    updater: (config: ModelConfig) => ModelConfig,
  ) => {
    setSettings((prev) => ({
      ...prev,
      [type]: prev[type].map((config) => (config.id === id ? updater(config) : config)),
    }));
  };

  const setConfigField = (
    type: "vlmConfigs" | "llmConfigs",
    id: number,
    field: keyof Omit<ModelConfig, "id">,
    value: string | ConnectionStatus,
  ) => {
    updateConfigs(type, id, (config) => ({
      ...config,
      [field]: value,
    }));
  };

  const addModelConfig = (type: "vlmConfigs" | "llmConfigs") => {
    setSettings((prev) => ({
      ...prev,
      [type]: [...prev[type], createModelConfig()],
    }));
  };

  const removeModelConfig = (type: "vlmConfigs" | "llmConfigs", id: number) => {
    setSettings((prev) => ({
      ...prev,
      [type]: prev[type].length > 1 ? prev[type].filter((config) => config.id !== id) : prev[type],
    }));
  };

  const updateTtsConfig = (patch: Partial<TtsConfig>) => {
    setSettings((prev) => ({
      ...prev,
      ttsConfig: {
        ...prev.ttsConfig,
        ...patch,
      },
    }));
  };

  const stopCurrentAudio = () => {
    audioRef.current?.pause();
    audioRef.current?.removeAttribute("src");
    audioRef.current = null;

    if (audioUrlRef.current) {
      URL.revokeObjectURL(audioUrlRef.current);
      audioUrlRef.current = null;
    }
  };

  const testModelConnection = async (type: "vlm" | "llm", id?: number) => {
    const key = type === "vlm" ? "vlmConfigs" : "llmConfigs";
    const label = type.toUpperCase();
    const target = settings[key].find((config) => config.id === id);

    if (!target) {
      toast.error(`${label} node not found.`);
      return;
    }

    if (!target.endpoint.trim() || !target.key.trim() || !target.model.trim()) {
      setConfigField(key, target.id, "status", "error");
      toast.error(`${label} endpoint, model, and API key are required.`);
      return;
    }

    setConfigField(key, target.id, "status", "testing");

    try {
      const response = await fetch(resolveChatCompletionsUrl(target.endpoint), {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
          Authorization: `Bearer ${target.key.trim()}`,
        },
        body: JSON.stringify(createTestPayload(type, target.model.trim())),
      });

      if (!response.ok) {
        throw new Error(await extractErrorMessage(response));
      }

      setConfigField(key, target.id, "status", "success");
      toast.success(`${label} connection succeeded.`);
    } catch (error) {
      const message =
        error instanceof Error
          ? error.message
          : "Request failed. Check the endpoint, model, API key, or network access.";

      setConfigField(key, target.id, "status", "error");
      toast.error(`${label} connection failed: ${message}`);
    }
  };

  const testTtsConnection = async () => {
    const selectedVoice = settings.ttsConfig.voice.trim();

    if (!selectedVoice) {
      updateTtsConfig({ status: "error" });
      toast.error("TTS voice is required.");
      return;
    }

    updateTtsConfig({ status: "testing" });

    try {
      await testTtsBackendConnection(selectedVoice, "Edge TTS connection test.");
      updateTtsConfig({ status: "success" });
      toast.success("TTS connection succeeded.");
    } catch (error) {
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateTtsConfig({ status: "error" });
      toast.error(`TTS connection failed: ${message}`);
    }
  };

  const previewTtsVoice = async () => {
    const selectedVoice = settings.ttsConfig.voice.trim();
    const text = settings.ttsConfig.text.trim() || DEFAULT_TTS_TEXT;

    if (!selectedVoice) {
      updateTtsConfig({ status: "error" });
      toast.error("TTS voice is required.");
      return;
    }

    updateTtsConfig({ status: "testing" });

    try {
      stopCurrentAudio();
      const audioBlob = await synthesizeTtsAudio(selectedVoice, text);
      const audioUrl = URL.createObjectURL(audioBlob);
      const audio = new Audio(audioUrl);

      audioRef.current = audio;
      audioUrlRef.current = audioUrl;

      audio.addEventListener(
        "ended",
        () => {
          updateTtsConfig({ status: "success" });
        },
        { once: true },
      );

      await audio.play();
      updateTtsConfig({ status: "success" });
      toast.success("Preview started.");
    } catch (error) {
      stopCurrentAudio();
      const message = error instanceof Error ? error.message : "Unknown error.";
      updateTtsConfig({ status: "error" });
      toast.error(`Preview failed: ${message}`);
    }
  };

  const renderStatusButtonClass = (status: ConnectionStatus) => {
    if (status === "success") {
      return "bg-emerald-500/10 border-emerald-500/50 text-emerald-500";
    }

    if (status === "error") {
      return "bg-red-500/10 border-red-500/50 text-red-400";
    }

    if (status === "testing") {
      return "bg-white/5 border-white/20 text-white animate-pulse";
    }

    return "bg-white/5 border-white/10 text-white/20 hover:text-white hover:border-white/30";
  };

  const renderModelSection = (
    type: "vlmConfigs" | "llmConfigs",
    title: string,
    icon: "vlm" | "llm",
  ) => {
    const items = settings[type];
    const Icon = icon === "vlm" ? Database : Type;

    return (
      <section className="space-y-6">
        <div className="flex items-center justify-between gap-3">
          <div className="flex items-center gap-3">
            <Icon size={16} className="text-white/40" />
            <h3 className="text-[10px] font-black tracking-[0.3em] uppercase text-white/40">{title}</h3>
          </div>
          <button
            onClick={() => addModelConfig(type)}
            className="flex items-center gap-2 px-4 py-2 bg-white/5 hover:bg-white/10 rounded-xl transition-all group"
          >
            <Plus size={14} className="text-white/40 group-hover:text-white" />
            <span className="text-[9px] font-bold uppercase tracking-widest text-white/40 group-hover:text-white">
              Add
            </span>
          </button>
        </div>

        <div className="max-h-[420px] overflow-y-auto pr-2 space-y-4 scrollbar-thin scrollbar-thumb-white/10 scrollbar-track-transparent">
          <AnimatePresence initial={false}>
            {items.map((config) => (
              <motion.div
                key={config.id}
                initial={{ opacity: 0, height: 0, marginBottom: 0 }}
                animate={{ opacity: 1, height: "auto", marginBottom: 16 }}
                exit={{ opacity: 0, height: 0, marginBottom: 0 }}
                transition={{ duration: 0.3, ease: [0.16, 1, 0.3, 1] }}
                className="overflow-hidden"
              >
                <div className="grid grid-cols-1 md:grid-cols-[1.3fr_1fr_1fr_auto] gap-4 items-end bg-white/[0.02] border border-white/5 p-5 rounded-[20px] hover:border-white/10 transition-colors">
                  <div className="space-y-2">
                    <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                      Endpoint
                    </label>
                    <input
                      type="text"
                      placeholder={OPENAI_COMPATIBLE_PLACEHOLDER}
                      value={config.endpoint}
                      onChange={(e) => setConfigField(type, config.id, "endpoint", e.target.value)}
                      className="w-full bg-white/[0.03] border border-white/10 rounded-xl px-5 py-3 text-xs font-mono focus:outline-none focus:border-white/30 transition-colors"
                    />
                  </div>
                  <div className="space-y-2">
                    <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                      Model
                    </label>
                    <input
                      type="text"
                      placeholder={DEFAULT_MODEL}
                      value={config.model}
                      onChange={(e) => setConfigField(type, config.id, "model", e.target.value)}
                      className="w-full bg-white/[0.03] border border-white/10 rounded-xl px-5 py-3 text-xs font-mono focus:outline-none focus:border-white/30 transition-colors"
                    />
                  </div>
                  <div className="space-y-2">
                    <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                      API Key
                    </label>
                    <input
                      type="password"
                      placeholder="sk-..."
                      value={config.key}
                      onChange={(e) => setConfigField(type, config.id, "key", e.target.value)}
                      className="w-full bg-white/[0.03] border border-white/10 rounded-xl px-5 py-3 text-xs font-mono focus:outline-none focus:border-white/30 transition-colors"
                    />
                  </div>
                  <div className="flex gap-2">
                    <button
                      onClick={() => void testModelConnection(icon, config.id)}
                      className={`w-10 h-10 flex items-center justify-center rounded-xl border transition-all ${renderStatusButtonClass(config.status)}`}
                      title="Test Link"
                    >
                      <Wifi size={16} />
                    </button>
                    {items.length > 1 && (
                      <button
                        onClick={() => removeModelConfig(type, config.id)}
                        className="w-10 h-10 flex items-center justify-center bg-red-500/5 border border-red-500/10 rounded-xl text-red-500/40 hover:text-red-500 hover:bg-red-500/10 transition-all"
                      >
                        <Trash2 size={16} />
                      </button>
                    )}
                  </div>
                </div>
              </motion.div>
            ))}
          </AnimatePresence>
        </div>
      </section>
    );
  };

  if (!open) {
    return null;
  }

  return (
    <motion.div
      initial={{ opacity: 0, backdropFilter: "blur(0px)" }}
      animate={{ opacity: 1, backdropFilter: "blur(20px)" }}
      className="fixed inset-0 z-[100] bg-black/60 flex items-center justify-center p-4 md:p-10"
    >
      <motion.div
        initial={{ scale: 0.9, opacity: 0, y: 20 }}
        animate={{ scale: 1, opacity: 1, y: 0 }}
        className="w-full max-w-5xl bg-[#0a0a0a] border border-white/10 rounded-[32px] md:rounded-[48px] overflow-hidden shadow-[0_0_100px_rgba(0,0,0,1)] flex flex-col max-h-[90vh]"
      >
        <div className="p-8 md:p-12 flex items-center justify-between border-b border-white/5">
          <div className="flex items-center gap-4">
            <div className="w-12 h-12 bg-white/5 rounded-2xl flex items-center justify-center">
              <Settings size={24} className="text-white/40" />
            </div>
            <h2 className="text-2xl font-black tracking-tight uppercase">Settings</h2>
          </div>
          <button
            onClick={onClose}
            className="w-12 h-12 bg-white/5 hover:bg-white/10 rounded-2xl flex items-center justify-center transition-all group"
          >
            <X size={24} className="text-white/20 group-hover:text-white transition-colors" />
          </button>
        </div>

        <div className="flex-1 overflow-y-auto p-8 md:p-12 space-y-12 scrollbar-none">
          {renderModelSection("vlmConfigs", "VLM", "vlm")}
          {renderModelSection("llmConfigs", "LLM", "llm")}

          <section className="space-y-6">
            <div className="flex items-center justify-between gap-3">
              <div className="flex items-center gap-3">
                <Mic size={16} className="text-white/40" />
                <h3 className="text-[10px] font-black tracking-[0.3em] uppercase text-white/40">
                  Edge TTS
                </h3>
              </div>
              <div className="flex items-center gap-2">
                <button
                  onClick={() => void previewTtsVoice()}
                  className="flex items-center gap-2 px-4 py-2 rounded-xl border border-white/10 bg-white/5 text-white/70 transition-all hover:border-white/30 hover:text-white"
                >
                  <Play size={14} />
                  <span className="text-[9px] font-bold uppercase tracking-widest">Preview</span>
                </button>
                <button
                  onClick={() => void testTtsConnection()}
                  className={`flex items-center gap-2 px-4 py-2 rounded-xl border transition-all ${renderStatusButtonClass(settings.ttsConfig.status)}`}
                >
                  <Wifi size={14} />
                  <span className="text-[9px] font-bold uppercase tracking-widest">Test Link</span>
                </button>
              </div>
            </div>

            <div className="grid grid-cols-1 md:grid-cols-2 gap-4 bg-white/[0.02] border border-white/5 p-5 rounded-[20px] hover:border-white/10 transition-colors">
              <div className="space-y-2">
                <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                  Voice
                </label>
                <Select
                  value={settings.ttsConfig.voice}
                  onValueChange={(value) => updateTtsConfig({ voice: value, status: "idle" })}
                >
                  <SelectTrigger>
                    <SelectValue placeholder="Select voice" />
                  </SelectTrigger>
                  <SelectContent>
                    {isLoadingVoices ? (
                      <SelectItem value="loading-voices" disabled>
                        Loading voices...
                      </SelectItem>
                    ) : ttsVoiceError ? (
                      <SelectItem value="backend-offline" disabled>
                        TTS backend offline
                      </SelectItem>
                    ) : ttsVoices.length === 0 ? (
                      <SelectItem value="no-voices" disabled>
                        No voices available
                      </SelectItem>
                    ) : (
                      ttsVoices.map((voice) => (
                        <SelectItem key={voice.ShortName} value={voice.ShortName}>
                          {(voice.DisplayName || voice.LocalName || voice.ShortName)} ({voice.Locale})
                        </SelectItem>
                      ))
                    )}
                  </SelectContent>
                </Select>
              </div>

              <div className="space-y-2">
                <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                  Status
                </label>
                <div className="w-full bg-white/[0.03] border border-white/10 rounded-xl px-5 py-3 text-xs font-mono text-white/60">
                  {settings.ttsConfig.status.toUpperCase()}
                </div>
              </div>

              <div className="space-y-2 md:col-span-2">
                <label className="text-[9px] font-mono text-white/20 uppercase tracking-widest px-1">
                  Text
                </label>
                <input
                  type="text"
                  placeholder={DEFAULT_TTS_TEXT}
                  value={settings.ttsConfig.text}
                  onChange={(e) => updateTtsConfig({ text: e.target.value, status: "idle" })}
                  className="w-full bg-white/[0.03] border border-white/10 rounded-xl px-5 py-3 text-xs font-mono focus:outline-none focus:border-white/30 transition-colors"
                />
              </div>
            </div>
          </section>
        </div>

        <div className="p-8 border-t border-white/5 bg-white/[0.01] flex justify-end gap-4">
          <button
            onClick={onDiscard}
            className="px-8 py-4 rounded-2xl text-[10px] font-black uppercase tracking-widest text-white/40 hover:text-white transition-colors"
          >
            Cancel
          </button>
          <button
            onClick={onApply}
            className="px-8 py-4 bg-white text-black rounded-2xl text-[10px] font-black uppercase tracking-widest hover:scale-105 active:scale-95 transition-all"
          >
            Save
          </button>
        </div>
      </motion.div>
    </motion.div>
  );
}
