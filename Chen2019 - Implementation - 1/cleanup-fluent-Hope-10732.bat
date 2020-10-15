echo off
set LOCALHOST=%COMPUTERNAME%
set KILL_CMD="C:\PROGRA~1\ANSYSI~1\v202\fluent/ntbin/win64/winkill.exe"

"C:\PROGRA~1\ANSYSI~1\v202\fluent\ntbin\win64\tell.exe" Hope 49388 CLEANUP_EXITING
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 24960) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 10732) 
if /i "%LOCALHOST%"=="Hope" (%KILL_CMD% 15552)
del "E:\IIT Bombay - Miscellaneous\ITSP - Simulation Files\Atmospheric-based-Ion-Propulsion-Project\Chen2019 - Implementation - 1\cleanup-fluent-Hope-10732.bat"
