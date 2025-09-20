#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../include/calc_pi.h"

double calc_gamma_lim(const double eps);
double calc_gamma_row(const double eps, const double pi);
double calc_gamma_equation(const double eps);