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
  auto n18 = gate_and(n16, n15);
  auto n17 = gate_and(b[2], a[2]);
  auto n20 = gate_or(n18, n17);
  auto n19 = gate_xor(a[3], b[3]);
  y[3] = gate_xor(n20, n19);
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
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
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
  auto n21 = gate_not(b[1]);
  auto n30 = gate_not(b[3]);
  auto n43 = gate_not(b[2]);
  auto n16 = gate_and(n30, n43);
  auto n12 = gate_and(n21, n16);
  auto n13 = gate_not(a[3]);
  auto n3 = gate_nand(b[0], n13);
  auto n5 = gate_nand(b[1], n13);
  y[3] = gate_and(n12, n3);
  auto n14 = gate_not(a[2]);
  auto n2 = gate_nand(b[0], n14);
  auto n15 = gate_and(n5, n2);
  y[2] = gate_and(n16, n15);
  auto n1 = gate_nand(y[2], b[0]);
  auto n18 = gate_not(y[2]);
  auto n17 = gate_not(y[3]);
  auto n19 = gate_and(n18, n17);
  auto n28 = gate_and(a[3], n19);
  auto n20 = gate_not(n28);
  auto n4 = gate_nand(b[2], n20);
  auto n26 = gate_and(n30, n4);
  auto n25 = gate_xor(b[2], n20);
  auto n31 = gate_and(a[2], n1);
  auto n9 = gate_nand(n31, n21);
  auto n23 = gate_xor(n31, n21);
  auto n35 = gate_not(a[1]);
  auto n33 = gate_and(b[0], n35);
  auto n22 = gate_not(n33);
  auto n8 = gate_nand(n23, n22);
  auto n24 = gate_and(n9, n8);
  auto n6 = gate_nand(n25, n24);
  y[1] = gate_and(n26, n6);
  auto n7 = gate_nand(n33, y[1]);
  auto n27 = gate_not(y[1]);
  auto n29 = gate_and(n28, n27);
  auto n50 = gate_and(n30, n29);
  auto n48 = gate_xor(n30, n29);
  auto n32 = gate_and(b[1], y[1]);
  auto n34 = gate_xor(n32, n31);
  auto n42 = gate_and(n34, n7);
  auto n36 = gate_and(y[1], b[0]);
  auto n40 = gate_xor(n36, n35);
  auto n10 = gate_nand(b[1], n40);
  auto n39 = gate_xor(b[1], n40);
  auto n37 = gate_not(a[0]);
  auto n38 = gate_and(b[0], n37);
  auto n11 = gate_nand(n39, n38);
  auto n41 = gate_and(n11, n10);
  auto n46 = gate_and(n42, n41);
  auto n44 = gate_xor(n42, n41);
  auto n45 = gate_and(n44, n43);
  auto n47 = gate_or(n46, n45);
  auto n49 = gate_and(n48, n47);
  y[0] = gate_or(n50, n49);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n71 = gate_xor(b[3], a[3]);
  auto n48 = gate_xor(b[2], b[3]);
  auto n47 = gate_not(n48);
  auto n16 = gate_and(a[0], a[3]);
  auto n42 = gate_xor(n16, a[1]);
  auto n37 = gate_xor(b[1], b[3]);
  auto n66 = gate_not(n37);
  auto n65 = gate_not(b[3]);
  auto n64 = gate_not(b[0]);
  auto n35 = gate_mux(n42, n65, n64);
  auto n34 = gate_xor(n66, n35);
  auto n18 = gate_not(a[1]);
  auto n17 = gate_not(a[0]);
  auto n22 = gate_and(n18, n17);
  auto n19 = gate_not(n22);
  auto n20 = gate_and(n19, a[3]);
  auto n32 = gate_xor(n20, a[2]);
  auto n21 = gate_not(a[2]);
  auto n23 = gate_and(n22, n21);
  auto n29 = gate_and(a[3], n23);
  auto n25 = gate_and(n29, n66);
  auto n24 = gate_and(n47, b[0]);
  auto n57 = gate_and(n25, n24);
  auto n26 = gate_not(n57);
  auto n41 = gate_and(n29, n26);
  auto n28 = gate_and(n66, n41);
  auto n27 = gate_mux(n32, n65, n64);
  auto n30 = gate_or(n28, n27);
  auto n38 = gate_not(n29);
  auto n4 = gate_nand(n48, n38);
  auto n9 = gate_nand(n37, n38);
  auto n31 = gate_and(n30, n9);
  auto n56 = gate_and(n47, n31);
  auto n40 = gate_not(n56);
  auto n50 = gate_and(n32, n40);
  auto n33 = gate_not(n50);
  auto n14 = gate_nand(n34, n33);
  auto n36 = gate_not(n35);
  auto n8 = gate_nand(n37, n36);
  auto n39 = gate_and(n14, n8);
  auto n7 = gate_nand(n39, n4);
  auto n52 = gate_and(n41, n40);
  auto n5 = gate_nand(n47, n52);
  auto n54 = gate_and(n7, n5);
  auto n55 = gate_not(n54);
  auto n10 = gate_nand(b[0], n55);
  auto n45 = gate_and(n42, n10);
  auto n12 = gate_nand(n45, n66);
  auto n44 = gate_xor(n45, n66);
  auto n43 = gate_mux(a[0], n65, n64);
  auto n13 = gate_nand(n44, n43);
  auto n49 = gate_and(n13, n12);
  auto n11 = gate_nand(n49, n48);
  auto n46 = gate_not(n49);
  auto n2 = gate_nand(n47, n46);
  auto n51 = gate_and(n50, n11);
  auto n53 = gate_or(n52, n51);
  auto n6 = gate_nand(n54, n53);
  auto n70 = gate_and(n2, n6);
  auto n63 = gate_and(n71, n70);
  auto n62 = gate_xor(n71, n55);
  auto n61 = gate_and(n63, n62);
  auto n60 = gate_xor(n71, n56);
  auto n59 = gate_and(n61, n60);
  auto n58 = gate_xor(n71, n57);
  y[3] = gate_xor(n59, n58);
  y[2] = gate_xor(n61, n60);
  y[1] = gate_xor(n63, n62);
  auto n73 = gate_not(n63);
  auto n69 = gate_and(n65, n64);
  auto n67 = gate_not(b[2]);
  auto n68 = gate_and(n67, n66);
  auto n1 = gate_nand(n69, n68);
  auto n15 = gate_nand(n71, n1);
  auto n72 = gate_xor(n71, n70);
  auto n3 = gate_nand(n15, n72);
  y[0] = gate_and(n73, n3);
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
  auto n29 = gate_not(a[0]);
  auto n32 = gate_and(b[0], n29);
  auto n24 = gate_nand(b[1], n32);
  auto n31 = gate_xor(b[1], n32);
  auto n30 = gate_not(a[1]);
  auto n23 = gate_nand(n31, n30);
  auto n35 = gate_and(n23, n24);
  auto n27 = gate_nand(a[2], n35);
  auto n34 = gate_xor(a[2], n35);
  auto n33 = gate_not(b[2]);
  auto n28 = gate_nand(n34, n33);
  auto n38 = gate_and(n28, n27);
  auto n25 = gate_nand(n38, b[3]);
  auto n37 = gate_xor(n38, b[3]);
  auto n36 = gate_not(a[3]);
  auto n26 = gate_nand(n37, n36);
  auto _gte_x_1_n29 = gate_and(n26, n25);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(a[0]);
  auto n32 = gate_and(b[0], n29);
  auto n23 = gate_nand(b[1], n32);
  auto n31 = gate_xor(b[1], n32);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nand(n31, n30);
  auto n35 = gate_and(n24, n23);
  auto n25 = gate_nand(a[2], n35);
  auto n34 = gate_xor(a[2], n35);
  auto n33 = gate_not(b[2]);
  auto n26 = gate_nand(n34, n33);
  auto n38 = gate_and(n26, n25);
  auto n27 = gate_nand(n38, a[3]);
  auto n37 = gate_xor(n38, a[3]);
  auto n36 = gate_not(b[3]);
  auto n28 = gate_nand(n37, n36);
  auto _gte_x_1_n29 = gate_and(n28, n27);
  y[0] = gate_buf(_gte_x_1_n29);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[3]);
  auto n40 = gate_and(n29, a[3]);
  auto n38 = gate_xor(n29, a[3]);
  auto n30 = gate_not(b[0]);
  auto n33 = gate_and(a[0], n30);
  auto n27 = gate_nand(a[1], n33);
  auto n32 = gate_xor(a[1], n33);
  auto n31 = gate_not(b[1]);
  auto n28 = gate_nand(n32, n31);
  auto n36 = gate_and(n28, n27);
  auto n26 = gate_nand(b[2], n36);
  auto n35 = gate_xor(b[2], n36);
  auto n34 = gate_not(a[2]);
  auto n25 = gate_nand(n35, n34);
  auto n37 = gate_and(n25, n26);
  auto n39 = gate_and(n38, n37);
  auto _gt_x_1_n29 = gate_or(n40, n39);
  y[0] = gate_buf(_gt_x_1_n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(a[3]);
  auto n40 = gate_and(n29, b[3]);
  auto n38 = gate_xor(n29, b[3]);
  auto n30 = gate_not(b[0]);
  auto n33 = gate_and(a[0], n30);
  auto n27 = gate_nand(a[1], n33);
  auto n32 = gate_xor(a[1], n33);
  auto n31 = gate_not(b[1]);
  auto n28 = gate_nand(n32, n31);
  auto n36 = gate_and(n28, n27);
  auto n26 = gate_nand(b[2], n36);
  auto n35 = gate_xor(b[2], n36);
  auto n34 = gate_not(a[2]);
  auto n25 = gate_nand(n35, n34);
  auto n37 = gate_and(n25, n26);
  auto n39 = gate_and(n38, n37);
  auto _gt_x_1_n29 = gate_or(n40, n39);
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
  auto n9 = gate_not(a[1]);
  auto n8 = gate_not(a[3]);
  auto n13 = gate_and(n9, n8);
  auto n11 = gate_not(a[2]);
  auto n10 = gate_not(a[0]);
  auto n12 = gate_and(n11, n10);
  auto n14 = gate_and(n13, n12);
  y[0] = gate_mux(b[0], c[0], n14);
  y[1] = gate_mux(b[1], c[1], n14);
  y[2] = gate_mux(b[2], c[2], n14);
  y[3] = gate_mux(b[3], c[3], n14);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n34 = gate_not(b[0]);
  auto n37 = gate_and(a[0], n34);
  auto n32 = gate_nand(a[1], n37);
  auto n36 = gate_xor(a[1], n37);
  auto n35 = gate_not(b[1]);
  auto n33 = gate_nand(n36, n35);
  auto n40 = gate_and(n33, n32);
  auto n29 = gate_nand(b[2], n40);
  auto n39 = gate_xor(b[2], n40);
  auto n38 = gate_not(a[2]);
  auto n28 = gate_nand(n39, n38);
  auto n43 = gate_and(n28, n29);
  auto n30 = gate_nand(a[3], n43);
  auto n42 = gate_xor(a[3], n43);
  auto n41 = gate_not(b[3]);
  auto n31 = gate_nand(n42, n41);
  y[0] = gate_and(n31, n30);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n34 = gate_not(b[0]);
  auto n37 = gate_and(a[0], n34);
  auto n32 = gate_nand(a[1], n37);
  auto n36 = gate_xor(a[1], n37);
  auto n35 = gate_not(b[1]);
  auto n33 = gate_nand(n36, n35);
  auto n40 = gate_and(n33, n32);
  auto n30 = gate_nand(b[2], n40);
  auto n39 = gate_xor(b[2], n40);
  auto n38 = gate_not(a[2]);
  auto n28 = gate_nand(n39, n38);
  auto n43 = gate_and(n28, n30);
  auto n31 = gate_nand(b[3], n43);
  auto n42 = gate_xor(b[3], n43);
  auto n41 = gate_not(a[3]);
  auto n29 = gate_nand(n42, n41);
  y[0] = gate_and(n29, n31);
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
  auto n18 = gate_nand(n24, n23);
  auto n26 = gate_not(b[0]);
  auto n25 = gate_not(b[1]);
  auto n30 = gate_and(n26, n25);
  auto n28 = gate_not(b[2]);
  auto n27 = gate_not(b[3]);
  auto n29 = gate_and(n28, n27);
  auto n17 = gate_nand(n30, n29);
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
  auto n26 = gate_not(a[0]);
  auto n29 = gate_and(b[0], n26);
  auto n23 = gate_nand(b[1], n29);
  auto n28 = gate_xor(b[1], n29);
  auto n27 = gate_not(a[1]);
  auto n22 = gate_nand(n28, n27);
  auto n32 = gate_and(n22, n23);
  auto n24 = gate_nand(n32, a[2]);
  auto n31 = gate_xor(n32, a[2]);
  auto n30 = gate_not(b[2]);
  auto n25 = gate_nand(n31, n30);
  auto n33 = gate_and(n25, n24);
  auto n37 = gate_and(n33, b[3]);
  auto n35 = gate_xor(n33, b[3]);
  auto n34 = gate_not(a[3]);
  auto n36 = gate_and(n35, n34);
  y[0] = gate_or(n37, n36);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_not(a[0]);
  auto n29 = gate_and(b[0], n26);
  auto n23 = gate_nand(b[1], n29);
  auto n28 = gate_xor(b[1], n29);
  auto n27 = gate_not(a[1]);
  auto n22 = gate_nand(n28, n27);
  auto n32 = gate_and(n22, n23);
  auto n24 = gate_nand(n32, a[2]);
  auto n31 = gate_xor(n32, a[2]);
  auto n30 = gate_not(b[2]);
  auto n25 = gate_nand(n31, n30);
  auto n33 = gate_and(n25, n24);
  auto n37 = gate_and(n33, a[3]);
  auto n35 = gate_xor(n33, a[3]);
  auto n34 = gate_not(b[3]);
  auto n36 = gate_and(n35, n34);
  y[0] = gate_or(n37, n36);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n56 = gate_not(b[1]);
  auto n48 = gate_not(b[3]);
  auto n51 = gate_not(b[2]);
  auto n28 = gate_and(n48, n51);
  auto n9 = gate_and(n28, b[0]);
  auto n12 = gate_and(n56, n9);
  auto n10 = gate_not(n12);
  auto n17 = gate_and(a[3], n10);
  auto n11 = gate_xor(n56, a[3]);
  auto n13 = gate_and(n28, n11);
  auto n15 = gate_or(n13, n12);
  auto n14 = gate_not(a[2]);
  auto n3 = gate_nand(b[0], n14);
  auto n18 = gate_and(n15, n3);
  auto n5 = gate_nand(n18, b[0]);
  auto n16 = gate_not(n18);
  auto n44 = gate_and(n17, n16);
  auto n31 = gate_and(a[2], n5);
  auto n23 = gate_and(n31, n56);
  auto n21 = gate_xor(n31, n56);
  auto n19 = gate_not(a[1]);
  auto n33 = gate_and(b[0], n19);
  auto n20 = gate_not(n33);
  auto n22 = gate_and(n21, n20);
  auto n25 = gate_or(n23, n22);
  auto n24 = gate_xor(n25, n51);
  auto n1 = gate_nand(n24, n48);
  auto n50 = gate_and(n44, n1);
  auto n26 = gate_xor(n51, n44);
  auto n27 = gate_and(n26, n25);
  auto n30 = gate_and(n48, n27);
  auto n29 = gate_and(n28, n44);
  auto n35 = gate_or(n30, n29);
  auto n6 = gate_nand(n33, n35);
  auto n32 = gate_and(b[1], n35);
  auto n34 = gate_xor(n32, n31);
  auto n54 = gate_and(n34, n6);
  auto n43 = gate_and(n51, n54);
  auto n41 = gate_xor(n51, n54);
  auto n36 = gate_and(n35, b[0]);
  auto n58 = gate_xor(n36, a[1]);
  auto n40 = gate_and(n56, n58);
  auto n38 = gate_xor(n56, n58);
  auto n37 = gate_not(a[0]);
  auto n2 = gate_nand(b[0], n37);
  auto n39 = gate_and(n38, n2);
  auto n52 = gate_or(n40, n39);
  auto n42 = gate_and(n41, n52);
  auto n49 = gate_or(n43, n42);
  auto n7 = gate_nand(n49, n48);
  auto n45 = gate_not(n44);
  auto n4 = gate_nand(b[3], n45);
  auto n47 = gate_and(n49, n4);
  auto n46 = gate_and(n50, n48);
  auto n60 = gate_or(n47, n46);
  auto n8 = gate_nand(n60, n7);
  y[3] = gate_and(n50, n8);
  auto n53 = gate_xor(n52, n51);
  auto n55 = gate_and(n53, n60);
  y[2] = gate_xor(n55, n54);
  auto n57 = gate_xor(n2, n56);
  auto n59 = gate_and(n57, n60);
  y[1] = gate_xor(n59, n58);
  auto n61 = gate_and(n60, b[0]);
  y[0] = gate_xor(n61, a[0]);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n45 = gate_not(b[3]);
  auto n41 = gate_xor(b[2], n45);
  auto n54 = gate_not(n41);
  auto n13 = gate_not(a[1]);
  auto n12 = gate_not(a[0]);
  auto n21 = gate_and(n13, n12);
  auto n61 = gate_xor(b[1], n45);
  auto n14 = gate_and(n61, n41);
  auto n3 = gate_nand(b[0], n14);
  auto n16 = gate_and(n21, n3);
  auto n15 = gate_not(a[2]);
  auto n17 = gate_and(n16, n15);
  auto n19 = gate_and(a[3], n17);
  auto n31 = gate_and(n54, n19);
  auto n24 = gate_xor(n19, n61);
  auto n18 = gate_not(b[0]);
  auto n10 = gate_nand(n24, n18);
  auto n20 = gate_and(n19, n10);
  auto n33 = gate_and(n20, n41);
  auto n22 = gate_not(n21);
  auto n23 = gate_and(n22, a[3]);
  auto n26 = gate_xor(n23, a[2]);
  auto n25 = gate_and(n41, n24);
  auto n9 = gate_nand(n25, b[0]);
  auto n36 = gate_and(n26, n9);
  auto n30 = gate_and(n36, n61);
  auto n28 = gate_xor(n36, n61);
  auto n27 = gate_and(a[3], a[0]);
  auto n43 = gate_xor(a[1], n27);
  auto n38 = gate_mux(n45, n43, b[0]);
  auto n29 = gate_and(n28, n38);
  auto n32 = gate_or(n30, n29);
  auto n50 = gate_mux(n31, n33, n32);
  auto n35 = gate_not(n61);
  auto n34 = gate_and(n32, n41);
  auto n42 = gate_or(n34, n33);
  auto n37 = gate_and(n35, n42);
  auto n40 = gate_xor(n37, n36);
  auto n39 = gate_not(n38);
  auto n6 = gate_nand(n39, n42);
  auto n55 = gate_and(n40, n6);
  auto n8 = gate_nand(n41, n55);
  auto n48 = gate_xor(n41, n55);
  auto n44 = gate_and(n42, b[0]);
  auto n64 = gate_xor(n44, n43);
  auto n5 = gate_nand(n64, n61);
  auto n46 = gate_xor(n64, n61);
  auto n62 = gate_mux(n45, a[0], b[0]);
  auto n4 = gate_nand(n46, n62);
  auto n53 = gate_and(n5, n4);
  auto n47 = gate_not(n53);
  auto n7 = gate_nand(n48, n47);
  auto n51 = gate_and(n8, n7);
  auto n49 = gate_not(n51);
  auto n11 = gate_nand(n50, n49);
  auto n69 = gate_and(a[3], n11);
  auto n52 = gate_not(n50);
  auto n2 = gate_nand(n52, n51);
  auto n1 = gate_nand(n2, n53);
  auto n56 = gate_and(n2, n54);
  auto n57 = gate_xor(n56, n55);
  auto n58 = gate_and(n1, n57);
  auto n71 = gate_xor(a[3], n58);
  auto n60 = gate_and(b[0], n2);
  auto n59 = gate_xor(a[0], a[3]);
  auto n75 = gate_xor(n60, n59);
  y[0] = gate_xor(a[3], n75);
  auto n67 = gate_and(a[3], n75);
  auto n63 = gate_xor(n62, n61);
  auto n65 = gate_and(n63, n2);
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
  auto n7 = gate_and(a[0], b[1]);
  auto n6 = gate_and(a[1], b[0]);
  y[1] = gate_xor(n7, n6);
  auto n5 = gate_and(a[1], b[1]);
  auto n4 = gate_and(b[2], a[0]);
  auto n15 = gate_xor(n5, n4);
  auto n14 = gate_and(a[2], b[0]);
  auto n2 = gate_nand(n15, n14);
  auto n13 = gate_xor(n15, n14);
  auto n12 = gate_and(n7, n6);
  auto n3 = gate_nand(n13, n12);
  y[2] = gate_xor(n13, n12);
  auto n8 = gate_not(n7);
  auto n9 = gate_and(n8, a[1]);
  auto n21 = gate_and(b[2], n9);
  auto n11 = gate_and(a[3], b[0]);
  auto n10 = gate_and(b[3], a[0]);
  auto n19 = gate_xor(n11, n10);
  auto n17 = gate_and(b[1], a[2]);
  auto n16 = gate_and(n3, n2);
  auto n18 = gate_xor(n17, n16);
  auto n20 = gate_xor(n19, n18);
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
  auto n27 = gate_not(b[2]);
  auto n26 = gate_not(b[3]);
  auto n30 = gate_and(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n39 = gate_and(n30, n28);
  auto n31 = gate_not(b[0]);
  auto n29 = gate_and(n39, n31);
  auto _ash_1_n16 = gate_and(n29, a[0]);
  y[0] = gate_buf(_ash_1_n16);
  auto n36 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n39, n36);
  auto n37 = gate_and(b[1], n30);
  auto n32 = gate_and(a[0], n37);
  auto n35 = gate_and(n32, n31);
  auto n33 = gate_mux(a[2], a[1], b[0]);
  auto n34 = gate_and(n39, n33);
  y[2] = gate_or(n35, n34);
  auto n41 = gate_and(n37, n36);
  auto n38 = gate_mux(a[3], a[2], b[0]);
  auto n40 = gate_and(n39, n38);
  y[3] = gate_or(n41, n40);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[3]);
  auto n16 = gate_not(b[2]);
  auto n22 = gate_and(n17, n16);
  auto n18 = gate_mux(a[0], a[2], b[1]);
  auto n20 = gate_and(n22, n18);
  auto n19 = gate_mux(a[1], a[3], b[1]);
  auto n24 = gate_and(n22, n19);
  y[0] = gate_mux(n20, n24, b[0]);
  auto n21 = gate_not(b[1]);
  auto n26 = gate_and(n22, n21);
  auto n23 = gate_and(n26, a[2]);
  y[1] = gate_mux(n24, n23, b[0]);
  auto n25 = gate_mux(a[2], a[3], b[0]);
  y[2] = gate_and(n26, n25);
  auto n28 = gate_and(a[3], n26);
  auto n27 = gate_not(b[0]);
  y[3] = gate_and(n28, n27);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n23 = gate_nand(b[0], b[1]);
  auto n25 = gate_not(b[2]);
  auto n24 = gate_not(b[3]);
  auto n29 = gate_and(n25, n24);
  auto n19 = gate_nand(n29, n23);
  auto n18 = gate_nand(a[3], n19);
  auto n26 = gate_and(b[1], a[2]);
  auto n36 = gate_not(b[0]);
  auto n27 = gate_and(n26, n36);
  auto n21 = gate_nand(n29, n27);
  auto n31 = gate_and(n21, n18);
  auto n28 = gate_not(b[1]);
  auto n37 = gate_and(n29, n28);
  auto n30 = gate_mux(a[0], a[1], b[0]);
  auto n22 = gate_nand(n37, n30);
  y[0] = gate_nand(n31, n22);
  auto n32 = gate_not(n37);
  auto n35 = gate_and(a[3], n32);
  auto n33 = gate_mux(a[1], a[2], b[0]);
  auto n34 = gate_and(n37, n33);
  y[1] = gate_or(n35, n34);
  auto n38 = gate_and(n37, n36);
  y[2] = gate_mux(a[3], a[2], n38);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n21 = gate_not(b[1]);
  auto n22 = gate_xor(a[1], n21);
  auto n20 = gate_not(a[0]);
  auto n17 = gate_nand(b[0], n20);
  y[1] = gate_xor(n22, n17);
  auto n27 = gate_not(b[2]);
  auto n18 = gate_nand(a[2], n27);
  auto n26 = gate_xor(a[2], n27);
  auto n24 = gate_and(a[1], n21);
  auto n23 = gate_and(n22, n17);
  auto n25 = gate_or(n24, n23);
  auto n19 = gate_nand(n26, n25);
  y[2] = gate_xor(n26, n25);
  auto n28 = gate_and(n19, n18);
  auto n29 = gate_xor(n28, a[3]);
  y[3] = gate_xor(b[3], n29);
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
