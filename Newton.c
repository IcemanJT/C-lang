#include <stdio.h>

/* program dziala dla pewnego zakresu liczb */



/* silnia_10.c */
int fact(double n){
    if (n>1)
    return n*fact(n-1);
    if (n<=1)
        return 1;
}


int main()
{
    double n, k, result;

    printf("Dwumian Newtona:(n!)/(k!(n-k)!\n");

    printf("Give n: ");
    scanf("%lf", &n);

    printf("Give k: ");
    scanf("%lf", &k);

    result = fact(n)/(fact(k)*fact(n-k));

    printf("%.1lf!/(%.1lf)!*(%.lf)!= %.1lf", n, k, n-k, result);

    return 0;
}