#include <stdio.h>
#include <stdint.h>

void bin(uint32_t num)
{
    uint32_t t = 1;
    int len, i;
    len = 32;
    t = t << 31;
    printf("Result: ");
    for (i = 0; i < len; i++, num <<= 1)
        if (num & t)
            printf("1");
        else
            printf("0");
    printf("\n");
}

unsigned int shift(uint32_t x, int count)
{
    return (x >> (count % 32)) | (x << (32 - count % 32));
}

int main() 
{
    uint32_t x;
    int count;
    int res;
    res = scanf("%u%d", &x, &count);
    if (res != 2)
    {
        printf("Error: неверный ввод данных\n");
        return 1;
    }
    else if (count < 0)
    {
        printf("Error: кол-во смещений нецелое\n");
        return 2;
    }
    else
    {
        x = shift(x, count);
        bin(x);
    }
    return 0;
}

