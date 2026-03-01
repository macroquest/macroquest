# ItemDefinitionProcessing.psm1
# Shared ItemDefinitionGroup processing for conversion scripts

# Import required modules
$ModulePath = Split-Path -Parent $PSCommandPath
Import-Module (Join-Path $ModulePath "ConversionCommon.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "GeneratorExpressions.psm1") -Force -Global

# Script-level option name arrays (shared between converters)
$script:CompilerOptionNames = @(
    'WarningLevel', 'Optimization', 'RuntimeLibrary', 'LanguageStandard', 'MultiProcessorCompilation',
    'BufferSecurityCheck', 'InlineFunctionExpansion', 'FunctionLevelLinking', 'StringPooling',
    'DebugInformationFormat', 'SupportJustMyCode', 'ConformanceMode', 'SDLCheck', 'IntrinsicFunctions',
    'RuntimeTypeInfo', 'ExceptionHandling', 'FloatingPointModel', 'EnableEnhancedInstructionSet',
    'WholeProgramOptimization', 'FavorSizeOrSpeed', 'OmitFramePointers', 'TreatWarningAsError',
    'DisableSpecificWarnings', 'TreatSpecificWarningsAsErrors', 'CallingConvention',
    'SmallerTypeCheck', 'BasicRuntimeChecks', 'ControlFlowGuard', 'MinimalRebuild',
    'ForcedIncludeFiles'
)

$script:LinkerOptionNames = @(
    'GenerateDebugInformation', 'SubSystem', 'OptimizeReferences', 'EnableCOMDATFolding',
    'LinkIncremental', 'RandomizedBaseAddress', 'DataExecutionPrevention', 'LargeAddressAware',
    'LinkTimeCodeGeneration', 'ImageHasSafeExceptionHandlers', 'Profile', 'SetChecksum',
    'FixedBaseAddress', 'BaseAddress'
)

# Helper to get text value from an XmlElement or string
function Get-XmlTextValue {
    param($Element)

    if ($Element -is [System.Xml.XmlElement]) {
        $Element.InnerText
    } elseif ($Element -is [string]) {
        $Element
    } else {
        "$Element"
    }
}

# Helper to process XML elements that may be arrays with conditions
function Process-ConditionalElements {
    param(
        [object]$Elements,
        [array]$ParentCondition,
        [hashtable]$TargetHash,
        [string[]]$ExcludePatterns = @(),
        [string]$Delimiter = ';',
        [switch]$ForPropsFile,
        [string]$PropsName,
        [scriptblock]$ValueConverter = $null
    )

    # Normalize to array
    $elemArray = @($Elements)

    foreach ($elem in $elemArray) {
        # Get text value and element-specific condition
        if ($elem -is [System.Xml.XmlElement]) {
            $textValue = $elem.InnerText
            $elemCondition = @($ParentCondition)
            if ($elem.Condition) {
                $elemCondition += $elem.Condition
            }
        } else {
            $textValue = "$elem"
            $elemCondition = @($ParentCondition)
        }

        # Skip empty values
        if ([string]::IsNullOrWhiteSpace($textValue)) { continue }

        # Parse delimited values
        $values = Get-DelimitedValues -Value $textValue -ExcludePatterns $ExcludePatterns -Delimiter $Delimiter

        foreach ($val in $values) {
            # Apply optional value converter
            $finalValue = if ($ValueConverter) {
                & $ValueConverter $val
            } else {
                Convert-MSBuildVariable -Value $val -ForPropsFile:$ForPropsFile -PropsName $PropsName
            }

            # Handle converters that return multiple values (space-separated)
            $finalValues = if ($finalValue -match ' ' -and $Delimiter -ne ' ') {
                $finalValue -split ' ' | Where-Object { $_ }
            } else {
                @($finalValue)
            }

            foreach ($fv in $finalValues) {
                if (-not [string]::IsNullOrWhiteSpace($fv)) {
                    if (-not $TargetHash.ContainsKey($fv)) {
                        $TargetHash[$fv] = @()
                    }
                    $TargetHash[$fv] += $elemCondition
                }
            }
        }
    }
}

# Helper to collect options from ClCompile element
function Collect-CompilerSettings {
    param(
        [System.Xml.XmlElement]$CompileElement,
        [array]$Condition,
        [hashtable]$PreprocessorDefs,
        [hashtable]$IncludeDirs,
        [hashtable]$CompileOptions,
        [switch]$ForPropsFile,
        [string]$PropsName
    )

    # Collect preprocessor definitions
    if ($CompileElement.PreprocessorDefinitions) {
        Process-ConditionalElements `
            -Elements $CompileElement.PreprocessorDefinitions `
            -ParentCondition $Condition `
            -TargetHash $PreprocessorDefs `
            -ExcludePatterns @('%\(PreprocessorDefinitions\)') `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }

    # Collect include directories
    if ($CompileElement.AdditionalIncludeDirectories) {
        Process-ConditionalElements `
            -Elements $CompileElement.AdditionalIncludeDirectories `
            -ParentCondition $Condition `
            -TargetHash $IncludeDirs `
            -ExcludePatterns @('%\(AdditionalIncludeDirectories\)', '\$\(AdditionalIncludeDirectories\)') `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }

    # Collect compiler options from named option elements
    foreach ($optName in $script:CompilerOptionNames) {
        $optElements = $CompileElement.$optName
        if ($optElements) {
            $elemArray = @($optElements)
            foreach ($elem in $elemArray) {
                # Get text value and element-specific condition
                if ($elem -is [System.Xml.XmlElement]) {
                    $optValue = $elem.InnerText
                    $elemCondition = @($Condition)
                    if ($elem.Condition) {
                        $elemCondition += $elem.Condition
                    }
                } else {
                    $optValue = "$elem"
                    $elemCondition = @($Condition)
                }

                $converted = Convert-CompilerOption -OptionName $optName -OptionValue $optValue
                if ($converted) {
                    # Handle options that return multiple values (space-separated like /wd4018 /wd4244)
                    $convertedValues = $converted -split ' ' | Where-Object { $_ }
                    foreach ($cv in $convertedValues) {
                        if (-not $CompileOptions.ContainsKey($cv)) {
                            $CompileOptions[$cv] = @()
                        }
                        $CompileOptions[$cv] += $elemCondition
                    }
                }
            }
        }
    }

    # Collect AdditionalOptions
    if ($CompileElement.AdditionalOptions) {
        Process-ConditionalElements `
            -Elements $CompileElement.AdditionalOptions `
            -ParentCondition $Condition `
            -TargetHash $CompileOptions `
            -ExcludePatterns @('%\(AdditionalOptions\)') `
            -Delimiter ' ' `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }
}

# Helper to collect options from Link element
function Collect-LinkerSettings {
    param(
        [System.Xml.XmlElement]$LinkElement,
        [array]$Condition,
        [hashtable]$LibDirs,
        [hashtable]$LinkLibraries,
        [hashtable]$LinkOptions,
        [switch]$ForPropsFile,
        [string]$PropsName
    )

    # Collect library directories
    if ($LinkElement.AdditionalLibraryDirectories) {
        Process-ConditionalElements `
            -Elements $LinkElement.AdditionalLibraryDirectories `
            -ParentCondition $Condition `
            -TargetHash $LibDirs `
            -ExcludePatterns @('%\(AdditionalLibraryDirectories\)') `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }

    # Collect additional dependencies
    if ($LinkElement.AdditionalDependencies) {
        Process-ConditionalElements `
            -Elements $LinkElement.AdditionalDependencies `
            -ParentCondition $Condition `
            -TargetHash $LinkLibraries `
            -ExcludePatterns @('%\(AdditionalDependencies\)') `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }

    # Collect linker options from named option elements
    foreach ($optName in $script:LinkerOptionNames) {
        $optElements = $LinkElement.$optName
        if ($optElements) {
            $elemArray = @($optElements)
            foreach ($elem in $elemArray) {
                # Get text value and element-specific condition
                if ($elem -is [System.Xml.XmlElement]) {
                    $optValue = $elem.InnerText
                    $elemCondition = @($Condition)
                    if ($elem.Condition) {
                        $elemCondition += $elem.Condition
                    }
                } else {
                    $optValue = "$elem"
                    $elemCondition = @($Condition)
                }

                $converted = Convert-LinkerOption -OptionName $optName -OptionValue $optValue
                if ($converted) {
                    # Handle options that return multiple values (space-separated)
                    $convertedValues = $converted -split ' ' | Where-Object { $_ }
                    foreach ($cv in $convertedValues) {
                        if (-not $LinkOptions.ContainsKey($cv)) {
                            $LinkOptions[$cv] = @()
                        }
                        $LinkOptions[$cv] += $elemCondition
                    }
                }
            }
        }
    }

    # Collect AdditionalOptions
    if ($LinkElement.AdditionalOptions) {
        Process-ConditionalElements `
            -Elements $LinkElement.AdditionalOptions `
            -ParentCondition $Condition `
            -TargetHash $LinkOptions `
            -ExcludePatterns @('%\(AdditionalOptions\)') `
            -Delimiter ' ' `
            -ForPropsFile:$ForPropsFile `
            -PropsName $PropsName
    }
}

# Generate library file patterns for vcpkg package filtering
function Get-VcpkgLibraryPatterns {
    param([string[]]$PackageNames)

    # Mapping of vcpkg package names to their library file patterns
    $vcpkgLibraryMap = @{
        'fmt'       = @('^fmt\.lib$', '^fmtd\.lib$')
        'protobuf'  = @('^libprotobuf\.lib$', '^libprotobufd\.lib$', '^libprotobuf-lite\.lib$', '^libprotobuf-lited\.lib$')
        'lua'       = @('^lua\d*\.lib$', '^luad\d*\.lib$', '^lua51\.lib$')
        'luajit'    = @('^lua\d*\.lib$', '^luad\d*\.lib$', '^lua51\.lib$')
        'sqlite3'   = @('^sqlite3\.lib$', '^sqlite3d\.lib$')
        'zlib'      = @('^zlib\.lib$', '^zlibd\.lib$', '^zlibstatic\.lib$', '^zlibstaticd\.lib$')
        'yaml-cpp'  = @('^yaml-cpp\.lib$', '^yaml-cppd\.lib$')
        'sol2'      = @()  # Header-only
        'wil'       = @()  # Header-only
        'freetype'  = @('^freetype\.lib$', '^freetyped\.lib$')
        'glm'       = @()  # Header-only
        'cpr'       = @('^cpr\.lib$', '^cprd\.lib$')
        'curl'      = @('^libcurl.*\.lib$', '^curl\.lib$')
        'openssl'   = @('^libcrypto\.lib$', '^libssl\.lib$')
        'argon2'    = @('^argon2\.lib$', '^argon2d\.lib$', '^libargon2\.lib$')
        'crashpad'  = @('^crashpad.*\.lib$', '^base\.lib$', '^common\.lib$', '^client\.lib$', '^util\.lib$')
        'dxsdk-d3dx' = @('^d3dx9.*\.lib$', '^d3dx10.*\.lib$', '^d3dx11.*\.lib$')
        'pe-parse'  = @('^pe-parse\.lib$')
    }

    $PackageNames | ForEach-Object {
        $pkgLower = $_.ToLower()

        if ($vcpkgLibraryMap.ContainsKey($pkgLower)) {
            $vcpkgLibraryMap[$pkgLower]
        } else {
            # Generate default patterns for unknown packages
            $escaped = [regex]::Escape($pkgLower)
            @("^${escaped}\.lib$", "^${escaped}d\.lib$", "^lib${escaped}\.lib$", "^lib${escaped}d\.lib$")
        }
    } | Where-Object { $_ }
}

# Process all ItemDefinitionGroup elements (shared implementation)
function Convert-AllItemDefinitionGroups {
    param(
        [System.Xml.XmlElement[]]$ItemDefGroupElements,
        [string]$TargetName,
        [switch]$ForPropsFile,
        [string]$PropsName = "",
        [switch]$MultiBuild,
        [string[]]$VcpkgDependencies = @()
    )

    # Collections for grouping settings
    $preprocessorDefs = @{}
    $preprocessorDefsRC = @{}
    $includeDirs = @{}
    $includeDirsRC = @{}
    $compileOptions = @{}
    $compileOptionsRC = @{}
    $libDirs = @{}
    $linkLibraries = @{}
    $linkOptions = @{}

    # First pass: collect all settings
    foreach ($group in $ItemDefGroupElements) {
        $groupCondition = $group.Condition

        # Process ClCompile settings
        foreach ($compile in $group.ClCompile) {
            $elementCondition = $compile.Condition
            $condition = @()
            if ($groupCondition) { $condition += $groupCondition }
            if ($elementCondition) { $condition += $elementCondition }

            Collect-CompilerSettings `
                -CompileElement $compile `
                -Condition $condition `
                -PreprocessorDefs $preprocessorDefs `
                -IncludeDirs $includeDirs `
                -CompileOptions $compileOptions `
                -ForPropsFile:$ForPropsFile `
                -PropsName $PropsName
        }

        # Process Link settings
        foreach ($link in $group.Link) {
            $elementCondition = $link.Condition
            $condition = @()
            if ($groupCondition) { $condition += $groupCondition }
            if ($elementCondition) { $condition += $elementCondition }

            Collect-LinkerSettings `
                -LinkElement $link `
                -Condition $condition `
                -LibDirs $libDirs `
                -LinkLibraries $linkLibraries `
                -LinkOptions $linkOptions `
                -ForPropsFile:$ForPropsFile `
                -PropsName $PropsName
        }

        # Process ResourceCompile settings
        foreach ($rc in $group.ResourceCompile) {
            $elementCondition = $rc.Condition
            $condition = @()
            if ($groupCondition) { $condition += $groupCondition }
            if ($elementCondition) { $condition += $elementCondition }

            Collect-CompilerSettings `
                -CompileElement $rc `
                -Condition $condition `
                -PreprocessorDefs $preprocessorDefsRC `
                -IncludeDirs $includeDirsRC `
                -CompileOptions $compileOptionsRC `
                -ForPropsFile:$ForPropsFile `
                -PropsName $PropsName
        }
    }

    # Filter vcpkg includes from include directories
    foreach ($include in @($includeDirs.Keys)) {
        if ($include -match 'contrib.vcpkg.installed') {
            $includeDirs.Remove($include)
        }
    }

    # Filter vcpkg libraries (vcxproj mode only)
    if ($VcpkgDependencies.Count -gt 0) {
        $vcpkgLibPatterns = Get-VcpkgLibraryPatterns -PackageNames $VcpkgDependencies
        if ($vcpkgLibPatterns.Count -gt 0) {
            $librariesToRemove = @()
            foreach ($libKey in @($linkLibraries.Keys)) {
                foreach ($pattern in $vcpkgLibPatterns) {
                    if ($libKey -match $pattern) {
                        $librariesToRemove += $libKey
                        Write-Verbose "Filtering vcpkg library: $libKey (matched pattern: $pattern)"
                        break
                    }
                }
            }
            foreach ($lib in $librariesToRemove) {
                $linkLibraries.Remove($lib)
            }
            if ($librariesToRemove.Count -gt 0) {
                Write-Host "  Filtered $($librariesToRemove.Count) vcpkg-provided libraries from link dependencies" -ForegroundColor Cyan
            }
        }
    }

    # Determine environments where properties are valid
    $preprocessorDefs = Clear-ListedProperties -Properties $preprocessorDefs -MultiBuild:$MultiBuild
    $preprocessorDefsRC = Clear-ListedProperties -Properties $preprocessorDefsRC -MultiBuild:$MultiBuild
    $includeDirs = Clear-ListedProperties -Properties $includeDirs -MultiBuild:$MultiBuild
    $includeDirsRC = Clear-ListedProperties -Properties $includeDirsRC -MultiBuild:$MultiBuild
    $compileOptions = Clear-ListedProperties -Properties $compileOptions -MultiBuild:$MultiBuild
    $compileOptionsRC = Clear-ListedProperties -Properties $compileOptionsRC -MultiBuild:$MultiBuild
    $libDirs = Clear-ListedProperties -Properties $libDirs -MultiBuild:$MultiBuild
    $linkLibraries = Clear-ListedProperties -Properties $linkLibraries -MultiBuild:$MultiBuild
    $linkOptions = Clear-ListedProperties -Properties $linkOptions -MultiBuild:$MultiBuild

    # Second pass: generate CMake code
    $output = @()
    $linkerOutput = @()

    # Props files use grouped headers, vcxproj uses per-section headers
    $compilerHeaderAdded = $false
    $linkerHeaderAdded = $false

    # Generate preprocessor definitions
    if ($preprocessorDefs.Count -gt 0) {
        if ($ForPropsFile -and -not $compilerHeaderAdded) {
            $output += New-Header -HeaderContent "Compiler settings"
            $compilerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $output += New-Header -HeaderContent "Preprocessor definitions"
        }

        if ($ForPropsFile) { $output += "# Preprocessor definitions" }
        $output += "target_compile_definitions($TargetName PRIVATE"
        foreach ($def in $preprocessorDefs.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $def.Name -Entries $def.Value
            $output += "    `"$expression`""
        }

        # small hack here, but zep needs NOGDI
        if ($TargetName -eq 'zep') {
            $output += "    `"NOGDI`""
        }

        $output += ")"
        $output += ""
    }

    if ($preprocessorDefsRC.Count -gt 0) {
        $output += New-Header -HeaderContent "Preprocessor (RC) definitions"
        $output += "target_compile_definitions($TargetName PRIVATE"
        foreach ($def in $preprocessorDefsRC.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $def.Name -Entries $def.Value
            $output += "    `"$expression`""
        }
        $output += ")"
        $output += ""
    }

    # Generate include directories
    if ($includeDirs.Count -gt 0) {
        if ($ForPropsFile -and -not $compilerHeaderAdded) {
            $output += New-Header -HeaderContent "Compiler settings"
            $compilerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $output += New-Header -HeaderContent "Include directories"
        }

        if ($ForPropsFile) { $output += "# Include directories" }
        $output += "target_include_directories($TargetName PRIVATE"
        foreach ($include in $includeDirs.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $include.Name -Entries $include.Value
            $output += "    `"$expression`""
        }
        $output += ")"
        $output += ""
    }

    if ($includeDirsRC.Count -gt 0) {
        $output += New-Header -HeaderContent "Include (RC) directories"
        $output += "target_include_directories($TargetName PRIVATE"
        foreach ($include in $includeDirsRC.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $include.Name -Entries $include.Value
            $output += "    `"$expression`""
        }
        $output += ")"
        $output += ""
    }

    # Generate compiler options
    if ($compileOptions.Count -gt 0) {
        if ($ForPropsFile -and -not $compilerHeaderAdded) {
            $output += New-Header -HeaderContent "Compiler settings"
            $compilerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $output += New-Header -HeaderContent "Compiler options"
        }

        if ($ForPropsFile) { $output += "# Compiler options" }
        $output += "target_compile_options($TargetName PRIVATE"
        foreach ($opt in $compileOptions.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $opt.Name -Entries $opt.Value
            $output += "    `"$expression`""
        }
        $output += ")"
        $output += ""
    }

    if ($compileOptionsRC.Count -gt 0) {
        $output += New-Header -HeaderContent "Compiler (RC) options"
        $output += "target_compile_options($TargetName PRIVATE"
        foreach ($opt in $compileOptionsRC.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $opt.Name -Entries $opt.Value
            $output += "    `"$expression`""
        }
        $output += ")"
        $output += ""
    }

    # Generate library directories
    if ($libDirs.Count -gt 0) {
        if ($ForPropsFile -and -not $linkerHeaderAdded) {
            $linkerOutput += New-Header -HeaderContent "Linker settings"
            $linkerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $linkerOutput += New-Header -HeaderContent "Library directories"
        }

        if ($ForPropsFile) { $linkerOutput += "# Library directories" }
        $linkerOutput += "target_link_directories($TargetName PRIVATE"
        foreach ($dir in $libDirs.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $dir.Name -Entries $dir.Value
            $linkerOutput += "    `"$expression`""
        }
        $linkerOutput += ")"
        $linkerOutput += ""
    }

    # Generate link libraries
    if ($linkLibraries.Count -gt 0) {
        if ($ForPropsFile -and -not $linkerHeaderAdded) {
            $linkerOutput += New-Header -HeaderContent "Linker settings"
            $linkerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $linkerOutput += New-Header -HeaderContent "Link libraries"
        }

        if ($ForPropsFile) { $linkerOutput += "# Additional dependencies" }
        $linkerOutput += "target_link_libraries($TargetName PRIVATE"
        foreach ($lib in $linkLibraries.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $lib.Name -Entries $lib.Value
            $linkerOutput += "    `"$expression`""
        }
        $linkerOutput += ")"
        $linkerOutput += ""
    }

    # Generate linker options
    if ($linkOptions.Count -gt 0) {
        if ($ForPropsFile -and -not $linkerHeaderAdded) {
            $linkerOutput += New-Header -HeaderContent "Linker settings"
            $linkerHeaderAdded = $true
        } elseif (-not $ForPropsFile) {
            $linkerOutput += New-Header -HeaderContent "Linker options"
        }

        if ($ForPropsFile) { $linkerOutput += "# Linker options" }
        $linkerOutput += "target_link_options($TargetName PRIVATE"
        foreach ($opt in $linkOptions.GetEnumerator()) {
            $expression = Join-OptionsWithGeneratorExpressions -OptionName $opt.Name -Entries $opt.Value
            $linkerOutput += "    `"$expression`""
        }
        $linkerOutput += ")"
        $linkerOutput += ""
    }

    # Return result (props uses combined output, vcxproj uses hashtable for additional data)
    if ($ForPropsFile) {
        if ($output -or $linkerOutput) {
            $output + $linkerOutput + " "
        } else {
            @()
        }
    } else {
        @{
            Output = $output + $linkerOutput
        }
    }
}

Export-ModuleMember -Function Convert-AllItemDefinitionGroups, Get-VcpkgLibraryPatterns