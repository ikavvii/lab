#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    int largest = 0, second_largest = 0;
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

    printf("Second largest value in the array: %d", second_largest);
}