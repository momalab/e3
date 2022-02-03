# Encrypt-Everything-Everywhere


E3 (Encrypt-Everything-Everywhere) is an easy-to-use open-source homomorphic encryption framework developed by the MoMA Lab at New York University Abu Dhabi. The framework provides C++ classes for supporting computation on private data. E3 is usability-oriented, allowing programmers to incorporate privacy to their programs without expertise in cryptography. In its first version, E3 encrypts variables using Fully Homomorphic Encryption and provides a rich set of C++ operators to the programmer.

Check out the [E3 Wiki](https://github.com/momalab/e3/wiki) for more information about the framework and usage guides. For examples of programs that you can create with E3, check out the [Tutorials Tab](./tutorials).

If you use our framework, please cite our paper titled "E3: A Framework for Compiling C++ Programs with Encrypted Operands", which can be found here: https://eprint.iacr.org/2018/1013. The paper describes the process of developing E3, as well as how to add new libraries to the framework.

# Quick setup

Here we show how to set up and test E3 on Linux. For Windows and MacOS please check our [wiki](https://github.com/momalab/e3/wiki/installing-e3).

## Dependencies

* git
* bash, sh
* make (at least version 3.79.1)
* a C++ compiler that supports C++17 (e.g. GCC ver >= 5.4.0)

## Setup

1. Clone E3:
```
git clone https://github.com/momalab/e3
```

2. Compile:
```
cd e3/src
make
```


# Example

Let's test E3 by running a simple example that does some arithmetic.

1. Create a directory anywhere you want. For this example, we will create a directory `examples/hello_world` at the root of E3:
```
mkdir -p examples/hello_world
```

2. We need to create a configuration file to tell E3 which encryption scheme(s) and parameters to use. At `examples/hello_world`, create a file called `cgt.cfg`:
```
# this is a comment
# name : type (name is arbitrary, type: bridge, circuit, native, ring)
Secure : circuit
{
    encryption = tfhe # encryption library/scheme
    postfix = Ep # for encrypted constants >= 0
    postneg = En # for encrypted constants < 0
    sizes = 8 # plaintext bit-size
}

```
The configuration file we just wrote defines one FHE library to be used in the program: TFHE, which we named Secure. We can use any combination of FHE libraries schemes, including the same library with different parameters.
The type 'circuit' works on bit-level arithmetic. E3 automatically creates three template classes for this type: SecureUint, SecureInt, and SecureBool. They are equivalent to unsigned int, int, and bool. We also defined the sizes of plaintexts that we will use in the program (8 bits).

3. Now, let's write our program. Create a text file called `main.cpp` in `examples/hello_world` and add the following code:

``` c++
#include <iostream>
#include "e3int.h"
#include "e3key.h" // includes support for decryption

using namespace std;

int main()
{
    // initializing variables
    SecureInt<8> a = _3_Ep, b = _2_En; // a = 3, b = -2;

    // homomorphic operations
    auto add = a + b;
    auto mul = a * b;

    // decrypting
    auto plain_a = e3::decrypt(a);
    auto plain_b = e3::decrypt(b);
    auto plain_add = e3::decrypt(add);
    auto plain_mul = e3::decrypt(mul);
    cout << plain_a << " + " << plain_b << " = " << plain_add << '\n';
    cout << plain_a << " * " << plain_b << " = " << plain_mul << '\n';
}

```

4. To compile, go to 'e3/src':
```
make alice USER=../examples/hello_world
```

5. Run:
```
./alice.exe
```
You should see this:
```
3 + -2 = 1
3 * -2 = -6
```

For more advanced use, check [E3 Wiki](https://github.com/momalab/e3/wiki) and [tutorials](./tutorials).

###### Versions - Documentation: 20091618; Software: 20091711

-----

### Cite us:

E. Chielle, O. Mazonka, H. Gamil, N. G. Tsoutsos and M. Maniatakos, "E3: A Framework for Compiling C++ Programs with Encrypted Operands," Cryptology ePrint Archive, Report 2018/1013, 2018, https://ia.cr/2018/1013.

```
@misc{cryptoeprint:2018:1013,
    author       = {Eduardo Chielle and
		    Oleg Mazonka and
		    Homer Gamil and
		    Nektarios Georgios Tsoutsos and
		    Michail Maniatakos},
    title        = {E3: A Framework for Compiling C++ Programs with Encrypted Operands},
    howpublished = {Cryptology ePrint Archive, Report 2018/1013},
    year         = {2018},
    note         = {\url{https://ia.cr/2018/1013}},
}
```

-----

This software is under GPLv3 [license](license.md)

<pre>
Copyright (C) 2022 NYUAD, MoMA lab
https://wp.nyu.edu/momalab/
</pre>

