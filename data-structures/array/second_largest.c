#include <stdio.h>

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size], first = 0, second = 0;
    for (int i = 0; i < size; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &arr[i]);

        if (arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second)
            second = arr[i];
    }

    printf("Second largest value in the array: %d", second);
}