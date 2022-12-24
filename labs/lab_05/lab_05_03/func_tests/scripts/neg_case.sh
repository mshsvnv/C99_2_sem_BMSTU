#!/bin/bash

# $1: файл с ключами
# $2: файл с входными данными(если они есть)
neg_in="$2"

# keys - массив ключей
keys=()
read -ra keys < "$1"

# файл empty.bin для проверки на пустой файл
if [[ ! (-f "./../../empty.bin") ]]; then
	touch  ./../../empty.bin
fi

# для проверки на отсутствие подходящей подстроки
if [[ "$neg_in" != "" ]]; then
	./../../t2b.exe "$neg_in" "${keys[1]}"
fi

if [[ "$USE_VALGRIND" != "" ]]; then
	valgrind --log-file=./../../log.txt ./../../app.exe "${keys[@]}"
else
	./../../app.exe "${keys[@]}"
fi

echo "$exit_code"

if [[ "$exit_code" -ne 0 ]]; then
	exit_code=0
else
	exit_code=1
fi

if [[ "$USE_VALGRIND" != "" ]]; then
	mapfile -t array < <(tail -1 ./../../log.txt | grep -Eo "[0-9]*")
	
	if [[ ${array[1]} -ne 0 ]]; then
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 10 - негативный тест пройден, есть утечки памяти
			exit 10   
		else
			# код возврата 20 - негативный тест не пройден, есть утечки памяти	
			exit 20
		fi
	else
		if [[ "$exit_code" -eq 0 ]]; then
			# код возврата 30 - негативный тест пройден, нет утечек памяти
			exit 30
		else
			# код возврата 40 - негативный тест не пройден, нет утечек памяти
			exit 40
		fi
	fi
else
	exit "$exit_code"
fi
