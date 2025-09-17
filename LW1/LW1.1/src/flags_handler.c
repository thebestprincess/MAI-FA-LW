#include "../include/flags_handler.h"
#include <stdio.h>

int is_number(const char* str)
{
    while (*str) {
        if (isdigit(*str++) == 0) return 0;
    }
    return 1;
}


void h_flag(const int num)
{
    printf("h-flag handler:\n");
    int fl = 0;
    if (num <= 100)
    {
        printf("List of numbers that are multiples of x:\n");
        for (int i = 1; i <= 100; ++i)
        {
            if (i % num == 0)
            {
                printf("%-5d", i);
                ++fl;
            }
        }
    }
    else 
    {
        printf("Your number is greater than 100.\n");
    }

    if (!fl)
    {
        printf("Such number doesn't exist.\n");
    }
    printf("\n");
}


void p_flag(const int num)
{
    printf("p-flag handler:\n");

    int top = sqrt(num);
    for (int i = 2; i < top + 1; ++i)
    {
        if (num % i == 0)
        {
            printf("This number is composite.\n\n");
            return;
        }
    }
    printf("This number is prime.\n\n");
}


void s_flag(const int num)
{
    printf("s-flag handler:\n");

    const int SIZE = 33;
    char buff[SIZE];
    char* p = buff + SIZE - 1;
    *p-- = 0;
    int r = 0, base = 16, n = num;
    while(n)
    {
        r = n % base;
        if(r > 9) *p-- = r - 10 + 'A';
        else *p-- = r + '0';
        n /= base;
    }

    while(*++p) printf("%c ", *p);
    printf("\n\n");
}


void e_flag(const int num)
{
    printf("e-flag handler:\n");
    if (num > 10)
    {
        printf("Your number is more than 10\n");
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


void a_flag(const int num)
{
    printf("a-flag handler:\n");
    if (num < 0)
    {
        printf("Your number is less than zero\n");
    }
    int sum = num * (num + 1) / 2;
    printf("The sum of all natural numbers from 1 to x: %d\n\n", sum);
}


void f_flag(const int num)
{
    printf("f-flag handler:\n");
    long long factorial = 1;
    for (int i = 1; i <= num; ++i)
    {
        factorial *= i;
    }
    printf("Factorial of %d: %lld\n\n", num, factorial);
}

