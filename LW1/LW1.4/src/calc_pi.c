#include "../include/calc_pi.h"


double lim_function_pi(const int n) 
{
    return 4.0 * n * (n - 1.0) / ((2.0 * n - 1.0) * (2.0 * n - 1.0));
}


double calc_pi_lim(const double eps) 
{
    double prev_value = 4.0;
    double value = prev_value * lim_function_pi(2);
    int n = 3;

    while (fabs(value - prev_value) >= eps) 
    {
        prev_value = value;
        value *= lim_function_pi(n);
        ++n;
    }

    printf("The result of pi obtained via the \"Limit\" function.\nn: %d\npi: %.20f\n", n, value);
    return value;
}


double calc_pi_row(const double eps)
{
    int n = 1;
    double row_value = 0.0;
    double sign = 1.0;
    double row_element = sign / (2.0 * n - 1.0);

    while (4.0 * fabs(row_element) >= eps)
    {
        if (n >= 1000000000)
        {
            break;
        }
        row_value += row_element;
        ++n;
        sign = -sign;
        row_element = sign / (2.0 * n - 1.0);
    }
    row_value *= 4.0;

    printf("The result of pi obtained via the \"Row\" function.\nn: %d\npi: %.20f\n", n, row_value);
    return row_value;
}


double calc_pi_equation()
{   
    // cos x = -1
    // x = arccos -1
    double pi = acos(-1);
    printf("The result of pi obtained via the \"Equation\" function.\npi: %.20f\n", pi);
    return pi;
}