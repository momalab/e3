#!/bin/bash

# this file sets Libs link variables


if test -f cgt.exe; then
:
else
echo "Error: cgt.exe not found"
exit 1
fi

# check CGT libraries
libstfh=(`./cgt.exe | grep LibsTSFHMC`)
libs=${libstfh[6]}
code=${libstfh[7]}
if [ "$libs" != "LibsTSFHMC" ]; then
  echo "Bad libs name in CGT [$libs]"
  exit 1
fi
##code=123456
#echo "Libs build: code=$code"
TFHE=${code:0:1}
SEAL=${code:1:1}
FHEW=${code:2:1}
HELI=${code:3:1}
MPIR=${code:4:1}
CUDD=${code:5:1}
echo "Libs build: code=$code TFHE=$TFHE SEAL=$SEAL FHEW=$FHEW HELI=$HELI MPIR=$MPIR CUDD=$CUDD"

