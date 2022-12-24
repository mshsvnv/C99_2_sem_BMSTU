#include <stdio.h>

#define OK 0

void from_bin_to_txt(FILE *f_bin, FILE *f_txt);

int main(int argc, char **argv)
{
    FILE *f_bin = fopen(argv[1], "rb");
    FILE *f_txt = fopen(argv[2], "w");

    from_bin_to_txt(f_bin, f_txt);

    fclose(f_bin);
    fclose(f_txt);

    return OK;
}

void from_bin_to_txt(FILE *f_bin, FILE *f_txt)
{
    int num;

    while (fread(&num, sizeof(int), 1, f_bin))
    {
        fprintf(f_txt, "%d\n", num);
    }
}
