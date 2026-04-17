import { render, screen } from "@testing-library/react";
import { describe, expect, it } from "vitest";

import { WorkflowNodeCard } from "./workflow-node-card";

describe("WorkflowNodeCard", () => {
  it("renders success feedback on the node frame", async () => {
    const { container } = render(
      <WorkflowNodeCard
        eyebrow="02"
        title="Boundary"
        status="Done"
        tone="success"
        message="Boundary done"
      />,
    );

    expect(await screen.findByText("Boundary done")).toBeInTheDocument();
    expect(container.querySelector('[data-tone="success"]')).toBeTruthy();
  });

  it("renders error feedback on the node frame", async () => {
    const { container } = render(
      <WorkflowNodeCard
        eyebrow="02"
        title="Boundary"
        status="Failed"
        tone="error"
        message="Boundary failed"
      />,
    );

    expect(await screen.findByText("Boundary failed")).toBeInTheDocument();
    expect(container.querySelector('[data-tone="error"]')).toBeTruthy();
  });
});
