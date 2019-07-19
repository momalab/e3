# Tutorials

You can check both the encrypted and decrypted results by building the tool with the 
given configuration file. Run following steps in the Command Line:
```
cd e3/src
make USER=../tests/tutorials
./bob.exe
./bob.exe | ./cgt.exe dec -c ../tests/tutorials/cgt.cfg
```

**NOTE**: Compare the runtimes of boolean circuit and arithmetic circuit for computing 
factorial of 5. Arithmetic circuit (using bridge) will give noticably less computation time.

To check the immediately decrypted results using alice.exe, run:
```
cd e3/src
make alice USER=../tests/tutorials
./alice.exe
```

**NOTE**: Only the variables that were annotated with 'dec()' or 'decs()' will be decrypted.
All the other variables will remain encrypted.

**NOTE**: Before you build your own program, make sure to run 'make cleanall' or 'make c'.