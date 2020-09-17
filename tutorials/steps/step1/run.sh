#!/bin/sh

e3=../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe *.obj
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./

if [ "$OS" =  "Windows_NT" ] ; then
  cl -EHsc -std:c++17 -Ox a.cpp secint.cpp cgtshared.cpp -Febob.exe
else
  g++ -std=c++17 -O2 a.cpp secint.cpp cgtshared.cpp -o bob.exe
fi

echo "Use command 'clean' to remove generated files"
