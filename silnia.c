#include <stdio.h>

int main()
{

int n;
long int result;
printf("Podaj n:\n");
scanf("%ld", &n);
result = 1;


while (n>1){
result *=n;
n--;
}

printf("n! = %ld\n", result);

return 0;
}
