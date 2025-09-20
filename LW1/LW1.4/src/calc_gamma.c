#include "../include/calc_gamma.h"

double factorial(const int m)
{
    double value = 1.0;
    for (int i = 2; i <= m; ++i)
    {
        value *= i;
    }
    return value;
}

double gamma_lim_func(const int m)
{
    double combinations, sum = 0;
    int sign = -1;
    for (int k = 1; k <= m; ++k)
    {
        combinations = (double)factorial(m) / (double)((factorial(k)) * factorial(m - k));
        sum += combinations * sign / k * log(factorial(k));
        sign *= -1;
    }
    return sum;
}


double calc_gamma_lim(const double eps)
{
    int m = 1;
    double prev_value = gamma_lim_func(m++);
    double value = gamma_lim_func(m++);
    while (fabs(value - prev_value) >= eps)
    {
        prev_value = value;
        value = gamma_lim_func(m++);
        if (m > 40) break;
    }
    printf("The result of gamma obtained via the \"Limit\" function.\nn: %d\ngamma: %.20f\n", m, value);
    return value;
}



double gamma_row_func(int k)
{
    return 1.0 / pow(floor(sqrt(k)), 2) - 1.0 / k;
}

double calc_gamma_row(const double eps, const double pi)
{
    int k = 2;
    double value = (pi * pi) / (-6.0) + gamma_row_func(k++);

    while (gamma_row_func(k) > eps || gamma_row_func(k - 1) > eps)
    {
        value += gamma_row_func(k++);
    }
    printf("The result of gamma obtained via the \"Row\" function.\nn: %d\ngamma: %.20f\n", k, value);
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


double calc_gamma_product(const int* const sieve, const int t)
{
    double log_t = log(t);
    double product = 1.0; 
    for (int p = 2; p <= t; ++p)
    {
        if (sieve[p] != 0)
        {
            product *= (p - 1.0) / p;
        }
    }
    return log_t * (double)product;
}


double calc_gamma_equation(const double eps)
{   
    double gamma = 0.0;
    double prev_value = 0.0, value = 0.0;
    int max_t = 100000;

    int* sieve = sieve_func(max_t);
    if (sieve == NULL)
    {
        return 0.0;
    }

    int t = 3;
    for (; t < max_t; ++t)
    {   
        value = calc_gamma_product(sieve, t);
        if (fabs( value - prev_value) < eps)
        {
            gamma = -log(value);
            break;
        }

        prev_value = value;

        if (t == max_t - 1)
        {
            gamma = -log(value);
        }
    }

    free(sieve);
    printf("The result of gamma obtained via the \"Equation\" function.\nt: %d\ngamma: %.20f\n", t, gamma);
    return gamma;
}