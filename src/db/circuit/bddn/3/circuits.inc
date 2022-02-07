// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[1]);
  auto n26 = gate_not(a[1]);
  auto n28 = gate_nand(n27, n26);
  auto n34 = gate_nand(a[1], b[1]);
  auto n29 = gate_nand(n28, n34);
  auto n48 = gate_nand(b[0], a[0]);
  auto n32 = gate_nand(n29, n48);
  auto n31 = gate_not(n48);
  auto n30 = gate_not(n29);
  auto n35 = gate_nand(n31, n30);
  auto n33 = gate_nand(n32, n35);
  y[1] = gate_not(n33);
  auto n38 = gate_nand(n35, n34);
  auto n37 = gate_not(n38);
  auto n36 = gate_not(b[2]);
  auto n40 = gate_nand(n37, n36);
  auto n39 = gate_nand(b[2], n38);
  auto n43 = gate_nand(n40, n39);
  auto n42 = gate_not(n43);
  auto n41 = gate_not(a[2]);
  auto n45 = gate_nand(n42, n41);
  auto n44 = gate_nand(n43, a[2]);
  y[2] = gate_nand(n45, n44);
  auto n47 = gate_not(a[0]);
  auto n46 = gate_not(b[0]);
  auto n49 = gate_nand(n47, n46);
  auto n50 = gate_nand(n49, n48);
  auto _add_x_1_n36 = gate_not(n50);
  y[0] = gate_buf(_add_x_1_n36);
}
template<> void $NameUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_nand(b[2], a[2]);
  y[2] = gate_not(n4);
  auto n5 = gate_nand(b[1], a[1]);
  y[1] = gate_not(n5);
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n6);
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
  auto n17 = gate_nand(a[1], N0);
  auto n14 = gate_not(N0);
  auto n13 = gate_not(a[1]);
  auto n15 = gate_nand(n14, n13);
  auto n18 = gate_nand(n15, n17);
  auto n16 = gate_not(n18);
  auto n20 = gate_nand(n16, a[2]);
  y[1] = gate_nand(n17, n20);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_nand(n19, n18);
  auto n22 = gate_nand(n21, n20);
  auto _add_x_2_n36 = gate_not(n22);
  y[0] = gate_buf(_add_x_2_n36);
}
template<> void $NameUint<3>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(b[2]);
  auto n16 = gate_nand(a[2], n13);
  auto n14 = gate_not(a[2]);
  auto n15 = gate_nand(b[2], n14);
  y[2] = gate_nand(n16, n15);
  auto n17 = gate_not(b[1]);
  auto n20 = gate_nand(a[1], n17);
  auto n18 = gate_not(a[1]);
  auto n19 = gate_nand(b[1], n18);
  y[1] = gate_nand(n20, n19);
  auto n21 = gate_not(b[0]);
  auto n24 = gate_nand(a[0], n21);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_nand(b[0], n22);
  y[0] = gate_nand(n24, n23);
}
template<> void $NameUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_nand(a[0], b[0]);
  y[0] = gate_not(n4);
  auto n5 = gate_nand(a[0], b[1]);
  y[1] = gate_not(n5);
  auto n6 = gate_nand(a[0], b[2]);
  y[2] = gate_not(n6);
}
template<> void $NameUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n9 = gate_nand(b[0], a[0]);
  auto n12 = gate_not(a[0]);
  auto n8 = gate_nand(c[0], n12);
  y[0] = gate_nand(n9, n8);
  auto n11 = gate_nand(n12, c[1]);
  auto n10 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n11, n10);
  auto n14 = gate_nand(n12, c[2]);
  auto n13 = gate_nand(a[0], b[2]);
  y[2] = gate_nand(n14, n13);
}
template<> void $NameUint<3>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_nand(a[0], b[0]);
  auto n18 = gate_not(a[1]);
  auto n17 = gate_not(b[1]);
  auto n19 = gate_nand(n18, n17);
  auto n31 = gate_nand(b[1], a[1]);
  auto n20 = gate_nand(n19, n31);
  auto n23 = gate_nand(n27, n20);
  auto n22 = gate_not(n20);
  auto n21 = gate_not(n27);
  auto n30 = gate_nand(n22, n21);
  auto n24 = gate_nand(n23, n30);
  y[1] = gate_not(n24);
  auto n26 = gate_not(b[0]);
  auto n25 = gate_not(a[0]);
  auto n28 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto _add_x_1_n36 = gate_not(n29);
  y[2] = gate_nand(n31, n30);
  y[0] = gate_buf(_add_x_1_n36);
}
template<> void $NameUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n10 = gate_nand(a[1], a[0]);
  auto n9 = gate_not(a[1]);
  auto n13 = gate_nand(y[0], n9);
  y[1] = gate_nand(n10, n13);
  auto n12 = gate_not(n13);
  auto n11 = gate_not(a[2]);
  auto n15 = gate_nand(n12, n11);
  auto n14 = gate_nand(a[2], n13);
  y[2] = gate_nand(n15, n14);
}
template<> void $NameUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(a[2]);
  auto n4 = gate_nand(n16, b[1]);
  auto n1 = gate_not(a[1]);
  auto n2 = gate_nand(n1, b[0]);
  auto n12 = gate_not(b[2]);
  auto n10 = gate_nand(n2, n12);
  auto n3 = gate_not(n10);
  auto n5 = gate_nand(n4, n3);
  y[1] = gate_not(n5);
  auto n8 = gate_nand(n16, b[0]);
  auto n24 = gate_not(b[1]);
  auto n6 = gate_nand(n12, n24);
  auto n7 = gate_not(n6);
  auto n9 = gate_nand(n8, n7);
  y[2] = gate_not(n9);
  auto n11 = gate_nand(n10, a[2]);
  auto n15 = gate_not(n11);
  auto n13 = gate_nand(b[1], n12);
  auto n14 = gate_not(n13);
  auto n30 = gate_nand(n15, n14);
  auto n28 = gate_nand(n16, b[2]);
  auto n17 = gate_nand(y[1], b[0]);
  auto n18 = gate_nand(n17, a[1]);
  auto n21 = gate_nand(n18, b[1]);
  auto n19 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n26 = gate_nand(n21, n20);
  auto n22 = gate_nand(b[2], a[1]);
  auto n23 = gate_not(n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  y[0] = gate_nand(n30, n29);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(b[1]);
  auto n2 = gate_nand(n1, b[2]);
  auto n52 = gate_not(b[2]);
  auto n67 = gate_nand(b[1], n52);
  auto n35 = gate_nand(n2, n67);
  auto n26 = gate_not(n35);
  auto n22 = gate_nand(n26, b[0]);
  auto n5 = gate_not(n22);
  auto n11 = gate_not(a[1]);
  auto n3 = gate_not(a[0]);
  auto n4 = gate_nand(n11, n3);
  auto n23 = gate_not(n4);
  auto n6 = gate_nand(n5, n23);
  auto n58 = gate_nand(a[2], n6);
  auto n57 = gate_not(n58);
  auto n9 = gate_nand(a[2], n52);
  auto n7 = gate_not(a[2]);
  auto n8 = gate_nand(b[2], n7);
  auto n68 = gate_nand(n9, n8);
  auto n10 = gate_nand(b[0], a[0]);
  auto n18 = gate_not(n10);
  auto n13 = gate_nand(a[0], a[2]);
  auto n12 = gate_not(n13);
  auto n15 = gate_nand(n12, n11);
  auto n14 = gate_nand(n13, a[1]);
  auto n34 = gate_nand(n15, n14);
  auto n16 = gate_not(n34);
  auto n17 = gate_nand(n35, n16);
  auto n40 = gate_nand(n18, n17);
  auto n19 = gate_not(b[0]);
  auto n33 = gate_nand(n52, n19);
  auto n20 = gate_nand(b[0], n34);
  auto n21 = gate_nand(n33, n20);
  auto n28 = gate_not(n21);
  auto n24 = gate_nand(n23, n22);
  auto n25 = gate_not(n24);
  auto n29 = gate_nand(a[2], n25);
  auto n42 = gate_not(n29);
  auto n27 = gate_nand(n26, n42);
  auto n31 = gate_nand(n28, n27);
  auto n30 = gate_nand(n35, n29);
  auto n46 = gate_nand(n31, n30);
  auto n32 = gate_nand(n46, n34);
  auto n38 = gate_nand(n33, n32);
  auto n66 = gate_not(n33);
  auto n36 = gate_nand(n66, n34);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  auto n44 = gate_not(n41);
  auto n43 = gate_nand(n46, n42);
  auto n70 = gate_nand(n44, n43);
  auto n45 = gate_not(n70);
  auto n75 = gate_nand(n68, n45);
  auto n51 = gate_not(n75);
  auto n71 = gate_not(n68);
  auto n49 = gate_nand(n46, n71);
  auto n47 = gate_not(n46);
  auto n48 = gate_nand(n68, n47);
  auto n62 = gate_nand(n49, n48);
  auto n50 = gate_not(n62);
  auto n63 = gate_nand(n51, n50);
  auto n55 = gate_nand(b[2], n63);
  auto n53 = gate_not(n63);
  auto n54 = gate_nand(n53, n52);
  auto n59 = gate_nand(n55, n54);
  auto n56 = gate_not(n59);
  auto n61 = gate_nand(n57, n56);
  auto n60 = gate_nand(n59, n58);
  y[2] = gate_nand(n61, n60);
  auto n64 = gate_nand(n75, n62);
  auto n65 = gate_nand(n64, n63);
  y[1] = gate_not(n65);
  auto n69 = gate_nand(n67, n66);
  auto n73 = gate_nand(n69, n68);
  auto n72 = gate_nand(n71, n70);
  auto n74 = gate_nand(n73, n72);
  auto n76 = gate_nand(n75, n74);
  y[0] = gate_not(n76);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(b[2]);
  auto n38 = gate_nand(n23, a[2]);
  auto n24 = gate_not(b[1]);
  auto n27 = gate_nand(a[1], n24);
  auto n25 = gate_not(a[1]);
  auto n26 = gate_nand(b[1], n25);
  auto n28 = gate_nand(n27, n26);
  auto n35 = gate_not(n28);
  auto n29 = gate_not(b[0]);
  auto n32 = gate_nand(a[0], n29);
  auto n30 = gate_not(a[0]);
  auto n31 = gate_nand(b[0], n30);
  auto n33 = gate_nand(n32, n31);
  auto n34 = gate_not(n33);
  auto n36 = gate_nand(n35, n34);
  auto n37 = gate_not(n36);
  auto n39 = gate_nand(n38, n37);
  auto n42 = gate_not(n39);
  auto n40 = gate_not(a[2]);
  auto n41 = gate_nand(n40, b[2]);
  auto n43 = gate_nand(n42, n41);
  y[0] = gate_not(n43);
}
template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[2]);
  auto n27 = gate_nand(n15, a[2]);
  auto n16 = gate_not(a[2]);
  auto n25 = gate_nand(n16, b[2]);
  auto n17 = gate_not(a[1]);
  auto n20 = gate_nand(n17, b[1]);
  auto n18 = gate_not(a[0]);
  auto n19 = gate_nand(b[0], n18);
  auto n23 = gate_nand(n20, n19);
  auto n21 = gate_not(b[1]);
  auto n22 = gate_nand(n21, a[1]);
  auto n24 = gate_nand(n23, n22);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_nand(n27, n26);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[2]);
  auto n30 = gate_nand(n18, b[2]);
  auto n19 = gate_not(b[2]);
  auto n28 = gate_nand(n19, a[2]);
  auto n20 = gate_not(a[1]);
  auto n23 = gate_nand(n20, b[1]);
  auto n21 = gate_not(a[0]);
  auto n22 = gate_nand(b[0], n21);
  auto n26 = gate_nand(n23, n22);
  auto n24 = gate_not(b[1]);
  auto n25 = gate_nand(n24, a[1]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto _gte_x_1_n44 = gate_nand(n30, n29);
  y[0] = gate_buf(_gte_x_1_n44);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[2]);
  auto n29 = gate_nand(n16, a[2]);
  auto n17 = gate_not(a[2]);
  auto n27 = gate_nand(n17, b[2]);
  auto n18 = gate_not(b[0]);
  auto n20 = gate_nand(a[0], n18);
  auto n19 = gate_not(n20);
  auto n25 = gate_nand(n19, a[1]);
  auto n21 = gate_not(a[1]);
  auto n23 = gate_nand(n21, n20);
  auto n22 = gate_not(b[1]);
  auto n24 = gate_nand(n23, n22);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_nand(n27, n26);
  y[0] = gate_nand(n29, n28);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[2]);
  auto n28 = gate_nand(n15, b[2]);
  auto n16 = gate_not(b[2]);
  auto n26 = gate_nand(n16, a[2]);
  auto n17 = gate_not(b[0]);
  auto n19 = gate_nand(a[0], n17);
  auto n18 = gate_not(n19);
  auto n24 = gate_nand(n18, a[1]);
  auto n20 = gate_not(a[1]);
  auto n22 = gate_nand(n20, n19);
  auto n21 = gate_not(b[1]);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto _gt_x_1_n44 = gate_nand(n28, n27);
  y[0] = gate_buf(_gt_x_1_n44);
}
template<> void $NameUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n10 = gate_not(a[1]);
  auto n11 = gate_nand(n10, y[0]);
  auto n15 = gate_nand(a[0], a[1]);
  auto n12 = gate_nand(n11, n15);
  y[1] = gate_not(n12);
  auto n14 = gate_not(n15);
  auto n13 = gate_not(a[2]);
  auto n17 = gate_nand(n14, n13);
  auto n16 = gate_nand(a[2], n15);
  y[2] = gate_nand(n17, n16);
}
template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(b[2]);
  auto n36 = gate_nand(n21, a[2]);
  auto n22 = gate_not(b[0]);
  auto n25 = gate_nand(a[0], n22);
  auto n23 = gate_not(a[0]);
  auto n24 = gate_nand(b[0], n23);
  auto n26 = gate_nand(n25, n24);
  auto n33 = gate_not(n26);
  auto n27 = gate_not(b[1]);
  auto n30 = gate_nand(a[1], n27);
  auto n28 = gate_not(a[1]);
  auto n29 = gate_nand(b[1], n28);
  auto n31 = gate_nand(n30, n29);
  auto n32 = gate_not(n31);
  auto n34 = gate_nand(n33, n32);
  auto n35 = gate_not(n34);
  auto n37 = gate_nand(n36, n35);
  auto n40 = gate_not(n37);
  auto n38 = gate_not(a[2]);
  auto n39 = gate_nand(n38, b[2]);
  auto _ne_x_1_n30 = gate_nand(n40, n39);
  y[0] = gate_buf(_ne_x_1_n30);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n15 = gate_not(a[0]);
  auto n14 = gate_not(a[1]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_not(n16);
  auto n17 = gate_not(a[2]);
  auto n23 = gate_nand(n18, n17);
  auto n20 = gate_nand(n23, b[0]);
  auto n24 = gate_not(n23);
  auto n19 = gate_nand(n24, c[0]);
  y[0] = gate_nand(n20, n19);
  auto n22 = gate_nand(n23, b[1]);
  auto n21 = gate_nand(n24, c[1]);
  y[1] = gate_nand(n22, n21);
  auto n26 = gate_nand(n23, b[2]);
  auto n25 = gate_nand(n24, c[2]);
  y[2] = gate_nand(n26, n25);
}
template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[2]);
  auto n30 = gate_nand(n18, b[2]);
  auto n19 = gate_not(b[2]);
  auto n28 = gate_nand(n19, a[2]);
  auto n20 = gate_not(b[1]);
  auto n23 = gate_nand(n20, a[1]);
  auto n21 = gate_not(b[0]);
  auto n22 = gate_nand(a[0], n21);
  auto n26 = gate_nand(n23, n22);
  auto n24 = gate_not(a[1]);
  auto n25 = gate_nand(n24, b[1]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto _lte_x_1_n7 = gate_nand(n30, n29);
  y[0] = gate_buf(_lte_x_1_n7);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[2]);
  auto n29 = gate_nand(n17, a[2]);
  auto n18 = gate_not(a[2]);
  auto n27 = gate_nand(n18, b[2]);
  auto n19 = gate_not(b[1]);
  auto n22 = gate_nand(n19, a[1]);
  auto n20 = gate_not(b[0]);
  auto n21 = gate_nand(a[0], n20);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_not(a[1]);
  auto n24 = gate_nand(n23, b[1]);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_nand(n27, n26);
  y[0] = gate_nand(n29, n28);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[0]);
  auto n14 = gate_not(a[1]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_not(n16);
  auto n17 = gate_not(a[2]);
  auto n25 = gate_nand(n18, n17);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_not(b[1]);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_not(n21);
  auto n22 = gate_not(b[2]);
  auto n24 = gate_nand(n23, n22);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_not(n26);
}
template<> void $NameUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(a[1]);
  auto n10 = gate_nand(n9, n8);
  auto n12 = gate_not(n10);
  auto n11 = gate_not(a[2]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_not(n13);
}
template<> void $NameUint<3>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(a[1]);
  auto n17 = gate_nand(n16, n15);
  auto n22 = gate_not(n17);
  auto n19 = gate_not(a[2]);
  auto n18 = gate_not(b[2]);
  auto n20 = gate_nand(n19, n18);
  auto n21 = gate_not(n20);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_not(n23);
  auto n24 = gate_not(b[1]);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_not(n26);
  auto n27 = gate_not(a[0]);
  y[0] = gate_nand(n28, n27);
}
template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[2]);
  auto n28 = gate_nand(n15, b[2]);
  auto n16 = gate_not(b[2]);
  auto n26 = gate_nand(n16, a[2]);
  auto n17 = gate_not(a[0]);
  auto n19 = gate_nand(b[0], n17);
  auto n18 = gate_not(n19);
  auto n24 = gate_nand(n18, b[1]);
  auto n20 = gate_not(b[1]);
  auto n22 = gate_nand(n20, n19);
  auto n21 = gate_not(a[1]);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto _lt_x_1_n7 = gate_nand(n28, n27);
  y[0] = gate_buf(_lt_x_1_n7);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[2]);
  auto n29 = gate_nand(n16, a[2]);
  auto n17 = gate_not(a[2]);
  auto n27 = gate_nand(n17, b[2]);
  auto n18 = gate_not(a[0]);
  auto n20 = gate_nand(b[0], n18);
  auto n19 = gate_not(n20);
  auto n25 = gate_nand(n19, b[1]);
  auto n21 = gate_not(b[1]);
  auto n23 = gate_nand(n21, n20);
  auto n22 = gate_not(a[1]);
  auto n24 = gate_nand(n23, n22);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_nand(n27, n26);
  y[0] = gate_nand(n29, n28);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_not(b[1]);
  auto n1 = gate_nand(n16, b[0]);
  auto n2 = gate_not(n1);
  auto n22 = gate_not(b[2]);
  auto n3 = gate_nand(n2, n22);
  auto n4 = gate_nand(n3, a[2]);
  auto n15 = gate_not(n4);
  auto n5 = gate_not(a[1]);
  auto n14 = gate_nand(n5, b[0]);
  auto n6 = gate_not(b[0]);
  auto n9 = gate_nand(n6, n16);
  auto n7 = gate_not(a[2]);
  auto n8 = gate_nand(n7, b[1]);
  auto n10 = gate_nand(n9, n8);
  auto n11 = gate_not(n10);
  auto n12 = gate_nand(n11, n22);
  auto n13 = gate_not(n12);
  auto n18 = gate_nand(n14, n13);
  auto n44 = gate_nand(n15, n18);
  auto n28 = gate_not(a[0]);
  auto n36 = gate_nand(b[0], n28);
  auto n21 = gate_nand(n16, n36);
  auto n17 = gate_not(n36);
  auto n19 = gate_nand(b[1], n17);
  auto n34 = gate_nand(n18, a[1]);
  auto n35 = gate_not(n34);
  auto n20 = gate_nand(n19, n35);
  auto n23 = gate_nand(n21, n20);
  auto n43 = gate_nand(n23, n22);
  auto n26 = gate_nand(n44, n43);
  auto n24 = gate_not(n23);
  auto n25 = gate_nand(b[2], n24);
  auto n27 = gate_nand(n26, n25);
  auto n42 = gate_not(n27);
  auto n30 = gate_nand(b[0], n42);
  auto n29 = gate_not(n30);
  auto n32 = gate_nand(n29, n28);
  auto n31 = gate_nand(n30, a[0]);
  y[0] = gate_nand(n32, n31);
  auto n33 = gate_nand(n42, b[1]);
  auto n40 = gate_nand(n34, n33);
  auto n37 = gate_nand(b[1], n35);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_nand(n42, n38);
  auto n41 = gate_nand(n40, n39);
  y[1] = gate_not(n41);
  auto n46 = gate_nand(n43, n42);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  y[2] = gate_not(n47);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(b[2]);
  auto n2 = gate_nand(b[1], n21);
  auto n23 = gate_not(b[1]);
  auto n1 = gate_nand(b[2], n23);
  auto n14 = gate_nand(n2, n1);
  auto n10 = gate_not(n14);
  auto n5 = gate_nand(b[0], a[0]);
  auto n3 = gate_not(b[0]);
  auto n4 = gate_nand(n3, n21);
  auto n13 = gate_nand(n5, n4);
  auto n41 = gate_nand(n10, n13);
  auto n7 = gate_nand(a[2], a[0]);
  auto n6 = gate_not(n7);
  auto n18 = gate_not(a[1]);
  auto n9 = gate_nand(n6, n18);
  auto n8 = gate_nand(a[1], n7);
  auto n12 = gate_nand(n9, n8);
  auto n11 = gate_nand(n10, b[0]);
  auto n46 = gate_nand(n12, n11);
  auto n16 = gate_nand(n41, n46);
  auto n15 = gate_not(n13);
  auto n42 = gate_nand(n15, n14);
  auto n32 = gate_nand(n16, n42);
  auto n30 = gate_not(n32);
  auto n17 = gate_not(a[0]);
  auto n33 = gate_nand(a[2], n17);
  auto n19 = gate_not(n33);
  auto n20 = gate_nand(n19, n18);
  auto n28 = gate_not(n20);
  auto n24 = gate_nand(n21, b[0]);
  auto n22 = gate_not(n24);
  auto n26 = gate_nand(n22, b[1]);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n31 = gate_nand(n28, n27);
  auto n29 = gate_not(n31);
  auto n58 = gate_nand(n30, n29);
  auto n44 = gate_nand(n32, n31);
  auto n37 = gate_nand(b[0], n44);
  auto n35 = gate_not(n37);
  auto n66 = gate_not(a[2]);
  auto n34 = gate_nand(a[0], n66);
  auto n36 = gate_nand(n34, n33);
  auto n40 = gate_nand(n35, n36);
  auto n38 = gate_not(n36);
  auto n39 = gate_nand(n38, n37);
  auto n65 = gate_nand(n40, n39);
  auto n59 = gate_not(n65);
  auto n43 = gate_nand(n42, n41);
  auto n45 = gate_not(n43);
  auto n52 = gate_nand(n45, n44);
  auto n51 = gate_not(n52);
  auto n49 = gate_nand(a[2], n46);
  auto n47 = gate_not(n46);
  auto n48 = gate_nand(n47, n66);
  auto n53 = gate_nand(n49, n48);
  auto n50 = gate_not(n53);
  auto n55 = gate_nand(n51, n50);
  auto n54 = gate_nand(n53, n52);
  auto n60 = gate_nand(n55, n54);
  auto n56 = gate_nand(n59, n60);
  auto n57 = gate_nand(n56, a[2]);
  y[2] = gate_nand(n58, n57);
  auto n67 = gate_nand(a[2], n59);
  auto n64 = gate_nand(n60, n67);
  auto n62 = gate_not(n67);
  auto n61 = gate_not(n60);
  auto n63 = gate_nand(n62, n61);
  y[1] = gate_nand(n64, n63);
  auto n68 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  y[0] = gate_not(n69);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n7);
  auto n3 = gate_nand(a[1], b[0]);
  auto n1 = gate_not(n3);
  auto n2 = gate_nand(b[1], a[0]);
  auto n6 = gate_nand(n1, n2);
  auto n4 = gate_not(n2);
  auto n5 = gate_nand(n4, n3);
  y[1] = gate_nand(n6, n5);
  auto n13 = gate_nand(b[1], a[1]);
  auto n8 = gate_nand(a[0], n13);
  auto n9 = gate_nand(n8, n7);
  auto n17 = gate_nand(n9, b[2]);
  auto n11 = gate_not(b[0]);
  auto n10 = gate_not(b[2]);
  auto n12 = gate_nand(n11, n10);
  auto n15 = gate_nand(n12, a[0]);
  auto n14 = gate_not(n13);
  auto n16 = gate_nand(n15, n14);
  auto n20 = gate_nand(n17, n16);
  auto n18 = gate_not(n20);
  auto n19 = gate_nand(a[2], b[0]);
  auto n23 = gate_nand(n18, n19);
  auto n21 = gate_not(n19);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  y[2] = gate_not(n24);
}
template<> void $NameUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_nand(a[0], a[1]);
  auto n5 = gate_not(n4);
  auto n6 = gate_nand(a[2], n5);
  y[0] = gate_not(n6);
}
template<> void $NameUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_nand(a[0], a[1]);
  auto n5 = gate_not(n4);
  y[0] = gate_nand(a[2], n5);
}
template<> void $NameUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(a[1]);
  auto n10 = gate_nand(n9, n8);
  auto n12 = gate_not(n10);
  auto n11 = gate_not(a[2]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_not(n13);
}
template<> void $NameUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[1]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_not(n8);
  auto n9 = gate_not(a[2]);
  y[0] = gate_nand(n10, n9);
}
template<> void $NameUint<3>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[2]);
  auto n14 = gate_nand(a[0], n11);
  auto n12 = gate_not(a[0]);
  auto n13 = gate_nand(a[2], n12);
  auto n17 = gate_nand(n14, n13);
  auto n16 = gate_not(n17);
  auto n15 = gate_not(a[1]);
  auto n19 = gate_nand(n16, n15);
  auto n18 = gate_nand(n17, a[1]);
  y[0] = gate_nand(n19, n18);
}
template<> void $NameUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_not(a[2]);
  auto n13 = gate_nand(a[0], n10);
  auto n11 = gate_not(a[0]);
  auto n12 = gate_nand(a[2], n11);
  auto n16 = gate_nand(n13, n12);
  auto n14 = gate_not(n16);
  auto n18 = gate_nand(n14, a[1]);
  auto n15 = gate_not(a[1]);
  auto n17 = gate_nand(n16, n15);
  y[0] = gate_nand(n18, n17);
}
template<> void $NameUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n36 = gate_not(b[2]);
  auto n33 = gate_not(b[1]);
  auto n25 = gate_nand(n36, n33);
  auto n40 = gate_not(n25);
  auto n39 = gate_not(b[0]);
  auto n26 = gate_nand(a[0], n39);
  auto n27 = gate_not(n26);
  auto n28 = gate_nand(n40, n27);
  y[0] = gate_not(n28);
  auto n30 = gate_nand(n39, a[1]);
  auto n29 = gate_nand(b[0], a[0]);
  auto n31 = gate_nand(n30, n29);
  auto n32 = gate_nand(n40, n31);
  y[1] = gate_not(n32);
  auto n35 = gate_nand(n33, a[2]);
  auto n34 = gate_nand(b[1], a[0]);
  auto n37 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n43 = gate_nand(n39, n38);
  auto n41 = gate_nand(a[1], n40);
  auto n42 = gate_nand(n41, b[0]);
  auto n44 = gate_nand(n43, n42);
  y[2] = gate_not(n44);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n34 = gate_not(b[1]);
  auto n25 = gate_nand(a[1], n34);
  auto n26 = gate_not(n25);
  auto n31 = gate_nand(n26, b[0]);
  auto n40 = gate_not(b[0]);
  auto n28 = gate_nand(n34, a[0]);
  auto n27 = gate_nand(b[1], a[2]);
  auto n29 = gate_nand(n28, n27);
  auto n30 = gate_nand(n40, n29);
  auto n32 = gate_nand(n31, n30);
  auto n35 = gate_not(b[2]);
  auto n33 = gate_nand(n32, n35);
  y[0] = gate_not(n33);
  auto n36 = gate_nand(n35, n34);
  auto n44 = gate_not(n36);
  auto n37 = gate_nand(a[2], n44);
  auto n38 = gate_not(n37);
  auto n39 = gate_nand(n38, n40);
  y[2] = gate_not(n39);
  auto n42 = gate_nand(n40, a[1]);
  auto n41 = gate_nand(b[0], a[2]);
  auto n43 = gate_nand(n42, n41);
  auto n45 = gate_nand(n44, n43);
  y[1] = gate_not(n45);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n20 = gate_not(b[1]);
  auto n19 = gate_not(b[2]);
  auto n25 = gate_nand(n20, n19);
  auto n29 = gate_not(n25);
  auto n26 = gate_not(b[0]);
  auto n21 = gate_nand(n29, n26);
  auto n24 = gate_nand(n21, a[2]);
  auto n22 = gate_not(n21);
  auto n23 = gate_nand(n22, a[1]);
  y[1] = gate_nand(n24, n23);
  auto n32 = gate_nand(n25, a[2]);
  auto n28 = gate_nand(n26, a[0]);
  auto n27 = gate_nand(b[0], a[1]);
  auto n30 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  y[0] = gate_nand(n32, n31);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(b[0]);
  auto n27 = gate_nand(n25, a[0]);
  auto n26 = gate_not(a[0]);
  auto n33 = gate_nand(b[0], n26);
  y[0] = gate_nand(n27, n33);
  auto n28 = gate_not(a[1]);
  auto n30 = gate_nand(n28, b[1]);
  auto n29 = gate_not(b[1]);
  auto n37 = gate_nand(a[1], n29);
  auto n32 = gate_nand(n30, n37);
  auto n31 = gate_not(n33);
  auto n35 = gate_nand(n32, n31);
  auto n34 = gate_not(n32);
  auto n38 = gate_nand(n34, n33);
  auto n36 = gate_nand(n35, n38);
  y[1] = gate_not(n36);
  auto n45 = gate_nand(n38, n37);
  auto n44 = gate_not(n45);
  auto n39 = gate_not(b[2]);
  auto n42 = gate_nand(a[2], n39);
  auto n40 = gate_not(a[2]);
  auto n41 = gate_nand(b[2], n40);
  auto n46 = gate_nand(n42, n41);
  auto n43 = gate_not(n46);
  auto n48 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  y[2] = gate_nand(n48, n47);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n12 = gate_nand(a[1], a[0]);
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[1]);
  auto n16 = gate_nand(n11, n10);
  auto n13 = gate_nand(n12, n16);
  y[1] = gate_not(n13);
  auto n14 = gate_not(n16);
  auto n18 = gate_nand(n14, a[2]);
  auto n15 = gate_not(a[2]);
  auto n17 = gate_nand(n16, n15);
  y[2] = gate_nand(n18, n17);
}
