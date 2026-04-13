import { useEffect, useState } from "react";
import { Toaster, toast } from "sonner";

import { DashboardShell } from "./components/dashboard-shell";
import { SettingsModal } from "./components/settings-modal";
import { loadStoredSettings, persistSettings, withIdleStatus } from "./lib/settings";
import type { SystemConfig } from "./types/settings";
import "./index.css";

const cloneSettings = (settings: SystemConfig): SystemConfig =>
  JSON.parse(JSON.stringify(settings)) as SystemConfig;

function App() {
  const [showSettings, setShowSettings] = useState(false);
  const [settings, setSettings] = useState<SystemConfig>(() => loadStoredSettings());
  const [settingsSnapshot, setSettingsSnapshot] = useState<SystemConfig | null>(null);

  useEffect(() => {
    persistSettings(settings);
  }, [settings]);

  const openSettings = () => {
    setSettingsSnapshot(cloneSettings(withIdleStatus(settings)));
    setShowSettings(true);
  };

  const closeSettings = () => {
    setShowSettings(false);
  };

  const applyConfiguration = () => {
    const sanitized = withIdleStatus(settings);
    setSettings(sanitized);
    persistSettings(sanitized);
    setSettingsSnapshot(cloneSettings(sanitized));
    toast.success("Settings saved.");
    closeSettings();
  };

  const discardChanges = () => {
    if (settingsSnapshot) {
      setSettings(settingsSnapshot);
      persistSettings(settingsSnapshot);
      toast.info("Changes discarded.");
    }

    closeSettings();
  };

  return (
    <>
      <Toaster
        closeButton
        position="top-right"
        richColors
        theme="dark"
        toastOptions={{
          classNames: {
            toast: "border border-white/10 bg-[#090909] text-white",
            title: "text-sm font-semibold",
            description: "text-xs text-white/60",
          },
        }}
      />

      <DashboardShell onOpenSettings={openSettings} />

      <SettingsModal
        open={showSettings}
        settings={settings}
        setSettings={setSettings}
        onApply={applyConfiguration}
        onClose={closeSettings}
        onDiscard={discardChanges}
      />
    </>
  );
}

export default App;
