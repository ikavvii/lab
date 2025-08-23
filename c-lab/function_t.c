#include <stdio.h>

int main() {
    int t, p;
    printf("Enter t: ");
    scanf("%d", &t);

    if (0 < t && t <= 2) {
        p = 20;
    } else if ( 13 < t && t <= 16 || t > 30 ){
        p = 4 * t + 8;
    } else {
        p = 4 * t * t + 8 * t;
    }

    printf("Value of p: %d", p);
}