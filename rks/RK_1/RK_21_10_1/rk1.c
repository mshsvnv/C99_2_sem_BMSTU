#include <stdio.h>

#define BEGIN 100
#define END 1000
#define SUCCESS 0

void func(int i)
{
    int ost = i % 100;
    if (ost != 0)
    {
        if (ost * 5 == i)
            printf("%d\n", i);
    }
}

int main(void)
{
    int i;
    printf("Result: \n");
    for (i = BEGIN; i < END; i++)
        func(i);
    return SUCCESS;
}