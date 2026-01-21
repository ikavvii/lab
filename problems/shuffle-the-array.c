#include <stdlib.h>
#include <stdio.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (*returnSize % 2 == 0) {
            ans[(*returnSize)++] = nums[i];
        } else {
            ans[(*returnSize)++] = nums[n + i];
        }
    }

    return ans;
}

int main() {
    int nums[] = {2, 5, 1, 3, 4, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int n = numsSize / 2;
    int returnSize = 0;

    int* shuffled = shuffle(nums, numsSize, n, &returnSize);

    printf("Shuffled array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", shuffled[i]);
    }
    printf("\n");

    free(shuffled);
    return 0;
}