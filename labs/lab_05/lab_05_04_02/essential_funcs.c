#include <stdio.h>

#include "defs.h"
#include "struct.h"
#include "file_funcs.h"
#include "specific_funcs.h"

int sort_files(char *file_src, char *file_dst)
{
    FILE *f_src = fopen(file_src, "r+b");
    FILE *f_dst = fopen(file_dst, "w+b");

    int rc;
    size_t i, j, ind, end;
    long size;

    struct product prod_i;
    struct product *p_i = &prod_i;
    struct product prod_ind;
    struct product *p_ind = &prod_ind;
    struct product prod_j;
    struct product *p_j = &prod_j;

    rc = check_files(f_src);
    if (rc != SUCCESS)
    {
        return rc;
    }

    size = file_size(f_src);
    if (size == 0)
    {
        return EMPTY_FILE_ERROR;
    }

    end = size / sizeof(prod_i);

    for (i = 0; i < end; i++)
    {
        read_struct_by_pos(f_src, i, p_i);
        write_struct_by_pos(f_dst, i, p_i);
    }

    for (i = 0; i < end; i++)
    {
        ind = i;

        read_struct_by_pos(f_dst, i, p_i);

        read_struct_by_pos(f_dst, ind, p_ind);

        for (j = i + 1; j < end; j++)
        {
            read_struct_by_pos(f_dst, j, p_j);

            if (prod_j.price > prod_ind.price)
            {
                ind = j;
                prod_ind = prod_j;
                read_struct_by_pos(f_dst, ind, p_ind);
            }
            else if (prod_j.price == prod_ind.price)
            { 
                if (prod_j.count > prod_ind.count)
                {
                    ind = j;
                    prod_ind = prod_j;
                    read_struct_by_pos(f_dst, ind, p_ind);
                }
            }
        }
        write_struct_by_pos(f_dst, i, p_ind);

        write_struct_by_pos(f_dst, ind, p_i);
    }

    fclose(f_src);
    fclose(f_dst);

    return SUCCESS;
}

int find_files(char *file_name, char *substr)
{
    FILE *f_src = fopen(file_name, "r+b");

    int rc;
    size_t i, end, flag;
    long size;

    struct product prod_i;
    struct product *p_i = &prod_i;

    rc = check_files(f_src);
    if (rc != SUCCESS)
    {
        return rc;
    }

    size = file_size(f_src);
    if (size == 0)
    {
        return EMPTY_FILE_ERROR;
    }

    end = size / sizeof(prod_i);

    flag = 0;
    for (i = 0; i < end; i++)
    {
        read_struct_by_pos(f_src, i, p_i);

        if (compare_names(p_i->name, substr) == SUCCESS)
        {
            printf("%s\n%s\n%u\n%u\n", p_i->name, p_i->maker, p_i->price, p_i->count);
        }
        else
        {
            flag++;
        }
    }

    if (flag == end)
    {
        return NO_SUBSTR_ERROR;
    }

    return SUCCESS;
}