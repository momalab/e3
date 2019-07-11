#!/bin/sh

PLAT=win
me="=== e3 ==="
root=../tests/user

compare_result() {
	input=$1
	correct=$2

	if [[ $input != $correct ]]; then
		echo "Test failed"
		rm -rf result.txt
		exit
	else
		return 11
	fi
}

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

	path1=../3p/tfhe_$PLAT/native/libtfhe.lib
	path2=../3p/tfhe_$PLAT/target/libtfhe.lib

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
	echo "Generating cgt.exe..."
	make USER=$path TFHE=1 &> /dev/null & progress_bar 106 $!
	echo ""
	echo "Compiling..."
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
}

check_SEAL() {
	echo "$me check SEAL"
	path=$root/seal 
	CGT=$path/cgt.cfg

	#FIXME: check if SEAL library is installed

	make c > /dev/null
	echo "Generating cgt.exe..."

	#FIXME: MOCK used instead of SEAL
	make USER=$path SEAL=0 &> /dev/null & progress_bar 102 $!
	echo ""
	echo "Compiling..."
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt
	four=$(awk 'NR == 4 {print $0}' result.txt)

	if [ $four != 4 ]; then
		echo "Test failed"
		rm -rf result.txt
		exit
	else
		echo "SEAL checked"
	fi
}

check_PIL() {
	echo "$me check PILA for MPIR"
	path=$root/pila
	CGT=$path/cgt.cfg

	path1=../3p/mpir_$PLAT/native/mpirxx.lib
	path2=../3p/mpir_$PLAT/target/mpirxx.lib

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
		echo "NOTE: Installing MPIR requires Visual Studio 17."
		exit
	fi

	make c > /dev/null 
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 &> /dev/null & progress_bar 168 $!
	echo ""
	echo "Compiling..."
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	iter=1
	correct=(28 -22 75)
	while IFS="=" read -r desc val; do
		compare_result $val ${correct[iter]}
		final=$?
		iter=$((iter+1))
	done < result.txt

	if [[ $final = 11 ]]; then
		echo "PILA checked" 
	fi

	echo ""
	echo "$me check PILC for MPIR"
	path=$root/pilc
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 &> /dev/null & progress_bar 162 $!
	echo ""
	echo "Compiling..."
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
	echo "$me check FIBO for MPIR"
	path=$root/fibo
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path MPIR=1 &> /dev/null & progress_bar 174 $!
	echo ""
	echo "Compiling..."
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
}

check_BDD() {

	#FIXME: check if BDD library is installed?

	echo ""
	echo "$me check BDDA for BDD"
	path=$root/bdda
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path CUDD=1 &> /dev/null & progress_bar 200 $!
	echo ""
	echo "Compiling..."
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

	make USER=$path CUDD=1 &> /dev/null & progress_bar 186 $!
	echo ""
	echo "Compiling..."
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

	make USER=$path CUDD=1 &> /dev/null & progress_bar 136 $!
	echo ""
	echo "Compiling..."
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
}

check_default() {
	echo ""
	echo "Step 1"
	echo "$me check Default"
	path=$root/def
	CGT=$path/cgt.cfg

	echo "Compiling..."
	make alice &> /dev/null & progress_bar 79 $!
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
}

check_gat() {
	echo ""
	echo "Step 2"
	echo "$me check GAT for Gates"
	path=$root/gat
	CGT=$path/cgt.cfg

	make c > /dev/null
	echo "Generating cgt.exe..."

	make USER=$path &> /dev/null & progress_bar 136 $!
	echo ""
	echo "Compiling..."
	./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

	while IFS="=" read -r desc val; do	
		if [ $val = 1 ]; then
			echo "GAT checked" | tee -a ./check.log
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

	make USER=$path &> /dev/null & progress_bar 135 $!
	echo ""
	echo "Compiling..."
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

options() {
	while true; do
		echo ""
		echo "Select the external library to check (Enter the number):"
		echo "1.TFHE 2.SEAL 3.PIL 4.BDD 0.Quit"
		echo "NOTE: HElib and FHEW are not supported on Windows."
		echo "NOTE: This process does not automatically install the external libraries."
		echo "NOTE: Make sure to install them before checking."
		read choice
		case $choice in
			1)
				check_TFHE
				rm -rf result.txt
				;;
			2)
				check_SEAL
				rm -rf result.txt
				;;
			3)
				check_PIL
				rm -rf result.txt
				;;
			4)
				check_BDD
				rm -rf result.txt
				;;
			0)
				make c &> /dev/null
				exit
				;;
		esac
	done
}


default=$(sed -n 's/.*Default //p' check.log 2> /dev/null)
gat=$(sed -n 's/.*GAT //p' check.log 2> /dev/null)
gate=$(sed -n 's/.*GATE //p' check.log 2> /dev/null)

if [[ $gate = "checked" ]]; then
	options
elif [[ $gat = "checked" ]]; then
	check_gate
	options
elif [[ $default = "checked" ]]; then
	check_gat
	check_gate
	options
else
	check_default
	check_gat
	check_gate
	options
fi


# echo ""
# echo "Step 6-c"
# echo "$me check NAND for Gates"
# path=$root/nand
# CGT=$path/cgt.cfg

# make c > /dev/null
# echo "Generating cgt.exe..."

# make USER=$path MPIR=1 &> /dev/null & progress_dot $!
# echo ""
# echo "Compiling..."
# ./bob.exe | ./cgt.exe dec -c $CGT | tee ./result.txt

# array=( $(cat result.txt) )

# if [[ ${array[1]} = 0 ]] && [[ ${array[2]} = 1 ]]; then
# 	for (( i=4; i<${#array[@]}; i+=2 ))
# 	do
# 		compare_result ${array[i]} 1
# 	done
# fi

# echo "NAND checked"