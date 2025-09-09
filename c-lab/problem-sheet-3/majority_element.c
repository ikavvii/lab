// Given an array of size n and a number k, find all elements that appear more than n/k
// times.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, k;

    printf("size: ");
    scanf("%d", &n);

    printf("elements: ");

    int *arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("k: ");
    scanf("%d", &k);

    // find max element
    int max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (i = 0; i <= max; i++)
    {
        if (count[i] > n / k)
        {
            printf("%d ", i);
        }
    }

    free(arr);
    free(count);
    
    return 0;
}