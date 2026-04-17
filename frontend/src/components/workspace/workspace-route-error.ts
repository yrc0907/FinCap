export const WORKSPACE_ROUTE_MISSING_MESSAGE = "后端需要重启一次。";

const WORKSPACE_ROUTE_MISSING_ERRORS = new Set(["Not Found", "404 Not Found", "HTTP 404"]);

export const isWorkspaceRouteMissingError = (error: unknown) => {
  if (!(error instanceof Error)) {
    return false;
  }
  return WORKSPACE_ROUTE_MISSING_ERRORS.has(error.message.trim());
};
