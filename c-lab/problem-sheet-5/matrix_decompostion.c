// any square matrix A can be expressed as the sum of a symmetric matrix B and an anti/skew-symmetric matrix C

#include <stdio.h>
#include <stdlib.h>

typedef struct DecomposedMatrices
{
    int **symmetric;
    int **skew_symmetric;
} DecomposedMatrices;

typedef struct SquareMatrix
{
    int size;
    int **matrix;
} SquareMatrix;

DecomposedMatrices decomposeMatrix(SquareMatrix inputMatrix)
{
    DecomposedMatrices decomposedMatrices;

    decomposedMatrices.symmetric = (int **)malloc(inputMatrix.size * sizeof(int *));
    decomposedMatrices.skew_symmetric = (int **)malloc(inputMatrix.size * sizeof(int *));

    for (int i = 0; i < inputMatrix.size; i++)
    {
        decomposedMatrices.symmetric[i] = (int *)malloc(inputMatrix.size * sizeof(int));
        decomposedMatrices.skew_symmetric[i] = (int *)malloc(inputMatrix.size * sizeof(int));

        for (int j = 0; j < inputMatrix.size; j++)
        {
            decomposedMatrices.symmetric[i][j] = (inputMatrix.matrix[i][j] + inputMatrix.matrix[j][i]) / 2;
            decomposedMatrices.skew_symmetric[i][j] = (inputMatrix.matrix[i][j] - inputMatrix.matrix[j][i]) / 2;
        }
    }

    return decomposedMatrices;
}

int main()
{

    SquareMatrix inputMatrix;
    inputMatrix.size = 3;

    inputMatrix.matrix = (int **)malloc(inputMatrix.size * sizeof(int *));
    for (int i = 0; i < inputMatrix.size; i++)
    {
        inputMatrix.matrix[i] = (int *)malloc(inputMatrix.size * sizeof(int));
    }

    // Example matrix
    int example[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (int i = 0; i < inputMatrix.size; i++)
    {
        for (int j = 0; j < inputMatrix.size; j++)
        {
            inputMatrix.matrix[i][j] = example[i][j];
        }
    }

    DecomposedMatrices result = decomposeMatrix(inputMatrix);

    printf("Symmetric Matrix:\n");
    for (int i = 0; i < inputMatrix.size; i++)
    {
        for (int j = 0; j < inputMatrix.size; j++)
        {
            printf("%d ", result.symmetric[i][j]);
        }
        printf("\n");
    }

    printf("\nSkew-Symmetric Matrix:\n");
    for (int i = 0; i < inputMatrix.size; i++)
    {
        for (int j = 0; j < inputMatrix.size; j++)
        {
            printf("%d ", result.skew_symmetric[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < inputMatrix.size; i++)
    {
        free(inputMatrix.matrix[i]);
        free(result.symmetric[i]);
        free(result.skew_symmetric[i]);
    }
    free(inputMatrix.matrix);
    free(result.symmetric);
    free(result.skew_symmetric);

    return 0;
}