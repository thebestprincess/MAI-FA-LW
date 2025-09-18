#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sieve.h"
#include "../include/validator.h"



int main(int argc, const char* argv[])
{
    int quantity = 0, max = 0;
    printf("Input number of requests: ");
    number_check(&quantity);

    int* const requests = malloc(quantity * sizeof(int));
    if (requests == NULL)
    {
        printf("Something went wrong...\nIt's impossible to allocate memory for requests...\n");
        return 1;
    }

    for (unsigned i = 0; i < quantity; ++i)
    {
        printf("%d: ", i + 1);
        number_check(requests + i);

        if(*(requests + i) > max)
        {
            max = *(requests + i);
        }
    }

    int number = 10000;
    int* const sieve = sieve_of_eratosthenes(number, max);
    if (sieve == NULL)
    {
        printf("Something went wrong...\n");
        free(requests);
        return 1;
    }

    printf("\n");
    for (unsigned i = 0; i < quantity; ++i)
    {
        printf("%d: %d\n", *(requests + i), sieve[*(requests + i) - 1]);
    }

    free(requests);
    free(sieve);
    return 0;
}