#include "olc.h"

const size_t MAX_FILE_SIZE = 1024u * 1024 * 10; // 10Mb


bool ol::replaceAll(string & s, const string & r, const string & to)
{
    bool found = false;
    while (1)
    {
        size_t i = s.find(r);
        if ( i == string::npos ) return found;
        s.replace(i, r.size(), to);
        found = true;
    }
    throw 0; // never
}

void ol::cutline(string & line)
{
    while ( line.size() &&
            std::isspace(line[line.size() - 1]) )
        line = line.substr(0, line.size() - 1);
}

string ol::file2str(const string & file, bool silent)
{
    std::ifstream in(file.c_str(), std::ios::binary);

    if ( !in )
    {
        if ( silent ) return "";
        throw "Cannot open " + file;
    }

    string r;

    in.seekg(0, std::ios::end);

    size_t sz = ol::x2st(in.tellg());

    if ( sz > MAX_FILE_SIZE )
        return "";

    r.reserve( sz );
    in.seekg(0, std::ios::beg);

    r.assign( std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>() );

    return r;
}

void ol::str2file(const string & file, const string & str)
{
    std::ofstream of(file.c_str(), std::ios::binary);
    of << str;
}

void ol::toHex(const char * in, int inlen, char * out)
{
    const char * hexDigits = "0123456789abcdef";
    int index = 0;

    if (in && inlen > 0 && out)
    {
        for (int i = 0; i < inlen; i++)
        {
            out[index++] = hexDigits[(in[i] >> 4) & 0x0F];   // equal to "in[i]/16"
            out[index++] = hexDigits[in[i] & 0x0F];          // equal to "in[i]%16"
        }
    }
}

void ol::toBin(const char * in, int inlen, char * out)
{
    int index = 0;

    if (in && inlen > 0 && out)
    {
        for (int i = 0; i < inlen; i++)
        {
            char a = in[i];
            if ( a >= '0' && a <= '9' ) a -= '0';
            else if ( a >= 'a' && a <= 'f' ) a -= 'a' - char(10);

            if ( i % 2 )
            {
                out[index] <<= 4;
                out[index++] |= a;
            }
            else
                out[index] = a;
        }
    }
}

string ol::toHex(const string & s)
{
    size_t sz = s.size();
    char * buf = new char[sz * 2];
    toHex(s.c_str(), st2i(sz), buf);
    string r(buf, sz * 2);
    delete [] buf;
    return r;
}

string ol::toBin(const string & s)
{
    size_t sz = s.size();
    char * buf = new char[sz];
    toBin(s.c_str(), st2i(sz), buf);
    string r(buf, sz / 2);
    delete [] buf;
    return r;
}


ol::vstr ol::str2vstr(const string & s, string delim)
{
    if ( s.size() < 1 ) return vstr();

    const string * ps = &s;
    string ds; // with delim at the end
    string::size_type i = s.rfind(delim);
    if ( i == string::npos || i + delim.size() != s.size() )
    {
        ds = s + delim;
        ps = &ds;
    }

    // now ps points to a string with delim at the end

    vstr r;
    i = 0;
    while ( 1 )
    {
        string::size_type j = ps->find(delim, i);
        if ( j == string::npos ) break;
        r.push_back(ps->substr(i, j - i));
        i = j + delim.size();
    }

    return r;
}
