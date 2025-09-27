#include "../include/opt_processing.h"
#include "../include/file_processing.h"


int main(int argc, const char** argv)
{
    args_processing(argc);

    file_processing(argv);

    return 0;
}