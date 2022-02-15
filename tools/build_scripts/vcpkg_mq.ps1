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
    [string]$MQRoot,

    [Parameter(
        Mandatory = $true,
        ValueFromPipeline = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$Platform
)

$vcpkg_root = "$MQRoot\contrib\vcpkg"
$vcpkg_triplet = "$Platform-windows-static"
$vcpkg_mq_file = "vcpkg_mq.txt"

$vcpkg_last_bootstrap_file = "vcpkg_mq_last_bootstrap-$Platform.txt"

function Wait-Process {
    [CmdletBinding()]

    Param (
        [Parameter(
            Mandatory = $true,
            ValueFromPipeLine = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [string]$Name,
        [Parameter(
            Mandatory = $false,
            ValueFromPipeLine = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [int]$Timeout = 600,
        [Parameter(
            Mandatory = $false,
            ValueFromPipeLine = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [int]$SleepInterval = 30,
        [Parameter(
            Mandatory = $false,
            ValueFromPipeLine = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [string]$Filter = "*"
    )

    while ($Timeout -gt 0 -And @(Get-CimInstance Win32_Process -Filter "name = '$Name'" | Where-Object {$_.CommandLine -like $Filter}).Count -gt 0) {
        Write-Host "$ProjectName waiting for another $Name process to complete, timeout in $Timeout seconds..."
        $Timeout -= $SleepInterval
        Start-Sleep $SleepInterval
    }
    if ($Timeout -lt 1)
    {
        Write-Host "$ProjectName timed out waiting for another $Name process to complete."
    }
}

# If there is not a vcpkg_mq_file, then no reason to continue
if (-Not (Test-Path -Path "$ProjectDirectory\$vcpkg_mq_file")) {
    exit 0
}

if (-Not (Test-Path -Path "$vcpkg_root" -PathType Container))
{
    Write-Error "VCPKG directory not found: $vcpkg_root"
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

# If multiple vcpkg_mq processes are running, try to divide them up so they're not running at EXACTLY the same time.
$ProcessList = @(Get-CimInstance Win32_Process -Filter "name = 'powershell.exe'" | Where-Object {$_.CommandLine -like "*vcpkg_mq.ps1*"} | Sort-Object -Property ProcessId)
if ($ProcessList.Count -gt 1) {
    $ProcessIndex = 0;
    ForEach ($process in $ProcessList) {
        if ($process.ProcessId -eq $PID) {
            break
        }
        $ProcessIndex++
    }
    Start-Sleep $($ProcessIndex * 5)
}

# For simultaneous runs, if bootstrap is currently running, wait until it finishes
Wait-Process -Name "powershell.exe" -Filter "*scripts\bootstrap.ps1*"

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

$vcpkg_drive = Split-Path (Get-Item "./vcpkg.exe").FullName -Qualifier
$vcpkg_drive_fixed = $false
if (-Not [string]::IsNullOrWhiteSpace($vcpkg_drive)) {
    [System.IO.DriveInfo]::GetDrives() | Where-Object { $_.DriveType -eq "Fixed" } | ForEach-Object {
        if (-Not $vcpkg_drive_fixed -And $_.Name -Like "$vcpkg_drive*")
        {
            $vcpkg_drive_fixed = $true
        }
    }
}
if (-Not $vcpkg_drive_fixed) {
    Write-Warning "vcpkg may have issues building from a non-fixed drive (usb/network) - if you have issues compiling, switch to a fixed drive."
}

if ($performBootstrap) {
    Write-Host "Searching for all $vcpkg_mq_file files..."
    $vcpkg_file_list = Get-ChildItem -Directory -Path $MQRoot -Exclude .git,.vs,build,contrib,data,docs,extras,include | Get-ChildItem -Recurse -Filter $vcpkg_mq_file
    Write-Host "Search complete"
}

$vcpkgTable = @{}
$vcpkgList = ./vcpkg.exe list
if (-Not ($vcpkgList -Like "No packages are installed*") -Or $vcpkgList.Count -gt 1) {
    foreach ($line in $vcpkgList) {
        $fullPackage = $line.Split(" ")[0]
        $packageParts = $fullPackage.Split(":")
        $packageName = $packageParts[0]
        $packageTriplet = $packageParts[1]
        $packageFeature = ""
        if ($packageName -Match "(?<package>.+)\[(?<feature>.*)\]") {
            $packageName = $Matches.package
            $packageFeature = $Matches.feature
        }
        # Ignore the built-in packages
        if ($packageName -NotLike 'vcpkg-cmake*') {
            if (-Not $vcpkgTable.ContainsKey($packageTriplet)) {
                $vcpkgTable.Add($packageTriplet,@{})
            }

            if (-Not $vcpkgTable[$packageTriplet].ContainsKey($packageName)) {
                $vcpkgTable[$packageTriplet][$packageName] = New-Object System.Collections.Generic.List[System.Object]
            }

            if ($packageFeature -ne "" -And -Not ($vcpkgTable[$packageTriplet][$packageName] -Contains $packageFeature)) {
                $vcpkgTable[$packageTriplet][$packageName].Add("$packageFeature")
            }
        }
    }
}

# If we did a bootstrap and we already had installed packages
if ($performBootstrap -And $vcpkgTable.Count -ne 0) {
    & ./vcpkg.exe upgrade --no-dry-run
}

$vcpkgInstallTable = @{}
foreach ($file in $vcpkg_file_list) {
    Write-Host "$ProjectName checking vcpkgs from $($file.FullName)"
    $fileContents = Get-Content -Path $file.FullName
    foreach ($line in $fileContents) {
        $line = $line.Trim()
        # Hash is a comment
        if (-Not $line.StartsWith("#")) {
            $packageLine = $line.Split(":")
            $packageName = $packageLine[0]
            $packageTriplet = $vcpkg_triplet
            if ($packageLine.Count -gt 1) {
                $packageTriplet = $packageLine[1]
            }
            $packageFeatures = New-Object System.Collections.Generic.List[System.Object]
            if ($packageName -Match "(?<package>.+)\[(?<features>.*)\]") {
                $packageName = $Matches.package
                $splitFeatures = $Matches.features.Split(",")
                foreach ($feature in $splitFeatures) {
                    $packageFeatures.Add($feature)
                }
            }

            #TODO: This logic got convoluted.  Clean it up.
            if (-Not $vcpkgTable.ContainsKey($packageTriplet) -Or (-Not $vcpkgTable[$packageTriplet].ContainsKey($packageName) -And (-Not $vcpkgInstallTable.ContainsKey($packageTriplet) -Or -Not $vcpkgInstallTable[$packageTriplet].ContainsKey($packageName)))) {
                if (-Not $vcpkgInstallTable.ContainsKey($packageTriplet)) {
                    $vcpkgInstallTable.Add($packageTriplet,@{})
                }
                $vcpkgInstallTable[$packageTriplet][$packageName] = New-Object System.Collections.Generic.List[System.Object]
            }

            foreach ($feature in $packageFeatures) {
                if (-Not $vcpkgTable.ContainsKey($packageTriplet) -Or -Not $vcpkgTable[$packageTriplet].ContainsKey($packageName)) {
                    $vcpkgInstallTable[$packageTriplet][$packageName].Add("$feature")
                } else {
                    # core would not show up in a feature list and the package is already installed so only add additional features that aren't core
                    if ("core" -ne $feature -And -Not $vcpkgTable[$packageTriplet][$packageName] -Contains $feature) {
                        if (-Not $vcpkgInstallTable[$packageTriplet].ContainsKey($packageName)) {
                            $vcpkgInstallTable[$packageTriplet][$packageName] = New-Object System.Collections.Generic.List[System.Object]
                        }
                        if (-Not $vcpkgInstallTable[$packageTriplet][$packageName] -Contains $feature) {
                            $vcpkgInstallTable[$packageTriplet][$packageName].Add("$feature")
                        }
                    }
                }
            }
        }
    }
}

if ($vcpkgInstallTable.Count -ne 0) {
    $vcpkg_command = "install --x-wait-for-lock"
    foreach ($triplet in $vcpkgInstallTable.GetEnumerator()) {
        if ($triplet.Value.Count -ne 0) {
            foreach ($node in $triplet.Value.GetEnumerator()) {
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
                $vcpkg_command += ":$($triplet.Name)"
            }
        }
    }

    if ($vcpkg_command -ne "install --x-wait-for-lock") {
        # For simultaneous runs, if vcpkg.exe is currently running, wait until it finishes.
        Wait-Process -Name "vcpkg.exe"
        & ./vcpkg.exe $vcpkg_command.Split(" ")
    }
}

Set-Location $startingDirectory
