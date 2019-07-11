// === BEGIN circuit.base.h Name=$Name

class $NameBit;

class $NameBaseBit
{
    protected:
        ///struct PekInitializer { PekInitializer( void(*f)() ) { f(); } } pekInitializer;
        static CircuitEvalKey * pek;
        static void init_pek();
        static const char * name() { return "$Ename"; }

        $NameBaseBit() { init_pek(); }

    public:
        static const $NameBit * zero, * unit;
};

// === END circuit.base.h Name=$Name
