#pragma once

typedef enum 
{
    OPT_Q,
    OPT_M,
    OPT_T,
    OPT_INVALID,
} OptHandler;

OptHandler parse_args(const char* argv);
void value_processing(int argc, const char** argv);
void handle_q(double precision, double num1, double num2, double num3);
void handle_m(int num1, int num2);
void handle_t(double precision, double num1, double num2, double num3);
void handle_help(const char* message); // Receives a message and displays help information
void handle_message(const char* message); // Receives a message and displays message for user

