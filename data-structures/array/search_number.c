#include <stdio.h>

int main () {

    int arr[] = {23, 34, 45, 25, 675, 754, 2, 3, 13};

    int search_element = 675;

    for (int i = 0; i < sizeof(arr)/4 ; i++) {
        if (arr[i] == search_element) {
            printf("Element is found at index %d", i); 
            break;
        }
    }


}
