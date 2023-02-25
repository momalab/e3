#include <iostream>

#include "e3int.h"
#include "chron.h"

#include "e3key.h"

/*
    You MUST include 'e3int.h' in your program file. It links to 'secint.cpp', a
    FHE Framework API file which consists of Bit, secret and evaluation keys
    generation, functions to encrypt and decrypt using FHE, and a list of logic
    gates. This FHE API is generated for a given configuration file. It enables
    the program to abstract different APIs of existing FHE libraries. In other words,
    the user's C++ code becomes oblivious to the underlying FHE library, and, hence,
    a new FHE library can be plugged in without any change to the implementation
    of the SecureInt class. You simply need to link your compiled binary with the
    corresponding FHE library and the newly generated 'secint.cpp' file.

    If you want to access decrypted results by building alice.exe, you need to
    include alice.h as well.
 */

using namespace std;
using SecureInt  = TypeUint<4>;
using SecureBool = TypeBool;
using SecureMint = TypeMint;
//using SecureInt = NativeInt<64>;

/*
    You MUST declare Secure datatypes. Three basic integral types are generated
    by our tool: 'int', 'unsigned', and 'bool'. Their names are constructed from
    the basename specified in the configuration file by adding suffixes 'Int',
    'Uint' and 'Bool' correspondingly.

    Here, you can also declare the bitsize of the datatype. For example, TypeUint<32>
    refers to an unsigned integer of bitsize 32. In the configuration file, 'Type'
    is defined as 'circuit', which refers to boolean circuit and 'TypeMint' is
    defined as 'partial', meaning arithmetic circuit. 'Native' is a weakly encrypted
    datatype often used for testing compilation without encryption.

    NOTE: For arithmetic circuits, you use the custom datatype as it is in the
    configuration file.
 */

#define MAX_NUM 4

/*
    In order to make your program data-oblivious and privacy-preserving, the 'for' loop
    beow is executed for a maximum number of iterations 'MAX_NUM', which needs to be defined
    by you. This is required to prohibit memory references or control-flow decisions
    based on encrypted variables, as this leaks side-channel information about the
    execution context.
 */

void print_hello_world()
{
    cout << "Printing 'Hello World':" << "\n";
    cout << "Hello World" << "\n";

    /*
        In this example, you are giving a string output. String is not included in
        the privacy-preserving computation of E3 framework. Therefore, there is nothing
        to be added or modified to printing out a string using cout function.
     */
}

template <class T>
inline string dec(const T & num)
{
    string s = e3::decrypt(num);
    if( s.empty() ) return "[EMPTY]";
    ///cout<<"AAA1 "<<s.size()<<" ["<<s[0]<<"] ["<<s[1]<<"]\n";
    auto v = e3::util::split(s, '_');
    ///cout<<"AAA2 "<<v.size()<<" ["<<v[0]<<"] ["<<v[0]<<"]\n";
    ///return "ooo";
    return v[0];
}

void add_two_integers()
{
    cout << "\nAdding two integers:" << "\n";

    SecureInt num1 = _5_Ep;
    SecureInt num2 = _2_En;
    SecureInt res = _0_Ep;

    SecureMint m1 = _5_Ea;
    SecureMint m2 = _2_Ea;

    /*
        Instead of using regular integer datatype 'int', you need to replace with our
        'SecureInt' class for PHE. If you need to initialize private variables with
        encrypted constants (without manually encrypting every value), you can append an
        E3-defined suffix, which will be parsed by our helper tool to automatically
        generate the encrypted constants. Here, '_Ep' and '_En' is used as stated in the
        configuration file.
     */

    res = num1 + num2;
    auto mr = m1 + m2;

    /*
        All standard operators are available to the user when using encrypted variables.
        For more information about supported C++ operators, see FAQ.
     */

     cout << "Sum is finished\n";
    //cout << "num1 = " << num1 << "\n";
    //cout << "num2 = " << num2 << "\n";
    //cout << "5 + -2 = " << res << "\n";

    cout << "num1d = " << dec(num1) << "\n";
    cout << "num2d = " << dec(num2) << "\n";
    cout << "5 + -2 = " << dec(res) << "\n";
    cout << "5 + 2 = " << dec(mr) << "\n";

    /*
        Here, you can immediately retrieve decrypted results by using alice.exe. 'e3::decrypt()'
        is used for unsigned value and 'e3::decrypt()' is for signed value.
     */

}

void factorial()
{
    cout << "\nFactorial using boolean circuit:" << "\n";

    SecureInt i = _1_Ep;
    SecureInt input = _3_Ep;
    SecureInt fact = _1_Ep;
    SecureInt result = _0_Ep;

    for (int cntr = 1; cntr < MAX_NUM; cntr++)
    {
        fact *= i;
        result += (i == input) * fact;

        i++;

        /*
            As mentioned above, it is important to execute the 'for' loop for a maximum
            number of iterations irrelevant to the variables. In C++ terms, a SecureInt
            to Bool conversion is not allowed, which manifests as a termination
            problem in the program's control-flow. To address this termination problem,
            loops must execute for a predetermined maximum number of iterations, which
            ensures that a correct result would be reached.

            Correct result is selected by the 'i == n' comparison: when the counter 'i'
            equals the desired input 'n', the comparison returns the encryption of 1, which
            is ultimately multiplied by the factorial number of the current interation.
         */
    }

    //cout << "Factorial of " << input << " = " << result << "\n";
    cout << "Factorial of " << dec(input) << " = " << dec(result) << "\n";
}

void factorial_using_bridge()
{
    cout << "\nFactorial using arithmetic circuit:" << "\n";

    SecureMint  one = _1_Ea;
    SecureMint fact = _1_Ea;
    SecureMint   ia = _1_Ea;
    SecureInt    ic = _1_Ep;
    SecureMint  res = _0_Ea;
    SecureInt input = _3_Ep;

    for (int cntr = 1; cntr < MAX_NUM; cntr++)
    {
        fact *= ia;
        res += (ic == input) * fact;

        ic++;
        ia += one;

        /*
            Here, circuits(boolean)-to-partial(arithmetic) conversion is used to maximize the
            use of arithmetic circuits. 'fact' is computing factorial for every iteration
            regardless of input using arithmetic circuit. Correct result is selected by the
            'ic == input' boolean comparison. Since this outputs the value of either '0' or
            '1', the boolean value can be incorporated in arithmetic multiplication with 'fact'
            value. Although 'ia' and 'ic' have the same role as 'i' in the above example,
            'ia' is used for arithmetic computation for 'fact' and 'ic' is compared to a
            boolean value 'input'. Hence, they are declared as different datatypes.
         */
    }

    cout << "Factorial of " << dec(input)[0] << " = " << dec(res) << "\n";
}

int main()
try
{

    ///Timer t;
    auto r0 = chron::now();

    print_hello_world();
    add_two_integers();
    factorial();
    auto r1 = chron::now();
    cout << "Runtime: " << (r1 - r0) << " ms\n";
    factorial_using_bridge();
    auto r2 = chron::now();
    cout << "Runtime: " << (r2 - r1) << " ms\n";

    /*
        You can check both the encrypted and decrypted results by building the tool with the
        given configuration file. Run following steps in the Command Line:
        1. cd e3/src
        2. make USER=../tutorials/basic
        3. ./bob.exe
        4. ./bob.exe | ./cgt.exe dec -c ../tests/tutorials/cgt.cfg -s 8

        NOTE: Compare the runtimes of boolean circuit and arithmetic circuit for computing
        the factorial of 5. Arithmetic circuit (using bridge) will give noticably less
        computation time.

        To check the immediately decrypted results using alice.exe, run:
        1. cd e3/src
        2. make alice USER=../tutorials/basic
        3. ./alice.exe

        NOTE: Only the variables that were annotated with 'e3::decrypt()' or 'e3::decrypt()' will be decrypted.
        All the other variables will remain encrypted.

        NOTE: When compiled for bob, the decryption function is dummy and returns the encrypted value.

        NOTE: Before you build your own program, make sure to run 'make cleanall' or 'make c'.
     */
}
catch(...)
{
   std::cout<<"exception\n";
}
