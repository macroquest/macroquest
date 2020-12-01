param([string]$VCPkgRoot);
Set-Location $VCPkgRoot
if (!(Test-Path ".\vcpkg.exe")) {
    & ".\bootstrap-vcpkg.bat"
}
& ".\vcpkg.exe" install luajit:x86-windows-static