
srcu2=cpp_share/util/e3util.cpp \
	cpp_share/util/def_fhew$(FHEW).cpp \
	cpp_share/util/def_heli$(HELI).cpp \
	cpp_share/util/def_seal$(SEAL).cpp \
	cpp_share/util/def_tfhe$(TFHE).cpp \
	cpp_share/util/def_mpir$(MPIR).cpp \
	cpp_share/util/def_pil.cpp \
	cpp_share/util/base64.cpp
obju2 := $(srcu2:cpp_share/util/%.cpp=$(BIN)/%.$(OEXT))

srck2= ${EKDIR}/ek_abstract.cpp ${EKDIR}/ek_native.cpp \
	${EKDIR}/anykey.cpp \
	${EKDIR}/ek_circ_plain.cpp \
	${EKDIR}/ek_circ_pil.cpp \
	${EKDIR}/ek_circ_fhew$(FHEW).cpp \
	${EKDIR}/ek_circ_heli$(HELI).cpp \
	${EKDIR}/ek_circ_seal$(SEAL).cpp \
	${EKDIR}/ek_circ_tfhe$(TFHE).cpp \
	${EKDIR}/ek_circ_bdd.cpp \
	${EKDIR}/ek_circ.cpp ${EKDIR}/ek_pil.cpp
objk2 := $(srck2:${EKDIR}/%.cpp=$(BIN)/%.$(OEXT))
