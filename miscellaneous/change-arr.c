#include <stdio.h>

void changeArr(int *a, int n)
{
    int *p;
    p = a;
    while (n)
    {
        if (*(p + n - 1) > 0 && *(p + n - 1) % 2 == 0)
        {
            (*(p + n - 1))++;
        }
        else if (*(p + n - 1) > 0)
        {
            (*(p + n - 1))--;
        }
        n--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 0, -1, -2, 8}, n = 11;

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    changeArr(a, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}