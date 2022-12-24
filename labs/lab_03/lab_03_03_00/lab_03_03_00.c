#include <stdio.h>

#define N 10
#define M 10

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3

int read_r_c(int *rows, int *columns);
int read_massive(int a[][M], int *rows, int *columns);
void summ(int a[][M], int sum[], int *rows, int *columns);
void sort(int a[][M], int sum[], int *rows, int *columns);
void show(int a[][M], int *rows, int *columns);

int main(void)
{
    int a[N][M] = { 0 };
    int sum[N] = { 0 };
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
            summ(a, sum, &rows, &columns);
            sort(a, sum, &rows, &columns);
            show(a, &rows, &columns);
        }
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
    else if ((*rows > M) || (*rows <= 1) || (*columns > N) || (*columns <= 0))
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

void summ(int a[][M], int sum[], int *rows, int *columns)
{
    int i, j;
    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *columns; j++)
            sum[i] += a[i][j];
    }
}

void sort(int a[][M], int sum[], int *rows, int *columns)
{
    int i, j, k;
    int c = 0;
    for (i = 0; i < *rows - 1; i++)
    {
        for (j = i + 1; j < *rows; j++)
        {
            if (sum[i] > sum[j])
            {
                c = sum[i];
                sum[i] = sum[j];
                sum[j] = c;
                for (k = 0; k < *columns; k++)
                {
                    c = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = c;
                }
            }
        }
    }
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





