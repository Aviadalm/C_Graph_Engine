#ifndef PRSH
#define PRSSH

#include "parametrs.h"
#include "general.h"

#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define E 2.71828182845904523536
#define PI 3.14159265358979323846

void skip_whitespace();

float parse_number();

float parse_primary();

float parse_power();

float parse_term();

float parse_number();

float evaluate_function(char* function, float x);

float derivative (char* function, float x);

float find_y(float x, char* function);

float deriv(float x, char* function);

#endif