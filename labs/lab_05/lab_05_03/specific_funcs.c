#include <stdio.h>
#include <ctype.h>
#include "defs.h"

int correct_number(char *num)
{
    char *n = num;
    
    if (*n == '-' && isdigit(*(n + 1)))
        n++;
    
    while (*n != '\0')
    {
        if (isdigit(*n) == 0)
            return NOT_NUM_ERROR;
        n++;
    }
    
    return SUCCESS;
}