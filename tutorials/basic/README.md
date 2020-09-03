# Tutorials

You can check both the encrypted and decrypted results by building the tool with the
given configuration file. Run following steps in the Command Line:
```
cd e3/src
make bob USER=../tutorials/basic SEAL=1
./bob.exe
./bob.exe | ./cgt.exe dec -c ../tutorials/basic/cgt.cfg
```

**NOTE**: Compare the runtimes of boolean circuit and arithmetic circuit for computing
factorial of 5. Arithmetic circuit (using bridge) will give noticably less computation time.

To check the immediately decrypted results using alice.exe, run:
```
cd e3/src
make alice USER=../tutorials/basic SEAL=1
./alice.exe
```

**NOTE**: Only the variables that were annotated with 'e3::decrypt()' will be decrypted.
All the other variables will remain encrypted.

**NOTE**: When compiled for bob, the decryption function is dummy and returns the encrypted value.

**NOTE**: Before you build your own program, make sure to run 'make cleanall' or 'make c'.

Check [tutorials.cpp](tutorials.cpp) for details.
