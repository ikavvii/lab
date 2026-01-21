#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int totalElements = rows * cols;
    int* result = (int*)malloc(totalElements * sizeof(int));
    int k = 0; // Index for result array

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (k < totalElements) {
        // 1. Traverse Right (Top Row)
        for (int j = left; j <= right && k < totalElements; j++) {
            result[k++] = matrix[top][j];
        }
        top++; // Move top boundary down

        // 2. Traverse Down (Right Column)
        for (int i = top; i <= bottom && k < totalElements; i++) {
            result[k++] = matrix[i][right];
        }
        right--; // Move right boundary left

        // 3. Traverse Left (Bottom Row)
        for (int j = right; j >= left && k < totalElements; j--) {
            result[k++] = matrix[bottom][j];
        }
        bottom--; // Move bottom boundary up

        // 4. Traverse Up (Left Column)
        for (int i = bottom; i >= top && k < totalElements; i--) {
            result[k++] = matrix[i][left];
        }
        left++; // Move left boundary right
    }

    *returnSize = totalElements;
    return result;
}