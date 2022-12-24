#!/bin/bash

# $1: файл с ключами
# $2: файл с входными данными
# $3: файл с выходными эталонными данными

pos_in="$2"
pos_out="$3"

# keys - массив ключей
keys=()
read -ra keys < "$1"

# array - массив для нахождения кол-ва ошибок утечки памяти
array=()

if [[ ${keys[0]} == "fb" ]]; then

	./../../t2b.exe "$pos_in" "${keys[1]}"

	if [[ "$USE_VALGRIND" != "" ]]; then
		valgrind --log-file=./../../log.txt ./../../app.exe "${keys[@]}" > ./../../pos_out.txt
	else
		./../../app.exe "${keys[@]}" > ./../../pos_out.txt
	fi
	
	./comparator.sh ./../../pos_out.txt "$pos_out"
	exit_code="$?"

elif [[ ${keys[0]} == "sb" ]]; then

	./../../t2b.exe "$pos_in" "${keys[1]}"

	if [[ "$USE_VALGRIND" != "" ]]; then
		valgrind --log-file=./../../log.txt ./../../app.exe "${keys[@]}"
	else
		./../../app.exe "${keys[@]}"
	fi
	
	./../../b2t.exe "${keys[2]}" ./../../pos_out.txt

	./comparator.sh ./../../pos_out.txt "$pos_out"
	exit_code="$?"

fi

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



