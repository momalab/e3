# Batching #

Each directory contains a program implemented using batching on top of bridging. For example, to run the matrix multiplication with SEAL, do the following:
```
cd e3/src
make c
make bob USER=../tutorials/bench/batch/matrix CGT=../tutorials/bench/batch/cgt_seal.cfg SEAL=1
./bob.exe > output.tmp
./cgt.exe dec -c ../tutorials/bench/batch/cgt_seal.cfg -f output.tmp
```

Conversely, one can run with Alice:
```
make alice USER=../tutorials/bench/batch/matrix CGT=../tutorials/bench/batch/cgt_seal.cfg SEAL=1
./alice.exe
```

**NOTE**: For `SEAL=1` to work, SEAL must be installed. Check [e3\\3p](../../../3p). If `SEAL=1` is not defined, the default `SEAL=0`, which uses a mockup library, is used.

# List of Programs #
* [Bubble Sort](bsort/main.cpp)
* [Factorial](fact/main.cpp)
* [Fibonacci](fib/main.cpp)
* [Insertion Sort](isort/main.cpp)
* [Jenkins](jen/main.cpp)
* [Matrix Multiplication](matrix/main.cpp)
* [Sieve of Eratosthenes](sieve/main.cpp)
* [Speck Cipher](speck/main.cpp)
