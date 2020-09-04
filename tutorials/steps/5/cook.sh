#!/bin/sh

E3=../../..

#cp $E3/src/e3key.h ./

cp $E3/src/e3int.h ./
cp $E3/src/cgtshared.* ./
$E3/src/cgt.exe gen -r $E3/src

cl /EHsc -I$E3/3p/tfhe_win/inc/tfhe -I$E3/3p/tfhe_win/inc/fftwa -I$E3/3p/tfhe_win/inc/fftw3 a.cpp secint.cpp cgtshared.cpp -Febob.exe $E3/3p/tfhe_win/target/libfftw3-3.lib $E3/3p/tfhe_win/target/libtfhe.lib

cp $E3/3p/tfhe_win/target/libfftw3-3.dll ./

#cp $E3/src/e3key.h ./
#cp $E3/src/cgtkey.* ./
#cl /EHsc -DE3KEY=1 a.cpp secint.cpp cgtshared.cpp cgtkey.cpp -Fealice.exe

echo ""
echo run bob:
./bob.exe | $E3/src/cgt.exe dec

#echo run alice:
#./alice.exe
