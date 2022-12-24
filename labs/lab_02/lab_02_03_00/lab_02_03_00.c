#include <stdio.h>

#define SUCCESS 0
#define MAX_LEN 20
#define SIZE_ERROR 2
#define NUM_ERROR 3
#define ENTRY_ERROR 4

int palindrome(int num)
{
    int rev = 0;
    int temp = num;
    while (temp > 0)
    {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    if (rev == num)
        return 0;
    else
        return 1;
}

void shift(int *a, int n, int i)
{
    int el;
    for (; i < n; i++)
    {
        el = a[i];
        a[i] = a[i + 1];
        a[i + 1] = el;
    }
}

int new_masive(int *a, int n)
{
    int i = 0, k = 0, count = 0;
    while (count != n)
    {
        if (palindrome(a[i]) == 0 && a[i] >= 0)
        {
            shift(a, n, i);
            k += 1;
        }
        else
            i++;
        count++;
    }
    return k;
}

int main()
{
    int a[MAX_LEN];
    int n, len = 0;
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
        len = n - new_masive(a, n);
        if (len == 0)
            return NUM_ERROR;
        for (i = 0; i < len; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return SUCCESS;
}
