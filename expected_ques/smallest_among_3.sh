#!/bin/bash

echo "Enter three numbers:"
read a
read b
read c

if [ $a -le $b ]; then
	if [ $a -le $c ]; then
		echo "$a is the smallest"
	else
		echo "$c is the smallest"
	fi
else
	if [ $b -le $c ]; then
		echo "$b is the smallest"
	else
		echo "$c is the smallest"
	fi
fi
