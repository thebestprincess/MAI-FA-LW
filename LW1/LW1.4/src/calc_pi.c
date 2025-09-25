#include "../include/calc_pi.h"

#include <math.h>
#include <stdio.h>


long double lim_function_pi(const int n) 
{
    // f(n + 1) / f(n)
    return 4.0 * n * (n - 1.0) / ((2.0 * n - 1.0) * (2.0 * n - 1.0));
}


long double calc_pi_lim(const long double eps) 
{
    int n = 2;
    long double prev_value = 4.0;
    long double value = prev_value * lim_function_pi(n);

    while (fabsl(value - prev_value) >= eps) 
    {
        ++n;
        prev_value = value;
        value *= lim_function_pi(n);
    }

    printf("The result of pi obtained via the \"Limit\" function.\nn: %d\npi: %.20Lf\n", n, value);
    return value;
}


long double calc_pi_row(const long double eps)
{
    long int n = 1;
    long double row_value = 1.0;
    long double row_element = 1.0;

    while (4.0 * fabsl(row_element) >= eps)
    {
        if (n >= 1000000000)
        {
            break;
        }
        ++n;
        row_element = ((n % 2 == 0) ? -1.0 : 1.0) / (2.0 * n - 1.0);
        row_value += row_element;
    }
    row_value *= 4.0;

    printf("The result of pi obtained via the \"Row\" function.\nn: %ld\npi: %.20Lf\n", n, row_value);
    return row_value;
}


long double calc_pi_equation(const long double eps)
{   
    // Newton method based of function derivative
    long double approximated_value = 3.0;

    while (cosl(approximated_value) + 1.0 >= eps)
    {
        approximated_value -= (cosl(approximated_value) + 1.0) / (-sinl(approximated_value));
    }

    printf("The result of pi obtained via the \"Equation\" function.\npi: %.20Lf\n", approximated_value);
    return approximated_value;
}