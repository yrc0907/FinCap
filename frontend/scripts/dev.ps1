$ErrorActionPreference = "Stop"

$frontendPath = Split-Path -Parent $PSScriptRoot
$repoRoot = Split-Path -Parent $frontendPath
$backendPath = Join-Path $repoRoot "backend"
$venvPath = Join-Path $backendPath ".venv"
$venvPython = Join-Path $venvPath "Scripts\\python.exe"
$requirementsPath = Join-Path $backendPath "requirements.txt"

if (-not (Test-Path $venvPython)) {
  Write-Host "Creating backend virtual environment..."
  python -m venv $venvPath
}

Write-Host "Installing backend dependencies..."
& $venvPython -m pip install -r $requirementsPath | Out-Host

$backendProcess = $null
$startedBackend = $false

try {
  $backendListening = Get-NetTCPConnection -LocalPort 8765 -State Listen -ErrorAction SilentlyContinue

  if (-not $backendListening) {
    Write-Host "Starting backend on http://127.0.0.1:8765 ..."
    $backendProcess = Start-Process -FilePath $venvPython -ArgumentList "run.py" -WorkingDirectory $backendPath -PassThru
    $startedBackend = $true
    Start-Sleep -Seconds 2
  }

  pnpm run dev:vite
} finally {
  if ($startedBackend -and $backendProcess -and -not $backendProcess.HasExited) {
    Stop-Process -Id $backendProcess.Id
  }
}
