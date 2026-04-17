import { ArrowRight, CornerDownLeft } from "lucide-react";

type WorkflowNodeConnectorProps = {
  vertical?: boolean;
};

export function WorkflowNodeConnector({
  vertical = false,
}: WorkflowNodeConnectorProps) {
  if (vertical) {
    return (
      <div className="flex items-center justify-center py-3 text-white/20">
        <CornerDownLeft size={20} />
      </div>
    );
  }

  return (
    <div className="hidden items-center justify-center px-2 text-white/20 xl:flex">
      <ArrowRight size={20} />
    </div>
  );
}
