#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defs.h"
#include "struct.h"

void read_struct_by_pos(FILE *f, size_t i, struct product *p)
{
    fseek(f, i * sizeof(*p), SEEK_SET); 
    fread(p, sizeof(*p), 1, f);
}

void write_struct_by_pos(FILE *f, size_t i, struct product *p)
{
    fseek(f, i * sizeof(*p), SEEK_SET);
    fwrite(p, sizeof(*p), 1, f);
}

int compare_names(char *file_name, char *substr)
{
    size_t st, i;

    if (strlen(file_name) < strlen(substr))
    {
        return NO_SUBSTR_ERROR;
    }

    i = 0;
    st = strlen(file_name) - strlen(substr);

    while (file_name[st] != '\0')
    {
        if (file_name[st++] != substr[i++])
        {
            return NO_SUBSTR_ERROR;
        }
    }

    return SUCCESS;
}