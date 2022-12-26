#include <stdio.h>
#include <string.h>

#define MAX_LEN 20 // max chars for names, surnames, titles... etc.
#define MAX_BORROW 2 // max books you can borrow at a time
#define MAX_PEOPLE 20 // max people in data base
#define MAX_BOOKS 10 // max books person can have in records

// making sure every id is unique
int id_check[MAX_PEOPLE];
int n=0;

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

void AddPerson(Library people[])
{
    int id, i;
    Library person;

    printf("ID should be a digit.\n");
    printf("ID to creat: ");
    scanf("%d", &id);
    for (i=0; i<n; i++)
    {
        if (id_check[i]==id)
        {
            while (id_check[i]==id)
            {
                printf("Invalid ID.\n");
                printf("New ID: ");
                scanf("%d", &id);
            }
        }
    }
    id_check[n]=id;
    person.id = id;

    printf("Name: ");
    scanf("%s", person.name);

    printf("Surname: ");
    scanf("%s", person.surname);

    person.count_books = 0;
    person.borrowed = 0;

    people[n]=person;

    n++;
}

void BorrowBook(Library people[])
{   
    int id;
    Library person;
    book book1;

    printf("ID of person borrowing a book: ");
    scanf("%d", &id);
    while (ElementCheck(id_check ,id)==0)
    {
        printf("ID doesnt exist.\n");
        printf("ID of person borrowing a book: ");
        scanf("%d", &id);
    }
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
            scanf("%s", book1.title);

            printf("Author: ");
            scanf("%s", book1.author);

            printf("Borrow date: ");
            scanf("%s", book1.borrow_date);
            book1.status = 0;
            
            person.book[(person.count_books-1)]=book1;
            people[i]= person;
            }
        }
    }
    printf("\n");
}

void ReturnBook(Library people[])
{
    int id;
    char tit[MAX_LEN];
    Library person;
    book book1;

    printf("ID of person returning a book: ");
    scanf("%d", &id);
    while (ElementCheck(id_check ,id)==0)
    {
        printf("ID doesnt exist.\n");
        printf("ID of person returning a book: ");
        scanf("%d", &id);
    }

    printf("Title of a book to return: ");
    scanf("%s", tit);

    for (int i =0; i < n; i++)
    {
        person = people[i];

        if (person.id==id)
        {
            for (int j = 0; j<MAX_BORROW; j++)
            {
                book1 = person.book[j];
                if (strcmp(book1.title, tit)==0)
                {
                    book1.status = 1;
                    person.borrowed -=1;

                    printf("Return date: ");
                    scanf("%s", book1.return_date);

                    person.book[j]=book1;
                    people[i]=person;
                    break;
                }
                else
                {
                    printf("Wrong title.\n");
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
    scanf("%d", &id);
    while (ElementCheck(id_check ,id)==0)
    {
        printf("ID doesnt exist.\n");
        printf("ID of person to display: ");
        scanf("%d", &id);
    }
    for (int i =0; i < n; i++)
    {
        person = people[i];
        if (person.id==id)
        {
        printf("\nID: %d, Name: %s, Surname: %s\n", person.id, person.name, person.surname);
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
}

int main()
{
    Library people[MAX_PEOPLE];
    char buffer[MAX_LEN];

    char add[4]={'A','d','d',0};
    char borrow[7]={'B','o','r','r','o','w',0};
    char ret[7]={'R','e','t','u','r','n',0};
    char info[5]={'I','n','f','o',0};


    printf("You can add %d people.\n", MAX_PEOPLE);
    printf("One person can borrow %d books at a time.\n", MAX_BORROW);


    printf("\n---MENU---\n");
    DisplayInfo();
    printf("Task: ");

    while (scanf("%s", buffer) != EOF)
    {
        if(strcmp(buffer,add)==0)
        {
            AddPerson(people);
            printf("\n---MENU---\n");
            DisplayInfo();
            printf("Task: ");
            continue;
        }
        if(strcmp(buffer,borrow)==0)
        {
            BorrowBook(people);
            printf("\n---MENU---\n");
            DisplayInfo();
            printf("Task: ");
            continue;
        }
        if(strcmp(buffer,ret)==0)
        {
            ReturnBook(people);
            printf("\n---MENU---\n");
            DisplayInfo();
            printf("Task: ");
            continue;
        }
        if(strcmp(buffer,info)==0)
        {
            DisplayPerson(people);
            printf("\n---MENU---\n");
            DisplayInfo();
            printf("Task: ");
            continue;
        }
        else
        {
            printf("Invalid command.\n");
            printf("\n---MENU---\n");
            DisplayInfo();
            printf("Task: ");
            continue;
        }
    }

    return 0;
}
