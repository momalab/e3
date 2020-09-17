#!/bin/sh

e3=../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe e3int.h e3key.h cgtkey.* *.obj
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./
cp $e3/src/cgtkey.* ./
cp $e3/src/e3int.h ./
cp $e3/src/e3key.h ./

if [ "$OS" =  "Windows_NT" ] ; then
  cl -EHsc -std:c++17 -Ox -DE3KEY=1 a.cpp secint.cpp cgtshared.cpp cgtkey.cpp -Fealice.exe
else
  g++ -std=c++17 -DE3KEY=1 a.cpp secint.cpp cgtshared.cpp cgtkey.cpp -o alice.exe
fi

./alice.exe

