#include <stdio.h>

int checkDuplicatesWithinK(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n && j - i <= k; j++) {

            if (arr[i] == arr[j])
                return 1; 
        }
    }
    return 0; 
}

int main()
{
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", checkDuplicatesWithinK(arr, n, 3));
    return 0;
}