#include <stdio.h>

int main()
{
    int n, sum = 0;
    printf("Enter positive integer: ");

    if (!scanf("%d", &n))
    {
        printf("Invalid input");
        return 1;
    }

    if (n < 0)
    {
        printf("Invalid input.");
        return 2;
    }

    int temp = n;
    for (int i = 1; i <= n; i++)
    {
        sum += i * temp--;
    }
    printf("%d", sum);

    return 0;
}