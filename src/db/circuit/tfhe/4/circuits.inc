// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_and(b[0], a[0]);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n13 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n12, n13);
  auto n17 = gate_xor(b[2], a[2]);
  auto n15 = gate_nand(b[1], a[1]);
  auto n14 = gate_nand(n12, n13);
  auto n16 = gate_nand(n15, n14);
  y[2] = gate_xor(n17, n16);
  auto n19 = gate_nand(n17, n16);
  auto n18 = gate_nand(b[2], a[2]);
  auto n20 = gate_nand(n19, n18);
  auto n21 = gate_xor(b[3], n20);
  y[3] = gate_xor(a[3], n21);
}
template<> void $NameUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_and(b[3], a[3]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
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
  auto n10 = gate_not(b[3]);
  auto n9 = gate_not(a[3]);
  y[3] = gate_nand(n10, n9);
  auto n12 = gate_not(b[2]);
  auto n11 = gate_not(a[2]);
  y[2] = gate_nand(n12, n11);
  auto n14 = gate_not(b[1]);
  auto n13 = gate_not(a[1]);
  y[1] = gate_nand(n14, n13);
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(a[0]);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n15 = gate_nand(a[1], a[2]);
  auto n13 = gate_not(n15);
  auto n17 = gate_nand(N0, a[3]);
  auto n12 = gate_not(n17);
  y[2] = gate_and(n13, n12);
  auto n19 = gate_xor(a[1], a[2]);
  auto n18 = gate_xor(N0, a[3]);
  auto n14 = gate_nand(n19, n18);
  auto n16 = gate_nand(n17, n14);
  y[1] = gate_mux(n17, n16, n15);
  y[0] = gate_xor(n19, n18);
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
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
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
  auto n10 = gate_and(b[0], a[0]);
  auto n11 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[2], a[2]);
  auto n13 = gate_nand(b[1], a[1]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[2] = gate_xor(n15, n14);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n17 = gate_nand(b[2], a[2]);
  auto n16 = gate_nand(n15, n14);
  auto _add_x_1_n14 = gate_nand(n17, n16);
  y[3] = gate_buf(_add_x_1_n14);
}
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n9);
  y[0] = gate_not(a[0]);
  auto n7 = gate_and(y[0], n9);
  y[2] = gate_xor(a[2], n7);
  auto n10 = gate_not(a[2]);
  auto n8 = gate_and(n7, n10);
  y[3] = gate_xor(n8, a[3]);
}
template<> void $NameUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(b[1]);
  auto n47 = gate_not(b[3]);
  auto n40 = gate_not(b[2]);
  auto n2 = gate_and(n47, n40);
  auto n1 = gate_and(n31, n2);
  auto n22 = gate_not(a[3]);
  auto n7 = gate_nand(b[0], n22);
  auto n17 = gate_nand(n1, n7);
  auto n5 = gate_and(a[3], n17);
  y[3] = gate_not(n17);
  auto n8 = gate_not(a[2]);
  auto n9 = gate_nand(b[0], n8);
  auto n3 = gate_and(n9, n2);
  auto n10 = gate_nand(b[1], n22);
  auto n18 = gate_nand(n3, n10);
  auto n4 = gate_and(n5, n18);
  y[2] = gate_not(n18);
  auto n16 = gate_nand(n22, b[2]);
  auto n11 = gate_nand(y[2], b[0]);
  auto n27 = gate_nand(a[2], n11);
  auto n12 = gate_not(n27);
  auto n14 = gate_nand(n12, n31);
  auto n23 = gate_xor(b[1], n27);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nand(b[0], n30);
  auto n13 = gate_nand(n23, n24);
  auto n15 = gate_nand(n14, n13);
  auto n20 = gate_nand(n16, n15);
  auto n19 = gate_nand(n40, n4);
  auto n21 = gate_nand(n20, n19);
  auto n46 = gate_nand(n47, n21);
  auto n6 = gate_and(n4, n46);
  y[1] = gate_not(n46);
  auto n45 = gate_nand(n22, b[3]);
  auto n25 = gate_not(n23);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_mux(n27, n26, y[1]);
  auto n39 = gate_not(n28);
  auto n29 = gate_nand(y[1], b[0]);
  auto n32 = gate_xor(n30, n29);
  auto n37 = gate_nand(n32, n31);
  auto n35 = gate_xor(n32, n31);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_nand(b[0], n33);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n43 = gate_nand(n39, n38);
  auto n41 = gate_xor(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n49 = gate_nand(n45, n44);
  auto n48 = gate_nand(n47, n6);
  y[0] = gate_nand(n49, n48);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n61 = gate_not(b[3]);
  auto n56 = gate_xor(a[3], n61);
  auto n46 = gate_xor(b[2], b[3]);
  auto n43 = gate_not(n46);
  auto n20 = gate_not(a[1]);
  auto n8 = gate_not(a[0]);
  auto n11 = gate_nand(n20, n8);
  auto n9 = gate_not(n11);
  auto n13 = gate_not(a[2]);
  auto n6 = gate_and(a[3], n13);
  auto n21 = gate_nand(n9, n6);
  auto n10 = gate_not(n21);
  auto n38 = gate_xor(b[1], b[3]);
  auto n36 = gate_not(n38);
  auto n1 = gate_and(n43, n36);
  auto n4 = gate_and(n1, b[0]);
  auto n67 = gate_nand(n10, n4);
  auto n3 = gate_and(n10, n67);
  auto n17 = gate_nand(n3, n36);
  auto n12 = gate_nand(a[3], n11);
  auto n22 = gate_xor(n13, n12);
  auto n60 = gate_not(b[0]);
  auto n2 = gate_and(n61, n60);
  auto n15 = gate_mux(n22, n61, n60);
  auto n14 = gate_nand(n38, n21);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n29 = gate_nand(n43, n18);
  auto n5 = gate_and(n22, n29);
  auto n66 = gate_xor(n56, n29);
  auto n68 = gate_not(n56);
  auto n19 = gate_nand(a[3], a[0]);
  auto n34 = gate_xor(n20, n19);
  auto n28 = gate_nand(n21, n46);
  auto n23 = gate_mux(n34, n61, n60);
  auto n26 = gate_nand(n23, n5);
  auto n24 = gate_xor(n23, n5);
  auto n25 = gate_nand(n24, n36);
  auto n27 = gate_nand(n26, n25);
  auto n32 = gate_nand(n28, n27);
  auto n48 = gate_nand(n3, n29);
  auto n30 = gate_not(n48);
  auto n31 = gate_nand(n43, n30);
  auto n50 = gate_nand(n32, n31);
  auto n33 = gate_nand(b[0], n50);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_not(n37);
  auto n42 = gate_nand(n36, n35);
  auto n40 = gate_xor(n38, n37);
  auto n39 = gate_mux(a[0], n61, n60);
  auto n41 = gate_nand(n40, n39);
  auto n44 = gate_nand(n42, n41);
  auto n53 = gate_nand(n44, n43);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n47, n5);
  auto n51 = gate_nand(n49, n48);
  auto n55 = gate_not(n50);
  auto n52 = gate_nand(n51, n55);
  auto n59 = gate_nand(n53, n52);
  auto n54 = gate_not(n59);
  auto n65 = gate_nand(n68, n54);
  auto n58 = gate_not(n65);
  auto n57 = gate_xor(n56, n55);
  auto n7 = gate_and(n58, n57);
  y[2] = gate_xor(n66, n7);
  y[1] = gate_xor(n58, n57);
  auto n64 = gate_xor(n59, n68);
  auto n62 = gate_nand(n2, n1);
  auto n63 = gate_nand(n68, n62);
  y[0] = gate_mux(n65, n64, n63);
  auto n70 = gate_nand(n66, n7);
  auto n69 = gate_xor(n68, n67);
  y[3] = gate_xor(n70, n69);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n18 = gate_not(b[2]);
  auto n23 = gate_xor(n18, a[2]);
  auto n19 = gate_not(a[3]);
  auto n22 = gate_xor(n19, b[3]);
  auto n20 = gate_not(a[0]);
  auto n21 = gate_xor(n20, b[0]);
  auto n15 = gate_and(n22, n21);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_and(n23, n14);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[3]);
  auto n32 = gate_nand(n17, a[3]);
  auto n30 = gate_xor(n17, a[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[3]);
  auto n32 = gate_nand(n17, b[3]);
  auto n30 = gate_xor(n17, b[3]);
  auto n18 = gate_not(b[1]);
  auto n23 = gate_nand(n18, a[1]);
  auto n21 = gate_xor(n18, a[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n24, a[2]);
  auto n26 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[2]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto _gte_x_1_n29 = gate_nand(n32, n31);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(a[3], n22);
  auto n35 = gate_xor(a[3], n22);
  auto n34 = gate_not(b[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n22 = gate_and(n33, n32);
  auto n37 = gate_nand(b[3], n22);
  auto n35 = gate_xor(b[3], n22);
  auto n34 = gate_not(a[3]);
  auto n36 = gate_nand(n35, n34);
  auto _gt_x_1_n29 = gate_nand(n37, n36);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[0], a[1]);
  y[2] = gate_xor(n6, a[2]);
  auto n5 = gate_and(n6, a[2]);
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  y[3] = gate_xor(n5, a[3]);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[1], b[1]);
  auto n17 = gate_not(b[2]);
  auto n22 = gate_xor(n17, a[2]);
  auto n18 = gate_not(a[3]);
  auto n21 = gate_xor(n18, b[3]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_xor(n19, b[0]);
  auto n15 = gate_and(n21, n20);
  auto n14 = gate_and(n15, n16);
  y[0] = gate_nand(n22, n14);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n13 = gate_not(a[1]);
  auto n12 = gate_not(a[3]);
  auto n11 = gate_and(n13, n12);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[0]);
  auto n10 = gate_and(n15, n14);
  auto n16 = gate_nand(n11, n10);
  y[3] = gate_mux(c[3], b[3], n16);
  y[0] = gate_mux(c[0], b[0], n16);
  y[1] = gate_mux(c[1], b[1], n16);
  y[2] = gate_mux(c[2], b[2], n16);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[3]);
  auto n37 = gate_nand(n22, b[3]);
  auto n35 = gate_xor(n22, b[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[3]);
  auto n37 = gate_nand(n22, a[3]);
  auto n35 = gate_xor(n22, a[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_nand(n23, b[1]);
  auto n26 = gate_xor(n23, b[1]);
  auto n24 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n33 = gate_nand(n29, b[2]);
  auto n31 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[2]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  y[0] = gate_nand(n37, n36);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_not(a[1]);
  auto n25 = gate_not(a[3]);
  auto n24 = gate_and(n26, n25);
  auto n28 = gate_not(a[2]);
  auto n27 = gate_not(a[0]);
  auto n23 = gate_and(n28, n27);
  auto n34 = gate_nand(n24, n23);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(b[3]);
  auto n22 = gate_and(n30, n29);
  auto n32 = gate_not(b[2]);
  auto n31 = gate_not(b[0]);
  auto n21 = gate_and(n32, n31);
  auto n33 = gate_nand(n22, n21);
  y[0] = gate_and(n34, n33);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(a[1]);
  auto n27 = gate_not(a[3]);
  auto n26 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[0]);
  auto n25 = gate_and(n30, n29);
  auto n22 = gate_and(n26, n25);
  auto n32 = gate_not(b[1]);
  auto n31 = gate_not(b[3]);
  auto n24 = gate_and(n32, n31);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[0]);
  auto n23 = gate_and(n34, n33);
  auto n21 = gate_and(n24, n23);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[3]);
  auto n35 = gate_nand(n20, a[3]);
  auto n33 = gate_xor(n20, a[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n35 = gate_nand(n20, b[3]);
  auto n33 = gate_xor(n20, b[3]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_nand(n21, a[1]);
  auto n24 = gate_xor(n21, a[1]);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n27, a[2]);
  auto n29 = gate_xor(n27, a[2]);
  auto n28 = gate_not(b[2]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_and(n35, n34);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n44 = gate_not(b[3]);
  auto n29 = gate_not(b[2]);
  auto n3 = gate_and(n44, n29);
  auto n33 = gate_not(b[1]);
  auto n2 = gate_and(n3, n33);
  auto n8 = gate_nand(b[0], n2);
  auto n6 = gate_and(a[3], n8);
  auto n9 = gate_mux(a[3], b[0], n33);
  auto n5 = gate_and(n3, n9);
  auto n10 = gate_not(a[2]);
  auto n11 = gate_nand(b[0], n10);
  auto n12 = gate_nand(n5, n11);
  auto n38 = gate_nand(n6, n12);
  auto n21 = gate_not(n38);
  auto n28 = gate_nand(a[2], n12);
  auto n13 = gate_not(n28);
  auto n16 = gate_nand(n13, n33);
  auto n19 = gate_xor(n33, n28);
  auto n14 = gate_not(n19);
  auto n32 = gate_not(a[1]);
  auto n20 = gate_nand(b[0], n32);
  auto n15 = gate_nand(n14, n20);
  auto n22 = gate_nand(n16, n15);
  auto n17 = gate_xor(n29, n22);
  auto n18 = gate_nand(n44, n17);
  auto n1 = gate_and(n21, n18);
  auto n27 = gate_nand(n20, n19);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_xor(n22, n21);
  auto n24 = gate_nand(n23, n29);
  auto n26 = gate_nand(n25, n24);
  auto n4 = gate_and(n44, n26);
  auto n30 = gate_mux(n28, n27, n4);
  auto n48 = gate_not(n30);
  auto n37 = gate_nand(n29, n48);
  auto n43 = gate_xor(b[2], n30);
  auto n31 = gate_nand(n4, b[0]);
  auto n52 = gate_xor(n32, n31);
  auto n35 = gate_nand(n33, n52);
  auto n50 = gate_xor(n33, n52);
  auto n55 = gate_not(a[0]);
  auto n49 = gate_nand(b[0], n55);
  auto n34 = gate_nand(n50, n49);
  auto n42 = gate_nand(n35, n34);
  auto n36 = gate_nand(n43, n42);
  auto n40 = gate_nand(n37, n36);
  auto n39 = gate_nand(b[3], n38);
  auto n46 = gate_nand(n40, n39);
  auto n41 = gate_mux(n46, n40, n44);
  y[3] = gate_and(n1, n41);
  auto n47 = gate_xor(n43, n42);
  auto n45 = gate_nand(n44, n1);
  auto n53 = gate_nand(n46, n45);
  y[2] = gate_mux(n48, n47, n53);
  auto n51 = gate_xor(n50, n49);
  y[1] = gate_mux(n52, n51, n53);
  auto n54 = gate_nand(n53, b[0]);
  y[0] = gate_xor(n55, n54);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n69 = gate_not(a[3]);
  auto n12 = gate_not(a[2]);
  auto n9 = gate_not(a[1]);
  auto n56 = gate_not(a[0]);
  auto n13 = gate_nand(n9, n56);
  auto n10 = gate_nand(a[3], n13);
  auto n20 = gate_xor(n12, n10);
  auto n47 = gate_xor(b[2], b[3]);
  auto n46 = gate_not(n47);
  auto n37 = gate_not(b[3]);
  auto n60 = gate_xor(n37, b[1]);
  auto n5 = gate_and(b[0], n60);
  auto n11 = gate_nand(n5, n46);
  auto n3 = gate_and(n12, n11);
  auto n14 = gate_not(n13);
  auto n8 = gate_and(n14, a[3]);
  auto n2 = gate_and(n3, n8);
  auto n15 = gate_xor(n60, n2);
  auto n1 = gate_and(n46, n15);
  auto n36 = gate_not(b[0]);
  auto n16 = gate_not(n20);
  auto n17 = gate_nand(b[0], n16);
  auto n23 = gate_nand(n1, n17);
  auto n4 = gate_and(n2, n23);
  auto n18 = gate_not(n23);
  auto n19 = gate_nand(n18, b[0]);
  auto n32 = gate_nand(n20, n19);
  auto n21 = gate_nand(a[3], a[0]);
  auto n35 = gate_xor(a[1], n21);
  auto n22 = gate_mux(n35, b[3], n36);
  auto n26 = gate_not(n22);
  auto n25 = gate_xor(n32, n60);
  auto n31 = gate_nand(n26, n25);
  auto n43 = gate_nand(n4, n46);
  auto n24 = gate_not(n32);
  auto n29 = gate_nand(n24, n60);
  auto n27 = gate_not(n25);
  auto n28 = gate_nand(n27, n26);
  auto n42 = gate_nand(n29, n28);
  auto n30 = gate_nand(n46, n42);
  auto n33 = gate_nand(n43, n30);
  auto n54 = gate_mux(n32, n31, n33);
  auto n34 = gate_nand(b[0], n33);
  auto n64 = gate_xor(n35, n34);
  auto n40 = gate_nand(n64, n60);
  auto n38 = gate_xor(n64, n60);
  auto n59 = gate_mux(a[0], n37, n36);
  auto n39 = gate_nand(n38, n59);
  auto n48 = gate_nand(n40, n39);
  auto n41 = gate_xor(n54, n46);
  auto n53 = gate_nand(n48, n41);
  auto n44 = gate_nand(n47, n2);
  auto n71 = gate_mux(n44, n43, n42);
  auto n45 = gate_not(n54);
  auto n51 = gate_nand(n46, n45);
  auto n49 = gate_xor(n47, n54);
  auto n50 = gate_nand(n49, n48);
  auto n73 = gate_nand(n51, n50);
  auto n52 = gate_not(n73);
  auto n62 = gate_nand(n71, n52);
  auto n55 = gate_mux(n54, n53, n62);
  auto n70 = gate_xor(n69, n55);
  auto n58 = gate_xor(a[3], n56);
  auto n57 = gate_nand(b[0], n62);
  auto n65 = gate_xor(n58, n57);
  auto n6 = gate_and(a[3], n65);
  auto n61 = gate_xor(n60, n59);
  auto n63 = gate_nand(n62, n61);
  auto n67 = gate_xor(n64, n63);
  auto n7 = gate_and(n6, n67);
  y[2] = gate_xor(n70, n7);
  auto n68 = gate_not(n65);
  auto n66 = gate_nand(a[3], n68);
  y[1] = gate_xor(n67, n66);
  y[0] = gate_xor(n69, n68);
  auto n76 = gate_nand(n70, n7);
  auto n72 = gate_not(n71);
  auto n74 = gate_nand(n73, n72);
  auto n75 = gate_nand(a[3], n74);
  y[3] = gate_xor(n76, n75);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(a[2], b[0]);
  y[0] = gate_and(a[0], b[0]);
  auto n4 = gate_and(a[1], b[2]);
  auto n5 = gate_and(a[1], b[0]);
  auto n17 = gate_nand(a[0], b[1]);
  auto n8 = gate_not(n17);
  auto n2 = gate_and(n8, n5);
  y[1] = gate_xor(n8, n5);
  auto n7 = gate_nand(a[1], b[1]);
  auto n6 = gate_nand(b[2], a[0]);
  auto n10 = gate_xor(n7, n6);
  auto n9 = gate_xor(n10, n1);
  y[2] = gate_xor(n9, n2);
  auto n14 = gate_nand(a[0], b[3]);
  auto n12 = gate_nand(n9, n2);
  auto n11 = gate_nand(n10, n1);
  auto n13 = gate_nand(n12, n11);
  auto n21 = gate_xor(n14, n13);
  auto n16 = gate_nand(a[3], b[0]);
  auto n15 = gate_nand(a[2], b[1]);
  auto n19 = gate_xor(n16, n15);
  auto n18 = gate_nand(n17, n4);
  auto n20 = gate_xor(n19, n18);
  y[3] = gate_xor(n21, n20);
}
template<> void $NameUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n8 = gate_and(a[2], a[0]);
  y[0] = gate_and(n6, n8);
}
template<> void $NameUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[1], a[3]);
  auto n7 = gate_and(a[2], a[0]);
  y[0] = gate_nand(n6, n7);
}
template<> void $NameUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n16 = gate_not(a[0]);
  auto n14 = gate_not(a[3]);
  auto n13 = gate_and(n15, n14);
  auto n17 = gate_not(a[2]);
  auto n12 = gate_and(n17, n16);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n10 = gate_and(n12, n11);
  auto n14 = gate_not(a[2]);
  auto n13 = gate_not(a[0]);
  auto n9 = gate_and(n14, n13);
  y[0] = gate_nand(n10, n9);
}
template<> void $NameUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_not(a[0]);
  auto n7 = gate_xor(n5, a[1]);
  auto n6 = gate_xor(a[2], a[3]);
  y[0] = gate_xor(n7, n6);
}
template<> void $NameUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_xor(a[0], a[1]);
  auto n3 = gate_xor(a[3], a[2]);
  y[0] = gate_xor(n4, n3);
}
template<> void $NameUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(b[2]);
  auto n41 = gate_not(b[3]);
  auto n37 = gate_and(n42, n41);
  auto n40 = gate_and(n37, b[1]);
  auto n44 = gate_not(b[1]);
  auto n36 = gate_and(n37, n44);
  auto n46 = gate_not(b[0]);
  auto n35 = gate_and(n36, n46);
  y[0] = gate_and(a[0], n35);
  auto n43 = gate_mux(a[0], a[1], n46);
  y[1] = gate_and(n36, n43);
  auto n47 = gate_nand(a[1], n36);
  auto n45 = gate_mux(a[0], a[2], n44);
  auto n49 = gate_nand(n37, n45);
  auto n48 = gate_mux(n47, n49, n46);
  y[2] = gate_not(n48);
  auto n50 = gate_nand(n40, a[1]);
  auto n52 = gate_mux(n50, n49, b[0]);
  auto n51 = gate_nand(a[3], n35);
  y[3] = gate_nand(n52, n51);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[3]);
  auto n28 = gate_not(b[2]);
  auto n23 = gate_and(n29, n28);
  auto n34 = gate_not(b[1]);
  auto n25 = gate_and(n23, n34);
  auto n26 = gate_and(a[3], n25);
  auto n30 = gate_mux(a[3], a[1], n34);
  auto n35 = gate_nand(n23, n30);
  auto n31 = gate_mux(a[2], a[0], n34);
  auto n32 = gate_nand(n31, n23);
  auto n39 = gate_not(b[0]);
  auto n38 = gate_mux(a[3], a[2], n39);
  y[3] = gate_and(n26, n39);
  y[2] = gate_and(n25, n38);
  auto n33 = gate_mux(n35, n32, n39);
  y[0] = gate_not(n33);
  auto n36 = gate_nand(n25, a[2]);
  auto n37 = gate_mux(n36, n35, n39);
  y[1] = gate_not(n37);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n20 = gate_and(b[1], a[2]);
  auto n37 = gate_not(b[0]);
  auto n23 = gate_nand(n20, n37);
  auto n27 = gate_not(a[3]);
  auto n22 = gate_not(b[2]);
  auto n21 = gate_not(b[3]);
  auto n24 = gate_nand(n22, n21);
  auto n32 = gate_mux(n23, n27, n24);
  auto n26 = gate_not(n24);
  auto n25 = gate_not(b[1]);
  auto n34 = gate_nand(n26, n25);
  auto n38 = gate_not(n34);
  auto n30 = gate_nand(a[0], n38);
  auto n28 = gate_nand(a[1], n26);
  auto n29 = gate_mux(n28, n27, b[1]);
  auto n31 = gate_mux(n30, n29, b[0]);
  y[0] = gate_nand(n32, n31);
  auto n33 = gate_mux(a[1], a[2], b[0]);
  auto n36 = gate_nand(n38, n33);
  auto n35 = gate_nand(a[3], n34);
  y[1] = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  y[2] = gate_mux(a[2], a[3], n39);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n27 = gate_xor(b[3], a[3]);
  auto n17 = gate_not(b[1]);
  auto n19 = gate_xor(a[1], n17);
  auto n16 = gate_not(a[0]);
  auto n18 = gate_nand(b[0], n16);
  y[1] = gate_xor(n19, n18);
  auto n22 = gate_not(b[2]);
  auto n24 = gate_xor(a[2], n22);
  auto n21 = gate_nand(a[1], n17);
  auto n20 = gate_nand(n19, n18);
  auto n23 = gate_nand(n21, n20);
  y[2] = gate_xor(n24, n23);
  auto n26 = gate_nand(a[2], n22);
  auto n25 = gate_nand(n24, n23);
  auto n28 = gate_nand(n26, n25);
  y[3] = gate_xnor(n28, n27);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_not(a[0]);
  auto n9 = gate_nand(n8, n7);
  y[2] = gate_xor(a[2], n9);
  auto n11 = gate_not(n9);
  auto n10 = gate_not(a[2]);
  auto n12 = gate_nand(n11, n10);
  y[3] = gate_xor(a[3], n12);
}
