#include <stdio.h>
#include "defs.h"

void permutations(int *n_1, int *n_2, int *n_3, int *num)
{
    *n_1 = *n_2;
    *n_2 = *n_3;
    *n_3 = *num;
}

int process(FILE *f, int *count_max)
{
    int num, i = 0, n_1 = 0, n_2 = 0, n_3 = 0;

    while (fscanf(f, "%d", &num) == 1)
    {
        permutations(&n_1, &n_2, &n_3, &num);

        if (i >= 2)
        {
            *count_max = (n_2 > n_1 && n_2 > n_3) ? *count_max + 1 : *count_max;
        }

        i++;
    }

    if (i == 0)
    {
        return INCORRECT_INPUT;
    }
    if (i < 3)
    {
        return LACK_OF_NUMS_ERROR;
    }

    return SUCCESS;
}