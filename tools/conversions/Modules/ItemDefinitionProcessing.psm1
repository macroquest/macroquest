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
        $defs = Get-DelimitedValues -Value $CompileElement.PreprocessorDefinitions -ExcludePatterns @('%\(PreprocessorDefinitions\)')
        foreach ($def in $defs) {
            $converted = Convert-MSBuildVariable -Value $def -ForPropsFile:$ForPropsFile -PropsName $PropsName
            if (-not $PreprocessorDefs.ContainsKey($converted)) {
                $PreprocessorDefs[$converted] = @()
            }
            $PreprocessorDefs[$converted] += $Condition
        }
    }

    # Collect include directories
    if ($CompileElement.AdditionalIncludeDirectories) {
        $includes = Get-DelimitedValues -Value $CompileElement.AdditionalIncludeDirectories -ExcludePatterns @('%\(AdditionalIncludeDirectories\)', '\$\(AdditionalIncludeDirectories\)')
        foreach ($inc in $includes) {
            $converted = Convert-MSBuildVariable -Value $inc -ForPropsFile:$ForPropsFile -PropsName $PropsName
            if (-not $IncludeDirs.ContainsKey($converted)) {
                $IncludeDirs[$converted] = @()
            }
            $IncludeDirs[$converted] += $Condition
        }
    }

    # Collect compiler options
    foreach ($optName in $script:CompilerOptionNames) {
        if ($CompileElement.$optName) {
            $value = Convert-CompilerOption -OptionName $optName -OptionValue $CompileElement.$optName
            if ($value) {
                if (-not $CompileOptions.ContainsKey($value)) {
                    $CompileOptions[$value] = @()
                }
                $CompileOptions[$value] += $Condition
            }
        }
    }

    # Collect AdditionalOptions
    if ($CompileElement.AdditionalOptions) {
        $additionalOpts = Get-DelimitedValues -Value $CompileElement.AdditionalOptions -ExcludePatterns @('%\(AdditionalOptions\)') -Delimiter ' '
        foreach ($opt in $additionalOpts) {
            if (-not $CompileOptions.ContainsKey($opt)) {
                $CompileOptions[$opt] = @()
            }
            $CompileOptions[$opt] += $Condition
        }
    }
}

# Helper to collect options from Link element
function Collect-LinkerSettings {
    param(
        [System.Xml.XmlElement]$LinkElement,
        [string]$Condition,
        [hashtable]$LibDirs,
        [hashtable]$LinkLibraries,
        [hashtable]$LinkOptions,
        [switch]$ForPropsFile,
        [string]$PropsName
    )

    # Collect library directories
    if ($LinkElement.AdditionalLibraryDirectories) {
        $libs = Get-DelimitedValues -Value $LinkElement.AdditionalLibraryDirectories -ExcludePatterns @('%\(AdditionalLibraryDirectories\)')
        foreach ($lib in $libs) {
            $converted = Convert-MSBuildVariable -Value $lib -ForPropsFile:$ForPropsFile -PropsName $PropsName
            if (-not $LibDirs.ContainsKey($converted)) {
                $LibDirs[$converted] = @()
            }
            $LibDirs[$converted] += $Condition
        }
    }

    # Collect additional dependencies
    if ($LinkElement.AdditionalDependencies) {
        $deps = Get-DelimitedValues -Value $LinkElement.AdditionalDependencies -ExcludePatterns @('%\(AdditionalDependencies\)')
        foreach ($dep in $deps) {
            $converted = Convert-MSBuildVariable -Value $dep -ForPropsFile:$ForPropsFile -PropsName $PropsName
            if (-not $LinkLibraries.ContainsKey($converted)) {
                $LinkLibraries[$converted] = @()
            }
            $LinkLibraries[$converted] += $Condition
        }
    }

    # Collect linker options
    foreach ($optName in $script:LinkerOptionNames) {
        if ($LinkElement.$optName) {
            $value = Convert-LinkerOption -OptionName $optName -OptionValue $LinkElement.$optName
            if ($value) {
                if (-not $LinkOptions.ContainsKey($value)) {
                    $LinkOptions[$value] = @()
                }
                $LinkOptions[$value] += $Condition
            }
        }
    }

    # Collect AdditionalOptions
    if ($LinkElement.AdditionalOptions) {
        $additionalOpts = Get-DelimitedValues -Value $LinkElement.AdditionalOptions -ExcludePatterns @('%\(AdditionalOptions\)') -Delimiter ' '
        foreach ($opt in $additionalOpts) {
            if (-not $LinkOptions.ContainsKey($opt)) {
                $LinkOptions[$opt] = @()
            }
            $LinkOptions[$opt] += $Condition
        }
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