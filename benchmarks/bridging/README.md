# Bridging #

This directory contains benchmarks used to evaluate the bridging technique.
Each subdirectory contains a program implemented using plaintext, bit-level arithmetic, and bridging, which combines modular and bit-level arithmetic. For example, to run the matrix multiplication with SEAL, do the following:
```
cd e3/src
make c
make bob USER=../benchmarks/bridging/mm CGT=../benchmarks/bridging/cgt.cfg SEAL=1
./bob.exe > output.tmp
./cgt.exe dec -c ../benchmarks/bridging/cgt.cfg -f output.tmp
```

Conversely, one can run with Alice:
```
make alice USER=../benchmarks/bridging/mm CGT=../benchmarks/bridging/cgt.cfg SEAL=1
./alice.exe
```

**NOTE**: For `SEAL=1` to work, SEAL must be installed. Check [e3\\3p](../../../3p). If `SEAL=1` is not defined, the default `SEAL=0`, which uses a mockup library, is used.

# List of Benchmarks #
* [Fibonacci](fib/main.cpp)
* [Logistic Regression](log/main.cpp)
* [Max Function](maxd/main.cpp)
* [Matrix Multiplication](mm/main.cpp)
* [Multiplexer](mux/main.cpp)
* [Private Keyword Search](pks/main.cpp)
* [Product](prod/main.cpp)
* [Sorting](sort/main.cpp)
* [Summation](sum/main.cpp)

**NOTE**: Bit-level arithmetic may take a very long time to run. You may want run with SEAL=0 (mockup) or comment out the SecureUint and SecureInt blocks.

**NOTE**: The bit size set for bit-level arithmetic is 4. You can change it by modifying the [cgt.cfg](cgt.cfg) file and [lib/size.hpp](lib/size.hpp).

# Conversion #

Conversion from bit-level arithmetic (SecureUint, SecureInt, or SecureBool) to modular arithmetic (SecureMod) is integrated with the E3 framework. However, the reverse conversion is not since it is inefficient and we do not want to incentive its usage. In any case, the code from converting from modular to bit-level arithmetic is available in the following files:

* [From SecureMod to SecureUint/SecureInt](fromSecureMod/main.cpp)
* [From SecureMod to SecureBool](fromSecureModtoSecureBool/main.cpp)

# Cite us #

```
Eduardo Chielle, Oleg Mazonka, Homer Gamil, and Michail Maniatakos. 2022. Accelerating Fully Homomorphic Encryption by Bridging Modular and Bit-Level Arithmetic. In Proceedings of the 41st IEEE/ACM International Conference on Computer-Aided Design (ICCAD '22). Association for Computing Machinery, New York, NY, USA, Article 100, 1–9. https://doi.org/10.1145/3508352.3549415
```

```
@inproceedings{10.1145/3508352.3549415,
author = {Chielle, Eduardo and Mazonka, Oleg and Gamil, Homer and Maniatakos, Michail},
title = {Accelerating Fully Homomorphic Encryption by Bridging Modular and Bit-Level Arithmetic},
year = {2022},
isbn = {9781450392174},
publisher = {Association for Computing Machinery},
address = {New York, NY, USA},
url = {https://doi.org/10.1145/3508352.3549415},
doi = {10.1145/3508352.3549415},
booktitle = {Proceedings of the 41st IEEE/ACM International Conference on Computer-Aided Design},
articleno = {100},
numpages = {9},
keywords = {privacy-preserving computation, fully homomorphic encryption},
location = {San Diego, California},
series = {ICCAD '22}
}
```
