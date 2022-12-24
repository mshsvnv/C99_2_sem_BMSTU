#include <stdio.h>
#include "defs.h"

int check_file(FILE *f)
{
    if (f == NULL)
    {
        return IO_ERROR;
    }

    return SUCCESS;
}

long file_size(FILE *f)
{
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    return size;
}