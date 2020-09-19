# Data Oblivious Programming tutorial

`bs0.cpp` is a Bubble sort algorithm. The core of the algorithm is:
``` c++
            if (arr[j + 1] < arr[j])
                swap(arr[j], arr[j + 1]);
```
### step 0
Compile it with:
```
$ g++ bs0.cpp -o bs0
$ ./bs0
Original array : 5 12 9 2
Sorted  array  : 2 5 9 12
```
### step 1
Next assume that the array contains secret values. We replace the type of the array to Secure and compile it:
```
$ g++ -std=c++11 bs1.cpp -o bs1
$ ./bs1
Original array : 5 12 9 2
Sorted  array  : 2 5 9 12
```

### step 2 (optional)
In the directory `wrap` a simple implementation of Secure is given as an example. Note that `secure2.h` implements `operator<` as `bool`. And it compiles `bs2.cpp` (change include to `secure2.h`). However when `operator<` returns encrypted result `Secure`, the compiler gives an error.

Replacing the code with Data Oblivious functions does the trick.

### step 3
`bs3.cpp` implements the algorithm in data oblivious way.
```
aaa
$ g++ -std=c++11 bs3.cpp -o bs3
$ ./bs3
Original array : 5 12 9 2
Sorted  array  : 2 5 9 12
```

### step 4
In the final version we write encryption configuration file:
```
password = hello_world4
Secure : circuit
{
    encryption = tfhe
    postfix = e
    sizes = 4
}
```
`Secure` is the name of our type. 
`circuit` is the type of computation, it means working on bit level.
`postfix` - the notation for the encrypted constants
`sizes` - a list of integer sizes to be included in the program. In our case 4 bits is sufficient.

Change the program to
1. Include E3 headers
2. Define the type
3. Replace the constants [This is to make sure that the final binary does not contain plaintext values.]

The files are in `project` directory.

#### Building cgt and executables
In `src` do
```
$ make clean
$ make
$ make alice bob USER=../tutorials/dop/project
$ ./alice.exe
Original array : 5 12 9 2
Sorted  array  : 2 5 9 12
$ ./bob.exe
Original array : Secure[1,0,1,0] Secure[0,0,1,1] Secure[1,0,0,1] Secure[0,1,0,0]
Sorted  array  : Secure[0,1,0,0] Secure[1,0,1,0] Secure[1,0,0,1] Secure[0,0,1,1]
$ ./bob.exe | ./cgt.exe dec -c ../tutorials/dop/project/cgt.cfg
Original array : 5 12 9 2
Sorted array : 2 5 9 12
```
#### Building with TFHE
First build TFHE library. In `3p` do:
```
make TFHE
```
Then back in `src`
```
$ make clean
$ make TFHE=1
$ make alice bob TFHE=1 USER=../tutorials/dop/project
$ ./alice.exe
Original array : 5 12 9 2
Sorted  array  : 2 5 9 12
$ ./bob.exe
[ ... TFHE encryption jubberish ... ]
$ ./bob.exe | ./cgt.exe dec -c ../tutorials/dop/project/cgt.cfg
Original array : 5 12 9 2
Sorted array : 2 5 9 12
```

