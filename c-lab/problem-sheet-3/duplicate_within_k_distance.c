/*

Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller
than size of array. Write a C function that returns true if array contains duplicates within k
distance.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int *nums, int numsSize, int k);

struct HashNode
{
    int key;
    int value;
    struct HashNode *next;
};

int main()
{

    int n, i, k;

    printf("size: ");
    scanf("%d", &n);

    printf("elements: ");

    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("distance k: ");
    scanf("%d", &k);

    if (containsNearbyDuplicate(arr, n, k))
    {
        printf("contains nearby duplicates");
    }
    else
    {
        printf("doesn't contains nearby duplicates");
    }

    return 0;
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{

    struct HashNode** hashMap = (struct HashNode**)calloc(numsSize, sizeof(struct HashNode*));

    for (int i = 0; i < numsSize; i++ ) {
        
    }
}