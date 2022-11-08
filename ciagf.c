#include <stdio.h>

long int fib(long int n){
    if (n==0)
        return 0;
    if (n<=2 && n>0)
        return 1;
    else 
        return fib(n-1)+fib(n-2);
}


int main()
{
/**
int i, n;
int x1=0, x2=1;
int nextx = x1 + x2;

printf("How many numbers to display:\n");
scanf("%d", &n);

printf("%d, %d", x1, x2);

for(i =3; i<=n; i++){
printf(", %d", nextx);
x1 = x2;
x2 = nextx;
nextx = x1 + x2;
}

printf("\n");
*/

long int x;
printf("Which element of Fibonacci sequence to display:");
scanf("%ld",&x);
printf("Fib[%ld] = %ld\n", x, fib(x));

return 0;
}
