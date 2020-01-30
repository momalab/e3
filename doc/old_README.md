# E<sup>3</sup> Framework

E<sup>3</sup> (Encrypt-Everything-Everywhere) is a framework 
providing C++ classes for supporting computation on private 
data. E<sup>3</sup> is usability-oriented, allowing 
programmers to incorporate privacy to their 
programs without expertise in cryptography.

In its first version, E<sup>3</sup> encrypts variables 
using Fully Homomorphic Encryption and provides 
a rich set of C++ operators to the programmer.

If you use our framework, please cite our paper 
titled "E<sup>3</sup>: A Framework for Compiling C++ 
Programs with Encrypted Operands", which can be found 
here: https://eprint.iacr.org/2018/1013.
The paper describes the process of using E<sup>3</sup>,
as well as how to add new libraries to the framework.

## Current state: 1 Nov 2018

### TFHE
Implemented and working TFHE in Linux and Windows

### HELib
Implemented HELib for Linux, Windows is not supported.

### FHEW
Implemented FHEW for Linux. FHEW has an internal error (sic)
```
ERROR: Please only use independant ciphertexts as inputs.
```
forbidding binary operations on the same bits.


## Running examples
### The simplest example

This example builds executable using a mock-up
encryption. No 3rd party libraries are necessary.

Check out the repository, e.g. `/home/user/e3`.
Go to `./src ` and build `cgt.exe` tool:
```bash
$ make -f mak_cgt.mak
$ ls cgt.exe
cgt.exe
```
Go to `./demo/001`. This is a user directory where the C++ source files are.
This directory can be in any place. Copy a script building the binaries
into the current directory:
```bash
$ cp ../../src/e3work.sh ./
```
This script requires as the first argument the directory of the checked out
E<sup>3</sup> repository. It can be either absolute or relative path. In this
case:
```bash
$ bash e3work.sh ../../
```
The script builds the keys and the executable `bob.exe`.
```bash
$ ./bob.exe
0000000000000805
$ ./bob.exe | ../../src/cgt.exe dec
5
```
This is the result of adding 2+3 as described in `a.cpp`.

### The example 2

This example uses TFHE library as the encryption engine.

First go to `./3p` directory and build the dependent TFHE library:
```bash
$ make TFHE
```
This step creates a directory and builds a test executable inside `test.exe`.

Next, go back to `./src` to rebuild cgt with TFHE
```bash
make -f mak_cgt.mak clean
make -f mak_cgt.mak TFHE=1
```

Go to `./demo/001` and do the rest as in the previous example.
The executable is built:
```bash
$ ./bob.exe | ../../src/cgt.exe dec
5
```

## Building on Windows

Make sure that the following commands run in your Windows console shell:
```bash
$ make
make: *** No targets specified and no makefile found.  Stop.
```
```bash
$ cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25224 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.
usage: cl [ option... ] filename... [ /link linkoption... ]
```
```bash
$ sh --help
GNU bash, version 4.1.17(9)-release-(i686-pc-cygwin)
```
```bash
$ bash --help
GNU bash, version 4.1.17(9)-release-(i686-pc-cygwin)
```

= end of description
