export type ProjectItem = {
  id: string;
  name: string;
  meta: string;
  createdAt: number;
  updatedAt: number;
  deletedAt: number | null;
  thumb?: string;
  isVideo?: boolean;
};
