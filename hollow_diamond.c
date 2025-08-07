#include <stdio.h>

int main() {
    int n, i, j, space;
    printf("Enter the number of rows for the diamond's half height (n): ");
    scanf("%d", &n);

    // Upper half (including the middle row)
    for(i = 1; i <= n; i++) {
        // Print leading spaces
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print asterisks with a space after each for proper formatting
        for(j = 1; j <= 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half
    for(i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for(space = 1; space <= n - i; space++) {
            printf(" ");
        }
        // Print asterisks with a space after each for proper formatting
        for(j = 1; j <= 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
