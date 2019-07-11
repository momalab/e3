#pragma once

#include "ek_circ.h"
#include "e3util.h"
#include "def_pil.h"
#include "ek_pil.h"

namespace e3
{

class CircuitEvalKey_pilc : public CircuitEvalKey
{
        static const bool NOCOUT = false;

    public: // let nameBit directly access
        PilBaseEvalKey bek;

    public:
        CircuitEvalKey_pilc(User u, std::string name)
            : CircuitEvalKey(name), bek(0) { user(u); }

        virtual bool load() { return bek.load(filename()); }
        virtual std::string filename() const { return EvalKey::filename(); }

    private:
        void dummy() const;
};


} // e3
