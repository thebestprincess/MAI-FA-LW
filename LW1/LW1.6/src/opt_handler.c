#include "../include/opt_handler.h"

#include <stdio.h>
#include <stdlib.h>


long double get_precision(const int argc,const char** argv)
{
    double eps = 0.0001;

    if (argc != 2)
    {
        printf("Incorrect number of arguments\n");
        printf("The default value is set. Default: 0.0001\n");
        return eps;
    }

    char* endptr;
    eps = strtod(argv[1], &endptr);
    
    if (endptr == argv[1] || *endptr != '\0') {
        printf("Error: %s is not a valid number\n", argv[1]);
        printf("The default value is set. Default: 0.0001\n");
        return 0.0001;
    }
    
    if (eps <= 0) {
        printf("Error: precision must be positive\n");
        printf("The default value is set. Default: 0.0001\n");
        return 0.0001;
    }
    return eps;
}