#include "parametrs.h"

parmeters parms[88] = { 0 };
char def_signs[104] = {"XxSCTLOe#-+()^/*1234567890"};

int is_char_not_defin(char ch)
{
    int len = strlen(def_signs);
    for(int i = 0; i < len; i++)
    {
        if(def_signs[i] == ch) return FALSE;
    }
    return TRUE;
}


float gets_parm_v(char ch)
{
    int len = get_list_len();
    for(int i = 0; i < len; i++)
    {
        if(parms[i].sign == ch) return parms[i].val;
    }
    return TRUE;
}

int get_list_len()
{
    int count = 0;
    for (int i = 0; i < 88; i++) 
    {
        if (parms[i].sign != '\0') count++;
    }
    return count;
}

void add_parm()
{
    char ch = ' ';
    int len = get_list_len();
    printf("Enter the sign of the paramter: ");
    do
    {
        scanf("%c", &ch);
        if(!(is_char_not_defin(ch)))
        {
            printf("This char is taken try another one\n");
        }
    }
    while (!(is_char_not_defin(ch)));
    parms[len].sign = ch;
    printf("Enter the value: ");
    scanf("%f", &(parms[len].val));
    len = strlen(def_signs);
    def_signs[len] = ch;
    getchar();
}

int is_it_a_parm(char ch)
{
    int len = get_list_len();
    for(int i = 0; i < len; i++)
    {
        if(parms[i].sign == ch) return TRUE;
    }
    return FALSE;
}