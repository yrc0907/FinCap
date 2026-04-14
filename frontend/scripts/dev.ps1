$ErrorActionPreference = "Stop"

$frontendPath = Split-Path -Parent $PSScriptRoot
$repoRoot = Split-Path -Parent $frontendPath
$backendPath = Join-Path $repoRoot "backend"
$venvPath = Join-Path $backendPath ".venv"
$venvPython = Join-Path $venvPath "Scripts\\python.exe"
$requirementsPath = Join-Path $backendPath "requirements.txt"
$requirementsHashPath = Join-Path $venvPath ".requirements.sha256"
$buildRequirementsPath = Join-Path $backendPath "requirements-build.txt"
$buildRequirementsHashPath = Join-Path $venvPath ".requirements-build.sha256"
$needsInstall = $false

if (-not (Test-Path $venvPython)) {
  Write-Host "Creating backend virtual environment..."
  python -m venv $venvPath
  $needsInstall = $true
}

$requirementsHash = (Get-FileHash -Path $requirementsPath -Algorithm SHA256).Hash

if (-not (Test-Path $requirementsHashPath)) {
  $needsInstall = $true
} else {
  $storedHash = (Get-Content -Path $requirementsHashPath -Raw).Trim()
  if ($storedHash -ne $requirementsHash) {
    $needsInstall = $true
  }
}

if ($needsInstall) {
  Write-Host "Installing backend dependencies..."
  & $venvPython -m pip install -r $requirementsPath | Out-Host
  Set-Content -Path $requirementsHashPath -Value $requirementsHash -NoNewline
} else {
  Write-Host "Backend dependencies unchanged. Skipping install."
}

$hostLine = (rustc -vV | Select-String "^host: ").Line
$hostTarget = $hostLine.Replace("host: ", "").Trim()
$sidecarBinary = Join-Path $frontendPath "src-tauri\\binaries\\fincap-backend-$hostTarget.exe"

if (-not (Test-Path $sidecarBinary)) {
  $buildRequirementsHash = (Get-FileHash -Path $buildRequirementsPath -Algorithm SHA256).Hash
  $needsBuildInstall = $false

  if (-not (Test-Path $buildRequirementsHashPath)) {
    $needsBuildInstall = $true
  } else {
    $storedBuildHash = (Get-Content -Path $buildRequirementsHashPath -Raw).Trim()
    if ($storedBuildHash -ne $buildRequirementsHash) {
      $needsBuildInstall = $true
    }
  }

  if ($needsBuildInstall) {
    Write-Host "Installing backend build dependencies..."
    & $venvPython -m pip install -r $buildRequirementsPath | Out-Host
    Set-Content -Path $buildRequirementsHashPath -Value $buildRequirementsHash -NoNewline
  }

  Write-Host "Preparing desktop backend sidecar..."
  & $venvPython (Join-Path $backendPath "build_sidecar.py") | Out-Host
}

$backendProcess = $null
$startedBackend = $false

try {
  $frontendListening = Get-NetTCPConnection -LocalPort 1420 -State Listen -ErrorAction SilentlyContinue
  if ($frontendListening) {
    throw "Port 1420 is already in use by process $($frontendListening[0].OwningProcess). Close the existing frontend dev process and try again."
  }

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
