// === BEGIN circuit.base.h Name=$Name

class $NameBit;

class $NameBaseBit
{
    protected:
        static e3::CircuitEvalKey * pek;
        static void init_pek();

        $NameBaseBit() { init_pek(); }

    public:
        static const char * typname() { return "$Name"; }
        static const char * filname() { return "$Filencname"; }
        static const char * clsname() { return "$Clsencname"; }

        static const $NameBit * zero, * unit;
};

// === END circuit.base.h Name=$Name
