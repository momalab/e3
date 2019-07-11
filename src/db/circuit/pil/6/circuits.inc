template<> void $NameUint<6>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_nand(b[4], a[4]);
  y[0] = gate_xor(a[0], b[0]);
  auto n5 = gate_xor(b[1], a[1]);
  auto n4 = gate_and(a[0], b[0]);
  y[1] = gate_xor(n5, n4);
  auto n9 = gate_xor(b[2], a[2]);
  auto n7 = gate_and(b[1], a[1]);
  auto n6 = gate_and(n5, n4);
  auto n8 = gate_or(n7, n6);
  y[2] = gate_xor(n9, n8);
  auto n13 = gate_xor(b[3], a[3]);
  auto n11 = gate_and(b[2], a[2]);
  auto n10 = gate_and(n9, n8);
  auto n12 = gate_or(n11, n10);
  y[3] = gate_xor(n13, n12);
  auto n17 = gate_xor(b[4], a[4]);
  auto n15 = gate_and(b[3], a[3]);
  auto n14 = gate_and(n13, n12);
  auto n16 = gate_or(n15, n14);
  y[4] = gate_xor(n17, n16);
  auto n20 = gate_not(b[5]);
  auto n3 = gate_nand(n17, n16);
  auto n18 = gate_and(n2, n3);
  auto n19 = gate_xor(a[5], n18);
  y[5] = gate_xor(n20, n19);
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
template<> void $NameUint<6>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  y[4] = gate_buf(zero);
  y[5] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n1 = gate_nand(N0, a[4]);
  auto n6 = gate_xor(N0, a[4]);
  auto n9 = gate_xor(n6, a[2]);
  auto n7 = gate_xor(a[1], a[3]);
  auto n8 = gate_xor(n7, a[5]);
  y[0] = gate_xor(n9, n8);
  auto n15 = gate_and(a[1], a[3]);
  auto n2 = gate_nand(n6, a[2]);
  auto n4 = gate_nand(n7, a[5]);
  auto n5 = gate_nand(n9, n8);
  auto n14 = gate_and(n1, n2);
  auto n13 = gate_and(n4, n5);
  auto n10 = gate_xor(n15, n13);
  y[1] = gate_xor(n14, n10);
  auto n12 = gate_not(n14);
  auto n11 = gate_not(n13);
  auto n17 = gate_and(n12, n11);
  auto n3 = gate_nand(n14, n13);
  auto n16 = gate_and(n15, n3);
  y[2] = gate_or(n17, n16);
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
template<> void $NameUint<6>::d_carryadd
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
  auto n15 = gate_xor(b[4], a[4]);
  y[4] = gate_xor(n14, n15);
  auto n17 = gate_and(b[4], a[4]);
  auto n16 = gate_and(n15, n14);
  y[5] = gate_or(n17, n16);
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
  auto n101 = gate_not(b[1]);
  auto n119 = gate_not(b[5]);
  auto n115 = gate_not(b[4]);
  auto n63 = gate_and(n119, n115);
  auto n111 = gate_not(b[3]);
  auto n45 = gate_and(n63, n111);
  auto n107 = gate_not(b[2]);
  auto n30 = gate_and(n45, n107);
  auto n29 = gate_and(n101, n30);
  auto n37 = gate_not(a[5]);
  auto n31 = gate_not(a[4]);
  auto n33 = gate_not(a[3]);
  auto n52 = gate_not(a[2]);
  auto n98 = gate_not(a[1]);
  auto n100 = gate_not(a[0]);
  auto n102 = gate_and(b[0], n100);
  auto n7 = gate_nand(b[0], n33);
  auto n8 = gate_nand(b[0], n31);
  auto n9 = gate_nand(b[0], n52);
  auto n10 = gate_nand(b[2], n37);
  auto n12 = gate_nand(b[0], n37);
  auto n14 = gate_nand(b[0], n98);
  auto n15 = gate_nand(b[1], n37);
  y[5] = gate_and(n29, n12);
  auto n32 = gate_and(n30, n15);
  y[4] = gate_and(n32, n8);
  auto n40 = gate_not(y[4]);
  auto n39 = gate_not(y[5]);
  auto n41 = gate_and(n40, n39);
  auto n61 = gate_and(a[5], n41);
  auto n42 = gate_and(n61, n107);
  auto n57 = gate_not(n61);
  auto n58 = gate_and(b[3], n57);
  auto n68 = gate_xor(n9, n101);
  auto n95 = gate_xor(n14, n101);
  auto n13 = gate_nand(n32, b[0]);
  auto n48 = gate_and(a[4], n13);
  auto n36 = gate_and(n48, n101);
  auto n46 = gate_xor(n48, b[1]);
  auto n34 = gate_not(n46);
  auto n35 = gate_and(n34, n7);
  auto n38 = gate_or(n36, n35);
  auto n43 = gate_and(n38, n10);
  auto n44 = gate_or(n43, n42);
  y[3] = gate_and(n45, n44);
  auto n47 = gate_and(y[3], n46);
  auto n50 = gate_and(n7, n47);
  auto n60 = gate_not(y[3]);
  auto n49 = gate_and(n48, n60);
  auto n66 = gate_or(n50, n49);
  auto n56 = gate_xor(n107, n66);
  auto n51 = gate_and(y[3], b[0]);
  auto n69 = gate_xor(n51, a[3]);
  auto n55 = gate_and(n101, n69);
  auto n53 = gate_xor(n101, n69);
  auto n54 = gate_and(n53, n9);
  auto n64 = gate_or(n55, n54);
  auto n83 = gate_and(n61, n60);
  auto n65 = gate_xor(n64, n107);
  auto n79 = gate_not(n83);
  auto n80 = gate_and(b[4], n79);
  auto n4 = gate_nand(n83, n111);
  auto n27 = gate_nand(n107, n66);
  auto n28 = gate_nand(n56, n64);
  auto n59 = gate_and(n28, n27);
  auto n62 = gate_or(n59, n58);
  auto n1 = gate_nand(n62, n4);
  y[2] = gate_and(n63, n1);
  auto n67 = gate_and(y[2], n65);
  auto n89 = gate_xor(n67, n66);
  auto n78 = gate_xor(n111, n89);
  auto n70 = gate_and(y[2], n68);
  auto n93 = gate_xor(n70, n69);
  auto n77 = gate_and(n93, n107);
  auto n75 = gate_xor(n107, n93);
  auto n71 = gate_and(y[2], b[0]);
  auto n96 = gate_xor(n71, a[2]);
  auto n74 = gate_and(n101, n96);
  auto n72 = gate_xor(n101, n96);
  auto n73 = gate_and(n72, n14);
  auto n91 = gate_or(n74, n73);
  auto n76 = gate_and(n75, n91);
  auto n87 = gate_or(n77, n76);
  auto n82 = gate_not(y[2]);
  auto n86 = gate_and(n83, n82);
  auto n88 = gate_xor(n111, n87);
  auto n92 = gate_xor(n107, n91);
  auto n6 = gate_nand(n86, n115);
  auto n25 = gate_nand(n89, n111);
  auto n26 = gate_nand(n78, n87);
  auto n81 = gate_and(n26, n25);
  auto n84 = gate_or(n81, n80);
  auto n22 = gate_nand(n84, n6);
  y[1] = gate_and(n119, n22);
  auto n85 = gate_not(y[1]);
  auto n117 = gate_and(n86, n85);
  auto n90 = gate_and(y[1], n88);
  auto n113 = gate_xor(n90, n89);
  auto n94 = gate_and(y[1], n92);
  auto n109 = gate_xor(n94, n93);
  auto n97 = gate_and(y[1], n95);
  auto n105 = gate_xor(n97, n96);
  auto n99 = gate_and(y[1], b[0]);
  auto n103 = gate_xor(n99, n98);
  auto n104 = gate_or(n103, n102);
  auto n20 = gate_nand(n103, n102);
  auto n5 = gate_nand(n101, n20);
  auto n106 = gate_and(n5, n104);
  auto n108 = gate_not(n106);
  auto n2 = gate_nand(n108, n107);
  auto n19 = gate_nand(n106, b[2]);
  auto n17 = gate_nand(n105, n19);
  auto n110 = gate_and(n17, n2);
  auto n112 = gate_not(n110);
  auto n3 = gate_nand(n112, n111);
  auto n16 = gate_nand(n110, b[3]);
  auto n23 = gate_nand(n109, n16);
  auto n114 = gate_and(n23, n3);
  auto n116 = gate_not(n114);
  auto n11 = gate_nand(n116, n115);
  auto n21 = gate_nand(n114, b[4]);
  auto n24 = gate_nand(n113, n21);
  auto n118 = gate_and(n24, n11);
  auto n120 = gate_not(n118);
  auto n121 = gate_and(n120, n119);
  auto n18 = gate_nand(n118, b[5]);
  auto n122 = gate_and(n117, n18);
  y[0] = gate_or(n122, n121);
}
template<> void $NameUint<6>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_nand(a[0], b[0]);
  auto n166 = gate_xor(a[5], b[5]);
  auto n45 = gate_not(b[5]);
  auto n106 = gate_xor(b[4], n45);
  auto n136 = gate_not(n106);
  auto n36 = gate_not(a[0]);
  auto n35 = gate_not(a[1]);
  auto n73 = gate_and(n36, n35);
  auto n37 = gate_not(a[2]);
  auto n57 = gate_and(n73, n37);
  auto n38 = gate_not(a[3]);
  auto n43 = gate_and(n57, n38);
  auto n39 = gate_not(n43);
  auto n40 = gate_and(n39, a[5]);
  auto n54 = gate_xor(n40, a[4]);
  auto n99 = gate_xor(b[3], n45);
  auto n68 = gate_and(n106, n99);
  auto n110 = gate_xor(b[2], n45);
  auto n163 = gate_and(n68, n110);
  auto n41 = gate_not(b[0]);
  auto n165 = gate_and(n45, n41);
  auto n119 = gate_not(n165);
  auto n42 = gate_not(a[4]);
  auto n44 = gate_and(n43, n42);
  auto n50 = gate_and(a[5], n44);
  auto n65 = gate_not(n50);
  auto n123 = gate_xor(b[1], n45);
  auto n126 = gate_not(n123);
  auto n47 = gate_and(b[0], n110);
  auto n46 = gate_and(n50, n68);
  auto n48 = gate_and(n47, n46);
  auto n150 = gate_and(n123, n48);
  auto n49 = gate_not(n150);
  auto n56 = gate_and(n50, n49);
  auto n51 = gate_and(n123, n56);
  auto n58 = gate_not(n57);
  auto n59 = gate_and(n58, a[5]);
  auto n71 = gate_xor(n59, a[3]);
  auto n128 = gate_not(n110);
  auto n132 = gate_not(n99);
  auto n74 = gate_not(n73);
  auto n75 = gate_and(n74, a[5]);
  auto n91 = gate_xor(n75, a[2]);
  auto n93 = gate_and(a[0], a[5]);
  auto n121 = gate_xor(n93, a[1]);
  auto n124 = gate_and(n119, n15);
  auto n145 = gate_not(n166);
  auto n151 = gate_xor(n166, n150);
  auto n162 = gate_not(b[1]);
  auto n164 = gate_and(n163, n162);
  auto n4 = gate_nand(n128, n65);
  auto n12 = gate_nand(n65, n126);
  auto n16 = gate_nand(n165, n164);
  auto n22 = gate_nand(b[0], n121);
  auto n24 = gate_nand(b[0], n91);
  auto n25 = gate_nand(b[0], n71);
  auto n32 = gate_nand(b[0], n54);
  auto n33 = gate_nand(n166, n16);
  auto n87 = gate_and(n119, n24);
  auto n76 = gate_not(n87);
  auto n88 = gate_xor(n126, n87);
  auto n115 = gate_and(n119, n22);
  auto n94 = gate_not(n115);
  auto n116 = gate_xor(n115, n126);
  auto n10 = gate_nand(n25, n119);
  auto n11 = gate_nand(n119, n32);
  auto n52 = gate_and(n11, n12);
  auto n53 = gate_or(n52, n51);
  auto n149 = gate_and(n163, n53);
  auto n55 = gate_not(n149);
  auto n69 = gate_and(n54, n55);
  auto n82 = gate_and(n56, n55);
  auto n64 = gate_and(n82, n110);
  auto n60 = gate_not(n69);
  auto n61 = gate_and(n123, n69);
  auto n70 = gate_not(n82);
  auto n153 = gate_xor(n166, n149);
  auto n1 = gate_nand(n132, n70);
  auto n14 = gate_nand(n126, n60);
  auto n62 = gate_and(n10, n14);
  auto n63 = gate_or(n62, n61);
  auto n66 = gate_or(n64, n63);
  auto n67 = gate_and(n66, n4);
  auto n148 = gate_and(n68, n67);
  auto n81 = gate_not(n148);
  auto n86 = gate_and(n69, n81);
  auto n72 = gate_and(n148, b[0]);
  auto n89 = gate_xor(n72, n71);
  auto n77 = gate_xor(n123, n89);
  auto n79 = gate_not(n86);
  auto n105 = gate_and(n82, n81);
  auto n83 = gate_and(n105, n99);
  auto n155 = gate_xor(n166, n148);
  auto n6 = gate_nand(n79, n128);
  auto n20 = gate_nand(n86, n110);
  auto n30 = gate_nand(n77, n76);
  auto n31 = gate_nand(n123, n89);
  auto n78 = gate_and(n31, n30);
  auto n5 = gate_nand(n78, n20);
  auto n80 = gate_and(n5, n6);
  auto n84 = gate_and(n1, n80);
  auto n85 = gate_or(n84, n83);
  auto n147 = gate_and(n106, n85);
  auto n104 = gate_not(n147);
  auto n109 = gate_and(n86, n104);
  auto n90 = gate_and(n147, n88);
  auto n113 = gate_xor(n90, n89);
  auto n98 = gate_xor(n113, n110);
  auto n92 = gate_and(n147, b[0]);
  auto n117 = gate_xor(n92, n91);
  auto n97 = gate_and(n123, n117);
  auto n95 = gate_xor(n123, n117);
  auto n96 = gate_and(n95, n94);
  auto n111 = gate_or(n97, n96);
  auto n101 = gate_not(n109);
  auto n102 = gate_and(n132, n101);
  auto n143 = gate_and(n105, n104);
  auto n108 = gate_not(n143);
  auto n112 = gate_xor(n111, n110);
  auto n157 = gate_xor(n166, n147);
  auto n3 = gate_nand(n108, n136);
  auto n18 = gate_nand(n143, n106);
  auto n19 = gate_nand(n99, n109);
  auto n28 = gate_nand(n98, n111);
  auto n29 = gate_nand(n113, n110);
  auto n100 = gate_and(n29, n28);
  auto n103 = gate_and(n100, n19);
  auto n107 = gate_or(n103, n102);
  auto n2 = gate_nand(n107, n18);
  auto n120 = gate_and(n2, n3);
  auto n146 = gate_not(n120);
  auto n137 = gate_and(n109, n146);
  auto n114 = gate_and(n112, n120);
  auto n134 = gate_xor(n114, n113);
  auto n118 = gate_and(n116, n120);
  auto n130 = gate_xor(n118, n117);
  auto n122 = gate_and(n120, b[0]);
  auto n125 = gate_xor(n122, n121);
  auto n127 = gate_not(n125);
  auto n140 = gate_not(n137);
  auto n159 = gate_xor(n146, n145);
  auto n7 = gate_nand(n127, n126);
  auto n17 = gate_nand(n146, n143);
  auto n21 = gate_nand(n125, n123);
  auto n8 = gate_nand(n124, n21);
  auto n129 = gate_and(n8, n7);
  auto n131 = gate_or(n130, n129);
  auto n23 = gate_nand(n130, n129);
  auto n9 = gate_nand(n128, n23);
  auto n133 = gate_and(n9, n131);
  auto n135 = gate_or(n134, n133);
  auto n27 = gate_nand(n134, n133);
  auto n13 = gate_nand(n132, n27);
  auto n138 = gate_and(n13, n135);
  auto n139 = gate_not(n138);
  auto n141 = gate_and(n140, n139);
  auto n26 = gate_nand(n137, n138);
  auto n142 = gate_and(n136, n26);
  auto n144 = gate_or(n142, n141);
  auto n161 = gate_and(n144, n17);
  auto n160 = gate_and(n166, n161);
  auto n158 = gate_and(n160, n159);
  auto n156 = gate_and(n158, n157);
  auto n154 = gate_and(n156, n155);
  auto n152 = gate_and(n154, n153);
  y[5] = gate_xor(n152, n151);
  y[4] = gate_xor(n154, n153);
  y[3] = gate_xor(n156, n155);
  y[2] = gate_xor(n158, n157);
  y[1] = gate_xor(n160, n159);
  auto n168 = gate_not(n160);
  auto n167 = gate_xor(n166, n161);
  auto n34 = gate_nand(n167, n33);
  y[0] = gate_and(n168, n34);
}
template<> void $NameUint<6>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_xnor(b[0], a[0]);
  auto n18 = gate_not(b[2]);
  auto n21 = gate_xor(n18, a[2]);
  auto n19 = gate_not(b[4]);
  auto n20 = gate_xor(n19, a[4]);
  auto n27 = gate_and(n21, n20);
  auto n22 = gate_not(b[5]);
  auto n25 = gate_xor(n22, a[5]);
  auto n23 = gate_not(b[3]);
  auto n24 = gate_xor(n23, a[3]);
  auto n26 = gate_and(n25, n24);
  auto n28 = gate_and(n27, n26);
  auto n31 = gate_and(n28, n17);
  auto n29 = gate_not(b[1]);
  auto n30 = gate_xor(n29, a[1]);
  y[0] = gate_and(n31, n30);
}
template<> void $NameUint<6>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n54 = gate_not(a[5]);
  auto n55 = gate_not(a[4]);
  auto n56 = gate_not(b[4]);
  auto n57 = gate_not(b[3]);
  auto n58 = gate_not(a[3]);
  auto n59 = gate_not(a[2]);
  auto n60 = gate_not(b[2]);
  auto n61 = gate_not(b[1]);
  auto n62 = gate_not(a[0]);
  auto n65 = gate_and(b[0], n62);
  auto n63 = gate_not(a[1]);
  auto n64 = gate_and(b[1], n63);
  auto n66 = gate_or(n65, n64);
  auto n71 = gate_not(b[5]);
  auto n72 = gate_and(a[5], n71);
  auto n43 = gate_nand(b[2], n59);
  auto n44 = gate_nand(b[3], n58);
  auto n46 = gate_nand(b[4], n55);
  auto n49 = gate_nand(b[5], n54);
  auto n50 = gate_nand(a[1], n61);
  auto n51 = gate_nand(a[3], n57);
  auto n52 = gate_nand(a[4], n56);
  auto n53 = gate_nand(a[2], n60);
  auto n70 = gate_and(n49, n46);
  auto n69 = gate_and(n52, n51);
  auto n68 = gate_and(n44, n43);
  auto n67 = gate_and(n53, n50);
  auto n47 = gate_nand(n67, n66);
  auto n48 = gate_nand(n68, n47);
  auto n45 = gate_nand(n69, n48);
  auto n73 = gate_and(n70, n45);
  y[0] = gate_or(n73, n72);
}
template<> void $NameUint<6>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n54 = gate_not(b[5]);
  auto n55 = gate_not(a[4]);
  auto n56 = gate_not(b[4]);
  auto n57 = gate_not(b[3]);
  auto n58 = gate_not(a[3]);
  auto n59 = gate_not(a[2]);
  auto n60 = gate_not(b[2]);
  auto n61 = gate_not(b[1]);
  auto n62 = gate_not(a[0]);
  auto n65 = gate_and(b[0], n62);
  auto n63 = gate_not(a[1]);
  auto n64 = gate_and(b[1], n63);
  auto n66 = gate_or(n65, n64);
  auto n71 = gate_not(a[5]);
  auto n72 = gate_and(b[5], n71);
  auto n44 = gate_nand(b[2], n59);
  auto n47 = gate_nand(b[4], n55);
  auto n48 = gate_nand(b[3], n58);
  auto n49 = gate_nand(a[4], n56);
  auto n50 = gate_nand(a[3], n57);
  auto n51 = gate_nand(a[5], n54);
  auto n52 = gate_nand(a[2], n60);
  auto n53 = gate_nand(a[1], n61);
  auto n70 = gate_and(n51, n47);
  auto n69 = gate_and(n49, n50);
  auto n68 = gate_and(n48, n44);
  auto n67 = gate_and(n52, n53);
  auto n46 = gate_nand(n67, n66);
  auto n43 = gate_nand(n68, n46);
  auto n45 = gate_nand(n69, n43);
  auto n73 = gate_and(n70, n45);
  y[0] = gate_or(n73, n72);
}
template<> void $NameUint<6>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(a[5]);
  auto n59 = gate_not(a[4]);
  auto n60 = gate_not(b[4]);
  auto n61 = gate_not(b[3]);
  auto n62 = gate_not(a[3]);
  auto n63 = gate_not(a[2]);
  auto n64 = gate_not(a[1]);
  auto n65 = gate_not(b[0]);
  auto n67 = gate_not(b[2]);
  auto n68 = gate_not(b[1]);
  auto n73 = gate_not(b[5]);
  auto n74 = gate_and(a[5], n73);
  auto n46 = gate_nand(b[3], n62);
  auto n47 = gate_nand(b[2], n63);
  auto n49 = gate_nand(b[4], n59);
  auto n50 = gate_nand(b[5], n58);
  auto n51 = gate_nand(b[1], n64);
  auto n54 = gate_nand(a[3], n61);
  auto n55 = gate_nand(a[2], n67);
  auto n56 = gate_nand(a[4], n60);
  auto n57 = gate_nand(a[1], n68);
  auto n72 = gate_and(n50, n49);
  auto n71 = gate_and(n56, n54);
  auto n70 = gate_and(n46, n47);
  auto n66 = gate_and(a[0], n51);
  auto n53 = gate_nand(n66, n65);
  auto n69 = gate_and(n53, n55);
  auto n45 = gate_nand(n69, n57);
  auto n52 = gate_nand(n70, n45);
  auto n48 = gate_nand(n71, n52);
  auto n75 = gate_and(n72, n48);
  y[0] = gate_or(n75, n74);
}
template<> void $NameUint<6>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[5]);
  auto n59 = gate_not(a[4]);
  auto n60 = gate_not(b[4]);
  auto n61 = gate_not(b[3]);
  auto n62 = gate_not(a[3]);
  auto n63 = gate_not(a[2]);
  auto n64 = gate_not(a[1]);
  auto n65 = gate_not(b[0]);
  auto n67 = gate_not(b[2]);
  auto n68 = gate_not(b[1]);
  auto n73 = gate_not(a[5]);
  auto n74 = gate_and(b[5], n73);
  auto n47 = gate_nand(b[2], n63);
  auto n48 = gate_nand(b[3], n62);
  auto n49 = gate_nand(b[1], n64);
  auto n50 = gate_nand(b[4], n59);
  auto n53 = gate_nand(a[2], n67);
  auto n54 = gate_nand(a[3], n61);
  auto n55 = gate_nand(a[5], n58);
  auto n56 = gate_nand(a[4], n60);
  auto n57 = gate_nand(a[1], n68);
  auto n72 = gate_and(n55, n50);
  auto n71 = gate_and(n56, n54);
  auto n70 = gate_and(n48, n47);
  auto n66 = gate_and(a[0], n49);
  auto n45 = gate_nand(n66, n65);
  auto n69 = gate_and(n45, n53);
  auto n51 = gate_nand(n69, n57);
  auto n46 = gate_nand(n70, n51);
  auto n52 = gate_nand(n71, n46);
  auto n75 = gate_and(n72, n52);
  y[0] = gate_or(n75, n74);
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
  auto n20 = gate_xnor(a[4], b[4]);
  auto n21 = gate_not(a[3]);
  auto n24 = gate_xor(n21, b[3]);
  auto n22 = gate_not(b[0]);
  auto n23 = gate_xor(n22, a[0]);
  auto n30 = gate_and(n24, n23);
  auto n25 = gate_not(a[1]);
  auto n28 = gate_xor(n25, b[1]);
  auto n26 = gate_not(a[2]);
  auto n27 = gate_xor(n26, b[2]);
  auto n29 = gate_and(n28, n27);
  auto n31 = gate_and(n30, n29);
  auto n34 = gate_and(n31, n20);
  auto n32 = gate_not(a[5]);
  auto n33 = gate_xor(n32, b[5]);
  y[0] = gate_nand(n34, n33);
}
template<> void $NameUint<6>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n24 = gate_not(a[3]);
  auto n23 = gate_not(a[1]);
  auto n28 = gate_and(n24, n23);
  auto n26 = gate_not(a[2]);
  auto n25 = gate_not(a[5]);
  auto n27 = gate_and(n26, n25);
  auto n30 = gate_and(n28, n27);
  auto n29 = gate_not(a[4]);
  auto n32 = gate_and(n30, n29);
  auto n31 = gate_not(a[0]);
  auto n42 = gate_and(n32, n31);
  y[0] = gate_mux(b[0], c[0], n42);
  auto n41 = gate_not(n42);
  auto n34 = gate_and(b[1], n41);
  auto n33 = gate_and(n42, c[1]);
  y[1] = gate_or(n34, n33);
  auto n36 = gate_and(b[2], n41);
  auto n35 = gate_and(n42, c[2]);
  y[2] = gate_or(n36, n35);
  auto n38 = gate_and(b[3], n41);
  auto n37 = gate_and(n42, c[3]);
  y[3] = gate_or(n38, n37);
  auto n40 = gate_and(b[4], n41);
  auto n39 = gate_and(n42, c[4]);
  y[4] = gate_or(n40, n39);
  auto n44 = gate_and(b[5], n41);
  auto n43 = gate_and(n42, c[5]);
  y[5] = gate_or(n44, n43);
}
template<> void $NameUint<6>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n54 = gate_not(b[5]);
  auto n55 = gate_not(b[4]);
  auto n56 = gate_not(a[4]);
  auto n57 = gate_not(a[3]);
  auto n58 = gate_not(b[3]);
  auto n59 = gate_not(b[2]);
  auto n60 = gate_not(a[2]);
  auto n61 = gate_not(a[1]);
  auto n62 = gate_not(b[0]);
  auto n65 = gate_and(a[0], n62);
  auto n63 = gate_not(b[1]);
  auto n64 = gate_and(a[1], n63);
  auto n66 = gate_or(n65, n64);
  auto n71 = gate_not(a[5]);
  auto n72 = gate_and(b[5], n71);
  auto n44 = gate_nand(b[1], n61);
  auto n45 = gate_nand(b[3], n57);
  auto n47 = gate_nand(b[4], n56);
  auto n48 = gate_nand(b[2], n60);
  auto n49 = gate_nand(a[4], n55);
  auto n50 = gate_nand(a[3], n58);
  auto n51 = gate_nand(a[5], n54);
  auto n52 = gate_nand(a[2], n59);
  auto n70 = gate_and(n51, n49);
  auto n69 = gate_and(n47, n45);
  auto n68 = gate_and(n50, n52);
  auto n67 = gate_and(n48, n44);
  auto n53 = gate_nand(n67, n66);
  auto n46 = gate_nand(n68, n53);
  auto n43 = gate_nand(n69, n46);
  auto n73 = gate_and(n70, n43);
  y[0] = gate_or(n73, n72);
}
template<> void $NameUint<6>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n54 = gate_not(a[5]);
  auto n55 = gate_not(b[4]);
  auto n56 = gate_not(a[4]);
  auto n57 = gate_not(a[3]);
  auto n58 = gate_not(b[3]);
  auto n59 = gate_not(b[2]);
  auto n60 = gate_not(a[2]);
  auto n61 = gate_not(a[1]);
  auto n62 = gate_not(b[0]);
  auto n65 = gate_and(a[0], n62);
  auto n63 = gate_not(b[1]);
  auto n64 = gate_and(a[1], n63);
  auto n66 = gate_or(n65, n64);
  auto n71 = gate_not(b[5]);
  auto n72 = gate_and(a[5], n71);
  auto n43 = gate_nand(b[1], n61);
  auto n44 = gate_nand(b[2], n60);
  auto n45 = gate_nand(b[3], n57);
  auto n46 = gate_nand(b[4], n56);
  auto n49 = gate_nand(b[5], n54);
  auto n51 = gate_nand(a[3], n58);
  auto n52 = gate_nand(a[4], n55);
  auto n53 = gate_nand(a[2], n59);
  auto n70 = gate_and(n49, n52);
  auto n69 = gate_and(n46, n45);
  auto n68 = gate_and(n51, n53);
  auto n67 = gate_and(n44, n43);
  auto n50 = gate_nand(n67, n66);
  auto n47 = gate_nand(n68, n50);
  auto n48 = gate_nand(n69, n47);
  auto n73 = gate_and(n70, n48);
  y[0] = gate_or(n73, n72);
}
template<> void $NameUint<6>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n28 = gate_not(a[3]);
  auto n27 = gate_not(a[1]);
  auto n32 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(a[5]);
  auto n31 = gate_and(n30, n29);
  auto n34 = gate_and(n32, n31);
  auto n33 = gate_not(a[4]);
  auto n36 = gate_and(n34, n33);
  auto n35 = gate_not(a[0]);
  auto n38 = gate_not(b[3]);
  auto n37 = gate_not(b[1]);
  auto n42 = gate_and(n38, n37);
  auto n40 = gate_not(b[2]);
  auto n39 = gate_not(b[5]);
  auto n41 = gate_and(n40, n39);
  auto n44 = gate_and(n42, n41);
  auto n43 = gate_not(b[4]);
  auto n46 = gate_and(n44, n43);
  auto n45 = gate_not(b[0]);
  auto n25 = gate_nand(n46, n45);
  auto n26 = gate_nand(n36, n35);
  y[0] = gate_and(n26, n25);
}
template<> void $NameUint<6>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n13 = gate_not(a[3]);
  auto n12 = gate_not(a[1]);
  auto n17 = gate_and(n13, n12);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[5]);
  auto n16 = gate_and(n15, n14);
  auto n19 = gate_and(n17, n16);
  auto n18 = gate_not(a[4]);
  auto n21 = gate_and(n19, n18);
  auto n20 = gate_not(a[0]);
  y[0] = gate_and(n21, n20);
}
template<> void $NameUint<6>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_not(a[5]);
  auto n25 = gate_not(b[4]);
  auto n46 = gate_and(n26, n25);
  auto n28 = gate_not(b[3]);
  auto n27 = gate_not(a[3]);
  auto n32 = gate_and(n28, n27);
  auto n30 = gate_not(a[2]);
  auto n29 = gate_not(b[2]);
  auto n31 = gate_and(n30, n29);
  auto n34 = gate_and(n32, n31);
  auto n33 = gate_not(a[1]);
  auto n44 = gate_and(n34, n33);
  auto n36 = gate_not(a[4]);
  auto n35 = gate_not(b[0]);
  auto n40 = gate_and(n36, n35);
  auto n38 = gate_not(b[5]);
  auto n37 = gate_not(b[1]);
  auto n39 = gate_and(n38, n37);
  auto n42 = gate_and(n40, n39);
  auto n41 = gate_not(a[0]);
  auto n43 = gate_and(n42, n41);
  auto n45 = gate_and(n44, n43);
  y[0] = gate_nand(n46, n45);
}
template<> void $NameUint<6>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[5]);
  auto n59 = gate_not(b[4]);
  auto n60 = gate_not(a[4]);
  auto n61 = gate_not(a[3]);
  auto n62 = gate_not(b[3]);
  auto n63 = gate_not(b[2]);
  auto n64 = gate_not(b[1]);
  auto n65 = gate_not(a[0]);
  auto n67 = gate_not(a[2]);
  auto n68 = gate_not(a[1]);
  auto n73 = gate_not(a[5]);
  auto n74 = gate_and(b[5], n73);
  auto n46 = gate_nand(b[1], n68);
  auto n47 = gate_nand(b[2], n67);
  auto n49 = gate_nand(b[3], n61);
  auto n51 = gate_nand(b[4], n60);
  auto n53 = gate_nand(a[2], n63);
  auto n54 = gate_nand(a[3], n62);
  auto n55 = gate_nand(a[5], n58);
  auto n56 = gate_nand(a[4], n59);
  auto n57 = gate_nand(a[1], n64);
  auto n72 = gate_and(n55, n56);
  auto n71 = gate_and(n51, n49);
  auto n70 = gate_and(n54, n53);
  auto n66 = gate_and(b[0], n57);
  auto n48 = gate_nand(n66, n65);
  auto n69 = gate_and(n48, n47);
  auto n45 = gate_nand(n69, n46);
  auto n52 = gate_nand(n70, n45);
  auto n50 = gate_nand(n71, n52);
  auto n75 = gate_and(n72, n50);
  y[0] = gate_or(n75, n74);
}
template<> void $NameUint<6>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(a[5]);
  auto n59 = gate_not(b[4]);
  auto n60 = gate_not(a[4]);
  auto n61 = gate_not(a[3]);
  auto n62 = gate_not(b[3]);
  auto n63 = gate_not(b[2]);
  auto n64 = gate_not(b[1]);
  auto n65 = gate_not(a[0]);
  auto n67 = gate_not(a[2]);
  auto n68 = gate_not(a[1]);
  auto n73 = gate_not(b[5]);
  auto n74 = gate_and(a[5], n73);
  auto n46 = gate_nand(b[2], n67);
  auto n47 = gate_nand(b[1], n68);
  auto n49 = gate_nand(b[3], n61);
  auto n50 = gate_nand(b[4], n60);
  auto n53 = gate_nand(b[5], n58);
  auto n54 = gate_nand(a[3], n62);
  auto n55 = gate_nand(a[2], n63);
  auto n56 = gate_nand(a[4], n59);
  auto n57 = gate_nand(a[1], n64);
  auto n72 = gate_and(n53, n56);
  auto n71 = gate_and(n50, n49);
  auto n70 = gate_and(n54, n55);
  auto n66 = gate_and(b[0], n57);
  auto n51 = gate_nand(n66, n65);
  auto n69 = gate_and(n51, n46);
  auto n52 = gate_nand(n69, n47);
  auto n48 = gate_nand(n70, n52);
  auto n45 = gate_nand(n71, n48);
  auto n75 = gate_and(n72, n45);
  y[0] = gate_or(n75, n74);
}
template<> void $NameUint<6>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n98 = gate_not(b[1]);
  auto n116 = gate_not(b[5]);
  auto n120 = gate_not(b[4]);
  auto n81 = gate_and(n116, n120);
  auto n125 = gate_not(b[3]);
  auto n31 = gate_and(n81, n125);
  auto n130 = gate_not(b[2]);
  auto n18 = gate_and(n31, n130);
  auto n15 = gate_and(n18, b[0]);
  auto n16 = gate_not(b[0]);
  auto n27 = gate_not(a[5]);
  auto n19 = gate_not(a[4]);
  auto n22 = gate_not(a[3]);
  auto n36 = gate_and(b[0], n22);
  auto n23 = gate_not(n36);
  auto n40 = gate_not(a[2]);
  auto n59 = gate_and(b[0], n40);
  auto n41 = gate_not(n59);
  auto n60 = gate_xor(n59, b[1]);
  auto n65 = gate_not(a[1]);
  auto n92 = gate_and(b[0], n65);
  auto n66 = gate_not(n92);
  auto n93 = gate_xor(n92, b[1]);
  auto n99 = gate_not(a[0]);
  auto n134 = gate_and(b[0], n99);
  auto n100 = gate_not(n134);
  auto n135 = gate_xor(n134, b[1]);
  auto n1 = gate_nand(n98, n16);
  auto n2 = gate_nand(n98, n15);
  auto n3 = gate_nand(b[0], n19);
  auto n4 = gate_nand(b[2], n27);
  auto n5 = gate_nand(b[1], n27);
  auto n21 = gate_and(a[5], n2);
  auto n17 = gate_and(n1, n5);
  auto n20 = gate_and(n18, n17);
  auto n7 = gate_nand(n20, n3);
  auto n33 = gate_and(n21, n7);
  auto n34 = gate_and(a[4], n7);
  auto n26 = gate_and(n34, n98);
  auto n24 = gate_xor(n34, n98);
  auto n25 = gate_and(n24, n23);
  auto n32 = gate_or(n26, n25);
  auto n29 = gate_and(n32, n4);
  auto n28 = gate_and(n33, n130);
  auto n30 = gate_or(n29, n28);
  auto n38 = gate_and(n31, n30);
  auto n35 = gate_and(n38, b[1]);
  auto n37 = gate_xor(n35, n34);
  auto n39 = gate_and(n38, b[0]);
  auto n61 = gate_xor(n39, a[3]);
  auto n44 = gate_and(n98, n61);
  auto n42 = gate_xor(n98, n61);
  auto n43 = gate_and(n42, n41);
  auto n55 = gate_or(n44, n43);
  auto n56 = gate_xor(n55, n130);
  auto n6 = gate_nand(n32, n130);
  auto n9 = gate_nand(n38, n36);
  auto n14 = gate_nand(n38, n6);
  auto n49 = gate_and(n33, n14);
  auto n57 = gate_and(n37, n9);
  auto n47 = gate_and(n130, n57);
  auto n45 = gate_xor(n130, n57);
  auto n46 = gate_and(n45, n55);
  auto n50 = gate_or(n47, n46);
  auto n48 = gate_xor(n125, n50);
  auto n53 = gate_and(n125, n49);
  auto n51 = gate_xor(n125, n49);
  auto n52 = gate_and(n51, n50);
  auto n54 = gate_or(n53, n52);
  auto n63 = gate_and(n81, n54);
  auto n58 = gate_and(n63, n56);
  auto n86 = gate_xor(n58, n57);
  auto n75 = gate_and(n86, n125);
  auto n73 = gate_xor(n125, n86);
  auto n62 = gate_and(n63, n60);
  auto n90 = gate_xor(n62, n61);
  auto n72 = gate_and(n90, n130);
  auto n70 = gate_xor(n130, n90);
  auto n64 = gate_and(n63, b[0]);
  auto n94 = gate_xor(n64, a[2]);
  auto n69 = gate_and(n98, n94);
  auto n67 = gate_xor(n98, n94);
  auto n68 = gate_and(n67, n66);
  auto n88 = gate_or(n69, n68);
  auto n71 = gate_and(n70, n88);
  auto n84 = gate_or(n72, n71);
  auto n74 = gate_and(n73, n84);
  auto n78 = gate_or(n75, n74);
  auto n76 = gate_xor(n120, n78);
  auto n85 = gate_xor(n125, n84);
  auto n89 = gate_xor(n130, n88);
  auto n12 = gate_nand(n76, n116);
  auto n13 = gate_nand(n81, n48);
  auto n80 = gate_and(n49, n13);
  auto n118 = gate_and(n80, n12);
  auto n113 = gate_not(n80);
  auto n77 = gate_xor(b[4], n113);
  auto n79 = gate_and(n78, n77);
  auto n83 = gate_and(n79, n116);
  auto n82 = gate_and(n81, n80);
  auto n96 = gate_or(n83, n82);
  auto n87 = gate_and(n96, n85);
  auto n122 = gate_xor(n87, n86);
  auto n112 = gate_and(n122, n120);
  auto n110 = gate_xor(n120, n122);
  auto n91 = gate_and(n96, n89);
  auto n127 = gate_xor(n91, n90);
  auto n109 = gate_and(n127, n125);
  auto n107 = gate_xor(n125, n127);
  auto n95 = gate_and(n96, n93);
  auto n132 = gate_xor(n95, n94);
  auto n106 = gate_and(n132, n130);
  auto n104 = gate_xor(n130, n132);
  auto n97 = gate_and(n96, b[0]);
  auto n136 = gate_xor(n97, a[1]);
  auto n103 = gate_and(n98, n136);
  auto n101 = gate_xor(n98, n136);
  auto n102 = gate_and(n101, n100);
  auto n129 = gate_or(n103, n102);
  auto n105 = gate_and(n104, n129);
  auto n124 = gate_or(n106, n105);
  auto n108 = gate_and(n107, n124);
  auto n119 = gate_or(n109, n108);
  auto n111 = gate_and(n110, n119);
  auto n117 = gate_or(n112, n111);
  auto n114 = gate_and(n118, n116);
  auto n121 = gate_xor(n120, n119);
  auto n126 = gate_xor(n125, n124);
  auto n131 = gate_xor(n130, n129);
  auto n8 = gate_nand(b[5], n113);
  auto n10 = gate_nand(n117, n116);
  auto n115 = gate_and(n117, n8);
  auto n138 = gate_or(n115, n114);
  auto n123 = gate_and(n121, n138);
  y[4] = gate_xor(n123, n122);
  auto n128 = gate_and(n126, n138);
  y[3] = gate_xor(n128, n127);
  auto n133 = gate_and(n131, n138);
  y[2] = gate_xor(n133, n132);
  auto n137 = gate_and(n135, n138);
  y[1] = gate_xor(n137, n136);
  auto n139 = gate_and(n138, b[0]);
  y[0] = gate_xor(n139, a[0]);
  auto n11 = gate_nand(n138, n10);
  y[5] = gate_and(n118, n11);
}
template<> void $NameUint<6>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_nand(a[0], b[0]);
  auto n33 = gate_not(a[1]);
  auto n32 = gate_not(a[0]);
  auto n75 = gate_and(n33, n32);
  auto n34 = gate_not(a[2]);
  auto n56 = gate_and(n75, n34);
  auto n35 = gate_not(a[3]);
  auto n44 = gate_and(n56, n35);
  auto n48 = gate_not(b[5]);
  auto n132 = gate_xor(b[1], n48);
  auto n163 = gate_xor(b[3], n48);
  auto n121 = gate_xor(b[4], n48);
  auto n89 = gate_and(n163, n121);
  auto n93 = gate_xor(b[5], b[2]);
  auto n148 = gate_not(n93);
  auto n43 = gate_and(n89, n148);
  auto n36 = gate_and(b[0], n43);
  auto n37 = gate_and(n132, n36);
  auto n38 = gate_not(n37);
  auto n40 = gate_and(n44, n38);
  auto n39 = gate_not(a[4]);
  auto n41 = gate_and(n40, n39);
  auto n52 = gate_and(a[5], n41);
  auto n42 = gate_xor(n132, n52);
  auto n50 = gate_and(n43, n42);
  auto n45 = gate_not(n44);
  auto n46 = gate_and(n45, a[5]);
  auto n54 = gate_xor(n46, a[4]);
  auto n49 = gate_not(n54);
  auto n47 = gate_not(b[0]);
  auto n57 = gate_not(n56);
  auto n58 = gate_and(n57, a[5]);
  auto n72 = gate_xor(n58, a[3]);
  auto n155 = gate_not(n132);
  auto n76 = gate_not(n75);
  auto n77 = gate_and(n76, a[5]);
  auto n102 = gate_xor(n77, a[2]);
  auto n104 = gate_and(a[5], a[0]);
  auto n130 = gate_xor(a[1], n104);
  auto n169 = gate_not(n121);
  auto n117 = gate_not(n163);
  auto n153 = gate_xor(a[0], a[5]);
  auto n5 = gate_nand(n48, n47);
  auto n23 = gate_nand(b[0], n130);
  auto n24 = gate_nand(b[0], n102);
  auto n30 = gate_nand(b[0], n72);
  auto n69 = gate_and(n5, n30);
  auto n59 = gate_not(n69);
  auto n97 = gate_and(n5, n24);
  auto n78 = gate_not(n97);
  auto n98 = gate_xor(n155, n97);
  auto n126 = gate_and(n5, n23);
  auto n105 = gate_not(n126);
  auto n127 = gate_xor(n155, n126);
  auto n156 = gate_and(n5, n15);
  auto n133 = gate_not(n156);
  auto n157 = gate_xor(n156, n155);
  auto n4 = gate_nand(n49, n5);
  auto n53 = gate_and(n50, n4);
  auto n51 = gate_not(n53);
  auto n63 = gate_and(n52, n51);
  auto n64 = gate_not(n63);
  auto n31 = gate_nand(n53, b[0]);
  auto n67 = gate_and(n54, n31);
  auto n55 = gate_and(n67, n132);
  auto n61 = gate_not(n55);
  auto n60 = gate_xor(n67, n132);
  auto n11 = gate_nand(n60, n59);
  auto n65 = gate_and(n61, n11);
  auto n62 = gate_xor(n93, n65);
  auto n6 = gate_nand(n65, n64);
  auto n22 = gate_nand(n89, n62);
  auto n88 = gate_and(n63, n22);
  auto n66 = gate_and(n6, n148);
  auto n71 = gate_and(n89, n66);
  auto n68 = gate_and(n71, n155);
  auto n70 = gate_xor(n68, n67);
  auto n73 = gate_and(n71, b[0]);
  auto n99 = gate_xor(n73, n72);
  auto n74 = gate_and(n99, n132);
  auto n80 = gate_not(n74);
  auto n79 = gate_xor(n99, n132);
  auto n90 = gate_and(n89, n88);
  auto n14 = gate_nand(n71, n69);
  auto n29 = gate_nand(n79, n78);
  auto n94 = gate_and(n70, n14);
  auto n84 = gate_and(n148, n94);
  auto n82 = gate_xor(n148, n94);
  auto n92 = gate_and(n80, n29);
  auto n81 = gate_not(n92);
  auto n83 = gate_and(n82, n81);
  auto n86 = gate_or(n84, n83);
  auto n85 = gate_xor(n86, n163);
  auto n87 = gate_and(n163, n86);
  auto n91 = gate_and(n87, n121);
  auto n101 = gate_or(n91, n90);
  auto n95 = gate_and(n101, n93);
  auto n96 = gate_xor(n95, n94);
  auto n100 = gate_and(n101, n98);
  auto n124 = gate_xor(n100, n99);
  auto n109 = gate_xor(n124, n148);
  auto n103 = gate_and(n101, b[0]);
  auto n128 = gate_xor(n103, n102);
  auto n108 = gate_and(n128, n132);
  auto n106 = gate_xor(n128, n132);
  auto n107 = gate_and(n106, n105);
  auto n122 = gate_or(n108, n107);
  auto n123 = gate_xor(n148, n122);
  auto n8 = gate_nand(n101, n92);
  auto n10 = gate_nand(n85, n121);
  auto n27 = gate_nand(n109, n122);
  auto n28 = gate_nand(n124, n148);
  auto n114 = gate_and(n88, n10);
  auto n118 = gate_and(n8, n96);
  auto n111 = gate_xor(n163, n118);
  auto n116 = gate_and(n28, n27);
  auto n110 = gate_not(n116);
  auto n16 = gate_nand(n114, n121);
  auto n20 = gate_nand(n111, n110);
  auto n21 = gate_nand(n118, n163);
  auto n112 = gate_and(n21, n20);
  auto n115 = gate_not(n112);
  auto n2 = gate_nand(n115, n121);
  auto n3 = gate_nand(n16, n2);
  auto n7 = gate_nand(n115, n169);
  auto n9 = gate_nand(n3, n116);
  auto n17 = gate_nand(n112, n121);
  auto n113 = gate_and(n17, n7);
  auto n144 = gate_and(n114, n113);
  auto n119 = gate_and(n3, n117);
  auto n120 = gate_xor(n119, n118);
  auto n170 = gate_and(n9, n120);
  auto n142 = gate_xor(n121, n170);
  auto n125 = gate_and(n3, n123);
  auto n165 = gate_xor(n125, n124);
  auto n140 = gate_xor(n163, n165);
  auto n129 = gate_and(n3, n127);
  auto n150 = gate_xor(n129, n128);
  auto n139 = gate_and(n150, n148);
  auto n137 = gate_xor(n150, n148);
  auto n131 = gate_and(n3, b[0]);
  auto n158 = gate_xor(n131, n130);
  auto n136 = gate_and(n158, n132);
  auto n134 = gate_xor(n158, n132);
  auto n135 = gate_and(n134, n133);
  auto n147 = gate_or(n136, n135);
  auto n138 = gate_and(n137, n147);
  auto n162 = gate_or(n139, n138);
  auto n145 = gate_not(n144);
  auto n149 = gate_xor(n148, n147);
  auto n164 = gate_xor(n163, n162);
  auto n19 = gate_nand(n170, n121);
  auto n25 = gate_nand(n140, n162);
  auto n26 = gate_nand(n165, n163);
  auto n168 = gate_and(n26, n25);
  auto n141 = gate_not(n168);
  auto n18 = gate_nand(n142, n141);
  auto n146 = gate_and(n19, n18);
  auto n143 = gate_not(n146);
  auto n1 = gate_nand(n144, n143);
  auto n13 = gate_nand(n146, n145);
  auto n175 = gate_and(a[5], n1);
  auto n151 = gate_and(n13, n149);
  auto n152 = gate_xor(n151, n150);
  auto n181 = gate_xor(a[5], n152);
  auto n154 = gate_and(b[0], n13);
  auto n185 = gate_xor(n154, n153);
  auto n161 = gate_and(a[5], n185);
  auto n159 = gate_and(n157, n13);
  auto n183 = gate_xor(n159, n158);
  auto n160 = gate_not(n183);
  auto n180 = gate_and(n161, n160);
  auto n179 = gate_and(n181, n180);
  auto n166 = gate_and(n13, n164);
  auto n167 = gate_xor(n166, n165);
  auto n178 = gate_xor(a[5], n167);
  auto n177 = gate_and(n179, n178);
  auto n171 = gate_and(n13, n169);
  auto n172 = gate_xor(n171, n170);
  y[3] = gate_xor(n179, n178);
  y[2] = gate_xor(n181, n180);
  auto n182 = gate_not(n185);
  auto n184 = gate_and(n182, a[5]);
  y[1] = gate_xor(n184, n183);
  y[0] = gate_xor(a[5], n185);
  auto n12 = gate_nand(n13, n168);
  auto n173 = gate_and(n12, n172);
  auto n176 = gate_xor(a[5], n173);
  auto n174 = gate_and(n177, n176);
  y[5] = gate_xor(n175, n174);
  y[4] = gate_xor(n177, n176);
}
template<> void $NameUint<6>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n14 = gate_and(a[1], b[0]);
  auto n13 = gate_and(b[1], a[0]);
  y[1] = gate_xor(n14, n13);
  auto n16 = gate_and(n14, n13);
  auto n29 = gate_and(b[1], a[1]);
  auto n31 = gate_and(a[0], b[2]);
  auto n15 = gate_xor(n29, n31);
  auto n23 = gate_or(n16, n15);
  auto n24 = gate_and(b[0], a[2]);
  auto n28 = gate_and(b[0], a[3]);
  auto n27 = gate_and(b[1], a[2]);
  auto n22 = gate_xor(n28, n27);
  auto n20 = gate_and(b[3], a[0]);
  auto n63 = gate_and(a[1], b[3]);
  auto n61 = gate_and(b[2], a[2]);
  auto n60 = gate_and(a[0], b[4]);
  auto n62 = gate_xor(n61, n60);
  auto n64 = gate_xor(n63, n62);
  auto n51 = gate_and(b[0], a[4]);
  auto n50 = gate_and(b[1], a[3]);
  auto n40 = gate_xor(n51, n50);
  auto n39 = gate_and(n28, n27);
  auto n30 = gate_or(n29, n63);
  auto n38 = gate_and(n31, n30);
  auto n32 = gate_xor(n39, n38);
  auto n36 = gate_xor(n40, n32);
  auto n33 = gate_not(n36);
  auto n43 = gate_or(n38, n39);
  auto n41 = gate_and(n39, n38);
  auto n42 = gate_or(n41, n40);
  auto n59 = gate_and(n43, n42);
  auto n45 = gate_and(b[5], a[0]);
  auto n44 = gate_and(b[4], a[1]);
  auto n49 = gate_xor(n45, n44);
  auto n47 = gate_and(a[5], b[0]);
  auto n46 = gate_and(a[4], b[1]);
  auto n48 = gate_xor(n47, n46);
  auto n57 = gate_xor(n49, n48);
  auto n55 = gate_and(n51, n50);
  auto n53 = gate_and(a[2], b[3]);
  auto n52 = gate_and(a[3], b[2]);
  auto n54 = gate_xor(n53, n52);
  auto n56 = gate_xor(n55, n54);
  auto n58 = gate_xor(n57, n56);
  auto n69 = gate_xor(n59, n58);
  auto n65 = gate_not(n64);
  auto n5 = gate_nand(n29, n31);
  auto n6 = gate_nand(n16, n15);
  auto n10 = gate_nand(n61, n60);
  auto n11 = gate_nand(n63, n62);
  auto n12 = gate_nand(n24, n23);
  auto n17 = gate_and(n6, n23);
  y[2] = gate_xor(n17, n24);
  auto n18 = gate_and(b[2], n5);
  auto n19 = gate_and(n18, a[1]);
  auto n21 = gate_xor(n20, n19);
  auto n26 = gate_or(n22, n21);
  auto n67 = gate_and(n10, n11);
  auto n2 = gate_nand(n12, n6);
  auto n8 = gate_nand(n2, n26);
  auto n9 = gate_nand(n22, n21);
  auto n25 = gate_and(n9, n26);
  y[3] = gate_xor(n25, n2);
  auto n34 = gate_and(n9, n8);
  auto n35 = gate_not(n34);
  auto n4 = gate_nand(n34, n33);
  auto n7 = gate_nand(n36, n35);
  auto n37 = gate_and(n4, n7);
  y[4] = gate_xor(n64, n37);
  auto n3 = gate_nand(n65, n7);
  auto n66 = gate_and(n4, n3);
  auto n68 = gate_xor(n67, n66);
  y[5] = gate_xnor(n69, n68);
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
  auto n13 = gate_not(a[3]);
  auto n12 = gate_not(a[1]);
  auto n17 = gate_and(n13, n12);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[5]);
  auto n16 = gate_and(n15, n14);
  auto n19 = gate_and(n17, n16);
  auto n18 = gate_not(a[4]);
  auto n21 = gate_and(n19, n18);
  auto n20 = gate_not(a[0]);
  y[0] = gate_and(n21, n20);
}
template<> void $NameUint<6>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n14 = gate_not(a[3]);
  auto n13 = gate_not(a[1]);
  auto n18 = gate_and(n14, n13);
  auto n16 = gate_not(a[2]);
  auto n15 = gate_not(a[5]);
  auto n17 = gate_and(n16, n15);
  auto n20 = gate_and(n18, n17);
  auto n19 = gate_not(a[4]);
  auto n22 = gate_and(n20, n19);
  auto n21 = gate_not(a[0]);
  y[0] = gate_nand(n22, n21);
}
template<> void $NameUint<6>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_xor(a[5], a[4]);
  auto n8 = gate_xor(a[0], a[1]);
  auto n11 = gate_xor(n9, n8);
  auto n10 = gate_xor(a[3], a[2]);
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
  auto n69 = gate_nand(b[0], a[1]);
  auto n70 = gate_nand(b[0], a[3]);
  auto n73 = gate_nand(b[0], a[4]);
  auto n75 = gate_nand(b[0], a[2]);
  auto n79 = gate_not(b[3]);
  auto n78 = gate_not(b[4]);
  auto n81 = gate_and(n79, n78);
  auto n80 = gate_not(b[5]);
  auto n97 = gate_and(n81, n80);
  auto n98 = gate_not(b[1]);
  auto n91 = gate_not(b[0]);
  auto n96 = gate_not(b[2]);
  auto n85 = gate_and(a[1], n91);
  auto n84 = gate_and(b[0], a[0]);
  auto n101 = gate_or(n85, n84);
  auto n110 = gate_and(n98, n101);
  auto n86 = gate_and(b[2], n110);
  auto n112 = gate_and(a[0], n91);
  auto n89 = gate_and(b[2], n112);
  auto n94 = gate_and(n98, n89);
  auto n109 = gate_and(n97, n96);
  auto n111 = gate_and(n109, n98);
  auto n104 = gate_and(b[1], n109);
  auto n102 = gate_and(n104, n101);
  auto n108 = gate_and(n112, n104);
  y[1] = gate_and(n110, n109);
  y[0] = gate_and(n112, n111);
  auto n66 = gate_nand(a[5], n91);
  auto n71 = gate_nand(a[3], n91);
  auto n72 = gate_nand(a[4], n91);
  auto n74 = gate_nand(a[2], n91);
  auto n82 = gate_and(n66, n73);
  auto n99 = gate_and(n71, n75);
  auto n90 = gate_and(n72, n70);
  auto n105 = gate_and(n74, n69);
  auto n100 = gate_not(n99);
  auto n103 = gate_and(n111, n100);
  y[3] = gate_or(n103, n102);
  auto n106 = gate_not(n105);
  auto n107 = gate_and(n111, n106);
  y[2] = gate_or(n108, n107);
  auto n67 = gate_nand(n98, n90);
  auto n68 = gate_nand(n98, n82);
  auto n76 = gate_nand(b[1], n105);
  auto n77 = gate_nand(b[1], n99);
  auto n83 = gate_and(n68, n77);
  auto n87 = gate_and(n83, n96);
  auto n88 = gate_or(n87, n86);
  y[5] = gate_and(n97, n88);
  auto n92 = gate_and(n67, n76);
  auto n93 = gate_and(n92, n96);
  auto n95 = gate_or(n94, n93);
  y[4] = gate_and(n97, n95);
}
template<> void $NameUint<6>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n96 = gate_not(b[0]);
  auto n84 = gate_and(a[5], n96);
  auto n67 = gate_not(b[3]);
  auto n66 = gate_not(b[4]);
  auto n69 = gate_and(n67, n66);
  auto n68 = gate_not(b[5]);
  auto n110 = gate_and(n69, n68);
  auto n104 = gate_not(b[2]);
  auto n72 = gate_and(n110, n104);
  auto n99 = gate_not(b[1]);
  auto n81 = gate_and(n72, n99);
  y[5] = gate_and(n84, n81);
  auto n71 = gate_and(a[4], n96);
  auto n70 = gate_and(b[0], a[5]);
  auto n77 = gate_or(n71, n70);
  auto n106 = gate_and(n99, n77);
  y[4] = gate_and(n72, n106);
  auto n78 = gate_and(b[1], n72);
  auto n76 = gate_and(n84, n78);
  auto n74 = gate_and(a[3], n96);
  auto n73 = gate_and(b[0], a[4]);
  auto n89 = gate_or(n74, n73);
  auto n75 = gate_and(n81, n89);
  y[3] = gate_or(n76, n75);
  auto n83 = gate_and(n78, n77);
  auto n80 = gate_and(a[2], n96);
  auto n79 = gate_and(b[0], a[3]);
  auto n101 = gate_or(n80, n79);
  auto n82 = gate_and(n81, n101);
  y[2] = gate_or(n83, n82);
  auto n85 = gate_and(b[2], n84);
  auto n94 = gate_and(n99, n85);
  auto n87 = gate_and(a[1], n96);
  auto n86 = gate_and(b[0], a[2]);
  auto n88 = gate_or(n87, n86);
  auto n91 = gate_and(n88, n99);
  auto n90 = gate_and(b[1], n89);
  auto n92 = gate_or(n91, n90);
  auto n93 = gate_and(n92, n104);
  auto n95 = gate_or(n94, n93);
  y[1] = gate_and(n110, n95);
  auto n98 = gate_and(a[0], n96);
  auto n97 = gate_and(b[0], a[1]);
  auto n100 = gate_or(n98, n97);
  auto n103 = gate_and(n100, n99);
  auto n102 = gate_and(b[1], n101);
  auto n105 = gate_or(n103, n102);
  auto n108 = gate_and(n105, n104);
  auto n107 = gate_and(b[2], n106);
  auto n109 = gate_or(n108, n107);
  y[0] = gate_and(n110, n109);
}
template<> void $NameUint<6>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_buf(a[5]);
  auto n71 = gate_nand(b[0], a[3]);
  auto n76 = gate_nand(b[0], a[1]);
  auto n84 = gate_not(b[3]);
  auto n83 = gate_not(b[4]);
  auto n86 = gate_and(n84, n83);
  auto n85 = gate_not(b[5]);
  auto n122 = gate_and(n86, n85);
  auto n119 = gate_not(b[2]);
  auto n109 = gate_and(n122, n119);
  auto n115 = gate_not(b[1]);
  auto n93 = gate_and(n109, n115);
  auto n87 = gate_not(n93);
  auto n95 = gate_and(y[5], n87);
  auto n114 = gate_not(b[0]);
  auto n97 = gate_and(a[4], n114);
  auto n88 = gate_and(b[0], y[5]);
  auto n89 = gate_or(n97, n88);
  auto n112 = gate_and(n89, n115);
  auto n90 = gate_and(n112, n109);
  y[4] = gate_or(n95, n90);
  auto n92 = gate_and(a[3], n114);
  auto n91 = gate_and(b[0], a[4]);
  auto n106 = gate_or(n92, n91);
  auto n94 = gate_and(n93, n106);
  y[3] = gate_or(n95, n94);
  auto n96 = gate_not(n109);
  auto n100 = gate_and(b[1], n97);
  auto n111 = gate_and(y[5], b[1]);
  auto n104 = gate_and(a[1], n114);
  auto n103 = gate_and(b[0], a[2]);
  auto n105 = gate_or(n104, n103);
  auto n108 = gate_and(n105, n115);
  auto n107 = gate_and(b[1], n106);
  auto n110 = gate_or(n108, n107);
  auto n113 = gate_or(n112, n111);
  auto n121 = gate_and(b[2], n113);
  auto n73 = gate_nand(a[2], n114);
  auto n77 = gate_nand(a[0], n114);
  auto n79 = gate_nand(n111, b[0]);
  auto n80 = gate_nand(y[5], n96);
  auto n81 = gate_nand(n110, n109);
  auto n117 = gate_and(n73, n71);
  auto n98 = gate_not(n117);
  auto n99 = gate_and(n98, n115);
  auto n101 = gate_or(n100, n99);
  auto n116 = gate_and(n77, n76);
  auto n72 = gate_nand(n116, n115);
  y[1] = gate_nand(n80, n81);
  auto n78 = gate_nand(b[1], n117);
  auto n82 = gate_nand(n109, n101);
  auto n102 = gate_and(n80, n82);
  auto n118 = gate_and(n72, n78);
  auto n120 = gate_and(n119, n118);
  auto n123 = gate_or(n121, n120);
  y[0] = gate_mux(y[5], n123, n122);
  y[2] = gate_nand(n102, n79);
}
template<> void $NameUint<6>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n6 = gate_not(b[1]);
  auto n7 = gate_xor(a[1], n6);
  auto n5 = gate_not(a[0]);
  auto n10 = gate_not(b[2]);
  auto n12 = gate_xor(a[2], n10);
  auto n9 = gate_and(a[1], n6);
  auto n15 = gate_not(b[3]);
  auto n17 = gate_xor(a[3], n15);
  auto n14 = gate_and(a[2], n10);
  auto n20 = gate_not(b[4]);
  auto n22 = gate_xor(a[4], n20);
  auto n19 = gate_and(a[3], n15);
  auto n23 = gate_xor(a[5], b[5]);
  auto n2 = gate_nand(b[0], n5);
  auto n3 = gate_nand(a[4], n20);
  y[1] = gate_xor(n7, n2);
  auto n8 = gate_and(n7, n2);
  auto n11 = gate_or(n9, n8);
  y[2] = gate_xor(n12, n11);
  auto n13 = gate_and(n12, n11);
  auto n16 = gate_or(n14, n13);
  y[3] = gate_xor(n17, n16);
  auto n18 = gate_and(n17, n16);
  auto n21 = gate_or(n19, n18);
  y[4] = gate_xor(n22, n21);
  auto n4 = gate_nand(n22, n21);
  auto n24 = gate_and(n3, n4);
  y[5] = gate_xor(n24, n23);
}
template<> void $NameUint<6>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n14 = gate_not(a[5]);
  auto n12 = gate_not(y[0]);
  auto n11 = gate_not(a[1]);
  auto n20 = gate_and(n12, n11);
  auto n19 = gate_not(a[2]);
  auto n18 = gate_and(n20, n19);
  auto n17 = gate_not(a[3]);
  auto n16 = gate_and(n18, n17);
  auto n15 = gate_not(a[4]);
  auto n13 = gate_and(n16, n15);
  y[5] = gate_xor(n14, n13);
  y[4] = gate_xor(n16, n15);
  y[3] = gate_xor(n18, n17);
  y[2] = gate_xor(n20, n19);
  y[1] = gate_xor(y[0], a[1]);
}
