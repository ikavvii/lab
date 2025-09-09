// https://leetcode.com/problems/spiral-matrix/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int * spiralMatrix = malloc(matrixSize * (*matrixColSize) * sizeof(int));

    int top, bottom, left, right, i;

    top = left = 0;
    bottom = matrixSize - 1;
    right = *matrixColSize - 1;
    *returnSize = 0;


    while (top <= bottom && left <= right) {

        for (i = left; i <= right; i++) {
            spiralMatrix[(*returnSize)++]=matrix[top][i];
        }
        top++;

        for (i = top; i <= bottom; i++) {
            spiralMatrix[(*returnSize)++] = matrix[i][right];
        }
        right--;

        if (top <= bottom ) {
            for (i = right; i >= left; i--) {
                spiralMatrix[(*returnSize)++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right ) {
            for (i = bottom; i >= top; i--) {
                spiralMatrix[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }

    return spiralMatrix;
}