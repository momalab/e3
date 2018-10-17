#include <iostream>
#include <set>

#include "os_filesys.h"
#include "cgt.h"
#include "util.h"

#include "secnames.h"
#include "sectype.h"
#include "sec_native.h"
#include "sec_circuit.h"

using std::map;

SecType * SecType::load
(std::istream & is, string name, string typ)
{
    if (0);
    else if ( typ == secNames::typeNative ) return new Native(is, name);
    else if ( typ == secNames::typeCircuit ) return new Circuit(is, name);
    else throw "Type '" + typ + "' is not valid or implemented";
}

bool SecType::readKeyVal(std::istream & is, pss & r, string end_word) const
{
    is >> r.first;
    if ( !is ) throw "Unexpected EOF in '" + name + "'";

    if ( r.first == end_word ) return false;

    string w;
    is >> w;
    if ( w != "=" ) throw "Expecting '=', got [" + w + "]";

    is >> r.second;
    if ( !is ) throw "Unexpected EOF while reading [" + r.first + "]";
    return true;
}

string remove_cpp_comments(const string & f)
{
    string r;

    // remove comments
    bool is_comm_line = false, is_comm_block = false;
    for ( size_t i = 0; i + 1 < f.size(); i++ )
    {
        auto c1 = f[i];
        auto c2 = f[i + 1];

        if ( is_comm_line )
        {
            if ( c1 != '\n' ) continue;
            is_comm_line = false;
        }

        if ( is_comm_block )
        {
            if ( c1 != '*' || c2 != '/' ) continue;
            is_comm_block = false;
            i++;
            continue;
        }

        if ( c1 == '/' )
        {
            if ( c2 == '*' ) is_comm_block = true;
            else if ( c2 == '/' ) is_comm_line = true;
            if ( is_comm_block || is_comm_line ) continue;
        }

        r += c1;
    }

    return r;
}


string SecType::find_next_constant(const string & text, size_t & pos, const string & pfx)
{
    string r;
    int stage = 0;

    auto isab = [](char c)->bool { return  !!std::isalpha(c); };
    auto isau = [](char c)->bool { return  !!std::isalpha(c) || c == '_'; };
    auto isdg = [](char c)->bool { return  !!std::isdigit(c); };

    for ( ; pos < text.size(); pos++ )
    {
        auto c = text[pos];
        if ( stage == 0 )
        {
            if ( isab(c) || isdg(c) ) stage = 1;
            else if (c == '_')
            {
                stage = 5;
            }
        }
        else if ( stage == 1 )
        {
            if ( !isdg(c) && !isau(c) ) stage = 0;
        }
        else if ( stage == 2 )
        {
            if ( isdg(c) ) r += c;
            else if ( c == '_' ) stage = 3;
            else stage = 0;
        }
        else if ( stage == 3 )
        {
            auto epos = pos + pfx.size();
            if ( epos > text.size() ) return "";

            if ( pfx == text.substr(pos, pfx.size()) ) stage = 4;
            else stage = 0;
            pos += pfx.size() - 1;
        }
        else if ( stage == 4 )
        {
            if ( isau(c) || isdg(c) ) stage = 0;
            else return r;
        }
        else if ( stage == 5 )
        {
            if ( !isdg(c) ) stage = 0;
            else
            {
                r = ""; r += c;
                stage = 2;
            }
        }
    }

    return "";
}

///map<string, bool> SecType::find_constants(string dirnames) const
SecType::Consts SecType::find_constants(string dirnames) const
{
    ///map<string, bool> r;
    Consts r;

    std::cout << nm::cgt << ": scan " << postfixP << "/" << postfixN;

    ol::istr is(dirnames);
    for ( string sdir; std::getline(is, sdir, ';'); )
    {
        if ( !os::isDir(sdir) )
            throw "Cannot enter directory [" + sdir + "]";

        os::Dir dir = os::FileSys::readDir(sdir);

        for ( auto entry : dir.files )
        {
            if ( !util::isCpp(entry.first) ) continue;

            string file = (os::Path(sdir) + entry.first).str();

            std::cout << " [" << file << "]";

            string f = ol::file2str(file);
            f = remove_cpp_comments(f);

            size_t pos = 0;
            if ( !postfixP.empty() )
                for ( string s; !(s = find_next_constant(f, pos, postfixP)).empty(); )
                    r.pos.insert(s);
            ///r[s] = false;

            pos = 0;
            if ( !postfixN.empty() )
                for ( string s; !(s = find_next_constant(f, pos, postfixN)).empty(); )
                    r.neg.insert(s);
            ///r[s] = true;
        }
    }

    if ( r.pos.empty() && r.neg.empty() )
    {
        std::cout << " none\n";
    }
    else
    {
        std::cout << ":";
        for ( auto x : r.pos ) cout << ' ' << x;
        for ( auto x : r.neg ) cout << " -" << x;
        std::cout << "\n";
    }

    return r;
}

namespace
{
string break_str(const string & s, const size_t m)
{
    auto sz = s.size();
    if ( sz <= m ) return s;
    return break_str(s.substr(0, sz / 2), m)
           + "\" \""
           + break_str(s.substr(sz / 2), m);
}
} // namespace

string SecType::makeDefines(const Consts & c) const
{
    return makeDefines(c.pos, false) + makeDefines(c.neg, true);
}

string SecType::makeDefines(const std::set<string> & sx, bool neg) const
{
    string r;
    if ( !sk ) throw "Secret key not found";
    for ( auto m : sx )
    {
        string sign; sign = neg ? "-" : "";
        string encrypted = encrypt(sign + m);

        if ( encrypted.size() > MAX_C_STR ) encrypted = break_str(encrypted, MAX_C_STR);

        r += "#define _" + ol::tos(m) + "_" + (neg ? postfixN : postfixP);
        r += " \"" + encrypted + "\"\n";
    }
    return r;
}

/*///
string SecType::makeDefines(const map<string, bool> & sx) const
{
    string r;
    if ( !sk ) throw "Secret key not found";
    for ( auto m : sx )
    {
        string sign; sign = m.second ? "-" : "";
        string encrypted = encrypt(sign + m.first);

        if ( encrypted.size() > MAX_C_STR ) encrypted = break_str(encrypted, MAX_C_STR);

        r += "#define _" + ol::tos(m.first) + "_" + (m.second ? postfixN : postfixP);
        r += " \"" + encrypted + "\"\n";
    }
    return r;
}
*/

void SecType::loadPairs(std::istream & is, std::map<string, string *> & kv)
{
    string w;
    is >> w;
    if ( w != "{" ) throw "Expecting '{', got [" + w + "] when parsing [" + name + "]";

    string ptsize;
    kv[secNames::msize] = &ptsize;

    for ( pss p; readKeyVal( is, p, "}" ); )
    {
        auto it = kv.find(p.first);
        if ( it == kv.end() ) throw "Bad key [" + p.first + "] for [" + name + "]";
        *it->second = p.second;
    }

    if ( !ptsize.empty() ) plaintext_size = std::stoi(ptsize);
}

std::string SecType::encrypt(const std::string & s) const
{
    if ( plaintext_size <= 0 ) throw "Unknown plaintext size in " + name;
    auto r = get_sk()->encrypt(s, plaintext_size);
    return r;
}

std::string SecType::decrypt(const std::string & s) const
{
    return get_sk()->decrypt(s);
}

// checking for duplicated postfixes
void SecType::checkPostfixes(std::set<string> & postfixes)
{
    auto func = [& postfixes] (std::string postfix)
    {
        if ( postfixes.find(postfix) != postfixes.end() )
            throw "Postfix '" + postfix + "' defined more than once";
        postfixes.insert(postfix);
    };

    func(postfixP);
    func(postfixN);
}
