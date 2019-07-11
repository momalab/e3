// === BEGIN circuit.cpp Name=$Name

CircuitEvalKey * g_pek_$Name = nullptr;
CircuitEvalKey * $NameBaseBit::pek = nullptr;
const $NameBit * $NameBaseBit::zero = nullptr;
const $NameBit * $NameBaseBit::unit = nullptr;

void $NameBaseBit::init_pek()
{
    using namespace e3;
    if ( pek ) return;

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_$Encryption >
    (name(), pek, g_pek_$Name);

    if ( !zero ) zero = new $NameBit("$BitZero");
    if ( !unit ) unit = new $NameBit("$BitUnit");
}

// === END circuit.cpp Name=$Name
