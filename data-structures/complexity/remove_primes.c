#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2 ) {
        if (n % i == 0) {
            return 0;
        }

    }
    return 1;
}


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
    for (i = 0; i < n; i++) {

        if (!isPrime(arr[i])) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++) {
        printf("%d, ", temp[i]);
    }

    printf("\b\b ");

    return 0;
}
