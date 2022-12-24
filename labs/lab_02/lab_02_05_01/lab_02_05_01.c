#include <stdio.h>

#define SUCCESS 0
#define MAX_LEN 10
#define SIZE_ERROR 2
#define NUM_ERROR 3
#define ENTRY_ERROR 4

int min(const int *pb_a, const int *pe_a)
{
    int p = 0, q = 0;
    while (pb_a < pe_a)
    {
        if (*pb_a > 0)
            p++;
        else
        {
            if (*pb_a < 0)
                q++;
        }
        pb_a++;
    }
    if (q < p)
        return q;
    else
        return p;
}

void positive(const int *pb_a, const int *pe_a, int *pb_p, int count)
{
    int cur_count = 0;
    pe_a--;
    while (pe_a >= pb_a)
    {
        if (*pe_a > 0)
        {
            *pb_p = *pe_a;
            pb_p++;
            cur_count++;
            if (cur_count == count)
                break;
        }
        pe_a--;
    }
}

void negative(const int *pb_a, const int *pe_a, int *pb_q, int count)
{
    int cur_count = 0;
    while (pb_a < pe_a)
    {
        if (*pb_a < 0)
        {
            *pb_q = *pb_a;
            pb_q++;
            cur_count++;
            if (cur_count == count)
                break;
        }
        pb_a++;
    }
}

int result(const int *pb_p, const int *pe_p, const int *pb_q)
{
    int sum = 0;
    while (pb_p < pe_p)
    {
        sum += (*pb_q) * (*pb_p);
        pb_q++;
        pb_p++;
    }
    return sum;
}

int main()
{
    int a[MAX_LEN], p[MAX_LEN], q[MAX_LEN];
    int n, min_count, sum = 0;
    int res, i;
    if (scanf("%d", &n) != 1)
        return ENTRY_ERROR;
    if (n <= 0 || n > 10)
        return SIZE_ERROR;
    else
    {
        res = 0;
        int *pe_a = a;
        int *pb_a = a;
        for (; pe_a < n + pb_a; i++, pe_a++)
            res += scanf("%d", pe_a);
        if (res != n)
            return NUM_ERROR;
        min_count = min(pb_a, pe_a);
        if (min_count == 0)
            return NUM_ERROR;
        int *pb_p = p;
        int *pe_p = pb_p + min_count;
        positive(pb_a, pe_a, pb_p, min_count);
        int *pb_q = q;
        negative(pb_a, pe_a, pb_q, min_count);
        sum = result(pb_p, pe_p, pb_q);
        printf("%d\n", sum);
    }
    return SUCCESS;
}
