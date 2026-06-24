<#
.SYNOPSIS
  Single source of truth for the vcpkg cache contents and the vcpkg state fingerprint.

.DESCRIPTION
  Two related lists are defined here to minimize drift:

    CachePaths  - everything actions/cache must store to reconstitute a working vcpkg
    StateFiles  - the cheap, representative files whose contents define "which vcpkg"
                  we are on.

  The build job uses this to define the cache path, gate the save, and key/publish a
  fingerprint.

  A guard fails the run if a StateFile is ever not covered by a CachePath -- otherwise
  that file would be present on the build (fingerprint succeeds) but missing on a cold
  restore (fingerprint throws).

.PARAMETER Mode
  CachePaths  -> outputs the newline-separated cache path list (feed to actions/cache path:).
  Fingerprint -> outputs a single deterministic SHA-256 hash of the StateFiles' contents.

.PARAMETER MQRoot
  Repository root. Defaults to the current directory (the workspace root in CI).
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory)][ValidateSet('CachePaths', 'Fingerprint')][string]$Mode,
    [string]$MQRoot = (Get-Location).Path
)

$ErrorActionPreference = 'Stop'

# Everything the cache must store to restore a working vcpkg.
$CachePaths = @(
    'contrib/vcpkg/installed'
    'contrib/vcpkg/vcpkg.exe'
    'contrib/vcpkg-overlays/msbuild/vcpkg_mq_last_bootstrap-*.txt'
)

# Cheap files whose contents define "which vcpkg". MUST be a subset of $CachePaths.
$StateFiles = @(
    'contrib/vcpkg/installed/vcpkg/status'
    'contrib/vcpkg-overlays/msbuild/vcpkg_mq_last_bootstrap-*.txt'
)

foreach ($s in $StateFiles) {
    $covered = $CachePaths | Where-Object { $s -eq $_ -or $s.StartsWith("$_/") }
    if (-not $covered) {
        throw "Get-VcpkgState: StateFile '$s' is not covered by any CachePath. This will cause a false fingerprint mismatch."
    }
}

switch ($Mode) {
    'CachePaths' {
        $CachePaths
    }
    'Fingerprint' {
        $files = foreach ($pattern in $StateFiles) {
            $matched = Get-ChildItem -Path (Join-Path $MQRoot $pattern) -File -ErrorAction SilentlyContinue
            if (-not $matched) {
                throw "Get-VcpkgState: required state file(s) '$pattern' not found under '$MQRoot'. The fingerprint must cover every StateFile to be comparable across jobs."
            }
            $matched
        }
        # Hash each file, concatenate the per-file hashes in a stable order, then hash that deterministic fingerprint. Identical whenever the StateFiles' contents match.
        $combined = ($files | Sort-Object FullName | ForEach-Object {
                (Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash
            }) -join ''
        $digest = [System.Security.Cryptography.SHA256]::Create().ComputeHash([System.Text.Encoding]::UTF8.GetBytes($combined))
        (($digest | ForEach-Object { $_.ToString('x2') }) -join '')
    }
}
