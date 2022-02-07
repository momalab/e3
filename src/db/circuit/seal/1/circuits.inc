// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
template<> void $NameUint<1>::d_add
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<1>::d_bitand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<1>::d_bitnot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_bitor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<1>::d_bitsum
(vector<Bit> & y, const vector<Bit> & a, const Bit & zero) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void $NameUint<1>::d_bitxor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<1>::d_boolmul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<1>::d_boolmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void $NameUint<1>::d_dec
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_div
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n2);
}
template<> void $NameUint<1>::d_divsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _a0 = gate_buf(a[0]);
  y[0] = gate_buf(_a0);
}
template<> void $NameUint<1>::d_eq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xnor(b[0], a[0]);
}
template<> void $NameUint<1>::d_ge
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n5);
}
template<> void $NameUint<1>::d_gesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n5);
}
template<> void $NameUint<1>::d_gt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void $NameUint<1>::d_gtsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(a[0]);
  y[0] = gate_and(b[0], n2);
}
template<> void $NameUint<1>::d_inc
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_ineq
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<1>::d_intmux
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b, const vector<Bit> & c) noexcept
{
  y[0] = gate_mux(c[0], b[0], a[0]);
}
template<> void $NameUint<1>::d_le
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(b[0]);
  y[0] = gate_nand(a[0], n5);
}
template<> void $NameUint<1>::d_lesig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n5 = gate_not(a[0]);
  y[0] = gate_nand(b[0], n5);
}
template<> void $NameUint<1>::d_logand
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<1>::d_lognot
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_logor
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_or(a[0], b[0]);
}
template<> void $NameUint<1>::d_lt
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(a[0]);
  y[0] = gate_and(b[0], n2);
}
template<> void $NameUint<1>::d_ltsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void $NameUint<1>::d_mod
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(b[0]);
  y[0] = gate_and(a[0], n1);
}
template<> void $NameUint<1>::d_modsig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n1 = gate_not(b[0]);
  y[0] = gate_and(a[0], n1);
}
template<> void $NameUint<1>::d_mul
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_and(b[0], a[0]);
}
template<> void $NameUint<1>::d_redand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void $NameUint<1>::d_rednand
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_rednor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_redor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void $NameUint<1>::d_redxnor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  y[0] = gate_not(a[0]);
}
template<> void $NameUint<1>::d_redxor
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void $NameUint<1>::d_sll
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void $NameUint<1>::d_slr
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto n2 = gate_not(b[0]);
  y[0] = gate_and(a[0], n2);
}
template<> void $NameUint<1>::d_srasig
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
template<> void $NameUint<1>::d_sub
(vector<Bit> & y, const vector<Bit> & a, const vector<Bit> & b) noexcept
{
  y[0] = gate_xor(b[0], a[0]);
}
template<> void $NameUint<1>::d_uminus
(vector<Bit> & y, const vector<Bit> & a) noexcept
{
  auto _y0 = gate_buf(a[0]);
  y[0] = gate_buf(_y0);
}
