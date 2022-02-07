// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[1]);
  auto n37 = gate_not(a[1]);
  auto n39 = gate_nand(n38, n37);
  auto n49 = gate_nand(a[1], b[1]);
  auto n40 = gate_nand(n39, n49);
  auto n70 = gate_nand(b[0], a[0]);
  auto n43 = gate_nand(n40, n70);
  auto n42 = gate_not(n70);
  auto n41 = gate_not(n40);
  auto n48 = gate_nand(n42, n41);
  auto n44 = gate_nand(n43, n48);
  y[1] = gate_not(n44);
  auto n46 = gate_not(b[2]);
  auto n45 = gate_not(a[2]);
  auto n47 = gate_nand(n46, n45);
  auto n56 = gate_nand(a[2], b[2]);
  auto n51 = gate_nand(n47, n56);
  auto n52 = gate_nand(n49, n48);
  auto n50 = gate_not(n52);
  auto n54 = gate_nand(n51, n50);
  auto n53 = gate_not(n51);
  auto n57 = gate_nand(n53, n52);
  auto n55 = gate_nand(n54, n57);
  y[2] = gate_not(n55);
  auto n60 = gate_nand(n57, n56);
  auto n59 = gate_not(n60);
  auto n58 = gate_not(b[3]);
  auto n62 = gate_nand(n59, n58);
  auto n61 = gate_nand(b[3], n60);
  auto n65 = gate_nand(n62, n61);
  auto n64 = gate_not(n65);
  auto n63 = gate_not(a[3]);
  auto n67 = gate_nand(n64, n63);
  auto n66 = gate_nand(n65, a[3]);
  y[3] = gate_nand(n67, n66);
  auto n69 = gate_not(a[0]);
  auto n68 = gate_not(b[0]);
  auto n71 = gate_nand(n69, n68);
  auto n72 = gate_nand(n71, n70);
  auto _add_x_1_n48 = gate_not(n72);
  y[0] = gate_buf(_add_x_1_n48);
}
template<> void $NameUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_nand(b[3], a[3]);
  y[3] = gate_not(n5);
  auto n6 = gate_nand(b[2], a[2]);
  y[2] = gate_not(n6);
  auto n7 = gate_nand(b[1], a[1]);
  y[1] = gate_not(n7);
  auto n8 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n8);
}
template<> void $NameUint<4>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[3] = gate_not(a[3]);
  y[2] = gate_not(a[2]);
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<4>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_not(b[3]);
  auto n9 = gate_not(a[3]);
  y[3] = gate_nand(n10, n9);
  auto n12 = gate_not(b[2]);
  auto n11 = gate_not(a[2]);
  y[2] = gate_nand(n12, n11);
  auto n14 = gate_not(b[1]);
  auto n13 = gate_not(a[1]);
  y[1] = gate_nand(n14, n13);
  auto n16 = gate_not(b[0]);
  auto n15 = gate_not(a[0]);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<4>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n23 = gate_nand(a[2], a[3]);
  auto n25 = gate_not(n23);
  auto n35 = gate_nand(N0, a[1]);
  auto n24 = gate_not(n35);
  auto n38 = gate_nand(n25, n24);
  y[2] = gate_not(n38);
  auto n29 = gate_not(a[2]);
  auto n27 = gate_not(N0);
  auto n26 = gate_not(a[1]);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n28, n35);
  auto n32 = gate_nand(n29, n30);
  auto n31 = gate_not(n30);
  auto n34 = gate_nand(n31, a[2]);
  auto n42 = gate_nand(n32, n34);
  auto n33 = gate_not(n42);
  auto n43 = gate_nand(a[3], n33);
  auto n36 = gate_nand(n35, n34);
  auto n37 = gate_not(n36);
  auto n39 = gate_nand(n43, n37);
  auto n40 = gate_nand(n39, n38);
  y[1] = gate_not(n40);
  auto n41 = gate_not(a[3]);
  auto n44 = gate_nand(n42, n41);
  auto n45 = gate_nand(n44, n43);
  y[0] = gate_not(n45);
}
template<> void $NameUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_not(b[3]);
  auto n20 = gate_nand(a[3], n17);
  auto n18 = gate_not(a[3]);
  auto n19 = gate_nand(b[3], n18);
  y[3] = gate_nand(n20, n19);
  auto n21 = gate_not(b[2]);
  auto n24 = gate_nand(a[2], n21);
  auto n22 = gate_not(a[2]);
  auto n23 = gate_nand(b[2], n22);
  y[2] = gate_nand(n24, n23);
  auto n25 = gate_not(b[1]);
  auto n28 = gate_nand(a[1], n25);
  auto n26 = gate_not(a[1]);
  auto n27 = gate_nand(b[1], n26);
  y[1] = gate_nand(n28, n27);
  auto n29 = gate_not(b[0]);
  auto n32 = gate_nand(a[0], n29);
  auto n30 = gate_not(a[0]);
  auto n31 = gate_nand(b[0], n30);
  y[0] = gate_nand(n32, n31);
}
template<> void $NameUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[0], b[0]);
  y[0] = gate_not(n1);
  auto n2 = gate_nand(a[0], b[1]);
  y[1] = gate_not(n2);
  auto n3 = gate_nand(a[0], b[2]);
  y[2] = gate_not(n3);
  auto n4 = gate_nand(a[0], b[3]);
  y[3] = gate_not(n4);
}
template<> void $NameUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n16 = gate_not(a[0]);
  auto n11 = gate_nand(n16, c[0]);
  auto n10 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n11, n10);
  auto n13 = gate_nand(n16, c[1]);
  auto n12 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n13, n12);
  auto n15 = gate_nand(n16, c[2]);
  auto n14 = gate_nand(a[0], b[2]);
  y[2] = gate_nand(n15, n14);
  auto n18 = gate_nand(n16, c[3]);
  auto n17 = gate_nand(a[0], b[3]);
  y[3] = gate_nand(n18, n17);
}
template<> void $NameUint<4>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n49 = gate_nand(a[0], b[0]);
  auto n29 = gate_not(b[1]);
  auto n28 = gate_not(a[1]);
  auto n30 = gate_nand(n29, n28);
  auto n37 = gate_nand(a[1], b[1]);
  auto n31 = gate_nand(n30, n37);
  auto n34 = gate_nand(n49, n31);
  auto n33 = gate_not(n31);
  auto n32 = gate_not(n49);
  auto n36 = gate_nand(n33, n32);
  auto n35 = gate_nand(n34, n36);
  y[1] = gate_not(n35);
  auto n43 = gate_nand(n37, n36);
  auto n41 = gate_not(n43);
  auto n39 = gate_not(a[2]);
  auto n38 = gate_not(b[2]);
  auto n40 = gate_nand(n39, n38);
  auto n53 = gate_nand(b[2], a[2]);
  auto n42 = gate_nand(n40, n53);
  auto n45 = gate_nand(n41, n42);
  auto n44 = gate_not(n42);
  auto n52 = gate_nand(n44, n43);
  auto n46 = gate_nand(n45, n52);
  y[2] = gate_not(n46);
  auto n48 = gate_not(b[0]);
  auto n47 = gate_not(a[0]);
  auto n50 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto _add_x_1_n48 = gate_not(n51);
  y[3] = gate_nand(n53, n52);
  y[0] = gate_buf(_add_x_1_n48);
}
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  auto n12 = gate_not(a[1]);
  auto n21 = gate_nand(y[0], n12);
  auto n14 = gate_not(n21);
  auto n13 = gate_not(a[2]);
  auto n19 = gate_nand(n14, n13);
  auto n18 = gate_nand(a[3], n19);
  auto n16 = gate_not(n19);
  auto n15 = gate_not(a[3]);
  auto n17 = gate_nand(n16, n15);
  y[3] = gate_nand(n18, n17);
  auto n20 = gate_nand(n21, a[2]);
  y[2] = gate_nand(n20, n19);
  auto n22 = gate_nand(a[1], a[0]);
  y[1] = gate_nand(n22, n21);
}
template<> void $NameUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_not(a[3]);
  auto n2 = gate_nand(b[1], n14);
  auto n28 = gate_not(b[3]);
  auto n42 = gate_not(b[2]);
  auto n1 = gate_nand(n28, n42);
  auto n12 = gate_not(n1);
  auto n3 = gate_nand(n2, n12);
  auto n6 = gate_not(n3);
  auto n4 = gate_not(a[2]);
  auto n5 = gate_nand(b[0], n4);
  auto n17 = gate_nand(n6, n5);
  y[2] = gate_not(n17);
  auto n50 = gate_not(a[1]);
  auto n36 = gate_nand(b[0], n50);
  auto n47 = gate_not(b[1]);
  auto n8 = gate_nand(n36, n47);
  auto n7 = gate_nand(y[2], b[0]);
  auto n34 = gate_nand(n7, a[2]);
  auto n11 = gate_nand(n8, n34);
  auto n9 = gate_not(n36);
  auto n10 = gate_nand(n9, b[1]);
  auto n20 = gate_nand(n11, n10);
  auto n13 = gate_nand(n47, n12);
  auto n16 = gate_not(n13);
  auto n15 = gate_nand(n14, b[0]);
  auto n26 = gate_nand(n16, n15);
  auto n18 = gate_nand(n17, n26);
  auto n19 = gate_not(n18);
  auto n32 = gate_nand(a[3], n19);
  auto n25 = gate_nand(n20, n32);
  auto n21 = gate_not(n20);
  auto n30 = gate_not(n32);
  auto n22 = gate_nand(n21, n30);
  auto n23 = gate_nand(n22, b[2]);
  auto n27 = gate_nand(n23, n28);
  auto n24 = gate_not(n27);
  auto n44 = gate_nand(n25, n24);
  y[1] = gate_not(n44);
  y[3] = gate_not(n26);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_not(n29);
  auto n66 = gate_nand(n31, n30);
  auto n64 = gate_nand(n32, b[3]);
  auto n33 = gate_nand(y[1], b[1]);
  auto n40 = gate_nand(n34, n33);
  auto n35 = gate_not(n34);
  auto n37 = gate_nand(n35, b[1]);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_nand(y[1], n38);
  auto n43 = gate_nand(n40, n39);
  auto n41 = gate_not(n43);
  auto n62 = gate_nand(n42, n41);
  auto n60 = gate_nand(b[2], n43);
  auto n45 = gate_nand(a[1], n44);
  auto n46 = gate_not(n45);
  auto n58 = gate_nand(n47, n46);
  auto n49 = gate_nand(y[1], b[0]);
  auto n48 = gate_not(n49);
  auto n52 = gate_nand(n48, a[1]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n56 = gate_nand(b[1], n53);
  auto n54 = gate_not(a[0]);
  auto n55 = gate_nand(b[0], n54);
  auto n57 = gate_nand(n56, n55);
  auto n59 = gate_nand(n58, n57);
  auto n61 = gate_nand(n60, n59);
  auto n63 = gate_nand(n62, n61);
  auto n65 = gate_nand(n64, n63);
  y[0] = gate_nand(n66, n65);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(b[2]);
  auto n2 = gate_nand(n1, b[3]);
  auto n20 = gate_not(b[3]);
  auto n110 = gate_nand(b[2], n20);
  auto n77 = gate_nand(n2, n110);
  auto n71 = gate_not(n77);
  auto n5 = gate_nand(b[1], n20);
  auto n3 = gate_not(b[1]);
  auto n4 = gate_nand(b[3], n3);
  auto n64 = gate_nand(n5, n4);
  auto n108 = gate_not(n64);
  auto n6 = gate_nand(b[0], n108);
  auto n7 = gate_not(n6);
  auto n32 = gate_nand(n71, n7);
  auto n11 = gate_not(n32);
  auto n15 = gate_not(a[1]);
  auto n46 = gate_not(a[0]);
  auto n22 = gate_nand(n15, n46);
  auto n8 = gate_not(n22);
  auto n23 = gate_not(a[2]);
  auto n9 = gate_nand(n8, n23);
  auto n10 = gate_not(n9);
  auto n28 = gate_nand(a[3], n10);
  auto n43 = gate_not(n28);
  auto n96 = gate_nand(n11, n43);
  auto n12 = gate_not(a[3]);
  auto n14 = gate_nand(b[3], n12);
  auto n13 = gate_nand(a[3], n20);
  auto n112 = gate_nand(n14, n13);
  auto n17 = gate_nand(a[0], a[3]);
  auto n16 = gate_not(n17);
  auto n19 = gate_nand(n16, n15);
  auto n18 = gate_nand(n17, a[1]);
  auto n65 = gate_nand(n19, n18);
  auto n21 = gate_nand(b[0], n65);
  auto n59 = gate_not(b[0]);
  auto n106 = gate_nand(n20, n59);
  auto n39 = gate_nand(n21, n106);
  auto n38 = gate_nand(n39, n108);
  auto n25 = gate_nand(a[3], n22);
  auto n24 = gate_not(n25);
  auto n27 = gate_nand(n24, n23);
  auto n26 = gate_nand(n25, a[2]);
  auto n37 = gate_nand(n27, n26);
  auto n31 = gate_nand(n28, n64);
  auto n29 = gate_nand(b[0], n37);
  auto n30 = gate_nand(n29, n106);
  auto n35 = gate_nand(n31, n30);
  auto n33 = gate_nand(n43, n32);
  auto n48 = gate_not(n33);
  auto n34 = gate_nand(n108, n48);
  auto n36 = gate_nand(n35, n34);
  auto n91 = gate_nand(n71, n36);
  auto n73 = gate_nand(n37, n91);
  auto n42 = gate_nand(n38, n73);
  auto n40 = gate_not(n39);
  auto n41 = gate_nand(n40, n64);
  auto n50 = gate_nand(n42, n41);
  auto n44 = gate_nand(n50, n43);
  auto n45 = gate_not(n44);
  auto n82 = gate_nand(n45, n77);
  auto n47 = gate_nand(n46, b[0]);
  auto n58 = gate_not(n47);
  auto n52 = gate_nand(n91, n48);
  auto n49 = gate_not(n52);
  auto n51 = gate_nand(n49, n71);
  auto n54 = gate_nand(n51, n50);
  auto n53 = gate_nand(n52, n77);
  auto n84 = gate_nand(n54, n53);
  auto n55 = gate_nand(n84, n108);
  auto n56 = gate_not(n55);
  auto n57 = gate_nand(a[1], n56);
  auto n70 = gate_nand(n58, n57);
  auto n60 = gate_nand(b[3], n59);
  auto n68 = gate_nand(n108, n60);
  auto n61 = gate_nand(b[0], n84);
  auto n62 = gate_nand(n61, n106);
  auto n63 = gate_not(n62);
  auto n66 = gate_nand(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n78 = gate_nand(n70, n69);
  auto n72 = gate_not(n78);
  auto n76 = gate_nand(n72, n71);
  auto n74 = gate_not(n73);
  auto n75 = gate_nand(n74, n84);
  auto n80 = gate_nand(n76, n75);
  auto n79 = gate_nand(n78, n77);
  auto n81 = gate_nand(n80, n79);
  auto n114 = gate_nand(n82, n81);
  auto n83 = gate_not(n114);
  auto n119 = gate_nand(n112, n83);
  auto n89 = gate_not(n119);
  auto n115 = gate_not(n112);
  auto n87 = gate_nand(n84, n115);
  auto n85 = gate_not(n84);
  auto n86 = gate_nand(n112, n85);
  auto n102 = gate_nand(n87, n86);
  auto n88 = gate_not(n102);
  auto n103 = gate_nand(n89, n88);
  auto n94 = gate_not(n103);
  auto n90 = gate_not(n91);
  auto n93 = gate_nand(n90, n115);
  auto n92 = gate_nand(n112, n91);
  auto n97 = gate_nand(n93, n92);
  auto n99 = gate_nand(n94, n97);
  auto n95 = gate_nand(n112, n99);
  y[3] = gate_nand(n96, n95);
  auto n98 = gate_not(n97);
  auto n100 = gate_nand(n98, n103);
  auto n101 = gate_nand(n100, n99);
  y[2] = gate_not(n101);
  auto n104 = gate_nand(n119, n102);
  auto n105 = gate_nand(n104, n103);
  y[1] = gate_not(n105);
  auto n107 = gate_not(n106);
  auto n109 = gate_nand(n108, n107);
  auto n111 = gate_not(n109);
  auto n113 = gate_nand(n111, n110);
  auto n117 = gate_nand(n113, n112);
  auto n116 = gate_nand(n115, n114);
  auto n118 = gate_nand(n117, n116);
  auto n120 = gate_nand(n119, n118);
  y[0] = gate_not(n120);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[3]);
  auto n53 = gate_nand(n30, a[3]);
  auto n31 = gate_not(b[2]);
  auto n46 = gate_nand(n31, a[2]);
  auto n32 = gate_not(b[0]);
  auto n35 = gate_nand(a[0], n32);
  auto n33 = gate_not(a[0]);
  auto n34 = gate_nand(b[0], n33);
  auto n36 = gate_nand(n35, n34);
  auto n43 = gate_not(n36);
  auto n37 = gate_not(b[1]);
  auto n40 = gate_nand(a[1], n37);
  auto n38 = gate_not(a[1]);
  auto n39 = gate_nand(b[1], n38);
  auto n41 = gate_nand(n40, n39);
  auto n42 = gate_not(n41);
  auto n44 = gate_nand(n43, n42);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  auto n50 = gate_not(n47);
  auto n48 = gate_not(a[2]);
  auto n49 = gate_nand(n48, b[2]);
  auto n51 = gate_nand(n50, n49);
  auto n52 = gate_not(n51);
  auto n54 = gate_nand(n53, n52);
  auto n57 = gate_not(n54);
  auto n55 = gate_not(a[3]);
  auto n56 = gate_nand(n55, b[3]);
  auto n58 = gate_nand(n57, n56);
  auto _eq_x_1_n56 = gate_not(n58);
  y[0] = gate_buf(_eq_x_1_n56);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(b[3]);
  auto n38 = gate_nand(n20, a[3]);
  auto n21 = gate_not(a[3]);
  auto n36 = gate_nand(n21, b[3]);
  auto n22 = gate_not(b[2]);
  auto n34 = gate_nand(n22, a[2]);
  auto n23 = gate_not(a[2]);
  auto n32 = gate_nand(n23, b[2]);
  auto n24 = gate_not(a[1]);
  auto n27 = gate_nand(n24, b[1]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_nand(b[0], n25);
  auto n30 = gate_nand(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n29 = gate_nand(n28, a[1]);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto _gte_x_1_n55 = gate_nand(n38, n37);
  y[0] = gate_buf(_gte_x_1_n55);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_not(a[3]);
  auto n38 = gate_nand(n20, b[3]);
  auto n21 = gate_not(b[3]);
  auto n36 = gate_nand(n21, a[3]);
  auto n22 = gate_not(b[2]);
  auto n34 = gate_nand(n22, a[2]);
  auto n23 = gate_not(a[2]);
  auto n32 = gate_nand(n23, b[2]);
  auto n24 = gate_not(a[1]);
  auto n27 = gate_nand(n24, b[1]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_nand(b[0], n25);
  auto n30 = gate_nand(n27, n26);
  auto n28 = gate_not(b[1]);
  auto n29 = gate_nand(n28, a[1]);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto _gte_x_1_n55 = gate_nand(n38, n37);
  y[0] = gate_buf(_gte_x_1_n55);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(b[3]);
  auto n40 = gate_nand(n21, a[3]);
  auto n22 = gate_not(a[3]);
  auto n38 = gate_nand(n22, b[3]);
  auto n23 = gate_not(b[2]);
  auto n36 = gate_nand(n23, a[2]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_nand(n24, b[2]);
  auto n25 = gate_not(b[0]);
  auto n27 = gate_nand(a[0], n25);
  auto n26 = gate_not(n27);
  auto n32 = gate_nand(n26, a[1]);
  auto n28 = gate_not(a[1]);
  auto n30 = gate_nand(n28, n27);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto _gt_x_1_n55 = gate_nand(n40, n39);
  y[0] = gate_buf(_gt_x_1_n55);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(a[3]);
  auto n40 = gate_nand(n21, b[3]);
  auto n22 = gate_not(b[3]);
  auto n38 = gate_nand(n22, a[3]);
  auto n23 = gate_not(b[2]);
  auto n36 = gate_nand(n23, a[2]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_nand(n24, b[2]);
  auto n25 = gate_not(b[0]);
  auto n27 = gate_nand(a[0], n25);
  auto n26 = gate_not(n27);
  auto n32 = gate_nand(n26, a[1]);
  auto n28 = gate_not(a[1]);
  auto n30 = gate_nand(n28, n27);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto _gt_x_1_n55 = gate_nand(n40, n39);
  y[0] = gate_buf(_gt_x_1_n55);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n24 = gate_nand(a[0], a[1]);
  auto n14 = gate_not(n24);
  auto n20 = gate_nand(n14, a[2]);
  auto n18 = gate_nand(a[3], n20);
  auto n16 = gate_not(n20);
  auto n15 = gate_not(a[3]);
  auto n17 = gate_nand(n16, n15);
  y[3] = gate_nand(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n21 = gate_nand(n19, n24);
  auto n22 = gate_nand(n21, n20);
  y[2] = gate_not(n22);
  y[0] = gate_not(a[0]);
  auto n23 = gate_not(a[1]);
  auto n25 = gate_nand(n23, y[0]);
  auto n26 = gate_nand(n25, n24);
  y[1] = gate_not(n26);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n30 = gate_not(b[0]);
  auto n33 = gate_nand(a[0], n30);
  auto n31 = gate_not(a[0]);
  auto n32 = gate_nand(b[0], n31);
  auto n34 = gate_nand(n33, n32);
  auto n41 = gate_not(n34);
  auto n35 = gate_not(b[1]);
  auto n38 = gate_nand(a[1], n35);
  auto n36 = gate_not(a[1]);
  auto n37 = gate_nand(b[1], n36);
  auto n39 = gate_nand(n38, n37);
  auto n40 = gate_not(n39);
  auto n42 = gate_nand(n41, n40);
  auto n57 = gate_not(n42);
  auto n43 = gate_not(b[2]);
  auto n46 = gate_nand(a[2], n43);
  auto n44 = gate_not(a[2]);
  auto n45 = gate_nand(b[2], n44);
  auto n47 = gate_nand(n46, n45);
  auto n54 = gate_not(n47);
  auto n48 = gate_not(b[3]);
  auto n51 = gate_nand(a[3], n48);
  auto n49 = gate_not(a[3]);
  auto n50 = gate_nand(b[3], n49);
  auto n52 = gate_nand(n51, n50);
  auto n53 = gate_not(n52);
  auto n55 = gate_nand(n54, n53);
  auto n56 = gate_not(n55);
  y[0] = gate_nand(n57, n56);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n20 = gate_not(a[1]);
  auto n19 = gate_not(a[3]);
  auto n21 = gate_nand(n20, n19);
  auto n26 = gate_not(n21);
  auto n23 = gate_not(a[2]);
  auto n22 = gate_not(a[0]);
  auto n24 = gate_nand(n23, n22);
  auto n25 = gate_not(n24);
  auto n33 = gate_nand(n26, n25);
  auto n28 = gate_nand(n33, b[0]);
  auto n34 = gate_not(n33);
  auto n27 = gate_nand(n34, c[0]);
  y[0] = gate_nand(n28, n27);
  auto n30 = gate_nand(n33, b[1]);
  auto n29 = gate_nand(n34, c[1]);
  y[1] = gate_nand(n30, n29);
  auto n32 = gate_nand(n33, b[2]);
  auto n31 = gate_nand(n34, c[2]);
  y[2] = gate_nand(n32, n31);
  auto n36 = gate_nand(n33, b[3]);
  auto n35 = gate_nand(n34, c[3]);
  y[3] = gate_nand(n36, n35);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(a[3]);
  auto n41 = gate_nand(n23, b[3]);
  auto n24 = gate_not(b[3]);
  auto n39 = gate_nand(n24, a[3]);
  auto n25 = gate_not(b[2]);
  auto n34 = gate_nand(n25, a[2]);
  auto n26 = gate_not(a[1]);
  auto n32 = gate_nand(n26, b[1]);
  auto n27 = gate_not(b[0]);
  auto n30 = gate_nand(a[0], n27);
  auto n28 = gate_not(b[1]);
  auto n29 = gate_nand(a[1], n28);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_not(a[2]);
  auto n36 = gate_nand(n35, b[2]);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  y[0] = gate_nand(n41, n40);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n23 = gate_not(b[3]);
  auto n41 = gate_nand(n23, a[3]);
  auto n24 = gate_not(a[3]);
  auto n39 = gate_nand(n24, b[3]);
  auto n25 = gate_not(b[2]);
  auto n34 = gate_nand(n25, a[2]);
  auto n26 = gate_not(a[1]);
  auto n32 = gate_nand(n26, b[1]);
  auto n27 = gate_not(b[0]);
  auto n30 = gate_nand(a[0], n27);
  auto n28 = gate_not(b[1]);
  auto n29 = gate_nand(a[1], n28);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n37 = gate_nand(n34, n33);
  auto n35 = gate_not(a[2]);
  auto n36 = gate_nand(n35, b[2]);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  y[0] = gate_nand(n41, n40);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_not(a[1]);
  auto n20 = gate_not(a[3]);
  auto n22 = gate_nand(n21, n20);
  auto n27 = gate_not(n22);
  auto n24 = gate_not(a[2]);
  auto n23 = gate_not(a[0]);
  auto n25 = gate_nand(n24, n23);
  auto n26 = gate_not(n25);
  auto n37 = gate_nand(n27, n26);
  auto n29 = gate_not(b[1]);
  auto n28 = gate_not(b[3]);
  auto n30 = gate_nand(n29, n28);
  auto n35 = gate_not(n30);
  auto n32 = gate_not(b[2]);
  auto n31 = gate_not(b[0]);
  auto n33 = gate_nand(n32, n31);
  auto n34 = gate_not(n33);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  y[0] = gate_not(n38);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n13 = gate_nand(n12, n11);
  auto n18 = gate_not(n13);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[0]);
  auto n16 = gate_nand(n15, n14);
  auto n17 = gate_not(n16);
  auto n19 = gate_nand(n18, n17);
  y[0] = gate_not(n19);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[1]);
  auto n21 = gate_not(a[3]);
  auto n23 = gate_nand(n22, n21);
  auto n28 = gate_not(n23);
  auto n25 = gate_not(a[2]);
  auto n24 = gate_not(a[0]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_not(n26);
  auto n29 = gate_nand(n28, n27);
  auto n40 = gate_not(n29);
  auto n31 = gate_not(b[1]);
  auto n30 = gate_not(b[3]);
  auto n32 = gate_nand(n31, n30);
  auto n37 = gate_not(n32);
  auto n34 = gate_not(b[2]);
  auto n33 = gate_not(b[0]);
  auto n35 = gate_nand(n34, n33);
  auto n36 = gate_not(n35);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_not(n38);
  y[0] = gate_nand(n40, n39);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[3]);
  auto n41 = gate_nand(n22, b[3]);
  auto n23 = gate_not(b[3]);
  auto n39 = gate_nand(n23, a[3]);
  auto n24 = gate_not(a[2]);
  auto n37 = gate_nand(n24, b[2]);
  auto n25 = gate_not(b[2]);
  auto n35 = gate_nand(n25, a[2]);
  auto n26 = gate_not(a[0]);
  auto n28 = gate_nand(b[0], n26);
  auto n27 = gate_not(n28);
  auto n33 = gate_nand(n27, b[1]);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_nand(n29, n28);
  auto n30 = gate_not(a[1]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  y[0] = gate_nand(n41, n40);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[3]);
  auto n41 = gate_nand(n22, a[3]);
  auto n23 = gate_not(a[3]);
  auto n39 = gate_nand(n23, b[3]);
  auto n24 = gate_not(a[2]);
  auto n37 = gate_nand(n24, b[2]);
  auto n25 = gate_not(b[2]);
  auto n35 = gate_nand(n25, a[2]);
  auto n26 = gate_not(a[0]);
  auto n28 = gate_nand(b[0], n26);
  auto n27 = gate_not(n28);
  auto n33 = gate_nand(n27, b[1]);
  auto n29 = gate_not(b[1]);
  auto n31 = gate_nand(n29, n28);
  auto n30 = gate_not(a[1]);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n40 = gate_nand(n39, n38);
  y[0] = gate_nand(n41, n40);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n35 = gate_not(b[1]);
  auto n30 = gate_not(a[1]);
  auto n42 = gate_nand(b[0], n30);
  auto n12 = gate_nand(n42, n35);
  auto n1 = gate_not(a[2]);
  auto n11 = gate_nand(n1, b[0]);
  auto n2 = gate_not(b[0]);
  auto n5 = gate_nand(n2, n35);
  auto n3 = gate_not(a[3]);
  auto n4 = gate_nand(n3, b[1]);
  auto n6 = gate_nand(n5, n4);
  auto n8 = gate_not(n6);
  auto n60 = gate_not(b[3]);
  auto n52 = gate_not(b[2]);
  auto n7 = gate_nand(n60, n52);
  auto n16 = gate_not(n7);
  auto n9 = gate_nand(n8, n16);
  auto n10 = gate_not(n9);
  auto n21 = gate_nand(n11, n10);
  auto n40 = gate_nand(n21, a[2]);
  auto n15 = gate_nand(n12, n40);
  auto n13 = gate_not(n42);
  auto n14 = gate_nand(n13, b[1]);
  auto n24 = gate_nand(n15, n14);
  auto n17 = gate_nand(n35, n16);
  auto n18 = gate_not(n17);
  auto n19 = gate_nand(n18, b[0]);
  auto n20 = gate_nand(n19, a[3]);
  auto n22 = gate_not(n20);
  auto n23 = gate_nand(n22, n21);
  auto n28 = gate_nand(n24, n23);
  auto n56 = gate_not(n23);
  auto n53 = gate_not(n24);
  auto n25 = gate_nand(n56, n53);
  auto n26 = gate_nand(n25, b[2]);
  auto n27 = gate_nand(n26, n60);
  auto n54 = gate_not(n27);
  auto n29 = gate_nand(n28, n54);
  auto n45 = gate_not(n29);
  auto n32 = gate_nand(b[0], n45);
  auto n31 = gate_not(n32);
  auto n34 = gate_nand(n31, n30);
  auto n33 = gate_nand(n32, a[1]);
  auto n76 = gate_nand(n34, n33);
  auto n67 = gate_nand(n35, n76);
  auto n36 = gate_not(a[0]);
  auto n70 = gate_nand(b[0], n36);
  auto n68 = gate_not(n70);
  auto n38 = gate_nand(n67, n68);
  auto n37 = gate_not(n76);
  auto n66 = gate_nand(b[1], n37);
  auto n48 = gate_nand(n38, n66);
  auto n79 = gate_nand(n48, b[2]);
  auto n39 = gate_nand(n45, b[1]);
  auto n47 = gate_nand(n40, n39);
  auto n41 = gate_not(n40);
  auto n43 = gate_nand(n41, b[1]);
  auto n44 = gate_nand(n43, n42);
  auto n46 = gate_nand(n45, n44);
  auto n83 = gate_nand(n47, n46);
  auto n85 = gate_not(n83);
  auto n50 = gate_nand(n79, n85);
  auto n49 = gate_not(n48);
  auto n80 = gate_nand(n52, n49);
  auto n61 = gate_nand(n50, n80);
  auto n51 = gate_not(n61);
  auto n59 = gate_nand(b[3], n51);
  auto n55 = gate_nand(n53, n52);
  auto n57 = gate_nand(n55, n54);
  auto n58 = gate_nand(n57, n56);
  auto n91 = gate_not(n58);
  auto n62 = gate_nand(n59, n91);
  auto n89 = gate_nand(n61, n60);
  auto n90 = gate_nand(n62, n89);
  auto n63 = gate_nand(n90, b[0]);
  auto n65 = gate_nand(a[0], n63);
  auto n64 = gate_nand(n90, n68);
  y[0] = gate_nand(n65, n64);
  auto n71 = gate_nand(n67, n66);
  auto n69 = gate_not(n71);
  auto n73 = gate_nand(n69, n68);
  auto n72 = gate_nand(n71, n70);
  auto n74 = gate_nand(n73, n72);
  auto n78 = gate_nand(n90, n74);
  auto n75 = gate_not(n90);
  auto n77 = gate_nand(n76, n75);
  y[1] = gate_nand(n78, n77);
  auto n81 = gate_nand(n80, n79);
  auto n82 = gate_not(n81);
  auto n86 = gate_nand(n82, n90);
  auto n84 = gate_not(n86);
  auto n88 = gate_nand(n84, n83);
  auto n87 = gate_nand(n86, n85);
  y[2] = gate_nand(n88, n87);
  auto n92 = gate_nand(n90, n89);
  auto n93 = gate_nand(n92, n91);
  y[3] = gate_not(n93);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n15 = gate_not(b[3]);
  auto n3 = gate_nand(b[1], n15);
  auto n1 = gate_not(b[1]);
  auto n2 = gate_nand(b[3], n1);
  auto n50 = gate_nand(n3, n2);
  auto n83 = gate_nand(a[3], a[0]);
  auto n4 = gate_not(n83);
  auto n10 = gate_not(a[1]);
  auto n6 = gate_nand(n4, n10);
  auto n5 = gate_nand(a[1], n83);
  auto n40 = gate_nand(n6, n5);
  auto n8 = gate_nand(b[0], n40);
  auto n7 = gate_not(b[0]);
  auto n45 = gate_nand(n7, n15);
  auto n24 = gate_nand(n8, n45);
  auto n9 = gate_not(n24);
  auto n23 = gate_nand(n50, n9);
  auto n82 = gate_not(a[0]);
  auto n27 = gate_nand(n10, n82);
  auto n11 = gate_nand(a[3], n27);
  auto n14 = gate_nand(a[2], n11);
  auto n12 = gate_not(n11);
  auto n28 = gate_not(a[2]);
  auto n13 = gate_nand(n12, n28);
  auto n21 = gate_nand(n14, n13);
  auto n18 = gate_nand(b[2], n15);
  auto n16 = gate_not(b[2]);
  auto n17 = gate_nand(b[3], n16);
  auto n58 = gate_nand(n18, n17);
  auto n52 = gate_not(n58);
  auto n47 = gate_not(n50);
  auto n19 = gate_nand(n52, n47);
  auto n20 = gate_not(n19);
  auto n31 = gate_nand(b[0], n20);
  auto n22 = gate_nand(n21, n31);
  auto n55 = gate_not(n22);
  auto n25 = gate_nand(n23, n55);
  auto n54 = gate_nand(n47, n24);
  auto n37 = gate_nand(n25, n54);
  auto n26 = gate_not(n37);
  auto n36 = gate_nand(n26, n58);
  auto n29 = gate_not(n27);
  auto n30 = gate_nand(n29, n28);
  auto n34 = gate_not(n30);
  auto n32 = gate_nand(a[3], n31);
  auto n33 = gate_not(n32);
  auto n35 = gate_nand(n34, n33);
  auto n62 = gate_not(n35);
  auto n38 = gate_nand(n36, n62);
  auto n60 = gate_nand(n52, n37);
  auto n61 = gate_nand(n38, n60);
  auto n42 = gate_nand(n61, b[0]);
  auto n39 = gate_not(n42);
  auto n44 = gate_nand(n39, n40);
  auto n41 = gate_not(n40);
  auto n43 = gate_nand(n42, n41);
  auto n97 = gate_nand(n44, n43);
  auto n46 = gate_nand(a[0], b[0]);
  auto n48 = gate_nand(n46, n45);
  auto n92 = gate_nand(n47, n48);
  auto n51 = gate_nand(n97, n92);
  auto n49 = gate_not(n48);
  auto n94 = gate_nand(n50, n49);
  auto n57 = gate_nand(n51, n94);
  auto n53 = gate_not(n57);
  auto n67 = gate_nand(n53, n52);
  auto n56 = gate_nand(n61, n54);
  auto n72 = gate_nand(n56, n55);
  auto n59 = gate_nand(n67, n72);
  auto n66 = gate_nand(n58, n57);
  auto n70 = gate_nand(n59, n66);
  auto n65 = gate_not(n70);
  auto n63 = gate_nand(n61, n60);
  auto n69 = gate_nand(n63, n62);
  auto n64 = gate_not(n69);
  auto n109 = gate_nand(n65, n64);
  auto n68 = gate_nand(n67, n66);
  auto n71 = gate_not(n68);
  auto n91 = gate_nand(n70, n69);
  auto n78 = gate_nand(n71, n91);
  auto n77 = gate_not(n78);
  auto n75 = gate_nand(a[3], n72);
  auto n73 = gate_not(n72);
  auto n123 = gate_not(a[3]);
  auto n74 = gate_nand(n73, n123);
  auto n79 = gate_nand(n75, n74);
  auto n76 = gate_not(n79);
  auto n81 = gate_nand(n77, n76);
  auto n80 = gate_nand(n79, n78);
  auto n113 = gate_nand(n81, n80);
  auto n87 = gate_nand(b[0], n91);
  auto n85 = gate_not(n87);
  auto n84 = gate_nand(n123, n82);
  auto n86 = gate_nand(n84, n83);
  auto n90 = gate_nand(n85, n86);
  auto n88 = gate_not(n86);
  auto n89 = gate_nand(n88, n87);
  auto n122 = gate_nand(n90, n89);
  auto n93 = gate_nand(n92, n91);
  auto n95 = gate_not(n93);
  auto n102 = gate_nand(n95, n94);
  auto n101 = gate_not(n102);
  auto n96 = gate_not(n97);
  auto n99 = gate_nand(n96, n123);
  auto n98 = gate_nand(a[3], n97);
  auto n103 = gate_nand(n99, n98);
  auto n100 = gate_not(n103);
  auto n105 = gate_nand(n101, n100);
  auto n104 = gate_nand(n103, n102);
  auto n119 = gate_nand(n105, n104);
  auto n106 = gate_nand(n122, n119);
  auto n110 = gate_not(n106);
  auto n107 = gate_nand(n113, n110);
  auto n108 = gate_nand(n107, a[3]);
  y[3] = gate_nand(n109, n108);
  auto n114 = gate_nand(n110, a[3]);
  auto n112 = gate_not(n114);
  auto n111 = gate_not(n113);
  auto n116 = gate_nand(n112, n111);
  auto n115 = gate_nand(n114, n113);
  y[2] = gate_nand(n116, n115);
  auto n125 = gate_nand(a[3], n122);
  auto n118 = gate_not(n125);
  auto n117 = gate_not(n119);
  auto n121 = gate_nand(n118, n117);
  auto n120 = gate_nand(n119, n125);
  y[1] = gate_nand(n121, n120);
  auto n124 = gate_not(n122);
  auto n126 = gate_nand(n124, n123);
  auto n127 = gate_nand(n126, n125);
  y[0] = gate_not(n127);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_not(n6);
  auto n3 = gate_nand(b[0], a[1]);
  auto n1 = gate_not(n3);
  auto n2 = gate_nand(b[1], a[0]);
  auto n5 = gate_nand(n1, n2);
  auto n17 = gate_not(n2);
  auto n4 = gate_nand(n3, n17);
  y[1] = gate_nand(n5, n4);
  auto n24 = gate_nand(a[1], b[1]);
  auto n19 = gate_not(n24);
  auto n13 = gate_nand(n19, n6);
  auto n12 = gate_not(n13);
  auto n7 = gate_nand(b[0], a[2]);
  auto n25 = gate_not(n7);
  auto n23 = gate_nand(a[0], b[2]);
  auto n10 = gate_nand(n25, n23);
  auto n8 = gate_not(n23);
  auto n9 = gate_nand(n8, n7);
  auto n14 = gate_nand(n10, n9);
  auto n11 = gate_not(n14);
  auto n16 = gate_nand(n12, n11);
  auto n15 = gate_nand(n14, n13);
  y[2] = gate_nand(n16, n15);
  auto n37 = gate_nand(a[1], b[2]);
  auto n39 = gate_not(n37);
  auto n20 = gate_nand(n39, n17);
  auto n18 = gate_not(n20);
  auto n30 = gate_nand(n25, n18);
  auto n21 = gate_nand(n19, y[0]);
  auto n22 = gate_nand(n21, n20);
  auto n28 = gate_not(n22);
  auto n26 = gate_nand(n24, n23);
  auto n27 = gate_nand(n26, n25);
  auto n29 = gate_nand(n28, n27);
  auto n51 = gate_nand(n30, n29);
  auto n50 = gate_not(n51);
  auto n33 = gate_nand(a[2], b[1]);
  auto n31 = gate_not(n33);
  auto n32 = gate_nand(b[3], a[0]);
  auto n36 = gate_nand(n31, n32);
  auto n34 = gate_not(n32);
  auto n35 = gate_nand(n34, n33);
  auto n44 = gate_nand(n36, n35);
  auto n40 = gate_nand(a[3], b[0]);
  auto n38 = gate_not(n40);
  auto n42 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  auto n46 = gate_nand(n42, n41);
  auto n43 = gate_not(n46);
  auto n48 = gate_nand(n44, n43);
  auto n45 = gate_not(n44);
  auto n47 = gate_nand(n46, n45);
  auto n52 = gate_nand(n48, n47);
  auto n49 = gate_not(n52);
  auto n54 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  y[3] = gate_nand(n54, n53);
}
template<> void $NameUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[1], a[3]);
  auto n9 = gate_not(n6);
  auto n7 = gate_nand(a[2], a[0]);
  auto n8 = gate_not(n7);
  auto n10 = gate_nand(n9, n8);
  y[0] = gate_not(n10);
}
template<> void $NameUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[1], a[3]);
  auto n9 = gate_not(n6);
  auto n7 = gate_nand(a[2], a[0]);
  auto n8 = gate_not(n7);
  y[0] = gate_nand(n9, n8);
}
template<> void $NameUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n13 = gate_nand(n12, n11);
  auto n18 = gate_not(n13);
  auto n15 = gate_not(a[2]);
  auto n14 = gate_not(a[0]);
  auto n16 = gate_nand(n15, n14);
  auto n17 = gate_not(n16);
  auto n19 = gate_nand(n18, n17);
  y[0] = gate_not(n19);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_not(a[1]);
  auto n9 = gate_not(a[3]);
  auto n11 = gate_nand(n10, n9);
  auto n16 = gate_not(n11);
  auto n13 = gate_not(a[2]);
  auto n12 = gate_not(a[0]);
  auto n14 = gate_nand(n13, n12);
  auto n15 = gate_not(n14);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n16 = gate_not(a[1]);
  auto n19 = gate_nand(a[2], n16);
  auto n17 = gate_not(a[2]);
  auto n18 = gate_nand(a[1], n17);
  auto n21 = gate_nand(n19, n18);
  auto n20 = gate_not(a[0]);
  auto n24 = gate_nand(n21, n20);
  auto n22 = gate_not(n21);
  auto n23 = gate_nand(a[0], n22);
  auto n27 = gate_nand(n24, n23);
  auto n26 = gate_not(n27);
  auto n25 = gate_not(a[3]);
  auto n29 = gate_nand(n26, n25);
  auto n28 = gate_nand(n27, a[3]);
  y[0] = gate_nand(n29, n28);
}
template<> void $NameUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_not(a[1]);
  auto n18 = gate_nand(a[0], n15);
  auto n16 = gate_not(a[0]);
  auto n17 = gate_nand(a[1], n16);
  auto n24 = gate_nand(n18, n17);
  auto n19 = gate_not(a[2]);
  auto n22 = gate_nand(a[3], n19);
  auto n20 = gate_not(a[3]);
  auto n21 = gate_nand(a[2], n20);
  auto n26 = gate_nand(n22, n21);
  auto n23 = gate_not(n26);
  auto n28 = gate_nand(n24, n23);
  auto n25 = gate_not(n24);
  auto n27 = gate_nand(n26, n25);
  y[0] = gate_nand(n28, n27);
}
template<> void $NameUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n35 = gate_not(b[2]);
  auto n34 = gate_not(b[3]);
  auto n36 = gate_nand(n35, n34);
  auto n46 = gate_not(n36);
  auto n37 = gate_not(b[1]);
  auto n38 = gate_nand(n46, n37);
  auto n45 = gate_not(n38);
  auto n50 = gate_not(b[0]);
  auto n39 = gate_nand(n45, n50);
  auto n54 = gate_not(n39);
  auto n40 = gate_nand(a[0], n54);
  y[0] = gate_not(n40);
  auto n42 = gate_nand(n50, a[1]);
  auto n41 = gate_nand(b[0], a[0]);
  auto n56 = gate_nand(n42, n41);
  auto n43 = gate_nand(n45, n56);
  y[1] = gate_not(n43);
  auto n44 = gate_nand(b[0], n45);
  auto n55 = gate_not(n44);
  auto n53 = gate_nand(n55, a[1]);
  auto n49 = gate_nand(n45, a[2]);
  auto n47 = gate_nand(b[1], n46);
  auto n57 = gate_not(n47);
  auto n48 = gate_nand(a[0], n57);
  auto n51 = gate_nand(n49, n48);
  auto n52 = gate_nand(n51, n50);
  y[2] = gate_nand(n53, n52);
  auto n62 = gate_nand(a[3], n54);
  auto n59 = gate_nand(n55, a[2]);
  auto n58 = gate_nand(n57, n56);
  auto n60 = gate_nand(n59, n58);
  auto n61 = gate_not(n60);
  y[3] = gate_nand(n62, n61);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n33 = gate_not(b[3]);
  auto n32 = gate_not(b[2]);
  auto n34 = gate_nand(n33, n32);
  auto n37 = gate_not(n34);
  auto n35 = gate_not(b[1]);
  auto n36 = gate_nand(n37, n35);
  auto n52 = gate_not(n36);
  auto n40 = gate_nand(a[1], n52);
  auto n38 = gate_nand(b[1], n37);
  auto n41 = gate_not(n38);
  auto n39 = gate_nand(n41, a[3]);
  auto n48 = gate_nand(n40, n39);
  auto n46 = gate_nand(n48, b[0]);
  auto n43 = gate_nand(n52, a[0]);
  auto n42 = gate_nand(n41, a[2]);
  auto n44 = gate_nand(n43, n42);
  auto n51 = gate_not(b[0]);
  auto n45 = gate_nand(n44, n51);
  y[0] = gate_nand(n46, n45);
  auto n47 = gate_nand(b[0], n52);
  auto n54 = gate_not(n47);
  auto n50 = gate_nand(n54, a[2]);
  auto n49 = gate_nand(n48, n51);
  y[1] = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n57 = gate_not(n53);
  auto n56 = gate_nand(n57, a[2]);
  auto n55 = gate_nand(n54, a[3]);
  y[2] = gate_nand(n56, n55);
  auto n58 = gate_nand(a[3], n57);
  y[3] = gate_not(n58);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n43 = gate_nand(b[0], b[1]);
  auto n41 = gate_not(b[3]);
  auto n40 = gate_not(b[2]);
  auto n42 = gate_nand(n41, n40);
  auto n56 = gate_not(n42);
  auto n44 = gate_nand(n43, n56);
  auto n54 = gate_nand(n44, a[3]);
  auto n55 = gate_not(b[1]);
  auto n45 = gate_nand(a[1], n55);
  auto n46 = gate_not(n45);
  auto n51 = gate_nand(n46, b[0]);
  auto n61 = gate_not(b[0]);
  auto n48 = gate_nand(n55, a[0]);
  auto n47 = gate_nand(b[1], a[2]);
  auto n49 = gate_nand(n48, n47);
  auto n50 = gate_nand(n61, n49);
  auto n52 = gate_nand(n51, n50);
  auto n53 = gate_nand(n52, n56);
  y[0] = gate_nand(n54, n53);
  auto n66 = gate_nand(n56, n55);
  auto n65 = gate_not(n66);
  auto n58 = gate_nand(n65, n61);
  auto n57 = gate_not(n58);
  auto n60 = gate_nand(n57, a[2]);
  auto n59 = gate_nand(n58, a[3]);
  y[2] = gate_nand(n60, n59);
  auto n63 = gate_nand(n61, a[1]);
  auto n62 = gate_nand(b[0], a[2]);
  auto n64 = gate_nand(n63, n62);
  auto n68 = gate_nand(n65, n64);
  auto n67 = gate_nand(a[3], n66);
  y[1] = gate_nand(n68, n67);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n36 = gate_not(b[0]);
  auto n38 = gate_nand(n36, a[0]);
  auto n37 = gate_not(a[0]);
  auto n44 = gate_nand(b[0], n37);
  y[0] = gate_nand(n38, n44);
  auto n39 = gate_not(a[1]);
  auto n41 = gate_nand(n39, b[1]);
  auto n40 = gate_not(b[1]);
  auto n52 = gate_nand(a[1], n40);
  auto n43 = gate_nand(n41, n52);
  auto n42 = gate_not(n44);
  auto n46 = gate_nand(n43, n42);
  auto n45 = gate_not(n43);
  auto n51 = gate_nand(n45, n44);
  auto n47 = gate_nand(n46, n51);
  y[1] = gate_not(n47);
  auto n48 = gate_not(a[2]);
  auto n50 = gate_nand(n48, b[2]);
  auto n49 = gate_not(b[2]);
  auto n59 = gate_nand(a[2], n49);
  auto n54 = gate_nand(n50, n59);
  auto n55 = gate_nand(n52, n51);
  auto n53 = gate_not(n55);
  auto n57 = gate_nand(n54, n53);
  auto n56 = gate_not(n54);
  auto n60 = gate_nand(n56, n55);
  auto n58 = gate_nand(n57, n60);
  y[2] = gate_not(n58);
  auto n67 = gate_nand(n60, n59);
  auto n66 = gate_not(n67);
  auto n61 = gate_not(b[3]);
  auto n64 = gate_nand(a[3], n61);
  auto n62 = gate_not(a[3]);
  auto n63 = gate_nand(b[3], n62);
  auto n68 = gate_nand(n64, n63);
  auto n65 = gate_not(n68);
  auto n70 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  y[3] = gate_nand(n70, n69);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n17 = gate_nand(a[1], a[0]);
  auto n16 = gate_not(a[0]);
  auto n15 = gate_not(a[1]);
  auto n19 = gate_nand(n16, n15);
  auto n18 = gate_nand(n17, n19);
  y[1] = gate_not(n18);
  auto n22 = gate_nand(n19, a[2]);
  auto n21 = gate_not(n19);
  auto n20 = gate_not(a[2]);
  auto n26 = gate_nand(n21, n20);
  auto n23 = gate_nand(n22, n26);
  y[2] = gate_not(n23);
  auto n24 = gate_not(n26);
  auto n28 = gate_nand(n24, a[3]);
  auto n25 = gate_not(a[3]);
  auto n27 = gate_nand(n26, n25);
  y[3] = gate_nand(n28, n27);
}
