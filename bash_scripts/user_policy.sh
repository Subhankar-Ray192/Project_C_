#!/bin/bash

if [ $1 = "a" ]; then
	if [ -z $2 ]; then
		echo "Provide username"
	else
		if [ -z $3 ]; then
			echo "Provide access group"
		else
			sudo usermod -a -G $3 $2
			echo "Done"
		fi
	fi
elif [ $1 = "d" ]; then
	if [ -z $2 ]; then
		echo "Provide username"
	else
		if [ -z $3 ]; then
			echo "Provide access group"
		else
			sudo deluser $2 $3
			echo "Done"
		fi
	fi
fi

