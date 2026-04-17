import type { ReactNode } from "react";

import {
  Dialog,
  DialogBody,
  DialogContent,
  DialogDescription,
  DialogFooter,
  DialogHeader,
  DialogTitle,
} from "../ui/dialog";

type WorkspacePreviewDialogProps = {
  open: boolean;
  title: string;
  description: string;
  footer?: ReactNode;
  contentClassName?: string;
  headerClassName?: string;
  bodyClassName?: string;
  footerClassName?: string;
  onOpenChange: (open: boolean) => void;
  children: ReactNode;
};

export function WorkspacePreviewDialog({
  open,
  title,
  description,
  footer,
  contentClassName,
  headerClassName,
  bodyClassName,
  footerClassName,
  onOpenChange,
  children,
}: WorkspacePreviewDialogProps) {
  return (
    <Dialog open={open} onOpenChange={onOpenChange}>
      <DialogContent className={contentClassName}>
        <DialogHeader className={headerClassName}>
          <DialogTitle>{title}</DialogTitle>
          <DialogDescription>{description}</DialogDescription>
        </DialogHeader>
        <DialogBody className={bodyClassName}>{children}</DialogBody>
        {footer ? <DialogFooter className={footerClassName}>{footer}</DialogFooter> : null}
      </DialogContent>
    </Dialog>
  );
}
