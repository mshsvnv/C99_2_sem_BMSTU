#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, h, p, x;
    scanf("%lf%lf%lf", &a, &b, &h);
    x = fabs(a - b) / 2;
    p = a + b + 2 * pow(x * x + h * h, 0.5);
    printf("%lf\n", p);
    return 0;
}
