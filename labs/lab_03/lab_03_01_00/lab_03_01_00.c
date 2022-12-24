#include <stdio.h>

#define N 10
#define M 10

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3

int read_r_c(int *rows, int *columns);
int read_massive(int a[][M], int *rows, int *columns);
int descend(int a[][M], int *j, int *rows);
void print_arr(int b[], int *columns);
void new_massive(int a[][M], int b[], int *rows, int *columns);

int main(void)
{
    int a[N][M] = { 0 };
    int b[M] = { 0 };
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
            return TYPE_ERROR;
        }
        new_massive(a, b, &rows, &columns);
        print_arr(b, &columns);
        return SUCCESS;
    }
}

int read_r_c(int *rows, int *columns)
{
    int res = 0;
    printf("Введите кол-во строк: ");
    res += scanf("%d", rows);
    printf("Введите кол-во столбцов: ");
    res += scanf("%d", columns);
    if (res != 2)
    {
        return TYPE_ERROR;
    }
    else if ((*rows > M) || (*rows <= 0) || (*columns > N) || (*columns <= 0))
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

void print_arr(int b[], int *columns)
{
    int i;
    printf("Result: \n");
    for (i = 0; i < *columns; i++)
        printf("%d ", b[i]);
    printf("\n");
}

void new_massive(int a[][M], int b[], int *rows, int *columns)
{
    int j;
    for (j = 0; j < *columns; j++)
        b[j] = descend(a, &j, rows);
}

int descend(int a[][M], int *j, int *rows)
{
    int i;
    int flag = 1;
    for (i = 0; i < *rows - 1; i++)
    {
        if (a[i][*j] <= a[i + 1][*j])
        {
            flag = 0;
            break;
        }
    }
    if (*rows == 1)
        flag = 0;
    return flag;
}


