#include "parametrs.h"
#include "prass_func.h"
#include "visuals.h"

#define EPSILON 0.0001f
#define EPSILON2 0.001f

int main() 
{
    char graph[SIDE_LEN][SIDE_LEN] = {'\0'};
    char function[256];
    int to_stop = 0;

    print_menu(graph, function, 1);

    while (!to_stop)
    {
        to_stop = print_menu(graph, function, 0);
    } 
    getchar();
    return 0;
}
