# E3 Framework Quick Start Guide

Encrypt-Everything-Everywhere (E<sup>3</sup>) computation paradigm allows non-crypto-savvy developers to *effortlessly* incorporate data privacy in their C++ programs. Specifically, E<sup>3</sup> offers secure cryptographic libraries that define new datatypes to *selectively* protect critical variables using end-to-end encryption for numerous real-life applications.

Given user program with a configuration file delineating the FHE scheme to be instantiated, E<sup>3</sup> build tool ('cgt.exe') is generated. This tool builds 'secret key' for decryption and 'evaluation key' needed to execute a compiled binary, and generates 'Framework API.cpp' file that gives access to the new secure datatypes. 

### Requirements
To build and use E<sup>3</sup>, your system must have the following tools available:
- **git**
- **make**
- C++ compiler that supports C++17 (**GNU G++, GCC** for Linux; **cl** for Windows)

Your program must include a configuration file (cgt.cfg), which contains parameters that define settings for building the program using E<sup>3</sup> framework. 

### How to Build
The easiest way to build is to do the following 4 steps:
1. Checkout repository
2. Go to src and build by `make`
3. You can run CGT with different options
4. You can build your own program with a corresponding config

The user code is built with 'bob.exe' file. Simply running `./bob.exe` gives the encrypted results.  
You can also decrypt the results using CGT:
```
./bob.exe | ./cgt.exe dec -c [USER PROGRAM CGT FILE]
```

For more details see FAQ and tests/tutorials.