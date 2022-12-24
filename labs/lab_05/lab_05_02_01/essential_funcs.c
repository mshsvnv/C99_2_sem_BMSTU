#include <stdio.h>
#include "defs.h"

int find_max_min(FILE *f, double *max, double *min)
{
    double num = 0;

    int i = 0;

    while (!(feof(f)))
    {
        if (fscanf(f, "%lf", &num) == 1)
        {
            if (i == 0 || *max < num)
                *max = num;
            if (i++ == 0 || *min > num)
                *min = num;
        }
        else
        {
            return INCORRECT_INPUT_ERROR;
        }
    }

    if (i == 1)
    {
        return LACK_OF_NUMS_ERROR;
    }
    
    return SUCCESS;
}

int count_average(FILE *f, double *max, double *min)
{
    double num;
    double average_max_min = (*max + *min) / 2;

    int count = 0;

    while (!(feof(f)))
    {
        fscanf(f, "%lf", &num);

        if (num > average_max_min)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return SUCCESS;
}