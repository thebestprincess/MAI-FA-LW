#include "../include/sieve.h"


int* const sieve_of_eratosthenes(const int num, const int index)
{
    // Allocate memory for sieve
    int* const sieve = malloc(num * sizeof(int));
    if (sieve == NULL)
    {
        printf("Something went wrong...\nImpossible to allocate memory for sieve...\n");
        return NULL;
    }

    // Fill the sieve from 0 to num
    for (int i = 0; i < num; ++i)   
    {
        *(sieve + i) = i;
    }
    *(sieve + 1) = 0;


    // Allocate memory for primes
    int* const primes = malloc(index * sizeof(int));
    if (primes == NULL)
    {
        printf("Something went wrong...\nImpossible to allocate memory for primes...\n");
        free(sieve);
        return NULL;
    }
    int counter = 0;


    // Sieve of Eratosthenes algorithm
    for (int i = 2; i < num && counter < index; ++i)    
    {
        if (sieve[i])
        {
            primes[counter++] = sieve[i];
            for (int j = i * i; j < num; j += i)
            {
                sieve[j] = 0;
            }
        }
    }

    free(sieve);
    return primes;
}