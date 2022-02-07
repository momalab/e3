// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n9);
  auto n11 = gate_nand(n8, n9);
  auto n10 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n13 = gate_xor(b[2], n12);
  y[2] = gate_xor(a[2], n13);
}
template<> void $NameUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_and(b[2], a[2]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
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
template<> void $NameUint<3>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[2] = gate_buf(zero);
  auto n6 = gate_nand(a[1], N0);
  auto n7 = gate_xor(a[1], N0);
  auto n5 = gate_nand(n7, a[2]);
  y[1] = gate_nand(n6, n5);
  auto _add_x_2_n9 = gate_xor(n7, a[2]);
  y[0] = gate_buf(_add_x_2_n9);
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
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void $NameUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
}
template<> void $NameUint<3>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_and(b[0], a[0]);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n7, n6);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
  auto n9 = gate_nand(b[1], a[1]);
  auto n8 = gate_nand(n7, n6);
  auto _add_x_1_n11 = gate_nand(n9, n8);
  y[2] = gate_buf(_add_x_1_n11);
}
template<> void $NameUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n5 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n5);
  auto n7 = gate_not(a[2]);
  auto n6 = gate_nand(y[0], n5);
  y[2] = gate_xor(n7, n6);
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
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_xor(a[2], b[2]);
  auto n9 = gate_not(a[1]);
  auto n18 = gate_not(a[0]);
  auto n4 = gate_and(n9, n18);
  auto n6 = gate_nand(a[2], n4);
  auto n35 = gate_not(n6);
  auto n27 = gate_not(b[2]);
  auto n7 = gate_xor(b[1], n27);
  auto n34 = gate_nand(n7, b[0]);
  auto n3 = gate_and(n35, n34);
  auto n17 = gate_not(n7);
  auto n14 = gate_nand(n17, n6);
  auto n12 = gate_nand(n7, n3);
  auto n8 = gate_nand(a[0], a[2]);
  auto n15 = gate_xor(n9, n8);
  auto n10 = gate_mux(n27, n15, b[0]);
  auto n11 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n25 = gate_nand(n14, n13);
  auto n24 = gate_nand(n3, n25);
  auto n16 = gate_nand(n15, n25);
  auto n22 = gate_nand(n17, n16);
  auto n20 = gate_xor(n17, n16);
  auto n19 = gate_mux(b[2], n18, b[0]);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n5 = gate_and(n24, n23);
  auto n30 = gate_nand(n40, n5);
  auto n31 = gate_xor(n25, n40);
  y[1] = gate_xor(n30, n31);
  auto n26 = gate_not(b[0]);
  auto n2 = gate_and(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n1 = gate_and(n2, n28);
  auto n29 = gate_nand(n1, n40);
  y[0] = gate_xor(n5, n29);
  auto n33 = gate_not(n30);
  auto n32 = gate_not(n31);
  auto n38 = gate_nand(n33, n32);
  auto n36 = gate_not(n34);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_xor(n38, n37);
  y[2] = gate_xor(n40, n39);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(b[2], a[2]);
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
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_not(b[1]);
  auto n17 = gate_nand(n12, a[1]);
  auto n15 = gate_xor(n12, a[1]);
  auto n13 = gate_not(a[0]);
  auto n14 = gate_nand(b[0], n13);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n22 = gate_nand(n18, b[2]);
  auto n20 = gate_xor(n18, b[2]);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_nand(n20, n19);
  auto _gte_x_1_n22 = gate_nand(n22, n21);
  y[0] = gate_buf(_gte_x_1_n22);
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
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[2]);
  auto n26 = gate_nand(n16, a[2]);
  auto n24 = gate_xor(n16, a[2]);
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  y[0] = gate_and(n26, n25);
}
template<> void $NameUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  auto n5 = gate_not(a[2]);
  auto n4 = gate_nand(a[0], a[1]);
  y[2] = gate_xor(n5, n4);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_xnor(b[2], a[2]);
  auto n11 = gate_xnor(a[0], b[0]);
  auto n10 = gate_and(n9, n11);
  auto n12 = gate_xnor(a[1], b[1]);
  auto _ne_x_1_n7 = gate_nand(n10, n12);
  y[0] = gate_buf(_ne_x_1_n7);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_and(n9, n8);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(n7, n10);
  y[2] = gate_mux(c[2], b[2], n11);
  y[0] = gate_mux(c[0], b[0], n11);
  y[1] = gate_mux(c[1], b[1], n11);
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
  auto _lte_x_1_n8 = gate_nand(n26, n25);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[1]);
  auto n22 = gate_nand(n17, b[1]);
  auto n20 = gate_xor(n17, b[1]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n27 = gate_nand(n23, a[2]);
  auto n25 = gate_xor(n23, a[2]);
  auto n24 = gate_not(b[2]);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_nand(n27, n26);
}
template<> void $NameUint<3>::d_logand
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
template<> void $NameUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
  y[0] = gate_and(n8, n12);
}
template<> void $NameUint<3>::d_logor
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
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[1]);
  auto n20 = gate_nand(n15, a[1]);
  auto n18 = gate_xor(n15, a[1]);
  auto n16 = gate_not(a[0]);
  auto n17 = gate_nand(b[0], n16);
  auto n19 = gate_nand(n18, n17);
  auto n21 = gate_nand(n20, n19);
  auto n25 = gate_nand(n21, b[2]);
  auto n23 = gate_xor(n21, b[2]);
  auto n22 = gate_not(a[2]);
  auto n24 = gate_nand(n23, n22);
  y[0] = gate_and(n25, n24);
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
  auto n6 = gate_mux(b[0], a[2], b[1]);
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
  auto n25 = gate_mux(n24, n23, n26);
  y[1] = gate_not(n25);
  auto n27 = gate_not(n26);
  auto n32 = gate_nand(n2, n27);
  auto n30 = gate_not(n28);
  auto n31 = gate_nand(n30, n29);
  y[2] = gate_nand(n32, n31);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_xnor(b[2], b[1]);
  auto n6 = gate_nand(a[0], a[2]);
  auto n4 = gate_xnor(a[1], n6);
  auto n7 = gate_nand(n5, b[0]);
  auto n22 = gate_nand(n4, n7);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_mux(n8, a[0], b[0]);
  auto n10 = gate_xor(n22, n5);
  auto n21 = gate_nand(n11, n10);
  auto n9 = gate_not(n22);
  auto n14 = gate_nand(n9, n5);
  auto n12 = gate_not(n10);
  auto n13 = gate_nand(n12, n11);
  auto n31 = gate_nand(n14, n13);
  auto n20 = gate_not(n31);
  auto n15 = gate_not(a[0]);
  auto n3 = gate_and(a[2], n15);
  auto n16 = gate_not(a[1]);
  auto n2 = gate_and(n3, n16);
  auto n17 = gate_not(b[0]);
  auto n18 = gate_mux(n17, b[0], n5);
  auto n19 = gate_not(n18);
  auto n30 = gate_nand(n2, n19);
  auto n23 = gate_nand(n20, n30);
  auto n28 = gate_mux(n22, n21, n23);
  auto n25 = gate_xor(a[2], a[0]);
  auto n24 = gate_nand(b[0], n23);
  auto n27 = gate_xor(n25, n24);
  auto n26 = gate_nand(n27, a[2]);
  y[1] = gate_xor(n28, n26);
  auto n29 = gate_not(n27);
  auto n1 = gate_and(a[2], n29);
  y[0] = gate_xor(a[2], n29);
  auto n35 = gate_nand(n28, n1);
  auto n32 = gate_not(n30);
  auto n33 = gate_nand(n32, n31);
  auto n34 = gate_nand(a[2], n33);
  y[2] = gate_xor(n35, n34);
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
  auto n12 = gate_not(a[2]);
  auto n10 = gate_not(a[1]);
  auto n8 = gate_and(n11, n10);
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
  auto n29 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n23, n29);
  auto n30 = gate_mux(a[2], a[1], b[0]);
  auto n31 = gate_mux(n30, n25, b[1]);
  y[2] = gate_and(n32, n31);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[2]);
  auto n25 = gate_mux(a[1], a[2], b[0]);
  auto n21 = gate_mux(a[0], a[1], b[0]);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_and(a[2], n20);
  auto n22 = gate_mux(n21, n19, b[1]);
  y[0] = gate_and(n24, n22);
  auto n23 = gate_not(b[1]);
  auto n15 = gate_and(n24, n23);
  y[2] = gate_and(n19, n15);
  y[1] = gate_and(n15, n25);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n10 = gate_mux(a[0], a[1], b[0]);
  auto n9 = gate_not(b[1]);
  auto n8 = gate_not(b[2]);
  auto n11 = gate_nand(n9, n8);
  y[0] = gate_mux(n10, a[2], n11);
  auto n13 = gate_not(n11);
  auto n12 = gate_not(b[0]);
  auto n14 = gate_nand(n13, n12);
  y[1] = gate_mux(a[1], a[2], n14);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n17 = gate_xor(b[2], a[2]);
  auto n12 = gate_not(b[1]);
  auto n14 = gate_xor(a[1], n12);
  auto n11 = gate_not(a[0]);
  auto n13 = gate_nand(b[0], n11);
  y[1] = gate_xor(n14, n13);
  auto n16 = gate_nand(a[1], n12);
  auto n15 = gate_nand(n14, n13);
  auto n18 = gate_nand(n16, n15);
  y[2] = gate_xnor(n18, n17);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_not(a[1]);
  auto n4 = gate_not(a[0]);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(a[2], n6);
}
