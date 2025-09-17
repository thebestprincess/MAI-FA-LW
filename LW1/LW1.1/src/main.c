#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/flags_handler.h"


int main(const int argc, const char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if ((i + 1 != argc) && is_number(argv[i + 1]))
        {
            int number = atoi(argv[i + 1]);
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "/h") == 0)
            {
                h_flag(number);
            }
            else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "/p") == 0)
            {
                p_flag(number);
            }
            else if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "/s") == 0)
            {
                s_flag(number);
            }
            else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "/e") == 0)
            {
                e_flag(number);
            }
            else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "/a") == 0)
            {
                a_flag(number);
            }
            else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "/f") == 0)
            {
                f_flag(number); 
            }
            ++i;
        }
        else
        {
            printf("You have not specified the number!\n");
        }
    }
    return 0;
}