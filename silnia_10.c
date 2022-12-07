#include <stdio.h>


/* rekurencja */


int fact(int n){
    if (n>1)
    return n*fact(n-1);
    if (n<=1)
        return 1;
}


/* iteracja */

/*
int fact(int n){
    int suma = 1;
    for(int i=n; i>0;i--){
        suma*=i;
    }

    return suma;
}
*/


/* 
int - 13!
long - 20!
unsigned long int - 20!
float - do 13! poprawnie, na 34 kończy liczenie
double - do 22! poprawnie, kończy liczenie na 170!
long double - do 25! poprawnie, kończy liczenie na ok. 1750!
*/

int main(){
    int x;
    printf("Podaj x:\n");
    scanf("%d", &x);
    printf("%d! = %d\n", x, fact(x));
    return 0; 
}