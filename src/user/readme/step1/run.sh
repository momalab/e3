#!/bin/sh

e3=../../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./

g++ -std=c++17 -O2 a.cpp secint.cpp cgtshared.cpp -o bob.exe

echo "Use command 'clean' to remove generated files"
