#include <stdio.h>

int main() {
    int n, first, last, middle;
    printf("Enter a three digit positive integer: ");
    scanf("%d", &n);

    if (n < 0 || n > 999) {
        printf("Invalid input");
        return 1;
    }

    last = n % 10;
    first = n / 100;
    middle = (n - first * 100) / 10;

    printf("%d %d %d\n", first, middle, last);
   
    if (first + last == middle) {
        printf("The sum of the first and the last digits is equal to the middle digit.");
    } else {
        printf("The sum of the first and the last digits is NOT equal to the middle digit.");
    }

    return 0;

}
