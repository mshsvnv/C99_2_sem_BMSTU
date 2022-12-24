#include <stdio.h>

#define NAME_LEN 31
#define MAKER_LEN 16 
#define OK 0

void from_bin_to_txt(FILE *f_bin, FILE *f_txt);

struct product
{
    char name[NAME_LEN];
    char maker[MAKER_LEN];
    unsigned int price;
    unsigned int count;
};

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
    struct product prod;

    while (fread(&prod, sizeof(prod), 1, f_bin))
    {
        fprintf(f_txt, "%s\n%s\n%u\n%u\n", prod.name, prod.maker, prod.price, prod.count);
    }
}
