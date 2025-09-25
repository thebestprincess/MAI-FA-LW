#include "../include/calc_sqrt2.h"

#include <math.h>
#include <stdio.h>


long double calc_sqrt2_lim(const long double eps)
{
    int n = 2;
    long double prev_value = -0.5;
    long double value = prev_value - prev_value * prev_value / 2.0 + 1.0;

    while (fabsl(value - prev_value) >= eps)
    {
        n++;
        prev_value = value;
        value = prev_value - prev_value * prev_value / 2.0 + 1.0;
    }

    printf("The result of sqrt2 obtained via the \"Limit\" function.\nn: %d\nsqrt2: %.20Lf\n", n, value);
    return value;
}


long double calc_sqrt2_row(const long double eps)
{
    int k = 2;
    long double prev_value = pow(2.0, pow(2.0, -(k++)));
    long double value = prev_value * pow(2.0, pow(2.0, -k));

    while (fabsl(value - prev_value) >= eps)
    {
        ++k;
        prev_value = value;
        value = prev_value * pow(2.0, pow(2.0, -k));
    }

    printf("The result of sqrt2 obtained via the \"Row\" function.\nn: %d\nsqrt2: %.20Lf\n", k, value);
    return value;
}


long double calc_sqrt2_equation(const long double eps)
{   
    // x^2 = 2
    long double lhs = 1.0;
    long double rhs = 2.0;
    long double mid;

    while (fabsl(lhs - rhs) >= eps)
    {
        mid = (lhs + rhs) / 2.0;

        if ((powl(lhs, 2.0) - 2.0) * (powl(rhs, 2.0) - 2.0) > 0)
        {
            rhs = mid;
        }
        else
        {
            lhs = mid;
        }
    }

    printf("The result of sqrt2 obtained via the \"Equation\" function.\nsqrt2: %.20Lf\n", (lhs + rhs) / 2.0);
    return (lhs + rhs) / 2.0;
}