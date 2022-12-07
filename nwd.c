#include <stdio.h>
/*
int nwd(int x, int y){
    int c;
    while(y != 0){
        c = x%y;
        x = y;
        y = a;
    }
    return a;
}
*/
int nwd(int x, int y){
    if (y==0)
        return x;
    else
        return nwd(y, (x%y));
}



int main()
{
    
    int a, b;
    printf("Podaj a:\n");
    scanf("%d", &a);
    printf("Podaj b:\n");
    scanf("%d", &b);    
    printf("Nwd(a, b) = %d\n", nwd(a,b));
    return 0;
}