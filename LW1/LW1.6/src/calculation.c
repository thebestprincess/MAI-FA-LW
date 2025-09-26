#include "../include/calculation.h"

#include <math.h>
#include <stdio.h>


long double trapezoid_method(long double (*math_func) (long double), long long steps)
{
    long double delta = 1.0 / steps; 
    long double x;
    long double sum = (math_func(0) + math_func(1)) / 2.0;

    for (long long i = 1; i < steps; ++i)
    {
        x = i * delta;
        sum += math_func(x);
    }

    return delta * sum;
}


long double first_function(long double x)
{
    if (x == 0)
    {
        return 1;
    }

    return logl(1 + x) / x;
}


long double second_function(long double x)
{
    return expl(-(pow(x, 2) / 2.0));
}


long double third_function(long double x)
{
    if (x >= 0.999999999999999)
    {
        x = 0.999999999999999;
    }

    return logl(1.0 / (1.0 - x));
}


long double fourth_function(long double x)
{
    return pow(x, x);
}


long double calc_integral(long double eps, long double (*math_func) (long double))
{
    long long steps = 2;
    long double first = trapezoid_method(math_func, steps);

    steps *= 2;
    long double second = trapezoid_method(math_func, steps);

    while (fabsl(first - second) / 3.0 >= eps && steps <= 1000000)
    {
        first = second;
        steps *= 2;
        second = trapezoid_method(math_func, steps);
    }

    return second;
}


void all_calculations(long double precision)
{
    printf("Result of the first integral is: %.10Lf\n", calc_integral(precision, first_function));
    printf("Result of the second integral is: %.10Lf\n", calc_integral(precision, second_function));
    printf("Result of the third integral is: %.10Lf\n", calc_integral(precision, third_function));
    printf("Result of the fourth integral is: %.10Lf\n", calc_integral(precision, fourth_function));
}



