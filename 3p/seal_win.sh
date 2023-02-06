#!/bin/bash

PLAT=win
me="=== 3p ==="

root=../../e3_seal
sealdir=$root/SEAL
cwd=`pwd`
#target=$cwd/seal_$PLAT.372
target=$cwd/seal_$PLAT

echo "$me Cooking SEAL for $PLAT"

echo ""
echo "Step 1"
echo -n "$me SEAL checkout: "
file=README.md
path=$sealdir/$file
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


echo ""
echo "Step 2"
echo -n "$me check libs: "
file1=seal-3.7.lib
file2=seal.lib
mkdir -p $target/lib
x3264=`bash test_win.sh`

if [ "$x3264" = "x64" ] ; then
:
else
echo "Now we support only 64 bit (x64)"
fi

spath=$sealdir/build/lib/Release/$file1
#spath=$sealdir/build/lib/$file1
tpath=$target/lib/$file2

if test -f $tpath; then
	echo "YES"
else
	echo "NO"
	echo "$me copying lib"

	if test -f $spath; then
		:
	else
		echo "Error: no lib $spath"
		echo "Please build SEAL using external tool, e.g. with Visual Studio"
		echo "$> cmake -S . -B build -G \"Visual Studio 16 2019\" -A x64"
		echo "$> cmake -S . -B build -G \"Visual Studio 17 2022\" -A x64"
		#echo "$> cmake --build build"
		echo "Then build .sln (project 'seal') in build"
		echo "Select Release, select project 'seal'"
		echo "Use Options -> C++ -> Code Gen -> Runtime Lib -> MT"
		exit
	fi
	cp $spath $target/lib/$file2
fi

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

echo ""
echo "Step 4"
echo "$me set up native and target"
cd $target
mkdir -p native
mkdir -p target
cp lib/*.lib native/
cp lib/*.lib target/

cd $cwd

echo "done"
exit

