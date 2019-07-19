#!/bin/bash

set -e
trap 'echo "Command filed with exit code $?."' EXIT

PLAT=unx
me="=== e3 ==="
root=../tests/user


## Additional Functions ##

compare_result() {
	if [[ $1 != $2 ]]; then
		echo "Test failed"
		rm -rf result.txt
		exit
	else
		return 11
	fi
}

# progress_dot() {
# 	pid=$1

# 	# If this script is killed, kill the `pid'.
# 	trap "kill $pid 2> /dev/null" EXIT

# 	# While pid is running...
# 	while (kill -0 $pid 2> /dev/null); do
#         printf "."
#         sleep 1
# 	done
# 	printf "OK"

# 	# Disable the trap on a normal exit.
# 	trap - EXIT
# }

progress_bar() {
    bar="##################################################"
    barlength=${#bar}

	trap "kill $2 2> /dev/null" EXIT
	while (kill -0 $2 2> /dev/null); do
    	for (( i=1 ; i <= $1 ; i++ ))
    	do   
        	n=$(($i*barlength/$1))
        	printf "\r[%-${barlength}s (%d%%)] " "${bar:0:n}" "$(($i*100/$1))" 
        	sleep 1
    	done
	done
	printf "\r[%-${barlength}s (%d%%)] " "${bar:0:50}" "100" 

	trap - EXIT
}


## Functions to check different encryption schemes ##

check_TFHE() {
	echo "$me check TFHE"
	path=$root/tfhe
	CGT=$path/cgt.cfg

	path1=../3p/tfhe_$PLAT/native/libtfhe.a
	path2=../3p/tfhe_$PLAT/target/libtfhe.a

	if test -f $path1 && test -f $path2; then
		echo "Using TFHE library"
	else
		echo "USER ATTENTION!"
		echo "This script does not automatically build TFHE."
		echo "Please follow the user manual and install"
		echo "TFHE on this and the target platforms."
		echo "Use the following commands to install it:"
		echo "$ cd ../3p"
		echo "$ make TFHE"
		exit
	fi

	make c > /dev/null
	printf "Generating cgt.exe"
	make USER=$path TFHE=1 > /dev/null & progress_bar 84 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	# chmod +x bob.exe
	# chmod +x cgt.exe
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 5 4)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "TFHE checked" 
	fi
	rm -rf result.txt
}

check_HElib() {
	echo "$me check HElib"
	path=$root/heli 
	CGT=$path/cgt.cfg

	path1=../3p/heli_$PLAT/native/fhe.a
	path2=../3p/heli_$PLAT/target/fhe.a

	if test -f $path1 && test -f $path2; then
		echo "Using HElib library"
	else
		echo "USER ATTENTION!"
		echo "This script does not automatically build HElib."
		echo "Please follow the user manual and install"
		echo "HElib on this and the target platforms."
		echo "Use the following commands to install it:"
		echo "$ cd ../3p"
		echo "$ make HElib"
		echo "NOTE: Installing HElib requires additional packages: plzip."
		exit
	fi

	make c &> /dev/null
	echo "Generating cgt.exe..."

	make USER=$path HELI=1 > /dev/null & progress_bar 88 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 -2 6 1 4 3)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "HElib checked"
	fi
	rm -rf result.txt
}

check_FHEW() {
	echo "$me check FHEW"
	path=$root/fhew 
	CGT=$path/cgt.cfg

	path1=../3p/fhew_$PLAT/native/libfhew.a
	path2=../3p/fhew_$PLAT/target/libfhew.a

	if test -f $path1 && test -f $path2; then
		echo "Using FHEW library"
	else
		echo "USER ATTENTION!"
		echo "This script does not automatically build FHEW."
		echo "Please follow the user manual and install"
		echo "FHEW on this and the target platforms."
		echo "Use the following commands to install it:"
		echo "$ cd ../3p"
		echo "$ make FHEW"
		exit
	fi

	make c > /dev/null
	echo "Generating cgt.exe..."

	#FIXME: MOCK used instead of FHEW due to compilation errors in FHEW
	make USER=$path FHEW=0 > /dev/null & progress_bar 104 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 0 0 0 0 7 0 0)
	while IFS="=" read -r desc val; do
		if [ ${correct[iter]} != 0 ]; then
			compare_result $val ${correct[iter]}
			final=$?
		fi
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "FHEW checked"
	fi
	rm -rf result.txt
}

check_SEAL() {
	echo "$me check SEAL"
	path=$root/seal 
	CGT=$path/cgt.cfg

	path1=../3p/seal_$PLAT/native/libseal.a
	path2=../3p/seal_$PLAT/target/libseal.a

	if test -f $path1 && test -f $path2; then
		echo "Using FHEW library"
	else
		echo "USER ATTENTION!"
		echo "This script does not automatically build SEAL."
		echo "Please follow the user manual and install"
		echo "SEAL on this and the target platforms."
		echo "Use the following commands to install it:"
		echo "$ cd ../3p"
		echo "$ make SEAL"
		exit
	fi

	make c > /dev/null
	echo "Generating cgt.exe..."

	#FIXME: MOCK used instead of SEAL
	make USER=$path SEAL=0 > /dev/null & progress_bar 107 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt
	four=$(awk 'NR == 4 {print $0}' result.txt)

	if [ $four != 4 ]; then
		echo "Test failed"
		rm -rf result.txt
		exit
	else
		echo "SEAL checked"
		rm -rf result.txt
	fi
}

check_PIL() {
	path1=../3p/mpir_$PLAT/native/libcxx.a
	path2=../3p/mpir_$PLAT/target/libcxx.a

	if test -f $path1 && test -f $path2; then
		echo "Using MPIR library"
	else
		echo "USER ATTENTION!"
		echo "This script does not automatically build MPIR."
		echo "Please follow the user manual and install"
		echo "MPIR on this and the target platforms."
		echo "Use the following commands to install it:"
		echo "$ cd ../3p"
		echo "$ make MPIR"
		echo "NOTE: Installing MPIR requires additional packages: yasm, m4."
		exit
	fi

	echo ""
	echo "$me check PILA for PIL"
	path=$root/pila
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 > /dev/null & progress_bar 104 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	iter=0
	correct=(0 28 1045563287892137766342366891529347017067793485384657753314482765037292502557 75)
	while IFS="=" read -r desc val; do
		if [ ${correct[iter]} != 0 ]; then
			compare_result $val ${correct[iter]}
			final=$?
		fi
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "PILA checked"
	fi

	echo ""
	echo "$me check PILC for PIL"
	path=$root/pilc
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 > /dev/null & progress_bar 108 $!
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	array=( $(cat result.txt) )

	if [[ ${array[1]} = 0 ]] && [[ ${array[2]} = 1 ]]; then
		for (( i=4; i<${#array[@]}; i+=2 ))
		do
			compare_result ${array[i]} 1
			final=$?
		done
	fi

	if [[ $final = 11 ]]; then
		echo "PILC checked"
	fi

	echo ""
	echo "$me check FIBO for PIL"
	path=$root/fibo
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 > /dev/null & progress_bar 125 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 13 0 0 3 13 13 3 13)
	while IFS="=" read -r desc val; do
		if [[ ${correct[iter]} != 0 ]]; then
			compare_result $val ${correct[iter]}
			final=$?
		fi
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "FIBO checked"
	fi
	rm -rf result.txt
}

check_BDD() {

	#FIXME: check if BDD library is installed?
	
	echo ""
	echo "$me check BDDA for BDD"
	path=$root/bdda
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 > /dev/null & progress_bar 144 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 5 4)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "BDDA checked"
	fi

	echo ""
	echo "$me check BDDF for BDD"
	path=$root/bddf
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 > /dev/null & progress_bar 136 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 5 4)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "BDDF checked"
	fi

	echo ""
	echo "$me check BDDN for BDD"
	path=$root/bddn
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 > /dev/null & progress_bar 134 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT -s 8 | tee ./result.txt

	iter=0
	correct=(13 -3 5 4)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "BDDN checked"
	fi
	rm -rf result.txt
}

check_default() {
	echo ""
	echo "Step 1"
	echo "$me check Default"
	path=$root/def
	CGT=$path/cgt.cfg

	currentcgt=$(cat secint.h | sed -n 's/.*Config: //p')

	if [[ $currentcgt != "../tests/user/def/cgt.cfg" ]]; then
		make
	fi

	echo "Compiling..."
	make alice > /dev/null & progress_bar 80 $!
	echo ""
	./alice.exe | tee ./result.txt

	iter=0
	correct=(0 101 4 0 1 -1 201 89 1 -1 1 6 3 13 4 15 201 89 14 -4 4 13 13 13)
	while IFS="=" read -r desc val; do
		if [ ${correct[iter]} != 0 ]; then
			compare_result $val ${correct[iter]}
			final=$?
		fi
		iter=$((iter+1))
	done < result.txt

	echo ""
	if [[ $final = 11 ]]; then
		echo "Default checked" | tee -a ./check.log
	fi

# Test carry on
# Cplain: 129 + 100 = 101
# Cplain: bitsum( 101 ) = 4
# Test carry off
# Pil [ enc(1) ] = 1
# Pil [ enc(-1) ] = -1
# Pil: 101 + 100 = 201
# Pil: 101 + -12 = 89
# Bug [ enc(1) ] = 1
# Bug [ enc(-1) ] = -1
# Test NativeBool op && = 1
# Test Int*Enc = 6
# Test mux = 3
# This must be [ enc(13) ] = 13
# NativeInt<64>	7 + -3 = 4
# Native2Int<16>	10 + 5 = 15
# Cplain: 101 + 100 = 201
# Cplain: 101 + -12 = 89
# This must be [ enc(14) ] = 14
# This must be [ enc(-4) ] = -4
# TFHE: 7 + -3 = 4
# TFHE<8> fib( 7 ) = 13
# NativeUint<32>	fib( 7 ) = 13 
# NativeInt<64>	fib( 7 ) = 13
}

check_gat() {
	echo ""
	echo "Step 2"
	echo "$me check GAT for Gates"
	path=$root/gat
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 > /dev/null & progress_bar 180 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	while IFS="=" read -r desc val; do
		if [ $val = 1 ]; then
			echo "GAT checked"| tee -a ./check.log
		else
			echo "Test failed"
			rm -rf result.txt
			exit
		fi
	done < result.txt
}

check_gate() {
	echo ""
	echo "Step 3"
	echo "$me check GATE for Gates"
	path=$root/gate
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 > /dev/null & progress_bar 260 $!
	wait $! &> /dev/null
	echo ""
	echo "Compiling..."
	ls bob.exe >/dev/null
	ls cgt.exe >/dev/null
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	while IFS=$'\n' read -r string; do
		IFS=' '
		array=( $string )

		if [[ ${array[1]} = 0 ]] && [[ ${array[2]} = 1 ]]; then
			for (( i=4; i<${#array[@]}; i+=2 ))
			do
				compare_result ${array[i]} 1
				final=$?
			done
		fi
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "GATE checked" | tee -a ./check.log
	fi
}


## Main ##

echo "$me Running User Tests"

check_default
check_gat
check_gate
check_TFHE
check_HElib
check_FHEW
check_SEAL
check_BDD
check_PIL




# echo ""
# echo "Step 6-c"
# echo "$me check NAND for Gates"
# path=$root/nand
# CGT=$path/cgt.cfg

# make c > /dev/null
# echo "Generating cgt.exe..."

# make USER=$path MPIR=1 &> /dev/null & progress_dot $!
# wait $! &> /dev/null
# echo ""
# echo "Compiling..."
# ls bob.exe >/dev/null
# ls cgt.exe >/dev/null
# ./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

# array=( $(cat result.txt) )

# if [[ ${array[1]} = 0 ]] && [[ ${array[2]} = 1 ]]; then
# 	for (( i=4; i<${#array[@]}; i+=2 ))
# 	do
# 		compare_result ${array[i]} 1
# 	done
# fi

# echo "NAND checked"