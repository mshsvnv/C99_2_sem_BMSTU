#include <stdio.h>
#include <math.h>

double num(double x, int c)
{
    double el;
    if (c % 2 != 0)
        el = -((c - 1) * c * pow(x, c - 2)) / 2;
    else
        el = ((c - 1) * c * pow(x, c - 2)) / 2;
    return el;
}

int main(void)
{
    double x, eps, s = 0, f, delta, b, el;
    int res = 0, c = 3;
    res = scanf("%lf%lf", &x, &eps);
    if (res != 2)
        return 1;
    else if (fabs(x) >= 1.0)
        return 2;
    else if ((eps <= 0.0) || (eps > 1.0))
        return 3;
    else
    {
        f = 1 / pow((1 + x), 3);
        el = 1;
        while (fabs(el) >= eps)
        {
            s += el;
            el = num(x, c);
            c += 1;
        }
        b = fabs((f - s) / f);
        delta = fabs(f - s);
        printf("%lf\n", s);
        printf("%lf\n", f);
        printf("%lf\n", delta);
        printf("%lf\n", b);
    }
    return 0;
}
