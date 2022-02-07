// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<6>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n17 = gate_nand(n15, n14);
  auto n16 = gate_nand(b[4], a[4]);
  auto n18 = gate_nand(n17, n16);
  auto n19 = gate_xor(b[5], n18);
  y[5] = gate_xor(a[5], n19);
}
template<> void $NameUint<6>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_and(b[5], a[5]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
  y[3] = gate_and(b[3], a[3]);
  y[4] = gate_and(b[4], a[4]);
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
  auto n14 = gate_not(b[5]);
  auto n13 = gate_not(a[5]);
  y[5] = gate_nand(n14, n13);
  auto n16 = gate_not(b[4]);
  auto n15 = gate_not(a[4]);
  y[4] = gate_nand(n16, n15);
  auto n18 = gate_not(b[3]);
  auto n17 = gate_not(a[3]);
  y[3] = gate_nand(n18, n17);
  auto n20 = gate_not(b[2]);
  auto n19 = gate_not(a[2]);
  y[2] = gate_nand(n20, n19);
  auto n22 = gate_not(b[1]);
  auto n21 = gate_not(a[1]);
  y[1] = gate_nand(n22, n21);
  auto n24 = gate_not(b[0]);
  auto n23 = gate_not(a[0]);
  y[0] = gate_nand(n24, n23);
}
template<> void $NameUint<6>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  y[4] = gate_buf(zero);
  y[5] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n6 = gate_xor(N0, a[4]);
  auto n2 = gate_xor(n6, a[2]);
  auto n3 = gate_xor(a[1], a[3]);
  auto n1 = gate_xor(n3, a[5]);
  y[0] = gate_xor(n2, n1);
  auto n9 = gate_nand(n2, n1);
  auto n4 = gate_nand(n3, a[5]);
  auto n5 = gate_nand(n9, n4);
  auto n10 = gate_nand(a[1], a[3]);
  auto n14 = gate_mux(n9, n5, n10);
  auto n8 = gate_nand(N0, a[4]);
  auto n7 = gate_nand(n6, a[2]);
  auto n13 = gate_nand(n8, n7);
  y[1] = gate_xor(n14, n13);
  auto n12 = gate_not(n9);
  auto n11 = gate_not(n10);
  auto n16 = gate_nand(n12, n11);
  auto n15 = gate_nand(n14, n13);
  y[2] = gate_nand(n16, n15);
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
  y[5] = gate_and(a[0], b[5]);
  y[4] = gate_and(a[0], b[4]);
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
}
template<> void $NameUint<6>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
  y[5] = gate_mux(c[5], b[5], a[0]);
}
template<> void $NameUint<6>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_and(a[0], b[0]);
  y[0] = gate_xor(a[0], b[0]);
  auto n3 = gate_xor(b[1], a[1]);
  y[1] = gate_xor(n3, n2);
  auto n7 = gate_xor(b[2], a[2]);
  auto n5 = gate_nand(b[1], a[1]);
  auto n4 = gate_nand(n3, n2);
  auto n6 = gate_nand(n5, n4);
  y[2] = gate_xor(n7, n6);
  auto n11 = gate_xor(b[3], a[3]);
  auto n9 = gate_nand(b[2], a[2]);
  auto n8 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  y[3] = gate_xor(n11, n10);
  auto n15 = gate_xor(b[4], a[4]);
  auto n13 = gate_nand(b[3], a[3]);
  auto n12 = gate_nand(n11, n10);
  auto n14 = gate_nand(n13, n12);
  y[4] = gate_xor(n15, n14);
  auto n17 = gate_nand(b[4], a[4]);
  auto n16 = gate_nand(n15, n14);
  y[5] = gate_nand(n17, n16);
}
template<> void $NameUint<6>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[1], y[0]);
  auto n5 = gate_not(a[1]);
  auto n2 = gate_and(n5, y[0]);
  y[2] = gate_xor(a[2], n2);
  auto n6 = gate_not(a[2]);
  auto n3 = gate_and(n2, n6);
  y[3] = gate_xor(a[3], n3);
  auto n7 = gate_not(a[3]);
  auto n4 = gate_and(n3, n7);
  y[4] = gate_xor(a[4], n4);
  auto n10 = gate_not(a[5]);
  auto n8 = gate_not(a[4]);
  auto n9 = gate_nand(n4, n8);
  y[5] = gate_xor(n10, n9);
}
template<> void $NameUint<6>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n78 = gate_not(b[1]);
  auto n68 = gate_not(b[5]);
  auto n106 = gate_not(b[4]);
  auto n5 = gate_and(n68, n106);
  auto n75 = gate_not(b[3]);
  auto n6 = gate_and(n5, n75);
  auto n91 = gate_not(b[2]);
  auto n2 = gate_and(n6, n91);
  auto n1 = gate_and(n78, n2);
  auto n13 = gate_not(a[5]);
  auto n9 = gate_nand(b[0], n13);
  auto n20 = gate_nand(n1, n9);
  auto n7 = gate_and(a[5], n20);
  y[5] = gate_not(n20);
  auto n10 = gate_nand(b[1], n13);
  auto n4 = gate_and(n2, n10);
  auto n11 = gate_not(a[4]);
  auto n12 = gate_nand(b[0], n11);
  auto n21 = gate_nand(n4, n12);
  y[4] = gate_not(n21);
  auto n19 = gate_nand(n13, b[2]);
  auto n14 = gate_nand(y[4], b[0]);
  auto n31 = gate_nand(a[4], n14);
  auto n15 = gate_not(n31);
  auto n17 = gate_nand(n15, n78);
  auto n27 = gate_xor(b[1], n31);
  auto n33 = gate_not(a[3]);
  auto n28 = gate_nand(b[0], n33);
  auto n16 = gate_nand(n27, n28);
  auto n18 = gate_nand(n17, n16);
  auto n23 = gate_nand(n19, n18);
  auto n39 = gate_nand(n7, n21);
  auto n26 = gate_not(n39);
  auto n22 = gate_nand(n91, n26);
  auto n24 = gate_nand(n23, n22);
  auto n25 = gate_nand(n6, n24);
  y[3] = gate_not(n25);
  auto n69 = gate_nand(n26, n25);
  auto n46 = gate_not(n69);
  auto n43 = gate_nand(n46, n75);
  auto n29 = gate_not(n27);
  auto n30 = gate_nand(n29, n28);
  auto n36 = gate_mux(n31, n30, y[3]);
  auto n48 = gate_xor(b[2], n36);
  auto n32 = gate_nand(y[3], b[0]);
  auto n54 = gate_xor(n33, n32);
  auto n35 = gate_nand(n78, n54);
  auto n52 = gate_xor(n78, n54);
  auto n56 = gate_not(a[2]);
  auto n51 = gate_nand(b[0], n56);
  auto n34 = gate_nand(n52, n51);
  auto n47 = gate_nand(n35, n34);
  auto n38 = gate_nand(n48, n47);
  auto n50 = gate_not(n36);
  auto n37 = gate_nand(n91, n50);
  auto n41 = gate_nand(n38, n37);
  auto n40 = gate_nand(b[3], n39);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n45 = gate_nand(n5, n44);
  auto n3 = gate_and(n46, n45);
  y[2] = gate_not(n45);
  auto n66 = gate_nand(n3, n106);
  auto n49 = gate_xor(n48, n47);
  auto n102 = gate_mux(n50, n49, y[2]);
  auto n99 = gate_xor(n75, n102);
  auto n53 = gate_xor(n52, n51);
  auto n72 = gate_mux(n54, n53, y[2]);
  auto n60 = gate_nand(n72, n91);
  auto n70 = gate_xor(n91, n72);
  auto n55 = gate_nand(y[2], b[0]);
  auto n88 = gate_xor(n56, n55);
  auto n58 = gate_nand(n78, n88);
  auto n86 = gate_xor(n78, n88);
  auto n77 = gate_not(a[1]);
  auto n85 = gate_nand(b[0], n77);
  auto n57 = gate_nand(n86, n85);
  auto n71 = gate_nand(n58, n57);
  auto n59 = gate_nand(n70, n71);
  auto n100 = gate_nand(n60, n59);
  auto n62 = gate_nand(n99, n100);
  auto n61 = gate_nand(n102, n75);
  auto n64 = gate_nand(n62, n61);
  auto n63 = gate_nand(b[4], n69);
  auto n65 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n101 = gate_nand(n68, n67);
  auto n8 = gate_and(n3, n101);
  y[1] = gate_not(n101);
  auto n113 = gate_nand(n8, n68);
  auto n111 = gate_nand(b[5], n69);
  auto n73 = gate_xor(n71, n70);
  auto n74 = gate_mux(n73, n72, n101);
  auto n98 = gate_nand(n75, n74);
  auto n96 = gate_xor(n75, n74);
  auto n76 = gate_nand(y[1], b[0]);
  auto n79 = gate_xor(n77, n76);
  auto n84 = gate_nand(n79, n78);
  auto n82 = gate_xor(n79, n78);
  auto n80 = gate_not(a[0]);
  auto n81 = gate_nand(b[0], n80);
  auto n83 = gate_nand(n82, n81);
  auto n90 = gate_nand(n84, n83);
  auto n87 = gate_xor(n86, n85);
  auto n89 = gate_mux(n88, n87, y[1]);
  auto n94 = gate_nand(n90, n89);
  auto n92 = gate_xor(n90, n89);
  auto n93 = gate_nand(n92, n91);
  auto n95 = gate_nand(n94, n93);
  auto n97 = gate_nand(n96, n95);
  auto n105 = gate_nand(n98, n97);
  auto n103 = gate_xor(n100, n99);
  auto n104 = gate_mux(n103, n102, n101);
  auto n109 = gate_nand(n105, n104);
  auto n107 = gate_xor(n105, n104);
  auto n108 = gate_nand(n107, n106);
  auto n110 = gate_nand(n109, n108);
  auto n112 = gate_nand(n111, n110);
  y[0] = gate_nand(n113, n112);
}
template<> void $NameUint<6>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n150 = gate_xor(a[5], b[5]);
  auto n77 = gate_not(a[1]);
  auto n100 = gate_not(a[0]);
  auto n51 = gate_nand(n77, n100);
  auto n20 = gate_not(n51);
  auto n19 = gate_not(a[2]);
  auto n35 = gate_nand(n20, n19);
  auto n22 = gate_not(n35);
  auto n21 = gate_not(a[3]);
  auto n25 = gate_nand(n22, n21);
  auto n23 = gate_not(n25);
  auto n27 = gate_not(a[4]);
  auto n6 = gate_and(n23, n27);
  auto n34 = gate_nand(a[5], n6);
  auto n24 = gate_not(n34);
  auto n10 = gate_and(n24, b[0]);
  auto n147 = gate_not(b[5]);
  auto n90 = gate_xor(b[4], n147);
  auto n67 = gate_xor(b[3], n147);
  auto n13 = gate_and(n90, n67);
  auto n94 = gate_xor(b[2], n147);
  auto n1 = gate_and(n13, n94);
  auto n112 = gate_xor(b[1], n147);
  auto n2 = gate_and(n112, n10);
  auto n138 = gate_nand(n1, n2);
  auto n9 = gate_and(n24, n138);
  auto n102 = gate_not(n112);
  auto n29 = gate_nand(n102, n34);
  auto n26 = gate_nand(a[5], n25);
  auto n33 = gate_xor(n27, n26);
  auto n28 = gate_mux(n147, n33, b[0]);
  auto n31 = gate_nand(n29, n28);
  auto n30 = gate_nand(n112, n9);
  auto n32 = gate_nand(n31, n30);
  auto n137 = gate_nand(n1, n32);
  auto n14 = gate_and(n33, n137);
  auto n47 = gate_nand(n9, n137);
  auto n125 = gate_not(n90);
  auto n89 = gate_nand(n47, n125);
  auto n109 = gate_not(n94);
  auto n43 = gate_nand(n34, n109);
  auto n41 = gate_nand(n14, n112);
  auto n39 = gate_xor(n14, n112);
  auto n36 = gate_nand(a[5], n35);
  auto n50 = gate_xor(a[3], n36);
  auto n37 = gate_mux(b[5], n50, b[0]);
  auto n38 = gate_not(n37);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n45 = gate_nand(n43, n42);
  auto n63 = gate_not(n47);
  auto n44 = gate_nand(n94, n63);
  auto n46 = gate_nand(n45, n44);
  auto n136 = gate_nand(n13, n46);
  auto n7 = gate_and(n14, n136);
  auto n8 = gate_and(n63, n136);
  auto n98 = gate_not(n67);
  auto n62 = gate_nand(n47, n98);
  auto n60 = gate_nand(n94, n7);
  auto n58 = gate_xor(n94, n7);
  auto n48 = gate_not(n136);
  auto n49 = gate_nand(n48, b[0]);
  auto n71 = gate_xor(n50, n49);
  auto n56 = gate_nand(n112, n71);
  auto n54 = gate_xor(n112, n71);
  auto n52 = gate_nand(a[5], n51);
  auto n75 = gate_xor(a[2], n52);
  auto n68 = gate_mux(b[5], n75, b[0]);
  auto n53 = gate_not(n68);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n59 = gate_nand(n58, n57);
  auto n61 = gate_nand(n60, n59);
  auto n65 = gate_nand(n62, n61);
  auto n64 = gate_nand(n67, n8);
  auto n66 = gate_nand(n65, n64);
  auto n135 = gate_nand(n90, n66);
  auto n15 = gate_and(n8, n135);
  auto n16 = gate_and(n7, n135);
  auto n87 = gate_nand(n67, n16);
  auto n85 = gate_xor(n67, n16);
  auto n73 = gate_not(n135);
  auto n69 = gate_xor(n102, n68);
  auto n70 = gate_nand(n73, n69);
  auto n72 = gate_xor(n71, n70);
  auto n97 = gate_not(n72);
  auto n83 = gate_nand(n97, n94);
  auto n81 = gate_xor(n109, n72);
  auto n74 = gate_nand(b[0], n73);
  auto n115 = gate_xor(n75, n74);
  auto n80 = gate_nand(n112, n115);
  auto n78 = gate_xor(n112, n115);
  auto n76 = gate_nand(a[0], a[5]);
  auto n104 = gate_xor(n77, n76);
  auto n111 = gate_mux(n147, n104, b[0]);
  auto n79 = gate_nand(n78, n111);
  auto n93 = gate_nand(n80, n79);
  auto n82 = gate_nand(n81, n93);
  auto n84 = gate_nand(n83, n82);
  auto n86 = gate_nand(n85, n84);
  auto n88 = gate_nand(n87, n86);
  auto n92 = gate_nand(n89, n88);
  auto n91 = gate_nand(n90, n15);
  auto n134 = gate_nand(n92, n91);
  auto n126 = gate_not(n134);
  auto n132 = gate_nand(n126, n15);
  auto n95 = gate_xor(n94, n93);
  auto n96 = gate_nand(n134, n95);
  auto n99 = gate_xor(n97, n96);
  auto n123 = gate_nand(n99, n98);
  auto n121 = gate_xor(n99, n98);
  auto n101 = gate_mux(b[5], n100, b[0]);
  auto n108 = gate_nand(n102, n101);
  auto n106 = gate_xor(n102, n101);
  auto n103 = gate_nand(b[0], n134);
  auto n105 = gate_xor(n104, n103);
  auto n107 = gate_nand(n106, n105);
  auto n110 = gate_nand(n108, n107);
  auto n119 = gate_nand(n110, n109);
  auto n117 = gate_xor(n110, n109);
  auto n113 = gate_xor(n112, n111);
  auto n114 = gate_nand(n134, n113);
  auto n116 = gate_xor(n115, n114);
  auto n118 = gate_nand(n117, n116);
  auto n120 = gate_nand(n119, n118);
  auto n122 = gate_nand(n121, n120);
  auto n124 = gate_nand(n123, n122);
  auto n130 = gate_nand(n125, n124);
  auto n128 = gate_xor(n125, n124);
  auto n127 = gate_nand(n16, n126);
  auto n129 = gate_nand(n128, n127);
  auto n131 = gate_nand(n130, n129);
  auto n17 = gate_and(n132, n131);
  auto n151 = gate_nand(n150, n17);
  auto n133 = gate_not(n151);
  auto n144 = gate_xor(n150, n134);
  auto n12 = gate_and(n133, n144);
  auto n145 = gate_not(n150);
  auto n143 = gate_xor(n145, n135);
  auto n3 = gate_and(n12, n143);
  auto n142 = gate_xor(n145, n136);
  auto n11 = gate_and(n3, n142);
  auto n141 = gate_xor(n145, n137);
  auto n140 = gate_nand(n11, n141);
  auto n139 = gate_xor(n150, n138);
  y[5] = gate_xor(n140, n139);
  y[4] = gate_xor(n11, n141);
  y[3] = gate_xor(n3, n142);
  y[2] = gate_xor(n12, n143);
  y[1] = gate_xor(n133, n144);
  auto n152 = gate_xor(n17, n145);
  auto n146 = gate_not(b[0]);
  auto n5 = gate_and(n147, n146);
  auto n148 = gate_not(b[1]);
  auto n4 = gate_and(n5, n148);
  auto n149 = gate_nand(n4, n1);
  auto n18 = gate_and(n150, n149);
  y[0] = gate_mux(n152, n151, n18);
}
template<> void $NameUint<6>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_xnor(a[4], b[4]);
  auto n29 = gate_not(a[3]);
  auto n32 = gate_xor(n29, b[3]);
  auto n30 = gate_not(b[0]);
  auto n31 = gate_xor(n30, a[0]);
  auto n27 = gate_and(n32, n31);
  auto n33 = gate_not(a[1]);
  auto n36 = gate_xor(n33, b[1]);
  auto n34 = gate_not(a[2]);
  auto n35 = gate_xor(n34, b[2]);
  auto n24 = gate_and(n36, n35);
  auto n23 = gate_and(n27, n24);
  auto n25 = gate_and(n23, n28);
  auto n37 = gate_not(a[5]);
  auto n38 = gate_xor(n37, b[5]);
  y[0] = gate_and(n25, n38);
}
template<> void $NameUint<6>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[5]);
  auto n52 = gate_nand(n27, a[5]);
  auto n50 = gate_xor(n27, a[5]);
  auto n28 = gate_not(b[3]);
  auto n43 = gate_nand(n28, a[3]);
  auto n41 = gate_xor(n28, a[3]);
  auto n29 = gate_not(b[2]);
  auto n39 = gate_nand(n29, a[2]);
  auto n37 = gate_xor(n29, a[2]);
  auto n30 = gate_not(b[1]);
  auto n35 = gate_nand(n30, a[1]);
  auto n33 = gate_xor(n30, a[1]);
  auto n31 = gate_not(a[0]);
  auto n32 = gate_nand(b[0], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n44, a[4]);
  auto n46 = gate_xor(n44, a[4]);
  auto n45 = gate_not(b[4]);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  y[0] = gate_nand(n52, n51);
}
template<> void $NameUint<6>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[5]);
  auto n52 = gate_nand(n27, b[5]);
  auto n50 = gate_xor(n27, b[5]);
  auto n28 = gate_not(b[3]);
  auto n43 = gate_nand(n28, a[3]);
  auto n41 = gate_xor(n28, a[3]);
  auto n29 = gate_not(b[2]);
  auto n39 = gate_nand(n29, a[2]);
  auto n37 = gate_xor(n29, a[2]);
  auto n30 = gate_not(b[1]);
  auto n35 = gate_nand(n30, a[1]);
  auto n33 = gate_xor(n30, a[1]);
  auto n31 = gate_not(a[0]);
  auto n32 = gate_nand(b[0], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n44, a[4]);
  auto n46 = gate_xor(n44, a[4]);
  auto n45 = gate_not(b[4]);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  y[0] = gate_nand(n52, n51);
}
template<> void $NameUint<6>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[5]);
  auto n53 = gate_nand(n29, a[5]);
  auto n51 = gate_xor(n29, a[5]);
  auto n30 = gate_not(a[4]);
  auto n50 = gate_nand(n30, b[4]);
  auto n48 = gate_xor(n30, b[4]);
  auto n31 = gate_not(a[1]);
  auto n36 = gate_nand(n31, b[1]);
  auto n34 = gate_xor(n31, b[1]);
  auto n32 = gate_not(b[0]);
  auto n33 = gate_nand(a[0], n32);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n41 = gate_nand(n37, b[2]);
  auto n39 = gate_xor(n37, b[2]);
  auto n38 = gate_not(a[2]);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, b[3]);
  auto n44 = gate_xor(n42, b[3]);
  auto n43 = gate_not(a[3]);
  auto n45 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n28 = gate_and(n50, n49);
  auto n52 = gate_nand(n51, n28);
  y[0] = gate_nand(n53, n52);
}
template<> void $NameUint<6>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(a[5]);
  auto n53 = gate_nand(n29, b[5]);
  auto n51 = gate_xor(n29, b[5]);
  auto n30 = gate_not(a[4]);
  auto n50 = gate_nand(n30, b[4]);
  auto n48 = gate_xor(n30, b[4]);
  auto n31 = gate_not(a[1]);
  auto n36 = gate_nand(n31, b[1]);
  auto n34 = gate_xor(n31, b[1]);
  auto n32 = gate_not(b[0]);
  auto n33 = gate_nand(a[0], n32);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n41 = gate_nand(n37, b[2]);
  auto n39 = gate_xor(n37, b[2]);
  auto n38 = gate_not(a[2]);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, b[3]);
  auto n44 = gate_xor(n42, b[3]);
  auto n43 = gate_not(a[3]);
  auto n45 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n28 = gate_and(n50, n49);
  auto n52 = gate_nand(n51, n28);
  y[0] = gate_nand(n53, n52);
}
template<> void $NameUint<6>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n2, a[2]);
  auto n4 = gate_and(n3, a[3]);
  y[0] = gate_not(a[0]);
  y[1] = gate_xor(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  y[4] = gate_xor(n4, a[4]);
  auto n6 = gate_not(a[5]);
  auto n5 = gate_nand(n4, a[4]);
  y[5] = gate_xor(n6, n5);
}
template<> void $NameUint<6>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n25 = gate_xnor(a[4], b[4]);
  auto n26 = gate_not(a[3]);
  auto n29 = gate_xor(n26, b[3]);
  auto n27 = gate_not(b[0]);
  auto n28 = gate_xor(n27, a[0]);
  auto n24 = gate_and(n29, n28);
  auto n30 = gate_not(a[1]);
  auto n33 = gate_xor(n30, b[1]);
  auto n31 = gate_not(a[2]);
  auto n32 = gate_xor(n31, b[2]);
  auto n22 = gate_and(n33, n32);
  auto n21 = gate_and(n24, n22);
  auto n23 = gate_and(n21, n25);
  auto n34 = gate_not(a[5]);
  auto n35 = gate_xor(n34, b[5]);
  y[0] = gate_nand(n23, n35);
}
template<> void $NameUint<6>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n21 = gate_not(a[3]);
  auto n20 = gate_not(a[1]);
  auto n17 = gate_and(n21, n20);
  auto n23 = gate_not(a[2]);
  auto n22 = gate_not(a[5]);
  auto n19 = gate_and(n23, n22);
  auto n16 = gate_and(n17, n19);
  auto n24 = gate_not(a[4]);
  auto n18 = gate_and(n16, n24);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_nand(n18, n25);
  y[5] = gate_mux(c[5], b[5], n26);
  y[0] = gate_mux(c[0], b[0], n26);
  y[1] = gate_mux(c[1], b[1], n26);
  y[2] = gate_mux(c[2], b[2], n26);
  y[3] = gate_mux(c[3], b[3], n26);
  y[4] = gate_mux(c[4], b[4], n26);
}
template<> void $NameUint<6>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(a[5]);
  auto n52 = gate_nand(n27, b[5]);
  auto n50 = gate_xor(n27, b[5]);
  auto n28 = gate_not(a[3]);
  auto n43 = gate_nand(n28, b[3]);
  auto n41 = gate_xor(n28, b[3]);
  auto n29 = gate_not(a[2]);
  auto n39 = gate_nand(n29, b[2]);
  auto n37 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[1]);
  auto n35 = gate_nand(n30, b[1]);
  auto n33 = gate_xor(n30, b[1]);
  auto n31 = gate_not(b[0]);
  auto n32 = gate_nand(a[0], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n44, b[4]);
  auto n46 = gate_xor(n44, b[4]);
  auto n45 = gate_not(a[4]);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  y[0] = gate_nand(n52, n51);
}
template<> void $NameUint<6>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n27 = gate_not(b[5]);
  auto n52 = gate_nand(n27, a[5]);
  auto n50 = gate_xor(n27, a[5]);
  auto n28 = gate_not(a[3]);
  auto n43 = gate_nand(n28, b[3]);
  auto n41 = gate_xor(n28, b[3]);
  auto n29 = gate_not(a[2]);
  auto n39 = gate_nand(n29, b[2]);
  auto n37 = gate_xor(n29, b[2]);
  auto n30 = gate_not(a[1]);
  auto n35 = gate_nand(n30, b[1]);
  auto n33 = gate_xor(n30, b[1]);
  auto n31 = gate_not(b[0]);
  auto n32 = gate_nand(a[0], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  auto n48 = gate_nand(n44, b[4]);
  auto n46 = gate_xor(n44, b[4]);
  auto n45 = gate_not(a[4]);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  y[0] = gate_nand(n52, n51);
}
template<> void $NameUint<6>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_not(a[3]);
  auto n41 = gate_not(a[1]);
  auto n38 = gate_and(n42, n41);
  auto n44 = gate_not(a[2]);
  auto n43 = gate_not(a[5]);
  auto n40 = gate_and(n44, n43);
  auto n33 = gate_and(n38, n40);
  auto n45 = gate_not(a[4]);
  auto n39 = gate_and(n33, n45);
  auto n46 = gate_not(a[0]);
  auto n54 = gate_nand(n39, n46);
  auto n48 = gate_not(b[4]);
  auto n47 = gate_not(b[1]);
  auto n35 = gate_and(n48, n47);
  auto n50 = gate_not(b[2]);
  auto n49 = gate_not(b[5]);
  auto n36 = gate_and(n50, n49);
  auto n32 = gate_and(n35, n36);
  auto n52 = gate_not(b[0]);
  auto n51 = gate_not(b[3]);
  auto n34 = gate_and(n52, n51);
  auto n53 = gate_nand(n32, n34);
  y[0] = gate_and(n54, n53);
}
template<> void $NameUint<6>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n23 = gate_not(a[3]);
  auto n27 = gate_not(a[0]);
  auto n22 = gate_not(a[1]);
  auto n19 = gate_and(n23, n22);
  auto n25 = gate_not(a[2]);
  auto n24 = gate_not(a[5]);
  auto n21 = gate_and(n25, n24);
  auto n17 = gate_and(n19, n21);
  auto n26 = gate_not(a[4]);
  auto n20 = gate_and(n17, n26);
  y[0] = gate_and(n20, n27);
}
template<> void $NameUint<6>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n44 = gate_not(a[4]);
  auto n43 = gate_not(a[0]);
  auto n41 = gate_and(n44, n43);
  auto n46 = gate_not(a[2]);
  auto n45 = gate_not(a[1]);
  auto n39 = gate_and(n46, n45);
  auto n48 = gate_not(b[2]);
  auto n47 = gate_not(b[4]);
  auto n37 = gate_and(n48, n47);
  auto n50 = gate_not(a[5]);
  auto n49 = gate_not(b[0]);
  auto n42 = gate_and(n50, n49);
  auto n36 = gate_and(n37, n42);
  auto n52 = gate_not(a[3]);
  auto n51 = gate_not(b[3]);
  auto n40 = gate_and(n52, n51);
  auto n54 = gate_not(b[5]);
  auto n53 = gate_not(b[1]);
  auto n38 = gate_and(n54, n53);
  auto n35 = gate_and(n40, n38);
  auto n33 = gate_and(n36, n35);
  auto n34 = gate_and(n39, n33);
  y[0] = gate_nand(n41, n34);
}
template<> void $NameUint<6>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(a[5]);
  auto n53 = gate_nand(n29, b[5]);
  auto n51 = gate_xor(n29, b[5]);
  auto n30 = gate_not(b[4]);
  auto n50 = gate_nand(n30, a[4]);
  auto n48 = gate_xor(n30, a[4]);
  auto n31 = gate_not(b[1]);
  auto n36 = gate_nand(n31, a[1]);
  auto n34 = gate_xor(n31, a[1]);
  auto n32 = gate_not(a[0]);
  auto n33 = gate_nand(b[0], n32);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n41 = gate_nand(n37, a[2]);
  auto n39 = gate_xor(n37, a[2]);
  auto n38 = gate_not(b[2]);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, a[3]);
  auto n44 = gate_xor(n42, a[3]);
  auto n43 = gate_not(b[3]);
  auto n45 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n28 = gate_and(n50, n49);
  auto n52 = gate_nand(n51, n28);
  y[0] = gate_nand(n53, n52);
}
template<> void $NameUint<6>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n29 = gate_not(b[5]);
  auto n53 = gate_nand(n29, a[5]);
  auto n51 = gate_xor(n29, a[5]);
  auto n30 = gate_not(b[4]);
  auto n50 = gate_nand(n30, a[4]);
  auto n48 = gate_xor(n30, a[4]);
  auto n31 = gate_not(b[1]);
  auto n36 = gate_nand(n31, a[1]);
  auto n34 = gate_xor(n31, a[1]);
  auto n32 = gate_not(a[0]);
  auto n33 = gate_nand(b[0], n32);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n41 = gate_nand(n37, a[2]);
  auto n39 = gate_xor(n37, a[2]);
  auto n38 = gate_not(b[2]);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, a[3]);
  auto n44 = gate_xor(n42, a[3]);
  auto n43 = gate_not(b[3]);
  auto n45 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  auto n49 = gate_nand(n48, n47);
  auto n28 = gate_and(n50, n49);
  auto n52 = gate_nand(n51, n28);
  y[0] = gate_nand(n53, n52);
}
template<> void $NameUint<6>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n81 = gate_not(b[5]);
  auto n86 = gate_not(b[4]);
  auto n3 = gate_and(n81, n86);
  auto n96 = gate_not(b[2]);
  auto n91 = gate_not(b[3]);
  auto n2 = gate_and(n3, n91);
  auto n1 = gate_and(n2, n96);
  auto n99 = gate_not(b[1]);
  auto n9 = gate_and(n1, n99);
  auto n15 = gate_mux(a[5], b[0], n99);
  auto n11 = gate_and(n1, n15);
  auto n16 = gate_not(a[4]);
  auto n17 = gate_nand(b[0], n16);
  auto n19 = gate_nand(n11, n17);
  auto n32 = gate_nand(a[4], n19);
  auto n35 = gate_not(a[3]);
  auto n23 = gate_nand(b[0], n35);
  auto n22 = gate_xor(n99, n32);
  auto n31 = gate_nand(n23, n22);
  auto n18 = gate_nand(b[0], n9);
  auto n10 = gate_and(a[5], n18);
  auto n7 = gate_and(n10, n19);
  auto n29 = gate_nand(n7, n96);
  auto n20 = gate_not(a[5]);
  auto n27 = gate_nand(b[2], n20);
  auto n21 = gate_not(n32);
  auto n26 = gate_nand(n21, n99);
  auto n24 = gate_not(n22);
  auto n25 = gate_nand(n24, n23);
  auto n43 = gate_nand(n26, n25);
  auto n28 = gate_nand(n27, n43);
  auto n30 = gate_nand(n29, n28);
  auto n6 = gate_and(n2, n30);
  auto n55 = gate_mux(n32, n31, n6);
  auto n33 = gate_not(n55);
  auto n41 = gate_nand(n96, n33);
  auto n39 = gate_xor(b[2], n55);
  auto n34 = gate_nand(n6, b[0]);
  auto n59 = gate_xor(n35, n34);
  auto n38 = gate_nand(n99, n59);
  auto n36 = gate_xor(n99, n59);
  auto n62 = gate_not(a[2]);
  auto n56 = gate_nand(b[0], n62);
  auto n37 = gate_nand(n36, n56);
  auto n52 = gate_nand(n38, n37);
  auto n40 = gate_nand(n39, n52);
  auto n48 = gate_nand(n41, n40);
  auto n42 = gate_xor(n48, n91);
  auto n46 = gate_nand(n3, n42);
  auto n44 = gate_nand(n96, n43);
  auto n45 = gate_nand(n44, n6);
  auto n8 = gate_and(n45, n7);
  auto n74 = gate_nand(n46, n8);
  auto n75 = gate_not(n74);
  auto n47 = gate_xor(n91, n8);
  auto n50 = gate_nand(n48, n47);
  auto n49 = gate_nand(n91, n8);
  auto n51 = gate_nand(n50, n49);
  auto n14 = gate_and(n3, n51);
  auto n53 = gate_xor(n52, n96);
  auto n54 = gate_nand(n14, n53);
  auto n85 = gate_xor(n55, n54);
  auto n71 = gate_nand(n85, n91);
  auto n69 = gate_xor(n91, n85);
  auto n57 = gate_xor(n56, n99);
  auto n58 = gate_nand(n14, n57);
  auto n90 = gate_xor(n59, n58);
  auto n60 = gate_not(n90);
  auto n68 = gate_nand(n60, n96);
  auto n66 = gate_xor(b[2], n90);
  auto n61 = gate_nand(n14, b[0]);
  auto n95 = gate_xor(n62, n61);
  auto n65 = gate_nand(n99, n95);
  auto n63 = gate_xor(n99, n95);
  auto n98 = gate_not(a[1]);
  auto n92 = gate_nand(b[0], n98);
  auto n64 = gate_nand(n63, n92);
  auto n87 = gate_nand(n65, n64);
  auto n67 = gate_nand(n66, n87);
  auto n82 = gate_nand(n68, n67);
  auto n70 = gate_nand(n69, n82);
  auto n76 = gate_nand(n71, n70);
  auto n72 = gate_xor(n86, n76);
  auto n73 = gate_nand(n72, n81);
  auto n4 = gate_and(n75, n73);
  auto n111 = gate_nand(n4, n81);
  auto n108 = gate_nand(b[5], n74);
  auto n79 = gate_nand(n75, n86);
  auto n77 = gate_xor(n86, n75);
  auto n78 = gate_nand(n77, n76);
  auto n80 = gate_nand(n79, n78);
  auto n13 = gate_and(n81, n80);
  auto n83 = gate_xor(n91, n82);
  auto n84 = gate_nand(n13, n83);
  auto n12 = gate_xnor(n85, n84);
  auto n107 = gate_nand(n12, n86);
  auto n116 = gate_xor(n86, n12);
  auto n88 = gate_xor(n96, n87);
  auto n89 = gate_nand(n13, n88);
  auto n122 = gate_xor(n90, n89);
  auto n105 = gate_nand(n122, n91);
  auto n119 = gate_xor(n91, n122);
  auto n93 = gate_xor(n92, n99);
  auto n94 = gate_nand(n13, n93);
  auto n5 = gate_xnor(n95, n94);
  auto n103 = gate_nand(n5, n96);
  auto n123 = gate_xor(n96, n5);
  auto n97 = gate_nand(n13, b[0]);
  auto n129 = gate_xor(n98, n97);
  auto n101 = gate_nand(n99, n129);
  auto n127 = gate_xor(n99, n129);
  auto n132 = gate_not(a[0]);
  auto n126 = gate_nand(b[0], n132);
  auto n100 = gate_nand(n127, n126);
  auto n124 = gate_nand(n101, n100);
  auto n102 = gate_nand(n123, n124);
  auto n120 = gate_nand(n103, n102);
  auto n104 = gate_nand(n119, n120);
  auto n117 = gate_nand(n105, n104);
  auto n106 = gate_nand(n116, n117);
  auto n112 = gate_nand(n107, n106);
  auto n109 = gate_nand(n108, n112);
  auto n130 = gate_nand(n111, n109);
  auto n110 = gate_not(n130);
  auto n115 = gate_nand(n4, n110);
  auto n113 = gate_not(n111);
  auto n114 = gate_nand(n113, n112);
  y[5] = gate_nand(n115, n114);
  auto n118 = gate_xor(n117, n116);
  y[4] = gate_mux(n12, n118, n130);
  auto n121 = gate_xor(n120, n119);
  y[3] = gate_mux(n122, n121, n130);
  auto n125 = gate_xor(n124, n123);
  y[2] = gate_mux(n5, n125, n130);
  auto n128 = gate_xor(n127, n126);
  y[1] = gate_mux(n129, n128, n130);
  auto n131 = gate_nand(n130, b[0]);
  y[0] = gate_xor(n132, n131);
}
template<> void $NameUint<6>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n14 = gate_not(a[0]);
  auto n17 = gate_nand(n15, n14);
  auto n16 = gate_nand(a[5], n17);
  auto n69 = gate_xor(a[2], n16);
  auto n105 = gate_not(b[5]);
  auto n114 = gate_xor(b[4], n105);
  auto n149 = gate_xor(b[3], n105);
  auto n8 = gate_and(n149, n114);
  auto n121 = gate_not(n149);
  auto n19 = gate_not(n17);
  auto n18 = gate_not(a[2]);
  auto n23 = gate_nand(n19, n18);
  auto n20 = gate_nand(a[5], n23);
  auto n47 = gate_xor(a[3], n20);
  auto n22 = gate_not(a[4]);
  auto n122 = gate_xor(b[2], n105);
  auto n1 = gate_and(n8, n122);
  auto n99 = gate_xor(b[5], b[1]);
  auto n145 = gate_not(n99);
  auto n7 = gate_and(n1, n145);
  auto n21 = gate_nand(b[0], n7);
  auto n5 = gate_and(n22, n21);
  auto n25 = gate_not(n23);
  auto n24 = gate_not(a[3]);
  auto n27 = gate_nand(n25, n24);
  auto n26 = gate_not(n27);
  auto n10 = gate_and(n26, a[5]);
  auto n32 = gate_nand(n5, n10);
  auto n31 = gate_not(n32);
  auto n30 = gate_xor(n32, n99);
  auto n28 = gate_nand(a[5], n27);
  auto n33 = gate_xor(a[4], n28);
  auto n29 = gate_nand(n33, b[0]);
  auto n9 = gate_and(n1, n29);
  auto n34 = gate_nand(n30, n9);
  auto n2 = gate_and(n31, n34);
  auto n44 = gate_nand(n2, n122);
  auto n124 = gate_not(n122);
  auto n42 = gate_nand(n124, n32);
  auto n37 = gate_not(n33);
  auto n35 = gate_not(n34);
  auto n36 = gate_nand(n35, b[0]);
  auto n56 = gate_nand(n37, n36);
  auto n38 = gate_not(n56);
  auto n41 = gate_nand(n38, n145);
  auto n52 = gate_xor(n99, n56);
  auto n39 = gate_mux(b[5], n47, b[0]);
  auto n54 = gate_not(n39);
  auto n40 = gate_nand(n52, n54);
  auto n61 = gate_nand(n41, n40);
  auto n43 = gate_nand(n42, n61);
  auto n45 = gate_nand(n44, n43);
  auto n55 = gate_nand(n8, n45);
  auto n62 = gate_not(n55);
  auto n46 = gate_nand(n62, b[0]);
  auto n83 = gate_xor(n47, n46);
  auto n51 = gate_nand(n83, n145);
  auto n49 = gate_xor(n83, n145);
  auto n79 = gate_mux(b[5], n69, b[0]);
  auto n48 = gate_not(n79);
  auto n50 = gate_nand(n49, n48);
  auto n75 = gate_nand(n51, n50);
  auto n53 = gate_not(n52);
  auto n57 = gate_nand(n54, n53);
  auto n77 = gate_mux(n57, n56, n55);
  auto n73 = gate_not(n77);
  auto n58 = gate_xor(n122, n73);
  auto n60 = gate_nand(n75, n58);
  auto n59 = gate_nand(n122, n73);
  auto n70 = gate_nand(n60, n59);
  auto n66 = gate_nand(n149, n70);
  auto n63 = gate_nand(n122, n61);
  auto n64 = gate_nand(n63, n62);
  auto n3 = gate_and(n64, n2);
  auto n65 = gate_nand(n149, n3);
  auto n67 = gate_nand(n66, n65);
  auto n76 = gate_nand(n114, n67);
  auto n81 = gate_not(n76);
  auto n68 = gate_nand(n81, b[0]);
  auto n102 = gate_xor(n69, n68);
  auto n71 = gate_xor(n70, n149);
  auto n72 = gate_nand(n114, n71);
  auto n11 = gate_and(n3, n72);
  auto n97 = gate_nand(n11, n114);
  auto n74 = gate_xor(n124, n73);
  auto n78 = gate_nand(n75, n74);
  auto n113 = gate_mux(n78, n77, n76);
  auto n109 = gate_not(n113);
  auto n95 = gate_nand(n109, n149);
  auto n93 = gate_xor(n109, n149);
  auto n80 = gate_xor(n99, n79);
  auto n82 = gate_nand(n81, n80);
  auto n119 = gate_xor(n83, n82);
  auto n84 = gate_not(n119);
  auto n92 = gate_nand(n84, n122);
  auto n90 = gate_xor(n124, n119);
  auto n89 = gate_nand(n102, n145);
  auto n87 = gate_xor(n102, n145);
  auto n85 = gate_nand(a[5], a[0]);
  auto n104 = gate_xor(a[1], n85);
  auto n98 = gate_mux(b[5], n104, b[0]);
  auto n86 = gate_not(n98);
  auto n88 = gate_nand(n87, n86);
  auto n115 = gate_nand(n89, n88);
  auto n91 = gate_nand(n90, n115);
  auto n111 = gate_nand(n92, n91);
  auto n94 = gate_nand(n93, n111);
  auto n135 = gate_nand(n95, n94);
  auto n155 = gate_not(n114);
  auto n96 = gate_nand(n135, n114);
  auto n116 = gate_nand(n97, n96);
  auto n100 = gate_xor(n99, n98);
  auto n101 = gate_nand(n116, n100);
  auto n140 = gate_xor(n102, n101);
  auto n103 = gate_nand(b[0], n116);
  auto n148 = gate_xor(n104, n103);
  auto n108 = gate_nand(n148, n145);
  auto n106 = gate_xor(n148, n145);
  auto n144 = gate_mux(n105, a[0], b[0]);
  auto n107 = gate_nand(n106, n144);
  auto n125 = gate_nand(n108, n107);
  auto n138 = gate_xor(n125, n122);
  auto n110 = gate_xor(n109, n121);
  auto n112 = gate_nand(n111, n110);
  auto n161 = gate_mux(n113, n112, n116);
  auto n156 = gate_not(n161);
  auto n134 = gate_nand(n156, n114);
  auto n132 = gate_xor(n156, n114);
  auto n117 = gate_xor(n115, n122);
  auto n118 = gate_nand(n117, n116);
  auto n120 = gate_xor(n119, n118);
  auto n131 = gate_nand(n120, n149);
  auto n153 = gate_not(n120);
  auto n129 = gate_xor(n121, n153);
  auto n123 = gate_not(n140);
  auto n128 = gate_nand(n123, n122);
  auto n126 = gate_xor(n124, n140);
  auto n127 = gate_nand(n126, n125);
  auto n150 = gate_nand(n128, n127);
  auto n130 = gate_nand(n129, n150);
  auto n158 = gate_nand(n131, n130);
  auto n133 = gate_nand(n132, n158);
  auto n164 = gate_nand(n134, n133);
  auto n137 = gate_not(n164);
  auto n136 = gate_mux(n155, n114, n135);
  auto n163 = gate_nand(n11, n136);
  auto n159 = gate_nand(n137, n163);
  auto n139 = gate_nand(n138, n159);
  auto n141 = gate_xor(n140, n139);
  auto n171 = gate_xor(a[5], n141);
  auto n176 = gate_not(a[5]);
  auto n143 = gate_xor(n176, a[0]);
  auto n142 = gate_nand(b[0], n159);
  auto n172 = gate_xor(n143, n142);
  auto n12 = gate_and(a[5], n172);
  auto n146 = gate_xor(n145, n144);
  auto n147 = gate_nand(n159, n146);
  auto n174 = gate_xor(n148, n147);
  auto n6 = gate_and(n12, n174);
  auto n13 = gate_and(n171, n6);
  auto n151 = gate_xor(n150, n149);
  auto n152 = gate_nand(n151, n159);
  auto n154 = gate_xor(n153, n152);
  auto n170 = gate_xor(a[5], n154);
  auto n4 = gate_and(n13, n170);
  auto n157 = gate_xor(n156, n155);
  auto n160 = gate_nand(n158, n157);
  auto n162 = gate_mux(n161, n160, n159);
  auto n169 = gate_xor(n176, n162);
  auto n168 = gate_nand(n4, n169);
  auto n165 = gate_not(n163);
  auto n166 = gate_nand(n165, n164);
  auto n167 = gate_nand(a[5], n166);
  y[5] = gate_xor(n168, n167);
  y[4] = gate_xor(n4, n169);
  y[3] = gate_xor(n13, n170);
  y[2] = gate_xor(n171, n6);
  auto n175 = gate_not(n172);
  y[0] = gate_xor(n176, n175);
  auto n173 = gate_nand(a[5], n175);
  y[1] = gate_xor(n174, n173);
}
template<> void $NameUint<6>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(b[0], a[3]);
  auto n3 = gate_and(b[1], a[0]);
  y[0] = gate_and(a[0], b[0]);
  auto n5 = gate_and(a[1], b[1]);
  auto n6 = gate_and(a[1], b[0]);
  y[1] = gate_xor(n6, n3);
  auto n13 = gate_nand(n6, n3);
  auto n7 = gate_not(n13);
  auto n8 = gate_nand(b[2], a[0]);
  auto n12 = gate_xor(n5, n8);
  auto n11 = gate_nand(b[0], a[2]);
  auto n14 = gate_xor(n12, n11);
  y[2] = gate_xor(n7, n14);
  auto n20 = gate_nand(a[1], b[2]);
  auto n21 = gate_nand(a[0], b[3]);
  auto n10 = gate_xor(n20, n21);
  auto n9 = gate_not(n8);
  auto n25 = gate_nand(n5, n9);
  auto n29 = gate_xor(n10, n25);
  auto n17 = gate_not(n29);
  auto n16 = gate_nand(n12, n11);
  auto n15 = gate_nand(n14, n13);
  auto n28 = gate_nand(n16, n15);
  auto n18 = gate_nand(b[1], a[2]);
  auto n27 = gate_xor(n1, n18);
  auto n30 = gate_xor(n28, n27);
  y[3] = gate_xor(n17, n30);
  auto n41 = gate_nand(b[0], a[4]);
  auto n42 = gate_nand(b[1], a[3]);
  auto n40 = gate_xor(n41, n42);
  auto n19 = gate_not(n18);
  auto n37 = gate_nand(n1, n19);
  auto n23 = gate_not(n20);
  auto n22 = gate_not(n21);
  auto n24 = gate_nand(n23, n22);
  auto n36 = gate_nand(n25, n24);
  auto n26 = gate_xor(n37, n36);
  auto n69 = gate_xor(n40, n26);
  auto n34 = gate_not(n69);
  auto n32 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n68 = gate_nand(n32, n31);
  auto n50 = gate_nand(a[1], b[3]);
  auto n54 = gate_nand(b[2], a[2]);
  auto n49 = gate_nand(a[0], b[4]);
  auto n33 = gate_xor(n54, n49);
  auto n67 = gate_xor(n50, n33);
  auto n70 = gate_xor(n68, n67);
  y[4] = gate_xor(n34, n70);
  auto n35 = gate_not(n37);
  auto n46 = gate_nand(n35, n36);
  auto n38 = gate_not(n36);
  auto n39 = gate_nand(n38, n37);
  auto n2 = gate_and(n40, n39);
  auto n44 = gate_not(n41);
  auto n43 = gate_not(n42);
  auto n45 = gate_nand(n44, n43);
  auto n76 = gate_mux(n46, n2, n45);
  auto n48 = gate_nand(a[5], b[0]);
  auto n47 = gate_nand(a[4], b[1]);
  auto n58 = gate_xor(n48, n47);
  auto n56 = gate_nand(n49, n50);
  auto n52 = gate_not(n49);
  auto n51 = gate_not(n50);
  auto n53 = gate_nand(n52, n51);
  auto n55 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n55);
  auto n66 = gate_xor(n58, n57);
  auto n60 = gate_nand(b[5], a[0]);
  auto n59 = gate_nand(b[4], a[1]);
  auto n64 = gate_xor(n60, n59);
  auto n62 = gate_nand(b[3], a[2]);
  auto n61 = gate_nand(a[3], b[2]);
  auto n63 = gate_xor(n62, n61);
  auto n65 = gate_xor(n64, n63);
  auto n74 = gate_xor(n66, n65);
  auto n72 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  auto n75 = gate_xor(n74, n73);
  y[5] = gate_xor(n76, n75);
}
template<> void $NameUint<6>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n13 = gate_and(a[0], a[3]);
  auto n14 = gate_and(a[4], a[1]);
  auto n11 = gate_and(n14, n13);
  auto n12 = gate_and(a[2], n11);
  y[0] = gate_and(a[5], n12);
}
template<> void $NameUint<6>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_and(a[4], a[1]);
  auto n13 = gate_and(a[0], a[3]);
  auto n11 = gate_and(n10, n13);
  auto n12 = gate_and(a[2], n11);
  y[0] = gate_nand(a[5], n12);
}
template<> void $NameUint<6>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n23 = gate_not(a[3]);
  auto n27 = gate_not(a[0]);
  auto n22 = gate_not(a[1]);
  auto n19 = gate_and(n23, n22);
  auto n25 = gate_not(a[2]);
  auto n24 = gate_not(a[5]);
  auto n21 = gate_and(n25, n24);
  auto n17 = gate_and(n19, n21);
  auto n26 = gate_not(a[4]);
  auto n20 = gate_and(n17, n26);
  y[0] = gate_and(n20, n27);
}
template<> void $NameUint<6>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n19 = gate_not(a[1]);
  auto n16 = gate_and(n20, n19);
  auto n22 = gate_not(a[2]);
  auto n21 = gate_not(a[5]);
  auto n18 = gate_and(n22, n21);
  auto n15 = gate_and(n16, n18);
  auto n23 = gate_not(a[4]);
  auto n17 = gate_and(n15, n23);
  auto n24 = gate_not(a[0]);
  y[0] = gate_nand(n17, n24);
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
  auto n50 = gate_not(b[3]);
  auto n78 = gate_not(b[0]);
  auto n49 = gate_not(b[4]);
  auto n38 = gate_and(n50, n49);
  auto n51 = gate_not(b[5]);
  auto n41 = gate_and(n38, n51);
  auto n52 = gate_nand(b[2], b[1]);
  auto n45 = gate_and(n41, n52);
  auto n69 = gate_not(b[2]);
  auto n36 = gate_and(n41, n69);
  auto n53 = gate_not(a[5]);
  auto n54 = gate_nand(n69, n53);
  auto n57 = gate_mux(n54, a[3], b[1]);
  auto n55 = gate_not(a[1]);
  auto n56 = gate_nand(b[2], n55);
  auto n62 = gate_nand(n57, n56);
  auto n58 = gate_not(a[4]);
  auto n59 = gate_nand(n58, n69);
  auto n66 = gate_mux(n59, a[2], b[1]);
  auto n60 = gate_not(a[0]);
  auto n67 = gate_nand(b[2], n60);
  auto n61 = gate_nand(n66, n67);
  auto n63 = gate_mux(n62, n61, b[0]);
  auto n64 = gate_not(n63);
  y[5] = gate_and(n45, n64);
  auto n65 = gate_mux(a[3], a[1], b[1]);
  auto n48 = gate_and(n65, n69);
  auto n68 = gate_mux(n66, n48, b[0]);
  auto n43 = gate_and(n68, n67);
  y[4] = gate_and(n45, n43);
  auto n70 = gate_mux(a[3], a[2], b[0]);
  auto n77 = gate_mux(a[1], a[0], b[0]);
  auto n71 = gate_mux(n70, n77, b[1]);
  y[3] = gate_and(n36, n71);
  auto n72 = gate_mux(a[2], a[0], b[1]);
  auto n75 = gate_nand(n36, n72);
  auto n73 = gate_not(b[1]);
  auto n42 = gate_and(n36, n73);
  y[1] = gate_and(n42, n77);
  auto n46 = gate_and(a[0], n42);
  y[0] = gate_and(n46, n78);
  auto n74 = gate_nand(n42, a[1]);
  auto n76 = gate_mux(n75, n74, b[0]);
  y[2] = gate_not(n76);
}
template<> void $NameUint<6>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n52 = gate_not(b[3]);
  auto n51 = gate_not(b[4]);
  auto n38 = gate_and(n52, n51);
  auto n53 = gate_not(b[5]);
  auto n39 = gate_and(n38, n53);
  auto n67 = gate_not(b[2]);
  auto n42 = gate_and(n39, n67);
  auto n54 = gate_not(b[0]);
  auto n36 = gate_and(n42, n54);
  auto n50 = gate_and(a[5], n36);
  auto n68 = gate_not(b[1]);
  auto n37 = gate_and(n42, n68);
  y[5] = gate_and(n50, n68);
  auto n47 = gate_and(n37, a[4]);
  auto n55 = gate_mux(a[4], a[5], b[0]);
  y[4] = gate_and(n37, n55);
  auto n58 = gate_mux(a[3], a[5], b[1]);
  auto n57 = gate_nand(n36, n58);
  auto n56 = gate_nand(b[0], n47);
  y[3] = gate_nand(n57, n56);
  auto n63 = gate_mux(a[2], a[4], b[1]);
  auto n46 = gate_and(n63, n67);
  auto n59 = gate_mux(n63, n58, b[0]);
  y[2] = gate_and(n42, n59);
  auto n60 = gate_nand(b[2], b[1]);
  auto n45 = gate_and(n39, n60);
  auto n61 = gate_not(a[1]);
  auto n62 = gate_nand(n61, n67);
  auto n73 = gate_mux(n62, a[3], b[1]);
  auto n64 = gate_mux(n73, n46, b[0]);
  auto n43 = gate_and(n45, n64);
  auto n65 = gate_not(a[5]);
  auto n74 = gate_nand(b[2], n65);
  y[1] = gate_and(n43, n74);
  auto n66 = gate_not(a[0]);
  auto n69 = gate_nand(n67, n66);
  auto n72 = gate_mux(a[2], n69, n68);
  auto n70 = gate_not(a[4]);
  auto n71 = gate_nand(b[2], n70);
  auto n76 = gate_nand(n72, n71);
  auto n75 = gate_nand(n74, n73);
  auto n77 = gate_mux(n76, n75, b[0]);
  auto n78 = gate_not(n77);
  y[0] = gate_and(n45, n78);
}
template<> void $NameUint<6>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_buf(a[5]);
  auto n25 = gate_and(y[5], b[1]);
  auto n44 = gate_not(b[0]);
  auto n43 = gate_not(b[1]);
  auto n23 = gate_and(a[3], n43);
  auto n27 = gate_nand(n44, n43);
  auto n49 = gate_mux(a[4], y[5], n27);
  auto n29 = gate_not(b[3]);
  auto n28 = gate_not(b[4]);
  auto n24 = gate_and(n29, n28);
  auto n30 = gate_not(b[5]);
  auto n50 = gate_nand(n24, n30);
  auto n32 = gate_not(n50);
  auto n31 = gate_not(b[2]);
  auto n35 = gate_nand(n32, n31);
  y[4] = gate_mux(n49, y[5], n35);
  auto n34 = gate_mux(a[4], a[3], n44);
  auto n48 = gate_not(n35);
  auto n33 = gate_nand(n48, n43);
  y[3] = gate_mux(n34, y[5], n33);
  auto n41 = gate_nand(y[5], n35);
  auto n39 = gate_mux(a[4], a[2], n43);
  auto n36 = gate_mux(n39, n23, b[0]);
  auto n37 = gate_nand(n48, n36);
  auto n26 = gate_and(n41, n37);
  auto n38 = gate_nand(b[0], n25);
  y[2] = gate_nand(n26, n38);
  auto n46 = gate_mux(a[3], a[1], n43);
  auto n40 = gate_mux(n46, n39, b[0]);
  auto n42 = gate_nand(n48, n40);
  y[1] = gate_nand(n42, n41);
  auto n45 = gate_mux(a[2], a[0], n43);
  auto n47 = gate_mux(n46, n45, n44);
  auto n54 = gate_nand(n48, n47);
  auto n52 = gate_nand(b[2], n49);
  auto n51 = gate_not(y[5]);
  auto n53 = gate_mux(n52, n51, n50);
  y[0] = gate_nand(n54, n53);
}
template<> void $NameUint<6>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n24 = gate_xor(b[5], a[5]);
  auto n4 = gate_not(b[1]);
  auto n6 = gate_xor(a[1], n4);
  auto n3 = gate_not(a[0]);
  auto n5 = gate_nand(b[0], n3);
  y[1] = gate_xor(n6, n5);
  auto n9 = gate_not(b[2]);
  auto n11 = gate_xor(a[2], n9);
  auto n8 = gate_nand(a[1], n4);
  auto n7 = gate_nand(n6, n5);
  auto n10 = gate_nand(n8, n7);
  y[2] = gate_xor(n11, n10);
  auto n14 = gate_not(b[3]);
  auto n16 = gate_xor(a[3], n14);
  auto n13 = gate_nand(a[2], n9);
  auto n12 = gate_nand(n11, n10);
  auto n15 = gate_nand(n13, n12);
  y[3] = gate_xor(n16, n15);
  auto n19 = gate_not(b[4]);
  auto n21 = gate_xor(a[4], n19);
  auto n18 = gate_nand(a[3], n14);
  auto n17 = gate_nand(n16, n15);
  auto n20 = gate_nand(n18, n17);
  y[4] = gate_xor(n21, n20);
  auto n23 = gate_nand(a[4], n19);
  auto n22 = gate_nand(n21, n20);
  auto n25 = gate_nand(n23, n22);
  y[5] = gate_xnor(n25, n24);
}
template<> void $NameUint<6>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n17 = gate_not(y[0]);
  auto n16 = gate_not(a[1]);
  auto n13 = gate_and(n17, n16);
  auto n21 = gate_not(a[2]);
  auto n14 = gate_and(n13, n21);
  auto n20 = gate_not(a[3]);
  auto n15 = gate_and(n14, n20);
  auto n19 = gate_not(a[4]);
  auto n18 = gate_nand(n15, n19);
  y[5] = gate_xor(a[5], n18);
  y[4] = gate_xor(n15, n19);
  y[3] = gate_xor(n14, n20);
  y[2] = gate_xor(n13, n21);
  y[1] = gate_xor(y[0], a[1]);
}
