#include <stdio.h>
#include <math.h>


void Calc(char op){

float a, b;

if(op=='+'){
printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);
printf("a %c b = %f", op, a+b);
}

if(op=='*'){
printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);
printf("a %c b = %f", op, a*b);
}

if(op=='-'){
printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);
printf("a %c b = %f", op, a-b);
}

if(op=='/'){
printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);
if (b==0)
printf("Nie można, dzielić przez 0\n");
else
printf("a %c b = %f\n", op, a/b);
}

if (op=='p'){
printf("val a:\n");
scanf("%f", &a);
printf("val b:\n");
scanf("%f", &b);
printf("a^b = %.2lf\n", pow(a,b));    
}

if (op=='s'){
printf("val a:\n");
scanf("%f", &a);
printf("square root of a = %.2lf\n", sqrt(a));    
}

if (op=='l'){
printf("val a:\n");
scanf("%f", &a);
printf("log10 of a = %.2lf\n", log10(a));   
}

if (op=='c'){
printf("val a:\n");
scanf("%f", &a);
printf("for cos of a = %.2lf\n", cos(a));
}}

int main()
{

char c;
printf("z: +, -, *, /\n");
printf("for a^b, op -> p\n");
printf("for square root of a, op -> s\n");
printf("for log10 of a, op -> l\n");
printf("for cos of a, op -> c\n");


printf("Sign of operation:\n");
scanf(" %c", &c);

Calc(c);

return 0;
}