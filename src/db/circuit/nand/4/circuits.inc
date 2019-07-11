template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n43 = gate_nand(b[1], a[1]);
  auto n38 = gate_nand(b[1], b[1]);
  auto n37 = gate_nand(a[1], a[1]);
  auto n45 = gate_nand(n38, n37);
  auto n39 = gate_nand(n43, n45);
  auto n72 = gate_nand(b[0], a[0]);
  auto n40 = gate_nand(n39, n72);
  auto n42 = gate_nand(n39, n40);
  auto n41 = gate_nand(n72, n40);
  y[1] = gate_nand(n42, n41);
  auto n44 = gate_nand(n43, n72);
  auto n52 = gate_nand(n45, n44);
  auto n59 = gate_nand(n52, n52);
  auto n67 = gate_nand(a[2], b[2]);
  auto n47 = gate_nand(a[2], a[2]);
  auto n46 = gate_nand(b[2], b[2]);
  auto n60 = gate_nand(n47, n46);
  auto n48 = gate_nand(n67, n60);
  auto n54 = gate_nand(n59, n48);
  auto n50 = gate_nand(n67, b[2]);
  auto n49 = gate_nand(n67, a[2]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  y[2] = gate_nand(n54, n53);
  auto n55 = gate_nand(a[3], a[3]);
  auto n58 = gate_nand(b[3], n55);
  auto n56 = gate_nand(b[3], b[3]);
  auto n57 = gate_nand(a[3], n56);
  auto n62 = gate_nand(n58, n57);
  auto n61 = gate_nand(n60, n59);
  auto n65 = gate_nand(n62, n61);
  auto n63 = gate_nand(n61, n61);
  auto n69 = gate_nand(n62, n62);
  auto n64 = gate_nand(n63, n69);
  auto n66 = gate_nand(n65, n64);
  auto n71 = gate_nand(n66, n67);
  auto n68 = gate_nand(n67, n67);
  auto n70 = gate_nand(n69, n68);
  y[3] = gate_nand(n71, n70);
  auto n74 = gate_nand(n72, a[0]);
  auto n73 = gate_nand(n72, b[0]);
  auto _add_x_1_n48 = gate_nand(n74, n73);
  y[0] = gate_buf(_add_x_1_n48);
}
template<> void $NameUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_nand(b[3], a[3]);
  y[3] = gate_nand(n5, n5);
  auto n6 = gate_nand(b[2], a[2]);
  y[2] = gate_nand(n6, n6);
  auto n7 = gate_nand(b[1], a[1]);
  y[1] = gate_nand(n7, n7);
  auto n8 = gate_nand(b[0], a[0]);
  y[0] = gate_nand(n8, n8);
}
template<> void $NameUint<4>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[3] = gate_nand(a[3], a[3]);
  y[2] = gate_nand(a[2], a[2]);
  y[1] = gate_nand(a[1], a[1]);
  y[0] = gate_nand(a[0], a[0]);
}
template<> void $NameUint<4>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n10 = gate_nand(b[3], b[3]);
  auto n9 = gate_nand(a[3], a[3]);
  y[3] = gate_nand(n10, n9);
  auto n12 = gate_nand(b[2], b[2]);
  auto n11 = gate_nand(a[2], a[2]);
  y[2] = gate_nand(n12, n11);
  auto n14 = gate_nand(b[1], b[1]);
  auto n13 = gate_nand(a[1], a[1]);
  y[1] = gate_nand(n14, n13);
  auto n16 = gate_nand(b[0], b[0]);
  auto n15 = gate_nand(a[0], a[0]);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n17 = gate_nand(b[3], b[3]);
  auto n20 = gate_nand(a[3], n17);
  auto n18 = gate_nand(a[3], a[3]);
  auto n19 = gate_nand(b[3], n18);
  y[3] = gate_nand(n20, n19);
  auto n21 = gate_nand(b[2], b[2]);
  auto n24 = gate_nand(a[2], n21);
  auto n22 = gate_nand(a[2], a[2]);
  auto n23 = gate_nand(b[2], n22);
  y[2] = gate_nand(n24, n23);
  auto n25 = gate_nand(b[1], b[1]);
  auto n28 = gate_nand(a[1], n25);
  auto n26 = gate_nand(a[1], a[1]);
  auto n27 = gate_nand(b[1], n26);
  y[1] = gate_nand(n28, n27);
  auto n29 = gate_nand(b[0], b[0]);
  auto n32 = gate_nand(a[0], n29);
  auto n30 = gate_nand(a[0], a[0]);
  auto n31 = gate_nand(b[0], n30);
  y[0] = gate_nand(n32, n31);
}
template<> void $NameUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[0], b[0]);
  y[0] = gate_nand(n1, n1);
  auto n2 = gate_nand(a[0], b[1]);
  y[1] = gate_nand(n2, n2);
  auto n3 = gate_nand(a[0], b[2]);
  y[2] = gate_nand(n3, n3);
  auto n4 = gate_nand(a[0], b[3]);
  y[3] = gate_nand(n4, n4);
}
template<> void $NameUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n16 = gate_nand(a[0], a[0]);
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
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[0]);
  auto n12 = gate_nand(a[1], a[1]);
  auto n21 = gate_nand(y[0], n12);
  auto n14 = gate_nand(n21, n21);
  auto n13 = gate_nand(a[2], a[2]);
  auto n19 = gate_nand(n14, n13);
  auto n18 = gate_nand(a[3], n19);
  auto n16 = gate_nand(n19, n19);
  auto n15 = gate_nand(a[3], a[3]);
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
  auto n68 = gate_nand(b[3], b[3]);
  auto n44 = gate_nand(b[2], b[2]);
  auto n8 = gate_nand(n68, n44);
  auto n23 = gate_nand(n8, n8);
  auto n37 = gate_nand(b[0], b[0]);
  auto n2 = gate_nand(n23, n37);
  auto n1 = gate_nand(n23, a[2]);
  auto n3 = gate_nand(n2, n1);
  auto n55 = gate_nand(b[1], b[1]);
  auto n5 = gate_nand(n3, n55);
  auto n4 = gate_nand(n3, a[3]);
  y[2] = gate_nand(n5, n4);
  auto n15 = gate_nand(a[3], n8);
  auto n6 = gate_nand(n15, n15);
  auto n7 = gate_nand(n68, n6);
  auto n20 = gate_nand(n8, n7);
  auto n9 = gate_nand(a[2], a[2]);
  auto n10 = gate_nand(n9, b[0]);
  auto n11 = gate_nand(n10, n10);
  auto n12 = gate_nand(n11, a[3]);
  auto n13 = gate_nand(n12, n12);
  auto n14 = gate_nand(n13, b[1]);
  auto n70 = gate_nand(n15, n14);
  auto n17 = gate_nand(n44, n70);
  auto n16 = gate_nand(y[2], b[0]);
  auto n45 = gate_nand(n16, a[2]);
  auto n33 = gate_nand(n45, n45);
  auto n36 = gate_nand(n33, n55);
  auto n28 = gate_nand(n17, n36);
  auto n22 = gate_nand(n20, n28);
  auto n18 = gate_nand(a[1], a[1]);
  auto n50 = gate_nand(b[0], n18);
  auto n35 = gate_nand(b[1], n45);
  auto n30 = gate_nand(n50, n35);
  auto n19 = gate_nand(n30, n30);
  auto n21 = gate_nand(n20, n19);
  y[1] = gate_nand(n22, n21);
  auto n24 = gate_nand(n23, n55);
  auto n25 = gate_nand(n24, n24);
  auto n27 = gate_nand(n25, n37);
  auto n26 = gate_nand(n25, a[3]);
  y[3] = gate_nand(n27, n26);
  auto n29 = gate_nand(n28, n28);
  auto n31 = gate_nand(n30, n29);
  auto n32 = gate_nand(n31, n31);
  auto n67 = gate_nand(n32, n70);
  auto n34 = gate_nand(y[1], y[1]);
  auto n42 = gate_nand(n34, n33);
  auto n38 = gate_nand(n36, n35);
  auto n40 = gate_nand(n38, a[1]);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  auto n46 = gate_nand(y[1], n41);
  auto n43 = gate_nand(n42, n46);
  auto n65 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, y[1]);
  auto n48 = gate_nand(n33, n47);
  auto n63 = gate_nand(b[2], n48);
  auto n49 = gate_nand(y[1], b[0]);
  auto n53 = gate_nand(a[1], n49);
  auto n51 = gate_nand(n50, n50);
  auto n52 = gate_nand(y[1], n51);
  auto n56 = gate_nand(n53, n52);
  auto n54 = gate_nand(n56, n56);
  auto n59 = gate_nand(n54, b[1]);
  auto n61 = gate_nand(n59, a[0]);
  auto n57 = gate_nand(n56, n55);
  auto n58 = gate_nand(n57, b[0]);
  auto n60 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n71 = gate_nand(n65, n64);
  auto n66 = gate_nand(n71, n71);
  auto n69 = gate_nand(n67, n66);
  auto n73 = gate_nand(n69, n68);
  auto n72 = gate_nand(n71, n70);
  y[0] = gate_nand(n73, n72);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_nand(a[3], a[3]);
  auto n3 = gate_nand(b[3], n1);
  auto n21 = gate_nand(b[3], b[3]);
  auto n2 = gate_nand(a[3], n21);
  auto n103 = gate_nand(n3, n2);
  auto n35 = gate_nand(a[0], a[3]);
  auto n4 = gate_nand(a[3], a[1]);
  auto n5 = gate_nand(n35, n4);
  auto n14 = gate_nand(a[2], a[2]);
  auto n8 = gate_nand(n5, n14);
  auto n6 = gate_nand(n5, n5);
  auto n7 = gate_nand(a[2], n6);
  auto n31 = gate_nand(n8, n7);
  auto n11 = gate_nand(b[2], n21);
  auto n9 = gate_nand(b[2], b[2]);
  auto n10 = gate_nand(b[3], n9);
  auto n73 = gate_nand(n11, n10);
  auto n30 = gate_nand(n73, n73);
  auto n33 = gate_nand(a[1], a[1]);
  auto n12 = gate_nand(a[0], a[0]);
  auto n13 = gate_nand(n33, n12);
  auto n15 = gate_nand(n13, n13);
  auto n16 = gate_nand(n15, n14);
  auto n17 = gate_nand(n16, n16);
  auto n43 = gate_nand(a[3], n17);
  auto n20 = gate_nand(b[1], n21);
  auto n18 = gate_nand(b[1], b[1]);
  auto n19 = gate_nand(b[3], n18);
  auto n57 = gate_nand(n20, n19);
  auto n24 = gate_nand(n43, n57);
  auto n22 = gate_nand(b[0], n31);
  auto n58 = gate_nand(b[0], b[0]);
  auto n77 = gate_nand(n21, n58);
  auto n23 = gate_nand(n22, n77);
  auto n28 = gate_nand(n24, n23);
  auto n52 = gate_nand(n57, n57);
  auto n92 = gate_nand(n43, n43);
  auto n88 = gate_nand(n52, n30);
  auto n26 = gate_nand(n92, n88);
  auto n25 = gate_nand(n92, n58);
  auto n46 = gate_nand(n26, n25);
  auto n27 = gate_nand(n52, n46);
  auto n29 = gate_nand(n28, n27);
  auto n100 = gate_nand(n30, n29);
  auto n32 = gate_nand(n31, n100);
  auto n50 = gate_nand(n32, n32);
  auto n40 = gate_nand(n32, n57);
  auto n34 = gate_nand(n35, n35);
  auto n37 = gate_nand(n34, n33);
  auto n36 = gate_nand(n35, a[1]);
  auto n59 = gate_nand(n37, n36);
  auto n38 = gate_nand(b[0], n59);
  auto n39 = gate_nand(n38, n77);
  auto n42 = gate_nand(n40, n39);
  auto n41 = gate_nand(n52, n50);
  auto n45 = gate_nand(n42, n41);
  auto n44 = gate_nand(n73, n43);
  auto n47 = gate_nand(n45, n44);
  auto n68 = gate_nand(n46, n100);
  auto n49 = gate_nand(n47, n68);
  auto n48 = gate_nand(n47, n73);
  auto n94 = gate_nand(n49, n48);
  auto n72 = gate_nand(n50, n94);
  auto n67 = gate_nand(n72, n73);
  auto n53 = gate_nand(b[0], a[0]);
  auto n51 = gate_nand(n53, n77);
  auto n65 = gate_nand(n52, n51);
  auto n55 = gate_nand(n53, b[0]);
  auto n54 = gate_nand(n53, b[3]);
  auto n56 = gate_nand(n55, n54);
  auto n63 = gate_nand(n57, n56);
  auto n61 = gate_nand(n59, n58);
  auto n60 = gate_nand(n59, n94);
  auto n62 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n69 = gate_nand(n67, n66);
  auto n71 = gate_nand(n69, n68);
  auto n95 = gate_nand(n94, n94);
  auto n70 = gate_nand(n69, n95);
  auto n74 = gate_nand(n71, n70);
  auto n76 = gate_nand(n74, n72);
  auto n75 = gate_nand(n74, n73);
  auto n81 = gate_nand(n76, n75);
  auto n93 = gate_nand(n103, n81);
  auto n79 = gate_nand(n103, n88);
  auto n78 = gate_nand(n103, n77);
  auto n80 = gate_nand(n79, n78);
  auto n85 = gate_nand(n80, n80);
  auto n83 = gate_nand(n81, n81);
  auto n82 = gate_nand(n103, n103);
  auto n84 = gate_nand(n83, n82);
  auto n86 = gate_nand(n85, n84);
  auto n87 = gate_nand(n93, n86);
  y[0] = gate_nand(n87, n87);
  auto n89 = gate_nand(n88, n88);
  auto n90 = gate_nand(b[0], n89);
  auto n91 = gate_nand(n90, n90);
  auto n105 = gate_nand(n92, n91);
  auto n112 = gate_nand(n93, n93);
  auto n97 = gate_nand(n94, n82);
  auto n96 = gate_nand(n103, n95);
  auto n98 = gate_nand(n97, n96);
  auto n111 = gate_nand(n98, n98);
  auto n113 = gate_nand(n112, n111);
  auto n107 = gate_nand(n113, n113);
  auto n99 = gate_nand(n100, n100);
  auto n102 = gate_nand(n99, n82);
  auto n101 = gate_nand(n103, n100);
  auto n106 = gate_nand(n102, n101);
  auto n108 = gate_nand(n107, n106);
  auto n104 = gate_nand(n103, n108);
  y[3] = gate_nand(n105, n104);
  auto n110 = gate_nand(n108, n106);
  auto n109 = gate_nand(n108, n107);
  y[2] = gate_nand(n110, n109);
  auto n115 = gate_nand(n113, n111);
  auto n114 = gate_nand(n113, n112);
  y[1] = gate_nand(n115, n114);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n51 = gate_nand(a[3], a[3]);
  auto n43 = gate_nand(a[2], a[2]);
  auto n30 = gate_nand(b[0], b[0]);
  auto n33 = gate_nand(n30, a[0]);
  auto n31 = gate_nand(a[0], a[0]);
  auto n32 = gate_nand(n31, b[0]);
  auto n34 = gate_nand(n33, n32);
  auto n38 = gate_nand(n34, n34);
  auto n35 = gate_nand(a[1], a[1]);
  auto n37 = gate_nand(n38, n35);
  auto n36 = gate_nand(b[1], b[1]);
  auto n41 = gate_nand(n37, n36);
  auto n39 = gate_nand(n38, a[1]);
  auto n40 = gate_nand(n39, b[1]);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, n42);
  auto n45 = gate_nand(n43, n46);
  auto n44 = gate_nand(b[2], b[2]);
  auto n49 = gate_nand(n45, n44);
  auto n47 = gate_nand(a[2], n46);
  auto n48 = gate_nand(n47, b[2]);
  auto n50 = gate_nand(n49, n48);
  auto n54 = gate_nand(n50, n50);
  auto n53 = gate_nand(n51, n54);
  auto n52 = gate_nand(b[3], b[3]);
  auto n57 = gate_nand(n53, n52);
  auto n55 = gate_nand(a[3], n54);
  auto n56 = gate_nand(n55, b[3]);
  auto n58 = gate_nand(n57, n56);
  auto _eq_x_1_n56 = gate_nand(n58, n58);
  y[0] = gate_buf(_eq_x_1_n56);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n20 = gate_nand(b[3], b[3]);
  auto n38 = gate_nand(n20, a[3]);
  auto n21 = gate_nand(a[3], a[3]);
  auto n36 = gate_nand(n21, b[3]);
  auto n22 = gate_nand(b[2], b[2]);
  auto n34 = gate_nand(n22, a[2]);
  auto n23 = gate_nand(a[1], a[1]);
  auto n32 = gate_nand(n23, b[1]);
  auto n24 = gate_nand(a[2], a[2]);
  auto n28 = gate_nand(n24, b[2]);
  auto n30 = gate_nand(n28, a[0]);
  auto n25 = gate_nand(b[1], b[1]);
  auto n26 = gate_nand(n25, a[1]);
  auto n27 = gate_nand(n26, b[0]);
  auto n29 = gate_nand(n28, n27);
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
  auto n20 = gate_nand(a[3], a[3]);
  auto n38 = gate_nand(n20, b[3]);
  auto n21 = gate_nand(b[3], b[3]);
  auto n36 = gate_nand(n21, a[3]);
  auto n22 = gate_nand(b[2], b[2]);
  auto n34 = gate_nand(n22, a[2]);
  auto n23 = gate_nand(a[1], a[1]);
  auto n32 = gate_nand(n23, b[1]);
  auto n24 = gate_nand(a[2], a[2]);
  auto n28 = gate_nand(n24, b[2]);
  auto n30 = gate_nand(n28, a[0]);
  auto n25 = gate_nand(b[1], b[1]);
  auto n26 = gate_nand(n25, a[1]);
  auto n27 = gate_nand(n26, b[0]);
  auto n29 = gate_nand(n28, n27);
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
  auto n26 = gate_nand(a[1], a[1]);
  auto n28 = gate_nand(n26, b[1]);
  auto n30 = gate_nand(n28, a[2]);
  auto n27 = gate_nand(b[2], b[2]);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n34 = gate_nand(a[0], n31);
  auto n32 = gate_nand(b[1], b[1]);
  auto n38 = gate_nand(a[1], n32);
  auto n33 = gate_nand(n38, b[2]);
  auto n35 = gate_nand(n33, a[2]);
  auto n37 = gate_nand(n34, n35);
  auto n36 = gate_nand(b[0], n35);
  auto n39 = gate_nand(n37, n36);
  auto n41 = gate_nand(n39, n38);
  auto n40 = gate_nand(n39, b[2]);
  auto n44 = gate_nand(n41, n40);
  auto n43 = gate_nand(n44, n44);
  auto n42 = gate_nand(b[3], b[3]);
  auto n47 = gate_nand(n43, n42);
  auto n45 = gate_nand(n44, b[3]);
  auto n46 = gate_nand(n45, a[3]);
  auto _gt_x_1_n55 = gate_nand(n47, n46);
  y[0] = gate_buf(_gt_x_1_n55);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_nand(a[1], a[1]);
  auto n28 = gate_nand(n26, b[1]);
  auto n30 = gate_nand(n28, a[2]);
  auto n27 = gate_nand(b[2], b[2]);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n34 = gate_nand(a[0], n31);
  auto n32 = gate_nand(b[1], b[1]);
  auto n38 = gate_nand(a[1], n32);
  auto n33 = gate_nand(n38, b[2]);
  auto n35 = gate_nand(n33, a[2]);
  auto n37 = gate_nand(n34, n35);
  auto n36 = gate_nand(b[0], n35);
  auto n39 = gate_nand(n37, n36);
  auto n41 = gate_nand(n39, n38);
  auto n40 = gate_nand(n39, b[2]);
  auto n44 = gate_nand(n41, n40);
  auto n43 = gate_nand(n44, n44);
  auto n42 = gate_nand(a[3], a[3]);
  auto n47 = gate_nand(n43, n42);
  auto n45 = gate_nand(n44, a[3]);
  auto n46 = gate_nand(n45, b[3]);
  auto _gt_x_1_n55 = gate_nand(n47, n46);
  y[0] = gate_buf(_gt_x_1_n55);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n20 = gate_nand(a[0], a[1]);
  auto n16 = gate_nand(n20, n20);
  auto n17 = gate_nand(n16, a[2]);
  auto n15 = gate_nand(a[3], n17);
  auto n13 = gate_nand(n17, n17);
  auto n12 = gate_nand(a[3], a[3]);
  auto n14 = gate_nand(n13, n12);
  y[3] = gate_nand(n15, n14);
  auto n19 = gate_nand(n17, a[2]);
  auto n18 = gate_nand(n17, n16);
  y[2] = gate_nand(n19, n18);
  auto n22 = gate_nand(n20, a[1]);
  auto n21 = gate_nand(n20, a[0]);
  y[1] = gate_nand(n22, n21);
  y[0] = gate_nand(a[0], a[0]);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n51 = gate_nand(a[3], a[3]);
  auto n43 = gate_nand(a[2], a[2]);
  auto n30 = gate_nand(b[0], b[0]);
  auto n33 = gate_nand(n30, a[0]);
  auto n31 = gate_nand(a[0], a[0]);
  auto n32 = gate_nand(n31, b[0]);
  auto n34 = gate_nand(n33, n32);
  auto n38 = gate_nand(n34, n34);
  auto n35 = gate_nand(a[1], a[1]);
  auto n37 = gate_nand(n38, n35);
  auto n36 = gate_nand(b[1], b[1]);
  auto n41 = gate_nand(n37, n36);
  auto n39 = gate_nand(n38, a[1]);
  auto n40 = gate_nand(n39, b[1]);
  auto n42 = gate_nand(n41, n40);
  auto n46 = gate_nand(n42, n42);
  auto n45 = gate_nand(n43, n46);
  auto n44 = gate_nand(b[2], b[2]);
  auto n49 = gate_nand(n45, n44);
  auto n47 = gate_nand(a[2], n46);
  auto n48 = gate_nand(n47, b[2]);
  auto n50 = gate_nand(n49, n48);
  auto n54 = gate_nand(n50, n50);
  auto n53 = gate_nand(n51, n54);
  auto n52 = gate_nand(b[3], b[3]);
  auto n57 = gate_nand(n53, n52);
  auto n55 = gate_nand(a[3], n54);
  auto n56 = gate_nand(n55, b[3]);
  y[0] = gate_nand(n57, n56);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n20 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(a[3], a[3]);
  auto n21 = gate_nand(n20, n19);
  auto n26 = gate_nand(n21, n21);
  auto n23 = gate_nand(a[2], a[2]);
  auto n22 = gate_nand(a[0], a[0]);
  auto n24 = gate_nand(n23, n22);
  auto n25 = gate_nand(n24, n24);
  auto n33 = gate_nand(n26, n25);
  auto n28 = gate_nand(n33, b[0]);
  auto n34 = gate_nand(n33, n33);
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
  auto n26 = gate_nand(a[3], a[3]);
  auto n45 = gate_nand(n26, b[3]);
  auto n27 = gate_nand(b[3], b[3]);
  auto n43 = gate_nand(n27, a[3]);
  auto n28 = gate_nand(a[2], a[2]);
  auto n36 = gate_nand(n28, b[2]);
  auto n30 = gate_nand(n36, a[1]);
  auto n33 = gate_nand(b[1], b[1]);
  auto n29 = gate_nand(n36, n33);
  auto n31 = gate_nand(n30, n29);
  auto n38 = gate_nand(n31, a[0]);
  auto n32 = gate_nand(b[2], b[2]);
  auto n35 = gate_nand(n32, a[2]);
  auto n34 = gate_nand(a[1], n33);
  auto n37 = gate_nand(n35, n34);
  auto n39 = gate_nand(n37, n36);
  auto n41 = gate_nand(n38, n39);
  auto n40 = gate_nand(b[0], n39);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  y[0] = gate_nand(n45, n44);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n26 = gate_nand(b[3], b[3]);
  auto n45 = gate_nand(n26, a[3]);
  auto n27 = gate_nand(a[3], a[3]);
  auto n43 = gate_nand(n27, b[3]);
  auto n28 = gate_nand(a[2], a[2]);
  auto n36 = gate_nand(n28, b[2]);
  auto n30 = gate_nand(n36, a[1]);
  auto n33 = gate_nand(b[1], b[1]);
  auto n29 = gate_nand(n36, n33);
  auto n31 = gate_nand(n30, n29);
  auto n38 = gate_nand(n31, a[0]);
  auto n32 = gate_nand(b[2], b[2]);
  auto n35 = gate_nand(n32, a[2]);
  auto n34 = gate_nand(a[1], n33);
  auto n37 = gate_nand(n35, n34);
  auto n39 = gate_nand(n37, n36);
  auto n41 = gate_nand(n38, n39);
  auto n40 = gate_nand(b[0], n39);
  auto n42 = gate_nand(n41, n40);
  auto n44 = gate_nand(n43, n42);
  y[0] = gate_nand(n45, n44);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_nand(b[0], b[0]);
  auto n18 = gate_nand(b[2], b[2]);
  auto n20 = gate_nand(n19, n18);
  auto n25 = gate_nand(n20, n20);
  auto n22 = gate_nand(b[1], b[1]);
  auto n21 = gate_nand(b[3], b[3]);
  auto n23 = gate_nand(n22, n21);
  auto n24 = gate_nand(n23, n23);
  auto n32 = gate_nand(n25, n24);
  auto n27 = gate_nand(a[2], a[2]);
  auto n26 = gate_nand(a[1], a[1]);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n32, n28);
  auto n29 = gate_nand(n32, a[0]);
  auto n31 = gate_nand(n30, n29);
  auto n34 = gate_nand(n31, n31);
  auto n33 = gate_nand(n32, a[3]);
  y[0] = gate_nand(n34, n33);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(a[3], a[3]);
  auto n13 = gate_nand(n12, n11);
  auto n18 = gate_nand(n13, n13);
  auto n15 = gate_nand(a[2], a[2]);
  auto n14 = gate_nand(a[0], a[0]);
  auto n16 = gate_nand(n15, n14);
  auto n17 = gate_nand(n16, n16);
  auto n19 = gate_nand(n18, n17);
  y[0] = gate_nand(n19, n19);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_nand(a[1], a[1]);
  auto n21 = gate_nand(a[3], a[3]);
  auto n23 = gate_nand(n22, n21);
  auto n28 = gate_nand(n23, n23);
  auto n25 = gate_nand(a[2], a[2]);
  auto n24 = gate_nand(a[0], a[0]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_nand(n26, n26);
  auto n29 = gate_nand(n28, n27);
  auto n40 = gate_nand(n29, n29);
  auto n31 = gate_nand(b[1], b[1]);
  auto n30 = gate_nand(b[3], b[3]);
  auto n32 = gate_nand(n31, n30);
  auto n37 = gate_nand(n32, n32);
  auto n34 = gate_nand(b[2], b[2]);
  auto n33 = gate_nand(b[0], b[0]);
  auto n35 = gate_nand(n34, n33);
  auto n36 = gate_nand(n35, n35);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_nand(n38, n38);
  y[0] = gate_nand(n40, n39);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_nand(a[3], a[3]);
  auto n42 = gate_nand(n21, b[3]);
  auto n22 = gate_nand(b[3], b[3]);
  auto n40 = gate_nand(n22, a[3]);
  auto n23 = gate_nand(a[2], a[2]);
  auto n35 = gate_nand(n23, b[2]);
  auto n24 = gate_nand(b[1], b[0]);
  auto n26 = gate_nand(n24, a[1]);
  auto n25 = gate_nand(a[0], a[1]);
  auto n27 = gate_nand(n26, n25);
  auto n37 = gate_nand(n35, n27);
  auto n30 = gate_nand(b[1], b[1]);
  auto n28 = gate_nand(a[0], a[0]);
  auto n29 = gate_nand(b[0], n28);
  auto n33 = gate_nand(n30, n29);
  auto n31 = gate_nand(b[2], b[2]);
  auto n32 = gate_nand(a[2], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_nand(n38, n38);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n21 = gate_nand(b[3], b[3]);
  auto n42 = gate_nand(n21, a[3]);
  auto n22 = gate_nand(a[3], a[3]);
  auto n40 = gate_nand(n22, b[3]);
  auto n23 = gate_nand(a[2], a[2]);
  auto n35 = gate_nand(n23, b[2]);
  auto n24 = gate_nand(b[1], b[0]);
  auto n26 = gate_nand(n24, a[1]);
  auto n25 = gate_nand(a[0], a[1]);
  auto n27 = gate_nand(n26, n25);
  auto n37 = gate_nand(n35, n27);
  auto n30 = gate_nand(b[1], b[1]);
  auto n28 = gate_nand(a[0], a[0]);
  auto n29 = gate_nand(b[0], n28);
  auto n33 = gate_nand(n30, n29);
  auto n31 = gate_nand(b[2], b[2]);
  auto n32 = gate_nand(a[2], n31);
  auto n34 = gate_nand(n33, n32);
  auto n36 = gate_nand(n35, n34);
  auto n38 = gate_nand(n37, n36);
  auto n39 = gate_nand(n38, n38);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n90 = gate_nand(b[3], b[3]);
  auto n52 = gate_nand(b[2], b[2]);
  auto n1 = gate_nand(a[1], a[1]);
  auto n42 = gate_nand(b[0], n1);
  auto n15 = gate_nand(n90, n52);
  auto n4 = gate_nand(n15, n15);
  auto n48 = gate_nand(b[1], b[1]);
  auto n2 = gate_nand(a[3], a[3]);
  auto n3 = gate_nand(b[1], n2);
  auto n5 = gate_nand(n4, n3);
  auto n7 = gate_nand(a[2], n5);
  auto n22 = gate_nand(b[0], b[0]);
  auto n6 = gate_nand(a[2], n22);
  auto n8 = gate_nand(n7, n6);
  auto n33 = gate_nand(n8, n8);
  auto n51 = gate_nand(b[1], n33);
  auto n18 = gate_nand(n8, n48);
  auto n21 = gate_nand(n51, n18);
  auto n32 = gate_nand(n42, n21);
  auto n9 = gate_nand(a[2], a[2]);
  auto n10 = gate_nand(n9, b[0]);
  auto n14 = gate_nand(n10, b[1]);
  auto n11 = gate_nand(n48, b[0]);
  auto n12 = gate_nand(n11, a[3]);
  auto n13 = gate_nand(n12, n12);
  auto n17 = gate_nand(n14, n13);
  auto n16 = gate_nand(n15, a[3]);
  auto n55 = gate_nand(n17, n16);
  auto n19 = gate_nand(n55, n52);
  auto n20 = gate_nand(n19, n18);
  auto n28 = gate_nand(n20, n90);
  auto n23 = gate_nand(n21, n21);
  auto n25 = gate_nand(n23, n22);
  auto n24 = gate_nand(n23, a[1]);
  auto n26 = gate_nand(n25, n24);
  auto n27 = gate_nand(n26, n90);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n29, n52);
  auto n30 = gate_nand(n29, a[3]);
  auto n53 = gate_nand(n31, n30);
  auto n36 = gate_nand(n32, n53);
  auto n34 = gate_nand(n53, n53);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n82 = gate_nand(n37, n37);
  auto n50 = gate_nand(n52, n82);
  auto n38 = gate_nand(b[2], n37);
  auto n40 = gate_nand(n38, n37);
  auto n39 = gate_nand(n38, b[2]);
  auto n76 = gate_nand(n40, n39);
  auto n41 = gate_nand(n53, b[0]);
  auto n45 = gate_nand(a[1], n41);
  auto n43 = gate_nand(n42, n42);
  auto n44 = gate_nand(n53, n43);
  auto n72 = gate_nand(n45, n44);
  auto n46 = gate_nand(n72, n72);
  auto n64 = gate_nand(b[1], n46);
  auto n47 = gate_nand(a[0], a[0]);
  auto n62 = gate_nand(b[0], n47);
  auto n49 = gate_nand(n64, n62);
  auto n65 = gate_nand(n48, n72);
  auto n75 = gate_nand(n49, n65);
  auto n81 = gate_nand(n76, n75);
  auto n87 = gate_nand(n50, n81);
  auto n57 = gate_nand(n90, n87);
  auto n54 = gate_nand(n51, n52);
  auto n56 = gate_nand(n54, n53);
  auto n85 = gate_nand(n56, n55);
  auto n60 = gate_nand(n57, n85);
  auto n58 = gate_nand(n87, n87);
  auto n59 = gate_nand(b[3], n58);
  auto n86 = gate_nand(n60, n59);
  auto n77 = gate_nand(n86, n86);
  auto n61 = gate_nand(n77, b[0]);
  auto n63 = gate_nand(a[0], n61);
  auto n66 = gate_nand(n62, n62);
  auto n68 = gate_nand(n77, n66);
  y[0] = gate_nand(n63, n68);
  auto n67 = gate_nand(n65, n64);
  auto n71 = gate_nand(n66, n67);
  auto n69 = gate_nand(n77, n67);
  auto n70 = gate_nand(n69, n68);
  auto n74 = gate_nand(n71, n70);
  auto n73 = gate_nand(n86, n72);
  y[1] = gate_nand(n74, n73);
  auto n79 = gate_nand(n77, n75);
  auto n78 = gate_nand(n77, n76);
  auto n80 = gate_nand(n79, n78);
  auto n84 = gate_nand(n81, n80);
  auto n83 = gate_nand(n86, n82);
  y[2] = gate_nand(n84, n83);
  auto n88 = gate_nand(n85, n85);
  auto n93 = gate_nand(n86, n88);
  auto n89 = gate_nand(n88, n87);
  auto n91 = gate_nand(n89, n89);
  auto n92 = gate_nand(n91, n90);
  y[3] = gate_nand(n93, n92);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n98 = gate_nand(b[3], b[3]);
  auto n3 = gate_nand(b[2], n98);
  auto n1 = gate_nand(b[2], b[2]);
  auto n2 = gate_nand(b[3], n1);
  auto n67 = gate_nand(n3, n2);
  auto n6 = gate_nand(b[1], n98);
  auto n4 = gate_nand(b[1], b[1]);
  auto n5 = gate_nand(b[3], n4);
  auto n57 = gate_nand(n6, n5);
  auto n52 = gate_nand(n57, n57);
  auto n86 = gate_nand(a[3], a[0]);
  auto n9 = gate_nand(a[3], a[1]);
  auto n10 = gate_nand(n86, n9);
  auto n18 = gate_nand(a[2], a[2]);
  auto n13 = gate_nand(n10, n18);
  auto n11 = gate_nand(n10, n10);
  auto n12 = gate_nand(a[2], n11);
  auto n14 = gate_nand(n13, n12);
  auto n28 = gate_nand(a[1], a[1]);
  auto n81 = gate_nand(a[0], a[0]);
  auto n17 = gate_nand(n28, n81);
  auto n19 = gate_nand(n17, n17);
  auto n20 = gate_nand(n19, n18);
  auto n22 = gate_nand(n20, n20);
  auto n24 = gate_nand(n22, n67);
  auto n21 = gate_nand(b[0], n52);
  auto n23 = gate_nand(n22, n21);
  auto n25 = gate_nand(n24, n23);
  auto n26 = gate_nand(a[3], n25);
  auto n29 = gate_nand(n86, n86);
  auto n31 = gate_nand(n29, n28);
  auto n30 = gate_nand(a[1], n86);
  auto n48 = gate_nand(n31, n30);
  auto n32 = gate_nand(b[0], n48);
  auto n34 = gate_nand(n32, b[0]);
  auto n33 = gate_nand(n32, b[3]);
  auto n40 = gate_nand(n34, n33);
  auto n60 = gate_nand(n67, n67);
  auto n7 = gate_nand(n60, n52);
  auto n8 = gate_nand(n7, n7);
  auto n15 = gate_nand(n8, b[0]);
  auto n27 = gate_nand(n15, n14);
  auto n39 = gate_nand(n27, n27);
  auto n36 = gate_nand(n27, n57);
  auto n41 = gate_nand(n39, n52);
  auto n35 = gate_nand(n41, n40);
  auto n113 = gate_nand(n36, n35);
  auto n46 = gate_nand(n48, n48);
  auto n99 = gate_nand(b[0], a[0]);
  auto n54 = gate_nand(n99, b[0]);
  auto n53 = gate_nand(n99, b[3]);
  auto n55 = gate_nand(n54, n53);
  auto n82 = gate_nand(a[3], a[3]);
  auto n83 = gate_nand(n82, n81);
  auto n84 = gate_nand(n83, n86);
  auto n88 = gate_nand(n86, a[0]);
  auto n87 = gate_nand(n86, a[3]);
  auto n89 = gate_nand(n88, n87);
  auto n97 = gate_nand(b[0], b[0]);
  auto n100 = gate_nand(n98, n97);
  auto n102 = gate_nand(n100, n99);
  auto n114 = gate_nand(n113, n113);
  auto n62 = gate_nand(n26, n26);
  auto n112 = gate_nand(n62, n60);
  auto n37 = gate_nand(n112, n113);
  auto n61 = gate_nand(n60, n37);
  auto n42 = gate_nand(n39, n61);
  auto n44 = gate_nand(n42, n40);
  auto n43 = gate_nand(n42, n41);
  auto n66 = gate_nand(n44, n43);
  auto n76 = gate_nand(n66, n66);
  auto n45 = gate_nand(n61, n61);
  auto n49 = gate_nand(b[0], n45);
  auto n47 = gate_nand(n49, n49);
  auto n51 = gate_nand(n47, n46);
  auto n50 = gate_nand(n49, n48);
  auto n56 = gate_nand(n51, n50);
  auto n95 = gate_nand(n56, n52);
  auto n58 = gate_nand(n95, n55);
  auto n94 = gate_nand(n56, n56);
  auto n96 = gate_nand(n57, n94);
  auto n68 = gate_nand(n58, n96);
  auto n59 = gate_nand(n68, n68);
  auto n74 = gate_nand(n60, n59);
  auto n63 = gate_nand(n62, n61);
  auto n64 = gate_nand(n67, n66);
  auto n65 = gate_nand(n64, n64);
  auto n73 = gate_nand(n63, n65);
  auto n70 = gate_nand(n68, n66);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n72 = gate_nand(n63, n71);
  auto n93 = gate_nand(n73, n72);
  auto n103 = gate_nand(n93, n93);
  auto n75 = gate_nand(n74, n103);
  auto n78 = gate_nand(n76, n75);
  auto n77 = gate_nand(n78, n78);
  auto n80 = gate_nand(n77, n82);
  auto n79 = gate_nand(n78, a[3]);
  auto n119 = gate_nand(n80, n79);
  auto n90 = gate_nand(b[0], n103);
  auto n85 = gate_nand(n90, n90);
  auto n92 = gate_nand(n85, n84);
  auto n91 = gate_nand(n90, n89);
  auto n129 = gate_nand(n92, n91);
  auto n130 = gate_nand(a[3], n129);
  auto n110 = gate_nand(n130, n130);
  auto n109 = gate_nand(n94, n93);
  auto n101 = gate_nand(n96, n95);
  auto n107 = gate_nand(n101, n102);
  auto n105 = gate_nand(n103, n101);
  auto n104 = gate_nand(n103, n102);
  auto n106 = gate_nand(n105, n104);
  auto n108 = gate_nand(n107, n106);
  auto n125 = gate_nand(n109, n108);
  auto n111 = gate_nand(n110, n125);
  auto n118 = gate_nand(n111, n111);
  auto n120 = gate_nand(n119, n118);
  auto n117 = gate_nand(a[3], n120);
  auto n115 = gate_nand(n112, n112);
  auto n116 = gate_nand(n115, n114);
  y[3] = gate_nand(n117, n116);
  auto n122 = gate_nand(n120, n118);
  auto n121 = gate_nand(n120, n119);
  y[2] = gate_nand(n122, n121);
  auto n123 = gate_nand(n129, n129);
  auto n131 = gate_nand(a[3], n123);
  auto n124 = gate_nand(n131, n131);
  auto n128 = gate_nand(n124, n125);
  auto n126 = gate_nand(n125, n125);
  auto n127 = gate_nand(n131, n126);
  y[1] = gate_nand(n128, n127);
  auto n132 = gate_nand(n130, n129);
  y[0] = gate_nand(n132, n131);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nand(b[0], a[0]);
  y[0] = gate_nand(n6, n6);
  auto n3 = gate_nand(b[0], a[1]);
  auto n1 = gate_nand(n3, n3);
  auto n2 = gate_nand(b[1], a[0]);
  auto n5 = gate_nand(n1, n2);
  auto n26 = gate_nand(n2, n2);
  auto n4 = gate_nand(n3, n26);
  y[1] = gate_nand(n5, n4);
  auto n16 = gate_nand(a[1], b[1]);
  auto n20 = gate_nand(n16, n16);
  auto n8 = gate_nand(n20, n6);
  auto n7 = gate_nand(n8, n8);
  auto n25 = gate_nand(b[0], a[2]);
  auto n10 = gate_nand(n7, n25);
  auto n18 = gate_nand(n25, n25);
  auto n9 = gate_nand(n18, n8);
  auto n13 = gate_nand(n10, n9);
  auto n12 = gate_nand(n13, n13);
  auto n17 = gate_nand(a[0], b[2]);
  auto n11 = gate_nand(n17, n17);
  auto n15 = gate_nand(n12, n11);
  auto n14 = gate_nand(n13, n17);
  y[2] = gate_nand(n15, n14);
  auto n33 = gate_nand(b[1], a[2]);
  auto n32 = gate_nand(n33, n33);
  auto n19 = gate_nand(n17, n16);
  auto n24 = gate_nand(n19, n18);
  auto n21 = gate_nand(n20, y[0]);
  auto n37 = gate_nand(a[1], b[2]);
  auto n22 = gate_nand(n21, n37);
  auto n23 = gate_nand(n26, n22);
  auto n28 = gate_nand(n24, n23);
  auto n30 = gate_nand(n28, n25);
  auto n39 = gate_nand(n37, n37);
  auto n27 = gate_nand(n39, n26);
  auto n29 = gate_nand(n28, n27);
  auto n34 = gate_nand(n30, n29);
  auto n31 = gate_nand(n34, n34);
  auto n36 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n50 = gate_nand(n36, n35);
  auto n40 = gate_nand(a[3], b[0]);
  auto n38 = gate_nand(n40, n40);
  auto n42 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  auto n44 = gate_nand(n42, n41);
  auto n43 = gate_nand(a[0], b[3]);
  auto n48 = gate_nand(n44, n43);
  auto n46 = gate_nand(n43, n43);
  auto n45 = gate_nand(n44, n44);
  auto n47 = gate_nand(n46, n45);
  auto n52 = gate_nand(n48, n47);
  auto n49 = gate_nand(n52, n52);
  auto n54 = gate_nand(n50, n49);
  auto n51 = gate_nand(n50, n50);
  auto n53 = gate_nand(n52, n51);
  y[3] = gate_nand(n54, n53);
}
template<> void $NameUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[1], a[3]);
  auto n9 = gate_nand(n6, n6);
  auto n7 = gate_nand(a[2], a[0]);
  auto n8 = gate_nand(n7, n7);
  auto n10 = gate_nand(n9, n8);
  y[0] = gate_nand(n10, n10);
}
template<> void $NameUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n6 = gate_nand(a[1], a[3]);
  auto n9 = gate_nand(n6, n6);
  auto n7 = gate_nand(a[2], a[0]);
  auto n8 = gate_nand(n7, n7);
  y[0] = gate_nand(n9, n8);
}
template<> void $NameUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n12 = gate_nand(a[1], a[1]);
  auto n11 = gate_nand(a[3], a[3]);
  auto n13 = gate_nand(n12, n11);
  auto n18 = gate_nand(n13, n13);
  auto n15 = gate_nand(a[2], a[2]);
  auto n14 = gate_nand(a[0], a[0]);
  auto n16 = gate_nand(n15, n14);
  auto n17 = gate_nand(n16, n16);
  auto n19 = gate_nand(n18, n17);
  y[0] = gate_nand(n19, n19);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_nand(a[1], a[1]);
  auto n9 = gate_nand(a[3], a[3]);
  auto n11 = gate_nand(n10, n9);
  auto n16 = gate_nand(n11, n11);
  auto n13 = gate_nand(a[2], a[2]);
  auto n12 = gate_nand(a[0], a[0]);
  auto n14 = gate_nand(n13, n12);
  auto n15 = gate_nand(n14, n14);
  y[0] = gate_nand(n16, n15);
}
template<> void $NameUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n16 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(a[2], n16);
  auto n17 = gate_nand(a[2], a[2]);
  auto n18 = gate_nand(a[1], n17);
  auto n21 = gate_nand(n19, n18);
  auto n20 = gate_nand(a[0], a[0]);
  auto n24 = gate_nand(n21, n20);
  auto n22 = gate_nand(n21, n21);
  auto n23 = gate_nand(a[0], n22);
  auto n27 = gate_nand(n24, n23);
  auto n26 = gate_nand(n27, n27);
  auto n25 = gate_nand(a[3], a[3]);
  auto n29 = gate_nand(n26, n25);
  auto n28 = gate_nand(n27, a[3]);
  y[0] = gate_nand(n29, n28);
}
template<> void $NameUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n15 = gate_nand(a[1], a[1]);
  auto n18 = gate_nand(a[0], n15);
  auto n16 = gate_nand(a[0], a[0]);
  auto n17 = gate_nand(a[1], n16);
  auto n24 = gate_nand(n18, n17);
  auto n19 = gate_nand(a[2], a[2]);
  auto n22 = gate_nand(a[3], n19);
  auto n20 = gate_nand(a[3], a[3]);
  auto n21 = gate_nand(a[2], n20);
  auto n26 = gate_nand(n22, n21);
  auto n23 = gate_nand(n26, n26);
  auto n28 = gate_nand(n24, n23);
  auto n25 = gate_nand(n24, n24);
  auto n27 = gate_nand(n26, n25);
  y[0] = gate_nand(n28, n27);
}
template<> void $NameUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n36 = gate_nand(b[2], b[2]);
  auto n35 = gate_nand(b[3], b[3]);
  auto n37 = gate_nand(n36, n35);
  auto n60 = gate_nand(n37, n37);
  auto n38 = gate_nand(b[1], b[1]);
  auto n39 = gate_nand(n60, n38);
  auto n45 = gate_nand(n39, n39);
  auto n47 = gate_nand(b[0], b[0]);
  auto n40 = gate_nand(n45, n47);
  auto n55 = gate_nand(n40, n40);
  auto n41 = gate_nand(a[0], n55);
  y[0] = gate_nand(n41, n41);
  auto n43 = gate_nand(n47, a[1]);
  auto n42 = gate_nand(b[0], a[0]);
  auto n56 = gate_nand(n43, n42);
  auto n44 = gate_nand(n45, n56);
  y[1] = gate_nand(n44, n44);
  auto n46 = gate_nand(b[0], n45);
  auto n57 = gate_nand(n46, n46);
  auto n54 = gate_nand(n57, a[1]);
  auto n48 = gate_nand(a[0], n47);
  auto n49 = gate_nand(n55, a[2]);
  auto n52 = gate_nand(n48, n49);
  auto n50 = gate_nand(b[1], n60);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  y[2] = gate_nand(n54, n53);
  auto n63 = gate_nand(a[3], n55);
  auto n59 = gate_nand(n56, b[1]);
  auto n58 = gate_nand(n57, a[2]);
  auto n61 = gate_nand(n59, n58);
  auto n62 = gate_nand(n61, n60);
  y[3] = gate_nand(n63, n62);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n33 = gate_nand(b[3], b[3]);
  auto n32 = gate_nand(b[2], b[2]);
  auto n34 = gate_nand(n33, n32);
  auto n37 = gate_nand(n34, n34);
  auto n35 = gate_nand(b[1], b[1]);
  auto n36 = gate_nand(n37, n35);
  auto n49 = gate_nand(n36, n36);
  auto n40 = gate_nand(a[1], n49);
  auto n44 = gate_nand(b[1], n37);
  auto n38 = gate_nand(n44, n44);
  auto n39 = gate_nand(n38, a[3]);
  auto n52 = gate_nand(n40, n39);
  auto n48 = gate_nand(n52, b[0]);
  auto n51 = gate_nand(b[0], b[0]);
  auto n42 = gate_nand(n51, a[2]);
  auto n41 = gate_nand(n49, n51);
  auto n58 = gate_nand(n41, n41);
  auto n43 = gate_nand(n58, a[0]);
  auto n46 = gate_nand(n42, n43);
  auto n45 = gate_nand(n44, n43);
  auto n47 = gate_nand(n46, n45);
  y[0] = gate_nand(n48, n47);
  auto n50 = gate_nand(b[0], n49);
  auto n55 = gate_nand(n50, n50);
  auto n54 = gate_nand(n55, a[2]);
  auto n53 = gate_nand(n52, n51);
  y[1] = gate_nand(n54, n53);
  auto n57 = gate_nand(n58, a[2]);
  auto n56 = gate_nand(n55, a[3]);
  y[2] = gate_nand(n57, n56);
  auto n59 = gate_nand(a[3], n58);
  y[3] = gate_nand(n59, n59);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n43 = gate_nand(a[3], a[3]);
  auto n55 = gate_nand(b[3], b[3]);
  auto n48 = gate_nand(b[2], b[2]);
  auto n60 = gate_nand(n55, n48);
  auto n54 = gate_nand(n43, n60);
  auto n69 = gate_nand(b[0], b[0]);
  auto n45 = gate_nand(n69, a[0]);
  auto n44 = gate_nand(b[0], a[1]);
  auto n46 = gate_nand(n45, n44);
  auto n61 = gate_nand(b[1], b[1]);
  auto n52 = gate_nand(n46, n61);
  auto n47 = gate_nand(a[2], b[1]);
  auto n50 = gate_nand(n47, n48);
  auto n49 = gate_nand(b[0], n48);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n59 = gate_nand(n54, n53);
  auto n56 = gate_nand(b[0], b[1]);
  auto n57 = gate_nand(n56, n55);
  auto n58 = gate_nand(n57, a[3]);
  y[0] = gate_nand(n59, n58);
  auto n67 = gate_nand(a[3], b[0]);
  auto n63 = gate_nand(a[2], n69);
  auto n62 = gate_nand(n60, n60);
  auto n68 = gate_nand(n62, n61);
  auto n74 = gate_nand(a[3], n68);
  auto n65 = gate_nand(n63, n74);
  auto n64 = gate_nand(n68, n74);
  auto n66 = gate_nand(n65, n64);
  y[2] = gate_nand(n67, n66);
  auto n73 = gate_nand(n68, n68);
  auto n71 = gate_nand(n69, a[1]);
  auto n70 = gate_nand(b[0], a[2]);
  auto n72 = gate_nand(n71, n70);
  auto n75 = gate_nand(n73, n72);
  y[1] = gate_nand(n75, n74);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n35 = gate_nand(b[0], b[0]);
  auto n37 = gate_nand(n35, a[0]);
  auto n36 = gate_nand(a[0], a[0]);
  auto n41 = gate_nand(b[0], n36);
  y[0] = gate_nand(n37, n41);
  auto n38 = gate_nand(b[1], b[1]);
  auto n49 = gate_nand(a[1], n38);
  auto n40 = gate_nand(n49, n38);
  auto n39 = gate_nand(n49, a[1]);
  auto n42 = gate_nand(n40, n39);
  auto n48 = gate_nand(n42, n41);
  auto n44 = gate_nand(n48, n41);
  auto n43 = gate_nand(n48, n42);
  y[1] = gate_nand(n44, n43);
  auto n45 = gate_nand(b[2], b[2]);
  auto n59 = gate_nand(a[2], n45);
  auto n47 = gate_nand(n59, n45);
  auto n46 = gate_nand(n59, a[2]);
  auto n51 = gate_nand(n47, n46);
  auto n50 = gate_nand(n49, n48);
  auto n58 = gate_nand(n51, n50);
  auto n53 = gate_nand(n58, n50);
  auto n52 = gate_nand(n58, n51);
  y[2] = gate_nand(n53, n52);
  auto n54 = gate_nand(b[3], b[3]);
  auto n57 = gate_nand(a[3], n54);
  auto n55 = gate_nand(a[3], a[3]);
  auto n56 = gate_nand(b[3], n55);
  auto n63 = gate_nand(n57, n56);
  auto n61 = gate_nand(n63, n63);
  auto n62 = gate_nand(n59, n58);
  auto n60 = gate_nand(n62, n62);
  auto n65 = gate_nand(n61, n60);
  auto n64 = gate_nand(n63, n62);
  y[3] = gate_nand(n65, n64);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n15 = gate_nand(a[0], a[0]);
  auto n16 = gate_nand(a[1], a[1]);
  auto n19 = gate_nand(n15, n16);
  auto n18 = gate_nand(n19, n15);
  auto n17 = gate_nand(n19, n16);
  y[1] = gate_nand(n18, n17);
  auto n23 = gate_nand(a[2], a[2]);
  auto n21 = gate_nand(n19, n23);
  auto n22 = gate_nand(n19, n19);
  auto n20 = gate_nand(a[2], n22);
  y[2] = gate_nand(n21, n20);
  auto n26 = gate_nand(n23, n22);
  auto n24 = gate_nand(n26, n26);
  auto n28 = gate_nand(n24, a[3]);
  auto n25 = gate_nand(a[3], a[3]);
  auto n27 = gate_nand(n26, n25);
  y[3] = gate_nand(n28, n27);
}
