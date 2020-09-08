# Encrypt-Everything-Everywhere
E<sup>3</sup> (Encrypt-Everything-Everywhere) is an easy-to-use open-source homomorphic encryption framework developed by the MoMA Lab at New York University Abu Dhabi. The framework provides C++ classes for supporting computation on private data. E<sup>3</sup> is usability-oriented, allowing programmers to incorporate privacy to their programs without expertise in cryptography.

In its first version, E<sup>3</sup> encrypts variables using Fully Homomorphic Encryption and provides a rich set of C++ operators to the programmer.

Check out the [E3 Wiki](https://github.com/momalab/e3/wiki) for more information about the framework and for installation and usage guides. For examples of programs that you can create with E<sup>3</sup>, check out the [Tutorials Tab](./tutorials).

If you use our framework, please cite our paper titled "E<sup>3</sup>: A Framework for Compiling C++ Programs with Encrypted Operands", which can be found here: https://eprint.iacr.org/2018/1013. The paper describes the process of using E<sup>3</sup>, as well as how to add new libraries to the framework.

# Quick setup

Here we show how to set up and test E3 on Linux. For Windows or more information check our [wiki](https://github.com/momalab/e3/wiki).

## Dependencies

* git
* bash, sh
* make (at least version 3.79.1)
* a C++ compiler that supports C++17 (GNU G++, GCC (\verb->=5.4.0-)

## Setup

1. Clone E3:
```
git clone https://github.com/momalab/e3
```

2. Compile the CGT tool:
```
cd e3/src
make
```

Done!

# Example - Hello world

Let's test E3 buy running a simple example that does some arithmetic.

1. Create a directory anywhere you want. For this example, we will create a directory 'examples/hello_world' at the root of E3:
```
mkdir -p examples/hello_world
```

2. Now we need to create a configuration file to tell the CGT tool which encryption scheme(s) and parameters to use. At 'examples/hello_world', create a file 'cgt.cfg':
```
# this is a comment
# name : type (name is arbitrary, type: bridge, circuit, native, ring)
Secure : circuit
{
    encryption = tfhe # encryption library/scheme
    postfix = Ep # for encrypted constants >= 0
	postneg = En # for encrypted constants < 0
    sizes = 8,16 # plaintext bit-size
}

SealRing : ring
{
    encryption = seal
    encoder = integer
    logn = 13 # degree of the polynomial n = 2^13
    t = 65537 # plaintext modulus
    postfix = Ea # for encrypted constants [0, t-1]
}
```
