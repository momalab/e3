// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
// === BEGIN bridge.inc Name0=$Name0 Name1=$Name1

template<int SZ>
$Name1 to_$Name1(const $Name0Uint<SZ> & c)
{
    auto i = SZ;
    $Name1 r ( c[--i].native() );
    while (i--) r += r + c[i].native();
    return r;
}

template<int SZ>
$Name1 to_$Name1(const $Name0Int<SZ> & v)
{
    $Name0Uint<SZ> u(v);
    $Name1 pos = to_$Name1(u);

    int mx = 1;
    int size = SZ;
    while (size >= 32) // max shift is 31 bits
    {
        size -= 31;
        mx <<= 31;
    }
    mx <<= size;
    $Name1 neg = $Name1::getPlaintextModulus() + pos - mx;
    //$Name1 neg = pos - mx;

    $Name0Bool isNeg{v[SZ-1]};
    //return pos;
    return isNeg * neg + (!isNeg) * pos;
    //$Name1 isNeg = $Name0Bool(v[SZ-1]);
    //return isNeg * neg + (1-isNeg) * pos;
}

// === END bridge.inc Name0=$Name0 Name1=$Name1
