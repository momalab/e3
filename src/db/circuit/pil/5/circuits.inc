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
template<> void $NameUint<5>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  y[4] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n5 = gate_xor(N0, a[2]);
  auto n2 = gate_xor(n5, a[3]);
  auto n1 = gate_xor(a[1], a[4]);
  y[0] = gate_xor(n2, n1);
  auto n4 = gate_and(a[1], a[4]);
  auto n3 = gate_and(n2, n1);
  auto n9 = gate_or(n4, n3);
  auto n7 = gate_and(N0, a[2]);
  auto n6 = gate_and(n5, a[3]);
  auto n8 = gate_or(n7, n6);
  y[1] = gate_xor(n9, n8);
  y[2] = gate_and(n9, n8);
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
  auto n20 = gate_not(a[0]);
  auto n13 = gate_and(c[0], n20);
  auto n12 = gate_and(a[0], b[0]);
  y[0] = gate_or(n13, n12);
  auto n15 = gate_and(c[1], n20);
  auto n14 = gate_and(a[0], b[1]);
  y[1] = gate_or(n15, n14);
  auto n17 = gate_and(c[2], n20);
  auto n16 = gate_and(a[0], b[2]);
  y[2] = gate_or(n17, n16);
  auto n19 = gate_and(c[3], n20);
  auto n18 = gate_and(a[0], b[3]);
  y[3] = gate_or(n19, n18);
  auto n22 = gate_and(c[4], n20);
  auto n21 = gate_and(a[0], b[4]);
  y[4] = gate_or(n22, n21);
}
template<> void $NameUint<5>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_and(b[3], a[3]);
  auto n20 = gate_xor(b[3], a[3]);
  auto n16 = gate_and(b[2], a[2]);
  auto n22 = gate_xor(b[2], a[2]);
  auto n14 = gate_and(b[1], a[1]);
  auto n24 = gate_and(a[0], b[0]);
  auto n23 = gate_xor(b[1], a[1]);
  auto n13 = gate_and(n24, n23);
  auto n21 = gate_or(n14, n13);
  auto n15 = gate_and(n22, n21);
  auto n19 = gate_or(n16, n15);
  auto n17 = gate_and(n20, n19);
  y[4] = gate_or(n18, n17);
  y[3] = gate_xor(n20, n19);
  y[2] = gate_xor(n22, n21);
  y[1] = gate_xor(n24, n23);
  y[0] = gate_xor(a[0], b[0]);
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
  auto n38 = gate_not(b[1]);
  auto n82 = gate_not(b[4]);
  auto n75 = gate_not(b[3]);
  auto n32 = gate_and(n82, n75);
  auto n71 = gate_not(b[2]);
  auto n18 = gate_and(n32, n71);
  auto n17 = gate_and(n38, n18);
  auto n24 = gate_not(a[4]);
  auto n19 = gate_not(a[3]);
  auto n21 = gate_not(a[2]);
  auto n58 = gate_not(a[1]);
  auto n53 = gate_and(b[0], n58);
  auto n40 = gate_not(n53);
  auto n54 = gate_xor(b[1], n53);
  auto n57 = gate_not(a[0]);
  auto n62 = gate_and(b[0], n57);
  auto n2 = gate_nand(b[0], n21);
  auto n3 = gate_nand(b[0], n19);
  auto n8 = gate_nand(b[2], n24);
  auto n10 = gate_nand(b[0], n24);
  auto n12 = gate_nand(b[1], n24);
  y[4] = gate_and(n17, n10);
  auto n20 = gate_and(n18, n12);
  y[3] = gate_and(n20, n3);
  auto n27 = gate_not(y[3]);
  auto n26 = gate_not(y[4]);
  auto n28 = gate_and(n27, n26);
  auto n50 = gate_and(a[4], n28);
  auto n29 = gate_and(n50, n71);
  auto n46 = gate_not(n50);
  auto n47 = gate_and(b[3], n46);
  auto n11 = gate_nand(n20, b[0]);
  auto n36 = gate_and(a[3], n11);
  auto n23 = gate_and(n36, n38);
  auto n33 = gate_xor(n36, n38);
  auto n22 = gate_and(n33, n2);
  auto n25 = gate_or(n23, n22);
  auto n30 = gate_and(n25, n8);
  auto n31 = gate_or(n30, n29);
  y[2] = gate_and(n32, n31);
  auto n34 = gate_not(n33);
  auto n35 = gate_and(y[2], n34);
  auto n49 = gate_not(y[2]);
  auto n37 = gate_and(y[2], b[0]);
  auto n39 = gate_xor(n37, a[2]);
  auto n43 = gate_and(n38, n39);
  auto n55 = gate_not(n39);
  auto n41 = gate_xor(b[1], n55);
  auto n42 = gate_and(n41, n40);
  auto n70 = gate_or(n43, n42);
  auto n81 = gate_and(n50, n49);
  auto n52 = gate_not(n81);
  auto n72 = gate_xor(n71, n70);
  auto n6 = gate_nand(n36, n49);
  auto n9 = gate_nand(n81, n75);
  auto n13 = gate_nand(b[4], n52);
  auto n16 = gate_nand(n2, n35);
  auto n45 = gate_and(n16, n6);
  auto n44 = gate_xor(b[2], n45);
  auto n73 = gate_not(n45);
  auto n1 = gate_nand(n71, n73);
  auto n15 = gate_nand(n44, n70);
  auto n48 = gate_and(n15, n1);
  auto n51 = gate_or(n48, n47);
  auto n7 = gate_nand(n51, n9);
  y[1] = gate_and(n82, n7);
  auto n56 = gate_and(n54, y[1]);
  auto n67 = gate_xor(n56, n55);
  auto n59 = gate_and(y[1], b[0]);
  auto n61 = gate_xor(n59, n58);
  auto n60 = gate_or(n62, n61);
  auto n64 = gate_and(b[1], n60);
  auto n63 = gate_and(n62, n61);
  auto n66 = gate_or(n64, n63);
  auto n65 = gate_or(n67, n66);
  auto n69 = gate_and(b[2], n65);
  auto n68 = gate_and(n67, n66);
  auto n76 = gate_or(n69, n68);
  auto n74 = gate_and(n72, y[1]);
  auto n77 = gate_xor(n74, n73);
  auto n78 = gate_not(n77);
  auto n80 = gate_not(y[1]);
  auto n83 = gate_and(n81, n80);
  auto n84 = gate_and(n83, n82);
  auto n4 = gate_nand(n78, b[3]);
  auto n14 = gate_nand(n77, n75);
  auto n5 = gate_nand(n76, n14);
  auto n79 = gate_and(n5, n4);
  auto n85 = gate_and(n13, n79);
  y[0] = gate_or(n85, n84);
}
template<> void $NameUint<5>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_nand(b[0], a[0]);
  auto n39 = gate_not(b[4]);
  auto n100 = gate_xor(a[4], n39);
  auto n111 = gate_not(n100);
  auto n30 = gate_not(a[0]);
  auto n29 = gate_not(a[1]);
  auto n46 = gate_and(n30, n29);
  auto n31 = gate_not(a[2]);
  auto n35 = gate_and(n46, n31);
  auto n32 = gate_not(a[3]);
  auto n33 = gate_and(n35, n32);
  auto n41 = gate_and(a[4], n33);
  auto n88 = gate_xor(b[3], b[4]);
  auto n68 = gate_not(n88);
  auto n84 = gate_xor(b[2], b[4]);
  auto n62 = gate_not(n84);
  auto n43 = gate_and(n68, n62);
  auto n80 = gate_xor(b[1], b[4]);
  auto n72 = gate_not(n80);
  auto n113 = gate_and(n43, n72);
  auto n34 = gate_and(n41, n113);
  auto n102 = gate_and(b[0], n34);
  auto n36 = gate_not(n35);
  auto n37 = gate_and(n36, a[4]);
  auto n44 = gate_xor(n37, a[3]);
  auto n38 = gate_not(b[0]);
  auto n110 = gate_and(n39, n38);
  auto n78 = gate_not(n110);
  auto n45 = gate_not(n41);
  auto n47 = gate_not(n46);
  auto n48 = gate_and(n47, a[4]);
  auto n58 = gate_xor(n48, a[2]);
  auto n60 = gate_and(a[0], a[4]);
  auto n76 = gate_xor(n60, a[1]);
  auto n82 = gate_and(n78, n14);
  auto n79 = gate_not(n82);
  auto n112 = gate_and(n111, n110);
  auto n115 = gate_and(n113, n112);
  auto n10 = gate_nand(n80, n45);
  auto n13 = gate_nand(n84, n45);
  auto n16 = gate_nand(n113, b[0]);
  auto n20 = gate_nand(b[0], n76);
  auto n21 = gate_nand(b[0], n58);
  auto n23 = gate_nand(b[0], n44);
  auto n52 = gate_and(n41, n16);
  auto n40 = gate_and(n78, n23);
  auto n49 = gate_and(n78, n21);
  auto n5 = gate_nand(n78, n20);
  auto n28 = gate_nand(n52, n72);
  auto n73 = gate_xor(n5, n72);
  auto n6 = gate_nand(n28, n40);
  auto n42 = gate_and(n6, n10);
  auto n11 = gate_nand(n43, n42);
  auto n56 = gate_and(n44, n11);
  auto n50 = gate_not(n56);
  auto n67 = gate_and(n52, n11);
  auto n53 = gate_and(n67, n62);
  auto n104 = gate_xor(n100, n11);
  auto n4 = gate_nand(n50, n80);
  auto n22 = gate_nand(n56, n72);
  auto n9 = gate_nand(n49, n22);
  auto n51 = gate_and(n9, n4);
  auto n54 = gate_and(n13, n51);
  auto n55 = gate_or(n54, n53);
  auto n57 = gate_and(n68, n55);
  auto n99 = gate_not(n57);
  auto n71 = gate_and(n56, n99);
  auto n59 = gate_and(n57, b[0]);
  auto n74 = gate_xor(n59, n58);
  auto n61 = gate_xor(n74, n72);
  auto n64 = gate_not(n71);
  auto n65 = gate_and(n84, n64);
  auto n95 = gate_and(n67, n99);
  auto n70 = gate_not(n95);
  auto n106 = gate_xor(n100, n99);
  auto n1 = gate_nand(n62, n71);
  auto n2 = gate_nand(n95, n68);
  auto n18 = gate_nand(n70, n88);
  auto n26 = gate_nand(n61, n5);
  auto n27 = gate_nand(n74, n72);
  auto n63 = gate_and(n27, n26);
  auto n66 = gate_and(n63, n1);
  auto n69 = gate_or(n66, n65);
  auto n17 = gate_nand(n69, n2);
  auto n98 = gate_and(n17, n18);
  auto n96 = gate_not(n98);
  auto n89 = gate_and(n71, n96);
  auto n75 = gate_and(n73, n98);
  auto n86 = gate_xor(n75, n74);
  auto n77 = gate_and(n98, b[0]);
  auto n81 = gate_xor(n77, n76);
  auto n83 = gate_not(n81);
  auto n92 = gate_not(n89);
  auto n108 = gate_xor(n98, n111);
  auto n8 = gate_nand(n83, n82);
  auto n15 = gate_nand(n96, n95);
  auto n19 = gate_nand(n81, n79);
  auto n7 = gate_nand(n80, n19);
  auto n85 = gate_and(n7, n8);
  auto n87 = gate_or(n86, n85);
  auto n25 = gate_nand(n86, n85);
  auto n12 = gate_nand(n84, n25);
  auto n90 = gate_and(n12, n87);
  auto n91 = gate_not(n90);
  auto n93 = gate_and(n92, n91);
  auto n24 = gate_nand(n89, n90);
  auto n94 = gate_and(n88, n24);
  auto n97 = gate_or(n94, n93);
  auto n114 = gate_and(n97, n15);
  auto n109 = gate_and(n114, n111);
  auto n107 = gate_and(n109, n108);
  auto n105 = gate_and(n107, n106);
  auto n101 = gate_and(n105, n104);
  auto n103 = gate_xor(n102, n101);
  y[4] = gate_xor(n111, n103);
  y[3] = gate_xor(n105, n104);
  y[2] = gate_xor(n107, n106);
  y[1] = gate_xor(n109, n108);
  y[0] = gate_xnor(n115, n114);
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
  auto n38 = gate_not(a[3]);
  auto n39 = gate_not(a[2]);
  auto n40 = gate_not(b[2]);
  auto n41 = gate_not(b[1]);
  auto n42 = gate_not(a[0]);
  auto n45 = gate_and(b[0], n42);
  auto n43 = gate_not(a[1]);
  auto n44 = gate_and(b[1], n43);
  auto n46 = gate_or(n45, n44);
  auto n49 = gate_not(b[3]);
  auto n50 = gate_and(a[3], n49);
  auto n52 = gate_not(a[4]);
  auto n54 = gate_not(b[4]);
  auto n55 = gate_and(a[4], n54);
  auto n33 = gate_nand(b[3], n38);
  auto n34 = gate_nand(b[4], n52);
  auto n35 = gate_nand(b[2], n39);
  auto n36 = gate_nand(a[2], n40);
  auto n37 = gate_nand(a[1], n41);
  auto n48 = gate_and(n33, n35);
  auto n47 = gate_and(n36, n37);
  auto n32 = gate_nand(n47, n46);
  auto n51 = gate_and(n48, n32);
  auto n53 = gate_or(n51, n50);
  auto n56 = gate_and(n53, n34);
  y[0] = gate_or(n56, n55);
}
template<> void $NameUint<5>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(a[3]);
  auto n39 = gate_not(a[2]);
  auto n40 = gate_not(b[2]);
  auto n41 = gate_not(b[1]);
  auto n42 = gate_not(a[0]);
  auto n45 = gate_and(b[0], n42);
  auto n43 = gate_not(a[1]);
  auto n44 = gate_and(b[1], n43);
  auto n46 = gate_or(n45, n44);
  auto n49 = gate_not(b[3]);
  auto n50 = gate_and(a[3], n49);
  auto n52 = gate_not(b[4]);
  auto n54 = gate_not(a[4]);
  auto n55 = gate_and(b[4], n54);
  auto n32 = gate_nand(b[2], n39);
  auto n33 = gate_nand(b[3], n38);
  auto n35 = gate_nand(a[4], n52);
  auto n36 = gate_nand(a[2], n40);
  auto n37 = gate_nand(a[1], n41);
  auto n48 = gate_and(n33, n32);
  auto n47 = gate_and(n36, n37);
  auto n34 = gate_nand(n47, n46);
  auto n51 = gate_and(n48, n34);
  auto n53 = gate_or(n51, n50);
  auto n56 = gate_and(n53, n35);
  y[0] = gate_or(n56, n55);
}
template<> void $NameUint<5>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(a[3]);
  auto n43 = gate_not(a[2]);
  auto n44 = gate_not(a[1]);
  auto n45 = gate_not(b[0]);
  auto n47 = gate_not(b[2]);
  auto n48 = gate_not(b[1]);
  auto n51 = gate_not(b[3]);
  auto n52 = gate_and(a[3], n51);
  auto n54 = gate_not(a[4]);
  auto n56 = gate_not(b[4]);
  auto n57 = gate_and(a[4], n56);
  auto n35 = gate_nand(b[1], n44);
  auto n36 = gate_nand(b[2], n43);
  auto n37 = gate_nand(b[4], n54);
  auto n38 = gate_nand(b[3], n42);
  auto n40 = gate_nand(a[2], n47);
  auto n41 = gate_nand(a[1], n48);
  auto n50 = gate_and(n38, n36);
  auto n46 = gate_and(a[0], n35);
  auto n39 = gate_nand(n46, n45);
  auto n49 = gate_and(n39, n40);
  auto n34 = gate_nand(n49, n41);
  auto n53 = gate_and(n50, n34);
  auto n55 = gate_or(n53, n52);
  auto n58 = gate_and(n55, n37);
  y[0] = gate_or(n58, n57);
}
template<> void $NameUint<5>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(a[3]);
  auto n43 = gate_not(a[2]);
  auto n44 = gate_not(a[1]);
  auto n45 = gate_not(b[0]);
  auto n47 = gate_not(b[2]);
  auto n48 = gate_not(b[1]);
  auto n51 = gate_not(b[3]);
  auto n52 = gate_and(a[3], n51);
  auto n54 = gate_not(b[4]);
  auto n56 = gate_not(a[4]);
  auto n57 = gate_and(b[4], n56);
  auto n35 = gate_nand(b[1], n44);
  auto n37 = gate_nand(b[3], n42);
  auto n38 = gate_nand(b[2], n43);
  auto n39 = gate_nand(a[4], n54);
  auto n40 = gate_nand(a[2], n47);
  auto n41 = gate_nand(a[1], n48);
  auto n50 = gate_and(n37, n38);
  auto n46 = gate_and(a[0], n35);
  auto n36 = gate_nand(n46, n45);
  auto n49 = gate_and(n36, n40);
  auto n34 = gate_nand(n49, n41);
  auto n53 = gate_and(n50, n34);
  auto n55 = gate_or(n53, n52);
  auto n58 = gate_and(n55, n39);
  y[0] = gate_or(n58, n57);
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
  auto n20 = gate_not(a[0]);
  auto n19 = gate_not(a[4]);
  auto n24 = gate_and(n20, n19);
  auto n22 = gate_not(a[2]);
  auto n21 = gate_not(a[1]);
  auto n23 = gate_and(n22, n21);
  auto n26 = gate_and(n24, n23);
  auto n25 = gate_not(a[3]);
  auto n34 = gate_and(n26, n25);
  y[0] = gate_mux(b[0], c[0], n34);
  auto n33 = gate_not(n34);
  auto n28 = gate_and(b[1], n33);
  auto n27 = gate_and(n34, c[1]);
  y[1] = gate_or(n28, n27);
  auto n30 = gate_and(b[2], n33);
  auto n29 = gate_and(n34, c[2]);
  y[2] = gate_or(n30, n29);
  auto n32 = gate_and(b[3], n33);
  auto n31 = gate_and(n34, c[3]);
  y[3] = gate_or(n32, n31);
  auto n36 = gate_and(b[4], n33);
  auto n35 = gate_and(n34, c[4]);
  y[4] = gate_or(n36, n35);
}
template<> void $NameUint<5>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[3]);
  auto n39 = gate_not(b[2]);
  auto n40 = gate_not(a[2]);
  auto n41 = gate_not(a[1]);
  auto n42 = gate_not(b[0]);
  auto n45 = gate_and(a[0], n42);
  auto n43 = gate_not(b[1]);
  auto n44 = gate_and(a[1], n43);
  auto n46 = gate_or(n45, n44);
  auto n49 = gate_not(a[3]);
  auto n50 = gate_and(b[3], n49);
  auto n52 = gate_not(b[4]);
  auto n54 = gate_not(a[4]);
  auto n55 = gate_and(b[4], n54);
  auto n32 = gate_nand(b[1], n41);
  auto n33 = gate_nand(b[2], n40);
  auto n34 = gate_nand(a[4], n52);
  auto n35 = gate_nand(a[3], n38);
  auto n36 = gate_nand(a[2], n39);
  auto n48 = gate_and(n35, n36);
  auto n47 = gate_and(n33, n32);
  auto n37 = gate_nand(n47, n46);
  auto n51 = gate_and(n48, n37);
  auto n53 = gate_or(n51, n50);
  auto n56 = gate_and(n53, n34);
  y[0] = gate_or(n56, n55);
}
template<> void $NameUint<5>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[3]);
  auto n39 = gate_not(b[2]);
  auto n40 = gate_not(a[2]);
  auto n41 = gate_not(a[1]);
  auto n42 = gate_not(b[0]);
  auto n45 = gate_and(a[0], n42);
  auto n43 = gate_not(b[1]);
  auto n44 = gate_and(a[1], n43);
  auto n46 = gate_or(n45, n44);
  auto n49 = gate_not(a[3]);
  auto n50 = gate_and(b[3], n49);
  auto n52 = gate_not(a[4]);
  auto n54 = gate_not(b[4]);
  auto n55 = gate_and(a[4], n54);
  auto n32 = gate_nand(b[2], n40);
  auto n33 = gate_nand(b[4], n52);
  auto n34 = gate_nand(b[1], n41);
  auto n35 = gate_nand(a[3], n38);
  auto n36 = gate_nand(a[2], n39);
  auto n48 = gate_and(n35, n36);
  auto n47 = gate_and(n32, n34);
  auto n37 = gate_nand(n47, n46);
  auto n51 = gate_and(n48, n37);
  auto n53 = gate_or(n51, n50);
  auto n56 = gate_and(n53, n33);
  y[0] = gate_or(n56, n55);
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
  auto n32 = gate_not(b[0]);
  auto n31 = gate_not(b[4]);
  auto n36 = gate_and(n32, n31);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[1]);
  auto n35 = gate_and(n34, n33);
  auto n38 = gate_and(n36, n35);
  auto n37 = gate_not(b[3]);
  auto n21 = gate_nand(n38, n37);
  auto n22 = gate_nand(n30, n29);
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
  auto n42 = gate_not(b[3]);
  auto n43 = gate_not(b[2]);
  auto n44 = gate_not(b[1]);
  auto n45 = gate_not(a[0]);
  auto n47 = gate_not(a[2]);
  auto n48 = gate_not(a[1]);
  auto n51 = gate_not(a[3]);
  auto n52 = gate_and(b[3], n51);
  auto n54 = gate_not(b[4]);
  auto n56 = gate_not(a[4]);
  auto n57 = gate_and(b[4], n56);
  auto n35 = gate_nand(b[1], n48);
  auto n36 = gate_nand(b[2], n47);
  auto n38 = gate_nand(a[3], n42);
  auto n39 = gate_nand(a[2], n43);
  auto n40 = gate_nand(a[1], n44);
  auto n41 = gate_nand(a[4], n54);
  auto n50 = gate_and(n38, n39);
  auto n46 = gate_and(b[0], n40);
  auto n37 = gate_nand(n46, n45);
  auto n49 = gate_and(n37, n36);
  auto n34 = gate_nand(n49, n35);
  auto n53 = gate_and(n50, n34);
  auto n55 = gate_or(n53, n52);
  auto n58 = gate_and(n55, n41);
  y[0] = gate_or(n58, n57);
}
template<> void $NameUint<5>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(b[3]);
  auto n43 = gate_not(b[2]);
  auto n44 = gate_not(b[1]);
  auto n45 = gate_not(a[0]);
  auto n47 = gate_not(a[2]);
  auto n48 = gate_not(a[1]);
  auto n51 = gate_not(a[3]);
  auto n52 = gate_and(b[3], n51);
  auto n54 = gate_not(a[4]);
  auto n56 = gate_not(b[4]);
  auto n57 = gate_and(a[4], n56);
  auto n36 = gate_nand(b[2], n47);
  auto n37 = gate_nand(b[4], n54);
  auto n38 = gate_nand(b[1], n48);
  auto n39 = gate_nand(a[3], n42);
  auto n40 = gate_nand(a[2], n43);
  auto n41 = gate_nand(a[1], n44);
  auto n50 = gate_and(n39, n40);
  auto n46 = gate_and(b[0], n41);
  auto n35 = gate_nand(n46, n45);
  auto n49 = gate_and(n35, n36);
  auto n34 = gate_nand(n49, n38);
  auto n53 = gate_and(n50, n34);
  auto n55 = gate_or(n53, n52);
  auto n58 = gate_and(n55, n37);
  y[0] = gate_or(n58, n57);
}
template<> void $NameUint<5>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n64 = gate_not(b[1]);
  auto n79 = gate_not(b[4]);
  auto n83 = gate_not(b[3]);
  auto n51 = gate_and(n79, n83);
  auto n88 = gate_not(b[2]);
  auto n17 = gate_and(n51, n88);
  auto n14 = gate_and(n17, b[0]);
  auto n15 = gate_not(b[0]);
  auto n26 = gate_not(a[4]);
  auto n18 = gate_not(a[3]);
  auto n21 = gate_not(a[2]);
  auto n34 = gate_and(b[0], n21);
  auto n22 = gate_not(n34);
  auto n38 = gate_not(a[1]);
  auto n58 = gate_and(b[0], n38);
  auto n39 = gate_not(n58);
  auto n59 = gate_xor(n58, b[1]);
  auto n65 = gate_not(a[0]);
  auto n92 = gate_and(b[0], n65);
  auto n66 = gate_not(n92);
  auto n93 = gate_xor(n92, b[1]);
  auto n1 = gate_nand(n64, n15);
  auto n2 = gate_nand(n64, n14);
  auto n3 = gate_nand(b[2], n26);
  auto n4 = gate_nand(b[0], n18);
  auto n5 = gate_nand(b[1], n26);
  auto n20 = gate_and(a[4], n2);
  auto n16 = gate_and(n1, n5);
  auto n19 = gate_and(n17, n16);
  auto n7 = gate_nand(n19, n4);
  auto n31 = gate_and(n20, n7);
  auto n32 = gate_and(a[3], n7);
  auto n25 = gate_and(n32, n64);
  auto n23 = gate_xor(n32, n64);
  auto n24 = gate_and(n23, n22);
  auto n30 = gate_or(n25, n24);
  auto n28 = gate_and(n30, n3);
  auto n27 = gate_and(n31, n88);
  auto n29 = gate_or(n28, n27);
  auto n36 = gate_and(n51, n29);
  auto n33 = gate_and(n36, b[1]);
  auto n35 = gate_xor(n33, n32);
  auto n37 = gate_and(n36, b[0]);
  auto n60 = gate_xor(n37, a[2]);
  auto n42 = gate_and(n64, n60);
  auto n40 = gate_xor(n64, n60);
  auto n41 = gate_and(n40, n39);
  auto n54 = gate_or(n42, n41);
  auto n55 = gate_xor(n54, n88);
  auto n8 = gate_nand(n30, n88);
  auto n9 = gate_nand(n36, n34);
  auto n13 = gate_nand(n36, n8);
  auto n50 = gate_and(n31, n13);
  auto n56 = gate_and(n35, n9);
  auto n45 = gate_and(n88, n56);
  auto n43 = gate_xor(n88, n56);
  auto n44 = gate_and(n43, n54);
  auto n47 = gate_or(n45, n44);
  auto n46 = gate_xor(n47, n83);
  auto n76 = gate_not(n50);
  auto n48 = gate_xor(b[3], n76);
  auto n49 = gate_and(n48, n47);
  auto n53 = gate_and(n49, n79);
  auto n52 = gate_and(n51, n50);
  auto n62 = gate_or(n53, n52);
  auto n57 = gate_and(n62, n55);
  auto n85 = gate_xor(n57, n56);
  auto n75 = gate_and(n85, n83);
  auto n73 = gate_xor(n83, n85);
  auto n61 = gate_and(n62, n59);
  auto n90 = gate_xor(n61, n60);
  auto n72 = gate_and(n90, n88);
  auto n70 = gate_xor(n88, n90);
  auto n63 = gate_and(n62, b[0]);
  auto n94 = gate_xor(n63, a[1]);
  auto n69 = gate_and(n64, n94);
  auto n67 = gate_xor(n64, n94);
  auto n68 = gate_and(n67, n66);
  auto n87 = gate_or(n69, n68);
  auto n71 = gate_and(n70, n87);
  auto n82 = gate_or(n72, n71);
  auto n74 = gate_and(n73, n82);
  auto n80 = gate_or(n75, n74);
  auto n84 = gate_xor(n83, n82);
  auto n89 = gate_xor(n88, n87);
  auto n6 = gate_nand(n76, b[4]);
  auto n10 = gate_nand(n80, n79);
  auto n12 = gate_nand(n46, n79);
  auto n81 = gate_and(n50, n12);
  auto n78 = gate_and(n80, n6);
  auto n77 = gate_and(n81, n79);
  auto n96 = gate_or(n78, n77);
  auto n86 = gate_and(n84, n96);
  y[3] = gate_xor(n86, n85);
  auto n91 = gate_and(n89, n96);
  y[2] = gate_xor(n91, n90);
  auto n95 = gate_and(n93, n96);
  y[1] = gate_xor(n95, n94);
  auto n97 = gate_and(n96, b[0]);
  y[0] = gate_xor(n97, a[0]);
  auto n11 = gate_nand(n96, n10);
  y[4] = gate_and(n81, n11);
}
template<> void $NameUint<5>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_nand(a[0], b[0]);
  auto n36 = gate_not(a[3]);
  auto n29 = gate_not(a[1]);
  auto n28 = gate_not(a[0]);
  auto n45 = gate_and(n29, n28);
  auto n30 = gate_not(a[2]);
  auto n34 = gate_and(n45, n30);
  auto n32 = gate_and(n36, n34);
  auto n76 = gate_xor(b[2], b[4]);
  auto n98 = gate_not(n76);
  auto n112 = gate_xor(b[3], b[4]);
  auto n80 = gate_not(n112);
  auto n56 = gate_and(n98, n80);
  auto n31 = gate_and(b[0], n56);
  auto n59 = gate_xor(b[1], b[4]);
  auto n105 = gate_not(n59);
  auto n35 = gate_not(n34);
  auto n37 = gate_and(n35, a[4]);
  auto n42 = gate_xor(n37, n36);
  auto n86 = gate_or(b[0], b[4]);
  auto n44 = gate_not(n42);
  auto n46 = gate_not(n45);
  auto n47 = gate_and(n46, a[4]);
  auto n65 = gate_xor(n47, a[2]);
  auto n67 = gate_and(a[4], a[0]);
  auto n84 = gate_xor(a[1], n67);
  auto n103 = gate_xor(a[0], a[4]);
  auto n3 = gate_nand(n31, n105);
  auto n11 = gate_nand(n86, n13);
  auto n20 = gate_nand(b[0], n84);
  auto n25 = gate_nand(b[0], n65);
  auto n26 = gate_nand(n42, n86);
  auto n33 = gate_and(n32, n3);
  auto n41 = gate_and(a[4], n33);
  auto n38 = gate_xor(n41, n105);
  auto n39 = gate_and(n38, n26);
  auto n43 = gate_and(n56, n39);
  auto n40 = gate_not(n43);
  auto n55 = gate_and(n41, n40);
  auto n62 = gate_and(n86, n25);
  auto n48 = gate_not(n62);
  auto n57 = gate_and(n56, n55);
  auto n106 = gate_xor(n11, n105);
  auto n7 = gate_nand(n86, n20);
  auto n27 = gate_nand(n43, b[0]);
  auto n60 = gate_and(n44, n27);
  auto n51 = gate_and(n60, n105);
  auto n49 = gate_xor(n60, n105);
  auto n50 = gate_and(n49, n48);
  auto n53 = gate_or(n51, n50);
  auto n52 = gate_xor(n53, n98);
  auto n54 = gate_and(n98, n53);
  auto n58 = gate_and(n80, n54);
  auto n64 = gate_or(n58, n57);
  auto n61 = gate_and(n64, n59);
  auto n63 = gate_xor(n61, n60);
  auto n66 = gate_and(n64, b[0]);
  auto n82 = gate_xor(n66, n65);
  auto n68 = gate_xor(n82, n105);
  auto n81 = gate_xor(n105, n7);
  auto n4 = gate_nand(n52, n80);
  auto n15 = gate_nand(n64, n62);
  auto n23 = gate_nand(n68, n7);
  auto n24 = gate_nand(n82, n105);
  auto n73 = gate_and(n55, n4);
  auto n77 = gate_and(n63, n15);
  auto n70 = gate_xor(n98, n77);
  auto n75 = gate_and(n24, n23);
  auto n69 = gate_not(n75);
  auto n2 = gate_nand(n70, n69);
  auto n6 = gate_nand(n80, n73);
  auto n8 = gate_nand(n98, n77);
  auto n71 = gate_and(n8, n2);
  auto n74 = gate_not(n71);
  auto n5 = gate_nand(n71, n80);
  auto n9 = gate_nand(n74, n80);
  auto n17 = gate_nand(n74, n112);
  auto n72 = gate_and(n5, n17);
  auto n94 = gate_and(n73, n72);
  auto n95 = gate_not(n94);
  auto n1 = gate_nand(n6, n9);
  auto n12 = gate_nand(n1, n75);
  auto n78 = gate_and(n1, n76);
  auto n79 = gate_xor(n78, n77);
  auto n113 = gate_and(n12, n79);
  auto n92 = gate_xor(n80, n113);
  auto n83 = gate_and(n1, n81);
  auto n100 = gate_xor(n83, n82);
  auto n90 = gate_xor(n98, n100);
  auto n85 = gate_and(n1, b[0]);
  auto n107 = gate_xor(n85, n84);
  auto n89 = gate_and(n107, n105);
  auto n87 = gate_xor(n107, n105);
  auto n88 = gate_and(n87, n11);
  auto n97 = gate_or(n89, n88);
  auto n99 = gate_xor(n98, n97);
  auto n19 = gate_nand(n113, n80);
  auto n21 = gate_nand(n90, n97);
  auto n22 = gate_nand(n100, n98);
  auto n111 = gate_and(n22, n21);
  auto n91 = gate_not(n111);
  auto n18 = gate_nand(n92, n91);
  auto n96 = gate_and(n19, n18);
  auto n93 = gate_not(n96);
  auto n10 = gate_nand(n96, n95);
  auto n14 = gate_nand(n10, n111);
  auto n16 = gate_nand(n94, n93);
  auto n118 = gate_and(a[4], n16);
  auto n101 = gate_and(n10, n99);
  auto n102 = gate_xor(n101, n100);
  auto n122 = gate_xor(a[4], n102);
  auto n104 = gate_and(b[0], n10);
  auto n126 = gate_xor(n104, n103);
  auto n110 = gate_and(a[4], n126);
  auto n108 = gate_and(n106, n10);
  auto n124 = gate_xor(n108, n107);
  auto n109 = gate_not(n124);
  auto n121 = gate_and(n110, n109);
  auto n120 = gate_and(n122, n121);
  auto n114 = gate_and(n10, n112);
  auto n115 = gate_xor(n114, n113);
  auto n116 = gate_and(n14, n115);
  auto n119 = gate_xor(a[4], n116);
  auto n117 = gate_and(n120, n119);
  y[4] = gate_xor(n118, n117);
  y[3] = gate_xor(n120, n119);
  y[2] = gate_xor(n122, n121);
  auto n123 = gate_not(n126);
  auto n125 = gate_and(n123, a[4]);
  y[1] = gate_xor(n125, n124);
  y[0] = gate_xor(a[4], n126);
}
template<> void $NameUint<5>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n8 = gate_and(a[1], b[0]);
  auto n7 = gate_and(b[1], a[0]);
  y[1] = gate_xor(n8, n7);
  auto n10 = gate_and(n8, n7);
  auto n12 = gate_and(a[1], b[1]);
  auto n37 = gate_and(a[0], b[2]);
  auto n9 = gate_xor(n12, n37);
  auto n19 = gate_or(n10, n9);
  auto n20 = gate_and(b[0], a[2]);
  auto n15 = gate_and(b[3], a[0]);
  auto n16 = gate_and(a[3], b[0]);
  auto n22 = gate_and(b[1], a[2]);
  auto n17 = gate_xor(n16, n22);
  auto n23 = gate_and(a[3], n22);
  auto n24 = gate_xor(a[4], n23);
  auto n36 = gate_and(b[0], n24);
  auto n32 = gate_and(a[3], b[1]);
  auto n30 = gate_and(a[1], b[3]);
  auto n28 = gate_and(a[2], b[2]);
  auto n27 = gate_and(b[4], a[0]);
  auto n29 = gate_xor(n28, n27);
  auto n31 = gate_xor(n30, n29);
  auto n33 = gate_xor(n32, n31);
  auto n39 = gate_and(n37, a[1]);
  auto n38 = gate_or(b[1], b[3]);
  auto n40 = gate_and(n39, n38);
  auto n1 = gate_nand(n20, n19);
  auto n3 = gate_nand(n12, n37);
  auto n4 = gate_nand(n10, n9);
  auto n11 = gate_and(n4, n19);
  y[2] = gate_xor(n11, n20);
  auto n13 = gate_and(b[2], n3);
  auto n14 = gate_and(n13, a[1]);
  auto n18 = gate_xor(n15, n14);
  auto n26 = gate_or(n18, n17);
  auto n25 = gate_and(n4, n1);
  auto n5 = gate_nand(n18, n17);
  auto n21 = gate_and(n26, n5);
  auto n2 = gate_nand(n25, n5);
  y[3] = gate_xnor(n21, n25);
  auto n34 = gate_and(n26, n2);
  auto n35 = gate_xor(n34, n33);
  auto n41 = gate_xor(n36, n35);
  y[4] = gate_xor(n41, n40);
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
  auto n11 = gate_not(a[4]);
  auto n16 = gate_and(n12, n11);
  auto n14 = gate_not(a[2]);
  auto n13 = gate_not(a[1]);
  auto n15 = gate_and(n14, n13);
  auto n18 = gate_and(n16, n15);
  auto n17 = gate_not(a[3]);
  y[0] = gate_nand(n18, n17);
}
template<> void $NameUint<5>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_xor(a[0], a[1]);
  auto n9 = gate_xor(a[3], n7);
  auto n8 = gate_xor(a[2], a[4]);
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
  auto n56 = gate_nand(b[0], a[0]);
  auto n57 = gate_nand(b[0], a[2]);
  auto n60 = gate_nand(b[0], a[3]);
  auto n62 = gate_nand(b[0], a[1]);
  auto n66 = gate_not(b[4]);
  auto n65 = gate_not(b[3]);
  auto n74 = gate_and(n66, n65);
  auto n76 = gate_not(b[0]);
  auto n86 = gate_and(a[0], n76);
  auto n67 = gate_and(b[2], n86);
  auto n81 = gate_not(b[1]);
  auto n71 = gate_and(n67, n81);
  auto n73 = gate_not(b[2]);
  auto n82 = gate_and(n74, n73);
  auto n78 = gate_not(n86);
  auto n85 = gate_and(n82, n81);
  y[0] = gate_and(n86, n85);
  auto n51 = gate_nand(a[4], n76);
  auto n55 = gate_nand(b[1], n78);
  auto n58 = gate_nand(a[2], n76);
  auto n59 = gate_nand(a[3], n76);
  auto n61 = gate_nand(a[1], n76);
  auto n68 = gate_and(n51, n60);
  auto n79 = gate_and(n58, n62);
  auto n75 = gate_and(n59, n57);
  auto n83 = gate_and(n61, n56);
  auto n84 = gate_not(n83);
  y[1] = gate_and(n85, n84);
  auto n52 = gate_nand(n79, n81);
  auto n53 = gate_nand(n81, n75);
  auto n54 = gate_nand(n81, n68);
  auto n63 = gate_nand(n83, b[1]);
  auto n64 = gate_nand(b[1], n79);
  auto n69 = gate_and(n54, n64);
  auto n70 = gate_and(n69, n73);
  auto n72 = gate_or(n71, n70);
  y[4] = gate_and(n74, n72);
  auto n77 = gate_and(n82, n53);
  y[3] = gate_and(n77, n63);
  auto n80 = gate_and(n55, n52);
  y[2] = gate_and(n82, n80);
}
template<> void $NameUint<5>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n56 = gate_nand(b[0], a[3]);
  auto n58 = gate_nand(b[0], a[2]);
  auto n60 = gate_nand(b[0], a[4]);
  auto n61 = gate_nand(b[0], a[1]);
  auto n77 = gate_not(b[0]);
  auto n75 = gate_and(a[4], n77);
  auto n66 = gate_not(b[4]);
  auto n65 = gate_not(b[3]);
  auto n86 = gate_and(n66, n65);
  auto n81 = gate_not(b[2]);
  auto n72 = gate_and(n86, n81);
  auto n79 = gate_not(b[1]);
  auto n68 = gate_and(n72, n79);
  y[4] = gate_and(n75, n68);
  auto n69 = gate_not(n75);
  auto n76 = gate_and(b[2], n75);
  auto n84 = gate_and(n76, n79);
  auto n51 = gate_nand(a[0], n77);
  auto n55 = gate_nand(b[1], n69);
  auto n57 = gate_nand(a[3], n77);
  auto n59 = gate_nand(a[2], n77);
  auto n62 = gate_nand(a[1], n77);
  auto n73 = gate_and(n57, n60);
  auto n67 = gate_not(n73);
  y[3] = gate_and(n68, n67);
  auto n80 = gate_and(n59, n56);
  auto n71 = gate_and(n62, n58);
  auto n78 = gate_and(n51, n61);
  auto n52 = gate_nand(n79, n78);
  auto n53 = gate_nand(n79, n71);
  auto n54 = gate_nand(n80, n79);
  auto n63 = gate_nand(b[1], n80);
  auto n64 = gate_nand(b[1], n73);
  auto n70 = gate_and(n55, n54);
  y[2] = gate_and(n72, n70);
  auto n74 = gate_and(n53, n72);
  y[1] = gate_and(n74, n64);
  auto n82 = gate_and(n52, n63);
  auto n83 = gate_and(n82, n81);
  auto n85 = gate_or(n84, n83);
  y[0] = gate_and(n86, n85);
}
template<> void $NameUint<5>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_buf(a[4]);
  auto n50 = gate_nand(b[0], y[4]);
  auto n55 = gate_nand(b[0], a[3]);
  auto n56 = gate_nand(b[0], a[1]);
  auto n58 = gate_nand(b[0], a[2]);
  auto n63 = gate_not(b[4]);
  auto n62 = gate_not(b[3]);
  auto n65 = gate_and(n63, n62);
  auto n64 = gate_not(b[2]);
  auto n80 = gate_and(n65, n64);
  auto n79 = gate_not(b[1]);
  auto n69 = gate_and(n80, n79);
  auto n77 = gate_not(b[0]);
  auto n66 = gate_and(n69, n77);
  y[3] = gate_mux(y[4], a[3], n66);
  auto n67 = gate_not(n69);
  auto n71 = gate_and(y[4], n67);
  auto n72 = gate_not(n80);
  auto n84 = gate_and(y[4], n72);
  auto n53 = gate_nand(a[0], n77);
  auto n54 = gate_nand(a[3], n77);
  auto n57 = gate_nand(a[1], n77);
  auto n59 = gate_nand(a[2], n77);
  auto n81 = gate_and(n59, n55);
  auto n68 = gate_not(n81);
  auto n70 = gate_and(n69, n68);
  y[2] = gate_or(n71, n70);
  auto n73 = gate_and(n54, n50);
  auto n74 = gate_and(n57, n58);
  auto n78 = gate_and(n53, n56);
  auto n51 = gate_nand(n79, n78);
  auto n52 = gate_nand(n79, n74);
  auto n60 = gate_nand(b[1], n81);
  auto n61 = gate_nand(b[1], n73);
  auto n75 = gate_and(n61, n52);
  auto n76 = gate_and(n80, n75);
  y[1] = gate_or(n84, n76);
  auto n82 = gate_and(n51, n80);
  auto n83 = gate_and(n82, n60);
  y[0] = gate_or(n84, n83);
}
template<> void $NameUint<5>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n6 = gate_not(b[1]);
  auto n7 = gate_xor(a[1], n6);
  auto n5 = gate_not(a[0]);
  auto n10 = gate_not(b[2]);
  auto n12 = gate_xor(a[2], n10);
  auto n9 = gate_and(a[1], n6);
  auto n17 = gate_not(b[3]);
  auto n16 = gate_xor(a[3], n17);
  auto n14 = gate_and(a[2], n10);
  auto n18 = gate_xor(a[4], b[4]);
  auto n2 = gate_nand(b[0], n5);
  auto n3 = gate_nand(a[3], n17);
  y[1] = gate_xor(n7, n2);
  auto n8 = gate_and(n7, n2);
  auto n11 = gate_or(n9, n8);
  y[2] = gate_xor(n12, n11);
  auto n13 = gate_and(n12, n11);
  auto n15 = gate_or(n14, n13);
  y[3] = gate_xor(n16, n15);
  auto n4 = gate_nand(n16, n15);
  auto n19 = gate_and(n4, n3);
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
