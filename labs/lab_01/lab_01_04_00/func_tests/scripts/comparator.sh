#!/bin/bash

if [[ -f "$1" && -f "$2" ]]; then
	seq_1=$(grep -Eo "[-]?[0-9]+[.,]?[0-9]*" "$1")
	seq_2=$(grep -Eo "[-]?[0-9]+[.,]?[0-9]*" "$2")

	if [ "$seq_1" == "$seq_2" ]; then
		exit 0
	else
		exit 1
	fi
else
	exit 1
fi