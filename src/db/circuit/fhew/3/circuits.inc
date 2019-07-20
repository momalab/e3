template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n45 = gate_nor(b[0], a[0]);
  auto n46 = gate_nor(b[1], a[1]);
  auto n49 = gate_not(b[0]);
  auto n48 = gate_not(a[0]);
  auto n52 = gate_or(n49, n48);
  auto n51 = gate_not(b[1]);
  auto n50 = gate_not(a[1]);
  auto n40 = gate_nor(n51, n50);
  auto n53 = gate_or(n40, n46);
  auto n47 = gate_nor(n52, n53);
  auto n61 = gate_not(n52);
  y[0] = gate_nor(n61, n45);
  auto n54 = gate_not(n53);
  auto n36 = gate_nor(n61, n54);
  y[1] = gate_nor(n47, n36);
  auto n55 = gate_not(b[2]);
  auto n44 = gate_nor(a[2], n55);
  auto n56 = gate_not(a[2]);
  auto n37 = gate_nor(b[2], n56);
  auto n58 = gate_or(n44, n37);
  auto n59 = gate_not(n58);
  auto n57 = gate_or(n40, n47);
  auto n43 = gate_nor(n58, n57);
  auto n60 = gate_not(n57);
  auto n42 = gate_nor(n60, n59);
  y[2] = gate_nor(n43, n42);
}
template<> void $NameUint<3>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[2]);
  auto n17 = gate_not(b[0]);
  auto n13 = gate_not(b[2]);
  y[2] = gate_nor(n14, n13);
  auto n16 = gate_not(a[1]);
  auto n15 = gate_not(b[1]);
  y[1] = gate_nor(n16, n15);
  auto n18 = gate_not(a[0]);
  y[0] = gate_nor(n18, n17);
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
  auto n25 = gate_not(b[2]);
  auto n23 = gate_nor(a[2], n25);
  auto n26 = gate_not(a[2]);
  auto n20 = gate_nor(b[2], n26);
  y[2] = gate_or(n23, n20);
  auto n27 = gate_not(b[1]);
  auto n22 = gate_nor(a[1], n27);
  auto n28 = gate_not(a[1]);
  auto n21 = gate_nor(b[1], n28);
  y[1] = gate_or(n22, n21);
  auto n29 = gate_not(b[0]);
  auto n24 = gate_nor(a[0], n29);
  auto n30 = gate_not(a[0]);
  auto n19 = gate_nor(b[0], n30);
  y[0] = gate_or(n24, n19);
}
template<> void $NameUint<3>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[0]);
  auto n13 = gate_not(b[2]);
  y[2] = gate_nor(n14, n13);
  auto n11 = gate_not(b[0]);
  y[0] = gate_nor(n14, n11);
  auto n12 = gate_not(b[1]);
  y[1] = gate_nor(n14, n12);
}
template<> void $NameUint<3>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n23 = gate_nor(a[0], c[2]);
  auto n26 = gate_not(a[0]);
  auto n17 = gate_nor(b[0], n26);
  auto n21 = gate_nor(b[2], n26);
  y[2] = gate_nor(n21, n23);
  auto n22 = gate_nor(b[1], n26);
  auto n24 = gate_nor(a[0], c[1]);
  y[1] = gate_nor(n22, n24);
  auto n25 = gate_nor(a[0], c[0]);
  y[0] = gate_nor(n17, n25);
}
template<> void $NameUint<3>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n18 = gate_or(a[0], a[1]);
  auto n14 = gate_nor(a[2], n18);
  auto n17 = gate_not(n18);
  auto n15 = gate_not(a[1]);
  auto n12 = gate_nor(y[0], n15);
  y[1] = gate_or(n17, n12);
  auto n16 = gate_not(a[2]);
  auto n13 = gate_nor(n17, n16);
  y[2] = gate_or(n13, n14);
}
template<> void $NameUint<3>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[0]);
  auto n25 = gate_or(b[2], b[1]);
  auto n8 = gate_nor(a[1], n24);
  auto n10 = gate_nor(n24, a[2]);
  y[2] = gate_nor(n10, n25);
  auto n18 = gate_not(b[1]);
  auto n12 = gate_nor(a[2], n18);
  auto n13 = gate_or(n8, n12);
  auto n17 = gate_or(b[2], n13);
  auto n9 = gate_nor(n24, n17);
  y[1] = gate_not(n17);
  auto n16 = gate_or(y[1], b[2]);
  auto n14 = gate_not(a[2]);
  auto n15 = gate_or(n18, n14);
  auto n6 = gate_nor(n16, n15);
  auto n19 = gate_not(a[1]);
  auto n5 = gate_nor(n19, n9);
  auto n7 = gate_nor(n5, n18);
  auto n21 = gate_or(a[0], n24);
  auto n20 = gate_or(b[1], n19);
  auto n22 = gate_not(b[2]);
  auto n2 = gate_nor(n20, n22);
  auto n1 = gate_nor(n21, n2);
  auto n11 = gate_nor(a[2], n22);
  auto n23 = gate_or(n1, n11);
  auto n3 = gate_nor(n7, n23);
  y[0] = gate_or(n6, n3);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n32 = gate_not(a[2]);
  auto n2 = gate_nor(b[2], n32);
  auto n28 = gate_or(a[0], a[1]);
  auto n46 = gate_or(n32, n28);
  auto n29 = gate_not(b[1]);
  auto n24 = gate_nor(b[2], n29);
  auto n31 = gate_not(b[2]);
  auto n3 = gate_nor(b[1], n31);
  auto n22 = gate_nor(a[2], n31);
  auto n23 = gate_nor(n2, n22);
  auto n45 = gate_or(n24, n3);
  auto n16 = gate_nor(b[0], n45);
  auto n30 = gate_or(n46, n45);
  auto n39 = gate_not(b[0]);
  auto n6 = gate_nor(n30, n39);
  auto n55 = gate_or(b[2], b[0]);
  auto n56 = gate_or(n55, n24);
  auto n13 = gate_nor(n56, n23);
  auto n41 = gate_not(n55);
  auto n40 = gate_not(a[0]);
  auto n11 = gate_nor(n40, n39);
  auto n35 = gate_or(n32, n40);
  auto n18 = gate_nor(a[1], n35);
  auto n34 = gate_not(n35);
  auto n33 = gate_not(a[1]);
  auto n7 = gate_nor(n34, n33);
  auto n44 = gate_or(n7, n18);
  auto n36 = gate_not(n44);
  auto n8 = gate_nor(n36, n39);
  auto n47 = gate_or(n41, n8);
  auto n9 = gate_nor(n16, n47);
  auto n38 = gate_not(n46);
  auto n37 = gate_not(n47);
  auto n27 = gate_nor(n45, n37);
  auto n10 = gate_nor(n38, n27);
  auto n54 = gate_or(n9, n10);
  auto n51 = gate_not(n54);
  auto n26 = gate_nor(n51, n45);
  auto n42 = gate_or(n41, n11);
  auto n15 = gate_nor(n26, n42);
  auto n43 = gate_not(n42);
  auto n25 = gate_nor(n45, n43);
  auto n20 = gate_nor(n44, n25);
  auto n5 = gate_nor(n15, n20);
  auto n49 = gate_not(n45);
  auto n48 = gate_or(n47, n46);
  auto n21 = gate_nor(n49, n48);
  auto n50 = gate_or(n5, n21);
  auto n17 = gate_nor(n50, n51);
  auto n12 = gate_nor(n23, n17);
  y[2] = gate_or(n6, n12);
  auto n57 = gate_not(n50);
  y[0] = gate_nor(n57, n13);
  auto n53 = gate_or(n57, n23);
  auto n19 = gate_nor(n54, n53);
  auto n52 = gate_not(n53);
  auto n1 = gate_nor(n52, n51);
  y[1] = gate_nor(n1, n19);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n32 = gate_not(b[2]);
  auto n29 = gate_nor(a[2], n32);
  auto n33 = gate_not(a[2]);
  auto n25 = gate_nor(b[2], n33);
  auto n41 = gate_or(n29, n25);
  auto n34 = gate_not(b[1]);
  auto n30 = gate_nor(a[1], n34);
  auto n35 = gate_not(a[1]);
  auto n26 = gate_nor(b[1], n35);
  auto n39 = gate_or(n30, n26);
  auto n36 = gate_not(b[0]);
  auto n31 = gate_nor(a[0], n36);
  auto n37 = gate_not(a[0]);
  auto n28 = gate_nor(b[0], n37);
  auto n38 = gate_or(n31, n28);
  auto n40 = gate_or(n39, n38);
  y[0] = gate_nor(n41, n40);
}
template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(b[2]);
  auto n27 = gate_nor(n28, a[2]);
  auto n29 = gate_not(b[0]);
  auto n32 = gate_or(n29, a[0]);
  auto n26 = gate_nor(a[1], n32);
  auto n22 = gate_nor(b[1], n26);
  auto n31 = gate_not(n32);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nor(n31, n30);
  auto n21 = gate_nor(n24, n22);
  auto n25 = gate_nor(n27, n21);
  auto n33 = gate_not(a[2]);
  auto n23 = gate_nor(b[2], n33);
  y[0] = gate_or(n25, n23);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(b[2]);
  auto n34 = gate_not(a[2]);
  auto n23 = gate_nor(b[2], n34);
  auto n27 = gate_nor(n28, a[2]);
  auto n29 = gate_not(b[0]);
  auto n32 = gate_or(n29, a[0]);
  auto n26 = gate_nor(a[1], n32);
  auto n22 = gate_nor(b[1], n26);
  auto n31 = gate_not(n32);
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nor(n31, n30);
  auto n33 = gate_or(n24, n22);
  auto n25 = gate_nor(n27, n33);
  y[0] = gate_nor(n25, n23);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[2]);
  auto n25 = gate_nor(n27, a[2]);
  auto n28 = gate_not(a[0]);
  auto n31 = gate_or(n28, b[0]);
  auto n26 = gate_nor(b[1], n31);
  auto n21 = gate_nor(a[1], n26);
  auto n30 = gate_not(n31);
  auto n29 = gate_not(b[1]);
  auto n22 = gate_nor(n30, n29);
  auto n32 = gate_or(n22, n21);
  auto n24 = gate_nor(n25, n32);
  auto n33 = gate_not(a[2]);
  auto n23 = gate_nor(b[2], n33);
  y[0] = gate_or(n24, n23);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[2]);
  auto n23 = gate_nor(n27, b[2]);
  auto n28 = gate_not(a[0]);
  auto n31 = gate_or(n28, b[0]);
  auto n26 = gate_nor(b[1], n31);
  auto n21 = gate_nor(a[1], n26);
  auto n30 = gate_not(n31);
  auto n29 = gate_not(b[1]);
  auto n24 = gate_nor(n30, n29);
  auto n32 = gate_or(n24, n21);
  auto n22 = gate_nor(n23, n32);
  auto n33 = gate_not(b[2]);
  auto n25 = gate_nor(a[2], n33);
  auto _gt_x_1_n40 = gate_or(n22, n25);
  y[0] = gate_buf(_gt_x_1_n40);
}
template<> void $NameUint<3>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_nor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  auto n17 = gate_not(a[1]);
  auto n20 = gate_or(y[0], n17);
  auto n16 = gate_nor(a[2], n20);
  auto n19 = gate_not(n20);
  y[1] = gate_nor(n19, n15);
  auto n18 = gate_not(a[2]);
  auto n13 = gate_nor(n19, n18);
  y[2] = gate_or(n13, n16);
}
template<> void $NameUint<3>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(a[1]);
  auto n25 = gate_nor(b[1], n29);
  auto n30 = gate_not(b[1]);
  auto n26 = gate_nor(a[1], n30);
  auto n38 = gate_or(n25, n26);
  auto n31 = gate_not(b[0]);
  auto n28 = gate_nor(a[0], n31);
  auto n32 = gate_not(a[0]);
  auto n23 = gate_nor(b[0], n32);
  auto n36 = gate_or(n28, n23);
  auto n33 = gate_not(a[2]);
  auto n24 = gate_nor(b[2], n33);
  auto n34 = gate_not(b[2]);
  auto n27 = gate_nor(a[2], n34);
  auto n35 = gate_or(n24, n27);
  auto n37 = gate_or(n36, n35);
  auto _ne_x_1_n26 = gate_or(n38, n37);
  y[0] = gate_buf(_ne_x_1_n26);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n28 = gate_or(a[1], a[0]);
  auto n29 = gate_or(a[2], n28);
  auto n30 = gate_not(n29);
  auto n22 = gate_nor(n30, b[2]);
  auto n23 = gate_nor(n30, b[1]);
  auto n24 = gate_nor(n30, b[0]);
  auto n25 = gate_nor(c[2], n29);
  y[2] = gate_nor(n25, n22);
  auto n26 = gate_nor(c[1], n29);
  y[1] = gate_nor(n26, n23);
  auto n27 = gate_nor(c[0], n29);
  y[0] = gate_nor(n27, n24);
}
template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[2]);
  auto n23 = gate_nor(n27, b[2]);
  auto n28 = gate_not(a[0]);
  auto n31 = gate_or(n28, b[0]);
  auto n25 = gate_nor(b[1], n31);
  auto n20 = gate_nor(a[1], n25);
  auto n30 = gate_not(n31);
  auto n29 = gate_not(b[1]);
  auto n21 = gate_nor(n30, n29);
  auto n22 = gate_nor(n21, n20);
  auto n24 = gate_nor(n23, n22);
  auto n32 = gate_not(b[2]);
  auto n26 = gate_nor(a[2], n32);
  auto _lte_x_1_n7 = gate_or(n24, n26);
  y[0] = gate_buf(_lte_x_1_n7);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(b[2]);
  auto n27 = gate_nor(n28, a[2]);
  auto n29 = gate_not(a[0]);
  auto n32 = gate_or(n29, b[0]);
  auto n26 = gate_nor(b[1], n32);
  auto n21 = gate_nor(a[1], n26);
  auto n31 = gate_not(n32);
  auto n30 = gate_not(b[1]);
  auto n25 = gate_nor(n31, n30);
  auto n22 = gate_nor(n25, n21);
  auto n24 = gate_nor(n27, n22);
  auto n33 = gate_not(a[2]);
  auto n23 = gate_nor(b[2], n33);
  y[0] = gate_or(n24, n23);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_or(a[1], a[0]);
  auto n12 = gate_or(b[1], b[0]);
  auto n8 = gate_nor(a[2], n11);
  auto n10 = gate_nor(b[2], n12);
  y[0] = gate_nor(n8, n10);
}
template<> void $NameUint<3>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_or(a[1], a[0]);
  y[0] = gate_nor(a[2], n5);
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
  auto n26 = gate_not(a[2]);
  auto n23 = gate_nor(n26, b[2]);
  auto n27 = gate_not(b[0]);
  auto n30 = gate_or(n27, a[0]);
  auto n24 = gate_nor(a[1], n30);
  auto n22 = gate_nor(b[1], n24);
  auto n29 = gate_not(n30);
  auto n28 = gate_not(a[1]);
  auto n21 = gate_nor(n29, n28);
  auto n31 = gate_or(n21, n22);
  auto n20 = gate_nor(n23, n31);
  auto n32 = gate_not(b[2]);
  auto n25 = gate_nor(a[2], n32);
  auto _lt_x_1_n7 = gate_or(n20, n25);
  y[0] = gate_buf(_lt_x_1_n7);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[2]);
  auto n26 = gate_nor(n27, a[2]);
  auto n28 = gate_not(b[0]);
  auto n31 = gate_or(n28, a[0]);
  auto n25 = gate_nor(a[1], n31);
  auto n21 = gate_nor(b[1], n25);
  auto n30 = gate_not(n31);
  auto n29 = gate_not(a[1]);
  auto n23 = gate_nor(n30, n29);
  auto n32 = gate_or(n23, n21);
  auto n24 = gate_nor(n26, n32);
  auto n33 = gate_not(a[2]);
  auto n22 = gate_nor(b[2], n33);
  y[0] = gate_or(n24, n22);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[0]);
  auto n12 = gate_nor(a[1], n30);
  auto n35 = gate_not(b[1]);
  auto n11 = gate_nor(a[2], n35);
  auto n21 = gate_or(a[0], n30);
  auto n18 = gate_nor(n35, n21);
  auto n19 = gate_or(b[2], n11);
  auto n2 = gate_nor(n30, n19);
  auto n20 = gate_not(a[1]);
  auto n34 = gate_or(n2, n20);
  auto n38 = gate_not(n34);
  auto n36 = gate_not(n21);
  auto n5 = gate_nor(b[1], n36);
  auto n3 = gate_nor(n38, n5);
  auto n28 = gate_or(n18, n3);
  auto n15 = gate_nor(b[2], n28);
  auto n23 = gate_not(n28);
  auto n22 = gate_not(b[2]);
  auto n9 = gate_nor(n23, n22);
  auto n10 = gate_nor(n9, n15);
  auto n27 = gate_not(a[2]);
  auto n24 = gate_or(b[2], n30);
  auto n16 = gate_nor(n24, b[1]);
  auto n25 = gate_or(b[2], n12);
  auto n4 = gate_nor(n35, n25);
  auto n26 = gate_or(n16, n4);
  auto n41 = gate_or(n27, n26);
  y[2] = gate_nor(n41, n10);
  auto n29 = gate_not(n41);
  auto n6 = gate_nor(n29, n15);
  auto n40 = gate_or(n9, n6);
  auto n7 = gate_nor(n5, n40);
  auto n14 = gate_nor(n7, n34);
  auto n33 = gate_or(n30, n40);
  auto n17 = gate_nor(a[0], n33);
  auto n32 = gate_not(n33);
  auto n31 = gate_not(a[0]);
  auto n8 = gate_nor(n32, n31);
  y[0] = gate_or(n8, n17);
  auto n37 = gate_or(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n1 = gate_nor(n40, n39);
  y[1] = gate_or(n14, n1);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_nor(b[0], b[2]);
  auto n65 = gate_not(a[0]);
  auto n70 = gate_not(b[0]);
  auto n4 = gate_nor(n65, n70);
  auto n36 = gate_or(n30, n4);
  auto n32 = gate_not(n36);
  auto n37 = gate_not(b[1]);
  auto n29 = gate_nor(b[2], n37);
  auto n31 = gate_not(b[2]);
  auto n14 = gate_nor(b[1], n31);
  auto n35 = gate_or(n29, n14);
  auto n2 = gate_nor(n32, n35);
  auto n18 = gate_nor(n70, n35);
  auto n69 = gate_not(a[2]);
  auto n13 = gate_nor(a[1], n69);
  auto n33 = gate_or(n69, n65);
  auto n27 = gate_nor(a[1], n33);
  auto n34 = gate_not(n33);
  auto n63 = gate_not(a[1]);
  auto n16 = gate_nor(n34, n63);
  auto n17 = gate_nor(n27, n16);
  auto n24 = gate_nor(a[2], n63);
  auto n49 = gate_or(n18, n17);
  auto n25 = gate_nor(a[2], n49);
  auto n50 = gate_not(n49);
  auto n1 = gate_nor(n50, n69);
  auto n12 = gate_nor(n2, n50);
  auto n67 = gate_not(n35);
  auto n21 = gate_nor(n67, n36);
  auto n42 = gate_or(n12, n21);
  auto n66 = gate_or(a[0], a[1]);
  auto n39 = gate_or(n70, b[2]);
  auto n28 = gate_nor(b[1], n39);
  auto n38 = gate_not(n39);
  auto n8 = gate_nor(n38, n37);
  auto n40 = gate_or(n8, n28);
  auto n41 = gate_or(n66, n40);
  auto n58 = gate_or(n42, n41);
  auto n44 = gate_not(n41);
  auto n43 = gate_not(n42);
  auto n15 = gate_nor(n44, n43);
  auto n46 = gate_or(n15, n70);
  auto n45 = gate_or(n69, n46);
  auto n10 = gate_nor(n45, n65);
  auto n47 = gate_not(n46);
  auto n48 = gate_or(n47, n69);
  auto n20 = gate_nor(n48, a[0]);
  auto n61 = gate_or(n10, n20);
  auto n57 = gate_not(n61);
  auto n53 = gate_or(n25, n1);
  auto n51 = gate_or(n2, n21);
  auto n52 = gate_or(n15, n51);
  auto n23 = gate_nor(n53, n52);
  auto n55 = gate_not(n52);
  auto n54 = gate_not(n53);
  auto n5 = gate_nor(n55, n54);
  auto n60 = gate_or(n23, n5);
  auto n22 = gate_nor(n61, n60);
  auto n56 = gate_not(n60);
  auto n59 = gate_or(n57, n56);
  auto n26 = gate_nor(n58, n59);
  auto n62 = gate_not(n59);
  auto n3 = gate_nor(n62, n69);
  y[1] = gate_nor(n62, n22);
  y[2] = gate_or(n26, n3);
  auto n64 = gate_or(n13, n24);
  auto n19 = gate_nor(n67, n64);
  auto n7 = gate_nor(n19, n70);
  auto n11 = gate_nor(n65, n7);
  auto n68 = gate_or(n67, n66);
  auto n71 = gate_or(n69, n68);
  auto n6 = gate_nor(n71, n70);
  y[0] = gate_or(n11, n6);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n11 = gate_nor(b[2], b[0]);
  auto n16 = gate_not(b[0]);
  auto n21 = gate_not(a[0]);
  y[0] = gate_nor(n16, n21);
  auto n7 = gate_nor(n11, n21);
  auto n19 = gate_not(a[1]);
  auto n14 = gate_or(n16, n19);
  auto n12 = gate_not(n14);
  auto n18 = gate_not(b[1]);
  auto n13 = gate_or(n18, n21);
  auto n4 = gate_nor(n12, n13);
  auto n15 = gate_not(n13);
  auto n10 = gate_nor(n15, n14);
  y[1] = gate_or(n4, n10);
  auto n17 = gate_not(a[2]);
  auto n26 = gate_or(n17, n16);
  auto n24 = gate_not(n26);
  auto n20 = gate_or(n19, n18);
  auto n2 = gate_nor(n7, n20);
  auto n8 = gate_nor(n20, b[0]);
  auto n22 = gate_not(b[2]);
  auto n23 = gate_or(n22, n21);
  auto n3 = gate_nor(n8, n23);
  auto n25 = gate_or(n2, n3);
  auto n27 = gate_not(n25);
  auto n6 = gate_nor(n24, n25);
  auto n9 = gate_nor(n27, n26);
  y[2] = gate_nor(n6, n9);
}
template<> void $NameUint<3>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n8 = gate_not(a[0]);
  auto n7 = gate_not(a[2]);
  auto n9 = gate_or(n8, n7);
  y[0] = gate_nor(n10, n9);
}
template<> void $NameUint<3>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[1]);
  auto n7 = gate_not(a[0]);
  auto n6 = gate_not(a[2]);
  auto n8 = gate_or(n7, n6);
  y[0] = gate_or(n9, n8);
}
template<> void $NameUint<3>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_or(a[1], a[0]);
  y[0] = gate_nor(a[2], n5);
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
  auto n21 = gate_not(a[2]);
  auto n17 = gate_nor(a[0], n21);
  auto n22 = gate_not(a[0]);
  auto n20 = gate_nor(a[2], n22);
  auto n24 = gate_or(n17, n20);
  auto n25 = gate_not(n24);
  auto n19 = gate_nor(a[1], n25);
  auto n23 = gate_not(a[1]);
  auto n18 = gate_nor(n24, n23);
  y[0] = gate_nor(n18, n19);
}
template<> void $NameUint<3>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n18 = gate_not(a[2]);
  auto n14 = gate_nor(a[0], n18);
  auto n19 = gate_not(a[0]);
  auto n17 = gate_nor(a[2], n19);
  auto n21 = gate_or(n14, n17);
  auto n20 = gate_not(a[1]);
  auto n15 = gate_nor(n21, n20);
  auto n22 = gate_not(n21);
  auto n16 = gate_nor(a[1], n22);
  y[0] = gate_or(n15, n16);
}
template<> void $NameUint<3>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_nor(b[0], a[2]);
  auto n35 = gate_nor(a[1], b[0]);
  auto n40 = gate_not(a[0]);
  auto n45 = gate_or(b[0], n40);
  auto n42 = gate_or(b[2], b[1]);
  y[0] = gate_nor(n45, n42);
  auto n43 = gate_not(b[0]);
  auto n34 = gate_nor(a[1], n43);
  auto n36 = gate_nor(a[0], n43);
  auto n41 = gate_or(n35, n36);
  y[1] = gate_nor(n42, n41);
  auto n44 = gate_or(n34, n30);
  auto n33 = gate_nor(b[1], n44);
  auto n46 = gate_not(b[1]);
  auto n31 = gate_nor(n46, n45);
  auto n32 = gate_nor(n33, n31);
  y[2] = gate_nor(b[2], n32);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_nor(b[0], a[0]);
  auto n35 = gate_nor(a[1], b[0]);
  auto n42 = gate_or(b[2], b[1]);
  auto n43 = gate_not(b[0]);
  auto n34 = gate_nor(a[1], n43);
  auto n36 = gate_nor(a[2], n43);
  auto n40 = gate_or(n35, n36);
  y[1] = gate_nor(n42, n40);
  auto n41 = gate_not(a[2]);
  auto n45 = gate_or(b[0], n41);
  y[2] = gate_nor(n45, n42);
  auto n44 = gate_or(n34, n30);
  auto n33 = gate_nor(b[1], n44);
  auto n46 = gate_not(b[1]);
  auto n31 = gate_nor(n46, n45);
  auto n32 = gate_nor(n33, n31);
  y[0] = gate_nor(b[2], n32);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n25 = gate_nor(b[0], a[0]);
  auto n28 = gate_not(b[0]);
  auto n26 = gate_nor(a[1], n28);
  auto n29 = gate_or(n26, n25);
  auto n31 = gate_or(b[2], b[1]);
  auto n27 = gate_nor(n29, n31);
  auto n30 = gate_not(n31);
  auto n32 = gate_not(a[2]);
  auto n23 = gate_nor(n30, n32);
  y[0] = gate_or(n27, n23);
  auto n35 = gate_or(b[0], n31);
  auto n33 = gate_not(n35);
  auto n22 = gate_nor(n33, n32);
  auto n34 = gate_not(a[1]);
  auto n24 = gate_nor(n35, n34);
  y[1] = gate_or(n22, n24);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n44 = gate_not(b[0]);
  auto n50 = gate_or(a[0], n44);
  auto n48 = gate_not(n50);
  auto n45 = gate_not(a[0]);
  auto n34 = gate_nor(b[0], n45);
  y[0] = gate_or(n48, n34);
  auto n46 = gate_not(a[1]);
  auto n37 = gate_nor(b[1], n46);
  auto n47 = gate_not(b[1]);
  auto n41 = gate_nor(a[1], n47);
  auto n49 = gate_or(n37, n41);
  auto n36 = gate_nor(n48, n49);
  auto n51 = gate_not(n49);
  auto n43 = gate_nor(n51, n50);
  y[1] = gate_nor(n36, n43);
  auto n52 = gate_not(b[2]);
  auto n40 = gate_nor(a[2], n52);
  auto n53 = gate_not(a[2]);
  auto n35 = gate_nor(b[2], n53);
  auto n55 = gate_or(n40, n35);
  auto n54 = gate_or(n37, n36);
  auto n42 = gate_nor(n55, n54);
  auto n57 = gate_not(n54);
  auto n56 = gate_not(n55);
  auto n38 = gate_nor(n57, n56);
  y[2] = gate_or(n42, n38);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n19 = gate_not(a[0]);
  auto n18 = gate_nor(a[1], n19);
  auto n20 = gate_not(a[1]);
  auto n16 = gate_nor(a[0], n20);
  y[1] = gate_or(n18, n16);
  auto n23 = gate_or(a[1], a[0]);
  auto n17 = gate_nor(a[2], n23);
  auto n22 = gate_not(n23);
  auto n21 = gate_not(a[2]);
  auto n14 = gate_nor(n22, n21);
  y[2] = gate_nor(n14, n17);
}
