#include <stdio.h>
#include <string.h>

#define MAX_LEN 255
#define ASCII_R 82
#define ASCII_D 68

int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

void Decimal2R(int num){
    int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int i = 0;
 
    while(num){
        while(num/decimal[i]){
            printf("%s",symbol[i]);
            num -= decimal[i];
        }
        i++;
    }
}

int Roman2D(char str[])
{
    int res = 0;
 
    for (int i = 0; i < strlen(str); i++)
    {
        int s1 = value(str[i]);
 
        if (i + 1 < strlen(str))
        {
            int s2 = value(str[i + 1]);
 
            if (s1 >= s2)
            {
                res = res + s1;
            }
            else
            {
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}


int main()
{
    char flag;
    int x, op;
    char t[MAX_LEN]={0};

    printf("\nDecimal to Roman ---> D\n");
    printf("Roman to Decimal ---> R\n");
    printf("Operation: ");
    scanf("%c", &flag);
    op = flag;



    if (op==ASCII_D){
    printf("\nDecimal number to convert: ");
    scanf("%d", &x);

    Decimal2R(x);
    printf("\n");
    }


    if (op==ASCII_R){
    printf("\nRoman number to convert: ");
    scanf("%s", t);

    printf("%d\n", Roman2D(t));
    }

    
    if (op!=ASCII_D && op!=ASCII_R)
        printf("Podano bledne instrukcje.");
    

    return 0;
}