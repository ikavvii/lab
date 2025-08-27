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

    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int positive= 0, negative=0, odd=0, even=0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            negative++;
        else
            positive++;

        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("-ve: %d |+ve: %d |even: %d |odd: %d", \
        negative, positive, even, odd);

}