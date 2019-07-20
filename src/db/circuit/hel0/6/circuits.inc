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
  auto n17 = gate_and(n15, n14);
  auto n16 = gate_and(b[4], a[4]);
  auto n19 = gate_or(n17, n16);
  auto n18 = gate_xor(a[5], b[5]);
  y[5] = gate_xor(n19, n18);
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
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
  y[2] = gate_mux(c[2], b[2], a[0]);
  y[3] = gate_mux(c[3], b[3], a[0]);
  y[4] = gate_mux(c[4], b[4], a[0]);
  y[5] = gate_mux(c[5], b[5], a[0]);
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
  auto n85 = gate_not(b[5]);
  auto n80 = gate_not(b[4]);
  auto n58 = gate_and(n85, n80);
  auto n113 = gate_not(b[3]);
  auto n41 = gate_and(n58, n113);
  auto n106 = gate_not(b[2]);
  auto n31 = gate_and(n41, n106);
  auto n28 = gate_and(n90, n31);
  auto n34 = gate_not(a[5]);
  auto n10 = gate_nand(b[1], n34);
  auto n11 = gate_nand(b[0], n34);
  y[5] = gate_and(n28, n11);
  auto n29 = gate_not(a[4]);
  auto n7 = gate_nand(b[0], n29);
  auto n30 = gate_and(n10, n7);
  y[4] = gate_and(n31, n30);
  auto n13 = gate_nand(y[4], b[0]);
  auto n42 = gate_and(a[4], n13);
  auto n27 = gate_nand(n42, n90);
  auto n33 = gate_xor(n42, n90);
  auto n46 = gate_not(a[3]);
  auto n44 = gate_and(b[0], n46);
  auto n32 = gate_not(n44);
  auto n26 = gate_nand(n33, n32);
  auto n36 = gate_and(n27, n26);
  auto n35 = gate_and(b[2], n34);
  auto n40 = gate_or(n36, n35);
  auto n38 = gate_not(y[4]);
  auto n37 = gate_not(y[5]);
  auto n39 = gate_and(n38, n37);
  auto n56 = gate_and(a[5], n39);
  auto n20 = gate_nand(n56, n106);
  auto n9 = gate_nand(n40, n20);
  y[3] = gate_and(n41, n9);
  auto n15 = gate_nand(y[3], n44);
  auto n43 = gate_and(y[3], b[1]);
  auto n45 = gate_xor(n43, n42);
  auto n61 = gate_and(n45, n15);
  auto n24 = gate_nand(n106, n61);
  auto n51 = gate_xor(n106, n61);
  auto n47 = gate_and(y[3], b[0]);
  auto n4 = gate_xnor(n47, n46);
  auto n50 = gate_and(n90, n4);
  auto n48 = gate_xor(n90, n4);
  auto n65 = gate_not(a[2]);
  auto n3 = gate_nand(b[0], n65);
  auto n49 = gate_and(n48, n3);
  auto n59 = gate_or(n50, n49);
  auto n25 = gate_nand(n51, n59);
  auto n54 = gate_and(n25, n24);
  auto n52 = gate_not(n56);
  auto n53 = gate_and(b[3], n52);
  auto n57 = gate_or(n54, n53);
  auto n55 = gate_not(y[3]);
  auto n79 = gate_and(n56, n55);
  auto n19 = gate_nand(n79, n113);
  auto n5 = gate_nand(n57, n19);
  y[2] = gate_and(n58, n5);
  auto n60 = gate_xor(n59, n106);
  auto n62 = gate_and(y[2], n60);
  auto n88 = gate_xor(n62, n61);
  auto n22 = gate_nand(n88, n113);
  auto n74 = gate_xor(n88, n113);
  auto n63 = gate_xor(n3, n90);
  auto n64 = gate_and(y[2], n63);
  auto n108 = gate_xor(n64, n4);
  auto n73 = gate_and(n108, n106);
  auto n71 = gate_xor(n106, n108);
  auto n66 = gate_and(y[2], b[0]);
  auto n92 = gate_xor(n66, n65);
  auto n67 = gate_not(n92);
  auto n70 = gate_and(n90, n67);
  auto n68 = gate_xor(n90, n67);
  auto n94 = gate_not(a[1]);
  auto n2 = gate_nand(b[0], n94);
  auto n69 = gate_and(n68, n2);
  auto n105 = gate_or(n70, n69);
  auto n72 = gate_and(n71, n105);
  auto n86 = gate_or(n73, n72);
  auto n23 = gate_nand(n74, n86);
  auto n77 = gate_and(n23, n22);
  auto n75 = gate_not(n79);
  auto n76 = gate_and(b[4], n75);
  auto n81 = gate_or(n77, n76);
  auto n78 = gate_not(y[2]);
  auto n83 = gate_and(n79, n78);
  auto n18 = gate_nand(n83, n80);
  auto n6 = gate_nand(n81, n18);
  y[1] = gate_and(n85, n6);
  auto n82 = gate_not(y[1]);
  auto n84 = gate_and(n83, n82);
  auto n119 = gate_and(n85, n84);
  auto n117 = gate_xor(n85, n84);
  auto n87 = gate_xor(n86, n113);
  auto n89 = gate_and(n87, y[1]);
  auto n21 = gate_xnor(n89, n88);
  auto n12 = gate_nand(b[4], n21);
  auto n115 = gate_xor(b[4], n21);
  auto n91 = gate_xor(n90, n2);
  auto n93 = gate_and(n91, y[1]);
  auto n104 = gate_xor(n93, n92);
  auto n16 = gate_nand(b[2], n104);
  auto n103 = gate_xor(b[2], n104);
  auto n95 = gate_and(y[1], b[0]);
  auto n96 = gate_xor(n95, n94);
  auto n101 = gate_and(n96, b[1]);
  auto n99 = gate_xor(n96, b[1]);
  auto n97 = gate_not(a[0]);
  auto n98 = gate_and(b[0], n97);
  auto n100 = gate_and(n99, n98);
  auto n102 = gate_or(n101, n100);
  auto n17 = gate_nand(n103, n102);
  auto n112 = gate_and(n17, n16);
  auto n1 = gate_nand(n113, n112);
  auto n111 = gate_xor(n113, n112);
  auto n107 = gate_xor(n106, n105);
  auto n109 = gate_and(n107, y[1]);
  auto n110 = gate_xor(n109, n108);
  auto n14 = gate_nand(n111, n110);
  auto n114 = gate_and(n14, n1);
  auto n8 = gate_nand(n115, n114);
  auto n116 = gate_and(n8, n12);
  auto n118 = gate_and(n117, n116);
  y[0] = gate_or(n119, n118);
}
template<> void $NameUint<6>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_nand(a[0], b[0]);
  auto n162 = gate_xor(a[5], b[5]);
  auto n46 = gate_not(b[5]);
  auto n88 = gate_xor(b[3], n46);
  auto n133 = gate_not(n88);
  auto n36 = gate_not(a[1]);
  auto n35 = gate_not(a[0]);
  auto n80 = gate_and(n36, n35);
  auto n37 = gate_not(a[2]);
  auto n59 = gate_and(n80, n37);
  auto n38 = gate_not(a[3]);
  auto n47 = gate_and(n59, n38);
  auto n39 = gate_not(a[4]);
  auto n40 = gate_and(n47, n39);
  auto n67 = gate_and(a[5], n40);
  auto n99 = gate_xor(b[1], n46);
  auto n126 = gate_xor(b[2], n46);
  auto n42 = gate_and(b[0], n126);
  auto n135 = gate_xor(b[4], n46);
  auto n71 = gate_and(n135, n88);
  auto n41 = gate_and(n67, n71);
  auto n43 = gate_and(n42, n41);
  auto n146 = gate_and(n99, n43);
  auto n44 = gate_not(n146);
  auto n56 = gate_and(n67, n44);
  auto n158 = gate_and(n71, n126);
  auto n45 = gate_not(b[0]);
  auto n157 = gate_and(n46, n45);
  auto n117 = gate_not(n157);
  auto n48 = gate_not(n47);
  auto n49 = gate_and(n48, a[5]);
  auto n57 = gate_xor(n49, a[4]);
  auto n33 = gate_nand(n57, b[0]);
  auto n51 = gate_and(n117, n33);
  auto n50 = gate_not(n56);
  auto n6 = gate_nand(n51, n50);
  auto n54 = gate_and(n99, n6);
  auto n52 = gate_not(n51);
  auto n53 = gate_and(n52, n67);
  auto n55 = gate_or(n54, n53);
  auto n145 = gate_and(n158, n55);
  auto n58 = gate_not(n145);
  auto n72 = gate_and(n56, n58);
  auto n66 = gate_and(n126, n72);
  auto n121 = gate_not(n99);
  auto n75 = gate_and(n58, n57);
  auto n64 = gate_not(n75);
  auto n5 = gate_nand(n121, n64);
  auto n63 = gate_xor(n121, n64);
  auto n60 = gate_not(n59);
  auto n61 = gate_and(n60, a[5]);
  auto n78 = gate_xor(n61, a[3]);
  auto n32 = gate_nand(n78, b[0]);
  auto n62 = gate_and(n117, n32);
  auto n7 = gate_nand(n63, n62);
  auto n65 = gate_and(n7, n5);
  auto n69 = gate_or(n66, n65);
  auto n77 = gate_not(n126);
  auto n68 = gate_not(n67);
  auto n16 = gate_nand(n77, n68);
  auto n70 = gate_and(n69, n16);
  auto n144 = gate_and(n71, n70);
  auto n74 = gate_not(n144);
  auto n92 = gate_and(n72, n74);
  auto n73 = gate_not(n72);
  auto n13 = gate_nand(n133, n73);
  auto n107 = gate_and(n75, n74);
  auto n76 = gate_not(n107);
  auto n1 = gate_nand(n77, n76);
  auto n87 = gate_and(n13, n1);
  auto n86 = gate_xor(n77, n76);
  auto n79 = gate_and(n144, b[0]);
  auto n96 = gate_xor(n79, n78);
  auto n31 = gate_nand(n99, n96);
  auto n84 = gate_xor(n99, n96);
  auto n81 = gate_not(n80);
  auto n82 = gate_and(n81, a[5]);
  auto n97 = gate_xor(n82, a[2]);
  auto n26 = gate_nand(n97, b[0]);
  auto n93 = gate_and(n117, n26);
  auto n83 = gate_not(n93);
  auto n30 = gate_nand(n84, n83);
  auto n85 = gate_and(n31, n30);
  auto n10 = gate_nand(n86, n85);
  auto n90 = gate_and(n87, n10);
  auto n89 = gate_and(n92, n88);
  auto n91 = gate_or(n90, n89);
  auto n143 = gate_and(n91, n135);
  auto n106 = gate_not(n143);
  auto n139 = gate_and(n92, n106);
  auto n94 = gate_xor(n93, n121);
  auto n95 = gate_and(n94, n143);
  auto n129 = gate_xor(n96, n95);
  auto n29 = gate_nand(n129, n126);
  auto n105 = gate_xor(n129, n126);
  auto n98 = gate_and(n143, b[0]);
  auto n115 = gate_xor(n98, n97);
  auto n104 = gate_and(n99, n115);
  auto n102 = gate_xor(n99, n115);
  auto n100 = gate_and(a[0], a[5]);
  auto n118 = gate_xor(n100, a[1]);
  auto n23 = gate_nand(b[0], n118);
  auto n113 = gate_and(n117, n23);
  auto n101 = gate_not(n113);
  auto n103 = gate_and(n102, n101);
  auto n127 = gate_or(n104, n103);
  auto n28 = gate_nand(n105, n127);
  auto n110 = gate_and(n29, n28);
  auto n18 = gate_nand(n133, n110);
  auto n109 = gate_xor(n133, n110);
  auto n134 = gate_and(n107, n106);
  auto n108 = gate_not(n134);
  auto n19 = gate_nand(n109, n108);
  auto n112 = gate_and(n19, n18);
  auto n4 = gate_nand(n139, n112);
  auto n111 = gate_xor(n139, n112);
  auto n21 = gate_nand(n111, n135);
  auto n140 = gate_and(n21, n4);
  auto n2 = gate_nand(n140, n139);
  auto n142 = gate_not(n140);
  auto n114 = gate_xor(n121, n113);
  auto n116 = gate_and(n142, n114);
  auto n125 = gate_xor(n116, n115);
  auto n122 = gate_and(n117, n17);
  auto n9 = gate_nand(n122, n121);
  auto n120 = gate_xor(n122, n121);
  auto n119 = gate_and(n142, b[0]);
  auto n22 = gate_xnor(n119, n118);
  auto n11 = gate_nand(n120, n22);
  auto n124 = gate_and(n11, n9);
  auto n24 = gate_nand(n125, n124);
  auto n123 = gate_xor(n125, n124);
  auto n25 = gate_nand(n123, n126);
  auto n132 = gate_and(n25, n24);
  auto n12 = gate_nand(n133, n132);
  auto n131 = gate_xor(n133, n132);
  auto n128 = gate_xor(n127, n126);
  auto n130 = gate_and(n142, n128);
  auto n27 = gate_xnor(n130, n129);
  auto n14 = gate_nand(n131, n27);
  auto n138 = gate_and(n14, n12);
  auto n137 = gate_and(n134, n140);
  auto n3 = gate_nand(n138, n137);
  auto n136 = gate_xor(n138, n137);
  auto n20 = gate_nand(n136, n135);
  auto n141 = gate_and(n20, n3);
  auto n161 = gate_and(n141, n2);
  auto n156 = gate_and(n162, n161);
  auto n155 = gate_xor(n162, n142);
  auto n154 = gate_and(n156, n155);
  auto n153 = gate_xor(n162, n143);
  auto n152 = gate_and(n154, n153);
  auto n151 = gate_xor(n162, n144);
  auto n150 = gate_and(n152, n151);
  auto n149 = gate_xor(n162, n145);
  auto n148 = gate_and(n150, n149);
  auto n147 = gate_xor(n162, n146);
  y[5] = gate_xor(n148, n147);
  y[4] = gate_xor(n150, n149);
  y[3] = gate_xor(n152, n151);
  y[2] = gate_xor(n154, n153);
  y[1] = gate_xor(n156, n155);
  auto n164 = gate_not(n156);
  auto n160 = gate_not(b[1]);
  auto n159 = gate_and(n158, n157);
  auto n8 = gate_nand(n160, n159);
  auto n34 = gate_nand(n162, n8);
  auto n163 = gate_xor(n162, n161);
  auto n15 = gate_nand(n34, n163);
  y[0] = gate_and(n164, n15);
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
  auto n58 = gate_not(b[4]);
  auto n42 = gate_nand(a[4], n58);
  auto n57 = gate_xor(a[4], n58);
  auto n46 = gate_not(a[0]);
  auto n49 = gate_and(b[0], n46);
  auto n39 = gate_nand(n49, b[1]);
  auto n48 = gate_xor(n49, b[1]);
  auto n47 = gate_not(a[1]);
  auto n36 = gate_nand(n48, n47);
  auto n52 = gate_and(n36, n39);
  auto n44 = gate_nand(a[2], n52);
  auto n51 = gate_xor(a[2], n52);
  auto n50 = gate_not(b[2]);
  auto n45 = gate_nand(n51, n50);
  auto n55 = gate_and(n45, n44);
  auto n40 = gate_nand(b[3], n55);
  auto n54 = gate_xor(b[3], n55);
  auto n53 = gate_not(a[3]);
  auto n37 = gate_nand(n54, n53);
  auto n56 = gate_and(n37, n40);
  auto n43 = gate_nand(n57, n56);
  auto n61 = gate_and(n43, n42);
  auto n41 = gate_nand(b[5], n61);
  auto n60 = gate_xor(b[5], n61);
  auto n59 = gate_not(a[5]);
  auto n38 = gate_nand(n60, n59);
  y[0] = gate_and(n38, n41);
}
template<> void $NameUint<6>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(b[4]);
  auto n40 = gate_nand(a[4], n58);
  auto n57 = gate_xor(a[4], n58);
  auto n46 = gate_not(a[0]);
  auto n49 = gate_and(b[0], n46);
  auto n37 = gate_nand(n49, b[1]);
  auto n48 = gate_xor(n49, b[1]);
  auto n47 = gate_not(a[1]);
  auto n36 = gate_nand(n48, n47);
  auto n52 = gate_and(n36, n37);
  auto n44 = gate_nand(a[2], n52);
  auto n51 = gate_xor(a[2], n52);
  auto n50 = gate_not(b[2]);
  auto n45 = gate_nand(n51, n50);
  auto n55 = gate_and(n45, n44);
  auto n38 = gate_nand(b[3], n55);
  auto n54 = gate_xor(b[3], n55);
  auto n53 = gate_not(a[3]);
  auto n39 = gate_nand(n54, n53);
  auto n56 = gate_and(n39, n38);
  auto n41 = gate_nand(n57, n56);
  auto n61 = gate_and(n41, n40);
  auto n42 = gate_nand(a[5], n61);
  auto n60 = gate_xor(a[5], n61);
  auto n59 = gate_not(b[5]);
  auto n43 = gate_nand(n60, n59);
  y[0] = gate_and(n43, n42);
}
template<> void $NameUint<6>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n57 = gate_not(b[4]);
  auto n39 = gate_nand(a[4], n57);
  auto n56 = gate_xor(a[4], n57);
  auto n51 = gate_not(b[2]);
  auto n41 = gate_nand(a[2], n51);
  auto n50 = gate_xor(a[2], n51);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_and(a[0], n43);
  auto n48 = gate_and(n44, a[1]);
  auto n46 = gate_xor(n44, a[1]);
  auto n45 = gate_not(b[1]);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n42 = gate_nand(n50, n49);
  auto n54 = gate_and(n42, n41);
  auto n38 = gate_nand(b[3], n54);
  auto n53 = gate_xor(b[3], n54);
  auto n52 = gate_not(a[3]);
  auto n35 = gate_nand(n53, n52);
  auto n55 = gate_and(n35, n38);
  auto n40 = gate_nand(n56, n55);
  auto n60 = gate_and(n40, n39);
  auto n37 = gate_nand(b[5], n60);
  auto n59 = gate_xor(b[5], n60);
  auto n58 = gate_not(a[5]);
  auto n36 = gate_nand(n59, n58);
  y[0] = gate_and(n36, n37);
}
template<> void $NameUint<6>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n57 = gate_not(b[4]);
  auto n37 = gate_nand(a[4], n57);
  auto n56 = gate_xor(a[4], n57);
  auto n51 = gate_not(b[2]);
  auto n39 = gate_nand(a[2], n51);
  auto n50 = gate_xor(a[2], n51);
  auto n43 = gate_not(b[0]);
  auto n44 = gate_and(a[0], n43);
  auto n48 = gate_and(n44, a[1]);
  auto n46 = gate_xor(n44, a[1]);
  auto n45 = gate_not(b[1]);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n40 = gate_nand(n50, n49);
  auto n54 = gate_and(n40, n39);
  auto n36 = gate_nand(b[3], n54);
  auto n53 = gate_xor(b[3], n54);
  auto n52 = gate_not(a[3]);
  auto n35 = gate_nand(n53, n52);
  auto n55 = gate_and(n35, n36);
  auto n38 = gate_nand(n56, n55);
  auto n60 = gate_and(n38, n37);
  auto n41 = gate_nand(a[5], n60);
  auto n59 = gate_xor(a[5], n60);
  auto n58 = gate_not(b[5]);
  auto n42 = gate_nand(n59, n58);
  y[0] = gate_and(n42, n41);
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
  auto n22 = gate_and(n21, n20);
  y[0] = gate_mux(b[0], c[0], n22);
  y[1] = gate_mux(b[1], c[1], n22);
  y[2] = gate_mux(b[2], c[2], n22);
  y[3] = gate_mux(b[3], c[3], n22);
  y[4] = gate_mux(b[4], c[4], n22);
  y[5] = gate_mux(b[5], c[5], n22);
}
template<> void $NameUint<6>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(a[4]);
  auto n39 = gate_nand(b[4], n58);
  auto n57 = gate_xor(b[4], n58);
  auto n46 = gate_not(b[0]);
  auto n49 = gate_and(a[0], n46);
  auto n40 = gate_nand(n49, a[1]);
  auto n48 = gate_xor(n49, a[1]);
  auto n47 = gate_not(b[1]);
  auto n41 = gate_nand(n48, n47);
  auto n52 = gate_and(n41, n40);
  auto n38 = gate_nand(b[2], n52);
  auto n51 = gate_xor(b[2], n52);
  auto n50 = gate_not(a[2]);
  auto n36 = gate_nand(n51, n50);
  auto n55 = gate_and(n36, n38);
  auto n42 = gate_nand(a[3], n55);
  auto n54 = gate_xor(a[3], n55);
  auto n53 = gate_not(b[3]);
  auto n43 = gate_nand(n54, n53);
  auto n56 = gate_and(n43, n42);
  auto n37 = gate_nand(n57, n56);
  auto n61 = gate_and(n37, n39);
  auto n44 = gate_nand(a[5], n61);
  auto n60 = gate_xor(a[5], n61);
  auto n59 = gate_not(b[5]);
  auto n45 = gate_nand(n60, n59);
  y[0] = gate_and(n45, n44);
}
template<> void $NameUint<6>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n58 = gate_not(a[4]);
  auto n37 = gate_nand(b[4], n58);
  auto n57 = gate_xor(b[4], n58);
  auto n46 = gate_not(b[0]);
  auto n49 = gate_and(a[0], n46);
  auto n42 = gate_nand(n49, a[1]);
  auto n48 = gate_xor(n49, a[1]);
  auto n47 = gate_not(b[1]);
  auto n43 = gate_nand(n48, n47);
  auto n52 = gate_and(n43, n42);
  auto n39 = gate_nand(b[2], n52);
  auto n51 = gate_xor(b[2], n52);
  auto n50 = gate_not(a[2]);
  auto n36 = gate_nand(n51, n50);
  auto n55 = gate_and(n36, n39);
  auto n44 = gate_nand(a[3], n55);
  auto n54 = gate_xor(a[3], n55);
  auto n53 = gate_not(b[3]);
  auto n45 = gate_nand(n54, n53);
  auto n56 = gate_and(n45, n44);
  auto n40 = gate_nand(n57, n56);
  auto n61 = gate_and(n40, n37);
  auto n41 = gate_nand(b[5], n61);
  auto n60 = gate_xor(b[5], n61);
  auto n59 = gate_not(a[5]);
  auto n38 = gate_nand(n60, n59);
  y[0] = gate_and(n38, n41);
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
  auto n26 = gate_nand(n36, n35);
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
  auto n57 = gate_not(a[4]);
  auto n35 = gate_nand(b[4], n57);
  auto n56 = gate_xor(b[4], n57);
  auto n51 = gate_not(a[2]);
  auto n38 = gate_nand(b[2], n51);
  auto n50 = gate_xor(b[2], n51);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_and(b[0], n43);
  auto n48 = gate_and(n44, b[1]);
  auto n46 = gate_xor(n44, b[1]);
  auto n45 = gate_not(a[1]);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n37 = gate_nand(n50, n49);
  auto n54 = gate_and(n37, n38);
  auto n39 = gate_nand(a[3], n54);
  auto n53 = gate_xor(a[3], n54);
  auto n52 = gate_not(b[3]);
  auto n40 = gate_nand(n53, n52);
  auto n55 = gate_and(n40, n39);
  auto n36 = gate_nand(n56, n55);
  auto n60 = gate_and(n36, n35);
  auto n41 = gate_nand(a[5], n60);
  auto n59 = gate_xor(a[5], n60);
  auto n58 = gate_not(b[5]);
  auto n42 = gate_nand(n59, n58);
  y[0] = gate_and(n42, n41);
}
template<> void $NameUint<6>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n57 = gate_not(a[4]);
  auto n40 = gate_nand(b[4], n57);
  auto n56 = gate_xor(b[4], n57);
  auto n51 = gate_not(a[2]);
  auto n35 = gate_nand(b[2], n51);
  auto n50 = gate_xor(b[2], n51);
  auto n43 = gate_not(a[0]);
  auto n44 = gate_and(b[0], n43);
  auto n48 = gate_and(n44, b[1]);
  auto n46 = gate_xor(n44, b[1]);
  auto n45 = gate_not(a[1]);
  auto n47 = gate_and(n46, n45);
  auto n49 = gate_or(n48, n47);
  auto n38 = gate_nand(n50, n49);
  auto n54 = gate_and(n38, n35);
  auto n41 = gate_nand(a[3], n54);
  auto n53 = gate_xor(a[3], n54);
  auto n52 = gate_not(b[3]);
  auto n42 = gate_nand(n53, n52);
  auto n55 = gate_and(n42, n41);
  auto n36 = gate_nand(n56, n55);
  auto n60 = gate_and(n36, n40);
  auto n39 = gate_nand(b[5], n60);
  auto n59 = gate_xor(b[5], n60);
  auto n58 = gate_not(a[5]);
  auto n37 = gate_nand(n59, n58);
  y[0] = gate_and(n37, n39);
}
template<> void $NameUint<6>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n99 = gate_not(b[1]);
  auto n117 = gate_not(b[5]);
  auto n121 = gate_not(b[4]);
  auto n82 = gate_and(n117, n121);
  auto n126 = gate_not(b[3]);
  auto n32 = gate_and(n82, n126);
  auto n131 = gate_not(b[2]);
  auto n15 = gate_and(n32, n131);
  auto n12 = gate_and(n15, b[0]);
  auto n16 = gate_and(n99, n12);
  auto n13 = gate_not(n16);
  auto n21 = gate_and(a[5], n13);
  auto n14 = gate_xor(n99, a[5]);
  auto n17 = gate_and(n15, n14);
  auto n19 = gate_or(n17, n16);
  auto n18 = gate_not(a[4]);
  auto n3 = gate_nand(b[0], n18);
  auto n22 = gate_and(n19, n3);
  auto n5 = gate_nand(n22, b[0]);
  auto n20 = gate_not(n22);
  auto n34 = gate_and(n21, n20);
  auto n30 = gate_and(n34, n131);
  auto n35 = gate_and(a[4], n5);
  auto n27 = gate_and(n35, n99);
  auto n25 = gate_xor(n35, n99);
  auto n23 = gate_not(a[3]);
  auto n37 = gate_and(b[0], n23);
  auto n24 = gate_not(n37);
  auto n26 = gate_and(n25, n24);
  auto n33 = gate_or(n27, n26);
  auto n1 = gate_nand(n33, n131);
  auto n28 = gate_not(a[5]);
  auto n2 = gate_nand(b[2], n28);
  auto n29 = gate_and(n33, n2);
  auto n31 = gate_or(n30, n29);
  auto n39 = gate_and(n32, n31);
  auto n6 = gate_nand(n39, n37);
  auto n11 = gate_nand(n39, n1);
  auto n50 = gate_and(n34, n11);
  auto n36 = gate_and(n39, b[1]);
  auto n38 = gate_xor(n36, n35);
  auto n58 = gate_and(n38, n6);
  auto n48 = gate_and(n131, n58);
  auto n46 = gate_xor(n131, n58);
  auto n40 = gate_and(n39, b[0]);
  auto n62 = gate_xor(n40, a[3]);
  auto n45 = gate_and(n99, n62);
  auto n43 = gate_xor(n99, n62);
  auto n41 = gate_not(a[2]);
  auto n60 = gate_and(b[0], n41);
  auto n42 = gate_not(n60);
  auto n44 = gate_and(n43, n42);
  auto n56 = gate_or(n45, n44);
  auto n47 = gate_and(n46, n56);
  auto n51 = gate_or(n48, n47);
  auto n49 = gate_xor(n126, n51);
  auto n10 = gate_nand(n82, n49);
  auto n81 = gate_and(n50, n10);
  auto n54 = gate_and(n126, n50);
  auto n52 = gate_xor(n126, n50);
  auto n53 = gate_and(n52, n51);
  auto n55 = gate_or(n54, n53);
  auto n64 = gate_and(n82, n55);
  auto n57 = gate_xor(n56, n131);
  auto n59 = gate_and(n64, n57);
  auto n87 = gate_xor(n59, n58);
  auto n76 = gate_and(n87, n126);
  auto n74 = gate_xor(n126, n87);
  auto n61 = gate_xor(n60, b[1]);
  auto n63 = gate_and(n64, n61);
  auto n91 = gate_xor(n63, n62);
  auto n73 = gate_and(n91, n131);
  auto n71 = gate_xor(n131, n91);
  auto n65 = gate_and(n64, b[0]);
  auto n95 = gate_xor(n65, a[2]);
  auto n70 = gate_and(n99, n95);
  auto n68 = gate_xor(n99, n95);
  auto n66 = gate_not(a[1]);
  auto n93 = gate_and(b[0], n66);
  auto n67 = gate_not(n93);
  auto n69 = gate_and(n68, n67);
  auto n89 = gate_or(n70, n69);
  auto n72 = gate_and(n71, n89);
  auto n85 = gate_or(n73, n72);
  auto n75 = gate_and(n74, n85);
  auto n79 = gate_or(n76, n75);
  auto n77 = gate_xor(n121, n79);
  auto n9 = gate_nand(n77, n117);
  auto n119 = gate_and(n81, n9);
  auto n116 = gate_and(n119, n117);
  auto n114 = gate_not(n81);
  auto n4 = gate_nand(b[5], n114);
  auto n78 = gate_xor(b[4], n114);
  auto n80 = gate_and(n79, n78);
  auto n84 = gate_and(n80, n117);
  auto n83 = gate_and(n82, n81);
  auto n97 = gate_or(n84, n83);
  auto n86 = gate_xor(n126, n85);
  auto n88 = gate_and(n97, n86);
  auto n123 = gate_xor(n88, n87);
  auto n113 = gate_and(n123, n121);
  auto n111 = gate_xor(n121, n123);
  auto n90 = gate_xor(n131, n89);
  auto n92 = gate_and(n97, n90);
  auto n128 = gate_xor(n92, n91);
  auto n110 = gate_and(n128, n126);
  auto n108 = gate_xor(n126, n128);
  auto n94 = gate_xor(n93, b[1]);
  auto n96 = gate_and(n97, n94);
  auto n133 = gate_xor(n96, n95);
  auto n107 = gate_and(n133, n131);
  auto n105 = gate_xor(n131, n133);
  auto n98 = gate_and(n97, b[0]);
  auto n137 = gate_xor(n98, a[1]);
  auto n104 = gate_and(n99, n137);
  auto n102 = gate_xor(n99, n137);
  auto n100 = gate_not(a[0]);
  auto n135 = gate_and(b[0], n100);
  auto n101 = gate_not(n135);
  auto n103 = gate_and(n102, n101);
  auto n130 = gate_or(n104, n103);
  auto n106 = gate_and(n105, n130);
  auto n125 = gate_or(n107, n106);
  auto n109 = gate_and(n108, n125);
  auto n120 = gate_or(n110, n109);
  auto n112 = gate_and(n111, n120);
  auto n118 = gate_or(n113, n112);
  auto n7 = gate_nand(n118, n117);
  auto n115 = gate_and(n118, n4);
  auto n139 = gate_or(n116, n115);
  auto n8 = gate_nand(n139, n7);
  y[5] = gate_and(n119, n8);
  auto n122 = gate_xor(n121, n120);
  auto n124 = gate_and(n122, n139);
  y[4] = gate_xor(n124, n123);
  auto n127 = gate_xor(n126, n125);
  auto n129 = gate_and(n127, n139);
  y[3] = gate_xor(n129, n128);
  auto n132 = gate_xor(n131, n130);
  auto n134 = gate_and(n132, n139);
  y[2] = gate_xor(n134, n133);
  auto n136 = gate_xor(n135, b[1]);
  auto n138 = gate_and(n136, n139);
  y[1] = gate_xor(n138, n137);
  auto n140 = gate_and(n139, b[0]);
  y[0] = gate_xor(n140, a[0]);
}
template<> void $NameUint<6>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_nand(a[0], b[0]);
  auto n29 = gate_not(a[1]);
  auto n28 = gate_not(a[0]);
  auto n70 = gate_and(n29, n28);
  auto n30 = gate_not(a[2]);
  auto n51 = gate_and(n70, n30);
  auto n31 = gate_not(a[3]);
  auto n37 = gate_and(n51, n31);
  auto n42 = gate_not(b[5]);
  auto n128 = gate_xor(b[1], n42);
  auto n157 = gate_xor(b[3], n42);
  auto n117 = gate_xor(b[4], n42);
  auto n84 = gate_and(n157, n117);
  auto n88 = gate_xor(b[5], b[2]);
  auto n142 = gate_not(n88);
  auto n61 = gate_and(n84, n142);
  auto n32 = gate_and(b[0], n61);
  auto n33 = gate_and(n128, n32);
  auto n34 = gate_not(n33);
  auto n35 = gate_and(n37, n34);
  auto n39 = gate_not(a[4]);
  auto n36 = gate_and(n35, n39);
  auto n46 = gate_and(a[5], n36);
  auto n43 = gate_xor(n128, n46);
  auto n38 = gate_not(n37);
  auto n40 = gate_and(n38, a[5]);
  auto n47 = gate_xor(n40, n39);
  auto n41 = gate_not(b[0]);
  auto n2 = gate_nand(n42, n41);
  auto n26 = gate_nand(n47, n2);
  auto n44 = gate_and(n43, n26);
  auto n48 = gate_and(n61, n44);
  auto n27 = gate_nand(n48, b[0]);
  auto n45 = gate_not(n48);
  auto n58 = gate_and(n46, n45);
  auto n49 = gate_not(n47);
  auto n62 = gate_and(n49, n27);
  auto n50 = gate_and(n62, n128);
  auto n56 = gate_not(n50);
  auto n55 = gate_xor(n62, n128);
  auto n52 = gate_not(n51);
  auto n53 = gate_and(n52, a[5]);
  auto n67 = gate_xor(n53, a[3]);
  auto n25 = gate_nand(n67, b[0]);
  auto n64 = gate_and(n2, n25);
  auto n54 = gate_not(n64);
  auto n7 = gate_nand(n55, n54);
  auto n59 = gate_and(n56, n7);
  auto n57 = gate_xor(n88, n59);
  auto n17 = gate_nand(n84, n57);
  auto n83 = gate_and(n58, n17);
  auto n60 = gate_not(n58);
  auto n1 = gate_nand(n60, n59);
  auto n66 = gate_and(n61, n1);
  auto n6 = gate_nand(n66, n64);
  auto n149 = gate_not(n128);
  auto n63 = gate_and(n66, n149);
  auto n65 = gate_xor(n63, n62);
  auto n89 = gate_and(n65, n6);
  auto n79 = gate_and(n142, n89);
  auto n77 = gate_xor(n142, n89);
  auto n68 = gate_and(n66, b[0]);
  auto n94 = gate_xor(n68, n67);
  auto n69 = gate_and(n94, n128);
  auto n75 = gate_not(n69);
  auto n74 = gate_xor(n94, n128);
  auto n71 = gate_not(n70);
  auto n72 = gate_and(n71, a[5]);
  auto n97 = gate_xor(n72, a[2]);
  auto n19 = gate_nand(n97, b[0]);
  auto n92 = gate_and(n2, n19);
  auto n73 = gate_not(n92);
  auto n24 = gate_nand(n74, n73);
  auto n87 = gate_and(n75, n24);
  auto n76 = gate_not(n87);
  auto n78 = gate_and(n77, n76);
  auto n81 = gate_or(n79, n78);
  auto n80 = gate_xor(n81, n157);
  auto n5 = gate_nand(n117, n80);
  auto n110 = gate_and(n83, n5);
  auto n12 = gate_nand(n110, n117);
  auto n82 = gate_and(n157, n81);
  auto n86 = gate_and(n82, n117);
  auto n85 = gate_and(n84, n83);
  auto n96 = gate_or(n86, n85);
  auto n10 = gate_nand(n96, n87);
  auto n90 = gate_and(n96, n88);
  auto n91 = gate_xor(n90, n89);
  auto n114 = gate_and(n10, n91);
  auto n108 = gate_and(n114, n157);
  auto n106 = gate_xor(n157, n114);
  auto n93 = gate_xor(n149, n92);
  auto n95 = gate_and(n96, n93);
  auto n120 = gate_xor(n95, n94);
  auto n23 = gate_nand(n120, n142);
  auto n104 = gate_xor(n120, n142);
  auto n98 = gate_and(n96, b[0]);
  auto n124 = gate_xor(n98, n97);
  auto n103 = gate_and(n124, n128);
  auto n101 = gate_xor(n124, n128);
  auto n99 = gate_and(a[5], a[0]);
  auto n126 = gate_xor(a[1], n99);
  auto n18 = gate_nand(n126, b[0]);
  auto n122 = gate_and(n2, n18);
  auto n100 = gate_not(n122);
  auto n102 = gate_and(n101, n100);
  auto n118 = gate_or(n103, n102);
  auto n22 = gate_nand(n104, n118);
  auto n112 = gate_and(n23, n22);
  auto n105 = gate_not(n112);
  auto n107 = gate_and(n106, n105);
  auto n111 = gate_or(n108, n107);
  auto n15 = gate_nand(n111, n117);
  auto n4 = gate_nand(n12, n15);
  auto n9 = gate_nand(n4, n112);
  auto n163 = gate_not(n117);
  auto n109 = gate_xor(n111, n163);
  auto n16 = gate_nand(n110, n109);
  auto n113 = gate_not(n157);
  auto n115 = gate_and(n4, n113);
  auto n116 = gate_xor(n115, n114);
  auto n164 = gate_and(n9, n116);
  auto n14 = gate_nand(n164, n117);
  auto n138 = gate_xor(n117, n164);
  auto n119 = gate_xor(n142, n118);
  auto n121 = gate_and(n4, n119);
  auto n159 = gate_xor(n121, n120);
  auto n21 = gate_nand(n159, n157);
  auto n136 = gate_xor(n157, n159);
  auto n123 = gate_xor(n149, n122);
  auto n125 = gate_and(n4, n123);
  auto n144 = gate_xor(n125, n124);
  auto n135 = gate_and(n144, n142);
  auto n133 = gate_xor(n144, n142);
  auto n127 = gate_and(n4, b[0]);
  auto n152 = gate_xor(n127, n126);
  auto n132 = gate_and(n152, n128);
  auto n130 = gate_xor(n152, n128);
  auto n150 = gate_and(n2, n8);
  auto n129 = gate_not(n150);
  auto n131 = gate_and(n130, n129);
  auto n141 = gate_or(n132, n131);
  auto n134 = gate_and(n133, n141);
  auto n156 = gate_or(n135, n134);
  auto n20 = gate_nand(n136, n156);
  auto n162 = gate_and(n21, n20);
  auto n137 = gate_not(n162);
  auto n13 = gate_nand(n138, n137);
  auto n140 = gate_and(n14, n13);
  auto n3 = gate_nand(n140, n16);
  auto n11 = gate_nand(n3, n162);
  auto n139 = gate_or(n16, n140);
  auto n169 = gate_and(a[5], n139);
  auto n143 = gate_xor(n142, n141);
  auto n145 = gate_and(n3, n143);
  auto n146 = gate_xor(n145, n144);
  auto n175 = gate_xor(a[5], n146);
  auto n148 = gate_and(b[0], n3);
  auto n147 = gate_xor(a[0], a[5]);
  auto n179 = gate_xor(n148, n147);
  y[0] = gate_xor(a[5], n179);
  auto n155 = gate_and(a[5], n179);
  auto n151 = gate_xor(n150, n149);
  auto n153 = gate_and(n151, n3);
  auto n177 = gate_xor(n153, n152);
  auto n154 = gate_not(n177);
  auto n174 = gate_and(n155, n154);
  auto n173 = gate_and(n175, n174);
  auto n158 = gate_xor(n157, n156);
  auto n160 = gate_and(n3, n158);
  auto n161 = gate_xor(n160, n159);
  auto n172 = gate_xor(a[5], n161);
  auto n171 = gate_and(n173, n172);
  auto n165 = gate_and(n3, n163);
  auto n166 = gate_xor(n165, n164);
  auto n167 = gate_and(n11, n166);
  auto n170 = gate_xor(a[5], n167);
  auto n168 = gate_and(n171, n170);
  y[5] = gate_xor(n169, n168);
  y[4] = gate_xor(n171, n170);
  y[3] = gate_xor(n173, n172);
  y[2] = gate_xor(n175, n174);
  auto n176 = gate_not(n179);
  auto n178 = gate_and(n176, a[5]);
  y[1] = gate_xor(n178, n177);
}
template<> void $NameUint<6>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n14 = gate_and(a[1], b[0]);
  auto n13 = gate_and(a[0], b[1]);
  y[1] = gate_xor(n14, n13);
  auto n31 = gate_and(a[1], b[1]);
  auto n33 = gate_and(a[0], b[2]);
  auto n10 = gate_nand(n31, n33);
  auto n19 = gate_xor(n31, n33);
  auto n18 = gate_and(b[0], a[2]);
  auto n21 = gate_xor(n19, n18);
  auto n20 = gate_and(n14, n13);
  y[2] = gate_xor(n21, n20);
  auto n15 = gate_and(b[2], n10);
  auto n17 = gate_and(n15, a[1]);
  auto n16 = gate_and(a[0], b[3]);
  auto n26 = gate_xor(n17, n16);
  auto n30 = gate_and(a[3], b[0]);
  auto n29 = gate_and(b[1], a[2]);
  auto n25 = gate_xor(n30, n29);
  auto n5 = gate_nand(n26, n25);
  auto n28 = gate_xor(n26, n25);
  auto n23 = gate_and(n19, n18);
  auto n22 = gate_and(n21, n20);
  auto n27 = gate_or(n23, n22);
  auto n6 = gate_nand(n28, n27);
  y[3] = gate_xor(n28, n27);
  auto n41 = gate_and(b[3], a[1]);
  auto n44 = gate_not(n41);
  auto n45 = gate_and(a[0], b[4]);
  auto n42 = gate_and(b[2], a[2]);
  auto n11 = gate_nand(n41, n42);
  auto n24 = gate_xor(n45, n42);
  auto n37 = gate_xor(n44, n24);
  auto n38 = gate_and(n5, n6);
  auto n12 = gate_nand(n38, n37);
  auto n57 = gate_and(n30, n29);
  auto n55 = gate_and(b[1], a[3]);
  auto n54 = gate_and(b[0], a[4]);
  auto n60 = gate_xor(n55, n54);
  auto n32 = gate_not(n31);
  auto n2 = gate_nand(n32, n44);
  auto n59 = gate_and(n33, n2);
  auto n7 = gate_nand(n60, n59);
  auto n56 = gate_xor(n60, n59);
  auto n8 = gate_nand(n57, n56);
  auto n39 = gate_xor(n57, n56);
  auto n9 = gate_nand(n39, n12);
  auto n34 = gate_xor(n38, n39);
  y[4] = gate_xor(n37, n34);
  auto n36 = gate_and(b[4], a[1]);
  auto n35 = gate_and(b[5], a[0]);
  auto n53 = gate_xor(n36, n35);
  auto n40 = gate_or(n37, n38);
  auto n51 = gate_and(n40, n9);
  auto n43 = gate_not(n42);
  auto n3 = gate_nand(n44, n43);
  auto n4 = gate_nand(n45, n3);
  auto n49 = gate_and(n11, n4);
  auto n47 = gate_and(a[5], b[0]);
  auto n46 = gate_and(a[4], b[1]);
  auto n48 = gate_xor(n47, n46);
  auto n50 = gate_xor(n49, n48);
  auto n52 = gate_xor(n51, n50);
  auto n67 = gate_xor(n53, n52);
  auto n58 = gate_and(n55, n54);
  auto n61 = gate_xor(n58, n8);
  auto n65 = gate_and(n61, n7);
  auto n63 = gate_and(a[3], b[2]);
  auto n62 = gate_and(a[2], b[3]);
  auto n64 = gate_xor(n63, n62);
  auto n66 = gate_xor(n65, n64);
  y[5] = gate_xnor(n67, n66);
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
  auto n21 = gate_not(a[0]);
  auto n13 = gate_not(a[1]);
  auto n18 = gate_and(n14, n13);
  auto n16 = gate_not(a[2]);
  auto n15 = gate_not(a[5]);
  auto n17 = gate_and(n16, n15);
  auto n20 = gate_and(n18, n17);
  auto n19 = gate_not(a[4]);
  auto n22 = gate_and(n20, n19);
  y[0] = gate_nand(n22, n21);
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
  auto n25 = gate_not(b[3]);
  auto n24 = gate_not(b[4]);
  auto n27 = gate_and(n25, n24);
  auto n26 = gate_not(b[5]);
  auto n38 = gate_and(n27, n26);
  auto n28 = gate_mux(a[5], a[3], b[1]);
  auto n32 = gate_mux(a[4], a[2], b[1]);
  auto n30 = gate_mux(n28, n32, b[0]);
  auto n41 = gate_not(b[1]);
  auto n29 = gate_mux(a[1], a[0], b[0]);
  auto n45 = gate_and(n41, n29);
  auto n31 = gate_mux(n30, n45, b[2]);
  y[5] = gate_and(n38, n31);
  auto n39 = gate_mux(a[3], a[1], b[1]);
  auto n35 = gate_mux(n32, n39, b[0]);
  auto n33 = gate_not(b[0]);
  auto n34 = gate_and(a[0], n33);
  auto n47 = gate_and(n34, n41);
  auto n36 = gate_mux(n35, n47, b[2]);
  y[4] = gate_and(n38, n36);
  auto n37 = gate_not(b[2]);
  auto n46 = gate_and(n38, n37);
  auto n43 = gate_mux(a[2], a[0], b[1]);
  auto n40 = gate_mux(n39, n43, b[0]);
  y[3] = gate_and(n46, n40);
  auto n42 = gate_and(a[1], n41);
  auto n44 = gate_mux(n43, n42, b[0]);
  y[2] = gate_and(n46, n44);
  y[1] = gate_and(n45, n46);
  y[0] = gate_and(n47, n46);
}
template<> void $NameUint<6>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[0]);
  auto n25 = gate_and(a[5], n24);
  auto n32 = gate_not(b[1]);
  auto n39 = gate_and(n25, n32);
  auto n27 = gate_not(b[3]);
  auto n26 = gate_not(b[4]);
  auto n29 = gate_and(n27, n26);
  auto n28 = gate_not(b[5]);
  auto n47 = gate_and(n29, n28);
  auto n30 = gate_not(b[2]);
  auto n37 = gate_and(n47, n30);
  y[5] = gate_and(n39, n37);
  auto n31 = gate_mux(a[4], a[5], b[0]);
  auto n44 = gate_and(n32, n31);
  y[4] = gate_and(n44, n37);
  auto n35 = gate_mux(a[3], a[5], b[1]);
  auto n33 = gate_and(a[4], n32);
  auto n34 = gate_mux(n35, n33, b[0]);
  y[3] = gate_and(n37, n34);
  auto n38 = gate_mux(a[2], a[4], b[1]);
  auto n36 = gate_mux(n38, n35, b[0]);
  y[2] = gate_and(n37, n36);
  auto n42 = gate_mux(a[1], a[3], b[1]);
  auto n40 = gate_mux(n42, n38, b[0]);
  auto n41 = gate_mux(n40, n39, b[2]);
  y[1] = gate_and(n47, n41);
  auto n43 = gate_mux(a[0], a[2], b[1]);
  auto n45 = gate_mux(n43, n42, b[0]);
  auto n46 = gate_mux(n45, n44, b[2]);
  y[0] = gate_and(n47, n46);
}
template<> void $NameUint<6>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[5] = gate_buf(a[5]);
  auto n29 = gate_not(b[3]);
  auto n28 = gate_not(b[4]);
  auto n31 = gate_and(n29, n28);
  auto n30 = gate_not(b[5]);
  auto n48 = gate_and(n31, n30);
  auto n32 = gate_not(b[2]);
  auto n52 = gate_and(n48, n32);
  auto n33 = gate_not(n52);
  auto n27 = gate_nand(y[5], n33);
  auto n53 = gate_not(b[0]);
  auto n50 = gate_not(b[1]);
  auto n34 = gate_and(n53, n50);
  auto n47 = gate_mux(y[5], a[4], n34);
  auto n26 = gate_nand(n52, n47);
  y[4] = gate_nand(n27, n26);
  auto n35 = gate_mux(a[4], a[3], n53);
  auto n36 = gate_and(n52, n50);
  y[3] = gate_mux(y[5], n35, n36);
  auto n38 = gate_and(n36, a[3]);
  auto n37 = gate_and(b[1], y[5]);
  auto n40 = gate_or(n38, n37);
  auto n39 = gate_mux(a[4], a[2], n50);
  auto n44 = gate_and(n52, n39);
  auto n41 = gate_mux(n40, n44, n53);
  auto n42 = gate_not(n41);
  y[2] = gate_nand(n27, n42);
  auto n43 = gate_mux(a[3], a[1], n50);
  auto n55 = gate_and(n52, n43);
  auto n45 = gate_mux(n44, n55, n53);
  auto n46 = gate_not(n45);
  y[1] = gate_nand(n27, n46);
  auto n49 = gate_and(b[2], n47);
  auto n57 = gate_mux(y[5], n49, n48);
  auto n51 = gate_mux(a[2], a[0], n50);
  auto n54 = gate_and(n52, n51);
  auto n56 = gate_mux(n55, n54, n53);
  y[0] = gate_or(n57, n56);
}
template<> void $NameUint<6>::d_sub
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
  auto n15 = gate_not(b[3]);
  auto n17 = gate_xor(a[3], n15);
  auto n14 = gate_and(a[2], n10);
  auto n13 = gate_and(n12, n11);
  auto n16 = gate_or(n14, n13);
  y[3] = gate_xor(n17, n16);
  auto n22 = gate_not(b[4]);
  auto n3 = gate_nand(a[4], n22);
  auto n21 = gate_xor(a[4], n22);
  auto n19 = gate_and(a[3], n15);
  auto n18 = gate_and(n17, n16);
  auto n20 = gate_or(n19, n18);
  auto n4 = gate_nand(n21, n20);
  y[4] = gate_xor(n21, n20);
  auto n23 = gate_and(n4, n3);
  auto n24 = gate_xor(n23, b[5]);
  y[5] = gate_xor(a[5], n24);
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
