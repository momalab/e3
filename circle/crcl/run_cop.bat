::make c
make -j 5
cd ..\cop
call cop clean
::start cmd /c cop all
call cop all
cd ..\crcl
::make c
::make -j 5
