#pragma once

#include <string>

struct Key { int k; void init(); };

class Cipherbit
{
    private:
        int x = 10;
        static Key key;

    public:
        static void init() { key.init(); }
        Cipherbit() {};
        Cipherbit(std::string v): x(std::stoi(v)) {}
        std::string str() const { return std::to_string(x); }


        Cipherbit nand(Cipherbit b) const
        {
            Cipherbit r;
            r.x = ( 1 & ~((x - key.k) & (b.x - key.k)) ) + key.k;
            return r;
        }
};

inline Cipherbit gate_buf(const Cipherbit & a)
{
    return a;
}

inline Cipherbit gate_nand(const Cipherbit & a, const Cipherbit & b)
{
    return a.nand(b);
}

inline Cipherbit gate_not(const Cipherbit & a)
{
    return gate_nand(a, a);
}

inline Cipherbit gate_and(const Cipherbit & a, const Cipherbit & b)
{
    return gate_not(gate_nand(a, b));
}

inline Cipherbit gate_or(const Cipherbit & a, const Cipherbit & b)
{
    return gate_not(gate_and(gate_not(a), gate_not(b)));
}

inline Cipherbit gate_nor(const Cipherbit & a, const Cipherbit & b)
{
    return gate_and(gate_not(a), gate_not(b));
}

inline Cipherbit gate_xor(const Cipherbit & a, const Cipherbit & b)
{
    return gate_or(gate_and(a, gate_not(b)), gate_and(b, gate_not(b)));
}

inline Cipherbit gate_xnor(const Cipherbit & a, const Cipherbit & b)
{
    return gate_not(gate_xor(a, b));
}

inline Cipherbit gate_mux(const Cipherbit & a, const Cipherbit & b, const Cipherbit & c)
{
    return gate_or(gate_and(c, gate_not(a)), gate_and(b, a));
}
