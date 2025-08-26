#include <stdio.h>

int main() {
    int n;

    printf("size\n");
    scanf("%d", &n);

    printf("array\n");

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("position to split ");
    scanf("%d", &k);

    k %= n;

    int temp[n],i, j = 0;
    for (i = k; i < n; i++) {
        temp[j++] = arr[i];
    }

    for (i = 0; i < k; i++) {
        temp[j++] = arr[i];
    }

    for (i = 0; i< n; i++) {
        printf("%d, ", temp[i]);
    }
    printf("\b\b ");
}