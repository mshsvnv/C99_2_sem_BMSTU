#include <stdio.h>

int main(void)
{
    double h, t, m, m_n, bmi;
    scanf("%lf%lf%lf", &h, &t, &m);
    m_n = (h * t) / 240;
    bmi = 10000 * m / (h * h);
    printf("%lf %lf\n", m_n, bmi);
    return 0;
}

