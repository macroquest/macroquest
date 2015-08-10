@echo off
set SOLUTIONDIR=%~1
set TARGETDIR=%~2
set TARGET_BASE=%3
set TARGET_BINARY=%3*.dll
set TARGET_SYMBOL=%3*.pdb

:: delims is a TAB followed by a space
if not defined InnerSpacePath FOR /F "tokens=2* delims=	 " %%A IN ('REG QUERY "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\App Paths\InnerSpace.exe" /v "Path"') DO SET InnerSpacePath=%%B
if not defined InnerSpacePath FOR /F "tokens=2* delims=	 " %%A IN ('REG QUERY "HKCU\Software\Microsoft\IntelliPoint\AppSpecific\InnerSpace.exe" /v "Path"') DO SET InnerSpacePath=%%B
if not defined InnerSpacePath FOR /F "tokens=2* delims=	 " %%A IN ('REG QUERY "HKCU\Software\Microsoft\IntelliType Pro\AppSpecific\InnerSpace.exe" /v "Path"') DO SET InnerSpacePath=%%B
if not defined InnerSpacePath goto :ERROR

if "%InnerSpacePath:~-15%" == "\InnerSpace.exe" set InnerSpacePath=%InnerSpacePath:~0,-15%

set SYMBOLCACHE=N:\SymbolCache\Personal

:COPY_DLL
	IF EXIST "%InnerSpacePath%\Extensions\%TARGET_BINARY%" (
		echo Removing existing "%InnerSpacePath%\Extensions\%TARGET_BINARY%"
		del "%InnerSpacePath%\Extensions\%TARGET_BINARY%"
		IF EXIST "%InnerSpacePath%\Extensions\%TARGET_BINARY%" (
			echo "%InnerSpacePath%\Extensions\%TARGET_BINARY%" is in use, unable to delete!
			exit /B 1
		)
	)
	echo PostBuild: Copying %TARGET_BINARY% to "%InnerSpacePath%\Extensions\%TARGET_BINARY%"
	copy /Y "%TARGETDIR%\%TARGET_BINARY%" "%InnerSpacePath%\Extensions\%TARGET_BINARY%"
	echo PostBuild: Copying %TARGET_SYMBOL% to "%InnerSpacePath%\Extensions\%TARGET_SYMBOL%"
	copy /Y "%TARGETDIR%\%TARGET_SYMBOL%" "%InnerSpacePath%\Extensions\%TARGET_SYMBOL%"
	goto COPY_CHANGELOG

:COPY_CHANGELOG
	echo PostBuild: Copying Changes-%TARGET_BASE%.txt to "%InnerSpacePath%\Extensions\Changes-%TARGET_BASE%.txt"
	copy /Y "%SOLUTIONDIR%\Release\Changes-%TARGET_BASE%.txt" "%InnerSpacePath%\Extensions\Changes-%TARGET_BASE%.txt"
	echo PostBuild: Copying Changes.txt to "%InnerSpacePath%\Extensions\Changes-MQ2.txt"
	copy /Y "%SOLUTIONDIR%\Release\Changes.txt" "%InnerSpacePath%\Extensions\Changes-MQ2.txt"

	goto COPY_SYMBOLS

:COPY_SYMBOLS
	IF EXIST "C:\Program Files (x86)\Windows Kits\8.0\Debuggers\x86\symstore.exe" goto COPY_SYMBOLS_SymStorePath1
	goto DONE

:COPY_SYMBOLS_SymStorePath1
@REM To use this setup, set
@REM   _NT_SYMBOL_PATH=N:\SymbolCache\Personal;srv*N:\SymbolCache\Microsoft*http://msdl.microsoft.com/download/symbols
@REM Note that there are TWO dirs there, the Personal dir, and the Microsoft cache dir. The Personal dir is ONLY for files
@REM locally generated, and the Microsoft dir is the cache for files from the MS Symbol Server
	IF NOT EXIST "%SYMBOLCACHE%" GOTO DONE

	echo PostBuild: Committing DLL files to Personal Symbol Store...
	C:\"Program Files (x86)"\"Windows Kits"\"8.0"\Debuggers\x86\symstore.exe add /r /f "%SOLUTIONDIR%Release\*.dll" /s "%SYMBOLCACHE%" /t %TARGET_BASE% /z pri

	echo PostBuild: Committing PDB files to Personal Symbol Store...
	C:\"Program Files (x86)"\"Windows Kits"\"8.0"\Debuggers\x86\symstore.exe add /r /f "%SOLUTIONDIR%Release\*.pdb" /s "%SYMBOLCACHE%" /t %TARGET_BASE% /z pri

	echo PostBuild: Deleting symbols which haven't been accessed in 100 days
	C:\"Program Files (x86)"\"Windows Kits"\"8.0"\Debuggers\x86\agestore.exe %SYMBOLCACHE% -days=100 -k -y -q
	goto DONE

:ERROR
	echo Error
	exit /B 1
:DONE
	IF NOT EXIST "%InnerSpacePath%\Extensions\%TARGET_BINARY%" (
		echo "%InnerSpacePath%\Extensions\%TARGET_BINARY%" does not exist!
		exit /B 1
	)
	exit /B 0

