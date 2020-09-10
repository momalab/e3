#pragma once

#include <ostream>

using std::ostream;

struct Secure
{
    int x;

    bool operator<(const Secure & y) const { return x < y.x; }
    //Secure operator<(const Secure & y) const { return Secure {int(x < y.x)}; }

    friend ostream & operator<<(ostream & os, const Secure & y) { return os << y.x; }

    Secure operator*(const Secure & y) const { return Secure {int(x * y.x)}; }
    Secure operator!() const { return Secure {int(!x)}; }
    Secure operator+(const Secure & y) const { return Secure {int(x + y.x)}; }
};
