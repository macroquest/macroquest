#!/usr/bin/env pwsh
# MacroQuest CMake Configuration Script
# This script is idempotent - safe to run multiple times
#
# Auto-detects architecture from MQ_EXPANSION_LEVEL in src/eqlib/include/eqlib/BuildType.h:
#   - EXPANSION_LEVEL_ROF (and other configured levels): builds Win32
#   - All other expansion levels: builds x64
#
# Performs:
# 1. Git submodule initialization
# 2. Architecture auto-detection from MQ_EXPANSION_LEVEL
# 3. Platform change detection (cleans build/solution if architecture changed)
# 4. CMake project generation for detected architecture
#
# Output structure:
#   build/solution/  - CMake-generated files (solution, projects, cache)
#   build/bin/       - Compiled binaries (debug/release)
#   build/lib/       - Import libraries
#
# To clean CMake files only: Remove-Item -Recurse build\solution
# This preserves your compiled binaries in build\bin\

param(
    [switch]$Verbose,        # Show detailed output
    [switch]$Clean,          # Clean the build directory only
    [switch]$SyncSubmodules, # Sync the submodules if they are already cloned
    [switch]$SkipVcpkg,      # Skip running vcpkg in cmake
    [switch]$SkipLauncher,   # Skip adding the launcher
    [switch]$SkipCustom,     # Skip adding custom plugins
    [switch]$SkipPlugins,    # Skip adding core plugins
    [switch]$BuildTest       # Add the test exes
)

$ErrorActionPreference = "Stop"

# ============================================================================
# Helper Functions
# ============================================================================

function Write-Step {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Cyan
}

function Write-ErrorMessage {
    param([string]$Message)
    Write-Host "ERROR: $Message" -ForegroundColor Red
}

function Write-Success {
    param([string]$Message)
    Write-Host $Message -ForegroundColor Green
}

function Write-VerboseLog {
    param([string]$Message)
    if ($Verbose) {
        Write-Host $Message -ForegroundColor DarkGray
    }
}

function Get-TargetArchitecture {
    Write-Step "Detecting target architecture..."

    $buildTypeFile = "src\eqlib\include\eqlib\BuildType.h"

    if (-not (Test-Path $buildTypeFile)) {
        Write-ErrorMessage "BuildType.h not found at $buildTypeFile"
        Write-Host "Defaulting to x64 architecture" -ForegroundColor Yellow
        return "x64"
    }

    # Define expansion levels that require Win32 architecture
    $win32ExpansionLevels = @(
        "EXPANSION_LEVEL_ROF"
    )

    # Read the file and look for #define MQ_EXPANSION_LEVEL
    $content = Get-Content $buildTypeFile -Raw

    # Match lines like "#define MQ_EXPANSION_LEVEL EXPANSION_LEVEL_XXX"
    if ($content -match '^\s*#define\s+MQ_EXPANSION_LEVEL\s+(\w+)' -or $content -match '\n\s*#define\s+MQ_EXPANSION_LEVEL\s+(\w+)') {
        $expansionLevel = $matches[1]

        if ($win32ExpansionLevels -contains $expansionLevel) {
            Write-Host "Detected expansion level: $expansionLevel -> Win32 architecture" -ForegroundColor Cyan
            return "Win32"
        }
        else {
            Write-Host "Detected expansion level: $expansionLevel -> x64 architecture" -ForegroundColor Cyan
            return "x64"
        }
    }
    else {
        Write-Host "Could not detect MQ_EXPANSION_LEVEL, defaulting to x64 architecture" -ForegroundColor Yellow
        return "x64"
    }
}

function Initialize-Submodules {
    Write-Step "Checking Git submodules..."

    # Check if submodules are already initialized
    $eqLibPath = "src\eqlib\.git"
    $vcpkgPath = "contrib\vcpkg\.git"

    if ((Test-Path $eqLibPath) -and (Test-Path $vcpkgPath)) {
        Write-Host "Submodules already initialized."
        if ($SyncSubmodules)
        {
            Write-Host "Syncing submodules to remote..."
            git submodule update --recursive
            if ($LASTEXITCODE -ne 0) {
                Write-ErrorMessage "Failed to sync submodules"
                exit 1
            }
        }
    }
    else {
        Write-Host "Initializing submodules..."
        git submodule update --init --recursive
        if ($LASTEXITCODE -ne 0) {
            Write-ErrorMessage "Failed to initialize submodules"
            exit 1
        }
    }

    Write-Host ""
}

function Get-PreviousPlatform {
    param([string]$BuildDir)

    $cacheFile = Join-Path $BuildDir "CMakeCache.txt"

    if (-not (Test-Path $cacheFile)) {
        return $null
    }

    # Read CMakeCache.txt and look for CMAKE_GENERATOR_PLATFORM
    $content = Get-Content $cacheFile -Raw

    if ($content -match 'CMAKE_GENERATOR_PLATFORM:INTERNAL=(.+)') {
        return $matches[1].Trim()
    }

    return $null
}

function Clear-BuildDirectory {
    param([string]$BuildDir)

    Write-Host "Cleaning build directory..." -ForegroundColor Yellow

    if (Test-Path $BuildDir) {
        Remove-Item -Recurse -Force $BuildDir -ErrorAction SilentlyContinue
        if ($LASTEXITCODE -ne 0) {
            Write-ErrorMessage "Failed to clean build directory"
            exit 1
        }
    }

    Write-Host "Build directory cleaned." -ForegroundColor Green
    Write-Host ""
}

function Test-PlatformChange {
    param(
        [string]$TargetArch,
        [string]$BuildDir
    )

    $previousArch = Get-PreviousPlatform -BuildDir $BuildDir

    if ($null -eq $previousArch) {
        Write-VerboseLog "No previous build detected."
        return $false
    }

    if ($previousArch -ne $TargetArch) {
        Write-Host ""
        Write-Host "========================================" -ForegroundColor Yellow
        Write-Host "Platform Change Detected!" -ForegroundColor Yellow
        Write-Host "========================================" -ForegroundColor Yellow
        Write-Host "  Previous: $previousArch" -ForegroundColor Cyan
        Write-Host "  New:      $TargetArch" -ForegroundColor Cyan
        Write-Host ""
        return $true
    }

    Write-VerboseLog "Platform unchanged: $TargetArch"
    return $false
}

function New-Platform {
    param(
        [string]$Arch,
        [string]$BuildDir
    )

    Write-Host ""
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host "Configuring for $Arch platform" -ForegroundColor Cyan
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host ""

    # Build cmake arguments from switches
    $cmakeArgs = @(
        "--fresh",
        "-B", $BuildDir,
        "-G", "Visual Studio 17 2022",
        "-A", $Arch
    )

    if ($SkipVcpkg) {
        $cmakeArgs += "-DMQ_BUILD_VCPKG=OFF"
    }

    if ($SkipLauncher) {
        $cmakeArgs += "-DMQ_BUILD_LAUNCHER=OFF"
    }

    if ($SkipCustom) {
        $cmakeArgs += "-DMQ_BUILD_CUSTOM_PLUGINS=OFF"
    }

    if ($SkipPlugins) {
        $cmakeArgs += "-DMQ_BUILD_PLUGINS=OFF"
    }

    if ($BuildTest) {
        $cmakeArgs += "-DMQ_BUILD_TESTS=ON"
    }

    & cmake @cmakeArgs

    if ($LASTEXITCODE -ne 0) {
        Write-Host ""
        Write-ErrorMessage "CMake configuration failed for $Arch!"
        exit 1
    }

    Write-VerboseLog "$Arch configuration completed: $BuildDir\MacroQuest.sln"
}


# ============================================================================
# Main Execution
# ============================================================================

Write-Host "==========================================" -ForegroundColor Yellow
Write-Host "MacroQuest CMake Configuration" -ForegroundColor Yellow
Write-Host "==========================================" -ForegroundColor Yellow
Write-Host ""

try {
    # Check prerequisites
    Write-Step "Checking prerequisites..."
    if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
        Write-ErrorMessage "Git is not installed or not in PATH"
        Write-Host "Please install Git from https://git-scm.com/"
        exit 1
    }
    if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
        Write-ErrorMessage "CMake is not installed or not in PATH"
        Write-Host "Please install CMake from https://cmake.org/"
        exit 1
    }
    Write-Host ""

    if ($Clean)
    {
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host "Cleaning Solution Build Directory" -ForegroundColor Cyan
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host ""
        Clear-BuildDirectory -BuildDir "build/solution"
    }
    else
    {

        # Initialize submodules
        Initialize-Submodules

        # Detect target architecture
        $targetArch = Get-TargetArchitecture
        Write-Host ""

        # Check for platform change and clean if necessary
        if (Test-PlatformChange -TargetArch $targetArch -BuildDir "build/solution")
        {
            Clear-BuildDirectory -BuildDir "build/solution"
        }

        # Generate project files
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host "Generating Visual Studio Projects" -ForegroundColor Cyan
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host ""

        New-Platform -Arch $targetArch -BuildDir "build/solution"

        Write-Host ""
        Write-Host "========================================" -ForegroundColor Green
        Write-Success "Configuration Complete!"
        Write-Host "========================================" -ForegroundColor Green
        Write-Host ""
        Write-Host "Generated solution:" -ForegroundColor Yellow
        Write-Host "  Architecture: $targetArch" -ForegroundColor Cyan
        Write-Host "  Solution: build\solution\MacroQuest.sln" -ForegroundColor Cyan
        Write-Host ""
        Write-Host "Build output:" -ForegroundColor Yellow
        Write-Host "  Binaries: build\bin\debug\ or build\bin\release\" -ForegroundColor Cyan
        Write-Host ""
        Write-Host "Next steps:" -ForegroundColor Yellow
        Write-Host "  1. Open solution in Visual Studio:" -ForegroundColor White
        Write-Host "     build\solution\MacroQuest.sln" -ForegroundColor Gray
        Write-Host "  2. Or build via command line (WIP):" -ForegroundColor White
        Write-Host "     cmake --build build\solution --config Release" -ForegroundColor Gray
        Write-Host ""
        Write-Host "To clean build directory:" -ForegroundColor Yellow
        Write-Host "  .\gen_solution.ps1 -Clean" -ForegroundColor Gray
        Write-Host ""
        Write-Host "Note: Architecture auto-detected from MQ_EXPANSION_LEVEL in BuildType.h" -ForegroundColor DarkGray
        Write-Host "      EXPANSION_LEVEL_ROF = Win32, other levels = x64" -ForegroundColor DarkGray
        Write-Host ""
    }
}
catch {
    Write-ErrorMessage $_.Exception.Message
    exit 1
}
