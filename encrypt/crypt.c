#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WRONG_ARGS 1
#define WRONG_FILE 2
#define FILE_ERROR 3
#define MAX_LEN 255


void Encrypt(FILE *fi, FILE *fo)
{
    char password[MAX_LEN];
    int pass_len, j;
    char c;
    j = 1;

    printf("Give password to use to crypt: ");
    scanf("%s", password);
    pass_len = strlen(password);

    //getting chars from file 
    while ((c = getc(fi)) != EOF)
    {
        c ^= password[j % pass_len];
        //putting crypted chars to temp file
        putc(c, fo);
        j++;
    }
}

int main(int narg, char *argv[])
{
    FILE *file1;
    FILE *file2 = tmpfile();
    //generating temprorary name for file2
    char temp[L_tmpnam + 1];
    tmpnam(temp);

    if (narg < 2 || narg > 2)
    {
        printf("Usage: main <filename.ext>\n");
        return WRONG_ARGS;
    }
    file1 = fopen(argv[1], "rb");

    if (file1 == NULL)
    {
        printf("Wrong file name or ext.\n");
        return WRONG_FILE;
    }

    file2 = fopen(temp, "wb");

    if (file2 == NULL)
    {
        printf("Failed to create or open a file.\n");
        return FILE_ERROR;
    }

    Encrypt(file1, file2);

    fclose(file1);
    fclose(file2);
    unlink(argv[1]);
    rename(temp, argv[1]);
    return 0;
}