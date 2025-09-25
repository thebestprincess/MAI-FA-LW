#include "../include/calc_gamma.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long double factorial(const int m)
{
    long double value = 1.0;

    for (int i = 2; i <= m; ++i)
    {
        value *= (long double)i;
    }

    return value;
}


long double gamma_lim_func(const int m)
{
    int sign = -1;
    long double combinations;
    long double sum = 0;
    
    for (int k = 1; k <= m; ++k)
    {
        combinations = factorial(m) / ((factorial(k)) * factorial(m - k));
        sum += combinations * sign / k * logl(factorial(k));
        sign *= -1;
    }

    return sum;
}


long double calc_gamma_lim(const long double eps)
{
    int m = 1;
    long double prev_value = gamma_lim_func(m++);
    long double value = gamma_lim_func(m++);

    while (fabsl(value - prev_value) >= eps && m != 20)
    {
        prev_value = value;
        value = gamma_lim_func(m++);
    }

    printf("The result of gamma obtained via the \"Limit\" function.\nn: %d\ngamma: %.20Lf\n", m, value);
    return value;
}


long double gamma_row_func(int k)
{
    return 1.0 / (floorl(sqrtl(k)) * floorl(sqrtl(k))) - 1.0 / k;
}

long double calc_gamma_row(const long double eps, const long double pi)
{
    int k = 2;
    long double prev_row_elem;
    long double row_elem = 0.5;
    long double value = (pi * pi) / (-6.0) + row_elem;

    while (row_elem >= eps || prev_row_elem >= eps)
    {
        prev_row_elem = row_elem;
        row_elem = gamma_row_func(++k);
        value += row_elem;
    }

    printf("The result of gamma obtained via the \"Row\" function.\nn: %d\ngamma: %.20Lf\n", k, value);
    return value;
}


int* sieve_func(const int t)
{
    if (t < 2) return NULL;

    int* sieve = (int*)malloc((t + 1) * sizeof(int));
    if (sieve == NULL)
    {
        printf("It's impossible to allocate memory for sieve...\n");
        return NULL;
    }

    for (int i = 0; i <= t; ++i)
    {
        sieve[i] = i;
    }
    sieve[1] = 0;



    for (int i = 2; i * i < t; ++i)
    {
        if (sieve[i] != 0)
        {
            for (long long j = i * i; j <= t; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}


long double calc_gamma_product(const int* const sieve, const int t)
{
    long double log_t = logl(t);
    long double product = 1.0; 

    for (int p = 2; p <= t; ++p)
    {
        if (sieve[p] != 0)
        {
            product *= (p - 1.0) / p;
        }
    }

    return log_t * product;
}


long double calc_gamma_equation(const long double eps)
{   
    long double gamma = 0.0;
    long double prev_value = 0.0, value = 0.0;
    int max_t = (int)2e6;

    int* sieve = sieve_func((int)2e6);
    if (sieve == NULL)
    {
        return 0.0;
    }

    long double lhs  = 0;
    long double rhs = 1.0;
    long double mid;

    long double function_in_limit = calc_gamma_product(sieve, (int)2e6);

    while (fabsl(rhs - lhs) >= eps)
    {
        mid = (lhs + rhs) / 2.0;

        if (expl(-mid) > function_in_limit)
        {
            lhs = mid;
        }
        else
        {
            rhs = mid;
        }
    }

    free(sieve);
    printf("The result of gamma obtained via the \"Equation\" function.\ngamma: %.20Lf\n", mid);

    return mid;
}