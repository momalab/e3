// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN circuit.gatcow.cpp Name=$Name


const char * const e3::gatcow::gateNames [e3::gatcow::NGateTypes] =
{ "not", "and", "or", "nand", "nor", "xnor", "xor", "mux" };
const int gNOT = 0, gAND = 1, gOR = 2, gNAND = 3, gNOR = 4, gXNOR = 5, gXOR = 6, gMUX = 7;

e3::gatcow::PathBlock * e3::gatcow::g_curPathBlock = nullptr; // will be &g_rootPathBlock;
e3::gatcow::PathBlock e3::gatcow::g_rootPathBlock;
bool e3::gatcow::PathBlock::berr;
std::string e3::gatcow::PathBlock::err;

#define never (std::cout<<"never: "<<__func__<<'\n')

e3::gatcow::Share::Share(std::string nm, bool anonym)
    : PathBlock(SEQ), name(nm), anon(anonym) {}

e3::gatcow::PathBlock::~PathBlock()
{
    g_curPathBlock = parent;
    if ( merged ) return;
    if ( !parent ) return;
    if ( !parent->parent ) return; // no join to root
    parent->join_pb(*this);
}

void e3::gatcow::PathBlock::merge()
{
    if ( berr ) throw err;
    if ( merged ) never;
    if ( !parent ) never;
    if ( !parent->parent ) never; // no join to root
    parent->join_pb(*this);
    re.clear();
    tri = Triplet();
    pardata = ParData {};
}

e3::gatcow::Share::~Share()
{
    merged = true; // stop join on ~PathBlock
    if ( !parent )
    {
        seterr("Bad parent in Share");
        return;
    }
    parent->join_share(*this);
}

std::map<std::string, int> load_pbt_config()
{
    std::ifstream in("gatcow.cfg");
    if ( !in ) throw "Cannot open gatcow.cfg";
    std::map<std::string, int> r;
    while (1)
    {
        string v, k;
        in >> v >> k;
        if ( !in ) break;
        if (0) {}
        else if ( v == "P" || v == "p" || v == "Par" || v == "par" ) r[k] = e3::gatcow::PAR;
        else if ( v == "S" || v == "s" || v == "Seq" || v == "seq" ) r[k] = e3::gatcow::SEQ;
        else if ( v.size() && v[0] == '#' ) continue;
        else throw "Unexpected value [" + v + "] in config; use 'P' or 'S'";
    }

    return r;
}

int get_pbt_from_config(std::string cfgname)
{
    static std::map<std::string, int> m = load_pbt_config();
    auto it = m.find(cfgname);
    if ( it != m.end() ) return it->second;
    it = m.find("*");
    if ( it != m.end() ) return it->second;

    throw "Cannot find " + cfgname + " in gatcow.cfg";
}

void e3::gatcow::PathBlock::swap_stack()
{
    if ( berr ) throw err;
    parent = g_curPathBlock;
    g_curPathBlock = this;
}

e3::gatcow::PathBlock::PathBlock(std::string cfgname)
{
    swap_stack();
    pathBlockType = get_pbt_from_config(cfgname);
}

e3::gatcow::PathBlock::PathBlock(int apbt)
{
    swap_stack();
    pathBlockType = apbt;
}



void e3::gatcow::PathBlock::isvalid()
{
    if ( berr ) throw err;
    if ( !g_curPathBlock )
    {
        std::string err = "g_curPathBlock==0";
        std::cout << "Error: " << err << '\n';
        throw err;
    }

    auto & g = g_rootPathBlock;
    auto & t = g.tri;
    auto sum = t.ops.total() + t.gts.total() + t.crs.total();
    if ( sum )
    {
        std::string err = "Root PathBlock has counts";
        std::cout << "Error: " << err << '\n';
        g.print();
        throw err;
    }
}

void e3::gatcow::PathBlock::grab_real_estate(std::string nm, const RE & k)
{
    auto it = re.find(nm);

    if ( it == re.end() )
    {
        re[nm] = k; // import shared
        return;
    }

    const auto & mytri = it->second.ng;
    int myhowmany = it->second.howmany;

    // check that they are equal
    if ( mytri != k.ng )
        seterr("found shared same names different implementation");

    if ( pathBlockType == SEQ )
    {
        ///if ( !mykid ) return; // exclude only sequential same modules

        auto mygts = mytri;
        if ( myhowmany >= k.howmany ) // no update to re required, just subtract
        {
            ///tri.gts -= mytri.gts * k.howmany;
            mygts = mygts * k.howmany;
        }
        else // myhowmany < k.howmany
        {
            ///tri.gts -= mytri.gts * myhowmany;
            it->second.howmany = k.howmany;
            mygts = mygts * myhowmany;
        }

        if ( !tri.gts.canSubtract(mygts) ) seterr("negative gates (sub)");
        tri.gts -= mygts;

    }
    else if ( pathBlockType == PAR )
    {
        ///if ( myhowmany != k.howmany ) seterr("different number of submodules");
        it->second.howmany += k.howmany;
    }
    else never;
}

e3::gatcow::Gcounter e3::gatcow::PathBlock::net_gts() const
{
    Gcounter sum;
    for ( const auto & a : re )
    {
        auto nm = a.first;
        auto k = a.second;
        if ( k.anon ) continue;
        sum += k.ng * k.howmany;
    }

    if ( !tri.gts.canSubtract(sum) ) seterr("negative gates (net)");
    auto r = tri.gts;
    r -= sum;
    return r;
}

void e3::gatcow::PathBlock::grab_real_estate(const PathBlock & kid)
{
    for ( const auto & a : kid.re )
    {
        auto nm = a.first;
        auto k = a.second;
        if ( k.anon ) continue;
        grab_real_estate(nm, k);
    }
}

void e3::gatcow::PathBlock::join_pb(const PathBlock & kid)
{
    if ( pathBlockType == PAR ) seterr("Par PathBlock cannot have PathBlock children");
    tri += kid.tri;

    grab_real_estate(kid);
}

void e3::gatcow::PathBlock::join_share(const Share & s)
{

    if ( pathBlockType == SEQ )
    {
        tri += s.tri;
        grab_real_estate(s.name, RE {s.anon, s.net_gts(), 1});
        grab_real_estate(s);
        return;
    }

    // PAR
    // need to detect if tri changed without join
    if ( pardata.shadow != tri )
    {
        seterr("Computation in Par outside of Share");
        return;
    }

    tri += s.tri;

    auto & maxcrit = pardata.maxcrit;
    if ( maxcrit.total() >= s.tri.crs.total() ) tri.crs -= s.tri.crs;
    else
    {
        tri.crs -= maxcrit;
        maxcrit = s.tri.crs;
    }

    grab_real_estate(s.name, RE {s.anon, s.net_gts(), 1});
    grab_real_estate(s);
    pardata.shadow = tri;
}


#undef never

void e3::gatcow::Share::debug()
{
    using std::cout;
    cout << "name=[" << name << "]\tanon=" << anon << '\n';
    PathBlock::debug(name);
}

void e3::gatcow::PathBlock::debug(std::string nm)
{
    using std::cout;
    cout << "parent=" << ((void *)parent) << "\tpathBlockType=" << pathBlockType
         << "\tmerged=" << merged << "\ttri={" << sum() << "}" << '\n';
    cout << "shadow={" << e3::gatcow::summary(pardata.shadow)
         << "}\tmaxcrit=" << pardata.maxcrit.total() << "\t";

    cout << "PB:" << nm << '\n';

    cout << "re:";
    for ( auto i : re)
    {
        cout << " " << (i.first) << ":" << (i.second.anon ? 'A' : 'N');
        cout << "{" << i.second.ng.total() << "}_" << i.second.howmany;
    }
    cout << "\n";
}

void e3::gatcow::PathBlock::errsig()
{
    std::cout << "Set error: " << err << '\n';
}

void e3::gatcow::PathBlock::print(int w)
{
    if ( berr ) throw err;

    using std::cout;
    using std::setw;
    cout << "-------------------------------\n";
    cout << setw(w) << ' ' << ' ' << setw(w) << "ops" << ' '
         << setw(w) << "gates" << ' ' << setw(w) << "crit" << '\n';
    cout << "-------------------------------\n";

    for ( int i = 0; i < NGateTypes; i++ )
        cout << setw(w) << gateNames[i] << ' ' << setw(w)
             << tri.ops.x[i] << ' ' << setw(w) << tri.gts.x[i]
             << ' ' << setw(w) << tri.crs.x[i] << '\n';

    cout << "-------------------------------\n";
    cout << setw(w) << "total" << ' ' << setw(w) << tri.ops.total()
         << ' ' << setw(w) << tri.gts.total() << ' '
         << setw(w) << tri.crs.total() << '\n';
    cout << "-------------------------------\n";
}


std::string e3::gatcow::PathBlock::sum(unsigned long coeff, std::string delim)
{
    if ( berr ) throw err;
    return e3::gatcow::summary(tri, coeff, delim);
}

std::string e3::gatcow::summary(Triplet tri, unsigned long coeff, std::string delim)
{
    int t = 0;

    if ( coeff < 1 ) throw std::string() + __func__ + " bad coeff";

    auto nops = tri.ops.total() / coeff;
    auto ngts = tri.gts.total() / coeff;
    auto ncrs = tri.crs.total() / coeff;

    if ( t == 0 )
    {
        string r;
        r += std::to_string(nops);
        r += delim;
        r += std::to_string(ngts);
        r += delim;
        r += std::to_string(ncrs);
        return r;
    }

    auto sh = [](auto & x) -> std::string
    {
        using typ = typename std::decay<decltype(x)>::type;

        if ( x > 10000 ) { x = (typ)( x / 1000.0 + 0.5 ); return "k"; }
        if ( x > 10000000 ) { x = (typ)( x / 1000000.0 + 0.5 ); return "m"; }
        return "";
    };

    auto ox = sh(nops);
    auto gx = sh(ngts);
    auto cx = sh(ncrs);

    string r;
    if ( t & 1 ) r += std::to_string(nops) + ox;
    if ( t & 3 ) r += '/';
    if ( t & 2 ) r += std::to_string(ngts) + gx;
    if ( t & 7 ) r += '/';
    if ( t & 4 ) r += std::to_string(ncrs) + cx;
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
    e3::gatcow::g_curPathBlock->gate(gNOT);
    return !a.x;
}

$NameBit $NameBit::gate_and(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gAND);
    return (a.x & b.x);
}

$NameBit $NameBit::gate_or(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gOR);
    return (a.x | b.x);
}

$NameBit $NameBit::gate_nand(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gNAND);
    return !(a.x & b.x);
}

$NameBit $NameBit::gate_nor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gNOR);
    return !(a.x | b.x);
}

$NameBit $NameBit::gate_xnor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gXNOR);
    return !(a.x ^ b.x);
}

$NameBit $NameBit::gate_xor(const $NameBit & a, const $NameBit & b)
{
    e3::gatcow::g_curPathBlock->gate(gXOR);
    return (a.x ^ b.x);
}
// a ? b : c

$NameBit $NameBit::gate_mux(const $NameBit & a, const $NameBit & b, const $NameBit & c)
{
    e3::gatcow::g_curPathBlock->gate(gMUX);
    return a.x ? b.x : c.x;
}


// === END circuit.gatcow.cpp Name=$Name
