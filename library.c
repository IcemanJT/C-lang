#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 20 // max chars for names, surnames, titles... etc.
#define MAX_BORROW 2 // max books you can borrow at a time
#define MAX_PEOPLE 2 // max people in data base
#define MAX_BOOKS 10 // max books person can have in records

// making sure every id is unique
int id_check[MAX_PEOPLE];
char title_check[MAX_PEOPLE*MAX_BOOKS][MAX_LEN];
int n=0;
int x=0;

typedef struct
{

    char title[MAX_LEN];
    char author[MAX_LEN];
    char borrow_date[MAX_LEN];
    char return_date[MAX_LEN];
    int status;

}book;

typedef struct
{

    int id;
    char name[MAX_LEN];
    char surname[MAX_LEN];
    int count_books;
    int borrowed;
    book book[MAX_BOOKS];

}Library;

// checks if int is an element of array of ints
int ElementCheck(int arr[], int x)
{     
    int isElementPresent = 0;
     
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
        {
            isElementPresent = 1;
            break;
        }
    }
    return isElementPresent;
}

int IsDigits(char text[])
{
    for (int i=0; i<strlen(text); i++)
    {
        if (isdigit(text[i])==0)
        return 0;
    }

    return 1;
}

int CreatId()
{
    char temp[MAX_LEN];
    int id, i;

    printf("ID should be a digit.\n");
    printf("ID to creat: ");
    fgets(temp, 20, stdin);
    temp[strcspn(temp, "\n")] = 0;
    while(IsDigits(temp)==0)
    {
        printf("ID should be a digit.\n");
        printf("New ID: ");
        fgets(temp, 20, stdin);
        temp[strcspn(temp, "\n")] = 0;
    }
    id = atol(temp);
    for (i=0; i<n; i++)
    {
        if (id_check[i]==id)
        {
            while (id_check[i]==id || IsDigits(temp)==0)
            {
                printf("Invalid ID.\n");
                printf("New ID: ");
                fgets(temp, 20, stdin);
                temp[strcspn(temp, "\n")] = 0;
                id = atol(temp);
            }
        }
    }
    return id;
}

int IDValidate()
{
    char temp[MAX_LEN];
    int id, temp2;

    fgets(temp, MAX_LEN, stdin);
    temp[strcspn(temp, "\n")] = 0;
    while(IsDigits(temp)==0)
    {
        printf("ID should be a digit.\n");
        printf("ID: ");
        fgets(temp, MAX_LEN, stdin);
        temp[strcspn(temp, "\n")] = 0;
    }
    temp2 = atol(temp);
    while (ElementCheck(id_check ,temp2)==0 || IsDigits(temp)==0)
    {
        printf("ID doesnt exist.\n");
        printf("ID: ");
        fgets(temp, MAX_LEN, stdin);
        temp[strcspn(temp, "\n")] = 0;
        temp2 = atol(temp);
    }
    id = temp2;
    return id;
}

void AddPerson(Library people[])
{   
    if (n >= MAX_PEOPLE)
    {
        printf("You cant add more people.\n");
    }
    else
    {
    int id;
    Library person;

    id = CreatId();
    id_check[n]=id;
    person.id = id;

    printf("Name: ");
    fgets(person.name, MAX_LEN, stdin);
    person.name[strcspn(person.name, "\n")] = 0;

    printf("Surname: ");
    fgets(person.surname, MAX_LEN, stdin);
    person.surname[strcspn(person.surname, "\n")] = 0;

    person.count_books = 0;
    person.borrowed = 0;

    people[n]=person;

    n++;
    }
}

void BorrowBook(Library people[])
{   
    int id;
    Library person;
    book book1;

    printf("ID of person borrowing a book: ");
    id = IDValidate();
    for (int i =0; i < n; i++)
    {
        person = people[i];
        if (person.id==id)
        {
            printf("\nAdding book.\n");
            if(person.borrowed == MAX_BORROW)
            {
                printf("You cant borrow more books.\n");
                break;
            }
            else
            {
            person.count_books += 1;
            person.borrowed +=1;
            



            printf("Title: ");
            fgets(book1.title, MAX_LEN, stdin);
            book1.title[strcspn(book1.title, "\n")] = 0;
            strcpy(title_check[x],book1.title);
            x++;

            printf("Author: ");
            fgets(book1.author, MAX_LEN, stdin);
            book1.author[strcspn(book1.author, "\n")] = 0;

            printf("Borrow date: ");
            fgets(book1.borrow_date, MAX_LEN, stdin);
            book1.borrow_date[strcspn(book1.borrow_date, "\n")] = 0;

            book1.status = 0;
            
            person.book[(person.count_books-1)]=book1;
            people[i]= person;
            }
        }
    }
    printf("\n");
}

int ValidTitle(char tit[])
{
    for (int i =0; i<x;i++)
    {
        if (strcmp(tit,title_check[i])==0)
            return 0;
    }
    return 1;
}

void ReturnBook(Library people[])
{
    int id;
    char tit[MAX_LEN]={0};
    Library person;
    book book1;

    printf("ID of person returning a book: ");
    id = IDValidate();

    printf("Title of a book to return: ");
    fgets(tit, MAX_LEN, stdin);
    tit[strcspn(tit, "\n")] = 0;
    while (ValidTitle(tit))
    {   
        printf("Wrong title.\n");
        fgets(tit, MAX_LEN, stdin);
        tit[strcspn(tit, "\n")] = 0;
    }
    for (int i =0; i < n; i++)
    {
        person = people[i];

        if (person.id==id)
        {
            for (int j = 0; j<person.count_books; j++)
            {
                book1 = person.book[j];
                if (book1.status == 1)
                {
                    printf("Book already returned.\n");
                    break;
                }
                if (strncmp(book1.title, tit, strlen(book1.title))==0)
                {
                    book1.status = 1;
                    person.borrowed -=1;

                    printf("Return date: ");
                    fgets(book1.return_date, MAX_LEN, stdin);
                    book1.return_date[strcspn(book1.return_date, "\n")] = 0;

                    person.book[j]=book1;
                    people[i]=person;
                    break;
                }
            }
        }
    }
    printf("\n");
}


void DisplayPerson(Library people[])
{
    int id;
    Library person;
    book book1;

    printf("ID of person to display: ");
    id = IDValidate();
    for (int i =0; i < n; i++)
    {
        person = people[i];
        if (person.id==id)
        {
        printf("\nID: %d, Name: %s, Surname: %s\n", person.id, person.name, person.surname);
        printf("\nOne person can borrow %d books at a time.\n\n", MAX_BORROW);
        printf("Borrowed books:\n");
        printf("-----\n");
        for (int j =0; j<person.count_books; j++)
        {
            book1 = person.book[j];
            if(book1.status == 0)
            {
            printf("Title: %s, Author: %s, Borrowed: %s\n", book1.title, book1.author, book1.borrow_date);
            }
            else
            {
            printf("Title: %s, Author: %s, Borrowed: %s, Returned: %s\n", book1.title, book1.author, book1.borrow_date, book1.return_date);
            }
        }
        printf("-----\n");


        }
    }
}

void DisplayInfo()
{
    printf("To creat an account --> Add\n");
    printf("To borrow book --> Borrow\n");
    printf("To return a book --> Return\n");
    printf("To display account information --> Info\n");
    printf("To exit program --> Exit\n");
}

void DisplayMenu()
{
    printf("\n---MENU---\n");
    DisplayInfo();
    printf("Task: ");
}

int main()
{
    Library people[MAX_PEOPLE];
    char buffer[MAX_LEN]={0};

    char add[20]={'A','d','d',0};
    char borrow[7]={'B','o','r','r','o','w',0};
    char ret[7]={'R','e','t','u','r','n',0};
    char info[5]={'I','n','f','o',0};
    char exit_loop[5]={'E','x','i','t',0};

    printf("You can add %d people.\n", MAX_PEOPLE);
    printf("One person can borrow %d books at a time.\n", MAX_BORROW);

    DisplayMenu();

    while (fgets(buffer, MAX_LEN, stdin))
    {
        buffer[strcspn(buffer, "\n")] = 0;
        if(strcmp(buffer,add)==0)
        {
            AddPerson(people);
            DisplayMenu();
            continue;
        }
        if(strcmp(buffer,borrow)==0)
        {
            BorrowBook(people);
            DisplayMenu();
            continue;
        }
        if(strcmp(buffer,ret)==0)
        {
            ReturnBook(people);
            DisplayMenu();
            continue;
        }
        if(strcmp(buffer,info)==0)
        {
            DisplayPerson(people);
            DisplayMenu();
            continue;
        }
        if(strcmp(buffer, exit_loop)==0)
        {
            break;
        }
        else
        {
            printf("Invalid command.\n");
            DisplayMenu();
            continue;
        }
    }

    return 0;
}
