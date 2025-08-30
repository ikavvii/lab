#include <stdio.h>

int isPrime(int n);

int main()
{
    int n;

    printf("size\n");
    scanf("%d", &n);

    printf("array\n");

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp[n], i, j = 0;
    for (i = 0; i < n; i++)
    {

        if (!isPrime(arr[i]))
        {
            temp[j++] = arr[i];
        }
    }

    if (j == 0)
    {
        printf("No non-prime elements.");
    }

    for (int i = 0; i < j; i++)
    {
        if (i > 0)
            printf(", ");
        printf("%d", temp[i]);
    }

    return 0;
}

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}