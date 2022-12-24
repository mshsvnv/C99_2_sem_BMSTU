/**
 * @file essential_funcs.c
 * @author Мария Савинова
 * @brief Функции, необходимые для работы со строками
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <string.h>
#include "defs.h"

/**
 * @brief Функция для считывания строки из файла
 * 
 * @param[in] f файловая переменная
 * @param[in] string исходная строка 
 * @return int код возврата SUCCESS // STR_LEN_ERROR
 */
int read_string(FILE *f, char *string)
{
    fgets(string, MAX_STR_LEN, f);

    if (strlen(string) >= 101)
        return STR_LEN_ERROR;

    return SUCCESS;
}

/**
 * @brief Функция, проверяющая первую букву в слове
 * 
 * @param[in] word исходное слово
 * @return int 1 - если удовлетворяет условию, в противном случае 0
 */
int check_first_num(const char *word)
{
    const char *letter = word;
    return (*letter == 'a') ? 1 : 0;
}

/**
 * @brief Функция, разбивающая строку на слова
 * 
 * @param[in] string входная строка
 * @return int кол-во слов в строке, начинающихся на "a"
 */
int split_string(char *string)
{
    const char *p_b;
    int count_a = 0;

    p_b = strtok(string, " \n\t\v");

    while (p_b != NULL)
    {
        count_a += check_first_num(p_b);
        p_b = strtok(NULL, " \t");
    }

    return count_a;
}
