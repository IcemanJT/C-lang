#include <stdio.h>
#include <math.h>

int main()
{
float a, b;
char z;

printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);

printf("z: +, -, *, /\n");
printf("for a^b, z -> p\n");
printf("for square root of a, z -> s\n");
printf("for log10 of a, z -> l\n");
printf("for cos of a, z -> c\n");

printf("Podaj znak operacji:\n");
scanf(" %c", &z);


if(z=='+')
printf("a %c b = %f", z, a+b);


if(z=='*')
printf("a %c b = %f", z, a*b);


if(z=='-')
printf("a %c b = %f", z, a-b);


if(z=='/'){
if (b==0)
printf("Nie można, dzielić przez 0\n");
else
printf("a %c b = %f\n", z, a/b);
}

if (z=='p')
printf("a^b = %.2lf\n", pow(a,b));    

if (z=='s')
printf("square root of a = %.2lf\n", sqrt(a));    

if (z=='l')
printf("log10 of a = %.2lf\n", log10(a));   

if (z=='c')
printf("for cos of a = %.2lf\n", cos(a));


return 0;
}
