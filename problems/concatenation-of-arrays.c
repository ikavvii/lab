#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans = (int *) malloc(2 * numsSize * sizeof(int));
    memcpy(ans, nums, numsSize * sizeof(int));
    memcpy(&ans[numsSize], nums,  numsSize * sizeof(int));

    *returnSize= 2 * numsSize;


    return ans;
}

int main() {
    int nums[] = {1,2,1};
    int returnSize;

    int * arr = getConcatenation(nums, 3, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", arr[i]);
    }


    free(arr);

    return 0;
}