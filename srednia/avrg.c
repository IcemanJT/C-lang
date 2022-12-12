#include <stdio.h>
#include <math.h>

#define MAX_LEN 1000

/* Program wymaga podania ilosci liczb na wejsciu,
ktora nalepszy przypisac stalej MAX_LEN */



void FillArray(double t[])
{
    double x;
    int i =0;
    while(scanf("%lf", &x)>0)
    {   
        t[i]=x;
        i++;
        if (i==MAX_LEN)
        {
            break;
        }
    }
}

double SumArray(double t[])
{
    double result = 0;
    int i;
    for(i=0;i<MAX_LEN;i++)
        result += t[i];

    return result;
}

double AritAvrg(double t[])
{
    double result;
    result = SumArray(t)/(double)MAX_LEN;
    
    return result;
}

double StdDev(double t[])
{
    int i;
    double result, x;
    x = AritAvrg(t);
    result = 0;

    for (i=0; i<MAX_LEN;i++)
    {
        result += pow((t[i]-x),2);
    }

    result = sqrt((result/(double)MAX_LEN));

    return result;
}


int main()
{
    
    double t[MAX_LEN]={0};

    printf("Average and Standard Deviation\n");
    printf("for %d numbers.\n\n", MAX_LEN);

    FillArray(t);


    printf("Average: %.5lf\n", AritAvrg(t));
    printf("Stanrd Deviation: %.5lf\n", StdDev(t));



    return 0;
}