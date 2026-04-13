export type EdgeTtsVoice = {
  ShortName: string;
  Locale: string;
  FriendlyName?: string;
  DisplayName?: string;
  LocalName?: string;
  Gender?: string;
};

const DEFAULT_TTS_BACKEND_URL = "http://127.0.0.1:8765";

const resolveBackendUrl = () => {
  const envUrl = import.meta.env.VITE_TTS_BACKEND_URL;
  return (typeof envUrl === "string" && envUrl.trim() ? envUrl : DEFAULT_TTS_BACKEND_URL).replace(
    /\/+$/,
    "",
  );
};

const buildApiUrl = (path: string) => `${resolveBackendUrl()}${path}`;

const extractBackendError = async (response: Response) => {
  const fallback = `HTTP ${response.status}`;
  const text = await response.text();

  if (!text) {
    return fallback;
  }

  try {
    const parsed = JSON.parse(text) as { detail?: string; message?: string };
    return parsed.detail || parsed.message || fallback;
  } catch {
    return text.length > 160 ? `${text.slice(0, 157)}...` : text;
  }
};

export const fetchTtsVoices = async () => {
  const response = await fetch(buildApiUrl("/api/tts/voices"));

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  const data = (await response.json()) as { voices?: EdgeTtsVoice[] };
  return Array.isArray(data.voices) ? data.voices : [];
};

export const testTtsBackendConnection = async (voice: string, text: string) => {
  const response = await fetch(buildApiUrl("/api/tts/test"), {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      voice,
      text,
    }),
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }
};

export const synthesizeTtsAudio = async (voice: string, text: string) => {
  const response = await fetch(buildApiUrl("/api/tts/synthesize"), {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      voice,
      text,
    }),
  });

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  return response.blob();
};
