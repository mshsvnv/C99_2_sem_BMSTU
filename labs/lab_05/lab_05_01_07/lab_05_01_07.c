#include <stdio.h>
#include "defs.h"
#include "essential_funcs.h"

int main()
{
    int count_max = 0, rc;
    
    rc = process(stdin, &count_max);

    if (rc == SUCCESS)
    {
        fprintf(stdout, "%d\n", count_max); 
    }

    return rc;
}