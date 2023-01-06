#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 40

double S[MAX_LEN] = {0};
int count = 0; // number of elements in container
int *ptr;

char IsOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double MakeNumber(char text[], int i)
{
    double result;
    int buff;
    buff = 10;

    while (isdigit(text[i + 1]))
    {
        i++;
    }

    result = (double)((text[i] - '0'));
    *ptr = i;
    i--;
    
    while (isdigit(text[i]))
    {
        result += (double)((text[i] - '0') * buff);
        buff *= 10;
        i--;
    }

    printf("%.2f\n", result);

    return result;
}

double pop()
{
    double a;

    a = S[count-1];
    S[count-1] = 0;
    count--;

    return a;
}

void push(double a)
{
    S[count] = a;
    count++;
}

void Prog(char text[])
{
    double x, y, result;
    char c;
    char *pointer;
    char temp[MAX_LEN];
    

    for (int i = 0; i < strlen(text); i++)
    {
        c = text[i];

        if (isdigit(c))
        {   
            int j = 0;
            while (isdigit(c))
            {
                temp[j]=c;
                j++;    
                i++;
                c = text[i];
            }
            result = (double)(strtol(temp, &pointer , 10));
            memset(temp, 0, MAX_LEN);
            push(result);
        }
        if (IsOperand(c))
        {
            if (c == '+')
            {
                x = pop();
                y = pop();
                push(x + y);
                
            }
            if (c == '-')
            {
                y = pop();
                x = pop();
                push(x - y);
                
            }
            if (c == '*')
            {
                x = pop();
                y = pop();
                push(x * y);
            }
            if (c == '/')
            {
                y = pop();
                x = pop();
                push(x / y);
            }
            if (c == '=')
            {
                printf("Result of an equation: %.2f\n", S[count-1]);
                printf("New equation: ");
                count = 0;
            }
        }
    }
}

int main()
{
    char text[MAX_LEN];

    printf("Separate every number and operand with space.\n");
    printf("Possible operations: +, -, *, /.\n\n");


    printf("Equation: ");
    while( scanf("%[^\n]%*c", text)){
    Prog(text);
    }

    return 0;
}
