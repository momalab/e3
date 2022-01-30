#!/bin/bash

PLAT=unx
me="=== 3p ==="

root=../../e3_seal
sealdir=$root/SEAL
cwd=`pwd`
target=$cwd/seal_$PLAT

echo "$me Cooking SEAL for $PLAT"

echo ""
echo "Step 1"
echo -n "$me SEAL checkout: "
# file=Makefile
path=$sealdir #/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out SEAL"
	mkdir -p $root
	cd $root
	# git -c http.sslVerify=false clone --depth 1 --branch master https://github.com/Microsoft/SEAL
	git -c http.sslVerify=false clone --depth 1 --branch 3.3.2 https://github.com/Microsoft/SEAL
	cd $cwd
	if [ -d "$path" ]; then
		echo "$me done"
	else
		echo "$me failed to checkout SEAL"
		exit
	fi
fi

echo "$me checking dependencies"

if cmake --help > /dev/null; then
	echo "$me using cmake"
else
	echo "$me cmake not found, exiting"
	echo "$me install with: sudo apt install cmake"
	exit
fi

echo ""
echo "Step 2"
echo "$me make"
if [ ! -d "$target" ]; then
	mkdir $target
fi
cd $path/native/src
cmake -DCMAKE_INSTALL_PREFIX=$target .
make
make install

echo ""
echo "Step 3"
echo "$me set up native and target"
cd $target
if [ ! -d "native" ]; then
	mkdir native
fi
if [ ! -d target ]; then
	mkdir target
fi
cp lib/*.a native/
cp lib/*.a target/

cd $cwd
exit
