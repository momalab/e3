template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n49 = gate_nand(b[0], a[0]);
  auto n28 = gate_nand(n49, n49);
  auto n34 = gate_nand(a[1], b[1]);
  auto n26 = gate_nand(n34, b[1]);
  auto n25 = gate_nand(n34, a[1]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n29, n27);
  auto n30 = gate_nand(n29, n28);
  y[1] = gate_nand(n31, n30);
  auto n42 = gate_nand(a[2], a[2]);
  auto n33 = gate_nand(a[1], a[1]);
  auto n32 = gate_nand(b[1], b[1]);
  auto n36 = gate_nand(n33, n32);
  auto n35 = gate_nand(n34, n49);
  auto n41 = gate_nand(n36, n35);
  auto n43 = gate_nand(n41, n41);
  auto n38 = gate_nand(n42, n43);
  auto n37 = gate_nand(a[2], n41);
  auto n40 = gate_nand(n38, n37);
  auto n39 = gate_nand(b[2], b[2]);
  auto n48 = gate_nand(n40, n39);
  auto n45 = gate_nand(n42, n41);
  auto n44 = gate_nand(n43, a[2]);
  auto n46 = gate_nand(n45, n44);
  auto n47 = gate_nand(n46, b[2]);
  y[2] = gate_nand(n48, n47);
  auto n51 = gate_nand(n49, a[0]);
  auto n50 = gate_nand(n49, b[0]);
  auto _add_x_1_n36 = gate_nand(n51, n50);
  y[0] = gate_buf(_add_x_1_n36);
}
template<> void $NameUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_nand(b[2], a[2]);
  y[2] = gate_nand(n4, n4);
  auto n5 = gate_nand(b[1], a[1]);
  y[1] = gate_nand(n5, n5);
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_nand(n6, n6);
}
template<> void $NameUint<3>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[2] = gate_nand(a[2], a[2]);
  y[1] = gate_nand(a[1], a[1]);
  y[0] = gate_nand(a[0], a[0]);
}
template<> void $NameUint<3>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(b[2], b[2]);
  auto n7 = gate_nand(a[2], a[2]);
  y[2] = gate_nand(n8, n7);
  auto n10 = gate_nand(b[1], b[1]);
  auto n9 = gate_nand(a[1], a[1]);
  y[1] = gate_nand(n10, n9);
  auto n12 = gate_nand(b[0], b[0]);
  auto n11 = gate_nand(a[0], a[0]);
  y[0] = gate_nand(n12, n11);
}
template<> void $NameUint<3>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_nand(b[2], b[2]);
  auto n16 = gate_nand(a[2], n13);
  auto n14 = gate_nand(a[2], a[2]);
  auto n15 = gate_nand(b[2], n14);
  y[2] = gate_nand(n16, n15);
  auto n17 = gate_nand(b[1], b[1]);
  auto n20 = gate_nand(a[1], n17);
  auto n18 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(b[1], n18);
  y[1] = gate_nand(n20, n19);
  auto n21 = gate_nand(b[0], b[0]);
  auto n24 = gate_nand(a[0], n21);
  auto n22 = gate_nand(a[0], a[0]);
  auto n23 = gate_nand(b[0], n22);
  y[0] = gate_nand(n24, n23);
}
template<> void $NameUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n4, n4);
  auto n5 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n5, n5);
  auto n6 = gate_nand(a[0], b[2]);
  y[2] = gate_nand(n6, n6);
}
template<> void $NameUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n12 = gate_nand(a[0], a[0]);
  auto n9 = gate_nand(n12, c[0]);
  auto n8 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n9, n8);
  auto n11 = gate_nand(n12, c[1]);
  auto n10 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n11, n10);
  auto n14 = gate_nand(n12, c[2]);
  auto n13 = gate_nand(a[0], b[2]);
  y[2] = gate_nand(n14, n13);
}
template<> void $NameUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[0]);
  auto n10 = gate_nand(a[1], a[0]);
  auto n9 = gate_nand(a[1], a[1]);
  auto n13 = gate_nand(y[0], n9);
  y[1] = gate_nand(n10, n13);
  auto n12 = gate_nand(n13, n13);
  auto n11 = gate_nand(a[2], a[2]);
  auto n15 = gate_nand(n12, n11);
  auto n14 = gate_nand(a[2], n13);
  y[2] = gate_nand(n15, n14);
}
template<> void $NameUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_nand(a[2], a[2]);
  auto n3 = gate_nand(n11, b[1]);
  auto n9 = gate_nand(b[2], b[2]);
  auto n13 = gate_nand(b[0], b[0]);
  auto n2 = gate_nand(n9, n13);
  auto n1 = gate_nand(n9, a[1]);
  auto n28 = gate_nand(n2, n1);
  auto n12 = gate_nand(n3, n28);
  y[1] = gate_nand(n12, n12);
  auto n18 = gate_nand(b[1], b[1]);
  auto n4 = gate_nand(n9, n18);
  auto n5 = gate_nand(n4, n4);
  auto n7 = gate_nand(n5, n13);
  auto n6 = gate_nand(n5, a[2]);
  y[2] = gate_nand(n7, n6);
  auto n8 = gate_nand(a[2], b[1]);
  auto n10 = gate_nand(n8, n8);
  auto n26 = gate_nand(n10, n9);
  auto n25 = gate_nand(n11, b[2]);
  auto n15 = gate_nand(a[1], n12);
  auto n14 = gate_nand(a[1], n13);
  auto n17 = gate_nand(n15, n14);
  auto n16 = gate_nand(n17, n17);
  auto n21 = gate_nand(n16, b[1]);
  auto n23 = gate_nand(n21, a[0]);
  auto n19 = gate_nand(n18, n17);
  auto n20 = gate_nand(n19, b[0]);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n27 = gate_nand(n25, n24);
  auto n30 = gate_nand(n26, n27);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  y[0] = gate_nand(n31, n31);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(a[1], a[1]);
  auto n1 = gate_nand(a[0], a[0]);
  auto n24 = gate_nand(n9, n1);
  auto n6 = gate_nand(a[2], n24);
  auto n2 = gate_nand(b[1], b[1]);
  auto n3 = gate_nand(n2, b[2]);
  auto n70 = gate_nand(b[2], b[2]);
  auto n74 = gate_nand(b[1], n70);
  auto n75 = gate_nand(n74, n74);
  auto n33 = gate_nand(n3, n74);
  auto n40 = gate_nand(n33, n33);
  auto n4 = gate_nand(n40, b[0]);
  auto n5 = gate_nand(a[2], n4);
  auto n54 = gate_nand(n6, n5);
  auto n8 = gate_nand(a[2], n70);
  auto n69 = gate_nand(a[2], a[2]);
  auto n7 = gate_nand(b[2], n69);
  auto n76 = gate_nand(n8, n7);
  auto n11 = gate_nand(a[0], a[2]);
  auto n10 = gate_nand(n11, n11);
  auto n13 = gate_nand(n10, n9);
  auto n12 = gate_nand(n11, a[1]);
  auto n34 = gate_nand(n13, n12);
  auto n14 = gate_nand(b[0], n34);
  auto n25 = gate_nand(b[0], b[0]);
  auto n19 = gate_nand(n70, n25);
  auto n41 = gate_nand(n14, n19);
  auto n15 = gate_nand(n41, n41);
  auto n44 = gate_nand(n33, n15);
  auto n17 = gate_nand(a[0], n34);
  auto n16 = gate_nand(a[0], n40);
  auto n18 = gate_nand(n17, n16);
  auto n21 = gate_nand(n18, b[0]);
  auto n23 = gate_nand(n21, n19);
  auto n20 = gate_nand(n34, n34);
  auto n22 = gate_nand(n21, n20);
  auto n30 = gate_nand(n23, n22);
  auto n32 = gate_nand(n44, n30);
  auto n26 = gate_nand(n24, n24);
  auto n28 = gate_nand(n26, n25);
  auto n27 = gate_nand(n26, n33);
  auto n29 = gate_nand(n28, n27);
  auto n42 = gate_nand(a[2], n29);
  auto n31 = gate_nand(n42, n30);
  auto n37 = gate_nand(n32, n31);
  auto n39 = gate_nand(n37, n33);
  auto n35 = gate_nand(n20, b[2]);
  auto n36 = gate_nand(n25, n35);
  auto n38 = gate_nand(n37, n36);
  auto n68 = gate_nand(n39, n38);
  auto n72 = gate_nand(n68, n68);
  auto n79 = gate_nand(n76, n68);
  auto n64 = gate_nand(n79, n79);
  auto n43 = gate_nand(n41, n40);
  auto n45 = gate_nand(n43, n42);
  auto n46 = gate_nand(n45, n44);
  auto n49 = gate_nand(n46, n69);
  auto n47 = gate_nand(n46, n46);
  auto n48 = gate_nand(a[2], n47);
  auto n51 = gate_nand(n49, n48);
  auto n50 = gate_nand(n51, n51);
  auto n53 = gate_nand(n50, n70);
  auto n52 = gate_nand(n51, b[2]);
  auto n63 = gate_nand(n53, n52);
  auto n65 = gate_nand(n64, n63);
  auto n58 = gate_nand(n54, n65);
  auto n56 = gate_nand(n65, n65);
  auto n55 = gate_nand(n54, n54);
  auto n57 = gate_nand(n56, n55);
  auto n60 = gate_nand(n58, n57);
  auto n59 = gate_nand(n60, n60);
  auto n62 = gate_nand(n59, b[2]);
  auto n61 = gate_nand(n60, n70);
  y[2] = gate_nand(n62, n61);
  auto n67 = gate_nand(n65, n63);
  auto n66 = gate_nand(n65, n64);
  y[1] = gate_nand(n67, n66);
  auto n71 = gate_nand(n72, n69);
  auto n73 = gate_nand(n71, n70);
  auto n82 = gate_nand(n73, n72);
  auto n78 = gate_nand(n75, n76);
  auto n77 = gate_nand(b[0], n76);
  auto n80 = gate_nand(n78, n77);
  auto n81 = gate_nand(n80, n79);
  y[0] = gate_nand(n82, n81);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n36 = gate_nand(a[2], a[2]);
  auto n23 = gate_nand(a[0], a[0]);
  auto n26 = gate_nand(b[0], n23);
  auto n24 = gate_nand(b[0], b[0]);
  auto n25 = gate_nand(a[0], n24);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n27, n27);
  auto n31 = gate_nand(b[1], n29);
  auto n28 = gate_nand(a[1], a[1]);
  auto n30 = gate_nand(n29, n28);
  auto n33 = gate_nand(n31, n30);
  auto n32 = gate_nand(b[1], b[1]);
  auto n35 = gate_nand(n33, n32);
  auto n34 = gate_nand(n33, a[1]);
  auto n39 = gate_nand(n35, n34);
  auto n38 = gate_nand(n36, n39);
  auto n37 = gate_nand(b[2], b[2]);
  auto n42 = gate_nand(n38, n37);
  auto n40 = gate_nand(a[2], n39);
  auto n41 = gate_nand(n40, b[2]);
  auto n43 = gate_nand(n42, n41);
  y[0] = gate_nand(n43, n43);
}
template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_nand(b[2], b[2]);
  auto n27 = gate_nand(n15, a[2]);
  auto n16 = gate_nand(a[1], a[1]);
  auto n25 = gate_nand(n16, b[1]);
  auto n17 = gate_nand(a[2], a[2]);
  auto n21 = gate_nand(n17, b[2]);
  auto n23 = gate_nand(n21, a[0]);
  auto n18 = gate_nand(b[1], b[1]);
  auto n19 = gate_nand(n18, a[1]);
  auto n20 = gate_nand(n19, b[0]);
  auto n22 = gate_nand(n21, n20);
  auto n24 = gate_nand(n23, n22);
  auto n26 = gate_nand(n25, n24);
  y[0] = gate_nand(n27, n26);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_nand(a[0], a[0]);
  auto n19 = gate_nand(b[0], n17);
  auto n20 = gate_nand(a[1], a[1]);
  auto n18 = gate_nand(b[1], n20);
  auto n21 = gate_nand(n19, n18);
  auto n23 = gate_nand(n21, n20);
  auto n22 = gate_nand(n21, b[1]);
  auto n26 = gate_nand(n23, n22);
  auto n25 = gate_nand(n26, n26);
  auto n24 = gate_nand(a[2], a[2]);
  auto n29 = gate_nand(n25, n24);
  auto n27 = gate_nand(n26, a[2]);
  auto n28 = gate_nand(n27, b[2]);
  auto _gte_x_1_n44 = gate_nand(n29, n28);
  y[0] = gate_buf(_gte_x_1_n44);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_nand(b[1], b[1]);
  auto n26 = gate_nand(a[1], n21);
  auto n20 = gate_nand(n26, n26);
  auto n35 = gate_nand(n20, a[2]);
  auto n27 = gate_nand(a[2], a[2]);
  auto n22 = gate_nand(n27, b[2]);
  auto n24 = gate_nand(n22, a[1]);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  auto n30 = gate_nand(a[0], n25);
  auto n29 = gate_nand(n27, n26);
  auto n28 = gate_nand(b[2], b[2]);
  auto n31 = gate_nand(n29, n28);
  auto n33 = gate_nand(n30, n31);
  auto n32 = gate_nand(b[0], n31);
  auto n34 = gate_nand(n33, n32);
  y[0] = gate_nand(n35, n34);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_nand(b[2], b[2]);
  auto n17 = gate_nand(n16, a[2]);
  auto n19 = gate_nand(n17, a[1]);
  auto n21 = gate_nand(b[1], b[1]);
  auto n18 = gate_nand(n17, n21);
  auto n25 = gate_nand(n19, n18);
  auto n20 = gate_nand(b[0], b[0]);
  auto n23 = gate_nand(a[0], n20);
  auto n22 = gate_nand(a[1], n21);
  auto n24 = gate_nand(n23, n22);
  auto n28 = gate_nand(n25, n24);
  auto n26 = gate_nand(a[2], a[2]);
  auto n27 = gate_nand(b[2], n26);
  auto _gt_x_1_n44 = gate_nand(n28, n27);
  y[0] = gate_buf(_gt_x_1_n44);
}
template<> void $NameUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n13 = gate_nand(a[0], a[1]);
  auto n10 = gate_nand(n13, a[1]);
  auto n9 = gate_nand(n13, a[0]);
  y[1] = gate_nand(n10, n9);
  auto n12 = gate_nand(n13, n13);
  auto n11 = gate_nand(a[2], a[2]);
  auto n15 = gate_nand(n12, n11);
  auto n14 = gate_nand(a[2], n13);
  y[2] = gate_nand(n15, n14);
  y[0] = gate_nand(a[0], a[0]);
}
template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n34 = gate_nand(a[2], a[2]);
  auto n21 = gate_nand(b[1], b[1]);
  auto n24 = gate_nand(a[1], n21);
  auto n22 = gate_nand(a[1], a[1]);
  auto n23 = gate_nand(b[1], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n25, n25);
  auto n29 = gate_nand(a[0], n27);
  auto n26 = gate_nand(b[0], b[0]);
  auto n28 = gate_nand(n27, n26);
  auto n31 = gate_nand(n29, n28);
  auto n30 = gate_nand(a[0], a[0]);
  auto n33 = gate_nand(n31, n30);
  auto n32 = gate_nand(n31, b[0]);
  auto n37 = gate_nand(n33, n32);
  auto n36 = gate_nand(n34, n37);
  auto n35 = gate_nand(b[2], b[2]);
  auto n40 = gate_nand(n36, n35);
  auto n38 = gate_nand(a[2], n37);
  auto n39 = gate_nand(n38, b[2]);
  auto _ne_x_1_n30 = gate_nand(n40, n39);
  y[0] = gate_buf(_ne_x_1_n30);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n15 = gate_nand(a[0], a[0]);
  auto n14 = gate_nand(a[1], a[1]);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n16, n16);
  auto n17 = gate_nand(a[2], a[2]);
  auto n23 = gate_nand(n18, n17);
  auto n20 = gate_nand(n23, b[0]);
  auto n24 = gate_nand(n23, n23);
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
  auto n22 = gate_nand(a[2], a[2]);
  auto n34 = gate_nand(n22, b[2]);
  auto n23 = gate_nand(b[2], b[2]);
  auto n32 = gate_nand(n23, a[2]);
  auto n24 = gate_nand(b[1], b[1]);
  auto n28 = gate_nand(n24, a[1]);
  auto n30 = gate_nand(n28, b[0]);
  auto n25 = gate_nand(a[1], a[1]);
  auto n26 = gate_nand(n25, b[1]);
  auto n27 = gate_nand(n26, a[0]);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto _lte_x_1_n7 = gate_nand(n34, n33);
  y[0] = gate_buf(_lte_x_1_n7);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_nand(b[2], b[2]);
  auto n28 = gate_nand(n16, a[2]);
  auto n17 = gate_nand(b[1], b[1]);
  auto n26 = gate_nand(n17, a[1]);
  auto n18 = gate_nand(a[2], a[2]);
  auto n22 = gate_nand(n18, b[2]);
  auto n24 = gate_nand(n22, b[0]);
  auto n19 = gate_nand(a[1], a[1]);
  auto n20 = gate_nand(n19, b[1]);
  auto n21 = gate_nand(n20, a[0]);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  y[0] = gate_nand(n28, n27);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_nand(b[2], b[2]);
  auto n12 = gate_nand(b[1], b[1]);
  auto n14 = gate_nand(n13, n12);
  auto n16 = gate_nand(n14, n14);
  auto n15 = gate_nand(b[0], b[0]);
  auto n20 = gate_nand(n16, n15);
  auto n18 = gate_nand(n20, a[2]);
  auto n17 = gate_nand(n20, a[1]);
  auto n19 = gate_nand(n18, n17);
  auto n22 = gate_nand(n19, n19);
  auto n21 = gate_nand(n20, a[0]);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_nand(a[0], a[0]);
  auto n8 = gate_nand(a[1], a[1]);
  auto n10 = gate_nand(n9, n8);
  auto n12 = gate_nand(n10, n10);
  auto n11 = gate_nand(a[2], a[2]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_nand(n13, n13);
}
template<> void $NameUint<3>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_nand(b[0], b[0]);
  auto n15 = gate_nand(a[1], a[1]);
  auto n17 = gate_nand(n16, n15);
  auto n22 = gate_nand(n17, n17);
  auto n19 = gate_nand(a[2], a[2]);
  auto n18 = gate_nand(b[2], b[2]);
  auto n20 = gate_nand(n19, n18);
  auto n21 = gate_nand(n20, n20);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n23, n23);
  auto n24 = gate_nand(b[1], b[1]);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_nand(n26, n26);
  auto n27 = gate_nand(a[0], a[0]);
  y[0] = gate_nand(n28, n27);
}
template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_nand(a[2], a[2]);
  auto n26 = gate_nand(n14, b[2]);
  auto n15 = gate_nand(b[1], b[0]);
  auto n17 = gate_nand(n15, a[1]);
  auto n16 = gate_nand(a[0], a[1]);
  auto n18 = gate_nand(n17, n16);
  auto n28 = gate_nand(n26, n18);
  auto n21 = gate_nand(b[1], b[1]);
  auto n19 = gate_nand(a[0], a[0]);
  auto n20 = gate_nand(b[0], n19);
  auto n24 = gate_nand(n21, n20);
  auto n22 = gate_nand(b[2], b[2]);
  auto n23 = gate_nand(a[2], n22);
  auto n25 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto _lt_x_1_n7 = gate_nand(n29, n29);
  y[0] = gate_buf(_lt_x_1_n7);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_nand(b[2], b[2]);
  auto n27 = gate_nand(n15, a[2]);
  auto n16 = gate_nand(b[1], b[0]);
  auto n18 = gate_nand(n16, a[1]);
  auto n17 = gate_nand(a[0], a[1]);
  auto n19 = gate_nand(n18, n17);
  auto n29 = gate_nand(n27, n19);
  auto n22 = gate_nand(b[1], b[1]);
  auto n20 = gate_nand(a[0], a[0]);
  auto n21 = gate_nand(b[0], n20);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_nand(a[2], a[2]);
  auto n24 = gate_nand(b[2], n23);
  auto n26 = gate_nand(n25, n24);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n29, n28);
  y[0] = gate_nand(n30, n30);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[2], a[2]);
  auto n9 = gate_nand(b[2], n1);
  auto n2 = gate_nand(a[0], a[0]);
  auto n22 = gate_nand(b[0], n2);
  auto n12 = gate_nand(b[1], b[1]);
  auto n3 = gate_nand(b[1], n1);
  auto n4 = gate_nand(n3, b[0]);
  auto n6 = gate_nand(n4, a[1]);
  auto n5 = gate_nand(b[2], a[1]);
  auto n34 = gate_nand(n6, n5);
  auto n7 = gate_nand(n34, n34);
  auto n26 = gate_nand(b[1], n7);
  auto n8 = gate_nand(n22, n26);
  auto n27 = gate_nand(n34, n12);
  auto n40 = gate_nand(n8, n27);
  auto n20 = gate_nand(n9, n40);
  auto n10 = gate_nand(a[1], a[1]);
  auto n28 = gate_nand(b[0], b[0]);
  auto n11 = gate_nand(n10, b[0]);
  auto n16 = gate_nand(n11, b[1]);
  auto n13 = gate_nand(n12, b[0]);
  auto n14 = gate_nand(n13, a[2]);
  auto n15 = gate_nand(n14, n14);
  auto n18 = gate_nand(n16, n15);
  auto n17 = gate_nand(b[2], a[2]);
  auto n38 = gate_nand(n18, n17);
  auto n19 = gate_nand(b[2], b[2]);
  auto n39 = gate_nand(n38, n19);
  auto n33 = gate_nand(n20, n39);
  auto n21 = gate_nand(n33, b[0]);
  auto n25 = gate_nand(a[0], n21);
  auto n23 = gate_nand(n22, n22);
  auto n24 = gate_nand(n33, n23);
  y[0] = gate_nand(n25, n24);
  auto n29 = gate_nand(n27, n26);
  auto n31 = gate_nand(n29, a[0]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n31, n30);
  auto n36 = gate_nand(n33, n32);
  auto n37 = gate_nand(n33, n33);
  auto n35 = gate_nand(n37, n34);
  y[1] = gate_nand(n36, n35);
  auto n43 = gate_nand(n38, n37);
  auto n41 = gate_nand(n39, n39);
  auto n42 = gate_nand(n41, n40);
  y[2] = gate_nand(n43, n42);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const Bit & one) noexcept
{
  auto n1 = gate_nand(a[0], b[0]);
  auto n3 = gate_nand(n1, b[2]);
  auto n2 = gate_nand(n1, b[0]);
  auto n27 = gate_nand(n3, n2);
  auto n7 = gate_nand(n27, n27);
  auto n4 = gate_nand(b[1], b[1]);
  auto n6 = gate_nand(n4, b[2]);
  auto n12 = gate_nand(b[2], b[2]);
  auto n5 = gate_nand(b[1], n12);
  auto n43 = gate_nand(n6, n5);
  auto n41 = gate_nand(n43, n43);
  auto n30 = gate_nand(n7, n41);
  auto n13 = gate_nand(b[0], b[0]);
  auto n10 = gate_nand(b[1], n13);
  auto n8 = gate_nand(a[0], a[0]);
  auto n33 = gate_nand(a[2], n8);
  auto n9 = gate_nand(n33, n33);
  auto n11 = gate_nand(n10, n9);
  auto n15 = gate_nand(n11, n11);
  auto n17 = gate_nand(n15, n43);
  auto n46 = gate_nand(n13, n12);
  auto n14 = gate_nand(n46, n46);
  auto n16 = gate_nand(n15, n14);
  auto n18 = gate_nand(n17, n16);
  auto n20 = gate_nand(a[1], a[1]);
  auto n59 = gate_nand(n18, n20);
  auto n21 = gate_nand(a[0], a[1]);
  auto n19 = gate_nand(a[2], a[0]);
  auto n22 = gate_nand(n20, n19);
  auto n24 = gate_nand(n21, n22);
  auto n32 = gate_nand(a[2], a[2]);
  auto n23 = gate_nand(n32, n22);
  auto n25 = gate_nand(n24, n23);
  auto n42 = gate_nand(one, n25);
  auto n29 = gate_nand(n59, n42);
  auto n28 = gate_nand(n59, n27);
  auto n47 = gate_nand(n29, n28);
  auto n31 = gate_nand(n30, n47);
  auto n38 = gate_nand(n31, b[0]);
  auto n36 = gate_nand(n38, n38);
  auto n34 = gate_nand(n32, a[0]);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_nand(n37, n37);
  auto n40 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n72 = gate_nand(n40, n39);
  auto n73 = gate_nand(a[2], n72);
  auto n57 = gate_nand(n73, n73);
  auto n45 = gate_nand(n42, n41);
  auto n44 = gate_nand(n42, n42);
  auto n52 = gate_nand(n44, n43);
  auto n60 = gate_nand(n45, n52);
  auto n50 = gate_nand(n60, n60);
  auto n51 = gate_nand(n47, n47);
  auto n48 = gate_nand(n14, n51);
  auto n49 = gate_nand(n48, n48);
  auto n53 = gate_nand(n50, n49);
  auto n55 = gate_nand(n53, n51);
  auto n54 = gate_nand(n53, n52);
  auto n64 = gate_nand(n55, n54);
  auto n68 = gate_nand(a[2], n64);
  auto n56 = gate_nand(n68, n68);
  auto n58 = gate_nand(n57, n56);
  auto n63 = gate_nand(a[2], n58);
  auto n61 = gate_nand(n59, n59);
  auto n62 = gate_nand(n61, n60);
  y[2] = gate_nand(n63, n62);
  auto n66 = gate_nand(n68, n64);
  auto n65 = gate_nand(n68, a[2]);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n67, n73);
  auto n71 = gate_nand(n69, n73);
  auto n70 = gate_nand(n69, n68);
  y[1] = gate_nand(n71, n70);
  auto n75 = gate_nand(n73, n72);
  auto n74 = gate_nand(n73, a[2]);
  y[0] = gate_nand(n75, n74);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n11, n11);
  auto n3 = gate_nand(a[1], b[0]);
  auto n1 = gate_nand(n3, n3);
  auto n2 = gate_nand(b[1], a[0]);
  auto n6 = gate_nand(n1, n2);
  auto n4 = gate_nand(n2, n2);
  auto n5 = gate_nand(n4, n3);
  y[1] = gate_nand(n6, n5);
  auto n18 = gate_nand(a[2], b[0]);
  auto n16 = gate_nand(n18, n18);
  auto n9 = gate_nand(b[1], a[1]);
  auto n7 = gate_nand(a[0], n9);
  auto n8 = gate_nand(n7, n11);
  auto n13 = gate_nand(n8, b[2]);
  auto n15 = gate_nand(n13, n9);
  auto n10 = gate_nand(a[0], b[2]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  auto n17 = gate_nand(n15, n14);
  auto n21 = gate_nand(n16, n17);
  auto n19 = gate_nand(n17, n17);
  auto n20 = gate_nand(n19, n18);
  y[2] = gate_nand(n21, n20);
}
template<> void $NameUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_nand(a[0], a[1]);
  auto n5 = gate_nand(n4, n4);
  auto n6 = gate_nand(a[2], n5);
  y[0] = gate_nand(n6, n6);
}
template<> void $NameUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_nand(a[0], a[1]);
  auto n5 = gate_nand(n4, n4);
  y[0] = gate_nand(a[2], n5);
}
template<> void $NameUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_nand(a[0], a[0]);
  auto n8 = gate_nand(a[1], a[1]);
  auto n10 = gate_nand(n9, n8);
  auto n12 = gate_nand(n10, n10);
  auto n11 = gate_nand(a[2], a[2]);
  auto n13 = gate_nand(n12, n11);
  y[0] = gate_nand(n13, n13);
}
template<> void $NameUint<3>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_nand(a[0], a[0]);
  auto n6 = gate_nand(a[1], a[1]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n8, n8);
  auto n9 = gate_nand(a[2], a[2]);
  y[0] = gate_nand(n10, n9);
}
template<> void $NameUint<3>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_nand(a[2], a[2]);
  auto n14 = gate_nand(a[0], n11);
  auto n12 = gate_nand(a[0], a[0]);
  auto n13 = gate_nand(a[2], n12);
  auto n17 = gate_nand(n14, n13);
  auto n16 = gate_nand(n17, n17);
  auto n15 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(n16, n15);
  auto n18 = gate_nand(n17, a[1]);
  y[0] = gate_nand(n19, n18);
}
template<> void $NameUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_nand(a[2], a[2]);
  auto n13 = gate_nand(a[0], n10);
  auto n11 = gate_nand(a[0], a[0]);
  auto n12 = gate_nand(a[2], n11);
  auto n16 = gate_nand(n13, n12);
  auto n14 = gate_nand(n16, n16);
  auto n18 = gate_nand(n14, a[1]);
  auto n15 = gate_nand(a[1], a[1]);
  auto n17 = gate_nand(n16, n15);
  y[0] = gate_nand(n18, n17);
}
template<> void $NameUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n33 = gate_nand(b[0], b[0]);
  auto n24 = gate_nand(a[0], n33);
  auto n41 = gate_nand(n24, n24);
  auto n37 = gate_nand(b[2], b[2]);
  auto n40 = gate_nand(b[1], b[1]);
  auto n25 = gate_nand(n37, n40);
  auto n27 = gate_nand(n25, n25);
  auto n26 = gate_nand(n41, n27);
  y[0] = gate_nand(n26, n26);
  auto n29 = gate_nand(n27, a[1]);
  auto n28 = gate_nand(n27, b[0]);
  auto n30 = gate_nand(n29, n28);
  auto n32 = gate_nand(n30, n33);
  auto n31 = gate_nand(n30, a[0]);
  y[1] = gate_nand(n32, n31);
  auto n35 = gate_nand(n33, a[2]);
  auto n34 = gate_nand(b[0], a[1]);
  auto n36 = gate_nand(n35, n34);
  auto n39 = gate_nand(n37, n36);
  auto n38 = gate_nand(n37, b[1]);
  auto n42 = gate_nand(n39, n38);
  auto n44 = gate_nand(n42, n40);
  auto n43 = gate_nand(n42, n41);
  y[2] = gate_nand(n44, n43);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n35 = gate_nand(b[2], b[2]);
  auto n42 = gate_nand(b[0], b[0]);
  auto n26 = gate_nand(n42, a[0]);
  auto n25 = gate_nand(b[0], a[1]);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n35, n27);
  auto n28 = gate_nand(n35, b[1]);
  auto n31 = gate_nand(n29, n28);
  auto n34 = gate_nand(b[1], b[1]);
  auto n33 = gate_nand(n31, n34);
  auto n30 = gate_nand(a[2], n42);
  auto n37 = gate_nand(n30, n30);
  auto n32 = gate_nand(n31, n37);
  y[0] = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n39 = gate_nand(n36, n36);
  auto n38 = gate_nand(n37, n39);
  y[2] = gate_nand(n38, n38);
  auto n41 = gate_nand(n39, a[1]);
  auto n40 = gate_nand(n39, b[0]);
  auto n43 = gate_nand(n41, n40);
  auto n45 = gate_nand(n43, n42);
  auto n44 = gate_nand(n43, a[2]);
  y[1] = gate_nand(n45, n44);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n20 = gate_nand(b[1], b[1]);
  auto n19 = gate_nand(b[2], b[2]);
  auto n25 = gate_nand(n20, n19);
  auto n29 = gate_nand(n25, n25);
  auto n26 = gate_nand(b[0], b[0]);
  auto n21 = gate_nand(n29, n26);
  auto n24 = gate_nand(n21, a[2]);
  auto n22 = gate_nand(n21, n21);
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
  auto n26 = gate_nand(b[0], b[0]);
  auto n28 = gate_nand(n26, a[0]);
  auto n27 = gate_nand(a[0], a[0]);
  auto n32 = gate_nand(b[0], n27);
  y[0] = gate_nand(n28, n32);
  auto n29 = gate_nand(b[1], b[1]);
  auto n41 = gate_nand(a[1], n29);
  auto n31 = gate_nand(n41, n29);
  auto n30 = gate_nand(n41, a[1]);
  auto n33 = gate_nand(n31, n30);
  auto n40 = gate_nand(n33, n32);
  auto n35 = gate_nand(n40, n32);
  auto n34 = gate_nand(n40, n33);
  y[1] = gate_nand(n35, n34);
  auto n36 = gate_nand(b[2], b[2]);
  auto n39 = gate_nand(a[2], n36);
  auto n37 = gate_nand(a[2], a[2]);
  auto n38 = gate_nand(b[2], n37);
  auto n45 = gate_nand(n39, n38);
  auto n43 = gate_nand(n45, n45);
  auto n44 = gate_nand(n41, n40);
  auto n42 = gate_nand(n44, n44);
  auto n47 = gate_nand(n43, n42);
  auto n46 = gate_nand(n45, n44);
  y[2] = gate_nand(n47, n46);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n12 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(a[0], n12);
  auto n13 = gate_nand(a[0], a[0]);
  auto n10 = gate_nand(a[1], n13);
  y[1] = gate_nand(n11, n10);
  auto n16 = gate_nand(n13, n12);
  auto n14 = gate_nand(n16, n16);
  auto n18 = gate_nand(n14, a[2]);
  auto n15 = gate_nand(a[2], a[2]);
  auto n17 = gate_nand(n16, n15);
  y[2] = gate_nand(n18, n17);
}
