// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.extern.h Name=$Name

#include "cipherbit.h"

class CircuitEvalKey_extern : public e3::CircuitEvalKey
{
    protected:
        e3::util::usi key;

    public:
        CircuitEvalKey_extern(User u, e3::KeyName name)
            : CircuitEvalKey(name) { user(u); }

        virtual bool load() { return true; }
};

class $NameBit : public $NameBaseBit
{
    protected:
        Cipherbit x;

    public:
        $NameBit() {}
        $NameBit(Cipherbit ax) : x(ax) {}
        $NameBit(const std::string & s);

        static CircuitEvalKey_extern * k() { return static_cast<CircuitEvalKey_extern *>(pek); }

        std::string str() const { return x.str(); }

        static $NameBit gate_buf(const $NameBit & a) { return ::gate_buf(a.x); }
        static $NameBit gate_not(const $NameBit & a) { return ::gate_not(a.x); }
        static $NameBit gate_and(const $NameBit & a, const $NameBit & b) { return ::gate_and(a.x, b.x); }
        static $NameBit gate_or(const $NameBit & a, const $NameBit & b) { return ::gate_or(a.x, b.x); }
        static $NameBit gate_nand(const $NameBit & a, const $NameBit & b) { return ::gate_nand(a.x, b.x); }
        static $NameBit gate_nor(const $NameBit & a, const $NameBit & b) { return ::gate_nor(a.x, b.x); }
        static $NameBit gate_xnor(const $NameBit & a, const $NameBit & b) { return ::gate_xnor(a.x, b.x); }
        static $NameBit gate_xor(const $NameBit & a, const $NameBit & b) { return ::gate_xor(a.x, b.x); }
        static $NameBit gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c) { return ::gate_mux(a.x, b.x, c.x); }
};


// === END circuit.extern.h Name=$Name
