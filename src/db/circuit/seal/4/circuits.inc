// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xor(b[1], a[1]);
  auto n12 = gate_and(b[0], a[0]);
  y[1] = gate_xor(n11, n12);
  auto n14 = gate_and(b[1], a[1]);
  auto n13 = gate_and(n12, n11);
  auto n16 = gate_nor(n14, n13);
  auto n15 = gate_xnor(b[2], a[2]);
  y[2] = gate_xor(n16, n15);
  auto n20 = gate_xnor(a[3], b[3]);
  auto n18 = gate_and(b[2], a[2]);
  auto n17 = gate_nor(n16, n15);
  auto n19 = gate_nor(n18, n17);
  y[3] = gate_xor(n20, n19);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
}
template<> void $NameUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(b[3], a[3]);
  y[2] = gate_and(b[2], a[2]);
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<4>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<4>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_or(a[3], b[3]);
  y[0] = gate_or(a[0], b[0]);
  y[1] = gate_or(a[1], b[1]);
  y[2] = gate_or(a[2], b[2]);
}
template<> void $NameUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n12 = gate_and(a[3], N0);
  auto n13 = gate_and(a[1], a[2]);
  y[2] = gate_and(n12, n13);
  auto n17 = gate_xor(a[3], N0);
  auto n16 = gate_xnor(a[1], a[2]);
  auto n10 = gate_not(n16);
  auto n11 = gate_and(n17, n10);
  auto n14 = gate_nor(n13, n11);
  auto n15 = gate_mux(n14, n13, n12);
  y[1] = gate_not(n15);
  y[0] = gate_xnor(n17, n16);
}
template<> void $NameUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  y[1] = gate_and(a[0], b[1]);
  y[2] = gate_and(a[0], b[2]);
  y[3] = gate_and(a[0], b[3]);
}
template<> void $NameUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
}
template<> void $NameUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_xor(b[1], a[1]);
  auto n11 = gate_and(b[0], a[0]);
  y[1] = gate_xor(n12, n11);
  auto n14 = gate_and(b[1], a[1]);
  auto n13 = gate_and(n12, n11);
  auto n15 = gate_nor(n14, n13);
  auto n17 = gate_xor(b[2], a[2]);
  y[2] = gate_xnor(n15, n17);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  auto n19 = gate_and(b[2], a[2]);
  auto n16 = gate_not(n15);
  auto n18 = gate_and(n17, n16);
  y[0] = gate_buf(_add_x_1_n12);
  y[3] = gate_or(n19, n18);
}
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xnor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  auto n6 = gate_nor(a[0], a[1]);
  auto n5 = gate_not(a[2]);
  auto n4 = gate_and(n6, n5);
  y[3] = gate_xor(a[3], n4);
  y[2] = gate_xnor(n6, n5);
}
template<> void $NameUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nor(b[3], b[2]);
  auto n4 = gate_not(a[3]);
  auto n2 = gate_and(b[0], n4);
  auto n3 = gate_nor(n2, b[1]);
  y[3] = gate_and(n8, n3);
  auto n6 = gate_and(b[1], n4);
  auto n11 = gate_not(a[2]);
  auto n5 = gate_and(b[0], n11);
  auto n7 = gate_nor(n6, n5);
  y[2] = gate_and(n8, n7);
  auto n42 = gate_not(b[3]);
  auto n9 = gate_nor(y[2], y[3]);
  auto n38 = gate_and(a[3], n9);
  auto n10 = gate_and(y[2], b[0]);
  auto n23 = gate_nor(n11, n10);
  auto n12 = gate_not(b[1]);
  auto n14 = gate_and(n23, n12);
  auto n22 = gate_xnor(n12, n23);
  auto n26 = gate_not(b[0]);
  auto n20 = gate_nor(n26, a[1]);
  auto n13 = gate_nor(n22, n20);
  auto n16 = gate_nor(n14, n13);
  auto n15 = gate_nor(b[2], n16);
  auto n18 = gate_nor(n38, n15);
  auto n17 = gate_and(b[2], n16);
  auto n19 = gate_nor(n18, n17);
  y[1] = gate_and(n42, n19);
  auto n21 = gate_not(n20);
  auto n24 = gate_and(n22, n21);
  auto n37 = gate_not(y[1]);
  auto n25 = gate_mux(n24, n23, n37);
  auto n33 = gate_not(n25);
  auto n36 = gate_and(n33, b[2]);
  auto n29 = gate_nor(a[0], n26);
  auto n27 = gate_and(b[0], y[1]);
  auto n28 = gate_xnor(n27, a[1]);
  auto n32 = gate_nor(n29, n28);
  auto n30 = gate_and(n29, n28);
  auto n31 = gate_nor(b[1], n30);
  auto n34 = gate_nor(n32, n31);
  auto n39 = gate_and(n38, n37);
  auto n1 = gate_or(n33, b[2]);
  auto n35 = gate_and(n34, n1);
  auto n40 = gate_nor(n36, n35);
  auto n44 = gate_nor(n40, n39);
  auto n41 = gate_and(n40, n39);
  auto n43 = gate_nor(n42, n41);
  y[0] = gate_nor(n44, n43);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_or(a[1], a[0]);
  auto n33 = gate_not(b[3]);
  auto n55 = gate_xnor(a[3], n33);
  auto n3 = gate_nor(n1, a[2]);
  auto n23 = gate_and(a[3], n3);
  auto n16 = gate_xnor(b[3], b[1]);
  auto n5 = gate_and(n23, n16);
  auto n30 = gate_xnor(b[3], b[2]);
  auto n4 = gate_and(n30, b[0]);
  auto n6 = gate_and(n5, n4);
  auto n50 = gate_xnor(n55, n6);
  auto n7 = gate_not(n6);
  auto n14 = gate_and(n23, n7);
  auto n8 = gate_and(n1, a[3]);
  auto n17 = gate_xnor(n8, a[2]);
  auto n9 = gate_mux(b[3], n17, b[0]);
  auto n10 = gate_nor(n16, n23);
  auto n15 = gate_and(a[0], a[3]);
  auto n32 = gate_xnor(n15, a[1]);
  auto n18 = gate_mux(b[3], n32, b[0]);
  auto n57 = gate_not(n16);
  auto n21 = gate_and(n18, n57);
  auto n19 = gate_nor(n18, n57);
  auto n42 = gate_not(n30);
  auto n34 = gate_mux(n33, a[0], b[0]);
  auto n61 = gate_not(n55);
  auto n59 = gate_nor(b[3], b[0]);
  auto n58 = gate_nor(b[2], n57);
  auto n60 = gate_and(n59, n58);
  auto n62 = gate_nor(n61, n60);
  auto n2 = gate_nand(n14, n16);
  auto n11 = gate_and(n9, n2);
  auto n12 = gate_nor(n11, n10);
  auto n48 = gate_and(n30, n12);
  auto n13 = gate_not(n48);
  auto n27 = gate_and(n14, n13);
  auto n29 = gate_nor(n17, n48);
  auto n20 = gate_nor(n29, n19);
  auto n22 = gate_nor(n21, n20);
  auto n26 = gate_nor(n22, n27);
  auto n24 = gate_and(n23, n22);
  auto n25 = gate_nor(n30, n24);
  auto n47 = gate_nor(n26, n25);
  auto n28 = gate_not(n47);
  auto n46 = gate_and(n27, n28);
  auto n40 = gate_and(n29, n28);
  auto n31 = gate_and(b[0], n47);
  auto n35 = gate_nor(n32, n31);
  auto n38 = gate_and(n35, n34);
  auto n36 = gate_nor(n35, n34);
  auto n37 = gate_nor(n57, n36);
  auto n41 = gate_nor(n38, n37);
  auto n39 = gate_nor(n42, n41);
  auto n44 = gate_nor(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_nor(n44, n43);
  auto n54 = gate_nor(n46, n45);
  auto n56 = gate_and(n55, n54);
  auto n53 = gate_xnor(n61, n47);
  auto n51 = gate_and(n56, n53);
  auto n52 = gate_xnor(n48, n61);
  auto n49 = gate_and(n51, n52);
  y[3] = gate_xnor(n50, n49);
  y[2] = gate_xor(n52, n51);
  y[1] = gate_xor(n56, n53);
  auto n64 = gate_xnor(n55, n54);
  auto n63 = gate_not(n56);
  y[0] = gate_mux(n64, n63, n62);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_xnor(b[2], a[2]);
  auto n7 = gate_xnor(b[0], a[0]);
  auto n12 = gate_and(n8, n7);
  auto n10 = gate_xnor(a[3], b[3]);
  auto n9 = gate_xnor(b[1], a[1]);
  auto n11 = gate_and(n10, n9);
  auto _eq_x_1_n30 = gate_and(n12, n11);
  y[0] = gate_buf(_eq_x_1_n30);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[1]);
  auto n18 = gate_and(b[1], n14);
  auto n15 = gate_nor(b[1], n14);
  auto n16 = gate_nor(n15, a[0]);
  auto n17 = gate_and(b[0], n16);
  auto n19 = gate_nor(n18, n17);
  auto n22 = gate_and(a[2], n19);
  auto n20 = gate_nor(a[2], n19);
  auto n21 = gate_nor(b[2], n20);
  auto n23 = gate_nor(n22, n21);
  auto n26 = gate_and(b[3], n23);
  auto n24 = gate_nor(b[3], n23);
  auto n25 = gate_nor(a[3], n24);
  auto _gte_x_1_n29 = gate_nor(n26, n25);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[1]);
  auto n18 = gate_and(b[1], n14);
  auto n15 = gate_nor(b[1], n14);
  auto n16 = gate_nor(n15, a[0]);
  auto n17 = gate_and(b[0], n16);
  auto n19 = gate_nor(n18, n17);
  auto n22 = gate_and(a[2], n19);
  auto n20 = gate_nor(a[2], n19);
  auto n21 = gate_nor(b[2], n20);
  auto n23 = gate_nor(n22, n21);
  auto n26 = gate_and(a[3], n23);
  auto n24 = gate_nor(a[3], n23);
  auto n25 = gate_nor(b[3], n24);
  auto _gte_x_1_n29 = gate_nor(n26, n25);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[1]);
  auto n20 = gate_nor(n22, a[1]);
  auto n21 = gate_nor(n20, b[0]);
  auto n24 = gate_and(a[0], n21);
  auto n23 = gate_and(a[1], n22);
  auto n25 = gate_nor(n24, n23);
  auto n28 = gate_and(n25, b[2]);
  auto n26 = gate_nor(n25, b[2]);
  auto n27 = gate_nor(a[2], n26);
  auto n19 = gate_or(n28, n27);
  auto n31 = gate_and(n19, b[3]);
  auto n29 = gate_nor(n19, b[3]);
  auto n30 = gate_nor(a[3], n29);
  auto _gt_x_1_n29 = gate_nor(n31, n30);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[1]);
  auto n20 = gate_nor(n22, a[1]);
  auto n21 = gate_nor(n20, b[0]);
  auto n24 = gate_and(a[0], n21);
  auto n23 = gate_and(a[1], n22);
  auto n25 = gate_nor(n24, n23);
  auto n28 = gate_and(n25, b[2]);
  auto n26 = gate_nor(n25, b[2]);
  auto n27 = gate_nor(a[2], n26);
  auto n19 = gate_or(n28, n27);
  auto n31 = gate_and(n19, a[3]);
  auto n29 = gate_nor(n19, a[3]);
  auto n30 = gate_nor(b[3], n29);
  auto _gt_x_1_n29 = gate_nor(n31, n30);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xnor(a[1], y[0]);
  auto n4 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n4, a[2]);
  y[3] = gate_xor(a[3], n3);
  y[2] = gate_xor(a[2], n4);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(b[0], a[0]);
  auto n10 = gate_xnor(b[1], a[1]);
  auto n13 = gate_and(n11, n10);
  auto n12 = gate_xnor(b[2], a[2]);
  auto n15 = gate_and(n13, n12);
  auto n14 = gate_xnor(b[3], a[3]);
  y[0] = gate_nand(n15, n14);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n5 = gate_nor(a[1], a[0]);
  auto n4 = gate_nor(a[3], a[2]);
  auto n6 = gate_and(n5, n4);
  y[0] = gate_mux(b[0], c[0], n6);
  y[1] = gate_mux(b[1], c[1], n6);
  y[2] = gate_mux(b[2], c[2], n6);
  y[3] = gate_mux(b[3], c[3], n6);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(b[1]);
  auto n21 = gate_nor(n23, a[1]);
  auto n22 = gate_nor(n21, b[0]);
  auto n25 = gate_and(a[0], n22);
  auto n24 = gate_and(a[1], n23);
  auto n26 = gate_nor(n25, n24);
  auto n29 = gate_and(n26, b[2]);
  auto n27 = gate_nor(n26, b[2]);
  auto n28 = gate_nor(a[2], n27);
  auto n19 = gate_or(n29, n28);
  auto n20 = gate_nand(n19, b[3]);
  auto n31 = gate_nor(n19, b[3]);
  auto n30 = gate_and(a[3], n20);
  y[0] = gate_nor(n31, n30);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(b[1]);
  auto n21 = gate_nor(n23, a[1]);
  auto n22 = gate_nor(n21, b[0]);
  auto n25 = gate_and(a[0], n22);
  auto n24 = gate_and(a[1], n23);
  auto n26 = gate_nor(n25, n24);
  auto n29 = gate_and(n26, b[2]);
  auto n27 = gate_nor(n26, b[2]);
  auto n28 = gate_nor(a[2], n27);
  auto n20 = gate_or(n29, n28);
  auto n31 = gate_nor(n20, a[3]);
  auto n19 = gate_nand(n20, a[3]);
  auto n30 = gate_and(b[3], n19);
  y[0] = gate_nor(n31, n30);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nor(a[1], a[0]);
  auto n7 = gate_nor(a[3], a[2]);
  auto n12 = gate_and(n8, n7);
  auto n10 = gate_nor(b[1], b[0]);
  auto n9 = gate_nor(b[3], b[2]);
  auto n11 = gate_and(n10, n9);
  y[0] = gate_nor(n12, n11);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_nor(a[1], a[0]);
  auto n4 = gate_nor(a[3], a[2]);
  y[0] = gate_and(n5, n4);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_nor(a[1], a[0]);
  auto n10 = gate_nor(a[3], a[2]);
  auto n9 = gate_nor(b[1], b[0]);
  auto n12 = gate_and(n10, n9);
  auto n11 = gate_nor(b[3], b[2]);
  auto n13 = gate_and(n12, n11);
  y[0] = gate_nand(n14, n13);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n20 = gate_and(b[1], n16);
  auto n17 = gate_nor(b[1], n16);
  auto n18 = gate_nor(n17, a[0]);
  auto n19 = gate_and(b[0], n18);
  auto n22 = gate_nor(n20, n19);
  auto n23 = gate_not(a[2]);
  auto n21 = gate_nor(n23, b[2]);
  auto n25 = gate_nor(n22, n21);
  auto n24 = gate_and(b[2], n23);
  auto n26 = gate_nor(n25, n24);
  auto n29 = gate_and(n26, a[3]);
  auto n27 = gate_nor(n26, a[3]);
  auto n28 = gate_nor(b[3], n27);
  y[0] = gate_nor(n29, n28);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n20 = gate_and(b[1], n16);
  auto n17 = gate_nor(b[1], n16);
  auto n18 = gate_nor(n17, a[0]);
  auto n19 = gate_and(b[0], n18);
  auto n22 = gate_nor(n20, n19);
  auto n23 = gate_not(a[2]);
  auto n21 = gate_nor(n23, b[2]);
  auto n25 = gate_nor(n22, n21);
  auto n24 = gate_and(b[2], n23);
  auto n26 = gate_nor(n25, n24);
  auto n29 = gate_and(n26, b[3]);
  auto n27 = gate_nor(n26, b[3]);
  auto n28 = gate_nor(a[3], n27);
  y[0] = gate_nor(n29, n28);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[2]);
  auto n42 = gate_not(b[3]);
  auto n18 = gate_and(n42, n27);
  auto n28 = gate_not(b[0]);
  auto n7 = gate_mux(b[0], a[3], b[1]);
  auto n8 = gate_and(n18, n7);
  auto n31 = gate_not(b[1]);
  auto n17 = gate_nor(n28, a[1]);
  auto n9 = gate_not(n17);
  auto n13 = gate_and(n18, n31);
  auto n53 = gate_not(a[0]);
  auto n48 = gate_and(b[0], n53);
  auto n32 = gate_not(n48);
  auto n1 = gate_or(n28, a[2]);
  auto n3 = gate_nand(n8, n1);
  auto n6 = gate_nand(b[0], n13);
  auto n25 = gate_and(a[2], n3);
  auto n11 = gate_and(n25, n31);
  auto n16 = gate_xnor(b[1], n25);
  auto n10 = gate_and(n16, n9);
  auto n19 = gate_nor(n11, n10);
  auto n12 = gate_xnor(n27, n19);
  auto n15 = gate_and(n12, n42);
  auto n14 = gate_and(a[3], n6);
  auto n20 = gate_and(n14, n3);
  auto n39 = gate_not(n20);
  auto n43 = gate_nor(n15, n39);
  auto n26 = gate_nor(n17, n16);
  auto n24 = gate_and(n18, n20);
  auto n22 = gate_nor(b[3], n19);
  auto n21 = gate_xnor(b[2], n20);
  auto n23 = gate_and(n22, n21);
  auto n29 = gate_nor(n24, n23);
  auto n47 = gate_mux(n26, n25, n29);
  auto n37 = gate_and(n27, n47);
  auto n45 = gate_xnor(b[2], n47);
  auto n30 = gate_nor(n29, n28);
  auto n51 = gate_xor(n30, a[1]);
  auto n34 = gate_and(n31, n51);
  auto n49 = gate_xnor(n51, b[1]);
  auto n33 = gate_and(n49, n32);
  auto n44 = gate_nor(n34, n33);
  auto n35 = gate_not(n44);
  auto n36 = gate_and(n45, n35);
  auto n38 = gate_and(n43, n42);
  auto n40 = gate_and(b[3], n39);
  auto n46 = gate_xnor(n45, n44);
  auto n50 = gate_xnor(n49, n48);
  auto n5 = gate_or(n37, n36);
  auto n41 = gate_nor(n5, n38);
  auto n52 = gate_nor(n41, n40);
  y[2] = gate_mux(n47, n46, n52);
  y[1] = gate_mux(n51, n50, n52);
  auto n54 = gate_and(n52, b[0]);
  y[0] = gate_xnor(n54, n53);
  auto n2 = gate_nand(n5, n42);
  auto n4 = gate_nand(n52, n2);
  y[3] = gate_and(n43, n4);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_xnor(b[2], b[3]);
  auto n6 = gate_nor(a[1], a[0]);
  auto n66 = gate_not(a[3]);
  auto n2 = gate_nor(n6, n66);
  auto n12 = gate_xnor(n2, a[2]);
  auto n31 = gate_xnor(b[3], b[1]);
  auto n3 = gate_and(b[0], n31);
  auto n4 = gate_and(n27, n3);
  auto n5 = gate_nor(a[2], n4);
  auto n7 = gate_and(n6, n5);
  auto n21 = gate_and(a[3], n7);
  auto n9 = gate_xnor(n21, n31);
  auto n8 = gate_and(b[0], n12);
  auto n10 = gate_nor(n9, n8);
  auto n19 = gate_and(n10, n27);
  auto n11 = gate_and(n19, b[0]);
  auto n26 = gate_nor(n12, n11);
  auto n13 = gate_and(a[3], a[0]);
  auto n29 = gate_xnor(a[1], n13);
  auto n14 = gate_mux(b[3], n29, b[0]);
  auto n52 = gate_not(n31);
  auto n16 = gate_xnor(n52, n26);
  auto n25 = gate_nor(n14, n16);
  auto n18 = gate_and(n26, n31);
  auto n15 = gate_not(n14);
  auto n17 = gate_and(n16, n15);
  auto n39 = gate_nor(n18, n17);
  auto n20 = gate_not(n19);
  auto n41 = gate_and(n21, n20);
  auto n22 = gate_not(n41);
  auto n24 = gate_and(n39, n22);
  auto n23 = gate_not(n27);
  auto n28 = gate_nor(n24, n23);
  auto n46 = gate_mux(n26, n25, n28);
  auto n38 = gate_and(n27, n46);
  auto n43 = gate_xnor(n23, n46);
  auto n30 = gate_and(b[0], n28);
  auto n57 = gate_xnor(n30, n29);
  auto n35 = gate_and(n57, n31);
  auto n33 = gate_xnor(n52, n57);
  auto n32 = gate_not(b[3]);
  auto n53 = gate_mux(n32, a[0], b[0]);
  auto n34 = gate_and(n33, n53);
  auto n44 = gate_nor(n35, n34);
  auto n36 = gate_not(n44);
  auto n37 = gate_and(n43, n36);
  auto n40 = gate_xnor(n39, n23);
  auto n45 = gate_and(n41, n40);
  auto n47 = gate_nor(n44, n43);
  auto n50 = gate_xnor(a[0], a[3]);
  auto n55 = gate_xnor(n53, n52);
  auto n1 = gate_or(n38, n37);
  auto n42 = gate_and(n1, n45);
  auto n60 = gate_nor(n42, n66);
  auto n49 = gate_nor(n1, n45);
  auto n48 = gate_mux(n47, n46, n49);
  auto n62 = gate_xnor(n48, n66);
  auto n54 = gate_not(n49);
  auto n51 = gate_and(b[0], n54);
  auto n65 = gate_xnor(n51, n50);
  auto n58 = gate_and(a[3], n65);
  auto n56 = gate_and(n55, n54);
  auto n63 = gate_xnor(n57, n56);
  auto n61 = gate_and(n58, n63);
  auto n59 = gate_and(n62, n61);
  y[3] = gate_xor(n60, n59);
  y[2] = gate_xor(n62, n61);
  auto n64 = gate_nor(n66, n65);
  y[1] = gate_xnor(n64, n63);
  y[0] = gate_xnor(n66, n65);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
  auto n5 = gate_and(b[0], a[1]);
  auto n4 = gate_and(b[1], a[0]);
  auto n12 = gate_not(n4);
  y[1] = gate_xnor(n5, n12);
  auto n3 = gate_and(b[2], a[0]);
  auto n2 = gate_and(a[1], b[1]);
  auto n6 = gate_xnor(n3, n2);
  auto n9 = gate_and(b[0], a[2]);
  auto n19 = gate_and(b[3], a[0]);
  auto n13 = gate_and(b[2], n12);
  auto n17 = gate_and(a[1], n13);
  auto n15 = gate_and(a[2], b[1]);
  auto n14 = gate_and(a[3], b[0]);
  auto n16 = gate_xnor(n15, n14);
  auto n18 = gate_xnor(n17, n16);
  auto n20 = gate_xnor(n19, n18);
  auto n1 = gate_nand(n5, n4);
  auto n10 = gate_and(n6, n1);
  auto n8 = gate_nor(n6, n1);
  auto n7 = gate_nor(n10, n8);
  y[2] = gate_xor(n7, n9);
  auto n11 = gate_nor(n9, n8);
  auto n21 = gate_nor(n11, n10);
  y[3] = gate_xnor(n21, n20);
}
template<> void $NameUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_and(a[1], a[3]);
  auto n3 = gate_and(a[2], a[0]);
  y[0] = gate_and(n4, n3);
}
template<> void $NameUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_and(a[1], a[3]);
  auto n6 = gate_and(a[2], a[0]);
  y[0] = gate_nand(n7, n6);
}
template<> void $NameUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_nor(a[1], a[0]);
  auto n4 = gate_nor(a[3], a[2]);
  y[0] = gate_and(n5, n4);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nor(a[1], a[0]);
  auto n5 = gate_nor(a[3], a[2]);
  y[0] = gate_nand(n6, n5);
}
template<> void $NameUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_xnor(a[1], a[2]);
  auto n5 = gate_xnor(n4, a[0]);
  y[0] = gate_xnor(a[3], n5);
}
template<> void $NameUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n3 = gate_xor(a[1], a[2]);
  auto n4 = gate_xnor(a[0], n3);
  y[0] = gate_xnor(a[3], n4);
}
template<> void $NameUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n32 = gate_nor(b[3], b[2]);
  auto n29 = gate_not(b[1]);
  auto n38 = gate_and(n32, n29);
  auto n33 = gate_not(b[0]);
  auto n30 = gate_and(n38, n33);
  auto _ash_1_n16 = gate_and(n30, a[0]);
  auto n39 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n38, n39);
  auto n31 = gate_mux(a[2], a[1], b[0]);
  auto n36 = gate_and(n38, n31);
  auto n40 = gate_and(b[1], n32);
  auto n34 = gate_and(a[0], n33);
  auto n35 = gate_and(n40, n34);
  auto n37 = gate_mux(a[3], a[2], b[0]);
  auto n42 = gate_and(n38, n37);
  auto n41 = gate_and(n40, n39);
  y[0] = gate_buf(_ash_1_n16);
  y[3] = gate_or(n42, n41);
  y[2] = gate_or(n36, n35);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_nor(b[2], b[3]);
  auto n19 = gate_not(b[1]);
  auto n28 = gate_and(n22, n19);
  auto n23 = gate_not(b[0]);
  auto n20 = gate_and(n28, n23);
  y[3] = gate_and(a[3], n20);
  auto n29 = gate_mux(a[2], a[3], b[0]);
  y[2] = gate_and(n28, n29);
  auto n21 = gate_mux(a[1], a[2], b[0]);
  auto n26 = gate_and(n28, n21);
  auto n30 = gate_and(b[1], n22);
  auto n24 = gate_and(a[3], n23);
  auto n25 = gate_and(n30, n24);
  auto n27 = gate_mux(a[0], a[1], b[0]);
  auto n32 = gate_and(n28, n27);
  auto n31 = gate_and(n30, n29);
  y[1] = gate_or(n26, n25);
  y[0] = gate_or(n32, n31);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n18 = gate_nand(b[0], b[1]);
  auto n30 = gate_not(a[3]);
  auto n27 = gate_nor(b[3], b[2]);
  auto n21 = gate_and(n18, n27);
  auto n25 = gate_nor(n30, n21);
  auto n22 = gate_and(b[1], a[2]);
  auto n34 = gate_not(b[0]);
  auto n23 = gate_and(n22, n34);
  auto n24 = gate_and(n27, n23);
  auto n29 = gate_nor(n25, n24);
  auto n26 = gate_not(b[1]);
  auto n35 = gate_and(n27, n26);
  auto n28 = gate_mux(a[1], a[0], n34);
  auto n31 = gate_mux(a[2], a[1], n34);
  auto n36 = gate_and(n35, n34);
  y[2] = gate_mux(a[3], a[2], n36);
  y[1] = gate_mux(a[3], n31, n35);
  auto n17 = gate_nand(n35, n28);
  y[0] = gate_nand(n29, n17);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[0]);
  y[0] = gate_xnor(b[0], n16);
  auto n18 = gate_and(b[0], n16);
  auto n20 = gate_xnor(a[1], b[1]);
  y[1] = gate_xnor(n18, n20);
  auto n17 = gate_not(b[1]);
  auto n22 = gate_and(a[1], n17);
  auto n19 = gate_not(n18);
  auto n21 = gate_and(n20, n19);
  auto n24 = gate_nor(n22, n21);
  auto n26 = gate_xnor(a[2], b[2]);
  y[2] = gate_xnor(n24, n26);
  auto n23 = gate_not(b[2]);
  auto n28 = gate_and(a[2], n23);
  auto n25 = gate_not(n24);
  auto n27 = gate_and(n26, n25);
  auto n30 = gate_nor(n28, n27);
  auto n29 = gate_xnor(b[3], a[3]);
  y[3] = gate_xnor(n30, n29);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_nor(a[0], a[1]);
  y[2] = gate_xnor(a[2], n5);
  auto n4 = gate_not(a[2]);
  auto n6 = gate_and(n5, n4);
  y[3] = gate_xnor(a[3], n6);
}
