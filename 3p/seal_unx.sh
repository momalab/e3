#!/bin/bash


PLAT=unx
me="=== 3p ==="

root=../../e3_seal.372
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
	git -c http.sslVerify=false clone --depth 1 --branch 3.7.2 https://github.com/Microsoft/SEAL
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
cd $path
cmake -S . -B build -DSEAL_THROW_ON_TRANSPARENT_CIPHERTEXT=OFF
cmake --build build
#cmake -DCMAKE_INSTALL_PREFIX=$target .
#make
#make install

echo ""
echo "Step 3x"
echo "$me set up native and target"
cd $target
if [ ! -d "native" ]; then
	mkdir native
fi
if [ ! -d target ]; then
	mkdir target
fi

cp ../$path/build/lib/*.a native/
cp ../$path/build/lib/*.a target/
cp native/libseal-3.7.a native/libseal.a
cp target/libseal-3.7.a target/libseal.a

cd $cwd

echo ""
echo "Step 3a"
echo -n "$me check headers: "
file=seal.h
spath=$sealdir/native/src/seal
spatb=$sealdir/build/native/src/seal
tpath=$target/include/seal

if test -f $tpath/$file; then
	echo "YES"
else
	echo "NO"
	echo "$me copying headers"

	mkdir -p $tpath/util
	cp $spath/*.h $tpath/
	cp $spath/util/*.h $tpath/util/
	cp $spatb/util/*.h $tpath/util/

	if test -f $tpath/$file; then
		:
	else
		echo "Error when copying headers"
		exit
	fi
fi

#e3_seal\SEAL\thirdparty\msgsl-src\include\

echo ""
echo "Step 3b."
echo -n "$me check headers: "
file=gsl
spath=$sealdir/thirdparty/msgsl-src/include/gsl
tpath=$target/include/gsl

if test -f $tpath/$file; then
	echo "YES"
else
	echo "NO"
	echo "$me copying headers"

	mkdir -p $tpath
	cp $spath/* $tpath/

	if test -f $tpath/$file; then
		:
	else
		echo "Error when copying headers"
		exit
	fi
fi

cd $cwd

exit
