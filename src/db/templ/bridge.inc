// === BEGIN bridge.inc Name0=$Name0 Name1=$Name1

template<int SZ>
$Name1 to_$Name1(const $Name0Uint<SZ> & c)
{
    auto i = SZ;
    $Name1 r ( c[--i].native() );
    while (i--) r += r + c[i].native();
    return r;
}

// === END bridge.inc Name0=$Name0 Name1=$Name1
