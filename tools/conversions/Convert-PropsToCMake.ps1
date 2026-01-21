[CmdletBinding(DefaultParameterSetName='Single')]
param(
    [Parameter(ParameterSetName='Single', Mandatory=$true, Position=0)]
    [string]$PropsPath,

    [Parameter(ParameterSetName='Single', Mandatory=$false)]
    [string]$OutputPath,

    [Parameter(Mandatory=$false)]
    [switch]$GenerateAnalysis,

    [Parameter(Mandatory=$false)]
    [switch]$Force,

    [Parameter(Mandatory=$false)]
    [switch]$BackupExisting
)

# Import shared modules
$ModulePath = Join-Path $PSScriptRoot "Modules"
Import-Module (Join-Path $ModulePath "ConversionCommon.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "GeneratorExpressions.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "FileOperations.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "AnalysisReporting.psm1") -Force -Global
Import-Module (Join-Path $ModulePath "ItemDefinitionProcessing.psm1") -Force -Global

# Process Import element
function Process-Import {
    param(
        [System.Xml.XmlElement]$ImportElement,
        [string]$InheritedCondition
    )

    $importContent = @()
    $importPath = $ImportElement.Project
    if ($importPath -and $importPath -notmatch 'Microsoft\.Cpp' -and $importPath -notmatch 'protobuf') {
        $condition = if ($ImportElement.Condition) {
            $ImportElement.Condition
        } else {
            $InheritedCondition
        }

        $convertedPath = Convert-MSBuildVariable -Value $importPath -ForPropsFile -PropsName $PropsName

        $importContent += New-Header -HeaderContent "Import from original props file"

        # Check if this is a .props file
        if ($importPath -match '\.props$') {
            $cmakePath = $convertedPath -replace '\.props$', '.cmake'
            $cmakeName = [System.IO.Path]::GetFileNameWithoutExtension($convertedPath) -replace '-', '_'

            if ($condition) {
                $cmakeCondition = Convert-ConditionToCMake $condition
                $importContent += @(
                    "# Depends on conversion of: $convertedPath",
                    "$cmakeCondition",
                    "    include(`${PATH_TO_${PropsName}_DIR}/$cmakePath)",
                    "    target_${cmakeName}_props(`$`{TARGET_NAME`})"
                    "endif()"
                )
            } else {
                $importContent += @(
                    "# Depends on conversion of: $convertedPath",
                    "include($cmakePath)",
                    "target_${cmakeName}_props(`$`{TARGET_NAME`})"
                )
            }
        } else {
            $importContent += @(
                "# TODO: Manual conversion required for import: $convertedPath",
                "# This import does not have a .props extension and cannot be automatically processed"
            )

            if ($condition) {
                $importContent += "# Original condition: $condition"
            }
        }

        $importContent += ""
        $script:analysis.ImportedProps += $importPath
    }

    $importContent
}

# Process ImportGroup element
function Process-ImportGroup {
    param(
        [System.Xml.XmlElement]$ImportGroupElement
    )

    $groupCondition = $ImportGroupElement.Condition

    # Process all Import elements within the group
    $ImportGroupElement.Import | ForEach-Object {
        Process-Import -ImportElement $_ -InheritedCondition $groupCondition
    }
}

# Wrapper to add Platform condition check (extends module's Test-NeedsGeneratorExpression)
function Test-IsBuildCondition {
    param([string]$Condition)
    (Test-NeedsGeneratorExpression -Condition $Condition) -or ($Condition -match '\$\(Platform\)')
}

# Process PropertyGroup element
function Process-AllPropertyGroups {
    param(
        [System.Xml.XmlElement[]]$PropertyGroupElements
    )

    $groupCondition = $PropertyGroupElement.Condition
    $groupLabel = $PropertyGroupElement.Label

    $propertyContent = @()

    # First pass: collect all properties and group by name
    $propertiesByName = [ordered]@{}

    $PropertyGroupElements.ChildNodes | Where-Object {
        $_.NodeType -eq 'Element' -and $_.Name -notmatch '^(Label|ProjectGuid)$'
    } | ForEach-Object {
        $propertyName = $_.Name
        $propertyValue = $_.InnerText
        $elementCondition = $_.Condition

        if (-not [string]::IsNullOrWhiteSpace($propertyName) -and -not [string]::IsNullOrWhiteSpace($propertyValue)) {
            if (@('MQSolutionDirectory', 'MQRoot', 'MQ2Root', 'IntDir', 'OutDir') -notcontains $propertyName) {
                $condition = if ($elementCondition) {
                    $elementCondition
                } else {
                    $groupCondition
                }

                if (-not $propertiesByName.Contains($propertyName)) {
                    $propertiesByName[$propertyName] = @()
                }

                $propertiesByName[$propertyName] += @{
                    Value = $propertyValue
                    Condition = $condition
                }
            }
        }
    }

    # Second pass: generate CMake code for each property
    foreach ($propertyName in $propertiesByName.Keys) {
        $entries = $propertiesByName[$propertyName]

        if (-not $propertyContent) {
            $header = "PropertyGroup settings"
            if (-not [string]::IsNullOrWhiteSpace($groupLabel)) {
                $header += " with LABEL=$groupLabel"
            }
            $propertyContent += New-Header -HeaderContent $header
        }

        if ($entries | Where-Object { Test-IsBuildCondition -Condition $_.Condition }) {
            $propertyContent += Join-PropertiesWithGeneratorExpression -PropertyName $propertyName -Entries $entries
        } else {
            $propertyContent += New-IfElseBlock -PropertyName $propertyName -Entries $entries -PropsName $PropsName
        }

        $propertyContent += ""
        $script:analysis.UserMacros += $propertyName
    }

    if ($propertyContent) {
        $propertyContent += ""
    }

    $propertyContent
}

# Resolve paths
$PropsPath = Resolve-Path $PropsPath -ErrorAction Stop
$PropsDir = Split-Path $PropsPath -Parent
$PropsName = [System.IO.Path]::GetFileNameWithoutExtension($PropsPath) -replace '-', '_'

if (-not $OutputPath) {
    $OutputPath = Join-Path $PropsDir "$PropsName.cmake"
}

# Check if output file already exists
if (-not (Test-OutputFileExists -OutputPath $OutputPath -Force $Force -BackupExisting $BackupExisting)) {
    exit 0
}

# Parse XML
Write-Host "Parsing $PropsPath..." -ForegroundColor Cyan
[xml]$props = Get-Content $PropsPath

Write-Host "Processing props file in document order..." -ForegroundColor Cyan

# Initialize script-level variables
$script:cmake = ""
$script:analysis = @{
    Converted = @()
    Partial = @()
    NotConverted = @()
    Warnings = @()
    UserMacros = @()
    ImportedProps = @()
}

# Generate CMake header
$script:cmake = "# Generated from $PropsName.props`n"
$script:cmake += "# This file should be included in CMakeLists.txt files that need these settings`n"
$script:cmake += "# NOTE: Import order preserved from original .props file`n`n"
$script:cmake += "include_guard()`n`n"
$script:cmake += "set(PATH_TO_${PropsName}_DIR `${CMAKE_CURRENT_LIST_DIR})`n`n"
$script:cmake += "macro(target_${PropsName}_props TARGET_NAME)`n`n"

# Process all Project child nodes in document order
$nodeContent = $props.Project.ChildNodes | Where-Object {
    $_.NodeType -eq 'Element'
} | ForEach-Object {
    $element = $_

    switch ($element.Name) {
        'Import' {
            Process-Import -ImportElement $element -InheritedCondition $null
        }
        'ImportGroup' {
            Process-ImportGroup -ImportGroupElement $element
        }
        'PropertyGroup' {
            # Skip individual processing - we'll processl all PropertyGroups together
            @()
        }
        'ItemDefinitionGroup' {
            # Skip individual processing - we'll process all ItemDefinitionGroups together
            @()
        }
        default {
            # Skip other elements (like ProjectExtensions, Target, etc.)
            @(
                "# TODO: Manual conversion required for element: $($element.Name)",
                ""
            )
        }
    }
} | ForEach-Object { "    $_" }

# Process all PropertyGroup elements together
$allPropertyGroups = $props.Project.PropertyGroup
if ($allPropertyGroups) {
    $propertyDefContent = Process-AllPropertyGroups -PropertyGroupElements $allPropertyGroups
    if ($propertyDefContent) {
        $nodeContent += $propertyDefContent | ForEach-Object { "    $_" }
    }
}

# Process all ItemDefinitionGroup elements together at the end
$allItemDefGroups = $props.Project.ItemDefinitionGroup
if ($allItemDefGroups) {
    $itemDefContent = Convert-AllItemDefinitionGroups `
        -ItemDefGroupElements $allItemDefGroups `
        -TargetName '${TARGET_NAME}' `
        -ForPropsFile `
        -PropsName $PropsName `
        -MultiBuild
    if ($itemDefContent) {
        $nodeContent += $itemDefContent | ForEach-Object { "    $_" }
    }
}

$script:cmake += $($nodeContent -join "`n")
$script:cmake += "`nendmacro()`n"

# Write CMake file
Write-Host "Writing CMake file to $OutputPath..." -ForegroundColor Cyan
$script:cmake | Out-File -FilePath $OutputPath -Encoding UTF8 -NoNewline

Write-Host "CMake file generated successfully!" -ForegroundColor Green

# Generate analysis report if requested
if ($GenerateAnalysis) {
    $analysisPath = Join-Path $PropsDir "$PropsName-conversion-analysis.txt"

    $report = New-PropsAnalysisReport `
        -Analysis $script:analysis `
        -PropsName $PropsName `
        -PropsPath $PropsPath `
        -OutputPath $OutputPath

    $report | Out-File -FilePath $analysisPath -Encoding UTF8 -NoNewline
    Write-Host "Analysis report written to $analysisPath" -ForegroundColor Green

    Write-ConversionSummary -Analysis $script:analysis -ConverterType "Props"
}

Write-Host ""
Write-Host "Done! The CMake file preserves the import order from the original .props file." -ForegroundColor Cyan
