#!/bin/bash

# $1: файл с входными данными
# $2: файл с выходными эталонными данными
# $3: файл с ключами

pos_out="$2"
# keys - массив ключей
keys=()
# array - массив для нахождения кол-ва ошибок утечки памяти
array=()

if [[ "$#" -eq 3 ]]; then
	pos_in=""
	read -ra keys < "$3"
else
	pos_in="$1"
fi

if [[ "$pos_in" != "" ]]; then
	# нужен ли valgrind
	if [[ "$USE_VALGRIND" != "" ]]; then
		valgrind --log-file=./../../log.txt ./../../app.exe "${keys[@]}" < "$pos_in" > ./../../pos_res.txt
	else
		./../../app.exe "${keys[@]}" < "$pos_in" > ./../../pos_res.txt 
	fi
else
	if [[ "$USE_VALGRIND" != "" ]]; then
		valgrind --log-file=./../../log.txt ./../../app.exe "${keys[@]}" > ./../../pos_res.txt
	else
		./../../app.exe "${keys[@]}" > ./../../pos_res.txt 
	fi
fi

./comparator.sh ./../../pos_res.txt "$pos_out"
exit_code="$?"

if [[ "$USE_VALGRIND" != "" ]]; then
	
	mapfile -t array < <(tail -1 ./../../log.txt | grep -Eo "[0-9]*")
	
	if [[ ${array[1]} -ne 0 ]]; then
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 10 - позитивный тест пройден, есть утечки памяти
			exit 10   
		else
			# код возврата 20 - позитивный тест не пройден, есть утечки памяти	
			exit 20
		fi
	else
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 30 - позитивный тест пройден, нет утечек памяти
			exit 30
		else
			# код возврата 40 - тпозитивный ест не пройден, нет утечек памяти
			exit 40
		fi
	fi
else
	exit "$exit_code"
fi



