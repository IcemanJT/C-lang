#include <stdio.h>



int main()
{
float a, b, x0;
printf("podaj a: \n");
scanf("%f", &a);

printf("podaj b: \n");
scanf("%f", &b);

x0=((-b)/a);

printf("Miejsce zerowe to: %.2f\n", x0);

return 0;
}
