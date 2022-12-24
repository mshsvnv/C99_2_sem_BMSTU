#include <stdio.h>
#include "defs.h"
#include "essential_funcs.h"
#include "file_funcs.h"

int main(int argc, char **argv)
{
    FILE *f;

    double max, min;
    int rc = 0;

    if (argc != 2)
    {
        return NO_ARGS_ERROR;
    }
       
    f = fopen(argv[1], "r");

    rc = check_file(f);

    if (rc != SUCCESS)
    {
        return rc;
    }

    if (file_size(f) == 0)
    {
        return EMPTY_FILE_ERROR;
    }

    rc = find_max_min(f, &max, &min);
    fclose(f);

    if (rc != SUCCESS)
    {
        return rc;
    }

    f = fopen(argv[1], "r");

    rc = count_average(f, &max, &min);
    fclose(f);

    return rc;
}
