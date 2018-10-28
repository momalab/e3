template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n8 = gate_and(b[0], a[0]);
    auto n9 = gate_xor(b[1], a[1]);
    y[1] = gate_xor(n8, n9);
    auto n11 = gate_nand(n8, n9);
    auto n10 = gate_nand(b[1], a[1]);
    auto n12 = gate_nand(n11, n10);
    auto n13 = gate_xor(b[2], n12);
    y[2] = gate_xor(a[2], n13);
    y[0] = gate_xor(b[0], a[0]);
}


template<> void $NameUint<3>::d_and
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[2] = gate_and(b[2], a[2]);
    y[0] = gate_and(b[0], a[0]);
    y[1] = gate_and(b[1], a[1]);
}


template<> void $NameUint<3>::d_bmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[2] = gate_and(a[0], b[2]);
    y[1] = gate_and(a[0], b[1]);
    y[0] = gate_and(a[0], b[0]);
}


template<> void $NameUint<3>::d_bmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
    y[0] = gate_mux(a[0], b[0], c[0]);
    y[1] = gate_mux(a[0], b[1], c[1]);
    y[2] = gate_mux(a[0], b[2], c[2]);
}


template<> void $NameUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n22 = gate_not(b[2]);
    auto n1 = gate_and(b[1], n22);
    auto n7 = gate_not(a[1]);
    auto n8 = gate_nand(b[0], n7);
    auto n23 = gate_nand(n22, n8);
    auto n6 = gate_and(a[2], n23);
    auto n10 = gate_not(n23);
    auto n19 = gate_not(a[2]);
    auto n9 = gate_nand(b[1], n19);
    y[1] = gate_and(n10, n9);
    auto n13 = gate_not(b[1]);
    auto n2 = gate_and(n22, n13);
    auto n11 = gate_nand(b[0], n19);
    y[2] = gate_and(n2, n11);
    auto n12 = gate_nand(y[1], b[0]);
    auto n5 = gate_and(a[1], n12);
    auto n18 = gate_nand(n13, n5);
    auto n16 = gate_xor(n13, n5);
    auto n14 = gate_not(a[0]);
    auto n15 = gate_nand(b[0], n14);
    auto n17 = gate_nand(n16, n15);
    auto n21 = gate_nand(n18, n17);
    auto n20 = gate_nand(b[2], n19);
    auto n25 = gate_nand(n21, n20);
    auto n24 = gate_nand(n1, n6);
    y[0] = gate_nand(n25, n24);
}


template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n11 = gate_xnor(a[2], b[2]);
    auto n14 = gate_xnor(a[0], b[0]);
    auto n13 = gate_and(n11, n14);
    auto n15 = gate_xnor(a[1], b[1]);
    y[0] = gate_and(n13, n15);
}


template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n13 = gate_not(b[2]);
    auto n23 = gate_nand(n13, a[2]);
    auto n21 = gate_xor(n13, a[2]);
    auto n14 = gate_not(b[1]);
    auto n19 = gate_nand(n14, a[1]);
    auto n17 = gate_xor(n14, a[1]);
    auto n15 = gate_not(a[0]);
    auto n16 = gate_nand(b[0], n15);
    auto n18 = gate_nand(n17, n16);
    auto n20 = gate_nand(n19, n18);
    auto n22 = gate_nand(n21, n20);
    y[0] = gate_nand(n23, n22);
}


template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n15 = gate_not(a[1]);
    auto n20 = gate_nand(n15, b[1]);
    auto n18 = gate_xor(n15, b[1]);
    auto n16 = gate_not(b[0]);
    auto n17 = gate_nand(a[0], n16);
    auto n19 = gate_nand(n18, n17);
    auto n21 = gate_nand(n20, n19);
    auto n25 = gate_nand(n21, b[2]);
    auto n23 = gate_xor(n21, b[2]);
    auto n22 = gate_not(a[2]);
    auto n24 = gate_nand(n23, n22);
    y[0] = gate_and(n25, n24);
}


template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n9 = gate_xnor(b[2], a[2]);
    auto n11 = gate_xnor(a[0], b[0]);
    auto n10 = gate_and(n9, n11);
    auto n12 = gate_xnor(a[1], b[1]);
    y[0] = gate_nand(n10, n12);
}


template<> void $NameUint<3>::d_land
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n18 = gate_not(a[0]);
    auto n17 = gate_not(a[1]);
    auto n15 = gate_and(n18, n17);
    auto n19 = gate_not(a[2]);
    auto n24 = gate_nand(n15, n19);
    auto n21 = gate_not(b[1]);
    auto n20 = gate_not(b[2]);
    auto n14 = gate_and(n21, n20);
    auto n22 = gate_not(b[0]);
    auto n23 = gate_nand(n14, n22);
    y[0] = gate_and(n24, n23);
}


template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n16 = gate_not(a[1]);
    auto n21 = gate_nand(n16, b[1]);
    auto n19 = gate_xor(n16, b[1]);
    auto n17 = gate_not(b[0]);
    auto n18 = gate_nand(a[0], n17);
    auto n20 = gate_nand(n19, n18);
    auto n22 = gate_nand(n21, n20);
    auto n26 = gate_nand(n22, b[2]);
    auto n24 = gate_xor(n22, b[2]);
    auto n23 = gate_not(a[2]);
    auto n25 = gate_nand(n24, n23);
    y[0] = gate_nand(n26, n25);
}


template<> void $NameUint<3>::d_lnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n11 = gate_not(a[0]);
    auto n10 = gate_not(a[1]);
    auto n8 = gate_and(n11, n10);
    auto n12 = gate_not(a[2]);
    y[0] = gate_and(n8, n12);
}


template<> void $NameUint<3>::d_lor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n20 = gate_not(b[0]);
    auto n19 = gate_not(a[1]);
    auto n17 = gate_and(n20, n19);
    auto n22 = gate_not(a[2]);
    auto n21 = gate_not(b[2]);
    auto n18 = gate_and(n22, n21);
    auto n15 = gate_and(n17, n18);
    auto n23 = gate_not(b[1]);
    auto n16 = gate_and(n15, n23);
    auto n24 = gate_not(a[0]);
    y[0] = gate_nand(n16, n24);
}


template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n14 = gate_not(b[1]);
    auto n19 = gate_nand(n14, a[1]);
    auto n17 = gate_xor(n14, a[1]);
    auto n15 = gate_not(a[0]);
    auto n16 = gate_nand(b[0], n15);
    auto n18 = gate_nand(n17, n16);
    auto n20 = gate_nand(n19, n18);
    auto n24 = gate_nand(n20, a[2]);
    auto n22 = gate_xor(n20, a[2]);
    auto n21 = gate_not(b[2]);
    auto n23 = gate_nand(n22, n21);
    y[0] = gate_and(n24, n23);
}


template<> void $NameUint<3>::d_mm
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = gate_not(a[0]);
    auto n5 = gate_not(a[1]);
    y[1] = gate_xor(a[0], n5);
    auto n7 = gate_not(a[2]);
    auto n6 = gate_nand(y[0], n5);
    y[2] = gate_xor(n7, n6);
}


template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n19 = gate_not(a[0]);
    auto n9 = gate_not(b[2]);
    auto n12 = gate_not(b[1]);
    auto n1 = gate_and(n9, n12);
    auto n5 = gate_nand(b[0], n1);
    auto n4 = gate_and(a[2], n5);
    auto n6 = gate_mux(b[1], a[2], b[0]);
    auto n3 = gate_and(n9, n6);
    auto n7 = gate_not(a[1]);
    auto n8 = gate_nand(b[0], n7);
    auto n11 = gate_nand(n3, n8);
    auto n2 = gate_and(n4, n11);
    auto n28 = gate_nand(n2, n9);
    auto n10 = gate_not(a[2]);
    auto n16 = gate_nand(b[2], n10);
    auto n24 = gate_nand(a[1], n11);
    auto n13 = gate_not(n24);
    auto n15 = gate_nand(n13, n12);
    auto n20 = gate_xor(b[1], n24);
    auto n21 = gate_nand(b[0], n19);
    auto n14 = gate_nand(n20, n21);
    auto n29 = gate_nand(n15, n14);
    auto n17 = gate_nand(n16, n29);
    auto n26 = gate_nand(n28, n17);
    auto n18 = gate_nand(n26, b[0]);
    y[0] = gate_xor(n19, n18);
    auto n22 = gate_not(n20);
    auto n23 = gate_nand(n22, n21);
    auto n25 = gate_mux(n26, n23, n24);
    y[1] = gate_not(n25);
    auto n27 = gate_not(n26);
    auto n32 = gate_nand(n2, n27);
    auto n30 = gate_not(n28);
    auto n31 = gate_nand(n30, n29);
    y[2] = gate_nand(n32, n31);
}


template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n1 = gate_and(a[1], b[1]);
    auto n2 = gate_and(b[2], a[0]);
    auto n6 = gate_nand(b[0], a[0]);
    y[0] = gate_not(n6);
    auto n4 = gate_nand(b[1], a[0]);
    auto n3 = gate_nand(a[1], b[0]);
    y[1] = gate_xor(n4, n3);
    auto n5 = gate_nand(a[2], b[0]);
    auto n8 = gate_xor(n2, n5);
    auto n7 = gate_nand(n6, n1);
    y[2] = gate_xor(n8, n7);
}


template<> void $NameUint<3>::d_mux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
    auto n9 = gate_not(a[0]);
    auto n8 = gate_not(a[1]);
    auto n7 = gate_and(n9, n8);
    auto n10 = gate_not(a[2]);
    auto n11 = gate_nand(n7, n10);
    y[0] = gate_mux(n11, b[0], c[0]);
    y[1] = gate_mux(n11, b[1], c[1]);
    y[2] = gate_mux(n11, b[2], c[2]);
}


template<> void $NameUint<3>::d_not
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[2] = gate_not(a[2]);
    y[1] = gate_not(a[1]);
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<3>::d_or
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n8 = gate_not(b[2]);
    auto n7 = gate_not(a[2]);
    y[2] = gate_nand(n8, n7);
    auto n10 = gate_not(b[1]);
    auto n9 = gate_not(a[1]);
    y[1] = gate_nand(n10, n9);
    auto n12 = gate_not(b[0]);
    auto n11 = gate_not(a[0]);
    y[0] = gate_nand(n12, n11);
}


template<> void $NameUint<3>::d_pp
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[1] = gate_xor(a[0], a[1]);
    auto n5 = gate_not(a[2]);
    auto n4 = gate_nand(a[0], a[1]);
    y[2] = gate_xor(n5, n4);
    y[0] = gate_not(a[0]);
}


template<> void $NameUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n5 = gate_and(a[0], a[1]);
    y[0] = gate_and(a[2], n5);
}


template<> void $NameUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n4 = gate_and(a[0], a[1]);
    y[0] = gate_nand(a[2], n4);
}


template<> void $NameUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n11 = gate_not(a[0]);
    auto n10 = gate_not(a[1]);
    auto n8 = gate_and(n11, n10);
    auto n12 = gate_not(a[2]);
    y[0] = gate_and(n8, n12);
}


template<> void $NameUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n8 = gate_not(a[0]);
    auto n7 = gate_not(a[1]);
    auto n6 = gate_and(n8, n7);
    auto n9 = gate_not(a[2]);
    y[0] = gate_nand(n6, n9);
}


template<> void $NameUint<3>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n5 = gate_xor(a[1], a[2]);
    y[0] = gate_xnor(a[0], n5);
}


template<> void $NameUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    auto n2 = gate_xor(a[2], a[0]);
    y[0] = gate_xor(a[1], n2);
}


template<> void $NameUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n27 = gate_not(b[0]);
    auto n25 = gate_and(a[0], n27);
    auto n32 = gate_not(b[2]);
    auto n28 = gate_not(b[1]);
    auto n23 = gate_and(n32, n28);
    y[0] = gate_and(n25, n23);
    auto n29 = gate_mux(b[0], a[0], a[1]);
    y[1] = gate_and(n23, n29);
    auto n30 = gate_mux(b[0], a[1], a[2]);
    auto n31 = gate_mux(b[1], n25, n30);
    y[2] = gate_and(n32, n31);
}


template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    auto n19 = gate_not(b[0]);
    auto n18 = gate_and(a[2], n19);
    auto n24 = gate_not(b[2]);
    auto n20 = gate_not(b[1]);
    auto n15 = gate_and(n24, n20);
    y[2] = gate_and(n18, n15);
    auto n21 = gate_mux(b[0], a[2], a[1]);
    y[1] = gate_and(n15, n21);
    auto n22 = gate_mux(b[0], a[1], a[0]);
    auto n23 = gate_mux(b[1], n18, n22);
    y[0] = gate_and(n24, n23);
}


template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[0] = gate_xor(a[0], b[0]);
    auto n12 = gate_not(b[1]);
    auto n14 = gate_xor(a[1], n12);
    auto n11 = gate_not(a[0]);
    auto n13 = gate_nand(b[0], n11);
    y[1] = gate_xor(n14, n13);
    auto n16 = gate_nand(a[1], n12);
    auto n15 = gate_nand(n14, n13);
    auto n18 = gate_nand(n16, n15);
    auto n17 = gate_xor(b[2], a[2]);
    y[2] = gate_xnor(n18, n17);
}


template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
    y[0] = a[0];
    y[1] = gate_xor(a[1], a[0]);
    auto n5 = gate_not(a[1]);
    auto n4 = gate_not(a[0]);
    auto n6 = gate_nand(n5, n4);
    y[2] = gate_xor(a[2], n6);
}


template<> void $NameUint<3>::d_xor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
    y[2] = gate_xor(b[2], a[2]);
    y[1] = gate_xor(b[1], a[1]);
    y[0] = gate_xor(b[0], a[0]);
}


