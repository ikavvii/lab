#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int left, int right);

void merge(int *arr, int left, int mid, int right);

int main () {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int arr_size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, arr_size - 1);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    return;
}

void merge(int *arr, int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = 0;

    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }

    free(temp);
    return;
}