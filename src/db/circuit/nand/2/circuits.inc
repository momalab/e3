template<> void $NameUint<2>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_nand(a[1], a[1]);
  auto n16 = gate_nand(b[1], n13);
  auto n14 = gate_nand(b[1], b[1]);
  auto n15 = gate_nand(a[1], n14);
  auto n19 = gate_nand(n16, n15);
  auto n18 = gate_nand(n19, n19);
  auto n22 = gate_nand(b[0], a[0]);
  auto n17 = gate_nand(n22, n22);
  auto n21 = gate_nand(n18, n17);
  auto n20 = gate_nand(n19, n22);
  y[1] = gate_nand(n21, n20);
  auto n24 = gate_nand(n22, a[0]);
  auto n23 = gate_nand(n22, b[0]);
  auto _add_x_1_n24 = gate_nand(n24, n23);
  y[0] = gate_buf(_add_x_1_n24);
}
template<> void $NameUint<2>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_nand(b[1], a[1]);
  y[1] = gate_nand(n3, n3);
  auto n4 = gate_nand(b[0], a[0]);
  y[0] = gate_nand(n4, n4);
}
template<> void $NameUint<2>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_nand(a[1], a[1]);
  y[0] = gate_nand(a[0], a[0]);
}
template<> void $NameUint<2>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[1], b[1]);
  auto n5 = gate_nand(a[1], a[1]);
  y[1] = gate_nand(n6, n5);
  auto n8 = gate_nand(b[0], b[0]);
  auto n7 = gate_nand(a[0], a[0]);
  y[0] = gate_nand(n8, n7);
}
template<> void $NameUint<2>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(b[1], b[1]);
  auto n12 = gate_nand(a[1], n9);
  auto n10 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(b[1], n10);
  y[1] = gate_nand(n12, n11);
  auto n13 = gate_nand(b[0], b[0]);
  auto n16 = gate_nand(a[0], n13);
  auto n14 = gate_nand(a[0], a[0]);
  auto n15 = gate_nand(b[0], n14);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<2>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n3, n3);
  auto n4 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n4, n4);
}
template<> void $NameUint<2>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n8 = gate_nand(a[0], a[0]);
  auto n7 = gate_nand(n8, c[0]);
  auto n6 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n7, n6);
  auto n10 = gate_nand(n8, c[1]);
  auto n9 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n10, n9);
}
template<> void $NameUint<2>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[0]);
  auto n8 = gate_nand(a[1], y[0]);
  auto n6 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(a[0], n6);
  auto n9 = gate_nand(n8, n7);
  y[1] = gate_nand(n9, n9);
}
template<> void $NameUint<2>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(b[1], b[1]);
  auto n5 = gate_nand(b[0], b[0]);
  auto n3 = gate_nand(n1, n5);
  auto n2 = gate_nand(n1, a[1]);
  y[1] = gate_nand(n3, n2);
  auto n4 = gate_nand(a[1], a[1]);
  auto n6 = gate_nand(n4, b[1]);
  auto n8 = gate_nand(n6, a[0]);
  auto n7 = gate_nand(n6, n5);
  y[0] = gate_nand(n8, n7);
}
template<> void $NameUint<2>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const Bit & one) noexcept
{
  auto n1 = gate_nand(b[0], a[0]);
  auto n13 = gate_nand(b[0], b[0]);
  auto n16 = gate_nand(a[1], n13);
  auto n2 = gate_nand(n1, n16);
  auto n5 = gate_nand(n2, b[1]);
  auto n4 = gate_nand(n5, n5);
  auto n3 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(n4, n3);
  auto n6 = gate_nand(n5, a[1]);
  y[1] = gate_nand(n7, n6);
  auto n12 = gate_nand(a[1], one);
  auto n9 = gate_nand(b[1], b[1]);
  auto n10 = gate_nand(n9, n13);
  auto n11 = gate_nand(n10, n10);
  auto n20 = gate_nand(n12, n11);
  auto n15 = gate_nand(a[0], a[0]);
  auto n14 = gate_nand(b[1], n15);
  auto n18 = gate_nand(n14, n13);
  auto n17 = gate_nand(n16, n15);
  auto n19 = gate_nand(n18, n17);
  y[0] = gate_nand(n20, n19);
}
template<> void $NameUint<2>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_nand(a[0], a[0]);
  auto n15 = gate_nand(n18, b[0]);
  auto n17 = gate_nand(n15, a[1]);
  auto n14 = gate_nand(b[1], b[1]);
  auto n16 = gate_nand(n15, n14);
  auto n19 = gate_nand(n17, n16);
  auto n21 = gate_nand(n19, n18);
  auto n20 = gate_nand(n19, b[0]);
  auto n23 = gate_nand(n21, n20);
  auto n22 = gate_nand(a[1], a[1]);
  auto n25 = gate_nand(n23, n22);
  auto n24 = gate_nand(n23, b[1]);
  y[0] = gate_nand(n25, n24);
}
template<> void $NameUint<2>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(b[1], b[1]);
  auto n15 = gate_nand(n9, a[1]);
  auto n10 = gate_nand(a[0], a[0]);
  auto n13 = gate_nand(b[0], n10);
  auto n11 = gate_nand(a[1], a[1]);
  auto n12 = gate_nand(b[1], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_nand(n15, n14);
}
template<> void $NameUint<2>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(a[1], a[1]);
  auto n15 = gate_nand(n9, b[1]);
  auto n10 = gate_nand(a[0], a[0]);
  auto n13 = gate_nand(b[0], n10);
  auto n11 = gate_nand(b[1], b[1]);
  auto n12 = gate_nand(a[1], n11);
  auto n14 = gate_nand(n13, n12);
  y[0] = gate_nand(n15, n14);
}
template<> void $NameUint<2>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_nand(b[1], b[1]);
  auto n14 = gate_nand(n10, a[1]);
  auto n16 = gate_nand(n14, b[0]);
  auto n11 = gate_nand(a[1], a[1]);
  auto n12 = gate_nand(n11, b[1]);
  auto n13 = gate_nand(n12, a[0]);
  auto n15 = gate_nand(n14, n13);
  auto n17 = gate_nand(n16, n15);
  y[0] = gate_nand(n17, n17);
}
template<> void $NameUint<2>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_nand(a[1], a[1]);
  auto n14 = gate_nand(n10, b[1]);
  auto n16 = gate_nand(n14, b[0]);
  auto n11 = gate_nand(b[1], b[1]);
  auto n12 = gate_nand(n11, a[1]);
  auto n13 = gate_nand(n12, a[0]);
  auto n15 = gate_nand(n14, n13);
  auto n17 = gate_nand(n16, n15);
  y[0] = gate_nand(n17, n17);
}
template<> void $NameUint<2>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[0]);
  auto n7 = gate_nand(a[1], y[0]);
  auto n5 = gate_nand(a[1], a[1]);
  auto n6 = gate_nand(a[0], n5);
  y[1] = gate_nand(n7, n6);
}
template<> void $NameUint<2>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_nand(a[0], a[0]);
  auto n11 = gate_nand(n15, b[0]);
  auto n13 = gate_nand(n11, b[1]);
  auto n14 = gate_nand(a[1], a[1]);
  auto n12 = gate_nand(n11, n14);
  auto n20 = gate_nand(n13, n12);
  auto n16 = gate_nand(n14, b[1]);
  auto n18 = gate_nand(n16, b[0]);
  auto n17 = gate_nand(n16, n15);
  auto n19 = gate_nand(n18, n17);
  auto _ne_x_1_n22 = gate_nand(n20, n19);
  y[0] = gate_buf(_ne_x_1_n22);
}
template<> void $NameUint<2>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n10 = gate_nand(a[0], a[0]);
  auto n9 = gate_nand(a[1], a[1]);
  auto n13 = gate_nand(n10, n9);
  auto n12 = gate_nand(n13, b[0]);
  auto n14 = gate_nand(n13, n13);
  auto n11 = gate_nand(n14, c[0]);
  y[0] = gate_nand(n12, n11);
  auto n16 = gate_nand(n13, b[1]);
  auto n15 = gate_nand(n14, c[1]);
  y[1] = gate_nand(n16, n15);
}
template<> void $NameUint<2>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(a[1], a[1]);
  auto n14 = gate_nand(n8, b[1]);
  auto n9 = gate_nand(b[0], b[0]);
  auto n12 = gate_nand(a[0], n9);
  auto n10 = gate_nand(b[1], b[1]);
  auto n11 = gate_nand(a[1], n10);
  auto n13 = gate_nand(n12, n11);
  auto _lte_x_1_n23 = gate_nand(n14, n13);
  y[0] = gate_buf(_lte_x_1_n23);
}
template<> void $NameUint<2>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(b[1], b[1]);
  auto n14 = gate_nand(n8, a[1]);
  auto n9 = gate_nand(b[0], b[0]);
  auto n12 = gate_nand(a[0], n9);
  auto n10 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(b[1], n10);
  auto n13 = gate_nand(n12, n11);
  auto _lte_x_1_n23 = gate_nand(n14, n13);
  y[0] = gate_buf(_lte_x_1_n23);
}
template<> void $NameUint<2>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_nand(b[0], b[0]);
  auto n6 = gate_nand(b[1], b[1]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n8, a[0]);
  auto n9 = gate_nand(n8, a[1]);
  y[0] = gate_nand(n10, n9);
}
template<> void $NameUint<2>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[0], a[0]);
  auto n5 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(n6, n5);
  y[0] = gate_nand(n7, n7);
}
template<> void $NameUint<2>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_nand(a[1], a[1]);
  auto n9 = gate_nand(b[1], b[1]);
  auto n11 = gate_nand(n10, n9);
  auto n16 = gate_nand(n11, n11);
  auto n13 = gate_nand(b[0], b[0]);
  auto n12 = gate_nand(a[0], a[0]);
  auto n14 = gate_nand(n13, n12);
  auto n15 = gate_nand(n14, n14);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<2>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(a[1], a[1]);
  auto n12 = gate_nand(n8, b[1]);
  auto n14 = gate_nand(n12, a[0]);
  auto n9 = gate_nand(b[1], b[1]);
  auto n10 = gate_nand(n9, a[1]);
  auto n11 = gate_nand(n10, b[0]);
  auto n13 = gate_nand(n12, n11);
  auto n15 = gate_nand(n14, n13);
  auto _lt_x_1_n23 = gate_nand(n15, n15);
  y[0] = gate_buf(_lt_x_1_n23);
}
template<> void $NameUint<2>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(b[1], b[1]);
  auto n13 = gate_nand(n9, a[1]);
  auto n15 = gate_nand(n13, a[0]);
  auto n10 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(n10, b[1]);
  auto n12 = gate_nand(n11, b[0]);
  auto n14 = gate_nand(n13, n12);
  auto n16 = gate_nand(n15, n14);
  auto _lt_x_1_n23 = gate_nand(n16, n16);
  y[0] = gate_buf(_lt_x_1_n23);
}
template<> void $NameUint<2>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[1], a[1]);
  auto n2 = gate_nand(b[1], n1);
  auto n3 = gate_nand(n2, b[0]);
  auto n4 = gate_nand(n3, a[0]);
  y[0] = gate_nand(n4, n4);
  auto n5 = gate_nand(b[1], b[1]);
  auto n7 = gate_nand(a[1], n5);
  auto n6 = gate_nand(a[1], b[0]);
  auto n9 = gate_nand(n7, n6);
  auto n8 = gate_nand(b[0], b[0]);
  auto n14 = gate_nand(n9, n8);
  auto n10 = gate_nand(n9, b[1]);
  auto n12 = gate_nand(n10, n10);
  auto n11 = gate_nand(a[0], a[0]);
  auto n13 = gate_nand(n12, n11);
  y[1] = gate_nand(n14, n13);
}
template<> void $NameUint<2>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[0], b[0]);
  auto n1 = gate_nand(a[1], n6);
  auto n3 = gate_nand(n1, n1);
  auto n5 = gate_nand(n3, a[0]);
  auto n2 = gate_nand(b[1], b[1]);
  auto n4 = gate_nand(n3, n2);
  y[1] = gate_nand(n5, n4);
  auto n7 = gate_nand(a[0], n6);
  y[0] = gate_nand(n7, n7);
}
template<> void $NameUint<2>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(b[0], a[0]);
  y[0] = gate_nand(n8, n8);
  auto n11 = gate_nand(a[1], b[0]);
  auto n9 = gate_nand(n11, n11);
  auto n10 = gate_nand(b[1], a[0]);
  auto n14 = gate_nand(n9, n10);
  auto n12 = gate_nand(n10, n10);
  auto n13 = gate_nand(n12, n11);
  y[1] = gate_nand(n14, n13);
}
template<> void $NameUint<2>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_nand(a[0], a[1]);
  y[0] = gate_nand(n2, n2);
}
template<> void $NameUint<2>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[1]);
}
template<> void $NameUint<2>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[0], a[0]);
  auto n5 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(n6, n5);
  y[0] = gate_nand(n7, n7);
}
template<> void $NameUint<2>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_nand(a[0], a[0]);
  auto n3 = gate_nand(a[1], a[1]);
  y[0] = gate_nand(n4, n3);
}
template<> void $NameUint<2>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_nand(a[0], a[0]);
  auto n10 = gate_nand(a[1], n7);
  auto n8 = gate_nand(a[1], a[1]);
  auto n9 = gate_nand(a[0], n8);
  auto n11 = gate_nand(n10, n9);
  y[0] = gate_nand(n11, n11);
}
template<> void $NameUint<2>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_nand(a[0], a[0]);
  auto n8 = gate_nand(a[1], n5);
  auto n6 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(a[0], n6);
  y[0] = gate_nand(n8, n7);
}
template<> void $NameUint<2>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_nand(b[0], b[0]);
  auto n13 = gate_nand(a[0], n19);
  auto n14 = gate_nand(n13, n13);
  auto n16 = gate_nand(b[1], b[1]);
  auto n15 = gate_nand(n14, n16);
  y[0] = gate_nand(n15, n15);
  auto n18 = gate_nand(n16, a[1]);
  auto n17 = gate_nand(n16, b[0]);
  auto n20 = gate_nand(n18, n17);
  auto n22 = gate_nand(n20, n19);
  auto n21 = gate_nand(n20, a[0]);
  y[1] = gate_nand(n22, n21);
}
template<> void $NameUint<2>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_nand(b[0], b[0]);
  auto n13 = gate_nand(a[1], n19);
  auto n14 = gate_nand(n13, n13);
  auto n16 = gate_nand(b[1], b[1]);
  auto n15 = gate_nand(n14, n16);
  y[1] = gate_nand(n15, n15);
  auto n18 = gate_nand(n16, a[0]);
  auto n17 = gate_nand(n16, b[0]);
  auto n20 = gate_nand(n18, n17);
  auto n22 = gate_nand(n20, n19);
  auto n21 = gate_nand(n20, a[1]);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<2>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_buf(a[1]);
  auto n9 = gate_nand(b[0], b[0]);
  auto n8 = gate_nand(b[1], b[1]);
  auto n10 = gate_nand(n9, n8);
  auto n13 = gate_nand(n10, a[1]);
  auto n11 = gate_nand(n10, n10);
  auto n12 = gate_nand(n11, a[0]);
  y[0] = gate_nand(n13, n12);
}
template<> void $NameUint<2>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_nand(b[0], b[0]);
  auto n16 = gate_nand(n14, a[0]);
  auto n15 = gate_nand(a[0], a[0]);
  auto n23 = gate_nand(b[0], n15);
  y[0] = gate_nand(n16, n23);
  auto n17 = gate_nand(b[1], b[1]);
  auto n20 = gate_nand(a[1], n17);
  auto n18 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(b[1], n18);
  auto n24 = gate_nand(n20, n19);
  auto n22 = gate_nand(n24, n24);
  auto n21 = gate_nand(n23, n23);
  auto n26 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  y[1] = gate_nand(n26, n25);
}
template<> void $NameUint<2>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n5 = gate_nand(a[0], a[0]);
  auto n8 = gate_nand(a[1], n5);
  auto n6 = gate_nand(a[1], a[1]);
  auto n7 = gate_nand(a[0], n6);
  y[1] = gate_nand(n8, n7);
}