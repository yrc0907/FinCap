import { describe, expect, it } from "vitest";

import { isWorkspaceRouteMissingError } from "./workspace-route-error";

describe("isWorkspaceRouteMissingError", () => {
  it("matches the generic fastapi route-missing errors only", () => {
    expect(isWorkspaceRouteMissingError(new Error("Not Found"))).toBe(true);
    expect(isWorkspaceRouteMissingError(new Error("404 Not Found"))).toBe(true);
    expect(isWorkspaceRouteMissingError(new Error("HTTP 404"))).toBe(true);
    expect(isWorkspaceRouteMissingError(new Error("Project not found."))).toBe(false);
    expect(isWorkspaceRouteMissingError(new Error("Backend is unavailable."))).toBe(false);
  });
});
