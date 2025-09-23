#include "../include/opt_handler.h"


int main(int argc, const char** argv)
{
    if (argc < 2)
    {
        handle_help("Not enough arguments");
        return 1;
    }

    value_processing(argc, argv);
    return 0;
}