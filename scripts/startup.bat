@echo off

set project=6502

set clpath="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"

call %clpath% x64

set cwd=C:\Projects\%project%
set path=%cwd%\scripts;%path%
set path=%cwd%\scripts\test;%path%

prompt ico@%project%$G

pushd ..\
