#!/bin/bash

# переменные для цветного вывода в консоль
end="\033[0m"
red="\033[1;31m"
green="\033[1;32m"
yel="\033[1;33m"
bold_white="\033[1m"
abstr="\033[1;3;4;37;45m"
abstr_t="\033[1;3;34m"

# если нет исполняемого файла, выводим соответствующее сообщение
if [[ ! ( -e ./../../app.exe ) ]]; then
	echo -e "$red""CAN NOT RUN FUNC_TEST.SH""$end"
	exit 1
fi

# функция, обрабатывающая позитивные тесты
pos_tests() {

	pos_args=""
	if [[ -f ../data/pos_"$i"_args.txt ]]; then
		pos_args=$(ls ../data/pos_"$i"_args.txt)
		./pos_case.sh "$pos_in" "$pos_out" "$pos_args" 
	else
		./pos_case.sh "$pos_in" "$pos_out" 
	fi
	
	exit_code="$?"
	if [[ "$exit_code" -eq 0 ]]; then 
		echo -e "POS TEST pos_${i}_in.txt:$green PASSED""$end"
		pos_pass=$((pos_pass+1))
	else
		if [[ "$exit_code" -eq 1 ]]; then
			echo -e "POS TEST pos_${i}_in.txt:$red FAILED""$end"
		else
			if [[ "$exit_code" -eq 10 ]]; then
				echo -e "POS TEST pos_${i}_in.txt:$green PASSED""$end"
				echo -e "POS TEST pos_${i}_in.txt:$yel MEMORY ERROR$end"
				pos_pass=$((pos_pass+1))
			fi
			if [[ "$exit_code" -eq 20 ]]; then
				echo -e "POS TEST pos_${i}_in.txt:$red FAILED$end"
				echo -e "POS TEST pos_${i}_in.txt:$yel MEMORY ERROR$end"
			fi
			if [[ "$exit_code" -eq 30 ]]; then
				echo -e "POS TEST pos_${i}_in.txt:$green PASSED""$end"
				echo -e "POS TEST pos_${i}_in.txt:$green MEMORY OK""$end"
				pos_pass_mem=$((pos_pass_mem+1))
				pos_pass=$((pos_pass+1))
			fi
			if [[ "$exit_code" -eq 40 ]]; then
				echo -e "POS TEST pos_${i}_in.txt:$red FAILED$end"
				echo -e "POS TEST pos_${i}_in.txt:$green MEMORY OK$end"
				pos_pass_mem=$((pos_pass_mem+1))
			fi
		fi
	fi
}

# функция, обрабатывающая негативные тесты
neg_tests() {

	neg_args=""
	if [[ -f ../data/neg_"$i"_args.txt ]]; then
		neg_args=$(ls ../data/neg_"$i"_args.txt)
		./neg_case.sh "$neg_in" "$neg_args"
	else
		./neg_case.sh "$neg_in" 
	fi
        
    exit_code="$?"
	if [[ "$exit_code" -eq 0 ]]; then 
		echo -e "NEG TEST neg_${i}_in.txt:$green PASSED""$end"
		neg_pass=$((neg_pass+1))
	else
		if [[ "$exit_code" -eq 1 ]]; then
			echo -e "NEG TEST neg_${i}_in.txt:$red FAILED$end"
		else
			if [[ "$exit_code" -eq 10 ]]; then
				echo -e "NEG TEST neg_${i}_in.txt:$green PASSED""$end"
				echo -e "NEG TEST neg_${i}_in.txt:$yel MEMORY ERROR$end"
				neg_pass=$((neg_pass+1))
			fi
			if [[ "$exit_code" -eq 20 ]]; then
				echo -e "NEG TEST neg_${i}_in.txt:$red FAILED$end"
				echo -e "NEG TEST neg_${i}_in.txt:$yel MEMORY ERROR$end"
			fi
			if [[ "$exit_code" -eq 30 ]]; then
				echo -e "NEG TEST neg_${i}_in.txt:$green PASSED""$end"
				echo -e "NEG TEST neg_${i}_in.txt:$green MEMORY OK""$end"
				neg_pass=$((neg_pass+1))
				neg_pass_mem=$((neg_pass_mem+1))
			fi
			if [[ "$exit_code" -eq 40 ]]; then
				echo -e "NEG TEST neg_${i}_in.txt:$red FAILED$end"
				echo -e "NEG TEST neg_${i}_in.txt:$green MEMORY OK$end"
				neg_pass_mem=$((neg_pass_mem+1))
			fi
		fi	
	fi
}

echo -e "${abstr}Functional testing${end}\n"

if [[ "$USE_VALGRIND" != "" ]]; then
	echo -e "${bold_white}VALGRIND ON${end}\n"
else
	echo -e "${bold_white}VALGRIND OFF${end}\n"
fi

echo -e "${abstr_t}Positive tests${end}\n"

# no_files - код возврата в случае отсутствия тестовых данных
no_files=0
# total - кол-во непройденных тестов
total=0

i="01"
j=1
# pos_pass - кол-во пройденных позитивных тестов
pos_pass=0
# pos_pass_mem - кол-во пройденных позитивных тестов по памяти
pos_pass_mem=0
while [[ -f ../data/pos_"$i"_in.txt ]]; do

	pos_in=$(ls ../data/pos_"$i"_in.txt)
	pos_out=$(ls ../data/pos_"$i"_out.txt)

	pos_tests "$pos_in", "$pos_out", "$i"

	j=$((j+1))
	if [[ $j -gt 9 ]]; then
		i="$j"
	else
		i="0$j"
	fi

done

if [[ "$j" -eq 1 ]]; then 
	echo -e "${bold_white}No positive tests${end}\n"
	no_files=$((no_files+1))
else
	echo -e "\n${bold_white}Positive tests:$end correct $pos_pass of $((j-1))\n"
fi

if [[ "$USE_VALGRIND" != "" ]]; then
	echo -e "${bold_white}Memory:$end correct $pos_pass_mem of $((j-1))\n"
fi
	
total=$((j-1-pos_pass))

echo -e "${abstr_t}Negative tests${end}\n"

i="01"
j=1
# neg_pass - кол-во пройденных негативных тестов
neg_pass=0
# neg_pass_mem - кол-во пройденных негативных тестов по памяти
neg_pass_mem=0
while [[ -f ../data/neg_"$i"_in.txt ]]; do

	neg_in=$(ls ../data/neg_"$i"_in.txt)

	neg_tests "$neg_in", "$i"

	j=$((j+1))
	if [[ $j -gt 9 ]]; then
		i="$j"
	else
		i="0$j"
	fi

done

if [[ $j -eq 1 ]]; then 
	echo -e "${bold_white}No negative tests$end\n"
	no_files=$((no_files+1))
else
	echo -e "\n${bold_white}Negative tests:$end correct $neg_pass of $((j-1))\n"
fi

if [[ "$USE_VALGRIND" != "" ]]; then
	echo -e "${bold_white}Memory:$end correct $neg_pass_mem of $((j-1))\n"
fi

total=$((total+j-1-neg_pass))
if [[ $no_files -eq 2 ]]; then 
	exit "$no_files"
else
	exit "$total"
fi