// === BEGIN circuit.cpp Name=$Name

CircuitEvalKey * g_pek_$Name = nullptr;
CircuitEvalKey * $NameBit::pek = nullptr;
const $NameBit * $NameBit::zero = nullptr;

void $NameBit::init_pek()
{
    if ( pek ) return;
    ///std::cout << "AAA init_pek\n";

    initEvalKey
    < CircuitEvalKey, CircuitEvalKey_$Encryption >
    (name(), pek, g_pek_$Name);

    if ( !zero ) zero = new $NameBit("$BitZero");
}

// === END circuit.cpp Name=$Name
