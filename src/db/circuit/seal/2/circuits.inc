// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<2>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_and(b[0], a[0]);
  auto n4 = gate_xnor(n3, a[1]);
  y[1] = gate_xnor(n4, b[1]);
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
}
template<> void $NameUint<2>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_and(b[1], a[1]);
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<2>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_not(a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<2>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_or(a[1], b[1]);
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<2>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto N0 = gate_buf(a[0]);
  auto _add_x_1_n6 = gate_xor(a[1], N0);
  auto _add_x_1_n5 = gate_and(a[1], N0);
  y[0] = gate_buf(_add_x_1_n6);
  y[1] = gate_buf(_add_x_1_n5);
}
template<> void $NameUint<2>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_xor(b[1], a[1]);
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<2>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  y[1] = gate_and(a[0], b[1]);
}
template<> void $NameUint<2>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
  y[1] = gate_mux(c[1], b[1], a[0]);
}
template<> void $NameUint<2>::d_carryadd
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _add_x_1_n6 = gate_xor(b[0], a[0]);
  auto _add_x_1_n5 = gate_and(b[0], a[0]);
  y[0] = gate_buf(_add_x_1_n6);
  y[1] = gate_buf(_add_x_1_n5);
}
template<> void $NameUint<2>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[1] = gate_xnor(a[0], a[1]);
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<2>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[1]);
  auto n1 = gate_and(b[0], n3);
  y[1] = gate_nor(b[1], n1);
  auto n2 = gate_not(a[0]);
  auto n5 = gate_and(b[0], n2);
  auto n4 = gate_and(b[1], n3);
  y[0] = gate_nor(n5, n4);
}
template<> void $NameUint<2>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_mux(a[1], a[0], b[0]);
  auto n2 = gate_and(n1, b[1]);
  y[1] = gate_xor(n2, a[1]);
  auto n4 = gate_not(b[1]);
  auto n3 = gate_nor(a[0], n4);
  auto n5 = gate_mux(n4, n3, a[1]);
  y[0] = gate_mux(n5, a[0], b[0]);
}
template<> void $NameUint<2>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_xnor(b[0], a[0]);
  auto n4 = gate_xnor(a[1], b[1]);
  y[0] = gate_and(n5, n4);
}
template<> void $NameUint<2>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n7 = gate_not(a[1]);
  auto n11 = gate_and(b[1], n7);
  auto n8 = gate_nor(b[1], n7);
  auto n9 = gate_nor(n8, a[0]);
  auto n10 = gate_and(b[0], n9);
  y[0] = gate_nor(n11, n10);
}
template<> void $NameUint<2>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(a[0]);
  auto n10 = gate_and(b[0], n9);
  auto n12 = gate_nor(a[1], n10);
  auto n7 = gate_nand(a[1], n10);
  auto n11 = gate_and(b[1], n7);
  y[0] = gate_or(n12, n11);
}
template<> void $NameUint<2>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(b[0]);
  auto n10 = gate_and(a[0], n9);
  auto n12 = gate_nor(n10, a[1]);
  auto n8 = gate_nand(n10, a[1]);
  auto n11 = gate_and(b[1], n8);
  y[0] = gate_nor(n12, n11);
}
template<> void $NameUint<2>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n9 = gate_not(b[0]);
  auto n10 = gate_and(a[0], n9);
  auto n12 = gate_nor(n10, b[1]);
  auto n8 = gate_nand(n10, b[1]);
  auto n11 = gate_and(a[1], n8);
  y[0] = gate_nor(n12, n11);
}
template<> void $NameUint<2>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
  y[1] = gate_xnor(a[1], y[0]);
}
template<> void $NameUint<2>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_xnor(b[0], a[0]);
  auto n5 = gate_xnor(b[1], a[1]);
  y[0] = gate_nand(n6, n5);
}
template<> void $NameUint<2>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  auto n2 = gate_nor(a[1], a[0]);
  y[0] = gate_mux(b[0], c[0], n2);
  y[1] = gate_mux(b[1], c[1], n2);
}
template<> void $NameUint<2>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(b[1]);
  auto n6 = gate_nor(n8, a[1]);
  auto n7 = gate_nor(n6, b[0]);
  auto n10 = gate_and(a[0], n7);
  auto n9 = gate_and(a[1], n8);
  auto _lte_x_1_n5 = gate_nor(n10, n9);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void $NameUint<2>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[1]);
  auto n6 = gate_nor(n8, b[1]);
  auto n7 = gate_nor(n6, b[0]);
  auto n10 = gate_and(a[0], n7);
  auto n9 = gate_and(b[1], n8);
  auto _lte_x_1_n5 = gate_nor(n10, n9);
  y[0] = gate_buf(_lte_x_1_n5);
}
template<> void $NameUint<2>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_nor(b[1], b[0]);
  auto n3 = gate_nor(a[1], a[0]);
  y[0] = gate_nor(n4, n3);
}
template<> void $NameUint<2>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nor(a[1], a[0]);
}
template<> void $NameUint<2>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n6 = gate_nor(a[1], a[0]);
  auto n5 = gate_nor(b[1], b[0]);
  y[0] = gate_nand(n6, n5);
}
template<> void $NameUint<2>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n9 = gate_and(b[0], n8);
  auto n11 = gate_nor(n9, b[1]);
  auto n7 = gate_nand(n9, b[1]);
  auto n10 = gate_and(a[1], n7);
  auto _lt_x_1_n5 = gate_nor(n11, n10);
  y[0] = gate_buf(_lt_x_1_n5);
}
template<> void $NameUint<2>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n8 = gate_not(a[0]);
  auto n9 = gate_and(b[0], n8);
  auto n11 = gate_nor(n9, a[1]);
  auto n7 = gate_nand(n9, a[1]);
  auto n10 = gate_and(b[1], n7);
  auto _lt_x_1_n5 = gate_nor(n11, n10);
  y[0] = gate_buf(_lt_x_1_n5);
}
template<> void $NameUint<2>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(b[0]);
  auto n2 = gate_not(a[1]);
  auto n3 = gate_and(b[1], n2);
  auto n4 = gate_nor(n5, a[0]);
  auto n6 = gate_mux(n5, n4, b[1]);
  y[1] = gate_and(a[1], n6);
  auto n1 = gate_or(n5, n3);
  y[0] = gate_and(a[0], n1);
}
template<> void $NameUint<2>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n3 = gate_not(a[0]);
  auto n1 = gate_and(b[1], n3);
  auto n2 = gate_nor(n1, b[0]);
  y[1] = gate_and(a[1], n2);
  y[0] = gate_nor(n3, b[0]);
}
template<> void $NameUint<2>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(a[0], b[0]);
  auto n4 = gate_and(a[1], b[0]);
  auto n3 = gate_and(b[1], a[0]);
  y[1] = gate_xor(n4, n3);
}
template<> void $NameUint<2>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_and(a[0], a[1]);
}
template<> void $NameUint<2>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nand(a[0], a[1]);
}
template<> void $NameUint<2>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_nor(a[1], a[0]);
}
template<> void $NameUint<2>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_or(a[1], a[0]);
}
template<> void $NameUint<2>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xnor(a[0], a[1]);
}
template<> void $NameUint<2>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_xor(a[0], a[1]);
}
template<> void $NameUint<2>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(b[0]);
  auto n6 = gate_and(a[0], n5);
  auto n8 = gate_not(b[1]);
  auto _ash_1_n6 = gate_and(n6, n8);
  auto n7 = gate_mux(a[1], a[0], b[0]);
  y[1] = gate_and(n8, n7);
  y[0] = gate_buf(_ash_1_n6);
}
template<> void $NameUint<2>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(b[0]);
  auto n6 = gate_and(a[1], n5);
  auto n8 = gate_not(b[1]);
  y[1] = gate_and(n6, n8);
  auto n7 = gate_mux(a[0], a[1], b[0]);
  y[0] = gate_and(n8, n7);
}
template<> void $NameUint<2>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[1] = gate_buf(a[1]);
  auto n2 = gate_nor(b[1], b[0]);
  y[0] = gate_mux(a[1], a[0], n2);
}
template<> void $NameUint<2>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n4 = gate_not(a[0]);
  y[0] = gate_xnor(b[0], n4);
  auto n5 = gate_and(b[0], n4);
  auto n6 = gate_xnor(n5, b[1]);
  y[1] = gate_xnor(n6, a[1]);
}
template<> void $NameUint<2>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_buf(a[0]);
  y[1] = gate_xor(a[1], a[0]);
}
