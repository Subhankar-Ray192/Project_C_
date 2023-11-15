#!/bin/bash

counter=0

while [ $counter -lt 3 ]; do
	echo "Hello World!"
	counter=$((counter + 1))
	sleep 2
done
