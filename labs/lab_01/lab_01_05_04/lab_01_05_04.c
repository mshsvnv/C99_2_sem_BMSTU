#include <stdio.h>
#include <math.h>

int simple(int x)
{
    int i;
    for (i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void razl(int x)
{
    int i = 2;
    while (x > 1)
    {
        if (simple(x) == 1)
        {
            printf("%d\n", x);
            break;
        }
        else
        {
            if (x % i == 0)
            {
                printf("%d\n", i);
                x /= i;
            }
            else
                i++;
        }
    }
}

int main(void)
{
    int x;
    int res = scanf("%d", &x);
    if (res != 1)
        return 1;
    else if (x == 1)
        return 0;
    else if (x < 1)
        return 2;
    else
    {
        razl(x);
    }
    return 0;
}

