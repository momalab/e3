inline $Name1 to_$Name1(const $Name0Bool & c) { return $Name1(c[0].native()); }
inline $Name1 operator*(const $Name1 & m, const $Name0Bool & c) { return m * to_$Name1(c);}
inline $Name1 operator*(const $Name0Bool & c, const $Name1 & m) { return m * c; }

template<int SZ>
inline $Name1 to_$Name1(const $Name0Uint<SZ> & c, int i){ return $Name1(c[i].native()); }
