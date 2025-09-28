#include "../include/validate_input.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 64


// Returns 1 if number is valid, 0 otherwise 
int is_valid_number(const char* buffer)
{
    if (*buffer == '-')
    {
        ++buffer;
    }

    if (strlen(buffer) == 0)
    {
        return 0;
    }

    while (*buffer != 0)
    {
        if (!isdigit(*buffer))
        {
            return 0;
        }

        ++buffer;
    }

    return 1;
}


int obtain_base()
{
    printf("Input base (2-36): ");

    char buffer[BUFFERSIZE];
    if (fgets(buffer, BUFFERSIZE, stdin) == NULL)
    {
        perror("Unable to read from stding");
        exit(EXIT_FAILURE);
    }

    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0 || !is_valid_number(buffer))
    {
        perror("Wrong base");
        exit(EXIT_FAILURE);
    }

    int number = atoi(buffer);

    if (number < 2 || number > 36)
    {
        perror("Wrong base");
        exit(EXIT_FAILURE);
    }

    return number;
}


long long decimal_from_any(const char* buffer, int base)
{
    if (buffer == NULL)
    {
        return 0;
    }

    int sign = 1;

    if (*buffer == '-')
    {
        ++buffer;
        sign = -1;
    }

    long long temp_res = 0;
    long long number = 0;

    while (*buffer != 0)
    {
        if (isdigit(*buffer))
        {
            temp_res = (long long)(*buffer - '0');
        }
        else 
        {
            temp_res = toupper(*buffer) - 'A' + 10;
        }

        number = number * base + temp_res;
        ++buffer;
    }

    return sign * number;
}


// returns 1 if the base matches, 0 otherwise 
int check_base(const char* buffer, int base)
{
    if (buffer == NULL)
    {
        return 0;
    }    

    if (*buffer == '-')
    {
        ++buffer;
    }

    if (strlen(buffer) == 0)
    {
        return 0;
    }

    int number;

    while (*buffer != 0)
    {
        if (isalpha(*buffer))
        {
            number = toupper(*buffer) - 'A' + 10;
        }
        else if (isdigit(*buffer))
        {
            number = *buffer - '0';
        }
        else
        {
            return 0;
        }
        
        if (number >= base)
        {
            return 0;
        }

        ++buffer;
    }

    return 1;
}


long long validate_input(int base)
{
    long long max = 0;
    long long number = 0;
    char buffer[BUFFERSIZE];

    while (1)
    {
        printf("Enter number: ");
        if (fgets(buffer, BUFFERSIZE, stdin) == NULL)
        {
            break;
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "Stop") == 0
            || strcmp(buffer, "q") == 0
            || strcmp(buffer, "Q") == 0
            || strcmp(buffer, "stop") == 0)
        {
            break;
        }

        if (strlen(buffer) == 0)
        {
            continue;
        }

        if (check_base(buffer, base) == 0)
        {
            printf("Your number doesn't match base. This number will be equal to 0.\n");
            number = 0;
        }
        else
        {
            number = decimal_from_any(buffer, base);
        }

        if (llabs(number) > llabs(max))
        {
            max = number;
        }
    }

    return max;
}


char* any_from_decimal(char* buffer, long long number, int base)
{
    if (buffer == NULL)
    {
        return NULL;
    }

    if (number == 0)
    {
        buffer[0] = '0';
        buffer[1] = 0;
        return buffer;
    }

    int sign = 1;
    int res = 0;
    char temp[BUFFERSIZE];
    char* ptr = temp + BUFFERSIZE - 1;
    *ptr-- = 0;

    if(number < 0)
    {
        sign = -1;
        number = -number;

        *buffer = '-';
        ++buffer;
    }

    while (number)
    {
        res = number % base;

        if (res > 9)
        {
            *ptr = res - 10 + 'A'; 
        }
        else
        {
            *ptr = res + '0';
        }

        --ptr;
        number /= base;
    }
    ++ptr;

    while (*ptr != 0)
    {
        *buffer = *ptr;
        ++buffer;
        ++ptr;
    }
    *buffer = 0;
    
    return buffer;
}


void print_max_value()
{
    int base = obtain_base();
    long long number = validate_input(base);
    char buffer[BUFFERSIZE];

    any_from_decimal(buffer, number, base);
    printf("Maximum number by absolute value: %s\n", buffer);

    any_from_decimal(buffer, number, 9);
    printf("Number with base 9: %s\n", buffer);

    any_from_decimal(buffer, number, 18);
    printf("Number with base 18: %s\n", buffer);

    any_from_decimal(buffer, number, 27);
    printf("Number with base 27: %s\n", buffer);

    any_from_decimal(buffer, number, 36);
    printf("Number with base 36: %s\n", buffer);

}