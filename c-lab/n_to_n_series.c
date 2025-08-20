#include <stdio.h>

int main()
{
    int n, sum = 0;
    printf("Enter positive integer: ");
    scanf("%d", &n);

    int temp = n;
    for (int i = 1; i <= n; i++) {
        sum += i * temp--;
    }
    printf("%d", sum);
}