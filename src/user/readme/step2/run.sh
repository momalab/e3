#!/bin/sh

e3=../../../..

if [ "$1" = "clean" ] ; then
  echo cleaning
  rm -f *.key secint.* cgtshared.* *.exe e3int.h
  exit
fi

$e3/src/cgt.exe gen -r $e3/src
cp $e3/src/cgtshared.* ./
cp $e3/src/e3int.* ./

g++ -std=c++17 a.cpp secint.cpp cgtshared.cpp -o bob.exe
./bob.exe | $e3/src/cgt.exe dec

