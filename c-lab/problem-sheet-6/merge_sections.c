#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer();
int *convert2dTo1dRowMajor(int **arr2d, int arraySize, int *arrayLengths, int *returnLength);
void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int mid, int right);
int *removeDuplicatesInSortedArray(int *arr, int arrLength, int *returnLength);

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
        printf("Section %d: ", i + 1);

        int itemId;

        // jagged array
        while (scanf("%d", &itemId) == 1)
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

            char c = getchar();
            if (c == '\n')
            {
                break;
            }
        }
        sections[i] = section;
    }

    printf("\nInput: \n");
    for (int i = 0; i < numSections; i++)
    {
        for (int j = 0; j < sectionLengths[i]; j++)
        {
            printf("%d ", sections[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // merge sections or flatten 2d array
    int mergedSectionsLength;
    int *mergedSections = convert2dTo1dRowMajor(sections, numSections, sectionLengths, &mergedSectionsLength);

    printf("Length of Item IDs after merging sections: %d\n\n", mergedSectionsLength);

    printf("Merged array: \n");
    for (int i = 0; i < mergedSectionsLength; i++)
    {
        printf("%d ", mergedSections[i]);
    }
    printf("\n\n");

    // sort sections
    mergeSort(mergedSections, 0, mergedSectionsLength - 1);

    // print after sorting
    printf("After sorting Item IDs in ascending order: \n");
    for (int i = 0; i < mergedSectionsLength; i++)
    {
        printf("%d ", mergedSections[i]);
    }
    printf("\n\n");

    // remove duplicates
    int sortedUniqueMergedSectionLength;
    int *sortedUniqueMergedSection = removeDuplicatesInSortedArray(mergedSections, mergedSectionsLength, &sortedUniqueMergedSectionLength);

    // printing after removing duplicates
    printf("Without duplicate Item IDs: \n");
    for (int i = 0; i < sortedUniqueMergedSectionLength; i++)
    {
        printf("%d ", sortedUniqueMergedSection[i]);
    }
    printf("\n\n");

    return 0;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return;
}

int *convert2dTo1dRowMajor(int **arr2d, int arraySize, int *arrayLengths, int *returnLength)
{
    *returnLength = 0;
    for (int i = 0; i < arraySize; i++)
    {
        *returnLength += arrayLengths[i];
    }

    int *arr1d = malloc((*returnLength) * sizeof(int));
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arrayLengths[i]; j++)
        {
            int index = 0;

            for (int k = 0; k < i; k++)
            {
                index += arrayLengths[k];
            }
            index += j;
            arr1d[index] = arr2d[i][j];
        }
    }

    return arr1d;
}

int *removeDuplicatesInSortedArray(int *arr, int arrLength, int *returnLength)
{
    *returnLength = 0;
    int *uniqueArr = NULL;
    int previousElement = INT_MIN, currentElement;

    for (int i = 0; i < arrLength; i++)
    {
        currentElement = arr[i];
        if (previousElement != currentElement)
        {
            int *temp = realloc(uniqueArr, ((*returnLength) + 1) * sizeof(int));
            if (temp == NULL)
            {
                free(uniqueArr);
                return NULL;
            }
            uniqueArr = temp;
            uniqueArr[(*returnLength)++] = currentElement;
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