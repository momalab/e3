# Specialized Circuits #

Each directory contains a program implemented using specialized circuits. For example, to run the matrix multiplication with SEAL, do the following:
```
cd e3/src
make c
make USER=../tutorials/bench/spec/matrix CGT=../tutorials/bench/spec/cgt_tfhe.cfg TFHE=1
./bob.exe > output.tmp
./cgt.exe dec -c ../tutorials/bench/spec/cgt_tfhe.cfg -f output.tmp
```

Conversely, one can run with Alice:
```
make alice USER=../tutorials/bench/spec/matrix CGT=../tutorials/bench/spec/cgt_tfhe.cfg TFHE=1
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
