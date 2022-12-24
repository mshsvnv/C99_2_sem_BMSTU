#include <stdio.h>

#define MAX_LEN 10
#define NUM_ERROR 3

void insert_sort(int *a, int n)
{
    int i, j = 0, cur = 0;
    for (i = 1; i < n; i++)
    {
        cur = a[i];
        j = i - 1;
        while (j >= 0 && cur < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = cur;
    }
}

int main()
{
    int a[MAX_LEN];
    int n = 0, num;
    int i, f = 0;
    for (i = 0; i < MAX_LEN+1; i++)
    {
        if (scanf("%d", &num))
            if (i == 10)
            {
                f = 100;
                break;
            }
            else
                a[i] = num;
        else
        {
            if (i == 0)
                return NUM_ERROR;
            else
                break;
        }
        n++;
    }
    insert_sort(a, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return f;
}
