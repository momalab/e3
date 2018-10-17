template<> void $NameUint<1>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xor(b[0], a[0]);
}


template<> void $NameUint<1>::d_and
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_and(b[0], a[0]);
}


template<> void $NameUint<1>::d_bmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_and(b[0], a[0]);
}


template<> void $NameUint<1>::d_bmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
    y[0] = gate_mux(a[0], b[0], c[0]);
}


template<> void $NameUint<1>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n1 = gate_not(a[0]);
    y[0] = gate_nand(b[0], n1);
}


template<> void $NameUint<1>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xnor(b[0], a[0]);
}


template<> void $NameUint<1>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n3 = gate_not(a[0]);
    y[0] = gate_nand(b[0], n3);
}


template<> void $NameUint<1>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(b[0]);
    y[0] = gate_and(a[0], n4);
}


template<> void $NameUint<1>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xor(b[0], a[0]);
}


template<> void $NameUint<1>::d_land
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_and(b[0], a[0]);
}


template<> void $NameUint<1>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n3 = gate_not(b[0]);
    y[0] = gate_nand(a[0], n3);
}


template<> void $NameUint<1>::d_lnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_lor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(b[0]);
    auto n3 = gate_not(a[0]);
    y[0] = gate_nand(n4, n3);
}


template<> void $NameUint<1>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(a[0]);
    y[0] = gate_and(b[0], n4);
}


template<> void $NameUint<1>::d_mm
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n2 = gate_not(b[0]);
    y[0] = gate_and(a[0], n2);
}


template<> void $NameUint<1>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_and(b[0], a[0]);
}


template<> void $NameUint<1>::d_mux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
    y[0] = gate_mux(a[0], b[0], c[0]);
}


template<> void $NameUint<1>::d_not
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_or
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(b[0]);
    auto n3 = gate_not(a[0]);
    y[0] = gate_nand(n4, n3);
}


template<> void $NameUint<1>::d_pp
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = y[0] ;
    y[0]  = a[0];
}


template<> void $NameUint<1>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = y[0] ;
    y[0]  = a[0];
}


template<> void $NameUint<1>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<1>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = y[0] ;
    y[0]  = a[0];
}


template<> void $NameUint<1>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(b[0]);
    y[0] = gate_and(a[0], n4);
}


template<> void $NameUint<1>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n4 = gate_not(b[0]);
    y[0] = gate_and(a[0], n4);
}


template<> void $NameUint<1>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xor(b[0], a[0]);
}


template<> void $NameUint<1>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = y[0] ;
    y[0]  = a[0];
}


template<> void $NameUint<1>::d_xor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xor(b[0], a[0]);
}
