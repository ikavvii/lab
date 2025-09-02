#include <stdio.h>
#include <stdlib.h>

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
    printf("k: ");
    scanf("%d", k);

    int rank[n];
    rank[0] = 0;
    int down = 0, up = 0;

    for (int i = 0; i < n - 2; i++) {
        if (arr[i] > arr[i+1]) {
            
        }
    }
}