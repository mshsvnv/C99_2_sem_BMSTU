#include <stdio.h>
#include <math.h>

double summa(double x, int count, double sum)
{
    sum += x / count;
    return sum;
}

int main()
{
    double x = 0, g, sum = 0;
    int res, count = 1;
    while (x >= 0)
    {
        res = scanf("%lf", &x);
        if (res != 1)
            return 1;
        if (x < 0)
            break;
        sum = summa(x, count, sum);
        count += 1;
    }
    if (count == 1)
        return 1;
    g = pow(sum, 0.5);
    printf("%lf\n", g);
    return 0;
}

