#include <stdio.h>

#define N 10
#define M 10

#define SUCCESS 0
#define TYPE_ERROR 1
#define SIZE_ERROR 2

int read_r_c(int *rows, int *columns);
void read_massive(int a[][M], int *rows, int *columns);
int down(int a[][M], int *j, int rows, int total);
int up(int a[][M], int *j, int rows, int total);
void show(int a[][M], int *rows, int *columns);

int main(void)
{
    int a[N][M] = { 0 };
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
        read_massive(a, &rows, &columns);
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
    else if ((*rows > M) || (*rows < 1) || (*columns > N) || (*columns < 1))
        return SIZE_ERROR;
    else
        return SUCCESS;
}

void read_massive(int a[][M], int *rows, int *columns)
{
    int j;
    int total = 1;
    for (j = 0; j < *columns; j++)
    {
        if (j % 2 == 0)
            total = down(a, &j, *rows, total);
        else
            total = up(a, &j, *rows, total);
    }
}

int down(int a[][M], int *j, int rows, int total)
{
    int i;
    for (i = 0; i < rows; i++)
        a[i][*j] = total++;
    return total;
}

int up(int a[][M], int *j, int rows, int total)
{
    int i;
    for (i = rows - 1; i >= 0; i--)
        a[i][*j] = total++;
    return total;
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



