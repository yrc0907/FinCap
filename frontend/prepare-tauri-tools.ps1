param(
  [string]$MirrorTemplate,
  [switch]$PersistUser
)

$envVarName = "TAURI_BUNDLER_TOOLS_GITHUB_MIRROR_TEMPLATE"
$tauriCacheDir = Join-Path $env:LOCALAPPDATA "tauri"

Write-Host "Tauri bundler tools are versioned by the installed Tauri CLI/bundler."
Write-Host "This script does not download WiX/NSIS manually anymore."
Write-Host "It only configures the official mirror environment variable."
Write-Host ""

if ([string]::IsNullOrWhiteSpace($MirrorTemplate)) {
  Write-Host "No mirror template was provided."
  Write-Host "Tauri will keep downloading from GitHub directly unless you set $envVarName."
  Write-Host ""
  Write-Host "Current cache directory:"
  Write-Host "  $tauriCacheDir"
  Write-Host ""
  Write-Host "Example:"
  Write-Host "  .\prepare-tauri-tools.ps1 -MirrorTemplate 'https://your-mirror.example/<owner>/<repo>/releases/download/<version>/<asset>'"
  Write-Host "  .\prepare-tauri-tools.ps1 -MirrorTemplate 'https://your-mirror.example/<owner>/<repo>/releases/download/<version>/<asset>' -PersistUser"
  exit 0
}

$env:$envVarName = $MirrorTemplate
Write-Host "Set $envVarName for this PowerShell session."
Write-Host "Value:"
Write-Host "  $MirrorTemplate"

if ($PersistUser) {
  [Environment]::SetEnvironmentVariable($envVarName, $MirrorTemplate, "User")
  Write-Host "Persisted $envVarName to user environment variables."
} else {
  Write-Host "This setting is temporary for the current shell only."
  Write-Host "Add -PersistUser if you want it to survive new terminals."
}

Write-Host ""
Write-Host "Next step:"
Write-Host "  pnpm tauri build"
