// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n7);
  auto n10 = gate_and(b[1], a[1]);
  auto n9 = gate_and(n8, n7);
  auto n11 = gate_or(n10, n9);
  auto n12 = gate_xor(b[2], n11);
  y[2] = gate_xor(a[2], n12);
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
  auto n12 = gate_not(a[0]);
  auto n9 = gate_and(c[0], n12);
  auto n8 = gate_and(a[0], b[0]);
  y[0] = gate_or(n9, n8);
  auto n11 = gate_and(c[1], n12);
  auto n10 = gate_and(a[0], b[1]);
  y[1] = gate_or(n11, n10);
  auto n14 = gate_and(c[2], n12);
  auto n13 = gate_and(a[0], b[2]);
  y[2] = gate_or(n14, n13);
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
  auto n12 = gate_not(b[2]);
  auto n15 = gate_not(b[0]);
  auto n4 = gate_or(a[1], n15);
  auto n8 = gate_and(n12, n4);
  auto n5 = gate_not(a[2]);
  auto n1 = gate_nand(b[0], n5);
  auto n2 = gate_nand(b[1], n5);
  y[1] = gate_and(n8, n2);
  auto n3 = gate_nand(y[1], b[0]);
  auto n14 = gate_not(b[1]);
  auto n6 = gate_and(n12, n14);
  y[2] = gate_and(n6, n1);
  auto n7 = gate_not(n6);
  auto n10 = gate_and(a[2], n7);
  auto n9 = gate_not(n8);
  auto n11 = gate_and(n10, n9);
  auto n23 = gate_and(n12, n11);
  auto n21 = gate_xor(n12, n11);
  auto n13 = gate_and(a[1], n3);
  auto n19 = gate_and(n14, n13);
  auto n17 = gate_xor(n14, n13);
  auto n16 = gate_or(a[0], n15);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  auto n22 = gate_and(n21, n20);
  y[0] = gate_or(n23, n22);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[0], b[0]);
  auto n9 = gate_not(a[1]);
  auto n5 = gate_and(a[2], n9);
  auto n4 = gate_not(a[0]);
  auto n18 = gate_and(n5, n4);
  auto n15 = gate_xor(b[1], b[2]);
  auto n6 = gate_not(n15);
  auto n16 = gate_and(n6, b[0]);
  auto n34 = gate_and(n18, n16);
  auto n40 = gate_xor(a[2], b[2]);
  auto n7 = gate_not(b[2]);
  auto n11 = gate_not(b[0]);
  auto n37 = gate_and(n7, n11);
  auto n13 = gate_not(n37);
  auto n8 = gate_and(n13, n1);
  auto n27 = gate_and(n15, n8);
  auto n25 = gate_xor(n15, n8);
  auto n10 = gate_and(a[2], a[0]);
  auto n23 = gate_xor(n10, n9);
  auto n12 = gate_or(n11, n23);
  auto n14 = gate_and(n13, n12);
  auto n22 = gate_and(n15, n14);
  auto n20 = gate_xor(n15, n14);
  auto n17 = gate_not(n16);
  auto n28 = gate_and(n18, n17);
  auto n19 = gate_not(n28);
  auto n21 = gate_and(n20, n19);
  auto n29 = gate_or(n22, n21);
  auto n3 = gate_nand(n29, n28);
  auto n31 = gate_not(n29);
  auto n24 = gate_or(n23, n31);
  auto n26 = gate_and(n25, n24);
  auto n30 = gate_or(n27, n26);
  auto n41 = gate_and(n30, n3);
  auto n36 = gate_and(n40, n41);
  auto n35 = gate_xor(n40, n31);
  auto n32 = gate_and(n36, n35);
  auto n33 = gate_xor(n40, n32);
  y[2] = gate_xor(n34, n33);
  y[1] = gate_xor(n36, n35);
  auto n38 = gate_not(b[1]);
  auto n39 = gate_and(n38, n37);
  auto n42 = gate_and(n40, n39);
  y[0] = gate_xnor(n42, n41);
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
  auto n16 = gate_not(a[0]);
  auto n15 = gate_nand(b[0], n16);
  auto n20 = gate_and(n15, a[1]);
  auto n18 = gate_xor(n15, a[1]);
  auto n17 = gate_not(b[1]);
  auto n19 = gate_and(n18, n17);
  auto n21 = gate_or(n20, n19);
  auto n25 = gate_and(a[2], n21);
  auto n23 = gate_xor(a[2], n21);
  auto n22 = gate_not(b[2]);
  auto n24 = gate_and(n23, n22);
  y[0] = gate_or(n25, n24);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[0]);
  auto n14 = gate_nand(b[0], n15);
  auto n19 = gate_and(n14, a[1]);
  auto n17 = gate_xor(n14, a[1]);
  auto n16 = gate_not(b[1]);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  auto n24 = gate_and(n20, b[2]);
  auto n22 = gate_xor(n20, b[2]);
  auto n21 = gate_not(a[2]);
  auto n23 = gate_and(n22, n21);
  auto _gte_x_1_n22 = gate_or(n24, n23);
  y[0] = gate_buf(_gte_x_1_n22);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(b[2]);
  auto n23 = gate_and(n13, a[2]);
  auto n21 = gate_xor(n13, a[2]);
  auto n14 = gate_not(b[0]);
  auto n15 = gate_and(a[0], n14);
  auto n19 = gate_and(n15, a[1]);
  auto n17 = gate_xor(n15, a[1]);
  auto n16 = gate_not(b[1]);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  auto n22 = gate_and(n21, n20);
  y[0] = gate_or(n23, n22);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(a[2]);
  auto n22 = gate_and(n12, b[2]);
  auto n20 = gate_xor(n12, b[2]);
  auto n13 = gate_not(b[0]);
  auto n14 = gate_and(a[0], n13);
  auto n18 = gate_and(n14, a[1]);
  auto n16 = gate_xor(n14, a[1]);
  auto n15 = gate_not(b[1]);
  auto n17 = gate_and(n16, n15);
  auto n19 = gate_or(n18, n17);
  auto n21 = gate_and(n20, n19);
  auto _gt_x_1_n22 = gate_or(n22, n21);
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
  auto n6 = gate_xor(b[0], a[0]);
  auto n5 = gate_xor(b[1], a[1]);
  auto n8 = gate_or(n6, n5);
  auto n7 = gate_xor(b[2], a[2]);
  auto _ne_x_1_n7 = gate_or(n8, n7);
  y[0] = gate_buf(_ne_x_1_n7);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n14 = gate_not(a[0]);
  auto n13 = gate_not(a[1]);
  auto n16 = gate_and(n14, n13);
  auto n15 = gate_not(a[2]);
  auto n22 = gate_and(n16, n15);
  auto n21 = gate_not(n22);
  auto n18 = gate_and(b[0], n21);
  auto n17 = gate_and(n22, c[0]);
  y[0] = gate_or(n18, n17);
  auto n20 = gate_and(b[1], n21);
  auto n19 = gate_and(n22, c[1]);
  y[1] = gate_or(n20, n19);
  auto n24 = gate_and(b[2], n21);
  auto n23 = gate_and(n22, c[2]);
  y[2] = gate_or(n24, n23);
}
template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[0]);
  auto n18 = gate_and(a[0], n15);
  auto n13 = gate_nand(a[1], n18);
  auto n17 = gate_xor(a[1], n18);
  auto n16 = gate_not(b[1]);
  auto n14 = gate_nand(n17, n16);
  auto n19 = gate_and(n14, n13);
  auto n23 = gate_and(n19, b[2]);
  auto n21 = gate_xor(n19, b[2]);
  auto n20 = gate_not(a[2]);
  auto n22 = gate_and(n21, n20);
  auto _lte_x_1_n8 = gate_or(n23, n22);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[0]);
  auto n19 = gate_and(a[0], n16);
  auto n14 = gate_nand(a[1], n19);
  auto n18 = gate_xor(a[1], n19);
  auto n17 = gate_not(b[1]);
  auto n15 = gate_nand(n18, n17);
  auto n20 = gate_and(n15, n14);
  auto n24 = gate_and(n20, a[2]);
  auto n22 = gate_xor(n20, a[2]);
  auto n21 = gate_not(b[2]);
  auto n23 = gate_and(n22, n21);
  y[0] = gate_or(n24, n23);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_or(a[1], a[0]);
  auto n8 = gate_or(a[2], n5);
  auto n6 = gate_or(b[1], b[0]);
  auto n7 = gate_or(b[2], n6);
  y[0] = gate_and(n8, n7);
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
  auto n6 = gate_or(b[0], a[1]);
  auto n5 = gate_or(a[2], b[2]);
  auto n7 = gate_or(n6, n5);
  auto n8 = gate_or(b[1], n7);
  y[0] = gate_or(a[0], n8);
}
template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(a[2]);
  auto n22 = gate_and(n12, b[2]);
  auto n20 = gate_xor(n12, b[2]);
  auto n13 = gate_not(a[0]);
  auto n14 = gate_and(b[0], n13);
  auto n18 = gate_and(n14, b[1]);
  auto n16 = gate_xor(n14, b[1]);
  auto n15 = gate_not(a[1]);
  auto n17 = gate_and(n16, n15);
  auto n19 = gate_or(n18, n17);
  auto n21 = gate_and(n20, n19);
  auto _lt_x_1_n8 = gate_or(n22, n21);
  y[0] = gate_buf(_lt_x_1_n8);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(b[2]);
  auto n23 = gate_and(n13, a[2]);
  auto n21 = gate_xor(n13, a[2]);
  auto n14 = gate_not(a[0]);
  auto n15 = gate_and(b[0], n14);
  auto n19 = gate_and(n15, b[1]);
  auto n17 = gate_xor(n15, b[1]);
  auto n16 = gate_not(a[1]);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  auto n22 = gate_and(n21, n20);
  y[0] = gate_or(n23, n22);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[2]);
  auto n11 = gate_not(b[1]);
  auto n6 = gate_xor(n11, a[2]);
  auto n8 = gate_and(n30, n6);
  auto n7 = gate_and(n30, n11);
  auto n18 = gate_and(b[0], n7);
  auto n10 = gate_or(n8, n18);
  auto n9 = gate_not(a[1]);
  auto n2 = gate_nand(n9, b[0]);
  auto n20 = gate_and(n10, n2);
  auto n5 = gate_nand(n20, b[0]);
  auto n26 = gate_and(a[1], n5);
  auto n16 = gate_and(n26, n11);
  auto n14 = gate_xor(n26, n11);
  auto n12 = gate_not(a[0]);
  auto n28 = gate_and(n12, b[0]);
  auto n13 = gate_not(n28);
  auto n15 = gate_and(n14, n13);
  auto n31 = gate_or(n16, n15);
  auto n1 = gate_nand(n31, n30);
  auto n17 = gate_or(n30, a[2]);
  auto n24 = gate_and(n31, n17);
  auto n19 = gate_not(n18);
  auto n22 = gate_and(a[2], n19);
  auto n21 = gate_not(n20);
  auto n33 = gate_and(n22, n21);
  auto n23 = gate_and(n33, n30);
  auto n32 = gate_or(n24, n23);
  auto n3 = gate_nand(n32, n1);
  y[2] = gate_and(n33, n3);
  auto n4 = gate_nand(n32, n28);
  auto n25 = gate_and(n32, b[0]);
  y[0] = gate_xor(n25, a[0]);
  auto n27 = gate_and(n32, b[1]);
  auto n29 = gate_xor(n27, n26);
  y[1] = gate_and(n29, n4);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_xor(b[2], b[1]);
  auto n7 = gate_xor(n24, b[0]);
  auto n6 = gate_not(a[1]);
  auto n13 = gate_not(a[0]);
  auto n5 = gate_and(n13, a[2]);
  auto n4 = gate_nand(n6, n5);
  auto n20 = gate_or(n7, n4);
  auto n8 = gate_and(a[0], a[2]);
  auto n10 = gate_xor(n8, a[1]);
  auto n12 = gate_not(b[0]);
  auto n9 = gate_or(n12, n24);
  auto n25 = gate_and(n10, n9);
  auto n11 = gate_not(n24);
  auto n3 = gate_nand(n25, n11);
  auto n16 = gate_xor(n24, n25);
  auto n15 = gate_and(b[2], n12);
  auto n14 = gate_and(b[0], n13);
  auto n23 = gate_or(n15, n14);
  auto n17 = gate_or(n16, n23);
  auto n19 = gate_and(n3, n17);
  auto n1 = gate_nand(n20, n19);
  auto n2 = gate_nand(n1, n23);
  auto n18 = gate_or(n20, n19);
  auto n31 = gate_and(a[2], n18);
  auto n22 = gate_and(b[0], n1);
  auto n21 = gate_xor(a[2], a[0]);
  auto n35 = gate_xor(n22, n21);
  y[0] = gate_xor(a[2], n35);
  auto n26 = gate_and(n1, n24);
  auto n27 = gate_xor(n26, n25);
  auto n33 = gate_and(n2, n27);
  auto n28 = gate_not(n33);
  auto n29 = gate_and(a[2], n28);
  auto n30 = gate_and(n35, n29);
  y[2] = gate_xor(n31, n30);
  auto n32 = gate_not(n35);
  auto n34 = gate_and(a[2], n32);
  y[1] = gate_xor(n34, n33);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
  auto n2 = gate_and(a[0], b[1]);
  auto n1 = gate_and(b[0], a[1]);
  y[1] = gate_xor(n2, n1);
  auto n8 = gate_and(b[2], a[0]);
  auto n5 = gate_and(a[1], b[1]);
  auto n3 = gate_and(n5, a[0]);
  auto n4 = gate_xor(a[2], n3);
  auto n6 = gate_and(b[0], n4);
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
  auto n2 = gate_or(a[1], a[0]);
  y[0] = gate_or(a[2], n2);
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
  auto n26 = gate_not(b[0]);
  auto n31 = gate_and(a[0], n26);
  auto n34 = gate_not(b[2]);
  auto n29 = gate_not(b[1]);
  auto n25 = gate_and(n34, n29);
  auto _ash_1_n11 = gate_and(n31, n25);
  y[0] = gate_buf(_ash_1_n11);
  auto n23 = gate_and(a[1], n26);
  auto n22 = gate_and(b[0], a[0]);
  auto n24 = gate_or(n23, n22);
  y[1] = gate_and(n25, n24);
  auto n28 = gate_and(a[2], n26);
  auto n27 = gate_and(b[0], a[1]);
  auto n30 = gate_or(n28, n27);
  auto n33 = gate_and(n30, n29);
  auto n32 = gate_and(b[1], n31);
  auto n35 = gate_or(n33, n32);
  y[2] = gate_and(n35, n34);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[0]);
  auto n17 = gate_and(a[0], n24);
  auto n16 = gate_and(b[0], a[1]);
  auto n18 = gate_or(n17, n16);
  auto n22 = gate_not(b[1]);
  auto n20 = gate_and(n18, n22);
  auto n29 = gate_and(a[2], n24);
  auto n19 = gate_and(b[1], n29);
  auto n21 = gate_or(n20, n19);
  auto n23 = gate_not(b[2]);
  y[0] = gate_and(n21, n23);
  auto n28 = gate_and(n23, n22);
  auto n26 = gate_and(a[1], n24);
  auto n25 = gate_and(b[0], a[2]);
  auto n27 = gate_or(n26, n25);
  y[1] = gate_and(n28, n27);
  y[2] = gate_and(n29, n28);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n10 = gate_or(b[2], b[1]);
  auto n15 = gate_and(a[2], n10);
  auto n17 = gate_not(n10);
  auto n16 = gate_not(b[0]);
  auto n12 = gate_and(a[0], n16);
  auto n11 = gate_and(b[0], a[1]);
  auto n13 = gate_or(n12, n11);
  auto n14 = gate_and(n17, n13);
  y[0] = gate_or(n15, n14);
  auto n19 = gate_and(n17, n16);
  auto n18 = gate_not(n19);
  auto n21 = gate_and(a[2], n18);
  auto n20 = gate_and(n19, a[1]);
  y[1] = gate_or(n21, n20);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n11 = gate_not(a[0]);
  auto n13 = gate_and(b[0], n11);
  auto n12 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n13, n12);
  auto n15 = gate_or(n13, n12);
  auto n14 = gate_not(b[1]);
  auto n10 = gate_nand(a[1], n14);
  auto n17 = gate_and(n15, n10);
  auto n16 = gate_xor(b[2], a[2]);
  y[2] = gate_xor(n17, n16);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n2 = gate_or(a[1], a[0]);
  y[2] = gate_xor(a[2], n2);
}
