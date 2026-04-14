$ErrorActionPreference = "Stop"

$frontendPath = Split-Path -Parent $PSScriptRoot
$repoRoot = Split-Path -Parent $frontendPath
$backendPath = Join-Path $repoRoot "backend"
$venvPath = Join-Path $backendPath ".venv"
$venvPython = Join-Path $venvPath "Scripts\\python.exe"

function Sync-Requirements {
  param(
    [string]$PythonPath,
    [string]$RequirementsPath,
    [string]$HashFilePath
  )

  $requirementsHash = (Get-FileHash -Path $RequirementsPath -Algorithm SHA256).Hash
  $needsInstall = $false

  if (-not (Test-Path $HashFilePath)) {
    $needsInstall = $true
  } else {
    $storedHash = (Get-Content -Path $HashFilePath -Raw).Trim()
    if ($storedHash -ne $requirementsHash) {
      $needsInstall = $true
    }
  }

  if ($needsInstall) {
    & $PythonPath -m pip install -r $RequirementsPath | Out-Host
    Set-Content -Path $HashFilePath -Value $requirementsHash -NoNewline
  }
}

if (-not (Test-Path $venvPython)) {
  python -m venv $venvPath
}

Get-Process -ErrorAction SilentlyContinue |
  Where-Object { $_.ProcessName -like "fincap-backend*" } |
  Stop-Process -Force

Sync-Requirements -PythonPath $venvPython -RequirementsPath (Join-Path $backendPath "requirements.txt") -HashFilePath (Join-Path $venvPath ".requirements.sha256")
Sync-Requirements -PythonPath $venvPython -RequirementsPath (Join-Path $backendPath "requirements-build.txt") -HashFilePath (Join-Path $venvPath ".requirements-build.sha256")

& $venvPython (Join-Path $backendPath "build_sidecar.py") | Out-Host
pnpm run build:web
