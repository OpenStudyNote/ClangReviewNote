@echo off
set DIR=%cd%
echo Delete files of a specified type in batches
echo &set /p strtemp2="Please input  exe:"
setlocal enabledelayedexpansion
for /R %DIR% %%f in (*.%strtemp2%) do (
	echo %%f
	del %%f
)
echo All.%strtemp2% Successfully delete !
pause
