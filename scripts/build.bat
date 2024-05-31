@echo off

set main=%cwd%\source\main.cpp

set debug_args=/Z7 /Od /MTd /DDEBUG_BUILD=1
set release_args=/O2 /MT /GA /GL /Gw /QIntel-jcc-erratum /Qpar
set warnings=/W4 /WX /wd4201 /wd4100 /wd4189 /wd4505

set common_linker=/link /incremental:no /opt:ref

set comp_args=/nologo /Oi /GR- /EHa- /EHsc /FC /fp:fast %warnings%
set link_args=%common_linker%

if "%1%" EQU "/r" ( 
    set comp_args=%release_args% %comp_args% 
    echo ~ Release build ~
) else (
    set comp_args=%debug_args% %comp_args%
    echo ~ Debug build ~ 
)

pushd %cwd%\build

cl %comp_args% %main% %link_args%

popd
