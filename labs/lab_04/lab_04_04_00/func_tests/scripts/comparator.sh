#!/bin/bash

if [[ -f "$1" && -f "$2" ]]; then

	seq_1=$(sed -z "s/\n//g" "$1")
	seq_2=$(sed -z "s/\n//g" "$2")

	if [[ "$seq_1" == "$seq_2" ]]; then
		exit 0
	else
		exit 1
	fi
else
	exit 1
fi
