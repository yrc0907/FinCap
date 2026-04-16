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
$devBackendPort = 8877
$devBackendUrl = "http://127.0.0.1:$devBackendPort"
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

$hostTarget = (& $venvPython (Join-Path $backendPath "host_target.py")).Trim()
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
$previousBackendPort = $env:FINCAP_BACKEND_PORT
$previousBackendUrl = $env:VITE_TTS_BACKEND_URL

try {
  $frontendListening = Get-NetTCPConnection -LocalPort 1420 -State Listen -ErrorAction SilentlyContinue
  if ($frontendListening) {
    throw "Port 1420 is already in use by process $($frontendListening[0].OwningProcess). Close the existing frontend dev process and try again."
  }

  $backendListening = Get-NetTCPConnection -LocalPort $devBackendPort -State Listen -ErrorAction SilentlyContinue

  if (-not $backendListening) {
    Write-Host "Starting backend on $devBackendUrl ..."
    $env:FINCAP_BACKEND_PORT = "$devBackendPort"
    $backendProcess = Start-Process -FilePath $venvPython -ArgumentList "run.py" -WorkingDirectory $backendPath -PassThru
    $startedBackend = $true
    Start-Sleep -Seconds 2
  }

  $env:VITE_TTS_BACKEND_URL = $devBackendUrl
  pnpm run dev:vite
} finally {
  if ($null -eq $previousBackendPort) {
    Remove-Item Env:FINCAP_BACKEND_PORT -ErrorAction SilentlyContinue
  } else {
    $env:FINCAP_BACKEND_PORT = $previousBackendPort
  }

  if ($null -eq $previousBackendUrl) {
    Remove-Item Env:VITE_TTS_BACKEND_URL -ErrorAction SilentlyContinue
  } else {
    $env:VITE_TTS_BACKEND_URL = $previousBackendUrl
  }

  if ($startedBackend -and $backendProcess -and -not $backendProcess.HasExited) {
    Stop-Process -Id $backendProcess.Id
  }
}
