# This script is referenced from vcpkg_mq.ps1 for pre-flight checks as well as being the prebuild for MQ2Main.
# Any modifications should take this into account.

# This will have to be modified when VS2022 comes out (64 bit)
$vswherePath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"

if (-Not (Test-Path -Path $vswherePath -PathType Leaf))
{
    Write-Warning "Crashpad build relies on chromium which relies on vswhere. You may have issues, could not find: $vswherePath"
}
else
{
    $vswhereResult = & $vswherePath -latest -property installationPath
    if ([string]::IsNullOrWhiteSpace($vswhereResult))
    {
        Write-Warning "Crashpad build relies on chromium which relies on vswhere for your path.  vswhere did not return a path.  Make sure a current build of Visual Studio (not Preview) is installed."
    }
    else
    {
        $vcvarsAllPath = "$vswhereResult\VC\Auxiliary\Build\vcvarsall.bat"
        if (-Not (Test-Path -Path $vcvarsAllPath -PathType Leaf))
        {
            Write-Warning "Building relies on vcvarsall.bat which could not be found.  Check your Visual Studio installation for proper msvc c++ components.  Path searched: $vcvarsAllPath"
        }
    }
}

$systemLocale = (Get-WinSystemLocale).Name
if (-Not $systemLocale.StartsWith("en"))
{
    Write-Warning "You may have problems building if you have non-unicode characters in your paths.  To resolve this issue, change your system locale to English"
}