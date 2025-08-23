#include <stdio.h>
#include <math.h>

int main () {
    int X, n; 
    double sum = 0;
    printf("Enter X: ");
    scanf("%d", &X);

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        sum += pow(X, i);

    printf("%.0lf", sum);

    return 0;
}