#include<stdio.h>
#include<conio.h>
#define A(x) x;x;x;x;x;x;x;x;x;x;

int main() {
    int n=1;
    A(A(A(printf("%d \n",n++))));
    return 0; 
}