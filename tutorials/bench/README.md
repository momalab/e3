# [Modular Arithmetic](mod)

Some FHE schemes define arithmetic addition, subtraction, and multiplication on numeric rings, but not other arithmetic such as division or comparison. While some applications may not require any other operation, a programmer expects to have all programming operations available in their programs.
For example, the C++ statement `if (a<b) c+=a;` and its corresponding data-oblivious form: `c+=(a<b)*a;`, cannot be evaluated with an FHE scheme where the comparison operation is not defined.
Addition, subtraction, and multiplication on integers is an incomplete set of arithmetic operations; for example, the comparison operation cannot be reduced to these three operations. The same set of operations is, however, complete on the bit level.

# [Bit-Level Arithmetic](bit)

E3 solves this problem by allowing the programmer to use types constructed out of sequences of encrypted bits. Indeed, as the least possible requirement to the evaluation power, any FHE scheme has to be able to evaluate the logic NAND (or equivalently NOR) gate on ciphertexts, since this elementary function is sufficient for universal computation.
In this way, the variables in the expression `c+=(a<b)*a;` are defined as *integral types* where all three operations (comparison, multiplication, and addition) are performed using bit-level arithmetic circuits. We call this computation *Bit-level arithmetic*, as opposite to the natively provided *Modular arithmetic*, where addition and multiplication are performed directly on ciphertexts.

# [Specialized Circuits](spec)

In Bit-Level Arithmetic all computation boils down to logic gate operations operating on encrypted bits. It is possible in E3, however, to improve performance of the program by utilizing optimization algorithms applied onto combinational circuits, by porting parts of the program to Verilog and compiling the code into gate-level netlist. This feature is similar to assembly insertions in C/C++. Then, E3 converts the compiled netlist into C++ functions that can be called directly from the program.

# [Bridging](bridge)

Declaring variables with a protected integral type and using solely Bit-level arithmetic has a potential drawback: When an FHE scheme provides fast Modular arithmetic operations, the usage of circuits operating on separate bits is slow. E3 brings the novel idea of *Bridging* - mixing both Modular and Bit-level arithmetic in one program with the ability to convert variables from integral type to modular. Some variables can be declared as of protected type supporting only Modular arithmetic while others with the other type supporting Bit-level arithmetic. In bridging mode, a type of Bit-level arithmetic declares a conversion function into a type of Modular arithmetic. Obviously, the encryption of the two different C++ types must share the same keys.

# [Batching](batch)

Batching is the ability to pack several plaintexts into a single ciphertext. This feature is supported by some FHE schemes. In practice, it enables parallel processing of plaintexts, since they are all part of the same ciphertext, in a Single Instruction Multiple Data (SIMD) style. This can provide significant performance improvements for algorithms with parallel computation properties.
