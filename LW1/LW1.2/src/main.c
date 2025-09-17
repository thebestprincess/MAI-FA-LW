#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sieve.h"



int main(int argc, const char* argv[])
{
    int quantity = 0, max = 0;
    printf("Input number of requests: ");
    scanf("%d", &quantity);

    int* const requests = malloc(quantity * sizeof(int));
    if (requests == NULL)
    {
        printf("Something went wrong...\nIt's impossible to allocate memory...");
        return 1;
    }

    for (unsigned i = 0; i < quantity; ++i)
    {
        printf("%d: ", i + 1);
        scanf("%d", requests + i);
        if (*(requests + i) < 1 || *(requests + i) > 1000)
        {
            printf("Invalid data format. Default: 1\n");
            printf("Hint: Your number must be positive and within a thousand.\n");
            *(requests + i) = 1;
        }
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