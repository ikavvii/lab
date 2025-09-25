// any square matrix A can be expressed as the sum of a symmetric matrix B and an anti/skew-symmetric matrix C

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **symmetric;
    int **skew_symmetric;
} DecomposedMatrices;

typedef struct {
    int size;
    int **matrix;
} SquareMatrix;

DecomposedMatrices decomposeMatrix(SquareMatrix inputMatrix) {
    DecomposedMatrices decomposedMatrices;

    decomposedMatrices.symmetric = (int **)malloc(inputMatrix.size * sizeof(int *));
    decomposedMatrices.skew_symmetric = (int **)malloc(inputMatrix.size * sizeof(int *));

    for (int i = 0; i < inputMatrix.size; i++) {
        decomposedMatrices.symmetric[i] = (int *)malloc(inputMatrix.size * sizeof(int));
        decomposedMatrices.skew_symmetric[i] = (int *)malloc(inputMatrix.size * sizeof(int));

        
        for (int j = 0; j < inputMatrix.size; j++) {
            decomposedMatrices.symmetric[i][j] = (inputMatrix.matrix[i][j] + inputMatrix.matrix[j][i]) / 2;
            decomposedMatrices.skew_symmetric[i][j] = (inputMatrix.matrix[i][j] - inputMatrix.matrix[j][i]) / 2;
        }
    }

    return decomposedMatrices;
}

int main() {

}