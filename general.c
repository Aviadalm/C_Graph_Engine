#include "general.h"
#include "visuals.h"
#include <string.h>

void myFgets(char str[], int n)
{
    fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}

int is_pol(char* func, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(func[i] == 'X' || func[i] == 'x')
        {
            return 1;
        }
    }
    return 0;
}




void analyze(char* function, float lim, int is_not_line)
{
    printf("%f\n", lim);
    int flag = 0;
    float y = 0;

    printf(RED "Extreme points:\n" LIGHT_RED);
    for(float x = -lim; x <= lim && is_not_line; x += 0.25)
    {
        if(deriv(x, function) == 0)
        {
            printf("    (%f, %f)\n", x, find_y(x, function));
            flag = 1;
        }
    }
    if(!flag) printf("No extreme points in the range");
    printf("\n");

    flag = 0;
    printf(RED "X-intercepts:\n" LIGHT_RED);
    for(float x = -lim; x <= lim; x += 0.25)
    {
        y = find_y(x, function);
        if(y == 0)
        {
            printf("    (%f, %f)\n", x, y);
            flag = 1;
        }
    }
    if(!flag) printf("No x-intercepts in the range");
    printf("\n");

    flag = 0;
    printf(RED "Y-intercept:\n" LIGHT_RED);
    y = find_y(0, function);
    if(!isnan(y) && !isinf(y))
    {
        printf("    (0.000000, %f)\n", y);
        flag = 1;
    }
    if(!flag) printf("No y-intercept in the range");
    printf("\n");
}
