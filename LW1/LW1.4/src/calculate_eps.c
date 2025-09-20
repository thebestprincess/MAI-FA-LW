#include "../include/calculate_eps.h"

double calculate_epsilon(const int precision)
{   
    double eps = 1.0;
    for (int i = precision; i > 0; --i)
    {
        eps /= 10.0;
    }
    return eps;
}