# GeneratorExpressions.psm1
# Shared generator expression builders for CMake conversion

# Import ConversionCommon for variable conversion
$ModulePath = Split-Path -Parent $PSCommandPath
Import-Module (Join-Path $ModulePath "ConversionCommon.psm1") -Force -Global

# Helper function to detect if condition uses Configuration or ConfigurationType
function Test-NeedsGeneratorExpression {
    param([string]$Condition)

    -not [string]::IsNullOrWhiteSpace($Condition) -and (
        ($Condition -match '\$\(Configuration[\.)]') -or
        ($Condition -match '\$\(ConfigurationType[\.)]') -or
        ($Condition -match 'MQConfig') -or
        ($Condition -match 'MQStaticBuild')
    )
}

# Helper function to generate generator expression for ConfigurationType-based conditions
function New-ConfigTypeGeneratorExpression {
    param(
        [string]$PropertyName,
        [array]$Entries,
        [string]$PropsName = ""
    )

    if ($Entries | Where-Object { $_.Condition -match '-Static' }) {
        $staticEntry = $Entries | Where-Object { $_.Condition -match '-Static' } | Select-Object -First 1
        $sharedEntry = $Entries | Where-Object { $_.Condition -notmatch '-Static' } | Select-Object -First 1

        $staticValue = Convert-MSBuildVariable -Value $staticEntry.Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName
        $sharedValue = Convert-MSBuildVariable -Value $sharedEntry.Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName

        "`"`$<IF:`$<BOOL:`${MQ_STATIC_BUILD}>,$staticValue,$sharedValue>`""
    } else {
        $PropertyName
    }
}

# Helper function to generate generator expression for Configuration-based conditions
function New-ConfigGeneratorExpression {
    param(
        [array]$Entries,
        [string]$PropsName = "",
        [string]$DefaultValue = ""
    )

    $debugEntry = $Entries | Where-Object { $_.Condition -match "Debug" } | Select-Object -First 1
    $releaseEntry = $Entries | Where-Object { $_.Condition -match "Release" } | Select-Object -First 1

    # Use default value if Debug or Release entry is missing
    $debugRawValue = if ($debugEntry) { $debugEntry.Value } else { $DefaultValue }
    $releaseRawValue = if ($releaseEntry) { $releaseEntry.Value } else { $DefaultValue }

    $debugValue = Convert-MSBuildVariable -Value $debugRawValue -ForPropsFile:($PropsName -ne "") -PropsName $PropsName
    $releaseValue = Convert-MSBuildVariable -Value $releaseRawValue -ForPropsFile:($PropsName -ne "") -PropsName $PropsName

    "`"`$<IF:`$<CONFIG:Debug>,$debugValue,$releaseValue>`""
}

# Helper function to generate if...elseif...endif block
function New-IfElseBlock {
    param(
        [string]$PropertyName,
        [array]$Entries,
        [string]$PropsName = ""
    )

    # Recursive helper to process entries and build result
    function Process-Entry {
        param([array]$Remaining, [array]$Accumulator, [bool]$IsFirst)

        if ($Remaining.Count -eq 0) {
            # Base case: add endif if we had conditionals
            if (-not $IsFirst) { $Accumulator + @("endif()") }
            else { $Accumulator }
        }
        else {
            $entry = $Remaining[0]
            $rest = $Remaining | Select-Object -Skip 1
            $convertedValue = Convert-MSBuildVariable -Value $entry.Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName

            $newLines = if ($entry.Condition) {
                $cmakeCondition = Convert-ConditionToCMake $entry.Condition
                if ($IsFirst) {
                    @("$cmakeCondition", "    set($PropertyName `"$convertedValue`")")
                }
                else {
                    $elseifCondition = $cmakeCondition -replace '^if\(', 'elseif('
                    @("$elseifCondition", "    set($PropertyName `"$convertedValue`")")
                }
            }
            else {
                # No condition - default case
                if ($IsFirst) { @("set($PropertyName `"$convertedValue`")") }
                else { @("else()", "    set($PropertyName `"$convertedValue`")") }
            }

            $newIsFirst = $IsFirst -and (-not $entry.Condition)
            Process-Entry -Remaining $rest -Accumulator ($Accumulator + $newLines) -IsFirst $newIsFirst
        }
    }

    Process-Entry -Remaining $Entries -Accumulator @() -IsFirst $true
}

# Generate static/shared build conditionals
function New-StaticGeneratorExpression {
    param(
        [array]$Entries,
        [scriptblock]$InnerGenerator
    )

    $hasStatic = $Entries | Where-Object { $_.Condition -match '-Static' }

    if ($hasStatic) {
        $staticEntries = $Entries | Where-Object { $_.Condition -match '-Static' }
        $sharedEntries = $Entries | Where-Object { $_.Condition -notmatch '-Static' }

        $staticBlock = @("if(MQ_STATIC_BUILD)") +
            (&$InnerGenerator -InnerEntries $staticEntries | ForEach-Object { "    $_" })

        $sharedBlock = if ($sharedEntries) {
            @("else()") + (&$InnerGenerator -InnerEntries $sharedEntries | ForEach-Object { "    $_" })
        } else { @() }

        $staticBlock + $sharedBlock + @("endif()")
    }
    else {
        &$InnerGenerator -InnerEntries $Entries
    }
}

# Helper function to generate platform-specific generator expressions
function New-PlatformGeneratorExpression {
    param(
        [array]$Entries,
        [scriptblock]$InnerGenerator
    )

    $x64 = $Entries | Where-Object { $_.Condition -match "x64" }
    $win32 = $Entries | Where-Object { $_.Condition -match "Win32" }

    # Helper to indent block
    $Indent = { param($lines) $lines | ForEach-Object { "    $_" } }

    # Pattern-match on platform combinations
    $hasBoth = $x64 -and $win32
    $hasX64Only = $x64 -and -not $win32
    $hasWin32Only = $win32 -and -not $x64

    if ($hasBoth) {
        @('if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")') +
            (& $Indent (New-StaticGeneratorExpression -Entries $x64 -InnerGenerator $InnerGenerator)) +
            @('elseif(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")') +
            (& $Indent (New-StaticGeneratorExpression -Entries $win32 -InnerGenerator $InnerGenerator)) +
            @('endif()')
    }
    elseif ($hasX64Only) {
        @('if(CMAKE_GENERATOR_PLATFORM STREQUAL "x64")') +
            (& $Indent (New-StaticGeneratorExpression -Entries $x64 -InnerGenerator $InnerGenerator)) +
            @('endif()')
    }
    elseif ($hasWin32Only) {
        @('if(CMAKE_GENERATOR_PLATFORM STREQUAL "Win32")') +
            (& $Indent (New-StaticGeneratorExpression -Entries $win32 -InnerGenerator $InnerGenerator)) +
            @('endif()')
    }
    else {
        New-StaticGeneratorExpression -Entries $Entries -InnerGenerator $InnerGenerator
    }
}

# Combine properties with generator expressions (for PropertyGroups)
# This unifies Generate-ConfigurationProperties, Generate-ConfigTypeGeneratorExpression, and Generate-IfElseBlock
function Join-PropertiesWithGeneratorExpression {
    param(
        [string]$PropertyName,
        [array]$Entries,
        [string]$PropsName = ""
    )

    function Generate-ConfigSet {
        param([array]$InnerEntries)

        $debugEntry = $InnerEntries | Where-Object { $_.Condition -match "Debug" } | Select-Object -First 1
        $releaseEntry = $InnerEntries | Where-Object { $_.Condition -match "Release" } | Select-Object -First 1

        $debugValue = Convert-MSBuildVariable -Value $debugEntry.Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName
        $releaseValue = Convert-MSBuildVariable -Value $releaseEntry.Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName

        if ($PropertyName -eq 'LinkIncremental') {
            # Special handling for LinkIncremental (linker option in PropertyGroup)
            $debugValueIncr = if ($debugValue -eq 'true') { '' } else { ':NO' }
            $releaseValueIncr = if ($releaseValue -eq 'true') { '' } else { ':NO' }

            $expression = if ($debugValue -and $releaseValue) {
                "`$<IF:`$<CONFIG:Debug>,/INCREMENTAL$debugValueIncr,/INCREMENTAL$releaseValueIncr>"
            } elseif ($debugValue) {
                "`$<`$<CONFIG:Debug>:/INCREMENTAL$debugValueIncr>"
            } elseif ($releaseValue) {
                "`$<`$<CONFIG:Release>:/INCREMENTAL$releaseValueIncr>"
            } else {
                $value = Convert-MSBuildVariable -Value $($InnerEntries | Select-Object -First 1).Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName
                if ($value -eq 'true') { '/INCREMENTAL' } else { '/INCREMENTAL:NO' }
            }

            "target_link_options(`${TARGET_NAME} PRIVATE `"$expression`")"
        } else {
            $expression = if ($debugValue -and $releaseValue) {
                "`$<IF:`$<CONFIG:Debug>,$debugValue,$releaseValue>"
            } elseif ($debugValue) {
                "`$<`$<CONFIG:Debug>:$debugValue>"
            } elseif ($releaseValue) {
                "`$<`$<CONFIG:Release>:$releaseValue>"
            } else {
                Convert-MSBuildVariable -Value $($InnerEntries | Select-Object -First 1).Value -ForPropsFile:($PropsName -ne "") -PropsName $PropsName
            }

            "set($PropertyName `"$expression`")"
        }
    }

    if ($Entries | Where-Object { $_.Condition -match '\$\(Platform\)' }) {
        # Platform-specific entries
        New-PlatformGeneratorExpression -Entries $Entries -InnerGenerator ${function:Generate-ConfigSet}
    } else {
        # No platform specified
        New-StaticGeneratorExpression -Entries $Entries -InnerGenerator ${function:Generate-ConfigSet}
    }
}

# Helper function to combine options with generator expressions (for ItemDefinitionGroups)
function Join-OptionsWithGeneratorExpressions {
    param(
        [string]$OptionName,
        [Tuple[string, string, string]]$Entries
    )

    # If there is a single entry without a condition, it will always be selected
    if (-not $Entries) {
        $OptionName
    } else {
        # helper functions to generate the expression from the tuple(Platform, Configuration, Static)
        function Generate-ConfigExpression {
            param ([string]$Configuration)

            if (-not [string]::IsNullOrWhitespace($Configuration)) {
                "`$<`$<CONFIG:$Configuration>:$OptionName>"
            } else {
                $OptionName
            }
        }

        function Generate-StaticExpression {
            param ([tuple[string, string]]$ConfigStatic)
            $config = Generate-ConfigExpression -Configuration $ConfigStatic.Item1

            if ($ConfigStatic.Item2 -eq 'Static') {
                "`$<`$<BOOL:`${MQ_STATIC_BUILD}>:$config>"
            } elseif ($ConfigStatic.Item2 -eq 'Shared') {
                "`$<`$<NOT:`$<BOOL:`${MQ_STATIC_BUILD}>>:$config>"
            } else {
                $config
            }
        }

        function Generate-PlatformExpression {
            param([tuple[string, string, string]]$PlatformConfigStatic)
            $configStatic = Generate-StaticExpression -ConfigStatic $([Tuple]::Create(
                $PlatformConfigStatic.Item2, $PlatformConfigStatic.Item3
            ))

            if (-not [string]::IsNullOrWhitespace($PlatformConfigStatic.Item1)) {
                "`$<`$<STREQUAL:`${CMAKE_GENERATOR_PLATFORM},$($PlatformConfigStatic.Item1)>:$configStatic>"
            } else {
                $configStatic
            }
        }

        Generate-PlatformExpression -PlatformConfigStatic $Entries
    }
}

# Clean listed properties by removing redundant conditions
function Clear-ListedProperties {
    param (
        [hashtable]$Properties,
        [switch]$MultiBuild
    )

    foreach ($prop in @($Properties.Keys)) {
        $entries = $Properties[$prop]

        if ($entries | Where-Object { [string]::IsNullOrWhiteSpace($_)}) {
            # short-circuit this because if any single entry has no condition, then that's necessarily
            # the least number of conditions
            $Properties[$prop] = $null
        } else {
            # Parse each condition into structured components
            $conditionMaps = @()
            class Conditions {
                [string]$Platform
                [string]$Configuration
                [string]$Static
            }

            foreach ($entry in $entries) {
                $conditionMap = [Conditions]::new()
                # Parse conditions in format: x==y or x|a==y|b
                if ($entry -match "(.+)==(.+)")
                {
                    $leftSide = $matches[1].Trim("`"' ")
                    $rightSide = $matches[2].Trim("`"' ")

                    # Split compound conditions by pipe
                    $leftParts = @($leftSide -split '\|' | ForEach-Object { $_.Trim("`"' `$()") })
                    $rightParts = @($rightSide -split '\|' | ForEach-Object { $_.Trim("`"' `$()") })

                    if ($leftParts.Count -ne $rightParts.Count) {
                        Write-Host "Could not parse condition `"$entry`" in Clear-ListedProperties" -ForegroundColor Yellow
                    } else {
                        # Process each part of the condition
                        for ($i = 0; $i -lt $leftParts.Count; $i++) {
                            $left = $leftParts[$i]
                            $right = $rightParts[$i]

                            # Classify the condition type
                            if ($left -eq 'Platform') {
                                $conditionMap.Platform = $right
                            } elseif ($left -eq 'Configuration') {
                                # Check for -Static suffix
                                if ($right -match '^(.+)-Static$') {
                                    $conditionMap.Static = 'Static'
                                    $conditionMap.Configuration = $matches[1]
                                } else {
                                    $conditionMap.Static = 'Shared'
                                    $conditionMap.Configuration = $right
                                }
                            } elseif ($left -eq 'MQConfig') {
                                # MQConfig applies to both static and shared
                                $conditionMap.Configuration = $right
                                # Static remains null for MQConfig
                            } elseif ($left -eq 'MQStaticBuild') {
                                if ($right -eq 'true') {
                                    $conditionMap.Static = 'Static'
                                } else {
                                    $conditionMap.Static = 'Shared'
                                }
                            }
                        }
                    }
                } elseif ($entry -match "Configuration\.StartsWith\(([^\)]+)\)") {
                    $conditionMap.Configuration = $matches[1].Trim("`"' ")
                }

                $conditionMaps += $conditionMap
            }

            # Collect unique values for each dimension
            $allPlatforms = $conditionMaps | ForEach-Object { $_.Platform } | Where-Object { $_ -ne $null } | Select-Object -Unique
            $allConfigurations = $conditionMaps | ForEach-Object { $_.Configuration } | Where-Object { $_ -ne $null } | Select-Object -Unique
            $allStatics = $conditionMaps | ForEach-Object { $_.Static } | Where-Object { $_ -ne $null } | Select-Object -Unique

            # Determine which dimensions to remove (if all standard variants are present)
            foreach ($cm in $conditionMaps) {
                if ($('x64' -in $allPlatforms) -and $('Win32' -in $allPlatforms)) {
                    $cm.Platform = $null
                }

                if ($('Debug' -in $allConfigurations) -and $('Release' -in $allConfigurations)) {
                    $cm.Configuration = $null
                }

                if ($('Static' -in $allStatics) -and $('Shared' -in $allStatics)) {
                    $cm.Static = $null
                } elseif (-not $MultiBuild) {
                    # if not multi-build, just remove this
                    $cm.Static = $null
                }
            }

            # There is guaranteed to be a single unique entry here
            $Properties[$prop] = $conditionMaps | Select-Object * -Unique | ForEach-Object {
                if ($_.Platform -or $_.Configuration -or $_.Static) {
                    [Tuple[string, string, string]]::new($_.Platform, $_.Configuration, $_.Static)
                } else {
                    $null
                }
            } | Select-Object -First 1
        }
    }

    $Properties
}

Export-ModuleMember -Function Test-NeedsGeneratorExpression, New-ConfigTypeGeneratorExpression, `
    New-ConfigGeneratorExpression, New-IfElseBlock, `
    New-PlatformGeneratorExpression, New-StaticGeneratorExpression, `
    Join-PropertiesWithGeneratorExpression, Join-OptionsWithGeneratorExpressions, Clear-ListedProperties