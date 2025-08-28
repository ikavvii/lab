#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr = NULL;
    int count = 0;
    int num;

    printf("Enter numbers (space-separated, press Enter to finish) :-\n");

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

    printf("You entered %d numbers:\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}