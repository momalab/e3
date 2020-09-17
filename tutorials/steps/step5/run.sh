#!/bin/sh

e3=../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe e3int.h *.const libfftw3-3.dll *.obj
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./
cp $e3/src/e3int.h ./

echo "compiling"
if [ "$OS" =  "Windows_NT" ] ; then
  cl -EHsc -std:c++17 -Ox -I$e3/3p/tfhe_win/inc/tfhe -I$e3/3p/tfhe_win/inc/fftwa \
       -I$e3/3p/tfhe_win/inc/fftw3 a.cpp secint.cpp cgtshared.cpp \
       -Febob.exe $e3/3p/tfhe_win/target/libtfhe.lib \
       $e3/3p/tfhe_win/target/libfftw3-3.lib

       cp $e3/3p/tfhe_win/target/libfftw3-3.dll ./
else
g++ -std=c++17 -I$e3/3p/tfhe_unx/inc/tfhe -I$e3/3p/tfhe_unx/inc/fftwa \
       -I$e3/3p/tfhe_unx/inc/fftw3 a.cpp secint.cpp cgtshared.cpp \
       -o bob.exe $e3/3p/tfhe_unx/target/libtfhe.a \
       $e3/3p/tfhe_unx/target/libfftw3.a
fi


echo "running bob.exe"
./bob.exe | $e3/src/cgt.exe dec

