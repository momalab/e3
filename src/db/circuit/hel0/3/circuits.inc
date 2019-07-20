template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n7);
  auto n10 = gate_and(n8, n7);
  auto n9 = gate_and(b[1], a[1]);
  auto n12 = gate_or(n10, n9);
  auto n11 = gate_xor(a[2], b[2]);
  y[2] = gate_xor(n12, n11);
}
template<> void $NameUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(b[2], a[2]);
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<3>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<3>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_or(a[2], b[2]);
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<3>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  y[1] = gate_and(a[0], b[1]);
  y[2] = gate_and(a[0], b[2]);
}
template<> void $NameUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
}
template<> void $NameUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n4 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n4);
  auto n5 = gate_and(y[0], n4);
  y[2] = gate_xor(a[2], n5);
}
template<> void $NameUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[2]);
  auto n8 = gate_not(a[1]);
  auto n2 = gate_nand(b[0], n8);
  auto n11 = gate_and(n17, n2);
  auto n10 = gate_not(a[2]);
  auto n1 = gate_nand(b[0], n10);
  auto n3 = gate_nand(b[1], n10);
  y[1] = gate_and(n11, n3);
  auto n4 = gate_nand(y[1], b[0]);
  auto n7 = gate_nand(a[1], n4);
  auto n9 = gate_not(b[1]);
  auto n12 = gate_and(n17, n9);
  y[2] = gate_and(n12, n1);
  auto n14 = gate_not(n11);
  auto n13 = gate_not(n12);
  auto n15 = gate_and(n14, n13);
  auto n16 = gate_and(a[2], n15);
  auto n24 = gate_and(n17, n16);
  auto n22 = gate_xor(n17, n16);
  auto n18 = gate_not(a[0]);
  auto n20 = gate_and(b[0], n18);
  auto n6 = gate_nand(b[1], n20);
  auto n19 = gate_xor(b[1], n20);
  auto n5 = gate_nand(n19, n7);
  auto n21 = gate_and(n5, n6);
  auto n23 = gate_and(n22, n21);
  y[0] = gate_or(n24, n23);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[1]);
  auto n10 = gate_and(a[2], n8);
  auto n9 = gate_not(a[0]);
  auto n13 = gate_and(n10, n9);
  auto n30 = gate_not(b[2]);
  auto n21 = gate_xor(b[1], n30);
  auto n11 = gate_and(b[0], n21);
  auto n27 = gate_and(n13, n11);
  auto n34 = gate_xor(b[2], a[2]);
  auto n12 = gate_not(n11);
  auto n22 = gate_and(n13, n12);
  auto n6 = gate_nand(n21, n22);
  auto n16 = gate_xor(n21, n22);
  auto n14 = gate_and(a[2], a[0]);
  auto n17 = gate_xor(n14, a[1]);
  auto n15 = gate_mux(n30, n17, b[0]);
  auto n7 = gate_nand(n16, n15);
  auto n24 = gate_and(n7, n6);
  auto n4 = gate_xnor(n24, n34);
  auto n5 = gate_nand(n24, n22);
  auto n20 = gate_and(n24, n17);
  auto n1 = gate_nand(n21, n20);
  auto n19 = gate_xor(n21, n20);
  auto n18 = gate_mux(n30, a[0], b[0]);
  auto n2 = gate_nand(n19, n18);
  auto n23 = gate_and(n2, n1);
  auto n35 = gate_and(n23, n5);
  auto n28 = gate_and(n34, n35);
  auto n25 = gate_and(n28, n4);
  auto n26 = gate_xor(n34, n25);
  y[2] = gate_xor(n27, n26);
  y[1] = gate_xor(n28, n4);
  auto n29 = gate_not(b[0]);
  auto n32 = gate_and(n30, n29);
  auto n31 = gate_not(b[1]);
  auto n33 = gate_and(n32, n31);
  auto n3 = gate_nand(n34, n33);
  y[0] = gate_xor(n3, n35);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n12 = gate_xor(n9, b[0]);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_xor(n10, b[2]);
  auto n15 = gate_and(n12, n11);
  auto n13 = gate_not(a[1]);
  auto n14 = gate_xor(n13, b[1]);
  y[0] = gate_and(n15, n14);
}
template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[0]);
  auto n18 = gate_and(b[0], n17);
  auto n22 = gate_and(n18, b[1]);
  auto n20 = gate_xor(n18, b[1]);
  auto n19 = gate_not(a[1]);
  auto n21 = gate_and(n20, n19);
  auto n25 = gate_or(n22, n21);
  auto n16 = gate_nand(b[2], n25);
  auto n24 = gate_xor(b[2], n25);
  auto n23 = gate_not(a[2]);
  auto n15 = gate_nand(n24, n23);
  y[0] = gate_and(n15, n16);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[0]);
  auto n19 = gate_and(b[0], n16);
  auto n15 = gate_nand(b[1], n19);
  auto n18 = gate_xor(b[1], n19);
  auto n17 = gate_not(a[1]);
  auto n14 = gate_nand(n18, n17);
  auto n20 = gate_and(n14, n15);
  auto n24 = gate_and(b[2], n20);
  auto n22 = gate_xor(b[2], n20);
  auto n21 = gate_not(a[2]);
  auto n23 = gate_and(n22, n21);
  auto _gte_x_1_n22 = gate_or(n24, n23);
  y[0] = gate_buf(_gte_x_1_n22);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(b[0]);
  auto n24 = gate_and(a[0], n21);
  auto n19 = gate_nand(n24, a[1]);
  auto n23 = gate_xor(n24, a[1]);
  auto n22 = gate_not(b[1]);
  auto n20 = gate_nand(n23, n22);
  auto n27 = gate_and(n20, n19);
  auto n18 = gate_nand(n27, b[2]);
  auto n26 = gate_xor(n27, b[2]);
  auto n25 = gate_not(a[2]);
  auto n17 = gate_nand(n26, n25);
  y[0] = gate_and(n17, n18);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[0]);
  auto n23 = gate_and(a[0], n20);
  auto n18 = gate_nand(a[1], n23);
  auto n22 = gate_xor(a[1], n23);
  auto n21 = gate_not(b[1]);
  auto n19 = gate_nand(n22, n21);
  auto n26 = gate_and(n19, n18);
  auto n16 = gate_nand(a[2], n26);
  auto n25 = gate_xor(a[2], n26);
  auto n24 = gate_not(b[2]);
  auto n17 = gate_nand(n25, n24);
  auto _gt_x_1_n22 = gate_and(n17, n16);
  y[0] = gate_buf(_gt_x_1_n22);
}
template<> void $NameUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  auto n3 = gate_and(a[0], a[1]);
  y[2] = gate_xor(a[2], n3);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_xnor(b[2], a[2]);
  auto n11 = gate_xnor(b[1], a[1]);
  auto n12 = gate_not(a[0]);
  auto n13 = gate_xor(n12, b[0]);
  auto n14 = gate_and(n13, n11);
  y[0] = gate_nand(n14, n9);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  auto n9 = gate_and(n7, n6);
  auto n8 = gate_not(a[2]);
  auto n10 = gate_and(n9, n8);
  y[0] = gate_mux(b[0], c[0], n10);
  y[1] = gate_mux(b[1], c[1], n10);
  y[2] = gate_mux(b[2], c[2], n10);
}
template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(b[2]);
  auto n18 = gate_nand(a[2], n28);
  auto n27 = gate_xor(a[2], n28);
  auto n20 = gate_not(b[0]);
  auto n21 = gate_and(a[0], n20);
  auto n25 = gate_and(n21, a[1]);
  auto n23 = gate_xor(n21, a[1]);
  auto n22 = gate_not(b[1]);
  auto n24 = gate_and(n23, n22);
  auto n26 = gate_or(n25, n24);
  auto n19 = gate_nand(n27, n26);
  auto _lte_x_1_n8 = gate_and(n19, n18);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(b[0]);
  auto n22 = gate_and(a[0], n21);
  auto n26 = gate_and(n22, a[1]);
  auto n24 = gate_xor(n22, a[1]);
  auto n23 = gate_not(b[1]);
  auto n25 = gate_and(n24, n23);
  auto n29 = gate_or(n26, n25);
  auto n20 = gate_nand(b[2], n29);
  auto n28 = gate_xor(b[2], n29);
  auto n27 = gate_not(a[2]);
  auto n19 = gate_nand(n28, n27);
  y[0] = gate_and(n19, n20);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[0]);
  auto n15 = gate_not(a[1]);
  auto n18 = gate_and(n16, n15);
  auto n17 = gate_not(a[2]);
  auto n14 = gate_nand(n18, n17);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_not(b[1]);
  auto n22 = gate_and(n20, n19);
  auto n21 = gate_not(b[2]);
  auto n13 = gate_nand(n22, n21);
  y[0] = gate_and(n14, n13);
}
template<> void $NameUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  auto n9 = gate_and(n7, n6);
  auto n8 = gate_not(a[2]);
  y[0] = gate_and(n9, n8);
}
template<> void $NameUint<3>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(b[0]);
  auto n21 = gate_not(a[0]);
  auto n13 = gate_not(a[1]);
  auto n18 = gate_and(n14, n13);
  auto n16 = gate_not(a[2]);
  auto n15 = gate_not(b[2]);
  auto n17 = gate_and(n16, n15);
  auto n20 = gate_and(n18, n17);
  auto n19 = gate_not(b[1]);
  auto n22 = gate_and(n20, n19);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[0]);
  auto n23 = gate_and(b[0], n20);
  auto n17 = gate_nand(b[1], n23);
  auto n22 = gate_xor(b[1], n23);
  auto n21 = gate_not(a[1]);
  auto n16 = gate_nand(n22, n21);
  auto n26 = gate_and(n16, n17);
  auto n18 = gate_nand(a[2], n26);
  auto n25 = gate_xor(a[2], n26);
  auto n24 = gate_not(b[2]);
  auto n19 = gate_nand(n25, n24);
  auto _lt_x_1_n8 = gate_and(n19, n18);
  y[0] = gate_buf(_lt_x_1_n8);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(a[0]);
  auto n24 = gate_and(b[0], n21);
  auto n19 = gate_nand(b[1], n24);
  auto n23 = gate_xor(b[1], n24);
  auto n22 = gate_not(a[1]);
  auto n17 = gate_nand(n23, n22);
  auto n27 = gate_and(n17, n19);
  auto n20 = gate_nand(b[2], n27);
  auto n26 = gate_xor(b[2], n27);
  auto n25 = gate_not(a[2]);
  auto n18 = gate_nand(n26, n25);
  y[0] = gate_and(n18, n20);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_nand(a[2], b[0]);
  auto n31 = gate_not(b[2]);
  auto n17 = gate_not(b[1]);
  auto n10 = gate_and(n31, n17);
  auto n5 = gate_nand(b[0], n10);
  auto n15 = gate_and(a[2], n5);
  auto n23 = gate_not(a[2]);
  auto n3 = gate_nand(b[2], n23);
  auto n11 = gate_xor(n17, n23);
  auto n2 = gate_nand(n11, n7);
  auto n13 = gate_and(n31, n2);
  auto n12 = gate_not(a[1]);
  auto n1 = gate_nand(b[0], n12);
  auto n16 = gate_and(n13, n1);
  auto n4 = gate_nand(n16, b[0]);
  auto n14 = gate_not(n16);
  auto n34 = gate_and(n15, n14);
  auto n25 = gate_and(n34, n31);
  auto n27 = gate_and(a[1], n4);
  auto n22 = gate_and(n27, n17);
  auto n20 = gate_xor(n27, n17);
  auto n18 = gate_not(a[0]);
  auto n29 = gate_and(b[0], n18);
  auto n19 = gate_not(n29);
  auto n21 = gate_and(n20, n19);
  auto n32 = gate_or(n22, n21);
  auto n6 = gate_nand(n32, n31);
  auto n24 = gate_and(n32, n3);
  auto n33 = gate_or(n25, n24);
  auto n8 = gate_nand(n33, n6);
  y[2] = gate_and(n34, n8);
  auto n9 = gate_nand(n29, n33);
  auto n26 = gate_and(n33, b[0]);
  y[0] = gate_xor(n26, a[0]);
  auto n28 = gate_and(b[1], n33);
  auto n30 = gate_xor(n28, n27);
  y[1] = gate_and(n30, n9);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[0]);
  auto n8 = gate_and(a[2], n15);
  auto n12 = gate_not(a[1]);
  auto n9 = gate_and(n8, n12);
  auto n25 = gate_xor(b[1], b[2]);
  auto n14 = gate_not(n25);
  auto n5 = gate_nand(b[0], n14);
  auto n11 = gate_and(n9, n5);
  auto n10 = gate_or(b[0], n14);
  auto n19 = gate_and(n11, n10);
  auto n13 = gate_and(a[0], a[2]);
  auto n6 = gate_xnor(n13, n12);
  auto n26 = gate_and(n6, n5);
  auto n2 = gate_nand(n26, n14);
  auto n17 = gate_xor(n26, n14);
  auto n24 = gate_mux(b[2], n15, b[0]);
  auto n16 = gate_not(n24);
  auto n4 = gate_nand(n17, n16);
  auto n21 = gate_and(n2, n4);
  auto n18 = gate_not(n21);
  auto n7 = gate_nand(n19, n18);
  auto n32 = gate_and(a[2], n7);
  auto n20 = gate_not(n19);
  auto n1 = gate_nand(n21, n20);
  auto n3 = gate_nand(n1, n24);
  auto n23 = gate_and(b[0], n1);
  auto n22 = gate_xor(a[2], a[0]);
  auto n36 = gate_xor(n23, n22);
  y[0] = gate_xor(a[2], n36);
  auto n27 = gate_and(n1, n25);
  auto n28 = gate_xor(n27, n26);
  auto n34 = gate_and(n3, n28);
  auto n29 = gate_not(n34);
  auto n30 = gate_and(a[2], n29);
  auto n31 = gate_and(n36, n30);
  y[2] = gate_xor(n32, n31);
  auto n33 = gate_not(n36);
  auto n35 = gate_and(a[2], n33);
  y[1] = gate_xor(n35, n34);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
  auto n2 = gate_and(a[0], b[1]);
  auto n1 = gate_and(b[0], a[1]);
  y[1] = gate_xor(n2, n1);
  auto n8 = gate_and(a[1], b[1]);
  auto n6 = gate_and(b[2], a[0]);
  auto n3 = gate_and(n8, a[0]);
  auto n4 = gate_xor(a[2], n3);
  auto n5 = gate_and(b[0], n4);
  auto n7 = gate_xor(n6, n5);
  y[2] = gate_xor(n8, n7);
}
template<> void $NameUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  y[0] = gate_and(a[2], n2);
}
template<> void $NameUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_and(a[0], a[1]);
  y[0] = gate_nand(a[2], n5);
}
template<> void $NameUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  auto n9 = gate_and(n7, n6);
  auto n8 = gate_not(a[2]);
  y[0] = gate_and(n9, n8);
}
template<> void $NameUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n9 = gate_not(a[2]);
  auto n7 = gate_not(a[1]);
  auto n10 = gate_and(n8, n7);
  y[0] = gate_nand(n10, n9);
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
  auto n18 = gate_not(b[0]);
  auto n22 = gate_and(a[0], n18);
  auto n25 = gate_not(b[2]);
  auto n19 = gate_not(b[1]);
  auto n21 = gate_and(n25, n19);
  auto _ash_1_n11 = gate_and(n22, n21);
  y[0] = gate_buf(_ash_1_n11);
  auto n20 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n21, n20);
  auto n23 = gate_mux(a[2], a[1], b[0]);
  auto n24 = gate_mux(n23, n22, b[1]);
  y[2] = gate_and(n25, n24);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(b[2]);
  auto n11 = gate_mux(a[0], a[1], b[0]);
  auto n10 = gate_not(b[0]);
  auto n17 = gate_and(a[2], n10);
  auto n12 = gate_mux(n11, n17, b[1]);
  y[0] = gate_and(n14, n12);
  auto n13 = gate_not(b[1]);
  auto n16 = gate_and(n14, n13);
  auto n15 = gate_mux(a[1], a[2], b[0]);
  y[1] = gate_and(n16, n15);
  y[2] = gate_and(n17, n16);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n9 = gate_mux(a[0], a[1], b[0]);
  auto n8 = gate_not(b[1]);
  auto n7 = gate_not(b[2]);
  auto n11 = gate_and(n8, n7);
  y[0] = gate_mux(a[2], n9, n11);
  auto n10 = gate_not(b[0]);
  auto n12 = gate_and(n11, n10);
  y[1] = gate_mux(a[2], a[1], n12);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n17 = gate_not(b[1]);
  auto n13 = gate_nand(a[1], n17);
  auto n16 = gate_xor(a[1], n17);
  auto n15 = gate_not(a[0]);
  auto n12 = gate_nand(b[0], n15);
  auto n14 = gate_nand(n16, n12);
  y[1] = gate_xor(n16, n12);
  auto n19 = gate_and(n14, n13);
  auto n18 = gate_xor(b[2], a[2]);
  y[2] = gate_xor(n19, n18);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_or(a[1], a[0]);
  y[2] = gate_xor(a[2], n5);
}
