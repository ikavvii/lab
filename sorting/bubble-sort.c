#include <stdio.h>

void bubble_sort(int A[], int n)
{
    int temp;
    for (int k = 0; k < n - 1; k++)
    {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                // here swapping of positions is being done.
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 10;
    int arr[10] = {2, 4, 6, 23, 1, 6, 2, 8, 34, 64};

    bubble_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}