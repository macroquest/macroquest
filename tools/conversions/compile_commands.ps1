# You can pass the project or solution file as the first argument to this script
# use like: `./compile_commands.ps1 ./build/MacroQuest.sln > ./build/compile_commands.json`

$include = '';
$output = @()
$extra_args = '-fdriver-only', '-clang:-MJ-';

# Avoiding parallelism is required to avoid interleaving
MSBuild -noLogo -v:d -t:ClCompile -m:1 `
        -p:MultiProcMaxCount=1 `
        -p:ContinueOnError=true `
        -p:PlatformToolset=ClangCL `
        -p:ClangClAdditionalOptions=$([string]::Join(' ', $extra_args)) `
        @Args | ForEach-Object {
    if ($_.TrimStart().StartsWith('INCLUDE=')) {
        $include = $_.Substring($_.IndexOf('=') + 1)
    } elseif ($_.TrimStart() -match '"directory":') {
        $include_args = $include.Split([IO.Path]::PathSeparator) |
                ? { $_.Length } |
                % { @('-imsvc', $_) }

        $json = $_.TrimEnd(',') | ConvertFrom-Json;

        $converted_json = [PSCustomObject]@{
            directory = $json.directory
            file = $json.file
            arguments = (($json.arguments | ? { -not ($extra_args -contains $_) }) + $include_args)
        }

        $output += $converted_json
        $include = '';
    }
}

$output | ConvertTo-Json
