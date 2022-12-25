#include <stdio.h>

#define MAX_LEN 255

/* program liczacy n! dla bardzo duzych n */

void factorial(int n){

    int x, a, num;
    x = 2;
    a = 0;
    num = 0; 

    int number[MAX_LEN] = {0};  
    number[0] = 1;

    int lenght = 1;

    while(x <= n)   
    {  
        a = 0;  
        num = 0;  
        while(a < lenght)  
        {  
            number[a] *= x;  
            number[a] += num;  
            num = number[a] / 10;  
            number[a] %= 10;  
            a++;  
        }  
        while(num != 0)  
        {  
            number[lenght] = num % 10;  
            num = num / 10;  
            lenght++;  
        }  
        x++;  
    }  
    lenght--;  
    printf("\nFactorial of %d is = ", n);  
    while(lenght >= 0)  
    {  
        printf("%d", number[lenght]);  
        lenght--;  
    }  
}



int main()
{
    int a;
    printf("Podaj liczbe: ");
    scanf("%d", &a);

    factorial(a);

    return 0;
}