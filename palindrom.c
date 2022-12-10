#include <stdio.h>

#define MAX_LEN 255

int StringCount(char t[])
{
    int i =0;
    while(t[i]!=0){
        i++;
    }
    return i-1;
}

void CopyString(char text_to_copy[],char text[]){
    int i=0;
    int j;
    j = StringCount(text_to_copy);
    while(text_to_copy[i]!=0){
        text[i]=text_to_copy[j];
        i++;
        j--;
    }
    text[i]=0;
}

int CompareTwoString(char a[],char b[])  
{  
    int flag=0,i=0; 
    while(a[i]!='\0' && b[i]!='\0')
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    } 
    if(a[i]!='\0'||b[i]!='\0')
       return 1;
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  


int main()
{
    char text[MAX_LEN];

    printf("Give a chain of chars to check:");
    scanf("%s", text);
    
    char t2[MAX_LEN];
    CopyString(text, t2);
    printf("Reversed text: %s\n", t2);

    if(CompareTwoString(text, t2)==0)
        printf("Palindrome\n");
    else
        printf("Not a palindrome");



    return 0;
}