<#
.SYNOPSIS
    Fetches custom plugins defined in custom_plugins.json.

.DESCRIPTION
    Reads the plugin manifest from the repo root and clones/updates git-sourced
    plugins or downloads RedGuides-sourced plugins into the specified plugins
    directory. Only plugins that are enabled (or have no 'enabled' key) are
    processed.

.PARAMETER ClientTarget
    The build target: 'live', 'test', or 'emu'.
    Determines which plugin sections are processed ('all' is always included;
    'live_test' is included for live/test; 'emu' is included for emu).

.PARAMETER RedGuidesApiKey
    Optional. API key used as the XF-Api-Key header when fetching RedGuides
    resources. Required only when any plugin has type 'redguides'.

.PARAMETER BaseUrl
    Base URL for the RedGuides community site.
    Default: https://www.redguides.com/community

.PARAMETER PluginsDir
    Directory (relative to repo root) where plugins are placed.
    Default: plugins
#>

param(
    [Parameter(Mandatory = $true)]
    [ValidateSet('live', 'test', 'emu')]
    [string]$ClientTarget,

    [Parameter(Mandatory = $false)]
    [string]$RedGuidesApiKey = '',

    [Parameter(Mandatory = $false)]
    [string]$BaseUrl = 'https://www.redguides.com/community',

    [Parameter(Mandatory = $false)]
    [string]$PluginsDir = 'plugins'
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

# ---------------------------------------------------------------------------
# Resolve paths relative to the repo root (parent of the script's directory)
# ---------------------------------------------------------------------------
$ScriptDir    = Split-Path -Parent $MyInvocation.MyCommand.Path
$RepoRoot     = Split-Path -Parent $ScriptDir
$ManifestPath = Join-Path $RepoRoot 'custom_plugins.json'
$PluginsPath  = Join-Path $RepoRoot $PluginsDir

# ---------------------------------------------------------------------------
# Helper: derive a directory-safe name for a plugin entry
# ---------------------------------------------------------------------------
function Get-PluginName {
    param([hashtable]$Plugin)

    if ($Plugin.ContainsKey('name') -and -not [string]::IsNullOrWhiteSpace($Plugin['name'])) {
        return $Plugin['name']
    }

    if ($Plugin['type'] -eq 'git') {
        # Derive name from the last path segment of the URL, strip .git suffix
        $url  = $Plugin['url']
        $name = ($url.TrimEnd('/') -split '/')[-1] -replace '\.git$', ''
        return $name
    }

    if ($Plugin['type'] -eq 'redguides') {
        return "redguides-$($Plugin['resource_id'])"
    }

    throw "Cannot determine plugin name for entry: $($Plugin | ConvertTo-Json -Compress)"
}

# ---------------------------------------------------------------------------
# Helper: check whether a plugin entry is enabled (default: true)
# ---------------------------------------------------------------------------
function Test-PluginEnabled {
    param([hashtable]$Plugin)
    if ($Plugin.ContainsKey('enabled') -and $Plugin['enabled'] -eq $false) {
        return $false
    }
    return $true
}

# ---------------------------------------------------------------------------
# Process a single git plugin
# ---------------------------------------------------------------------------
function Invoke-GitPlugin {
    param(
        [hashtable]$Plugin,
        [string]$TargetDir
    )

    $url    = $Plugin['url']
    $branch = if ($Plugin.ContainsKey('branch') -and -not [string]::IsNullOrWhiteSpace($Plugin['branch'])) {
        $Plugin['branch']
    } else {
        $null
    }

    if (Test-Path (Join-Path $TargetDir '.git')) {
        Write-Host "  Updating existing clone at: $TargetDir"

        if ($branch) {
            $currentBranch = & git -C $TargetDir rev-parse --abbrev-ref HEAD 2>&1
            if ($currentBranch -ne $branch) {
                Write-Host "  Switching branch from '$currentBranch' to '$branch'"
                & git -C $TargetDir fetch --depth=1 origin $branch
                if ($LASTEXITCODE -ne 0) {
                    throw "git fetch failed for '$TargetDir' (branch: $branch)"
                }
                & git -C $TargetDir checkout $branch
                if ($LASTEXITCODE -ne 0) {
                    throw "git checkout '$branch' failed for '$TargetDir'"
                }
            }
        }

        & git -C $TargetDir pull --ff-only
        if ($LASTEXITCODE -ne 0) {
            throw "git pull failed for '$TargetDir'"
        }
    }
    else {
        Write-Host "  Cloning: $url -> $TargetDir"
        $cloneArgs = @('clone', '--depth', '1')
        if ($branch) {
            $cloneArgs += @('-b', $branch)
        }
        $cloneArgs += @($url, $TargetDir)

        & git @cloneArgs
        if ($LASTEXITCODE -ne 0) {
            throw "git clone failed for '$url'"
        }
    }

    Write-Host "  Initializing submodules for: $TargetDir"
    & git -C $TargetDir submodule update --init --recursive --depth=1
    if ($LASTEXITCODE -ne 0) {
        throw "git submodule update failed for '$TargetDir'"
    }
}

# ---------------------------------------------------------------------------
# Process a single redguides plugin
# ---------------------------------------------------------------------------
function Invoke-RedGuidesPlugin {
    param(
        [hashtable]$Plugin,
        [string]$TargetDir
    )

    if ([string]::IsNullOrWhiteSpace($RedGuidesApiKey)) {
        throw "RedGuides plugin '$($Plugin['resource_id'])' requires -RedGuidesApiKey but none was provided."
    }

    $resourceId = $Plugin['resource_id']
    $apiUrl     = "$BaseUrl/api/resources/$resourceId"

    Write-Host "  Fetching resource metadata: $apiUrl"
    $headers = @{ 'XF-Api-Key' = $RedGuidesApiKey }

    try {
        $response = Invoke-RestMethod -Uri $apiUrl -Headers $headers -Method Get
    }
    catch {
        throw "Failed to fetch RedGuides resource $resourceId`: $_"
    }

    $downloadUrl = $response.resource.current_files[0].download_url
    if ([string]::IsNullOrWhiteSpace($downloadUrl)) {
        throw "No download URL found for RedGuides resource $resourceId"
    }

    $tempZip = Join-Path ([System.IO.Path]::GetTempPath()) `
               "redguides-$resourceId-$([System.IO.Path]::GetRandomFileName()).zip"

    Write-Host "  Downloading: $downloadUrl"
    try {
        Invoke-WebRequest -Uri $downloadUrl -Headers $headers -OutFile $tempZip
    }
    catch {
        throw "Failed to download RedGuides resource $resourceId`: $_"
    }

    if (Test-Path $TargetDir) {
        Write-Host "  Removing existing directory: $TargetDir"
        Remove-Item -Recurse -Force $TargetDir
    }
    New-Item -ItemType Directory -Path $TargetDir | Out-Null

    Write-Host "  Extracting to: $TargetDir"
    try {
        Expand-Archive -Path $tempZip -DestinationPath $TargetDir -Force
    }
    catch {
        throw "Failed to extract archive for RedGuides resource $resourceId`: $_"
    }
    finally {
        if (Test-Path $tempZip) {
            Remove-Item -Force $tempZip
        }
    }
}

# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

# Validate manifest exists
if (-not (Test-Path $ManifestPath)) {
    Write-Error "Plugin manifest not found: $ManifestPath"
    exit 1
}

Write-Host "Reading plugin manifest: $ManifestPath"
$manifest = Get-Content $ManifestPath -Raw | ConvertFrom-Json

# Ensure plugins directory exists
if (-not (Test-Path $PluginsPath)) {
    New-Item -ItemType Directory -Path $PluginsPath | Out-Null
}

# Build list of sections to process
$sections = @('all')
if ($ClientTarget -eq 'emu') {
    $sections += 'emu'
}
else {
    $sections += 'live_test'
}

$totalProcessed = 0
$totalSkipped   = 0
$errors         = @()

foreach ($section in $sections) {
    # ConvertFrom-Json returns PSCustomObject; access property dynamically
    $sectionPlugins = $manifest.$section
    if ($null -eq $sectionPlugins) {
        Write-Host "Section '$section' not found in manifest, skipping."
        continue
    }

    Write-Host ""
    Write-Host "=== Processing section: $section ==="

    foreach ($entry in $sectionPlugins) {
        # Convert PSCustomObject to hashtable for uniform access
        $plugin = @{}
        $entry.PSObject.Properties | ForEach-Object { $plugin[$_.Name] = $_.Value }

        if (-not (Test-PluginEnabled -Plugin $plugin)) {
            $identity = if ($plugin.ContainsKey('url')) { $plugin['url'] } else { $plugin['resource_id'] }
            Write-Host "SKIP (disabled): $($plugin['type']) / $identity"
            $totalSkipped++
            continue
        }

        try {
            $pluginName = Get-PluginName -Plugin $plugin
            $targetDir  = Join-Path $PluginsPath $pluginName

            Write-Host "Processing plugin: $pluginName (type: $($plugin['type']))"

            switch ($plugin['type']) {
                'git' {
                    Invoke-GitPlugin -Plugin $plugin -TargetDir $targetDir
                }
                'redguides' {
                    Invoke-RedGuidesPlugin -Plugin $plugin -TargetDir $targetDir
                }
                default {
                    throw "Unknown plugin type '$($plugin['type'])' for plugin '$pluginName'"
                }
            }

            $totalProcessed++
            Write-Host "  Done: $pluginName"
        }
        catch {
            $msg = "ERROR processing plugin '$pluginName': $_"
            Write-Error $msg
            $errors += $msg
        }
    }
}

Write-Host ""
Write-Host "=== Fetch-CustomPlugins summary ==="
Write-Host "  Processed : $totalProcessed"
Write-Host "  Skipped   : $totalSkipped"
Write-Host "  Errors    : $($errors.Count)"

if ($errors.Count -gt 0) {
    Write-Host ""
    Write-Host "Errors encountered:"
    foreach ($e in $errors) {
        Write-Host "  - $e"
    }
    exit 1
}

exit 0
