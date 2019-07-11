template<> void $NameUint<4>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n63 = gate_nor(b[0], a[0]);
  auto n66 = gate_nor(b[2], a[2]);
  auto n67 = gate_nor(b[1], a[1]);
  auto n69 = gate_not(b[0]);
  auto n68 = gate_not(a[0]);
  auto n72 = gate_or(n69, n68);
  auto n71 = gate_not(b[1]);
  auto n70 = gate_not(a[1]);
  auto n60 = gate_nor(n71, n70);
  auto n73 = gate_or(n60, n67);
  auto n64 = gate_nor(n72, n73);
  auto n87 = gate_not(n72);
  y[0] = gate_nor(n87, n63);
  auto n74 = gate_not(n73);
  auto n59 = gate_nor(n87, n74);
  y[1] = gate_nor(n64, n59);
  auto n79 = gate_or(n60, n64);
  auto n77 = gate_not(n79);
  auto n76 = gate_not(b[2]);
  auto n75 = gate_not(a[2]);
  auto n58 = gate_nor(n76, n75);
  auto n78 = gate_or(n58, n66);
  auto n61 = gate_nor(n77, n78);
  auto n80 = gate_not(n78);
  auto n52 = gate_nor(n80, n79);
  y[2] = gate_nor(n61, n52);
  auto n81 = gate_not(b[3]);
  auto n62 = gate_nor(a[3], n81);
  auto n82 = gate_not(a[3]);
  auto n56 = gate_nor(b[3], n82);
  auto n84 = gate_or(n62, n56);
  auto n85 = gate_not(n84);
  auto n83 = gate_or(n58, n61);
  auto n65 = gate_nor(n84, n83);
  auto n86 = gate_not(n83);
  auto n55 = gate_nor(n86, n85);
  y[3] = gate_nor(n65, n55);
}
template<> void $NameUint<4>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n18 = gate_not(a[3]);
  auto n23 = gate_not(b[0]);
  auto n17 = gate_not(b[3]);
  y[3] = gate_nor(n18, n17);
  auto n20 = gate_not(a[2]);
  auto n19 = gate_not(b[2]);
  y[2] = gate_nor(n20, n19);
  auto n22 = gate_not(a[1]);
  auto n21 = gate_not(b[1]);
  y[1] = gate_nor(n22, n21);
  auto n24 = gate_not(a[0]);
  y[0] = gate_nor(n24, n23);
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
  y[3] = gate_or(a[3], b[3]);
  y[2] = gate_or(a[2], b[2]);
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<4>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n33 = gate_not(b[3]);
  auto n32 = gate_nor(a[3], n33);
  auto n34 = gate_not(a[3]);
  auto n26 = gate_nor(b[3], n34);
  y[3] = gate_or(n32, n26);
  auto n35 = gate_not(b[2]);
  auto n29 = gate_nor(a[2], n35);
  auto n36 = gate_not(a[2]);
  auto n27 = gate_nor(b[2], n36);
  y[2] = gate_or(n29, n27);
  auto n37 = gate_not(b[1]);
  auto n30 = gate_nor(a[1], n37);
  auto n38 = gate_not(a[1]);
  auto n25 = gate_nor(b[1], n38);
  y[1] = gate_or(n30, n25);
  auto n39 = gate_not(b[0]);
  auto n31 = gate_nor(a[0], n39);
  auto n40 = gate_not(a[0]);
  auto n28 = gate_nor(b[0], n40);
  y[0] = gate_or(n31, n28);
}
template<> void $NameUint<4>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n8 = gate_not(b[3]);
  y[3] = gate_nor(n9, n8);
  auto n5 = gate_not(b[0]);
  y[0] = gate_nor(n9, n5);
  auto n6 = gate_not(b[1]);
  y[1] = gate_nor(n9, n6);
  auto n7 = gate_not(b[2]);
  y[2] = gate_nor(n9, n7);
}
template<> void $NameUint<4>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n30 = gate_nor(a[0], c[3]);
  auto n34 = gate_not(a[0]);
  auto n22 = gate_nor(b[0], n34);
  auto n24 = gate_nor(b[2], n34);
  auto n27 = gate_nor(b[3], n34);
  y[3] = gate_nor(n27, n30);
  auto n29 = gate_nor(b[1], n34);
  auto n31 = gate_nor(a[0], c[2]);
  y[2] = gate_nor(n24, n31);
  auto n32 = gate_nor(a[0], c[1]);
  y[1] = gate_nor(n29, n32);
  auto n33 = gate_nor(a[0], c[0]);
  y[0] = gate_nor(n22, n33);
}
template<> void $NameUint<4>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n22 = gate_or(a[0], a[1]);
  auto n20 = gate_or(a[2], n22);
  auto n19 = gate_nor(a[3], n20);
  auto n24 = gate_not(n20);
  auto n21 = gate_not(a[3]);
  auto n17 = gate_nor(n24, n21);
  y[3] = gate_or(n19, n17);
  auto n26 = gate_not(n22);
  auto n23 = gate_not(a[2]);
  auto n18 = gate_nor(n26, n23);
  y[2] = gate_or(n24, n18);
  y[0] = gate_not(a[0]);
  auto n25 = gate_not(a[1]);
  auto n16 = gate_nor(y[0], n25);
  y[1] = gate_or(n26, n16);
}
template<> void $NameUint<4>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n60 = gate_not(b[0]);
  auto n19 = gate_nor(a[0], n60);
  auto n20 = gate_nor(n60, a[2]);
  auto n24 = gate_nor(n60, a[3]);
  auto n35 = gate_not(b[1]);
  auto n26 = gate_nor(n35, a[3]);
  auto n29 = gate_or(b[3], b[2]);
  auto n33 = gate_or(n26, n29);
  y[2] = gate_nor(n20, n33);
  auto n14 = gate_nor(n60, n33);
  auto n32 = gate_not(a[3]);
  auto n61 = gate_or(b[1], n29);
  y[3] = gate_nor(n24, n61);
  auto n30 = gate_not(n61);
  auto n31 = gate_or(n30, y[2]);
  auto n44 = gate_or(n32, n31);
  auto n38 = gate_not(n44);
  auto n34 = gate_not(a[2]);
  auto n51 = gate_or(n14, n34);
  auto n17 = gate_nor(b[1], n51);
  auto n36 = gate_not(n51);
  auto n15 = gate_nor(n36, n35);
  auto n4 = gate_nor(n17, n15);
  auto n52 = gate_or(a[1], n60);
  auto n23 = gate_nor(n17, n52);
  auto n39 = gate_or(n15, n23);
  auto n16 = gate_nor(n39, n44);
  auto n37 = gate_not(n39);
  auto n2 = gate_nor(n38, n37);
  auto n57 = gate_not(b[2]);
  auto n42 = gate_or(n57, n16);
  auto n40 = gate_not(n42);
  auto n41 = gate_or(b[3], n40);
  auto n55 = gate_or(n2, n41);
  y[1] = gate_not(n55);
  auto n10 = gate_nor(y[1], n51);
  auto n43 = gate_or(b[3], n42);
  auto n27 = gate_nor(n44, n43);
  auto n45 = gate_not(b[3]);
  auto n25 = gate_nor(n45, a[3]);
  auto n46 = gate_or(n55, n60);
  auto n22 = gate_nor(a[1], n46);
  auto n47 = gate_not(n46);
  auto n48 = gate_not(a[1]);
  auto n3 = gate_nor(n47, n48);
  auto n5 = gate_nor(y[1], n48);
  auto n13 = gate_nor(n22, n3);
  auto n7 = gate_nor(n19, n13);
  auto n49 = gate_or(a[0], n5);
  auto n18 = gate_nor(n49, n60);
  auto n8 = gate_nor(b[1], n18);
  auto n58 = gate_or(n7, n8);
  auto n11 = gate_nor(n58, n57);
  auto n50 = gate_not(n58);
  auto n21 = gate_nor(b[2], n50);
  auto n53 = gate_not(n52);
  auto n54 = gate_or(n53, n4);
  auto n28 = gate_nor(n55, n54);
  auto n56 = gate_or(n10, n28);
  auto n6 = gate_nor(n21, n56);
  auto n59 = gate_or(n6, n11);
  auto n1 = gate_nor(n25, n59);
  y[0] = gate_or(n27, n1);
}
template<> void $NameUint<4>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n74 = gate_not(a[3]);
  auto n28 = gate_nor(b[3], n74);
  auto n64 = gate_or(a[1], a[0]);
  auto n53 = gate_or(a[2], n64);
  auto n76 = gate_or(n74, n53);
  auto n54 = gate_not(b[2]);
  auto n48 = gate_nor(b[3], n54);
  auto n82 = gate_not(b[3]);
  auto n16 = gate_nor(b[2], n82);
  auto n26 = gate_nor(b[1], n82);
  auto n27 = gate_nor(b[0], n82);
  auto n38 = gate_nor(a[3], n82);
  auto n93 = gate_or(n48, n16);
  auto n55 = gate_not(b[1]);
  auto n47 = gate_nor(b[3], n55);
  auto n83 = gate_or(n26, n47);
  auto n8 = gate_nor(n83, n27);
  auto n86 = gate_not(b[0]);
  auto n56 = gate_or(n83, n86);
  auto n62 = gate_or(n93, n56);
  auto n52 = gate_nor(n76, n62);
  auto n89 = gate_not(n93);
  auto n106 = gate_or(b[0], b[3]);
  auto n79 = gate_not(n106);
  auto n57 = gate_not(a[0]);
  auto n59 = gate_or(n74, n57);
  auto n41 = gate_nor(a[1], n59);
  auto n58 = gate_not(n59);
  auto n85 = gate_not(a[1]);
  auto n5 = gate_nor(n58, n85);
  auto n13 = gate_nor(n5, n41);
  auto n22 = gate_nor(n13, n86);
  auto n61 = gate_or(n79, n22);
  auto n60 = gate_not(n61);
  auto n33 = gate_nor(n83, n60);
  auto n80 = gate_not(n83);
  auto n7 = gate_nor(n80, n61);
  auto n63 = gate_not(n62);
  auto n73 = gate_or(n63, n76);
  auto n51 = gate_nor(n83, n73);
  auto n65 = gate_not(n64);
  auto n68 = gate_or(n65, n74);
  auto n35 = gate_nor(a[2], n68);
  auto n67 = gate_not(n68);
  auto n66 = gate_not(a[2]);
  auto n30 = gate_nor(n67, n66);
  auto n32 = gate_nor(n30, n35);
  auto n31 = gate_nor(n32, n86);
  auto n69 = gate_or(n79, n31);
  auto n19 = gate_nor(n51, n69);
  auto n70 = gate_not(n76);
  auto n11 = gate_nor(n70, n80);
  auto n71 = gate_or(n19, n11);
  auto n97 = gate_or(n93, n71);
  auto n96 = gate_not(n97);
  auto n50 = gate_nor(n96, n73);
  auto n91 = gate_or(n96, n32);
  auto n37 = gate_nor(n7, n91);
  auto n78 = gate_or(n33, n37);
  auto n9 = gate_nor(n89, n78);
  auto n72 = gate_not(n78);
  auto n45 = gate_nor(n93, n72);
  auto n18 = gate_nor(n45, n50);
  auto n75 = gate_or(n9, n18);
  auto n110 = gate_or(n28, n38);
  auto n43 = gate_nor(n110, n97);
  auto n107 = gate_not(n110);
  auto n12 = gate_nor(n75, n107);
  auto n14 = gate_nor(n96, n107);
  auto n90 = gate_not(n75);
  auto n20 = gate_nor(n90, n86);
  auto n44 = gate_nor(n110, n90);
  auto n102 = gate_or(n12, n44);
  auto n77 = gate_or(n76, n89);
  auto n49 = gate_nor(n78, n77);
  auto n81 = gate_or(n79, n20);
  auto n25 = gate_nor(n81, n80);
  auto n21 = gate_nor(n25, n13);
  auto n1 = gate_nor(n21, n8);
  auto n84 = gate_or(n83, n90);
  auto n6 = gate_nor(n85, n84);
  auto n87 = gate_or(n86, a[0]);
  auto n34 = gate_nor(n6, n87);
  auto n94 = gate_or(n1, n34);
  auto n39 = gate_nor(n94, n93);
  auto n88 = gate_not(n94);
  auto n10 = gate_nor(n89, n88);
  auto n92 = gate_or(n91, n90);
  auto n36 = gate_nor(n10, n92);
  auto n95 = gate_or(n36, n39);
  auto n108 = gate_or(n49, n95);
  auto n109 = gate_not(n108);
  auto n42 = gate_nor(n110, n109);
  auto n101 = gate_or(n107, n108);
  auto n99 = gate_or(n102, n101);
  auto n100 = gate_or(n14, n43);
  auto n98 = gate_not(n100);
  auto n40 = gate_nor(n99, n98);
  auto n15 = gate_nor(n40, n107);
  y[3] = gate_or(n52, n15);
  auto n104 = gate_not(n99);
  auto n4 = gate_nor(n104, n100);
  y[2] = gate_nor(n40, n4);
  auto n111 = gate_not(n101);
  auto n103 = gate_not(n102);
  auto n3 = gate_nor(n111, n103);
  y[1] = gate_nor(n104, n3);
  auto n105 = gate_or(b[2], b[1]);
  auto n46 = gate_nor(n106, n105);
  auto n29 = gate_nor(n46, n107);
  auto n17 = gate_nor(n29, n42);
  y[0] = gate_nor(n111, n17);
}
template<> void $NameUint<4>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[1]);
  auto n36 = gate_nor(b[1], n41);
  auto n42 = gate_not(b[1]);
  auto n38 = gate_nor(a[1], n42);
  auto n54 = gate_or(n36, n38);
  auto n43 = gate_not(a[0]);
  auto n32 = gate_nor(b[0], n43);
  auto n44 = gate_not(b[0]);
  auto n39 = gate_nor(a[0], n44);
  auto n52 = gate_or(n32, n39);
  auto n45 = gate_not(a[3]);
  auto n34 = gate_nor(b[3], n45);
  auto n46 = gate_not(b[3]);
  auto n40 = gate_nor(a[3], n46);
  auto n50 = gate_or(n34, n40);
  auto n47 = gate_not(a[2]);
  auto n33 = gate_nor(b[2], n47);
  auto n48 = gate_not(b[2]);
  auto n37 = gate_nor(a[2], n48);
  auto n49 = gate_or(n33, n37);
  auto n51 = gate_or(n50, n49);
  auto n53 = gate_or(n52, n51);
  y[0] = gate_nor(n54, n53);
}
template<> void $NameUint<4>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[0]);
  auto n41 = gate_or(n38, a[0]);
  auto n36 = gate_nor(a[1], n41);
  auto n34 = gate_nor(b[1], n36);
  auto n40 = gate_not(n41);
  auto n39 = gate_not(a[1]);
  auto n30 = gate_nor(n40, n39);
  auto n43 = gate_or(n30, n34);
  auto n42 = gate_not(a[2]);
  auto n33 = gate_nor(n42, b[2]);
  auto n29 = gate_nor(n43, n33);
  auto n44 = gate_not(b[3]);
  auto n35 = gate_nor(a[3], n44);
  auto n45 = gate_not(b[2]);
  auto n37 = gate_nor(a[2], n45);
  auto n46 = gate_or(n35, n37);
  auto n31 = gate_nor(n29, n46);
  auto n47 = gate_not(a[3]);
  auto n32 = gate_nor(b[3], n47);
  auto _gte_x_1_n50 = gate_or(n31, n32);
  y[0] = gate_buf(_gte_x_1_n50);
}
template<> void $NameUint<4>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n38 = gate_not(b[0]);
  auto n41 = gate_or(n38, a[0]);
  auto n36 = gate_nor(a[1], n41);
  auto n34 = gate_nor(b[1], n36);
  auto n40 = gate_not(n41);
  auto n39 = gate_not(a[1]);
  auto n30 = gate_nor(n40, n39);
  auto n43 = gate_or(n30, n34);
  auto n42 = gate_not(a[2]);
  auto n32 = gate_nor(n42, b[2]);
  auto n29 = gate_nor(n43, n32);
  auto n44 = gate_not(a[3]);
  auto n31 = gate_nor(b[3], n44);
  auto n45 = gate_not(b[2]);
  auto n37 = gate_nor(a[2], n45);
  auto n46 = gate_or(n31, n37);
  auto n33 = gate_nor(n29, n46);
  auto n47 = gate_not(b[3]);
  auto n35 = gate_nor(a[3], n47);
  auto _gte_x_1_n50 = gate_or(n33, n35);
  y[0] = gate_buf(_gte_x_1_n50);
}
template<> void $NameUint<4>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(a[2]);
  auto n46 = gate_not(b[3]);
  auto n34 = gate_nor(n40, b[2]);
  auto n41 = gate_not(a[0]);
  auto n44 = gate_or(n41, b[0]);
  auto n38 = gate_nor(b[1], n44);
  auto n36 = gate_nor(a[1], n38);
  auto n43 = gate_not(n44);
  auto n42 = gate_not(b[1]);
  auto n35 = gate_nor(n43, n42);
  auto n32 = gate_nor(n35, n36);
  auto n30 = gate_nor(n34, n32);
  auto n45 = gate_not(b[2]);
  auto n39 = gate_nor(a[2], n45);
  auto n48 = gate_or(n30, n39);
  auto n37 = gate_nor(b[3], n48);
  auto n29 = gate_nor(a[3], n37);
  auto n47 = gate_not(n48);
  auto n31 = gate_nor(n47, n46);
  y[0] = gate_nor(n31, n29);
}
template<> void $NameUint<4>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(a[2]);
  auto n46 = gate_not(a[3]);
  auto n34 = gate_nor(n40, b[2]);
  auto n41 = gate_not(a[0]);
  auto n44 = gate_or(n41, b[0]);
  auto n37 = gate_nor(b[1], n44);
  auto n29 = gate_nor(a[1], n37);
  auto n43 = gate_not(n44);
  auto n42 = gate_not(b[1]);
  auto n31 = gate_nor(n43, n42);
  auto n33 = gate_nor(n31, n29);
  auto n30 = gate_nor(n34, n33);
  auto n45 = gate_not(b[2]);
  auto n39 = gate_nor(a[2], n45);
  auto n48 = gate_or(n30, n39);
  auto n38 = gate_nor(a[3], n48);
  auto n32 = gate_nor(b[3], n38);
  auto n47 = gate_not(n48);
  auto n36 = gate_nor(n47, n46);
  y[0] = gate_nor(n36, n32);
}
template<> void $NameUint<4>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n23 = gate_nor(a[0], a[1]);
  y[0] = gate_not(a[0]);
  auto n24 = gate_not(a[1]);
  auto n28 = gate_or(y[0], n24);
  auto n30 = gate_not(n28);
  y[1] = gate_nor(n30, n23);
  auto n21 = gate_nor(n30, a[2]);
  auto n25 = gate_not(a[2]);
  auto n26 = gate_or(n28, n25);
  auto n22 = gate_nor(a[3], n26);
  auto n29 = gate_not(n26);
  y[2] = gate_nor(n29, n21);
  auto n27 = gate_not(a[3]);
  auto n19 = gate_nor(n29, n27);
  y[3] = gate_or(n22, n19);
}
template<> void $NameUint<4>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(b[0]);
  auto n38 = gate_nor(a[0], n40);
  auto n41 = gate_not(a[0]);
  auto n35 = gate_nor(b[0], n41);
  auto n45 = gate_or(n38, n35);
  auto n42 = gate_not(b[1]);
  auto n37 = gate_nor(a[1], n42);
  auto n43 = gate_not(a[1]);
  auto n32 = gate_nor(b[1], n43);
  auto n44 = gate_or(n37, n32);
  auto n53 = gate_or(n45, n44);
  auto n46 = gate_not(b[2]);
  auto n36 = gate_nor(a[2], n46);
  auto n47 = gate_not(a[2]);
  auto n34 = gate_nor(b[2], n47);
  auto n51 = gate_or(n36, n34);
  auto n48 = gate_not(b[3]);
  auto n39 = gate_nor(a[3], n48);
  auto n49 = gate_not(a[3]);
  auto n33 = gate_nor(b[3], n49);
  auto n50 = gate_or(n39, n33);
  auto n52 = gate_or(n51, n50);
  y[0] = gate_or(n53, n52);
}
template<> void $NameUint<4>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n38 = gate_or(a[1], a[0]);
  auto n37 = gate_or(a[3], a[2]);
  auto n39 = gate_or(n38, n37);
  auto n40 = gate_not(n39);
  auto n27 = gate_nor(n40, b[1]);
  auto n29 = gate_nor(n40, b[3]);
  auto n30 = gate_nor(n40, b[2]);
  auto n32 = gate_nor(n40, b[0]);
  auto n33 = gate_nor(c[3], n39);
  y[3] = gate_nor(n33, n29);
  auto n34 = gate_nor(c[2], n39);
  y[2] = gate_nor(n34, n30);
  auto n35 = gate_nor(c[1], n39);
  y[1] = gate_nor(n35, n27);
  auto n36 = gate_nor(c[0], n39);
  y[0] = gate_nor(n36, n32);
}
template<> void $NameUint<4>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[2]);
  auto n34 = gate_nor(n41, b[2]);
  auto n42 = gate_not(a[0]);
  auto n45 = gate_or(n42, b[0]);
  auto n39 = gate_nor(b[1], n45);
  auto n37 = gate_nor(a[1], n39);
  auto n44 = gate_not(n45);
  auto n43 = gate_not(b[1]);
  auto n32 = gate_nor(n44, n43);
  auto n35 = gate_nor(n32, n37);
  auto n36 = gate_nor(n34, n35);
  auto n46 = gate_not(b[2]);
  auto n40 = gate_nor(a[2], n46);
  auto n49 = gate_or(n36, n40);
  auto n38 = gate_nor(b[3], n49);
  auto n31 = gate_nor(a[3], n38);
  auto n48 = gate_not(n49);
  auto n47 = gate_not(b[3]);
  auto n33 = gate_nor(n48, n47);
  y[0] = gate_or(n33, n31);
}
template<> void $NameUint<4>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n41 = gate_not(a[2]);
  auto n35 = gate_nor(n41, b[2]);
  auto n42 = gate_not(a[0]);
  auto n45 = gate_or(n42, b[0]);
  auto n38 = gate_nor(b[1], n45);
  auto n31 = gate_nor(a[1], n38);
  auto n44 = gate_not(n45);
  auto n43 = gate_not(b[1]);
  auto n32 = gate_nor(n44, n43);
  auto n34 = gate_nor(n32, n31);
  auto n36 = gate_nor(n35, n34);
  auto n46 = gate_not(b[2]);
  auto n40 = gate_nor(a[2], n46);
  auto n49 = gate_or(n36, n40);
  auto n39 = gate_nor(a[3], n49);
  auto n33 = gate_nor(b[3], n39);
  auto n48 = gate_not(n49);
  auto n47 = gate_not(a[3]);
  auto n37 = gate_nor(n48, n47);
  y[0] = gate_or(n37, n33);
}
template<> void $NameUint<4>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_or(a[2], a[1]);
  auto n15 = gate_or(b[2], b[1]);
  auto n13 = gate_or(a[0], a[3]);
  auto n10 = gate_nor(n14, n13);
  auto n16 = gate_or(b[0], b[3]);
  auto n12 = gate_nor(n16, n15);
  y[0] = gate_nor(n10, n12);
}
template<> void $NameUint<4>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_or(a[1], a[0]);
  auto n6 = gate_or(a[3], a[2]);
  y[0] = gate_nor(n7, n6);
}
template<> void $NameUint<4>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_or(a[1], a[0]);
  auto n7 = gate_or(a[3], a[2]);
  auto n12 = gate_or(n8, n7);
  auto n10 = gate_or(b[1], b[0]);
  auto n9 = gate_or(b[3], b[2]);
  auto n11 = gate_or(n10, n9);
  y[0] = gate_or(n12, n11);
}
template<> void $NameUint<4>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(a[2]);
  auto n34 = gate_nor(n40, b[2]);
  auto n41 = gate_not(b[0]);
  auto n44 = gate_or(n41, a[0]);
  auto n38 = gate_nor(a[1], n44);
  auto n33 = gate_nor(b[1], n38);
  auto n43 = gate_not(n44);
  auto n42 = gate_not(a[1]);
  auto n35 = gate_nor(n43, n42);
  auto n45 = gate_or(n35, n33);
  auto n32 = gate_nor(n34, n45);
  auto n46 = gate_not(b[2]);
  auto n39 = gate_nor(a[2], n46);
  auto n49 = gate_or(n32, n39);
  auto n37 = gate_nor(b[3], n49);
  auto n31 = gate_nor(a[3], n37);
  auto n48 = gate_not(n49);
  auto n47 = gate_not(b[3]);
  auto n36 = gate_nor(n48, n47);
  y[0] = gate_or(n36, n31);
}
template<> void $NameUint<4>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(a[2]);
  auto n34 = gate_nor(n40, b[2]);
  auto n41 = gate_not(b[0]);
  auto n44 = gate_or(n41, a[0]);
  auto n38 = gate_nor(a[1], n44);
  auto n36 = gate_nor(b[1], n38);
  auto n43 = gate_not(n44);
  auto n42 = gate_not(a[1]);
  auto n32 = gate_nor(n43, n42);
  auto n45 = gate_or(n32, n36);
  auto n31 = gate_nor(n34, n45);
  auto n46 = gate_not(b[2]);
  auto n39 = gate_nor(a[2], n46);
  auto n49 = gate_or(n31, n39);
  auto n37 = gate_nor(a[3], n49);
  auto n33 = gate_nor(b[3], n37);
  auto n48 = gate_not(n49);
  auto n47 = gate_not(a[3]);
  auto n35 = gate_nor(n48, n47);
  y[0] = gate_or(n35, n33);
}
template<> void $NameUint<4>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n71 = gate_not(b[0]);
  auto n21 = gate_nor(a[2], n71);
  auto n42 = gate_or(b[3], b[2]);
  auto n60 = gate_not(b[1]);
  auto n19 = gate_nor(a[3], n60);
  auto n39 = gate_or(n21, n19);
  auto n41 = gate_or(n42, n39);
  auto n37 = gate_nor(n60, n41);
  auto n38 = gate_nor(n71, n41);
  auto n40 = gate_not(a[2]);
  auto n65 = gate_or(n38, n40);
  auto n23 = gate_nor(b[1], n65);
  auto n59 = gate_not(n65);
  auto n18 = gate_nor(n59, n60);
  auto n62 = gate_or(a[1], n71);
  auto n30 = gate_nor(n23, n62);
  auto n49 = gate_or(n18, n30);
  auto n28 = gate_nor(n49, b[2]);
  auto n43 = gate_or(n71, n42);
  auto n36 = gate_nor(b[1], n43);
  auto n44 = gate_not(a[3]);
  auto n45 = gate_or(n36, n44);
  auto n48 = gate_or(n37, n45);
  auto n20 = gate_nor(n49, n48);
  auto n56 = gate_not(b[2]);
  auto n16 = gate_nor(n20, n56);
  auto n52 = gate_or(n16, b[3]);
  auto n35 = gate_nor(n52, n28);
  auto n86 = gate_or(n35, n48);
  auto n67 = gate_not(n86);
  auto n46 = gate_or(a[0], n71);
  auto n32 = gate_nor(n60, n46);
  auto n47 = gate_not(n46);
  auto n2 = gate_nor(b[1], n47);
  auto n51 = gate_not(n48);
  auto n50 = gate_not(n49);
  auto n4 = gate_nor(n51, n50);
  auto n64 = gate_or(n52, n4);
  auto n55 = gate_or(n71, n64);
  auto n29 = gate_nor(a[1], n55);
  auto n54 = gate_not(n55);
  auto n53 = gate_not(a[1]);
  auto n14 = gate_nor(n54, n53);
  auto n77 = gate_or(n14, n29);
  auto n26 = gate_nor(n2, n77);
  auto n58 = gate_or(n32, n26);
  auto n27 = gate_nor(b[2], n58);
  auto n57 = gate_not(n58);
  auto n17 = gate_nor(n57, n56);
  auto n61 = gate_or(n59, n64);
  auto n34 = gate_nor(n61, n60);
  auto n11 = gate_nor(n34, n23);
  auto n63 = gate_not(n62);
  auto n9 = gate_nor(n11, n63);
  auto n66 = gate_not(n64);
  auto n12 = gate_nor(n66, n65);
  auto n82 = gate_or(n9, n12);
  auto n84 = gate_not(n82);
  auto n7 = gate_nor(n27, n82);
  auto n68 = gate_or(n17, n7);
  auto n33 = gate_nor(b[3], n68);
  auto n13 = gate_nor(n67, n33);
  auto n70 = gate_not(b[3]);
  auto n69 = gate_not(n68);
  auto n15 = gate_nor(n70, n69);
  auto n85 = gate_or(n13, n15);
  auto n10 = gate_nor(n85, n33);
  y[3] = gate_nor(n10, n86);
  auto n74 = gate_or(n71, n85);
  auto n31 = gate_nor(a[0], n74);
  auto n73 = gate_not(n74);
  auto n72 = gate_not(a[0]);
  auto n3 = gate_nor(n73, n72);
  y[0] = gate_or(n3, n31);
  auto n75 = gate_or(n32, n2);
  auto n78 = gate_or(n85, n75);
  auto n76 = gate_not(n78);
  auto n25 = gate_nor(n76, n77);
  auto n79 = gate_not(n77);
  auto n6 = gate_nor(n79, n78);
  y[1] = gate_nor(n25, n6);
  auto n80 = gate_or(n17, n27);
  auto n83 = gate_or(n85, n80);
  auto n22 = gate_nor(n84, n83);
  auto n81 = gate_not(n83);
  auto n8 = gate_nor(n81, n82);
  y[2] = gate_nor(n8, n22);
}
template<> void $NameUint<4>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n42 = gate_nor(b[0], b[3]);
  auto n51 = gate_nor(a[3], a[0]);
  auto n85 = gate_not(b[0]);
  auto n52 = gate_not(b[2]);
  auto n44 = gate_nor(b[3], n52);
  auto n53 = gate_not(b[3]);
  auto n20 = gate_nor(b[1], n53);
  auto n28 = gate_nor(b[2], n53);
  auto n81 = gate_or(n44, n28);
  auto n54 = gate_not(b[1]);
  auto n43 = gate_nor(b[3], n54);
  auto n71 = gate_or(n20, n43);
  auto n55 = gate_or(n81, n71);
  auto n7 = gate_nor(n85, n55);
  auto n65 = gate_or(a[0], a[1]);
  auto n56 = gate_not(n65);
  auto n113 = gate_not(a[3]);
  auto n59 = gate_or(n56, n113);
  auto n47 = gate_nor(a[2], n59);
  auto n58 = gate_not(n59);
  auto n57 = gate_not(a[2]);
  auto n16 = gate_nor(n58, n57);
  auto n18 = gate_nor(n16, n47);
  auto n69 = gate_or(n7, n18);
  auto n70 = gate_not(a[0]);
  auto n22 = gate_nor(n70, n85);
  auto n61 = gate_or(n113, n70);
  auto n37 = gate_nor(a[1], n61);
  auto n86 = gate_not(n61);
  auto n60 = gate_not(a[1]);
  auto n26 = gate_nor(n86, n60);
  auto n78 = gate_or(n26, n37);
  auto n75 = gate_not(n78);
  auto n10 = gate_nor(n75, n85);
  auto n63 = gate_or(n42, n10);
  auto n62 = gate_not(n63);
  auto n36 = gate_nor(n71, n62);
  auto n73 = gate_not(n71);
  auto n21 = gate_nor(n73, n63);
  auto n41 = gate_nor(n69, n21);
  auto n68 = gate_or(n36, n41);
  auto n64 = gate_not(n68);
  auto n39 = gate_nor(n81, n64);
  auto n67 = gate_or(n7, a[2]);
  auto n66 = gate_or(n65, n113);
  auto n82 = gate_or(n67, n66);
  auto n79 = gate_not(n81);
  auto n5 = gate_nor(n79, n68);
  auto n46 = gate_nor(n82, n5);
  auto n23 = gate_nor(n39, n46);
  auto n8 = gate_nor(n39, n23);
  auto n9 = gate_nor(n36, n23);
  auto n99 = gate_or(n69, n9);
  auto n49 = gate_nor(a[3], n99);
  auto n74 = gate_or(n42, n22);
  auto n3 = gate_nor(n74, n73);
  auto n72 = gate_not(n74);
  auto n35 = gate_nor(n72, n71);
  auto n77 = gate_or(n23, n85);
  auto n31 = gate_nor(n78, n77);
  auto n76 = gate_not(n77);
  auto n6 = gate_nor(n76, n75);
  auto n91 = gate_or(n6, n31);
  auto n19 = gate_nor(n91, n113);
  auto n92 = gate_not(n91);
  auto n1 = gate_nor(n3, n92);
  auto n50 = gate_nor(a[3], n92);
  auto n80 = gate_or(n35, n1);
  auto n4 = gate_nor(n79, n80);
  auto n40 = gate_nor(n99, n4);
  auto n106 = gate_not(n80);
  auto n38 = gate_nor(n81, n106);
  auto n105 = gate_or(n82, n8);
  auto n45 = gate_nor(n106, n105);
  auto n83 = gate_not(n105);
  auto n84 = gate_or(n38, n83);
  auto n24 = gate_nor(n40, n84);
  auto n89 = gate_or(n85, n24);
  auto n87 = gate_not(n89);
  auto n88 = gate_or(n86, n51);
  auto n30 = gate_nor(n87, n88);
  auto n90 = gate_not(n88);
  auto n17 = gate_nor(n90, n89);
  auto n117 = gate_or(n30, n17);
  auto n48 = gate_nor(a[3], n117);
  auto n112 = gate_not(n117);
  auto n95 = gate_or(n19, n50);
  auto n93 = gate_or(n3, n24);
  auto n94 = gate_or(n35, n93);
  auto n34 = gate_nor(n95, n94);
  auto n97 = gate_not(n94);
  auto n96 = gate_not(n95);
  auto n12 = gate_nor(n97, n96);
  auto n116 = gate_or(n34, n12);
  auto n114 = gate_not(n116);
  auto n107 = gate_or(n112, n114);
  auto n98 = gate_not(n99);
  auto n25 = gate_nor(n98, n113);
  auto n102 = gate_or(n25, n49);
  auto n100 = gate_or(n38, n24);
  auto n101 = gate_or(n4, n100);
  auto n33 = gate_nor(n102, n101);
  auto n104 = gate_not(n101);
  auto n103 = gate_not(n102);
  auto n11 = gate_nor(n104, n103);
  auto n111 = gate_or(n33, n11);
  auto n108 = gate_not(n111);
  auto n2 = gate_nor(n107, n108);
  auto n27 = gate_nor(n2, n113);
  y[3] = gate_or(n27, n45);
  auto n110 = gate_or(n113, n107);
  auto n29 = gate_nor(n111, n110);
  auto n109 = gate_not(n110);
  auto n14 = gate_nor(n109, n108);
  y[2] = gate_or(n14, n29);
  auto n115 = gate_or(n113, n112);
  auto n32 = gate_nor(n116, n115);
  auto n118 = gate_not(n115);
  y[0] = gate_nor(n118, n48);
  auto n15 = gate_nor(n118, n114);
  y[1] = gate_or(n15, n32);
}
template<> void $NameUint<4>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n46 = gate_not(a[0]);
  auto n47 = gate_not(b[0]);
  auto n29 = gate_or(n46, n47);
  y[0] = gate_not(n29);
  auto n38 = gate_not(a[1]);
  auto n21 = gate_or(n38, n47);
  auto n19 = gate_not(n21);
  auto n35 = gate_not(b[1]);
  auto n20 = gate_or(n35, n46);
  auto n9 = gate_nor(n19, n20);
  auto n40 = gate_not(n20);
  auto n14 = gate_nor(n40, n21);
  y[1] = gate_or(n9, n14);
  auto n37 = gate_not(b[2]);
  auto n23 = gate_or(n37, n46);
  auto n22 = gate_not(n23);
  auto n30 = gate_or(n38, n35);
  auto n18 = gate_nor(n22, n30);
  auto n24 = gate_not(n30);
  auto n6 = gate_nor(n24, n23);
  auto n28 = gate_or(n18, n6);
  auto n25 = gate_not(n28);
  auto n36 = gate_not(a[2]);
  auto n26 = gate_or(n47, n36);
  auto n11 = gate_nor(n25, n26);
  auto n27 = gate_not(n26);
  auto n8 = gate_nor(n28, n27);
  auto n31 = gate_or(n11, n8);
  auto n32 = gate_or(n30, n29);
  auto n17 = gate_nor(n31, n32);
  auto n34 = gate_not(n31);
  auto n33 = gate_not(n32);
  auto n4 = gate_nor(n34, n33);
  y[2] = gate_nor(n17, n4);
  auto n43 = gate_or(n36, n35);
  auto n41 = gate_not(n43);
  auto n39 = gate_or(n38, n37);
  auto n42 = gate_or(n40, n39);
  auto n10 = gate_nor(n41, n42);
  auto n44 = gate_not(n42);
  auto n15 = gate_nor(n44, n43);
  auto n54 = gate_or(n10, n15);
  auto n45 = gate_not(b[3]);
  auto n51 = gate_or(n46, n45);
  auto n49 = gate_not(n51);
  auto n48 = gate_not(a[3]);
  auto n50 = gate_or(n48, n47);
  auto n13 = gate_nor(n49, n50);
  auto n52 = gate_not(n50);
  auto n7 = gate_nor(n52, n51);
  auto n56 = gate_or(n13, n7);
  auto n53 = gate_not(n56);
  auto n3 = gate_nor(n54, n53);
  auto n55 = gate_not(n54);
  auto n12 = gate_nor(n56, n55);
  auto n58 = gate_or(n3, n12);
  auto n59 = gate_not(n58);
  auto n57 = gate_or(n11, n17);
  auto n16 = gate_nor(n58, n57);
  auto n60 = gate_not(n57);
  auto n1 = gate_nor(n60, n59);
  y[3] = gate_nor(n16, n1);
}
template<> void $NameUint<4>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n10 = gate_not(a[2]);
  auto n9 = gate_not(a[0]);
  auto n14 = gate_or(n10, n9);
  auto n12 = gate_not(a[1]);
  auto n11 = gate_not(a[3]);
  auto n13 = gate_or(n12, n11);
  y[0] = gate_nor(n14, n13);
}
template<> void $NameUint<4>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n9 = gate_not(a[2]);
  auto n8 = gate_not(a[0]);
  auto n13 = gate_or(n9, n8);
  auto n11 = gate_not(a[1]);
  auto n10 = gate_not(a[3]);
  auto n12 = gate_or(n11, n10);
  y[0] = gate_or(n13, n12);
}
template<> void $NameUint<4>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_or(a[1], a[0]);
  auto n6 = gate_or(a[3], a[2]);
  y[0] = gate_nor(n7, n6);
}
template<> void $NameUint<4>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_or(a[1], a[0]);
  auto n3 = gate_or(a[3], a[2]);
  y[0] = gate_or(n4, n3);
}
template<> void $NameUint<4>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n30 = gate_not(a[1]);
  auto n24 = gate_nor(a[0], n30);
  auto n31 = gate_not(a[0]);
  auto n29 = gate_nor(a[1], n31);
  auto n35 = gate_or(n24, n29);
  auto n36 = gate_not(n35);
  auto n32 = gate_not(a[2]);
  auto n28 = gate_nor(a[3], n32);
  auto n33 = gate_not(a[3]);
  auto n26 = gate_nor(a[2], n33);
  auto n37 = gate_or(n28, n26);
  auto n27 = gate_nor(n37, n36);
  auto n34 = gate_not(n37);
  auto n23 = gate_nor(n35, n34);
  y[0] = gate_nor(n23, n27);
}
template<> void $NameUint<4>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n27 = gate_not(a[1]);
  auto n22 = gate_nor(a[0], n27);
  auto n28 = gate_not(a[0]);
  auto n26 = gate_nor(a[1], n28);
  auto n32 = gate_or(n22, n26);
  auto n29 = gate_not(a[2]);
  auto n24 = gate_nor(a[3], n29);
  auto n30 = gate_not(a[3]);
  auto n23 = gate_nor(a[2], n30);
  auto n34 = gate_or(n24, n23);
  auto n31 = gate_not(n34);
  auto n21 = gate_nor(n32, n31);
  auto n33 = gate_not(n32);
  auto n25 = gate_nor(n34, n33);
  y[0] = gate_or(n21, n25);
}
template<> void $NameUint<4>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n55 = gate_nor(b[0], a[1]);
  auto n62 = gate_not(a[0]);
  auto n60 = gate_or(b[3], b[2]);
  auto n63 = gate_or(b[1], n60);
  auto n68 = gate_or(b[0], n63);
  y[0] = gate_nor(n62, n68);
  auto n58 = gate_not(b[0]);
  auto n56 = gate_nor(a[0], n58);
  auto n65 = gate_or(n56, n55);
  y[1] = gate_nor(n65, n63);
  auto n59 = gate_not(a[1]);
  auto n67 = gate_or(n58, n63);
  auto n48 = gate_nor(n59, n67);
  auto n61 = gate_not(b[1]);
  auto n64 = gate_or(n61, n60);
  auto n46 = gate_nor(n62, n64);
  auto n53 = gate_nor(n65, n64);
  auto n66 = gate_not(a[2]);
  auto n49 = gate_nor(n63, n66);
  auto n50 = gate_nor(n67, n66);
  auto n51 = gate_nor(n46, n49);
  auto n57 = gate_nor(n51, b[0]);
  y[2] = gate_or(n48, n57);
  auto n70 = gate_or(n53, n50);
  auto n69 = gate_not(a[3]);
  auto n47 = gate_nor(n69, n68);
  y[3] = gate_or(n70, n47);
}
template<> void $NameUint<4>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n55 = gate_not(b[0]);
  auto n50 = gate_not(a[1]);
  auto n51 = gate_or(b[2], b[3]);
  auto n56 = gate_or(b[1], n51);
  auto n41 = gate_nor(n50, n56);
  auto n52 = gate_not(b[1]);
  auto n53 = gate_or(n52, n51);
  auto n60 = gate_not(a[3]);
  auto n45 = gate_nor(n53, n60);
  auto n38 = gate_nor(n41, n45);
  auto n39 = gate_nor(n55, n38);
  auto n48 = gate_nor(b[0], n38);
  auto n57 = gate_not(a[2]);
  auto n43 = gate_nor(n53, n57);
  auto n54 = gate_not(a[0]);
  auto n40 = gate_nor(n56, n54);
  auto n37 = gate_nor(n43, n40);
  auto n49 = gate_nor(n37, b[0]);
  auto _ashr_1_n12 = gate_or(n39, n49);
  y[0] = gate_buf(_ashr_1_n12);
  auto n58 = gate_or(n55, n56);
  auto n42 = gate_nor(n57, n58);
  auto n47 = gate_nor(n60, n58);
  auto _ashr_1_n9 = gate_or(n42, n48);
  y[1] = gate_buf(_ashr_1_n9);
  auto n59 = gate_or(b[0], n56);
  y[3] = gate_nor(n60, n59);
  auto n46 = gate_nor(n57, n59);
  auto _ashr_1_n6 = gate_or(n46, n47);
  y[2] = gate_buf(_ashr_1_n6);
}
template<> void $NameUint<4>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[3] = gate_buf(a[3]);
  auto n61 = gate_nor(b[0], a[1]);
  auto n77 = gate_not(a[3]);
  auto n74 = gate_not(b[0]);
  auto n64 = gate_nor(a[2], n74);
  auto n70 = gate_not(b[1]);
  auto n59 = gate_nor(n74, n70);
  auto n75 = gate_or(b[3], b[2]);
  auto n67 = gate_nor(n59, n75);
  auto n53 = gate_nor(n77, n67);
  auto n68 = gate_not(a[1]);
  auto n58 = gate_nor(n68, b[1]);
  auto n52 = gate_nor(n58, n74);
  auto n69 = gate_not(a[0]);
  auto n54 = gate_nor(n69, b[1]);
  auto n71 = gate_not(a[2]);
  auto n57 = gate_nor(n71, n70);
  auto n72 = gate_or(n54, n57);
  auto n60 = gate_nor(b[0], n72);
  auto n73 = gate_or(n52, n60);
  auto n66 = gate_nor(n73, n75);
  y[0] = gate_or(n53, n66);
  auto n76 = gate_or(n64, n61);
  auto n79 = gate_or(b[1], n75);
  auto n65 = gate_nor(n76, n79);
  auto n78 = gate_not(n79);
  auto n55 = gate_nor(n78, n77);
  y[1] = gate_or(n65, n55);
  auto n80 = gate_or(b[0], n79);
  auto n63 = gate_nor(a[2], n80);
  auto n81 = gate_not(n80);
  auto n62 = gate_nor(n81, a[3]);
  y[2] = gate_nor(n63, n62);
}
template<> void $NameUint<4>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n64 = gate_not(b[0]);
  auto n70 = gate_or(a[0], n64);
  auto n68 = gate_not(n70);
  auto n65 = gate_not(a[0]);
  auto n51 = gate_nor(b[0], n65);
  y[0] = gate_or(n68, n51);
  auto n66 = gate_not(a[1]);
  auto n57 = gate_nor(b[1], n66);
  auto n67 = gate_not(b[1]);
  auto n59 = gate_nor(a[1], n67);
  auto n69 = gate_or(n57, n59);
  auto n53 = gate_nor(n68, n69);
  auto n71 = gate_not(n69);
  auto n63 = gate_nor(n71, n70);
  y[1] = gate_nor(n53, n63);
  auto n76 = gate_or(n57, n53);
  auto n74 = gate_not(n76);
  auto n72 = gate_not(a[2]);
  auto n56 = gate_nor(b[2], n72);
  auto n73 = gate_not(b[2]);
  auto n62 = gate_nor(a[2], n73);
  auto n75 = gate_or(n56, n62);
  auto n60 = gate_nor(n74, n75);
  auto n77 = gate_not(n75);
  auto n49 = gate_nor(n77, n76);
  y[2] = gate_nor(n60, n49);
  auto n78 = gate_not(b[3]);
  auto n61 = gate_nor(a[3], n78);
  auto n79 = gate_not(a[3]);
  auto n54 = gate_nor(b[3], n79);
  auto n81 = gate_or(n61, n54);
  auto n80 = gate_or(n56, n60);
  auto n58 = gate_nor(n81, n80);
  auto n83 = gate_not(n80);
  auto n82 = gate_not(n81);
  auto n52 = gate_nor(n83, n82);
  y[3] = gate_or(n58, n52);
}
template<> void $NameUint<4>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n29 = gate_or(a[0], a[1]);
  auto n31 = gate_not(n29);
  auto n28 = gate_not(a[0]);
  auto n27 = gate_not(a[1]);
  auto n24 = gate_nor(n28, n27);
  y[1] = gate_nor(n31, n24);
  auto n34 = gate_or(a[2], n29);
  auto n26 = gate_nor(a[3], n34);
  auto n33 = gate_not(n34);
  auto n30 = gate_not(a[2]);
  auto n21 = gate_nor(n31, n30);
  y[2] = gate_nor(n33, n21);
  auto n32 = gate_not(a[3]);
  auto n20 = gate_nor(n33, n32);
  y[3] = gate_nor(n20, n26);
}
