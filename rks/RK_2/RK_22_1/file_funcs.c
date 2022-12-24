/**
 * @file file_funcs.c
 * @author Мария Савинова
 * @brief Функции, необхоимые для работы с файлами
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "defs.h"

/**
 * @brief Функция, проверяющая файл на существование
 * 
 * @param[in] f файловая переменная
 * @return int IO_ERROR // SUCCESS
 */
int check_file(FILE *f)
{
    if (f == NULL)
    {
        return IO_ERROR;
    }

    return SUCCESS;
}

/**
 * @brief Функция, определяющая размер файла
 * 
 * @param[in] f файловая переменная
 * @return int размер файла
 */
int file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}

/**
 * @brief Функция, определяющая кол-во строк в файле
 * 
 * @param[in] in файловая переменная
 * @return int код возврата STR_COUNT_ERROR // SUCCESS
 */
int string_count(FILE *in)
{
    int lines = 0;

    while (feof(in) != 1)
    {
        if (fgetc(in) == '\n')
            lines++;
    }
    lines++;
    fseek(in, 0, SEEK_SET);

    if (lines > MAX_STR_COUNT)
        return STR_COUNT_ERROR;
    else
        return SUCCESS;
}