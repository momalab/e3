# Encrypt-Everything-Everywhere (E3)

E<sup>3</sup> (Encrypt-Everything-Everywhere) is an easy-to-use open-source homomorphic encryption framework developed by the MoMA Lab at New York University Abu Dhabi. The framework provides C++ classes for supporting computation on private data. E<sup>3</sup> is usability-oriented, allowing programmers to incorporate privacy to their programs without expertise in cryptography.

In its first version, E<sup>3</sup> encrypts variables using Fully Homomorphic Encryption and provides a rich set of C++ operators to the programmer.

If you use our framework, please cite our paper titled "E<sup>3</sup>: A Framework for Compiling C++ Programs with Encrypted Operands", which can be found here: https://eprint.iacr.org/2018/1013. The paper describes the process of using E<sup>3</sup>, as well as how to add new libraries to the framework.

Current state: June 2019

# Contents
- [Introduction](#introduction)
  - [Homomorphic Encryption](#homomorphic-encryption)
  - [E3 Framework](#e3-framework)
- [Installing E3](#installing-e3)
  - [Windows](#windows)
  - [Linux](#linux)
- [Getting Started](#getting-started)
  - [Build Your Program](#build-your-program)
  - [Manual Build using cgt.exe](#manual-build-using-cgt.exe)
  - [Using alice.exe](#using-alice.exe)

# Introduction
The proliferation of ubiquitous computing and the recent advances in cloud services have amplified the reliance of millions of users to outsourced computation and storage for their data. Remote servers across the globe are becoming the virtual containers of sensitive data, from banking records and medical information to file storage and search queries. Numerous benefits of outsourcing, however, are often matched with several limitations in security and privacy guarantees offered to the end users. 

As with most data confidentiality problems, modern cryptography offers a wide range of primitives that can protect outsourced computation against known, or yet unknown, attacks. In the most common cases, cryptography is leveraged to protect *data at rest*, such as remote backups, as well as *data in transit*, such as network communications with remote servers. Nevertheless, the use of cryptography primitives while data are being manipulated inside processor pipelines (i.e., *data in use*) has been limited so far, since modern computer architectures, such as x86 and ARM, are unable to process encrypted values natively. E<sup>3</sup> is developed based on the thesis that *cryptography protections need to be retained through the lowest levels of  computation stack*, since any leakage or privacy violation would be meaningless as long as data remain encrypted.

## Homomorphic Encryption
One compelling solution that allows native manipulation of encrypted values within processor pipelines is the use of a cryptosystem that has *homomorphic* properties. Indeed, following the breakthrough discovery of fully homomorphic encryption (FHE), if sensitive data are protected using FHE, it is possible to apply any algorithm directly on ciphertext values so that the decrypted final output would be the same as if the original algorithm was applied on the plaintext values. In this case, critical data are never decrypted, even within the processor pipeline, so *any* data leakage or side-channel attack is meaningless: user privacy is always preserved due to the semantic security of encryption.

## E3 Framework
Encrypt-Everything-Everywhere (E<sup>3</sup>) computation paradigm allows non-crypto-savvy developers to *effortlessly* incorporate data privacy in their programs. Specifically, E<sup>3</sup> offers secure cryptographic libraries that define new datatypes to *selectively* protect critical variables using end-to-end encryption for numerous real-life applications.

Programming support for the E<sup>3</sup> computation paradigm is provided through a set of software libraries and helper tools. E<sup>3</sup> works as following. The end user (Alice) employs E<sup>3</sup> to compile a program with encrypted data and send it to Bob for execution. Given a user program with a configuration file delineating the FHE scheme to be instantiated, E<sup>3</sup> build tool ('cgt.exe') is generated. This tool builds 'secret key' for decryption and 'evaluation key' needed to execute a compiled binary, and generates 'Framework API.cpp' file that gives access to the new secure datatypes.

### Encryption Libraries

E<sup>3</sup> implements four external FHE libraries: TFHE, FHEW, HElib, and SEAL. FHEW and HElib are only supported in Linux. Which library to be used is decided by user and specified in the configuration file. Different libraries can be used simultaneously, and the same source code can be used for any library - users only need to slightly modify the configuration file.

**TFHE** implements a variant of the GSW scheme and supports evaluation of any Boolean circuit on encrypted values. Unrestricted circuit sizes are possible by incorporating *bootstrapping* in the evaluation of eachgate; gate-by-gate bootstrapping reduces the noise of FHE ciphertexts after each operation and allows applying an arbitrary function *after the data are already encrypted*. 

**FHEW** is a predecessor of TFHE and the first FHE library supporting per-gate bootstrapping using a homomorphic accumulator based on a variant of the GSW scheme. The latest version of FHEW implements a functionally-complete set of bitwise operations on the encryptions of bits, and each ciphertext output is refreshed using bootstrapping to reduce its noise to similar levels as the corresponding inputs. Thus, FHEW enables the homomorphic evaluation of any Boolean circuit on encrypted bits. 

**HElib** implements a ring-LWE variant of the BGV scheme (second generation FHE) with the GHS optimizations. It provides bootstrapping operations to reduce ciphertext noise, as well as *batching* to pack multiple plaintexts within the same ciphertext and enable SIMD-style operations. HElib is used to compose higher-level functions on multi-bit inputs as *circuits* (specifically, we implement multi-bit adders and multipliers) and to evaluate integer addition and multiplication, directly using multi-inputs as coefficients of *polynomials*. 

**SEAL** implements two different homomorphic encryption schemes: BFV scheme and CKKS scheme. The BFV allows modular arithmetic to be performed on encrypted integers, and the CKKS scheme allows addition and multiplication on encrypted real or complex numbers, but yields only approximate results. 

**NOTE**: FHEW has internal error (sic) forbidding binary operations on the same bits:
```
ERROR: Please only use independant ciphertexts as inputs.
```

E<sup>3</sup> also implements two internally-developed encryption schemes: BDD and PIL. **BDD** is developed using an external library called CUDD. **PIL** uses MPIR, a highly optimized library for bignum arithmetic. Both support full gate operations and full programming via circuits. PIL also supports direct addition, subtraction, and multiplication in modular arithmetic. No bootstrapping is necessary for both schemes since they are sufficiently fast (compared to TFHE).

While TFHE and FHEW libraries provide gates for circuits, gates for HElib, SEAL, BDD and PIL are created using arithmetic equations. Hence, arithmetic addition and multiplication are available and encouraged using HElib, SEAL, BDD and PIL. While arithmetic circuits excel in speed, they have limited operations. The goal is to maximize the use of arithmetic circuits by "bridging" boolean-to-arithmetic conversion. Detailed example with explanation can be found in tutorials.

# Installing E3
To build and use E<sup>3</sup>, your system must have the following tools available:
- **git**
- **make** (>=3.79.1)
- **sh, bash**
- C++ compiler that supports C++17 (**GNU G++, GCC** (>=5.4.0) for Linux; **cl** (>=19.10.25224) for Windows)

If you are using external encryption libraries, you need to install them first. E<sup>3</sup> provides scripts and instructions to install them. Yet the scripts do not automatically build some libraries. HElib, for instance, includes GMP and NTL libraries that are not automatically built by E<sup>3</sup> script. Some libraries require additional tools to successfully build. MPIR, for instance, requires Visual Studio 17 in Windows environment. Detailed instruction will be displayed if necessary.

Once you have the necessary tools in place, you may access the software by way of the MoMA Lab git server: [https://github.com/momalab/e3](https://github.com/momalab/e3). The easiest way to start is to `git clone` the software:
```
git clone https://github.com/momalab/e3.git
```

## Windows
Detailed instructions to set up in the Windows environment can be found in [Windows Set Up Guideline](Windows-Set-Up.md).

You can use Command Prompt, Powershell to use E<sup>3</sup> in Windows. 
- command line
- linux subsystem in windows
- powershell

Alternatively, you can also use Cygwin. While setting up Cygwin, make sure to include installing 'git', 'cl', and 'make' packages. 

Programs are compiled with Microsoft compiler, specifically cl, which can be installed and linked to Cygwin.

Step-by-step instructions of using the Microsoft C++ toolset from Cygwin can be found in [Windows Set Up Guideline](Windows-Set-Up.md).

Make sure that the following commands run in your Windows console shell:
```bash
$ cl
Microsoft (R) C/C++ Optimizing Compiler Version [version number] for [architecture type]
Copyright (C) Microsoft Corporation.  All rights reserved.
usage: cl [ option... ] filename... [ /link linkoption... ]
```
```bash
$ sh --help
GNU bash, version [version number (>=3.1.23)]
```
```bash
$ make -v
GNU Make version [version number (>=3.79.1)]
```

## Linux
E<sup>3</sup> is very easy to configure and build in Linux using GNU G++ (>=5.4.0). Additional libraries and tools necessary to build E<sup>3</sup> with external libraries will be checked and notified during the process.

Instructions for how to install and build E<sup>3</sup> can be found below.

## How to build
On the command line in the E<sup>3</sup> src directory:
```
cd e3/src
make
```
will compile and build the tool and default user program. Once built, run
```
make check
```
which will compile and run a series of test programs. This might take a few minutes. After running default tests, you are given a choice of which encryption library to check. Make sure to install the libraries before checking them. You can always return and check new libraries. Once checked, default programs will not be checked later.

For more details, see FAQ.

# Getting Started
In you C++ program, you need to annotate which variables to be encrypted, bearing in mind that the performance impact is related to the amount of operations performed on the encrypted variables. You should also develop/adapt the C++ source code to refrain from branching based on the encrypted data, since this will leak information and should be avoided. To address this problem, the algorithm needs to execute for a predetermined, upper-bounded amount of iterations (i.e., *obliviously*), which would ensure that a correct result will be reached. 

An example of this algorithm transformation is presented below with a variation of the Fibonacci algorithm. As shown in the example, you should replace regular integers (`int`) with our `SecureInt` class for PHE. If you need to initialize private variables with encrypted constants (without manually encrypting every value), you can append user-defined suffix `_E`, which will be recognized by our helper tool. The main loop iterates `MAX_NUM` times, which is the upper bound of the computation. Correct output is selected by the `i==num` comparison: when `i` reaches encrypted 7, `fi` is added to `res`, as the `i==num` expression returns an encrypted 1. In any other case, an encrypted 0 is added to `res`, not affecting the final output. Independent of the input, the above algorithm will always run for 10 iterations, therefore not leaking any context about the user input. `res` is an encrypted result, which you can decrypt afterwards.

```cpp
#include <iostream>
#include "e3ext.h"
#define MAX_NUM 10

int main () {
    SecureInt num = _7_E;
    SecureInt f1 = _1_E;
    SecureInt f2 = _1_E;
    SecureInt fi = _1_E;
    SecureInt i = _1_E;
    SecureInt res = _0_E;

    for( int cntr=0; cntr<MAX_NUM; cntr++ ) {
        res += (i == num) * fi;
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
        ++i;
    }

    std::cout << "fib: " << res << "\n";
}
```

In C++ terms, the termination problem means that a `SecureInt` cannot be implicitly cast to a `bool`, and the compiler will return an error. Thus, the expression '`if (x>y) {}`', with `x,y` defined as `SecureInt`, will fail to compile. Therefore, existing algorithms may need modifications to be converted to a data-oblivious version. Further information about data oblivious programming can be found in doc directory (DataObliviousProg.pdf).

Sample programs can be found in 'e3/tests/user' directory.

## Build Your Program
**WARNING: Before implementing E<sup>3</sup> to your program, we strongly advise you to follow tutorials. Any developer attempting to use E<sup>3</sup> without reading all tutorials or by simply re-using the code from the tutorials will inevitably produce code that is vulnerable, malfunctioning, or extremely slow. Tutorials can be found in e3/tests/tutorials.**

Your program must include a configuration file (cgt.cfg), which contains parameters that define settings for building the program using E<sup>3</sup> framework. Below is a simple full working example:

**Configuration file (cgt.cfg)**:
```
MyType : native
{
	postfix = EN
	postneg = ENn
}
```

Postfix for constants is optional. If not defined, constants are forbidden in the program. Postneg refers to postfix for signed values.

**Program file (.cpp)**:
```cpp
 #include <iostream>
 #include "e3int.h"

 using SecureInt = MyTypeInt<32>;
 SecureInt f(SecureInt x, SecureInt y){ return x + y; }

 int main()
 {
     SecureInt x = _7_EN, y = _3_ENn;
     y = f(x, y);
     std::cout << x << ' ' << y << "\n";
 }
```

Three basic integral types are generated by our tool: __int__, __unsigned int__, and __bool__. Their names are constructed from the basename specified in the configuration file by adding suffixes __Int__, __Uint__, and __Bool__ correspondingly. Bitsize of datatype is specified in brackets.

**NOTE**: When you are building programs more than once (e.g. using other encryption library), make sure to clean:
```
make clean
```
`make clean` cleans all the FHE API files, executable files, and object files.  
`make cleankey` cleans all files related to keys.  
`make cleanall` runs both `make clean` and `make cleanall`.  
`make c` cleans everything generated by building your program on E<sup>3</sup> platform.

### Using Built-In Encryption Library
By default, E<sup>3</sup> includes a built-in encryption library. To build your program, go to the e3/src directory and specify the pathway to your program directory:
```
cd e3/src
make USER=[user program directory]
```
Then, you can run thfe executable to get the encrypted result:
```
./bob.exe
```
To decrypt the received output, run:
```
./bob.exe | ./cgt.exe dec [-c cfg] [-n name] [-s bitsize]
``` 

On the command line, run `./cgt.exe help` to see instructions for commands and parameters.

### Using External Encryption Library
If you are using external encryption library (e.g. TFHE, HElib, FHEW, SEAL, MPIR), you need to first install the libraries. To install the libraries, run:
```
cd e3/3p
make [encryption library (e.g. TFHE, HELI, FHEW, SEAL, MPIR)]
```
**NOTE**: MPIR is used for PIL encryption.

**NOTE**: GMP and NTL required for HElib are not automatically installed by the command above. You need to go to the directories and manually configure and install necessary files. Instructions will be given when you run the command.

Then, you build your program. Make sure you append `[library name]=1` at the end of the `make` command:
```
cd ../src
make USER=[user program directory] [library name]=1
```

### Example
```
make USER=../../user/to_be_encrypted TFHE=1
./bob.exe | ./cgt.exe dec -c ../../user/to_be_encrypted/cgt.cfg -s 8
```
Here, your program and corresponding configuration file are stored in 'user/to_be_encrypted' directory outside 'e3' directory, and, thus, a relative path from 'e3/src' directory is specified. TFHE library is used for encryption, and plaintexts are considered as signed number with the bitsize of 8 (default is unsigned).

## Manual Build using cgt.exe
You can also manually build and run your program on E<sup>3</sup> framework.

1. You need to build the build tool (cgt.exe):
```
cd e3/src
make cgt.exe
```
2. Then, the framework needs to generate appropriate set of secret/evaluation keys. This process is required once per program. You can re-use the same keys for different programs by setting the configuration file parameters accordingly, given that the keys are stored in a file. Generation of keys is required before the first compilation, since the secret key is needed to encrypt the constants in the source code. As a result of following command, you will get a set of private/evaluation keys, secint.cpp, secint.h, and secint.inc. 
```
./cgt.exe gen -c [user configuration file] -d [user program directory]
```
3. You also need to compile object files needed to build bob.exe. This task will be automatically done using the amalgamation script (amalgam.sh). As a result of follwing command, you will get cgtshared.cpp and cgtshared.h. Run:
```
./amalgam.sh
```
4. The last part of the building process is to compile and link all necessary files (cgtshared.cpp, secint.cpp, and user codes) to generate bob.exe. 
In Linux, run:
```
g++ -I./ -I[user program directory] cgtshared.cpp secint.cpp [user program directory]/*.cpp -o./bob.exe
```
In Windows, run:
```
cl -EHsc -I./ -I[user program directory] cgtshared.cpp secint.cpp [user program directory]/*.cpp -Febob.exe
```

## Using alice.exe
When you build using the command `make`, it generates bob.exe, which gives an encrypted set of computation results if not decrypted otherwise using cgt.exe. However, you can immediately access the decrypted result by making alice.exe. In order to do so, a slight modification in your C++ codes is necessary.

First, you need to include "alice.h" file in your program. The file can be found in tests/user directory. Then, you only need to wrap your variables with 'dec()' or 'decs()'. 'decs()' is used for signed number. Keep your variables as they are when declaring them. Here is a simple example:
```cpp
 #include <iostream>
 #include "e3int.h"

 #include "alice.h"

 using SecureInt = MyTypeInt<32>;
 SecureInt f(SecureInt x, SecureInt y){ return x + y; }

 int main()
 {
     SecureInt x = _7_EN, y = _3_ENn;
     auto z = f(x, y);
     std::cout << dec(x) << "-" << decs(y) << "=" << dec(z) << "\n";
 }
```

To retrieve the decrypted results, run:
```
cd e3/src
make alice
./alice.exe
```
