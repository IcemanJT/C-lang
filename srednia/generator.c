#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


int main()
{
    int max = 1000;
    int i =0;
    while(i<1000)
    {
        printf("%.10lf\n", randfrom(0,1));
        i++;
    }

    return 0;
}