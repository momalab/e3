#include <complex>
#include <iostream>
#include <string>
#include "e3int.h"
#include "e3key.h"

using namespace std;
using SecureA = PalisadeCKKS_Approx;
using SecureE = PalisadeCKKS_Exact;

const size_t LIMIT = 8;

template <class T>
string stringfy(const vector<T> & v, size_t limit)
{
    if ( v.empty() || !limit ) return "{ }";
    string s = "{ " + e3::util::to_string( v[0] );
    for ( size_t i=1; i<limit && i<v.size(); i++ )
        s += ", " + e3::util::to_string(v[i]);
    s += " }";
    return s;
}

template <class T, class U>
string dec(const T & a)
{
    return stringfy( e3::decrypt<T,U>(a), LIMIT );
}

template <class T, class U, class V>
void test_operators(const T & a, const U & b, const V & decryptionType)
{
    auto c = T(b); cout << "construct(" << typeid(b).name() << ")\t" << dec<T,V>(c) << '\n';
    {
        auto add = a+b; cout << "add\t" << dec<T,V>(add) << '\n';
        auto sub = a-b; cout << "sub\t" << dec<T,V>(sub) << '\n';
        auto mul = a*b; cout << "mul\t" << dec<T,V>(mul) << '\n';
    }
    {
        T add, sub, mul;
        add = sub = mul = a;
        add += b; cout << "add\t" << dec<T,V>(add) << '\n';
        sub -= b; cout << "sub\t" << dec<T,V>(sub) << '\n';
        mul *= b; cout << "mul\t" << dec<T,V>(mul) << '\n';
    }
    cout << '\n';
}

template <class T>
void test(const T & a, const T & b)
{
    cout << "\nTesting " << typeid(a).name() << "\n\n";

    int i = -42;
    double d = 1.41421356237;
    complex<double> c (1.5, -0.5);
    vector<int> vi = {-5, 7, 9, 3};
    vector<double> vd = {-5.4, 7.0, 9.8, 3.14};
    vector<complex<double>> vc(8, c);

    cout << "a " << dec<T,vector<double>>(a) << '\n';
    cout << "b " << dec<T,vector<double>>(b) << '\n';
    cout << '\n';

    test_operators(a, b, vector<double>());
    test_operators(a, i, vector<int>());
    test_operators(a, d, vector<double>());
    test_operators(a, c, vector<complex<double>>());
    test_operators(a, vi, vector<int>());
    test_operators(a, vd, vector<double>());
    test_operators(a, vc, vector<complex<double>>());

    vector<int> rotations = {1, 2, 4};
    {
        auto pos = +a ; cout << "pos\t" << dec<T,vector<double>>(pos) << '\n';
        auto neg = -a ; cout << "neg\t" << dec<T,vector<double>>(neg) << '\n';
        auto rot = T::rotate(a, 2); cout << "rot\t" << dec<T,vector<double>>(rot) << '\n';
        rot = a;  rot.rotate(   2); cout << "rot\t" << dec<T,vector<double>>(rot) << '\n';
        vector<T> frot; T t = a;
        frot = T::rotate(a, rotations); cout << "frot:\n"; for ( auto & e : frot ) cout << ' ' << dec<T,vector<double>>(e) << '\n';
        frot =  t.rotate(   rotations); cout << "frot:\n"; for ( auto & e : frot ) cout << ' ' << dec<T,vector<double>>(e) << '\n';
        cout << '\n';
    }
}

int main()
try {
    test<SecureE>(_5_4_3_2_1_Ee, _2_3_4_5_6_7_Ee);
    test<SecureA>(_5_4_3_2_1_Ea, _2_3_4_5_6_7_Ea);
}
catch(const string & e) { cout << e << '\n'; }
catch(const char   * e) { cout << e << '\n'; }
