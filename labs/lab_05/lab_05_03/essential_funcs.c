#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "file_funcs.h"
#include "defs.h"

int get_number_by_pos(FILE *f, long pos)
{
    int count;

    fseek(f, pos, SEEK_SET);
    fread(&count, sizeof(int), 1, f);

    return count;
}

void put_number_by_pos(FILE *f, long pos, int *num)
{
    fseek(f, pos, SEEK_SET);
    fwrite(num, sizeof(int), 1, f);
}

int create_file(int count_num, char *file_name)
{
    FILE *f;

    int i;
    int num;

    if (count_num <= 0)
    {
        return INCORRECT_DATA_ERROR;
    }

    f = fopen(file_name, "wb");

    srand(time(NULL));

    for (i = 0; i < count_num; i++)
    {
        num = rand() % 100 - 50;
        fwrite(&num, sizeof(int), 1, f);
    }

    fclose(f);

    return SUCCESS;
}

int print_file(char *file_name)
{
    size_t i;
    int count, rc;
    long size;

    FILE *f = fopen(file_name, "rb");

    rc = check_file(f);
    if (rc != SUCCESS)
    {
        return rc;
    }

    size = file_size(f);
    if (size < 4)
    {
        return EMPTY_FILE_ERROR;
    }

    for (i = 0; i < size / sizeof(int); i++)
    {
        rc = fread(&count, sizeof(int), 1, f);
        if (rc)
        {
            printf("%d\n", count);
        }
        else
        {
            return INCORRECT_DATA_ERROR;
        }
    }

    return SUCCESS;
}

int sort_file(char *file_name)
{
    size_t i, j, ind;
    int rc, cur_j, cur_ind, cur_i;
    long size, cur_pos, cur_pos_i;

    FILE *f = fopen(file_name, "r+b");

    rc = check_file(f);
    if (rc != SUCCESS)
    {
        return rc;
    }

    size = file_size(f);
    if (size < 4)
    {
        fclose(f);
        return EMPTY_FILE_ERROR;
    }

    for (i = 0; i < (size / sizeof(int)) - 1; i++)
    {
        ind = i;

        fseek(f, sizeof(int)*i, SEEK_SET);
        cur_pos_i = ftell(f);
        cur_i = get_number_by_pos(f, cur_pos_i);

        cur_ind = get_number_by_pos(f, cur_pos_i);

        for (j = i + 1; j < size / sizeof(int); j++)
        {
            fseek(f, sizeof(int)*j, SEEK_SET);
            cur_pos = ftell(f);
            cur_j = get_number_by_pos(f, cur_pos);
            
            if (cur_j < cur_ind)
            {
                ind = j;

                fseek(f, sizeof(int)*ind, SEEK_SET);
                cur_pos = ftell(f);
                cur_ind = get_number_by_pos(f, cur_pos);
            }
        }
        
        fseek(f, sizeof(int)*ind, SEEK_SET);
        cur_pos = ftell(f);
        cur_ind = get_number_by_pos(f, cur_pos);

        put_number_by_pos(f, cur_pos, &cur_i);
        put_number_by_pos(f, cur_pos_i, &cur_ind);
    }
    
    fclose(f);
    return SUCCESS;
}
