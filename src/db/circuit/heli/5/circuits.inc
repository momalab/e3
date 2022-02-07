// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
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
  auto n13 = gate_and(b[3], a[3]);
  auto n12 = gate_and(n11, n10);
  auto n14 = gate_or(n13, n12);
  auto n15 = gate_xor(b[4], n14);
  y[4] = gate_xor(a[4], n15);
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
  auto n59 = gate_not(b[1]);
  auto n45 = gate_not(b[4]);
  auto n51 = gate_not(b[3]);
  auto n23 = gate_and(n45, n51);
  auto n57 = gate_not(b[2]);
  auto n7 = gate_and(n23, n57);
  auto n6 = gate_and(n59, n7);
  auto n15 = gate_not(a[4]);
  auto n1 = gate_nand(b[2], n15);
  auto n2 = gate_nand(b[1], n15);
  auto n3 = gate_nand(b[0], n15);
  y[4] = gate_and(n6, n3);
  auto n9 = gate_and(n7, n2);
  auto n4 = gate_nand(n9, b[0]);
  auto n58 = gate_not(b[0]);
  auto n8 = gate_or(a[3], n58);
  y[3] = gate_and(n9, n8);
  auto n24 = gate_and(a[3], n4);
  auto n14 = gate_and(n24, n59);
  auto n12 = gate_xor(n24, n59);
  auto n10 = gate_not(a[2]);
  auto n26 = gate_and(n10, b[0]);
  auto n11 = gate_not(n26);
  auto n13 = gate_and(n12, n11);
  auto n16 = gate_or(n14, n13);
  auto n21 = gate_and(n16, n1);
  auto n18 = gate_not(y[3]);
  auto n17 = gate_not(y[4]);
  auto n19 = gate_and(n18, n17);
  auto n38 = gate_and(a[4], n19);
  auto n20 = gate_and(n38, n57);
  auto n22 = gate_or(n21, n20);
  y[2] = gate_and(n23, n22);
  auto n5 = gate_nand(y[2], n26);
  auto n25 = gate_and(y[2], b[1]);
  auto n27 = gate_xor(n25, n24);
  auto n49 = gate_and(n27, n5);
  auto n34 = gate_and(n57, n49);
  auto n32 = gate_xor(n57, n49);
  auto n28 = gate_and(y[2], b[0]);
  auto n55 = gate_xor(n28, a[2]);
  auto n31 = gate_and(n59, n55);
  auto n29 = gate_xor(n59, n55);
  auto n52 = gate_or(a[1], n58);
  auto n30 = gate_and(n29, n52);
  auto n46 = gate_or(n31, n30);
  auto n33 = gate_and(n32, n46);
  auto n36 = gate_or(n34, n33);
  auto n35 = gate_or(n51, n38);
  auto n40 = gate_and(n36, n35);
  auto n37 = gate_not(y[2]);
  auto n43 = gate_and(n38, n37);
  auto n39 = gate_and(n43, n51);
  auto n41 = gate_or(n40, n39);
  y[1] = gate_and(n45, n41);
  auto n42 = gate_not(y[1]);
  auto n44 = gate_and(n43, n42);
  auto n77 = gate_and(n45, n44);
  auto n75 = gate_xor(n45, n44);
  auto n47 = gate_xor(n46, n57);
  auto n48 = gate_and(n47, y[1]);
  auto n50 = gate_xor(n49, n48);
  auto n73 = gate_and(n51, n50);
  auto n71 = gate_xor(n51, n50);
  auto n53 = gate_xor(n52, n59);
  auto n54 = gate_and(n53, y[1]);
  auto n56 = gate_xor(n55, n54);
  auto n69 = gate_and(n57, n56);
  auto n67 = gate_xor(n57, n56);
  auto n60 = gate_or(a[0], n58);
  auto n65 = gate_and(n60, n59);
  auto n63 = gate_xor(n60, n59);
  auto n61 = gate_and(y[1], b[0]);
  auto n62 = gate_xor(n61, a[1]);
  auto n64 = gate_and(n63, n62);
  auto n66 = gate_or(n65, n64);
  auto n68 = gate_and(n67, n66);
  auto n70 = gate_or(n69, n68);
  auto n72 = gate_and(n71, n70);
  auto n74 = gate_or(n73, n72);
  auto n76 = gate_and(n75, n74);
  y[0] = gate_or(n77, n76);
}
template<> void $NameUint<5>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(b[0], a[0]);
  auto n102 = gate_xor(a[4], b[4]);
  auto n45 = gate_or(b[4], b[0]);
  auto n12 = gate_and(n45, n1);
  auto n69 = gate_xor(b[1], b[4]);
  auto n65 = gate_and(n12, n69);
  auto n63 = gate_xor(n12, n69);
  auto n78 = gate_xor(b[3], b[4]);
  auto n43 = gate_not(n69);
  auto n26 = gate_or(a[0], a[1]);
  auto n14 = gate_or(n26, a[2]);
  auto n13 = gate_and(n14, a[4]);
  auto n25 = gate_xor(n13, a[3]);
  auto n40 = gate_not(n78);
  auto n66 = gate_xor(b[2], b[4]);
  auto n38 = gate_not(n66);
  auto n24 = gate_and(n40, n38);
  auto n16 = gate_not(n14);
  auto n15 = gate_not(a[3]);
  auto n17 = gate_and(n16, n15);
  auto n90 = gate_and(a[4], n17);
  auto n104 = gate_and(n24, n43);
  auto n3 = gate_nand(n104, b[0]);
  auto n37 = gate_and(n90, n3);
  auto n101 = gate_not(n45);
  auto n18 = gate_and(b[0], n25);
  auto n20 = gate_or(n101, n18);
  auto n19 = gate_or(n37, n20);
  auto n22 = gate_and(n19, n43);
  auto n21 = gate_and(n20, n90);
  auto n23 = gate_or(n22, n21);
  auto n89 = gate_and(n24, n23);
  auto n36 = gate_not(n89);
  auto n49 = gate_and(n25, n36);
  auto n29 = gate_xor(n43, n49);
  auto n27 = gate_and(n26, a[4]);
  auto n41 = gate_xor(n27, a[2]);
  auto n7 = gate_nand(n41, b[0]);
  auto n28 = gate_and(n45, n7);
  auto n35 = gate_and(n29, n28);
  auto n30 = gate_not(n49);
  auto n33 = gate_and(n69, n30);
  auto n31 = gate_not(n90);
  auto n32 = gate_and(n66, n31);
  auto n34 = gate_or(n33, n32);
  auto n39 = gate_or(n35, n34);
  auto n56 = gate_and(n37, n36);
  auto n2 = gate_nand(n56, n38);
  auto n11 = gate_nand(n39, n2);
  auto n88 = gate_and(n11, n40);
  auto n42 = gate_and(n88, b[0]);
  auto n68 = gate_xor(n42, n41);
  auto n6 = gate_nand(n43, n68);
  auto n44 = gate_and(a[0], a[4]);
  auto n61 = gate_xor(n44, a[1]);
  auto n5 = gate_nand(n61, b[0]);
  auto n70 = gate_and(n45, n5);
  auto n46 = gate_xor(n69, n68);
  auto n47 = gate_or(n70, n46);
  auto n48 = gate_and(n6, n47);
  auto n53 = gate_and(n48, n66);
  auto n51 = gate_xor(n48, n66);
  auto n55 = gate_not(n88);
  auto n80 = gate_and(n49, n55);
  auto n50 = gate_not(n80);
  auto n52 = gate_and(n51, n50);
  auto n54 = gate_or(n53, n52);
  auto n60 = gate_and(n78, n54);
  auto n58 = gate_xor(n78, n54);
  auto n84 = gate_and(n56, n55);
  auto n57 = gate_not(n84);
  auto n59 = gate_and(n58, n57);
  auto n85 = gate_or(n60, n59);
  auto n9 = gate_nand(n85, n84);
  auto n10 = gate_nand(n80, n85);
  auto n87 = gate_not(n85);
  auto n62 = gate_and(n87, b[0]);
  auto n4 = gate_xnor(n62, n61);
  auto n64 = gate_and(n63, n4);
  auto n67 = gate_or(n65, n64);
  auto n77 = gate_and(n67, n66);
  auto n75 = gate_xor(n67, n66);
  auto n73 = gate_not(n68);
  auto n71 = gate_xor(n70, n69);
  auto n72 = gate_and(n87, n71);
  auto n74 = gate_xor(n73, n72);
  auto n76 = gate_and(n75, n74);
  auto n79 = gate_or(n77, n76);
  auto n83 = gate_and(n79, n78);
  auto n81 = gate_xor(n79, n78);
  auto n82 = gate_and(n81, n10);
  auto n86 = gate_or(n83, n82);
  auto n105 = gate_and(n86, n9);
  auto n100 = gate_and(n102, n105);
  auto n99 = gate_xor(n102, n87);
  auto n98 = gate_and(n100, n99);
  auto n97 = gate_xor(n102, n88);
  auto n96 = gate_and(n98, n97);
  auto n95 = gate_xor(n102, n89);
  auto n94 = gate_and(n96, n95);
  auto n91 = gate_and(n90, n104);
  auto n92 = gate_and(b[0], n91);
  auto n93 = gate_xor(n102, n92);
  y[4] = gate_xor(n94, n93);
  y[3] = gate_xor(n96, n95);
  y[2] = gate_xor(n98, n97);
  y[1] = gate_xor(n100, n99);
  auto n103 = gate_and(n102, n101);
  auto n106 = gate_and(n104, n103);
  y[0] = gate_xnor(n106, n105);
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
  auto n25 = gate_not(b[4]);
  auto n43 = gate_and(n25, a[4]);
  auto n41 = gate_xor(n25, a[4]);
  auto n26 = gate_not(b[3]);
  auto n39 = gate_and(n26, a[3]);
  auto n37 = gate_xor(n26, a[3]);
  auto n27 = gate_not(a[0]);
  auto n28 = gate_and(b[0], n27);
  auto n32 = gate_and(n28, b[1]);
  auto n30 = gate_xor(n28, b[1]);
  auto n29 = gate_not(a[1]);
  auto n31 = gate_and(n30, n29);
  auto n35 = gate_or(n32, n31);
  auto n24 = gate_nand(b[2], n35);
  auto n34 = gate_xor(b[2], n35);
  auto n33 = gate_not(a[2]);
  auto n23 = gate_nand(n34, n33);
  auto n36 = gate_and(n23, n24);
  auto n38 = gate_and(n37, n36);
  auto n40 = gate_or(n39, n38);
  auto n42 = gate_and(n41, n40);
  y[0] = gate_or(n43, n42);
}
template<> void $NameUint<5>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(a[4]);
  auto n43 = gate_and(n25, b[4]);
  auto n41 = gate_xor(n25, b[4]);
  auto n26 = gate_not(b[3]);
  auto n39 = gate_and(n26, a[3]);
  auto n37 = gate_xor(n26, a[3]);
  auto n27 = gate_not(a[0]);
  auto n28 = gate_and(b[0], n27);
  auto n32 = gate_and(n28, b[1]);
  auto n30 = gate_xor(n28, b[1]);
  auto n29 = gate_not(a[1]);
  auto n31 = gate_and(n30, n29);
  auto n35 = gate_or(n32, n31);
  auto n24 = gate_nand(b[2], n35);
  auto n34 = gate_xor(b[2], n35);
  auto n33 = gate_not(a[2]);
  auto n23 = gate_nand(n34, n33);
  auto n36 = gate_and(n23, n24);
  auto n38 = gate_and(n37, n36);
  auto n40 = gate_or(n39, n38);
  auto n42 = gate_and(n41, n40);
  y[0] = gate_or(n43, n42);
}
template<> void $NameUint<5>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[4]);
  auto n42 = gate_and(n22, a[4]);
  auto n40 = gate_xor(n22, a[4]);
  auto n23 = gate_not(b[3]);
  auto n38 = gate_and(n23, a[3]);
  auto n36 = gate_xor(n23, a[3]);
  auto n24 = gate_not(b[2]);
  auto n34 = gate_and(n24, a[2]);
  auto n32 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[0]);
  auto n26 = gate_and(a[0], n25);
  auto n30 = gate_and(n26, a[1]);
  auto n28 = gate_xor(n26, a[1]);
  auto n27 = gate_not(b[1]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto n35 = gate_or(n34, n33);
  auto n37 = gate_and(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n41 = gate_and(n40, n39);
  y[0] = gate_or(n42, n41);
}
template<> void $NameUint<5>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[4]);
  auto n42 = gate_and(n22, b[4]);
  auto n40 = gate_xor(n22, b[4]);
  auto n23 = gate_not(b[3]);
  auto n38 = gate_and(n23, a[3]);
  auto n36 = gate_xor(n23, a[3]);
  auto n24 = gate_not(b[2]);
  auto n34 = gate_and(n24, a[2]);
  auto n32 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[0]);
  auto n26 = gate_and(a[0], n25);
  auto n30 = gate_and(n26, a[1]);
  auto n28 = gate_xor(n26, a[1]);
  auto n27 = gate_not(b[1]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto n35 = gate_or(n34, n33);
  auto n37 = gate_and(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n41 = gate_and(n40, n39);
  y[0] = gate_or(n42, n41);
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
  auto n16 = gate_xor(a[3], b[3]);
  auto n10 = gate_xor(b[4], a[4]);
  auto n9 = gate_xor(b[1], a[1]);
  auto n14 = gate_or(n10, n9);
  auto n12 = gate_xor(a[2], b[2]);
  auto n11 = gate_xor(a[0], b[0]);
  auto n13 = gate_or(n12, n11);
  auto n15 = gate_or(n14, n13);
  y[0] = gate_or(n16, n15);
}
template<> void $NameUint<5>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n22 = gate_or(a[0], a[2]);
  auto n21 = gate_or(a[1], a[4]);
  auto n23 = gate_or(n22, n21);
  auto n32 = gate_or(a[3], n23);
  auto n25 = gate_and(b[0], n32);
  auto n33 = gate_not(n32);
  auto n24 = gate_and(n33, c[0]);
  y[0] = gate_or(n25, n24);
  auto n27 = gate_and(b[1], n32);
  auto n26 = gate_and(n33, c[1]);
  y[1] = gate_or(n27, n26);
  auto n29 = gate_and(b[2], n32);
  auto n28 = gate_and(n33, c[2]);
  y[2] = gate_or(n29, n28);
  auto n31 = gate_and(b[3], n32);
  auto n30 = gate_and(n33, c[3]);
  y[3] = gate_or(n31, n30);
  auto n35 = gate_and(b[4], n32);
  auto n34 = gate_and(n33, c[4]);
  y[4] = gate_or(n35, n34);
}
template<> void $NameUint<5>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(a[4]);
  auto n43 = gate_and(n25, b[4]);
  auto n41 = gate_xor(n25, b[4]);
  auto n26 = gate_not(a[3]);
  auto n39 = gate_and(n26, b[3]);
  auto n37 = gate_xor(n26, b[3]);
  auto n27 = gate_not(b[0]);
  auto n28 = gate_and(a[0], n27);
  auto n32 = gate_and(n28, a[1]);
  auto n30 = gate_xor(n28, a[1]);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_and(n30, n29);
  auto n35 = gate_or(n32, n31);
  auto n23 = gate_nand(a[2], n35);
  auto n34 = gate_xor(a[2], n35);
  auto n33 = gate_not(b[2]);
  auto n24 = gate_nand(n34, n33);
  auto n36 = gate_and(n24, n23);
  auto n38 = gate_and(n37, n36);
  auto n40 = gate_or(n39, n38);
  auto n42 = gate_and(n41, n40);
  y[0] = gate_or(n43, n42);
}
template<> void $NameUint<5>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_not(b[4]);
  auto n43 = gate_and(n25, a[4]);
  auto n41 = gate_xor(n25, a[4]);
  auto n26 = gate_not(a[3]);
  auto n39 = gate_and(n26, b[3]);
  auto n37 = gate_xor(n26, b[3]);
  auto n27 = gate_not(b[0]);
  auto n28 = gate_and(a[0], n27);
  auto n32 = gate_and(n28, a[1]);
  auto n30 = gate_xor(n28, a[1]);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_and(n30, n29);
  auto n35 = gate_or(n32, n31);
  auto n23 = gate_nand(a[2], n35);
  auto n34 = gate_xor(a[2], n35);
  auto n33 = gate_not(b[2]);
  auto n24 = gate_nand(n34, n33);
  auto n36 = gate_and(n24, n23);
  auto n38 = gate_and(n37, n36);
  auto n40 = gate_or(n39, n38);
  auto n42 = gate_and(n41, n40);
  y[0] = gate_or(n43, n42);
}
template<> void $NameUint<5>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_or(a[3], a[4]);
  auto n9 = gate_or(a[1], a[2]);
  auto n11 = gate_or(n10, n9);
  auto n16 = gate_or(n11, a[0]);
  auto n13 = gate_or(b[3], b[4]);
  auto n12 = gate_or(b[1], b[2]);
  auto n14 = gate_or(n13, n12);
  auto n15 = gate_or(n14, b[0]);
  y[0] = gate_and(n16, n15);
}
template<> void $NameUint<5>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n11 = gate_not(a[1]);
  auto n10 = gate_not(a[2]);
  auto n13 = gate_and(n11, n10);
  auto n12 = gate_not(a[0]);
  auto n17 = gate_and(n13, n12);
  auto n15 = gate_not(a[3]);
  auto n14 = gate_not(a[4]);
  auto n16 = gate_and(n15, n14);
  y[0] = gate_and(n17, n16);
}
template<> void $NameUint<5>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_or(a[4], a[2]);
  auto n9 = gate_or(a[3], a[0]);
  auto n11 = gate_or(n10, n9);
  auto n16 = gate_or(a[1], n11);
  auto n13 = gate_or(b[1], b[3]);
  auto n12 = gate_or(b[0], b[4]);
  auto n14 = gate_or(n13, n12);
  auto n15 = gate_or(n14, b[2]);
  y[0] = gate_or(n16, n15);
}
template<> void $NameUint<5>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[4]);
  auto n42 = gate_and(n22, b[4]);
  auto n40 = gate_xor(n22, b[4]);
  auto n23 = gate_not(a[3]);
  auto n38 = gate_and(n23, b[3]);
  auto n36 = gate_xor(n23, b[3]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_and(n24, b[2]);
  auto n32 = gate_xor(n24, b[2]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_and(b[0], n25);
  auto n30 = gate_and(n26, b[1]);
  auto n28 = gate_xor(n26, b[1]);
  auto n27 = gate_not(a[1]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto n35 = gate_or(n34, n33);
  auto n37 = gate_and(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n41 = gate_and(n40, n39);
  y[0] = gate_or(n42, n41);
}
template<> void $NameUint<5>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[4]);
  auto n42 = gate_and(n22, a[4]);
  auto n40 = gate_xor(n22, a[4]);
  auto n23 = gate_not(a[3]);
  auto n38 = gate_and(n23, b[3]);
  auto n36 = gate_xor(n23, b[3]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_and(n24, b[2]);
  auto n32 = gate_xor(n24, b[2]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_and(b[0], n25);
  auto n30 = gate_and(n26, b[1]);
  auto n28 = gate_xor(n26, b[1]);
  auto n27 = gate_not(a[1]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n33 = gate_and(n32, n31);
  auto n35 = gate_or(n34, n33);
  auto n37 = gate_and(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n41 = gate_and(n40, n39);
  y[0] = gate_or(n42, n41);
}
template<> void $NameUint<5>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n62 = gate_not(b[1]);
  auto n78 = gate_not(b[4]);
  auto n81 = gate_not(b[3]);
  auto n49 = gate_and(n78, n81);
  auto n86 = gate_not(b[2]);
  auto n12 = gate_and(n49, n86);
  auto n9 = gate_and(b[0], n12);
  auto n13 = gate_and(n62, n9);
  auto n10 = gate_not(n13);
  auto n18 = gate_and(a[4], n10);
  auto n11 = gate_xor(n62, a[4]);
  auto n14 = gate_and(n12, n11);
  auto n16 = gate_or(n14, n13);
  auto n15 = gate_not(a[3]);
  auto n2 = gate_nand(n15, b[0]);
  auto n19 = gate_and(n16, n2);
  auto n3 = gate_nand(n19, b[0]);
  auto n17 = gate_not(n19);
  auto n30 = gate_and(n18, n17);
  auto n31 = gate_and(a[3], n3);
  auto n24 = gate_and(n31, n62);
  auto n22 = gate_xor(n31, n62);
  auto n20 = gate_not(a[2]);
  auto n33 = gate_and(n20, b[0]);
  auto n21 = gate_not(n33);
  auto n23 = gate_and(n22, n21);
  auto n29 = gate_or(n24, n23);
  auto n1 = gate_nand(n29, n86);
  auto n25 = gate_or(n86, a[4]);
  auto n27 = gate_and(n29, n25);
  auto n26 = gate_and(n30, n86);
  auto n28 = gate_or(n27, n26);
  auto n35 = gate_and(n49, n28);
  auto n5 = gate_nand(n35, n33);
  auto n8 = gate_nand(n35, n1);
  auto n74 = gate_and(n30, n8);
  auto n32 = gate_and(n35, b[1]);
  auto n34 = gate_xor(n32, n31);
  auto n54 = gate_and(n34, n5);
  auto n43 = gate_and(n86, n54);
  auto n41 = gate_xor(n86, n54);
  auto n36 = gate_and(n35, b[0]);
  auto n58 = gate_xor(n36, a[2]);
  auto n4 = gate_nand(n62, n58);
  auto n37 = gate_not(a[1]);
  auto n56 = gate_and(b[0], n37);
  auto n38 = gate_xor(b[1], n58);
  auto n39 = gate_or(n56, n38);
  auto n52 = gate_and(n4, n39);
  auto n40 = gate_not(n52);
  auto n42 = gate_and(n41, n40);
  auto n46 = gate_or(n43, n42);
  auto n44 = gate_xor(n46, b[3]);
  auto n45 = gate_or(b[4], n44);
  auto n80 = gate_and(n74, n45);
  auto n77 = gate_and(n80, n78);
  auto n47 = gate_xor(n81, n74);
  auto n48 = gate_and(n47, n46);
  auto n51 = gate_and(n48, n78);
  auto n50 = gate_and(n49, n74);
  auto n60 = gate_or(n51, n50);
  auto n53 = gate_xor(n52, b[2]);
  auto n55 = gate_and(n60, n53);
  auto n84 = gate_xor(n55, n54);
  auto n73 = gate_and(n84, n81);
  auto n71 = gate_xor(n81, n84);
  auto n57 = gate_xor(n56, b[1]);
  auto n59 = gate_and(n60, n57);
  auto n89 = gate_xor(n59, n58);
  auto n70 = gate_and(n89, n86);
  auto n68 = gate_xor(n86, n89);
  auto n61 = gate_and(n60, b[0]);
  auto n94 = gate_xor(n61, a[1]);
  auto n67 = gate_and(n62, n94);
  auto n65 = gate_xor(n62, n94);
  auto n63 = gate_not(a[0]);
  auto n91 = gate_and(n63, b[0]);
  auto n64 = gate_not(n91);
  auto n66 = gate_and(n65, n64);
  auto n87 = gate_or(n67, n66);
  auto n69 = gate_and(n68, n87);
  auto n82 = gate_or(n70, n69);
  auto n72 = gate_and(n71, n82);
  auto n79 = gate_or(n73, n72);
  auto n6 = gate_nand(n79, n78);
  auto n75 = gate_or(n78, n74);
  auto n76 = gate_and(n79, n75);
  auto n95 = gate_or(n77, n76);
  auto n7 = gate_nand(n95, n6);
  y[4] = gate_and(n80, n7);
  auto n83 = gate_xor(n82, n81);
  auto n85 = gate_and(n95, n83);
  y[3] = gate_xor(n85, n84);
  auto n88 = gate_xor(n87, n86);
  auto n90 = gate_and(n95, n88);
  y[2] = gate_xor(n90, n89);
  auto n92 = gate_xor(n91, b[1]);
  auto n93 = gate_and(n95, n92);
  y[1] = gate_xor(n94, n93);
  auto n96 = gate_and(n95, b[0]);
  y[0] = gate_xor(n96, a[0]);
}
template<> void $NameUint<5>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n61 = gate_xor(b[2], b[4]);
  auto n87 = gate_not(n61);
  auto n103 = gate_xor(b[3], b[4]);
  auto n65 = gate_not(n103);
  auto n34 = gate_and(n87, n65);
  auto n37 = gate_xor(b[1], b[4]);
  auto n94 = gate_not(n37);
  auto n9 = gate_not(a[3]);
  auto n24 = gate_or(a[1], a[0]);
  auto n13 = gate_or(n24, a[2]);
  auto n8 = gate_not(n13);
  auto n11 = gate_and(n9, n8);
  auto n10 = gate_and(n34, n94);
  auto n1 = gate_nand(b[0], n10);
  auto n12 = gate_and(n11, n1);
  auto n20 = gate_and(a[4], n12);
  auto n18 = gate_xor(n94, n20);
  auto n14 = gate_and(n13, a[4]);
  auto n23 = gate_xor(n14, a[3]);
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(b[4]);
  auto n74 = gate_and(n16, n15);
  auto n17 = gate_or(n23, n74);
  auto n19 = gate_and(n18, n17);
  auto n22 = gate_and(n34, n19);
  auto n7 = gate_nand(n22, b[0]);
  auto n21 = gate_not(n22);
  auto n33 = gate_and(n21, n20);
  auto n38 = gate_and(n23, n7);
  auto n29 = gate_and(n38, n94);
  auto n27 = gate_xor(n38, n94);
  auto n25 = gate_and(n24, a[4]);
  auto n44 = gate_xor(n25, a[2]);
  auto n26 = gate_and(b[0], n44);
  auto n40 = gate_or(n74, n26);
  auto n28 = gate_and(n27, n40);
  auto n31 = gate_or(n29, n28);
  auto n30 = gate_xor(n31, n87);
  auto n6 = gate_nand(n65, n30);
  auto n55 = gate_and(n33, n6);
  auto n32 = gate_and(n87, n31);
  auto n36 = gate_and(n65, n32);
  auto n35 = gate_and(n34, n33);
  auto n43 = gate_or(n36, n35);
  auto n39 = gate_and(n43, n37);
  auto n42 = gate_xor(n39, n38);
  auto n41 = gate_not(n40);
  auto n2 = gate_nand(n43, n41);
  auto n62 = gate_and(n42, n2);
  auto n53 = gate_and(n87, n62);
  auto n51 = gate_xor(n87, n62);
  auto n45 = gate_and(n43, b[0]);
  auto n68 = gate_xor(n45, n44);
  auto n50 = gate_and(n68, n94);
  auto n48 = gate_xor(n68, n94);
  auto n46 = gate_and(a[4], a[0]);
  auto n71 = gate_xor(a[1], n46);
  auto n47 = gate_and(b[0], n71);
  auto n66 = gate_or(n74, n47);
  auto n49 = gate_and(n48, n66);
  auto n59 = gate_or(n50, n49);
  auto n52 = gate_and(n51, n59);
  auto n56 = gate_or(n53, n52);
  auto n54 = gate_xor(n56, n103);
  auto n85 = gate_and(n55, n54);
  auto n58 = gate_and(n65, n55);
  auto n57 = gate_and(n56, n65);
  auto n70 = gate_or(n58, n57);
  auto n60 = gate_not(n59);
  auto n3 = gate_nand(n70, n60);
  auto n63 = gate_and(n70, n61);
  auto n64 = gate_xor(n63, n62);
  auto n105 = gate_and(n3, n64);
  auto n83 = gate_and(n105, n65);
  auto n81 = gate_xor(n65, n105);
  auto n67 = gate_xor(n94, n66);
  auto n69 = gate_and(n70, n67);
  auto n89 = gate_xor(n69, n68);
  auto n80 = gate_and(n89, n87);
  auto n78 = gate_xor(n87, n89);
  auto n72 = gate_and(n70, b[0]);
  auto n98 = gate_xor(n72, n71);
  auto n77 = gate_and(n98, n94);
  auto n75 = gate_xor(n98, n94);
  auto n73 = gate_and(a[0], b[0]);
  auto n95 = gate_or(n74, n73);
  auto n76 = gate_and(n75, n95);
  auto n86 = gate_or(n77, n76);
  auto n79 = gate_and(n78, n86);
  auto n101 = gate_or(n80, n79);
  auto n82 = gate_and(n81, n101);
  auto n84 = gate_or(n83, n82);
  auto n5 = gate_nand(n85, n84);
  auto n110 = gate_and(a[4], n5);
  auto n104 = gate_or(n85, n84);
  auto n88 = gate_xor(n87, n86);
  auto n90 = gate_and(n104, n88);
  auto n91 = gate_xor(n90, n89);
  auto n114 = gate_xor(a[4], n91);
  auto n93 = gate_and(b[0], n104);
  auto n92 = gate_xor(a[0], a[4]);
  auto n118 = gate_xor(n93, n92);
  y[0] = gate_xor(a[4], n118);
  auto n100 = gate_and(a[4], n118);
  auto n96 = gate_xor(n95, n94);
  auto n97 = gate_and(n104, n96);
  auto n116 = gate_xor(n98, n97);
  auto n99 = gate_not(n116);
  auto n113 = gate_and(n100, n99);
  auto n112 = gate_and(n114, n113);
  auto n102 = gate_not(n101);
  auto n4 = gate_nand(n104, n102);
  auto n106 = gate_and(n104, n103);
  auto n107 = gate_xor(n106, n105);
  auto n108 = gate_and(n4, n107);
  auto n111 = gate_xor(a[4], n108);
  auto n109 = gate_and(n112, n111);
  y[4] = gate_xor(n110, n109);
  y[3] = gate_xor(n112, n111);
  y[2] = gate_xor(n114, n113);
  auto n115 = gate_not(n118);
  auto n117 = gate_and(n115, a[4]);
  y[1] = gate_xor(n117, n116);
}
template<> void $NameUint<5>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n3 = gate_and(a[1], b[0]);
  auto n2 = gate_and(a[0], b[1]);
  y[1] = gate_xor(n3, n2);
  auto n15 = gate_and(a[0], b[2]);
  auto n4 = gate_and(a[1], b[1]);
  auto n1 = gate_nand(n15, n4);
  auto n10 = gate_xor(n15, n4);
  auto n9 = gate_and(a[2], b[0]);
  auto n12 = gate_xor(n10, n9);
  auto n11 = gate_and(n3, n2);
  y[2] = gate_xor(n12, n11);
  auto n5 = gate_and(a[1], n1);
  auto n7 = gate_and(n5, b[2]);
  auto n6 = gate_and(b[3], a[0]);
  auto n32 = gate_xor(n7, n6);
  auto n8 = gate_and(a[3], b[0]);
  auto n18 = gate_and(b[1], a[2]);
  auto n31 = gate_xor(n8, n18);
  auto n34 = gate_xor(n32, n31);
  auto n14 = gate_and(n10, n9);
  auto n13 = gate_and(n12, n11);
  auto n33 = gate_or(n14, n13);
  y[3] = gate_xor(n34, n33);
  auto n17 = gate_and(a[1], n15);
  auto n16 = gate_or(b[3], b[1]);
  auto n30 = gate_and(n17, n16);
  auto n19 = gate_and(n18, a[3]);
  auto n20 = gate_xor(a[4], n19);
  auto n28 = gate_and(b[0], n20);
  auto n26 = gate_and(b[4], a[0]);
  auto n24 = gate_and(b[3], a[1]);
  auto n22 = gate_and(a[3], b[1]);
  auto n21 = gate_and(a[2], b[2]);
  auto n23 = gate_xor(n22, n21);
  auto n25 = gate_xor(n24, n23);
  auto n27 = gate_xor(n26, n25);
  auto n29 = gate_xor(n28, n27);
  auto n38 = gate_xor(n30, n29);
  auto n36 = gate_and(n32, n31);
  auto n35 = gate_and(n34, n33);
  auto n37 = gate_or(n36, n35);
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
  auto n11 = gate_not(a[1]);
  auto n10 = gate_not(a[2]);
  auto n13 = gate_and(n11, n10);
  auto n12 = gate_not(a[0]);
  auto n17 = gate_and(n13, n12);
  auto n15 = gate_not(a[3]);
  auto n14 = gate_not(a[4]);
  auto n16 = gate_and(n15, n14);
  y[0] = gate_and(n17, n16);
}
template<> void $NameUint<5>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n5 = gate_or(a[3], a[4]);
  auto n4 = gate_or(a[1], a[2]);
  auto n6 = gate_or(n5, n4);
  y[0] = gate_or(a[0], n6);
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
  auto n36 = gate_not(b[4]);
  auto n35 = gate_not(b[3]);
  auto n53 = gate_and(n36, n35);
  auto n52 = gate_not(b[2]);
  auto n61 = gate_not(b[0]);
  auto n38 = gate_and(a[2], n61);
  auto n37 = gate_and(b[0], a[1]);
  auto n63 = gate_or(n38, n37);
  auto n39 = gate_and(b[1], n63);
  auto n48 = gate_and(n52, n39);
  auto n40 = gate_and(b[0], a[3]);
  auto n45 = gate_and(n52, n40);
  auto n42 = gate_and(a[4], n52);
  auto n41 = gate_and(b[2], a[0]);
  auto n43 = gate_or(n42, n41);
  auto n44 = gate_and(n43, n61);
  auto n46 = gate_or(n45, n44);
  auto n54 = gate_not(b[1]);
  auto n47 = gate_and(n46, n54);
  auto n49 = gate_or(n48, n47);
  y[4] = gate_and(n53, n49);
  auto n51 = gate_and(a[3], n61);
  auto n50 = gate_and(b[0], a[2]);
  auto n55 = gate_or(n51, n50);
  auto n56 = gate_and(n53, n52);
  auto n68 = gate_and(n56, n54);
  auto n60 = gate_and(n55, n68);
  auto n62 = gate_and(b[1], n56);
  auto n58 = gate_and(a[1], n61);
  auto n57 = gate_and(b[0], a[0]);
  auto n66 = gate_or(n58, n57);
  auto n59 = gate_and(n62, n66);
  y[3] = gate_or(n60, n59);
  auto n67 = gate_and(a[0], n61);
  auto n65 = gate_and(n67, n62);
  auto n64 = gate_and(n68, n63);
  y[2] = gate_or(n65, n64);
  y[1] = gate_and(n68, n66);
  y[0] = gate_and(n68, n67);
}
template<> void $NameUint<5>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[0]);
  auto n35 = gate_and(a[4], n58);
  auto n55 = gate_not(b[1]);
  auto n65 = gate_and(n35, n55);
  auto n37 = gate_not(b[4]);
  auto n36 = gate_not(b[3]);
  auto n69 = gate_and(n37, n36);
  auto n63 = gate_not(b[2]);
  auto n54 = gate_and(n69, n63);
  y[4] = gate_and(n65, n54);
  auto n39 = gate_and(a[3], n58);
  auto n38 = gate_and(b[0], a[4]);
  auto n40 = gate_or(n39, n38);
  auto n41 = gate_and(n54, n40);
  y[3] = gate_and(n41, n55);
  auto n42 = gate_and(b[0], a[3]);
  auto n46 = gate_and(n55, n42);
  auto n44 = gate_and(a[2], n55);
  auto n43 = gate_and(b[1], a[4]);
  auto n50 = gate_or(n44, n43);
  auto n45 = gate_and(n50, n58);
  auto n47 = gate_or(n46, n45);
  y[2] = gate_and(n54, n47);
  auto n49 = gate_and(a[1], n55);
  auto n48 = gate_and(b[1], a[3]);
  auto n60 = gate_or(n49, n48);
  auto n52 = gate_and(n60, n58);
  auto n51 = gate_and(b[0], n50);
  auto n53 = gate_or(n52, n51);
  y[1] = gate_and(n54, n53);
  auto n57 = gate_and(a[0], n55);
  auto n56 = gate_and(b[1], a[2]);
  auto n59 = gate_or(n57, n56);
  auto n62 = gate_and(n59, n58);
  auto n61 = gate_and(b[0], n60);
  auto n64 = gate_or(n62, n61);
  auto n67 = gate_and(n64, n63);
  auto n66 = gate_and(b[2], n65);
  auto n68 = gate_or(n67, n66);
  y[0] = gate_and(n69, n68);
}
template<> void $NameUint<5>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_buf(a[4]);
  auto n37 = gate_not(b[2]);
  auto n36 = gate_not(b[4]);
  auto n39 = gate_and(n37, n36);
  auto n38 = gate_not(b[3]);
  auto n56 = gate_and(n39, n38);
  auto n40 = gate_not(b[1]);
  auto n63 = gate_and(n56, n40);
  auto n67 = gate_not(b[0]);
  auto n45 = gate_and(n63, n67);
  auto n41 = gate_not(n45);
  auto n43 = gate_and(y[4], n41);
  auto n42 = gate_and(n45, a[3]);
  y[3] = gate_or(n43, n42);
  auto n44 = gate_and(a[3], n63);
  auto n50 = gate_and(b[0], n44);
  auto n48 = gate_and(a[2], n45);
  auto n46 = gate_not(n63);
  auto n47 = gate_and(y[4], n46);
  auto n49 = gate_or(n48, n47);
  y[2] = gate_or(n50, n49);
  auto n62 = gate_and(n56, b[1]);
  auto n52 = gate_and(n62, a[3]);
  auto n51 = gate_and(a[1], n63);
  auto n61 = gate_or(n52, n51);
  auto n60 = gate_and(n61, n67);
  auto n54 = gate_and(a[2], n63);
  auto n53 = gate_and(b[1], y[4]);
  auto n55 = gate_or(n54, n53);
  auto n58 = gate_and(b[0], n55);
  auto n57 = gate_not(n56);
  auto n69 = gate_and(y[4], n57);
  auto n59 = gate_or(n58, n69);
  y[1] = gate_or(n60, n59);
  auto n71 = gate_and(b[0], n61);
  auto n65 = gate_and(a[2], n62);
  auto n64 = gate_and(n63, a[0]);
  auto n66 = gate_or(n65, n64);
  auto n68 = gate_and(n67, n66);
  auto n70 = gate_or(n69, n68);
  y[0] = gate_or(n71, n70);
}
template<> void $NameUint<5>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n5 = gate_not(a[0]);
  auto n8 = gate_and(b[0], n5);
  auto n7 = gate_xor(a[1], b[1]);
  y[1] = gate_xor(n8, n7);
  auto n6 = gate_not(b[1]);
  auto n3 = gate_nand(a[1], n6);
  auto n9 = gate_or(n8, n7);
  auto n12 = gate_and(n3, n9);
  auto n11 = gate_xor(a[2], b[2]);
  y[2] = gate_xor(n12, n11);
  auto n10 = gate_not(b[2]);
  auto n4 = gate_nand(a[2], n10);
  auto n13 = gate_or(n12, n11);
  auto n15 = gate_and(n4, n13);
  auto n14 = gate_xor(a[3], b[3]);
  y[3] = gate_xor(n15, n14);
  auto n17 = gate_or(n15, n14);
  auto n16 = gate_not(b[3]);
  auto n2 = gate_nand(a[3], n16);
  auto n19 = gate_and(n17, n2);
  auto n18 = gate_xor(a[4], b[4]);
  y[4] = gate_xor(n19, n18);
}
template<> void $NameUint<5>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n6 = gate_or(a[1], y[0]);
  auto n5 = gate_or(a[2], n6);
  auto n4 = gate_or(a[3], n5);
  y[4] = gate_xor(a[4], n4);
  y[3] = gate_xor(a[3], n5);
  y[2] = gate_xor(a[2], n6);
  y[1] = gate_xor(a[1], y[0]);
}
