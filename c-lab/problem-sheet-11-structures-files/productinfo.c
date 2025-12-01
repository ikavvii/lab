#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    int id;
    char name[20];
    int quantity;
    int cost;
};

typedef struct product Product;

void display_products(FILE *fp)
{
    if (fp == NULL)
    {
        printf("Error: Unable to open file for reading.\n");
        return;
    }

    int id, quantity, cost, n;
    char name[20];
    n = 1;

    printf("%-5s %5s %-20s %8s %4s\n\n", "S.no.", "ID", "Name", "Quantity", "Cost");
    while (fscanf(fp, "%d %19s %d %d", &id, name, &quantity, &cost) == 4)
    {
        printf("%-5d %5d %-20s %8d %4d\n", n, id, name, quantity, cost);
        ++n;
    }
}

void add_product(FILE *fp, int id, const char *name, int quantity, int cost)
{
    if (fp == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    fprintf(fp, "%d %s %d %d\n", id, name, quantity, cost);
    printf("Product added successfully!\n");
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    FILE *fp = NULL;
    int id, quantity, cost;
    char name[20];

    while (1)
    {
        printf("\n1. Add a Product\n2. Display\n3. Exit\nEnter: ");
        char input;
        do
        {
            input = getchar();
        } while (input == '\n');

        switch (input)
        {
        case '1':
            printf("ID: ");
            if (scanf("%d", &id) != 1 || id <= 0)
            {
                printf("Invalid ID. Please enter a positive number.\n");
                clear_input_buffer();
                break;
            }
            
            printf("Name: ");
            if (scanf("%19s", name) != 1)
            {
                printf("Invalid name.\n");
                clear_input_buffer();
                break;
            }
            
            printf("Quantity: ");
            if (scanf("%d", &quantity) != 1 || quantity < 0)
            {
                printf("Invalid quantity. Please enter a non-negative number.\n");
                clear_input_buffer();
                break;
            }
            
            printf("Cost: ");
            if (scanf("%d", &cost) != 1 || cost < 0)
            {
                printf("Invalid cost. Please enter a non-negative number.\n");
                clear_input_buffer();
                break;
            }

            fp = fopen("productinfo.dat", "a");
            if (fp == NULL)
            {
                printf("Error: Unable to open file.\n");
                break;
            }

            add_product(fp, id, name, quantity, cost);
            fclose(fp);
            break;

        case '2':
            fp = fopen("productinfo.dat", "r");
            if (fp == NULL)
            {
                printf("Error: Unable to open file. No products to display.\n");
                break;
            }

            display_products(fp);
            fclose(fp);
            break;

        case '3':
            printf("Exiting program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}