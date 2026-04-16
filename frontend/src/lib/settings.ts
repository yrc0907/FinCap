import type { ConnectionStatus, ModelConfig, SystemConfig } from "../types/settings";

export const STORAGE_KEY = "fincap.system-config.v1";
export const OPENAI_COMPATIBLE_PLACEHOLDER = "https://yunwu.ai/v1/chat/completions";
export const DEFAULT_MODEL = "gpt-4.1";
export const DEFAULT_TTS_VOICE = "";
export const DEFAULT_TTS_TEXT = "This is a test from FinCap.";

export const createModelConfig = (model = DEFAULT_MODEL): ModelConfig => ({
  id: Date.now() + Math.floor(Math.random() * 100_000),
  endpoint: OPENAI_COMPATIBLE_PLACEHOLDER,
  key: "",
  model,
  status: "idle",
});

export const createDefaultSettings = (): SystemConfig => ({
  vlmConfigs: [createModelConfig()],
  llmConfigs: [createModelConfig()],
  ttsConfig: {
    voice: DEFAULT_TTS_VOICE,
    text: DEFAULT_TTS_TEXT,
    status: "idle",
  },
});

export const withIdleStatus = (settings: SystemConfig): SystemConfig => ({
  vlmConfigs: settings.vlmConfigs.map((config) => ({ ...config, status: "idle" })),
  llmConfigs: settings.llmConfigs.map((config) => ({ ...config, status: "idle" })),
  ttsConfig: { ...settings.ttsConfig, status: "idle" },
});

export const loadStoredSettings = (): SystemConfig => {
  if (typeof window === "undefined") {
    return createDefaultSettings();
  }

  try {
    const raw = window.localStorage.getItem(STORAGE_KEY);

    if (!raw) {
      return createDefaultSettings();
    }

    const parsed = JSON.parse(raw) as Partial<SystemConfig>;
    const fallback = createDefaultSettings();

    const normalizeConfigs = (configs: unknown) => {
      if (!Array.isArray(configs) || configs.length === 0) {
        return [createModelConfig()];
      }

      return configs.map((config, index) => {
        const item = config as Partial<ModelConfig>;

        return {
          id: typeof item.id === "number" ? item.id : Date.now() + index,
          endpoint: typeof item.endpoint === "string" ? item.endpoint : "",
          key: typeof item.key === "string" ? item.key : "",
          model: typeof item.model === "string" && item.model.trim() ? item.model : DEFAULT_MODEL,
          status: "idle" as ConnectionStatus,
        };
      });
    };

    return {
      vlmConfigs: normalizeConfigs(parsed.vlmConfigs ?? fallback.vlmConfigs),
      llmConfigs: normalizeConfigs(parsed.llmConfigs ?? fallback.llmConfigs),
      ttsConfig: {
        voice:
          typeof parsed.ttsConfig?.voice === "string" && parsed.ttsConfig.voice.trim()
            ? parsed.ttsConfig.voice
            : fallback.ttsConfig.voice,
        text:
          typeof parsed.ttsConfig?.text === "string" && parsed.ttsConfig.text.trim()
            ? parsed.ttsConfig.text
            : fallback.ttsConfig.text,
        status: "idle",
      },
    };
  } catch {
    return createDefaultSettings();
  }
};

export const persistSettings = (settings: SystemConfig) => {
  if (typeof window === "undefined") {
    return;
  }

  window.localStorage.setItem(STORAGE_KEY, JSON.stringify(withIdleStatus(settings)));
};

export const resolveChatCompletionsUrl = (endpoint: string) => {
  const trimmed = endpoint.trim().replace(/\/+$/, "");

  if (!trimmed) {
    return "";
  }

  if (/\/chat\/completions$/i.test(trimmed)) {
    return trimmed;
  }

  if (/\/v\d+$/i.test(trimmed)) {
    return `${trimmed}/chat/completions`;
  }

  return `${trimmed}/v1/chat/completions`;
};

export const createTestPayload = (type: "vlm" | "llm", model: string) => {
  if (type === "vlm") {
    return {
      model,
      messages: [
        {
          role: "user",
          content: [
            {
              type: "text",
              text: "Reply with OK only.",
            },
          ],
        },
      ],
      max_tokens: 8,
      temperature: 0,
      stream: false,
    };
  }

  return {
    model,
    messages: [
      {
        role: "user",
        content: "Reply with OK only.",
      },
    ],
    max_tokens: 8,
    temperature: 0,
    stream: false,
  };
};

export const extractErrorMessage = async (response: Response) => {
  const fallback = `HTTP ${response.status}`;
  const text = await response.text();

  if (!text) {
    return fallback;
  }

  try {
    const parsed = JSON.parse(text) as {
      error?: { message?: string };
      message?: string;
    };

    return parsed.error?.message || parsed.message || fallback;
  } catch {
    return text.length > 120 ? `${text.slice(0, 117)}...` : text;
  }
};
