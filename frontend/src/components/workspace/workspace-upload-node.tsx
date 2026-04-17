import { useRef, type ChangeEvent } from "react";

import type { ProjectItem } from "../../types/project";
import { WorkflowNodeCard, type WorkflowNodeTone } from "./workflow-node-card";
import { WorkflowNodeMetric } from "./workflow-node-metric";

type WorkspaceUploadNodeProps = {
  project: ProjectItem | null;
  isUploading: boolean;
  tone: WorkflowNodeTone;
  message: string;
  onUpload: (file: File) => void;
};

function formatUpdatedAt(project: ProjectItem | null) {
  if (!project) {
    return "No Project";
  }

  return new Date(project.updatedAt).toLocaleString();
}

export function WorkspaceUploadNode({
  project,
  isUploading,
  tone,
  message,
  onUpload,
}: WorkspaceUploadNodeProps) {
  const fileInputRef = useRef<HTMLInputElement>(null);

  const handleFileChange = (event: ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) {
      return;
    }

    onUpload(file);
    event.target.value = "";
  };

  return (
    <WorkflowNodeCard
      eyebrow="01"
      title="Upload Video"
      status={project ? "Ready" : "Empty"}
      description="Source"
      active={Boolean(project)}
      tone={tone}
      message={message}
      actions={[
        {
          label: "Upload",
          onClick: () => fileInputRef.current?.click(),
          busy: isUploading,
          variant: "default",
        },
      ]}
    >
      <div className="grid gap-3 md:grid-cols-2 xl:grid-cols-3">
        <WorkflowNodeMetric label="Project" value={project?.name ?? "--"} />
        <WorkflowNodeMetric label="Meta" value={project?.meta ?? "--"} />
        <WorkflowNodeMetric label="Updated" value={formatUpdatedAt(project)} />
      </div>

      <input
        ref={fileInputRef}
        type="file"
        accept="video/*"
        className="hidden"
        onChange={handleFileChange}
      />
    </WorkflowNodeCard>
  );
}
