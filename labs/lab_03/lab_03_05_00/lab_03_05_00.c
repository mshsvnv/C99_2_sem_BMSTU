#include <stdio.h>
#include <math.h>

#define N 10
#define M 10

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2
#define ARRAY_ERROR 3
#define DATA_ERROR 4

int read_r_c(int *rows, int *columns);
int read_massive(int a[][M], int *rows, int *columns);
int simple_massive(int a[][M], int b[], int *index[], int *rows, int *columns);
int simple(int el);
void reverse(int b[], int *res);
void new_massive(int b[], int *index[], int *res);
void show(int a[], int *columns);

int main(void)
{
    int a[N][M] = { 0 };
    int b[N * M] = { 0 };
    int *index[N * M] = { 0 };
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
            res = simple_massive(a, b, index, &rows, &columns);
            if (res == 0)
            {
                printf("ERROR: нет простых чисел\n");
                return DATA_ERROR;
            }
            else
            {
                reverse(b, &res);
                new_massive(b, index, &res);
                printf("Result: \n");
                for (int i = 0; i < rows; i++)
                    show(a[i], &columns);
            } 
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

int simple_massive(int a[][M], int b[], int *index[], int *rows, int *columns)
{
    int i, j, k = 0;
    int res = 0;
    for (i = 0; i < *rows; i++)
    {
        for (j = 0; j < *columns; j++)
        {
            if (simple(a[i][j]) == 0)
            {
                b[k] = a[i][j];
                *index = &a[i][j];
                index++;
                k++;
                res++;
            }
        }
    }
    return res;
}

int simple(int el)
{
    if (el == 2)
        return SUCCESS;
    else
    {
        if (el <= 1)
            return TYPE_ERROR;
        for (int i = 2; i <= sqrt(el); i++)
        {
            if (el % i == 0)
                return TYPE_ERROR;
        } 
        return SUCCESS; 
    }
}

void reverse(int b[], int *res)
{
    int i, c = 0;
    for (i = 0; i < (*res / 2); i++)
    {
        c = b[i];
        b[i] = b[*res - i - 1];
        b[*res - i - 1] = c;
    }
}

void new_massive(int b[], int *index[], int *res)
{
    int i;
    for (i = 0; i < *res; i++)
        *index[i] = b[i];
}

void show(int a[], int *columns)
{
    int j;
    for (j = 0; j < *columns; j++)
        printf("%d ", a[j]);
    printf("\n");
}





