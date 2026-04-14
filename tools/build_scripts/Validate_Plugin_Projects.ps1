<#
.SYNOPSIS
    Validates plugin .vcxproj files to ensure they don't contain unauthorized build commands.

.DESCRIPTION
    Scans all .vcxproj files in the plugins directory and verifies:
    - PreBuildEvent commands match the approved mkplugin template exactly (or are empty)
    - No PostBuildEvent commands exist
    - No PreLinkEvent commands exist
    - No CustomBuild commands exist
    - No Exec tasks exist

    Plugins in the whitelist are skipped entirely.

.PARAMETER PluginsDirectory
    Path to the plugins directory.

.PARAMETER Whitelist
    Array of plugin directory names to skip validation for.
#>

param(
    [Parameter(Mandatory)]
    [string]$PluginsDirectory,
    [string[]]$Whitelist = @()
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path $PluginsDirectory)) {
    Write-Output "Plugins directory not found: $PluginsDirectory"
    exit 1
}

$PluginsDirectory = (Resolve-Path $PluginsDirectory).Path

# The only approved PreBuildEvent command (from mkplugin template)
$approvedCommand = 'if exist "$([MSBuild]::GetDirectoryNameOfFileAbove($(MSBuildThisFileDirectory), tools\build_scripts\Plugin_Versioning.ps1))\tools\build_scripts\Plugin_Versioning.ps1" powershell.exe -ExecutionPolicy Bypass -NoProfile -NonInteractive -File "$([MSBuild]::GetDirectoryNameOfFileAbove($(MSBuildThisFileDirectory), tools\build_scripts\Plugin_Versioning.ps1))\tools\build_scripts\Plugin_Versioning.ps1" -ProjectName "$(MSBuildProjectName)" -ProjectDirectory "$([MSBuild]::EnsureTrailingSlash(''$(MSBuildThisFileDirectory)''))\"'

# Dangerous elements to check for (element name -> XPath-like description)
$dangerousElements = @(
    "PostBuildEvent"
    "PreLinkEvent"
    "CustomBuild"
    "CustomBuildStep"
)

$failures = @()
$scanned = 0
$skipped = 0

# Find all vcxproj files in the plugins directory
$vcxprojFiles = Get-ChildItem -Path $PluginsDirectory -Filter "*.vcxproj" -Recurse

foreach ($file in $vcxprojFiles) {
    # Determine the top-level plugin directory name
    $relativePath = $file.FullName.Substring($PluginsDirectory.TrimEnd('\', '/').Length + 1)
    $pluginName = ($relativePath -split '[\\/]')[0]

    # Check whitelist
    if ($Whitelist -contains $pluginName) {
        $skipped++
    } else {
        $scanned++
        [xml]$xml = Get-Content $file.FullName -Raw
        $ns = New-Object System.Xml.XmlNamespaceManager($xml.NameTable)
        $ns.AddNamespace("ms", "http://schemas.microsoft.com/developer/msbuild/2003")

        # Check PreBuildEvent commands
        $preBuildNodes = $xml.SelectNodes("//ms:PreBuildEvent/ms:Command", $ns)
        foreach ($node in $preBuildNodes) {
            $command = $node.InnerText.Trim()
            if ($command -and $command -ne $approvedCommand) {
                $failures += "UNAUTHORIZED PreBuildEvent in $($file.FullName):`n  Command: $command"
            }
        }

        # Check for dangerous elements with Command children
        foreach ($elementName in $dangerousElements) {
            $nodes = $xml.SelectNodes("//ms:$elementName/ms:Command", $ns)
            foreach ($node in $nodes) {
                $command = $node.InnerText.Trim()
                if ($command) {
                    $failures += "UNAUTHORIZED $elementName in $($file.FullName):`n  Command: $command"
                }
            }

            # Also check for these elements with direct text content
            $directNodes = $xml.SelectNodes("//ms:$elementName", $ns)
            foreach ($node in $directNodes) {
                if ($node.HasChildNodes) {
                    foreach ($child in $node.ChildNodes) {
                        if ($child.NodeType -eq "Text" -and $child.InnerText.Trim()) {
                            $failures += "UNAUTHORIZED $elementName content in $($file.FullName):`n  Content: $($child.InnerText.Trim())"
                        }
                    }
                }
            }
        }

        # Check for Exec tasks (MSBuild inline task execution)
        $execNodes = $xml.SelectNodes("//ms:Exec", $ns)
        foreach ($node in $execNodes) {
            $command = $node.GetAttribute("Command")
            if ($command) {
                $failures += "UNAUTHORIZED Exec task in $($file.FullName):`n  Command: $command"
            }
        }

        # Check for UsingTask (could load arbitrary assemblies)
        $usingTaskNodes = $xml.SelectNodes("//ms:UsingTask", $ns)
        foreach ($node in $usingTaskNodes) {
            $taskName = $node.GetAttribute("TaskName")
            $assemblyFile = $node.GetAttribute("AssemblyFile")
            $assemblyName = $node.GetAttribute("AssemblyName")
            $failures += "UNAUTHORIZED UsingTask in $($file.FullName):`n  TaskName: $taskName, AssemblyFile: $assemblyFile, AssemblyName: $assemblyName"
        }

        # Check for Import elements that reference outside the repo
        $importNodes = $xml.SelectNodes("//ms:Import", $ns)
        foreach ($node in $importNodes) {
            $project = $node.GetAttribute("Project")
            # Allow standard MS imports, repo-relative props, and user props
            if (-NOT ($project -match "^\$\(VCTargetsPath\)" -or
                $project -match "^\$\(UserRootDir\)" -or
                $project -match "\.props$" -or
                $project -match "\.targets$" -or
                $project -match "\.user\.props"))
            {
                # Flag imports that reach outside the repo or use network paths
                if ($project -match "(https?://|ftp://|\\\\\\\\)") {
                    $failures += "SUSPICIOUS Import in $($file.FullName):`n  Project: $project"
                }
            }
        }
    }
}

# Report results
Write-Output "Plugin Project Validation Report"
Write-Output "================================"
Write-Output "Scanned: $scanned vcxproj file(s)"
Write-Output "Skipped: $skipped vcxproj file(s) (whitelisted)"
Write-Output ""

if ($failures.Count -gt 0) {
    Write-Output "VALIDATION FAILED - $($failures.Count) violation(s) found:"
    Write-Output ""
    foreach ($failure in $failures) {
        Write-Output "  [FAIL] $failure"
        Write-Output ""
    }
    exit 1
} else {
    Write-Output "VALIDATION PASSED - All plugin projects are clean."
    exit 0
}
