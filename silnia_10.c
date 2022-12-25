#include <stdio.h>
#include <stdlib.h>

#define IMPROPIET_USAGE 1
#define WRONG_ARGS 2
#define RECCURSION 82
#define ITERATION 73


/* rekurencja */

int fact_rec(int n){
    if (n>1)
    return n*fact_rec(n-1);
    if (n<=1)
        return 1;
}


/* iteracja */

int fact_inter(int n){
    int suma = 1;
    for(int i=n; i>0;i--){
        suma*=i;
    }

    return suma;
}

/* 
int - 13!
long - 20!
unsigned long int - 20!
float - do 13! poprawnie, na 34 kończy liczenie
double - do 22! poprawnie, kończy liczenie na 170!
long double - do 25! poprawnie, kończy liczenie na ok. 1750!
*/

int main(int argc, char* argv[])
{
    int n, metod;
    metod = RECCURSION;

    if (argc > 3 || argc < 2){
        printf("Usage: silnia (int):<n> {-M: R/I}\n");
        return IMPROPIET_USAGE;
    }
    if(argc == 3)
    {
        metod = argv[2][0];
    }

    #ifdef LOG
    int i;

    for (i=0;i<argc;i++)
        printf("argv[%d]: %s\n", i, argv[i]);

    printf("argc: %d\n", argc);
    printf("metod = %d\n", metod);
    printf("n = %d\n", n);
    #endif

    n = atoi(argv[1]);

    if (metod == RECCURSION)
    {
        printf("%d", fact_rec(n));
        return 0;
    }
    if(metod == ITERATION)
    {
        printf("%d", fact_inter(n));
        return 0;
    }
    else
    {
        printf("Wrong main args.");
        return WRONG_ARGS;
    }


    return 0; 
}