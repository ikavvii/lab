#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer();
int *removeDuplicates(int *arr);
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);

int main()
{
    int numSections;
    
    printf("Number of sections in warehouse: ");
    scanf("%d", &numSections);
    clearInputBuffer();

    int **sections = (int **)malloc(numSections * sizeof(int *));

    if (sections == NULL)
    {
        return 1;
    }

    int *sectionLengths = (int *)malloc(numSections * sizeof(int));
    if (sectionLengths == NULL)
    {
        return 1;
    }

    for (int i = 0; i < numSections; i++)
    {
        int *section = NULL;
        int numSectionItems = 0;
        printf("Section %d: [", i + 1);

        int itemId;
        char nextChar;
        while (scanf("%d%c", &itemId, &nextChar) == 2)
        {
            int *temp = (int *)realloc(section, (numSectionItems + 1) * sizeof(int));
            if (temp == NULL)
            {
                free(section);
                return 1;
            }

            section = temp;
            section[numSectionItems++] = itemId;
            sectionLengths[i] = numSectionItems;

            if (nextChar == '\n' ) {
                break;
            }
        }
        sections[i] = section;
    }

    for (int i = 0; i < numSections; i++)
    {
        for (int j = 0; j < sectionLengths[i]; j++)
        {
            printf("%d ", sections[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // merge sections
    int mergedSectionLength = 0;

    // sort sections

    // remove duplicates

    return 0;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

int *removeDuplicates(int *arr)
{
    int count = 0;
    int *uniqueArr;
    int previousElement = INT_MIN, currentElement;
    size_t arrLength = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < arrLength; i++)
    {
        currentElement = arr[i];
        if (previousElement != currentElement)
        {
            int *temp = realloc(uniqueArr, (count + 1) * sizeof(int));
            if (temp == NULL)
            {
                free(uniqueArr);
                return NULL;
            }
            uniqueArr = temp;
            uniqueArr[count++] = currentElement;
            previousElement = currentElement;
        }
    }

    return uniqueArr;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return;
}

void merge(int *arr, int left, int mid, int right)
{

    int i = left;
    int j = mid + 1;
    int k = 0;

    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }

    free(temp);
    return;
}