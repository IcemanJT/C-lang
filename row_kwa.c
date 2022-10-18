#include<stdio.h>



int main()
{
int a, b, c, delta;
float pierw, x1, x2;

printf("podaj a:\n");
scanf("%d", &a);
printf("podaj b:\n");
scanf("%d", &b);
printf("podaj c:\n");
scanf("%d", &c);

delta = (b^2)-(a*c*-4);


if (delta < 0)
printf("Nie ma miejsc zerowych\n");


if (delta == 0){
x1 = (-b)/(2*a);
printf("Miejsce zerowe to: %.2f\n", x0);
}

if (delta > 0){
pierw = delta^(1/2);
x1=((-b)+pierw)/(2*a);
x2=((-b)-pierw)/(2*a);
printf("Miejsca zerowe to: %.2f i %.2f\n", x1, x2);
}

return 0;
}
