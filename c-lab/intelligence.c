#include <stdio.h>

int main() {
    int y;
    float x, i;
    printf("%-5s %-7s %-10s\n", "y", "x", "i");

    for (y = 1; y <= 6; y++) {
        for (x = 5.5; x <= 12.5; x += 0.5) {
            i = 2 + ( y + 0.5 * x);
            printf("%-5d %-7.1f %-10.2f\n", y, x, i);
        }
        printf("\n");
    }
    return 0;
}