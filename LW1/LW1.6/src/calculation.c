#include "../include/calculation.h"

#include <math.h>
#include <stdio.h>


double trapezoid_method(double precision, double x1, double x2, double (*func) (double))
{
    return (func(x1) + func(x2)) / 2.0 * precision;
}


double first_function(double x)
{
    return log(1 + x) / x;
}


void first(double precision)
{
    double x = precision;
    double sum = 0.0;

    while (x <= 1)
    {
        sum += trapezoid_method(precision, x, x + precision, first_function);
        x += precision;
    }

    printf("Result of the first integral is: %.10f\n", sum);
}


double second_function(double x)
{
    return exp(-(pow(x, 2) / 2.0));
}


void second(double precision)
{
    double x = precision;
    double sum = 0.0;

    while (x <= 1)
    {
        sum += trapezoid_method(precision, x, x + precision, second_function);
        x += precision;
    }

    printf("Result of the second integral is: %.10f\n", sum);
}


double third_function(double x)
{
    return log(1.0 / (1.0 - x));
}


void third(double precision)
{
    double x = precision;
    double sum = 0.0;

    while (x < 1 - precision)
    {
        sum += trapezoid_method(precision, x, x + precision, third_function);
        x += precision;
    }

    printf("Result of the third integral is: %.10f\n", sum);
}


double fourth_function(double x)
{
    return pow(x, x);
}


void fourth(double precision)
{
    double x = precision;
    double sum = 0.0;

    while (x < 1)
    {
        sum += trapezoid_method(precision, x, x + precision, fourth_function);
        x += precision;
    }

    printf("Result of the third integral is: %.10f\n", sum);
}




void all_calculations(double precision)
{
    first(precision);
    second(precision);
    third(precision);
    fourth(precision);
}



