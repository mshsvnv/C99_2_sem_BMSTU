#!/bin/bash

if [[ -f "$1" && -f "$2" ]]; then

	sed -z "s/\n//g" "$1" >> f_1.txt
	sed -z "s/\n//g" "$2" >> f_2.txt

	seq_1=$(grep -Eo "Result: .*" f_1.txt)
	seq_2=$(grep -Eo "Result: .*" f_2.txt)

	rm f_1.txt f_2.txt

	if [[ "$seq_1" == "$seq_2" ]]; then
		exit 0
	else
		exit 1
	fi
else
	exit 1
fi
