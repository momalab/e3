#!/bin/bash

# Visual Studio version, reset if different
VS=19

PLAT=win
me="=== 3p ==="

root=../../e3_mpir_$PLAT
mpirdir=$root/mpir

echo "$me Cooking MPIR for $PLAT"

echo ""
echo "Step 1"
echo -n "$me MPIR checkout: "
file=Makefile.am
path=$mpirdir/$file
if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out MPIR"
	mkdir -p $root
	pushd $root
	git -c http.sslVerify=false clone --depth 1 --branch master https://github.com/BrianGladman/mpir.git
	popd
		if test -f $path; then
			echo "$me done"
		else
			echo "$me failed to checkout MPIR"
			exit
		fi
fi

echo ""
echo "Step 2"
echo -n "$me test MS compiler: "
msplat=undefined
file32=test_x32
file64=test_x64
rm -f $file32.obj $file64.obj
cl -c -nologo $file32.cpp > /dev/null
cl -c -nologo $file64.cpp > /dev/null

if test -f $file32.obj; then
	msplat=Win32
elif test -f $file64.obj; then
	msplat=x64
else
	echo "No MS compiler available"
	exit
fi
rm -f $file32.obj $file64.obj
echo $msplat

echo ""
echo "Step 3"
echo -n "$me check libraries: "

bin=mpir_$PLAT
##path=$bin/$testfile2.cpp
mpirxx=mpirxx.lib
fmpirxxdir=$mpirdir/msvc/vs$VS/lib_mpir_cxx/$msplat/Release
fmpirgcdir=$mpirdir/msvc/vs$VS/lib_mpir_gc/$msplat/Release
fmpirxxlib=$fmpirxxdir/$mpirxx

mkdir -p $bin

fcp()
{
	if test -f $1; then
		cp $1 $2/
	else
		echo "No file: $1"
		exit
	fi
}

if test -f $bin/$mpirxx; then
	echo "YES"
else
	echo "NO"
	echo "$me cheking if libraries are built"
	echo $fmpirxx
	if test -f $fmpirxxlib; then
		echo "copying mpirxx.lib and other ingredients"

		# copy lib headers
		fcp $fmpirxxdir/config.h $bin
		fcp $fmpirxxdir/gmp-impl.h $bin
		fcp $fmpirxxdir/gmp-mparam.h $bin
		fcp $fmpirxxdir/mpirxx.h $bin
		fcp $fmpirxxdir/mpir.h $bin

		# copy test files
		fcp $mpirdir/tests/memory.c $bin
		fcp $mpirdir/tests/misc.c $bin
		fcp $mpirdir/tests/tests.h $bin
		fcp $mpirdir/tests/cxx/t-binary.cc $bin

		# final copy
		fcp $fmpirgcdir/mpir.lib $bin
		fcp $fmpirxxdir/mpirxx.lib $bin
	else
		echo "The library $fmpirxxlib is not built"
		echo "1. Check that the VS version (this script set VS=$VS) is right"
		echo "2. Goto $mpirdir/msvc/vs$VS and start mpir.sln"
		echo "3. Select Release and Win32 or x64"
		echo "4. Fix SDK versions in lib_ projects (properties)"
		echo "5. Build first 'lib_mpir_gc' then 'lib_mpir_cxx'"
		echo "6. Verify $fmpirxxlib"
		exit
	fi
fi


echo ""
echo "Step 4"
echo -n "$me check build: "

testfile=t-binary.exe

if test -f $bin/$testfile; then
	echo "YES"
else
	echo "NO"
	echo "$me compiling"
	echo "cl -EHsc t-binary.cc misc.c memory.c -I. mpirxx.lib mpir.lib"
	cd $bin
	cl -EHsc t-binary.cc misc.c memory.c -I. mpirxx.lib mpir.lib
	cd ..

	if test -f $bin/$testfile; then
		echo "Compilation: ok"
	else
		echo "Compilation failed"
		exit
	fi
fi


echo ""
echo "Step 5 - faking plats"
files="mpir.lib mpirxx.lib"
path1=$bin/native/mpirxx.lib
path2=$bin/target/mpirxx.lib
echo -n "$me $path1 $path2: "
if test -f $path1 && test -f $path2; then
	echo "YES"
else
	echo "NO"
	echo "$me faking platforms"
	pushd mpir_$PLAT > /dev/null
	mkdir -p native
	cp $files native/
	mkdir -p target
	cp $files target/
	popd > /dev/null
fi
