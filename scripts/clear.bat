@echo off

pushd %cwd%\build

del *.pdb /q /s > NUL 2> NUL
del *.obj /q /s > NUL 2> NUL

popd
