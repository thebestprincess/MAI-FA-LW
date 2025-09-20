#include <stdio.h>

#include "../include/validator.h"
#include "../include/calculate_eps.h"
#include "../include/calc_e.h"
#include "../include/calc_pi.h"
#include "../include/calc_ln2.h"
#include "../include/calc_sqrt2.h"
#include "../include/calc_gamma.h"





int main()
{
    printf("Enter the desired precision from 0 to 10: ");
    int precision;
    number_check(&precision);
    double eps = calculate_epsilon(precision);
    double e_lim = calc_e_lim(eps); 
    double e_row = calc_e_row(eps);
    double e_equation = calc_e_equation();
    printf("\n");

    double pi_lim = calc_pi_lim(eps); 
    double pi_row = calc_pi_row(eps);
    double pi_equation = calc_pi_equation();
    printf("\n");


    double ln2_lim = calc_ln2_lim(eps); 
    double ln2_row = calc_ln2_row(eps);
    double ln2_equation = calc_ln2_equation();
    printf("\n");


    double sqrt2_lim = calc_sqrt2_lim(eps);
    double sqrt2_row = calc_sqrt2_row(eps); 
    double sqrt2_equation = calc_sqrt2_equation();
    printf("\n");


    double gamma_lim = calc_gamma_lim(eps); 
    double gamma_row = calc_gamma_row(eps, pi_equation);
    double gamma_equation = calc_gamma_equation(eps);

    return 0;
}