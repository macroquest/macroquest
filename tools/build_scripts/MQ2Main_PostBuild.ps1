$location = Get-Location

function Copy-Latestfile {
	Param($File1, $File2, $Relative)
	#Write-Host "Copy $File1 to $File2 ..."

	if (![System.IO.File]::Exists($File1)) {
		return
	}
	$File1Date = Get-Item $File1 | ForEach-Object{ $_.LastWriteTimeUtc }

	# make sure dest directory exists
	$dir = Split-Path -Parent $File2
	$dirExists = Test-Path -Path $dir -PathType Container
	if (-Not $dirExists)
	{
		Write-Host "DirName: $dir"
		New-Item -ItemType Directory -Path $dir | Out-Null
	}

	if (![System.IO.File]::Exists($File2)) {
		try {
			New-Item -ItemType HardLink -Path $File2 -Value $File1 | Out-Null

			$File2 = Resolve-Path $File2
			Write-Host "Linking $File2..."
		}
		catch {
			Copy-Item -Path $File1 -Dest $File2 -Force

			$File2 = Resolve-Path $File2
			Write-Host "Copying $File2..."
		}
		return
	}

	$File2 = Resolve-Path $File2
	$File2Date = Get-Item $File2 | ForEach-Object{ $_.LastWriteTimeUtc }

	if ($File1Date -gt $File2Date)
	{
		Remove-Item -Path $File2
		try {
			New-Item -ItemType HardLink -Path $File2 -Value $File1

			$File2 = Resolve-Path $File2
			Write-Host "Linking $File2..."
		}
		catch {
			Copy-Item -Path $File1 -Dest $File2 -Force

			$File2 = Resolve-Path $File2
			Write-Host "Copying $File2..."
		}
	}
}

try {
	$Src = $args[0]
	$Dst = $args[1]
	#Write-Output $Src $Dst

	$ListFile = "$Src\BinCopy.txt"
	Set-Location $Src

	$lines = Get-Content $ListFile 
	foreach ($line in $lines)
	{
		$files = Get-ChildItem -Path "$Src\$line" | % { $_.FullName }
		foreach ($file in $files)
		{
			$relative = Resolve-Path -Relative $file
			Copy-LatestFile $file "$Dst\$relative" $relative
		}
	}

	# Copy crash reporter
	Copy-LatestFile "$Src\..\contrib\vcpkg\installed\x86-windows-static\tools\crashpad_handler.exe" "$Dst\mq_crash_handler.exe" "mq_crash_handler.exe"
}
catch {
	Write-Output $_
	Set-Location $location

	exit 1
}

Set-Location $location