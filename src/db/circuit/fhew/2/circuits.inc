template<> void $NameUint<2>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_nor(b[0], a[0]);
  auto n27 = gate_not(b[0]);
  auto n26 = gate_not(a[0]);
  auto n28 = gate_or(n27, n26);
  auto n24 = gate_nor(a[1], n28);
  auto n33 = gate_not(n28);
  y[0] = gate_nor(n33, n23);
  auto n29 = gate_not(a[1]);
  auto n22 = gate_nor(n33, n29);
  auto n31 = gate_or(n24, n22);
  auto n30 = gate_not(b[1]);
  auto n20 = gate_nor(n31, n30);
  auto n32 = gate_not(n31);
  auto n25 = gate_nor(b[1], n32);
  y[1] = gate_or(n20, n25);
}
template<> void $NameUint<2>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n11 = gate_not(b[0]);
  auto n9 = gate_not(b[1]);
  y[1] = gate_nor(n10, n9);
  auto n12 = gate_not(a[0]);
  y[0] = gate_nor(n12, n11);
}
template<> void $NameUint<2>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<2>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<2>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[1]);
  auto n16 = gate_nor(a[1], n17);
  auto n18 = gate_not(a[1]);
  auto n13 = gate_nor(b[1], n18);
  y[1] = gate_or(n16, n13);
  auto n19 = gate_not(b[0]);
  auto n15 = gate_nor(a[0], n19);
  auto n20 = gate_not(a[0]);
  auto n14 = gate_nor(b[0], n20);
  y[0] = gate_or(n15, n14);
}
template<> void $NameUint<2>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(a[0]);
  auto n9 = gate_not(b[1]);
  y[1] = gate_nor(n10, n9);
  auto n8 = gate_not(b[0]);
  y[0] = gate_nor(n10, n8);
}
template<> void $NameUint<2>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n16 = gate_nor(a[0], c[1]);
  auto n18 = gate_not(a[0]);
  auto n12 = gate_nor(b[0], n18);
  auto n15 = gate_nor(b[1], n18);
  y[1] = gate_nor(n15, n16);
  auto n17 = gate_nor(a[0], c[0]);
  y[0] = gate_nor(n12, n17);
}
template<> void $NameUint<2>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n11 = gate_not(a[1]);
  auto n8 = gate_nor(a[0], n11);
  auto n10 = gate_nor(a[1], y[0]);
  y[1] = gate_nor(n10, n8);
}
template<> void $NameUint<2>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_not(b[1]);
  auto n7 = gate_not(b[0]);
  auto n1 = gate_nor(a[0], n7);
  auto n4 = gate_nor(a[1], n7);
  y[1] = gate_nor(b[1], n4);
  auto n5 = gate_nor(a[1], n6);
  y[0] = gate_nor(n5, n1);
}
template<> void $NameUint<2>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[0]);
  auto n17 = gate_not(b[1]);
  auto n6 = gate_nor(n14, n17);
  auto n12 = gate_nor(a[1], n6);
  auto n16 = gate_not(a[1]);
  auto n3 = gate_nor(n14, n16);
  auto n8 = gate_nor(a[0], n16);
  auto n9 = gate_nor(n8, n17);
  auto n10 = gate_nor(b[1], n16);
  auto n1 = gate_nor(n10, n9);
  auto n13 = gate_nor(b[0], n1);
  auto n15 = gate_not(b[0]);
  auto n2 = gate_nor(n3, n15);
  auto n4 = gate_nor(n2, n17);
  y[1] = gate_nor(n4, n12);
  auto n11 = gate_nor(a[0], n15);
  y[0] = gate_nor(n11, n13);
}
template<> void $NameUint<2>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[0]);
  auto n20 = gate_nor(a[0], n22);
  auto n23 = gate_not(a[0]);
  auto n17 = gate_nor(b[0], n23);
  auto n27 = gate_or(n20, n17);
  auto n24 = gate_not(b[1]);
  auto n21 = gate_nor(a[1], n24);
  auto n25 = gate_not(a[1]);
  auto n19 = gate_nor(b[1], n25);
  auto n26 = gate_or(n21, n19);
  y[0] = gate_nor(n27, n26);
}
template<> void $NameUint<2>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[0]);
  auto n18 = gate_or(n15, a[0]);
  auto n14 = gate_nor(a[1], n18);
  auto n12 = gate_nor(b[1], n14);
  auto n17 = gate_not(n18);
  auto n16 = gate_not(a[1]);
  auto n13 = gate_nor(n17, n16);
  y[0] = gate_or(n13, n12);
}
template<> void $NameUint<2>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[0]);
  auto n19 = gate_or(n16, a[0]);
  auto n15 = gate_nor(b[1], n19);
  auto n13 = gate_nor(a[1], n15);
  auto n18 = gate_not(n19);
  auto n17 = gate_not(b[1]);
  auto n14 = gate_nor(n18, n17);
  y[0] = gate_or(n14, n13);
}
template<> void $NameUint<2>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[0]);
  auto n18 = gate_not(b[1]);
  auto n20 = gate_or(n17, b[0]);
  auto n16 = gate_nor(b[1], n20);
  auto n13 = gate_nor(a[1], n16);
  auto n19 = gate_not(n20);
  auto n15 = gate_nor(n19, n18);
  y[0] = gate_nor(n15, n13);
}
template<> void $NameUint<2>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[0]);
  auto n17 = gate_not(a[1]);
  auto n19 = gate_or(n16, b[0]);
  auto n15 = gate_nor(a[1], n19);
  auto n13 = gate_nor(b[1], n15);
  auto n18 = gate_not(n19);
  auto n14 = gate_nor(n18, n17);
  y[0] = gate_nor(n14, n13);
}
template<> void $NameUint<2>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n8 = gate_nor(a[1], y[0]);
  auto n9 = gate_not(a[1]);
  auto n7 = gate_nor(a[0], n9);
  y[1] = gate_or(n8, n7);
}
template<> void $NameUint<2>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(b[0]);
  auto n17 = gate_nor(a[0], n19);
  auto n20 = gate_not(a[0]);
  auto n16 = gate_nor(b[0], n20);
  auto n24 = gate_or(n17, n16);
  auto n21 = gate_not(b[1]);
  auto n18 = gate_nor(a[1], n21);
  auto n22 = gate_not(a[1]);
  auto n15 = gate_nor(b[1], n22);
  auto n23 = gate_or(n18, n15);
  auto _ne_x_1_n19 = gate_or(n24, n23);
  y[0] = gate_buf(_ne_x_1_n19);
}
template<> void $NameUint<2>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n19 = gate_or(a[1], a[0]);
  auto n20 = gate_not(n19);
  auto n15 = gate_nor(n20, b[1]);
  auto n16 = gate_nor(n20, b[0]);
  auto n17 = gate_nor(c[1], n19);
  y[1] = gate_nor(n17, n15);
  auto n18 = gate_nor(c[0], n19);
  y[0] = gate_nor(n18, n16);
}
template<> void $NameUint<2>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[0]);
  auto n17 = gate_or(n14, b[0]);
  auto n13 = gate_nor(b[1], n17);
  auto n11 = gate_nor(a[1], n13);
  auto n16 = gate_not(n17);
  auto n15 = gate_not(b[1]);
  auto n12 = gate_nor(n16, n15);
  auto _lte_x_1_n20 = gate_or(n12, n11);
  y[0] = gate_buf(_lte_x_1_n20);
}
template<> void $NameUint<2>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[0]);
  auto n17 = gate_or(n14, b[0]);
  auto n13 = gate_nor(a[1], n17);
  auto n11 = gate_nor(b[1], n13);
  auto n16 = gate_not(n17);
  auto n15 = gate_not(a[1]);
  auto n12 = gate_nor(n16, n15);
  auto _lte_x_1_n20 = gate_or(n12, n11);
  y[0] = gate_buf(_lte_x_1_n20);
}
template<> void $NameUint<2>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nor(a[1], a[0]);
  auto n8 = gate_nor(b[1], b[0]);
  y[0] = gate_nor(n8, n6);
}
template<> void $NameUint<2>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nor(a[1], a[0]);
}
template<> void $NameUint<2>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_or(a[1], a[0]);
  auto n3 = gate_or(b[1], b[0]);
  y[0] = gate_or(n4, n3);
}
template<> void $NameUint<2>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[0]);
  auto n18 = gate_not(a[1]);
  auto n20 = gate_or(n17, a[0]);
  auto n16 = gate_nor(a[1], n20);
  auto n14 = gate_nor(b[1], n16);
  auto n19 = gate_not(n20);
  auto n15 = gate_nor(n19, n18);
  y[0] = gate_nor(n15, n14);
}
template<> void $NameUint<2>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[0]);
  auto n18 = gate_not(b[1]);
  auto n20 = gate_or(n17, a[0]);
  auto n16 = gate_nor(b[1], n20);
  auto n13 = gate_nor(a[1], n16);
  auto n19 = gate_not(n20);
  auto n14 = gate_nor(n19, n18);
  y[0] = gate_nor(n14, n13);
}
template<> void $NameUint<2>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(b[0]);
  auto n10 = gate_not(b[1]);
  auto n1 = gate_nor(n10, b[0]);
  auto n6 = gate_nor(n10, a[0]);
  auto n3 = gate_nor(n6, n9);
  auto n11 = gate_or(n3, n1);
  auto n7 = gate_nor(n10, a[1]);
  auto n4 = gate_nor(n9, n7);
  auto n8 = gate_not(a[0]);
  y[0] = gate_nor(n4, n8);
  auto n12 = gate_not(a[1]);
  y[1] = gate_nor(n12, n11);
}
template<> void $NameUint<2>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(b[1]);
  auto n7 = gate_not(a[0]);
  y[0] = gate_nor(b[0], n7);
  auto n3 = gate_nor(n4, a[0]);
  auto n5 = gate_not(a[1]);
  auto n6 = gate_or(b[0], n5);
  y[1] = gate_nor(n3, n6);
}
template<> void $NameUint<2>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(b[0]);
  auto n20 = gate_not(a[0]);
  y[0] = gate_nor(n18, n20);
  auto n17 = gate_not(a[1]);
  auto n23 = gate_or(n18, n17);
  auto n21 = gate_not(n23);
  auto n19 = gate_not(b[1]);
  auto n22 = gate_or(n20, n19);
  auto n14 = gate_nor(n21, n22);
  auto n24 = gate_not(n22);
  auto n16 = gate_nor(n24, n23);
  y[1] = gate_or(n14, n16);
}
template<> void $NameUint<2>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_not(a[1]);
  auto n5 = gate_not(a[0]);
  y[0] = gate_nor(n6, n5);
}
template<> void $NameUint<2>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_not(a[1]);
  auto n4 = gate_not(a[0]);
  y[0] = gate_or(n5, n4);
}
template<> void $NameUint<2>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nor(a[1], a[0]);
}
template<> void $NameUint<2>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_or(a[1], a[0]);
}
template<> void $NameUint<2>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[0]);
  auto n13 = gate_not(a[1]);
  auto n9 = gate_nor(a[0], n13);
  auto n11 = gate_nor(a[1], n12);
  y[0] = gate_nor(n11, n9);
}
template<> void $NameUint<2>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_nor(a[1], n9);
  auto n10 = gate_not(a[1]);
  auto n7 = gate_nor(a[0], n10);
  y[0] = gate_or(n8, n7);
}
template<> void $NameUint<2>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_nor(a[1], b[0]);
  auto n15 = gate_not(a[0]);
  auto n16 = gate_or(b[0], n15);
  y[0] = gate_nor(b[1], n16);
  auto n17 = gate_not(b[0]);
  auto n14 = gate_nor(a[0], n17);
  auto n18 = gate_or(n11, n14);
  y[1] = gate_nor(b[1], n18);
}
template<> void $NameUint<2>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_nor(a[0], b[0]);
  auto n17 = gate_not(b[0]);
  auto n16 = gate_nor(a[1], n17);
  auto n18 = gate_or(n13, n16);
  y[0] = gate_nor(b[1], n18);
  auto n19 = gate_not(a[1]);
  auto n20 = gate_or(b[0], n19);
  y[1] = gate_nor(b[1], n20);
}
template<> void $NameUint<2>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_buf(a[1]);
  auto n11 = gate_or(b[1], b[0]);
  auto n10 = gate_nor(a[0], n11);
  auto n12 = gate_not(n11);
  auto n8 = gate_nor(n12, a[1]);
  y[0] = gate_nor(n10, n8);
}
template<> void $NameUint<2>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[0]);
  auto n26 = gate_or(a[0], n24);
  auto n22 = gate_nor(a[1], n26);
  auto n28 = gate_not(n26);
  auto n25 = gate_not(a[0]);
  auto n19 = gate_nor(b[0], n25);
  y[0] = gate_or(n28, n19);
  auto n27 = gate_not(a[1]);
  auto n21 = gate_nor(n28, n27);
  auto n30 = gate_or(n22, n21);
  auto n29 = gate_not(b[1]);
  auto n20 = gate_nor(n30, n29);
  auto n31 = gate_not(n30);
  auto n23 = gate_nor(b[1], n31);
  y[1] = gate_or(n20, n23);
}
template<> void $NameUint<2>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n9 = gate_not(a[0]);
  auto n8 = gate_nor(a[1], n9);
  auto n10 = gate_not(a[1]);
  auto n7 = gate_nor(a[0], n10);
  y[1] = gate_or(n8, n7);
}
