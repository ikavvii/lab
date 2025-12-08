#include <stdio.h>
#include <stdlib.h>

// Comparison function for integers in ascending order
int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {20, 15, 36, -8, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    qsort(arr, n, sizeof(int), compareIntegers);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}