echo off
set LOCALHOST=%COMPUTERNAME%
set KILL_CMD="C:\PROGRA~1\ANSYSI~1\v202\fluent/ntbin/win64/winkill.exe"

"C:\PROGRA~1\ANSYSI~1\v202\fluent\ntbin\win64\tell.exe" Hope 49505 CLEANUP_EXITING
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 18220) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 22824) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 24084)
del "E:\IIT Bombay - Miscellaneous\ITSP - Simulation Files\Atmospheric-based-Ion-Propulsion-Project\Chen2019 - Implementation - 1\cleanup-fluent-Hope-22824.bat"
