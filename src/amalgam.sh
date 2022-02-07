#!/bin/bash
# Copyright 2022 MoMA Lab, NYU Abu Dhabi (wp.nyu.edu/momalab/)

# this file generates amalgamation of cpp_share

# definitions
amaname=cgtshared
cppshare=cpp_share
util=$cppshare/util
keys=$cppshare/keys
header=$amaname.h
cxfile=$amaname.cpp

echo "Amalgamating of cgt shared files"

source ./codelib.sh


: > $cxfile
echo "#include <algorithm>" >> $cxfile
echo "#include <sstream>" >> $cxfile
echo "#include <string>" >> $cxfile
echo "#include <vector>" >> $cxfile
echo "#include <map>" >> $cxfile
echo "#include <fstream>" >> $cxfile
echo "#include <iostream>" >> $cxfile
echo "" >> $cxfile
echo "#include \"$header\"" >> $cxfile
echo "" >> $cxfile
echo "using std::cout;" >> $cxfile
echo "using std::string;" >> $cxfile
echo "" >> $cxfile


echo "#pragma once" > $header
echo "" >> $header
echo "#include <complex>" >> $header
echo "#include <istream>" >> $header
echo "#include <memory>"  >> $header
echo "#include <ostream>" >> $header
echo "#include <string>"  >> $header
echo "#include <vector>"  >> $header
echo "" >> $header

# include specific libraries
echo "// TFHE=$TFHE SEAL=$SEAL FHEW=$FHEW HELI=$HELI MPIR=$MPIR CUDD=$CUDD PALI=$PALI" >> $header
echo "" >> $header


if [ "$MPIR" != "0" ]; then
echo "// including MPIR" >> $header
echo "#include \"mpir.h\"" >> $header
echo "#include \"mpirxx.h\"" >> $header
echo "#include \"gmp-impl.h\"" >> $header
fi

if [ "$MPIR" == "2" ] || [ "$MPIR" == "3" ] ; then
echo "#include <fcntl.h>" >> $header
echo "#include <termios.h>" >> $header
echo "#include <unistd.h>" >> $header
fi

if [ "$TFHE" = "1" ]; then
echo "// including TFHE" >> $header
echo "#include \"tfhe.h\"" >> $header
echo "#include \"tfhe_io.h\"" >> $header
fi

if [ "$SEAL" = "1" ]; then
echo "// including SEAL" >> $header
echo "#include \"seal/seal.h\"" >> $header
fi

if [ "$FHEW" = "1" ]; then
echo "// including FHEW" >> $header
echo "#include \"LWE.h\"" >> $header
echo "#include \"FHEW.h\"" >> $header
fi

if [ "$HELI" = "1" ]; then
echo "// including HELI" >> $header
echo "#include \"FHE.h\"" >> $header
echo "#include \"EncryptedArray.h\"" >> $header
fi

if [ "$PALI" = "1" ]; then
echo "// including PALI" >> $header
echo "#include \"palisade.h\"" >> $header
echo "#include \"ciphertext-ser.h\"" >> $header
echo "#include \"cryptocontext-ser.h\"" >> $header
echo "#include \"pubkeylp-ser.h\"" >> $header
echo "#include \"scheme/bfvrns/bfvrns-ser.h\"" >> $header
echo "#include \"scheme/ckks/ckks-ser.h\"" >> $header
echo "#include \"utils/serialize-binary.h\"" >> $header
fi

echo "// start header amalgama" >> $header

dof()
{
echo "" >> $1
echo "// *** begin $2" >> $1
cat $2 | grep -v "#pragma\|#include" >> $1
echo "// *** end $2" >> $1
}

# do util headers
dof $header $util/e3util.h
dof $header $util/e3math.h
dof $header $util/base64.h
dof $header $util/cophee.h
dof $header $util/def_fhew.h
dof $header $util/def_fhew$FHEW.h
dof $header $util/def_heli.h
dof $header $util/def_heli$HELI.h
dof $header $util/def_mpir.h
dof $header $util/def_mpir$MPIR.h
dof $header $util/def_pil.h
dof $header $util/def_seal.h
dof $header $util/def_seal$SEAL.h
dof $header $util/def_seal_ckks.h
dof $header $util/def_seal_ckks$SEAL.h
dof $header $util/def_tfhe.h
dof $header $util/def_tfhe$TFHE.h
dof $header $util/def_bfv.h
dof $header $util/def_pali.h
dof $header $util/def_pali$PALI.h
dof $header $util/def_palisade_ckks.h
dof $header $util/def_palisade_ckks$PALI.h

# do key headers
dof $header $keys/anykey.h
dof $header $keys/ek_abstract.h
dof $header $keys/ek_seal.h
dof $header $keys/ek_seal_ckks.h
dof $header $keys/ek_arith_seal.h
dof $header $keys/ek_arith_seal_ckks.h
dof $header $keys/ek_pil.h
dof $header $keys/ek_pail.h
dof $header $keys/ek_circ.h
dof $header $keys/ek_circ_bdd.h
dof $header $keys/ek_circ_fhew.h
dof $header $keys/ek_circ_heli.h
dof $header $keys/ek_circ_pil.h
dof $header $keys/ek_circ_plain.h
dof $header $keys/ek_circ_seal.h
dof $header $keys/ek_circ_tfhe.h
dof $header $keys/ek_native.h
dof $header $keys/ek_bfv_prot.h
dof $header $keys/ek_pali.h
dof $header $keys/ek_circ_gatcou.h
dof $header $keys/ek_palisade_ckks.h

# do util cpps
dof $cxfile $util/def_mpir.inc
dof $header $util/e3math.inc
dof $cxfile $util/e3util.cpp
dof $cxfile $util/cophee$MPIR.cpp
dof $cxfile $util/base64.cpp
dof $cxfile $util/def_fhew$FHEW.cpp
dof $cxfile $util/def_heli$HELI.cpp
dof $cxfile $util/def_mpir$MPIR.cpp
dof $cxfile $util/def_pil.cpp
dof $cxfile $util/def_seal$SEAL.cpp
dof $cxfile $util/def_seal_ckks$SEAL.cpp
dof $cxfile $util/def_tfhe$TFHE.cpp
dof $cxfile $util/def_bfv.cpp
dof $cxfile $util/def_pali$PALI.cpp
dof $cxfile $util/def_pali_sis$PALI.cpp
dof $cxfile $util/def_palisade_ckks$PALI.cpp
dof $cxfile $util/def_palisade_ckks_util$PALI.cpp

# do keys cpps
dof $cxfile $keys/anykey.cpp
dof $cxfile $keys/ek_abstract.cpp
dof $cxfile $keys/ek_circ.cpp
dof $cxfile $keys/ek_circ_bdd.cpp
dof $cxfile $keys/ek_circ_fhew$FHEW.cpp
dof $cxfile $keys/ek_circ_heli$HELI.cpp
dof $cxfile $keys/ek_circ_pil.cpp
dof $cxfile $keys/ek_circ_plain.cpp
dof $cxfile $keys/ek_circ_tfhe$TFHE.cpp
dof $cxfile $keys/ek_native.cpp
dof $cxfile $keys/ek_pil.cpp
dof $cxfile $keys/ek_pail.cpp
dof $cxfile $keys/ek_seal$SEAL.cpp
dof $cxfile $keys/ek_seal_ckks$SEAL.cpp
dof $cxfile $keys/ek_bfv_prot.cpp
dof $cxfile $keys/ek_pali$PALI.cpp
dof $cxfile $keys/ek_palisade_ckks$PALI.cpp

# test compilation - remove later
#cl -c -EHsc $amaname.cpp

echo "Files have been created: $cxfile and $header"
