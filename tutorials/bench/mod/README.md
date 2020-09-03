# Modular Arithmetic #

From `e3/src`, `make c` and compile with `make USER=../tutorials/bench/mod`. To run, just execute `./bob.exe > output.tmp`. And to decrypt the output, run `./cgt.exe dec -c ../tutorials/bench/mod/cgt.cfg -f output.tmp`.

The configuration file (cgt.cfg) is set to use the SEAL library. If you want to use it, you must specify it during compilation, otherwise E3 compiles the program using a mockup library. To run with SEAL, do the following:
```
cd e3/src
make c
make bob USER=../tutorials/bench/mod SEAL=1
./bob.exe > output.tmp
./cgt.exe dec -c ../tutorials/bench/mod/cgt.cfg -f output.tmp
```

**NOTE**: SEAL must be installed. Check [e3\\3p](../../../3p).
