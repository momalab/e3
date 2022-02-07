// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.plain.cpp Name=$Name

$NameBit::$NameBit(const std::string & s) : $NameBit()
{
    try { x = std::stoi(fs(s)); }
    catch (...)
    {
        // print, this exception may not be handled
        std::string e = "(circuit.plain) Bad init in $NameBit [%s]";
        std::printf((e + "\n").c_str(), s.c_str());
        throw e.substr(0, e.find('%')) + s + "]";
    }
}

$NameBit $NameBit::gate_buf(const $NameBit & a)
{
    return a;
}

$NameBit $NameBit::gate_not(const $NameBit & a)
{
    auto ek = k();
    auto y = ek->dec(a.x);

    y = !y;

    return ek->enc(y);
}
$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);
    ma &= mb;
    return ek->enc(ma);
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma |= mb;

    return ek->enc(ma);
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma & mb);

    return ek->enc(ma);
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma | mb);

    return ek->enc(ma);
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma = !(ma ^ mb);

    return ek->enc(ma);
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);

    ma ^= mb;

    return ek->enc(ma);
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    auto ek = k();
    auto ma = ek->dec(a.x);
    auto mb = ek->dec(b.x);
    auto mc = ek->dec(c.x);

    ma = ma ? mb : mc;

    return ek->enc(ma);
}

// === END circuit.plain.cpp Name=$Name
