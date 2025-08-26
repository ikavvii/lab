#include <stdio.h>

int main()
{
    int n;

    printf("size\n");
    scanf("%d", &n);

    printf("array\n");

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (mid == 0 && arr[0] >= arr[1])
        {
            printf("%d", mid);
            return 0;
        }

        if (mid == n - 1 && arr[n - 1] >= arr[n - 2])
        {
            printf("%d", mid);
            return 0;
        }

        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            printf("%d", mid);
            return 0;
        }

        if (arr[mid] < arr[mid - 1])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return 0;
}