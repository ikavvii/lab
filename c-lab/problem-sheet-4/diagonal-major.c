#include <stdio.h>

int main()
{
    int m = 4, n = 4;
    // int matrix[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int row = 0;
        int col = i;
        while (col <= n - 1)
        {
            printf("%d ", matrix[row][col]);
            col++;
            row++;
            if (row == m)
                break;
        }
        printf("\n");
        index++;
    }

    for (int i = m - 1; i > 0; i--)
    {
        int row = i, col = 0;
        while (col < m - i)
        {
            printf("%d ", matrix[row][col]);
            row++;
            col++;
        }
        printf("\n");
    }

    return 0;
}