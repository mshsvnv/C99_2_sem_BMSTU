#include <stdio.h>

int max_min(double a, double b, double c)
{
    double max, min;
    if (a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    if (c <= max && c >= min)
        return 1;
    else
        return 0;
}

int own(double xq, double yq, double xr, double yr, double xp, double yp)
{
    double s = (xp - xq) * (yr - yq) - (xr - xq) * (yp - yq);
    int r = max_min(xq, xr, xp) + max_min(yq, yr, yp);
    if ((s >= 0 && s <= 0) && r == 2)
        return 1;
    else
        return 0;
}

int main(void)
{
    double xq, yq, xr, yr, xp, yp;
    int res, s;
    res = scanf("%lf%lf%lf%lf%lf%lf", &xq, &yq, &xr, &yr, &xp, &yp);
    if (res != 6)
        return 1;
    else if ((xq <= xr && xq >= xr) && (yq <= yr && yq >= yr))
        return 2;
    else
    {
        s = own(xq, yq, xr, yr, xp, yp);
        printf("%d\n", s);
    }
    return 0;
}
