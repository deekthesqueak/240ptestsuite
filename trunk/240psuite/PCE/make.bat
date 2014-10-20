@REM Path to the Huc compiler, The suite uses the one at: https://github.com/uli/huc
@set HUC_HOME=C:\Devel\PCE\huc

@path=%path%;%HUC_HOME%\bin
@set PCE_INCLUDE=%HUC_HOME%/include/pce

@REM Compile, assemble, and link
@REM -msmall causes scroll to crash
huc -s -t -O2 -fno-recursive 240pSuite.c font.c video.c patterns.c tests.c help.c
pceas -raw 240pSuite.s
@REM with -s & 
