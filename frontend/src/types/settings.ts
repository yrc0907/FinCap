export type ConnectionStatus = "idle" | "testing" | "success" | "error";

export type ModelConfig = {
  id: number;
  endpoint: string;
  key: string;
  model: string;
  status: ConnectionStatus;
};

export type TtsConfig = {
  voice: string;
  text: string;
  status: ConnectionStatus;
};

export type SystemConfig = {
  vlmConfigs: ModelConfig[];
  llmConfigs: ModelConfig[];
  ttsConfig: TtsConfig;
};
