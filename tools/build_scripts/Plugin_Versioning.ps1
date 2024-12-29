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
    [string]$ProjectDirectory
)

$CPPFile = Get-ChildItem -Path $ProjectDirectory -Recurse -Filter "$ProjectName.cpp"
$ResFile = Get-ChildItem -Path $ProjectDirectory -Recurse -Filter "$ProjectName.rc"
if ($CPPFile.count -eq 1 -and $ResFile.count -eq 1) {
    $VersionMatch = Select-String -Path $CPPFile -Pattern 'PLUGIN_VERSION\((.*)\)'
    $Version = $VersionMatch.Matches.Groups[1].Value

    If ($Version) {
        $VersionCommas = $Version -replace '\.', ','
        $OriginalFile = Get-Content $ResFile.FullName
        $NewFile = $OriginalFile | ForEach-Object {
            $_ -replace 'FILEVERSION (.*)', "FILEVERSION $VersionCommas" `
            -replace 'PRODUCTVERSION (.*)', "PRODUCTVERSION $VersionCommas" `
            -replace 'VALUE "FileVersion", (.*)', "VALUE `"FileVersion`", `"$Version`"" `
            -replace 'VALUE "ProductVersion", (.*)', "VALUE `"ProductVersion`", `"$Version`""
        }
        if ($OriginalFile -ne $NewFile) {
            $NewFile | Set-Content $ResFile.FullName
        }
    }
}