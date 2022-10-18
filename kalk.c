#include <stdio.h>
#include <math.h>

int main()
{
float a, b;
char z;

printf("podaj a:\n");
scanf("%d", &a);
printf("podaj b:\n");
scanf("%d", &b);

printf("Podaj znak operacji:\n");
scanf(" %c", &z);


if(z=='+')
printf("a %c b = %d", z, a+b);


if(z=='*')
printf("a %c b = %d", z, a*b);


if(z=='-')
printf("a %c b = %d", z, a-b);


if(z=='/'){
if (b==0)
printf("Nie można, dzielić przez 0\n");
else
printf("a %c b = %d\n", z, a/b);
}


if (




return 0;
}
