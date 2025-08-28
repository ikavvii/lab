#include <stdio.h>

int main()
{

    int i, j, n1, n2, d1, d2;

    for (i = 10; i < 99; i++)
    {
        for (j = i + 1; j < 99; j++)
        {
            n1 = i / 10;
            n2 = i % 10;
            d1 = j / 10;
            d2 = j % 10;
            // printf("%d, %d -- \t", i, j);
            if (n2 == d2) continue;
            if (n2 == d1 && i * d2 == j * n1)
            {
                printf("%d / %d = %d / %d\n", i, j, n1, d2);
            }
        }
    }

    return 0;
}