#include "../include/opt_processing.h"

#include <stdlib.h>
#include <stdio.h>

void args_processing(const int argc)
{
    if (argc < 3)
    {
        printf("Not enough arguments");
        exit(EXIT_FAILURE);
    }
    
    if (argc > 3)
    {
        printf("Too many arguments");
        exit(EXIT_FAILURE);
    }
}