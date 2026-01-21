# FileOperations.psm1
# Shared file I/O operations for conversion scripts

# Helper function to backup an existing file
function Backup-ExistingFile {
    param([string]$FilePath)

    if (Test-Path $FilePath) {
        $timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
        $backupPath = "$FilePath.backup_$timestamp"
        Copy-Item -Path $FilePath -Destination $backupPath -Force
        Write-Host "  Backed up existing file to: $backupPath" -ForegroundColor Yellow
    }
}

# Helper function to test if output path exists and handle force flag
function Test-OutputFileExists {
    param(
        [string]$OutputPath,
        [bool]$Force,
        [bool]$BackupExisting
    )

    $outputExists = Test-Path $OutputPath
    $needsForcePrompt = $outputExists -and -not $Force
    $needsBackup = $outputExists -and $BackupExisting -and $Force

    if ($needsForcePrompt) {
        Write-Host ""
        Write-Host "Output file already exists at: $OutputPath" -ForegroundColor Yellow
        Write-Host "Use -Force to overwrite the existing file" -ForegroundColor Yellow
        Write-Host "Use -BackupExisting with -Force to backup before overwriting" -ForegroundColor Yellow
        Write-Host ""
    }

    if ($needsBackup) {
        Backup-ExistingFile -FilePath $OutputPath
    }

    # Expression-based result
    -not $needsForcePrompt
}

Export-ModuleMember -Function Backup-ExistingFile, Test-OutputFileExists
