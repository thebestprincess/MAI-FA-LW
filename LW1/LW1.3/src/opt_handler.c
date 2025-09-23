#include "../include/opt_handler.h"
#include "../include/validator.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

OptHandler parse_arg(const char* argv)
{
    if (strlen(argv) == 2 && (argv[0] == '-' || argv[0] == '/'))
    {
        switch (argv[1]) 
        {
            case 'q': return OPT_Q;
            case 'm': return OPT_M;
            case 't': return OPT_T;
            default: return OPT_INVALID;
        }
    }
    
    return OPT_INVALID;
}


void solve_quadratic_equation(double precision, double a, double b, double c)
{
    printf("Solution for a = %.5f, b = %.5f, c = %.5f\n", a, b, c);
    if (fabs(a - 0.0) > precision)
    {
        double D = b * b - 4 * a * c;
        if (fabs(D - 0.0) < precision)
        {
            printf("x = %.5f\n", (-b) / (2 * a));
        }
        else if (D < 0.0)
        {
            printf("There is no solution to the equation\n");
        }
        else 
        {
            printf("x1 = %.5f\nx2 = %.5f\n", ((-b) - sqrt(D)) / (2 * a), ((-b) + sqrt(D)) / (2 * a));
        }
    }
    else
    {

        printf("x = %.5f\n", (-c) / b);
    }
}


void value_processing(int argc, const char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        OptHandler opt = parse_arg(argv[i]);

        if (opt == OPT_INVALID)
        {
            continue;
        }
        else if (opt == OPT_Q) 
        {
            if (i + 4 < argc)
            {
                double eps, num1, num2, num3;
                char* endptr;
                if (check_real_number(argv[i + 1]) 
                    && check_real_number(argv[i + 2]) 
                    && check_real_number(argv[i + 3]) 
                    && check_real_number(argv[i + 4]))
                {
                    eps = strtod(argv[i + 1], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num1 = strtod(argv[i + 2], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num2 = strtod(argv[i + 3], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num3 = strtod(argv[i + 4], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    handle_q(eps, num1, num2, num3);
                }
                else 
                {
                    handle_message("Invalid value(s) for the [-q or /q] option");
                    continue;
                }
                
            }
            else 
            {
                handle_message("Not enough values for [-q or /q] option");
                break;
            }
        }
        else if (opt == OPT_M)
        {
            if (i + 2 < argc)
            {
                int num1, num2;
                if (check_integer(argv[i + 1]) && check_integer(argv[i + 2]))
                {
                    num1 = atoi(argv[i + 1]);
                    num2 = atoi(argv[i + 2]);
                    handle_m(num1, num2);
                }
                else 
                {
                    handle_message("Invalid value(s) ​​for the [-m or /m] option");
                    continue;
                }

            }
            else 
            {
                handle_message("Not enough values for [-m or /m] option");
                break;
            }
        }
        else if (opt == OPT_T)
        {
            if (i + 4 < argc)
            {
                double eps, num1, num2, num3;
                char* endptr;
                if (check_real_number(argv[i + 1]) 
                    && check_real_number(argv[i + 2]) 
                    && check_real_number(argv[i + 3]) 
                    && check_real_number(argv[i + 4]))
                {
                    eps = strtod(argv[i + 1], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num1 = strtod(argv[i + 2], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num2 = strtod(argv[i + 3], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    num3 = strtod(argv[i + 4], &endptr);
                    if (*endptr != '\0') {
                        continue;
                    }
                    handle_t(eps, num1, num2, num3);
                }
                else 
                {
                    handle_message("Invalid value(s) ​​for the [-t or /t] option");
                    continue;
                }
            }
            else 
            {
                handle_message("Not enough values for [-t or /t] option");
                break;
            }
        }
    }
    
}


void handle_q(double precision, double num1, double num2, double num3)
{
    solve_quadratic_equation(precision, num1, num2, num3);
    solve_quadratic_equation(precision, num1, num3, num2);
    solve_quadratic_equation(precision, num2, num1, num3);
    solve_quadratic_equation(precision, num2, num3, num1);
    solve_quadratic_equation(precision, num3, num1, num2);
    solve_quadratic_equation(precision, num3, num2, num1);
}


void handle_m(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        handle_message("Two NON-ZERO numbers must be specified for [-m or /m] flag");
        return;
    }

    if (num1 % 2 == 0)
    {
        printf("Result of flag [-m or /m]: first number IS a multiple of second\n");
    }
    else
    {
        printf("Result of flag [-m or /m]: first number is NOT a multiple of second\n");
    }
}


void handle_t(double precision, double num1, double num2, double num3)
{
    if (fabs(num1 - 0.0) < precision || fabs(num2 - 0.0) < precision || fabs(num3 - 0.0) < precision)
    {
        handle_message("Result of flag [-t or /t]: The side of a triangle CANNOT be equal to ZERO.");
        return;
    }

    if ((num1 - 0.0) < precision || (num2 - 0.0) < precision || (num3 - 0.0) < precision)
    {
        handle_message("Result of flag [-t or /t]: The side of a triangle CANNOT be negative.");
        return;  
    }

    if ((num1 + num2 - num3) < precision || (num1 + num3 - num2) < precision || (num2 + num3 - num1) < precision)
    {
        printf("Result of flag [-t or /t]: Three real parameters CANNOT be the sides of ANY triangle\n");
        return;
    }

    if (fabs(num1 * num1 + num2 * num2 - num3 * num3) < precision
        || fabs(num3 * num3 + num1 * num1 - num2 * num2) < precision 
        || fabs(num2 * num2 + num3 * num3 - num1 * num1) < precision)
    {
        printf("Result of flag [-t or /t]: Three real parameters CAN be the sides of a triangle\n");
    }
    else
    {
        printf("Result of flag [-t or /t]: Three real parameters CANNOT be the sides of a triangle\n");
    }
}


void handle_help(const char* message)
{
    printf("Reason for notification call: %s\n", message);
    printf("You should use: ./program [-q or /q] [-m or /m] [-t or /t]\n");
    printf("    -q <precision> <a> <b> <c>    - solution of a quadratic equation for all possible unique permutations of a b c\n");
    printf("    -m <a> <b>                    - determines the multiple of the first number to the second\n");
    printf("    -t <precision> <a> <b> <c>    - determines the possible correspondence of numbers to the sides of a triangle\n");
}

void handle_message(const char* message)
{
    printf("Reason for notification call: %s\n", message);
}
