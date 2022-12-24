#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"
#include "file_funcs.h"
#include "specific_funcs.h"
#include "essential_funcs.h"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        return INCORRECT_ARGS_ERROR;
    }

    if (strcmp(argv[1], "sb") == 0)
    {
        return sort_files(argv[2], argv[3]);
    }
    else if (strcmp(argv[1], "fb") == 0)
    {
        return find_files(argv[2], argv[3]);
    }
    else
    {
        return INCORRECT_ARGS_ERROR;
    }
}