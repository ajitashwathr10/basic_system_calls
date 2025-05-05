#!/bin/bash

read -p "Enter age" age
if [ "$age" -ge 18 ]; then
	echo "Eligible to vote"
else
	echo "Not eligible"
fi
