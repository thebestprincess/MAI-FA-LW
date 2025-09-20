#include "../include/calc_e.h"

double lim_function_e(const int n)
{
    double func_val;
    func_val = pow((1.0 + 1.0 / n), n);

    return func_val;
}

double calc_e_lim(const double eps)
{
    int n = 3;
    while (fabs(lim_function_e(n) - lim_function_e(n - 1)) > eps)
    {
        n++;
    }
    double e = lim_function_e(n);
    printf("The result of e obtained via the \"Limit\" function.\nn: %d\ne: %.20f\n", n, e);
    return e;
}



double calc_e_row(const double eps)
{
    double row_value = 1.0;
    long long factorial = 1;
    int n = 2;
    while(1.0 / factorial > eps)
    {
        row_value += 1.0 / factorial;
        factorial *= n++;
    }
    printf("The result of e obtained via the \"Row\" function.\nn: %d\ne: %.20f\n", n, row_value);
    return row_value;
}



double calc_e_equation()
{   
    // ln x = 1
    // x = e ^ 1 
    double e = exp(1.0);
    printf("The result of e obtained via the \"Equation\" function.\ne: %.20f\n", e);
    return e;
}