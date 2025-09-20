#include "../include/calculate_eps.h"

double calculate_epsilon(const int precision)
{   
    double eps = 1.0;
    if (precision > 0)
    {
        for (int i = precision; i > 0; --i)
        {
            eps /= 10.0;
        }
    }
    else 
    {
        while ((eps + 1) != 1)
        {
            eps /= 2;
        }
        eps *= 2;
    }
    return eps;
}