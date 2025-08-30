#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size < 2)
    {
        printf("At least two elements are required.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    int largest = INT_MIN, second_largest = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] < largest)
            second_largest = arr[i];
    }

    if (second_largest == INT_MIN)
    {
        printf("No second largest element is found.");
    }
    else
    {
        printf("Second largest value in the array: %d", second_largest);
    }

    free(arr);
    return 0;
}