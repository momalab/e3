// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_xor(b[1], a[1]);
  auto n9 = gate_and(b[0], a[0]);
  y[1] = gate_xor(n10, n9);
  auto n12 = gate_nand(b[1], a[1]);
  auto n11 = gate_nand(n10, n9);
  auto n13 = gate_nand(n12, n11);
  auto n14 = gate_xor(b[2], a[2]);
  y[2] = gate_xor(n13, n14);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  auto n16 = gate_nand(b[2], a[2]);
  auto n15 = gate_nand(n14, n13);
  auto _add_x_1_n14 = gate_nand(n16, n15);
  y[3] = gate_buf(_add_x_1_n14);
  y[0] = gate_buf(_add_x_1_n12);
}
template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_and(b[0], a[0]);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n11 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n12, n11);
  auto n16 = gate_xor(b[2], a[2]);
  auto n14 = gate_and(b[1], a[1]);
  auto n13 = gate_and(n12, n11);
  auto n15 = gate_or(n14, n13);
  y[2] = gate_xor(n16, n15);
  auto n18 = gate_and(b[2], a[2]);
  auto n17 = gate_and(n16, n15);
  auto n19 = gate_or(n18, n17);
  auto n20 = gate_xor(b[3], n19);
  y[3] = gate_xor(a[3], n20);
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
  y[2] = gate_or(a[2], b[2]);
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
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
  auto n16 = gate_not(a[0]);
  auto n11 = gate_and(c[0], n16);
  auto n10 = gate_and(a[0], b[0]);
  y[0] = gate_or(n11, n10);
  auto n13 = gate_and(c[1], n16);
  auto n12 = gate_and(a[0], b[1]);
  y[1] = gate_or(n13, n12);
  auto n15 = gate_and(c[2], n16);
  auto n14 = gate_and(a[0], b[2]);
  y[2] = gate_or(n15, n14);
  auto n18 = gate_and(c[3], n16);
  auto n17 = gate_and(a[0], b[3]);
  y[3] = gate_or(n18, n17);
}
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n5);
  y[0] = gate_not(a[0]);
  auto n8 = gate_and(y[0], n5);
  auto n6 = gate_not(a[2]);
  auto n7 = gate_and(n8, n6);
  y[3] = gate_xor(n7, a[3]);
  y[2] = gate_xor(a[2], n8);
}
template<> void $NameUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n33 = gate_not(b[1]);
  auto n25 = gate_not(b[3]);
  auto n30 = gate_not(b[2]);
  auto n8 = gate_and(n25, n30);
  auto n4 = gate_and(n33, n8);
  auto n32 = gate_not(b[0]);
  auto n3 = gate_or(n32, a[3]);
  y[3] = gate_and(n4, n3);
  auto n6 = gate_or(n33, a[3]);
  auto n5 = gate_or(n32, a[2]);
  auto n7 = gate_and(n6, n5);
  y[2] = gate_and(n8, n7);
  auto n2 = gate_nand(y[2], b[0]);
  auto n26 = gate_and(a[2], n2);
  auto n13 = gate_and(n26, n33);
  auto n11 = gate_xor(n26, n33);
  auto n9 = gate_not(a[1]);
  auto n28 = gate_and(n9, b[0]);
  auto n10 = gate_not(n28);
  auto n12 = gate_and(n11, n10);
  auto n14 = gate_or(n13, n12);
  auto n20 = gate_and(n30, n14);
  auto n18 = gate_xor(n30, n14);
  auto n16 = gate_not(y[2]);
  auto n15 = gate_not(y[3]);
  auto n17 = gate_and(n16, n15);
  auto n23 = gate_and(a[3], n17);
  auto n19 = gate_and(n18, n23);
  auto n21 = gate_or(n20, n19);
  y[1] = gate_and(n25, n21);
  auto n1 = gate_nand(y[1], n28);
  auto n22 = gate_not(y[1]);
  auto n24 = gate_and(n23, n22);
  auto n47 = gate_and(n25, n24);
  auto n45 = gate_xor(n25, n24);
  auto n27 = gate_and(y[1], b[1]);
  auto n29 = gate_xor(n27, n26);
  auto n31 = gate_and(n29, n1);
  auto n43 = gate_and(n31, n30);
  auto n41 = gate_xor(n31, n30);
  auto n34 = gate_or(a[0], n32);
  auto n39 = gate_and(n34, n33);
  auto n37 = gate_xor(n34, n33);
  auto n35 = gate_and(y[1], b[0]);
  auto n36 = gate_xor(n35, a[1]);
  auto n38 = gate_and(n37, n36);
  auto n40 = gate_or(n39, n38);
  auto n42 = gate_and(n41, n40);
  auto n44 = gate_or(n43, n42);
  auto n46 = gate_and(n45, n44);
  y[0] = gate_or(n47, n46);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(b[0], a[0]);
  auto n67 = gate_xor(b[3], a[3]);
  auto n9 = gate_not(b[3]);
  auto n38 = gate_xor(b[2], n9);
  auto n46 = gate_not(n38);
  auto n7 = gate_not(b[0]);
  auto n66 = gate_and(n9, n7);
  auto n8 = gate_not(n66);
  auto n11 = gate_and(n8, n1);
  auto n63 = gate_xor(b[1], n9);
  auto n10 = gate_not(n63);
  auto n44 = gate_and(n11, n10);
  auto n42 = gate_xor(n11, n10);
  auto n12 = gate_and(a[0], a[3]);
  auto n41 = gate_xor(n12, a[1]);
  auto n14 = gate_or(a[1], a[0]);
  auto n13 = gate_and(n14, a[3]);
  auto n27 = gate_xor(n13, a[2]);
  auto n16 = gate_not(n14);
  auto n15 = gate_not(a[2]);
  auto n17 = gate_and(n16, n15);
  auto n33 = gate_and(a[3], n17);
  auto n19 = gate_and(n33, n63);
  auto n18 = gate_and(n38, b[0]);
  auto n56 = gate_and(n19, n18);
  auto n20 = gate_not(n56);
  auto n37 = gate_and(n33, n20);
  auto n21 = gate_and(b[0], n27);
  auto n23 = gate_or(n66, n21);
  auto n22 = gate_or(n37, n23);
  auto n25 = gate_and(n22, n63);
  auto n24 = gate_and(n23, n33);
  auto n26 = gate_or(n25, n24);
  auto n55 = gate_and(n38, n26);
  auto n36 = gate_not(n55);
  auto n47 = gate_and(n27, n36);
  auto n32 = gate_and(n63, n47);
  auto n30 = gate_xor(n63, n47);
  auto n28 = gate_and(b[0], n41);
  auto n29 = gate_or(n66, n28);
  auto n31 = gate_and(n30, n29);
  auto n35 = gate_or(n32, n31);
  auto n34 = gate_or(n33, n38);
  auto n40 = gate_and(n35, n34);
  auto n51 = gate_and(n37, n36);
  auto n39 = gate_and(n38, n51);
  auto n54 = gate_or(n40, n39);
  auto n6 = gate_nand(b[0], n54);
  auto n3 = gate_nand(n41, n6);
  auto n43 = gate_and(n42, n3);
  auto n45 = gate_or(n44, n43);
  auto n50 = gate_and(n46, n45);
  auto n48 = gate_xor(n46, n45);
  auto n52 = gate_not(n54);
  auto n2 = gate_nand(n52, n51);
  auto n4 = gate_nand(n47, n52);
  auto n49 = gate_and(n48, n4);
  auto n53 = gate_or(n50, n49);
  auto n68 = gate_and(n53, n2);
  auto n62 = gate_and(n67, n68);
  auto n61 = gate_xor(n67, n54);
  auto n60 = gate_and(n62, n61);
  auto n59 = gate_xor(n67, n55);
  auto n58 = gate_and(n60, n59);
  auto n57 = gate_xor(n67, n56);
  y[3] = gate_xor(n58, n57);
  y[2] = gate_xor(n60, n59);
  y[1] = gate_xor(n62, n61);
  auto n73 = gate_not(n62);
  auto n64 = gate_not(b[2]);
  auto n65 = gate_and(n64, n63);
  auto n5 = gate_nand(n66, n65);
  auto n71 = gate_and(n67, n5);
  auto n69 = gate_not(n67);
  auto n70 = gate_xor(n69, n68);
  auto n72 = gate_or(n71, n70);
  y[0] = gate_and(n73, n72);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(a[1], b[1]);
  auto n12 = gate_xnor(a[0], b[0]);
  auto n13 = gate_not(b[3]);
  auto n16 = gate_xor(n13, a[3]);
  auto n14 = gate_not(b[2]);
  auto n15 = gate_xor(n14, a[2]);
  auto n17 = gate_and(n16, n15);
  auto n18 = gate_and(n17, n12);
  auto _eq_x_1_n30 = gate_and(n18, n11);
  y[0] = gate_buf(_eq_x_1_n30);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[3]);
  auto n34 = gate_and(n20, a[3]);
  auto n32 = gate_xor(n20, a[3]);
  auto n21 = gate_not(a[0]);
  auto n19 = gate_nand(b[0], n21);
  auto n25 = gate_and(n19, a[1]);
  auto n23 = gate_xor(n19, a[1]);
  auto n22 = gate_not(b[1]);
  auto n24 = gate_and(n23, n22);
  auto n26 = gate_or(n25, n24);
  auto n30 = gate_and(n26, a[2]);
  auto n28 = gate_xor(n26, a[2]);
  auto n27 = gate_not(b[2]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto _gte_x_1_n29 = gate_or(n34, n33);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n34 = gate_and(n20, b[3]);
  auto n32 = gate_xor(n20, b[3]);
  auto n21 = gate_not(a[0]);
  auto n19 = gate_nand(b[0], n21);
  auto n25 = gate_and(n19, a[1]);
  auto n23 = gate_xor(n19, a[1]);
  auto n22 = gate_not(b[1]);
  auto n24 = gate_and(n23, n22);
  auto n26 = gate_or(n25, n24);
  auto n30 = gate_and(n26, a[2]);
  auto n28 = gate_xor(n26, a[2]);
  auto n27 = gate_not(b[2]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto _gte_x_1_n29 = gate_or(n34, n33);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[2]);
  auto n27 = gate_and(n17, a[2]);
  auto n25 = gate_xor(n17, a[2]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_and(a[0], n18);
  auto n23 = gate_and(n19, a[1]);
  auto n21 = gate_xor(n19, a[1]);
  auto n20 = gate_not(b[1]);
  auto n22 = gate_and(n21, n20);
  auto n24 = gate_or(n23, n22);
  auto n26 = gate_and(n25, n24);
  auto n28 = gate_or(n27, n26);
  auto n32 = gate_and(a[3], n28);
  auto n30 = gate_xor(a[3], n28);
  auto n29 = gate_not(b[3]);
  auto n31 = gate_and(n30, n29);
  auto _gt_x_1_n29 = gate_or(n32, n31);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[2]);
  auto n27 = gate_and(n17, a[2]);
  auto n25 = gate_xor(n17, a[2]);
  auto n18 = gate_not(b[0]);
  auto n19 = gate_and(a[0], n18);
  auto n23 = gate_and(n19, a[1]);
  auto n21 = gate_xor(n19, a[1]);
  auto n20 = gate_not(b[1]);
  auto n22 = gate_and(n21, n20);
  auto n24 = gate_or(n23, n22);
  auto n26 = gate_and(n25, n24);
  auto n28 = gate_or(n27, n26);
  auto n32 = gate_and(b[3], n28);
  auto n30 = gate_xor(b[3], n28);
  auto n29 = gate_not(a[3]);
  auto n31 = gate_and(n30, n29);
  auto _gt_x_1_n29 = gate_or(n32, n31);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  auto n4 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n4, a[2]);
  y[3] = gate_xor(n3, a[3]);
  y[2] = gate_xor(n4, a[2]);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_xor(b[0], a[0]);
  auto n8 = gate_xor(b[1], a[1]);
  auto n13 = gate_or(n9, n8);
  auto n11 = gate_xor(b[2], a[2]);
  auto n10 = gate_xor(b[3], a[3]);
  auto n12 = gate_or(n11, n10);
  y[0] = gate_or(n13, n12);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n14 = gate_or(a[1], a[0]);
  auto n13 = gate_or(a[3], a[2]);
  auto n21 = gate_or(n14, n13);
  auto n16 = gate_and(b[0], n21);
  auto n22 = gate_not(n21);
  auto n15 = gate_and(n22, c[0]);
  y[0] = gate_or(n16, n15);
  auto n18 = gate_and(b[1], n21);
  auto n17 = gate_and(n22, c[1]);
  y[1] = gate_or(n18, n17);
  auto n20 = gate_and(b[2], n21);
  auto n19 = gate_and(n22, c[2]);
  y[2] = gate_or(n20, n19);
  auto n24 = gate_and(b[3], n21);
  auto n23 = gate_and(n22, c[3]);
  y[3] = gate_or(n24, n23);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[0]);
  auto n25 = gate_and(a[0], n22);
  auto n20 = gate_nand(a[1], n25);
  auto n24 = gate_xor(a[1], n25);
  auto n23 = gate_not(b[1]);
  auto n21 = gate_nand(n24, n23);
  auto n26 = gate_and(n21, n20);
  auto n30 = gate_and(n26, b[2]);
  auto n28 = gate_xor(n26, b[2]);
  auto n27 = gate_not(a[2]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n35 = gate_and(n31, b[3]);
  auto n33 = gate_xor(n31, b[3]);
  auto n32 = gate_not(a[3]);
  auto n34 = gate_and(n33, n32);
  y[0] = gate_or(n35, n34);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[0]);
  auto n25 = gate_and(a[0], n22);
  auto n20 = gate_nand(a[1], n25);
  auto n24 = gate_xor(a[1], n25);
  auto n23 = gate_not(b[1]);
  auto n21 = gate_nand(n24, n23);
  auto n26 = gate_and(n21, n20);
  auto n30 = gate_and(n26, b[2]);
  auto n28 = gate_xor(n26, b[2]);
  auto n27 = gate_not(a[2]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n35 = gate_and(n31, a[3]);
  auto n33 = gate_xor(n31, a[3]);
  auto n32 = gate_not(b[3]);
  auto n34 = gate_and(n33, n32);
  y[0] = gate_or(n35, n34);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_or(a[1], a[0]);
  auto n7 = gate_or(a[3], a[2]);
  auto n12 = gate_or(n8, n7);
  auto n10 = gate_or(b[1], b[0]);
  auto n9 = gate_or(b[3], b[2]);
  auto n11 = gate_or(n10, n9);
  y[0] = gate_and(n12, n11);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[2]);
  auto n8 = gate_not(a[3]);
  auto n13 = gate_and(n9, n8);
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[1]);
  auto n12 = gate_and(n11, n10);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_or(a[1], a[0]);
  auto n7 = gate_or(a[3], a[2]);
  auto n12 = gate_or(n8, n7);
  auto n10 = gate_or(b[1], b[0]);
  auto n9 = gate_or(b[3], b[2]);
  auto n11 = gate_or(n10, n9);
  y[0] = gate_or(n12, n11);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[3]);
  auto n33 = gate_and(n18, b[3]);
  auto n31 = gate_xor(n18, b[3]);
  auto n19 = gate_not(a[2]);
  auto n29 = gate_and(n19, b[2]);
  auto n27 = gate_xor(n19, b[2]);
  auto n20 = gate_not(a[0]);
  auto n21 = gate_and(b[0], n20);
  auto n25 = gate_and(n21, b[1]);
  auto n23 = gate_xor(n21, b[1]);
  auto n22 = gate_not(a[1]);
  auto n24 = gate_and(n23, n22);
  auto n26 = gate_or(n25, n24);
  auto n28 = gate_and(n27, n26);
  auto n30 = gate_or(n29, n28);
  auto n32 = gate_and(n31, n30);
  y[0] = gate_or(n33, n32);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(b[3]);
  auto n33 = gate_and(n18, a[3]);
  auto n31 = gate_xor(n18, a[3]);
  auto n19 = gate_not(a[2]);
  auto n29 = gate_and(n19, b[2]);
  auto n27 = gate_xor(n19, b[2]);
  auto n20 = gate_not(a[0]);
  auto n21 = gate_and(b[0], n20);
  auto n25 = gate_and(n21, b[1]);
  auto n23 = gate_xor(n21, b[1]);
  auto n22 = gate_not(a[1]);
  auto n24 = gate_and(n23, n22);
  auto n26 = gate_or(n25, n24);
  auto n28 = gate_and(n27, n26);
  auto n30 = gate_or(n29, n28);
  auto n32 = gate_and(n31, n30);
  y[0] = gate_or(n33, n32);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n48 = gate_not(b[3]);
  auto n51 = gate_not(b[2]);
  auto n27 = gate_and(n48, n51);
  auto n36 = gate_not(b[1]);
  auto n6 = gate_xor(n36, a[3]);
  auto n8 = gate_and(n27, n6);
  auto n7 = gate_and(n27, n36);
  auto n11 = gate_and(b[0], n7);
  auto n10 = gate_or(n8, n11);
  auto n9 = gate_not(a[2]);
  auto n1 = gate_nand(n9, b[0]);
  auto n15 = gate_and(n10, n1);
  auto n3 = gate_nand(n15, b[0]);
  auto n14 = gate_not(n15);
  auto n12 = gate_not(n11);
  auto n13 = gate_and(n12, a[3]);
  auto n26 = gate_and(n14, n13);
  auto n30 = gate_and(a[2], n3);
  auto n20 = gate_and(n30, n36);
  auto n18 = gate_xor(n30, n36);
  auto n16 = gate_not(a[1]);
  auto n32 = gate_and(n16, b[0]);
  auto n17 = gate_not(n32);
  auto n19 = gate_and(n18, n17);
  auto n23 = gate_or(n20, n19);
  auto n21 = gate_xor(n23, b[2]);
  auto n22 = gate_or(b[3], n21);
  auto n50 = gate_and(n26, n22);
  auto n45 = gate_or(n26, n48);
  auto n24 = gate_xor(n51, n26);
  auto n25 = gate_and(n24, n23);
  auto n29 = gate_and(n48, n25);
  auto n28 = gate_and(n27, n26);
  auto n34 = gate_or(n29, n28);
  auto n2 = gate_nand(n34, n32);
  auto n31 = gate_and(n34, b[1]);
  auto n33 = gate_xor(n31, n30);
  auto n55 = gate_and(n33, n2);
  auto n44 = gate_and(n51, n55);
  auto n42 = gate_xor(n51, n55);
  auto n35 = gate_and(n34, b[0]);
  auto n59 = gate_xor(n35, a[1]);
  auto n41 = gate_and(n36, n59);
  auto n39 = gate_xor(n36, n59);
  auto n37 = gate_not(a[0]);
  auto n56 = gate_and(n37, b[0]);
  auto n38 = gate_not(n56);
  auto n40 = gate_and(n39, n38);
  auto n52 = gate_or(n41, n40);
  auto n43 = gate_and(n42, n52);
  auto n49 = gate_or(n44, n43);
  auto n4 = gate_nand(n49, n48);
  auto n47 = gate_and(n45, n49);
  auto n46 = gate_and(n48, n50);
  auto n60 = gate_or(n47, n46);
  auto n5 = gate_nand(n60, n4);
  y[3] = gate_and(n50, n5);
  auto n53 = gate_xor(n52, n51);
  auto n54 = gate_and(n60, n53);
  y[2] = gate_xor(n55, n54);
  auto n57 = gate_xor(n56, b[1]);
  auto n58 = gate_and(n60, n57);
  y[1] = gate_xor(n59, n58);
  auto n61 = gate_and(n60, b[0]);
  y[0] = gate_xor(n61, a[0]);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_or(a[1], a[0]);
  auto n7 = gate_and(n8, a[3]);
  auto n15 = gate_xor(n7, a[2]);
  auto n16 = gate_not(b[3]);
  auto n37 = gate_xor(b[2], n16);
  auto n10 = gate_not(n8);
  auto n60 = gate_xor(b[1], n16);
  auto n9 = gate_and(n60, n37);
  auto n1 = gate_nand(b[0], n9);
  auto n12 = gate_and(n10, n1);
  auto n11 = gate_not(a[2]);
  auto n13 = gate_and(n12, n11);
  auto n25 = gate_and(a[3], n13);
  auto n23 = gate_xor(n25, n60);
  auto n14 = gate_and(n37, n23);
  auto n3 = gate_nand(n14, b[0]);
  auto n32 = gate_and(n15, n3);
  auto n22 = gate_and(n32, n60);
  auto n20 = gate_xor(n32, n60);
  auto n17 = gate_not(b[0]);
  auto n42 = gate_and(n17, n16);
  auto n18 = gate_and(a[3], a[0]);
  auto n39 = gate_xor(a[1], n18);
  auto n19 = gate_and(b[0], n39);
  auto n34 = gate_or(n42, n19);
  auto n21 = gate_and(n20, n34);
  auto n27 = gate_or(n22, n21);
  auto n53 = gate_not(n37);
  auto n26 = gate_xor(n27, n53);
  auto n24 = gate_and(n37, n42);
  auto n2 = gate_nand(n24, n23);
  auto n28 = gate_and(n25, n2);
  auto n50 = gate_and(n26, n28);
  auto n30 = gate_and(n27, n37);
  auto n29 = gate_and(n28, n37);
  auto n38 = gate_or(n30, n29);
  auto n31 = gate_not(n60);
  auto n33 = gate_and(n38, n31);
  auto n36 = gate_xor(n33, n32);
  auto n35 = gate_not(n34);
  auto n4 = gate_nand(n38, n35);
  auto n54 = gate_and(n36, n4);
  auto n48 = gate_and(n37, n54);
  auto n46 = gate_xor(n37, n54);
  auto n40 = gate_and(n38, b[0]);
  auto n65 = gate_xor(n40, n39);
  auto n45 = gate_and(n65, n60);
  auto n43 = gate_xor(n65, n60);
  auto n41 = gate_and(a[0], b[0]);
  auto n61 = gate_or(n42, n41);
  auto n44 = gate_and(n43, n61);
  auto n51 = gate_or(n45, n44);
  auto n47 = gate_and(n46, n51);
  auto n49 = gate_or(n48, n47);
  auto n6 = gate_nand(n50, n49);
  auto n69 = gate_and(a[3], n6);
  auto n63 = gate_or(n50, n49);
  auto n52 = gate_not(n51);
  auto n5 = gate_nand(n63, n52);
  auto n55 = gate_and(n63, n53);
  auto n56 = gate_xor(n55, n54);
  auto n57 = gate_and(n5, n56);
  auto n71 = gate_xor(a[3], n57);
  auto n59 = gate_and(b[0], n63);
  auto n58 = gate_xor(a[0], a[3]);
  auto n75 = gate_xor(n59, n58);
  y[0] = gate_xor(a[3], n75);
  auto n67 = gate_and(a[3], n75);
  auto n62 = gate_xor(n61, n60);
  auto n64 = gate_and(n63, n62);
  auto n73 = gate_xor(n65, n64);
  auto n66 = gate_not(n73);
  auto n70 = gate_and(n67, n66);
  auto n68 = gate_and(n71, n70);
  y[3] = gate_xor(n69, n68);
  y[2] = gate_xor(n71, n70);
  auto n72 = gate_not(n75);
  auto n74 = gate_and(n72, a[3]);
  y[1] = gate_xor(n74, n73);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n3 = gate_and(a[1], b[0]);
  auto n4 = gate_and(b[1], a[0]);
  y[1] = gate_xor(n3, n4);
  auto n2 = gate_and(b[2], a[0]);
  auto n1 = gate_and(a[1], b[1]);
  auto n12 = gate_xor(n2, n1);
  auto n11 = gate_and(b[0], a[2]);
  auto n14 = gate_xor(n12, n11);
  auto n13 = gate_and(n3, n4);
  y[2] = gate_xor(n14, n13);
  auto n5 = gate_not(n4);
  auto n6 = gate_and(n5, a[1]);
  auto n10 = gate_and(b[2], n6);
  auto n8 = gate_and(a[3], b[0]);
  auto n7 = gate_and(a[2], b[1]);
  auto n9 = gate_xor(n8, n7);
  auto n20 = gate_xor(n10, n9);
  auto n18 = gate_and(a[0], b[3]);
  auto n16 = gate_and(n12, n11);
  auto n15 = gate_and(n14, n13);
  auto n17 = gate_or(n16, n15);
  auto n19 = gate_xor(n18, n17);
  y[3] = gate_xor(n20, n19);
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
  auto n9 = gate_not(a[2]);
  auto n8 = gate_not(a[3]);
  auto n13 = gate_and(n9, n8);
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[1]);
  auto n12 = gate_and(n11, n10);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_or(a[1], a[0]);
  auto n3 = gate_or(a[3], a[2]);
  y[0] = gate_or(n4, n3);
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
  auto n33 = gate_not(b[2]);
  auto n32 = gate_not(b[3]);
  auto n37 = gate_and(n33, n32);
  auto n34 = gate_not(b[1]);
  auto n38 = gate_and(n37, n34);
  auto n42 = gate_not(b[0]);
  auto n45 = gate_and(n38, n42);
  auto _ash_1_n16 = gate_and(a[0], n45);
  y[0] = gate_buf(_ash_1_n16);
  auto n36 = gate_and(a[1], n42);
  auto n35 = gate_and(b[0], a[0]);
  auto n47 = gate_or(n36, n35);
  y[1] = gate_and(n38, n47);
  auto n46 = gate_and(b[0], n38);
  auto n44 = gate_and(a[1], n46);
  auto n48 = gate_and(b[1], n37);
  auto n40 = gate_and(a[0], n48);
  auto n39 = gate_and(n38, a[2]);
  auto n41 = gate_or(n40, n39);
  auto n43 = gate_and(n42, n41);
  y[2] = gate_or(n44, n43);
  auto n52 = gate_and(n45, a[3]);
  auto n50 = gate_and(n46, a[2]);
  auto n49 = gate_and(n48, n47);
  auto n51 = gate_or(n50, n49);
  y[3] = gate_or(n52, n51);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(b[3]);
  auto n22 = gate_not(b[2]);
  auto n25 = gate_and(n23, n22);
  auto n24 = gate_not(b[1]);
  auto n38 = gate_and(n25, n24);
  auto n27 = gate_and(a[1], n38);
  auto n28 = gate_and(b[1], n25);
  auto n26 = gate_and(n28, a[3]);
  auto n34 = gate_or(n27, n26);
  auto n33 = gate_and(b[0], n34);
  auto n37 = gate_not(b[0]);
  auto n30 = gate_and(n28, a[2]);
  auto n29 = gate_and(n38, a[0]);
  auto n31 = gate_or(n30, n29);
  auto n32 = gate_and(n37, n31);
  y[0] = gate_or(n33, n32);
  auto n39 = gate_and(b[0], n38);
  auto n36 = gate_and(n39, a[2]);
  auto n35 = gate_and(n34, n37);
  y[1] = gate_or(n36, n35);
  auto n42 = gate_and(n38, n37);
  auto n41 = gate_and(n42, a[2]);
  auto n40 = gate_and(n39, a[3]);
  y[2] = gate_or(n41, n40);
  y[3] = gate_and(a[3], n42);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n28 = gate_nand(b[0], b[1]);
  auto n30 = gate_not(b[2]);
  auto n29 = gate_not(b[3]);
  auto n36 = gate_and(n30, n29);
  auto n27 = gate_nand(n28, n36);
  auto n34 = gate_and(a[3], n27);
  auto n31 = gate_and(b[1], a[2]);
  auto n37 = gate_not(b[0]);
  auto n32 = gate_and(n31, n37);
  auto n33 = gate_and(n36, n32);
  auto n41 = gate_or(n34, n33);
  auto n35 = gate_not(b[1]);
  auto n42 = gate_and(n36, n35);
  auto n44 = gate_and(b[0], n42);
  auto n39 = gate_and(n44, a[1]);
  auto n50 = gate_and(n42, n37);
  auto n38 = gate_and(a[0], n50);
  auto n40 = gate_or(n39, n38);
  y[0] = gate_or(n41, n40);
  auto n43 = gate_not(n42);
  auto n48 = gate_and(a[3], n43);
  auto n46 = gate_and(a[2], n44);
  auto n45 = gate_and(a[1], n50);
  auto n47 = gate_or(n46, n45);
  y[1] = gate_or(n48, n47);
  auto n49 = gate_not(n50);
  auto n52 = gate_and(a[3], n49);
  auto n51 = gate_and(n50, a[2]);
  y[2] = gate_or(n52, n51);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n18 = gate_not(a[0]);
  auto n21 = gate_and(b[0], n18);
  auto n20 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n21, n20);
  auto n19 = gate_not(b[1]);
  auto n17 = gate_nand(a[1], n19);
  auto n22 = gate_or(n21, n20);
  auto n24 = gate_and(n17, n22);
  auto n23 = gate_xor(b[2], a[2]);
  y[2] = gate_xor(n24, n23);
  auto n26 = gate_or(n24, n23);
  auto n25 = gate_not(b[2]);
  auto n16 = gate_nand(a[2], n25);
  auto n28 = gate_and(n26, n16);
  auto n27 = gate_xor(b[3], a[3]);
  y[3] = gate_xor(n28, n27);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n3 = gate_or(a[1], a[0]);
  y[2] = gate_xor(a[2], n3);
  auto n4 = gate_or(a[2], n3);
  y[3] = gate_xor(a[3], n4);
}
