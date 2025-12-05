#include "prass_func.h"

char* input_ptr;

float x_value = 0;

void skip_whitespace() 
{
    while (isspace(*input_ptr)) input_ptr++;
}

float parse_primary() 
{
    skip_whitespace();
    if (*input_ptr == '(') 
    {
        input_ptr++;
        float val = parse_number();
        skip_whitespace();
        if (*input_ptr == ')') input_ptr++;
        return val;
    }
    else if (*input_ptr == 'X' || *input_ptr == 'x') 
    {
        input_ptr++;
        return x_value;
    }
    else if(*input_ptr == 'e')
    {
        input_ptr++;
        return E;
    }
    else if (*input_ptr == 'L') 
    {
        input_ptr++;
        float val = parse_primary();
        return logf(val);
    }
    else if (*input_ptr == 'O') 
    {
        input_ptr++;
        float val = parse_primary();
        return log(val);
    }
    else if (*input_ptr == 'S') 
    {
        input_ptr++;
        float val = parse_primary();
        return sin(val);
    }
    else if (*input_ptr == 'C') 
    {
        input_ptr++;
        float val = parse_primary();
        return cos(val);
    }
    else if (*input_ptr == 'T') 
    {
        input_ptr++;
        float val = parse_primary();
        return tan(val);
    }
    else if (*input_ptr == '#') 
    {
        input_ptr++;
        return PI;
    }
    else if(is_it_a_parm(*input_ptr))
    {
        input_ptr++;
        return gets_parm_v(*input_ptr);
    }         
    else 
    {
        char* endptr;
        float val = strtof(input_ptr, &endptr);
        input_ptr = endptr;
        return val;
    }
}

float parse_power() 
{
    float left = parse_primary();
    skip_whitespace();
    while (*input_ptr == '^') 
    {
        input_ptr++;
        float right = parse_power();
        left = powf(left, right);
        skip_whitespace();
    }
    return left;
}

float parse_term() 
{
    float left = parse_power();
    skip_whitespace();
    while (*input_ptr == '*' || *input_ptr == '/') 
    {
        char op = *input_ptr;
        input_ptr++;
        float right = parse_power();
        if (op == '*') left *= right;
        else left /= right;
        skip_whitespace();
    }
    return left;
}

float parse_number() 
{
    float left = parse_term();
    skip_whitespace();
    while (*input_ptr == '+' || *input_ptr == '-') 
    {
        char op = *input_ptr;
        input_ptr++;
        float right = parse_term();
        if (op == '+') left += right;
        else left -= right;
        skip_whitespace();
    }
    return left;
}

float evaluate_function(char* function, float x) 
{
    input_ptr = function;
    x_value = x;
    return parse_number();
}

float derivative(char* function, float x)
{
    float h = 0.0001f;
    float y1 = evaluate_function(function, x - h);
    float y2 = evaluate_function(function, x + h);
    return (y2 - y1) / (2 * h);
}

float find_y(float x, char* function) 
{
    return evaluate_function(function, x);
}

float deriv(float x, char* function) 
{
    return derivative(function, x);
}
