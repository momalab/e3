// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<6>::d_add
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
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_and(b[3], a[3]);
  auto n12 = gate_and(n11, n10);
  auto n14 = gate_or(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n17 = gate_and(b[4], a[4]);
  auto n16 = gate_and(n15, n14);
  auto n18 = gate_or(n17, n16);
  auto n19 = gate_xor(b[5], n18);
  y[5] = gate_xor(a[5], n19);
}
template<> void $NameUint<6>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_and(b[5], a[5]);
  y[4] = gate_and(b[4], a[4]);
  y[3] = gate_and(b[3], a[3]);
  y[2] = gate_and(b[2], a[2]);
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<6>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[5] = gate_not(a[5]);
  y[4] = gate_not(a[4]);
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<6>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_or(a[5], b[5]);
  y[4] = gate_or(a[4], b[4]);
  y[3] = gate_or(a[3], b[3]);
  y[2] = gate_or(a[2], b[2]);
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<6>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_xor(b[5], a[5]);
  y[4] = gate_xor(b[4], a[4]);
  y[3] = gate_xor(b[3], a[3]);
  y[2] = gate_xor(b[2], a[2]);
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<6>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  y[1] = gate_and(a[0], b[1]);
  y[2] = gate_and(a[0], b[2]);
  y[3] = gate_and(a[0], b[3]);
  y[4] = gate_and(a[0], b[4]);
  y[5] = gate_and(a[0], b[5]);
}
template<> void $NameUint<6>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n24 = gate_not(a[0]);
  auto n15 = gate_and(c[0], n24);
  auto n14 = gate_and(a[0], b[0]);
  y[0] = gate_or(n15, n14);
  auto n17 = gate_and(c[1], n24);
  auto n16 = gate_and(a[0], b[1]);
  y[1] = gate_or(n17, n16);
  auto n19 = gate_and(c[2], n24);
  auto n18 = gate_and(a[0], b[2]);
  y[2] = gate_or(n19, n18);
  auto n21 = gate_and(c[3], n24);
  auto n20 = gate_and(a[0], b[3]);
  y[3] = gate_or(n21, n20);
  auto n23 = gate_and(c[4], n24);
  auto n22 = gate_and(a[0], b[4]);
  y[4] = gate_or(n23, n22);
  auto n26 = gate_and(c[5], n24);
  auto n25 = gate_and(a[0], b[5]);
  y[5] = gate_or(n26, n25);
}
template<> void $NameUint<6>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
  auto n2 = gate_not(a[1]);
  auto n4 = gate_and(n2, y[0]);
  y[2] = gate_xor(a[2], n4);
  auto n3 = gate_not(a[2]);
  auto n6 = gate_and(n4, n3);
  y[3] = gate_xor(a[3], n6);
  auto n5 = gate_not(a[3]);
  auto n8 = gate_and(n6, n5);
  y[4] = gate_xor(a[4], n8);
  auto n7 = gate_not(a[4]);
  auto n9 = gate_and(n8, n7);
  y[5] = gate_xor(a[5], n9);
}
template<> void $NameUint<6>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n90 = gate_not(b[1]);
  auto n70 = gate_not(b[5]);
  auto n76 = gate_not(b[4]);
  auto n41 = gate_and(n70, n76);
  auto n82 = gate_not(b[3]);
  auto n22 = gate_and(n41, n82);
  auto n88 = gate_not(b[2]);
  auto n8 = gate_and(n22, n88);
  auto n4 = gate_and(n90, n8);
  auto n89 = gate_not(b[0]);
  auto n3 = gate_or(n89, a[5]);
  y[5] = gate_and(n4, n3);
  auto n6 = gate_or(n90, a[5]);
  auto n5 = gate_or(n89, a[4]);
  auto n7 = gate_and(n6, n5);
  y[4] = gate_and(n8, n7);
  auto n2 = gate_nand(y[4], b[0]);
  auto n23 = gate_and(a[4], n2);
  auto n13 = gate_and(n23, n90);
  auto n11 = gate_xor(n23, n90);
  auto n9 = gate_not(a[3]);
  auto n25 = gate_and(n9, b[0]);
  auto n10 = gate_not(n25);
  auto n12 = gate_and(n11, n10);
  auto n15 = gate_or(n13, n12);
  auto n14 = gate_or(n88, a[5]);
  auto n20 = gate_and(n15, n14);
  auto n17 = gate_not(y[4]);
  auto n16 = gate_not(y[5]);
  auto n18 = gate_and(n17, n16);
  auto n37 = gate_and(a[5], n18);
  auto n19 = gate_and(n37, n88);
  auto n21 = gate_or(n20, n19);
  y[3] = gate_and(n22, n21);
  auto n1 = gate_nand(y[3], n25);
  auto n24 = gate_and(y[3], b[1]);
  auto n26 = gate_xor(n24, n23);
  auto n44 = gate_and(n26, n1);
  auto n33 = gate_and(n88, n44);
  auto n31 = gate_xor(n88, n44);
  auto n27 = gate_and(y[3], b[0]);
  auto n48 = gate_xor(n27, a[3]);
  auto n30 = gate_and(n90, n48);
  auto n28 = gate_xor(n90, n48);
  auto n46 = gate_or(a[2], n89);
  auto n29 = gate_and(n28, n46);
  auto n42 = gate_or(n30, n29);
  auto n32 = gate_and(n31, n42);
  auto n35 = gate_or(n33, n32);
  auto n34 = gate_or(n82, n37);
  auto n39 = gate_and(n35, n34);
  auto n36 = gate_not(y[3]);
  auto n63 = gate_and(n37, n36);
  auto n38 = gate_and(n63, n82);
  auto n40 = gate_or(n39, n38);
  y[2] = gate_and(n41, n40);
  auto n43 = gate_xor(n42, n88);
  auto n45 = gate_and(y[2], n43);
  auto n74 = gate_xor(n45, n44);
  auto n59 = gate_and(n74, n82);
  auto n57 = gate_xor(n74, n82);
  auto n47 = gate_xor(n46, n90);
  auto n49 = gate_and(y[2], n47);
  auto n80 = gate_xor(n49, n48);
  auto n56 = gate_and(n80, n88);
  auto n54 = gate_xor(n80, n88);
  auto n50 = gate_and(y[2], b[0]);
  auto n86 = gate_xor(n50, a[2]);
  auto n53 = gate_and(n90, n86);
  auto n51 = gate_xor(n90, n86);
  auto n83 = gate_or(a[1], n89);
  auto n52 = gate_and(n51, n83);
  auto n77 = gate_or(n53, n52);
  auto n55 = gate_and(n54, n77);
  auto n71 = gate_or(n56, n55);
  auto n58 = gate_and(n57, n71);
  auto n61 = gate_or(n59, n58);
  auto n60 = gate_or(n63, n76);
  auto n65 = gate_and(n61, n60);
  auto n62 = gate_not(y[2]);
  auto n68 = gate_and(n63, n62);
  auto n64 = gate_and(n68, n76);
  auto n66 = gate_or(n65, n64);
  y[1] = gate_and(n70, n66);
  auto n67 = gate_not(y[1]);
  auto n69 = gate_and(n68, n67);
  auto n112 = gate_and(n70, n69);
  auto n110 = gate_xor(n70, n69);
  auto n72 = gate_xor(n71, n82);
  auto n73 = gate_and(n72, y[1]);
  auto n75 = gate_xor(n74, n73);
  auto n108 = gate_and(n76, n75);
  auto n106 = gate_xor(n76, n75);
  auto n78 = gate_xor(n77, n88);
  auto n79 = gate_and(n78, y[1]);
  auto n81 = gate_xor(n80, n79);
  auto n104 = gate_and(n82, n81);
  auto n102 = gate_xor(n82, n81);
  auto n84 = gate_xor(n83, n90);
  auto n85 = gate_and(n84, y[1]);
  auto n87 = gate_xor(n86, n85);
  auto n100 = gate_and(n88, n87);
  auto n98 = gate_xor(n88, n87);
  auto n91 = gate_or(a[0], n89);
  auto n96 = gate_and(n91, n90);
  auto n94 = gate_xor(n91, n90);
  auto n92 = gate_and(y[1], b[0]);
  auto n93 = gate_xor(n92, a[1]);
  auto n95 = gate_and(n94, n93);
  auto n97 = gate_or(n96, n95);
  auto n99 = gate_and(n98, n97);
  auto n101 = gate_or(n100, n99);
  auto n103 = gate_and(n102, n101);
  auto n105 = gate_or(n104, n103);
  auto n107 = gate_and(n106, n105);
  auto n109 = gate_or(n108, n107);
  auto n111 = gate_and(n110, n109);
  y[0] = gate_or(n112, n111);
}
template<> void $NameUint<6>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[0], b[0]);
  auto n51 = gate_or(a[0], a[1]);
  auto n33 = gate_or(n51, a[2]);
  auto n22 = gate_or(n33, a[3]);
  auto n14 = gate_not(n22);
  auto n13 = gate_not(a[4]);
  auto n15 = gate_and(n14, n13);
  auto n41 = gate_and(a[5], n15);
  auto n21 = gate_not(b[5]);
  auto n107 = gate_xor(b[1], n21);
  auto n79 = gate_xor(b[2], n21);
  auto n17 = gate_and(b[0], n79);
  auto n67 = gate_xor(b[4], n21);
  auto n64 = gate_xor(b[3], n21);
  auto n46 = gate_and(n67, n64);
  auto n16 = gate_and(n41, n46);
  auto n18 = gate_and(n17, n16);
  auto n140 = gate_and(n107, n18);
  auto n19 = gate_not(n140);
  auto n30 = gate_and(n41, n19);
  auto n132 = gate_and(n46, n79);
  auto n20 = gate_not(b[0]);
  auto n133 = gate_and(n21, n20);
  auto n23 = gate_and(n22, a[5]);
  auto n32 = gate_xor(n23, a[4]);
  auto n24 = gate_and(b[0], n32);
  auto n26 = gate_or(n133, n24);
  auto n25 = gate_or(n41, n107);
  auto n28 = gate_and(n26, n25);
  auto n27 = gate_and(n107, n30);
  auto n29 = gate_or(n28, n27);
  auto n139 = gate_and(n132, n29);
  auto n31 = gate_not(n139);
  auto n58 = gate_and(n30, n31);
  auto n48 = gate_and(n32, n31);
  auto n39 = gate_and(n48, n107);
  auto n37 = gate_xor(n48, n107);
  auto n34 = gate_and(n33, a[5]);
  auto n49 = gate_xor(n34, a[3]);
  auto n35 = gate_and(b[0], n49);
  auto n36 = gate_or(n133, n35);
  auto n38 = gate_and(n37, n36);
  auto n42 = gate_or(n39, n38);
  auto n40 = gate_or(n58, n42);
  auto n44 = gate_and(n40, n79);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_or(n44, n43);
  auto n138 = gate_and(n46, n45);
  auto n47 = gate_not(n138);
  auto n66 = gate_and(n58, n47);
  auto n7 = gate_nand(n66, n64);
  auto n118 = gate_not(n79);
  auto n84 = gate_and(n48, n47);
  auto n57 = gate_not(n84);
  auto n56 = gate_xor(n118, n57);
  auto n50 = gate_and(n138, b[0]);
  auto n71 = gate_xor(n50, n49);
  auto n12 = gate_nand(n107, n71);
  auto n97 = gate_not(n133);
  auto n52 = gate_and(n51, a[5]);
  auto n72 = gate_xor(n52, a[2]);
  auto n10 = gate_nand(n72, b[0]);
  auto n68 = gate_and(n97, n10);
  auto n99 = gate_not(n107);
  auto n53 = gate_xor(n71, n99);
  auto n54 = gate_or(n68, n53);
  auto n55 = gate_and(n12, n54);
  auto n63 = gate_and(n56, n55);
  auto n61 = gate_and(n118, n57);
  auto n116 = gate_not(n64);
  auto n59 = gate_not(n58);
  auto n60 = gate_and(n116, n59);
  auto n62 = gate_or(n61, n60);
  auto n65 = gate_or(n63, n62);
  auto n3 = gate_nand(n65, n7);
  auto n137 = gate_and(n3, n67);
  auto n83 = gate_not(n137);
  auto n94 = gate_and(n66, n83);
  auto n96 = gate_not(n67);
  auto n69 = gate_xor(n68, n99);
  auto n70 = gate_and(n137, n69);
  auto n78 = gate_xor(n71, n70);
  auto n11 = gate_nand(n79, n78);
  auto n73 = gate_and(n137, b[0]);
  auto n74 = gate_xor(n73, n72);
  auto n9 = gate_nand(n107, n74);
  auto n111 = gate_not(n74);
  auto n77 = gate_xor(n99, n111);
  auto n75 = gate_and(a[0], a[5]);
  auto n101 = gate_xor(n75, a[1]);
  auto n76 = gate_and(b[0], n101);
  auto n108 = gate_or(n133, n76);
  auto n8 = gate_nand(n77, n108);
  auto n119 = gate_and(n9, n8);
  auto n122 = gate_not(n78);
  auto n80 = gate_xor(n79, n122);
  auto n81 = gate_or(n119, n80);
  auto n82 = gate_and(n11, n81);
  auto n88 = gate_and(n82, n116);
  auto n86 = gate_xor(n82, n116);
  auto n95 = gate_and(n84, n83);
  auto n85 = gate_not(n95);
  auto n87 = gate_and(n86, n85);
  auto n89 = gate_or(n88, n87);
  auto n93 = gate_and(n96, n89);
  auto n91 = gate_xor(n96, n89);
  auto n90 = gate_not(n94);
  auto n92 = gate_and(n91, n90);
  auto n100 = gate_or(n93, n92);
  auto n5 = gate_nand(n95, n100);
  auto n6 = gate_nand(n94, n100);
  auto n130 = gate_and(n96, n5);
  auto n128 = gate_xor(n96, n5);
  auto n98 = gate_and(n97, n1);
  auto n105 = gate_and(n99, n98);
  auto n103 = gate_xor(n99, n98);
  auto n136 = gate_not(n100);
  auto n4 = gate_nand(n136, b[0]);
  auto n102 = gate_xor(n4, n101);
  auto n104 = gate_and(n103, n102);
  auto n106 = gate_or(n105, n104);
  auto n115 = gate_and(n106, n118);
  auto n113 = gate_xor(n106, n118);
  auto n109 = gate_xor(n108, n107);
  auto n110 = gate_and(n136, n109);
  auto n112 = gate_xor(n111, n110);
  auto n114 = gate_and(n113, n112);
  auto n117 = gate_or(n115, n114);
  auto n126 = gate_and(n117, n116);
  auto n124 = gate_xor(n117, n116);
  auto n120 = gate_xor(n119, n118);
  auto n121 = gate_and(n136, n120);
  auto n123 = gate_xor(n122, n121);
  auto n125 = gate_and(n124, n123);
  auto n127 = gate_or(n126, n125);
  auto n129 = gate_and(n128, n127);
  auto n131 = gate_or(n130, n129);
  auto n152 = gate_and(n6, n131);
  auto n151 = gate_xor(a[5], b[5]);
  auto n135 = gate_not(b[1]);
  auto n134 = gate_and(n133, n132);
  auto n2 = gate_nand(n135, n134);
  auto n155 = gate_and(n151, n2);
  auto n150 = gate_and(n152, n155);
  auto n149 = gate_xor(n151, n136);
  auto n148 = gate_and(n150, n149);
  auto n147 = gate_xor(n151, n137);
  auto n146 = gate_and(n148, n147);
  auto n145 = gate_xor(n151, n138);
  auto n144 = gate_and(n146, n145);
  auto n143 = gate_xor(n151, n139);
  auto n142 = gate_and(n144, n143);
  auto n141 = gate_xor(n151, n140);
  y[5] = gate_xor(n142, n141);
  y[4] = gate_xor(n144, n143);
  y[3] = gate_xor(n146, n145);
  y[2] = gate_xor(n148, n147);
  y[1] = gate_xor(n150, n149);
  auto n157 = gate_not(n150);
  auto n153 = gate_not(n151);
  auto n154 = gate_xor(n153, n152);
  auto n156 = gate_or(n155, n154);
  y[0] = gate_and(n157, n156);
}
template<> void $NameUint<6>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_xnor(b[5], a[5]);
  auto n18 = gate_xnor(b[1], a[1]);
  auto n19 = gate_xnor(a[2], b[2]);
  auto n20 = gate_xnor(b[3], a[3]);
  auto n21 = gate_xnor(b[4], a[4]);
  auto n23 = gate_and(n19, n18);
  auto n22 = gate_and(n17, n21);
  auto n24 = gate_and(n23, n22);
  auto n27 = gate_and(n20, n24);
  auto n25 = gate_not(b[0]);
  auto n26 = gate_xor(n25, a[0]);
  y[0] = gate_and(n27, n26);
}
template<> void $NameUint<6>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[5]);
  auto n53 = gate_and(n30, a[5]);
  auto n51 = gate_xor(n30, a[5]);
  auto n31 = gate_not(b[4]);
  auto n49 = gate_and(n31, a[4]);
  auto n47 = gate_xor(n31, a[4]);
  auto n32 = gate_not(b[3]);
  auto n45 = gate_and(n32, a[3]);
  auto n43 = gate_xor(n32, a[3]);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_and(b[0], n33);
  auto n38 = gate_and(n34, b[1]);
  auto n36 = gate_xor(n34, b[1]);
  auto n35 = gate_not(a[1]);
  auto n37 = gate_and(n36, n35);
  auto n41 = gate_or(n38, n37);
  auto n29 = gate_nand(b[2], n41);
  auto n40 = gate_xor(b[2], n41);
  auto n39 = gate_not(a[2]);
  auto n28 = gate_nand(n40, n39);
  auto n42 = gate_and(n28, n29);
  auto n44 = gate_and(n43, n42);
  auto n46 = gate_or(n45, n44);
  auto n48 = gate_and(n47, n46);
  auto n50 = gate_or(n49, n48);
  auto n52 = gate_and(n51, n50);
  y[0] = gate_or(n53, n52);
}
template<> void $NameUint<6>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(a[5]);
  auto n53 = gate_and(n30, b[5]);
  auto n51 = gate_xor(n30, b[5]);
  auto n31 = gate_not(b[4]);
  auto n49 = gate_and(n31, a[4]);
  auto n47 = gate_xor(n31, a[4]);
  auto n32 = gate_not(b[3]);
  auto n45 = gate_and(n32, a[3]);
  auto n43 = gate_xor(n32, a[3]);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_and(b[0], n33);
  auto n38 = gate_and(n34, b[1]);
  auto n36 = gate_xor(n34, b[1]);
  auto n35 = gate_not(a[1]);
  auto n37 = gate_and(n36, n35);
  auto n41 = gate_or(n38, n37);
  auto n29 = gate_nand(b[2], n41);
  auto n40 = gate_xor(b[2], n41);
  auto n39 = gate_not(a[2]);
  auto n28 = gate_nand(n40, n39);
  auto n42 = gate_and(n28, n29);
  auto n44 = gate_and(n43, n42);
  auto n46 = gate_or(n45, n44);
  auto n48 = gate_and(n47, n46);
  auto n50 = gate_or(n49, n48);
  auto n52 = gate_and(n51, n50);
  y[0] = gate_or(n53, n52);
}
template<> void $NameUint<6>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[5]);
  auto n52 = gate_and(n27, a[5]);
  auto n50 = gate_xor(n27, a[5]);
  auto n28 = gate_not(b[4]);
  auto n48 = gate_and(n28, a[4]);
  auto n46 = gate_xor(n28, a[4]);
  auto n29 = gate_not(b[3]);
  auto n44 = gate_and(n29, a[3]);
  auto n42 = gate_xor(n29, a[3]);
  auto n30 = gate_not(b[2]);
  auto n40 = gate_and(n30, a[2]);
  auto n38 = gate_xor(n30, a[2]);
  auto n31 = gate_not(b[0]);
  auto n32 = gate_and(a[0], n31);
  auto n36 = gate_and(n32, a[1]);
  auto n34 = gate_xor(n32, a[1]);
  auto n33 = gate_not(b[1]);
  auto n35 = gate_and(n34, n33);
  auto n37 = gate_or(n36, n35);
  auto n39 = gate_and(n38, n37);
  auto n41 = gate_or(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_or(n44, n43);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n51 = gate_and(n50, n49);
  y[0] = gate_or(n52, n51);
}
template<> void $NameUint<6>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[5]);
  auto n52 = gate_and(n27, b[5]);
  auto n50 = gate_xor(n27, b[5]);
  auto n28 = gate_not(b[4]);
  auto n48 = gate_and(n28, a[4]);
  auto n46 = gate_xor(n28, a[4]);
  auto n29 = gate_not(b[3]);
  auto n44 = gate_and(n29, a[3]);
  auto n42 = gate_xor(n29, a[3]);
  auto n30 = gate_not(b[2]);
  auto n40 = gate_and(n30, a[2]);
  auto n38 = gate_xor(n30, a[2]);
  auto n31 = gate_not(b[0]);
  auto n32 = gate_and(a[0], n31);
  auto n36 = gate_and(n32, a[1]);
  auto n34 = gate_xor(n32, a[1]);
  auto n33 = gate_not(b[1]);
  auto n35 = gate_and(n34, n33);
  auto n37 = gate_or(n36, n35);
  auto n39 = gate_and(n38, n37);
  auto n41 = gate_or(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_or(n44, n43);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n51 = gate_and(n50, n49);
  y[0] = gate_or(n52, n51);
}
template<> void $NameUint<6>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[0], a[1]);
  auto n2 = gate_and(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  auto n3 = gate_and(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  auto n4 = gate_and(n3, a[3]);
  y[4] = gate_xor(n4, a[4]);
  auto n5 = gate_and(n4, a[4]);
  y[5] = gate_xor(a[5], n5);
}
template<> void $NameUint<6>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_xor(b[3], a[3]);
  auto n12 = gate_xor(b[4], a[4]);
  auto n11 = gate_xor(b[5], a[5]);
  auto n16 = gate_or(n12, n11);
  auto n14 = gate_xor(a[0], b[0]);
  auto n13 = gate_xor(b[2], a[2]);
  auto n15 = gate_or(n14, n13);
  auto n17 = gate_or(n16, n15);
  auto n20 = gate_or(n18, n17);
  auto n19 = gate_xor(b[1], a[1]);
  y[0] = gate_or(n20, n19);
}
template<> void $NameUint<6>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n26 = gate_or(a[4], a[0]);
  auto n25 = gate_or(a[5], a[2]);
  auto n27 = gate_or(n26, n25);
  auto n28 = gate_or(a[3], n27);
  auto n39 = gate_or(a[1], n28);
  auto n30 = gate_and(b[0], n39);
  auto n40 = gate_not(n39);
  auto n29 = gate_and(n40, c[0]);
  y[0] = gate_or(n30, n29);
  auto n32 = gate_and(b[1], n39);
  auto n31 = gate_and(n40, c[1]);
  y[1] = gate_or(n32, n31);
  auto n34 = gate_and(b[2], n39);
  auto n33 = gate_and(n40, c[2]);
  y[2] = gate_or(n34, n33);
  auto n36 = gate_and(b[3], n39);
  auto n35 = gate_and(n40, c[3]);
  y[3] = gate_or(n36, n35);
  auto n38 = gate_and(b[4], n39);
  auto n37 = gate_and(n40, c[4]);
  y[4] = gate_or(n38, n37);
  auto n42 = gate_and(b[5], n39);
  auto n41 = gate_and(n40, c[5]);
  y[5] = gate_or(n42, n41);
}
template<> void $NameUint<6>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(a[5]);
  auto n53 = gate_and(n30, b[5]);
  auto n51 = gate_xor(n30, b[5]);
  auto n31 = gate_not(a[4]);
  auto n49 = gate_and(n31, b[4]);
  auto n47 = gate_xor(n31, b[4]);
  auto n32 = gate_not(a[3]);
  auto n45 = gate_and(n32, b[3]);
  auto n43 = gate_xor(n32, b[3]);
  auto n33 = gate_not(b[0]);
  auto n34 = gate_and(a[0], n33);
  auto n38 = gate_and(n34, a[1]);
  auto n36 = gate_xor(n34, a[1]);
  auto n35 = gate_not(b[1]);
  auto n37 = gate_and(n36, n35);
  auto n41 = gate_or(n38, n37);
  auto n28 = gate_nand(a[2], n41);
  auto n40 = gate_xor(a[2], n41);
  auto n39 = gate_not(b[2]);
  auto n29 = gate_nand(n40, n39);
  auto n42 = gate_and(n29, n28);
  auto n44 = gate_and(n43, n42);
  auto n46 = gate_or(n45, n44);
  auto n48 = gate_and(n47, n46);
  auto n50 = gate_or(n49, n48);
  auto n52 = gate_and(n51, n50);
  y[0] = gate_or(n53, n52);
}
template<> void $NameUint<6>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[5]);
  auto n53 = gate_and(n30, a[5]);
  auto n51 = gate_xor(n30, a[5]);
  auto n31 = gate_not(a[4]);
  auto n49 = gate_and(n31, b[4]);
  auto n47 = gate_xor(n31, b[4]);
  auto n32 = gate_not(a[3]);
  auto n45 = gate_and(n32, b[3]);
  auto n43 = gate_xor(n32, b[3]);
  auto n33 = gate_not(b[0]);
  auto n34 = gate_and(a[0], n33);
  auto n38 = gate_and(n34, a[1]);
  auto n36 = gate_xor(n34, a[1]);
  auto n35 = gate_not(b[1]);
  auto n37 = gate_and(n36, n35);
  auto n41 = gate_or(n38, n37);
  auto n28 = gate_nand(a[2], n41);
  auto n40 = gate_xor(a[2], n41);
  auto n39 = gate_not(b[2]);
  auto n29 = gate_nand(n40, n39);
  auto n42 = gate_and(n29, n28);
  auto n44 = gate_and(n43, n42);
  auto n46 = gate_or(n45, n44);
  auto n48 = gate_and(n47, n46);
  auto n50 = gate_or(n49, n48);
  auto n52 = gate_and(n51, n50);
  y[0] = gate_or(n53, n52);
}
template<> void $NameUint<6>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n12 = gate_or(a[3], a[1]);
  auto n11 = gate_or(a[2], a[5]);
  auto n13 = gate_or(n12, n11);
  auto n14 = gate_or(a[4], n13);
  auto n20 = gate_or(a[0], n14);
  auto n16 = gate_or(b[4], b[1]);
  auto n15 = gate_or(b[2], b[5]);
  auto n17 = gate_or(n16, n15);
  auto n18 = gate_or(n17, b[0]);
  auto n19 = gate_or(b[3], n18);
  y[0] = gate_and(n20, n19);
}
template<> void $NameUint<6>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n13 = gate_not(a[5]);
  auto n12 = gate_not(a[3]);
  auto n15 = gate_and(n13, n12);
  auto n14 = gate_not(a[2]);
  auto n19 = gate_and(n15, n14);
  auto n17 = gate_not(a[1]);
  auto n16 = gate_not(a[4]);
  auto n18 = gate_and(n17, n16);
  auto n21 = gate_and(n19, n18);
  auto n20 = gate_not(a[0]);
  y[0] = gate_and(n21, n20);
}
template<> void $NameUint<6>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_or(a[2], b[3]);
  auto n12 = gate_or(b[4], b[0]);
  auto n11 = gate_or(b[2], a[5]);
  auto n13 = gate_or(n12, n11);
  auto n18 = gate_or(a[0], n13);
  auto n15 = gate_or(a[4], a[3]);
  auto n14 = gate_or(b[5], b[1]);
  auto n16 = gate_or(n15, n14);
  auto n17 = gate_or(n16, a[1]);
  auto n19 = gate_or(n18, n17);
  y[0] = gate_or(n20, n19);
}
template<> void $NameUint<6>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[5]);
  auto n52 = gate_and(n27, b[5]);
  auto n50 = gate_xor(n27, b[5]);
  auto n28 = gate_not(a[4]);
  auto n48 = gate_and(n28, b[4]);
  auto n46 = gate_xor(n28, b[4]);
  auto n29 = gate_not(a[3]);
  auto n44 = gate_and(n29, b[3]);
  auto n42 = gate_xor(n29, b[3]);
  auto n30 = gate_not(a[2]);
  auto n40 = gate_and(n30, b[2]);
  auto n38 = gate_xor(n30, b[2]);
  auto n31 = gate_not(a[0]);
  auto n32 = gate_and(b[0], n31);
  auto n36 = gate_and(n32, b[1]);
  auto n34 = gate_xor(n32, b[1]);
  auto n33 = gate_not(a[1]);
  auto n35 = gate_and(n34, n33);
  auto n37 = gate_or(n36, n35);
  auto n39 = gate_and(n38, n37);
  auto n41 = gate_or(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_or(n44, n43);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n51 = gate_and(n50, n49);
  y[0] = gate_or(n52, n51);
}
template<> void $NameUint<6>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[5]);
  auto n52 = gate_and(n27, a[5]);
  auto n50 = gate_xor(n27, a[5]);
  auto n28 = gate_not(a[4]);
  auto n48 = gate_and(n28, b[4]);
  auto n46 = gate_xor(n28, b[4]);
  auto n29 = gate_not(a[3]);
  auto n44 = gate_and(n29, b[3]);
  auto n42 = gate_xor(n29, b[3]);
  auto n30 = gate_not(a[2]);
  auto n40 = gate_and(n30, b[2]);
  auto n38 = gate_xor(n30, b[2]);
  auto n31 = gate_not(a[0]);
  auto n32 = gate_and(b[0], n31);
  auto n36 = gate_and(n32, b[1]);
  auto n34 = gate_xor(n32, b[1]);
  auto n33 = gate_not(a[1]);
  auto n35 = gate_and(n34, n33);
  auto n37 = gate_or(n36, n35);
  auto n39 = gate_and(n38, n37);
  auto n41 = gate_or(n40, n39);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_or(n44, n43);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n51 = gate_and(n50, n49);
  y[0] = gate_or(n52, n51);
}
template<> void $NameUint<6>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n128 = gate_not(b[2]);
  auto n115 = gate_not(b[5]);
  auto n118 = gate_not(b[4]);
  auto n79 = gate_and(n115, n118);
  auto n123 = gate_not(b[3]);
  auto n34 = gate_and(n79, n123);
  auto n15 = gate_and(n34, n128);
  auto n96 = gate_not(b[1]);
  auto n14 = gate_xor(n96, a[5]);
  auto n17 = gate_and(n15, n14);
  auto n16 = gate_and(n15, n96);
  auto n26 = gate_and(n16, b[0]);
  auto n19 = gate_or(n17, n26);
  auto n18 = gate_not(a[4]);
  auto n1 = gate_nand(n18, b[0]);
  auto n28 = gate_and(n19, n1);
  auto n13 = gate_nand(b[0], n28);
  auto n35 = gate_and(a[4], n13);
  auto n24 = gate_and(n35, n96);
  auto n22 = gate_xor(n35, n96);
  auto n20 = gate_not(a[3]);
  auto n37 = gate_and(n20, b[0]);
  auto n21 = gate_not(n37);
  auto n23 = gate_and(n22, n21);
  auto n46 = gate_or(n24, n23);
  auto n2 = gate_nand(n46, n128);
  auto n25 = gate_or(n128, a[5]);
  auto n32 = gate_and(n46, n25);
  auto n27 = gate_not(n26);
  auto n30 = gate_and(a[5], n27);
  auto n29 = gate_not(n28);
  auto n48 = gate_and(n30, n29);
  auto n31 = gate_and(n48, n128);
  auto n33 = gate_or(n32, n31);
  auto n47 = gate_and(n34, n33);
  auto n5 = gate_nand(n47, n2);
  auto n8 = gate_nand(n47, n37);
  auto n36 = gate_and(n47, b[1]);
  auto n38 = gate_xor(n36, n35);
  auto n58 = gate_and(n38, n8);
  auto n12 = gate_nand(n128, n58);
  auto n39 = gate_and(n47, b[0]);
  auto n62 = gate_xor(n39, a[3]);
  auto n7 = gate_nand(n96, n62);
  auto n40 = gate_not(a[2]);
  auto n60 = gate_and(b[0], n40);
  auto n41 = gate_xor(b[1], n62);
  auto n42 = gate_or(n60, n41);
  auto n56 = gate_and(n7, n42);
  auto n43 = gate_xor(b[2], n58);
  auto n44 = gate_or(n56, n43);
  auto n50 = gate_and(n12, n44);
  auto n45 = gate_xor(n50, b[3]);
  auto n4 = gate_nand(n45, n79);
  auto n49 = gate_and(n5, n48);
  auto n111 = gate_and(n4, n49);
  auto n54 = gate_and(n123, n49);
  auto n52 = gate_xor(n123, n49);
  auto n51 = gate_not(n50);
  auto n53 = gate_and(n52, n51);
  auto n55 = gate_or(n54, n53);
  auto n64 = gate_and(n79, n55);
  auto n57 = gate_xor(n56, b[2]);
  auto n59 = gate_and(n64, n57);
  auto n84 = gate_xor(n59, n58);
  auto n74 = gate_and(n84, n123);
  auto n72 = gate_xor(n123, n84);
  auto n61 = gate_xor(n60, b[1]);
  auto n63 = gate_and(n64, n61);
  auto n88 = gate_xor(n63, n62);
  auto n6 = gate_nand(n128, n88);
  auto n65 = gate_and(n64, b[0]);
  auto n92 = gate_xor(n65, a[2]);
  auto n3 = gate_nand(n96, n92);
  auto n66 = gate_not(a[1]);
  auto n90 = gate_and(b[0], n66);
  auto n67 = gate_xor(b[1], n92);
  auto n68 = gate_or(n90, n67);
  auto n86 = gate_and(n3, n68);
  auto n69 = gate_xor(b[2], n88);
  auto n70 = gate_or(n86, n69);
  auto n82 = gate_and(n6, n70);
  auto n71 = gate_not(n82);
  auto n73 = gate_and(n72, n71);
  auto n77 = gate_or(n74, n73);
  auto n75 = gate_xor(n118, n77);
  auto n11 = gate_nand(n115, n75);
  auto n117 = gate_and(n111, n11);
  auto n76 = gate_xor(n118, n111);
  auto n78 = gate_and(n77, n76);
  auto n81 = gate_and(n78, n115);
  auto n80 = gate_and(n79, n111);
  auto n94 = gate_or(n81, n80);
  auto n83 = gate_xor(b[3], n82);
  auto n85 = gate_and(n94, n83);
  auto n121 = gate_xor(n85, n84);
  auto n110 = gate_and(n121, n118);
  auto n108 = gate_xor(n118, n121);
  auto n87 = gate_xor(b[2], n86);
  auto n89 = gate_and(n94, n87);
  auto n126 = gate_xor(n89, n88);
  auto n107 = gate_and(n126, n123);
  auto n105 = gate_xor(n123, n126);
  auto n91 = gate_xor(n90, b[1]);
  auto n93 = gate_and(n94, n91);
  auto n131 = gate_xor(n93, n92);
  auto n104 = gate_and(n131, n128);
  auto n102 = gate_xor(n128, n131);
  auto n95 = gate_and(n94, b[0]);
  auto n136 = gate_xor(n95, a[1]);
  auto n101 = gate_and(n96, n136);
  auto n99 = gate_xor(n96, n136);
  auto n97 = gate_not(a[0]);
  auto n133 = gate_and(n97, b[0]);
  auto n98 = gate_not(n133);
  auto n100 = gate_and(n99, n98);
  auto n129 = gate_or(n101, n100);
  auto n103 = gate_and(n102, n129);
  auto n124 = gate_or(n104, n103);
  auto n106 = gate_and(n105, n124);
  auto n119 = gate_or(n107, n106);
  auto n109 = gate_and(n108, n119);
  auto n116 = gate_or(n110, n109);
  auto n9 = gate_nand(n116, n115);
  auto n112 = gate_or(n115, n111);
  auto n114 = gate_and(n116, n112);
  auto n113 = gate_and(n117, n115);
  auto n137 = gate_or(n114, n113);
  auto n10 = gate_nand(n137, n9);
  y[5] = gate_and(n117, n10);
  auto n120 = gate_xor(n119, n118);
  auto n122 = gate_and(n137, n120);
  y[4] = gate_xor(n122, n121);
  auto n125 = gate_xor(n124, n123);
  auto n127 = gate_and(n137, n125);
  y[3] = gate_xor(n127, n126);
  auto n130 = gate_xor(n129, n128);
  auto n132 = gate_and(n137, n130);
  y[2] = gate_xor(n132, n131);
  auto n134 = gate_xor(n133, b[1]);
  auto n135 = gate_and(n137, n134);
  y[1] = gate_xor(n136, n135);
  auto n138 = gate_and(n137, b[0]);
  y[0] = gate_xor(n138, a[0]);
}
template<> void $NameUint<6>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n67 = gate_xor(b[2], b[5]);
  auto n129 = gate_not(n67);
  auto n13 = gate_not(b[5]);
  auto n136 = gate_xor(n13, b[1]);
  auto n49 = gate_or(a[1], a[0]);
  auto n25 = gate_or(n49, a[2]);
  auto n17 = gate_or(n25, a[3]);
  auto n11 = gate_and(n17, a[5]);
  auto n24 = gate_xor(n11, a[4]);
  auto n97 = gate_xor(b[3], b[5]);
  auto n144 = gate_not(n97);
  auto n151 = gate_xor(b[4], b[5]);
  auto n12 = gate_not(b[0]);
  auto n113 = gate_and(n13, n12);
  auto n14 = gate_or(n24, n113);
  auto n18 = gate_not(n17);
  auto n20 = gate_and(a[5], n18);
  auto n19 = gate_not(a[4]);
  auto n21 = gate_and(n20, n19);
  auto n26 = gate_and(n25, a[5]);
  auto n47 = gate_xor(n26, a[3]);
  auto n27 = gate_and(b[0], n47);
  auto n43 = gate_or(n113, n27);
  auto n40 = gate_not(n136);
  auto n2 = gate_not(n40);
  auto n44 = gate_not(n43);
  auto n50 = gate_and(n49, a[5]);
  auto n76 = gate_xor(n50, a[2]);
  auto n51 = gate_and(b[0], n76);
  auto n71 = gate_or(n113, n51);
  auto n72 = gate_xor(n136, n71);
  auto n78 = gate_and(a[5], a[0]);
  auto n110 = gate_xor(a[1], n78);
  auto n79 = gate_and(b[0], n110);
  auto n105 = gate_or(n113, n79);
  auto n91 = gate_not(n151);
  auto n62 = gate_and(n144, n91);
  auto n15 = gate_and(n62, n129);
  auto n23 = gate_and(n15, n14);
  auto n16 = gate_and(b[0], n15);
  auto n1 = gate_nand(n16, n2);
  auto n32 = gate_and(n1, n21);
  auto n22 = gate_xor(n136, n32);
  auto n31 = gate_and(n23, n22);
  auto n10 = gate_nand(n31, b[0]);
  auto n41 = gate_and(n24, n10);
  auto n30 = gate_and(n2, n41);
  auto n28 = gate_xor(n41, n136);
  auto n29 = gate_and(n28, n43);
  auto n34 = gate_or(n30, n29);
  auto n36 = gate_xor(n129, n34);
  auto n9 = gate_nand(n36, n62);
  auto n33 = gate_not(n31);
  auto n35 = gate_and(n33, n32);
  auto n61 = gate_and(n9, n35);
  auto n38 = gate_and(n129, n34);
  auto n37 = gate_and(n36, n35);
  auto n39 = gate_or(n38, n37);
  auto n46 = gate_and(n62, n39);
  auto n3 = gate_nand(n46, n44);
  auto n42 = gate_and(n46, n40);
  auto n45 = gate_xor(n42, n41);
  auto n68 = gate_and(n45, n3);
  auto n57 = gate_and(n129, n68);
  auto n55 = gate_xor(n129, n68);
  auto n48 = gate_and(n46, b[0]);
  auto n73 = gate_xor(n48, n47);
  auto n54 = gate_and(n2, n73);
  auto n52 = gate_xor(n73, n136);
  auto n53 = gate_and(n52, n71);
  auto n65 = gate_or(n54, n53);
  auto n56 = gate_and(n55, n65);
  auto n59 = gate_or(n57, n56);
  auto n58 = gate_xor(n59, n144);
  auto n8 = gate_nand(n91, n58);
  auto n90 = gate_and(n61, n8);
  auto n60 = gate_and(n144, n59);
  auto n64 = gate_and(n60, n91);
  auto n63 = gate_and(n62, n61);
  auto n75 = gate_or(n64, n63);
  auto n66 = gate_not(n65);
  auto n7 = gate_nand(n75, n66);
  auto n69 = gate_and(n75, n67);
  auto n70 = gate_xor(n69, n68);
  auto n98 = gate_and(n7, n70);
  auto n88 = gate_and(n98, n144);
  auto n86 = gate_xor(n144, n98);
  auto n74 = gate_and(n75, n72);
  auto n103 = gate_xor(n74, n73);
  auto n85 = gate_and(n103, n129);
  auto n83 = gate_xor(n103, n129);
  auto n77 = gate_and(n75, b[0]);
  auto n107 = gate_xor(n77, n76);
  auto n82 = gate_and(n107, n2);
  auto n80 = gate_xor(n107, n136);
  auto n81 = gate_and(n80, n105);
  auto n101 = gate_or(n82, n81);
  auto n84 = gate_and(n83, n101);
  auto n95 = gate_or(n85, n84);
  auto n87 = gate_and(n86, n95);
  auto n92 = gate_or(n88, n87);
  auto n89 = gate_xor(n92, n151);
  auto n127 = gate_and(n90, n89);
  auto n94 = gate_and(n90, n91);
  auto n93 = gate_and(n92, n91);
  auto n109 = gate_or(n94, n93);
  auto n96 = gate_not(n95);
  auto n4 = gate_nand(n109, n96);
  auto n99 = gate_and(n109, n97);
  auto n100 = gate_xor(n99, n98);
  auto n153 = gate_and(n4, n100);
  auto n125 = gate_and(n153, n91);
  auto n123 = gate_xor(n91, n153);
  auto n102 = gate_xor(n129, n101);
  auto n104 = gate_and(n109, n102);
  auto n146 = gate_xor(n104, n103);
  auto n122 = gate_and(n146, n144);
  auto n120 = gate_xor(n144, n146);
  auto n106 = gate_xor(n2, n105);
  auto n108 = gate_and(n109, n106);
  auto n131 = gate_xor(n108, n107);
  auto n119 = gate_and(n131, n129);
  auto n117 = gate_xor(n131, n129);
  auto n111 = gate_and(n109, b[0]);
  auto n140 = gate_xor(n111, n110);
  auto n116 = gate_and(n140, n2);
  auto n114 = gate_xor(n140, n136);
  auto n112 = gate_and(a[0], b[0]);
  auto n137 = gate_or(n113, n112);
  auto n115 = gate_and(n114, n137);
  auto n128 = gate_or(n116, n115);
  auto n118 = gate_and(n117, n128);
  auto n143 = gate_or(n119, n118);
  auto n121 = gate_and(n120, n143);
  auto n149 = gate_or(n122, n121);
  auto n124 = gate_and(n123, n149);
  auto n126 = gate_or(n125, n124);
  auto n6 = gate_nand(n127, n126);
  auto n158 = gate_and(a[5], n6);
  auto n152 = gate_or(n127, n126);
  auto n130 = gate_xor(n129, n128);
  auto n132 = gate_and(n152, n130);
  auto n133 = gate_xor(n132, n131);
  auto n164 = gate_xor(a[5], n133);
  auto n135 = gate_and(b[0], n152);
  auto n134 = gate_xor(a[5], a[0]);
  auto n168 = gate_xor(n135, n134);
  y[0] = gate_xor(a[5], n168);
  auto n142 = gate_and(a[5], n168);
  auto n138 = gate_xor(n137, n136);
  auto n139 = gate_and(n152, n138);
  auto n166 = gate_xor(n140, n139);
  auto n141 = gate_not(n166);
  auto n163 = gate_and(n142, n141);
  auto n162 = gate_and(n164, n163);
  auto n145 = gate_xor(n144, n143);
  auto n147 = gate_and(n152, n145);
  auto n148 = gate_xor(n147, n146);
  auto n161 = gate_xor(a[5], n148);
  auto n160 = gate_and(n162, n161);
  auto n150 = gate_not(n149);
  auto n5 = gate_nand(n152, n150);
  auto n154 = gate_and(n152, n151);
  auto n155 = gate_xor(n154, n153);
  auto n156 = gate_and(n5, n155);
  auto n159 = gate_xor(a[5], n156);
  auto n157 = gate_and(n160, n159);
  y[5] = gate_xor(n158, n157);
  y[4] = gate_xor(n160, n159);
  y[3] = gate_xor(n162, n161);
  y[2] = gate_xor(n164, n163);
  auto n165 = gate_not(n168);
  auto n167 = gate_and(n165, a[5]);
  y[1] = gate_xor(n167, n166);
}
template<> void $NameUint<6>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n3 = gate_and(a[1], b[0]);
  auto n2 = gate_and(a[0], b[1]);
  y[1] = gate_xor(n3, n2);
  auto n24 = gate_and(a[0], b[2]);
  auto n22 = gate_and(a[1], b[1]);
  auto n1 = gate_nand(n24, n22);
  auto n8 = gate_xor(n24, n22);
  auto n7 = gate_and(a[2], b[0]);
  auto n10 = gate_xor(n8, n7);
  auto n9 = gate_and(n3, n2);
  y[2] = gate_xor(n10, n9);
  auto n4 = gate_and(b[2], n1);
  auto n6 = gate_and(n4, a[1]);
  auto n5 = gate_and(b[3], a[0]);
  auto n15 = gate_xor(n6, n5);
  auto n21 = gate_and(b[0], a[3]);
  auto n20 = gate_and(a[2], b[1]);
  auto n14 = gate_xor(n21, n20);
  auto n17 = gate_xor(n15, n14);
  auto n12 = gate_and(n8, n7);
  auto n11 = gate_and(n10, n9);
  auto n16 = gate_or(n12, n11);
  y[3] = gate_xor(n17, n16);
  auto n25 = gate_and(b[2], a[2]);
  auto n28 = gate_and(b[4], a[0]);
  auto n26 = gate_and(a[1], b[3]);
  auto n13 = gate_xor(n28, n26);
  auto n56 = gate_xor(n25, n13);
  auto n19 = gate_and(n15, n14);
  auto n18 = gate_and(n17, n16);
  auto n55 = gate_or(n19, n18);
  auto n58 = gate_xor(n56, n55);
  auto n36 = gate_and(n21, n20);
  auto n38 = gate_and(b[1], a[3]);
  auto n37 = gate_and(b[0], a[4]);
  auto n35 = gate_xor(n38, n37);
  auto n40 = gate_xor(n36, n35);
  auto n23 = gate_or(n26, n22);
  auto n39 = gate_and(n24, n23);
  auto n57 = gate_xor(n40, n39);
  y[4] = gate_xor(n58, n57);
  auto n54 = gate_and(a[1], b[4]);
  auto n32 = gate_and(b[2], a[3]);
  auto n30 = gate_and(n26, n25);
  auto n27 = gate_or(n26, n25);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_or(n30, n29);
  auto n52 = gate_xor(n32, n31);
  auto n34 = gate_and(a[5], b[0]);
  auto n33 = gate_and(a[4], b[1]);
  auto n50 = gate_xor(n34, n33);
  auto n44 = gate_and(n36, n35);
  auto n42 = gate_and(n38, n37);
  auto n41 = gate_and(n40, n39);
  auto n43 = gate_xor(n42, n41);
  auto n48 = gate_or(n44, n43);
  auto n46 = gate_and(a[2], b[3]);
  auto n45 = gate_and(b[5], a[0]);
  auto n47 = gate_xor(n46, n45);
  auto n49 = gate_xor(n48, n47);
  auto n51 = gate_xor(n50, n49);
  auto n53 = gate_xor(n52, n51);
  auto n62 = gate_xor(n54, n53);
  auto n60 = gate_and(n56, n55);
  auto n59 = gate_and(n58, n57);
  auto n61 = gate_or(n60, n59);
  y[5] = gate_xor(n62, n61);
}
template<> void $NameUint<6>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_and(a[4], a[1]);
  auto n5 = gate_and(a[0], a[3]);
  auto n7 = gate_and(n6, n5);
  auto n8 = gate_and(a[2], n7);
  y[0] = gate_and(a[5], n8);
}
template<> void $NameUint<6>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_and(a[4], a[1]);
  auto n8 = gate_and(a[0], a[3]);
  auto n10 = gate_and(n9, n8);
  auto n11 = gate_and(a[2], n10);
  y[0] = gate_nand(a[5], n11);
}
template<> void $NameUint<6>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n13 = gate_not(a[5]);
  auto n12 = gate_not(a[3]);
  auto n15 = gate_and(n13, n12);
  auto n14 = gate_not(a[2]);
  auto n19 = gate_and(n15, n14);
  auto n17 = gate_not(a[1]);
  auto n16 = gate_not(a[4]);
  auto n18 = gate_and(n17, n16);
  auto n21 = gate_and(n19, n18);
  auto n20 = gate_not(a[0]);
  y[0] = gate_and(n21, n20);
}
template<> void $NameUint<6>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_or(a[3], a[1]);
  auto n5 = gate_or(a[2], a[5]);
  auto n7 = gate_or(n6, n5);
  auto n8 = gate_or(a[4], n7);
  y[0] = gate_or(a[0], n8);
}
template<> void $NameUint<6>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_xor(a[5], a[4]);
  auto n10 = gate_xor(a[3], a[2]);
  auto n8 = gate_xor(a[0], a[1]);
  auto n11 = gate_xor(n9, n8);
  y[0] = gate_xnor(n11, n10);
}
template<> void $NameUint<6>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_xor(a[3], a[4]);
  auto n5 = gate_xor(a[0], a[1]);
  auto n8 = gate_xor(n6, n5);
  auto n7 = gate_xor(a[2], a[5]);
  y[0] = gate_xor(n8, n7);
}
template<> void $NameUint<6>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n83 = gate_not(b[1]);
  auto n47 = gate_and(a[4], n83);
  auto n46 = gate_and(b[1], a[2]);
  auto n64 = gate_or(n47, n46);
  auto n53 = gate_and(b[0], n64);
  auto n84 = gate_not(b[0]);
  auto n49 = gate_and(b[1], a[3]);
  auto n48 = gate_and(a[5], n83);
  auto n50 = gate_or(n49, n48);
  auto n51 = gate_and(n84, n50);
  auto n52 = gate_or(b[2], n51);
  auto n58 = gate_or(n53, n52);
  auto n55 = gate_not(b[3]);
  auto n54 = gate_not(b[4]);
  auto n57 = gate_and(n55, n54);
  auto n56 = gate_not(b[5]);
  auto n75 = gate_and(n57, n56);
  auto n63 = gate_and(n58, n75);
  auto n60 = gate_and(b[0], a[0]);
  auto n59 = gate_and(a[1], n84);
  auto n61 = gate_or(n60, n59);
  auto n89 = gate_and(n83, n61);
  auto n74 = gate_not(b[2]);
  auto n62 = gate_or(n89, n74);
  y[5] = gate_and(n63, n62);
  auto n69 = gate_and(n64, n84);
  auto n66 = gate_and(a[3], n83);
  auto n65 = gate_and(b[1], a[1]);
  auto n76 = gate_or(n66, n65);
  auto n67 = gate_and(b[0], n76);
  auto n68 = gate_or(n67, b[2]);
  auto n70 = gate_or(n69, n68);
  auto n73 = gate_and(n70, n75);
  auto n71 = gate_and(n84, n83);
  auto n90 = gate_and(n71, a[0]);
  auto n72 = gate_or(n74, n90);
  y[4] = gate_and(n73, n72);
  auto n91 = gate_and(n75, n74);
  auto n80 = gate_and(n76, n84);
  auto n78 = gate_and(a[2], n83);
  auto n77 = gate_and(b[1], a[0]);
  auto n85 = gate_or(n78, n77);
  auto n79 = gate_and(b[0], n85);
  auto n81 = gate_or(n80, n79);
  y[3] = gate_and(n91, n81);
  auto n82 = gate_and(b[0], a[1]);
  auto n87 = gate_and(n83, n82);
  auto n86 = gate_and(n85, n84);
  auto n88 = gate_or(n87, n86);
  y[2] = gate_and(n91, n88);
  y[1] = gate_and(n91, n89);
  y[0] = gate_and(n91, n90);
}
template<> void $NameUint<6>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n47 = gate_not(b[3]);
  auto n46 = gate_not(b[4]);
  auto n49 = gate_and(n47, n46);
  auto n48 = gate_not(b[5]);
  auto n90 = gate_and(n49, n48);
  auto n84 = gate_not(b[2]);
  auto n55 = gate_and(n90, n84);
  auto n77 = gate_not(b[0]);
  auto n71 = gate_and(n55, n77);
  auto n68 = gate_not(b[1]);
  auto n50 = gate_and(a[5], n68);
  y[5] = gate_and(n71, n50);
  auto n78 = gate_and(n68, n77);
  auto n52 = gate_and(a[4], n78);
  auto n51 = gate_and(n50, b[0]);
  auto n86 = gate_or(n52, n51);
  y[4] = gate_and(n55, n86);
  auto n54 = gate_and(a[3], n68);
  auto n53 = gate_and(b[1], a[5]);
  auto n61 = gate_or(n54, n53);
  auto n58 = gate_and(n71, n61);
  auto n67 = gate_and(b[0], n55);
  auto n56 = gate_and(a[4], n67);
  auto n57 = gate_and(n56, n68);
  y[3] = gate_or(n58, n57);
  auto n60 = gate_and(a[2], n68);
  auto n59 = gate_and(b[1], a[4]);
  auto n66 = gate_or(n60, n59);
  auto n63 = gate_and(n71, n66);
  auto n62 = gate_and(n67, n61);
  y[2] = gate_or(n63, n62);
  auto n65 = gate_and(n78, b[2]);
  auto n64 = gate_and(a[5], n90);
  auto n75 = gate_and(n65, n64);
  auto n73 = gate_and(n67, n66);
  auto n70 = gate_and(a[1], n68);
  auto n69 = gate_and(b[1], a[3]);
  auto n79 = gate_or(n70, n69);
  auto n72 = gate_and(n71, n79);
  auto n74 = gate_or(n73, n72);
  y[1] = gate_or(n75, n74);
  auto n76 = gate_and(a[2], b[1]);
  auto n83 = gate_and(n77, n76);
  auto n81 = gate_and(a[0], n78);
  auto n80 = gate_and(b[0], n79);
  auto n82 = gate_or(n81, n80);
  auto n85 = gate_or(n83, n82);
  auto n88 = gate_and(n85, n84);
  auto n87 = gate_and(b[2], n86);
  auto n89 = gate_or(n88, n87);
  y[0] = gate_and(n90, n89);
}
template<> void $NameUint<6>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_buf(a[5]);
  auto n53 = gate_not(b[2]);
  auto n52 = gate_or(b[4], b[3]);
  auto n86 = gate_or(b[5], n52);
  auto n83 = gate_not(n86);
  auto n66 = gate_and(n53, n83);
  auto n54 = gate_not(n66);
  auto n82 = gate_and(y[5], n54);
  auto n60 = gate_not(b[1]);
  auto n89 = gate_not(b[0]);
  auto n56 = gate_and(n60, n89);
  auto n55 = gate_not(n56);
  auto n58 = gate_and(y[5], n55);
  auto n57 = gate_and(n56, a[4]);
  auto n85 = gate_or(n58, n57);
  auto n59 = gate_and(n66, n85);
  y[4] = gate_or(n82, n59);
  auto n93 = gate_and(n66, n60);
  auto n61 = gate_not(n93);
  auto n65 = gate_and(y[5], n61);
  auto n63 = gate_and(a[3], n89);
  auto n62 = gate_and(b[0], a[4]);
  auto n78 = gate_or(n63, n62);
  auto n64 = gate_and(n93, n78);
  y[3] = gate_or(n65, n64);
  auto n95 = gate_and(n66, b[1]);
  auto n68 = gate_and(a[4], n89);
  auto n67 = gate_and(b[0], y[5]);
  auto n69 = gate_or(n68, n67);
  auto n73 = gate_and(n95, n69);
  auto n71 = gate_and(a[2], n89);
  auto n70 = gate_and(b[0], a[3]);
  auto n94 = gate_or(n71, n70);
  auto n72 = gate_and(n93, n94);
  auto n74 = gate_or(n73, n72);
  y[2] = gate_or(n82, n74);
  auto n76 = gate_and(a[1], n89);
  auto n75 = gate_and(b[0], a[2]);
  auto n77 = gate_or(n76, n75);
  auto n80 = gate_and(n93, n77);
  auto n79 = gate_and(n95, n78);
  auto n81 = gate_or(n80, n79);
  y[1] = gate_or(n82, n81);
  auto n84 = gate_and(n83, b[2]);
  auto n88 = gate_and(n85, n84);
  auto n87 = gate_and(y[5], n86);
  auto n99 = gate_or(n88, n87);
  auto n91 = gate_and(a[0], n89);
  auto n90 = gate_and(b[0], a[1]);
  auto n92 = gate_or(n91, n90);
  auto n97 = gate_and(n93, n92);
  auto n96 = gate_and(n95, n94);
  auto n98 = gate_or(n97, n96);
  y[0] = gate_or(n99, n98);
}
template<> void $NameUint<6>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n6 = gate_not(a[0]);
  auto n9 = gate_and(b[0], n6);
  auto n8 = gate_xor(a[1], b[1]);
  y[1] = gate_xor(n9, n8);
  auto n7 = gate_not(b[1]);
  auto n3 = gate_nand(a[1], n7);
  auto n10 = gate_or(n9, n8);
  auto n13 = gate_and(n3, n10);
  auto n12 = gate_xor(a[2], b[2]);
  y[2] = gate_xor(n13, n12);
  auto n11 = gate_not(b[2]);
  auto n4 = gate_nand(a[2], n11);
  auto n14 = gate_or(n13, n12);
  auto n17 = gate_and(n4, n14);
  auto n16 = gate_xor(a[3], b[3]);
  y[3] = gate_xor(n17, n16);
  auto n15 = gate_not(b[3]);
  auto n5 = gate_nand(a[3], n15);
  auto n18 = gate_or(n17, n16);
  auto n20 = gate_and(n5, n18);
  auto n19 = gate_xor(b[4], a[4]);
  y[4] = gate_xor(n20, n19);
  auto n22 = gate_or(n20, n19);
  auto n21 = gate_not(b[4]);
  auto n2 = gate_nand(a[4], n21);
  auto n24 = gate_and(n22, n2);
  auto n23 = gate_xor(a[5], b[5]);
  y[5] = gate_xor(n24, n23);
}
template<> void $NameUint<6>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n8 = gate_or(a[1], y[0]);
  auto n7 = gate_or(a[2], n8);
  auto n6 = gate_or(a[3], n7);
  auto n5 = gate_or(a[4], n6);
  y[5] = gate_xor(a[5], n5);
  y[4] = gate_xor(a[4], n6);
  y[3] = gate_xor(a[3], n7);
  y[2] = gate_xor(a[2], n8);
  y[1] = gate_xor(a[1], y[0]);
}
