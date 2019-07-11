// === BEGIN mod.pilx.inc Name0=$Name0 Name1=$Name1

///#ifdef AAA
template<int SZ>
$Name1 to_$Name1(const $Name0Uint<SZ> & c)
{
    auto i = c.size();
    $Name1 r ( c[--i].native() );
    while (i--) r += r + c[i].native();
    return r;
}
///#endif

// === END mod.pilx.inc Name0=$Name0 Name1=$Name1
