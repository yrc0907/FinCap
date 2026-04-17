import type { VlmControlsPayload } from "./workspace-config";
import { WorkspaceCharacterReferenceList } from "./workspace-character-reference-list";

type WorkspaceCharacterReferenceShellProps = {
  references: VlmControlsPayload["characterReferences"];
  onAdd: () => void;
  onUpdate: (id: string, key: "name" | "imageBase64", value: string) => void;
  onRemove: (id: string) => void;
};

export function WorkspaceCharacterReferenceShell({
  references,
  onAdd,
  onUpdate,
  onRemove,
}: WorkspaceCharacterReferenceShellProps) {
  return (
    <div className="space-y-4">
      <div>
        <div className="text-[10px] font-black uppercase tracking-[0.24em] text-white/70">
          Character References
        </div>
        <div className="mt-2 text-[10px] font-mono uppercase tracking-[0.22em] text-white/25">
          Upload and name references before VLM
        </div>
      </div>
      <WorkspaceCharacterReferenceList
        references={references}
        onAdd={onAdd}
        onUpdate={onUpdate}
        onRemove={onRemove}
      />
    </div>
  );
}
