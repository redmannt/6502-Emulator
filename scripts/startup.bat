@echo off

set project=6502

set clpath="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall"

call %clpath% x64

set cwd=C:\Projects\%project%
set path=%cwd%\scripts;%path%

prompt ico@%project%$G

pushd ..\
