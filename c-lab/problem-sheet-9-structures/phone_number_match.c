#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// using pointers to access structure variable whenever possible

typedef struct
{
    char firstName[10];
    char lastName[10];
    char phoneNumber[10];
} Phone;

bool isSamePhoneNumber(Phone *, Phone *);
void clearInputBuffer(void);

int main()
{
    Phone *p1 = malloc(sizeof(Phone)); 
    Phone *p2 = malloc(sizeof(Phone));

    printf("Enter Details: \n");
    printf("First Name: ");
    scanf("%10s", p1->firstName);

    printf("Last Name: ");
    scanf("%10s", p1->lastName);

    printf("Phone Number: ");
    scanf("%10s", p1->phoneNumber);

    printf("First record completed..\n\n");

    clearInputBuffer();

    printf("Enter Details: \n");
    printf("First Name: ");
    scanf("%10s", p2->firstName);

    printf("Last Name: ");
    scanf("%10s", p2->lastName);

    printf("Phone Number: ");
    scanf("%10s", p2->phoneNumber);

    printf("Second record completed..\n\n");

    // printf("%s\n", p1.phoneNumber);
    // printf("%s", p2.phoneNumber);

    printf("%s", isSamePhoneNumber(p1, p2) ? "true" : "false");

    return 0;
}

bool isSamePhoneNumber(Phone *p1, Phone *p2)
{
    if (strcmp(p1->phoneNumber, p2->phoneNumber)) return false;
    return true;
}

void clearInputBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}