// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.bdd.cpp Name=$Name

// this flag used for debug and must be the same as in sk_circ_bdd.cpp
const bool $NameBit_useHex = true;

std::string $NameBit::vc2s(const std::vector<char> & v)
{
    std::vector<bool> vb(v.size());
    for ( size_t i = 0; i < v.size(); i++ ) vb[i] = bool(char(1)&v[i]);
    return $NameBit_useHex ? e3util::bin2hex(vb) : e3util::bin2sbn(vb);
}

void $NameBit::s2vc(const std::string & x, std::vector<char> & v)
{
    std::vector<bool> vb = $NameBit_useHex
                           ? e3util::hex2bin(x, $CtSize) : e3util::sbn2bin(x, $CtSize);

    for ( size_t i = 0; i < v.size(); i++ ) v[i] = vb[i] ? char(1) : '\0';
}

$NameBit::$NameBit(const std::string & s) : $NameBit()
{
    try { s2vc(fs(s), vc); }
    catch (...)
    {
        // print, this exception may not be handled
        std::string e = "(circuit.bdd) Bad init in $NameBit [%s]";
        std::printf((e + "\n").c_str(), s.c_str());
        throw e.substr(0, e.find('%')) + s + "]";
    }
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

// === END circuit.bdd.cpp Name=$Name
