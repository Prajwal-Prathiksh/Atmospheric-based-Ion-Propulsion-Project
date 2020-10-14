echo off
set LOCALHOST=%COMPUTERNAME%
set KILL_CMD="C:\PROGRA~1\ANSYSI~1\v202\fluent/ntbin/win64/winkill.exe"

"C:\PROGRA~1\ANSYSI~1\v202\fluent\ntbin\win64\tell.exe" Hope 49422 CLEANUP_EXITING
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 17520) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 18616) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 20208) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 11800) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 14720) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 13192)
del "E:\IIT Bombay - Miscellaneous\ITSP - Simulation Files\Atmospheric-based-Ion-Propulsion-Project\Chen2019 - Implementation - 1\cleanup-fluent-Hope-14720.bat"
