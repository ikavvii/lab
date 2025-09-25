#include <stdio.h>
int main(){
    int arr[] = {1,2,2,2,5,9,14,6,7,3,3,5};
    int unique_cnt=0, arr_size=12, i, j;

    for(i=0;i<arr_size;i++){
        if(arr[i] != -9999){
            unique_cnt++;
            printf("%d ",arr[i]);
            for(j=i+1;j<arr_size;j++){
                if(arr[j] == arr[i]){
                    arr[j] = -9999;
                }
            }
        }
    }
    printf("\nCount of unique numbers : %d", unique_cnt);
    return 0;
}