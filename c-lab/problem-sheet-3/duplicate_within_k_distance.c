/*

Check if a given array contains duplicate elements within k distance from each other
Given an unsorted array that may contain duplicates. Also given a number k which is smaller
than size of array. Write a C function that returns true if array contains duplicates within k
distance.

*/

// work on it later

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
    scanf("%d", &n); // 7

    printf("elements: ");

    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    printf("distance k: "); // 3
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
        int hashIndex = abs(nums[i]) % numsSize;
        struct HashNode* currentNode = hashMap[hashIndex];
        while (currentNode != NULL) {
            if (currentNode->key == nums[i]) {
                if (i - currentNode->value <= k) {
                    return true;
                } else {
                    currentNode->value = i; // update the index
                    break;
                }
            }
            currentNode = currentNode->next;
        }
        if (currentNode == NULL) {
            struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
            newNode->key = nums[i];
            newNode->value = i;
            newNode->next = hashMap[hashIndex];
            hashMap[hashIndex] = newNode;
        }
        
    }
}