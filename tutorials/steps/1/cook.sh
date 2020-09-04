#!/bin/sh

e3=../../..

cp $e3/src/e3int.h ./
cp $e3/src/cgtshared.* ./
$e3/src/cgt.exe gen -r $e3/src
cl /EHsc a.cpp secint.cpp cgtshared.cpp -Febob.exe

echo ""
echo run bob:
./bob.exe | $e3/src/cgt.exe dec
