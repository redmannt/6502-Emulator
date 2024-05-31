@echo off

set main=%cwd%\test\main_test.cpp

set debug_args=/Z7 /Od /MTd /DDEBUG_BUILD=1
set warnings=/W4 /WX /wd4201 /wd4100 /wd4189 /wd4505

set comp_args=/nologo /Oi /GR- /EHa- /EHsc /FC /fp:fast %warnings%
set link_args=/link /incremental:no /opt:ref

set comp_args=%debug_args% %comp_args%

pushd %cwd%\build\test

cl %comp_args% %main% %link_args%

popd
