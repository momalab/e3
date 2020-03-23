// === BEGIN circuit.base.h Name=$Name

class $NameBit;

class $NameBaseBit
{
    protected:
        static e3::CircuitEvalKey * pek;
        static void init_pek();

        $NameBaseBit() { init_pek(); }

        static std::string fs(const string & s);

    public:
        static const char * typname() { return "$Name"; } // User class
        static const char * filname() { return "$Filencname"; } // key file
        static const char * clsname() { return "$Clsencname"; } // key class

        static const $NameBit * zero, * unit;
};

// === END circuit.base.h Name=$Name
