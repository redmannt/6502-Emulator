@echo off

pushd %cwd%\build\test
%project%_test.exe
popd
