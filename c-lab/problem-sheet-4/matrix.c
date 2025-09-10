#include <stdio.h>
#include <stdlib.h>

int* toAndFroRowMajor(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int * toAndFroMatrix = malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < matrixSize; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < *matrixColSize; j++) {
                toAndFroMatrix[(*returnSize)++] = matrix[i][j];
            }
        } else {
            for (int j = *matrixColSize - 1; j >= 0; j--) {
                toAndFroMatrix[(*returnSize)++] = matrix[i][j];
            }
        }
    }

    return toAndFroMatrix;
}

int* diagonalMajor(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int * diagonalMatrix = malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;

    for (int d = 0; d < matrixSize + *matrixColSize - 1; d++) {
        int r, c;
        if (d < *matrixColSize) {
            r = 0;
            c = d;
        } else {
            r = d - (*matrixColSize) + 1;
            c = *matrixColSize - 1;
        }

        while (r < matrixSize && c >= 0) {
            diagonalMatrix[(*returnSize)++] = matrix[r][c];
            r++;
            c--;
        }
    }

    return diagonalMatrix;
}

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




int main() {
    int matrixSize, matrixColSize;
    scanf("%d %d", &matrixSize, &matrixColSize);

    int** matrix = malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = malloc(matrixColSize * sizeof(int));
        for (int j = 0; j < matrixColSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int* result1 = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result1[i]);
    }
    printf("\n");
    free(result1);

    // to-and-fro row-major print
    int* result2 = toAndFroRowMajor(matrix, matrixSize, &matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result2[i]);
    }
    printf("\n");
    free(result2);

    // diagonal-major print
    int* result3 = diagonalMajor(matrix, matrixSize, &matrixColSize, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result3[i]);
    }
    printf("\n");
    free(result3);

    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}