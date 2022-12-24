#include <stdio.h>

#define SUCCESS 0
#define MAX_LEN 10
#define SIZE_ERROR 2
#define NUM_ERROR 3
#define ENTRY_ERROR 4

double average(const int *pb, const int *pe, int n)
{
    double sum = 0;
    while (pb < pe)
    {
        sum += *pb;
        pb++;
    }
    return sum / n;
}

int new_massive(const int *pb, const int *pe, int *pb_new, double av)
{
    int *pb_new2 = pb_new;
    int f = 0;
    while (pb < pe)
    {
        if (*pb > av)
        {
            f = 1;
            *pb_new = *pb;
            pb_new++;
        }
        pb++;
    }
    while (pb_new2 < pb_new)
    {
        printf("%d ", *pb_new2);
        pb_new2++;
    }
    return f;
}

int main()
{
    int a[MAX_LEN], a_new[MAX_LEN];
    int n;
    double av;
    int res, i;
    res = scanf("%d", &n);
    if (res != 1)
        return ENTRY_ERROR;
    if (n <= 0 || n > 10)
        return SIZE_ERROR;
    else
    {
        res = 0;
        for (i = 0; i < n; i++)
            res += scanf("%d", &a[i]);
        if (res != n)
            return NUM_ERROR;
        int *pb = a;
        int *pe = pb + n;
        av = average(pb, pe, n);
        int *pb_new = a_new;
        res = new_massive(pb, pe, pb_new, av);
        if (res == 0)
            return NUM_ERROR;
        else
            printf("\n");
    }
    return SUCCESS;
}
