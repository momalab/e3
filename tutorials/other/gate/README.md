# Gate-Level Computation #

This tutorial shows how to access and operate on homomorphic gates. The bits of a SecureInt ([Bit-Level-Arithmetic](../../bench/bit)) can be accessed as items of a vector. Then, one can use the gate function of the SecureBit class to operate on them. Check the source files for more detail. To compile and run, do the following:
```
cd e3/src
make c
make bob USER=../tutorials/other/gate TFHE=1
./bob.exe > output.tmp
./cgt.exe dec -c ../tutorials/other/gate/cgt.cfg -f output.tmp
```

**NOTE**: For `TFHE=1` to work, TFHE must be installed. Check [e3\\3p](../../../3p). If `TFHE=1` is not defined, the default `TFHE=0`, which uses a mockup library, is used.

**NOTE**: To make and run the alice executable successfully, make sure to wrap cout statement in e3::decrypt() and include the "e3key.h" header file in main.cpp
