#pragma once

#include <stdio.h>


typedef enum
{
    OPT_INVALID = -1,
    OPT_D = 0,
    OPT_I,
    OPT_S,
    OPT_A,
    OPT_ND,
    OPT_NI,
    OPT_NS,
    OPT_NA,
} OptHandler;

typedef void (*handler) (FILE* path_in, FILE* path_out);

void option_processing(const int argc, const char** argv);