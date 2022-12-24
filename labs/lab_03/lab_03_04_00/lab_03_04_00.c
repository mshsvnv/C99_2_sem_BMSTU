#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3
#define LACK_ERROR 4

int read_r_c(int *rows, int *columns);
int read_massive(int a[][M], int *rows, int *columns);
void min(int a[][M], int *rows, int *min_nech);

int main(void)
{
    int a[N][M] = { 0 };
    int min_nech = 0;
    int res = 0;
    int rows = 0, columns = 0; 
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
        else
        {
            min(a, &rows, &min_nech);
            if (min_nech == 0)
            {
                printf("ERROR: такого числа нет\n");
                return LACK_ERROR;
            }
            else
                printf("Result: %d\n", min_nech);
            return SUCCESS;
        }
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
    else if ((*rows > M) || (*rows <= 1) || (*columns > N) || (*columns <= 0) || (*rows != *columns))
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

void min(int a[][M], int *rows, int *min_nech)
{
    int i, j;
    for (i = 1; i < *rows; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (abs(a[i][j]) % 2 != 0)
            {
                if (*min_nech == 0)
                    *min_nech = a[i][j];
                else if (a[i][j] < *min_nech)
                    *min_nech = a[i][j];
            }
        }
    }
}


