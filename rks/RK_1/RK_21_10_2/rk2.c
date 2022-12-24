#include <stdio.h>

#define MAX_LEN 10
#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3
#define NUM_ERROR 4

int read_columns(int *columns);
int read_massive(int a[], int *columns);
void sort(int a[], int *columns);
int func(int a[], int *columns);

int main(void)
{
    int a[MAX_LEN] = { 0 };
    int columns, total;
    int res = read_columns(&columns);
    if (res == 1)
    {
        printf("ERROR: неверный тип входных данных\n");
        return TYPE_ERROR;
    }
    else if (res == 2)
    {
        printf("ERROR: неверный диапазон входных данных\n");
        return SIZE_ERROR;
    }
    else
    {
        res = read_massive(a, &columns);
        if (res == 3)
        {
            printf("ERROR: неверный тип данных матрицы\n");
            return ARRAY_ERROR;
        }
        else
        {
            sort(a, &columns);
            total = func(a, &columns);
            if (total == 0)
            {
                printf("ERROR: таких чисел нет\n");
                return NUM_ERROR;
            }
            else
                printf("Result: %d\n", total);
            return SUCCESS;
        }
    }
}


int read_columns(int *columns)
{
    printf("Введите длину массива: ");
    int res = scanf("%d", columns);
    if (res != 1)
        return TYPE_ERROR;
    else if (*columns <= 0 || *columns > MAX_LEN)
        return SIZE_ERROR;
    return SUCCESS;
}

int read_massive(int a[], int *columns)
{
    int i, res = 0;
    printf("Введите строку: ");
    for (i = 0; i < *columns; i++)
    {
        res += scanf("%d", &a[i]);
    }
    if (res != *columns)
        return ARRAY_ERROR;
    return SUCCESS;
}

void sort(int a[], int *columns)
{
    int i, j, c = 0;
    for (i = 0; i < *columns - 1; i++)
    {
        for (j = i + 1; j < *columns; j++)
        {
            if (a[i] > a[j])
            {
                c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
}

int func(int a[], int *columns)
{
    int i;
    int total = 0, k = 1;
    for (i = 1; i < *columns; i++)
    {
        if (a[i] == a[i - 1])
            k += 1;
        else if (k != 1)
        {
            total += 1;
            k = 1;
        }
    }
    if (k != 1)
        total += 1;
    return total;
}