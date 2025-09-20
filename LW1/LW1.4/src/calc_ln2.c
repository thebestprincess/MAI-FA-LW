#include "../include/calc_ln2.h"


double lim_function_ln2(const int n)
{
    return n * (pow(2.0, 1.0 / n) - 1);
}


double calc_ln2_lim(const double eps)
{
    int n = 2;
    while (fabs(lim_function_ln2(n) - lim_function_ln2(n - 1)) >= eps)
    {
        n++;
    }
    const double ln2 = lim_function_ln2(n);
    printf("The result of ln2 obtained via the \"Limit\" function.\nn: %d\nln2: %.20f\n", n, ln2);
    return ln2;
}


double calc_ln2_row(const double eps)
{
    double sign = 1.0;
    double row_value = 0.0;
    int n = 1;
    double row_element = sign / n; 
    while(fabs(row_element) >= eps)
    {
        if (n == 1000000000)
        {
            break;
        }
        row_value += row_element;
        ++n;
        sign = -sign;
        row_element = sign / n;
    }
    printf("The result of ln2 obtained via the \"Row\" function.\nn: %d\nln2: %.20f\n", n, row_value);
    return row_value;
}


double calc_ln2_equation()
{   
    // e^x = 2
    // x = ln 2 
    double ln2 = log(2);
    printf("The result of ln2 obtained via the \"Equation\" function.\nln2: %.20f\n", ln2);
    return ln2;
}