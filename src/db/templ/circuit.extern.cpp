// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.extern.cpp Name=$Name

$NameBit::$NameBit(const std::string & s) : x()
{
    if ( s.size() == 1 && ( s == "0" || s == "1" ) )
    {
        Cipherbit a;
        auto b = ::gate_not(a);
        if ( s == "0" ) x = ::gate_and(a, b);
        else x = ::gate_nand(a, b);
    }
    else
        x = Cipherbit(s);
}

// === END circuit.extern.cpp Name=$Name
