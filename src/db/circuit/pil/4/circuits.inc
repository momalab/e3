template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_nand(b[2], a[2]);
  auto n17 = gate_and(b[0], a[0]);
  auto n16 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n17, n16);
  auto n21 = gate_xor(b[2], a[2]);
  auto n19 = gate_and(b[1], a[1]);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  y[2] = gate_xor(n21, n20);
  auto n24 = gate_not(b[3]);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n12);
  auto n15 = gate_nand(n21, n20);
  auto n22 = gate_and(n14, n15);
  auto n23 = gate_xor(a[3], n22);
  y[3] = gate_xor(n24, n23);
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
template<> void $NameUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n16 = gate_and(a[1], a[2]);
  auto n17 = gate_and(N0, a[3]);
  y[2] = gate_and(n16, n17);
  auto n21 = gate_not(y[2]);
  auto n19 = gate_not(n16);
  auto n18 = gate_not(n17);
  auto n20 = gate_and(n19, n18);
  auto n23 = gate_xor(a[1], a[2]);
  auto n22 = gate_xor(N0, a[3]);
  y[0] = gate_xor(n23, n22);
  auto n15 = gate_nand(n23, n22);
  auto n14 = gate_nand(n20, n15);
  y[1] = gate_and(n21, n14);
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
template<> void $NameUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_xor(b[1], a[1]);
  auto n9 = gate_and(b[0], a[0]);
  y[1] = gate_xor(n10, n9);
  auto n12 = gate_and(b[1], a[1]);
  auto n11 = gate_and(n10, n9);
  auto n13 = gate_or(n12, n11);
  auto n14 = gate_xor(b[2], a[2]);
  y[2] = gate_xor(n13, n14);
  auto _add_x_1_n12 = gate_xor(b[0], a[0]);
  auto n16 = gate_and(b[2], a[2]);
  auto n15 = gate_and(n14, n13);
  auto _add_x_1_n14 = gate_or(n16, n15);
  y[3] = gate_buf(_add_x_1_n14);
  y[0] = gate_buf(_add_x_1_n12);
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
  auto n28 = gate_not(b[1]);
  auto n47 = gate_not(b[3]);
  auto n40 = gate_not(b[2]);
  auto n15 = gate_and(n47, n40);
  auto n13 = gate_and(n28, n15);
  auto n14 = gate_not(a[3]);
  auto n16 = gate_not(a[2]);
  auto n18 = gate_not(a[1]);
  auto n26 = gate_not(a[0]);
  auto n29 = gate_and(b[0], n26);
  auto n30 = gate_not(n29);
  auto n2 = gate_nand(b[0], n18);
  auto n4 = gate_nand(b[0], n16);
  auto n8 = gate_nand(b[0], n14);
  auto n9 = gate_nand(b[1], n14);
  y[3] = gate_and(n13, n8);
  auto n17 = gate_and(n15, n9);
  y[2] = gate_and(n17, n4);
  auto n21 = gate_not(y[2]);
  auto n20 = gate_not(y[3]);
  auto n22 = gate_and(n21, n20);
  auto n48 = gate_and(a[3], n22);
  auto n45 = gate_not(n48);
  auto n49 = gate_and(n48, n47);
  auto n1 = gate_nand(n17, b[0]);
  auto n5 = gate_nand(b[3], n45);
  auto n10 = gate_nand(n45, b[2]);
  auto n12 = gate_nand(n48, n40);
  auto n34 = gate_and(a[2], n1);
  auto n35 = gate_xor(n34, b[1]);
  auto n19 = gate_not(n35);
  auto n36 = gate_and(n35, n2);
  auto n3 = gate_nand(n19, n2);
  auto n11 = gate_nand(n34, n28);
  auto n23 = gate_and(n11, n3);
  auto n7 = gate_nand(n23, n12);
  auto n24 = gate_and(n7, n10);
  y[1] = gate_and(n47, n24);
  auto n25 = gate_and(y[1], b[0]);
  auto n31 = gate_xor(n25, a[1]);
  auto n27 = gate_not(n31);
  auto n32 = gate_and(n31, n30);
  auto n50 = gate_not(y[1]);
  auto n38 = gate_and(n34, n50);
  auto n37 = gate_and(n36, y[1]);
  auto n41 = gate_or(n38, n37);
  auto n51 = gate_and(n50, n49);
  auto n6 = gate_nand(n27, n29);
  auto n33 = gate_and(n28, n6);
  auto n42 = gate_or(n33, n32);
  auto n39 = gate_or(n42, n41);
  auto n44 = gate_and(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n46 = gate_or(n44, n43);
  auto n52 = gate_and(n46, n5);
  y[0] = gate_or(n52, n51);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n69 = gate_xor(a[3], b[3]);
  auto n11 = gate_not(a[1]);
  auto n10 = gate_not(a[0]);
  auto n19 = gate_and(n11, n10);
  auto n12 = gate_not(a[2]);
  auto n13 = gate_and(n19, n12);
  auto n37 = gate_and(a[3], n13);
  auto n18 = gate_not(b[3]);
  auto n68 = gate_xor(b[1], n18);
  auto n15 = gate_and(n37, n68);
  auto n51 = gate_xor(b[2], n18);
  auto n14 = gate_and(n51, b[0]);
  auto n57 = gate_and(n15, n14);
  auto n16 = gate_not(n57);
  auto n28 = gate_and(n37, n16);
  auto n24 = gate_and(n28, n68);
  auto n17 = gate_not(b[0]);
  auto n66 = gate_and(n18, n17);
  auto n20 = gate_not(n19);
  auto n21 = gate_and(n20, a[3]);
  auto n32 = gate_xor(n21, a[2]);
  auto n22 = gate_and(b[0], n32);
  auto n23 = gate_or(n66, n22);
  auto n26 = gate_or(n24, n23);
  auto n25 = gate_or(n68, n37);
  auto n27 = gate_and(n26, n25);
  auto n56 = gate_and(n51, n27);
  auto n31 = gate_not(n56);
  auto n40 = gate_and(n28, n31);
  auto n29 = gate_and(a[0], a[3]);
  auto n41 = gate_xor(n29, a[1]);
  auto n30 = gate_and(b[0], n41);
  auto n34 = gate_or(n30, n66);
  auto n49 = gate_and(n32, n31);
  auto n33 = gate_or(n49, n68);
  auto n36 = gate_and(n34, n33);
  auto n35 = gate_and(n49, n68);
  auto n39 = gate_or(n36, n35);
  auto n38 = gate_or(n37, n51);
  auto n42 = gate_and(b[0], a[0]);
  auto n45 = gate_or(n66, n42);
  auto n43 = gate_or(n45, n68);
  auto n46 = gate_and(n45, n68);
  auto n60 = gate_xor(n69, n56);
  auto n58 = gate_xor(n69, n57);
  auto n65 = gate_not(b[2]);
  auto n67 = gate_and(n66, n65);
  auto n1 = gate_nand(n68, n67);
  auto n3 = gate_nand(n51, n40);
  auto n7 = gate_nand(n39, n38);
  auto n8 = gate_nand(n69, n1);
  auto n48 = gate_and(n7, n3);
  auto n55 = gate_not(n48);
  auto n52 = gate_and(n49, n48);
  auto n62 = gate_xor(n69, n55);
  auto n2 = gate_nand(n40, n48);
  auto n4 = gate_nand(b[0], n55);
  auto n44 = gate_and(n41, n4);
  auto n47 = gate_and(n44, n43);
  auto n53 = gate_or(n47, n46);
  auto n50 = gate_or(n53, n52);
  auto n5 = gate_nand(n53, n52);
  auto n6 = gate_nand(n51, n50);
  auto n54 = gate_and(n6, n5);
  auto n64 = gate_and(n2, n54);
  auto n63 = gate_and(n69, n64);
  auto n61 = gate_and(n63, n62);
  auto n59 = gate_and(n61, n60);
  y[3] = gate_xor(n59, n58);
  y[2] = gate_xor(n61, n60);
  y[1] = gate_xor(n63, n62);
  auto n71 = gate_not(n63);
  auto n70 = gate_xor(n69, n64);
  auto n9 = gate_nand(n70, n8);
  y[0] = gate_and(n71, n9);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_xnor(a[0], b[0]);
  auto n12 = gate_xnor(a[1], b[1]);
  auto n13 = gate_not(a[3]);
  auto n16 = gate_xor(n13, b[3]);
  auto n14 = gate_not(b[2]);
  auto n15 = gate_xor(n14, a[2]);
  auto n17 = gate_and(n16, n15);
  auto n18 = gate_and(n17, n11);
  auto _eq_x_1_n30 = gate_and(n18, n12);
  y[0] = gate_buf(_eq_x_1_n30);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(a[0]);
  auto n33 = gate_and(b[0], n30);
  auto n32 = gate_not(n33);
  auto n31 = gate_not(b[1]);
  auto n35 = gate_and(n32, n31);
  auto n36 = gate_not(a[2]);
  auto n38 = gate_not(b[2]);
  auto n40 = gate_not(b[3]);
  auto n26 = gate_nand(b[2], n36);
  auto n28 = gate_nand(a[2], n38);
  auto n29 = gate_nand(n33, b[1]);
  auto n34 = gate_and(a[1], n29);
  auto n37 = gate_or(n35, n34);
  auto n25 = gate_nand(n37, n26);
  auto n39 = gate_and(n25, n28);
  auto n41 = gate_not(n39);
  auto n42 = gate_and(n41, n40);
  auto n27 = gate_nand(n39, b[3]);
  auto n43 = gate_and(a[3], n27);
  auto _gte_x_1_n29 = gate_or(n43, n42);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(a[0]);
  auto n33 = gate_and(b[0], n30);
  auto n32 = gate_not(n33);
  auto n31 = gate_not(b[1]);
  auto n35 = gate_and(n32, n31);
  auto n36 = gate_not(a[2]);
  auto n38 = gate_not(b[2]);
  auto n40 = gate_not(a[3]);
  auto n26 = gate_nand(b[2], n36);
  auto n27 = gate_nand(a[2], n38);
  auto n29 = gate_nand(n33, b[1]);
  auto n34 = gate_and(a[1], n29);
  auto n37 = gate_or(n35, n34);
  auto n25 = gate_nand(n37, n26);
  auto n39 = gate_and(n25, n27);
  auto n41 = gate_not(n39);
  auto n42 = gate_and(n41, n40);
  auto n28 = gate_nand(n39, a[3]);
  auto n43 = gate_and(b[3], n28);
  auto _gte_x_1_n29 = gate_or(n43, n42);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n32 = gate_not(b[0]);
  auto n34 = gate_and(n32, a[0]);
  auto n33 = gate_not(a[1]);
  auto n35 = gate_not(b[1]);
  auto n36 = gate_and(a[1], n35);
  auto n38 = gate_not(a[2]);
  auto n40 = gate_not(b[2]);
  auto n42 = gate_not(b[3]);
  auto n27 = gate_nand(b[1], n33);
  auto n28 = gate_nand(b[2], n38);
  auto n30 = gate_nand(a[2], n40);
  auto n37 = gate_and(n34, n27);
  auto n39 = gate_or(n37, n36);
  auto n29 = gate_nand(n39, n28);
  auto n41 = gate_and(n29, n30);
  auto n43 = gate_not(n41);
  auto n44 = gate_and(n43, n42);
  auto n31 = gate_nand(n41, b[3]);
  auto n45 = gate_and(a[3], n31);
  auto _gt_x_1_n29 = gate_or(n45, n44);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n32 = gate_not(b[0]);
  auto n34 = gate_and(n32, a[0]);
  auto n33 = gate_not(a[1]);
  auto n35 = gate_not(b[1]);
  auto n36 = gate_and(a[1], n35);
  auto n38 = gate_not(a[2]);
  auto n40 = gate_not(b[2]);
  auto n42 = gate_not(a[3]);
  auto n27 = gate_nand(b[1], n33);
  auto n28 = gate_nand(b[2], n38);
  auto n29 = gate_nand(a[2], n40);
  auto n37 = gate_and(n34, n27);
  auto n39 = gate_or(n37, n36);
  auto n31 = gate_nand(n39, n28);
  auto n41 = gate_and(n31, n29);
  auto n43 = gate_not(n41);
  auto n44 = gate_and(n43, n42);
  auto n30 = gate_nand(n41, a[3]);
  auto n45 = gate_and(b[3], n30);
  auto _gt_x_1_n29 = gate_or(n45, n44);
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
  auto n13 = gate_xnor(b[3], a[3]);
  auto n15 = gate_xnor(b[2], a[2]);
  auto n16 = gate_not(a[0]);
  auto n19 = gate_xor(n16, b[0]);
  auto n17 = gate_not(a[1]);
  auto n18 = gate_xor(n17, b[1]);
  auto n20 = gate_and(n19, n18);
  auto n21 = gate_and(n20, n15);
  y[0] = gate_nand(n21, n13);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n15 = gate_not(a[3]);
  auto n20 = gate_and(n16, n15);
  auto n18 = gate_not(a[2]);
  auto n17 = gate_not(a[0]);
  auto n19 = gate_and(n18, n17);
  auto n26 = gate_and(n20, n19);
  y[0] = gate_mux(b[0], c[0], n26);
  auto n25 = gate_not(n26);
  auto n22 = gate_and(b[1], n25);
  auto n21 = gate_and(n26, c[1]);
  y[1] = gate_or(n22, n21);
  auto n24 = gate_and(b[2], n25);
  auto n23 = gate_and(n26, c[2]);
  y[2] = gate_or(n24, n23);
  auto n28 = gate_and(b[3], n25);
  auto n27 = gate_and(n26, c[3]);
  y[3] = gate_or(n28, n27);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(a[1]);
  auto n32 = gate_not(b[0]);
  auto n34 = gate_not(b[2]);
  auto n35 = gate_not(b[1]);
  auto n37 = gate_not(a[2]);
  auto n38 = gate_and(b[2], n37);
  auto n40 = gate_not(b[3]);
  auto n42 = gate_not(a[3]);
  auto n43 = gate_and(b[3], n42);
  auto n27 = gate_nand(b[1], n31);
  auto n28 = gate_nand(a[2], n34);
  auto n29 = gate_nand(a[3], n40);
  auto n30 = gate_nand(a[1], n35);
  auto n33 = gate_and(a[0], n27);
  auto n26 = gate_nand(n33, n32);
  auto n36 = gate_and(n26, n28);
  auto n39 = gate_and(n36, n30);
  auto n41 = gate_or(n39, n38);
  auto n44 = gate_and(n41, n29);
  y[0] = gate_or(n44, n43);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(a[1]);
  auto n32 = gate_not(b[0]);
  auto n34 = gate_not(b[2]);
  auto n35 = gate_not(b[1]);
  auto n37 = gate_not(a[2]);
  auto n38 = gate_and(b[2], n37);
  auto n40 = gate_not(a[3]);
  auto n42 = gate_not(b[3]);
  auto n43 = gate_and(a[3], n42);
  auto n26 = gate_nand(b[1], n31);
  auto n27 = gate_nand(b[3], n40);
  auto n29 = gate_nand(a[2], n34);
  auto n30 = gate_nand(a[1], n35);
  auto n33 = gate_and(a[0], n26);
  auto n28 = gate_nand(n33, n32);
  auto n36 = gate_and(n28, n29);
  auto n39 = gate_and(n36, n30);
  auto n41 = gate_or(n39, n38);
  auto n44 = gate_and(n41, n27);
  y[0] = gate_or(n44, n43);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[1]);
  auto n19 = gate_not(a[3]);
  auto n24 = gate_and(n20, n19);
  auto n22 = gate_not(a[2]);
  auto n21 = gate_not(a[0]);
  auto n23 = gate_and(n22, n21);
  auto n30 = gate_not(b[2]);
  auto n26 = gate_not(b[3]);
  auto n25 = gate_not(b[0]);
  auto n28 = gate_and(n26, n25);
  auto n27 = gate_not(b[1]);
  auto n29 = gate_and(n28, n27);
  auto n17 = gate_nand(n30, n29);
  auto n18 = gate_nand(n24, n23);
  y[0] = gate_and(n18, n17);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[1]);
  auto n8 = gate_not(a[3]);
  auto n13 = gate_and(n9, n8);
  auto n11 = gate_not(a[2]);
  auto n10 = gate_not(a[0]);
  auto n12 = gate_and(n11, n10);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[1]);
  auto n17 = gate_not(a[0]);
  auto n22 = gate_and(n18, n17);
  auto n20 = gate_not(a[3]);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_and(n20, n19);
  auto n24 = gate_and(n22, n21);
  auto n23 = gate_not(b[3]);
  auto n30 = gate_and(n24, n23);
  auto n26 = gate_not(b[2]);
  auto n25 = gate_not(b[1]);
  auto n28 = gate_and(n26, n25);
  auto n27 = gate_not(b[0]);
  auto n29 = gate_and(n28, n27);
  y[0] = gate_nand(n30, n29);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(a[2]);
  auto n32 = gate_not(b[2]);
  auto n33 = gate_not(b[1]);
  auto n34 = gate_not(a[1]);
  auto n37 = gate_and(b[1], n34);
  auto n35 = gate_not(a[0]);
  auto n36 = gate_and(b[0], n35);
  auto n38 = gate_or(n37, n36);
  auto n41 = gate_not(a[3]);
  auto n26 = gate_nand(b[2], n31);
  auto n28 = gate_nand(a[2], n32);
  auto n30 = gate_nand(a[1], n33);
  auto n39 = gate_and(n28, n30);
  auto n27 = gate_nand(n39, n38);
  auto n40 = gate_and(n26, n27);
  auto n42 = gate_not(n40);
  auto n43 = gate_and(n42, n41);
  auto n29 = gate_nand(n40, a[3]);
  auto n44 = gate_and(b[3], n29);
  y[0] = gate_or(n44, n43);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(a[2]);
  auto n32 = gate_not(b[2]);
  auto n33 = gate_not(b[1]);
  auto n34 = gate_not(a[1]);
  auto n37 = gate_and(b[1], n34);
  auto n35 = gate_not(a[0]);
  auto n36 = gate_and(b[0], n35);
  auto n38 = gate_or(n37, n36);
  auto n41 = gate_not(b[3]);
  auto n26 = gate_nand(b[2], n31);
  auto n29 = gate_nand(a[1], n33);
  auto n30 = gate_nand(a[2], n32);
  auto n39 = gate_and(n30, n29);
  auto n27 = gate_nand(n39, n38);
  auto n40 = gate_and(n26, n27);
  auto n42 = gate_not(n40);
  auto n43 = gate_and(n42, n41);
  auto n28 = gate_nand(n40, b[3]);
  auto n44 = gate_and(a[3], n28);
  y[0] = gate_or(n44, n43);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n49 = gate_not(b[3]);
  auto n52 = gate_not(b[2]);
  auto n28 = gate_and(n49, n52);
  auto n37 = gate_not(b[1]);
  auto n11 = gate_and(n28, n37);
  auto n12 = gate_not(b[0]);
  auto n13 = gate_not(a[3]);
  auto n15 = gate_not(a[2]);
  auto n18 = gate_not(a[1]);
  auto n33 = gate_and(b[0], n18);
  auto n19 = gate_not(n33);
  auto n38 = gate_not(a[0]);
  auto n57 = gate_and(b[0], n38);
  auto n39 = gate_not(n57);
  auto n58 = gate_xor(n57, b[1]);
  auto n1 = gate_nand(n37, n12);
  auto n3 = gate_nand(b[0], n15);
  auto n4 = gate_nand(b[1], n13);
  auto n7 = gate_nand(b[0], n11);
  auto n17 = gate_and(a[3], n7);
  auto n14 = gate_and(n1, n4);
  auto n16 = gate_and(n28, n14);
  auto n6 = gate_nand(n16, n3);
  auto n27 = gate_and(n17, n6);
  auto n31 = gate_and(a[2], n6);
  auto n22 = gate_and(n31, n37);
  auto n20 = gate_xor(n31, n37);
  auto n21 = gate_and(n20, n19);
  auto n24 = gate_or(n22, n21);
  auto n23 = gate_xor(n24, n52);
  auto n46 = gate_not(n27);
  auto n25 = gate_xor(b[2], n46);
  auto n26 = gate_and(n25, n24);
  auto n30 = gate_and(n49, n26);
  auto n29 = gate_and(n28, n27);
  auto n35 = gate_or(n30, n29);
  auto n32 = gate_and(n35, b[1]);
  auto n34 = gate_xor(n32, n31);
  auto n36 = gate_and(n35, b[0]);
  auto n59 = gate_xor(n36, a[1]);
  auto n42 = gate_and(n37, n59);
  auto n40 = gate_xor(n37, n59);
  auto n41 = gate_and(n40, n39);
  auto n53 = gate_or(n42, n41);
  auto n54 = gate_xor(n53, n52);
  auto n2 = gate_nand(b[3], n46);
  auto n5 = gate_nand(n23, n49);
  auto n8 = gate_nand(n35, n33);
  auto n51 = gate_and(n27, n5);
  auto n55 = gate_and(n34, n8);
  auto n45 = gate_and(n52, n55);
  auto n43 = gate_xor(n52, n55);
  auto n44 = gate_and(n43, n53);
  auto n50 = gate_or(n45, n44);
  auto n48 = gate_and(n50, n2);
  auto n47 = gate_and(n49, n51);
  auto n61 = gate_or(n48, n47);
  auto n56 = gate_and(n54, n61);
  y[2] = gate_xor(n56, n55);
  auto n60 = gate_and(n58, n61);
  y[1] = gate_xor(n60, n59);
  auto n62 = gate_and(n61, b[0]);
  y[0] = gate_xor(n62, a[0]);
  auto n9 = gate_nand(n50, n49);
  auto n10 = gate_nand(n61, n9);
  y[3] = gate_and(n51, n10);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(a[0], b[0]);
  auto n58 = gate_xor(b[3], b[2]);
  auto n16 = gate_not(a[1]);
  auto n15 = gate_not(a[0]);
  auto n20 = gate_and(n16, n15);
  auto n17 = gate_not(n20);
  auto n18 = gate_and(n17, a[3]);
  auto n29 = gate_xor(n18, a[2]);
  auto n47 = gate_not(n58);
  auto n24 = gate_not(b[3]);
  auto n51 = gate_xor(b[1], n24);
  auto n19 = gate_and(b[0], n51);
  auto n21 = gate_not(a[2]);
  auto n26 = gate_not(n29);
  auto n25 = gate_not(b[0]);
  auto n30 = gate_and(a[3], a[0]);
  auto n49 = gate_xor(a[1], n30);
  auto n65 = gate_not(n51);
  auto n63 = gate_xor(a[0], a[3]);
  auto n3 = gate_nand(n47, n19);
  auto n4 = gate_nand(n25, n24);
  auto n5 = gate_nand(n26, n4);
  auto n7 = gate_nand(b[0], n49);
  auto n22 = gate_and(n20, n3);
  auto n23 = gate_and(n22, n21);
  auto n37 = gate_and(a[3], n23);
  auto n27 = gate_xor(n37, n51);
  auto n28 = gate_and(n27, n5);
  auto n35 = gate_and(n28, n47);
  auto n45 = gate_and(n4, n7);
  auto n31 = gate_not(n45);
  auto n36 = gate_not(n35);
  auto n40 = gate_and(n37, n36);
  auto n41 = gate_and(n40, n47);
  auto n66 = gate_and(n4, n6);
  auto n52 = gate_not(n66);
  auto n67 = gate_xor(n66, n65);
  auto n8 = gate_nand(n35, b[0]);
  auto n43 = gate_and(n29, n8);
  auto n34 = gate_and(n43, n51);
  auto n32 = gate_xor(n43, n51);
  auto n33 = gate_and(n32, n31);
  auto n39 = gate_or(n34, n33);
  auto n38 = gate_xor(n58, n39);
  auto n74 = gate_and(n38, n40);
  auto n56 = gate_not(n74);
  auto n42 = gate_and(n39, n47);
  auto n48 = gate_or(n42, n41);
  auto n44 = gate_and(n48, n65);
  auto n46 = gate_xor(n44, n43);
  auto n50 = gate_and(n48, b[0]);
  auto n68 = gate_xor(n50, n49);
  auto n53 = gate_xor(n68, n51);
  auto n9 = gate_nand(n53, n52);
  auto n10 = gate_nand(n68, n51);
  auto n11 = gate_nand(n48, n45);
  auto n59 = gate_and(n46, n11);
  auto n55 = gate_xor(n47, n59);
  auto n57 = gate_and(n10, n9);
  auto n54 = gate_not(n57);
  auto n12 = gate_nand(n55, n54);
  auto n13 = gate_nand(n47, n59);
  auto n72 = gate_and(n13, n12);
  auto n73 = gate_not(n72);
  auto n2 = gate_nand(n56, n72);
  auto n14 = gate_nand(n74, n73);
  auto n60 = gate_and(n2, n58);
  auto n61 = gate_xor(n60, n59);
  auto n64 = gate_and(b[0], n2);
  auto n82 = gate_xor(n64, n63);
  auto n71 = gate_and(a[3], n82);
  auto n69 = gate_and(n67, n2);
  auto n80 = gate_xor(n69, n68);
  auto n70 = gate_not(n80);
  auto n77 = gate_and(n71, n70);
  auto n75 = gate_and(a[3], n14);
  auto n79 = gate_not(n82);
  auto n81 = gate_and(n79, a[3]);
  y[1] = gate_xor(n81, n80);
  y[0] = gate_xor(a[3], n82);
  auto n1 = gate_nand(n2, n57);
  auto n62 = gate_and(n1, n61);
  auto n78 = gate_xor(a[3], n62);
  auto n76 = gate_and(n78, n77);
  y[3] = gate_xor(n76, n75);
  y[2] = gate_xor(n78, n77);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
  auto n4 = gate_and(a[1], b[0]);
  auto n10 = gate_and(a[0], b[1]);
  y[1] = gate_xor(n4, n10);
  auto n8 = gate_and(n4, n10);
  auto n6 = gate_and(b[2], a[0]);
  auto n5 = gate_and(b[1], a[1]);
  auto n7 = gate_xor(n6, n5);
  auto n16 = gate_or(n8, n7);
  auto n17 = gate_and(b[0], a[2]);
  auto n11 = gate_not(n10);
  auto n12 = gate_and(n11, b[2]);
  auto n14 = gate_and(a[2], b[1]);
  auto n13 = gate_and(a[3], b[0]);
  auto n15 = gate_xor(n14, n13);
  auto n19 = gate_and(a[0], b[3]);
  auto n1 = gate_nand(n17, n16);
  auto n2 = gate_nand(a[1], n12);
  auto n3 = gate_nand(n8, n7);
  auto n9 = gate_and(n3, n16);
  y[2] = gate_xor(n9, n17);
  auto n21 = gate_xor(n2, n15);
  auto n18 = gate_and(n1, n3);
  auto n20 = gate_xor(n19, n18);
  y[3] = gate_xor(n21, n20);
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
  auto n9 = gate_not(a[1]);
  auto n8 = gate_not(a[3]);
  auto n13 = gate_and(n9, n8);
  auto n11 = gate_not(a[2]);
  auto n10 = gate_not(a[0]);
  auto n12 = gate_and(n11, n10);
  y[0] = gate_and(n13, n12);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n9 = gate_not(a[3]);
  auto n14 = gate_and(n10, n9);
  auto n12 = gate_not(a[2]);
  auto n11 = gate_not(a[0]);
  auto n13 = gate_and(n12, n11);
  y[0] = gate_nand(n14, n13);
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
  auto n41 = gate_not(b[2]);
  auto n40 = gate_not(b[3]);
  auto n45 = gate_and(n41, n40);
  auto n42 = gate_not(b[1]);
  auto n46 = gate_and(n45, n42);
  auto n50 = gate_not(b[0]);
  auto n56 = gate_and(n46, n50);
  auto _ash_1_n16 = gate_and(a[0], n56);
  auto n44 = gate_and(a[1], n50);
  auto n43 = gate_and(b[0], a[0]);
  auto n53 = gate_or(n44, n43);
  y[1] = gate_and(n46, n53);
  auto n55 = gate_and(b[0], n46);
  auto n52 = gate_and(a[1], n55);
  auto n54 = gate_and(b[1], n45);
  auto n48 = gate_and(a[0], n54);
  auto n47 = gate_and(n46, a[2]);
  auto n49 = gate_or(n48, n47);
  auto n51 = gate_and(n50, n49);
  y[2] = gate_or(n52, n51);
  y[0] = gate_buf(_ash_1_n16);
  auto n36 = gate_nand(a[3], n56);
  auto n38 = gate_nand(n54, n53);
  auto n39 = gate_nand(a[2], n55);
  auto n57 = gate_and(n38, n39);
  y[3] = gate_nand(n57, n36);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n35 = gate_not(b[2]);
  auto n34 = gate_not(b[3]);
  auto n53 = gate_and(n35, n34);
  auto n49 = gate_not(b[1]);
  auto n38 = gate_and(n53, n49);
  auto n40 = gate_not(b[0]);
  auto n47 = gate_and(n38, n40);
  y[3] = gate_and(a[3], n47);
  auto n37 = gate_and(a[2], n40);
  auto n36 = gate_and(b[0], a[3]);
  auto n48 = gate_or(n37, n36);
  y[2] = gate_and(n38, n48);
  auto n46 = gate_and(n47, a[1]);
  auto n39 = gate_and(b[0], n49);
  auto n43 = gate_and(a[2], n39);
  auto n41 = gate_and(b[1], a[3]);
  auto n42 = gate_and(n41, n40);
  auto n44 = gate_or(n43, n42);
  auto n45 = gate_and(n44, n53);
  y[1] = gate_or(n46, n45);
  auto n56 = gate_and(a[0], n47);
  auto n52 = gate_and(n48, b[1]);
  auto n50 = gate_and(a[1], b[0]);
  auto n51 = gate_and(n50, n49);
  auto n54 = gate_or(n52, n51);
  auto n55 = gate_and(n54, n53);
  y[0] = gate_or(n56, n55);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n35 = gate_nand(b[0], b[1]);
  auto n39 = gate_not(b[2]);
  auto n38 = gate_not(b[3]);
  auto n43 = gate_and(n39, n38);
  auto n40 = gate_and(b[1], a[2]);
  auto n45 = gate_not(b[0]);
  auto n41 = gate_and(n40, n45);
  auto n42 = gate_not(b[1]);
  auto n48 = gate_and(n43, n42);
  auto n47 = gate_and(b[0], n48);
  auto n52 = gate_and(n48, n45);
  auto n49 = gate_not(n48);
  auto n51 = gate_not(n52);
  auto n54 = gate_and(a[3], n51);
  auto n53 = gate_and(n52, a[2]);
  y[2] = gate_or(n54, n53);
  auto n27 = gate_nand(a[0], n52);
  auto n28 = gate_nand(n43, n35);
  auto n31 = gate_nand(a[1], n52);
  auto n32 = gate_nand(n47, a[1]);
  auto n33 = gate_nand(a[3], n49);
  auto n34 = gate_nand(a[3], n28);
  auto n36 = gate_nand(a[2], n47);
  auto n37 = gate_nand(n43, n41);
  auto n44 = gate_and(n37, n34);
  auto n46 = gate_and(n44, n32);
  auto n50 = gate_and(n36, n31);
  y[1] = gate_nand(n50, n33);
  y[0] = gate_nand(n46, n27);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n21 = gate_not(b[1]);
  auto n22 = gate_xor(a[1], n21);
  auto n20 = gate_not(a[0]);
  auto n27 = gate_not(b[2]);
  auto n26 = gate_xor(a[2], n27);
  auto n24 = gate_and(a[1], n21);
  auto n28 = gate_xor(b[3], a[3]);
  auto n17 = gate_nand(b[0], n20);
  auto n18 = gate_nand(a[2], n27);
  y[1] = gate_xor(n22, n17);
  auto n23 = gate_and(n22, n17);
  auto n25 = gate_or(n24, n23);
  y[2] = gate_xor(n26, n25);
  auto n19 = gate_nand(n26, n25);
  auto n29 = gate_and(n19, n18);
  y[3] = gate_xor(n29, n28);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n8 = gate_not(a[1]);
  auto n7 = gate_not(a[0]);
  auto n10 = gate_and(n8, n7);
  auto n9 = gate_not(a[2]);
  y[2] = gate_xor(n10, n9);
  auto n12 = gate_not(a[3]);
  auto n11 = gate_and(n10, n9);
  y[3] = gate_xor(n12, n11);
}
