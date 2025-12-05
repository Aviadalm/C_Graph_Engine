#include "visuals.h"
#include "prass_func.h"

int is_not_line = 0;
float scale = 0;

void add_to_board(float x, char graph[][SIDE_LEN], char* function) 
{
    float y = find_y(x, function);
    float slope = deriv(x, function);
    char ch = ' ';
    
    int xi = (int)roundf(x * scale) + IDK;
    int yi = (int)roundf(y * scale) + IDK;

    if(y < 0.5 && y > -0.5)
    {
        if(y < 0) yi--;
        else if(y > 0) yi++;
    }

    if (xi >= 0 && xi < SIDE_LEN && yi >= 0 && yi < SIDE_LEN) 
    {   
        if (slope == 0 && is_not_line) ch = 'O';
        else if (slope > 4 || slope < -4) ch = '|';
        else if (slope <= 4 && slope >= 0.9) ch = '/';
        else if (slope >= -4 && slope <= -0.9) ch = '\\';
        else ch = '_';
        graph[SIDE_LEN - 1 - yi][xi] = ch;
    }
}

void defult_board(char graph[][SIDE_LEN]) 
{
   for (int i = 0; i < SIDE_LEN; i++) 
    {
        for (int j = 0; j < SIDE_LEN; j++)
        {

            graph[i][j] = ' ';
        }
    } 
}

void set_board(char graph[][SIDE_LEN]) 
{
    for(int i = 0; i < SIDE_LEN; i++)
    {        
        if(graph[i][ZERO] != ' ')
        {
            if(graph[i][ZERO] == 'O') graph[i][ZERO] = '%';
            else graph[i][ZERO] = 'X';
        }
        else graph[i][ZERO] = '|';
    }
    for(int j = 0; j < SIDE_LEN; j++)
    {
        
        if(graph[ZERO][j] != ' ')
        {
            if(graph[ZERO][j] == 'O') graph[ZERO][j] = '%';
            else if(j != ZERO) graph[ZERO][j] = 'X';
        }
        else graph[ZERO][j] = '-';
    }
    if (graph[ZERO][ZERO] == '|') graph[ZERO][ZERO] = '+';
}

void print_graph(char graph[][SIDE_LEN]) 
{
    printf(BLACK);
    for(int i = 0; i < SIDE_LEN; i++)
    {       
        if(i == (ZERO)) printf("^\u2009");
        else if(i == (ZERO-1)) printf("  y");
        else 
        {
            printf("\u2009");
            printf(" ");
            
        }
    }
    printf(" \n");
    for (int i = 0; i < SIDE_LEN; i++) 
    {
        if(i == ZERO) printf("<");
        else if(i == (ZERO-1)) printf("x");
        else printf(" ");
        for (int j = 0; j < SIDE_LEN; j++) 
        {
            if (!(graph[i][j] == '-' || graph[i][j] == '+' || (j == ZERO && graph[i][j] == '|')))
            {
                if (graph[i][j] == 'X') printf(BLUE);
                else if  (graph[i][j] == '%') printf(PURPLE);
                else if  (graph[i][j] == 'O') printf(CYAN);
                else printf(RED);
            }           
            printf("%c", graph[i][j]);
            printf(BLACK);
            printf("\u2009");
        }
        if(i == ZERO) printf(">");
        else printf(" ");
        printf("\n");
    }
    for(int i = 0; i < SIDE_LEN; i++)
    {
        if(i == ZERO) printf(" v");
        else printf(" ");
        printf("\u2009");
    } 
    printf("\033[0m\n\n\n");
}

int print_menu(char graph[][SIDE_LEN], char function[], int start)
{
    float lim = 0, step = 0;
    int num = 0;
    if(start)
    {
        printf("set the first function: ");
        num = 1;
    }
    else
    {
        printf("1- set function\n2- add parameter\n3- show functions graph\n4- to analyze the function\nanything else - exit\n");
        scanf("%d", &num);
        getchar();
    } 
    switch (num)
    {
    case 1:
        defult_board(graph);
        printf("FUNCTIONS LIST:\nS - sin\nC - cos\nT - tan\nL - ln\nO - log\n\nVALUES LIST:\ne - e\n# - pi\n\n===================\n\n");
        printf("f(x) = ");
        myFgets(function, 256);
        is_not_line = is_pol(function, strlen(function));
        printf("Enter a value for scaleale factor - higher values zoom in, lower values zoom out.\n");
        scanf("%f", &scale);
        lim = (SIDE_LEN/scale)/2;
        step = 1/scale;
        for (float x = -lim; x <= lim; x += step) 
        {
            float y = find_y(x, function);
            if ((y * scale) + IDK >= 0 && (y * scale) + IDK < SIDE_LEN)
            {
                add_to_board(x, graph, function);
            }
        }
        add_to_board(0, graph, function);
        set_board(graph);
        break;
    
    case 2:
        add_parm();
        break;

    case 3:
        print_graph(graph);
        break;

    case 4:
        analyze(function, lim, is_not_line);
        break;
        
    default:
        printf("Goodbye!\n");
        getchar();
        return 1;
        break;
    }
    return 0;
}