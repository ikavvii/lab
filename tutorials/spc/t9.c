#include <stdio.h>
#include <conio.h>
void main()
{
    int i, j, k;
    // clrscr();
    for (i = 1; i < 10; i++)
    {
        printf("%d: ", i);
        for (j = 1; j < 10; j++)
        {
            if (i % 3 == 0)
                break;
            if (i > j)
                continue;
            k = i * 10 + j;
            printf("%d ", k);
        }
        printf("\n");
    }
}
