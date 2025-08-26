#include <stdio.h>
#include <stdlib.h>

int main () {
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

    int search_element, flag=0;

    printf("Enter the element to searched: ");
    scanf("%d", &search_element);

    for (int i = 0;arr[i]; i++) {
        if (arr[i] == search_element) {
            printf("Element is found at index %d", i);
            flag=1; 
            break;
        }

    }

    if (!flag) {
        printf("Element is not found.");
    }

}
