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
# 3. Platform change detection (cleans cmake generated files if architecture changed)
# 4. CMake project generation for detected architecture
# 5. Clean and move the solution file for user consumption
#
# Output structure:
#   build/solution/      - CMake-generated files (solution, projects, cache)
#   build/MacroQuest.sln - Cleaned and moved solution file
#   build/bin/           - Compiled binaries (debug/release) (not implemented in cmake yet)
#   build/lib/           - Import libraries (not implemented in cmake yet)
#
# To clean CMake files only: Remove-Item -Recurse build\solution
# This preserves your compiled binaries in build\bin\

param(
    [switch]$Help,                 # Display help information
    [switch]$Verbose,              # Show detailed output
    [switch]$Clean,                # Clean the build directory only
    [switch]$SyncSubmodules,       # Sync the submodules if they are already cloned
    [switch]$SkipVcpkg,            # Skip running vcpkg in cmake
    [switch]$SkipLauncher,         # Skip adding the launcher
    [switch]$SkipCustom,           # Skip adding custom plugins
    [switch]$SkipPlugins,          # Skip adding core plugins
    [switch]$BuildTest,            # Add the test exes
    [switch]$AddMQ2MainDependency, # Add MQ2Main dependency to custom plugins if not present
    [string]$CustomPluginsFile,    # Path to custom plugins CMake file (overrides auto-detection)
    [string]$WritePluginsFile,     # Path to write auto-detected plugins as CMake file
    [string]$OutputDir = "build",
    [string]$SolutionName = "MacroQuest.sln"
)

$BuildDir = Join-Path $OutputDir "solution"
$SolutionPath = Join-Path $OutputDir $SolutionName

# ============================================================================
# Help Display
# ============================================================================

if ($Help) {
    Write-Host ""
    Write-Host "MacroQuest CMake Configuration Script" -ForegroundColor Cyan
    Write-Host "=====================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "DESCRIPTION:" -ForegroundColor Yellow
    Write-Host "  This script automates the CMake configuration process for MacroQuest."
    Write-Host "  It performs the following operations:"
    Write-Host "    1. Initializes/updates Git submodules (eqlib, vcpkg)"
    Write-Host "    2. Auto-detects target architecture from MQ_EXPANSION_LEVEL in BuildType.h"
    Write-Host "    3. Detects platform changes and cleans build directory if needed"
    Write-Host "    4. Runs CMake to generate Visual Studio 2022 project files"
    Write-Host "    5. Creates a cleaned solution file for user consumption"
    Write-Host ""
    Write-Host "ARCHITECTURE DETECTION:" -ForegroundColor Yellow
    Write-Host "  - EXPANSION_LEVEL_ROF → Win32 (32-bit)"
    Write-Host "  - All other expansion levels → x64 (64-bit)"
    Write-Host "  File: src\eqlib\include\eqlib\BuildType.h"
    Write-Host ""
    Write-Host "OUTPUT STRUCTURE:" -ForegroundColor Yellow
    Write-Host "  $BuildDir\ - CMake cache and generated project files"
    Write-Host "  $SolutionPath - Cleaned solution for Visual Studio (recommended)"
    Write-Host "  build\bin\ - Compiled binaries (after building - not implemented yet)"
    Write-Host "  build\lib\ - Import libraries (after building - not implemented yet)"
    Write-Host ""
    Write-Host "PARAMETERS:" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "  -Help" -ForegroundColor Cyan
    Write-Host "    Display this help information and exit."
    Write-Host ""
    Write-Host "  -Verbose" -ForegroundColor Cyan
    Write-Host "    Show detailed output during configuration, including:"
    Write-Host "      - Line numbers of removed projects in solution file"
    Write-Host "      - Detailed CMake configuration messages"
    Write-Host ""
    Write-Host "  -Clean" -ForegroundColor Cyan
    Write-Host "    Remove the CMake build directory and generated solution file."
    Write-Host "    This preserves compiled binaries in build\bin\ but removes all"
    Write-Host "    CMake-generated files, forcing a fresh configuration on next run."
    Write-Host ""
    Write-Host "  -SyncSubmodules" -ForegroundColor Cyan
    Write-Host "    Update submodules to match the remote repository commits."
    Write-Host "    Only applies if submodules are already initialized."
    Write-Host "    Runs: git submodule update --recursive"
    Write-Host ""
    Write-Host "  -SkipVcpkg" -ForegroundColor Cyan
    Write-Host "    Skip vcpkg package management during CMake configuration."
    Write-Host "    Sets: -DMQ_BUILD_VCPKG=OFF"
    Write-Host "    Use only if vcpkg dependencies are already installed."
    Write-Host ""
    Write-Host "  -SkipLauncher" -ForegroundColor Cyan
    Write-Host "    Don't build the MacroQuest.exe launcher application."
    Write-Host "    Sets: -DMQ_BUILD_LAUNCHER=OFF"
    Write-Host ""
    Write-Host "  -SkipCustom" -ForegroundColor Cyan
    Write-Host "    Don't build custom user plugins from the plugins/ directory."
    Write-Host "    Sets: -DMQ_BUILD_CUSTOM_PLUGINS=OFF"
    Write-Host ""
    Write-Host "  -SkipPlugins" -ForegroundColor Cyan
    Write-Host "    Don't build core MacroQuest plugins (chat, lua, map, etc.)."
    Write-Host "    Sets: -DMQ_BUILD_PLUGINS=OFF"
    Write-Host ""
    Write-Host "  -BuildTest" -ForegroundColor Cyan
    Write-Host "    Include test projects in the generated solution."
    Write-Host "    Sets: -DMQ_BUILD_TESTS=ON"
    Write-Host ""
    Write-Host "  -AddMQ2MainDependency" -ForegroundColor Cyan
    Write-Host "    Automatically add MQ2Main as a dependency to custom plugin vcxproj files"
    Write-Host "    if it is not already present. This modifies the .vcxproj files directly."
    Write-Host "    Sets: -DMQ_ADD_MQ2MAIN_DEPENDENCY=ON"
    Write-Host "    Default: OFF (vcxproj files are not modified)"
    Write-Host ""
    Write-Host "  -CustomPluginsFile <path>" -ForegroundColor Cyan
    Write-Host "    Path to a custom CMake file that defines which plugins to include."
    Write-Host "    When specified, this overrides auto-detection of plugins in plugins/."
    Write-Host "    The file should contain add_subdirectory() or add_custom_vcxproj() calls."
    Write-Host "    Sets: -DMQ_CUSTOM_PLUGINS_FILE=<path>"
    Write-Host ""
    Write-Host "  -WritePluginsFile <path>" -ForegroundColor Cyan
    Write-Host "    Path to write auto-detected plugins as a CMake file."
    Write-Host "    Generates a plugin configuration file from the current scan that can"
    Write-Host "    be used later with -CustomPluginsFile."
    Write-Host "    Sets: -DMQ_WRITE_PLUGINS_FILE=<path>"
    Write-Host ""
    Write-Host "  -OutputDir <path>" -ForegroundColor Cyan
    Write-Host "    Specify the output directory for build artifacts."
    Write-Host "    Default: 'build'"
    Write-Host ""
    Write-Host "  -SolutionName <name>" -ForegroundColor Cyan
    Write-Host "    Specify the name of the cleaned solution file."
    Write-Host "    Default: 'MacroQuest.sln'"
    Write-Host ""
    Write-Host "EXAMPLES:" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "  Basic configuration (first time setup):" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1"
    Write-Host ""
    Write-Host "  Reconfigure after pulling changes:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1"
    Write-Host ""
    Write-Host "  Update submodules and reconfigure:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -SyncSubmodules"
    Write-Host ""
    Write-Host "  Clean build directory:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -Clean"
    Write-Host ""
    Write-Host "  Configure with verbose output:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -Verbose"
    Write-Host ""
    Write-Host "  Configure without custom plugins:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -SkipCustom"
    Write-Host ""
    Write-Host "  Configure with tests enabled:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -BuildTest"
    Write-Host ""
    Write-Host "  Add MQ2Main dependency to custom plugins:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -AddMQ2MainDependency"
    Write-Host ""
    Write-Host "  Generate plugin configuration file:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -WritePluginsFile my_plugins.cmake"
    Write-Host ""
    Write-Host "  Use custom plugin configuration:" -ForegroundColor Cyan
    Write-Host "    .\gen_solution.ps1 -CustomPluginsFile my_plugins.cmake"
    Write-Host ""
    Write-Host "NOTES:" -ForegroundColor Yellow
    Write-Host "  - This script is idempotent (safe to run multiple times)"
    Write-Host "  - Platform changes (Win32 <-> x64) automatically trigger a clean rebuild"
    Write-Host "  - The cleaned solution file removes ALL_BUILD and CMakePredefinedTargets"
    Write-Host "  - Requires: Git, CMake, Visual Studio 2022"
    Write-Host ""
    exit 0
}

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
    if (Test-Path $buildTypeFile) {
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
                "Win32"
            }
            else {
                Write-Host "Detected expansion level: $expansionLevel -> x64 architecture" -ForegroundColor Cyan
                "x64"
            }
        }
        else {
            Write-Host "Could not detect MQ_EXPANSION_LEVEL, defaulting to x64 architecture" -ForegroundColor Yellow
            "x64"
        }
    }
    else {
        Write-ErrorMessage "BuildType.h not found at $buildTypeFile"
        Write-Host "Defaulting to x64 architecture" -ForegroundColor Yellow
        "x64"
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
    $cacheFile = Join-Path $BuildDir "CMakeCache.txt"

    if (Test-Path $cacheFile) {
        # Read CMakeCache.txt and look for CMAKE_GENERATOR_PLATFORM
        $content = Get-Content $cacheFile -Raw

        if ($content -match 'CMAKE_GENERATOR_PLATFORM:INTERNAL=(.+)') {
            $matches[1].Trim()
        }
        else {
            $null
        }
    }
    else {
        $null
    }
}

function Clear-BuildDirectory {
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host "Cleaning Solution Build Directory" -ForegroundColor Cyan
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host ""

    if (Test-Path $BuildDir) {
        Remove-Item -Recurse -Force $BuildDir -ErrorAction SilentlyContinue
        if ($LASTEXITCODE -ne 0) {
            Write-ErrorMessage "Failed to clean build directory"
        }
    }

    if (Test-Path $SolutionPath) {
        Remove-Item $SolutionPath -ErrorAction SilentlyContinue
        if ($LASTEXITCODE -ne 0) {
            Write-ErrorMessage "Failed to remove solution file"
        }
    }

    Write-Host "Build directory and final output cleaned." -ForegroundColor Green
    Write-Host ""
}

function Test-PlatformChange {
    param(
        [string]$TargetArch
    )

    $previousArch = Get-PreviousPlatform

    if ($null -ne $previousArch) {
        if ($previousArch -ne $TargetArch) {
            Write-Host ""
            Write-Host "========================================" -ForegroundColor Yellow
            Write-Host "Platform Change Detected!" -ForegroundColor Yellow
            Write-Host "========================================" -ForegroundColor Yellow
            Write-Host "  Previous: $previousArch" -ForegroundColor Cyan
            Write-Host "  New:      $TargetArch" -ForegroundColor Cyan
            Write-Host ""
            $true
        }
        else {
            Write-VerboseLog "Platform unchanged: $TargetArch"
            $false
        }
    }
    else {
        Write-VerboseLog "No previous build detected."
        $false
    }
}

function Copy-CleanedSolution {
    param(
        [string]$SourceSln,
        [string]$DestSln
    )

    function Find-ProjectBlock
    {
        param($Lines, $ProjectPattern)

        # Find the start line: returns object with Index and Guid
        $startLine = 0..($Lines.Count - 1) | Where-Object {
            $Lines[$_] -match $ProjectPattern
        } | Select-Object -First 1 | ForEach-Object {
            @{
                Index = $_
                Guid = $matches[1]
            }
        }

        if ($startLine) {
            @{
                Guid = $startLine.Guid
                StartIndex = $startLine.Index
                EndIndex = ($startLine.Index + 1)..($Lines.Count - 1) | Where-Object {
                    $Lines[$_] -match '^\s*EndProject\s*$'
                } | Select-Object -First 1
            }
        } else {
            $null
        }
    }

    # Pure predicate: should we keep this line?
    function Test-ShouldKeepLine
    {
        param($Index, $Line, $ExcludedBlocks, $ExcludedGuids)

        # Check if index falls within any excluded block
        $inExcludedBlock = $ExcludedBlocks | Where-Object {
            $Index -ge $_.StartIndex -and $Index -le $_.EndIndex
        } | Select-Object -First 1

        if (-not ($inExcludedBlock)) {
            # Check if line contains any excluded GUID
            $containsExcludedGuid = $ExcludedGuids | Where-Object {
                $Line -match "\{$_\}"
            } | Select-Object -First 1

            if ($containsExcludedGuid) {
                Write-VerboseLog "Detected nested reference at line $Index"
            }
        }
        else {
            Write-VerboseLog "Detected direct reference at line $Index"
        }

        -not ($inExcludedBlock -or $containsExcludedGuid)
    }

    Write-Step "Copying and cleaning solution file..."

    if (Test-Path $SourceSln)
    {
        $lines = Get-Content $SourceSln

        # Build immutable exclusion data
        $allBuildBlock = Find-ProjectBlock -Lines $lines -ProjectPattern 'Project\(".*"\)\s*=\s*"ALL_BUILD".*\{([0-9A-F-]+)\}'
        $zeroCheckBlock = Find-ProjectBlock -Lines $lines -ProjectPattern 'Project\(".*"\)\s*=\s*"ZERO_CHECK".*\{([0-9A-F-]+)\}'
        $predefinedBlock = Find-ProjectBlock -Lines $lines -ProjectPattern 'Project\(".*"\)\s*=\s*"CMakePredefinedTargets".*\{([0-9A-F-]+)\}'

        if ($allBuildBlock) {
            Write-VerboseLog "Found ALL_BUILD project GUID: $( $allBuildBlock.Guid )"
            Write-VerboseLog "Removing ALL_BUILD project (lines $( $allBuildBlock.StartIndex )-$( $allBuildBlock.EndIndex ))"
        }

        if ($zeroCheckBlock) {
            Write-VerboseLog "Found ZERO_CHECK project GUID: $( $zeroCheckBlock.Guid )"
            Write-VerboseLog "Removing ZERO_CHECK project (lines $( $zeroCheckBlock.StartIndex )-$( $zeroCheckBlock.EndIndex ))"
        }

        if ($predefinedBlock) {
            Write-VerboseLog "Found CMakePredefinedTargets folder GUID: $( $predefinedBlock.Guid )"
            Write-VerboseLog "Removing CMakePredefinedTargets folder (lines $( $predefinedBlock.StartIndex )-$( $predefinedBlock.EndIndex ))"
        }

        # Find all VCXPROJ_DUMMY_ projects
        $dummyBlocks = @()
        for ($i = 0; $i -lt $lines.Count; $i++) {
            if ($lines[$i] -match 'Project\(".*"\)\s*=\s*"VCXPROJ_DUMMY_.*"\s*,.*\{([0-9A-F-]+)\}') {
                $projectGuid = $matches[1]
                $endIndex = ($i + 1)..($lines.Count - 1) | Where-Object {
                    $lines[$_] -match '^\s*EndProject\s*$'
                } | Select-Object -First 1

                if ($endIndex) {
                    $block = @{
                        Guid = $projectGuid
                        StartIndex = $i
                        EndIndex = $endIndex
                    }
                    $dummyBlocks += $block
                    Write-VerboseLog "Found VCXPROJ_DUMMY_ project GUID: $projectGuid"
                    Write-VerboseLog "Removing VCXPROJ_DUMMY_ project (lines $i-$endIndex)"
                }
            }
        }

        $excludedBlocks = @($allBuildBlock, $zeroCheckBlock, $predefinedBlock) + $dummyBlocks | Where-Object { $_ -ne $null }
        $excludedGuids = @($allBuildBlock.Guid, $zeroCheckBlock.Guid, $predefinedBlock.Guid) + ($dummyBlocks | ForEach-Object { $_.Guid }) | Where-Object { $_ -ne $null }

        # Filter lines using pure predicate and write the result
        0..($lines.Count - 1) | Where-Object {
            Test-ShouldKeepLine -Index $_ -Line $lines[$_] -ExcludedBlocks $excludedBlocks -ExcludedGuids $excludedGuids
        } | ForEach-Object { $lines[$_] } | Set-Content -Path $DestSln -Encoding UTF8
        Write-Success "Cleaned solution saved to: $DestSln"
    }
    else {
        Write-ErrorMessage "Source solution file not found: $SourceSln"
    }
}

function New-Platform {
    param(
        [string]$Arch
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
        "-A", $Arch,
        "-DMQ_REGENERATE_SOLUTION=ON"
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

    if ($AddMQ2MainDependency) {
        $cmakeArgs += "-DMQ_ADD_MQ2MAIN_DEPENDENCY=ON"
    }

    if ($CustomPluginsFile) {
        $cmakeArgs += "-DMQ_CUSTOM_PLUGINS_FILE=$CustomPluginsFile"
    }

    if ($WritePluginsFile) {
        $cmakeArgs += "-DMQ_WRITE_PLUGINS_FILE=$WritePluginsFile"
    }

    # Testing: this generates the compile commands json for running nonstandard IDEs
    #$cmakeArgs += "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON"

    & cmake @cmakeArgs

    if ($LASTEXITCODE -ne 0) {
        Write-Host ""
        Write-ErrorMessage "CMake configuration failed for $Arch!"
        exit 1
    }

    Write-VerboseLog "$Arch configuration completed: $BuildDir\MacroQuest.sln"

    # Copy and clean the solution file
    Write-Host ""
    $sourceSln = Join-Path $BuildDir "MacroQuest.sln"
    $destSln = $SolutionPath
    Copy-CleanedSolution -SourceSln $sourceSln -DestSln $destSln
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

    if ($Clean) {
        Clear-BuildDirectory
    }
    else {

        # Initialize submodules
        Initialize-Submodules

        # Detect target architecture
        $targetArch = Get-TargetArchitecture
        Write-Host ""

        # Check for platform change and clean if necessary
        if (Test-PlatformChange -TargetArch $targetArch) {
            Clear-BuildDirectory
        }

        # Generate project files
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host "Generating Visual Studio Projects" -ForegroundColor Cyan
        Write-Host "========================================" -ForegroundColor Cyan
        Write-Host ""

        New-Platform -Arch $targetArch

        Write-Host ""
        Write-Host "========================================" -ForegroundColor Green
        Write-Success "Configuration Complete!"
        Write-Host "========================================" -ForegroundColor Green
        Write-Host ""
        Write-Host "Generated solutions:" -ForegroundColor Yellow
        Write-Host "  Architecture: $targetArch" -ForegroundColor Cyan
        Write-Host "  CMake solution: $BuildDir\MacroQuest.sln" -ForegroundColor Cyan
        Write-Host "  Cleaned solution: $SolutionPath (recommended)" -ForegroundColor Green
        Write-Host ""
        Write-Host "Build output:" -ForegroundColor Yellow
        Write-Host "  Binaries: build\bin\debug\ or build\bin\release\" -ForegroundColor Cyan
        Write-Host ""
        Write-Host "Next steps:" -ForegroundColor Yellow
        Write-Host "  1. Open solution in Visual Studio:" -ForegroundColor White
        Write-Host "     $SolutionPath (without CMake internal projects)" -ForegroundColor Gray
        Write-Host "  2. Or build via command line:" -ForegroundColor White
        Write-Host "     cmake --build $BuildDir --config Release" -ForegroundColor Gray
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
