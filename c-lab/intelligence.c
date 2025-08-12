#include <stdio.h>

int main() {
    int y = 1;
    float x = 5.5;

    for (int i = y; i <= 6; i++) {
        while (x <= 12.5) {
            float ans = 2 + ( y + 0.5 * x);
            printf("%.2f, ", ans);
            x += 0.5;
        }
        x = 5.5;
    }
    printf("\b\b ");
    return 0;
}