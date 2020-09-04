#!/bin/sh

E3=../../..

cp $E3/src/e3key.h ./

cp $E3/src/e3int.h ./
cp $E3/src/cgtshared.* ./
$E3/src/cgt.exe gen -r $E3/src
cl /EHsc a.cpp secint.cpp cgtshared.cpp -Febob.exe

cp $E3/src/e3key.h ./
cp $E3/src/cgtkey.* ./
cl /EHsc -DE3KEY=1 a.cpp secint.cpp cgtshared.cpp cgtkey.cpp -Fealice.exe

echo ""
echo run bob:
./bob.exe | $E3/src/cgt.exe dec

echo run alice:
./alice.exe
