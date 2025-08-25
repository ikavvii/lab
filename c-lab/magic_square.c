#include <stdio.h>
#include <stdlib.h>

int **magicSquareOdd(int n);
int **initializeSquare(int n);
void printSquare(int **square, int n);
int **magicSquare4(int n);
int **magicSquareSinglyEven(int n);
int **magicSquareDoublyEven(int n);

int main()
{

    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }

    // for n -> square with 1 to n^2
    // is distinct, magic constant = n(n^2 + 1) / 2

    // divide and conquer

    int **magicSquare = magicSquare4(4);
    if (magicSquare == NULL)
    {
        return EXIT_FAILURE;
    }

    printSquare(magicSquare, n);

    // free memory
    for (int i = 0; i < n; i++)
    {
        free(magicSquare[i]);
    }

    free(magicSquare);

    return 0;
}

int **magicSquare4(int n)
{
    int topX = 0, topY = 0, bottomX = n - 1, bottomY = n - 1;
    int topDownValue = 1, bottomUpValue = n * n;
    int **square = initializeSquare(n);


    while (topX<bottomX) {
        while (topY <n) {
            square[topX][topY++] = topDownValue;
            square[bottomX][bottomY--] = bottomUpValue;

            topDownValue++; bottomUpValue--;

            if (topY != n / 2) {
                int temp = topDownValue;
                topDownValue = bottomUpValue;
                bottomUpValue = temp;
            }



        }

        topX++;bottomX--;
        topY = 0;
        bottomY = n-1;
    }

    return square;
}

int **magicSquareSinglyEven(int n)
{


}

int **magicSquareDoublyEven(int n)
{
}

int **magicSquareOdd(int n)
{
    int i, j, k, l;
    // check if n <- odd
    if (n % 2 == 0)
    {
        return NULL;
    }

    // initialize empty array
    int **square = initializeSquare(n);
    if (!square)
        return NULL;

    // initialize first item

    i = 0;
    j = (n - 1) / 2;
    square[i][j] = 1;

    for (int key = 2; key <= n * n; key++)
    {
        // k = (i - 1 + n) % n
        if (i >= 1)
        {
            k = i - 1;
        }
        else
        {
            k = n - 1;
        }

        // l = (j - 1 + n) % n
        if (j >= 1)
        {
            l = j - 1;
        }
        else
        {
            l = n - 1;
        }
        if (square[k][l] >= 1)
        {
            i = (i + 1) % n;
        }
        else
        {
            i = k;
            j = l;
        }

        square[i][j] = key;
    }
    return square;
}

int **initializeSquare(int n)
{
    int **square = (int **)malloc(n * sizeof(int *));

    if (square == NULL)
    {
        fprintf(stderr, "Memory allocation for row pointers failed.\n");
        return NULL;
    }

    for (int row = 0; row < n; row++)
    {
        square[row] = (int *)malloc(n * sizeof(int));

        if (square[row] == NULL)
        {
            fprintf(stderr, "Memory allocation for row %d failed.\n", row);

            // free previously allocated rows
            for (int k = 0; k < row; k++)
            {
                free(square[k]);
            }

            free(square);
            return NULL;
        }

        // fill zeros
        for (int col = 0; col < n; col++)
        {
            square[row][col] = 0;
        }
    }

    return square;
}

void printSquare(int **square, int n)

{
    printf("\nMagic Square of size %d (Magic Constant = %d):\n\n", n, n * (n * n + 1) / 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d\t", square[i][j]);
        }
        printf("\n");
    }
}