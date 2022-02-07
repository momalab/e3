// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

#include "vars.h"
#include "main.h"

#include "using.h"

string Varman::middle(int idx) const
{
    const unsigned char A = 'a';
    int base = 26;
    int j = idx, c = 1, b = base;

    while ( 1 )
    {
        j -= b;
        if ( j < 0 ) break;
        b *= base;
        c++;
    }
    j += b;

    // here j- index and c- number of digits

    string r;
    for (int i = 0; i < c; i++)
    {
        int jk = j % base;
        j = j / base;
        r = char(A + (decltype(A))(jk)) + r;
    }

    return r;
}


void Varman::replaceNum(string & ln, const string & fr, int to)
{
    const bool USE_ALNUM_ORDER = true;
    string z = ol::tos(to);

    if ( !USE_ALNUM_ORDER )
        while ( z.size() < fr.size() ) z = '0' + z;

    ol::replaceAll(ln, fr, z);
}
