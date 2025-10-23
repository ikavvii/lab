#include <stdio.h>
#include <stdlib.h>
/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is
to find the K th smallest element in the given array. It is given that all array elements
are distinct.
Expected Time Complexity: O(n)
*/

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