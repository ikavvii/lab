
#include<stdio.h>
#include<math.h>
#include<stdlib.h>




void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        if(i == 0)
            printf("[%d,", arr[i]);
        else if(i == n-1)
            printf("%d]", arr[i]);
        else
            printf(" %d, ", arr[i]);
    }
    printf("\n");
}

int minSum(int arr[10][10], int i, int j, int sum, int m, int n){
    if(i >= m || j >= n){
        return sum;
    }
    sum = sum + arr[i][j];
    if(i == m-1 && j < n-1)
        sum = minSum(arr,i,j+1,sum,m,n);
    else if(i < m-1 && j == n-1)
        sum = minSum(arr,i+1,j, sum,m,n);
    else{
        int right = minSum(arr,i,j+1,sum,m,n);
        int down = minSum(arr,i+1,j, sum,m,n);
        sum = right < down? right:down;
    }

    return sum;
}


int main(){
    int arr[10][10];
    int m;
    int n;

 
    printf("Enter M: ");
    scanf("%d", &m);

    printf("Enter N: ");
    scanf("%d", &n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Element %d X %d: ", i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Input: \n");
    for(int i=0; i<m; i++){
        printArray(arr[i],n);
    }
    printf("\nOutput: \n");

    printf("Solution: %d", minSum(arr,0,0,0,m,n));
}
