template<> void $NameUint<5>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  auto n2 = gate_and(a[0], b[0]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_and(b[1], a[1]);
  auto n4 = gate_and(n3, n2);
  auto n6 = gate_or(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_and(b[2], a[2]);
  auto n8 = gate_and(n7, n6);
  auto n10 = gate_or(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n13 = gate_and(n11, n10);
  auto n12 = gate_and(b[3], a[3]);
  auto n15 = gate_or(n13, n12);
  auto n14 = gate_xor(a[4], b[4]);
  y[4] = gate_xor(n15, n14);
}
template<> void $NameUint<5>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_and(b[4], a[4]);
  y[3] = gate_and(b[3], a[3]);
  y[2] = gate_and(b[2], a[2]);
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<5>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[4] = gate_not(a[4]);
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<5>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_or(a[4], b[4]);
  y[3] = gate_or(a[3], b[3]);
  y[2] = gate_or(a[2], b[2]);
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<5>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_xor(b[4], a[4]);
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<5>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  y[1] = gate_and(a[0], b[1]);
  y[2] = gate_and(a[0], b[2]);
  y[3] = gate_and(a[0], b[3]);
  y[4] = gate_and(a[0], b[4]);
}
template<> void $NameUint<5>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
}
template<> void $NameUint<5>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n2);
  y[0] = gate_not(a[0]);
  auto n4 = gate_and(y[0], n2);
  y[2] = gate_xor(a[2], n4);
  auto n3 = gate_not(a[2]);
  auto n6 = gate_and(n4, n3);
  y[3] = gate_xor(a[3], n6);
  auto n5 = gate_not(a[3]);
  auto n7 = gate_and(n6, n5);
  y[4] = gate_xor(a[4], n7);
}
template<> void $NameUint<5>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n67 = gate_not(b[1]);
  auto n56 = gate_not(b[4]);
  auto n51 = gate_not(b[3]);
  auto n36 = gate_and(n56, n51);
  auto n74 = gate_not(b[2]);
  auto n25 = gate_and(n36, n74);
  auto n22 = gate_and(n67, n25);
  auto n29 = gate_not(a[4]);
  auto n9 = gate_nand(b[0], n29);
  auto n10 = gate_nand(b[1], n29);
  y[4] = gate_and(n22, n9);
  auto n23 = gate_not(a[3]);
  auto n6 = gate_nand(b[0], n23);
  auto n24 = gate_and(n6, n10);
  y[3] = gate_and(n25, n24);
  auto n5 = gate_nand(y[3], b[0]);
  auto n37 = gate_and(a[3], n5);
  auto n21 = gate_nand(n37, n67);
  auto n28 = gate_xor(n37, n67);
  auto n26 = gate_not(a[2]);
  auto n39 = gate_and(b[0], n26);
  auto n27 = gate_not(n39);
  auto n20 = gate_nand(n28, n27);
  auto n31 = gate_and(n21, n20);
  auto n30 = gate_and(b[2], n29);
  auto n35 = gate_or(n31, n30);
  auto n33 = gate_not(y[3]);
  auto n32 = gate_not(y[4]);
  auto n34 = gate_and(n33, n32);
  auto n50 = gate_and(a[4], n34);
  auto n16 = gate_nand(n50, n74);
  auto n8 = gate_nand(n35, n16);
  y[2] = gate_and(n36, n8);
  auto n12 = gate_nand(y[2], n39);
  auto n38 = gate_and(y[2], b[1]);
  auto n40 = gate_xor(n38, n37);
  auto n59 = gate_and(n40, n12);
  auto n18 = gate_nand(n74, n59);
  auto n45 = gate_xor(n74, n59);
  auto n41 = gate_and(y[2], b[0]);
  auto n69 = gate_xor(n41, a[2]);
  auto n44 = gate_and(n67, n69);
  auto n42 = gate_xor(n67, n69);
  auto n61 = gate_not(a[1]);
  auto n4 = gate_nand(b[0], n61);
  auto n43 = gate_and(n42, n4);
  auto n57 = gate_or(n44, n43);
  auto n19 = gate_nand(n45, n57);
  auto n48 = gate_and(n19, n18);
  auto n46 = gate_not(n50);
  auto n47 = gate_and(b[3], n46);
  auto n52 = gate_or(n48, n47);
  auto n49 = gate_not(y[2]);
  auto n54 = gate_and(n50, n49);
  auto n15 = gate_nand(n54, n51);
  auto n7 = gate_nand(n52, n15);
  y[1] = gate_and(n56, n7);
  auto n53 = gate_not(y[1]);
  auto n55 = gate_and(n54, n53);
  auto n80 = gate_and(n56, n55);
  auto n78 = gate_xor(n56, n55);
  auto n58 = gate_xor(n74, n57);
  auto n60 = gate_and(n58, y[1]);
  auto n17 = gate_xnor(n60, n59);
  auto n3 = gate_nand(b[3], n17);
  auto n76 = gate_xor(b[3], n17);
  auto n62 = gate_and(y[1], b[0]);
  auto n66 = gate_xor(n62, n61);
  auto n13 = gate_nand(b[1], n66);
  auto n65 = gate_xor(b[1], n66);
  auto n63 = gate_not(a[0]);
  auto n64 = gate_and(b[0], n63);
  auto n14 = gate_nand(n65, n64);
  auto n73 = gate_and(n14, n13);
  auto n1 = gate_nand(n74, n73);
  auto n72 = gate_xor(n74, n73);
  auto n68 = gate_xor(n4, n67);
  auto n70 = gate_and(n68, y[1]);
  auto n71 = gate_xor(n70, n69);
  auto n11 = gate_nand(n72, n71);
  auto n75 = gate_and(n11, n1);
  auto n2 = gate_nand(n76, n75);
  auto n77 = gate_and(n2, n3);
  auto n79 = gate_and(n78, n77);
  y[0] = gate_or(n80, n79);
}
template<> void $NameUint<5>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_nand(b[0], a[0]);
  auto n109 = gate_xor(a[4], b[4]);
  auto n31 = gate_not(b[4]);
  auto n53 = gate_xor(b[2], n31);
  auto n84 = gate_not(n53);
  auto n60 = gate_xor(b[1], n31);
  auto n77 = gate_not(n60);
  auto n24 = gate_not(b[0]);
  auto n107 = gate_and(n31, n24);
  auto n62 = gate_not(n107);
  auto n25 = gate_and(n62, n9);
  auto n76 = gate_and(n77, n25);
  auto n74 = gate_xor(n77, n25);
  auto n27 = gate_not(a[0]);
  auto n26 = gate_not(a[1]);
  auto n45 = gate_and(n27, n26);
  auto n28 = gate_not(a[2]);
  auto n32 = gate_and(n45, n28);
  auto n29 = gate_not(a[3]);
  auto n30 = gate_and(n32, n29);
  auto n96 = gate_and(a[4], n30);
  auto n86 = gate_xor(b[3], n31);
  auto n41 = gate_and(n86, n53);
  auto n108 = gate_and(n41, n60);
  auto n10 = gate_nand(b[0], n108);
  auto n42 = gate_and(n96, n10);
  auto n33 = gate_not(n32);
  auto n34 = gate_and(n33, a[4]);
  auto n44 = gate_xor(n34, a[3]);
  auto n19 = gate_nand(n44, b[0]);
  auto n36 = gate_and(n62, n19);
  auto n35 = gate_not(n42);
  auto n3 = gate_nand(n36, n35);
  auto n39 = gate_and(n60, n3);
  auto n37 = gate_not(n36);
  auto n38 = gate_and(n37, n96);
  auto n40 = gate_or(n39, n38);
  auto n95 = gate_and(n41, n40);
  auto n43 = gate_not(n95);
  auto n57 = gate_and(n42, n43);
  auto n66 = gate_and(n44, n43);
  auto n50 = gate_not(n66);
  auto n1 = gate_nand(n77, n50);
  auto n49 = gate_xor(n77, n50);
  auto n46 = gate_not(n45);
  auto n47 = gate_and(n46, a[4]);
  auto n58 = gate_xor(n47, a[2]);
  auto n18 = gate_nand(n58, b[0]);
  auto n48 = gate_and(n62, n18);
  auto n4 = gate_nand(n49, n48);
  auto n52 = gate_and(n4, n1);
  auto n51 = gate_not(n96);
  auto n8 = gate_nand(n84, n51);
  auto n55 = gate_and(n52, n8);
  auto n54 = gate_and(n57, n53);
  auto n56 = gate_or(n55, n54);
  auto n94 = gate_and(n56, n86);
  auto n65 = gate_not(n94);
  auto n90 = gate_and(n57, n65);
  auto n59 = gate_and(n94, b[0]);
  auto n80 = gate_xor(n59, n58);
  auto n22 = gate_nand(n80, n60);
  auto n64 = gate_xor(n80, n60);
  auto n61 = gate_and(a[0], a[4]);
  auto n72 = gate_xor(n61, a[1]);
  auto n17 = gate_nand(n72, b[0]);
  auto n78 = gate_and(n62, n17);
  auto n63 = gate_not(n78);
  auto n21 = gate_nand(n64, n63);
  auto n69 = gate_and(n22, n21);
  auto n6 = gate_nand(n84, n69);
  auto n68 = gate_xor(n84, n69);
  auto n85 = gate_and(n66, n65);
  auto n67 = gate_not(n85);
  auto n2 = gate_nand(n68, n67);
  auto n71 = gate_and(n2, n6);
  auto n14 = gate_nand(n90, n71);
  auto n70 = gate_xor(n90, n71);
  auto n15 = gate_nand(n70, n86);
  auto n91 = gate_and(n15, n14);
  auto n13 = gate_nand(n91, n90);
  auto n93 = gate_not(n91);
  auto n73 = gate_and(n93, b[0]);
  auto n16 = gate_xnor(n73, n72);
  auto n75 = gate_and(n74, n16);
  auto n83 = gate_or(n76, n75);
  auto n5 = gate_nand(n84, n83);
  auto n82 = gate_xor(n84, n83);
  auto n79 = gate_xor(n78, n77);
  auto n81 = gate_and(n93, n79);
  auto n20 = gate_xnor(n81, n80);
  auto n7 = gate_nand(n82, n20);
  auto n89 = gate_and(n7, n5);
  auto n88 = gate_and(n85, n91);
  auto n11 = gate_nand(n89, n88);
  auto n87 = gate_xor(n89, n88);
  auto n12 = gate_nand(n87, n86);
  auto n92 = gate_and(n12, n11);
  auto n111 = gate_and(n92, n13);
  auto n106 = gate_and(n109, n111);
  auto n105 = gate_xor(n109, n93);
  auto n104 = gate_and(n106, n105);
  auto n103 = gate_xor(n109, n94);
  auto n102 = gate_and(n104, n103);
  auto n101 = gate_xor(n109, n95);
  auto n100 = gate_and(n102, n101);
  auto n97 = gate_and(n96, n108);
  auto n98 = gate_and(b[0], n97);
  auto n99 = gate_xor(n109, n98);
  y[4] = gate_xor(n100, n99);
  y[3] = gate_xor(n102, n101);
  y[2] = gate_xor(n104, n103);
  y[1] = gate_xor(n106, n105);
  auto n110 = gate_and(n108, n107);
  auto n23 = gate_nand(n110, n109);
  y[0] = gate_xor(n23, n111);
}
template<> void $NameUint<5>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_xnor(b[0], a[0]);
  auto n15 = gate_not(a[4]);
  auto n18 = gate_xor(n15, b[4]);
  auto n16 = gate_not(b[3]);
  auto n17 = gate_xor(n16, a[3]);
  auto n24 = gate_and(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n22 = gate_xor(n19, b[2]);
  auto n20 = gate_not(b[1]);
  auto n21 = gate_xor(n20, a[1]);
  auto n23 = gate_and(n22, n21);
  auto n25 = gate_and(n24, n23);
  y[0] = gate_and(n25, n14);
}
template<> void $NameUint<5>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n37 = gate_not(a[0]);
  auto n40 = gate_and(b[0], n37);
  auto n34 = gate_nand(n40, b[1]);
  auto n39 = gate_xor(n40, b[1]);
  auto n38 = gate_not(a[1]);
  auto n31 = gate_nand(n39, n38);
  auto n43 = gate_and(n31, n34);
  auto n35 = gate_nand(a[2], n43);
  auto n42 = gate_xor(a[2], n43);
  auto n41 = gate_not(b[2]);
  auto n36 = gate_nand(n42, n41);
  auto n46 = gate_and(n36, n35);
  auto n33 = gate_nand(b[3], n46);
  auto n45 = gate_xor(b[3], n46);
  auto n44 = gate_not(a[3]);
  auto n32 = gate_nand(n45, n44);
  auto n47 = gate_and(n32, n33);
  auto n51 = gate_and(n47, a[4]);
  auto n49 = gate_xor(n47, a[4]);
  auto n48 = gate_not(b[4]);
  auto n50 = gate_and(n49, n48);
  y[0] = gate_or(n51, n50);
}
template<> void $NameUint<5>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n37 = gate_not(a[0]);
  auto n40 = gate_and(b[0], n37);
  auto n33 = gate_nand(n40, b[1]);
  auto n39 = gate_xor(n40, b[1]);
  auto n38 = gate_not(a[1]);
  auto n31 = gate_nand(n39, n38);
  auto n43 = gate_and(n31, n33);
  auto n35 = gate_nand(a[2], n43);
  auto n42 = gate_xor(a[2], n43);
  auto n41 = gate_not(b[2]);
  auto n36 = gate_nand(n42, n41);
  auto n46 = gate_and(n36, n35);
  auto n34 = gate_nand(b[3], n46);
  auto n45 = gate_xor(b[3], n46);
  auto n44 = gate_not(a[3]);
  auto n32 = gate_nand(n45, n44);
  auto n47 = gate_and(n32, n34);
  auto n51 = gate_and(n47, b[4]);
  auto n49 = gate_xor(n47, b[4]);
  auto n48 = gate_not(a[4]);
  auto n50 = gate_and(n49, n48);
  y[0] = gate_or(n51, n50);
}
template<> void $NameUint<5>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[0]);
  auto n41 = gate_and(a[0], n38);
  auto n36 = gate_nand(a[1], n41);
  auto n40 = gate_xor(a[1], n41);
  auto n39 = gate_not(b[1]);
  auto n37 = gate_nand(n40, n39);
  auto n44 = gate_and(n37, n36);
  auto n32 = gate_nand(b[2], n44);
  auto n43 = gate_xor(b[2], n44);
  auto n42 = gate_not(a[2]);
  auto n30 = gate_nand(n43, n42);
  auto n47 = gate_and(n30, n32);
  auto n34 = gate_nand(n47, a[3]);
  auto n46 = gate_xor(n47, a[3]);
  auto n45 = gate_not(b[3]);
  auto n35 = gate_nand(n46, n45);
  auto n50 = gate_and(n35, n34);
  auto n31 = gate_nand(n50, b[4]);
  auto n49 = gate_xor(n50, b[4]);
  auto n48 = gate_not(a[4]);
  auto n33 = gate_nand(n49, n48);
  y[0] = gate_and(n33, n31);
}
template<> void $NameUint<5>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[0]);
  auto n41 = gate_and(a[0], n38);
  auto n34 = gate_nand(a[1], n41);
  auto n40 = gate_xor(a[1], n41);
  auto n39 = gate_not(b[1]);
  auto n35 = gate_nand(n40, n39);
  auto n44 = gate_and(n35, n34);
  auto n30 = gate_nand(b[2], n44);
  auto n43 = gate_xor(b[2], n44);
  auto n42 = gate_not(a[2]);
  auto n31 = gate_nand(n43, n42);
  auto n47 = gate_and(n31, n30);
  auto n32 = gate_nand(n47, a[3]);
  auto n46 = gate_xor(n47, a[3]);
  auto n45 = gate_not(b[3]);
  auto n33 = gate_nand(n46, n45);
  auto n50 = gate_and(n33, n32);
  auto n36 = gate_nand(n50, a[4]);
  auto n49 = gate_xor(n50, a[4]);
  auto n48 = gate_not(b[4]);
  auto n37 = gate_nand(n49, n48);
  y[0] = gate_and(n37, n36);
}
template<> void $NameUint<5>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xor(a[0], a[1]);
  auto n2 = gate_and(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  auto n3 = gate_and(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  auto n4 = gate_and(n3, a[3]);
  y[4] = gate_xor(a[4], n4);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<5>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n16 = gate_xnor(a[2], b[2]);
  auto n18 = gate_not(a[0]);
  auto n21 = gate_xor(n18, b[0]);
  auto n19 = gate_not(a[1]);
  auto n20 = gate_xor(n19, b[1]);
  auto n27 = gate_and(n21, n20);
  auto n22 = gate_not(b[3]);
  auto n25 = gate_xor(n22, a[3]);
  auto n23 = gate_not(a[4]);
  auto n24 = gate_xor(n23, b[4]);
  auto n26 = gate_and(n25, n24);
  auto n28 = gate_and(n27, n26);
  y[0] = gate_nand(n28, n16);
}
template<> void $NameUint<5>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[4]);
  auto n15 = gate_and(n11, n10);
  auto n13 = gate_not(a[2]);
  auto n12 = gate_not(a[1]);
  auto n14 = gate_and(n13, n12);
  auto n17 = gate_and(n15, n14);
  auto n16 = gate_not(a[3]);
  auto n18 = gate_and(n17, n16);
  y[0] = gate_mux(b[0], c[0], n18);
  y[1] = gate_mux(b[1], c[1], n18);
  y[2] = gate_mux(b[2], c[2], n18);
  y[3] = gate_mux(b[3], c[3], n18);
  y[4] = gate_mux(b[4], c[4], n18);
}
template<> void $NameUint<5>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n37 = gate_not(b[0]);
  auto n40 = gate_and(a[0], n37);
  auto n33 = gate_nand(n40, a[1]);
  auto n39 = gate_xor(n40, a[1]);
  auto n38 = gate_not(b[1]);
  auto n34 = gate_nand(n39, n38);
  auto n43 = gate_and(n34, n33);
  auto n32 = gate_nand(b[2], n43);
  auto n42 = gate_xor(b[2], n43);
  auto n41 = gate_not(a[2]);
  auto n31 = gate_nand(n42, n41);
  auto n46 = gate_and(n31, n32);
  auto n35 = gate_nand(a[3], n46);
  auto n45 = gate_xor(a[3], n46);
  auto n44 = gate_not(b[3]);
  auto n36 = gate_nand(n45, n44);
  auto n47 = gate_and(n36, n35);
  auto n51 = gate_and(n47, b[4]);
  auto n49 = gate_xor(n47, b[4]);
  auto n48 = gate_not(a[4]);
  auto n50 = gate_and(n49, n48);
  y[0] = gate_or(n51, n50);
}
template<> void $NameUint<5>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n37 = gate_not(b[0]);
  auto n40 = gate_and(a[0], n37);
  auto n35 = gate_nand(n40, a[1]);
  auto n39 = gate_xor(n40, a[1]);
  auto n38 = gate_not(b[1]);
  auto n36 = gate_nand(n39, n38);
  auto n43 = gate_and(n36, n35);
  auto n32 = gate_nand(b[2], n43);
  auto n42 = gate_xor(b[2], n43);
  auto n41 = gate_not(a[2]);
  auto n31 = gate_nand(n42, n41);
  auto n46 = gate_and(n31, n32);
  auto n33 = gate_nand(a[3], n46);
  auto n45 = gate_xor(a[3], n46);
  auto n44 = gate_not(b[3]);
  auto n34 = gate_nand(n45, n44);
  auto n47 = gate_and(n34, n33);
  auto n51 = gate_and(n47, a[4]);
  auto n49 = gate_xor(n47, a[4]);
  auto n48 = gate_not(b[4]);
  auto n50 = gate_and(n49, n48);
  y[0] = gate_or(n51, n50);
}
template<> void $NameUint<5>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(a[0]);
  auto n23 = gate_not(a[4]);
  auto n28 = gate_and(n24, n23);
  auto n26 = gate_not(a[2]);
  auto n25 = gate_not(a[1]);
  auto n27 = gate_and(n26, n25);
  auto n30 = gate_and(n28, n27);
  auto n29 = gate_not(a[3]);
  auto n22 = gate_nand(n30, n29);
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(b[4]);
  auto n36 = gate_and(n32, n31);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[1]);
  auto n35 = gate_and(n34, n33);
  auto n38 = gate_and(n36, n35);
  auto n37 = gate_not(b[3]);
  auto n21 = gate_nand(n38, n37);
  y[0] = gate_and(n22, n21);
}
template<> void $NameUint<5>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[4]);
  auto n15 = gate_and(n11, n10);
  auto n13 = gate_not(a[2]);
  auto n12 = gate_not(a[1]);
  auto n14 = gate_and(n13, n12);
  auto n17 = gate_and(n15, n14);
  auto n16 = gate_not(a[3]);
  y[0] = gate_and(n17, n16);
}
template<> void $NameUint<5>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[2]);
  auto n21 = gate_not(a[3]);
  auto n26 = gate_and(n22, n21);
  auto n24 = gate_not(a[0]);
  auto n23 = gate_not(a[2]);
  auto n25 = gate_and(n24, n23);
  auto n28 = gate_and(n26, n25);
  auto n27 = gate_not(a[4]);
  auto n38 = gate_and(n28, n27);
  auto n30 = gate_not(b[1]);
  auto n29 = gate_not(b[3]);
  auto n34 = gate_and(n30, n29);
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(b[4]);
  auto n33 = gate_and(n32, n31);
  auto n36 = gate_and(n34, n33);
  auto n35 = gate_not(a[1]);
  auto n37 = gate_and(n36, n35);
  y[0] = gate_nand(n38, n37);
}
template<> void $NameUint<5>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(a[0]);
  auto n41 = gate_and(b[0], n38);
  auto n32 = gate_nand(b[1], n41);
  auto n40 = gate_xor(b[1], n41);
  auto n39 = gate_not(a[1]);
  auto n30 = gate_nand(n40, n39);
  auto n44 = gate_and(n30, n32);
  auto n36 = gate_nand(a[2], n44);
  auto n43 = gate_xor(a[2], n44);
  auto n42 = gate_not(b[2]);
  auto n37 = gate_nand(n43, n42);
  auto n47 = gate_and(n37, n36);
  auto n33 = gate_nand(n47, b[3]);
  auto n46 = gate_xor(n47, b[3]);
  auto n45 = gate_not(a[3]);
  auto n31 = gate_nand(n46, n45);
  auto n50 = gate_and(n31, n33);
  auto n34 = gate_nand(n50, a[4]);
  auto n49 = gate_xor(n50, a[4]);
  auto n48 = gate_not(b[4]);
  auto n35 = gate_nand(n49, n48);
  y[0] = gate_and(n35, n34);
}
template<> void $NameUint<5>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(a[0]);
  auto n41 = gate_and(b[0], n38);
  auto n32 = gate_nand(b[1], n41);
  auto n40 = gate_xor(b[1], n41);
  auto n39 = gate_not(a[1]);
  auto n34 = gate_nand(n40, n39);
  auto n44 = gate_and(n34, n32);
  auto n36 = gate_nand(a[2], n44);
  auto n43 = gate_xor(a[2], n44);
  auto n42 = gate_not(b[2]);
  auto n37 = gate_nand(n43, n42);
  auto n47 = gate_and(n37, n36);
  auto n33 = gate_nand(n47, b[3]);
  auto n46 = gate_xor(n47, b[3]);
  auto n45 = gate_not(a[3]);
  auto n30 = gate_nand(n46, n45);
  auto n50 = gate_and(n30, n33);
  auto n35 = gate_nand(n50, b[4]);
  auto n49 = gate_xor(n50, b[4]);
  auto n48 = gate_not(a[4]);
  auto n31 = gate_nand(n49, n48);
  y[0] = gate_and(n31, n35);
}
template<> void $NameUint<5>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n80 = gate_not(b[4]);
  auto n84 = gate_not(b[3]);
  auto n52 = gate_and(n80, n84);
  auto n89 = gate_not(b[2]);
  auto n12 = gate_and(n52, n89);
  auto n65 = gate_not(b[1]);
  auto n11 = gate_xor(n65, a[4]);
  auto n14 = gate_and(n12, n11);
  auto n13 = gate_and(n12, n65);
  auto n23 = gate_and(b[0], n13);
  auto n16 = gate_or(n14, n23);
  auto n15 = gate_not(a[3]);
  auto n3 = gate_nand(b[0], n15);
  auto n25 = gate_and(n16, n3);
  auto n7 = gate_nand(n25, b[0]);
  auto n33 = gate_and(a[3], n7);
  auto n21 = gate_and(n33, n65);
  auto n19 = gate_xor(n33, n65);
  auto n17 = gate_not(a[2]);
  auto n35 = gate_and(b[0], n17);
  auto n18 = gate_not(n35);
  auto n20 = gate_and(n19, n18);
  auto n31 = gate_or(n21, n20);
  auto n1 = gate_nand(n31, n89);
  auto n22 = gate_not(a[4]);
  auto n4 = gate_nand(b[2], n22);
  auto n29 = gate_and(n31, n4);
  auto n24 = gate_not(n23);
  auto n27 = gate_and(a[4], n24);
  auto n26 = gate_not(n25);
  auto n32 = gate_and(n27, n26);
  auto n28 = gate_and(n32, n89);
  auto n30 = gate_or(n29, n28);
  auto n37 = gate_and(n52, n30);
  auto n2 = gate_nand(n37, n1);
  auto n6 = gate_nand(n37, n35);
  auto n51 = gate_and(n2, n32);
  auto n34 = gate_and(n37, b[1]);
  auto n36 = gate_xor(n34, n33);
  auto n57 = gate_and(n36, n6);
  auto n46 = gate_and(n89, n57);
  auto n44 = gate_xor(n89, n57);
  auto n38 = gate_and(n37, b[0]);
  auto n61 = gate_xor(n38, a[2]);
  auto n43 = gate_and(n65, n61);
  auto n41 = gate_xor(n65, n61);
  auto n39 = gate_not(a[1]);
  auto n59 = gate_and(b[0], n39);
  auto n40 = gate_not(n59);
  auto n42 = gate_and(n41, n40);
  auto n55 = gate_or(n43, n42);
  auto n45 = gate_and(n44, n55);
  auto n48 = gate_or(n46, n45);
  auto n47 = gate_xor(n48, n84);
  auto n10 = gate_nand(n80, n47);
  auto n82 = gate_and(n51, n10);
  auto n77 = gate_not(n51);
  auto n5 = gate_nand(n77, b[4]);
  auto n49 = gate_xor(b[3], n77);
  auto n50 = gate_and(n49, n48);
  auto n54 = gate_and(n50, n80);
  auto n53 = gate_and(n52, n51);
  auto n63 = gate_or(n54, n53);
  auto n56 = gate_xor(n55, n89);
  auto n58 = gate_and(n63, n56);
  auto n86 = gate_xor(n58, n57);
  auto n76 = gate_and(n86, n84);
  auto n74 = gate_xor(n84, n86);
  auto n60 = gate_xor(n59, b[1]);
  auto n62 = gate_and(n63, n60);
  auto n91 = gate_xor(n62, n61);
  auto n73 = gate_and(n91, n89);
  auto n71 = gate_xor(n89, n91);
  auto n64 = gate_and(n63, b[0]);
  auto n95 = gate_xor(n64, a[1]);
  auto n70 = gate_and(n65, n95);
  auto n68 = gate_xor(n65, n95);
  auto n66 = gate_not(a[0]);
  auto n93 = gate_and(b[0], n66);
  auto n67 = gate_not(n93);
  auto n69 = gate_and(n68, n67);
  auto n88 = gate_or(n70, n69);
  auto n72 = gate_and(n71, n88);
  auto n83 = gate_or(n73, n72);
  auto n75 = gate_and(n74, n83);
  auto n81 = gate_or(n76, n75);
  auto n8 = gate_nand(n81, n80);
  auto n79 = gate_and(n81, n5);
  auto n78 = gate_and(n82, n80);
  auto n97 = gate_or(n79, n78);
  auto n9 = gate_nand(n97, n8);
  y[4] = gate_and(n82, n9);
  auto n85 = gate_xor(n84, n83);
  auto n87 = gate_and(n85, n97);
  y[3] = gate_xor(n87, n86);
  auto n90 = gate_xor(n89, n88);
  auto n92 = gate_and(n90, n97);
  y[2] = gate_xor(n92, n91);
  auto n94 = gate_xor(n93, b[1]);
  auto n96 = gate_and(n94, n97);
  y[1] = gate_xor(n96, n95);
  auto n98 = gate_and(n97, b[0]);
  y[0] = gate_xor(n98, a[0]);
}
template<> void $NameUint<5>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[1]);
  auto n17 = gate_not(a[0]);
  auto n37 = gate_and(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n26 = gate_and(n37, n19);
  auto n82 = gate_not(b[4]);
  auto n99 = gate_xor(b[1], n82);
  auto n92 = gate_xor(b[2], n82);
  auto n75 = gate_xor(b[3], n82);
  auto n47 = gate_and(n92, n75);
  auto n20 = gate_and(b[0], n47);
  auto n21 = gate_and(n99, n20);
  auto n22 = gate_not(n21);
  auto n24 = gate_and(n26, n22);
  auto n23 = gate_not(a[3]);
  auto n25 = gate_and(n24, n23);
  auto n34 = gate_and(a[4], n25);
  auto n27 = gate_not(n26);
  auto n28 = gate_and(n27, a[4]);
  auto n36 = gate_xor(n28, a[3]);
  auto n29 = gate_not(b[0]);
  auto n30 = gate_or(n36, n29);
  auto n38 = gate_not(n37);
  auto n39 = gate_and(n38, a[4]);
  auto n57 = gate_xor(n39, a[2]);
  auto n53 = gate_mux(n82, n57, b[0]);
  auto n50 = gate_not(n99);
  auto n1 = gate_not(n50);
  auto n31 = gate_xor(n34, n1);
  auto n32 = gate_and(n31, n30);
  auto n35 = gate_and(n47, n32);
  auto n16 = gate_nand(n35, b[0]);
  auto n33 = gate_not(n35);
  auto n46 = gate_and(n34, n33);
  auto n51 = gate_and(n36, n16);
  auto n42 = gate_and(n51, n99);
  auto n40 = gate_xor(n51, n99);
  auto n41 = gate_and(n40, n53);
  auto n44 = gate_or(n42, n41);
  auto n43 = gate_xor(n44, n92);
  auto n15 = gate_nand(n43, n75);
  auto n68 = gate_and(n46, n15);
  auto n4 = gate_nand(n75, n68);
  auto n45 = gate_and(n92, n44);
  auto n49 = gate_and(n75, n45);
  auto n48 = gate_and(n47, n46);
  auto n56 = gate_or(n49, n48);
  auto n52 = gate_and(n50, n56);
  auto n55 = gate_xor(n52, n51);
  auto n54 = gate_not(n53);
  auto n10 = gate_nand(n54, n56);
  auto n72 = gate_and(n55, n10);
  auto n66 = gate_and(n92, n72);
  auto n64 = gate_xor(n92, n72);
  auto n58 = gate_and(n56, b[0]);
  auto n78 = gate_xor(n58, n57);
  auto n59 = gate_and(n78, n99);
  auto n62 = gate_not(n59);
  auto n61 = gate_xor(n78, n99);
  auto n60 = gate_and(a[4], a[0]);
  auto n80 = gate_xor(a[1], n60);
  auto n76 = gate_mux(n82, n80, b[0]);
  auto n9 = gate_nand(n61, n76);
  auto n70 = gate_and(n62, n9);
  auto n63 = gate_not(n70);
  auto n65 = gate_and(n64, n63);
  auto n69 = gate_or(n66, n65);
  auto n13 = gate_nand(n69, n75);
  auto n5 = gate_nand(n4, n13);
  auto n2 = gate_nand(n5, n70);
  auto n107 = gate_not(n75);
  auto n67 = gate_xor(n69, n107);
  auto n14 = gate_nand(n68, n67);
  auto n71 = gate_not(n92);
  auto n73 = gate_and(n5, n71);
  auto n74 = gate_xor(n73, n72);
  auto n108 = gate_and(n2, n74);
  auto n12 = gate_nand(n108, n75);
  auto n88 = gate_xor(n75, n108);
  auto n77 = gate_xor(n99, n76);
  auto n79 = gate_and(n5, n77);
  auto n94 = gate_xor(n79, n78);
  auto n8 = gate_nand(n94, n92);
  auto n86 = gate_xor(n92, n94);
  auto n81 = gate_and(n5, b[0]);
  auto n102 = gate_xor(n81, n80);
  auto n85 = gate_and(n102, n99);
  auto n83 = gate_xor(n102, n99);
  auto n100 = gate_mux(n82, a[0], b[0]);
  auto n84 = gate_and(n83, n100);
  auto n91 = gate_or(n85, n84);
  auto n7 = gate_nand(n86, n91);
  auto n106 = gate_and(n8, n7);
  auto n87 = gate_not(n106);
  auto n11 = gate_nand(n88, n87);
  auto n90 = gate_and(n12, n11);
  auto n6 = gate_nand(n90, n14);
  auto n3 = gate_nand(n6, n106);
  auto n89 = gate_or(n14, n90);
  auto n113 = gate_and(a[4], n89);
  auto n93 = gate_xor(n92, n91);
  auto n95 = gate_and(n6, n93);
  auto n96 = gate_xor(n95, n94);
  auto n117 = gate_xor(a[4], n96);
  auto n98 = gate_and(b[0], n6);
  auto n97 = gate_xor(a[0], a[4]);
  auto n121 = gate_xor(n98, n97);
  y[0] = gate_xor(a[4], n121);
  auto n105 = gate_and(a[4], n121);
  auto n101 = gate_xor(n100, n99);
  auto n103 = gate_and(n101, n6);
  auto n119 = gate_xor(n103, n102);
  auto n104 = gate_not(n119);
  auto n116 = gate_and(n105, n104);
  auto n115 = gate_and(n117, n116);
  auto n109 = gate_and(n6, n107);
  auto n110 = gate_xor(n109, n108);
  auto n111 = gate_and(n3, n110);
  auto n114 = gate_xor(a[4], n111);
  auto n112 = gate_and(n115, n114);
  y[4] = gate_xor(n113, n112);
  y[3] = gate_xor(n115, n114);
  y[2] = gate_xor(n117, n116);
  auto n118 = gate_not(n121);
  auto n120 = gate_and(n118, a[4]);
  y[1] = gate_xor(n120, n119);
}
template<> void $NameUint<5>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n3 = gate_and(a[1], b[0]);
  auto n2 = gate_and(b[1], a[0]);
  y[1] = gate_xor(n3, n2);
  auto n11 = gate_and(a[1], b[1]);
  auto n15 = gate_and(a[0], b[2]);
  auto n1 = gate_nand(n11, n15);
  auto n6 = gate_xor(n11, n15);
  auto n5 = gate_and(b[0], a[2]);
  auto n8 = gate_xor(n6, n5);
  auto n7 = gate_and(n3, n2);
  y[2] = gate_xor(n8, n7);
  auto n4 = gate_and(a[3], b[0]);
  auto n32 = gate_and(b[1], a[2]);
  auto n19 = gate_xor(n4, n32);
  auto n10 = gate_and(n6, n5);
  auto n9 = gate_and(n8, n7);
  auto n20 = gate_or(n10, n9);
  auto n14 = gate_and(b[3], a[0]);
  auto n12 = gate_and(b[2], n1);
  auto n13 = gate_and(n12, a[1]);
  auto n21 = gate_xor(n14, n13);
  auto n18 = gate_xor(n20, n21);
  y[3] = gate_xor(n19, n18);
  auto n17 = gate_and(n15, a[1]);
  auto n16 = gate_or(b[1], b[3]);
  auto n38 = gate_and(n17, n16);
  auto n23 = gate_and(n19, n18);
  auto n22 = gate_and(n21, n20);
  auto n31 = gate_or(n23, n22);
  auto n29 = gate_and(a[1], b[3]);
  auto n27 = gate_and(b[4], a[0]);
  auto n25 = gate_and(a[2], b[2]);
  auto n24 = gate_and(a[3], b[1]);
  auto n26 = gate_xor(n25, n24);
  auto n28 = gate_xor(n27, n26);
  auto n30 = gate_xor(n29, n28);
  auto n36 = gate_xor(n31, n30);
  auto n33 = gate_and(a[3], n32);
  auto n34 = gate_xor(a[4], n33);
  auto n35 = gate_and(b[0], n34);
  auto n37 = gate_xor(n36, n35);
  y[4] = gate_xor(n38, n37);
}
template<> void $NameUint<5>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_and(a[0], a[1]);
  auto n4 = gate_and(a[4], a[2]);
  auto n6 = gate_and(n5, n4);
  y[0] = gate_and(a[3], n6);
}
template<> void $NameUint<5>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_and(a[0], a[1]);
  auto n7 = gate_and(a[4], a[2]);
  auto n9 = gate_and(n8, n7);
  y[0] = gate_nand(a[3], n9);
}
template<> void $NameUint<5>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[0]);
  auto n10 = gate_not(a[4]);
  auto n15 = gate_and(n11, n10);
  auto n13 = gate_not(a[2]);
  auto n12 = gate_not(a[1]);
  auto n14 = gate_and(n13, n12);
  auto n17 = gate_and(n15, n14);
  auto n16 = gate_not(a[3]);
  y[0] = gate_and(n17, n16);
}
template<> void $NameUint<5>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[0]);
  auto n17 = gate_not(a[3]);
  auto n11 = gate_not(a[4]);
  auto n16 = gate_and(n12, n11);
  auto n14 = gate_not(a[2]);
  auto n13 = gate_not(a[1]);
  auto n15 = gate_and(n14, n13);
  auto n18 = gate_and(n16, n15);
  y[0] = gate_nand(n18, n17);
}
template<> void $NameUint<5>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_xor(a[0], a[1]);
  auto n8 = gate_xor(a[2], a[4]);
  auto n9 = gate_xor(a[3], n7);
  y[0] = gate_xnor(n9, n8);
}
template<> void $NameUint<5>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_xor(a[2], a[3]);
  auto n4 = gate_xor(a[4], a[1]);
  auto n6 = gate_xor(n5, n4);
  y[0] = gate_xor(a[0], n6);
}
template<> void $NameUint<5>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[4]);
  auto n19 = gate_not(b[3]);
  auto n27 = gate_and(n20, n19);
  auto n22 = gate_mux(a[4], a[0], b[2]);
  auto n26 = gate_not(b[2]);
  auto n21 = gate_and(a[3], n26);
  auto n24 = gate_mux(n22, n21, b[0]);
  auto n31 = gate_mux(a[2], a[1], b[0]);
  auto n23 = gate_and(n26, n31);
  auto n25 = gate_mux(n24, n23, b[1]);
  y[4] = gate_and(n27, n25);
  auto n34 = gate_and(n27, n26);
  auto n28 = gate_mux(a[3], a[2], b[0]);
  auto n35 = gate_mux(a[1], a[0], b[0]);
  auto n29 = gate_mux(n28, n35, b[1]);
  y[3] = gate_and(n34, n29);
  auto n30 = gate_not(b[0]);
  auto n36 = gate_and(a[0], n30);
  auto n32 = gate_mux(n31, n36, b[1]);
  y[2] = gate_and(n34, n32);
  auto n33 = gate_not(b[1]);
  auto n37 = gate_and(n34, n33);
  y[1] = gate_and(n37, n35);
  y[0] = gate_and(n37, n36);
}
template<> void $NameUint<5>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_not(b[0]);
  auto n20 = gate_and(a[4], n19);
  auto n26 = gate_not(b[1]);
  auto n34 = gate_and(n20, n26);
  auto n22 = gate_not(b[4]);
  auto n21 = gate_not(b[3]);
  auto n37 = gate_and(n22, n21);
  auto n23 = gate_not(b[2]);
  auto n31 = gate_and(n37, n23);
  y[4] = gate_and(n34, n31);
  auto n24 = gate_mux(a[3], a[4], b[0]);
  auto n25 = gate_and(n31, n24);
  y[3] = gate_and(n25, n26);
  auto n29 = gate_mux(a[2], a[4], b[1]);
  auto n27 = gate_and(a[3], n26);
  auto n28 = gate_mux(n29, n27, b[0]);
  y[2] = gate_and(n31, n28);
  auto n32 = gate_mux(a[1], a[3], b[1]);
  auto n30 = gate_mux(n32, n29, b[0]);
  y[1] = gate_and(n31, n30);
  auto n33 = gate_mux(a[0], a[2], b[1]);
  auto n35 = gate_mux(n33, n32, b[0]);
  auto n36 = gate_mux(n35, n34, b[2]);
  y[0] = gate_and(n37, n36);
}
template<> void $NameUint<5>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_buf(a[4]);
  auto n18 = gate_nand(b[1], y[4]);
  auto n21 = gate_not(b[2]);
  auto n20 = gate_not(b[4]);
  auto n23 = gate_and(n21, n20);
  auto n22 = gate_not(b[3]);
  auto n35 = gate_and(n23, n22);
  auto n24 = gate_not(b[1]);
  auto n31 = gate_and(n35, n24);
  auto n14 = gate_nand(a[2], n31);
  auto n25 = gate_not(b[0]);
  auto n41 = gate_and(n31, n25);
  auto n15 = gate_nand(n41, a[0]);
  y[3] = gate_mux(y[4], a[3], n41);
  auto n28 = gate_and(a[2], n41);
  auto n26 = gate_and(a[3], b[0]);
  auto n27 = gate_mux(y[4], n26, n31);
  y[2] = gate_or(n28, n27);
  auto n29 = gate_not(n35);
  auto n19 = gate_nand(y[4], n29);
  auto n30 = gate_mux(a[1], a[3], b[1]);
  auto n37 = gate_and(n35, n30);
  auto n33 = gate_not(n37);
  auto n32 = gate_and(n14, n18);
  auto n34 = gate_mux(n33, n32, b[0]);
  y[1] = gate_nand(n19, n34);
  auto n36 = gate_and(n35, b[1]);
  auto n38 = gate_and(n36, a[2]);
  auto n39 = gate_mux(n38, n37, b[0]);
  auto n40 = gate_not(n39);
  auto n42 = gate_and(n19, n40);
  y[0] = gate_nand(n42, n15);
}
template<> void $NameUint<5>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n6 = gate_not(b[1]);
  auto n7 = gate_xor(a[1], n6);
  auto n5 = gate_not(a[0]);
  auto n2 = gate_nand(b[0], n5);
  y[1] = gate_xor(n7, n2);
  auto n10 = gate_not(b[2]);
  auto n12 = gate_xor(a[2], n10);
  auto n9 = gate_and(a[1], n6);
  auto n8 = gate_and(n7, n2);
  auto n11 = gate_or(n9, n8);
  y[2] = gate_xor(n12, n11);
  auto n17 = gate_not(b[3]);
  auto n3 = gate_nand(a[3], n17);
  auto n16 = gate_xor(a[3], n17);
  auto n14 = gate_and(a[2], n10);
  auto n13 = gate_and(n12, n11);
  auto n15 = gate_or(n14, n13);
  auto n4 = gate_nand(n16, n15);
  y[3] = gate_xor(n16, n15);
  auto n19 = gate_and(n4, n3);
  auto n18 = gate_xor(a[4], b[4]);
  y[4] = gate_xor(n19, n18);
}
template<> void $NameUint<5>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n12 = gate_not(a[4]);
  auto n10 = gate_not(y[0]);
  auto n9 = gate_not(a[1]);
  auto n16 = gate_and(n10, n9);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_and(n16, n15);
  auto n13 = gate_not(a[3]);
  auto n11 = gate_and(n14, n13);
  y[4] = gate_xor(n12, n11);
  y[3] = gate_xor(n14, n13);
  y[2] = gate_xor(n16, n15);
  y[1] = gate_xor(y[0], a[1]);
}
