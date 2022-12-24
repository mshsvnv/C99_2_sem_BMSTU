/**
 * @file rk_22_1.c
 * @author Мария Савинова
 * @brief Основная программа
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

#include "defs.h"
#include "essential_funcs.h"
#include "file_funcs.h"

int main()
{
    int rc, i = 1, count_a;
    char string[MAX_STR_LEN];
    long size;

    FILE *f = fopen(FILE_NAME, "r");

    rc = check_file(f);
    if (rc != SUCCESS)
    {
        return rc;
    }

    size = file_size(f);
    if (size == 0)
    {
        return EMPTY_FILE_ERROR;
    }

    rc = string_count(f);
    if (rc != SUCCESS)
    {
        return rc;
    }

    while (! feof(f))
    {
        rc = read_string(f, string);

        if (rc != SUCCESS)
            return rc;

        count_a = split_string(string);
        printf("%d строка : %d\n", i, count_a);
        i++;
    }

    fclose(f);

    return SUCCESS;
}