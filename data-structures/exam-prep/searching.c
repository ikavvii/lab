#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);
        
        return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1;
}

int jumpSearch(int arr[], int n, int key) {
    int step = (int)sqrt(n);
    int prev = 0;
    
    while (arr[(step < n ? step : n) - 1] < key) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n)
            return -1;
    }
    
    while (arr[prev] < key) {
        prev++;
        if (prev == (step < n ? step : n))
            return -1;
    }
    
    if (arr[prev] == key)
        return prev;
    
    return -1;
}

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }
        
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));
        
        if (arr[pos] == key)
            return pos;
        
        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 23;
    
    printf("Array: ");
    printArray(arr, n);
    printf("\nSearching for: %d\n\n", key);
    
    int result = linearSearch(arr, n, key);
    printf("Linear Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    result = binarySearch(arr, 0, n - 1, key);
    printf("Binary Search (Iterative): %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    result = binarySearchRecursive(arr, 0, n - 1, key);
    printf("Binary Search (Recursive): %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    result = jumpSearch(arr, n, key);
    printf("Jump Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    result = interpolationSearch(arr, n, key);
    printf("Interpolation Search: %s at index %d\n", 
           result != -1 ? "Found" : "Not found", result);
    
    return 0;
}
