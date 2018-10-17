// === BEGIN circuit.cpp Name=$Name

CircuitEvalKey * g_pek_$Name = nullptr;
CircuitEvalKey * $NameBit::pek = nullptr;
const $NameBit * $NameBit::zero = nullptr;

void $NameBit::init_pek()
{
    if ( pek ) return;

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_$Encryption >
    (name(), pek, g_pek_$Name);

    if ( !zero ) zero = new $NameBit("$BitZero");
}

// FIXME to be removed
// $NameBool $NameBool::operator&&(const $NameBool & a) const
// {
//     $NameBool r;
//     d_bitand(r.bits, bits, a.bits);
//     return r;
// }

// === END circuit.cpp Name=$Name
