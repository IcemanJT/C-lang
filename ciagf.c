#include <stdio.h>

int main()
{
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

return 0;
}
