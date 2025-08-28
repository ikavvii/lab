/*
    Consider an array of numbers from 1 to N . In this array, one of the numbers gets duplicated
    and one is missing. Write a C program to find out the duplicated number. Condition: Using
`   only one loop and without any extra memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, _sumN = 0, _sumNN = 0, sumN, sumNN, x, y, z, d, m;
    printf("size \t");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("elements \t");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        _sumN += arr[i];
        _sumNN += arr[i] * arr[i];
    }

    // printf("%d\n", _sumN);
    // printf("%d\n", _sumNN);

    sumN = n * (n + 1) / 2;
    sumNN = sumN * (2 * n + 1) / 3;

    // printf("%d\n", sumN);
    // printf("%d\n", sumNN);

    x = _sumN - sumN;
    y = _sumNN - sumNN;

    // printf("%d\n", x);
    // printf("%d\n", y);

    z = y / x;

    // printf("%d\n", z);

    d = (x + z) / 2; // duplicate
    m = d - x;

    printf("Duplicate number: %d\n", d);
    printf("Missing number: %d\n", m);

    return 0;
}