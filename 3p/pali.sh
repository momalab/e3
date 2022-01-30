#!/bin/bash

## https://gitlab.com/palisade/palisade-release.git

#git -c http.sslVerify=false clone --depth 1 https://gitlab.com/palisade/palisade-release.git
#cd palisade-release
#git submodule sync --recursive
#git submodule update --init  --recursive
#mkdir build
#cd build
#cmake -DCMAKE_INSTALL_PREFIX=_ins ..
## faster
#make -j 3
## slower
#make
#make install
## check run : bin/examples/pke/simple-integers

echo "== Checking dependencies =="
dependencies=( autoconf cmake git libtool lzip make g++ )
dependenciesInstalled=true
for dependency in "${dependencies[@]}"; do
    echo -n "${dependency} .. "
    dpkg -s ${dependency} &> /dev/null
    if [ $? -eq 0 ]; then
        echo "ok"
    else
        echo "failed"
        dependenciesInstalled=false
    fi
done

if [ "${dependenciesInstalled}" = false ]; then
    echo "Install missing dependencies"
    exit
fi
echo

PLAT=unx
test -f ../src/mingw && PLAT=mgw

cwd=`pwd`
target=$cwd/pali_$PLAT

me="=== 3p ==="

root=../../e3_pali
palipath=$root/palisade-release
builddir=$palipath/build

echo "$me Cooking PALI for $PLAT"

echo ""
echo "Step 1"
echo -n "$me PALI checkout: "
file=Makefile
path=$palipath/$file

if test -f $path; then
	echo "YES"
else
	echo "NO"
	echo "$me checking out PALI"
	mkdir -p $root
	pushd $root
	git -c http.sslVerify=false clone --depth 1 https://gitlab.com/palisade/palisade-release.git
	popd
		if test -f $path; then
			echo "$me done"
		else
			echo "$me failed to checkout PALI"
			exit
		fi
fi


echo ""
echo "Step 2"
echo -n "$me Check PALI third-party: "
file=include
path=$palipath/third-party/cereal/$file

if test -d $path; then
	echo "YES"
else
	echo "NO $path"

	pushd $palipath
	git submodule sync --recursive
	git submodule update --init  --recursive
	popd

		if test -d $path; then
			echo "$me done"
		else
			echo "$me failed to checkout PALI third-party"
			exit
		fi
fi


echo ""
echo "Step 3"
echo -n "$me PALI build: "
file=palisade
path=$palipath/build/_ins/include/$file

if test -d $path; then
	echo "YES"
else
	echo "NO $path"

	pushd $palipath
	mkdir -p build
	pushd build
	# cmake -DCMAKE_INSTALL_PREFIX=_ins ..
    # cmake -DWITH_NTL=Y -DCMAKE_INSTALL_PREFIX=_ins ..
	cmake -DWITH_NTL=Y -DWITH_TCM=Y -DCMAKE_INSTALL_PREFIX=_ins ..
    make gmp_unpack
    make ntl_unpack
    make gmp_all
    make ntl_all
    make tcm
	make
	make install
	popd
	popd

		if test -d $path; then
			echo "$me done"
		else
			echo "$me failed to build PALI"
			exit
		fi
fi

echo ""
echo "Step 4"
echo -n "$me make PALI ingredients: "
file=palisade.h
path=$target/include/palisade/pke/$file

if test -f $path; then
	echo "YES"
else
	echo "NO $path"

	mkdir -p $target
	pushd $target
	cp ../pali_$PLAT.mak ./
	make -f pali_$PLAT.mak
	popd

		if test -f $path; then
			echo "$me done"
		else
			echo "$me failed to make PALI ingredients"
			exit
		fi
fi


echo ""
echo "Step 5"
echo "$me set up native and target"
pushd $target
if [ ! -d "native" ]; then
	mkdir native
fi
if [ ! -d target ]; then
	mkdir target
fi
# palipath=../$palipath
# cp $palipath/build/third-party/lib/lib* lib/
# cp $palipath/build/third-party/include/gmp.h include/
# cp -R $palipath/build/third-party/include/NTL include/
cp lib/lib* native/
cp lib/lib* target/

popd

echo "Mingw: Copy DLLs into reachable path."
echo "Unix: Add LD_LIBRARY_PATH by:"
echo "export LD_LIBRARY_PATH=`pwd`/pali_$PLAT/native"

exit
