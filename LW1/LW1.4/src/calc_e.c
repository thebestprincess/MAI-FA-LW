#include "../include/calc_e.h"

#include <math.h>
#include <stdio.h>

long double lim_function_e(const int n)
{
    double func_val;
    func_val = pow((1.0 + 1.0 / n), n);
    
    return func_val;
}


long double calc_e_lim(const long double eps)
{
    int n = 3;
    long double prev_value = lim_function_e(n - 1);
    long double value = lim_function_e(n);

    while (fabsl(value - prev_value) >= eps)
    {
        prev_value = value;
        value  = lim_function_e(++n);
    }

    printf("The result of e obtained via the \"Limit\" function.\nn: %d\ne: %.20Lf\n", n, value);
    return value;
}


long double calc_e_row(const long double eps)
{
    int n = 0;
    long long factorial = 1;
    long double row_value = 1.0;
    long double elem_value = 1.0;

    while(elem_value >= eps)
    {
        factorial *= ++n;
        elem_value = 1.0 / factorial;
        row_value += elem_value;
    }

    printf("The result of e obtained via the \"Row\" function.\nn: %d\ne: %.20Lf\n", n, row_value);
    return row_value;
}


long double calc_e_equation(const long double eps)
{   
    long double lhs = 1.0;
    long double rhs = 3.0;
    long double mid;

    while (fabsl(lhs - rhs) >= eps)
    {
        mid = (lhs + rhs) / 2.0;

        if ((log(lhs) - 1.0) * (log(rhs) - 1.0) < 0)
        {
            lhs = mid;
        }
        else
        {
            rhs = mid;
        }
    }
    
    mid = (lhs + rhs) / 2.0;
    printf("The result of e obtained via the \"Equation\" function.\ne: %.20Lf\n", mid);
    return mid;
}