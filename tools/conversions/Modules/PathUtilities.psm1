# PathUtilities.psm1
# Shared path handling utilities for conversion scripts

# Function to resolve MSBuild function calls in paths
function Resolve-MSBuildFunctions {
    param(
        [string]$Path,
        [string]$BaseDir
    )

    # Recursive helper to search upward for a file
    function Find-DirectoryContainingFile {
        param(
            [string]$CurrentDir,
            [string]$FileName,
            [int]$DepthRemaining
        )

        $parentDir = Split-Path $CurrentDir -Parent
        $atRoot = -not $parentDir -or $parentDir -eq $CurrentDir

        # Expression-based conditional logic
        if ($DepthRemaining -le 0) { $null }
        elseif (Test-Path (Join-Path $CurrentDir $FileName)) { $CurrentDir }
        elseif ($atRoot) { $null }
        else { Find-DirectoryContainingFile -CurrentDir $parentDir -FileName $FileName -DepthRemaining ($DepthRemaining - 1) }
    }

    # Resolve GetDirectoryNameOfFileAbove function
    # Pattern: $([MSBuild]::GetDirectoryNameOfFileAbove(startPath, fileName))
    if ($Path -match '\$\(\[MSBuild\]::GetDirectoryNameOfFileAbove\(([^,]+),\s*([^\)]+)\)\)') {
        $foundDir = Find-DirectoryContainingFile `
            -CurrentDir ($matches[1].Trim() -replace '\$\(MSBuildThisFileDirectory\)', $BaseDir) `
            -FileName ($matches[2].Trim()) `
            -DepthRemaining 10

        if ($foundDir) { $Path -replace [regex]::Escape($matches[0]), $foundDir }
        else {
            Write-Host "  Warning: Could not resolve GetDirectoryNameOfFileAbove for '$($matches[2].Trim())'" -ForegroundColor Yellow
            $Path
        }
    }
    else { $Path }
}

# Helper function to convert paths to CMake format
function Convert-PathToCMake {
    param(
        [string]$Path,
        [string]$BaseDir
    )

    # Pipeline of transformations
    $ApplyMSBuildResolution = { param($p) Resolve-MSBuildFunctions -Path $p -BaseDir $BaseDir }

    $ApplyVariableConversion = {
        param($p)
        $p `
            -replace '\$\(MQRoot\)', '${CMAKE_SOURCE_DIR}/' `
            -replace '\$\(MSBuildThisFileDirectory\)', '${CMAKE_CURRENT_SOURCE_DIR}/' `
            -replace '\$\(MQSolutionDirectory\)', '${CMAKE_SOURCE_DIR}/src/' `
            -replace '\\', '/'
    }

    $ApplyRelativeConversion = {
        param($p)
        $needsConversion = [System.IO.Path]::IsPathRooted($p) -and $p -notmatch '\$\{CMAKE_'
        if ($needsConversion) { Get-RelativePath -From $BaseDir -To $p }
        else { $p }
    }

    if ([string]::IsNullOrWhiteSpace($Path)) { "" }
    else {
        $Path |
            ForEach-Object { & $ApplyMSBuildResolution $_ } |
            ForEach-Object { & $ApplyVariableConversion $_ } |
            ForEach-Object { & $ApplyRelativeConversion $_ }
    }
}

# Function to calculate relative path (compatible with PowerShell 5.1)
function Get-RelativePath {
    param(
        [string]$From,
        [string]$To
    )

    Push-Location $From
    $FileName = Resolve-Path -Path $To -Relative `
        -ErrorAction SilentlyContinue `
        -ErrorVariable FileError
    Pop-Location

    if (-not $FileName) {
        $FileName = $FileError[0].TargetObject
    }

    $FileName -replace "\\", "/"
}

Export-ModuleMember -Function Resolve-MSBuildFunctions, Convert-PathToCMake, Get-RelativePath
