// Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)
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

        $NameBaseBit & rotate_columns() { return *this; }
        $NameBaseBit & rotate_rows(int s) { return *this; }
};

// === END circuit.base.h Name=$Name
