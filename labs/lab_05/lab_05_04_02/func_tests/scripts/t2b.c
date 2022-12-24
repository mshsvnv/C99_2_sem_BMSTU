#include <stdio.h>
#include <string.h>

#define NAME_LEN 31
#define MAKER_LEN 16 
#define OK 0
struct product
{
    char name[NAME_LEN];
    char maker[MAKER_LEN];
    unsigned int price;
    unsigned int count;
};

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
    struct product prod;

    char buf;

    memset(&prod, '\0', sizeof(prod));

    while (fscanf(f_txt, "%s%s%u%u%c", prod.name, prod.maker, &(prod.price), &(prod.count), &buf) == 5 && buf == '\n')
    {
        fwrite(&prod, sizeof(prod), 1, f_bin);
    }
}
