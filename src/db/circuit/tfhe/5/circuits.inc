// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<5>::d_add
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
  auto n13 = gate_nand(n11, n10);
  auto n12 = gate_nand(b[3], a[3]);
  auto n14 = gate_nand(n13, n12);
  auto n15 = gate_xor(b[4], n14);
  y[4] = gate_xor(a[4], n15);
}
template<> void $NameUint<5>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_and(b[4], a[4]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_and(b[1], a[1]);
  y[2] = gate_and(b[2], a[2]);
  y[3] = gate_and(b[3], a[3]);
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
  auto n12 = gate_not(b[4]);
  auto n11 = gate_not(a[4]);
  y[4] = gate_nand(n12, n11);
  auto n14 = gate_not(b[3]);
  auto n13 = gate_not(a[3]);
  y[3] = gate_nand(n14, n13);
  auto n16 = gate_not(b[2]);
  auto n15 = gate_not(a[2]);
  y[2] = gate_nand(n16, n15);
  auto n18 = gate_not(b[1]);
  auto n17 = gate_not(a[1]);
  y[1] = gate_nand(n18, n17);
  auto n20 = gate_not(b[0]);
  auto n19 = gate_not(a[0]);
  y[0] = gate_nand(n20, n19);
}
template<> void $NameUint<5>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  y[3] = gate_buf(zero);
  y[4] = gate_buf(zero);
  auto N0 = gate_buf(a[0]);
  auto n6 = gate_xor(N0, a[2]);
  auto n3 = gate_xor(n6, a[3]);
  auto n2 = gate_xor(a[1], a[4]);
  y[0] = gate_xor(n3, n2);
  auto n5 = gate_nand(a[1], a[4]);
  auto n4 = gate_nand(n3, n2);
  auto n10 = gate_nand(n5, n4);
  auto n8 = gate_nand(N0, a[2]);
  auto n7 = gate_nand(n6, a[3]);
  auto n9 = gate_nand(n8, n7);
  y[2] = gate_and(n10, n9);
  y[1] = gate_xor(n10, n9);
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
  y[4] = gate_and(a[0], b[4]);
  y[3] = gate_and(a[0], b[3]);
  y[2] = gate_and(a[0], b[2]);
  y[1] = gate_and(a[0], b[1]);
  y[0] = gate_and(a[0], b[0]);
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
template<> void $NameUint<5>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n14 = gate_and(a[0], b[0]);
  auto n20 = gate_nand(b[3], a[3]);
  auto n22 = gate_xor(b[3], a[3]);
  auto n18 = gate_nand(b[2], a[2]);
  auto n24 = gate_xor(b[2], a[2]);
  auto n16 = gate_nand(b[1], a[1]);
  auto n25 = gate_xor(b[1], a[1]);
  auto n15 = gate_nand(n14, n25);
  auto n23 = gate_nand(n16, n15);
  auto n17 = gate_nand(n24, n23);
  auto n21 = gate_nand(n18, n17);
  auto n19 = gate_nand(n22, n21);
  y[4] = gate_nand(n20, n19);
  y[3] = gate_xor(n22, n21);
  y[2] = gate_xor(n24, n23);
  y[1] = gate_xor(n14, n25);
  y[0] = gate_xor(a[0], b[0]);
}
template<> void $NameUint<5>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n4 = gate_not(a[1]);
  y[1] = gate_xor(a[0], n4);
  y[0] = gate_not(a[0]);
  auto n2 = gate_and(y[0], n4);
  y[2] = gate_xor(a[2], n2);
  auto n5 = gate_not(a[2]);
  auto n3 = gate_and(n2, n5);
  y[3] = gate_xor(a[3], n3);
  auto n8 = gate_not(a[4]);
  auto n6 = gate_not(a[3]);
  auto n7 = gate_nand(n3, n6);
  y[4] = gate_xor(n8, n7);
}
template<> void $NameUint<5>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n52 = gate_not(b[1]);
  auto n76 = gate_not(b[4]);
  auto n49 = gate_not(b[3]);
  auto n2 = gate_and(n76, n49);
  auto n65 = gate_not(b[2]);
  auto n4 = gate_and(n2, n65);
  auto n1 = gate_and(n52, n4);
  auto n11 = gate_not(a[4]);
  auto n8 = gate_nand(b[0], n11);
  auto n18 = gate_nand(n1, n8);
  y[4] = gate_not(n18);
  auto n9 = gate_not(a[3]);
  auto n10 = gate_nand(b[0], n9);
  auto n3 = gate_and(n10, n4);
  auto n12 = gate_nand(b[1], n11);
  auto n19 = gate_nand(n3, n12);
  auto n6 = gate_and(n19, n18);
  y[3] = gate_not(n19);
  auto n13 = gate_nand(y[3], b[0]);
  auto n30 = gate_nand(a[3], n13);
  auto n14 = gate_not(n30);
  auto n16 = gate_nand(n14, n52);
  auto n26 = gate_xor(b[1], n30);
  auto n32 = gate_not(a[2]);
  auto n27 = gate_nand(b[0], n32);
  auto n15 = gate_nand(n26, n27);
  auto n17 = gate_nand(n16, n15);
  auto n22 = gate_nand(n17, n65);
  auto n20 = gate_xor(n17, n65);
  auto n43 = gate_nand(a[4], n6);
  auto n25 = gate_not(n43);
  auto n21 = gate_nand(n20, n25);
  auto n23 = gate_nand(n22, n21);
  auto n24 = gate_nand(n2, n23);
  auto n5 = gate_and(n25, n24);
  y[2] = gate_not(n24);
  auto n41 = gate_nand(n5, n49);
  auto n28 = gate_not(n26);
  auto n29 = gate_nand(n28, n27);
  auto n35 = gate_mux(n30, n29, y[2]);
  auto n45 = gate_xor(b[2], n35);
  auto n31 = gate_nand(y[2], b[0]);
  auto n62 = gate_xor(n32, n31);
  auto n34 = gate_nand(n52, n62);
  auto n60 = gate_xor(n52, n62);
  auto n51 = gate_not(a[1]);
  auto n59 = gate_nand(b[0], n51);
  auto n33 = gate_nand(n60, n59);
  auto n44 = gate_nand(n34, n33);
  auto n37 = gate_nand(n45, n44);
  auto n47 = gate_not(n35);
  auto n36 = gate_nand(n65, n47);
  auto n39 = gate_nand(n37, n36);
  auto n38 = gate_nand(b[3], n43);
  auto n40 = gate_nand(n39, n38);
  auto n42 = gate_nand(n41, n40);
  auto n75 = gate_nand(n76, n42);
  auto n7 = gate_and(n5, n75);
  y[1] = gate_not(n75);
  auto n74 = gate_nand(n43, b[4]);
  auto n46 = gate_xor(n45, n44);
  auto n48 = gate_mux(n47, n46, y[1]);
  auto n72 = gate_nand(n49, n48);
  auto n70 = gate_xor(n49, n48);
  auto n50 = gate_nand(y[1], b[0]);
  auto n53 = gate_xor(n51, n50);
  auto n58 = gate_nand(n53, n52);
  auto n56 = gate_xor(n53, n52);
  auto n54 = gate_not(a[0]);
  auto n55 = gate_nand(b[0], n54);
  auto n57 = gate_nand(n56, n55);
  auto n64 = gate_nand(n58, n57);
  auto n61 = gate_xor(n60, n59);
  auto n63 = gate_mux(n62, n61, y[1]);
  auto n68 = gate_nand(n64, n63);
  auto n66 = gate_xor(n64, n63);
  auto n67 = gate_nand(n66, n65);
  auto n69 = gate_nand(n68, n67);
  auto n71 = gate_nand(n70, n69);
  auto n73 = gate_nand(n72, n71);
  auto n78 = gate_nand(n74, n73);
  auto n77 = gate_nand(n76, n7);
  y[0] = gate_nand(n78, n77);
}
template<> void $NameUint<5>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n103 = gate_not(b[4]);
  auto n94 = gate_xor(a[4], n103);
  auto n106 = gate_not(n94);
  auto n45 = gate_not(a[1]);
  auto n59 = gate_not(a[0]);
  auto n27 = gate_nand(n45, n59);
  auto n13 = gate_not(n27);
  auto n12 = gate_not(a[2]);
  auto n15 = gate_nand(n13, n12);
  auto n14 = gate_not(n15);
  auto n17 = gate_not(a[3]);
  auto n3 = gate_and(n14, n17);
  auto n25 = gate_nand(a[4], n3);
  auto n81 = gate_xor(b[3], b[4]);
  auto n54 = gate_nand(n25, n81);
  auto n68 = gate_xor(b[2], b[4]);
  auto n40 = gate_not(n68);
  auto n16 = gate_nand(a[4], n15);
  auto n24 = gate_xor(n17, n16);
  auto n56 = gate_not(n81);
  auto n4 = gate_and(n56, n40);
  auto n8 = gate_and(b[0], n4);
  auto n61 = gate_xor(b[1], b[4]);
  auto n71 = gate_not(n61);
  auto n18 = gate_not(n25);
  auto n5 = gate_and(n18, n71);
  auto n95 = gate_nand(n8, n5);
  auto n7 = gate_and(n18, n95);
  auto n22 = gate_nand(n71, n7);
  auto n102 = gate_not(b[0]);
  auto n2 = gate_and(n103, n102);
  auto n1 = gate_and(n4, n2);
  auto n20 = gate_mux(n24, n103, n102);
  auto n19 = gate_nand(n61, n25);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n93 = gate_nand(n4, n23);
  auto n9 = gate_and(n7, n93);
  auto n26 = gate_nand(n24, n93);
  auto n39 = gate_not(n26);
  auto n35 = gate_nand(n25, n68);
  auto n33 = gate_nand(n39, n71);
  auto n31 = gate_xor(n26, n61);
  auto n28 = gate_nand(a[4], n27);
  auto n43 = gate_xor(a[2], n28);
  auto n29 = gate_mux(n43, b[4], n102);
  auto n30 = gate_not(n29);
  auto n32 = gate_nand(n31, n30);
  auto n34 = gate_nand(n33, n32);
  auto n37 = gate_nand(n35, n34);
  auto n36 = gate_nand(n40, n9);
  auto n38 = gate_nand(n37, n36);
  auto n55 = gate_nand(n56, n38);
  auto n10 = gate_and(n9, n55);
  auto n41 = gate_nand(n39, n55);
  auto n82 = gate_not(n41);
  auto n52 = gate_nand(n40, n82);
  auto n50 = gate_xor(n68, n41);
  auto n92 = gate_not(n55);
  auto n42 = gate_nand(n92, b[0]);
  auto n75 = gate_xor(n43, n42);
  auto n48 = gate_nand(n71, n75);
  auto n46 = gate_xor(n71, n75);
  auto n44 = gate_nand(a[0], a[4]);
  auto n63 = gate_xor(n45, n44);
  auto n70 = gate_mux(n63, n103, n102);
  auto n47 = gate_nand(n46, n70);
  auto n49 = gate_nand(n48, n47);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_nand(n52, n51);
  auto n58 = gate_nand(n54, n53);
  auto n57 = gate_nand(n56, n10);
  auto n73 = gate_nand(n58, n57);
  auto n91 = gate_not(n73);
  auto n88 = gate_nand(n91, n10);
  auto n60 = gate_mux(n59, b[4], n102);
  auto n67 = gate_nand(n61, n60);
  auto n65 = gate_xor(n61, n60);
  auto n62 = gate_nand(b[0], n73);
  auto n64 = gate_xor(n63, n62);
  auto n66 = gate_nand(n65, n64);
  auto n69 = gate_nand(n67, n66);
  auto n79 = gate_nand(n69, n68);
  auto n77 = gate_xor(n69, n68);
  auto n72 = gate_xor(n71, n70);
  auto n74 = gate_nand(n73, n72);
  auto n76 = gate_xor(n75, n74);
  auto n78 = gate_nand(n77, n76);
  auto n80 = gate_nand(n79, n78);
  auto n86 = gate_nand(n81, n80);
  auto n84 = gate_xor(n81, n80);
  auto n83 = gate_nand(n82, n91);
  auto n85 = gate_nand(n84, n83);
  auto n87 = gate_nand(n86, n85);
  auto n101 = gate_nand(n88, n87);
  auto n89 = gate_not(n101);
  auto n109 = gate_nand(n106, n89);
  auto n90 = gate_not(n109);
  auto n100 = gate_xor(n94, n91);
  auto n11 = gate_and(n90, n100);
  auto n99 = gate_xor(n106, n92);
  auto n6 = gate_and(n11, n99);
  auto n98 = gate_xor(n94, n93);
  auto n97 = gate_nand(n6, n98);
  auto n96 = gate_xor(n106, n95);
  y[4] = gate_xor(n97, n96);
  y[3] = gate_xor(n6, n98);
  y[2] = gate_xor(n11, n99);
  y[1] = gate_xor(n90, n100);
  auto n108 = gate_xor(n101, n106);
  auto n104 = gate_not(b[1]);
  auto n105 = gate_nand(n104, n1);
  auto n107 = gate_nand(n106, n105);
  y[0] = gate_mux(n109, n108, n107);
}
template<> void $NameUint<5>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_xnor(a[2], b[2]);
  auto n24 = gate_not(a[0]);
  auto n27 = gate_xor(n24, b[0]);
  auto n25 = gate_not(a[1]);
  auto n26 = gate_xor(n25, b[1]);
  auto n19 = gate_and(n27, n26);
  auto n28 = gate_not(b[3]);
  auto n31 = gate_xor(n28, a[3]);
  auto n29 = gate_not(a[4]);
  auto n30 = gate_xor(n29, b[4]);
  auto n23 = gate_and(n31, n30);
  auto n21 = gate_and(n19, n23);
  y[0] = gate_and(n21, n22);
}
template<> void $NameUint<5>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[4]);
  auto n42 = gate_nand(n22, a[4]);
  auto n40 = gate_xor(n22, a[4]);
  auto n23 = gate_not(b[3]);
  auto n38 = gate_nand(n23, a[3]);
  auto n36 = gate_xor(n23, a[3]);
  auto n24 = gate_not(b[2]);
  auto n34 = gate_nand(n24, a[2]);
  auto n32 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[1]);
  auto n30 = gate_nand(n25, a[1]);
  auto n28 = gate_xor(n25, a[1]);
  auto n26 = gate_not(a[0]);
  auto n27 = gate_nand(b[0], n26);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<5>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[4]);
  auto n42 = gate_nand(n22, b[4]);
  auto n40 = gate_xor(n22, b[4]);
  auto n23 = gate_not(b[3]);
  auto n38 = gate_nand(n23, a[3]);
  auto n36 = gate_xor(n23, a[3]);
  auto n24 = gate_not(b[2]);
  auto n34 = gate_nand(n24, a[2]);
  auto n32 = gate_xor(n24, a[2]);
  auto n25 = gate_not(b[1]);
  auto n30 = gate_nand(n25, a[1]);
  auto n28 = gate_xor(n25, a[1]);
  auto n26 = gate_not(a[0]);
  auto n27 = gate_nand(b[0], n26);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<5>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(a[1]);
  auto n29 = gate_nand(n24, b[1]);
  auto n27 = gate_xor(n24, b[1]);
  auto n25 = gate_not(b[0]);
  auto n26 = gate_nand(a[0], n25);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n29, n28);
  auto n34 = gate_nand(n30, b[2]);
  auto n32 = gate_xor(n30, b[2]);
  auto n31 = gate_not(a[2]);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n35, b[3]);
  auto n37 = gate_xor(n35, b[3]);
  auto n36 = gate_not(a[3]);
  auto n38 = gate_nand(n37, n36);
  auto n23 = gate_and(n39, n38);
  auto n43 = gate_nand(a[4], n23);
  auto n41 = gate_xor(a[4], n23);
  auto n40 = gate_not(b[4]);
  auto n42 = gate_nand(n41, n40);
  y[0] = gate_nand(n43, n42);
}
template<> void $NameUint<5>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(a[1]);
  auto n29 = gate_nand(n24, b[1]);
  auto n27 = gate_xor(n24, b[1]);
  auto n25 = gate_not(b[0]);
  auto n26 = gate_nand(a[0], n25);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n29, n28);
  auto n34 = gate_nand(n30, b[2]);
  auto n32 = gate_xor(n30, b[2]);
  auto n31 = gate_not(a[2]);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n35, b[3]);
  auto n37 = gate_xor(n35, b[3]);
  auto n36 = gate_not(a[3]);
  auto n38 = gate_nand(n37, n36);
  auto n23 = gate_and(n39, n38);
  auto n43 = gate_nand(b[4], n23);
  auto n41 = gate_xor(b[4], n23);
  auto n40 = gate_not(a[4]);
  auto n42 = gate_nand(n41, n40);
  y[0] = gate_nand(n43, n42);
}
template<> void $NameUint<5>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n2 = gate_and(a[0], a[1]);
  auto n3 = gate_and(n2, a[2]);
  y[1] = gate_xor(a[0], a[1]);
  y[2] = gate_xor(n2, a[2]);
  y[3] = gate_xor(n3, a[3]);
  auto n5 = gate_not(a[4]);
  auto n4 = gate_nand(n3, a[3]);
  y[4] = gate_xor(n5, n4);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<5>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n19 = gate_xnor(a[2], b[2]);
  auto n21 = gate_not(a[0]);
  auto n24 = gate_xor(n21, b[0]);
  auto n22 = gate_not(a[1]);
  auto n23 = gate_xor(n22, b[1]);
  auto n17 = gate_and(n24, n23);
  auto n25 = gate_not(b[3]);
  auto n28 = gate_xor(n25, a[3]);
  auto n26 = gate_not(a[4]);
  auto n27 = gate_xor(n26, b[4]);
  auto n20 = gate_and(n28, n27);
  auto n18 = gate_and(n17, n20);
  y[0] = gate_nand(n18, n19);
}
template<> void $NameUint<5>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n17 = gate_not(a[0]);
  auto n16 = gate_not(a[4]);
  auto n15 = gate_and(n17, n16);
  auto n19 = gate_not(a[2]);
  auto n18 = gate_not(a[1]);
  auto n14 = gate_and(n19, n18);
  auto n13 = gate_and(n15, n14);
  auto n20 = gate_not(a[3]);
  auto n21 = gate_nand(n13, n20);
  y[4] = gate_mux(c[4], b[4], n21);
  y[0] = gate_mux(c[0], b[0], n21);
  y[1] = gate_mux(c[1], b[1], n21);
  y[2] = gate_mux(c[2], b[2], n21);
  y[3] = gate_mux(c[3], b[3], n21);
}
template<> void $NameUint<5>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(a[4]);
  auto n42 = gate_nand(n22, b[4]);
  auto n40 = gate_xor(n22, b[4]);
  auto n23 = gate_not(a[3]);
  auto n38 = gate_nand(n23, b[3]);
  auto n36 = gate_xor(n23, b[3]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_nand(n24, b[2]);
  auto n32 = gate_xor(n24, b[2]);
  auto n25 = gate_not(a[1]);
  auto n30 = gate_nand(n25, b[1]);
  auto n28 = gate_xor(n25, b[1]);
  auto n26 = gate_not(b[0]);
  auto n27 = gate_nand(a[0], n26);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<5>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n22 = gate_not(b[4]);
  auto n42 = gate_nand(n22, a[4]);
  auto n40 = gate_xor(n22, a[4]);
  auto n23 = gate_not(a[3]);
  auto n38 = gate_nand(n23, b[3]);
  auto n36 = gate_xor(n23, b[3]);
  auto n24 = gate_not(a[2]);
  auto n34 = gate_nand(n24, b[2]);
  auto n32 = gate_xor(n24, b[2]);
  auto n25 = gate_not(a[1]);
  auto n30 = gate_nand(n25, b[1]);
  auto n28 = gate_xor(n25, b[1]);
  auto n26 = gate_not(b[0]);
  auto n27 = gate_nand(a[0], n26);
  auto n29 = gate_nand(n28, n27);
  auto n31 = gate_nand(n30, n29);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n37 = gate_nand(n36, n35);
  auto n39 = gate_nand(n38, n37);
  auto n41 = gate_nand(n40, n39);
  y[0] = gate_nand(n42, n41);
}
template<> void $NameUint<5>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n34 = gate_not(a[0]);
  auto n33 = gate_not(a[4]);
  auto n32 = gate_and(n34, n33);
  auto n36 = gate_not(a[2]);
  auto n35 = gate_not(a[1]);
  auto n30 = gate_and(n36, n35);
  auto n27 = gate_and(n32, n30);
  auto n37 = gate_not(a[3]);
  auto n44 = gate_nand(n27, n37);
  auto n39 = gate_not(b[0]);
  auto n38 = gate_not(b[4]);
  auto n29 = gate_and(n39, n38);
  auto n41 = gate_not(b[2]);
  auto n40 = gate_not(b[1]);
  auto n28 = gate_and(n41, n40);
  auto n26 = gate_and(n29, n28);
  auto n42 = gate_not(b[3]);
  auto n43 = gate_nand(n26, n42);
  y[0] = gate_and(n44, n43);
}
template<> void $NameUint<5>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n19 = gate_not(a[0]);
  auto n22 = gate_not(a[3]);
  auto n18 = gate_not(a[4]);
  auto n17 = gate_and(n19, n18);
  auto n21 = gate_not(a[2]);
  auto n20 = gate_not(a[1]);
  auto n15 = gate_and(n21, n20);
  auto n14 = gate_and(n17, n15);
  y[0] = gate_and(n14, n22);
}
template<> void $NameUint<5>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n36 = gate_not(b[3]);
  auto n35 = gate_not(a[2]);
  auto n32 = gate_and(n36, n35);
  auto n38 = gate_not(a[0]);
  auto n37 = gate_not(b[1]);
  auto n31 = gate_and(n38, n37);
  auto n40 = gate_not(a[1]);
  auto n39 = gate_not(a[3]);
  auto n33 = gate_and(n40, n39);
  auto n28 = gate_and(n31, n33);
  auto n42 = gate_not(b[0]);
  auto n41 = gate_not(b[4]);
  auto n30 = gate_and(n42, n41);
  auto n44 = gate_not(b[2]);
  auto n43 = gate_not(a[4]);
  auto n34 = gate_and(n44, n43);
  auto n29 = gate_and(n30, n34);
  auto n27 = gate_and(n28, n29);
  y[0] = gate_nand(n32, n27);
}
template<> void $NameUint<5>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[1]);
  auto n29 = gate_nand(n24, a[1]);
  auto n27 = gate_xor(n24, a[1]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_nand(b[0], n25);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n29, n28);
  auto n34 = gate_nand(n30, a[2]);
  auto n32 = gate_xor(n30, a[2]);
  auto n31 = gate_not(b[2]);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n35, a[3]);
  auto n37 = gate_xor(n35, a[3]);
  auto n36 = gate_not(b[3]);
  auto n38 = gate_nand(n37, n36);
  auto n23 = gate_and(n39, n38);
  auto n43 = gate_nand(b[4], n23);
  auto n41 = gate_xor(b[4], n23);
  auto n40 = gate_not(a[4]);
  auto n42 = gate_nand(n41, n40);
  y[0] = gate_nand(n43, n42);
}
template<> void $NameUint<5>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n24 = gate_not(b[1]);
  auto n29 = gate_nand(n24, a[1]);
  auto n27 = gate_xor(n24, a[1]);
  auto n25 = gate_not(a[0]);
  auto n26 = gate_nand(b[0], n25);
  auto n28 = gate_nand(n27, n26);
  auto n30 = gate_nand(n29, n28);
  auto n34 = gate_nand(n30, a[2]);
  auto n32 = gate_xor(n30, a[2]);
  auto n31 = gate_not(b[2]);
  auto n33 = gate_nand(n32, n31);
  auto n35 = gate_nand(n34, n33);
  auto n39 = gate_nand(n35, a[3]);
  auto n37 = gate_xor(n35, a[3]);
  auto n36 = gate_not(b[3]);
  auto n38 = gate_nand(n37, n36);
  auto n23 = gate_and(n39, n38);
  auto n43 = gate_nand(a[4], n23);
  auto n41 = gate_xor(a[4], n23);
  auto n40 = gate_not(b[4]);
  auto n42 = gate_nand(n41, n40);
  y[0] = gate_nand(n43, n42);
}
template<> void $NameUint<5>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n69 = gate_not(b[4]);
  auto n52 = gate_not(b[3]);
  auto n3 = gate_and(n69, n52);
  auto n57 = gate_not(b[2]);
  auto n2 = gate_and(n3, n57);
  auto n61 = gate_not(b[1]);
  auto n1 = gate_and(n2, n61);
  auto n9 = gate_nand(b[0], n1);
  auto n7 = gate_and(a[4], n9);
  auto n10 = gate_mux(b[0], a[4], b[1]);
  auto n6 = gate_and(n2, n10);
  auto n11 = gate_not(a[3]);
  auto n12 = gate_nand(b[0], n11);
  auto n13 = gate_nand(n6, n12);
  auto n4 = gate_and(n7, n13);
  auto n26 = gate_nand(a[3], n13);
  auto n14 = gate_not(n26);
  auto n16 = gate_nand(n14, n61);
  auto n18 = gate_xor(b[1], n26);
  auto n32 = gate_not(a[2]);
  auto n20 = gate_nand(b[0], n32);
  auto n15 = gate_nand(n18, n20);
  auto n21 = gate_nand(n16, n15);
  auto n22 = gate_xor(n21, n57);
  auto n17 = gate_nand(n3, n22);
  auto n41 = gate_nand(n4, n17);
  auto n44 = gate_not(n41);
  auto n19 = gate_not(n18);
  auto n27 = gate_nand(n20, n19);
  auto n24 = gate_nand(n21, n57);
  auto n23 = gate_nand(n22, n4);
  auto n25 = gate_nand(n24, n23);
  auto n29 = gate_nand(n3, n25);
  auto n51 = gate_mux(n27, n26, n29);
  auto n28 = gate_not(n51);
  auto n38 = gate_nand(n57, n28);
  auto n36 = gate_xor(n57, n28);
  auto n30 = gate_not(n29);
  auto n31 = gate_nand(n30, b[0]);
  auto n56 = gate_xor(n32, n31);
  auto n35 = gate_nand(n61, n56);
  auto n33 = gate_xor(n61, n56);
  auto n60 = gate_not(a[1]);
  auto n53 = gate_nand(b[0], n60);
  auto n34 = gate_nand(n33, n53);
  auto n48 = gate_nand(n35, n34);
  auto n37 = gate_nand(n36, n48);
  auto n42 = gate_nand(n38, n37);
  auto n39 = gate_xor(n52, n42);
  auto n40 = gate_nand(n39, n69);
  auto n5 = gate_and(n44, n40);
  auto n68 = gate_nand(b[4], n41);
  auto n43 = gate_xor(b[3], n41);
  auto n46 = gate_nand(n43, n42);
  auto n45 = gate_nand(n44, n52);
  auto n47 = gate_nand(n46, n45);
  auto n8 = gate_and(n47, n69);
  auto n49 = gate_xor(n48, n57);
  auto n50 = gate_nand(n8, n49);
  auto n78 = gate_xor(n51, n50);
  auto n67 = gate_nand(n78, n52);
  auto n76 = gate_xor(n52, n78);
  auto n54 = gate_xor(n53, n61);
  auto n55 = gate_nand(n8, n54);
  auto n58 = gate_xor(n56, n55);
  auto n82 = gate_not(n58);
  auto n65 = gate_nand(n82, n57);
  auto n80 = gate_xor(b[2], n58);
  auto n59 = gate_nand(n8, b[0]);
  auto n87 = gate_xor(n60, n59);
  auto n63 = gate_nand(n61, n87);
  auto n85 = gate_xor(n61, n87);
  auto n91 = gate_not(a[0]);
  auto n84 = gate_nand(b[0], n91);
  auto n62 = gate_nand(n85, n84);
  auto n81 = gate_nand(n63, n62);
  auto n64 = gate_nand(n80, n81);
  auto n77 = gate_nand(n65, n64);
  auto n66 = gate_nand(n76, n77);
  auto n72 = gate_nand(n67, n66);
  auto n70 = gate_nand(n68, n72);
  auto n71 = gate_nand(n5, n69);
  auto n89 = gate_nand(n70, n71);
  auto n86 = gate_not(n89);
  auto n75 = gate_nand(n5, n86);
  auto n73 = gate_not(n71);
  auto n74 = gate_nand(n73, n72);
  y[4] = gate_nand(n75, n74);
  auto n79 = gate_xor(n77, n76);
  y[3] = gate_mux(n79, n78, n86);
  auto n83 = gate_xor(n81, n80);
  y[2] = gate_mux(n83, n82, n86);
  auto n88 = gate_xor(n85, n84);
  y[1] = gate_mux(n88, n87, n86);
  auto n90 = gate_nand(n89, b[0]);
  y[0] = gate_xor(n91, n90);
}
template<> void $NameUint<5>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n13 = gate_not(a[1]);
  auto n96 = gate_not(a[0]);
  auto n16 = gate_nand(n13, n96);
  auto n14 = gate_nand(a[4], n16);
  auto n42 = gate_xor(a[2], n14);
  auto n89 = gate_xor(b[3], b[4]);
  auto n104 = gate_not(n89);
  auto n22 = gate_not(a[3]);
  auto n51 = gate_xor(b[2], b[4]);
  auto n80 = gate_not(n51);
  auto n6 = gate_and(n104, n80);
  auto n69 = gate_not(b[4]);
  auto n1 = gate_xor(n69, b[1]);
  auto n3 = gate_and(n6, n1);
  auto n100 = gate_xor(n69, b[1]);
  auto n15 = gate_nand(b[0], n3);
  auto n9 = gate_and(n22, n15);
  auto n18 = gate_not(n16);
  auto n17 = gate_not(a[2]);
  auto n20 = gate_nand(n18, n17);
  auto n19 = gate_not(n20);
  auto n10 = gate_and(n19, a[4]);
  auto n27 = gate_nand(n9, n10);
  auto n26 = gate_not(n27);
  auto n25 = gate_xor(n26, n100);
  auto n21 = gate_nand(a[4], n20);
  auto n31 = gate_xor(n22, n21);
  auto n23 = gate_not(n31);
  auto n68 = gate_not(b[0]);
  auto n24 = gate_nand(n23, b[0]);
  auto n8 = gate_and(n6, n24);
  auto n28 = gate_nand(n25, n8);
  auto n7 = gate_and(n26, n28);
  auto n39 = gate_nand(n7, n80);
  auto n37 = gate_nand(n51, n27);
  auto n29 = gate_not(n28);
  auto n30 = gate_nand(n29, b[0]);
  auto n49 = gate_nand(n31, n30);
  auto n32 = gate_not(n49);
  auto n36 = gate_nand(n32, n100);
  auto n46 = gate_xor(n1, n49);
  auto n34 = gate_not(n46);
  auto n33 = gate_mux(n42, b[4], n68);
  auto n47 = gate_not(n33);
  auto n35 = gate_nand(n34, n47);
  auto n43 = gate_nand(n36, n35);
  auto n38 = gate_nand(n37, n43);
  auto n40 = gate_nand(n39, n38);
  auto n5 = gate_and(n104, n40);
  auto n41 = gate_nand(n5, b[0]);
  auto n65 = gate_xor(n42, n41);
  auto n44 = gate_nand(n80, n43);
  auto n45 = gate_nand(n44, n5);
  auto n2 = gate_and(n45, n7);
  auto n61 = gate_nand(n104, n2);
  auto n48 = gate_nand(n47, n46);
  auto n77 = gate_mux(n49, n48, n5);
  auto n50 = gate_not(n77);
  auto n59 = gate_nand(n80, n50);
  auto n57 = gate_xor(n51, n77);
  auto n56 = gate_nand(n65, n1);
  auto n54 = gate_xor(n65, n1);
  auto n52 = gate_nand(a[4], a[0]);
  auto n67 = gate_xor(a[1], n52);
  auto n53 = gate_mux(n67, b[4], n68);
  auto n62 = gate_not(n53);
  auto n55 = gate_nand(n54, n62);
  auto n74 = gate_nand(n56, n55);
  auto n58 = gate_nand(n57, n74);
  auto n88 = gate_nand(n59, n58);
  auto n60 = gate_nand(n88, n104);
  auto n75 = gate_nand(n61, n60);
  auto n63 = gate_xor(n100, n62);
  auto n64 = gate_nand(n75, n63);
  auto n94 = gate_xor(n65, n64);
  auto n66 = gate_nand(b[0], n75);
  auto n103 = gate_xor(n67, n66);
  auto n72 = gate_nand(n103, n100);
  auto n70 = gate_xor(n103, n100);
  auto n99 = gate_mux(a[0], n69, n68);
  auto n71 = gate_nand(n70, n99);
  auto n81 = gate_nand(n72, n71);
  auto n92 = gate_xor(n81, n80);
  auto n73 = gate_xor(n77, n80);
  auto n76 = gate_nand(n74, n73);
  auto n109 = gate_mux(n77, n76, n75);
  auto n78 = gate_not(n109);
  auto n87 = gate_nand(n78, n104);
  auto n85 = gate_xor(n109, n89);
  auto n79 = gate_not(n94);
  auto n84 = gate_nand(n79, n80);
  auto n82 = gate_xor(n80, n79);
  auto n83 = gate_nand(n82, n81);
  auto n106 = gate_nand(n84, n83);
  auto n86 = gate_nand(n85, n106);
  auto n113 = gate_nand(n87, n86);
  auto n91 = gate_not(n113);
  auto n90 = gate_mux(n89, n104, n88);
  auto n112 = gate_nand(n2, n90);
  auto n107 = gate_nand(n91, n112);
  auto n93 = gate_nand(n92, n107);
  auto n95 = gate_xor(n94, n93);
  auto n119 = gate_xor(a[4], n95);
  auto n98 = gate_xor(a[4], n96);
  auto n97 = gate_nand(b[0], n107);
  auto n123 = gate_xor(n98, n97);
  y[0] = gate_xor(a[4], n123);
  auto n11 = gate_and(a[4], n123);
  auto n101 = gate_xor(n1, n99);
  auto n102 = gate_nand(n107, n101);
  auto n122 = gate_xor(n103, n102);
  auto n4 = gate_and(n11, n122);
  auto n12 = gate_and(n119, n4);
  auto n111 = gate_not(a[4]);
  auto n105 = gate_xor(n109, n104);
  auto n108 = gate_nand(n106, n105);
  auto n110 = gate_mux(n109, n108, n107);
  auto n118 = gate_xor(n111, n110);
  auto n117 = gate_nand(n12, n118);
  auto n114 = gate_not(n112);
  auto n115 = gate_nand(n114, n113);
  auto n116 = gate_nand(a[4], n115);
  y[4] = gate_xor(n117, n116);
  y[3] = gate_xor(n12, n118);
  y[2] = gate_xor(n119, n4);
  auto n120 = gate_not(n123);
  auto n121 = gate_nand(a[4], n120);
  y[1] = gate_xor(n122, n121);
}
template<> void $NameUint<5>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_and(b[1], a[1]);
  auto n2 = gate_and(b[0], a[1]);
  auto n3 = gate_and(b[1], a[0]);
  y[0] = gate_and(b[0], a[0]);
  y[1] = gate_xor(n2, n3);
  auto n8 = gate_nand(n2, n3);
  auto n5 = gate_not(n8);
  auto n13 = gate_nand(b[2], a[0]);
  auto n7 = gate_xor(n1, n13);
  auto n6 = gate_nand(b[0], a[2]);
  auto n9 = gate_xor(n7, n6);
  y[2] = gate_xor(n5, n9);
  auto n11 = gate_nand(n7, n6);
  auto n10 = gate_nand(n9, n8);
  auto n18 = gate_nand(n11, n10);
  auto n25 = gate_nand(b[1], a[2]);
  auto n12 = gate_nand(a[3], b[0]);
  auto n20 = gate_xor(n25, n12);
  auto n14 = gate_not(n13);
  auto n45 = gate_nand(n1, n14);
  auto n40 = gate_nand(a[1], b[2]);
  auto n41 = gate_nand(a[0], b[3]);
  auto n15 = gate_xor(n40, n41);
  auto n22 = gate_xor(n45, n15);
  auto n16 = gate_xor(n20, n22);
  y[3] = gate_xor(n18, n16);
  auto n17 = gate_not(n20);
  auto n24 = gate_nand(n17, n18);
  auto n19 = gate_not(n18);
  auto n21 = gate_nand(n20, n19);
  auto n23 = gate_nand(n22, n21);
  auto n31 = gate_nand(n24, n23);
  auto n28 = gate_not(a[4]);
  auto n26 = gate_not(n25);
  auto n27 = gate_nand(n26, a[3]);
  auto n29 = gate_xor(n28, n27);
  auto n30 = gate_nand(b[0], n29);
  auto n39 = gate_xor(n31, n30);
  auto n33 = gate_nand(b[3], a[1]);
  auto n32 = gate_nand(b[2], a[2]);
  auto n37 = gate_xor(n33, n32);
  auto n35 = gate_nand(b[4], a[0]);
  auto n34 = gate_nand(a[3], b[1]);
  auto n36 = gate_xor(n35, n34);
  auto n38 = gate_xor(n37, n36);
  auto n47 = gate_xor(n39, n38);
  auto n43 = gate_not(n40);
  auto n42 = gate_not(n41);
  auto n44 = gate_nand(n43, n42);
  auto n46 = gate_nand(n45, n44);
  y[4] = gate_xor(n47, n46);
}
template<> void $NameUint<5>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_and(a[4], a[2]);
  auto n10 = gate_and(a[0], a[1]);
  auto n9 = gate_and(n10, n8);
  y[0] = gate_and(a[3], n9);
}
template<> void $NameUint<5>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n8 = gate_and(a[4], a[2]);
  auto n10 = gate_and(a[0], a[1]);
  auto n9 = gate_and(n10, n8);
  y[0] = gate_nand(a[3], n9);
}
template<> void $NameUint<5>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n19 = gate_not(a[0]);
  auto n22 = gate_not(a[3]);
  auto n18 = gate_not(a[4]);
  auto n17 = gate_and(n19, n18);
  auto n21 = gate_not(a[2]);
  auto n20 = gate_not(a[1]);
  auto n15 = gate_and(n21, n20);
  auto n14 = gate_and(n17, n15);
  y[0] = gate_and(n14, n22);
}
template<> void $NameUint<5>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n16 = gate_not(a[0]);
  auto n15 = gate_not(a[4]);
  auto n14 = gate_and(n16, n15);
  auto n18 = gate_not(a[2]);
  auto n17 = gate_not(a[1]);
  auto n13 = gate_and(n18, n17);
  auto n12 = gate_and(n14, n13);
  auto n19 = gate_not(a[3]);
  y[0] = gate_nand(n12, n19);
}
template<> void $NameUint<5>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto n7 = gate_xor(a[0], a[2]);
  auto n8 = gate_xor(a[3], a[4]);
  auto n9 = gate_xor(a[1], n7);
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
  auto n40 = gate_not(b[4]);
  auto n57 = gate_not(b[0]);
  auto n39 = gate_not(b[3]);
  auto n32 = gate_and(n40, n39);
  auto n47 = gate_not(b[2]);
  auto n31 = gate_and(n32, n47);
  auto n35 = gate_and(n31, n57);
  auto n41 = gate_not(a[4]);
  auto n42 = gate_nand(n47, n41);
  auto n44 = gate_mux(n42, a[2], b[1]);
  auto n43 = gate_mux(a[3], a[1], b[1]);
  auto n38 = gate_and(n43, n47);
  auto n45 = gate_mux(n44, n38, b[0]);
  auto n34 = gate_and(n32, n45);
  auto n51 = gate_not(b[1]);
  auto n30 = gate_and(n31, n51);
  auto n56 = gate_nand(a[0], n51);
  auto n46 = gate_nand(b[2], n56);
  y[4] = gate_and(n34, n46);
  auto n55 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n30, n55);
  auto n48 = gate_mux(a[3], a[2], b[0]);
  auto n49 = gate_mux(n55, n48, n51);
  y[3] = gate_and(n31, n49);
  auto n50 = gate_mux(a[2], a[0], b[1]);
  auto n53 = gate_nand(n50, n31);
  auto n52 = gate_nand(a[1], n30);
  auto n54 = gate_mux(n53, n52, b[0]);
  y[2] = gate_not(n54);
  auto n58 = gate_not(n56);
  y[0] = gate_and(n58, n35);
}
template<> void $NameUint<5>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n40 = gate_not(b[0]);
  auto n39 = gate_and(a[4], n40);
  auto n45 = gate_not(b[1]);
  auto n35 = gate_and(a[3], n45);
  auto n55 = gate_nand(n39, n45);
  auto n56 = gate_nand(b[2], n55);
  auto n43 = gate_not(n55);
  auto n42 = gate_not(b[4]);
  auto n41 = gate_not(b[3]);
  auto n33 = gate_and(n42, n41);
  auto n49 = gate_not(b[2]);
  auto n30 = gate_and(n33, n49);
  y[4] = gate_and(n43, n30);
  auto n44 = gate_mux(a[3], a[4], b[0]);
  auto n38 = gate_and(n30, n44);
  y[3] = gate_and(n38, n45);
  auto n47 = gate_mux(a[2], a[4], b[1]);
  auto n46 = gate_mux(n47, n35, b[0]);
  y[2] = gate_and(n30, n46);
  auto n52 = gate_mux(a[1], a[3], b[1]);
  auto n48 = gate_mux(n52, n47, b[0]);
  y[1] = gate_and(n30, n48);
  auto n50 = gate_not(a[0]);
  auto n51 = gate_nand(n50, n49);
  auto n53 = gate_mux(n51, a[2], b[1]);
  auto n54 = gate_mux(n53, n52, b[0]);
  auto n34 = gate_and(n33, n54);
  y[0] = gate_and(n34, n56);
}
template<> void $NameUint<5>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[4] = gate_buf(a[4]);
  auto n23 = gate_not(b[2]);
  auto n22 = gate_not(b[4]);
  auto n17 = gate_and(n23, n22);
  auto n24 = gate_not(b[3]);
  auto n31 = gate_nand(n17, n24);
  auto n36 = gate_not(n31);
  auto n19 = gate_and(n36, b[1]);
  auto n25 = gate_not(b[1]);
  auto n16 = gate_and(n36, n25);
  auto n26 = gate_not(b[0]);
  auto n18 = gate_and(n16, n26);
  y[3] = gate_mux(y[4], a[3], n18);
  auto n28 = gate_not(y[4]);
  auto n27 = gate_nand(b[0], a[3]);
  auto n30 = gate_mux(n28, n27, n16);
  auto n29 = gate_nand(n18, a[2]);
  y[2] = gate_nand(n30, n29);
  auto n40 = gate_nand(y[4], n31);
  auto n32 = gate_mux(a[1], a[3], b[1]);
  auto n37 = gate_nand(n36, n32);
  auto n34 = gate_nand(a[2], n16);
  auto n33 = gate_nand(b[1], y[4]);
  auto n20 = gate_and(n34, n33);
  auto n35 = gate_mux(n37, n20, b[0]);
  y[1] = gate_nand(n40, n35);
  auto n38 = gate_nand(n19, a[2]);
  auto n39 = gate_mux(n38, n37, b[0]);
  auto n21 = gate_and(n40, n39);
  auto n41 = gate_nand(n18, a[0]);
  y[0] = gate_nand(n21, n41);
}
template<> void $NameUint<5>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(a[0], b[0]);
  auto n19 = gate_xor(b[4], a[4]);
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
  auto n18 = gate_nand(a[3], n14);
  auto n17 = gate_nand(n16, n15);
  auto n20 = gate_nand(n18, n17);
  y[4] = gate_xnor(n20, n19);
}
template<> void $NameUint<5>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  auto n13 = gate_not(y[0]);
  auto n12 = gate_not(a[1]);
  auto n10 = gate_and(n13, n12);
  auto n16 = gate_not(a[2]);
  auto n11 = gate_and(n10, n16);
  auto n15 = gate_not(a[3]);
  auto n14 = gate_nand(n11, n15);
  y[4] = gate_xor(a[4], n14);
  y[3] = gate_xor(n11, n15);
  y[2] = gate_xor(n10, n16);
  y[1] = gate_xor(y[0], a[1]);
}
