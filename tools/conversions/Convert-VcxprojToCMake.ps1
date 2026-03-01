[CmdletBinding(DefaultParameterSetName='Single')]
param(
    [Parameter(ParameterSetName='Single', Mandatory=$true, Position=0)]
    [string]$VcxprojPath,

    [Parameter(ParameterSetName='Single', Mandatory=$false)]
    [string]$OutputPath,

    [Parameter(Mandatory=$false)]
    [switch]$GenerateAnalysis,

    [Parameter(Mandatory=$false)]
    [switch]$Force,

    [Parameter(Mandatory=$false)]
    [switch]$BackupExisting,

    [Parameter(Mandatory=$false)]
    [switch]$ConvertPropsFiles,  # Auto-convert props files if .cmake doesn't exist

    [Parameter(Mandatory=$false)]
    [string]$VcpkgManifest,  # Optional path to vcpkg.json manifest

    [Parameter(Mandatory=$false)]
    [string]$SolutionFolder  # Optional folder property to set in the solution for organization
)

# Import shared modules
$ModulePath = Join-Path $PSScriptRoot "Modules"
Import-Module (Join-Path $ModulePath "ConversionCommon.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "PathUtilities.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "GeneratorExpressions.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "AnalysisReporting.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "FileOperations.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "ItemDefinitionProcessing.psm1") -Force -Global

# ============================================================================
# New Processing Functions (Props-Style Two-Pass Pattern)
# ============================================================================

function Process-PropsFiles {
    param(
        [array]$PropsImports,
        [string]$ProjectDir,
        [bool]$ConvertMissing
    )

    $includeStatements = @()
    $macroStatements = @()
    $seenCmakePaths = @{}  # Track already-processed files for deduplication

    foreach ($import in $PropsImports) {
        $propsPath = Convert-PathToCMake $import.Path $ProjectDir

        # Handle both absolute and relative paths
        if ([System.IO.Path]::IsPathRooted($propsPath)) {
            $fullPropsPath = $propsPath
        } else {
            $fullPropsPath = Join-Path $ProjectDir $propsPath
        }

        # Normalize path
        $fullPropsPath = $fullPropsPath -replace '\\', '/'
        $cmakePath = $fullPropsPath -replace '\.props$', '.cmake'

        # Check if CMake version exists
        if (-not (Test-Path $cmakePath)) {
            if ($ConvertMissing) {
                Write-Host "  Converting missing props file: $fullPropsPath" -ForegroundColor Yellow

                # Call Convert-PropsToCMake.ps1
                if (Test-Path $fullPropsPath) {
                    & "$PSScriptRoot\Convert-PropsToCMake.ps1" `
                        -PropsPath $fullPropsPath `
                        -Force
                } else {
                    $script:analysis.Warnings += "Props file not found: $propsPath"
                }
            } else {
                $script:analysis.Warnings += "Props file not converted: $propsPath (use -ConvertPropsFiles to auto-convert)"
            }
        }

        # Generate include() and target_*_props() calls if cmake file exists
        if (Test-Path $cmakePath) {
            # Normalize cmake path for deduplication
            $normalizedPath = [System.IO.Path]::GetFullPath($cmakePath)

            if (-not $seenCmakePaths.ContainsKey($normalizedPath)) {
                $seenCmakePaths[$normalizedPath] = $true

                $propsName = [System.IO.Path]::GetFileNameWithoutExtension($propsPath) -replace '-', '_'
                $relativePath = Get-RelativePath -From $ProjectDir -To $cmakePath

                # Separate includes from macros
                $includeStatements += "include(`"$relativePath`")"
                $macroStatements += "target_${propsName}_props($ProjectName)"
            }
        }
    }

    # Return hashtable with separate arrays
    @{
        Includes = $includeStatements
        Macros = $macroStatements
    }
}

# ============================================================================
# Build Event Processing Functions
# ============================================================================

function Extract-BuildEvents {
    param(
        [System.Xml.XmlElement[]]$ItemDefGroupElements,
        [string]$ProjectDir
    )

    $preBuildEvents = @()
    $postBuildEvents = @()

    foreach ($group in $ItemDefGroupElements) {
        $groupCondition = $group.Condition

        # Process PreBuildEvent
        if ($group.PreBuildEvent -and $group.PreBuildEvent.Command) {
            $command = $group.PreBuildEvent.Command
            $message = $group.PreBuildEvent.Message

            if (-not [string]::IsNullOrWhiteSpace($command)) {
                $preBuildEvents += @{
                    Command = $command
                    Message = $message
                    Condition = $groupCondition
                }
            }
        }

        # Process PostBuildEvent
        if ($group.PostBuildEvent -and $group.PostBuildEvent.Command) {
            $command = $group.PostBuildEvent.Command
            $message = $group.PostBuildEvent.Message

            if (-not [string]::IsNullOrWhiteSpace($command)) {
                $postBuildEvents += @{
                    Command = $command
                    Message = $message
                    Condition = $groupCondition
                }
            }
        }
    }

    @{
        PreBuild = $preBuildEvents
        PostBuild = $postBuildEvents
    }
}

function Generate-BuildEventCMake {
    param(
        [array]$BuildEvents,
        [string]$EventType,  # "PRE_BUILD" or "POST_BUILD"
        [string]$ProjectName,
        [string]$ProjectDir
    )

    $output = @()
    if ($BuildEvents.Count -gt 0) {
        $output += New-Header -HeaderContent "$EventType events"
        $output += ""

        # Group events by their converted command to detect duplicates
        $uniqueEvents = @{ }

        foreach ($event in $BuildEvents) {
            $convertedCommands = Convert-BuildEventCommand -Command $event.Command -ProjectDir $ProjectDir

            if ($convertedCommands.Count -eq 0) {
                continue
            }

            # Create a key from the commands to detect duplicates
            $commandKey = $convertedCommands -join "|"

            if (-not $uniqueEvents.ContainsKey($commandKey)) {
                $uniqueEvents[$commandKey] = @{
                    Commands = $convertedCommands
                    Message = $event.Message
                    Conditions = @()
                }
            }

            if ($event.Condition) {
                $uniqueEvents[$commandKey].Conditions += $event.Condition
            }
        }

        foreach ($eventKey in $uniqueEvents.Keys) {
            $event = $uniqueEvents[$eventKey]
            $commands = $event.Commands -replace '\\"', '"'
            $message = $event.Message
            $conditions = $event.Conditions | Select-Object -Unique

            # If there are conditions, we might need to wrap in generator expressions
            # For simplicity, if all configurations have the same event, emit it unconditionally
            $hasConditions = $conditions.Count -gt 0 -and $conditions.Count -lt 4  # Less than all 4 standard configs

            if ($hasConditions) {
                # Parse conditions to get config names
                $configNames = $conditions | ForEach-Object {
                    $parsed = ConvertFrom-MSBuildCondition $_
                    if ($parsed.Configuration) {
                        $parsed.Configuration
                    }
                } | Where-Object { $_ } | Select-Object -Unique

                if ($configNames.Count -gt 0) {
                    $configList = $configNames -join ","
                    $output += "# Conditional: Only for $configList"
                }
            }

            $output += "add_custom_command(TARGET $ProjectName $EventType"

            foreach ($cmd in $commands) {
                # Escape the command for CMake
                $escapedCmd = $cmd

                # Check if the command starts with "if exist" pattern (Windows batch)
                if ($cmd -match '^if exist\s+') {
                    # Check if this is "if exist <path> powershell.exe ..." pattern
                    # CMake uses forward slashes which break cmd's "if exist", but PowerShell handles them fine
                    # So we extract the PowerShell command and call it directly
                    if ($cmd -match '^if exist\s+"?([^"]+)"?\s+powershell\.exe\s+(.+)$') {
                        $checkPath = $Matches[1]
                        $psArgs = $Matches[2]
                        # Call PowerShell directly - it handles forward slashes properly
                        # PowerShell will error clearly if the script doesn't exist
                        $output += "    COMMAND powershell.exe $psArgs"
                    } else {
                        # For other "if exist" commands, convert forward slashes to backslashes in the path
                        # cmd.exe's "if exist" requires backslashes
                        $fixedCmd = $escapedCmd -replace '^(if exist\s+)"?([^"]+)"?(.*)$', {
                            $prefix = $_.Groups[1].Value
                            $path = $_.Groups[2].Value -replace '/', '\'
                            $suffix = $_.Groups[3].Value
                            "${prefix}`"${path}`"${suffix}"
                        }
                        $output += "    COMMAND cmd /c `"$fixedCmd`""
                    }
                } else {
                    # For simple commands, try to parse into executable and args
                    $output += "    COMMAND $escapedCmd"
                }
            }

            if ($message) {
                $convertedMessage = Convert-MSBuildVariable -Value $message
                $output += "    COMMENT `"$convertedMessage`""
            }

            $output += "    VERBATIM"
            $output += ")"
            $output += ""
        }
    }

    $output
}

# ============================================================================
# Main Script Logic
# ============================================================================

# Resolve paths
$VcxprojPath = Resolve-Path $VcxprojPath -ErrorAction Stop
$ProjectDir = Split-Path $VcxprojPath -Parent

if (-not $OutputPath) {
    $OutputPath = Join-Path $ProjectDir "CMakeLists.txt"
}

# Check if output file already exists
if (-not (Test-OutputFileExists -OutputPath $OutputPath -Force $Force -BackupExisting $BackupExisting)) {
    exit 0
}

# Parse XML
Write-Host "Parsing $VcxprojPath..." -ForegroundColor Cyan
[xml]$vcxproj = Get-Content $VcxprojPath

# Extract project name - prefer from Globals PropertyGroup, fallback to filename
# This assumes globals aren't conditional
$globalsPropertyGroup = $vcxproj.Project.PropertyGroup |
    Where-Object { $_.Label -eq "Globals" } |
    Select-Object -First 1

$ProjectName = if ($globalsPropertyGroup -and $globalsPropertyGroup.ProjectName) {
    Write-Host "Using ProjectName from Globals" -ForegroundColor Cyan
    $globalsPropertyGroup.ProjectName
} elseif ($globalsPropertyGroup -and $globalsPropertyGroup.RootNamespace) {
    Write-Host "Using RootNamespace for project from Globals" -ForegroundColor Cyan
    $globalsPropertyGroup.RootNamespace
} else {
    # Fallback to filename
    Write-Host "ProjectName not found in Globals PropertyGroup, using filename" -ForegroundColor Yellow
    [System.IO.Path]::GetFileNameWithoutExtension($VcxprojPath)
}

Write-Host "Using ProjectName: $ProjectName" --ForegroundColor Cyan

Write-Host "Analyzing project structure..." -ForegroundColor Cyan

# Initialize analysis tracking
$script:analysis = @{
    Converted = @()
    Partial = @()
    NotConverted = @()
    Warnings = @()
    PropsFiles = @()
}

# ============================================================================
# First Pass: Data Collection
# ============================================================================

# Extract props file imports,  probuf is handled specially with cmake features
$propsImports = $vcxproj.Project.ImportGroup | ForEach-Object {
    $_.Import
} | Where-Object {
    $_.Project -match '\.props$' -and $_.Project -notmatch 'Microsoft\.Cpp' -and $_.Project -notmatch 'protobuf'
} | ForEach-Object {
    @{
        Path = $_.Project
        Condition = $_.Condition
    }
}

if ($propsImports.Count -gt 0) {
    Write-Host "Found $($propsImports.Count) props file(s)" -ForegroundColor Cyan
    $script:analysis.PropsFiles = $propsImports | ForEach-Object { $_.Path }
}

# Determine if this is a library or executable
$configurationType = $vcxproj.Project.PropertyGroup |
    Where-Object { $_.ConfigurationType } |
    Select-Object -First 1 -ExpandProperty ConfigurationType

$isDynamicLibrary = $configurationType -eq "DynamicLibrary"
$isStaticLibrary = $configurationType -eq "StaticLibrary"
$isExecutable = $configurationType -eq "Application"

# Check if project has mixed configuration types
$configTypes = $vcxproj.Project.PropertyGroup | Where-Object { $_.ConfigurationType }
$hasMixedTypes = ($configTypes | Select-Object -ExpandProperty ConfigurationType -Unique | Measure-Object).Count -gt 1

if ($hasMixedTypes) {
    $script:analysis.Warnings += "Project has mixed configuration types (DLL/Static)"
}

$characterSet = Clear-ListedProperties -Properties ($vcxproj.Project.PropertyGroup | Where-Object {
    $_.CharacterSet
} | ForEach-Object -Begin { $ex = @{} } -Process {
    $condition = $_.Condition
    $_.CharacterSet | ForEach-Object {
        if ($_ -eq 'Unicode') {
            if (-not $ex.ContainsKey('UNICODE')) { $ex['UNICODE'] = @() }
            $ex['UNICODE'] += $condition
            if (-not $ex.ContainsKey('_UNICODE')) { $ex['_UNICODE'] = @() }
            $ex['_UNICODE'] += $condition
        } elseif ($_ -eq 'MultiByte') {
            if (-not $ex.ContainsKey('_MBCS')) { $ex['_MBCS'] = @() }
            $ex['_MBCS'] += $condition
        }
    }
} -End { $ex }) -MultiBuild:$hasMixedTypes

# Extract precompiled header info
$pchEnabled = $vcxproj.Project.ItemDefinitionGroup |
        Where-Object { $_.ClCompile.PrecompiledHeader -eq "Use" } |
        Select-Object -First 1

# Process ClCompile items (source files)
Write-Host "Extracting source files..." -ForegroundColor Cyan
$allSourceFiles = @($vcxproj.Project.ItemGroup.ClCompile |
        Where-Object { $_.Include } |
        Where-Object {
            # Exclude protobuf-generated sources (have DependentUpon pointing to .proto)
            -not ($_.DependentUpon -and $_.DependentUpon -match '\.proto$')
        })

if ($pchEnabled) {
    $pchCompiled = $vcxproj.Project.ItemGroup.ClCompile | Where-Object {
        $_.ChildNodes | Where-Object {
            $_.Name -eq 'PrecompiledHeader' -and $_.'#text' -eq 'Create'
        }
    } | ForEach-Object { $_.Include } | Where-Object { $_ }

    $allSourceFiles = $allSourceFiles | Where-Object {
        $_.Include -notin $pchCompiled
    }

    $script:analysis.Converted += "Precompiled source: $pchCompiled"
}

$sourceFiles = $allSourceFiles |
        ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }

$sourceFilesNotPrecompiled = $allSourceFiles |
        Where-Object { $_.ExcludedFromBuild -ne "true" -and $_.PrecompiledHeader -eq "NotUsing" } |
        ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }

$script:analysis.Converted += "Source files: $($sourceFiles.Count)"

# Process ClInclude items (header files)
Write-Host "Extracting header files..." -ForegroundColor Cyan
$headerFiles = @($vcxproj.Project.ItemGroup.ClInclude |
    Where-Object { $_.Include } |
    Where-Object {
        # Exclude protobuf-generated headers (have DependentUpon pointing to .proto)
        -not ($_.DependentUpon -and $_.DependentUpon -match '\.proto$')
    } |
    ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir })

if ($headerFiles.Count -gt 0) {
    $script:analysis.Converted += "Header files: $($headerFiles.Count)"
}

Write-Host "Extracting assembly files..." -ForegroundColor Cyan
$allAsmFiles = @($vcxproj.Project.ItemGroup.NASM |
    Where-Object { $_.Include })

$asmFiles = $allAsmFiles |
    ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }

if ($asmFiles.Count -gt 0) {
    $script:analysis.Converted += "Assembly files: $($asmFiles.Count)"
}

# treat other files like headers
Write-Host "Extracting other compiled files (rc, natvis)..." -ForegroundColor Cyan
$otherFiles = (
    $vcxproj.Project.ItemGroup.ResourceCompile +
            $vcxproj.Project.ItemGroup.Natvis +
            $vcxproj.Project.ItemGroup.None +
            $vcxproj.Project.ItemGroup.Text
) | Where-Object { $_.Include } | Where-Object {
    Test-Path $(Join-Path $ProjectDir $_.Include)
} | ForEach-Object {
    Convert-PathToCMake $_.Include $ProjectDir
}

if ($otherFiles.Count -gt 0) {
    $script:analysis.Converted += "Other files: $($otherFiles.Count)"
}

# only cpp and asm files can be excluded
$excludedFiles = ($allSourceFiles + $allAsmFiles) | ForEach-Object -Begin { $ex = @{} } -Process {
    $conditions = $_.ChildNodes | Where-Object {
        $_.Name -eq 'ExcludedFromBuild' -and $_.'#text' -eq 'true'
    } | ForEach-Object {
        if ($_.Condition) { $_.Condition } else {''}
    }

    if ($conditions.Count -gt 0) {
        $distinct = Clear-ListedProperties -Properties @{ ex = $conditions } -MultiBuild:$hasMixedTypes
        $condition = Join-OptionsWithGeneratorExpressions -OptionName 'ExcludedFromBuild=true' -Entries $distinct['ex']
        if (-not $ex.ContainsKey($condition)) { $ex[$condition] = @() }
        $ex[$condition] += Convert-PathToCMake $_.Include $ProjectDir
    }
} -End { $ex }

# only cpp files can have forced includes
$forcedIncludes = $allSourceFiles | ForEach-Object -Begin { $ex = @{} } -Process {
    # MQ only really uses this for pch.h, so just assume simple file names
    $file = $_
    $_.ForcedIncludeFiles | Where-Object { $_ } | ForEach-Object {
        if (-not $ex.ContainsKey($_)) { $ex[$_] = @() }
        $ex[$_] += Convert-PathToCMake $file.Include $ProjectDir
    }
} -End { $ex }

if ($excludedFiles.Count -gt 0) {
    $script:analysis.Converted += "Excluded files: $($excludedFiles.Count)"
}

if ($forcedIncludes.Count -gt 0) {
    $script:analysis.Converted += "Forced includes: $($forcedIncludes.Count)"
}

# Process ProtocolBuffer items (.proto files)
Write-Host "Extracting protobuf files..." -ForegroundColor Cyan
$protobufFiles = @()

# Try CustomBuild items with .proto extension
$protobufFiles = $vcxproj.Project.ItemGroup.CustomBuild |
    Where-Object { $_.Include -match '\.proto$' } |
    ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }

# Try ProtocolBuffer elements (some projects use this)
if ($protobufFiles.Count -eq 0) {
    $protobufFiles = $vcxproj.Project.ItemGroup.ProtocolBuffer |
        Where-Object { $_.Include } |
        ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }
}

# Try Protobuf elements (alternative naming)
if ($protobufFiles.Count -eq 0) {
    $protobufFiles = $vcxproj.Project.ItemGroup.Protobuf |
        Where-Object { $_.Include } |
        ForEach-Object { Convert-PathToCMake $_.Include $ProjectDir }
}

if ($protobufFiles.Count -gt 0) {
    $script:analysis.Converted += "Protobuf files: $($protobufFiles.Count)"
}

# Track excluded protobuf-generated files for analysis report
$protobufGeneratedHeaders = $vcxproj.Project.ItemGroup.ClInclude |
    Where-Object { $_.Include -and $_.DependentUpon -and $_.DependentUpon -match '\.proto$' } |
    Measure-Object | Select-Object -ExpandProperty Count

$protobufGeneratedSources = $vcxproj.Project.ItemGroup.ClCompile |
    Where-Object { $_.Include -and $_.DependentUpon -and $_.DependentUpon -match '\.proto$' } |
    Measure-Object | Select-Object -ExpandProperty Count

if ($protobufGeneratedHeaders -gt 0 -or $protobufGeneratedSources -gt 0) {
    $script:analysis.Converted += "Excluded protobuf-generated files: $($protobufGeneratedHeaders + $protobufGeneratedSources) (will be auto-generated)"
}

# Parse vcpkg.json if specified or exists in project directory
Write-Host "Checking for vcpkg.json..." -ForegroundColor Cyan
$vcpkgDependencies = @()

# Determine vcpkg manifest path
$vcpkgJsonPath = if ($VcpkgManifest) {
    # User specified explicit path
    if ([System.IO.Path]::IsPathRooted($VcpkgManifest)) {
        $VcpkgManifest
    } else {
        Join-Path $ProjectDir $VcpkgManifest
    }
} else {
    # Default: same directory as vcxproj
    Join-Path $ProjectDir "vcpkg.json"
}

if (Test-Path $vcpkgJsonPath) {
    Write-Host "  Found vcpkg.json at $vcpkgJsonPath" -ForegroundColor Cyan
    try {
        $vcpkgJson = Get-Content $vcpkgJsonPath -Raw | ConvertFrom-Json

        if ($vcpkgJson.dependencies) {
            $vcpkgDependencies = $vcpkgJson.dependencies | ForEach-Object {
                # Dependencies can be strings or objects
                if ($_ -is [string]) {
                    $_
                } elseif ($_.name) {
                    $_.name
                }
            }

            $script:analysis.Converted += "vcpkg dependencies: $($vcpkgDependencies.Count)"
        }
    } catch {
        $script:analysis.Warnings += "Failed to parse vcpkg.json: $_"
    }
} else {
    Write-Host "  No vcpkg.json found, skipping vcpkg package handling" -ForegroundColor Gray
}

# Process ItemDefinitionGroups using two-pass approach
Write-Host "Processing compiler and linker settings..." -ForegroundColor Cyan
$itemDefResult = Convert-AllItemDefinitionGroups `
    -ItemDefGroupElements $vcxproj.Project.ItemDefinitionGroup `
    -TargetName $ProjectName `
    -MultiBuild:$hasMixedTypes `
    -VcpkgDependencies $vcpkgDependencies
$itemDefOutput = $itemDefResult.Output

$script:analysis.Converted += "Compiler/linker settings extracted"

# Extract project references
Write-Host "Extracting project references..." -ForegroundColor Cyan
$projectReferences = $vcxproj.Project.ItemGroup.ProjectReference |
        Where-Object { $_.Include } |
        ForEach-Object {
            $refFileName = [System.IO.Path]::GetFileNameWithoutExtension($_.Include)
            $refFullPath = [System.IO.Path]::GetFullPath([System.IO.Path]::Combine($ProjectDir, $_.Include))

            # Try to load the referenced vcxproj and extract ProjectName/RootNamespace/TargetName
            if (Test-Path $refFullPath) {
                try {
                    [xml]$refVcxproj = Get-Content $refFullPath -Raw

                    # Resolve project name: ProjectName -> RootNamespace -> Filename
                    $refGlobals = $refVcxproj.Project.PropertyGroup |
                        Where-Object { $_.Label -eq "Globals" } |
                        Select-Object -First 1

                    if ($refGlobals -and $refGlobals.ProjectName) {
                        $refGlobals.ProjectName
                    } elseif ($refGlobals -and $refGlobals.RootNamespace) {
                        $refGlobals.RootNamespace
                    } else {
                        $refFileName
                    }
                } catch {
                    Write-Warning "Could not parse referenced project: $refFullPath"
                    $refFileName
                }
            } else {
                $refFileName
            }
        }

if ($projectReferences.Count -gt 0) {
    $script:analysis.Converted += "Project references: $($projectReferences.Count)"
}

# Extract target name customizations
$targetNameEntries = @()

# Extract all TargetName elements (both conditional and unconditional)
$vcxproj.Project.PropertyGroup |
    Where-Object { $_.TargetName } |
    ForEach-Object {
        $value = $_.TargetName -replace '\$\(ProjectName\)', $ProjectName
        $targetNameEntries += @{
            Condition = $_.Condition
            Value = $value
        }
    }

if ($targetNameEntries.Count -gt 0) {
    $script:analysis.Converted += "Target name customization detected"
}

$pchHeader = $null
if ($pchEnabled) {
    # Get the PrecompiledHeaderFile, default to "pch.h" if not specified
    $pchHeader = $pchEnabled.ClCompile.PrecompiledHeaderFile
    if (-not $pchHeader) {
        $pchHeader = "pch.h"
    }

    # This handles eqlib.vcxproj, assume the shortest path is correct
    $pchHeader = Get-ChildItem -Path $ProjectDir -Filter $pchHeader -Recurse -File | ForEach-Object {
        Get-RelativePath -From $ProjectDir -To $_.FullName
    } | Sort-Object Length | Select-Object -First 1

    $pchHeader = $pchHeader -replace '\\', '/' -replace '^\./', ''
    $script:analysis.Converted += "Precompiled header: $pchHeader"
}

# Extract pre/post build events
Write-Host "Extracting build events..." -ForegroundColor Cyan
$buildEvents = Extract-BuildEvents -ItemDefGroupElements $vcxproj.Project.ItemDefinitionGroup -ProjectDir $ProjectDir

$preBuildEvents = $buildEvents.PreBuild
$postBuildEvents = $buildEvents.PostBuild

if ($preBuildEvents.Count -gt 0) {
    $script:analysis.Converted += "Pre-build events: $($preBuildEvents.Count)"
}
if ($postBuildEvents.Count -gt 0) {
    $script:analysis.Converted += "Post-build events: $($postBuildEvents.Count)"
}

# ============================================================================
# Second Pass: CMake Generation
# ============================================================================

Write-Host "Generating CMakeLists.txt..." -ForegroundColor Cyan

$cmake  = "# Generated from $ProjectName.vcxproj`n"
$cmake += "# This file is designed to work with add_subdirectory()`n"
$cmake += "`n"

# Process props files
$propsResult = @{ Includes = @(); Macros = @() }
if ($propsImports.Count -gt 0) {
    $propsResult = Process-PropsFiles -PropsImports $propsImports -ProjectDir $ProjectDir -ConvertMissing $ConvertPropsFiles

    if ($propsResult.Includes.Count -gt 0) {
        $cmake += (New-Header -HeaderContent "Props file includes") -join "`n"
        $cmake += "`n"
        $cmake += $propsResult.Includes -join "`n"
        $cmake += "`n`n"
    }
}
# Note: Props macros will be applied after target definition

# Add vcpkg package discovery
$vcpkgDependencies = $vcpkgDependencies | Where-Object { $_ -notin @("atl") }
if ($vcpkgDependencies.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "vcpkg dependencies") -join "`n"
    $cmake += "`n"

    foreach ($dep in $vcpkgDependencies) {
        # Map package names for find_package (some vcpkg packages use "unofficial-" prefix)
        $findPackageName = switch ($dep) {
            "sqlite3"            { "unofficial-sqlite3" }
            "argon2"             { "unofficial-argon2" }
            "crashpad-backtrace" { "crashpad" }
            "nlohmann-json"      { "nlohmann_json" }
            "zlib"               { "ZLIB" }
            default              { $dep }
        }

        $cmake += "find_package($findPackageName REQUIRED)`n"
    }

    $cmake += "`n"
}

# Add header collection (if any)
if ($headerFiles.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Header files") -join "`n"
    $cmake += "`n"
    $cmake += "set(${ProjectName}_HEADERS`n"

    foreach ($hdr in $headerFiles) {
        $cmake += "    `"$hdr`"`n"
    }

    $cmake += ")`n`n"
    $cmake += "source_groups(`"Header Files`" `${${ProjectName}_HEADERS})`n`n"
}

# Add other collection (if any)
if ($otherFiles.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Other files") -join "`n"
    $cmake += "`n"
    $cmake += "set(${ProjectName}_OTHERFILES`n"

    foreach ($other in $otherFiles) {
        $cmake += "    `"$other`"`n"
    }

    $cmake += ")`n`n"
    $cmake += "source_group(`"Resource Files`" FILES `${${ProjectName}_OTHERFILES})`n`n"
}

if ($asmFiles.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Assembly files") -join "`n"
    $cmake += "`n"
    $cmake += "set(${ProjectName}_ASSEMBLY`n"

    foreach ($asm in $asmFiles) {
        $cmake += "    `"$asm`"`n"
    }

    $cmake += ")`n`n"
    $cmake += "source_groups(`"Assembly Files`" `${${ProjectName}_ASSEMBLY})`n`n"
}

# Add source collection
$cmake += (New-Header -HeaderContent "Source files") -join "`n"
$cmake += "`n"
$cmake += "set(${ProjectName}_SOURCES`n"

foreach ($src in $sourceFiles) {
    $cmake += "    `"$src`"`n"
}

$cmake += ")`n`n"
$cmake += "source_groups(`"Source Files`" `${${ProjectName}_SOURCES})`n`n"

# Exclude files from being built
foreach ($excluded in $excludedFiles.GetEnumerator()) {
    if ($excluded.Value.Count -gt 0) {
        $cmake += "# Exclude files from being built`n"
        $cmake += "set_source_files_properties(`n"

        foreach ($src in $excluded.Value)
        {
            $cmake += "    `"$src`"`n"
        }

        $cmake += "    PROPERTIES`n"
        $cmake += "        VS_SETTINGS `"$($excluded.Key)`""
        $cmake += ")`n`n"
    }
}

# Force includes at the source level
foreach ($forced in $forcedIncludes.GetEnumerator()) {
    if ($forced.Value.Count -gt 0) {
        $cmake += "# Force includes in source files`n"
        $cmake += "set_source_files_properties(`n"

        foreach ($src in $forced.Value)
        {
            $cmake += "    `"$src`"`n"
        }

        $cmake += "    PROPERTIES`n"
        $cmake += "        COMPILE_OPTIONS `"/FI;$($forced.Key)`""
        $cmake += ")`n`n"
    }
}

# Add library/executable target
$cmake += (New-Header -HeaderContent "Target definition") -join "`n"
$cmake += "`n"

if ($hasMixedTypes) {
    $cmake += "# Library type depends on configuration`n"
    $cmake += "if(MQ_STATIC_BUILD)`n"
    $cmake += "    set(LIB_TYPE STATIC)`n"
    $cmake += "else()`n"
    $cmake += "    set(LIB_TYPE SHARED)`n"
    $cmake += "endif()`n`n"
    $cmake += "add_library($ProjectName `${LIB_TYPE}`n"
} elseif ($isDynamicLibrary) {
    $cmake += "add_library($ProjectName SHARED`n"
} elseif ($isStaticLibrary) {
    $cmake += "add_library($ProjectName STATIC`n"
} elseif ($isExecutable) {
    $cmake += "add_executable($ProjectName`n"
}

if ($headerFiles.Count -gt 0) {
    $cmake += "    `${${ProjectName}_HEADERS}`n"
}
if ($otherFiles.Count -gt 0) {
    $cmake += "    `${${ProjectName}_OTHERFILES}`n"
}
if ($asmFiles.Count -gt 0) {
    $cmake += "    `${${ProjectName}_ASSEMBLY}`n"
}
$cmake += "    `${${ProjectName}_SOURCES}`n"
$cmake += ")`n`n"

# Set the solution folder for the library, if one was set
if ($SolutionFolder) {
    $cmake += "set_target_properties($ProjectName PROPERTIES FOLDER `"$SolutionFolder`")`n`n"
}

# Set custom output name if TargetName is specified
if ($targetNameEntries.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Output name customization") -join "`n"
    $cmake += "`n"

    # Check if there's only one unconditional entry
    $unconditionalEntry = $targetNameEntries | Where-Object { -not $_.Condition } | Select-Object -First 1
    $conditionalEntries = $targetNameEntries | Where-Object { $_.Condition }


    if ($unconditionalEntry -and $conditionalEntries.Count -eq 0) {
        # Simple unconditional case
        $cmake += "set_target_properties($ProjectName PROPERTIES OUTPUT_NAME`n"
        $cmake += "    `"$($unconditionalEntry.Value)`"`n"
        $cmake += ")`n`n"
    } else {
        function Generate-PropSet {
            param([array]$InnerEntries)

            @(
                "set_target_properties($ProjectName PROPERTIES OUTPUT_NAME",
                "    $(New-ConfigGeneratorExpression -Entries $InnerEntries -DefaultValue $ProjectName)",
                ")"
            )
        }

        $outputNameStatements = if ($conditionalEntries | Where-Object { $_.Condition -match '\$\(Platform\)' }) {
            # Platform-specific entries
            New-PlatformGeneratorExpression -Entries $conditionalEntries -InnerGenerator ${function:Generate-PropSet}
        } else {
            # No platform specified
            New-StaticGeneratorExpression -Entries $conditionalEntries -InnerGenerator ${function:Generate-PropSet}
        }

        $cmake += $outputNameStatements -join "`n"
        $cmake += "`n`n"
    }
}

# Apply props file configurations (macros must be called AFTER target is created)
if ($propsResult.Macros.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Apply props file configurations") -join "`n"
    $cmake += "`n"
    $cmake += $propsResult.Macros -join "`n"
    $cmake += "`n`n"
}

# Add nasm file actions (must be done after the props file configurations)
if ($asmFiles.COunt -gt 0) {
    $cmake += (New-Header -HeaderContent "Add NASM tool to ASM files") -join "`n"
    $cmake += "`n"
    $cmake += "add_nasm_sources(`${${ProjectName}_ASSEMBLY})`n"
    $cmake += "`n"
}

# Generate protobuf files
if ($protobufFiles.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Protobuf generation") -join "`n"
    $cmake += "`n"
    $cmake += "# Create object library for protobuf files`n"
    $cmake += "add_library(${ProjectName}-proto OBJECT`n"

    foreach ($proto in $protobufFiles) {
        $cmake += "    `"$proto`"`n"
    }

    $cmake += ")`n`n"

    if ($SolutionFolder) {
        $cmake += "set_target_properties(${ProjectName}-proto PROPERTIES FOLDER `"${SolutionFolder}/proto`")`n"
    }

    if ($propsResult.Macros.Count -gt 0) {
        $macros = $propsResult.Macros | ForEach-Object {
            $_ -replace $ProjectName, "${ProjectName}-proto"
        }

        $cmake += "`n"
        $cmake += $macros -join "`n"
        $cmake += "`n`n"
    }

    $cmake += "target_link_libraries(${ProjectName}-proto PUBLIC`n"
    $cmake += "    protobuf::libprotobuf`n"
    $cmake += ")`n`n"

    $cmake += "target_include_directories(${ProjectName}-proto PUBLIC`n"
    $cmake += "    `$<TARGET_PROPERTY:${ProjectName}-proto,BINARY_DIR>`n"
    $cmake += ")`n`n"

    $cmake += "# Generate protobuf sources (.pb.cc and .pb.h files)`n"
    $cmake += "# Note: Generated files are automatically added to the target`n"
    $cmake += "# Do not manually list .pb.cc or .pb.h files in source variables`n"
    $cmake += "protobuf_generate(`n"
    $cmake += "    TARGET ${ProjectName}-proto`n"
    $cmake += "    LANGUAGE cpp`n"
    $cmake += "    PROTOC_OUT_DIR ${CMAKE_CURRENT_LIST_DIR}`n"
    $cmake += ")`n`n"

    $cmake += "# Link the proto library to main project`n"
    $cmake += "target_link_libraries($ProjectName PUBLIC`n"
    $cmake += "    ${ProjectName}-proto`n"
    $cmake += ")`n`n"
}

# Link vcpkg dependencies (filter out header-only libraries)
if ($vcpkgDependencies.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Link vcpkg dependencies") -join "`n"
    $cmake += "`n"
    $cmake += "target_link_libraries($ProjectName PRIVATE`n"

    foreach ($dep in $vcpkgDependencies) {
        # Map package names to CMake targets
        $targetName = switch ($dep) {
            "fmt"                { "fmt::fmt" }
            "protobuf"           { "protobuf::libprotobuf" }
            "lua"                { "lua::lua" }
            "sqlite3"            { "unofficial::sqlite3::sqlite3" }
            "argon2"             { "unofficial::argon2::libargon2" }
            "sol2"               { "sol2" }
            "freetype"           { "Freetype::Freetype" }
            "dxsdk-d3dx"         { "Microsoft::D3DX9" }
            "crashpad-backtrace" { "crashpad::crashpad" }
            "wil"                { "WIL::WIL" }
            "nlohmann-json"      { "nlohmann_json::nlohmann_json" }
            "zlib"               { "ZLIB::ZLIB" }
            "czmq"               { "czmq-static" }
            "zyre"               { "zyre-static" }
            "sleepy-discord"     { "sleepy-discord" }
            "curl-84"            { "CURL-84::libcurl" }
            "curl"               { "CURL::libcurl" }
            "rapidjson"          { "rapidjson" }
            "sdl2"               { "SDL2::SDL2main" }
            "directxtk"          { "Microsoft::DirectXTK" }
            "entt"               { "EnTT::EnTT" }
            "taskflow"           { "Taskflow::Taskflow" }
            default              { "${dep}::${dep}" }
        }

        $cmake += "    $targetName`n"
    }

    $cmake += ")`n`n"
}

# Add project dependencies
if ($projectReferences.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Project dependencies") -join "`n"
    $cmake += "`n"
    $refString = $projectReferences -join " "
#    $cmake += "add_dependencies($ProjectName $refString)`n"
#    $cmake += "`n"
    $cmake += "target_link_libraries($ProjectName PRIVATE $refString)`n"
    $cmake += "`n"
}

# Add ItemDefinitionGroup output
if ($itemDefOutput.Count -gt 0) {
    $cmake += $itemDefOutput -join "`n"
    $cmake += "`n"
}

if ($characterSet.Count -gt 0) {
    $cmake += (New-Header -HeaderContent "Character set defines") -join "`n"
    $cmake += "`n"
    $cmake += "target_compile_definitions($ProjectName PRIVATE`n"
    foreach ($s in $characterSet.GetEnumerator()) {
        $expression = Join-OptionsWithGeneratorExpressions -OptionName $s.Name -Entries $s.Value
        $cmake += "    `"$expression`"`n"
    }
    $cmake += ")`n`n"
}

# Add precompiled header -- note: this needs to be done after we are done with the sources because it mutates them
if ($pchHeader) {
    $cmake += (New-Header -HeaderContent "Precompiled header") -join "`n"
    $cmake += "`n"
    if ($sourceFilesNotPrecompiled.Count -gt 0) {
        $cmake += "set_source_files_properties(`n"
        foreach ($file in $sourceFilesNotPrecompiled) {
            $cmake += "    `"$file`""
        }
        $cmake += "    PROPERTIES SKIP_PRECOMPILE_HEADERS ON)`n`n"
    }
    $cmake += "target_precompile_headers($ProjectName PRIVATE `"$pchHeader`")`n`n"
}

# Add pre-build events
if ($preBuildEvents.Count -gt 0) {
    $preBuildOutput = Generate-BuildEventCMake -BuildEvents $preBuildEvents -EventType "PRE_BUILD" -ProjectName $ProjectName -ProjectDir $ProjectDir
    if ($preBuildOutput.Count -gt 0) {
        $cmake += $preBuildOutput -join "`n"
        $cmake += "`n"
    }
}

# Add post-build events
if ($postBuildEvents.Count -gt 0) {
    $postBuildOutput = Generate-BuildEventCMake -BuildEvents $postBuildEvents -EventType "POST_BUILD" -ProjectName $ProjectName -ProjectDir $ProjectDir
    if ($postBuildOutput.Count -gt 0) {
        $cmake += $postBuildOutput -join "`n"
        $cmake += "`n"
    }
}

# Add manual conversion notes
$cmake += "# ============================================================================`n"
$cmake += "# MANUAL CONVERSION NOTES`n"
$cmake += "# ============================================================================`n"
$cmake += "#`n"

if ($script:analysis.Warnings.Count -gt 0) {
    $cmake += "# - Warnings:`n"
    foreach ($warning in $script:analysis.Warnings) {
        $cmake += "#   - $warning`n"
    }
}

$cmake += "# - Review and adjust as needed`n"

# Write CMakeLists.txt
Write-Host "Writing CMakeLists.txt to $OutputPath..." -ForegroundColor Cyan
$cmake | Out-File -FilePath $OutputPath -Encoding UTF8 -NoNewline

Write-Host "CMakeLists.txt generated successfully!" -ForegroundColor Green

# ============================================================================
# Generate Analysis Report
# ============================================================================

if ($GenerateAnalysis) {
    $analysisPath = Join-Path $ProjectDir "$ProjectName-conversion-analysis.txt"

    $report = New-VcxprojAnalysisReport `
        -Analysis $script:analysis `
        -ProjectName $ProjectName `
        -VcxprojPath $VcxprojPath `
        -SourceFileCount $sourceFiles.Count `
        -ExcludedFileCount $excludedFiles.Count `
        -ProjectReferenceCount $projectReferences.Count `
        -DefinitionCount 0 `
        -LinkerOptionCount 0

    $report | Out-File -FilePath $analysisPath -Encoding UTF8 -NoNewline
    Write-Host "Analysis report written to $analysisPath" -ForegroundColor Green

    Write-ConversionSummary -Analysis $script:analysis -ConverterType "Vcxproj"
}

Write-Host ""
Write-Host "Done! Review the generated CMakeLists.txt and test building." -ForegroundColor Cyan
