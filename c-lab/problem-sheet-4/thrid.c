/*
    Search an element in an array where difference between adjacent elements is 1. Given
    an array where difference between adjacent elements is 1, write C program search for
    an element in the array and return the position of the element (return the first
    occurrence).
*/

#include <stdio.h>
#include <math.h>

int main()
{

    int n, i;
    printf("size: ");
    scanf("%d", &n);

    int arr[n];
    printf("elements\n ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) == 1)
        {
            printf("at %d, %d: %d, %d", i, i + 1, arr[i], arr[i+1]);
            return 0;
        }
    }

    printf("No adjacent elements with difference 1 is found.\n");

    return 0;
}