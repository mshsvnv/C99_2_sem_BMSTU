#include <stdio.h>
#include <stdlib.h>

#define N 20
#define M 20

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3

int read_r_c(int *rows, int *columns);
int read_massive(int a[][M], int *rows, int *columns);
int read_k(int *k);
int start(int a[], int columns, int k);
int end(int a[], int columns, int k);
void new_massive(int a[][M], int *rows, int *columns, int *k);
void shift(int a[][M], int rows, int columns, int i);
void show(int a[][M], int *rows, int *columns);

int main(void)
{
    int a[N][M] = { 0 };
    int res = 0;
    int rows = 0, columns = 0, k = 0; 
    res = read_r_c(&rows, &columns);
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
        res = read_massive(a, &rows, &columns);
        if (res == 3)
        {
            printf("ERROR: неверный тип данных матрицы\n");
            return ARRAY_ERROR;
        }
        res = read_k(&k);
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
        new_massive(a, &rows, &columns, &k);
        show(a, &rows, &columns);
        return SUCCESS;
    }
}

int read_r_c(int *rows, int *columns)
{
    int res = 0;
    printf("Введите кол-во сторок: ");
    res += scanf("%d", rows);
    printf("Введите кол-во столбцов: ");
    res += scanf("%d", columns);
    if (res != 2)
    {
        return TYPE_ERROR;
    }
    else if ((*rows > M - 10) || (*rows <= 0) || (*columns > N - 10) || (*columns <= 0))
        return SIZE_ERROR;
    else
        return SUCCESS;
}

int read_massive(int a[][M], int *rows, int *columns)
{
    int i, j;
    int res = 0;
    for (i = 0; i < *rows; i++)
    {
        printf("Введите строку: ");
        for (j = 0; j < *columns; j++)
            res += scanf("%d", &a[i][j]);
    }
    if (res != (*rows) * (*columns))
        return ARRAY_ERROR;
    else
        return SUCCESS;
}

int read_k(int *k)
{
    int res = 0;
    printf("Введите цифру (0-9): ");
    res = scanf("%d", k);
    if (res != 1)
    {
        return TYPE_ERROR;
    }
    else if ((*k >= 10) || (*k < 0))
        return SIZE_ERROR;
    else
        return SUCCESS;
}

void new_massive(int a[][M], int *rows, int *columns, int *k)
{
    int i = 0, count = 0, rows_n = *rows;
    while (count < rows_n)
    {
        if (start(a[i], *columns, *k) == end(a[i], *columns, *k) && end(a[i], *columns, *k) != 0)
        {
            shift(a, *rows, *columns, i);
            *rows += 1;
            i += 2;
        }
        else
            i++;
        count++;
    }
}

int start(int a[], int columns, int k)
{
    int i = 0, res = 0;
    for (;i < columns; i++)
    {
        int a_m = abs(a[i]);
        int st = 0;
        while (a_m > 0)
        {
            st = a_m % 10;
            a_m /= 10;
        }
        if (st == k)
            res++;
    }
    return res;
}

int end(int a[], int columns, int k)
{
    int i = 0, res = 0;
    for (;i < columns; i++)
    {
        int a_m = abs(a[i]);
        int en = 0;
        en = a_m % 10;
        if (en == k)
            res++;
    }
    return res;
}

void shift(int a[][M], int rows, int columns, int i)
{
    int c = 100;
    int i_n = rows, j;
    for (; i_n > i + 1; i_n--)
    {
        for (j = 0; j < columns; j++)
            a[i_n][j] = a[i_n - 1][j];
    }
    for (j = 0; j < columns; j++)
        a[i_n][j] = c;
}

void show(int a[][M], int *rows, int *columns)
{
    int i, j;
    printf("Result: \n");
    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *columns; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

