echo off
set LOCALHOST=%COMPUTERNAME%
set KILL_CMD="C:\PROGRA~1\ANSYSI~1\v202\fluent/ntbin/win64/winkill.exe"

"C:\PROGRA~1\ANSYSI~1\v202\fluent\ntbin\win64\tell.exe" Hope 54812 CLEANUP_EXITING
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 18700) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 4448) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 19320) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 5944) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 15996) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 5532)
del "E:\IIT Bombay - Miscellaneous\ITSP - Simulation Files\Atmospheric-based-Ion-Propulsion-Project\Chen2019 - Implementation - 1\cleanup-fluent-Hope-15996.bat"
