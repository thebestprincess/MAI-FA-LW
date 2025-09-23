#pragma once

typedef enum OptHandler
{
    OPT_H,
    OPT_P,
    OPT_S,
    OPT_E,
    OPT_A,
    OPT_F,
    OPT_INVALID,
} OptHandler;

typedef void (*opt_handler) (const int);

void value_processing(const int, const char**);
void handle_message(const char* message);
void handle_help(const char* message);
int is_number(const char* str);
void handle_h(const int num);
void handle_p(const int num);
void handle_s(const int num);
void handle_e(const int num);
void handle_a(const int num);
void handle_f(const int num);
