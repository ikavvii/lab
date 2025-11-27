#include <stdio.h>
#include <stdlib.h>

struct product
{
    int id;
    char name[20];
    int quantity;
    int cost;
};

typedef struct product Product;

int main()
{

    FILE *fp;
    int id, quantity, cost, n;
    char name[20];

    fp = (FILE *)fopen("productinfo.dat", "a+");

    if (fp == NULL)
        exit(1);

    n = 1;

    printf("%-5s %5s %-20s %8s %4s\n\n", "S.no.", "ID", "Name", "Quantity", "Cost");
    while (1)
    {
        if (fscanf(fp, "%d %s %d %d",
                   &id, name, &quantity, &cost) == EOF)
            break;
        printf("%-5d %5d %-20s %8d %4d\n", n, id, name, quantity, cost);
        ++n;
    }

    fclose(fp);

    exit(0);
}