import { useState, type Dispatch, type SetStateAction } from "react";

import type { VlmControlsPayload } from "./workspace-config";

type UseVlmControlsResult = {
  vlmPayload: VlmControlsPayload;
  setVlmPayload: Dispatch<SetStateAction<VlmControlsPayload>>;
  updateVlmField: <K extends keyof VlmControlsPayload>(key: K, value: string | boolean) => void;
  updateVlmSubtitleRegionField: (
    key: keyof VlmControlsPayload["subtitleRegion"],
    value: string,
  ) => void;
  addCharacterReference: () => void;
  updateCharacterReference: (id: string, key: "name" | "imageBase64", value: string) => void;
  removeCharacterReference: (id: string) => void;
};

export function useVlmControls(initialPayload: VlmControlsPayload): UseVlmControlsResult {
  const [vlmPayload, setVlmPayload] = useState<VlmControlsPayload>(initialPayload);

  const updateVlmField = <K extends keyof VlmControlsPayload>(key: K, value: string | boolean) => {
    setVlmPayload((current) => {
      if (typeof current[key] === "number") {
        const parsed = Number(value);
        return {
          ...current,
          [key]: Number.isFinite(parsed) ? parsed : current[key],
        };
      }
      return {
        ...current,
        [key]: value,
      };
    });
  };

  const updateVlmSubtitleRegionField = (
    key: keyof VlmControlsPayload["subtitleRegion"],
    value: string,
  ) => {
    const parsed = Number(value);
    setVlmPayload((current) => ({
      ...current,
      subtitleRegion: {
        ...current.subtitleRegion,
        [key]: Number.isFinite(parsed) ? parsed : current.subtitleRegion[key],
      },
    }));
  };

  const addCharacterReference = () => {
    setVlmPayload((current) => ({
      ...current,
      characterReferences: [
        ...current.characterReferences,
        { id: crypto.randomUUID(), name: "", imageBase64: "" },
      ],
    }));
  };

  const updateCharacterReference = (id: string, key: "name" | "imageBase64", value: string) => {
    setVlmPayload((current) => ({
      ...current,
      characterReferences: current.characterReferences.map((reference) =>
        reference.id === id ? { ...reference, [key]: value } : reference,
      ),
    }));
  };

  const removeCharacterReference = (id: string) => {
    setVlmPayload((current) => ({
      ...current,
      characterReferences: current.characterReferences.filter((reference) => reference.id !== id),
    }));
  };

  return {
    vlmPayload,
    setVlmPayload,
    updateVlmField,
    updateVlmSubtitleRegionField,
    addCharacterReference,
    updateCharacterReference,
    removeCharacterReference,
  };
}
