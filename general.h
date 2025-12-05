#ifndef GENH
#define GENH

#include <stdio.h>
#include <string.h>

typedef struct parmeters
{
    char sign;
    float val;
} parmeters;


void myFgets(char str[], int n);

void analyze(char* function, float lim, int is_not_line);

int is_pol(char* func, int len);

#endif