/*  Write a C program to reverse array in place in C.   */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr = NULL;
    int count = 0;
    int num;

    printf("Enter numbers -\n");

    while (scanf("%d", &num) == 1)
    {
        int *temp = realloc(arr, (count + 1) * sizeof(int));

        if (temp == NULL)
        {
            printf("Memory allocation failed.");
            free(arr);
            return 1;
        }

        arr = temp;
        arr[count++] = num;

        int c = getchar();

        if (c == '\n' || c == EOF)
            break;
    }

    int i = 0, j = count - 1;
    while (i < j)
    {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++;
        j--;
    }

    printf("Reversed array: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}