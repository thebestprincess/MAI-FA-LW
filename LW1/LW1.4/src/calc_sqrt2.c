#include "../include/calc_sqrt2.h"

double calc_sqrt2_lim(const double eps)
{
    double prev_value = -0.5;
    double value = prev_value - prev_value * prev_value / 2 + 1;
    int n = 2;
    while (fabs(value - prev_value) > eps)
    {
        n++;
        prev_value = value;
        value = prev_value - prev_value * prev_value / 2 + 1;
    }
    printf("The result of sqrt2 obtained via the \"Limit\" function.\nn: %d\nsqrt2: %.20f\n", n, value);
    return value;
}



double calc_sqrt2_row(const double eps)
{
    int k = 2;
    double prev_value = pow(2.0, pow(2.0, -k));
    ++k;
    double value = prev_value * pow(2.0, pow(2.0, -k));

    while (fabs(value - prev_value) > eps)
    {
        k++;
        prev_value = value;
        value = prev_value * pow(2.0, pow(2.0, -k));
    }
    printf("The result of sqrt2 obtained via the \"Row\" function.\nn: %d\nsqrt2: %.20f\n", k, value);
    return value;
}



double calc_sqrt2_equation()
{   
    // x^2 = 2
    // x = sqrt2 
    double sqrt2 = sqrt(2);
    printf("The result of sqrt2 obtained via the \"Equation\" function.\nsqrt2: %.20f\n", sqrt2);
    return sqrt2;
}