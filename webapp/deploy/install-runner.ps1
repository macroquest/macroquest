#Requires -Version 5.1
<#
.SYNOPSIS
    MacroQuest Admin Panel — GitHub Actions Self-Hosted Runner Setup (Windows)

.DESCRIPTION
    Installs prerequisites (Visual Studio Build Tools, Windows SDK, Git) via winget,
    downloads the latest GitHub Actions runner, and registers it as a Windows service.

.NOTES
    - Must be run as Administrator
    - Tested on Windows 10 22H2+ and Windows Server 2022
    - Run: PowerShell -ExecutionPolicy Bypass -File install-runner.ps1
#>

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# ── Helper functions ──────────────────────────────────────────────────────────

function Write-Step   { param([string]$msg) Write-Host "`n━━ $msg" -ForegroundColor Cyan }
function Write-Info   { param([string]$msg) Write-Host "  [INFO] $msg" -ForegroundColor Gray }
function Write-Ok     { param([string]$msg) Write-Host "  [ OK ] $msg" -ForegroundColor Green }
function Write-Warn   { param([string]$msg) Write-Host "  [WARN] $msg" -ForegroundColor Yellow }
function Write-Fail   { param([string]$msg) Write-Host " [FAIL] $msg" -ForegroundColor Red; throw $msg }

function Prompt-Input {
    param(
        [string]$Prompt,
        [string]$Default = ''
    )
    $suffix = if ($Default) { " [$Default]" } else { '' }
    $raw = Read-Host "  $Prompt$suffix"
    if ([string]::IsNullOrWhiteSpace($raw) -and $Default) { return $Default }
    return $raw.Trim()
}

function Prompt-Secret {
    param([string]$Prompt)
    $ss = Read-Host "  $Prompt" -AsSecureString
    $plain = [Runtime.InteropServices.Marshal]::PtrToStringAuto(
        [Runtime.InteropServices.Marshal]::SecureStringToBSTR($ss)
    )
    return $plain
}

function Test-WingetPackage {
    param([string]$PackageId)
    $result = winget list --id $PackageId --exact --accept-source-agreements 2>&1
    return ($result -match $PackageId)
}

function Install-WingetPackage {
    param(
        [string]$PackageId,
        [string]$DisplayName,
        [string[]]$ExtraArgs = @()
    )
    if (Test-WingetPackage -PackageId $PackageId) {
        Write-Ok "$DisplayName already installed"
        return
    }
    Write-Info "Installing $DisplayName via winget…"
    $args = @(
        'install', '--id', $PackageId,
        '--exact', '--silent', '--accept-package-agreements',
        '--accept-source-agreements'
    ) + $ExtraArgs
    $proc = Start-Process -FilePath 'winget' -ArgumentList $args `
                          -Wait -PassThru -NoNewWindow
    if ($proc.ExitCode -ne 0) {
        Write-Warn "winget exited with code $($proc.ExitCode) for $PackageId — may already be installed or require a reboot"
    } else {
        Write-Ok "$DisplayName installed"
    }
}

# ── 1. Administrator check ────────────────────────────────────────────────────
Write-Step "Pre-flight checks"

$currentPrincipal = [Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()
if (-not $currentPrincipal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)) {
    Write-Fail "This script must be run as Administrator. Right-click PowerShell → 'Run as administrator'."
}
Write-Ok "Running as Administrator"

# Check winget is available
if (-not (Get-Command winget -ErrorAction SilentlyContinue)) {
    Write-Fail "winget is not available. Install 'App Installer' from the Microsoft Store, or update Windows."
}
Write-Ok "winget found: $(winget --version)"

# ── 2. Install Visual Studio Build Tools ──────────────────────────────────────
Write-Step "Installing Visual Studio 2022 Build Tools"
Write-Info "This may take 10-20 minutes on first install…"

Install-WingetPackage `
    -PackageId 'Microsoft.VisualStudio.2022.BuildTools' `
    -DisplayName 'VS2022 Build Tools' `
    -ExtraArgs @(
        '--override',
        '--quiet --wait --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows11SDK.22621 --add Microsoft.VisualStudio.Component.VC.CMake.Project --add Microsoft.VisualStudio.Component.TestTools.BuildTools'
    )

# ── 3. Install Git ────────────────────────────────────────────────────────────
Write-Step "Installing Git for Windows"
Install-WingetPackage -PackageId 'Git.Git' -DisplayName 'Git for Windows'

# Refresh PATH for this session so git is available immediately
$env:PATH = [System.Environment]::GetEnvironmentVariable('PATH', 'Machine') + ';' +
            [System.Environment]::GetEnvironmentVariable('PATH', 'User')

if (Get-Command git -ErrorAction SilentlyContinue) {
    Write-Ok "Git: $(git --version)"
} else {
    Write-Warn "git not found in PATH after install — a reboot may be required. Continuing…"
}

# ── 4. Prompt for runner configuration ───────────────────────────────────────
Write-Step "Runner Configuration"

Write-Host @"

  To get a registration token:
    1. Go to your GitHub repository
    2. Settings > Actions > Runners > New self-hosted runner
    3. Select: Linux... no, select WINDOWS, x64
    4. Copy the token shown in the 'Configure' step (starts with 'A...', valid for 1 hour)

"@ -ForegroundColor DarkCyan

$RepoUrl = Prompt-Input `
    -Prompt "GitHub repository URL" `
    -Default "https://github.com/teichoui/macroquest"

if ([string]::IsNullOrWhiteSpace($RepoUrl)) {
    Write-Fail "Repository URL is required."
}

$RegistrationToken = Prompt-Secret -Prompt "Runner registration token (from GitHub Settings > Actions > Runners)"
if ([string]::IsNullOrWhiteSpace($RegistrationToken)) {
    Write-Fail "Registration token is required."
}

$RunnerName = Prompt-Input `
    -Prompt "Runner name" `
    -Default "$env:COMPUTERNAME-fast"

$RunnerLabels = Prompt-Input `
    -Prompt "Runner labels (comma-separated)" `
    -Default "self-hosted,Windows,X64,fast,mq-build"

# ── 5. Create runner directory ────────────────────────────────────────────────
Write-Step "Creating runner directory"

$RunnerDir = "C:\actions-runner"
if (Test-Path $RunnerDir) {
    Write-Warn "Directory $RunnerDir already exists."
    $overwrite = Prompt-Input -Prompt "Overwrite existing runner? (y/N)" -Default "N"
    if ($overwrite -notmatch '^[Yy]$') {
        Write-Info "Aborting — existing runner preserved."
        exit 0
    }
    Write-Info "Removing existing runner directory…"
    # Unregister existing service if present
    $existingService = Get-Service -Name 'actions.runner.*' -ErrorAction SilentlyContinue
    if ($existingService) {
        Write-Info "Stopping existing runner service: $($existingService.Name)"
        Stop-Service -Name $existingService.Name -Force -ErrorAction SilentlyContinue
        & "$RunnerDir\svc.cmd" uninstall 2>&1 | Out-Null
    }
    Remove-Item -Recurse -Force $RunnerDir
}
New-Item -ItemType Directory -Path $RunnerDir -Force | Out-Null
Write-Ok "Runner directory created: $RunnerDir"

# ── 6. Download latest GitHub Actions runner ──────────────────────────────────
Write-Step "Downloading GitHub Actions runner"

$ApiUrl = "https://api.github.com/repos/actions/runner/releases/latest"
Write-Info "Querying GitHub API: $ApiUrl"

try {
    $Release = Invoke-RestMethod -Uri $ApiUrl -Headers @{
        'Accept'     = 'application/vnd.github+json'
        'User-Agent' = 'mq-install-runner/1.0'
    }
} catch {
    Write-Fail "Failed to query GitHub API: $_"
}

$RunnerVersion = $Release.tag_name.TrimStart('v')
Write-Info "Latest runner version: $RunnerVersion"

# Find Windows x64 asset
$Asset = $Release.assets | Where-Object {
    $_.name -match 'win-x64' -and $_.name -match '\.zip$'
} | Select-Object -First 1

if (-not $Asset) {
    Write-Fail "Could not find Windows x64 runner asset in release $RunnerVersion"
}

$ZipPath = Join-Path $RunnerDir "actions-runner-win-x64-$RunnerVersion.zip"
Write-Info "Downloading: $($Asset.browser_download_url)"
Write-Info "Saving to:   $ZipPath"

$ProgressPreference = 'SilentlyContinue'
try {
    Invoke-WebRequest -Uri $Asset.browser_download_url `
                      -OutFile $ZipPath `
                      -UseBasicParsing
} catch {
    Write-Fail "Download failed: $_"
}
$ProgressPreference = 'Continue'
Write-Ok "Downloaded runner $RunnerVersion"

# ── 7. Extract runner zip ─────────────────────────────────────────────────────
Write-Step "Extracting runner archive"
Write-Info "Extracting to $RunnerDir…"
Expand-Archive -Path $ZipPath -DestinationPath $RunnerDir -Force
Remove-Item -Path $ZipPath -Force
Write-Ok "Extraction complete"

# ── 8. Configure runner ───────────────────────────────────────────────────────
Write-Step "Configuring runner"

$ConfigScript = Join-Path $RunnerDir "config.cmd"
if (-not (Test-Path $ConfigScript)) {
    Write-Fail "config.cmd not found at $ConfigScript — extraction may have failed."
}

Write-Info "Registering runner with GitHub…"
Write-Info "  URL:    $RepoUrl"
Write-Info "  Name:   $RunnerName"
Write-Info "  Labels: $RunnerLabels"

$ConfigArgs = @(
    "--url", $RepoUrl,
    "--token", $RegistrationToken,
    "--name", $RunnerName,
    "--labels", $RunnerLabels,
    "--work", "_work",
    "--runasservice",
    "--windowslogonaccount", "NT AUTHORITY\NetworkService",
    "--unattended"
)

Push-Location $RunnerDir
try {
    $configProc = Start-Process -FilePath $ConfigScript `
                                -ArgumentList $ConfigArgs `
                                -Wait -PassThru -NoNewWindow
    if ($configProc.ExitCode -ne 0) {
        Write-Fail "Runner configuration failed with exit code $($configProc.ExitCode). Token may be expired."
    }
    Write-Ok "Runner configured successfully"
} finally {
    Pop-Location
}

# ── 9. Install and start the runner service ────────────────────────────────────
Write-Step "Installing Windows service"

$SvcScript = Join-Path $RunnerDir "svc.cmd"
if (-not (Test-Path $SvcScript)) {
    Write-Fail "svc.cmd not found — runner may not have configured correctly."
}

Push-Location $RunnerDir
try {
    Write-Info "Installing service…"
    & cmd.exe /c $SvcScript install 2>&1 | ForEach-Object { Write-Info $_ }

    Write-Info "Starting service…"
    & cmd.exe /c $SvcScript start 2>&1 | ForEach-Object { Write-Info $_ }
} finally {
    Pop-Location
}

# Verify service is running
Start-Sleep -Seconds 3
$RunnerService = Get-Service -Name 'actions.runner.*' -ErrorAction SilentlyContinue
if ($RunnerService -and $RunnerService.Status -eq 'Running') {
    Write-Ok "Runner service is running: $($RunnerService.Name)"
} else {
    Write-Warn "Service may not be running. Check: Get-Service 'actions.runner.*'"
    Write-Warn "Logs: $RunnerDir\_diag\"
}

# ── 10. Configure Windows environment for builds ──────────────────────────────
Write-Step "Configuring build environment"

# Ensure long path support is enabled
$regPath = 'HKLM:\SYSTEM\CurrentControlSet\Control\FileSystem'
$current = Get-ItemPropertyValue -Path $regPath -Name 'LongPathsEnabled' -ErrorAction SilentlyContinue
if ($current -ne 1) {
    Set-ItemProperty -Path $regPath -Name 'LongPathsEnabled' -Value 1 -Type DWord
    Write-Ok "Long path support enabled (HKLM\\...\\LongPathsEnabled = 1)"
} else {
    Write-Ok "Long path support already enabled"
}

# Set VSCMD_SKIP_SENDTELEMETRY to suppress VS telemetry prompts in CI
[System.Environment]::SetEnvironmentVariable('VSCMD_SKIP_SENDTELEMETRY', '1', 'Machine')
Write-Ok "VS telemetry suppressed for CI builds"

# ── 11. Success ───────────────────────────────────────────────────────────────
Write-Host ""
Write-Host "╔══════════════════════════════════════════════════════════╗" -ForegroundColor Green
Write-Host "║  GitHub Actions runner installed and running!            ║" -ForegroundColor Green
Write-Host "╚══════════════════════════════════════════════════════════╝" -ForegroundColor Green
Write-Host ""
Write-Host "  Runner name:   $RunnerName" -ForegroundColor White
Write-Host "  Labels:        $RunnerLabels" -ForegroundColor White
Write-Host "  Runner dir:    $RunnerDir" -ForegroundColor White
Write-Host "  Service:       $(if ($RunnerService) { $RunnerService.Name } else { 'actions.runner.*' })" -ForegroundColor White
Write-Host ""
Write-Host "  Verify on GitHub: $RepoUrl/settings/actions/runners" -ForegroundColor Cyan
Write-Host ""
Write-Host "  Useful commands:" -ForegroundColor DarkCyan
Write-Host "    Get-Service 'actions.runner.*'              # check status" -ForegroundColor Gray
Write-Host "    Stop-Service 'actions.runner.*'             # stop runner" -ForegroundColor Gray
Write-Host "    Start-Service 'actions.runner.*'            # start runner" -ForegroundColor Gray
Write-Host "    Get-Content $RunnerDir\_diag\*.log -Tail 50 # view logs" -ForegroundColor Gray
Write-Host ""
Write-Host "  NOTE: A system reboot may be required for VS Build Tools to be" -ForegroundColor Yellow
Write-Host "  fully available on PATH during builds." -ForegroundColor Yellow
Write-Host ""
