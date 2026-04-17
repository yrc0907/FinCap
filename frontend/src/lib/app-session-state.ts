type AppView = "home" | "workspace";

type AppSessionState = {
  currentView: AppView;
  activeProjectId: string | null;
};

type SessionProjectLike = {
  id: string;
};

const APP_SESSION_STORAGE_KEY = "fincap.app-session";

const DEFAULT_APP_SESSION_STATE: AppSessionState = {
  currentView: "home",
  activeProjectId: null,
};

function isAppView(value: unknown): value is AppView {
  return value === "home" || value === "workspace";
}

export function loadAppSessionState(): AppSessionState {
  if (typeof window === "undefined") {
    return DEFAULT_APP_SESSION_STATE;
  }

  const rawValue = window.localStorage.getItem(APP_SESSION_STORAGE_KEY);
  if (!rawValue) {
    return DEFAULT_APP_SESSION_STATE;
  }

  try {
    const parsed = JSON.parse(rawValue) as Partial<AppSessionState>;
    return {
      currentView: isAppView(parsed.currentView) ? parsed.currentView : "home",
      activeProjectId:
        typeof parsed.activeProjectId === "string" && parsed.activeProjectId.trim()
          ? parsed.activeProjectId
          : null,
    };
  } catch {
    return DEFAULT_APP_SESSION_STATE;
  }
}

export function saveAppSessionState(session: AppSessionState) {
  if (typeof window === "undefined") {
    return;
  }

  window.localStorage.setItem(APP_SESSION_STORAGE_KEY, JSON.stringify(session));
}

export function clearAppSessionState() {
  if (typeof window === "undefined") {
    return;
  }

  window.localStorage.removeItem(APP_SESSION_STORAGE_KEY);
}

export function resolveAppSessionState(
  session: AppSessionState,
  projects: SessionProjectLike[],
): AppSessionState {
  if (session.currentView !== "workspace" || !session.activeProjectId) {
    return DEFAULT_APP_SESSION_STATE;
  }

  const hasProject = projects.some((project) => project.id === session.activeProjectId);
  if (!hasProject) {
    return DEFAULT_APP_SESSION_STATE;
  }

  return session;
}

export type { AppSessionState };
