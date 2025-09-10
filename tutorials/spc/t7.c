#include <stdio.h>
#include <conio.h>
void main()
{
    int i, j, x = 0;
    for (i = 0; i < 100; i++)
        for (j = i; j < 100; j++)
            x++;
    printf("%d", x);
}