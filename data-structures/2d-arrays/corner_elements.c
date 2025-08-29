#include <stdio.h>

int main()
{

  int m, n;
  printf("Enter order of matrix (mxn): ");

  scanf("%dx%d", &m, &n);

  int mat[m][n];
  int i, j;
  printf("Enter matrix %dx%d: \n", m, n);
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &mat[i][j]);
    }
  }

  printf("%dx%d matrix created successfully.\n", m, n);

  int c1, c2, c3, c4, sumC;

  c1 = mat[0][0];
  c2 = mat[m - 1][0];
  c3 = mat[0][n - 1];
  c4 = mat[m - 1][n - 1];

  sumC = c1 + c2 + c3 + c4;
  printf("Corner elements: %d, %d, %d, %d, Corner sum = %d\n", c1, c2, c3, c4, sumC);

  return 0;
}