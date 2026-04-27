<#
.SYNOPSIS
    Installs and registers a GitHub Actions self-hosted runner on Windows for MacroQuest builds.
.DESCRIPTION
    Installs Visual Studio 2022 Build Tools, Git, and the GitHub Actions runner service.
    Run from an elevated PowerShell prompt.
#>
#Requires -RunAsAdministrator

$ErrorActionPreference = "Stop"

function Write-Step { param($msg) Write-Host "`n[+] $msg" -ForegroundColor Green }
function Write-Warn  { param($msg) Write-Host "[!] $msg" -ForegroundColor Yellow }

Write-Host "`n════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "  MacroQuest Build Runner — Windows Setup   " -ForegroundColor Cyan
Write-Host "════════════════════════════════════════════`n" -ForegroundColor Cyan

# ── Collect inputs ─────────────────────────────────────────────────────────
$repoUrl = Read-Host "GitHub repo URL [https://github.com/teichoui/macroquest]"
if (-not $repoUrl) { $repoUrl = "https://github.com/teichoui/macroquest" }

$runnerToken = Read-Host "Runner registration token (from GitHub → Settings → Actions → Runners → New runner)"
if (-not $runnerToken) { throw "Runner token is required" }

$runnerDir = "C:\actions-runner"
$runnerLabels = "self-hosted,Windows,X64,fast"

# ── Check / install winget ─────────────────────────────────────────────────
Write-Step "Checking winget..."
if (-not (Get-Command winget -ErrorAction SilentlyContinue)) {
    throw "winget not found. Install App Installer from the Microsoft Store, then re-run."
}

# ── Visual Studio 2022 Build Tools ────────────────────────────────────────
Write-Step "Installing Visual Studio 2022 Build Tools..."
$vsInstalled = Get-ItemProperty "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\*" |
    Where-Object { $_.DisplayName -like "*Visual Studio*2022*" } | Select-Object -First 1

if ($vsInstalled) {
    Write-Warn "Visual Studio 2022 already installed — skipping"
} else {
    winget install Microsoft.VisualStudio.2022.BuildTools --silent --accept-package-agreements --accept-source-agreements `
        --override "--wait --quiet --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add Microsoft.VisualStudio.Component.Windows11SDK.22621 --add Microsoft.VisualStudio.Component.VC.CMake.Project --add Microsoft.VisualStudio.Component.VC.ATL --add Microsoft.VisualStudio.ComponentGroup.NativeDesktop.Core"
    Write-Step "Visual Studio 2022 Build Tools installed"
}

# ── Git ────────────────────────────────────────────────────────────────────
Write-Step "Installing Git..."
if (Get-Command git -ErrorAction SilentlyContinue) {
    Write-Warn "Git already installed: $(git --version)"
} else {
    winget install Git.Git --silent --accept-package-agreements --accept-source-agreements
    $env:PATH += ";C:\Program Files\Git\cmd"
    Write-Step "Git installed"
}

# ── 7-Zip (for build archives) ─────────────────────────────────────────────
Write-Step "Installing 7-Zip..."
if (Get-Command 7z -ErrorAction SilentlyContinue) {
    Write-Warn "7-Zip already installed"
} else {
    winget install 7zip.7zip --silent --accept-package-agreements --accept-source-agreements
}

# ── GitHub Actions Runner ──────────────────────────────────────────────────
Write-Step "Setting up GitHub Actions runner in $runnerDir..."
New-Item -ItemType Directory -Force -Path $runnerDir | Out-Null

# Fetch latest runner version
$apiUrl = "https://api.github.com/repos/actions/runner/releases/latest"
$release = Invoke-RestMethod -Uri $apiUrl -Headers @{ "User-Agent" = "MQInstaller" }
$asset = $release.assets | Where-Object { $_.name -like "actions-runner-win-x64-*.zip" } | Select-Object -First 1
if (-not $asset) { throw "Could not find Windows runner asset in latest release" }

$zipPath = "$runnerDir\runner.zip"
Write-Host "  Downloading $($asset.name)..."
Invoke-WebRequest -Uri $asset.browser_download_url -OutFile $zipPath

Write-Host "  Extracting..."
Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::ExtractToDirectory($zipPath, $runnerDir)
Remove-Item $zipPath -Force

# ── Configure runner ───────────────────────────────────────────────────────
Write-Step "Configuring runner..."
Set-Location $runnerDir
.\config.cmd --url $repoUrl --token $runnerToken --labels $runnerLabels `
             --name "${env:COMPUTERNAME}-mq-runner" --runasservice --windowslogonaccount "NT AUTHORITY\NETWORK SERVICE" 2>&1

Write-Step "Starting runner service..."
.\svc.sh start 2>&1 | Out-Null

Write-Host "`n════════════════════════════════════════════" -ForegroundColor Green
Write-Host "[✓] Runner installation complete!" -ForegroundColor Green
Write-Host ""
Write-Host "  Runner dir:  $runnerDir"
Write-Host "  Repo:        $repoUrl"
Write-Host "  Labels:      $runnerLabels"
Write-Host ""
Write-Host "  The runner is now online in GitHub → Settings → Actions → Runners"
Write-Host "════════════════════════════════════════════" -ForegroundColor Green
