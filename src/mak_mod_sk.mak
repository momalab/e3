# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

srcu1=cpp_cgt/util/os_filesys.cpp cpp_cgt/util/cgtutil.cpp \
	cpp_cgt/util/timer.cpp cpp_cgt/util/euler.cpp
obju1 := $(srcu1:cpp_cgt/util/%.cpp=$(BIN)/%.$(OEXT))

srck1= ${SKDIR}/sk_native.cpp ${SKDIR}/ekx_native.cpp \
	${SKDIR}/sk_abstract.cpp \
	${SKDIR}/sk_seal$(SEAL).cpp ${SKDIR}/ekx_seal$(SEAL).cpp \
	${SKDIR}/sk_pali$(PALI).cpp ${SKDIR}/ekx_pali$(PALI).cpp \
	${SKDIR}/sk_palisade_ckks$(PALI).cpp ${SKDIR}/ekx_palisade_ckks$(PALI).cpp \
	${SKDIR}/sk_seal_ckks$(SEAL).cpp ${SKDIR}/ekx_seal_ckks$(SEAL).cpp \
	${SKDIR}/sk_bfv_prot.cpp ${SKDIR}/ekx_bfv_prot.cpp \
	${SKDIR}/sk_circ.cpp ${SKDIR}/sk_pil.cpp ${SKDIR}/ekx_pil.cpp \
	${SKDIR}/sk_circ_bdd.cpp ${SKDIR}/ekx_circ_bdd.cpp \
	${SKDIR}/sk_circ_fhew$(FHEW).cpp ${SKDIR}/ekx_circ_fhew$(FHEW).cpp \
	${SKDIR}/sk_circ_heli$(HELI).cpp ${SKDIR}/ekx_circ_heli$(HELI).cpp \
	${SKDIR}/sk_circ_pil.cpp ${SKDIR}/ekx_circ_pil.cpp \
	${SKDIR}/sk_circ_plain.cpp ${SKDIR}/ekx_circ_plain.cpp \
	${SKDIR}/sk_circ_tfhe$(TFHE).cpp ${SKDIR}/ekx_circ_tfhe$(TFHE).cpp \
	${SKDIR}/sk_pail.cpp ${SKDIR}/ekx_pail.cpp
objk1 := $(srck1:${SKDIR}/%.cpp=$(BIN)/%.$(OEXT))
