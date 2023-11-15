#!/bin/bash

if [ $1 = "n" ]; then
	if [ -z $2 ]; then
		echo "Please provide an username"
	else
		sudo adduser $2
		echo "User $2 added"
	fi
elif [ $1 = "d" ]; then
	if [ -z $2 ]; then
		echo "Please provide an username"
	else
		sudo userdel -r $2
		echo "User $2 deleted"
	fi
else
	echo "Invalid Argument. Use n: to add user and d: to delete user"
fi
