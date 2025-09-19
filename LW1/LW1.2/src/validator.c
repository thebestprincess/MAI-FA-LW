#include "../include/validator.h"

int is_number(const char* str)
{
    while (*str) {
        if (isdigit(*str++) == 0) return 0;
    }
    return 1;
}

int number_check(int* number)
{
    const int buff_size = 20;
    char buff[buff_size];

    fgets(buff, buff_size, stdin);
    if (sscanf(buff, "%d", number) == 1 && *number > 0 && *number <= 1000 && is_number(buff))
    {
        return 1;
    }
    else 
    {
        *number = 1;
        printf("Invalid data format. Default: 1\n");
        printf("Hint: Your number must be positive and within a thousand.\n");
        return 0;
    }
}