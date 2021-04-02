#!/usr/bin/env bash

cc="clang++" # Tested with both g++ and clang++
flags="-Wall -Wextra -Werror -std=c++98"
ftcontainers_path=".." # Path to your project headers
test_std_library=0 # Set to 1 to test C++ STL, will not test your project anymore

echo -e "\e[1mWelcome to lsarrazi's tester for ft_containers\e[0m"
echo "See readme.md for more informations"
echo -e "Compiler set to \e[94m'$cc'\e[0m"
echo -e "Compiler flags set to \e[94m'$flags'\e[0m"
if [ $test_std_library = 1 ]; then
	echo -e "Testing standard C++ STL"
else
	echo -e "Project path set to \e[94m'$(realpath $ftcontainers_path)'\e[0m"
fi
echo ""
use_valgrind=1
use_lldb=1
if ! [ -x "$(command -v valgrind)" ]; then
	echo -e "\e[33m⚠ 'valgrind' command not detected, the test will not perform leak tests\e[0m"
	use_valgrind=0
fi

if [ $# = 0 ]; then
	target=base/*
else
	target=$@
fi

if [ $1 = "debug" ]; then
	echo -e "\e[1mRunning debug mode\e[0m (on '$2')\n"
	debug=1
	target=$2
else
	debug=0
fi

if [ $debug = 1 -a ! -x "$(command -v lldb)" ]; then
	echo -e "\e[33m⚠ 'lldb' command not detected, the test will not perform debugging\e[0m"
	use_lldb=0
fi

trap "echo -e \"\n\e[1mUser aborted test with signal\e[0m\"; exit" 2 3 9

function run_test()
{
	trap "tput cup 0 0; echo -e \"\nSEG FAULT FROM TRAP !\"; exit" 11
	local testDir=$1
	if [ ! -d $testDir ]; then
		return 0
	fi
		local src=./$testDir/main.cpp
		local bin=./$testDir/bin/test
		local log=./$testDir/log.txt
		local out=./$testDir/output.txt
		local exp=./$testDir/expected.txt
		local dif=./$testDir/diff.txt
		local vg=./$testDir/valgrind.txt
		local testDir__=$(echo $testDir | sed s:/:__:g)
		local patched=./$testDir/patched.cpp

		if [ ! -f $src ]; then
			return 0
		fi
		mkdir -p ./$testDir/bin

		# APPLY patch.sh
		rm -f $patched
		cp $src $patched
		if [ $test_std_library = 0 ]; then
			bash patch.sh "$patched"
		fi

		echo "ℹ️ Compiling '$testDir'..."
		function compile() {
			$cc $flags $patched -I"$ftcontainers_path" -g3 -o $bin
		}

		if [ $debug = 1 ]; then
			compile
		else
			compile &> $log
		fi

		if [ $? = 0 ]; then
			echo -e "\e[92m✔️\e[0m Compiling '$testDir' done"
			mkdir tmp/compiled/$testDir__
		else
			echo -e "\e[31m❌\e[0m Compiling '$testDir' failed with exit code $?"
			return 0
		fi

		if [ $use_valgrind = 1 ]; then 
			 > $out 2> $vg valgrind --leak-check=full --error-exitcode=6677 $bin
		else
			$bin > $out
		fi
		vgout=$?
		if [ -f $exp ]; then
			diff $out $exp > $dif
		fi
		if [ ! -f $exp -o $? = 0 ]; then
			local start="\e[92mTest '$testDir' succeed ✔️\e[0m "
			mkdir tmp/success/$testDir__
		else
			local start="\e[31mTest '$testDir' failed ❌\e[0m "
		fi
		local crash=0
		if [ $vgout = 139 ]; then
			local end=" \e[91m🕱 segmentation fault\e[0m"
			crash=1
		elif [ $vgout = 134 ]; then
			local end=" \e[91m⛔ abort\e[0m"
			crash=1
		elif [ $vgout = 21 ]; then
			local end=" \e[91m⚠ leak\e[0m"
			mkdir tmp/leak/$testDir__
		elif [ $vgout -ne 6677 -a $vgout -ne 0 ]; then
			local end=" \e[91m💥 exit code $vgout\e[0m"
		elif [ $use_valgrind = 0 ]; then
			local end=" \e[90m⁈ valgrind not detected\e[0m"
		elif [ $vgout = 6677 ]; then
			local end=" \e[33m⚠ seems to leak\e[0m"
			mkdir tmp/leak/$testDir__
		else
			local end=" \e[34m🔒 no leak\e[0m"
		fi
		if [ $crash = 1 ]; then
			mkdir tmp/crash/$testDir__
		fi

		echo -e "$start$end"

		# handle crash
		if [ $use_lldb = 1 -a $debug = 1 -a $crash = 1 ]; then
			echo -e "\e[1m\nRunning debugger\e[0m\n"
			lldb $bin -o 'run'
		fi
		
		return $code
}

file_count=0
rm -rf tmp || true
mkdir tmp tmp/compiled tmp/success tmp/leak tmp/crash

# run all process in parallel
for testDir in $target; do
	run_test $testDir &
	((file_count+=1))
done

time wait

success_count=$(ls tmp/success | wc -w)
compiled_count=$(ls tmp/compiled | wc -w)
leak_count=$(ls tmp/leak | wc -w)
crash_count=$(ls tmp/crash | wc -w)
rm -rf tmp || true

echo -e "\e[1mEnd of the test (compiled $compiled_count/$file_count, grade: $success_count/$file_count, crash: $crash_count, leaks: $leak_count)\e[0m"