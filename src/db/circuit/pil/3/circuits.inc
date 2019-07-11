template<> void $NameUint<3>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_and(b[0], a[0]);
  auto n7 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n8, n7);
  auto n10 = gate_and(n8, n7);
  auto n9 = gate_and(b[1], a[1]);
  auto n12 = gate_or(n10, n9);
  auto n11 = gate_xor(a[2], b[2]);
  y[2] = gate_xor(n12, n11);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n9);
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
template<> void $NameUint<3>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  y[2] = gate_buf(zero);
  auto n6 = gate_and(a[1], N0);
  auto n7 = gate_xor(a[1], N0);
  auto n5 = gate_and(n7, a[2]);
  y[1] = gate_or(n6, n5);
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
template<> void $NameUint<3>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_xor(b[1], a[1]);
  auto n5 = gate_and(b[0], a[0]);
  y[1] = gate_xor(n6, n5);
  auto _add_x_1_n9 = gate_xor(b[0], a[0]);
  auto n8 = gate_and(b[1], a[1]);
  auto n7 = gate_and(n6, n5);
  auto _add_x_1_n11 = gate_or(n8, n7);
  y[2] = gate_buf(_add_x_1_n11);
  y[0] = gate_buf(_add_x_1_n9);
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
  auto n23 = gate_not(b[2]);
  auto n9 = gate_not(a[1]);
  auto n10 = gate_not(a[2]);
  auto n17 = gate_not(b[1]);
  auto n11 = gate_and(n23, n17);
  auto n12 = gate_not(n11);
  auto n15 = gate_and(a[2], n12);
  auto n16 = gate_not(a[0]);
  auto n19 = gate_and(b[0], n16);
  auto n18 = gate_not(n19);
  auto n1 = gate_nand(n18, n17);
  auto n2 = gate_nand(b[0], n10);
  auto n3 = gate_nand(b[0], n9);
  auto n4 = gate_nand(b[1], n10);
  auto n6 = gate_nand(n19, b[1]);
  auto n13 = gate_and(n23, n3);
  y[1] = gate_and(n13, n4);
  y[2] = gate_and(n11, n2);
  auto n14 = gate_not(n13);
  auto n21 = gate_and(n15, n14);
  auto n5 = gate_nand(y[1], b[0]);
  auto n20 = gate_and(a[1], n5);
  auto n7 = gate_nand(n20, n6);
  auto n22 = gate_and(n1, n7);
  auto n24 = gate_not(n22);
  auto n25 = gate_and(n24, n23);
  auto n8 = gate_nand(n22, b[2]);
  auto n26 = gate_and(n21, n8);
  y[0] = gate_or(n26, n25);
}
template<> void $NameUint<3>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(b[0], a[0]);
  auto n7 = gate_not(a[1]);
  auto n9 = gate_and(a[2], n7);
  auto n8 = gate_not(a[0]);
  auto n16 = gate_and(n9, n8);
  auto n25 = gate_xor(b[1], b[2]);
  auto n22 = gate_not(n25);
  auto n14 = gate_and(b[0], n22);
  auto n35 = gate_and(n16, n14);
  auto n40 = gate_xor(a[2], b[2]);
  auto n11 = gate_not(b[2]);
  auto n10 = gate_not(b[0]);
  auto n39 = gate_and(n11, n10);
  auto n13 = gate_not(n39);
  auto n23 = gate_and(n13, n1);
  auto n12 = gate_and(a[2], a[0]);
  auto n21 = gate_xor(n12, a[1]);
  auto n15 = gate_not(n14);
  auto n29 = gate_and(n16, n15);
  auto n18 = gate_not(n29);
  auto n19 = gate_and(n25, n18);
  auto n38 = gate_not(b[1]);
  auto n41 = gate_and(n39, n38);
  auto n43 = gate_and(n41, n40);
  auto n3 = gate_nand(b[0], n21);
  auto n6 = gate_nand(n22, n29);
  auto n17 = gate_and(n13, n3);
  auto n20 = gate_and(n17, n6);
  auto n31 = gate_or(n20, n19);
  auto n24 = gate_and(n31, n21);
  auto n26 = gate_not(n24);
  auto n27 = gate_and(n26, n25);
  auto n32 = gate_not(n31);
  auto n36 = gate_xor(n32, n40);
  auto n2 = gate_nand(n24, n22);
  auto n5 = gate_nand(n31, n29);
  auto n28 = gate_and(n23, n2);
  auto n30 = gate_or(n28, n27);
  auto n42 = gate_and(n30, n5);
  auto n37 = gate_and(n40, n42);
  auto n33 = gate_and(n37, n36);
  auto n34 = gate_xor(n40, n33);
  y[2] = gate_xor(n35, n34);
  y[1] = gate_xor(n37, n36);
  y[0] = gate_xnor(n43, n42);
}
template<> void $NameUint<3>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n12 = gate_xor(n9, b[0]);
  auto n10 = gate_not(b[2]);
  auto n11 = gate_xor(n10, a[2]);
  auto n15 = gate_and(n12, n11);
  auto n13 = gate_not(a[1]);
  auto n14 = gate_xor(n13, b[1]);
  y[0] = gate_and(n15, n14);
}
template<> void $NameUint<3>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[2]);
  auto n24 = gate_not(a[0]);
  auto n26 = gate_and(b[0], n24);
  auto n25 = gate_not(b[1]);
  auto n27 = gate_not(a[1]);
  auto n28 = gate_and(n27, b[1]);
  auto n30 = gate_not(b[2]);
  auto n20 = gate_nand(b[2], n23);
  auto n21 = gate_nand(a[1], n25);
  auto n22 = gate_nand(a[2], n30);
  auto n29 = gate_and(n26, n21);
  auto n31 = gate_or(n29, n28);
  auto n19 = gate_nand(n31, n22);
  y[0] = gate_and(n20, n19);
}
template<> void $NameUint<3>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[0]);
  auto n23 = gate_and(b[0], n20);
  auto n22 = gate_not(n23);
  auto n21 = gate_not(b[1]);
  auto n25 = gate_and(n22, n21);
  auto n26 = gate_not(b[2]);
  auto n28 = gate_not(a[2]);
  auto n29 = gate_and(b[2], n28);
  auto n18 = gate_nand(n23, b[1]);
  auto n19 = gate_nand(a[2], n26);
  auto n24 = gate_and(a[1], n18);
  auto n27 = gate_or(n25, n24);
  auto n30 = gate_and(n27, n19);
  auto _gte_x_1_n22 = gate_or(n30, n29);
  y[0] = gate_buf(_gte_x_1_n22);
}
template<> void $NameUint<3>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(b[0]);
  auto n21 = gate_and(n19, a[0]);
  auto n20 = gate_not(a[1]);
  auto n22 = gate_not(b[1]);
  auto n23 = gate_and(a[1], n22);
  auto n25 = gate_not(a[2]);
  auto n27 = gate_not(b[2]);
  auto n28 = gate_and(a[2], n27);
  auto n17 = gate_nand(b[1], n20);
  auto n18 = gate_nand(b[2], n25);
  auto n24 = gate_and(n21, n17);
  auto n26 = gate_or(n24, n23);
  auto n29 = gate_and(n26, n18);
  y[0] = gate_or(n29, n28);
}
template<> void $NameUint<3>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[0]);
  auto n22 = gate_and(n20, a[0]);
  auto n21 = gate_not(a[1]);
  auto n23 = gate_not(b[1]);
  auto n25 = gate_not(a[2]);
  auto n17 = gate_nand(b[1], n21);
  auto n18 = gate_nand(a[1], n23);
  auto n16 = gate_nand(n22, n17);
  auto n24 = gate_and(n16, n18);
  auto n26 = gate_not(n24);
  auto n27 = gate_and(n26, n25);
  auto n19 = gate_nand(n24, a[2]);
  auto n28 = gate_and(b[2], n19);
  auto _gt_x_1_n22 = gate_or(n28, n27);
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
  auto n10 = gate_not(a[0]);
  auto n13 = gate_xor(n10, b[0]);
  auto n11 = gate_not(a[1]);
  auto n12 = gate_xor(n11, b[1]);
  auto n16 = gate_and(n13, n12);
  auto n14 = gate_not(a[2]);
  auto n15 = gate_xor(n14, b[2]);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<3>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n12 = gate_not(a[0]);
  auto n11 = gate_not(a[1]);
  auto n14 = gate_and(n12, n11);
  auto n13 = gate_not(a[2]);
  auto n18 = gate_and(n14, n13);
  y[0] = gate_mux(b[0], c[0], n18);
  auto n17 = gate_not(n18);
  auto n16 = gate_and(b[1], n17);
  auto n15 = gate_and(n18, c[1]);
  y[1] = gate_or(n16, n15);
  auto n20 = gate_and(b[2], n17);
  auto n19 = gate_and(n18, c[2]);
  y[2] = gate_or(n20, n19);
}
template<> void $NameUint<3>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[1]);
  auto n23 = gate_not(b[0]);
  auto n25 = gate_not(b[2]);
  auto n26 = gate_not(b[1]);
  auto n28 = gate_not(a[2]);
  auto n29 = gate_and(b[2], n28);
  auto n19 = gate_nand(b[1], n22);
  auto n20 = gate_nand(a[1], n26);
  auto n21 = gate_nand(a[2], n25);
  auto n24 = gate_and(a[0], n19);
  auto n18 = gate_nand(n24, n23);
  auto n27 = gate_and(n18, n21);
  auto n30 = gate_and(n27, n20);
  auto _lte_x_1_n8 = gate_or(n30, n29);
  y[0] = gate_buf(_lte_x_1_n8);
}
template<> void $NameUint<3>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[0]);
  auto n23 = gate_and(a[0], n22);
  auto n24 = gate_or(n23, a[1]);
  auto n26 = gate_not(b[2]);
  auto n20 = gate_nand(n23, a[1]);
  auto n19 = gate_nand(b[1], n20);
  auto n25 = gate_and(n24, n19);
  auto n27 = gate_not(n25);
  auto n28 = gate_and(n27, n26);
  auto n21 = gate_nand(n25, b[2]);
  auto n29 = gate_and(a[2], n21);
  y[0] = gate_or(n29, n28);
}
template<> void $NameUint<3>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[2]);
  auto n16 = gate_not(a[0]);
  auto n15 = gate_not(a[1]);
  auto n17 = gate_and(n16, n15);
  auto n20 = gate_not(b[2]);
  auto n19 = gate_not(b[0]);
  auto n22 = gate_and(n20, n19);
  auto n21 = gate_not(b[1]);
  auto n13 = gate_nand(n22, n21);
  auto n14 = gate_nand(n18, n17);
  y[0] = gate_and(n14, n13);
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
  auto n14 = gate_not(b[0]);
  auto n13 = gate_not(a[1]);
  auto n18 = gate_and(n14, n13);
  auto n16 = gate_not(a[2]);
  auto n15 = gate_not(b[2]);
  auto n17 = gate_and(n16, n15);
  auto n20 = gate_and(n18, n17);
  auto n19 = gate_not(b[1]);
  auto n22 = gate_and(n20, n19);
  auto n21 = gate_not(a[0]);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<3>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[2]);
  auto n28 = gate_and(b[2], n18);
  auto n19 = gate_not(b[2]);
  auto n20 = gate_not(b[1]);
  auto n21 = gate_not(a[1]);
  auto n24 = gate_and(b[1], n21);
  auto n22 = gate_not(a[0]);
  auto n23 = gate_and(b[0], n22);
  auto n25 = gate_or(n24, n23);
  auto n16 = gate_nand(a[2], n19);
  auto n17 = gate_nand(a[1], n20);
  auto n26 = gate_and(n16, n17);
  auto n27 = gate_and(n26, n25);
  auto _lt_x_1_n8 = gate_or(n28, n27);
  y[0] = gate_buf(_lt_x_1_n8);
}
template<> void $NameUint<3>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(b[2]);
  auto n29 = gate_and(a[2], n19);
  auto n20 = gate_not(a[2]);
  auto n21 = gate_not(b[1]);
  auto n22 = gate_not(a[1]);
  auto n25 = gate_and(b[1], n22);
  auto n23 = gate_not(a[0]);
  auto n24 = gate_and(b[0], n23);
  auto n26 = gate_or(n25, n24);
  auto n17 = gate_nand(b[2], n20);
  auto n18 = gate_nand(a[1], n21);
  auto n27 = gate_and(n17, n18);
  auto n28 = gate_and(n27, n26);
  y[0] = gate_or(n29, n28);
}
template<> void $NameUint<3>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n31 = gate_not(b[2]);
  auto n18 = gate_not(b[1]);
  auto n12 = gate_and(n31, n18);
  auto n13 = gate_not(b[0]);
  auto n23 = gate_not(a[2]);
  auto n15 = gate_not(a[1]);
  auto n19 = gate_not(a[0]);
  auto n1 = gate_nand(n18, n13);
  auto n2 = gate_nand(b[1], n23);
  auto n4 = gate_nand(b[0], n15);
  auto n5 = gate_nand(b[2], n23);
  auto n6 = gate_nand(b[0], n19);
  auto n8 = gate_nand(b[0], n12);
  auto n17 = gate_and(a[2], n8);
  auto n14 = gate_and(n1, n2);
  auto n16 = gate_and(n31, n14);
  auto n7 = gate_nand(n16, n4);
  auto n34 = gate_and(n17, n7);
  auto n26 = gate_and(a[1], n7);
  auto n22 = gate_and(n26, n18);
  auto n27 = gate_xor(n26, b[1]);
  auto n20 = gate_not(n27);
  auto n21 = gate_and(n20, n6);
  auto n32 = gate_or(n22, n21);
  auto n28 = gate_and(n27, n6);
  auto n9 = gate_nand(n34, n31);
  auto n10 = gate_nand(n32, n31);
  auto n11 = gate_nand(n32, n5);
  auto n25 = gate_and(n9, n11);
  auto n33 = gate_not(n25);
  auto n24 = gate_and(n33, b[0]);
  y[0] = gate_xor(n24, a[0]);
  auto n30 = gate_and(n26, n25);
  auto n29 = gate_and(n28, n33);
  y[1] = gate_or(n30, n29);
  auto n3 = gate_nand(n33, n10);
  y[2] = gate_and(n34, n3);
}
template<> void $NameUint<3>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(a[0]);
  auto n10 = gate_and(a[2], n17);
  auto n9 = gate_not(a[1]);
  auto n11 = gate_and(n10, n9);
  auto n26 = gate_xor(b[1], b[2]);
  auto n16 = gate_not(n26);
  auto n12 = gate_or(b[0], n16);
  auto n14 = gate_and(a[0], a[2]);
  auto n15 = gate_xor(n14, a[1]);
  auto n18 = gate_not(b[0]);
  auto n24 = gate_xor(a[2], a[0]);
  auto n2 = gate_nand(b[0], n17);
  auto n4 = gate_nand(b[2], n18);
  auto n5 = gate_nand(b[0], n16);
  auto n13 = gate_and(n11, n5);
  auto n21 = gate_and(n13, n12);
  auto n27 = gate_and(n15, n5);
  auto n19 = gate_xor(n27, n16);
  auto n29 = gate_and(n2, n4);
  auto n22 = gate_not(n21);
  auto n30 = gate_not(n29);
  auto n6 = gate_nand(n19, n29);
  auto n7 = gate_nand(n27, n16);
  auto n23 = gate_and(n7, n6);
  auto n20 = gate_not(n23);
  auto n3 = gate_nand(n23, n22);
  auto n8 = gate_nand(n21, n20);
  auto n35 = gate_and(a[2], n8);
  auto n25 = gate_and(b[0], n3);
  auto n39 = gate_xor(n25, n24);
  auto n28 = gate_and(n3, n26);
  auto n31 = gate_xor(n28, n27);
  auto n36 = gate_not(n39);
  auto n38 = gate_and(a[2], n36);
  y[0] = gate_xor(a[2], n39);
  auto n1 = gate_nand(n3, n30);
  auto n37 = gate_and(n31, n1);
  auto n32 = gate_not(n37);
  auto n33 = gate_and(a[2], n32);
  auto n34 = gate_and(n39, n33);
  y[2] = gate_xor(n35, n34);
  y[1] = gate_xor(n38, n37);
}
template<> void $NameUint<3>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
  auto n2 = gate_and(b[1], a[0]);
  auto n1 = gate_and(a[1], b[0]);
  y[1] = gate_xor(n2, n1);
  auto n3 = gate_not(y[0]);
  auto n4 = gate_and(n3, a[1]);
  auto n8 = gate_and(b[1], n4);
  auto n6 = gate_and(b[2], a[0]);
  auto n5 = gate_and(a[2], b[0]);
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
  auto n8 = gate_not(a[0]);
  auto n7 = gate_not(a[1]);
  auto n10 = gate_and(n8, n7);
  auto n9 = gate_not(a[2]);
  y[0] = gate_nand(n10, n9);
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
  y[0] = gate_buf(_ash_1_n11);
}
template<> void $NameUint<3>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[0]);
  auto n19 = gate_and(a[0], n27);
  auto n18 = gate_and(b[0], a[1]);
  auto n20 = gate_or(n19, n18);
  auto n24 = gate_not(b[1]);
  auto n22 = gate_and(n20, n24);
  auto n26 = gate_and(a[2], n27);
  auto n21 = gate_and(b[1], n26);
  auto n23 = gate_or(n22, n21);
  auto n25 = gate_not(b[2]);
  y[0] = gate_and(n23, n25);
  auto n31 = gate_and(n25, n24);
  y[2] = gate_and(n26, n31);
  auto n29 = gate_and(a[1], n27);
  auto n28 = gate_and(b[0], a[2]);
  auto n30 = gate_or(n29, n28);
  y[1] = gate_and(n31, n30);
}
template<> void $NameUint<3>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[2] = gate_buf(a[2]);
  auto n17 = gate_not(b[0]);
  auto n13 = gate_and(a[0], n17);
  auto n12 = gate_and(b[0], a[1]);
  auto n16 = gate_or(n13, n12);
  auto n15 = gate_not(b[1]);
  auto n14 = gate_not(b[2]);
  auto n18 = gate_and(n15, n14);
  y[0] = gate_mux(a[2], n16, n18);
  auto n19 = gate_and(n18, n17);
  y[1] = gate_mux(a[2], a[1], n19);
}
template<> void $NameUint<3>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n17 = gate_not(b[1]);
  auto n16 = gate_xor(a[1], n17);
  auto n15 = gate_not(a[0]);
  auto n18 = gate_xor(b[2], a[2]);
  auto n12 = gate_nand(b[0], n15);
  auto n13 = gate_nand(a[1], n17);
  auto n14 = gate_nand(n16, n12);
  y[1] = gate_xor(n16, n12);
  auto n19 = gate_and(n14, n13);
  y[2] = gate_xor(n19, n18);
}
template<> void $NameUint<3>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
  auto n5 = gate_or(a[1], a[0]);
  y[2] = gate_xor(a[2], n5);
}
