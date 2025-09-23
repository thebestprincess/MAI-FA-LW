#include "../include/flags_handler.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


OptHandler parse_args(const char* argv)
{
    const char* ptr = argv;
    if (*ptr == '-' || *ptr == '/')
    {
        ++ptr;
        while (*ptr != '\0')
        {
            switch (*(ptr++)) 
            {
                case 'h': return OPT_H;
                case 'p': return OPT_P;
                case 's': return OPT_S;
                case 'e': return OPT_E;
                case 'a': return OPT_A;
                case 'f': return OPT_F;
                default: return OPT_INVALID;
            }
        }
    }
    return OPT_INVALID;
}


void value_processing(const int argc, const char** argv)
{
    if (argc < 2)
    {
        handle_help("No flags passed");
        return;
    }

    opt_handler handler[6] = 
    {
        handle_h,
        handle_p,
        handle_s,
        handle_e,
        handle_a,
        handle_f,
    };
    
    for (int i = 1; i < argc; ++i)
    {
        OptHandler opt = parse_args(argv[i]);
        int number;

        if (opt == OPT_INVALID)
        {
            continue;
        }
        else
        {
            if (!(i + 1 < argc))
            {
                handle_message("Not enough arguments for option");
                return;
            }
            if (is_number(argv[i + 1]) > 0)
            {
                number = atoi(argv[i + 1]);
                handler[opt](number);
            }
            else 
            {
                handle_message("An invalid argument was passed.\n");
            }
        }
    }

}


void handle_help(const char* message)
{
    printf("Reason for notification call: %s\n", message);
    printf("You should use: ./program [-h or /h] [-p or /p] [-s or /s] [-e or /e] [-a or /a] [-f or /f]\n");
    printf("    -h <x>    - multiples of x within 100\n");
    printf("    -p <x>    - check if x is prime/composite\n");
    printf("    -s <x>    - split x into hex digits\n");
    printf("    -e <x>    - exponent table (x <= 10)\n");
    printf("    -a <x>    - sum of 1 to x\n");
    printf("    -f <x>    - factorial of x\n");
}


void handle_message(const char* message)
{
    printf("Notification call: %s\n", message);
}


int is_number(const char* str)
{
    const char* ptr = str;

    if(*ptr == '-') ++ptr;
    while (*ptr != '\0') {
        if (*ptr < '0' || *ptr > '9')
        { 
            return -1;
        }
        ptr++;
    }
    return 1;
}


void handle_h(const int num)
{
    printf("h-flag handler:\n");

    int fl = 0;

    if (abs(num) > 100 || num == 0)
    {
        printf("No naturals that can be divided by %d in 1-100 range.\n", num);
    }
    else 
    {
        printf("List of numbers that are multiples of x:\n");
        for (int i = 1; i <= 100; ++i)
        {
            if (i % num == 0)
            {
                printf("%-5d", i);
            }
        }
    }
    printf("\n");
}


void handle_p(const int num)
{
    printf("p-flag handler:\n");

    if (num < 2)
    {
        printf("%d isn't a prime number.\n", num);
        return;
    }

    int top = sqrt(num);
    for (int i = 2; i < top + 1; ++i)
    {
        if (num % i == 0)
        {
            printf("This number is composite.\n");
            return;
        }
    }
    printf("This number is prime.\n");
}


void handle_s(const int num)
{
    printf("s-flag handler:\n");

    const int SIZE = 33;
    char buff[SIZE];
    char* p = buff + SIZE - 1;
    *p-- = '\0';
    
    int r = 0;
    int base = 16;
    int n = abs(num);

    if (n == 0) *p-- = '0';
    while(n)
    {
        r = n % base;
        if(r > 9) *p-- = r - 10 + 'A';
        else *p-- = r + '0';
        n /= base;
    }

    if (num < 0) printf("- ");
    while(*++p != '\0') printf("%c ", *p);
    printf("\n");
}


void handle_e(const int num)
{
    printf("e-flag handler:\n");
    if (num < 1 || num > 10)
    {
        printf("The number must be in the range 1-10\n");
        return;
    }
    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= num; ++j)
        {
            printf("%-12ld", (long)pow(i, j));
        }
        printf("\n");
    }
    printf("\n");
}


void handle_a(const int num)
{
    printf("a-flag handler:\n");
    if (num < 1)
    {
        printf("Your number is less than 1\n");
        return;
    }
    int sum = num * (num + 1) / 2;
    printf("The sum of all natural numbers from 1 to %d: %d\n", num, sum);
}


void handle_f(const int num)
{
    printf("f-flag handler:\n");

    if (num < 0)
    {
        printf("Number cannot be negative\n");
        return;
    }

    long long factorial = 1;
    for (int i = 1; i <= num; ++i)
    {
        factorial *= i;
    }
    printf("Factorial of %d: %lld\n", num, factorial);
}

