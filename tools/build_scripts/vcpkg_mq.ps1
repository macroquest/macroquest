Param (
    [Parameter(
        Mandatory = $true,
        ValueFromPipeline = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$ProjectName,

    [Parameter(
        Mandatory = $true,
        ValueFromPipeline = $true,
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
    [string]$Platform,

    [Parameter(
        Mandatory = $true,
        ValueFromPipeline = $true,
        ValueFromPipelineByPropertyName = $true
    )]
    [string]$Toolchain
)

# Use the downloaded binaries so that we always get the expected version
$env:VCPKG_FORCE_DOWNLOADED_BINARIES = "1"

$vcpkg_root = "$MQRoot\contrib\vcpkg"
$vcpkg_triplet = "$Platform-windows-static"
$vcpkg_mq_file = "vcpkg_mq.txt"
$vcpkg_mq_file_platform = "vcpkg_mq_$Platform.txt"

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
        [int]$SleepInterval = 60,
        [Parameter(
            Mandatory = $false,
            ValueFromPipeLine = $true,
            ValueFromPipelineByPropertyName = $true
        )]
        [string]$Filter = "*"
    )

    while ($Timeout -gt 0 -And @(Get-CimInstance Win32_Process -Filter "name = '$Name'" | Where-Object {$_.CommandLine -like $Filter}).Count -gt 0) {
        Write-Host "$ProjectName waiting for another $Name process to complete..." #, timeout in $Timeout seconds..."
        #$Timeout -= $SleepInterval
        Start-Sleep $SleepInterval
    }
    if ($Timeout -lt 1)
    {
        Write-Host "$ProjectName timed out waiting for another $Name process to complete."
    }
}

function RunPreCheck {
    if ($vcpkg_root -match ' ') {
        Write-Warning "vcpkg may have issues building in paths with spaces - if you have issues compiling, remove spaces from your path."
    }
    $PrecheckScript = "$PSScriptRoot\MQ2Main_PreBuild.ps1"
    if (Test-Path $PrecheckScript -PathType Leaf) {
        & $PrecheckScript
    }
}

# If there is not a vcpkg_mq_file and vcpkg_mq_file_platform, then no reason to continue
if (-Not (Test-Path -Path "$ProjectDirectory\$vcpkg_mq_file") -And -Not (Test-Path -Path "$ProjectDirectory\$vcpkg_mq_file_platform")) {
    exit 0
}

if (-Not (Test-Path -Path "$vcpkg_root" -PathType Container))
{
    Write-Error "VCPKG directory not found: $vcpkg_root"
    exit 1
}

# The vcpkg_mq file might override this, but at least check the defaults
$tripletFile = "$vcpkg_root\triplets\$vcpkg_triplet.cmake"
if (-Not (Test-Path -Path "$tripletFile" -PathType Leaf))
{
    $tripletFile = "$vcpkg_root\triplets\community\$vcpkg_triplet.cmake"
    if (-Not (Test-Path -Path "$tripletFile" -PathType Leaf))
    {
        Write-Error "VCPKG Default Triplet not found: $vcpkg_triplet"
        exit 1
    }
}

$match = Get-Content "$tripletFile" | Select-String -Pattern "set\(VCPKG_PLATFORM_TOOLSET (.*)\)"
if (-Not ($match.Matches.Success))
{
    Write-Warning "VCPKG not set to expected toolchain: $Toolchain"
}
elseif (-Not ($Toolchain -eq $match.Matches.Groups[1]))
{
    Write-Warning "VCPKG toolchain mismatch: Visual Studio Expected ($Toolchain) VCPKG returned $($match.Matches.Groups[1])"
}

$startingDirectory = Get-Location
Set-Location $vcpkg_root

$vcpkg_file_list = @()
$vcpkg_file_list = @(Get-ChildItem -Path "$ProjectDirectory\$vcpkg_mq_file" -ErrorAction SilentlyContinue)
$vcpkg_file_list += @(Get-ChildItem -Path "$ProjectDirectory\$vcpkg_mq_file_platform" -ErrorAction SilentlyContinue)

$gitAvailable = $true
try
{
    git | Out-Null
}
catch [System.Management.Automation.CommandNotFoundException]
{
    $gitAvailable = $false
}

if (!$gitAvailable)
{
    Write-Warning "vcpkg could not find git.  You will need to manually bootstrap and upgrade when there are vcpkg updates"
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

if (Test-Path env:VCPKG_ROOT)
{
    Write-Warning "VCPKG_ROOT environment variable is set which means another installation of vcpkg is trying to override this one.  Temporarily resolving this issue, but there may be other issues with global vcpkg config."
    $env:VCPKG_ROOT = $vcpkg_root
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
    RunPreCheck
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
    $folderList = Get-ChildItem -Directory -Path $MQRoot -Exclude .git,.vs,build,contrib,data,docs,extras,include
    $vcpkg_file_list = @($folderList | Get-ChildItem -Recurse -Filter $vcpkg_mq_file)
    $vcpkg_file_list += @($folderList | Get-ChildItem -Recurse -Filter $vcpkg_mq_file_platform)

    Write-Host "Search complete"
}

function Get-VcpkgTable {
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
    return $vcpkgTable
}

$vcpkgTable = Get-VcpkgTable

# If we did a bootstrap and we already had installed packages
if ($performBootstrap -And $vcpkgTable.Count -ne 0) {
    & ./vcpkg.exe upgrade --no-dry-run
    if ($LASTEXITCODE -ne 0) {
        Write-Warning "vcpkg upgrade failed - your vcpkg installation may need to be manually fixed. Save this log before trying again."
        # if the upgrade failed, the bootstrap file should show accordingly
        "Upgrade Error" | Out-File "./$vcpkg_last_bootstrap_file" -NoNewline
        # Attempt automatic cleanup
        Write-Warning "vcpkg is now attempting to remove outdated packages"
        & ./vcpkg.exe remove --outdated --recurse
        if ($LASTEXITCODE -ne 0) {
            Write-Warning "vcpkg outdated remove failed - attempting to remove all packages."
            & ./vcpkg list | ForEach-Object { ./vcpkg remove $_.Split(" ")[0] --recurse }
        }
    }
    # Packages may have changed, so rebuild the list
    $vcpkgTable = Get-VcpkgTable
}

$vcpkgInstallTable = @{}
foreach ($file in $vcpkg_file_list) {
    Write-Host "$ProjectName checking vcpkgs from $($file.FullName)"
    $fileContents = Get-Content -Path "$($file.FullName)"
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

            # If either the triplet or the package is not installed
            if (-Not $vcpkgTable.ContainsKey($packageTriplet) -Or (-Not $vcpkgTable[$packageTriplet].ContainsKey($packageName))) {
                # If we don't have the triplet set to be installed already
                if (-Not $vcpkgInstallTable.ContainsKey($packageTriplet)) {
                    $vcpkgInstallTable.Add($packageTriplet,@{})
                }
                # If we don't have the package set to be installed already
                if (-Not $vcpkgInstallTable[$packageTriplet].ContainsKey($packageName)) {
                    $vcpkgInstallTable[$packageTriplet][$packageName] = New-Object System.Collections.Generic.List[System.Object]
                }
            }

            foreach ($feature in $packageFeatures) {
                # If this package isn't installed at all just add the feature
                if (-Not $vcpkgTable.ContainsKey($packageTriplet) -Or -Not $vcpkgTable[$packageTriplet].ContainsKey($packageName)) {
                    # If the feature isn't already set to be installed (this catches where core is specified as the only feature, assuming another package doesn't override that in a bulk install)
                    if (-Not ($vcpkgInstallTable[$packageTriplet][$packageName] -Contains $feature))
                    {
                        $vcpkgInstallTable[$packageTriplet][$packageName].Add("$feature")
                    }
                } else {
                    # core would not show up in a feature list and the package is already installed so only add additional features that aren't core
                    # here we also handle ADDING features when a package is already installed with a different featureset
                    if ("core" -ne $feature -And -Not ($vcpkgTable[$packageTriplet][$packageName] -Contains $feature)) {
                        if (-Not $vcpkgInstallTable.ContainsKey($packageTriplet)) {
                            $vcpkgInstallTable.Add($packageTriplet,@{})
                        }
                        if (-Not $vcpkgInstallTable[$packageTriplet].ContainsKey($packageName)) {
                            $vcpkgInstallTable[$packageTriplet][$packageName] = New-Object System.Collections.Generic.List[System.Object]
                        }
                        if (-Not ($vcpkgInstallTable[$packageTriplet][$packageName] -Contains $feature)) {
                            $vcpkgInstallTable[$packageTriplet][$packageName].Add("$feature")
                        }
                    }
                }
            }
        }
    }
}

if ($vcpkgInstallTable.Count -ne 0) {
    RunPreCheck
    $vcpkg_command = "install --x-wait-for-lock"
    foreach ($triplet in $vcpkgInstallTable.GetEnumerator()) {
        if ($triplet.Value.Count -ne 0) {
            foreach ($node in $triplet.Value.GetEnumerator()) {
                if ($node.Value.Count -ne 0) {
                    # Force recursion to install new features if it is not already specified
                    if ($vcpkg_command -NotLike "*--recurse*") {
                        $vcpkg_command = $vcpkg_command.Replace("install --x-wait-for-lock","install --x-wait-for-lock --recurse")
                    }
                    $vcpkg_command += " $($node.Name)["
                    foreach ($feature in $node.Value) {
                        $vcpkg_command += "$feature,"
                    }
                    # Strip the trailing comma
                    $vcpkg_command = $vcpkg_command.Substring(0,$vcpkg_command.Length-1)
                    $vcpkg_command += "]"
                } else {
                    $vcpkg_command += " $($node.Name)"
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
