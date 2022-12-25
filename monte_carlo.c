#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main(){

srand(time(NULL));

int count, i, n;
double pi, x, y, num;
count = 0;
pi=0;

printf("How many points: ");
scanf("%d", &n);

printf("RAND_MAX = %d\n", RAND_MAX);

for(i=1; i<=n;i++)
{
x=randfrom(0, 1);
y=randfrom(0, 1);
num = (x*x)+(y*y);
if(num <= 1)
{
    count++;
}
}

pi = (double) count / n * 4;
printf("Pi equals = %lf",pi);

}