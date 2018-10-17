#include <vector>
#include <string>
#include <sstream>

#include "e3util.h"

#include "ek_circ.h"


using std::string;
using std::vector;

namespace cir_name
{
char separator = ',';
char begin = '[';
char end = ']';
}

vector<string> CircuitEvalKey::enc2bits(const string & e)
{
    using rt = vector<string>;
    rt r;
    string c = e;
    if (c.size() < 2 || c[0] != cir_name::begin
            || c[c.size() - 1] != cir_name::end ) return rt();

    std::istringstream is(c.substr(1, c.size() - 2));
    int i = 0;
    vector<bool> v;
    for ( string s; std::getline(is, s, cir_name::separator); i++ )
        r.push_back( s );

    if ( !i ) return rt();
    return r;
}

string CircuitEvalKey::bits2enc(const vector<string> & v)
{
    string x; x += cir_name::begin;
    for ( auto b : v ) x += b + cir_name::separator;
    x[x.size() - 1] = cir_name::end;
    return x;
}

std::string CircuitEvalKey::prefix(
    const std::string & s, bool add, std::string pfx)
{
    auto sz = pfx.size();

    if ( add ) return pfx + s;

    if ( s.size() <= sz || s.substr(0, sz) != pfx ) return "";
    return s.substr(sz);
}
