#include <stdio.h>

#define SUCCESS 0
#define MAX_LEN 10
#define SIZE_ERROR 2
#define NUM_ERROR 3
#define ENTRY_ERROR 4

int sum_even(int *a, int n)
{
    int sum = 0, i = 0, f = 0;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
        {
            sum += a[i];
            f = 1;
        }
    if (f == 1)
        return sum;
    else
        return 1;
}

int main()
{
    int a[MAX_LEN];
    int n, sum;
    int res, i;
    res = scanf("%d", &n);
    if (res != 1)
        return ENTRY_ERROR;
    if (n > 10 || n <= 0)
        return SIZE_ERROR;
    else
    {
        res = 0;
        for (i = 0; i < n; i++)
        {
            res += scanf("%d", &a[i]);
        }
        if (res != n)
            return NUM_ERROR;
        sum = sum_even(a, n);
        if (sum == 1)
            return NUM_ERROR;
        printf("%d\n", sum);
    }
    return SUCCESS;
}
