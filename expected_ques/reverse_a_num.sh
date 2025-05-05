#!/bin/bash

read -p "Enter a number:" num
rev = 0
temp = $num

while [ $temp -gt 0 ]
do
	digit=$((temp%10))
	rev=$((rev*10+digit))
	temp=$((temp/10))
done

echo $rev

if [ $rev -eq $num ]; then
	echo "It is a palindrome"
else
	echo "It is not a palindrome"
fi
