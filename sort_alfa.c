#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USAGE_ERROR 1

#define ASCII_R 82

#define N_MAX 20
#define MAX_STR 10

// dziala dla liczb i znakow

void SortAlfa(char *array[], int num_of_el)
{
    int i, j;
    char temp[MAX_STR];

    for(i=0; i<num_of_el; i++)
    {
        for(j=0; j<num_of_el-1-i; j++)
        {
            if(strcmp(array[j], array[j+1]) > 0)
            {
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
}

void ReverseArray(char* arr[], int n)
{
    char* temp;
  
    int j = n - 1;
    for (int i = 0; i < j; i++)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}


int main(int narg, char *argv[])
{
    char *data[N_MAX];
    int i, n;
    char c;
    int op;
    
    if ( narg > 2)
    {
        printf("Usage: <main> {default - alfabetical} {R <- for reversed}\n");
        return USAGE_ERROR;
    }
    if ( narg == 2)
    {
        c = argv[1][0];
        op = c;
        if (op != ASCII_R)
        {
            printf("For reversed alfabetical order: <main> R\n");
            return USAGE_ERROR;
        }
    }


    for (i=0; i<N_MAX; i++)
    {
        data[i]=(char*)malloc(MAX_STR*sizeof(char));
    }

    n = 0;
    i = 0;
    while(scanf("%s", data[i]) != EOF)
    {
        i++;
        n++;
    }
    
    SortAlfa(data, n);

    if (op == ASCII_R)
    {
        ReverseArray(data, n);
    }


    printf("\nArray:\n");

    for(i = 0; i<n; i++)
    {
        printf("%s\n", data[i]);
    }
    
    
    for (i=0; i<N_MAX; i++)
    {
        free(data[i]);
    }


    return 0;
}