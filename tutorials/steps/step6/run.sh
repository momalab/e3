#!/bin/sh

e3=../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe e3int.h *.const *.obj
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./
cp $e3/src/e3int.h ./

echo "compiling"
if [ "$OS" =  "Windows_NT" ] ; then
  cl -EHsc -std:c++17 -Ox -I$e3/3p/seal_win/include \
       a.cpp secint.cpp cgtshared.cpp \
       -Febob.exe $e3/3p/seal_win/target/seal.lib
else
  g++ -std=c++17 -O2 -I$e3/3p/seal_unx/include \
       a.cpp secint.cpp cgtshared.cpp \
       -o bob.exe $e3/3p/seal_unx/target/libseal.a -lpthread

fi

echo "running bob.exe"
./bob.exe | $e3/src/cgt.exe dec

