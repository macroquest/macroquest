# ConversionCommon.psm1
# Shared conversion functions for MSBuild to CMake conversion

# Helper function to convert MSBuild variables to CMake (unified version)
function Convert-MSBuildVariable {
    param(
        [string]$Value,
        [switch]$ForPropsFile,
        [hashtable]$ResolvedMacros = @{},
        [string]$PropsName = ""
    )

    $ApplyMSBuildThisFileDirectory = {
        param($v)
        $replacement = if ($ForPropsFile -and $PropsName) {
            "`${PATH_TO_${PropsName}_DIR}/"
        } elseif ($ForPropsFile) {
            '${CMAKE_CURRENT_LIST_DIR}/'
        } else {
            '${CMAKE_CURRENT_SOURCE_DIR}/'
        }
        $v -replace '\$\(MSBuildThisFileDirectory\)', $replacement
    }

    $ApplyBuiltinVariables = {
        param($v)
        $v `
            -replace '\$\(MSBuildProjectDirectory\)', '${CMAKE_CURRENT_SOURCE_DIR}' `
            -replace '\$\(MSBuildProjectName\)', '${PROJECT_NAME}' `
            -replace '\$\(ProjectName\)', '${PROJECT_NAME}' `
            -replace '\$\(ProjectDir\)', '${CMAKE_CURRENT_LIST_DIR}/' `
            -replace '\$\(Configuration\)', '$<CONFIG>' `
            -replace '\$\(Platform\)', '${CMAKE_GENERATOR_PLATFORM}' `
            -replace '\$\(MQBuildDirectory\)', '${CMAKE_BINARY_DIR}/' `
            -replace '\$\(MQBinaryDirName\)', '$<CONFIG>' `
            -replace '\$\(OutDir\)', '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/' `
            -replace '\$\(IntDir\)', '${CMAKE_CURRENT_BINARY_DIR}/' `
            -replace '\$\(MQSolutionDirectory\)', '${CMAKE_SOURCE_DIR}/src/' `
            -replace '\$\(MQRoot\)', '${CMAKE_SOURCE_DIR}/' `
            -replace '\$\(MQ2Root\)', '${CMAKE_SOURCE_DIR}/'
    }

    $ApplyUserMacros = {
        param($v)
        $ResolvedMacros.Keys | ForEach-Object -Begin { $result = $v } -Process {
            $pattern = [regex]::Escape("`$($_)")
            $result = $result -replace $pattern, "`${$_}"
        } -End { $result }
    }

    $ApplyRemainingAndCleanup = {
        param($v)
        $v `
            -replace '\$\(([^)]+)\)', '${$1}' `
            -replace '\\\\', '/' `
            -replace '\\(?!")', '/' `
            -replace '/+', '/' `
            -replace '(?<!\\)"', '\"'
    }

    # Compose the pipeline - handle empty input at the start
    if ([string]::IsNullOrWhiteSpace($Value)) { "" }
    else {
        $Value |
            ForEach-Object { & $ApplyMSBuildThisFileDirectory $_ } |
            ForEach-Object { & $ApplyBuiltinVariables $_ } |
            ForEach-Object { & $ApplyUserMacros $_ } |
            ForEach-Object { & $ApplyRemainingAndCleanup $_ }
    }
}

# Helper function to parse and convert MSBuild conditions to CMake
function Convert-ConditionToCMake {
    param([string]$Condition)

    # Define matchers as an ordered list of (pattern, handler) pairs
    # Each handler receives $Matches and returns the CMake condition
    $matchers = @(
        @{
            Pattern = "\$\((\w+)\.StartsWith\('([^']+)'\)\)"
            Handler = { "if(`"`${$($Matches[1])}`" MATCHES `"^$($Matches[2])`")" }
        },
        @{
            Pattern = "\$\((\w+)\.EndsWith\('([^']+)'\)\)"
            Handler = { "if(`"`${$($Matches[1])}`" MATCHES `"$($Matches[2])`$`")" }
        },
        @{
            Pattern = "^'?\`$\(([^)]+)\)'?\s*==\s*'([^']*)'$"
            Handler = { "if(`"`${$($Matches[1])}`" STREQUAL `"$($Matches[2])`")" }
        },
        @{
            Pattern = "^'?\`$\(([^)]+)\)'?\|'?\`$\(([^)]+)\)'?\s*==\s*'([^|]+)'\|'([^']+)'$"
            Handler = { "if(`"`${$($Matches[1])}`" STREQUAL `"$($Matches[3])`" AND `"`${$($Matches[2])}`" STREQUAL `"$($Matches[4])`")" }
        },
        @{
            Pattern = "^'?\`$\(([^)]+)\)'?\s*!=\s*'([^']*)'`$"
            Handler = { "if(NOT `"`${$($Matches[1])}`" STREQUAL `"$($Matches[2])`")" }
        },
        @{
            Pattern = "Exists\('([^']+)'\)"
            Handler = {
                $path = $Matches[1] -replace '\.props$', '.cmake'
                $convertedPath = Convert-MSBuildVariable -Value $path -ForPropsFile
                $negated = $Condition -match "^!Exists"
                $prefix = if ($negated) { "NOT " } else { "" }
                "if(${prefix}EXISTS `"`${PATH_TO_Common_DIR}/$convertedPath`")"
            }
        }
    )

    # Use expression-based conditional
    if ([string]::IsNullOrWhiteSpace($Condition)) {
        $null
    }
    else {
        # Find first matching pattern
        $matched = $matchers | Where-Object { $Condition -match $_.Pattern } | Select-Object -First 1
        if ($matched) {
            & $matched.Handler
        }
        else {
            "# TODO: Convert condition: $Condition`nif(TRUE)"
        }
    }
}

# Helper function to parse MSBuild condition strings (from vcxproj converter)
function ConvertFrom-MSBuildCondition {
    param(
        [Parameter(Mandatory=$true)]
        [string]$Condition
    )

    # Match pattern: 'left_expression'=='right_values'
    if ($Condition -match "^['`"]([^'`"]+)['`"]==['`"]([^'`"]+)['`"]$") {
        $leftSide = $Matches[1]
        $rightSide = $Matches[2]

        # Extract variable names from left side
        $variables = [regex]::Matches($leftSide, '\$\(([^\)]+)\)') |
                ForEach-Object { $_.Groups[1].Value }

        # Build regex to extract values
        $rightRegex = [regex]::Escape($leftSide) -replace '\\\$\\\(([^\\)]+)\\\)', '(?<$1>.*)'

        [regex]::Matches($rightSide, $rightRegex) |
            ForEach-Object -Begin { $results = @{} } -Process {
                $val = $_
                $variables | ForEach-Object { $results[$_] = $val.Groups[$_].Value }
            } -End { $results }
    }
    else {
        Write-Verbose "Could not parse condition: $Condition"
        @{}
    }
}

# Helper function to extract delimited values
function Get-DelimitedValues {
    param(
        [string]$Value,
        [string[]]$ExcludePatterns = @(),
        [string]$Delimiter = ';'
    )

    if ([string]::IsNullOrWhiteSpace($Value)) { @() }
    else {
        $Value -split [regex]::Escape($Delimiter) |
            ForEach-Object { $_.Trim() } |
            Where-Object { $_ } |
            Where-Object {
                $item = $_
                -not ($ExcludePatterns | Where-Object { $item -match $_ })
            }
    }
}

# Each entry is: OptionName -> Handler (either a hashtable for lookup or scriptblock for custom logic)
$script:CompilerOptionMappings = @{
    # Map-based lookups
    'WarningLevel' = @{ 'Level1' = '/W1'; 'Level2' = '/W2'; 'Level3' = '/W3'; 'Level4' = '/W4'; 'EnableAllWarnings' = '/Wall' }
    'Optimization' = @{ 'Disabled' = '/Od'; 'MinSpace' = '/O1'; 'MaxSpeed' = '/O2'; 'Full' = '/Ox' }
    'InlineFunctionExpansion' = @{ 'Disabled' = '/Ob0'; 'OnlyExplicitInline' = '/Ob1'; 'AnySuitable' = '/Ob2' }
    'RuntimeLibrary' = @{ 'MultiThreaded' = '/MT'; 'MultiThreadedDebug' = '/MTd'; 'MultiThreadedDLL' = '/MD'; 'MultiThreadedDebugDLL' = '/MDd' }
    'LanguageStandard' = @{ 'stdcpp14' = '/std:c++14'; 'stdcpp17' = '/std:c++17'; 'stdcpp20' = '/std:c++20'; 'stdcpplatest' = '/std:c++latest' }
    'ExceptionHandling' = @{ 'false' = $null; 'Async' = '/EHa'; 'Sync' = '/EHsc'; 'SyncCThrow' = '/EHs' }
    'FloatingPointModel' = @{ 'Precise' = '/fp:precise'; 'Strict' = '/fp:strict'; 'Fast' = '/fp:fast' }
    'EnableEnhancedInstructionSet' = @{ 'AdvancedVectorExtensions' = '/arch:AVX'; 'AdvancedVectorExtensions2' = '/arch:AVX2'; 'AdvancedVectorExtensions512' = '/arch:AVX512'; 'StreamingSIMDExtensions' = '/arch:SSE'; 'StreamingSIMDExtensions2' = '/arch:SSE2' }
    'FavorSizeOrSpeed' = @{ 'Size' = '/Os'; 'Speed' = '/Ot'; 'Neither' = $null }
    'DebugInformationFormat' = @{ 'None' = $null; 'OldStyle' = '/Z7'; 'ProgramDatabase' = '/Zi'; 'EditAndContinue' = '/ZI' }
    'BasicRuntimeChecks' = @{ 'StackFrameRuntimeCheck' = '/RTCs'; 'UninitializedLocalUsageCheck' = '/RTCu'; 'EnableFastChecks' = '/RTC1' }
    'CallingConvention' = @{ 'Cdecl' = '/Gd'; 'FastCall' = '/Gr'; 'StdCall' = '/Gz'; 'VectorCall' = '/Gv' }
    'CompileAs' = @{ 'CompileAsC' = '/TC'; 'CompileAsCpp' = '/TP' }

    # Boolean options: (TrueValue, FalseValue) - null means no output for that case
    'FunctionLevelLinking' = @{ TrueVal = '/Gy'; FalseVal = '/Gy-' }
    'StringPooling' = @{ TrueVal = '/GF'; FalseVal = $null }
    'BufferSecurityCheck' = @{ TrueVal = '/GS'; FalseVal = '/GS-' }
    'ControlFlowGuard' = @{ MatchVal = 'Guard'; Result = '/guard:cf' }
    'SupportJustMyCode' = @{ TrueVal = '/JMC'; FalseVal = $null }
    'ConformanceMode' = @{ TrueVal = '/permissive-'; FalseVal = $null }
    'SDLCheck' = @{ TrueVal = '/sdl'; FalseVal = $null }
    'IntrinsicFunctions' = @{ TrueVal = '/Oi'; FalseVal = $null }
    'RuntimeTypeInfo' = @{ TrueVal = '/GR'; FalseVal = '/GR-' }
    'OmitFramePointers' = @{ TrueVal = '/Oy'; FalseVal = '/Oy-' }
    'WholeProgramOptimization' = @{ TrueVal = '/GL'; FalseVal = $null }
    'TreatWarningAsError' = @{ TrueVal = '/WX'; FalseVal = $null }
    'MultiProcessorCompilation' = @{ TrueVal = '/MP'; FalseVal = $null }
    'MinimalRebuild' = @{ TrueVal = '/Gm'; FalseVal = $null }
    'SmallerTypeCheck' = @{ TrueVal = '/RTCc'; FalseVal = $null }

    # Custom handlers
    'DisableSpecificWarnings' = { param($v) ($v -split ';' | ForEach-Object { "/wd$_" }) -join ' ' }
    'TreatSpecificWarningsAsErrors' = { param($v) ($v -split ';' | ForEach-Object { "/we$_" }) -join ' ' }
    'ForcedIncludeFiles' = { param($v) "/FI$v" }
}

# Helper function to convert compiler options to CMake equivalents
function Convert-CompilerOption {
    param(
        [string]$OptionName,
        [string]$OptionValue
    )

    $mapping = $script:CompilerOptionMappings[$OptionName]
    if (-not $mapping) { $null }
    elseif ($mapping -is [scriptblock]) { & $mapping $OptionValue }
    elseif ($mapping.TrueVal -or $mapping.FalseVal) {
        # Boolean option
        if ($OptionValue -eq 'true') { $mapping.TrueVal } else { $mapping.FalseVal }
    }
    elseif ($mapping.MatchVal) {
        # Match-specific option
        if ($OptionValue -eq $mapping.MatchVal) { $mapping.Result } else { $null }
    }
    else {
        # Direct hashtable lookup
        $mapping[$OptionValue]
    }
}

$script:LinkerOptionMappings = @{
    # Map-based lookups
    'GenerateDebugInformation' = @{ 'true' = '/DEBUG'; 'false' = $null; 'DebugFull' = '/DEBUG:FULL'; 'DebugFastLink' = '/DEBUG:FASTLINK' }
    'SubSystem' = @{ 'Console' = '/SUBSYSTEM:CONSOLE'; 'Windows' = '/SUBSYSTEM:WINDOWS'; 'Native' = '/SUBSYSTEM:NATIVE'; 'EFI Application' = '/SUBSYSTEM:EFI_APPLICATION' }
    'LinkTimeCodeGeneration' = @{ 'UseLinkTimeCodeGeneration' = '/LTCG'; 'PGInstrument' = '/LTCG:PGInstrument'; 'PGOptimization' = '/LTCG:PGOptimize'; 'PGUpdate' = '/LTCG:PGUpdate' }

    # Boolean options with both true/false values
    'OptimizeReferences' = @{ TrueVal = '/OPT:REF'; FalseVal = '/OPT:NOREF' }
    'EnableCOMDATFolding' = @{ TrueVal = '/OPT:ICF'; FalseVal = '/OPT:NOICF' }
    'LinkIncremental' = @{ TrueVal = '/INCREMENTAL'; FalseVal = '/INCREMENTAL:NO' }
    'RandomizedBaseAddress' = @{ TrueVal = '/DYNAMICBASE'; FalseVal = '/DYNAMICBASE:NO' }
    'DataExecutionPrevention' = @{ TrueVal = '/NXCOMPAT'; FalseVal = '/NXCOMPAT:NO' }
    'LargeAddressAware' = @{ TrueVal = '/LARGEADDRESSAWARE'; FalseVal = $null }
    'ImageHasSafeExceptionHandlers' = @{ TrueVal = '/SAFESEH'; FalseVal = '/SAFESEH:NO' }
    'Profile' = @{ TrueVal = '/PROFILE'; FalseVal = $null }
    'SetChecksum' = @{ TrueVal = '/RELEASE'; FalseVal = $null }
    'FixedBaseAddress' = @{ TrueVal = '/FIXED'; FalseVal = '/FIXED:NO' }

    # Custom handlers
    'BaseAddress' = { param($v) "/BASE:$v" }
    'ImportLibrary' = { param($v) $v }
    'ModuleDefinitionFile' = { param($v) $v }
    'AdditionalOptions' = { param($v) $v }
}

# Helper function to convert linker options to CMake equivalents
function Convert-LinkerOption {
    param(
        [string]$OptionName,
        [string]$OptionValue
    )

    $mapping = $script:LinkerOptionMappings[$OptionName]
    if (-not $mapping) { $null }
    elseif ($mapping -is [scriptblock]) { & $mapping $OptionValue }
    elseif ($mapping.TrueVal -or $mapping.FalseVal) {
        # Boolean option
        if ($OptionValue -eq 'true') { $mapping.TrueVal } else { $mapping.FalseVal }
    }
    else {
        # Direct hashtable lookup
        $mapping[$OptionValue]
    }
}

# Create a header for processed elements
function New-Header {
    param([string]$HeaderContent)

    return @(
        "# ---------------------------------------------------------------------",
        "# $HeaderContent"
        "# ---------------------------------------------------------------------"
    )
}

# MSBuild function patterns and their replacement handlers
$script:MSBuildFunctionPatterns = @(
    @{
        Pattern = '\$\(\[MSBuild\]::GetDirectoryNameOfFileAbove\(([^,]+),\s*([^\)]+)\)\)'
        Handler = { param($m) '${CMAKE_SOURCE_DIR}' }
    },
    @{
        Pattern = '\$\(\[MSBuild\]::EnsureTrailingSlash\((.+)\)\)'
        Handler = { param ($m) $m.Groups[1].Value.Trim("'`" ") }
    },
    @{
        Pattern = '\$\(\[System\.IO\.Path\]::GetDirectoryName\(([^\)]+)\)\)'
        Handler = { param($m) '$<TARGET_FILE_DIR:${PROJECT_NAME}>' }
    },
    @{
        Pattern = '\$\(\[System\.IO\.Path\]::GetFileName\(([^\)]+)\)\)'
        Handler = { param($m) '$<TARGET_FILE_NAME:${PROJECT_NAME}>' }
    },
    @{
        Pattern = '\$\(\[System\.IO\.Path\]::Combine\(([^,]+),\s*([^\)]+)\)\)'
        Handler = {
            param($m)
            $p1 = Convert-MSBuildVariable -Value $m.Groups[1].Value.Trim()
            $p2 = Convert-MSBuildVariable -Value $m.Groups[2].Value.Trim()
            "${p1}/${p2}"
        }
    }
)

# Helper function to convert MSBuild function calls to CMake equivalents
function Convert-MSBuildFunction {
    param(
        [string]$Value,
        [string]$ProjectDir = ""
    )

    # Recursive helper that applies one pattern replacement at a time
    function Apply-PatternRecursive {
        param([string]$Accumulator, [array]$Patterns)

        # Base case: no patterns left or empty input
        if ([string]::IsNullOrWhiteSpace($Accumulator) -or $Patterns.Count -eq 0) { $Accumulator }
        else {
            $pattern = $Patterns[0]
            $remainingPatterns = $Patterns | Select-Object -Skip 1

            # Apply current pattern recursively until no more matches
            function Apply-SinglePattern {
                param([string]$s)
                $match = [regex]::Match($s, $pattern.Pattern)
                if ($match.Success) {
                    $replacement = & $pattern.Handler $match
                    $newValue = $s.Substring(0, $match.Index) + $replacement + $s.Substring($match.Index + $match.Length)
                    Apply-SinglePattern $newValue  # Recursive call for same pattern
                }
                else { $s }
            }

            $afterCurrentPattern = Apply-SinglePattern $Accumulator
            Apply-PatternRecursive $afterCurrentPattern $remainingPatterns
        }
    }

    Apply-PatternRecursive $Value $script:MSBuildFunctionPatterns
}

# Helper function to convert a build event command to CMake format
# Uses pipeline operations instead of foreach with continue
function Convert-BuildEventCommand {
    param(
        [string]$Command,
        [string]$ProjectDir = ""
    )

    if ([string]::IsNullOrWhiteSpace($Command)) { @() }
    else {
        # Pipeline: convert -> split -> filter empty -> trim -> collect
        $Command |
            ForEach-Object { Convert-MSBuildFunction -Value $_ -ProjectDir $ProjectDir } |
            ForEach-Object { Convert-MSBuildVariable -Value $_ } |
            ForEach-Object { $_ -split "`r?`n" } |
            ForEach-Object { $_.Trim() } |
            Where-Object { -not [string]::IsNullOrWhiteSpace($_) }
    }
}

Export-ModuleMember -Function Convert-MSBuildVariable, Convert-ConditionToCMake, ConvertFrom-MSBuildCondition, `
    Get-DelimitedValues, Convert-CompilerOption, Convert-LinkerOption, New-Header, `
    Convert-MSBuildFunction, Convert-BuildEventCommand