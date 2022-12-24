#include <stdio.h>

#define OK 0

void from_txt_to_bin(FILE *f_txt, FILE *f_bin);

int main(int argc, char **argv)
{
    FILE *f_txt = fopen(argv[1], "r");
    FILE *f_bin = fopen(argv[2], "wb");

    from_txt_to_bin(f_txt, f_bin);

    fclose(f_txt);
    fclose(f_bin);

    return OK;
}

void from_txt_to_bin(FILE *f_txt, FILE *f_bin)
{
    int num;

    while (fscanf(f_txt, "%d", &num) != EOF)
    {
        fwrite(&num, sizeof(int), 1, f_bin);
    }
}