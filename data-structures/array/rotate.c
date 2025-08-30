#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, k;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Enter rotation key: ");
    scanf("%d", &k);

    // normalize k => [0, size - 1]
    k = (k % size + size) % size;

    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *temp = malloc(size * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed.");
        free(arr);
        return 1;
    }

    int i, j = 0;
    for (i = k; i < size; i++)
    {
        temp[j++] = arr[i];
    }
    for (i = 0; i < k; i++)
    {
        temp[j++] = arr[i];
    }

    for (i = 0; i < size; i++)
    {
        printf("%d ", temp[i]);
    }

    free(arr);
    free(temp);
    return 0;
}