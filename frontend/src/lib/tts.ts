export type EdgeTtsVoice = {
  ShortName: string;
  Locale: string;
  FriendlyName?: string;
  DisplayName?: string;
  LocalName?: string;
  Gender?: string;
};

import { ensureBackendReady, resolveBackendUrl } from "./backend-runtime";

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
  await ensureBackendReady();
  const response = await fetch(buildApiUrl("/api/tts/voices"));

  if (!response.ok) {
    throw new Error(await extractBackendError(response));
  }

  const data = (await response.json()) as { voices?: EdgeTtsVoice[] };
  return Array.isArray(data.voices) ? data.voices : [];
};

export const testTtsBackendConnection = async (voice: string, text: string) => {
  await ensureBackendReady();
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
  await ensureBackendReady();
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
