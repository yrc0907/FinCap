import { afterEach, beforeEach, describe, expect, it } from "vitest";

import {
  clearAppSessionState,
  loadAppSessionState,
  resolveAppSessionState,
  saveAppSessionState,
} from "./app-session-state";

describe("app session state", () => {
  beforeEach(() => {
    window.localStorage.clear();
  });

  afterEach(() => {
    window.localStorage.clear();
  });

  it("loads a saved workspace session from localStorage", () => {
    window.localStorage.setItem(
      "fincap.app-session",
      JSON.stringify({
        currentView: "workspace",
        activeProjectId: "project-2",
      }),
    );

    expect(loadAppSessionState()).toEqual({
      currentView: "workspace",
      activeProjectId: "project-2",
    });
  });

  it("falls back to home when the saved project is no longer available", () => {
    const resolved = resolveAppSessionState(
      {
        currentView: "workspace",
        activeProjectId: "missing-project",
      },
      [{ id: "project-1" }, { id: "project-2" }],
    );

    expect(resolved).toEqual({
      currentView: "home",
      activeProjectId: null,
    });
  });

  it("keeps workspace open when the saved project still exists", () => {
    const resolved = resolveAppSessionState(
      {
        currentView: "workspace",
        activeProjectId: "project-2",
      },
      [{ id: "project-1" }, { id: "project-2" }],
    );

    expect(resolved).toEqual({
      currentView: "workspace",
      activeProjectId: "project-2",
    });
  });

  it("can save and clear the app session", () => {
    saveAppSessionState({
      currentView: "workspace",
      activeProjectId: "project-3",
    });

    expect(loadAppSessionState()).toEqual({
      currentView: "workspace",
      activeProjectId: "project-3",
    });

    clearAppSessionState();

    expect(loadAppSessionState()).toEqual({
      currentView: "home",
      activeProjectId: null,
    });
  });
});
