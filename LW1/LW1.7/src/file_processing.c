#include "../include/file_processing.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int obtaining_number_base(const char* buffer)
{
    int current_base = 0;
    int target_base = 0;

    while (*buffer != '\0')
    {
        if ('A' <= toupper(*buffer) && toupper(*buffer) <= 'Z') 
        {
            current_base = toupper(*buffer) - 'A' + 10 + 1;
        }

        if ('0' <= *buffer && *buffer <= '9') 
        {
            current_base = *buffer - '0' + 0 + 1;
        }

        if (current_base > target_base)
        {
            target_base = current_base;
        }

        ++buffer;
    }

    return target_base;
}


long long decimal_from_any(const char* buffer, int base)
{
    char ch;
    long long number = 0;

    while (*buffer != '\0')
    {
        number = number * base + (isdigit(*buffer) ? *buffer - '0' + 0 : toupper(*buffer) - 'A' + 10);
	    ++buffer;
    }

    return number;
}


char* remove_leading_zeros(char* destination, char* source)
{
    char* prev_ch = source;
    ++source;

    while (*source == '0' && *prev_ch == '0')
    {
        prev_ch = source;
        ++source;
    }

    strcpy(destination, prev_ch);

    return destination;
}


void number_processing(FILE* file_in, FILE* file_out)
{
    int ch = 0;
    int prev_ch;
    int base = 0;
    int index = 0;
    const int BUFFSIZE = 64;
    long long number = 0;
    char buffer[BUFFSIZE];
    char updated_buffer[BUFFSIZE];
    char* ptr = buffer;

    do
    {
        ch = fgetc(file_in);
        if (index >= BUFFSIZE - 1) break;

        if (isalnum(ch))
        {
            *ptr++ = ch;
        }

        if ((!isalnum(ch) && isalnum(prev_ch)) || (isalnum(prev_ch) && ch == EOF))
        {
            *(ptr) = 0;
            ptr = buffer;
            index = 0;

            remove_leading_zeros(updated_buffer, buffer);
            base = obtaining_number_base(updated_buffer);
            number = decimal_from_any(updated_buffer, base);

            fprintf(file_out, "%s %d %lld\n", updated_buffer, base, number);
        }

        prev_ch = ch;
        ++index;
    } while (ch != EOF);
}


FILE* open_file(const char* path, const char* file_modes)
{
    FILE* file = fopen(path, file_modes);
    if (file == NULL)
    {
        printf("Impossible to open file: %s", path);
        exit(EXIT_FAILURE);
    }
    
    return file;
}


void file_processing(const char** argv)
{
    FILE* file_in = open_file(argv[1], "r");
    FILE* file_out = open_file(argv[2], "w+");

    number_processing(file_in,  file_out);

    fclose(file_in);
    fclose(file_out);
}