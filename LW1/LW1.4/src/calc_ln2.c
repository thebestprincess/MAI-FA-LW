#include "../include/calc_ln2.h"

#include <math.h>
#include <stdio.h>

long double lim_function_ln2(const int n)
{
    return n * (powl(2.0, 1.0 / n) - 1);
}


long double calc_ln2_lim(const long double eps)
{
    int n = 2;
    long double prev_value = lim_function_ln2(n - 1);
    long double value = lim_function_ln2(n);

    while (fabsl(value - prev_value) >= eps)
    {
        ++n;
        prev_value = value;
        value = lim_function_ln2(n);
    }

    printf("The result of ln2 obtained via the \"Limit\" function.\nn: %d\nln2: %.20Lf\n", n, value);
    return value;
}


long double calc_ln2_row(const long double eps)
{
    int n = 1;
    long double row_value = 1.0;
    long double row_element = 1.0; 

    while(fabsl(row_element) >= eps)
    {
        if (n == 1000000000)
        {
            break;
        }
        ++n;
        row_element = ((n % 2 == 0) ? -1.0 : 1.0) / n;
        row_value += row_element;
    }

    printf("The result of ln2 obtained via the \"Row\" function.\nn: %d\nln2: %.20Lf\n", n, row_value);
    return row_value;
}


long double calc_ln2_equation(const long double eps)
{   
    // e^x - 2 = 0
    long double lhs = 0.0;
    long double rhs = 1.0;
    long double mid;

    while (fabsl(lhs - rhs) >= eps)
    {
        mid = (lhs + rhs) / 2.0;

        if ((expl(lhs) - 2.0) * (expl(rhs - 2.0)) > 0.0)
        {
            rhs = mid;
        }
        else 
        {
            lhs = mid;
        }
    }

    printf("The result of ln2 obtained via the \"Equation\" function.\nln2: %.20Lf\n", (lhs + rhs) / 2.0);
    return (lhs + rhs) / 2.0;
}