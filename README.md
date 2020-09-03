# Encrypt-Everything-Everywhere
E<sup>3</sup> (Encrypt-Everything-Everywhere) is an easy-to-use open-source homomorphic encryption framework developed by the MoMA Lab at New York University Abu Dhabi. The framework provides C++ classes for supporting computation on private data. E<sup>3</sup> is usability-oriented, allowing programmers to incorporate privacy to their programs without expertise in cryptography.

In its first version, E<sup>3</sup> encrypts variables using Fully Homomorphic Encryption and provides a rich set of C++ operators to the programmer.

Check out the [E3 Wiki](https://github.com/momalab/e3test/wiki) for more information about the framework and for installation and usage guides. For examples of programs that you can create with E<sup>3</sup>, check out the [Tutorials Tab](https://github.com/momalab/e3test/tree/master/tutorials). 

If you use our framework, please cite our paper titled "E<sup>3</sup>: A Framework for Compiling C++ Programs with Encrypted Operands", which can be found here: https://eprint.iacr.org/2018/1013. The paper describes the process of using E<sup>3</sup>, as well as how to add new libraries to the framework.

Current state: July 2020

## E<sup>3</sup> Directory Structure
                         
    |- 3p
    |- circle
    |  |- crcl            
    |  |- cudd0
    |      |- c30
    |  |- cudd1
    |      |- c30
    |- src
    |  |- cpp_cgt
    |     |- keys
    |     |- main
    |     |- util
    |        |- unx
    |        |- win
    |  |- cpp_crcl
    |  |- cpp_share
    |     |- keys
    |     |- util
    |  |- db
    |     |- circle
    |     |- circuit
    |     |- templ
    |  |- e3x/emulate
    |- tutorials
    |  |- basic
    |  |- bench
    |     |- batch
    |     |- bit
    |     |- bridge
    |     |- mod 
    |     |- spec
    |  |- other
    |     |- gate
    
    
                         

### 3p
This directory contains shell scripts for installing external encryption libraries

### circle
This directory containts the files used to generate circuits for the BDD encryption scheme

### src
This directory contains the source code for E<sup>3</sup>, including all the helper tools, circuit files, and programs that generate secure classes.

### Tutorials
This directory contains tutorials that demonstrate the usage of E<sup>3</sup>. 
