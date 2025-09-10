#include <stdio.h>

double findMaxAverage(int* nums, int numsSize, int k, int* index) {
    int currSum = 0;

    // sum of first k elements
    for (int i = 0; i < k; i++) {
        currSum += nums[i];
    }

    int maxSum = currSum;
    *index = 0;
    // fixed size window
    for (int i = k; i < numsSize; i++) {
        currSum += nums[i] - nums[i - k];
        
        if (currSum > maxSum) {
            maxSum = currSum;
            (*index)++;
        }
    }

    return maxSum/(double)k;
}

int main() {
    int arr[] = {1,12,-5,-6,50,3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int index = -1;
    printf("Max average: %f at index %d  with length %d\n", findMaxAverage(arr, arr_size, k, &index), index, k);
    return 0;
}