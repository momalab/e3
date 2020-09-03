# Bit-Level Arithmetic #

Each directory contains a program implemented using bit-level arithmetic. There are two configuration files available, one for [SEAL](cgt_seal.cfg) and one for [TFHE](cgt_tfhe.cfg). For example, to run the matrix multiplication with TFHE, do the following:
```
cd e3/src
make c
make bob USER=../tutorials/bench/bit/matrix CGT=../tutorials/bench/bit/cgt_tfhe.cfg TFHE=1
./bob.exe > output.tmp
./cgt.exe dec -c ../tutorials/bench/bit/cgt_tfhe.cfg -f output.tmp
```

Conversely, one can run with Alice:
```
make alice USER=../tutorials/bench/bit/matrix CGT=../tutorials/bench/bit/cgt_tfhe.cfg TFHE=1
./alice.exe
```

**NOTE**: For `TFHE=1` to work, TFHE must be installed. Check [e3\\3p](../../../3p). If `TFHE=1` is not defined, the default `TFHE=0`, which uses a mockup library, is used.

# List of Programs #
* [Bubble Sort](bsort/main.cpp)
* [Factorial](fact/main.cpp)
* [Fibonacci](fib/main.cpp)
* [Insertion Sort](isort/main.cpp)
* [Jenkins](jen/main.cpp)
* [Matrix Multiplication](matrix/main.cpp)
* [Sieve of Eratosthenes](sieve/main.cpp)
* [Speck Cipher](speck/main.cpp)
