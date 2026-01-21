# AnalysisReporting.psm1
# Shared analysis reporting functions for conversion scripts

# Helper to format list items or "(none)" if empty
function Format-ListSection {
    param([array]$Items, [string]$Prefix = "  - ")
    if ($Items.Count -gt 0) {
        ($Items | ForEach-Object { "$Prefix$_" }) -join "`n"
    } else { "(none)" }
}

# Generate analysis report for props file conversion
function New-PropsAnalysisReport {
    param(
        [hashtable]$Analysis,
        [string]$PropsName,
        [string]$PropsPath,
        [string]$OutputPath
    )

    $importedSection = Format-ListSection -Items $Analysis.ImportedProps
    $macrosSection = Format-ListSection -Items ($Analysis.UserMacros | Select-Object -Unique)
    $uniqueMacroCount = ($Analysis.UserMacros | Select-Object -Unique).Count

    # Build report as array of sections, then join
    @(
        "================================================================"
        "PROPS TO CMAKE CONVERSION ANALYSIS"
        "================================================================"
        "Props File: $PropsName"
        "Source: $PropsPath"
        "Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
        ""
        "NOTE: This conversion processes the .props file in document order"
        "to preserve import precedence and variable override semantics."
        ""
        "================================================================"
        "IMPORTED PROPS FILES"
        "================================================================"
        $importedSection
        ""
        "================================================================"
        "USER MACROS/VARIABLES"
        "================================================================"
        $macrosSection
        ""
        "================================================================"
        "SUMMARY"
        "================================================================"
        "Imported props files: $($Analysis.ImportedProps.Count)"
        "User macros/variables: $uniqueMacroCount"
        ""
        "================================================================"
        "USAGE INSTRUCTIONS"
        "================================================================"
        "1. Ensure all imported .props files have been converted to .cmake"
        "2. Include this .cmake file in your CMakeLists.txt:"
        "   include($OutputPath)"
        "3. Apply properties to your target:"
        "   target_$($PropsName -replace '-', '_')_props(MyTarget)"
    ) -join "`n"
}

# Generate analysis report for vcxproj file conversion
function New-VcxprojAnalysisReport {
    param(
        [hashtable]$Analysis,
        [string]$ProjectName,
        [string]$VcxprojPath,
        [int]$SourceFileCount,
        [int]$ExcludedFileCount,
        [int]$ProjectReferenceCount,
        [int]$DefinitionCount,
        [int]$LinkerOptionCount
    )

    # Build report sections using helper
    $convertedSection = Format-ListSection -Items $Analysis.Converted -Prefix "+ "
    $partialSection = Format-ListSection -Items $Analysis.Partial -Prefix "~ "
    $notConvertedSection = Format-ListSection -Items $Analysis.NotConverted -Prefix "- "
    $warningsSection = Format-ListSection -Items $Analysis.Warnings -Prefix "! "
    $propsSection = Format-ListSection -Items $Analysis.PropsFiles

    # Build report as array of sections, then join
    @(
        "================================================================"
        "VCXPROJ TO CMAKE CONVERSION ANALYSIS"
        "================================================================"
        "Project: $ProjectName"
        "Source: $VcxprojPath"
        "Generated: $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
        ""
        "================================================================"
        "SUCCESSFULLY CONVERTED"
        "================================================================"
        $convertedSection
        ""
        "================================================================"
        "PARTIALLY CONVERTED (May Need Manual Adjustment)"
        "================================================================"
        $partialSection
        ""
        "================================================================"
        "NOT CONVERTED (Requires Manual Implementation)"
        "================================================================"
        $notConvertedSection
        ""
        "================================================================"
        "WARNINGS"
        "================================================================"
        $warningsSection
        ""
        "================================================================"
        "PROPS FILES DETECTED"
        "================================================================"
        $propsSection
        ""
        "================================================================"
        "SUMMARY"
        "================================================================"
        "Total source files: $SourceFileCount"
        "Excluded files: $ExcludedFileCount"
        "Project references: $ProjectReferenceCount"
        "Configurations with definitions: $DefinitionCount"
        "Configurations with linker options: $LinkerOptionCount"
        "Props files found: $($Analysis.PropsFiles.Count)"
        ""
        "================================================================"
        "NEXT STEPS"
        "================================================================"
        "1. Review the generated CMakeLists.txt file"
        "2. Test build with all configurations"
        "3. Address items in NOT CONVERTED section"
        "4. Verify preprocessor definitions match vcxproj"
        "5. Check that all dependencies are linked correctly"
        ""
    ) -join "`n"
}

# Write conversion summary to console
function Write-ConversionSummary {
    param(
        [hashtable]$Analysis,
        [string]$ConverterType  # "Props" or "Vcxproj"
    )

    Write-Host ""
    Write-Host "CONVERSION SUMMARY:" -ForegroundColor Yellow

    if ($ConverterType -eq "Props") {
        Write-Host "  Imported props: $($Analysis.ImportedProps.Count)" -ForegroundColor Cyan
        Write-Host "  User macros: $(($Analysis.UserMacros | Select-Object -Unique).Count)" -ForegroundColor Cyan
    }
    else {  # Vcxproj
        Write-Host "  Converted items: $($Analysis.Converted.Count)" -ForegroundColor Green
        Write-Host "  Partial items: $($Analysis.Partial.Count)" -ForegroundColor Yellow
        Write-Host "  Not converted: $($Analysis.NotConverted.Count)" -ForegroundColor Red
        Write-Host "  Warnings: $($Analysis.Warnings.Count)" -ForegroundColor Yellow
        Write-Host "  Props files: $($Analysis.PropsFiles.Count)" -ForegroundColor Cyan
    }
}

Export-ModuleMember -Function New-PropsAnalysisReport, New-VcxprojAnalysisReport, Write-ConversionSummary