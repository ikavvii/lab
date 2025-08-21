#include <stdio.h>

int main() {
    int n, sum = 0, product = 1;
    printf("Enter a three digit positive integer: ");
    scanf("%d", &n);

    if (n < 0 || n > 999) {
        printf("Invalid input");
        return;
    }

    while (n > 0) {
        int temp = n % 10;
        sum += temp;
        product *= temp;
        n /= 10;
    }

    if (sum == product) {
        printf("The sum of the digits is equal to the product of the digits");
    } else {
        printf("The sum of the digits is NOT equal to the product of the digits");
    }

    return 0;

}
