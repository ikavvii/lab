#include <stdio.h>

int main() {
    int n = 5, spaces, stars, range;

    printf("\n\n");

    // right triangle 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }


    printf("\n\n");

    // pyramid
    for (int i = 0; i < n; i++) {
        spaces = n - i - 1;
        stars = 2 * i + 1;

        for (int j = 0; j < spaces + stars; j++) {
            if (j < spaces) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    printf("\n\n");

    // diamond
    for (int i = 0; i < 2 * n - 1; i++) {
        if(i<n) {
            spaces = n - i - 1;
            stars = 2 * i + 1;
        } else {
            spaces = i - n + 1;
            stars = 2 * (i - 2 * spaces) + 1;
        }
        for (int j = 0; j < spaces + stars; j++) {
            if (j < spaces) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    printf("\n\n");

    // right arrow
    for (int i = 0; i < 2 * n; i++) {
        if (i<n) {
            range = n + i;
            spaces = (range - n) * 2;
        } else if (i>n) {
            range--;
            spaces -= 2;
        }
        for (int j = 0; j < range; j++) {
            if (j < spaces) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}