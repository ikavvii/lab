#include <stdio.h>

int main()
{

  int m, n;
  printf("Enter order of matrix (mxn): ");

  scanf("%dx%d", &m, &n);

  int mat[m][n];
  int i, j, c;
  printf("Enter matrix %dx%d: \n", m, n);
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &mat[i][j]);
    }
  }

  printf("%dx%d matrix created successfully.\n", m, n);

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (mat[i][j] == 0)
        c++;
    }
  }

  if (c >= (m * n) / 2)
  {
    printf("It is a sparse matrix.\n");
  }
  else
  {
    printf("It is not a sparse matrix.\n");
  }

  return 0;
}