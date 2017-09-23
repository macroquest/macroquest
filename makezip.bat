@Echo Off

for /f "tokens=1-4 delims=/ " %%i in ("%date%") do (
     set dow=%%i
     set month=%%j
     set day=%%k
     set year=%%l
)
set datestr=MQ2-%year%%month%%day%.zip
del "%datestr%"
ECHO NOTE! This requires Winzip commandline addon in order to work...

"C:\Program Files (x86)\WinZip\wzzip.exe" -P "%datestr%" @zipit.lst

pause