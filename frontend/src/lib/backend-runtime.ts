let backendReadyPromise: Promise<void> | null = null;
let sidecarStarted = false;

const DEFAULT_BACKEND_URL = "http://127.0.0.1:8765";

export const resolveBackendUrl = () => {
  const envUrl = import.meta.env.VITE_TTS_BACKEND_URL;
  return (typeof envUrl === "string" && envUrl.trim() ? envUrl : DEFAULT_BACKEND_URL).replace(
    /\/+$/,
    "",
  );
};

const isTauriRuntime = () =>
  typeof window !== "undefined" &&
  (Object.prototype.hasOwnProperty.call(window, "__TAURI_INTERNALS__") ||
    Object.prototype.hasOwnProperty.call(window, "__TAURI__"));

const wait = (ms: number) => new Promise((resolve) => window.setTimeout(resolve, ms));

const isBackendHealthy = async () => {
  try {
    const response = await fetch(`${resolveBackendUrl()}/health`);
    return response.ok;
  } catch {
    return false;
  }
};

const waitForBackend = async (timeoutMs: number) => {
  const deadline = Date.now() + timeoutMs;

  while (Date.now() < deadline) {
    if (await isBackendHealthy()) {
      return;
    }

    await wait(250);
  }

  throw new Error("Backend is unavailable.");
};

const startSidecarIfNeeded = async () => {
  if (sidecarStarted || !isTauriRuntime()) {
    return;
  }

  const { Command } = await import("@tauri-apps/plugin-shell");
  const command = Command.sidecar("binaries/fincap-backend");
  await command.spawn();
  sidecarStarted = true;
};

export const ensureBackendReady = async () => {
  if (!backendReadyPromise) {
    backendReadyPromise = (async () => {
      if (await isBackendHealthy()) {
        return;
      }

      await startSidecarIfNeeded();
      await waitForBackend(15_000);
    })().catch((error) => {
      backendReadyPromise = null;
      throw error;
    });
  }

  await backendReadyPromise;
};
