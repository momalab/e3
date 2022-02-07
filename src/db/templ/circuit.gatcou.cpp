// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.gatcou.cpp Name=$Name

e3::gatcou::GcStat e3::gatcou::gc_stat;

void e3::gatcou::print(int w)
{
    using std::cout;
    using std::setw;
    auto gc = e3::gatcou::get();
    cout << "----------------------------\n";
    cout << setw(w) << ' ' << setw(w) << "ops" << setw(w) << "gates" << setw(w) << "crit" << '\n';
    cout << "----------------------------\n";
    cout << setw(w) << "not" << setw(w) << gc.ops.not_ << setw(w) << gc.gates.not_ << setw(w) << gc.crit.not_ << '\n';
    cout << setw(w) << "and" << setw(w) << gc.ops.and_ << setw(w) << gc.gates.and_ << setw(w) << gc.crit.and_ << '\n';
    cout << setw(w) << "or" << setw(w) << gc.ops.or_ << setw(w) << gc.gates.or_ << setw(w) << gc.crit.or_ << '\n';
    cout << setw(w) << "nand" << setw(w) << gc.ops.nand_ << setw(w) << gc.gates.nand_ << setw(w) << gc.crit.nand_ << '\n';
    cout << setw(w) << " nor" << setw(w) << gc.ops.nor_ << setw(w) << gc.gates.nor_ << setw(w) << gc.crit.nor_ << '\n';
    cout << setw(w) << "xnor" << setw(w) << gc.ops.xnor_ << setw(w) << gc.gates.xnor_ << setw(w) << gc.crit.xnor_ << '\n';
    cout << setw(w) << " xor" << setw(w) << gc.ops.xor_ << setw(w) << gc.gates.xor_ << setw(w) << gc.crit.xor_ << '\n';
    cout << setw(w) << " mux" << setw(w) << gc.ops.mux_ << setw(w) << gc.gates.mux_ << setw(w) << gc.crit.mux_ << '\n';
    cout << "----------------------------\n";
    cout << setw(w) << "total" << setw(w) << gc.ops.total() << setw(w) << gc.gates.total() << setw(w) << gc.crit.total() << '\n';
    cout << "----------------------------\n";
}

std::string e3::gatcou::sum(int t)
{
    auto gc = e3::gatcou::get();

    auto ops = gc.ops.total();
    auto gts = gc.gates.total();
    auto crs = gc.crit.total();

    if ( t == 0 )
    {
        string r;
        r += std::to_string(ops);
        r += ',';
        r += std::to_string(gts);
        r += ',';
        r += std::to_string(crs);
        return r;
    }

    auto sh = [](auto & x) -> std::string
    {
        using typ = typename std::decay<decltype(x)>::type;

        if ( x > 10000 ) { x = (typ)( x / 1000.0 + 0.5 ); return "k"; }
        if ( x > 10000000 ) { x = (typ)( x / 1000000.0 + 0.5 ); return "m"; }
        return "";
    };

    auto ox = sh(ops);
    auto gx = sh(gts);
    auto cx = sh(crs);

    string r;
    if ( t & 1 ) r += std::to_string(ops) + ox;
    if ( t & 3 ) r += '/';
    if ( t & 2 ) r += std::to_string(gts) + gx;
    if ( t & 7 ) r += '/';
    if ( t & 4 ) r += std::to_string(crs) + cx;
    return r;
}

$NameBit::$NameBit(const std::string & s) : $NameBit()
{
    try { x = std::stoi(fs(s)); }
    catch (...)
    {
        // print, this exception may not be handled
        std::string e = "(circuit.gatcou) Bad init in $NameBit [%s]";
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
    e3::gatcou::gc_stat.not_();
    return !a.x;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.and_();
    return (a.x & b.x);
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.or_();
    return (a.x | b.x);
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.nand_();
    return !(a.x & b.x);
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.nor_();
    return !(a.x | b.x);
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.xnor_();
    return !(a.x ^ b.x);
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcou::gc_stat.xor_();
    return (a.x ^ b.x);
}

// a ? b : c
$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    e3::gatcou::gc_stat.mux_();
    return a.x ? b.x : c.x;
}

// === END circuit.gatcou.cpp Name=$Name
