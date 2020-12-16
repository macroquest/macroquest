param([string]$VCPkgRoot);
Set-Location $VCPkgRoot
if (!(Test-Path ".\vcpkg.exe")) {
    & ".\bootstrap-vcpkg.bat"
}
& ".\vcpkg.exe" install --triplet x86-windows-static luajit sol2