#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    char str[1000];

    fp = (FILE *)fopen("myfile.dat", "r");

    if (fp == NULL)
    {
        printf("Cannon open file for reading.\n");
        exit(0);
    }

    while (fgets(str, 1000, fp) != NULL)
    /* reads 999 chars at most at a time */
    {
        printf("We have read the string: %s\n", str);
    }

    return 0;
}