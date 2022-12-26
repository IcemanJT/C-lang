#include <stdio.h>
#include <string.h>

#define MAX_LEN 20
#define MAX_BORROW 4
#define BASE 100
#define MAX_PEOPLE 20

int id_check[BASE];
int n=0;

typedef struct
{

    char title[MAX_LEN];
    char author[MAX_LEN];
    char borrow_date[MAX_LEN];
    char return_date[MAX_LEN];
    int count_books[MAX_BORROW];

}book;

typedef struct
{

    int id;
    char name[MAX_LEN];
    char surname[MAX_LEN];
    book books;

}Library;


void AddPerson(Library* person)
{
    int id, i;
    Library *personptr;
    personptr = person;

    printf("ID to creat: ");
    scanf("%d", &id);
    for (i=0; i<BASE; i++)
    {
        if (id_check[i]==id)
        {
            while (id_check[i]==id)
            {
                printf("ID already exists.\n");
                printf("New ID: ");
                scanf("%d", &id);
            }
        }
    }
    id_check[n]=id;
    personptr->id = id;

    printf("Name: ");
    scanf("%s", personptr->name);

    printf("Surname: ");
    scanf("%s", personptr->surname);

    n++;
}

void PrintPerson(Library person)
{
    printf("ID of person to display: ");

    printf("id: %d, name: %s, surname: %s\n", person.id, person.name, person.surname);
}

int main()
{
    Library person1, person2;


    AddPerson(&person1);
    AddPerson(&person2);
    PrintPerson(person1);
    PrintPerson(person2);



    return 0;
}