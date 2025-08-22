#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void print_array(int *arr);

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

    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++)
    {
        printf("@ arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // bubble sort

    // asc and desc arrays

    int *asc_arr = malloc(size * sizeof(int));
    if (asc_arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        asc_arr[i] = arr[i];
    }

    int *desc_arr = malloc(size * sizeof(int));

    if (desc_arr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        desc_arr[i] = arr[i];
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (asc_arr[j] > asc_arr[j + 1])
            {
                swap(&asc_arr[j], &asc_arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - 1; j++)
        {

            if (desc_arr[j] < desc_arr[j + 1])
            {
                swap(&desc_arr[j], &desc_arr[j + 1]);
            }
        }
    }

    print_array(arr);
    print_array(asc_arr);
    print_array(desc_arr);

    return 0;
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void print_array(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b \n");
}