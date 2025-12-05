#ifndef PARMH
#define PARMH

#include <stdio.h>
#include <string.h>
#include "general.h"

#define FALSE 0
#define TRUE !FALSE


int is_char_not_defin(char ch);

int is_it_a_parm(char ch);

float gets_parm_v(char ch);

int get_list_len();

void add_parm();

#endif