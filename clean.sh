#!/usr/bin/env bash

function clean()
{
	f=$(pwd)
	for testDir in $@; do
		cd $testDir
		rm -rf bin
		rm -f log.txt valgrind.txt output.txt diff.txt
		echo \'$testDir\' cleaned.
		cd $f
	done
}

clean base/*/* bonus/*/*