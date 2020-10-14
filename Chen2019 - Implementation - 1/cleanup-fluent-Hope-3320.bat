echo off
set LOCALHOST=%COMPUTERNAME%
set KILL_CMD="C:\PROGRA~1\ANSYSI~1\v202\fluent/ntbin/win64/winkill.exe"

"C:\PROGRA~1\ANSYSI~1\v202\fluent\ntbin\win64\tell.exe" Hope 50376 CLEANUP_EXITING
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 7676) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 3384) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 18264) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 17168) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 3320) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 6972)
del "E:\IIT Bombay - Miscellaneous\ITSP - Simulation Files\Atmospheric-based-Ion-Propulsion-Project\Chen2019 - Implementation - 1\cleanup-fluent-Hope-3320.bat"
