Param (
    [Parameter(
        Mandatory = $true,
        ValueFromPipeLine = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$ProjectName,

    [Parameter(
        Mandatory = $true,
        ValueFromPipeLine = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$ProjectDirectory,

    [Parameter(
        Mandatory = $true,
        ValueFromPipeLine = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$MQRoot
)

$vcpkg_root = "$MQRoot\contrib\vcpkg"
$vcpkg_triplet = "x86-windows-static"
$vcpkg_mq_file = "vcpkg_mq.txt"
$vcpkg_last_bootstrap_file = "vcpkg_mq_last_bootstrap.txt"

# If there is not a vcpkg_mq_file, then no reason to continue
if (-Not (Test-Path -Path "$ProjectDirectory\$vcpkg_mq_file")) {
    exit 0
}

if (-Not (Test-Path -Path "$vcpkg_root" -PathType Container))
{
    Write-Error "VCPKG directory not found:  $vcpkg_root"
    exit 1
}

$startingDirectory = Get-Location
Set-Location $vcpkg_root

$vcpkg_file_list = Get-ChildItem -Path "$ProjectDirectory\$vcpkg_mq_file"

$gitAvailable = $true
try
{
    git | Out-Null
}
catch [System.Management.Automation.CommandNotFoundException]
{
    $gitAvailable = $false
}

# Only bootstrap if we have no vcpkg or an old vcpkg
$performBootstrap = $false
if (-Not (Test-Path "./vcpkg.exe")) {
    $performBootstrap = $true
}
elseif ($gitAvailable) {
    $currentCommit = git rev-parse HEAD
    if (-Not ((Test-Path -Path "./$vcpkg_last_bootstrap_file") -And ($currentCommit -eq (Get-Content -Path "./$vcpkg_last_bootstrap_file" -TotalCount 1)))) {
        $performBootstrap = $true
    }
}

if ($performBootstrap) {
    & "./bootstrap-vcpkg.bat"
    if ($gitAvailable -AND $LASTEXITCODE -eq 0) {
        $currentCommit | Out-File "./$vcpkg_last_bootstrap_file" -NoNewline
    }
}

if (-Not (Test-Path "./vcpkg.exe")) {
    Write-Error "Could not bootstrap vcpkg"
    Set-Location $startingDirectory
    exit 1
}

if ($performBootstrap) {
    Write-Host "Searching for all $vcpkg_mq_file files..."
    $vcpkg_file_list = Get-ChildItem -Directory -Path $MQRoot -Exclude .git,.vs,build,contrib,data,docs,extras,include | Get-ChildItem -Recurse -Filter $vcpkg_mq_file
    Write-Host "Search complete"
}

$vcpkgTable = @{}
$vcpkgList = ./vcpkg.exe list
if ($vcpkgList -gt 1 -Or -Not ($vcpkgList -Like "No packages are installed*")) {
    foreach ($line in $vcpkgList) {
        $fullPackage = $line.Split(" ")[0]
        $packageParts = $fullPackage.Split(":")
        if ($packageParts[1] -eq $vcpkg_triplet) {
            $packageName = $packageParts[0]
            $packageFeature = ""
            if ($packageName -Match "(?<package>.+)\[(?<feature>.*)\]") {
                $packageName = $Matches.package
                $packageFeature = $Matches.feature
            }

            if (-Not $vcpkgTable.ContainsKey($packageName)) {
                $vcpkgTable[$packageName] = New-Object System.Collections.Generic.List[System.Object]
            }

            if ($packageFeature -ne "" -And -Not ($vcpkgTable[$packageName] -Contains $packageFeature)) {
                $vcpkgTable[$packageName].Add("$packageFeature")
            }
        }
    }
}

# If we did a bootstrap and we already had installed packages
if ($performBootstrap -And $vcpkgTable.Count -ne 0) {
    & ./vcpkg.exe upgrade
}

$vcpkgInstallTable = @{}
foreach ($file in $vcpkg_file_list) {
    Write-Host "$ProjectName checking vcpkgs from $($file.FullName)"
    $fileContents = Get-Content -Path $file.FullName
    foreach ($line in $fileContents) {
        $line = $line.Trim()
        # Hash is a comment
        if (-Not $line.StartsWith("#")) {
            # Future work may want to allow for multiple triplets, but right now we only use the one.
            # Can change this later if needed to accept what the user puts in as the triplet.
            $packageName = $line.Split(":")[0]
            $packageFeatures = New-Object System.Collections.Generic.List[System.Object]
            if ($packageName -Match "(?<package>.+)\[(?<features>.*)\]") {
                $packageName = $Matches.package
                $splitFeatures = $Matches.features.Split(",")
                foreach ($feature in $splitFeatures) {
                    $packageFeatures.Add($feature)
                }
            }

            if (-Not $vcpkgTable.ContainsKey($packageName) -And -Not $vcpkgInstallTable.ContainsKey($packageName)) {
                $vcpkgInstallTable[$packageName] = New-Object System.Collections.Generic.List[System.Object]
            }
            foreach ($feature in $packageFeatures) {
                if (-Not $vcpkgTable.ContainsKey($packageName)) {
                    $vcpkgInstallTable[$packageName].Add("$feature")
                } else {
                    if (-Not $vcpkgTable[$packageName] -Contains $feature)
                    {
                        if (-Not $vcpkgInstallTable.ContainsKey($packageName)) {
                            $vcpkgInstallTable[$packageName] = New-Object System.Collections.Generic.List[System.Object]
                        }
                        if (-Not $vcpkgInstallTable[$packageName] -Contains $feature) {
                            $vcpkgTable[$packageName].Add("$feature")
                        }
                    }
                }
            }
        }
    }
}

if ($vcpkgInstallTable.Count -ne 0) {
    $vcpkg_command = "install --x-wait-for-lock"
    foreach ($node in $vcpkgInstallTable.GetEnumerator()) {
        $vcpkg_command += " $($node.Name)"
        if ($node.Value.Count -ne 0) {
            $vcpkg_command += "["
            foreach ($feature in $node.Value) {
                $vcpkg_command += "$feature,"
            }
            # Strip the trailing comma
            $vcpkg_command = $vcpkg_command.Substring(0,$vcpkg_command.Length-1)
            $vcpkg_command += "]"
        }
        $vcpkg_command += ":$vcpkg_triplet"
    }
    & ./vcpkg.exe $vcpkg_command.Split(" ")
}

Set-Location $startingDirectory
