#include "../include/validator.h"


int check_real_number(const char* const arg)
{
    const char* ptr = arg;
    int point_counter = 0;

    if (*ptr == '-') ++ptr;

    while (*ptr != '\0')
    {
        if (!('0' <= *ptr && *ptr <= '9'))
        {
            if (*ptr == '.')
            {
                ++point_counter;
                if (point_counter > 1)
                {
                    return 0;
                }
            }
            else 
            {
                return 0;
            }
        }
        ++ptr;
    }
    return 1;
}

int check_integer(const char* const arg)
{
    const char* ptr = arg;
    while (*ptr != '\0')
    {
        if (!('0' <= *ptr && *ptr <= '9'))
        {
            return 0;
        }
        ++ptr;
    }
    return 1;
}
