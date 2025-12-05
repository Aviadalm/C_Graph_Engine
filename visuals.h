#ifndef VISH
#define VISH

#include "prass_func.h"
#include "general.h"

#define SIDE_LEN 101
#define ZERO 50
#define IDK ZERO

#define RED "\e[1;31m"
#define BLUE "\033[1;34;107m"
#define CYAN "\033[1;36;107m"
#define PURPLE "\033[0;35;107m"
#define BLACK "\033[0;30;107m"
#define LIGHT_RED "\x1b[38;2;173;173;163m"

void add_to_board(float x, char graph[][SIDE_LEN], char* function);

void defult_board(char graph[][SIDE_LEN]);

void set_board(char graph[][SIDE_LEN]);

void print_graph(char graph[][SIDE_LEN]);

int print_menu(char graph[][SIDE_LEN], char function[], int start);

#endif