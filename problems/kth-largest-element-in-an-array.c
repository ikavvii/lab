#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

int findKthLargest(int arr[], int n, int k)
{
    qsort(arr, n, sizeof(int), comparator);
    return arr[n - k];
}

int findKthLargestQuickSelect() {
    
}

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int result = findKthLargest(arr, n, k);
    printf("The %d-th largest element is %d\n", k, result);
    return 0;
}