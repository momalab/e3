#!/bin/sh

e3=../../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe e3int.h *.const
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./
cp $e3/src/e3int.h ./

echo "compiling"
g++ -std=c++17 -I$e3/3p/tfhe_unx/inc/tfhe -I$e3/3p/tfhe_unx/inc/fftwa \
       -I$e3/3p/tfhe_unx/inc/fftw3 a.cpp secint.cpp cgtshared.cpp \
       -o bob.exe $e3/3p/tfhe_unx/target/libtfhe.a \
       $e3/3p/tfhe_unx/target/libfftw3.a

echo "running bob.exe"
./bob.exe | $e3/src/cgt.exe dec

