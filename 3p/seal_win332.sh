#!/bin/bash

PLAT=win
me="=== 3p ==="

root=../../e3_seal
sealdir=$root/SEAL
cwd=`pwd`
target=$cwd/seal_$PLAT.332

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
	git -c http.sslVerify=false clone --depth 1 --branch 3.3.2 https://github.com/Microsoft/SEAL
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
file=seal.lib
mkdir -p $target/lib
x3264=`bash test_win.sh`
spath=$sealdir/native/lib/$x3264/Release/$file
tpath=$target/lib/$file

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
		echo "Use Options -> C++ -> Code Gen -> Runtime Lib -> MT"
		exit
	fi
	cp $spath $target/lib/
fi

echo ""
echo "Step 3"
echo -n "$me check headers: "
file=seal.h
spath=$sealdir/native/src/seal
tpath=$target/include/seal

if test -f $tpath/$file; then
	echo "YES"
else
	echo "NO"
	echo "$me copying headers"

	mkdir -p $tpath/util
	cp $spath/*.h $tpath/
	cp $spath/util/*.h $tpath/util/

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

