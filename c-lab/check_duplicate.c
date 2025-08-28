/*  Write a C program to check if array contains a duplicate number.  */

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

    // check for duplicates
    int flag = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j< count;j++) {
            if (arr[i] == arr[j]) {
                flag = 1;
                break;
            }
        }
    }

    if (flag) {
        printf("Array contains duplicate elements");
    } else {
        printf("Array elements are distinct.");
    }

    free(arr);
    return 0;
}