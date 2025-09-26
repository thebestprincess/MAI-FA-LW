#include "../include/opt_handler.h"

#include <stdlib.h>
#include <string.h>


void handle_message(const char* message);
void help_message(const char* message);


OptHandler parse_args(const char* argv)
{
    if (!argv || strlen(argv) < 2) 
    {
        return OPT_INVALID;
    }

    const char* ptr = argv;
    if (*ptr != '-' && *ptr != '/') 
    {
        return OPT_INVALID;
    }
    ptr++;

    int has_n = (*ptr == 'n');
    if (has_n) 
    {
        ptr++;
        if (*ptr == '\0') return OPT_INVALID;
    }

    switch (*ptr) 
    {
        case 'd': return has_n ? OPT_ND : OPT_D;
        case 'i': return has_n ? OPT_NI : OPT_I;
        case 's': return has_n ? OPT_NS : OPT_S;
        case 'a': return has_n ? OPT_NA : OPT_A;
        default:  
        {
            help_message("Wrong option");
            return OPT_INVALID;
        }
    }
}


void handle_function(const char* path_in, const char* path_out, void (*handle_opt) (FILE* file_in, FILE* file_out))
{
    FILE* file_in = fopen(path_in, "r");
    if (file_in == NULL)
    {
        perror("Error occured while opening file");
        exit(EXIT_FAILURE);
    }

    FILE* file_out;
    if (strcmp(path_out,"") == 0)   // for non-n options
    {
        size_t path_len = strlen(path_in);
        char new_path_out[path_len + 5];
        snprintf(new_path_out, sizeof(new_path_out), "%s_out", path_in);

        file_out = fopen(new_path_out, "a+");
        if (file_out == NULL)
        {
            perror("Error occured while opening destination file");
            fclose(file_in);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        file_out = fopen(path_out, "a+");

        if (file_out == NULL)
        {
            perror("Error occured while opening destination file");
            fclose(file_in);
            exit(EXIT_FAILURE);
        }
    }

    handle_opt(file_in, file_out);

    fclose(file_out);
    fclose(file_in);
}


void handle_d(FILE* file_in, FILE* file_out)
{    
    int ch;
    while ((ch = getc(file_in)) != EOF)
    {
        if (ch < '0' || ch > '9')
        {
            fputc(ch, file_out);
        }
    }
}


void handle_i(FILE* file_in, FILE* file_out)
{
    int ch;
    int counter = 0;

    while ((ch = getc(file_in)) != EOF)
    {
        if (ch == '\n')
        {
            fprintf(file_out, "%d\n", counter);
            counter = 0;
        }
        else 
        {
            if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
            {
                ++counter;
            }
        }
    }

    fprintf(file_out, "%d", counter);
}


void handle_s(FILE* file_in, FILE* file_out)
{
    int ch;
    int counter = 0;

    while ((ch = getc(file_in)) != EOF)
    {
        if (ch == '\n')
        {
            fprintf(file_out, "%d\n", counter);
            counter = 0;
        }
        else 
        {
            if (!(('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')  
                || ('0' <= ch && ch <= '9') || (ch == ' ')))
            {
                ++counter;
            }
        }
    }

    fprintf(file_out, "%d", counter);
}


void int_to_hex(char* buff, const int buff_size, int num)
{
    char* ptr = buff + buff_size - 1;
    int base = 16, r;

    while(num)
    {
        r = num % base;
        if (r > 9) *ptr-- = r - 10 + 'A';
        else *ptr-- = r + '0';
        num /= 16;
    }

    buff[2] = '\0';

}


void handle_a(FILE* file_in, FILE* file_out)
{
    int ch;
    int counter = 0;
    const int SIZE = 2;
    char buff[SIZE];

    while ((ch = getc(file_in)) != EOF)
    {
        if (!('0' <= ch && ch <= '9') && ch != '\n')
        {
            int_to_hex(buff, SIZE, ch);
            fprintf(file_out, "%s", buff);
        }
        else
        {
            fputc(ch, file_out);
        }
    }
}


void help_message(const char* message)
{
    printf("Notification: %s\n", message);
    printf("You should use: ./program  [-d or /d] [-i or /i] [-s or /s] [-a or /a]\n");
    printf("    -[n]d <path> [<path>]   - exclude Arabic numerals\n");
    printf("    -[n]i <path> [<path>]   - number of Latin letters in the file\n");
    printf("    -[n]s <path> [<path>]   - Number of characters other than the\n"); 
    printf("                              Latin alphabet, Arabic numerals, and spaces\n");
    printf("    -[n]a <path> [<path>]   - replace non-numeric characters with ASCII code\n");
    printf("                              written in base 16.\n");
}


void handle_message(const char* message)
{
    printf("Notification: %s\n", message);
}


void option_processing(const int argc, const char **argv)
{
    if (argc < 3)
    {
        help_message("Not enough args for executing");
        return;
    }
    else if (argc > 4)
    {
        help_message("Too many args for executing");
        return;
    }

    handler handle_option[4] = 
    {
        handle_d,
        handle_i,
        handle_s,
        handle_a,
    };


    OptHandler opt = parse_args(argv[1]);

    if (opt == OPT_INVALID)
    {
        return;
    }
    else 
    {
        if (opt >= OPT_ND)
        {
            if (argc != 4)
            {
                handle_message("Output file path not passed");
                exit(EXIT_FAILURE);
            }
            handle_function(argv[2], argv[3], handle_option[opt - 4]);
        }
        else 
        {
            handle_function(argv[2], "", handle_option[opt]);
        }
    }
    
}