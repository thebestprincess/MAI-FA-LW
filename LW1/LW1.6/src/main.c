#include "../include/calculation.h"
#include "../include/opt_handler.h"


int main(const int argc, const char** argv)
{
    double precision = get_precision(argc, argv);
    all_calculations(precision);

    return 0;
}