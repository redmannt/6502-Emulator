@echo off

set main=%cwd%\test\main_test.cpp

set args=/O2 /MT /GA /GL /Gw /QIntel-jcc-erratum /Qpar
set warnings=/W4 /WX /wd4201 /wd4100 /wd4189 /wd4505 /wd4200

set comp_args=/nologo /Oi /GR- /EHa- /EHsc /FC /fp:fast %warnings%
set link_args=/link /incremental:no /opt:ref

set comp_args=%args% %comp_args% /Fe: %project%_test.exe

pushd %cwd%\build\test

cl %comp_args% %main% %link_args%

popd
